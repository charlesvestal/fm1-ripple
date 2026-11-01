// SPDX-License-Identifier: MPL-2.0
// Copyright (C) 2026 Charles Vestal
// Ripple's part of the emulator page (fm1-base web/emu/index.html imports it): write a droplet (Lua) or a current
// (Faust) here, or upload one (.lua, .dsp, or a .wasm build of a C or C++ current from sdk/tools/currents.py
// --web-module), and the emulator runs it. What you make is kept in this browser and put back each time the
// emulator starts. The worklet's side: app_worklet.js.

const FAUST = "https://cdn.jsdelivr.net/npm/@grame/faustwasm@0.19.6";
const KEY = "ripple-emu-files";
const DROPLET = `-- a droplet: the keys play a current
local voice, delay

function init()
  voice = current.load("plaits-va")
  delay = current.load("delay")
  flow.set(voice, delay)
end

function key(k, vel)
  voice:note(util.note(k), vel / 127)
end

function enc(n, d)
  if n == 1 then
    harmonics = util.clamp((harmonics or 0.5) + d * 0.02, 0, 1)
    voice:set("harmonics", harmonics)
    redraw()
  end
end

function redraw()
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 20, "my droplet")
  screen.font(1)
  screen.level(8)
  screen.text(12, 60, "K1: harmonics " .. string.format("%.2f", harmonics or 0.5))
  screen.update()
end
`;
const CURRENT = `// a current in Faust: with freq, gain and gate it is a voice (a droplet plays it with notes)
declare voices "6";
import("stdfaust.lib");

freq = hslider("freq", 440, 20, 8000, 0.01);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");
cutoff = hslider("cutoff", 2000, 60, 12000, 1);
res = hslider("res", 1, 0.5, 8, 0.01);

process = (os.sawtooth(freq) + os.square(freq * 1.005)) * 0.5
        : fi.resonlp(cutoff, res, 1) * en.adsr(0.005, 0.2, 0.6, 0.4, gate) * gain * 0.4 <: _, _;
`;

let node = null, ready = false, nextId = 1, faust = null;
const waiting = new Map();
const $ = (id) => document.getElementById(id);

function load() {
  try { return Object.assign({ droplets: {}, currents: {} }, JSON.parse(localStorage.getItem(KEY) || "{}")); }
  catch { return { droplets: {}, currents: {} }; }
}
function save(files) { try { localStorage.setItem(KEY, JSON.stringify(files)); } catch {} }
let files = load();

function ask(m) {
  const id = nextId++;
  return new Promise((res) => { waiting.set(id, res); node.port.postMessage({ type: "app", id, ...m }); });
}
const b64 = (bytes) => { let s = ""; for (const b of bytes) s += String.fromCharCode(b); return btoa(s); };
const unb64 = (s) => Uint8Array.from(atob(s), (c) => c.charCodeAt(0));
const clean = (name) => (name || "").replace(/\.(lua|dsp|wasm)$/i, "").toLowerCase().replace(/[^a-z0-9_-]/g, "").slice(0, 8);

async function compileFaust(name, code) {
  if (!faust) {
    say("Loading Faust (about 5 MB, once)…");
    const fw = await import(`${FAUST}/dist/esm/index.js`);
    const mod = await fw.instantiateFaustModuleFromFile(`${FAUST}/libfaust-wasm/libfaust-wasm.js`);
    faust = { fw, compiler: new fw.FaustCompiler(new fw.LibFaust(mod)) };
  }
  const gen = new faust.fw.FaustMonoDspGenerator();
  const ok = await gen.compile(faust.compiler, name, code, "-ftz 2");
  if (!ok || !gen.factory) throw new Error(faust.compiler.getErrorMessage() || "Faust could not compile it");
  return { bytes: gen.factory.code, json: JSON.parse(gen.factory.json) };
}

async function addCurrent(name, entry) {   // entry: { kind: "faust", code } or { kind: "wasm", data (base64) }
  if (entry.kind === "faust") {
    const c = await compileFaust(name, entry.code);
    return ask({ what: "current", kind: "faust", name, bytes: c.bytes, json: c.json });
  }
  return ask({ what: "current", kind: "wasm", bytes: unb64(entry.data) });
}

