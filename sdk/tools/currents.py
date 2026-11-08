#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
# Copyright (C) 2026 Charles Vestal
"""Build Ripple currents: Faust (.dsp), Pd (.pd), C (.c) and C++ (.cc) sources into .cur files for the FM-1, and into shared libraries for
the host simulator.

  currents.py SRC... --out DIR            each source into DIR/NAME.cur (the JieLi toolchain, as fm1-base builds)
  currents.py SRC... --host DIR           each source into DIR/NAME.so (this computer's cc), for the simulator
  currents.py SRC... --web DIR            each source as C in DIR (its entry rc_entry_NAME) and DIR/registry.c: a
                                          firmware's browser emulator links them all (fm1.toml web = [...])
  currents.py SRC... --web-module DIR     each source into DIR/NAME.wasm (emcc): the current as a module of its own,
                                          to upload to Ripple's emulator page beside its .cur (sdk/web/rc_module.c)

A Faust current: its sliders become the current's parameters. With a "freq", a "gain" and a "gate", it is a voice,
played polyphonically (declare voices "6" in the .dsp; default 6): notes set those three; with inputs, an effect.
A Pd patch: through Heavy (hvcc) into C++: its [r NAME @hv_param MIN MAX DEFAULT] are the parameters, [notein] gets
the notes, [adc~] makes it an effect; its abstractions in lib/ beside it. Heavy's C is kept in gen/NAME_heavy/ and its
runtime in sdk/heavy/runtime/, like Faust's C (sdk/heavy/HvUtils.h makes it freestanding).
A source may be a folder: its .dsp, .pd, .c and .cc files.
A C current: writes its own rc_desc_t (sdk/include/ripple_current.h) and RC_EXPORT()s it. A C++ current (.cc) the
same, freestanding: no exceptions, RTTI, thread-safe statics or C++ library, and nothing that needs a constructor
run (the build refuses it). Either may say, in its own lines,
  // ripple-sources: plaits/plaits/**/*.cc ...    more files built and linked in (globs, relative to the file)
  // ripple-cflags: -Iplaits -DTEST ...           flags for it and them (-I relative to the file)
The other sources are built once for each set of flags (sdk/build/obj/) and only what the current reaches is kept.
The browser's emulator leaves C++ currents out.

Faust's C for a .dsp is kept in gen/ beside it: made again where Faust is installed, used as it is where it is not.

Environment: JIELI_TOOLCHAIN (default ~/.jieli/toolchain), FAUST (default faust), HVCC (default hvcc)."""
import argparse
import hashlib
import os
import platform
import shutil
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

SDK = Path(__file__).resolve().parents[1]
ROOT = SDK.parent                                   # the repository: mounted as /work in the toolchain's container
BASE_INC = ROOT / "base" / "include"
CFLAGS = ["-ffunction-sections", "-fdata-sections", "-fno-builtin", "-Wall", "-Wno-unused-function",
          "-Wdouble-promotion", "-ffp-contract=off"]
CXXFLAGS = ["-std=c++11", "-nostdinc++", "-fno-exceptions", "-fno-rtti", "-fno-threadsafe-statics",
            "-DRIPPLE_CURRENT", "-Wno-unused-private-field", "-Wno-unused-local-typedef", "-Wno-unused-variable"]


def extras(src):
    """a current's own lines: the more sources it links (globs, relative to it) and its flags (-I relative to it)"""
    if src.suffix not in (".c", ".cc"):
        return [], []
    more, flags = [], []
    for line in src.read_text().splitlines()[:60]:
        m = re.match(r"\s*(?://|/\*|\*)\s*ripple-(sources|cflags):\s*(.*?)\s*(?:\*/)?$", line)
        if not m:
            continue
        for w in m.group(2).split():
            if m.group(1) == "sources":
                more += sorted(p for p in src.parent.glob(w) if p.resolve() != src.resolve())
            elif w.startswith("-I"):                # (a Path of its own: the toolchain's container sees it at /work)
                flags += ["-I", (src.parent / w[2:]).resolve()]
            else:
                flags.append(w)
    return more, flags


def lang(f):
    return CXXFLAGS if Path(f).suffix in (".cc", ".cpp") else []

# ------------------------------------------------------------------ Faust ---
UI_RE = re.compile(r'ui_interface->(addHorizontalSlider|addVerticalSlider|addNumEntry|addButton|addCheckButton)\('
                   r'ui_interface->uiInterface, "([^"]*)", &dsp->(\w+)(?:, \(FAUSTFLOAT\)([^,]+), \(FAUSTFLOAT\)([^,]+), '
                   r'\(FAUSTFLOAT\)([^,]+), \(FAUSTFLOAT\)([^)]+))?\);')


def fnum(s):
    return float(s.strip().rstrip("f"))


