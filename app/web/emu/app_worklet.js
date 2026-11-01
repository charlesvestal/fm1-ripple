// SPDX-License-Identifier: MPL-2.0
// Copyright (C) 2026 Charles Vestal
// Ripple's part of the emulator's worklet (fm1-base web/emu/worklet.js loads it first): the droplets the page puts on
// the disk, and the currents the page runs itself, which the emulator does not have linked in. A droplet asks for a
// current by name; Ripple's flow (app/flow.c, PLAT_WEB) asks here through its imports (env.rp_js_cur_*), and a
// current found here plays through them: an uploaded build of a current (sdk/tools/currents.py --web-module: its
// rcw_* exports, sdk/web/rc_module.c), or Faust compiled in the page (its own init / compute / setParamValue).

const mods = [];            // the page's currents: { name, kind: "wasm" | "faust", module, info, ... }
let slots = [];             // the instances the droplet has loaded (flow.c's slot numbers)
let fm1 = null;             // the worklet (its exports: fm1.ex, its memory: fm1.mem)
let said = "";              // the last state sent to the page
let hello = false;
let ticks = 0;              // quanta (the state goes to the page every 16)

const enc = new TextEncoder(), dec = new TextDecoder();
const u8 = (m, p, n) => new Uint8Array(m.buffer, p, n);
const f32 = (m, p, n) => new Float32Array(m.buffer, p, n);
function cstr(m, p) {
  if (!p) return "";
  const b = new Uint8Array(m.buffer);
  let e = p;
  while (e < b.length && b[e]) e++;
  return dec.decode(b.subarray(p, e));
}
const stub = new Proxy({}, { get: () => () => 0 });

// ----------------------------------------------------------------- an uploaded build (--web-module) ---
function wasmInfo(module) {
  const inst = new WebAssembly.Instance(module, { env: stub, wasi_snapshot_preview1: stub });
  const x = inst.exports, m = x.memory;
  if (x._initialize) x._initialize();
  const params = [];
  for (let i = 0; i < x.rcw_nparams(); i++)
    params.push({ name: cstr(m, x.rcw_param_name(i)), min: x.rcw_param_min(i), max: x.rcw_param_max(i), def: x.rcw_param_def(i) });
  return { name: cstr(m, x.rcw_name()), ins: x.rcw_ins(), voices: x.rcw_voices(), params };
}
function wasmNew(mod, sr) {
  const inst = new WebAssembly.Instance(mod.module, { env: stub, wasi_snapshot_preview1: stub });
  const x = inst.exports;
  if (x._initialize) x._initialize();
  x.rcw_new(sr);
  return {
    set: (p, v) => x.rcw_set(p, v),
    note: (n, v) => x.rcw_note(n, v),
    process(l, r, n) {
      const L = f32(x.memory, x.rcw_l(), n), R = f32(x.memory, x.rcw_r(), n);
      L.set(l); R.set(r);
      x.rcw_process(n);
      l.set(L); r.set(R);
    },
  };
}

