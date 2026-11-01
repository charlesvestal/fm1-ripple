-- midi: the FM-1 as a MIDI controller over USB, no sound of its own. The keys send notes with their velocity,
-- K1 to K4 send CCs 74, 71, 1 and 7, OCT- and OCT+ move the keys an octave, PRESET picks the channel.
-- What comes in over MIDI is shown at the bottom.

local s = {chan = 1, octave = 0, cc = {74, 71, 1, 7}, val = {64, 64, 0, 100}}
local held = {}
local last_in = "nothing yet"

function init()
  local saved = data.load()
  if saved then for k, v in pairs(saved) do s[k] = v end end
end

function key(k, vel)
  local n = util.clamp(util.note(k) + 12 * s.octave, 0, 127)
  if vel > 0 then
    held[k] = n
    midi.send(0x90 + s.chan - 1, n, vel)
    led.key(k, true)
  elseif held[k] then
    midi.send(0x80 + s.chan - 1, held[k], 0)
    held[k] = nil
    led.key(k, false)
  end
  redraw()
end

function button(name, z)
  if z == 0 then return end
  if name == "OCT-" then s.octave = math.max(-3, s.octave - 1)
  elseif name == "OCT+" then s.octave = math.min(3, s.octave + 1)
  elseif name == "SAVE" then data.save(s) end
  redraw()
end

function enc(n, d)
  if n >= 1 and n <= 4 then
    s.val[n] = util.clamp(s.val[n] + d, 0, 127)
    midi.send(0xB0 + s.chan - 1, s.cc[n], s.val[n])
  elseif n == 7 then
    s.chan = (s.chan - 1 + d) % 16 + 1
  end
  redraw()
end

function midi_in(b0, b1, b2)
  local kinds = {[0x80] = "note off", [0x90] = "note on", [0xB0] = "cc", [0xE0] = "bend", [0xC0] = "program"}
  local k = kinds[b0 & 0xF0]
  if k then last_in = string.format("%s  ch %d  %d %d", k, (b0 & 15) + 1, b1, b2) end
  redraw()
end

function redraw()
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 4, "midi")
  screen.font(1)
  screen.level(8)
  screen.text_right(228, 6, "channel " .. s.chan)
  screen.text_right(228, 22, "octave " .. (s.octave >= 0 and "+" or "") .. s.octave)
  for i = 1, 4 do
    local x = 12 + (i - 1) * 56
    screen.level(3)
    screen.rect(x, 60, 44, 100)
    screen.level(12)
    local h = s.val[i] * 100 // 127
    screen.rect(x, 160 - h, 44, h)
    screen.level(8)
    screen.text(x, 166, "CC " .. s.cc[i])
    screen.level(15)
    screen.text(x, 180, tostring(s.val[i]))
  end
  screen.level(6)
  screen.text(12, 208, "in:")
  screen.level(10)
  screen.text(36, 208, last_in)
  screen.update()
end
