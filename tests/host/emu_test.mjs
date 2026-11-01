// SPDX-License-Identifier: MPL-2.0
// Copyright (C) 2026 Charles Vestal
// Ripple's browser build in Node: boot it, start awake (second in the list: OCT+ then PLAY), expect it to play by
// itself (its currents linked into the emulator) and the screen to draw.
//   node tests/host/emu_test.mjs app/build/emu/app.wasm
import fs from "fs";
const wasm = fs.readFileSync(process.argv[2]);
let mem;
const wasi = new Proxy({ clock_time_get: (id, p, out) => { new DataView(mem.buffer).setBigUint64(out, 0n, true); return 0; },
  fd_write: (fd, iov, n, out) => { new DataView(mem.buffer).setUint32(out, 0, true); return 0; } }, { get: (t, k) => k in t ? t[k] : () => 0 });
const { instance } = await WebAssembly.instantiate(wasm, { wasi_snapshot_preview1: wasi, env: new Proxy({}, { get: () => () => 0 }) });
const ex = instance.exports; mem = ex.memory;
if (ex._initialize) ex._initialize();
const B_PLAY = 10, B_OCTUP = 13;
const run = (ms) => { for (let i = 0; i < ms * 44.1 / 128; i++) ex.web_render(128); };
const peakOver = (ms) => {
  let peak = 0;
  for (let i = 0; i < ms * 44.1 / 128; i++) {
    ex.web_render(128);
    for (const v of new Float32Array(mem.buffer, ex.web_out_l(), 128)) peak = Math.max(peak, Math.abs(v));
  }
  return peak;
};
ex.web_master(2800);
ex.web_boot();
run(800);
const quiet = peakOver(300);                   // the list: silence
ex.web_buttons(1 << B_OCTUP); run(80); ex.web_buttons(0); run(80);
ex.web_buttons(1 << B_PLAY); run(80); ex.web_buttons(0);
run(500);
const peak = peakOver(3000);
console.log("list peak", quiet.toFixed(3), "awake peak", peak.toFixed(3), "blits", ex.web_blits());
process.exit(quiet < 0.001 && peak > 0.02 && peak < 1 && ex.web_blits() > 5 ? 0 : 1);