// ------------------------------------------------------------------------------ Faust from the page ---
const math = new Proxy({}, {                // what a Faust module imports: its maths, as _sinf, _powf, ...
  get: (t, k) => {
    const n = String(k).replace(/^_/, "").replace(/f$/, "");
    const own = { fabs: Math.abs, fmod: (a, b) => a % b, remainder: (a, b) => a - Math.round(a / b) * b,
                  rint: (a) => Math.round(a), fmax: Math.max, fmin: Math.min, log10: Math.log10, isnan: Number.isNaN,
                  isinf: (a) => !Number.isFinite(a) && !Number.isNaN(a), copysign: (a, b) => Math.sign(b) * Math.abs(a) };
    return own[n] || Math[n] || (() => 0);
  },
});
function faustItems(ui, out = []) {
  for (const g of ui || []) {
    if (g.items) faustItems(g.items, out);
    else if (["hslider", "vslider", "nentry", "button", "checkbox"].includes(g.type))
      out.push({ name: g.label, index: g.index, min: g.min ?? 0, max: g.max ?? 1, def: g.init ?? 0 });
  }
  return out;
}
function faustInfo(json, name) {
  const items = faustItems(json.ui);
  const has = (l) => items.some((i) => i.name === l);
  const voice = json.inputs === 0 && has("freq") && has("gain") && has("gate");
  const meta = Object.assign({}, ...(json.meta || []));
  const params = items.filter((i) => !(voice && ["freq", "gain", "gate"].includes(i.name)));
  return { name, ins: json.inputs > 0 ? 2 : 0, voices: voice ? Math.max(1, Math.min(16, +meta.voices || 6)) : 0, params,
           items, json };
}
function faustInstance(mod, sr) {        // one module instance: the DSP at 0, its buffers after it
  const inst = new WebAssembly.Instance(mod.module, { env: math });
  const x = inst.exports, m = x.memory;
  const base = (mod.info.json.size + 15) & ~15, ptrs = base, bufs = base + 64, need = bufs + 4 * 256 * 4;
  if (m.buffer.byteLength < need) m.grow(Math.ceil((need - m.buffer.byteLength) / 65536));
  const dv = new DataView(m.buffer);
  for (let c = 0; c < 4; c++) dv.setUint32(ptrs + c * 4, bufs + c * 1024, true);   // 2 ins, then 2 outs
  x.init(0, sr);
  return { x, m, ins: ptrs, outs: ptrs + 8, buf: (c) => f32(m, bufs + c * 1024, 256) };
}
function faustNew(mod, sr) {
  const info = mod.info, idx = (name) => info.items.find((i) => i.name === name)?.index;
  const outs = info.json.outputs, nin = info.json.inputs;
  const n = info.voices || 1;
  const v = Array.from({ length: n }, () => faustInstance(mod, sr));
  const note = new Array(n).fill(-1), age = new Array(n).fill(0);
  let clock = 0;
  const F = idx("freq"), G = idx("gain"), T = idx("gate");
  return {
    set(p, val) { const it = info.params[p]; if (it) for (const s of v) s.x.setParamValue(0, it.index, val); },
    note(nt, vel) {
      if (!info.voices) return;
      if (vel <= 0) {
        for (let k = 0; k < n; k++) if (note[k] === nt) { v[k].x.setParamValue(0, T, 0); note[k] = -1; }
        return;
      }
      let pick = -1;
      for (let k = 0; k < n; k++) if (note[k] < 0 && (pick < 0 || age[k] < age[pick])) pick = k;
      if (pick < 0) for (let k = 0; k < n; k++) if (pick < 0 || age[k] < age[pick]) pick = k;
      const s = v[pick];
      if (note[pick] >= 0) { s.x.setParamValue(0, T, 0); s.x.compute(0, 1, s.ins, s.outs); }
      s.x.setParamValue(0, F, 440 * Math.pow(2, (nt - 69) / 12));
      s.x.setParamValue(0, G, vel);
      s.x.setParamValue(0, T, 1);
      note[pick] = nt;
      age[pick] = ++clock;
    },
    process(l, r, nf) {
      if (info.voices) {
        for (const s of v) {
          s.x.compute(0, nf, s.ins, s.outs);
          const a = s.buf(2), b = s.buf(outs > 1 ? 3 : 2);
          for (let i = 0; i < nf; i++) { l[i] += a[i]; r[i] += b[i]; }
        }
      } else {
        const s = v[0];
        if (nin === 1) { const a = s.buf(0); for (let i = 0; i < nf; i++) a[i] = 0.5 * (l[i] + r[i]); }
        else if (nin >= 2) { s.buf(0).set(l); s.buf(1).set(r); }
        s.x.compute(0, nf, s.ins, s.outs);
        const a = s.buf(2), b = s.buf(outs > 1 ? 3 : 2);
        if (nin > 0) { l.set(a.subarray(0, nf)); r.set(b.subarray(0, nf)); }
        else for (let i = 0; i < nf; i++) { l[i] += a[i]; r[i] += b[i]; }
      }
    },
  };
}

