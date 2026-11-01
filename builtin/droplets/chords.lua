-- chords: each white key plays a chord of the scale on its note; the black keys play single notes over them.
-- PRESET picks the kind: triads, sevenths, sus, ninths or open fifths. ALGORITHM switches the sound (saws or FM).
-- K1 the brightness, K2 the strum (0 plays them together), K3 the spread (close or open), K4 the echo.

local voice, fm, delay, synth
local scale = {0, 2, 4, 5, 7, 9, 11}            -- C major: the white keys are its notes
local kinds = {
  {name = "triads", deg = {0, 2, 4}},
  {name = "sevenths", deg = {0, 2, 4, 6}},
  {name = "sus", deg = {0, 3, 4}},
  {name = "ninths", deg = {0, 2, 4, 8}},
  {name = "fifths", deg = {0, 4, 7}},
}
local s = {kind = 1, bright = 0.5, strum = 0.02, spread = 0, echo = 0.25}
local held = {}                                 -- key -> the notes it plays
local shown = {}

-- the note of scale degree d (0 = C3, 7 = C4 ...)
local function note_of(d)
  return 48 + 12 * (d // 7) + scale[d % 7 + 1]
end

-- key k's place in the scale (white keys only): F3 is degree 3
local function degree_of(k)
  local n = util.note(k)
  for i, p in ipairs(scale) do
    if (n - 48) % 12 == p then return 7 * ((n - 48) // 12) + i - 1 end
  end
end

local function apply()
  voice:set("cutoff", 300 + 6000 * s.bright ^ 2)
  fm:set("index", 0.5 + 6 * s.bright)
  delay:set("mix", s.echo)
end

function init()
  voice = current.load("voice")
  fm = current.load("fm")
  delay = current.load("delay")
  fm:set("ratio", 1)
  fm:set("release", 1.2)
  voice:set("release", 0.8)
  synth = voice
  local saved = data.load()
  if saved then for k, v in pairs(saved) do s[k] = v end end
  apply()
  flow.set(synth, delay)
end

function key(k, vel)
  if vel == 0 then
    for _, n in ipairs(held[k] or {}) do synth:note(n, 0) end
    held[k] = nil
    shown[k] = nil
    redraw()
    return
  end
  local d = degree_of(k)
  if not d then                                 -- a black key: just its note, an octave up
    held[k] = {util.note(k) + 12}
    synth:note(held[k][1], vel / 127)
    return
  end
  local notes = {}
  for i, step in ipairs(kinds[s.kind].deg) do
    local n = note_of(d + step)
    if s.spread > 0 and i % 2 == 0 then n = n + 12 * s.spread end
    notes[#notes + 1] = n
  end
  held[k] = notes
  shown[k] = notes
  local v = vel / 127
  if s.strum <= 0 then
    for _, n in ipairs(notes) do synth:note(n, v * 0.8) end
  else
    clock.run(function()
      for _, n in ipairs(notes) do
        if held[k] ~= notes then return end     -- let go before the strum finished
        synth:note(n, v * 0.8)
        clock.sleep(s.strum)
      end
    end)
  end
  redraw()
end

function button(name, z)
  if name == "SAVE" and z == 1 then data.save(s) end
end

function enc(n, d)
  if n == 7 then s.kind = (s.kind - 1 + d) % #kinds + 1
  elseif n == 6 then
    for k, notes in pairs(held) do for _, nt in ipairs(notes) do synth:note(nt, 0) end end
    held, shown = {}, {}
    synth = (synth == voice) and fm or voice
    flow.set(synth, delay)
  elseif n == 1 then s.bright = util.clamp(s.bright + d * 0.02, 0, 1)
  elseif n == 2 then s.strum = util.clamp(s.strum + d * 0.005, 0, 0.2)
  elseif n == 3 then s.spread = util.clamp(s.spread + d, 0, 1)
  elseif n == 4 then s.echo = util.clamp(s.echo + d * 0.02, 0, 1) end
  apply()
  redraw()
end

local NAMES = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"}

function redraw()
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 4, "chords")
  screen.font(1)
  screen.level(8)
  screen.text_right(228, 6, kinds[s.kind].name)
  screen.text_right(228, 22, synth == voice and "saws" or "fm")
  -- the notes sounding, as dots on a two-octave staff of the twelve names
  local y = 60
  for k, notes in pairs(shown) do
    screen.level(15)
    screen.font(3)
    screen.text(12, y, NAMES[notes[1] % 12 + 1])
    screen.font(1)
    for i, n in ipairs(notes) do
      screen.level(10)
      screen.circle(60 + (n - 48) * 4, y + 8, 4, true)
    end
    y = y + 30
    if y > 180 then break end
  end
  screen.level(8)
  screen.text(12, 208, string.format("bright %d%%  strum %d ms  %s", s.bright * 100 // 1, s.strum * 1000 // 1,
    s.spread > 0 and "open" or "close"))
  screen.text(12, 224, string.format("echo %d%%", s.echo * 100 // 1))
  screen.update()
end