// ----------------------------------------------------------------------------------------- the panel ---
function say(t, bad) {
  const s = $("rp-status");
  s.textContent = t;
  s.className = bad ? "rp-bad" : "";
}

function draw() {
  const list = $("rp-files");
  list.textContent = "";
  const row = (label, kind, actions) => {
    const li = document.createElement("li");
    const n = document.createElement("span");
    n.textContent = label;
    const k = document.createElement("span");
    k.className = "rp-kind";
    k.textContent = kind;
    li.append(n, k);
    for (const [t, fn, aria] of actions) {
      const b = document.createElement("button");
      b.type = "button";
      b.textContent = t;
      b.setAttribute("aria-label", aria);
      b.addEventListener("click", fn);
      li.append(b);
    }
    list.append(li);
  };
  for (const name of Object.keys(files.droplets).sort())
    row(name, "droplet", [
      ["Open", () => open("droplet", name, files.droplets[name]), `Open the droplet ${name}`],
      ["Run", () => runDroplet(name, files.droplets[name]), `Run the droplet ${name}`],
      ["Download", () => download(name + ".lua", files.droplets[name]), `Download ${name}.lua`],
      ["Remove", () => { delete files.droplets[name]; save(files); draw(); }, `Remove the droplet ${name} from this browser`]]);
  for (const name of Object.keys(files.currents).sort()) {
    const c = files.currents[name];
    row(name, c.kind === "faust" ? "current (Faust)" : "current (.wasm)", [
      ...(c.kind === "faust" ? [["Open", () => open("current", name, c.code), `Open the current ${name}`]] : []),
      ["Download", () => c.kind === "faust" ? download(name + ".dsp", c.code) : download(name + ".wasm", unb64(c.data)),
       `Download ${name}`],
      ["Remove", async () => { delete files.currents[name]; save(files); draw(); if (ready) await ask({ what: "forget", name }); },
       `Remove the current ${name}`]]);
  }
  $("rp-none").hidden = list.children.length > 0;
}

function open(kind, name, text) {
  $("rp-kind").value = kind;
  $("rp-name").value = name;
  $("rp-code").value = text;
  $("rp-code").focus();
}

function download(name, data) {
  const a = document.createElement("a");
  a.href = URL.createObjectURL(new Blob([data]));
  a.download = name;
  a.click();
  setTimeout(() => URL.revokeObjectURL(a.href), 1000);
}

async function runDroplet(name, text) {
  if (!ready) return say("Switch the emulator on first.", true);
  const r = await ask({ what: "droplet", name, text, run: true });
  say(r.ok ? `${name} is running. Hold HOME for a second to go back to the list.` : `${name}: ${r.error}`, !r.ok);
}

async function run() {
  const kind = $("rp-kind").value, name = clean($("rp-name").value), text = $("rp-code").value;
  if (!name) return say("Give it a name: letters, digits, _ or -, eight at most.", true);
  $("rp-name").value = name;
  if (kind === "droplet") {
    files.droplets[name] = text;
    save(files);
    draw();
    return runDroplet(name, text);
  }
  if (!ready) return say("Switch the emulator on first.", true);
  try {
    say(`Compiling ${name}…`);
    const r = await addCurrent(name, { kind: "faust", code: text });
    if (!r.ok) throw new Error(r.error);
    files.currents[name] = { kind: "faust", code: text };
    save(files);
    draw();
    const c = r.current;
    say(`${name} is ready: ${c.voices ? `a voice of ${c.voices} notes` : c.ins ? "an effect" : "a sound"}` +
        `${c.params.length ? ", knobs " + c.params.join(", ") : ""}. A droplet loads it with current.load("${name}").`);
  } catch (e) {
    say(`${name}: ${e.message || e}`, true);
  }
}