// --------------------------------------------------------------------------------- the flow's imports ---
const env = {
  rp_js_cur_find(p, len) {
    const name = dec.decode(u8(fm1.mem, p, len));
    return mods.findIndex((m) => m.name === name) + 1;
  },
  rp_js_cur_info(id, p) {                   // flow.c js_info_t: ins, voices, nparams, then 64 x {name[24], min, max, def}, name[16]
    const info = mods[id].info, dv = new DataView(fm1.mem.buffer), b = new Uint8Array(fm1.mem.buffer);
    const np = Math.min(info.params.length, 64);
    dv.setInt32(p, info.ins, true); dv.setInt32(p + 4, info.voices, true); dv.setInt32(p + 8, np, true);
    for (let i = 0; i < np; i++) {
      const q = p + 12 + i * 36, it = info.params[i], nm = enc.encode(it.name).subarray(0, 23);
      b.fill(0, q, q + 24); b.set(nm, q);
      dv.setFloat32(q + 24, it.min, true); dv.setFloat32(q + 28, it.max, true); dv.setFloat32(q + 32, it.def, true);
    }
    const q = p + 12 + 64 * 36, nm = enc.encode(mods[id].name).subarray(0, 15);
    b.fill(0, q, q + 16); b.set(nm, q);
  },
  rp_js_cur_new(id, sr) {
    const mod = mods[id];
    const s = mod.kind === "faust" ? faustNew(mod, sr) : wasmNew(mod, sr);
    slots.push(s);
    return slots.length - 1;
  },
  rp_js_cur_set(slot, p, v) { slots[slot]?.set(p, v); },
  rp_js_cur_note(slot, n, v) { slots[slot]?.note(n, v); },
  rp_js_cur_process(slot, l, r, n) { const s = slots[slot]; if (s) s.process(f32(fm1.mem, l, n), f32(fm1.mem, r, n), n); },
  rp_js_cur_free_all() { slots = []; },
};

// ---------------------------------------------------------------------------------------- the page ---
function putDroplet(name, text, run) {
  const ex = fm1.ex, buf = ex.rp_web_buf(), nm = enc.encode(name), body = enc.encode(text);
  if (body.length > ex.rp_web_buf_max()) return { ok: false, error: "longer than 64 KB" };
  u8(fm1.mem, buf, nm.length).set(nm);
  u8(fm1.mem, buf + 256, body.length).set(body);
  const rc = ex.rp_web_put(0, nm.length, body.length);
  if (rc !== 0) return { ok: false, error: rc === -3 ? "the disk is full" : rc === -2 ? "too many droplets" : `could not write it (${rc})` };
  if (run) {
    u8(fm1.mem, buf, nm.length).set(nm);
    if (!ex.rp_web_start(nm.length)) return { ok: false, error: "not in the list" };
  }
  return { ok: true };
}

function addCurrent(m) {
  const module = m.module || new WebAssembly.Module(m.bytes);
  const info = m.kind === "faust" ? faustInfo(m.json, m.name) : wasmInfo(module);
  const name = m.kind === "faust" ? m.name : info.name;
  const i = mods.findIndex((x) => x.name === name);
  const mod = { name, kind: m.kind, module, info };
  if (i >= 0) mods[i] = mod; else mods.push(mod);
  return { name, kind: m.kind, voices: info.voices, ins: info.ins, params: info.params.map((p) => p.name) };
}

globalThis.fm1App = {
  env,
  load(f) { fm1 = f; },
  message(f, m) {
    let r;
    try {
      if (m.what === "droplet") r = putDroplet(m.name, m.text, m.run);
      else if (m.what === "current") r = { ok: true, current: addCurrent(m) };
      else if (m.what === "forget") { const i = mods.findIndex((x) => x.name === m.name); if (i >= 0) mods.splice(i, 1); r = { ok: true }; }
      else if (m.what === "stop") { f.ex.rp_web_stop(); r = { ok: true }; }
      else return;
    } catch (e) {
      r = { ok: false, error: String(e && e.message || e) };
    }
    f.port.postMessage({ type: "app", what: "done", id: m.id, ...r });
  },
  process(f) {
    if (!hello) {                           // (after the boot: the disk is there to write)
      hello = true;
      f.port.postMessage({ type: "app", what: "hello" });
    }
    if (++ticks % 16) return;
    const ex = f.ex, mode = ex.rp_web_mode();
    const st = { mode, running: cstr(f.mem, ex.rp_web_running()), error: mode === 2 ? cstr(f.mem, ex.rp_web_error()) : "",
                 console: [2, 1].map((k) => cstr(f.mem, ex.rp_web_console(k))).filter(Boolean) };
    const s = JSON.stringify(st);
    if (s !== said) { said = s; f.port.postMessage({ type: "app", what: "state", ...st }); }
  },
};
