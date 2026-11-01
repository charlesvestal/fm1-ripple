-- rack: build an instrument on the FM-1 from any currents. The keys go through MIDI effects (chords, arp, echo,
-- feel, loop and beat stretch), into a voice, then through two effects.
-- ARP: the MIDI effects (SELECT turns their pages; turning a knob turns the page's effect on, ARP again turns it on
-- or off). EDIT: the voice,
-- FX: the first effect, GLO: the second (ALGORITHM picks the current; SELECT turns its pages of knobs). K1-K4 the
-- page's knobs. SEQ held: the loop, at the stretch on the loop page. PRESET: tempo. OCT- and OCT+: octave.
-- SAVE keeps the rack.

local fx                              -- the MIDI effects
local MIDI = {                        -- their pages: an on switch (or none) and four knobs
  {name = "chord", on = "harm_on", knobs = {"unison", "octaver", "harm1", "harm2"}},
  {name = "arp", on = "arp_on", knobs = {"arp_mode", "arp_rate", "arp_oct", "arp_gate"}},
  {name = "echo", on = "delay_on", knobs = {"delay_time", "repeats", "delay_level", "fb_note"}},
  {name = "feel", on = "swing_on", also = {"gate_on", "humanize_on"}, knobs = {"swing", "gate", "humanize", "chance"}},
  {name = "loop", knobs = {"loop", "stretch", "scale", "root"}, on = "scale_on"},
}
local SECTIONS = {
  {name = "midi", button = "ARP"},
  {name = "voice", button = "EDIT", slot = 1, kind = "voice"},
  {name = "effect 1", button = "FX", slot = 2, kind = "effect"},
  {name = "effect 2", button = "GLO", slot = 3, kind = "effect"},
}
local voices, effects = {}, {"none"}  -- the currents there are, by kind
local slots = {"voice", "delay", "plate"}   -- each slot's current (an effect may be "none")
local loaded = {}                     -- each slot's loaded current (or nil)
local vals = {}                       -- every current's knobs as set, by its name: kept across changes
local midi = {}                       -- the MIDI effects' values, by name
local sec, page = 1, {1, 1, 1, 1}
local octave, held = 0, {}
local status = ""                     -- what the last change said ("no room")

local function find(list, x) for i, v in ipairs(list) do if v == x then return i end end end
local fxparams = {}                   -- the MIDI effects' parameters, by name ({min, max, default})

