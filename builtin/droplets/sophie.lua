-- sophie: sixteen pads of metallic FM percussion (the sophie current, from Sophie by Matt Estela, as SPH-16 has it),
-- through the plate, with a 16-step pattern.
-- The lowest 16 keys play the pads, and the one you play last is the one the knobs change. PLAY starts and stops
-- the pattern; with REC lit, what you play goes into it. SEQ: the white keys are the steps of the pad you play last.
-- Pages of knobs: EDIT sound, ENV shape, LFO ring, FX grit, GLO room. ALGORITHM picks the pad's model, SELECT the
-- pad, PRESET the tempo. SAVE keeps the kit, the pattern and the tempo.

local sph, plate
local white = {0, 2, 4, 6, 7, 9, 11, 12, 14, 16, 18, 19, 21, 23, 24, 26}
local models = {"fuse", "stack", "split", "shard", "pipe", "boom"}
-- kit 1 (CLANG): Sophie's factory pads, in SPH-16's order and pots
local FIELDS = {"model", "tune", "decay", "color", "metal", "fdbk", "sweep", "crush", "drive", "pan"}
local CLANG = {
  {"bd", 0, 19, 58, 24, 8, 6, 155, 0, 58, 64}, {"sd", 3, 25, 54, 52, 76, 18, 128, 30, 52, 64},
  {"cp", 2, 25, 48, 84, 88, 42, 92, 56, 68, 64}, {"rs", 3, 22, 29, 76, 72, 34, 116, 48, 58, 70},
  {"ch", 3, 26, 16, 94, 98, 58, 100, 52, 62, 74}, {"oh", 3, 29, 72, 91, 96, 62, 96, 42, 60, 74},
  {"ph", 3, 26, 31, 88, 94, 50, 102, 46, 58, 76}, {"s2", 1, 21, 47, 63, 82, 28, 124, 38, 58, 60},
  {"lt", 0, 21, 68, 24, 44, 16, 158, 8, 48, 44}, {"mt", 0, 24, 64, 38, 52, 22, 148, 12, 52, 64},
  {"ht", 0, 28, 53, 58, 64, 30, 136, 18, 58, 84}, {"ft", 0, 20, 71, 31, 48, 20, 154, 10, 50, 36},
  {"lm", 0, 23, 61, 45, 56, 25, 144, 14, 54, 54}, {"hm", 0, 23, 57, 51, 60, 28, 140, 16, 56, 74},
  {"cy", 1, 23, 104, 78, 92, 72, 88, 28, 54, 52}, {"rd", 2, 24, 95, 69, 86, 66, 94, 22, 52, 78},
}
local PAGES = {
  {name = "sound", button = "EDIT", knobs = {"tune", "decay", "color", "metal"}},
  {name = "shape", button = "ENV", knobs = {"fdbk", "sweep", "cutoff", "reso"}},
  {name = "ring", button = "LFO", knobs = {"time", "ring", "mix", "tone"}},
  {name = "grit", button = "FX", knobs = {"drive", "crush", "level", "pan"}},
  {name = "room", button = "GLO", room = true, knobs = {"size", "decay", "damp", "mix"}},
}
local ROOM = {size = 0.5, decay = 0.6, damp = 0.5, mix = 0.18}
-- a pad's settings: an array in the current's order of them (names; idx: a name's place), 0..max each (lo, hi)
local names, idx, lo, hi = {}, {}, {}, {}
local kit, labels, pattern = {}, {}, {}
local sel, page, step, playing, rec, steps = 1, 1, 0, false, false, false
local flash = {}                     -- when each pad last sounded

local function get(p, name) return kit[p][idx[name]] end

local function send(p, name)
  sph:set("pad", p)
  sph:set(name, get(p, name))
end

local function send_pad(p)
  sph:set("pad", p)
  for i, name in ipairs(names) do sph:set(name, kit[p][i]) end
end

local function hit(p, vel)               -- vel 0..1
  sph:note(35 + p, vel)
  flash[p] = util.ms()
end

function init()
  sph = current.load("sophie")
  plate = current.load("plate")
  flow.set(sph, plate)
  local def = {}
  for _, p in ipairs(sph:params()) do
    if p.name ~= "pad" and p.name ~= "voices" then
      names[#names + 1] = p.name
      idx[p.name], lo[p.name], hi[p.name] = #names, p.min, p.max
      def[#names] = p.default
    end
  end
  for p = 1, 16 do
    kit[p] = {table.unpack(def)}
    for i, f in ipairs(FIELDS) do kit[p][idx[f]] = CLANG[p][i + 1] end
    kit[p][idx.time] = 77
    labels[p] = CLANG[p][1]
    pattern[p] = {}
    for s = 1, 16 do pattern[p][s] = 0 end
  end
  for _, s in ipairs({1, 5, 9, 11, 13}) do pattern[1][s] = 120 end    -- velocities 1..127, 0: none
  pattern[2][5], pattern[2][13] = 110, 110
  for s = 1, 16, 2 do pattern[5][s] = 76 end
  pattern[6][15] = 76
  pattern[4][8], pattern[4][16] = 64, 50
  clock.set_tempo(118)
  local saved = data.load()
  if saved and saved.kit then         -- each pad's settings in the current's order then (saved.names)
    for p = 1, 16 do
      for i, v in ipairs(saved.kit[p] or {}) do
        local at = idx[saved.names[i]]
        if at then kit[p][at] = v end
      end
      pattern[p] = saved.pattern[p] or pattern[p]
    end
    for k, v in pairs(saved.room or {}) do ROOM[k] = v end
    clock.set_tempo(saved.tempo or 118)
  end
  for p = 1, 16 do send_pad(p) end
  for k, v in pairs(ROOM) do plate:set(k, v) end
  clock.run(function()
    while true do
      clock.sync(1 / 4)
      if playing then
        step = step % 16 + 1
        for p = 1, 16 do if pattern[p][step] > 0 then hit(p, pattern[p][step] / 127) end end
        lights()
      end
    end
  end)
  lights()
end

function lights()
  for k = 0, 26 do led.key(k, false) end
  if steps then
    for s = 1, 16 do led.key(white[s], (pattern[sel][s] > 0) ~= (s == step and playing)) end
  else
    led.key(sel - 1, true)
  end
  led.button("PLAY", playing)
  led.button("REC", rec)
  led.button("SEQ", steps)
  for i, pg in ipairs(PAGES) do led.button(pg.button, i == page) end
end

function key(k, vel)
  if vel == 0 then return end
  if steps then
    for s = 1, 16 do
      if white[s] == k then
        pattern[sel][s] = pattern[sel][s] > 0 and 0 or vel
        if pattern[sel][s] > 0 then hit(sel, vel / 127) end
      end
    end
  elseif k < 16 then
    sel = k + 1
    hit(sel, vel / 127)
    if rec and playing then pattern[sel][math.max(step, 1)] = vel end
  end
  lights()
end

function button(name, z)
  if z == 0 then return end
  if name == "PLAY" then playing = not playing; step = 0 end
  if name == "REC" then rec = not rec end
  if name == "SEQ" then steps = not steps end
  for i, pg in ipairs(PAGES) do if name == pg.button then page = i end end
  if name == "SAVE" then data.save({names = names, kit = kit, pattern = pattern, tempo = clock.tempo, room = ROOM}) end
  lights()
end

function enc(n, d)
  local pg = PAGES[page]
  if n == 5 then sel = (sel - 1 + d) % 16 + 1
  elseif n == 6 then kit[sel][idx.model] = (get(sel, "model") + d) % 6; send(sel, "model")
  elseif n == 7 then clock.set_tempo(clock.tempo + d)
  elseif n <= 4 and pg.room then
    local k = pg.knobs[n]
    ROOM[k] = util.clamp(ROOM[k] + d * 0.02, 0, 1)
    plate:set(k, ROOM[k])
  elseif n <= 4 then
    local k = pg.knobs[n]
    kit[sel][idx[k]] = util.clamp(get(sel, k) + d, lo[k], hi[k])
    send(sel, k)
  end
  lights()
end

function frame() redraw() end

local function knob(x, label, v, lo, hi)
  local t = (v - lo) / (hi - lo)
  screen.level(3)
  screen.rect(x, 178, 50, 5)
  screen.level(12)
  screen.rect(x, 178, math.floor(50 * t + 0.5), 5)
  screen.font(1)
  screen.level(8)
  screen.text(x, 160, label)
  screen.level(15)
  screen.text(x, 188, hi <= 1 and string.format("%d%%", math.floor(v * 100 + 0.5)) or tostring(math.floor(v)))
end

function redraw()
  local now = util.ms()
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 10, "sophie")
  screen.font(1)
  screen.level(8)
  screen.text_right(228, 12, math.floor(clock.tempo) .. " bpm")
  screen.text_right(228, 26, "cpu " .. util.cpu() .. "%  " .. util.cores() .. " cores")
  for p = 1, 16 do                   -- the pads, eight by two
    local x, y = 12 + ((p - 1) % 8) * 27, 48 + ((p - 1) // 8) * 34
    local lit = flash[p] and now - flash[p] < 120
    screen.level(lit and 15 or (p == sel and 11 or 4))
    if lit or p == sel then screen.rect(x, y, 24, 28) else screen.frame(x, y, 24, 28) end
    screen.level(lit and 1 or (p == sel and 1 or 10))
    screen.text_center(x + 12, y + 9, labels[p])
  end
  for s = 1, 16 do                   -- the selected pad's steps
    local x = 12 + (s - 1) * 13.5
    screen.level(s == step and playing and 15 or (pattern[sel][s] > 0 and 11 or 3))
    if pattern[sel][s] > 0 then screen.rect(x, 124, 11, 12) else screen.frame(x, 124, 11, 12) end
  end
  local pg = PAGES[page]
  screen.level(12)
  screen.text(12, 142, labels[sel] .. "  " .. models[get(sel, "model") + 1] .. "   " .. pg.name)
  for i, k in ipairs(pg.knobs) do
    if pg.room then knob(12 + (i - 1) * 56, k, ROOM[k], 0, 1)
    else knob(12 + (i - 1) * 56, k, get(sel, k), lo[k], hi[k]) end
  end
  screen.level(8)
  screen.text(12, 204, (steps and "SEQ: steps on the white keys" or "keys: pads") .. (rec and "   REC" or ""))
  screen.text(12, 220, playing and "PLAY: stop" or "PLAY: start")
  screen.update()
end
