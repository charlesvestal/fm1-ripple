# Pd and Faust currents the supported way: Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers-extended-cc:subagent-driven-development (recommended) or superpowers-extended-cc:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Build Pd currents through an hvcc external generator and a set of named runtime overrides, and Faust currents from `faust -json`, instead of rewriting and scraping the compilers' C output with regular expressions, with every current coming out the same as today.

**Architecture:** `sdk/tools/currents.py` imports hvcc as a Python library (`hvcc.compile_dataflow`) and has it load `sdk/heavy/c2ripple.py` as an external generator. The generator gets the patch's parameters, MIDI inputs, tables and channel counts from hvcc as data (`ExternInfo`) and writes the current's wrapper from a Jinja template. The FM-1 needs a handful of Heavy's runtime files changed (no `double`, no C library, aligned loads, no `delete`). Those become committed copies in `sdk/heavy/static/`, each change listed in `sdk/heavy/PATCHES.md`, laid over hvcc's output the way hvcc's own c2owl generator lays its `deps` over it. `sdk/tools/currents.py` keeps what is Ripple's: running the tools, measuring a patch's memory on the computer, keeping generated C for builders without hvcc, and building `.cur` files. A baseline taken first, of every current's name, channels, voices, parameters and sizes, proves nothing changed.

**Tech Stack:** Python 3.12 with hvcc 0.17.3 (pinned) and Jinja2 (hvcc's own dependency); Faust 2.x `-json`; C/C++ for the JieLi pi32v2 toolchain; Ripple's shell tests and host simulator.

**User decisions (already made):**
- "Sure": redo the Pd path as an hvcc external generator (after dreamer, hvcc's maintainer, called the regex rewriting wrong).
- Nothing goes upstream to hvcc: Wasted Audio does not accept AI-generated contributions (CONTRIBUTING.md, "Use of AI and LLMs").
- Faust gets the same treatment, as a separate final task ("Was our Faust approach wrong": partly, the scraping).
- Current names stay as released in 0.6.1 (`macro-*`, plain Pd names).
- The wrapper comes from a custom generator rendering Jinja2 templates, not built line by line (hvcc's maintainer's advice, relayed by the user).
- hvcc is used as a Python library (`hvcc.compile_dataflow`), not run as an external tool (same source).

---

## Background for the engineer

- A **current** is a sound module for Ripple, a firmware for the M-VAVE FM-1. `sdk/include/ripple_current.h` defines its descriptor (`rc_desc_t`): name, state size, inputs (0 or 2), voices, parameters (`rc_param_t`: name, min, max, default) and the `init`, `set`, `note` and `process` functions. `sdk/tools/currents.py` builds sources into `.cur` files for the FM-1 (`--out`), shared libraries for the host simulator (`--host`) and WebAssembly (`--web-module`).
- The FM-1 has a single-precision FPU and no C library for currents. A current's build fails if any soft-double routine (`__*df*`) is linked in, or if anything needs a constructor run at load, an exception table or `operator new`/`delete` (`build_device` in `currents.py`).
- **Today's Pd path** (`pd_to_cc` in `currents.py`): runs hvcc for C, rewrites every file with `heavy_rewrite` (regexes: `double` to `float`, float literals, `va_arg`, removing `#include <new>` and `<math.h>`, `virtual ~`, the `extern "C"` block in `Heavy_NAME.cpp`, `delete c`, the SSE fence, the hash), scrapes parameters, channels and tables out of `Heavy_NAME.cpp/.hpp` with regexes, then writes the wrapper `NAME_current.cc` line by line from Python. Heavy's shared runtime is kept in `sdk/heavy/runtime/`; each patch's own files and wrapper in `gen/NAME_heavy/` beside it.
- **Today's Faust path** (`faust_to_c`): runs `faust -lang c -single`, swaps `<math.h>` for `faust_shim.h`, and scrapes `addHorizontalSlider` calls and `getNumInputs` with regexes.
- **hvcc external generators:** a Python module with one subclass of `hvcc.types.compiler.Generator`, loaded with `hvcc PATCH -G MODULE` (hvcc adds the current directory to `sys.path`; set `PYTHONPATH` to load it from elsewhere). Its `compile()` gets `c_src_dir` (hvcc's C), `out_dir`, `externs: ExternInfo`, `patch_name`, `num_input_channels`, `num_output_channels` and `copyright`. `ExternInfo.parameters.inParam` is a list of `(name, IRReceiver)`, where `IRReceiver.hash` is `"0xF89F9F3E"` and `IRReceiver.attributes` is `{'min': 100.0, 'max': 8000.0, 'default': 1200.0, 'type': 'float'}`. `ExternInfo.midi.inMidi` lists names such as `'__hv_notein'`. `ExternInfo.tables` is a list of `(name, IRTable)` for `@hv_table` tables, with `IRTable.hash`. Reference: hvcc's `docs/generators/custom.md` and `hvcc/generators/c2owl/c2owl.py`.
- **Tools on this Mac:** hvcc in a venv, `uv venv -p 3.12 ~/.venvs/hvcc && uv pip install -p ~/.venvs/hvcc/bin/python hvcc==0.17.3 jinja2`. hvcc needs Python 3.10 or newer, and the system `python3` here is 3.9: run `currents.py` with `~/.venvs/hvcc/bin/python` (written `$PYH` below: `export PYH=~/.venvs/hvcc/bin/python`) when Pd patches should be compiled again. With a Python that has no hvcc, `currents.py` builds Pd currents from the kept files, as the release builder does. Faust is `/opt/homebrew/bin/faust`. The FM-1 toolchain runs in podman: `export PATH=~/github/fm1-parent/bin:$PATH` (and `podman machine start` once).
- **Tests:** `sh tests/run_tests.sh` (with `PYTHON=/opt/homebrew/bin/python3.14`) runs everything; `sh tests/pd_examples.sh` runs the four Pd droplets.

## Files

| File | What it is |
|---|---|
| `tests/host/currents_snapshot.py` (new) | Builds every Faust and Pd current and writes what each is (name, ins, voices, params, state, image size) as JSON |
| `tests/host/currents_baseline.json` (new) | That snapshot, taken before the change |
| `sdk/heavy/static/` (new) | Ripple's copies of the Heavy runtime files the FM-1 needs changed, plus `HvUtils.h`, `heavy_shim.c` and a `new` header |
| `sdk/heavy/PATCHES.md` (new) | Each change in `static/` against hvcc 0.17.3, and why |
| `sdk/heavy/c2ripple.py` (new) | The hvcc external generator |
| `sdk/heavy/templates/current.cc` (new) | The wrapper's Jinja template |
| `sdk/tools/currents.py` | Pd path calls the generator; `heavy_rewrite`, `FLOAT_LIT`, the regex scraping and the Python-built wrapper go; Faust path reads `-json` |
| `sdk/heavy/HvUtils.h`, `sdk/heavy/heavy_shim.c` | Move into `sdk/heavy/static/` |
| `sdk/README.md`, `LICENSING.md` | Say how it works now |

---

### Task 1: A snapshot of every current, before anything changes

**Goal:** A script that builds every Faust and Pd current and records what each one is, and its output from today's code committed as the baseline.

**Files:**
- Create: `tests/host/currents_snapshot.py`
- Create: `tests/host/currents_baseline.json`

**Acceptance Criteria:**
- [ ] `python3 tests/host/currents_snapshot.py --out /tmp/snap.json` exits 0 and lists every `.dsp` in `currents/` and every `.pd` in `currents/pd/` and `currents/pd/community/` (5 Faust, 11 Pd today)
- [ ] For each current the JSON has `name`, `ins`, `voices`, `params` (list of `[name, min, max, def]`), `state` and `image`
- [ ] `tests/host/currents_baseline.json` is committed, made from today's code

**Verify:** `python3 tests/host/currents_snapshot.py --out /tmp/snap.json && python3 -c "import json;d=json.load(open('/tmp/snap.json'));print(len(d))"` → `16`

**Steps:**

- [ ] **Step 1: Write the snapshot script**

It builds for the FM-1 (the `.cur` header and descriptor are the truth: what the firmware reads) and reads each `.cur` the way `app/flow.c` does.

```python
#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# Copyright (C) 2026 Charles Vestal
"""Every Faust and Pd current built for the FM-1, and what each one is, as JSON: its name, inputs, voices,
parameters, state and image size. tests/host/currents_baseline.json is this from before the hvcc generator; a
change to how currents are made must give the same, but for image sizes within a few percent.
  currents_snapshot.py --out FILE.json"""
import argparse, json, struct, subprocess, sys, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SOURCES = sorted(ROOT.glob("currents/*.dsp")) + sorted(ROOT.glob("currents/pd/*.pd")) + \
    sorted(ROOT.glob("currents/pd/community/*.pd"))


def describe(cur):
    """the .cur file read as app/flow.c reads it: header, then the descriptor found by its magic"""
    b = cur.read_bytes()
    magic, _ver, _info, image, bss, _entry, nrel, _sum, state = struct.unpack_from("<IHHIIIIII", b, 0)
    assert magic == 0x52554352, cur
    img = b[32:32 + image]
    for k in range(0, len(img) - 32, 4):
        m, abi, name_p, st, ins, voices, nparams, params_p = struct.unpack_from("<IIIIBBHI", img, k)
        if m == 0x52435231 and abi in (1, 2):
            break
    else:
        raise SystemExit(f"{cur}: no descriptor")

    def cstr(p):
        return img[p:img.index(b"\0", p)].decode()
    params = []
    for i in range(nparams):
        n_p, lo, hi, de = struct.unpack_from("<Ifff", img, params_p + 16 * i)
        params.append([cstr(n_p), round(lo, 6), round(hi, 6), round(de, 6)])
    return {"name": cstr(name_p), "ins": ins, "voices": voices, "params": params, "state": st,
            "image": image + bss}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", type=Path, required=True)
    a = ap.parse_args()
    out = Path(tempfile.mkdtemp(prefix="snap-"))
    r = subprocess.run([sys.executable, str(ROOT / "sdk/tools/currents.py"), *map(str, SOURCES), "--out", str(out)],
                       cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        sys.stderr.write(r.stdout[-3000:] + r.stderr[-3000:])
        return 1
    snap = {s.stem: describe(out / f"{s.stem}.cur") for s in SOURCES}
    a.out.write_text(json.dumps(snap, indent=1, sort_keys=True) + "\n")
    print(f"{len(snap)} currents")
    return 0


if __name__ == "__main__":
    sys.exit(main())
```

The pointers inside the image are offsets from 0 (the image is linked at 0 and relocated by the firmware), so `cstr(name_p)` reads straight from the image.

- [ ] **Step 2: Run it and check it reads correctly**

Run: `export PATH=~/github/fm1-parent/bin:$PATH; python3 tests/host/currents_snapshot.py --out tests/host/currents_baseline.json && python3 -c "import json;d=json.load(open('tests/host/currents_baseline.json'));print(d['pdsaw']);print(d['voice']['params'][:2])"`
Expected: `16 currents`, then pdsaw with `"params": [["cutoff", 100.0, 8000.0, 1200.0], ["volume", 0.0, 1.0, 0.5]]`, `"ins": 0`, `"voices": 1`, and two of `voice`'s parameters. If the descriptor isn't found, print `img[:64].hex()` for one current and compare the field order with `rc_desc_t` in `sdk/include/ripple_current.h`.

- [ ] **Step 3: Commit**

```bash
git add tests/host/currents_snapshot.py tests/host/currents_baseline.json
git commit -m "Currents: a snapshot of what each Faust and Pd current is, and the baseline before the hvcc generator"
```

```json:metadata
{"files": ["tests/host/currents_snapshot.py", "tests/host/currents_baseline.json"], "verifyCommand": "python3 tests/host/currents_snapshot.py --out /tmp/snap.json", "acceptanceCriteria": ["snapshot lists 16 currents", "each has name, ins, voices, params, state, image", "baseline committed from today's code"], "modelTier": "standard"}
```

---

### Task 2: Heavy's runtime changes as named files, not regexes

**Goal:** `sdk/heavy/static/` holds Ripple's copies of the Heavy runtime files that need changing for the FM-1, documented one by one in `sdk/heavy/PATCHES.md`, and `currents.py` lays them over hvcc's output instead of running `heavy_rewrite` on the runtime.

**Files:**
- Create: `sdk/heavy/static/` (files listed below), `sdk/heavy/PATCHES.md`
- Move: `sdk/heavy/HvUtils.h` → `sdk/heavy/static/HvUtils.h`, `sdk/heavy/heavy_shim.c` → `sdk/heavy/static/heavy_shim.c`
- Modify: `sdk/tools/currents.py` (`pd_to_cc`, `heavy_runtime`)

**Acceptance Criteria:**
- [ ] `sdk/heavy/static/` has exactly the files whose runtime copy differs from hvcc 0.17.3's (today: `HeavyContext.cpp`, `HeavyContext.hpp`, `HeavyContextInterface.hpp`, `HvControlPack.c`, `HvHeavy.cpp`, `HvHeavy.h`, `HvLightPipe.c`, `HvMath.h`, `HvSignalBiquad.c`, `HvSignalEnvelope.c`, `HvSignalPhasor.c`, `HvSignalPhasor.h`, `HvUtils.c`), plus `HvUtils.h`, `heavy_shim.c` and `new`
- [ ] Every one of them is in `PATCHES.md` with what changed and why
- [ ] `heavy_rewrite` is no longer applied to runtime files; the runtime is hvcc's files with `static/` laid over them
- [ ] The build of all 11 Pd currents passes, and `tests/host/currents_snapshot.py` matches the baseline

**Verify:** `python3 tests/host/currents_snapshot.py --out /tmp/snap.json && diff <(python3 -c "import json;d=json.load(open('/tmp/snap.json'));[print(k,v['ins'],v['voices'],v['params'],v['state']) for k,v in sorted(d.items())]") <(python3 -c "import json;d=json.load(open('tests/host/currents_baseline.json'));[print(k,v['ins'],v['voices'],v['params'],v['state']) for k,v in sorted(d.items())]")` → no output

**Steps:**

- [ ] **Step 1: Make the overlay from what is committed today**

The rewritten files in `sdk/heavy/runtime/` are already exactly what the FM-1 needs. Copy the ones that differ from hvcc's originals:

```bash
O=$($PYH -c "import hvcc,os;print(os.path.dirname(hvcc.__file__))")/generators/ir2c/static
mkdir -p sdk/heavy/static
for f in sdk/heavy/runtime/*; do b=$(basename $f); [ -f $O/$b ] && ! cmp -s $O/$b $f && cp $f sdk/heavy/static/$b; done
git mv sdk/heavy/HvUtils.h sdk/heavy/static/HvUtils.h
git mv sdk/heavy/heavy_shim.c sdk/heavy/static/heavy_shim.c
ls sdk/heavy/static
```

Expected: the 13 files listed in the acceptance criteria, `HvUtils.h` and `heavy_shim.c`.

- [ ] **Step 2: Add the `new` header**

hvcc's `Heavy_NAME.cpp` says `#include <new>` for placement `new`. Currents build with `-nostdinc++`, so give it a header of its own instead of deleting the include:

`sdk/heavy/static/new`:
```cpp
// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// <new> for Heavy's C++ in a Ripple current (built with -nostdinc++): placement new, which Heavy_NAME.cpp's
// hv_NAME_new uses. Nothing in a current calls the allocating new or delete.
#ifndef RIPPLE_NEW
#define RIPPLE_NEW
#include <stddef.h>
inline void *operator new(size_t, void *p) noexcept { return p; }
#endif
```

- [ ] **Step 3: Write `sdk/heavy/PATCHES.md`**

For each file, run `diff -u $O/FILE sdk/heavy/static/FILE`, and write one entry: the file, the change, and why. Use this structure (fill in each file's own lines from its diff):

```markdown
# Heavy's runtime for the FM-1

Ripple builds hvcc 0.17.3's runtime (its `ir2c/static` files, ISC, Enzien Audio and Wasted Audio) with these files
replaced by the copies in `static/`. A current runs on the FM-1's single-precision FPU, with no C library and no
allocator: these are the changes that needs. `sdk/tools/currents.py` lays `static/` over hvcc's output.

| File | Change | Why |
|---|---|---|
| `HvUtils.h` | Ripple's own: no platform detection, no SIMD, maths from `fastmath.h`, `hv_malloc` from the current's arena, no-op spinlocks | No C library; the arena is the current's state |
| `HvUtils.c` | `hv_string_to_hash` reads the string byte by byte (hvcc's Emscripten path) | The FM-1 faults on unaligned word loads |
| `HvLightPipe.c` | `hv_sfence()` is a compiler barrier; no `xmmintrin.h` or `arm_acle.h` | Set and render never run at once; on an x86 host the SSE header brought in `stdlib.h` |
| `HeavyContextInterface.hpp`, `HeavyContext.hpp` | Destructors not virtual; `double` to `float` | A virtual destructor emits a deleting destructor that calls `operator delete` |
| `HeavyContext.cpp`, `HvHeavy.cpp`, `HvControlPack.c` | `va_arg(ap, double)` read as its 64 bits and converted without a double operation (`RC_HV_VA_FLOAT`); `double` to `float`; `HvHeavy.cpp`'s `delete c` removed | No soft-double routines in a current |
| `HvHeavy.h`, `HvMath.h`, `HvSignalBiquad.c`, `HvSignalEnvelope.c`, `HvSignalPhasor.c`, `HvSignalPhasor.h` | `double` to `float`, and double literals made float | No soft-double routines in a current |
| `heavy_shim.c` | Ripple's own: the arena allocator, string and memory routines, `__cxa_pure_virtual` | No C library |
| `new` | Ripple's own: placement `new` | Built with `-nostdinc++` |
```

Check each row against its diff and correct it. In particular, list `HvMath.h`'s two-line change exactly.

- [ ] **Step 4: Lay `static/` over hvcc's files in `currents.py`**

In `pd_to_cc`, replace the loop that rewrites every file:

```python
    files = {}
    for f in sorted(out.iterdir()):
        if f.name == "HvUtils.h" or f.suffix not in (".c", ".cpp", ".h", ".hpp"):
            continue
        files[f.name] = heavy_rewrite(f.read_text(), f.name, name)
```

with the overlay (patch files still rewritten in this task; Task 4 removes that):

```python
    files = {}
    for f in sorted(out.iterdir()):
        if f.suffix not in (".c", ".cpp", ".h", ".hpp"):
            continue
        if f.name.startswith(f"Heavy_{name}."):
            files[f.name] = heavy_rewrite(f.read_text(), f.name, name)    # (until the generator: Task 4)
        else:
            files[f.name] = f.read_text()
    for f in sorted(HV_STATIC.iterdir()):                                  # Ripple's runtime files (PATCHES.md)
        if f.name in files or f.name in ("HvUtils.h", "heavy_shim.c", "new"):
            files[f.name] = f.read_text()
```

Add `HV_STATIC = SDK / "heavy" / "static"` next to `HV_RUNTIME`. In `heavy_runtime`, the shim and `new` must reach the runtime too: after `heavy_runtime(...)` is called, the runtime dir must hold `HvUtils.h`, `heavy_shim.c` and `new`. Change the wrapper's lines that name them:

```python
         f"// ripple-sources: *.cpp {rt}/*.c {rt}/*.cpp",
         f"// ripple-cflags: -I. -I{rt}",
```

(`heavy_shim.c` now sits in the runtime dir; `-I{sh}` is no longer needed.) Remove the lines that read `SDK / "heavy" / "HvUtils.h"` and `SDK / "heavy" / "heavy_shim.c"` into `files` (the overlay loop does it).

- [ ] **Step 5: Regenerate and compare**

Run:
```bash
export PATH=~/github/fm1-parent/bin:$PATH
rm -rf sdk/heavy/runtime
$PYH sdk/tools/currents.py currents/pd currents/pd/community --host app/build/currents-host
git diff --stat sdk/heavy/runtime | tail -1
python3 tests/host/currents_snapshot.py --out /tmp/snap.json
```
Expected: the runtime's files are byte-identical to before except the new `heavy_shim.c`, `HvUtils.h` and `new` (`git status sdk/heavy/runtime`), `16 currents`, and the Verify command prints nothing.

- [ ] **Step 6: Run the tests and commit**

Run: `PYTHON=/opt/homebrew/bin/python3.14 sh tests/run_tests.sh` → `all tests passed`

```bash
git add -A sdk/heavy sdk/tools/currents.py currents/pd
git commit -m "Heavy's runtime for the FM-1 as named files (sdk/heavy/static, PATCHES.md), laid over hvcc's, not regexes"
```

```json:metadata
{"files": ["sdk/heavy/static/", "sdk/heavy/PATCHES.md", "sdk/tools/currents.py"], "verifyCommand": "python3 tests/host/currents_snapshot.py --out /tmp/snap.json", "acceptanceCriteria": ["static/ holds exactly the changed runtime files plus HvUtils.h, heavy_shim.c, new", "each listed in PATCHES.md", "runtime no longer rewritten by regex", "snapshot matches baseline"], "modelTier": "standard"}
```

---

### Task 3: The hvcc external generator and its template

**Goal:** `sdk/heavy/c2ripple.py` and `sdk/heavy/templates/current.cc`, which hvcc runs with `-G c2ripple` to write a patch's wrapper from the data hvcc gives it.

**Files:**
- Create: `sdk/heavy/c2ripple.py`, `sdk/heavy/templates/current.cc`

**Acceptance Criteria:**
- [ ] `PYTHONPATH=sdk/heavy $PYH -m hvcc currents/pd/pdsaw.pd -o /tmp/g -n pdsaw -G c2ripple` writes `/tmp/g/ripple/pdsaw_current.cc` and `/tmp/g/ripple/ripple.json`
- [ ] `ripple.json` for pdsaw: `{"ins": 0, "outs": 2, "notes": true, "params": [["cutoff", "0xF89F9F3E", 100.0, 8000.0, 1200.0], ["volume", "0xB1642755", 0.0, 1.0, 0.5]]}`
- [ ] The wrapper for pdsaw is the same as today's `currents/pd/gen/pdsaw_heavy/pdsaw_current.cc` except for its first three lines and the `HEAP` line (both now come from elsewhere: Task 4)
- [ ] For a logue-style patch (`app/build/community/lg_Pluck/lg_Pluck.pd`, or `loguesdk_hvcc_examples/pd/Pluck.pd` from github.com/boochow/loguesdk_hvcc_examples), the wrapper has the `held` note logic and fills `noise_r`

**Verify:** `PYTHONPATH=sdk/heavy $PYH -m hvcc currents/pd/pdsaw.pd -o /tmp/g -n pdsaw -G c2ripple && cat /tmp/g/ripple/ripple.json` (the generator on its own, through hvcc's command line; Task 4 calls it through the library)

**Steps:**

- [ ] **Step 1: Write the generator**

`sdk/heavy/c2ripple.py`:
```python
# SPDX-License-Identifier: MIT
# Copyright (C) 2026 Charles Vestal
"""hvcc's external generator for Ripple currents (hvcc PATCH -G c2ripple, with sdk/heavy on PYTHONPATH): the patch's
wrapper, NAME_current.cc, from templates/current.cc and what hvcc knows of the patch (ExternInfo), and ripple.json,
what the wrapper was made from, for sdk/tools/currents.py. The wrapper makes the patch a current
(sdk/include/ripple_current.h):
- [r NAME @hv_param MIN MAX DEFAULT] are its parameters;
- [notein] takes its notes, or, with the logue SDK's convention (boochow's hvcc_loguesdk), [r pitch] in Hz or
  [r pitch_note], with bangs on [r noteon_trig] and [r noteoff_trig];
- a [table NAME_r @hv_table] is filled with white noise before each block (the same convention);
- [adc~] makes it an effect (it processes the bus), else it adds its sound."""
import json
import time
from pathlib import Path

import jinja2

from hvcc.types.compiler import CompilerResp, ExternInfo, Generator
from hvcc.types.meta import Meta

HERE = Path(__file__).resolve().parent
LOGUE_NOTE = ("pitch", "pitch_note", "noteon_trig", "noteoff_trig")
POOL_KB, IN_QUEUE_KB = 2, 1          # Heavy's message pool and input queue: Ripple's RAM is small (hvcc's default: 10)


class c2ripple(Generator):
    @classmethod
    def compile(cls, c_src_dir: Path, out_dir: Path, externs: ExternInfo, patch_name: str, patch_meta: Meta,
                num_input_channels: int = 0, num_output_channels: int = 0, copyright: str | None = None,
                verbose: bool | None = False) -> CompilerResp:
        tick = time.time()
        out = Path(out_dir, "ripple")
        out.mkdir(parents=True, exist_ok=True)
        params = [(n, r.hash, float(r.attributes.get("min", 0.0)), float(r.attributes.get("max", 1.0)),
                   float(r.attributes.get("default", 0.5))) for n, r in externs.parameters.inParam]
        notein = "__hv_notein" in externs.midi.inMidi
        logue = {} if notein else {p[0]: p[1] for p in params if p[0] in LOGUE_NOTE}
        params = [p for p in params if p[0] not in logue]
        noise = [(n, t.hash) for n, t in externs.tables if n.endswith("_r")]
        ins, outs = num_input_channels, num_output_channels
        if ins not in (0, 1, 2) or outs not in (1, 2):
            raise ValueError(f"{patch_name}: {ins} inputs, {outs} outputs ([adc~] 0..2, [dac~] 1..2)")
        env = jinja2.Environment(loader=jinja2.FileSystemLoader(HERE / "templates"), trim_blocks=True,
                                 lstrip_blocks=True, keep_trailing_newline=True)
        (out / f"{patch_name}_current.cc").write_text(env.get_template("current.cc").render(
            name=patch_name, params=params, notein=notein, logue=logue, noise=noise, ins=ins, outs=outs,
            pool_kb=POOL_KB, in_queue_kb=IN_QUEUE_KB))
        (out / "ripple.json").write_text(json.dumps({
            "ins": ins, "outs": outs, "notes": bool(notein or logue),
            "params": [[n, h, lo, hi, d] for n, h, lo, hi, d in params]}) + "\n")
        return CompilerResp(stage="c2ripple", in_dir=c_src_dir, out_dir=out, compile_time=time.time() - tick)
```

Note: hvcc's `-n NAME` sets `patch_name` (currents.py passes the current's name with `\W` made `_`). The current's display name (with hyphens, e.g. `macro-va`) is not known here; the template takes it from a `-D` define instead (Step 2), passed in Task 4.

- [ ] **Step 2: Write the template**

`sdk/heavy/templates/current.cc` reproduces today's wrapper (see `currents/pd/gen/pdsaw_heavy/pdsaw_current.cc` and `pd_to_cc`). The three header lines and `HEAP` come from `currents.py` (Task 4) through `ripple_heavy.h`, which it writes beside the wrapper:

```cpp
// generated by sdk/heavy/c2ripple.py (hvcc -G c2ripple) from {{ name }}: a Ripple current
#include "ripple_heavy.h"                /* RC_NAME (the current's name) and HEAP: sdk/tools/currents.py */
#include "ripple_current.h"
#include "Heavy_{{ name }}.hpp"

typedef struct { char *base; size_t size, used, peak_fail; } rc_hv_arena_t;
extern "C" rc_hv_arena_t *rc_hv_arena;

typedef struct {
    alignas(8) char obj[sizeof(Heavy_{{ name }})];
    rc_hv_arena_t arena;
    alignas(8) char heap[HEAP];
    float in[2][256], out[2][256];
    int held;                               /* the logue way's note playing, -1 none */
    uint32_t rnd;                           /* the noise tables' generator */
} st_t;

static const rc_param_t P[] = {
{% for n, h, lo, hi, d in params %}
    {"{{ n }}", {{ lo }}f, {{ hi }}f, {{ d }}f},
{% else %}
    {"", 0.0f, 0.0f, 0.0f},
{% endfor %}
};
static const hv_uint32_t H[] = {{ '{' }}{% for p in params %}{{ p[1] }}{{ ", " if not loop.last }}{% else %}0{% endfor %}{{ '}' }};

static Heavy_{{ name }} *hv(st_t *s)
{
    rc_hv_arena = &s->arena;                 /* (Heavy takes a little more as messages queue) */
    return reinterpret_cast<Heavy_{{ name }} *>(s->obj);
}

static void set(void *p, int k, float v)
{
    if (k >= 0 && k < (int)(sizeof(H) / sizeof(H[0])) && H[k]) hv((st_t *)p)->sendFloatToReceiver(H[k], v);
}

static void init(void *p, float sr)
{
    st_t *s = (st_t *)p;
    s->arena.base = s->heap;
    s->held = -1;
    s->rnd = 22222u;
    s->arena.size = HEAP;
    rc_hv_arena = &s->arena;
    new (s->obj) Heavy_{{ name }}(sr, {{ pool_kb }}, {{ in_queue_kb }}, 0);
    for (int k = 0; k < {{ params|length }}; k++) set(p, k, P[k].def);
}
{% if notein %}

static void note(void *p, int nt, float vel)
{
    HvMessage *m = HV_MESSAGE_ON_STACK(3);   /* [notein]: note, velocity 0..127, channel 1 */
    msg_init(m, 3, 0);
    msg_setFloat(m, 0, (float)nt);
    msg_setFloat(m, 1, vel * 127.0f);
    msg_setFloat(m, 2, 1.0f);
    hv((st_t *)p)->sendMessageToReceiver(0x67E37CA3, 0.0f, m);
}
{% elif logue %}

static void note(void *p, int nt, float vel)
{
    st_t *s = (st_t *)p;
    if (vel <= 0.0f) {                       /* the note playing let go: noteoff_trig */
        if (nt == s->held) {
            s->held = -1;
{% if "noteoff_trig" in logue %}
            hv(s)->sendBangToReceiver({{ logue["noteoff_trig"] }});
{% endif %}
        }
        return;
    }
    s->held = nt;
{% if "pitch" in logue %}
    hv(s)->sendFloatToReceiver({{ logue["pitch"] }}, 440.0f * fm_exp2f((float)(nt - 69) / 12.0f));
{% endif %}
{% if "pitch_note" in logue %}
    hv(s)->sendFloatToReceiver({{ logue["pitch_note"] }}, (float)nt);
{% endif %}
{% if "noteon_trig" in logue %}
    hv(s)->sendBangToReceiver({{ logue["noteon_trig"] }});
{% endif %}
}
{% endif %}

static void process(void *p, float *l, float *r, int n)
{
    st_t *s = (st_t *)p;
    float *in[2] = {s->in[0], s->in[1]}, *out[2] = {s->out[0], s->out[1]};
{% if ins == 2 %}
    for (int i = 0; i < n; i++) { s->in[0][i] = l[i]; s->in[1][i] = r[i]; }
{% elif ins == 1 %}
    for (int i = 0; i < n; i++) s->in[0][i] = 0.5f * (l[i] + r[i]);
{% endif %}
{% for tname, h in noise %}
    { float *b = hv(s)->getBufferForTable({{ h }}); int k = hv(s)->getLengthForTable({{ h }});   /* {{ tname }} */
      while (b && k--) { s->rnd = s->rnd * 1664525u + 1013904223u; *b++ = (float)(int32_t)s->rnd * 4.656613e-10f; } }
{% endfor %}
    hv(s)->process(in, out, n);
{% set rr = "s->out[1]" if outs == 2 else "s->out[0]" %}
{% if ins %}
    for (int i = 0; i < n; i++) { l[i] = s->out[0][i]; r[i] = {{ rr }}[i]; }
{% else %}
    for (int i = 0; i < n; i++) { l[i] += s->out[0][i]; r[i] += {{ rr }}[i]; }
{% endif %}
}

static const rc_desc_t D = {RC_MAGIC, RC_ABI, RC_NAME, sizeof(st_t), {{ 2 if ins else 0 }}, {{ 1 if (notein or logue) else 0 }}, {{ params|length }}, P, init, set, {{ "note" if (notein or logue) else "0" }}, process, 0, {0}, 0, 0};
extern "C" RC_EXPORT(D)
```

Floats in `P[]`: Jinja prints Python floats as `100.0`, so `{{ lo }}f` gives `100.0f`; a value like `1e-05` prints as `1e-05f`, which is valid C. The placement `new` comes from `static/new` through `Heavy_NAME.hpp`'s chain once Task 4 stops removing `#include <new>`; until then keep a local `inline void *operator new(size_t, void *p) noexcept { return p; }` line in the template after the includes, guarded with `#ifndef RIPPLE_NEW`.

- [ ] **Step 3: Run it on pdsaw and a logue patch**

Run:
```bash
export PYH=~/.venvs/hvcc/bin/python
PYTHONPATH=sdk/heavy $PYH -m hvcc currents/pd/pdsaw.pd -o /tmp/g -n pdsaw -G c2ripple >/dev/null && cat /tmp/g/ripple/ripple.json
diff <(sed 1,3d currents/pd/gen/pdsaw_heavy/pdsaw_current.cc | grep -v "define HEAP\|operator new") <(sed 1,4d /tmp/g/ripple/pdsaw_current.cc | grep -v "operator new")
```
Expected: the JSON in the acceptance criteria. The diff shows only the descriptor's name (`"pdsaw"` against `RC_NAME`). Any other difference is a template bug: fix the template.

For the logue case, run it on boochow's `Pluck.pd` (`-p` its folder) and check the wrapper has `s->held = nt;`, a `sendBangToReceiver` for `noteon_trig`, and the `noise_r` fill loop.

- [ ] **Step 4: Commit**

```bash
git add sdk/heavy/c2ripple.py sdk/heavy/templates/current.cc
git commit -m "c2ripple: an hvcc external generator for Ripple currents, the wrapper from a template and hvcc's ExternInfo"
```

```json:metadata
{"files": ["sdk/heavy/c2ripple.py", "sdk/heavy/templates/current.cc"], "verifyCommand": "PYTHONPATH=sdk/heavy $PYH -m hvcc currents/pd/pdsaw.pd -o /tmp/g -n pdsaw -G c2ripple && cat /tmp/g/ripple/ripple.json", "acceptanceCriteria": ["writes NAME_current.cc and ripple.json", "pdsaw ripple.json matches", "wrapper matches today's but for header lines and HEAP", "logue patch gets held-note logic and noise fill"], "modelTier": "standard"}
```

---

### Task 4: currents.py builds Pd currents through the generator

**Goal:** `pd_to_cc` compiles the patch through hvcc's Python library with the `c2ripple` generator and keeps its output; `heavy_rewrite`, `FLOAT_LIT`, `LOGUE_NOTE`, the regex scraping and the Python-built wrapper are gone; every current matches the baseline.

**Files:**
- Modify: `sdk/tools/currents.py` (`pd_to_cc`, `heavy_rewrite`, `heavy_heap`, module constants)
- Modify: `sdk/heavy/static/HvUtils.h` (one line, Step 2)
- Regenerate: `currents/pd/gen/`, `currents/pd/community/gen/`, `sdk/heavy/runtime/`

**Acceptance Criteria:**
- [ ] `grep -n "heavy_rewrite\|FLOAT_LIT\|getNumInputChannels\|info->name" sdk/tools/currents.py` finds nothing
- [ ] `Heavy_NAME.*` files are kept exactly as hvcc writes them (no rewriting at all)
- [ ] `tests/host/currents_snapshot.py` matches the baseline for every current: `name`, `ins`, `voices`, `params`, `state`; `image` within 5%
- [ ] `PYTHON=/opt/homebrew/bin/python3.14 sh tests/run_tests.sh` → `all tests passed`

**Verify:** the Verify command of Task 2, plus `python3 -c "import json;a=json.load(open('/tmp/snap.json'));b=json.load(open('tests/host/currents_baseline.json'));print([k for k in a if abs(a[k]['image']-b[k]['image'])>0.05*b[k]['image']])"` → `[]`

**Steps:**

- [ ] **Step 1: Compile through hvcc's library with the generator**

Replace the `shutil.which(hvcc)` test and the `subprocess.run([hvcc, ...])` call in `pd_to_cc`. hvcc is imported only when a Pd patch is compiled, and only if the running Python has it:

```python
def hvcc_lib():
    """hvcc's compile_dataflow, if this Python has hvcc (3.10 or newer, pip install hvcc), with Ripple's generator
    (sdk/heavy/c2ripple.py) where it can import it; else None: the kept files are used"""
    try:
        import hvcc
    except ImportError:
        return None
    if str(SDK / "heavy") not in sys.path:
        sys.path.insert(0, str(SDK / "heavy"))
    return hvcc.compile_dataflow
```

In `pd_to_cc`:

```python
    compile_dataflow = hvcc_lib()
    if compile_dataflow is None:
        if not wrapper.exists():
            raise SystemExit(f"currents: no hvcc in this Python ({sys.version.split()[0]}), and no {wrapper} to use "
                             "instead (run with a Python that has hvcc: pip install hvcc)")
        return wrapper
    tmp = Path(tempfile.mkdtemp(prefix="hvcc-"))
    results = compile_dataflow(pd, tmp, patch_name=name, copyright=patch_copyright(pd),
                               search_paths=[pd.parent / "lib", SDK / "heavy" / "heavylib"],
                               ext_generators=["c2ripple"])
    errors = [m.message for r in results.root.values() for m in r.notifs.errors]
    if errors or not (tmp / "ripple" / "ripple.json").exists():
        sys.stderr.write("\n".join(errors) + "\n")
        raise SystemExit(f"currents: hvcc failed on {pd}")
    made = json.loads((tmp / "ripple" / "ripple.json").read_text())
```

Check the exact keyword names against `hvcc/compiler.py`'s `compile_dataflow` signature in the installed version (0.17.3: `in_path, out_dir, patch_name, patch_meta_file, search_paths, generators, ext_generators, verbose, copyright, nodsp, gui`). If hvcc prints its own progress to stdout, wrap the call in `contextlib.redirect_stdout(io.StringIO())` and print that text only on failure. Remove the `HVCC` environment variable from the module docstring.

Then build `files` from hvcc's C (`tmp / "c"`), unchanged, with `static/` over it (Task 2's loop, without the `heavy_rewrite` branch), and add the wrapper `tmp / "ripple" / f"{name}_current.cc"`. Measure the heap (`heavy_heap(files, name, tmp)`, unchanged). Write `ripple_heavy.h` beside the wrapper in the kept folder, and put the source lines at the top of the wrapper there:

```python
    sh_rt = os.path.relpath(HV_RUNTIME, kept)
    head = (f"// ripple-sources: *.cpp {sh_rt}/*.c {sh_rt}/*.cpp\n"
            f"// ripple-cflags: -I. -I{sh_rt}\n")
    files[wrapper.name] = head + (tmp / "ripple" / f"{name}_current.cc").read_text()
    files["ripple_heavy.h"] = (f"/* generated by sdk/tools/currents.py for {pd.name}: its name as a current, and the\n"
                               f" * arena Heavy takes (measured on the computer, and a margin) */\n"
                               f'#define RC_NAME "{pd.stem}"\n#define HEAP {heap}\n')
```

`extras()` reads `ripple-sources`/`ripple-cflags` only in the first 60 lines, so they must be at the top: they are. Keep in the kept folder: `Heavy_{name}.*`, the wrapper, `ripple_heavy.h`. The runtime (`heavy_runtime`) gets every other file, as today.

Add `import json` at the top of `currents.py` if it isn't there.

- [ ] **Step 2: `double` in `Heavy_NAME.cpp`**

hvcc's `Heavy_NAME.cpp` and `.hpp` take the sample rate as `double` and are no longer rewritten. Add, as the last line before `#endif` in `sdk/heavy/static/HvUtils.h`:

```c
/* the patch's own files (Heavy_NAME.*) say double for the sample rate: a float on the FM-1, which has no double
 * arithmetic. (va_arg(ap, double) in the runtime is handled where it is read: RC_HV_VA_FLOAT, PATCHES.md) */
#define double float
```

Every Heavy file includes `HvUtils.h` before using `double`; check with `grep -L '#include "HvUtils.h"\|#include "HvHeavy.h"\|#include "HeavyContext' sdk/heavy/runtime/*.c` (each runtime `.c` includes a header that includes `HvUtils.h`). Add the line to `PATCHES.md`'s `HvUtils.h` row.

- [ ] **Step 3: Remove what the generator replaced**

Delete from `currents.py`: `FLOAT_LIT`, `heavy_rewrite`, `LOGUE_NOTE`, `HV_NOTEIN` (if no longer used), `HV_POOL_KB`/`HV_INQ_KB` (now in `c2ripple.py`; `heavy_heap` needs them: import them from there or pass `2, 1`), and in `pd_to_cc` the regexes for `getNumInputChannels`, `info->name`, `enum Table` and the whole `w = [...]` wrapper construction. In `heavy_heap`'s `measure.cpp`, use `{HV_POOL_KB}` and `{HV_INQ_KB}` from wherever they now live, and include `"ripple_heavy.h"`'s `HEAP` nowhere (the measure doesn't need it).

- [ ] **Step 4: Regenerate everything and compare**

Run:
```bash
export PATH=~/github/fm1-parent/bin:$PATH
rm -rf sdk/heavy/runtime currents/pd/gen currents/pd/community/gen
$PYH sdk/tools/currents.py currents/pd currents/pd/community --host app/build/currents-host
python3 tests/host/currents_snapshot.py --out /tmp/snap.json
```
Then the Verify commands. Expected: no differences, no image more than 5% off. If a current hits `soft-double routines` in the device build, find the double with `grep -n "[0-9]\.[0-9]*[^f0-9]" Heavy_NAME.cpp` in its kept folder; a literal in arithmetic needs the file in `static/` with the literal made float, and a row in `PATCHES.md`.

- [ ] **Step 5: Run all tests, then commit**

Run: `PYTHON=/opt/homebrew/bin/python3.14 sh tests/run_tests.sh` → `all tests passed`

```bash
git add -A sdk currents/pd
git commit -m "Pd currents through hvcc's generator (-G c2ripple): no rewriting of hvcc's output, no scraping; the same currents"
```

```json:metadata
{"files": ["sdk/tools/currents.py", "sdk/heavy/static/HvUtils.h", "currents/pd/gen/", "currents/pd/community/gen/", "sdk/heavy/runtime/"], "verifyCommand": "python3 tests/host/currents_snapshot.py --out /tmp/snap.json", "acceptanceCriteria": ["no heavy_rewrite/FLOAT_LIT/regex scraping left", "Heavy_NAME files kept as hvcc writes them", "snapshot matches baseline, image within 5%", "all tests pass"], "modelTier": "standard"}
```

---

### Task 5: Faust currents from `faust -json`

**Goal:** `faust_to_c` reads parameters and channel counts from Faust's JSON, and the wrapper finds each slider's field through Faust's own `buildUserInterface`, instead of regexes over the generated C.

**Files:**
- Modify: `sdk/tools/currents.py` (`faust_to_c`, `UI_RE`, `fnum`)
- Modify: `sdk/faust/faust_shim.h` (the UI glue)
- Regenerate: `currents/gen/` (only if Faust's C changes; it shouldn't)

**Acceptance Criteria:**
- [ ] `UI_RE` and the `getNumInputs`/`getNumOutputs` regexes are gone from `currents.py`
- [ ] Parameters (name, min, max, default) come from the JSON's `ui` tree; `ins`/`outs` from its `inputs`/`outputs`
- [ ] Builders without Faust still work: the JSON is kept beside the C in `currents/gen/NAME_faust.json`
- [ ] The snapshot matches the baseline for the 5 Faust currents; all tests pass, including the emulator ones

**Verify:** the Verify command of Task 2 (all 16 currents)

**Steps:**

- [ ] **Step 1: Look at Faust's JSON for one current**

Run: `faust -lang c -single -json currents/voice.dsp -o /tmp/v.c && python3 -m json.tool currents/voice.dsp.json | head -60`
(Faust writes `NAME.dsp.json` beside the `.dsp`; move it afterwards.) Note the fields: top-level `inputs`, `outputs`, and `ui`, a tree of groups (`type`: `vgroup`/`hgroup`/`tgroup` with `items`) and widgets (`type`: `hslider`, `vslider`, `nentry`, `button`, `checkbox`, with `label`, `init`, `min`, `max`).

- [ ] **Step 2: Read the JSON in `faust_to_c`**

Run faust with `-json` too, move the JSON next to the kept C (`kept_json = dsp.parent / "gen" / f"{name}_faust.json"`, same "made again / used as kept" rule as the C), then:

```python
def faust_widgets(ui):
    """the widgets in Faust's JSON ui tree, in order: (label, min, max, init); a button or checkbox is 0..1"""
    out = []
    for item in ui:
        if item["type"] in ("vgroup", "hgroup", "tgroup"):
            out += faust_widgets(item["items"])
        elif item["type"] in ("button", "checkbox"):
            out.append((item["label"], 0.0, 0.0, 1.0))
        elif item["type"] in ("hslider", "vslider", "nentry"):
            out.append((item["label"], float(item["init"]), float(item["min"]), float(item["max"])))
    return out
```

The tuple order `(label, default, lo, hi)` matches today's `ui` list in `faust_to_c` (`ui.append((label, field, d, lo, hi))` without `field`). Replace `ui` with this and `ins`/`outs` with `meta["inputs"]`/`meta["outputs"]`.

- [ ] **Step 3: Find the fields through `buildUserInterface`**

The wrapper writes `s->v[i].FIELD = v`, with `FIELD` scraped from the C. Instead, have the wrapper record each widget's zone (a `float *`) at `init`, in the same order as the JSON (Faust calls the UI functions in UI order):

In `faust_shim.h`, the UI glue Faust's C calls (`UIGlue`: `addHorizontalSlider(void *ui, const char *label, FAUSTFLOAT *zone, ...)` and the others) gets functions that append `zone` to a list in `ui`. In the wrapper: a `float *zone[NV][NP]` in the state, filled in `init` by calling `buildUserInterface{cls}(&s->v[i], &glue)` for each voice; `set` writes `*s->zone[i][k] = v`. For voices (`freq`/`gain`/`gate`), their indices in the widget list replace the field names.

Read `faust_shim.h`'s current UI glue first (`grep -n "UIGlue\|add" sdk/faust/faust_shim.h`); keep the struct layout Faust expects (its `CInterface.h` shape).

- [ ] **Step 4: Compare and run all tests**

Run: `python3 tests/host/currents_snapshot.py --out /tmp/snap.json` and the Verify command → no differences. Run `PYTHON=/opt/homebrew/bin/python3.14 sh tests/run_tests.sh` → `all tests passed` (the emulator tests build Faust currents as C units: check they still compile, `build_web` in `currents.py`).

- [ ] **Step 5: Commit**

```bash
git add -A sdk currents/gen
git commit -m "Faust currents: parameters and channels from faust -json, fields through buildUserInterface; no scraping"
```

```json:metadata
{"files": ["sdk/tools/currents.py", "sdk/faust/faust_shim.h", "currents/gen/"], "verifyCommand": "python3 tests/host/currents_snapshot.py --out /tmp/snap.json", "acceptanceCriteria": ["UI_RE and channel regexes gone", "params and channels from JSON", "JSON kept for builders without Faust", "snapshot matches for Faust currents; all tests pass"], "modelTier": "standard"}
```

---

### Task 6: Proof on other machines and patches, and the docs

**Goal:** The new path proven on Linux x86 (the release builder) and on the 44 community patches tried for 0.6, and the SDK docs saying how it works now.

**Files:**
- Modify: `sdk/README.md` ("In Pd"), `LICENSING.md` (the runtime row points at `sdk/heavy/static/` and `PATCHES.md`), the module docstring of `sdk/tools/currents.py`
- Delete: `tests/host/currents_baseline.json`? No: keep it, and add the snapshot comparison to `tests/run_tests.sh` so a later change can't silently alter a current

**Acceptance Criteria:**
- [ ] In a Debian amd64 container, all Pd currents build for the host from the kept files
- [ ] Of boochow's, MOD's and Wasted Audio's 44 patches, at least the same 39 build as with 0.6 (list them: both runs side by side)
- [ ] `tests/run_tests.sh` has a step comparing the snapshot with the baseline
- [ ] The docs describe the generator and `static/`, and nothing describes regex rewriting

**Verify:** `PYTHON=/opt/homebrew/bin/python3.14 sh tests/run_tests.sh` → `all tests passed` (with the new `currents-snapshot` step)

**Steps:**

- [ ] **Step 1: Linux x86**

Run:
```bash
docker run --rm --platform linux/amd64 -v "$PWD":/w -w /w debian:bookworm-slim sh -c \
  "apt-get update -qq >/dev/null && apt-get install -y -qq gcc g++ python3 >/dev/null 2>&1 && \
   python3 sdk/tools/currents.py currents/pd currents/pd/community --host /tmp/h 2>&1 | grep -cE '^host '"
```
Expected: `11`.

- [ ] **Step 2: The 44 community patches**

Clone the sources (github.com/boochow/loguesdk_hvcc_examples, nts1mkii_hvcc_examples, drumlogue_hvcc_examples; mod-audio/hvcc-plugins; Wasted-Audio/hvcc-examples-dpf) into a scratch folder, stage each patch as `app/build/community/NAME/NAME.pd` with its siblings in `lib/` (see the commit "Pd currents: logue-SDK patches play" for how 0.6 did it), and build each with `--host` and `--out`. Compare the list that builds with 0.6's: dl_EchoBoost (4 inputs) and the two DPF examples (a submodule) failed then; the other 39 built.

- [ ] **Step 3: A snapshot step in the tests**

In `tests/run_tests.sh`, after `run pd-currents ...`, add:

```sh
run currents-snapshot sh -c "python3 tests/host/currents_snapshot.py --out app/build/tests/snap.json && \
    python3 tests/host/currents_compare.py tests/host/currents_baseline.json app/build/tests/snap.json"
```

`tests/host/currents_compare.py` (new, small):
```python
#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# Copyright (C) 2026 Charles Vestal
"""Two currents snapshots (currents_snapshot.py) the same: every current's name, ins, voices, params and state;
its image within 5%. A current added or changed on purpose: make the baseline again.
  currents_compare.py BASELINE.json NEW.json"""
import json, sys

a, b = (json.load(open(f)) for f in sys.argv[1:3])
bad = []
for k in sorted(set(a) | set(b)):
    if k not in a or k not in b:
        bad.append(f"{k}: only in {'the new' if k in b else 'the baseline'}")
        continue
    for f in ("name", "ins", "voices", "params", "state"):
        if a[k][f] != b[k][f]:
            bad.append(f"{k}: {f} {a[k][f]} -> {b[k][f]}")
    if abs(a[k]["image"] - b[k]["image"]) > 0.05 * a[k]["image"]:
        bad.append(f"{k}: image {a[k]['image']} -> {b[k]['image']}")
print("\n".join(bad) or f"{len(b)} currents as the baseline")
sys.exit(1 if bad else 0)
```

The baseline's `state` for Pd currents includes the measured heap: if the measurement legitimately changes, the step fails and says so; make the baseline again on purpose then.

- [ ] **Step 4: The docs**

`sdk/README.md`, "In Pd": replace the paragraph starting "The build keeps Heavy's C for each patch" with:

```markdown
The build runs hvcc with Ripple's own generator (`sdk/heavy/c2ripple.py`, `-G c2ripple`), which writes the
current's wrapper from what hvcc knows of the patch. Heavy's runtime needs a few changes for the FM-1 (no
`double`, no C library, no unaligned loads): `sdk/heavy/static/` holds those files, and `sdk/heavy/PATCHES.md`
says what each change is. The build keeps Heavy's C for each patch in `gen/NAME_heavy/` beside it, and the
runtime, shared by every patch, in `sdk/heavy/runtime/`. Commit both: a computer without hvcc builds the patch
from them. The runtime is Enzien Audio's and Wasted Audio's, under the ISC licence; the C made from your patch is
yours. Put a `LICENSE` beside the patch and the build writes its copyright lines into that C.
```

`LICENSING.md`: in the Heavy runtime row, after "made freestanding for the FM-1", say "by the files in `sdk/heavy/static/` (`sdk/heavy/PATCHES.md`)" in place of "by `sdk/tools/currents.py`". `currents.py`'s docstring: the Pd paragraph says "through hvcc and Ripple's generator (sdk/heavy/c2ripple.py)", and drops "made freestanding by sdk/heavy/HvUtils.h".

- [ ] **Step 5: Run all tests and commit**

Run: `PYTHON=/opt/homebrew/bin/python3.14 sh tests/run_tests.sh` → `all tests passed`

```bash
git add -A tests sdk LICENSING.md
git commit -m "Currents: the snapshot compared in the tests; the docs say how Pd currents are made now"
```

```json:metadata
{"files": ["tests/run_tests.sh", "tests/host/currents_compare.py", "sdk/README.md", "LICENSING.md", "sdk/tools/currents.py"], "verifyCommand": "PYTHON=/opt/homebrew/bin/python3.14 sh tests/run_tests.sh", "acceptanceCriteria": ["11 Pd currents build in Debian amd64", "the same 39 of 44 community patches build", "tests compare snapshot with baseline", "docs describe generator and static/, no regex rewriting"], "modelTier": "standard"}
```

---

## Self-review notes

- The user's three points are covered: the generator replaces the Pd scraping and wrapper building (Tasks 3–4); the runtime changes become named, documented files (Task 2); Faust gets the supported route (Task 5).
- Order matters: the baseline (Task 1) must be taken before anything changes; Task 2 changes no output; Task 4 is the switch; Task 5 is independent of 2–4 but uses the same baseline.
- `RC_NAME`, `HEAP` and `ripple_heavy.h` are defined in Task 4 and used by the template in Task 3. Task 3's diff step ignores the descriptor name and `HEAP` for that reason.
- Nothing here goes to hvcc upstream.