async function upload(list) {
  for (const f of list) {
    const name = clean(f.name);
    try {
      if (/\.lua$/i.test(f.name)) {
        files.droplets[name] = await f.text();
        save(files);
        if (ready) await ask({ what: "droplet", name, text: files.droplets[name], run: false });
        say(`${name}: in the list of droplets.`);
      } else if (/\.dsp$/i.test(f.name)) {
        open("current", name, await f.text());
        await run();
      } else if (/\.wasm$/i.test(f.name)) {
        const bytes = new Uint8Array(await f.arrayBuffer());
        if (!ready) throw new Error("switch the emulator on first");
        const r = await ask({ what: "current", kind: "wasm", bytes });
        if (!r.ok) throw new Error(r.error);
        files.currents[r.current.name] = { kind: "wasm", data: b64(bytes) };
        save(files);
        say(`${r.current.name}: ready (current.load("${r.current.name}")).`);
      } else {
        throw new Error("a .lua droplet, a .dsp current or a .wasm build (currents.py --web-module)");
      }
    } catch (e) {
      say(`${f.name}: ${e.message || e}`, true);
    }
  }
  draw();
}

function build() {
  const css = document.createElement("style");
  css.textContent = `
#rp { margin: 28px 0 40px; padding: 18px 20px; background: var(--card); border: 1px solid var(--rule); border-radius: 12px; }
#rp h2 { margin: 0 0 4px; font-size: 1.25rem; }
#rp p { margin: 0 0 12px; color: var(--muted); }
#rp .rp-row { display: flex; flex-wrap: wrap; gap: 8px; align-items: center; margin-bottom: 8px; }
#rp label { color: var(--muted); }
#rp input, #rp select, #rp textarea, #rp button { font: inherit; color: var(--ink); background: var(--ground);
  border: 1px solid var(--rule); border-radius: 8px; padding: 6px 10px; }
#rp button { cursor: pointer; }
#rp button.rp-go { background: var(--teal); color: var(--card); border-color: var(--teal); }
#rp textarea { width: 100%; box-sizing: border-box; min-height: 300px; font-family: ui-monospace, Menlo, monospace;
  font-size: 13px; line-height: 1.45; tab-size: 2; }
#rp :focus-visible { outline: 3px solid var(--focus); outline-offset: 2px; }
#rp-status { min-height: 1.4em; margin: 8px 0; }
#rp-status.rp-bad { color: var(--bad); }
#rp-console { white-space: pre-wrap; font-family: ui-monospace, Menlo, monospace; font-size: 12px; color: var(--muted);
  margin: 0 0 12px; }
#rp-drop { border: 2px dashed var(--rule); border-radius: 10px; padding: 14px; text-align: center; color: var(--muted); }
#rp-drop.rp-over { border-color: var(--teal); color: var(--ink); }
#rp ul { list-style: none; padding: 0; margin: 10px 0 0; }
#rp li { display: flex; flex-wrap: wrap; gap: 8px; align-items: center; padding: 6px 0; border-top: 1px solid var(--rule); }
#rp li > span:first-child { font-weight: 600; min-width: 7em; }
#rp .rp-kind { color: var(--muted); flex: 1; }`;
  document.head.append(css);
  const sec = document.createElement("section");
  sec.id = "rp";
  sec.setAttribute("aria-labelledby", "rp-h");
  sec.innerHTML = `
<h2 id="rp-h">Write your own</h2>
<p>A droplet in Lua, or a current in Faust: Run puts it on the emulator's disk (a droplet starts at once; a current is
there for any droplet to load). Kept in this browser. How to write them: the guides for
<a href="https://github.com/charlesvestal/fm1-ripple/blob/main/docs/DROPLETS.md">droplets</a> and
<a href="https://github.com/charlesvestal/fm1-ripple/blob/main/sdk/README.md">currents</a>.</p>
<div class="rp-row">
  <label for="rp-kind">Writing</label>
  <select id="rp-kind"><option value="droplet">a droplet (Lua)</option><option value="current">a current (Faust)</option></select>
  <label for="rp-name">named</label>
  <input id="rp-name" size="10" maxlength="8" spellcheck="false" autocomplete="off" value="mine">
  <button type="button" class="rp-go" id="rp-run">Run</button>
  <button type="button" id="rp-new">Start again</button>
  <button type="button" id="rp-stop">Back to the list</button>
</div>
<textarea id="rp-code" spellcheck="false" aria-label="The code"></textarea>
<div id="rp-status" role="status" aria-live="polite"></div>
<div id="rp-console" aria-live="polite"></div>
<div id="rp-drop">Drop a .lua droplet, a .dsp current or a .wasm build here, or
  <label><input type="file" id="rp-file" multiple accept=".lua,.dsp,.wasm" hidden><button type="button" id="rp-pick">choose files</button></label>.
  (A .wasm build is a C or C++ current made by <code>currents.py --web-module</code>; the FM-1 takes the .cur.)</div>
<h2 style="margin-top:16px;font-size:1.05rem">In this browser</h2>
<p id="rp-none">Nothing yet.</p>
<ul id="rp-files"></ul>`;
  (document.querySelector("main") || document.body).append(sec);
  $("rp-code").value = DROPLET;
  $("rp-kind").addEventListener("change", () => {
    const t = $("rp-code").value;
    if (t === DROPLET || t === CURRENT || !t.trim()) $("rp-code").value = $("rp-kind").value === "droplet" ? DROPLET : CURRENT;
  });
  $("rp-run").addEventListener("click", run);
  $("rp-new").addEventListener("click", () => { $("rp-code").value = $("rp-kind").value === "droplet" ? DROPLET : CURRENT; });
  $("rp-stop").addEventListener("click", () => ready && ask({ what: "stop" }));
  $("rp-code").addEventListener("keydown", (e) => {
    if (e.key === "Enter" && (e.metaKey || e.ctrlKey)) { e.preventDefault(); run(); }
    else if (e.key === "Tab" && !e.shiftKey && !e.altKey) {     // two spaces (Esc first leaves the box: Tab moves on)
      if (e.target.dataset.escaped) { delete e.target.dataset.escaped; return; }
      e.preventDefault();
      e.target.setRangeText("  ", e.target.selectionStart, e.target.selectionEnd, "end");
    } else if (e.key === "Escape") e.target.dataset.escaped = "1";
  });
  $("rp-pick").addEventListener("click", () => $("rp-file").click());
  $("rp-file").addEventListener("change", (e) => upload([...e.target.files]));
  const drop = $("rp-drop");
  drop.addEventListener("dragover", (e) => { e.preventDefault(); drop.classList.add("rp-over"); });
  drop.addEventListener("dragleave", () => drop.classList.remove("rp-over"));
  drop.addEventListener("drop", (e) => { e.preventDefault(); drop.classList.remove("rp-over"); upload([...e.dataTransfer.files]); });
  draw();
  say("Switch the emulator on, then Run.");
}

async function restore() {                 // what this browser kept: back on the disk, the currents ready
  for (const [name, text] of Object.entries(files.droplets)) await ask({ what: "droplet", name, text, run: false });
  for (const [name, c] of Object.entries(files.currents)) {
    try { await addCurrent(name, c); } catch (e) { say(`${name}: ${e.message || e}`, true); }
  }
  say(Object.keys(files.droplets).length ? "Your droplets are in the list." : "Ready: write a droplet and Run.");
}

export function attach(ctx) {
  node = ctx.node;
  if (!$("rp")) build();
}

export function message(m) {
  if (m.what === "hello") { ready = true; restore(); }
  else if (m.what === "done") { const res = waiting.get(m.id); waiting.delete(m.id); if (res) res(m); }
  else if (m.what === "state") {
    const c = $("rp-console");
    if (m.mode === 2) { c.textContent = m.error + (m.console.length ? "\n" + m.console.join("\n") : ""); say("The droplet stopped: see below.", true); }
    else c.textContent = m.console.join("\n");
  }
}

if (document.readyState !== "loading") build(); else document.addEventListener("DOMContentLoaded", build);