def faust_to_c(dsp, work):
    """the .dsp through Faust, then the wrapper that makes it a current: its C source"""
    name = dsp.stem
    gen = work / f"{name}_faust.c"
    faust = os.environ.get("FAUST", "faust")
    cls = "rc_" + re.sub(r"\W", "_", name)              # the generated code's names: its own, so currents link together
    # Faust's C is kept beside the source (gen/NAME_faust.c): made again where Faust is installed, used as it is where
    # not (the release builder), so every build compiles the same C
    kept = dsp.parent / "gen" / f"{name}_faust.c"
    if shutil.which(faust):
        r = subprocess.run([faust, "-lang", "c", "-single", "-cn", cls, "-ftz", "0", str(dsp), "-o", str(gen)],
                           capture_output=True, text=True)
        if r.returncode:
            sys.stderr.write(r.stderr)
            raise SystemExit(f"currents: faust failed on {dsp}")
        made = gen.read_text()
        if not kept.exists() or kept.read_text() != made:
            kept.parent.mkdir(exist_ok=True)
            kept.write_text(made)
            print(f"currents: gen/{kept.name} made again (commit it)")
    elif kept.exists():
        gen.write_text(kept.read_text())
    else:
        raise SystemExit(f"currents: no faust, and no {kept} to use instead")
    src = gen.read_text()
    src = src.replace("#include <math.h>", '#include "faust_shim.h"').replace("#include <stdlib.h>", "")
    gen.write_text(src)
    ui = []
    for m in UI_RE.finditer(src):
        kind, label, field = m.group(1), m.group(2), m.group(3)
        if kind in ("addButton", "addCheckButton"):
            ui.append((label, field, 0.0, 0.0, 1.0))
        else:
            ui.append((label, field, fnum(m.group(4)), fnum(m.group(5)), fnum(m.group(6))))
    ins = int(re.search(rf"getNumInputs{cls}\({cls}\* RESTRICT dsp\) \{{\s*return (\d+);", src).group(1))
    outs = int(re.search(rf"getNumOutputs{cls}\({cls}\* RESTRICT dsp\) \{{\s*return (\d+);", src).group(1))
    if ins not in (0, 1, 2) or outs not in (1, 2):
        raise SystemExit(f"currents: {dsp}: {ins} inputs, {outs} outputs (0..2 in, 1..2 out)")
    labels = [u[0] for u in ui]
    poly = all(k in labels for k in ("freq", "gain", "gate")) and ins == 0
    vm = re.search(r'declare voices "(\d+)"', dsp.read_text())
    voices = int(vm.group(1)) if (poly and vm) else (6 if poly else 0)
    params = [u for u in ui if not (poly and u[0] in ("freq", "gain", "gate"))]
    field = {u[0]: u[1] for u in ui}
    n = max(voices, 1)
    w = [f'/* generated by sdk/tools/currents.py from {dsp.name}: a Ripple current */',
         '#include "ripple_current.h"', f'#include "{gen.name}"', "",
         f"#define NV {n}",
         "typedef struct {", f"    {cls} v[NV];",
         "    int note[NV];                 /* the voice's note, -1 free */",
         "    unsigned age[NV], clock;      /* when it started: the oldest goes first */",
         "    float tl[256], tr[256];       /* a voice's block, mixed in (part 0 and process) */",
         "    float tl2[256], tr2[256];     /* part 1's (the second core) */",
         "} st_t;", "",
         "static const rc_param_t P[] = {"]
    for label, _, d, lo, hi in params:
        w.append(f'    {{"{label}", {lo!r}f, {hi!r}f, {d!r}f}},')
    if not params:
        w.append('    {"", 0.0f, 0.0f, 0.0f},')
    w += ["};", "",
          "static void init(void *p, float sr)", "{", "    st_t *s = p;", "    int i;",
          "    for (i = 0; i < NV; i++) {", f"        instanceInit{cls}(&s->v[i], (int)sr);", "        s->note[i] = -1;", "    }",
          f"    classInit{cls}((int)sr);", "}", "",
          "static void set(void *p, int k, float v)", "{", "    st_t *s = p;", "    int i;", "    switch (k) {"]
    for i, (label, fld, *_r) in enumerate(params):
        w.append(f"    case {i}: for (i = 0; i < NV; i++) s->v[i].{fld} = v; break;")
    w += ["    default: break;", "    }", "}", ""]
    if poly:
        fq, gn, gt = field["freq"], field["gain"], field["gate"]
        w += ["static void note(void *p, int nt, float vel)", "{", "    st_t *s = p;", "    int i, pick = -1;",
              "    if (vel <= 0.0f) {",
              "        for (i = 0; i < NV; i++)",
              f"            if (s->note[i] == nt) {{ s->v[i].{gt} = 0.0f; s->note[i] = -1; }}",
              "        return;", "    }",
              "    for (i = 0; i < NV; i++)            /* a free voice, the one released longest ago */",
              "        if (s->note[i] < 0 && (pick < 0 || s->age[i] < s->age[pick])) pick = i;",
              "    if (pick < 0)                         /* else the oldest note: a sample with its gate down first */",
              "        for (i = 0; i < NV; i++) if (pick < 0 || s->age[i] < s->age[pick]) pick = i;",
              f"    if (s->v[pick].{gt} > 0.0f) {{",
              "        float *o[2] = {s->tl, s->tr};",
              f"        s->v[pick].{gt} = 0.0f;",
              f"        compute{cls}(&s->v[pick], 1, 0, o);", "    }",
              f"    s->v[pick].{fq} = 440.0f * fm_exp2f((float)(nt - 69) / 12.0f);",
              f"    s->v[pick].{gn} = vel;", f"    s->v[pick].{gt} = 1.0f;",
              "    s->note[pick] = nt;", "    s->age[pick] = ++s->clock;", "}", ""]
    if ins == 0:                                    # a voice's voices in two parts (the even, the odd): one per core
        rr = "o[1]" if outs == 2 else "o[0]"
        w += ["static void process_part(void *p, float *l, float *r, int n, int part)", "{", "    st_t *s = p;",
              "    int i, k;", "    float *o[2] = {part ? s->tl2 : s->tl, part ? s->tr2 : s->tr};",
              "    for (k = part; k < NV; k += 2) {", f"        compute{cls}(&s->v[k], n, 0, o);",
              "        for (i = 0; i < n; i++) {",
              "            l[i] += o[0][i];", f"            r[i] += {rr}[i];",
              "        }", "    }", "}", "",
              "static void process(void *p, float *l, float *r, int n)", "{",
              "    process_part(p, l, r, n, 0);", "    process_part(p, l, r, n, 1);", "}", ""]
    else:
        w += ["static void process(void *p, float *l, float *r, int n)", "{", "    st_t *s = p;", "    int i;",
              "    float *o[2] = {s->tl, s->tr};"]
        inp = "{l, r}" if ins == 2 else "{s->tr}"
        if ins == 1:
            w += ["    for (i = 0; i < n; i++) s->tr[i] = 0.5f * (l[i] + r[i]);"]
        w += [f"    float *in[2] = {inp};", f"    compute{cls}(&s->v[0], n, in, o);",
              "    for (i = 0; i < n; i++) {", "        l[i] = s->tl[i];",
              f"        r[i] = s->t{'r' if outs == 2 else 'l'}[i];", "    }", "}", ""]
    w += [
          "static const rc_desc_t D = {RC_MAGIC, RC_ABI, " + f'"{name}", sizeof(st_t), {ins and 2}, {voices}, '
          + f"{len(params)}, P, init, set, " + ("note" if poly else "0") + ", process, "
          + ("2, {0}, process_part, 0};" if ins == 0 and n > 1 else "0, {0}, 0, 0};"),   # (one voice: nothing to split)
          "RC_EXPORT(D)", ""]
    out = work / f"{name}_current.c"
    out.write_text("\n".join(w))
    return out


