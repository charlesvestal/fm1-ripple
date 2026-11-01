// SPDX-License-Identifier: MPL-2.0
// Copyright (C) 2026 Charles Vestal
// The emulator page's own part, in Node: app.wasm with Ripple's worklet part (app/web/emu/app_worklet.js) as its
// imports, as the page runs it. A droplet put on the disk and started plays a Plaits current (linked into the
// emulator), one using an uploaded current (tests/host/webbeep.c, built by currents.py --web-module) plays it, and a
// droplet with an error says so.
//   node tests/host/emu_upload.mjs app/build/emu/app.wasm app/build/tests/webbeep.wasm
import fs from "fs";
import path from "path";
import { pathToFileURL } from "url";
delete globalThis.TextEncoder;              // (as in an AudioWorklet, which has neither: the page's part must not need them)
delete globalThis.TextDecoder;
await import(pathToFileURL(path.resolve("app/web/emu/app_worklet.js")).href);
const app = globalThis.fm1App;
const said = [];
const fm1 = { port: { postMessage: (m) => said.push(m) } };
const wasi = new Proxy({ clock_time_get: (id, p, out) => { new DataView(fm1.mem.buffer).setBigUint64(out, 0n, true); return 0; },
  fd_write: (fd, iov, n, out) => { new DataView(fm1.mem.buffer).setUint32(out, 0, true); return 0; } }, { get: (t, k) => k in t ? t[k] : () => 0 });
const env = new Proxy(app.env, { get: (t, k) => (k in t ? t[k] : () => 0) });
const { instance } = await WebAssembly.instantiate(fs.readFileSync(process.argv[2]), { wasi_snapshot_preview1: wasi, env });
fm1.ex = instance.exports; fm1.mem = fm1.ex.memory;
if (fm1.ex._initialize) fm1.ex._initialize();
app.load(fm1);
const ex = fm1.ex;
const run = (ms) => { for (let i = 0; i < ms * 44.1 / 128; i++) { app.process(fm1); ex.web_render(128); } };
const peakOver = (ms) => {
  let peak = 0;
  for (let i = 0; i < ms * 44.1 / 128; i++) {
    app.process(fm1); ex.web_render(128);
    for (const v of new Float32Array(fm1.mem.buffer, ex.web_out_l(), 128)) peak = Math.max(peak, Math.abs(v));
  }
  return peak;
};
const ask = (m) => { said.length = 0; app.message(fm1, { id: 1, ...m }); return said.find((x) => x.what === "done"); };
const state = () => [...said].reverse().find((x) => x.what === "state");
let fails = 0;
const check = (what, ok, more = "") => { console.log(`${ok ? "  ok  " : "FAIL "} ${what} ${more}`); if (!ok) fails++; };
const key = (k, ms) => { ex.web_keys(1 << k); const p = peakOver(ms); ex.web_keys(0); run(100); return p; };

ex.web_master(2800);
ex.web_boot();
run(800);
check("hello after the boot", said.some((m) => m.what === "hello"));

let r = ask({ what: "droplet", name: "plva", run: true, text:
  'local c\nfunction init() c = current.load("plaits-va"); flow.set(c) end\n' +
  'function key(k, vel) c:note(util.note(k), vel / 127) end\nfunction redraw() screen.clear(); screen.update() end\n' });
run(400);
check("a droplet put on the disk and started", r && r.ok, r && r.error);
check("it runs", state() && state().mode === 1 && state().running === "plva.lua", JSON.stringify(state()));
let p = key(9, 400);
check("plaits-va plays in the emulator", p > 0.02 && p < 1, p.toFixed(3));

r = ask({ what: "current", kind: "wasm", bytes: fs.readFileSync(process.argv[3]) });
check("an uploaded current", r && r.ok && r.current.name === "webbeep" && r.current.voices === 1, JSON.stringify(r));
r = ask({ what: "droplet", name: "beep", run: true, text:
  'local c\nfunction init() c = current.load("webbeep"); c:set("level", 0.8); flow.set(c, current.load("plate")) end\n' +
  'function key(k, vel) c:note(util.note(k), vel / 127) end\n' });
run(300);
check("a droplet using it runs", r && r.ok && state().mode === 1, JSON.stringify(state()));
p = key(12, 300);
check("the uploaded current plays", p > 0.05 && p < 1.5, p.toFixed(3));

r = ask({ what: "droplet", name: "oops", run: true, text: "function init() nosuch() end\n" });
run(300);
check("a droplet's error comes back", state() && state().mode === 2 && /nosuch/.test(state().error), JSON.stringify(state()));
process.exit(fails ? 1 : 0);