-- a current's knobs: its parameters, with a step for a detent
local function knobs_of(c)
  local out = {}
  for _, p in ipairs(c:params()) do
    local whole = p.min == math.floor(p.min) and p.max == math.floor(p.max) and p.default == math.floor(p.default)
    p.step = (whole and p.max - p.min <= 200) and 1 or (p.max - p.min) / 100
    out[#out + 1] = p
  end
  return out
end

-- the flow from the slots: every current out, the chosen ones in, their knobs as they were
local function build()
  for _, n in pairs(held) do fx:note(n, 0) end
  held = {}
  flow.clear()
  status = ""
  local chain = {}
  for s = 1, 3 do
    loaded[s] = nil
    local name = slots[s]
    if name ~= "none" then
      if current.fits(name) then
        local c = current.load(name)
        c.knobs = knobs_of(c)
        vals[name] = vals[name] or {}
        for _, p in ipairs(c.knobs) do
          if vals[name][p.name] then c:set(p.name, vals[name][p.name]) else vals[name][p.name] = p.default end
        end
        loaded[s] = c
        chain[#chain + 1] = c
      else
        status = name .. ": no room"
      end
    end
  end
  flow.set(table.unpack(chain))
  fx:connect(loaded[1])
end

local function midi_set(name, v)
  midi[name] = v
  fx:set(name, v)
end

function init()
  fx = midifx.new()
  fx:midi_out(true)                   -- what it plays goes out over USB too (another synth can follow)
  for _, c in ipairs(current.list()) do
    if c.kind == "voice" then voices[#voices + 1] = c.name
    elseif c.kind == "effect" then effects[#effects + 1] = c.name end
  end
  for _, p in ipairs(fx:params()) do
    midi[p.name] = p.default
    fxparams[p.name] = p
  end
  midi.harm_on, midi.harm1 = 0, 7
  clock.set_tempo(110)
  local saved = data.load()
  if saved and saved.slots then
    slots, vals, octave = saved.slots, saved.vals or {}, saved.octave or 0
    for k, v in pairs(saved.midi or {}) do midi[k] = v end
    clock.set_tempo(saved.tempo or 110)
  end
  for k, v in pairs(midi) do fx:set(k, v) end
  fx:set("tempo", math.floor(clock.tempo + 0.5))
  build()
  lights()
end

function lights()
  for i, s in ipairs(SECTIONS) do led.button(s.button, i == sec) end
  for k = 0, 26 do led.key(k, held[k] ~= nil) end
end

function key(k, vel)
  if vel > 0 then
    held[k] = util.note(k) + 12 * octave
    fx:note(held[k], vel / 127)
  elseif held[k] then
    fx:note(held[k], 0)
    held[k] = nil
  end
  lights()
end

function midi_in(b0, b1, b2) fx:midi(b0, b1, b2) end   -- a keyboard, or the clock to follow

local function pages_of(s)
  if s == 1 then return #MIDI end
  local c = loaded[SECTIONS[s].slot]
  return c and math.max(1, (#c.knobs + 3) // 4) or 1
end

function button(name, z)
  if name == "SEQ" then fx:loop(z == 1) return end
  if z == 0 then return end
  for i, s in ipairs(SECTIONS) do
    if name == s.button then
      if i == sec and i == 1 then           -- ARP again: the page's effect on or off
        local pg = MIDI[page[1]]
        if pg.on then
          local on = midi[pg.on] == 1 and 0 or 1
          midi_set(pg.on, on)
          for _, o in ipairs(pg.also or {}) do midi_set(o, on) end
        end
      end
      sec = i
    end
  end
  if name == "OCT-" or name == "OCT+" then
    for _, n in pairs(held) do fx:note(n, 0) end
    held = {}
    octave = util.clamp(octave + (name == "OCT+" and 1 or -1), -3, 3)
  end
  if name == "SAVE" then
    data.save({slots = slots, vals = vals, midi = midi, tempo = clock.tempo, octave = octave})
    status = "saved"
  end
  lights()
end

function enc(n, d)
  local s = SECTIONS[sec]
  if n == 7 then
    clock.set_tempo(clock.tempo + d)
    fx:set("tempo", math.floor(clock.tempo + 0.5))
  elseif n == 5 then
    page[sec] = (page[sec] - 1 + d) % pages_of(sec) + 1
  elseif n == 6 and s.slot then                -- another current in this slot
    local list = s.kind == "voice" and voices or effects
    local i = find(list, slots[s.slot]) or 1
    slots[s.slot] = list[(i - 1 + d) % #list + 1]
    page[sec] = 1
    build()
  elseif n <= 4 and sec == 1 then
    local pg = MIDI[page[1]]
    local name = pg.knobs[n]
    if pg.on and midi[pg.on] ~= 1 and name ~= "loop" and name ~= "stretch" then   -- a knob turned: it is on
      midi_set(pg.on, 1)
      for _, o in ipairs(pg.also or {}) do midi_set(o, 1) end
    end
    local p = fxparams[name]
    local step = (p.max - p.min > 400) and 10 or 1
    midi_set(name, util.clamp(midi[name] + d * step, p.min, p.max))
  elseif n <= 4 and s.slot and loaded[s.slot] then
    local c = loaded[s.slot]
    local p = c.knobs[(page[sec] - 1) * 4 + n]
    if p then
      local v = util.clamp(vals[c.name][p.name] + d * p.step, p.min, p.max)
      vals[c.name][p.name] = v
      c:set(p.name, v)
    end
  end
end


function frame() redraw() end

local function knob(x, label, text, t)
  screen.level(3)
  screen.rect(x, 186, 50, 4)
  screen.level(12)
  screen.rect(x, 186, math.floor(50 * util.clamp(t, 0, 1) + 0.5), 4)
  screen.font(1)
  screen.level(8)
  screen.text(x, 166, label)
  screen.level(15)
  screen.text(x, 194, text)
end

local function fmt(v)
  if v == math.floor(v) then return tostring(math.floor(v)) end
  return string.format(math.abs(v) >= 100 and "%.0f" or "%.2f", v)
end

function redraw()
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 10, "rack")
  screen.font(1)
  screen.level(8)
  screen.text_right(228, 10, math.floor(clock.tempo) .. " bpm  oct " .. (octave > 0 and "+" or "") .. octave)
  screen.text_right(228, 24, "cpu " .. util.cpu() .. "%  free " .. current.room() .. " KB")
  -- the chain: midi -> voice -> effect -> effect
  local names = {"midi", slots[1], slots[2], slots[3]}
  for i = 1, 4 do
    local x = 12 + (i - 1) * 56
    screen.level(i == sec and 14 or 4)
    if i == sec then screen.rect(x, 48, 50, 30) else screen.frame(x, 48, 50, 30) end
    screen.level(i == sec and 1 or 11)
    screen.text_center(x + 25, 52, SECTIONS[i].name)
    screen.text_center(x + 25, 64, i == 1 and "fx" or names[i])
    if i < 4 then screen.level(6); screen.text(x + 50, 56, ">") end
  end
  for i, pg in ipairs(MIDI) do           -- the MIDI effects at a glance: lit when on
    local x = 12 + (i - 1) * 44
    local on = pg.on and midi[pg.on] == 1
    screen.level(on and 12 or 3)
    if on then screen.rect(x, 92, 40, 16) else screen.frame(x, 92, 40, 16) end
    screen.level(on and 1 or (sec == 1 and i == page[1] and 15 or 8))
    screen.text_center(x + 20, 93, pg.name == "loop" and "scale" or pg.name)
  end
  screen.level(12)
  if sec == 1 then
    local pg = MIDI[page[1]]
    screen.text(12, 140, pg.name .. "  " .. (pg.on and (midi[pg.on] == 1 and "on" or "off") or "") ..
      "   page " .. page[1] .. "/" .. #MIDI)
    for i, name in ipairs(pg.knobs) do
      local p = fxparams[name]
      knob(12 + (i - 1) * 56, name:gsub("_", " "), fx:text(name), (midi[name] - p.min) / math.max(1, p.max - p.min))
    end
  else
    local s = SECTIONS[sec]
    local c = loaded[s.slot]
    screen.text(12, 140, s.name .. ": " .. slots[s.slot] .. (c and ("   page " .. page[sec] .. "/" .. pages_of(sec)) or ""))
    if c then
      for i = 1, 4 do
        local p = c.knobs[(page[sec] - 1) * 4 + i]
        if p then
          local v = vals[c.name][p.name]
          knob(12 + (i - 1) * 56, p.name, fmt(v), (v - p.min) / math.max(1e-6, p.max - p.min))
        end
      end
    end
  end
  screen.level(8)
  screen.text(12, 212, status ~= "" and status or "ALGORITHM: the current   SELECT: page")
  screen.text(12, 226, "SEQ held: loop   ARP again: on / off")
  screen.update()
end