# --------------------------------------------------------------------- Pd ---
HV_NOTEIN = 0x67E37CA3                              # Heavy's hash of "__hv_notein": where [notein] listens
HV_POOL_KB, HV_INQ_KB = 2, 1                        # Heavy's message pool and input queue
HV_RUNTIME = SDK / "heavy" / "runtime"              # Heavy's own files, shared by every patch


FLOAT_LIT = re.compile(r"(?<![\w.])(\d+\.\d*(?:[eE][-+]?\d+)?|\.\d+(?:[eE][-+]?\d+)?|\d+[eE][-+]?\d+)(?![\w.])")


def heavy_rewrite(text, fname, name):
    """hvcc's C/C++ made freestanding: no doubles, no C library, no new or delete (sdk/heavy/HvUtils.h has the rest)"""
    text = text.replace("va_arg(ap, double)", "RC_HV_VA_FLOAT(ap)")
    text = re.sub(r"\bdouble\b", "float", text)
    text = FLOAT_LIT.sub(r"\1f", text)            # 1000.0 -> 1000.0f
    text = text.replace("#include <math.h>", "").replace("#include <new>", "")
    text = text.replace("virtual ~", "~")           # (no deleting destructors: they call operator delete)
    if fname == f"Heavy_{name}.cpp":                # its C functions allocate with new: the current builds it itself
        text = re.sub(r'extern "C" \{.*?\} // extern "C"', "", text, flags=re.S)
    if fname == "HvUtils.c":                        # the hash reads a word at a time from any address: the FM-1
        text = text.replace("#if HV_EMSCRIPTEN", "#if 1 /* the FM-1: no unaligned loads */")   # faults; byte by byte
    if fname == "HvHeavy.cpp":                      # (and frees with delete)
        text = text.replace("  delete c;", "  (void) c;")
    return text


def pd_to_cc(pd, work):
    """the patch through Heavy (hvcc), then the wrapper that makes it a current: its C++ source. Heavy's sources and
    the wrapper are kept beside the patch (gen/NAME_heavy/): made again where hvcc is installed, used as they are
    where it is not."""
    name = re.sub(r"\W", "_", pd.stem)
    kept = pd.parent / "gen" / f"{pd.stem}_heavy"
    wrapper = kept / f"{name}_current.cc"
    hvcc = os.environ.get("HVCC", "hvcc")
    if not shutil.which(hvcc):
        if not wrapper.exists():
            raise SystemExit(f"currents: no hvcc, and no {wrapper} to use instead")
        return wrapper
    tmp = Path(tempfile.mkdtemp(prefix="hvcc-"))
    r = subprocess.run([hvcc, str(pd), "-o", str(tmp), "-n", name, "--copyright", f"the author of {pd.name}",
                        "-p", str(pd.parent / "lib")],     # (abstractions: in lib/ beside the patch, so not currents)
                       capture_output=True, text=True)
    out = tmp / "c"
    if r.returncode or not (out / f"Heavy_{name}.cpp").exists():
        sys.stderr.write(r.stdout + r.stderr)
        raise SystemExit(f"currents: hvcc failed on {pd}")
    files = {}
    for f in sorted(out.iterdir()):
        if f.name == "HvUtils.h" or f.suffix not in (".c", ".cpp", ".h", ".hpp"):
            continue
        files[f.name] = heavy_rewrite(f.read_text(), f.name, name)
    own = {fn for fn in files if fn.startswith(f"Heavy_{name}.")}
    heavy_runtime({fn: text for fn, text in files.items() if fn not in own}, r.stdout)
    files["HvUtils.h"] = (SDK / "heavy" / "HvUtils.h").read_text()     # (for the measure: it builds everything in one place)
    files["rc_heavy_shim.c"] = (SDK / "heavy" / "heavy_shim.c").read_text()
    cpp = files[f"Heavy_{name}.cpp"]
    hpp = files[f"Heavy_{name}.hpp"]
    ins = int(re.search(r"getNumInputChannels\(\) override \{ return (\d+); \}", hpp).group(1))
    outs = int(re.search(r"getNumOutputChannels\(\) override \{ return (\d+); \}", hpp).group(1))
    if ins not in (0, 1, 2) or outs not in (1, 2):
        raise SystemExit(f"currents: {pd}: {ins} inputs, {outs} outputs (0..2 in, 1..2 out: [adc~], [dac~])")
    params = []                                     # the patch's [r NAME @hv_param MIN MAX DEFAULT]
    for m in re.finditer(r'info->name = "([^"]*)";\s*info->hash = (0x[0-9A-F]+);\s*'
                         r'info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;\s*'
                         r'info->minVal = ([-\d.e]+)f;\s*info->maxVal = ([-\d.e]+)f;\s*info->defaultVal = ([-\d.e]+)f;', cpp):
        params.append((m.group(1), m.group(2), float(m.group(3)), float(m.group(4)), float(m.group(5))))
    notes = f"0x{HV_NOTEIN:08X}" in cpp
    heap = heavy_heap(files, name, tmp)
    sh = os.path.relpath(SDK / "heavy", kept)       # (globs and -I relative to the wrapper)
    rt = os.path.relpath(HV_RUNTIME, kept)
    w = [f"// generated by sdk/tools/currents.py from {pd.name} (Heavy): a Ripple current",
         f"// ripple-sources: *.cpp {rt}/*.c {rt}/*.cpp {sh}/heavy_shim.c",
         f"// ripple-cflags: -I. -I{sh} -I{rt}",
         '#include "ripple_current.h"', f'#include "Heavy_{name}.hpp"', "",
         "inline void *operator new(size_t, void *p) noexcept { return p; }",
         "typedef struct { char *base; size_t size, used, peak_fail; } rc_hv_arena_t;",
         'extern "C" rc_hv_arena_t *rc_hv_arena;', "",
         f"#define HEAP {heap}                       /* measured with the patch built on the computer, and a margin */",
         "typedef struct {",
         f"    alignas(8) char obj[sizeof(Heavy_{name})];",
         "    rc_hv_arena_t arena;",
         "    alignas(8) char heap[HEAP];",
         "    float in[2][256], out[2][256];",
         "} st_t;", "",
         "static const rc_param_t P[] = {"]
    for label, _h, lo, hi, d in params:
        w.append(f'    {{"{label}", {lo!r}f, {hi!r}f, {d!r}f}},')
    if not params:
        w.append('    {"", 0.0f, 0.0f, 0.0f},')
    w += ["};", "static const hv_uint32_t H[] = {" + ", ".join(h for _l, h, *_r in params) + ("" if params else "0") + "};", "",
          f"static Heavy_{name} *hv(st_t *s)", "{",
          "    rc_hv_arena = &s->arena;                 /* (Heavy takes a little more as messages queue) */",
          f"    return reinterpret_cast<Heavy_{name} *>(s->obj);", "}", "",
          "static void set(void *p, int k, float v)", "{",
          "    if (k >= 0 && k < (int)(sizeof(H) / sizeof(H[0])) && H[k]) hv((st_t *)p)->sendFloatToReceiver(H[k], v);", "}", "",
          "static void init(void *p, float sr)", "{", "    st_t *s = (st_t *)p;",
          "    s->arena.base = s->heap;", "    s->arena.size = HEAP;", "    rc_hv_arena = &s->arena;",
          f"    new (s->obj) Heavy_{name}(sr, {HV_POOL_KB}, {HV_INQ_KB}, 0);",
          f"    for (int k = 0; k < {len(params)}; k++) set(p, k, P[k].def);", "}", ""]
    if notes:
        w += ["static void note(void *p, int nt, float vel)", "{",
              "    HvMessage *m = HV_MESSAGE_ON_STACK(3);   /* [notein]: note, velocity 0..127, channel 1 */",
              "    msg_init(m, 3, 0);", "    msg_setFloat(m, 0, (float)nt);", "    msg_setFloat(m, 1, vel * 127.0f);",
              "    msg_setFloat(m, 2, 1.0f);", f"    hv((st_t *)p)->sendMessageToReceiver(0x{HV_NOTEIN:08X}, 0.0f, m);", "}", ""]
    rr = "s->out[1]" if outs == 2 else "s->out[0]"
    w += ["static void process(void *p, float *l, float *r, int n)", "{", "    st_t *s = (st_t *)p;",
          "    float *in[2] = {s->in[0], s->in[1]}, *out[2] = {s->out[0], s->out[1]};"]
    if ins == 2:
        w += ["    for (int i = 0; i < n; i++) { s->in[0][i] = l[i]; s->in[1][i] = r[i]; }"]
    elif ins == 1:
        w += ["    for (int i = 0; i < n; i++) s->in[0][i] = 0.5f * (l[i] + r[i]);"]
    w += ["    hv(s)->process(in, out, n);"]
    if ins:
        w += [f"    for (int i = 0; i < n; i++) {{ l[i] = s->out[0][i]; r[i] = {rr}[i]; }}"]
    else:
        w += [f"    for (int i = 0; i < n; i++) {{ l[i] += s->out[0][i]; r[i] += {rr}[i]; }}"]
    w += ["}", "",
          "static const rc_desc_t D = {RC_MAGIC, RC_ABI, " + f'"{pd.stem}", sizeof(st_t), {ins and 2}, {1 if notes else 0}, '
          + f"{len(params)}, P, init, set, " + ("note" if notes else "0") + ", process, 0, {0}, 0, 0};",
          'extern "C" RC_EXPORT(D)', ""]
    files[wrapper.name] = "\n".join(w)
    if kept.exists():
        shutil.rmtree(kept)
    kept.mkdir(parents=True)
    for fn in [*own, wrapper.name]:
        (kept / fn).write_text(files[fn])
    print(f"currents: gen/{kept.name}/ made again (commit it): {len(params)} parameters, heap {heap} B")
    return wrapper


def heavy_runtime(files, log):
    """Heavy's runtime, made freestanding once and shared by every patch: sdk/heavy/runtime/. hvcc writes only the
    files a patch uses: they are added; another hvcc version's runtime replaces it all."""
    ver = re.search(r"\d+\.\d+\.\d+", subprocess.run([os.environ.get("HVCC", "hvcc"), "--version"], capture_output=True,
                                                     text=True).stdout or "")
    files = {**files, "VERSION": (ver.group(0) if ver else "?") + "\n"}
    have = {f.name: f.read_text() for f in HV_RUNTIME.iterdir()} if HV_RUNTIME.exists() else {}
    if any(have.get(fn, text) != text for fn, text in files.items()):
        shutil.rmtree(HV_RUNTIME)
        have = {}
    new = [fn for fn in files if fn not in have]
    if not new:
        return
    HV_RUNTIME.mkdir(parents=True, exist_ok=True)
    for fn in new:
        (HV_RUNTIME / fn).write_text(files[fn])
    print(f"currents: sdk/heavy/runtime/: {len(new)} files from hvcc {files['VERSION'].strip()} (commit them)")


def heavy_heap(files, name, tmp):
    """the arena the patch needs: built on this computer with a counting arena (its pointers are 8 bytes, the FM-1's
    4: an upper bound), a block of notes and parameters played through it, and a margin"""
    d = tmp / "measure"
    d.mkdir()
    for fn, text in files.items():
        (d / fn).write_text(text)
    (d / "measure.cpp").write_text(f"""#include <stdio.h>
#include "Heavy_{name}.hpp"
inline void *operator new(size_t, void *p) noexcept {{ return p; }}
typedef struct {{ char *base; size_t size, used, peak_fail; }} rc_hv_arena_t;
extern "C" rc_hv_arena_t *rc_hv_arena;
static char heap[1 << 22];
alignas(8) static char obj[sizeof(Heavy_{name})];
int main() {{
  static rc_hv_arena_t a = {{heap, sizeof heap, 0, 0}};
  rc_hv_arena = &a;
  Heavy_{name} *h = new (obj) Heavy_{name}(44100.0f, {HV_POOL_KB}, {HV_INQ_KB}, 0);
  static float o[2][256], i[2][256];
  float *in[2] = {{i[0], i[1]}}, *out[2] = {{o[0], o[1]}};
  for (int b = 0; b < 200; b++) {{
    HvMessage *m = HV_MESSAGE_ON_STACK(3);
    msg_init(m, 3, 0); msg_setFloat(m, 0, 60.0f + b % 12); msg_setFloat(m, 1, b & 1 ? 0.0f : 100.0f); msg_setFloat(m, 2, 1.0f);
    h->sendMessageToReceiver(0x{HV_NOTEIN:08X}, 0.0f, m);
    h->process(in, out, 256);
  }}
  printf("%zu\\n", a.used);
  return 0;
}}
""")
    cxx = os.environ.get("CXX", "c++")
    cc = os.environ.get("CC", "cc")
    inc = ["-I", str(d), "-I", str(SDK / "faust"), "-I", str(BASE_INC)]
    objs = []
    for f in sorted(d.iterdir()):
        if f.suffix not in (".c", ".cpp"):
            continue
        o = f.with_suffix(".o")
        args = [cxx, "-std=c++11", "-fno-exceptions", "-fno-rtti"] if f.suffix == ".cpp" else [cc, "-std=c99"]
        r = subprocess.run([*args, "-O1", "-w", *inc, "-c", str(f), "-o", str(o)], capture_output=True, text=True)
        if r.returncode:
            sys.stderr.write(r.stderr)
            raise SystemExit(f"currents: {f.name} (Heavy) did not compile on this computer")
        objs.append(str(o))
    exe = d / "measure"
    r = subprocess.run([cxx, *objs, "-o", str(exe)], capture_output=True, text=True)
    if r.returncode:
        sys.stderr.write(r.stderr)
        raise SystemExit("currents: Heavy's measure did not link")
    used = int(subprocess.run([str(exe)], capture_output=True, text=True, check=True).stdout)
    return (used + used // 4 + 512 + 255) & ~255


def source(src, work):
    """what a current's source compiles from: Faust and Pd through their compilers, C and C++ as they are"""
    if src.suffix == ".dsp":
        return faust_to_c(src, work)
    if src.suffix == ".pd":
        return pd_to_cc(src, work)
    return src


# -------------------------------------------------------- the FM-1's build ---
def toolchain():
    return Path(os.environ.get("JIELI_TOOLCHAIN", Path.home() / ".jieli" / "toolchain")).resolve()


def use_docker():
    native = platform.system() == "Linux" and platform.machine() in ("x86_64", "AMD64")
    return os.environ.get("JIELI_DOCKER", "0" if native else "1") == "1"


_BUILDER = None


def builder():
    """fm1-base's long-lived toolchain container for this repository (tools/build.py: the same name), or a new one"""
    global _BUILDER
    if _BUILDER:
        return _BUILDER
    name = "jieli-" + hashlib.sha1(str(ROOT).encode()).hexdigest()[:10]
    st = subprocess.run(["docker", "inspect", "-f", "{{.State.Running}}", name], capture_output=True, text=True)
    if st.stdout.strip() != "true":
        subprocess.run(["docker", "rm", "-f", name], capture_output=True)
        r = subprocess.run(["docker", "run", "-d", "--rm", "--name", name, "--platform", "linux/amd64",
                            "-v", f"{ROOT}:/work", "-v", f"{toolchain()}:/opt/jieli:ro", "-w", "/work",
                            "debian:bookworm-slim", "sh", "-c", "sleep 3600"], capture_output=True, text=True)
        if r.returncode:
            sys.stderr.write(r.stderr)
            raise SystemExit("currents: cannot start the toolchain container")
    _BUILDER = name
    return name


def tc(tool, *args):
    rel = [str(Path(a).resolve().relative_to(ROOT)) if isinstance(a, Path) else a for a in args]
    if use_docker():
        cmd = ["docker", "exec", "-w", "/work", builder(), f"/opt/jieli/{tool}", *rel]
    else:
        cmd = [str(toolchain() / tool), *rel]
    r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        sys.stderr.write(r.stdout + r.stderr)
        raise SystemExit(f"currents: {tool} failed")
    if r.stderr.strip():
        sys.stderr.write(r.stderr)
    return r.stdout


LDS = """/* a current: one image linked at 0 (code, constants, data), then its zeroed data; relocations kept (-q) */
ENTRY(rc_entry)
SECTIONS {
  . = 0;
  .image : { KEEP(*(.text.rc_entry)) *(.text*) *(.rodata*) *(.data*) *(.sdata*) . = ALIGN(8); }
  .bss (NOLOAD) : { *(.bss*) *(.sbss*) *(COMMON) . = ALIGN(8); }
  /DISCARD/ : { *(.comment) *(.note*) }
}
"""


def elf_sections(b):
    e_shoff, = struct.unpack_from("<I", b, 32)
    e_shentsize, e_shnum, e_shstrndx = struct.unpack_from("<HHH", b, 46)
    secs = []
    for i in range(e_shnum):
        secs.append(struct.unpack_from("<IIIIIIIIII", b, e_shoff + i * e_shentsize))
    strtab = secs[e_shstrndx]
    def nm(off):
        s = strtab[4] + off
        return b[s:b.index(b"\0", s)].decode()
    return [(nm(s[0]),) + s for s in secs]


def elf_symbol(b, secs, want):
    for name, _n, typ, _f, _a, off, size, link, *_ in secs:
        if typ == 2:                                # SHT_SYMTAB
            strs = secs[link]
            for k in range(0, size, 16):
                st_name, st_value = struct.unpack_from("<II", b, off + k)
                s = strs[5] + st_name
                if b[s:b.index(b"\0", s)].decode() == want:
                    return st_value
    return None


def pack(elf, out):
    """the linked current into a .cur: header, image, relocations (fm1-ripple app/flow.c reads it)"""
    b = elf.read_bytes()
    secs = elf_sections(b)
    image = bss = None
    relocs = []
    for name, _n, typ, _f, addr, off, size, link, info, *_ in secs:
        if name == ".image":
            image = (addr, b[off:off + size])
        elif name == ".bss":
            bss = size
    if image is None or image[0] != 0:
        raise SystemExit(f"currents: {elf}: no image at 0")
    img = image[1]
    names = {i: s[0] for i, s in enumerate(secs)}
    for name, _n, typ, _f, _a, off, size, link, info, *_ in secs:
        if typ == 4:                                # SHT_RELA
            if names[info] != ".image":
                continue
            for k in range(0, size, 12):
                r_off, r_info, _add = struct.unpack_from("<IIi", b, off + k)
                t = r_info & 0xFF
                if t in PC_RELATIVE:
                    continue                        # resolved at the link: the same wherever the image goes
                if t not in RELOC_KIND:
                    raise SystemExit(f"currents: {elf}: relocation type {t} at {r_off:#x} not supported")
                kind = RELOC_KIND[t]
                relocs.append(r_off | kind << 28)
    entry = elf_symbol(b, secs, "rc_entry")
    if entry is None:
        raise SystemExit(f"currents: {elf}: no rc_entry (RC_EXPORT)")
    rel = b"".join(struct.pack("<I", r) for r in relocs)
    s = (sum(img) + sum(rel)) & 0xFFFFFFFF
    # what the current is, for a droplet listing the currents without loading them (flow.c flow_info): its
    # descriptor found by its magic (ripple_current.h: magic, abi, name, state_size, ins, voices), into the header's
    # spare fields: info = 0x8000 | ins << 8 | voices, and the state's size
    info, state = 0, 0
    for k in range(0, len(img) - 18, 4):
        magic, abi = struct.unpack_from("<II", img, k)
        if magic == 0x52435231 and abi in (1, 2):
            state, ins, voices = struct.unpack_from("<IBB", img, k + 12)
            info = 0x8000 | (0x100 if ins else 0) | voices
            break
    head = struct.pack("<IHHIIIIII", 0x52554352, 1, info, len(img), bss or 0, entry, len(relocs), s, state)
    out.write_bytes(head + img + rel)
    return len(img), bss or 0, len(relocs)


# the toolchain's relocation types (objdump -r): the ones a loaded image must have patched, and the ones it need not
RELOC_KIND = {8: 1,                                 # R_PI32V2_ABS32: a word holding an address
              5: 2}                                 # R_PI32V2_MOV_ABS32: a 6-byte move, its address at +2
PC_RELATIVE = {2}                                   # R_PI32V2_LONG_JUMP_23M2: a call


def build_device(srcs, out_dir):
    out_dir.mkdir(parents=True, exist_ok=True)
    work = ROOT / "sdk" / "build"
    work.mkdir(parents=True, exist_ok=True)
    (work / "current.ld").write_text(LDS)
    for src in srcs:
        c = source(src, work)
        name = src.stem
        obj, elf = work / f"{name}.o", work / f"{name}.elf"
        more, xflags = extras(c)
        base = ["-target", "pi32v2", "-mcpu=r3", "-mfprev1", "-O2", *CFLAGS, "-I", SDK / "include",
                "-I", SDK / "faust", "-I", BASE_INC, "-I", work, *xflags]
        tc("pi32v2/bin/clang", *base, *lang(c), "-c", c, "-o", obj)
        objs = [obj]
        if more:                                    # built once for these flags, again only when a source changes
            odir = work / "obj" / hashlib.sha1(" ".join(map(str, base)).encode()).hexdigest()[:10]
            odir.mkdir(parents=True, exist_ok=True)
            for m in more:
                o = odir / (hashlib.sha1(str(m.resolve()).encode()).hexdigest()[:8] + "_" + m.stem + ".o")
                if not o.exists() or o.stat().st_mtime < m.stat().st_mtime:
                    tc("pi32v2/bin/clang", *base, *lang(m), "-c", m, "-o", o)
                objs.append(o)
        tc("pi32v2/bin/ld", "-q", "--gc-sections", "-T", work / "current.ld", *objs,
           "/opt/jieli/pi32v2/lib/r3/libcompiler_rt.a" if use_docker() else str(toolchain() / "pi32v2/lib/r3/libcompiler_rt.a"),
           "-o", elf)
        syms = tc("common/bin/objdump", "-t", elf)
        soft = re.findall(r"\s(__\w*df\w*)$", syms, re.M)
        if soft:
            raise SystemExit(f"currents: {src.name}: soft-double routines {soft[:4]} (a double in the code)")
        # nothing runs constructors, unwinds or links a C++ library: a current that needs one is refused
        heads = tc("common/bin/objdump", "-h", elf)
        bad = [x for x in (".init_array", ".ctors", ".eh_frame", ".gcc_except_table") if re.search(r"\s" + re.escape(x) + r"\b", heads)]
        cxx = sorted(set(re.findall(r"\s(__cxa_\w+|_Znw\w*|_Zdl\w*|__dso_handle|__gxx_personality\w*)$", syms, re.M))
                     - {"__cxa_pure_virtual"})
        undef = re.findall(r"\*UND\*\s+\S+\s+(\S+)$", syms, re.M)
        if bad or cxx or undef:
            raise SystemExit(f"currents: {src.name}: {bad or ''} {cxx[:4] or ''} {('undefined: ' + ' '.join(undef[:6])) if undef else ''}")
        n_img, n_bss, n_rel = pack(elf, out_dir / f"{name}.cur")
        print(f"current  {name}.cur  code+data {n_img} B, zeroed {n_bss} B, {n_rel} relocations")


def build_host(srcs, out_dir):
    out_dir.mkdir(parents=True, exist_ok=True)
    work = Path(tempfile.mkdtemp(prefix="currents-"))
    cc = os.environ.get("CC", "cc")
    cxx = os.environ.get("CXX", "c++")
    for src in srcs:
        c = source(src, work)
        so = out_dir / f"{src.stem}.so"
        more, xflags = extras(c)
        inc = ["-I", str(SDK / "include"), "-I", str(SDK / "faust"), "-I", str(BASE_INC), "-I", str(work), *map(str, xflags)]
        objs = []
        for f in [c, *more]:
            o = work / (hashlib.sha1(str(Path(f).resolve()).encode()).hexdigest()[:8] + ".o")
            cpp = Path(f).suffix in (".cc", ".cpp")
            r = subprocess.run([cxx if cpp else cc, "-O2", "-fPIC", "-ffp-contract=off", "-w",
                                *(["-std=c99"] if not cpp else CXXFLAGS), *inc, "-c", str(f), "-o", str(o)],
                               capture_output=True, text=True)
            if r.returncode:
                sys.stderr.write(r.stderr)
                raise SystemExit(f"currents: {Path(f).name} ({src.name}) did not compile for the host")
            objs.append(str(o))
        r = subprocess.run([cxx if c.suffix == ".cc" else cc, "-shared", *objs, "-o", str(so)], capture_output=True, text=True)
        if r.returncode:
            sys.stderr.write(r.stderr)
            raise SystemExit(f"currents: {src.name} did not link for the host")
        print(f"host     {so.name}")


def run_emcc(args, src):
    r = subprocess.run(["emcc", *args], capture_output=True, text=True)
    if r.returncode:
        sys.stderr.write(r.stderr)
        raise SystemExit(f"currents: {Path(src).name} did not compile for the emulator")


def build_web(srcs, out_dir):
    """C sources for the emulator: a unit per current (it includes the current's own C with rc_entry renamed) and a
    registry of them by name (flow.c's PLAT_WEB lookup)"""
    out_dir.mkdir(parents=True, exist_ok=True)
    for old in out_dir.glob("*.c"):
        old.unlink()
    names = []
    cxx_srcs = [s for s in srcs if s.suffix in (".cc", ".pd")]
    if cxx_srcs and not shutil.which("emcc"):
        print(f"web      no emcc: {len(cxx_srcs)} C++ currents left out of the emulator")
        cxx_srcs = []
    if cxx_srcs:                                    # C++: compiled here (fm1-base compiles the web units as C), into
        cdir = out_dir / "cxx"                      # one archive the emulator links (fm1.toml web_link)
        if cdir.exists():
            shutil.rmtree(cdir)
        cdir.mkdir(parents=True)
        done = {}
        objs = []
        base = ["-O2", "-ffp-contract=off", "-DPLAT_HOST", "-DPLAT_WEB", *CXXFLAGS, "-w",
                "-I", str(SDK / "include"), "-I", str(BASE_INC)]
        for src in cxx_srcs:
            name = re.sub(r"\W", "_", src.stem)
            c = source(src, out_dir)
            more, xflags = extras(c)
            xf = [str(x) for x in xflags]
            o = cdir / f"cur_{name}.o"
            run_emcc([*base, *xf, "-I", str(SDK / "faust"), f"-Drc_entry=rc_entry_{name}", f"-DRC_WEB_ID={name}", "-c", str(c), "-o", str(o)], src)
            objs.append(str(o))
            for m in more:                          # the shared sources: once each, for their flags
                key = (str(m.resolve()), tuple(xf))
                if key not in done:
                    mo = cdir / f"lib_{len(done)}_{m.stem}.o"
                    run_emcc([*base, *xf, "-c", str(m), "-o", str(mo)], m)
                    done[key] = str(mo)
                    objs.append(str(mo))
            names.append((src.stem, name))
        lib = out_dir / "currents_cxx.a"
        if lib.exists():
            lib.unlink()
        subprocess.run(["emar", "rcs", str(lib), *objs], check=True)
        print(f"web      {len(cxx_srcs)} C++ currents in {lib.name}")
    for src in srcs:
        if src.suffix in (".cc", ".pd"):
            continue
        name = re.sub(r"\W", "_", src.stem)
        c = faust_to_c(src, out_dir) if src.suffix == ".dsp" else src
        unit = out_dir / f"cur_{name}.c"
        unit.write_text(f"/* generated by sdk/tools/currents.py: the current {src.stem}, for the emulator */\n"
                        f"#define rc_entry rc_entry_{name}\n#include \"{c.resolve()}\"\n")
        if src.suffix == ".dsp":                    # (the Faust files themselves are included, not units)
            (out_dir / f"{name}_faust.c").rename(out_dir / f"{name}_faust.inc")
            (out_dir / f"{name}_current.c").rename(out_dir / f"{name}_current.inc")
            txt = (out_dir / f"{name}_current.inc").read_text().replace(f'#include "{name}_faust.c"',
                                                                         f'#include "{name}_faust.inc"')
            (out_dir / f"{name}_current.inc").write_text(txt)
            unit.write_text(unit.read_text().replace(str(c.resolve()), str((out_dir / f"{name}_current.inc").resolve())))
        names.append((src.stem, name))
    reg = ["/* generated by sdk/tools/currents.py: the currents the emulator has, by name */",
           '#include "ripple_current.h"']
    reg += [f"const rc_desc_t *rc_entry_{n}(void);" for _, n in names]
    reg += ["const struct rc_web { const char *name; const rc_desc_t *(*entry)(void); } rc_web_list[] = {"]
    reg += [f'    {{"{stem}", rc_entry_{n}}},' for stem, n in names]
    reg += ["    {0, 0}};", ""]
    (out_dir / "registry.c").write_text("\n".join(reg))
    print(f"web      {len(names)} currents in {out_dir}")


def build_web_module(srcs, out_dir):
    """each current with sdk/web/rc_module.c into a standalone WebAssembly module (NAME.wasm), for Ripple's emulator
    page to run without it being linked in"""
    if not shutil.which("emcc"):
        raise SystemExit("currents: --web-module needs emcc (Emscripten)")
    out_dir.mkdir(parents=True, exist_ok=True)
    work = Path(tempfile.mkdtemp(prefix="currents-mod-"))
    for src in srcs:
        c = source(src, work)
        name = re.sub(r"\W", "_", src.stem)
        more, xflags = extras(c)
        xf = [str(x) for x in xflags]
        base = ["-O2", "-ffp-contract=off", "-DPLAT_WEB", f"-DRC_WEB_ID={name}", "-w", "-I", str(SDK / "include"),
                "-I", str(SDK / "faust"), "-I", str(BASE_INC), "-I", str(work), *xf]
        objs = []
        for i, f in enumerate([c, *more, SDK / "web" / "rc_module.c"]):
            o = work / f"{name}_{i}.o"
            cpp = Path(f).suffix in (".cc", ".cpp")
            run_emcc([*base, *(CXXFLAGS if cpp else ["-std=c99"]), "-c", str(f), "-o", str(o)], f)
            objs.append(str(o))
        wasm = out_dir / f"{src.stem}.wasm"
        run_emcc(["-O2", "-sSTANDALONE_WASM", "--no-entry", "-sSTACK_SIZE=65536", "-sINITIAL_MEMORY=4194304",
                  "-sFILESYSTEM=0", *objs, "-o", str(wasm)], src)
        print(f"module   {wasm.name}  {wasm.stat().st_size} B")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("srcs", nargs="+", type=Path)
    ap.add_argument("--out", type=Path)
    ap.add_argument("--host", type=Path)
    ap.add_argument("--web", type=Path)
    ap.add_argument("--web-module", type=Path)
    a = ap.parse_args()
    srcs = []                                       # a folder: its .dsp, .pd, .c and .cc files
    for s in a.srcs:
        s = s.resolve()
        srcs += sorted([*s.glob("*.dsp"), *s.glob("*.pd"), *s.glob("*.c"), *s.glob("*.cc")]) if s.is_dir() else [s] if s.exists() else []
    if a.host:
        build_host(srcs, a.host)
    if a.web:
        build_web(srcs, a.web)
    if a.web_module:
        build_web_module(srcs, a.web_module)
    if a.out:
        build_device(srcs, a.out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
