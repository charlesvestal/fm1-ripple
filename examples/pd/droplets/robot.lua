-- robot: a drum beat sung through a vocoder. The drums are the voice, the keys the note it sings.
-- Currents: drums (built in), vocoder and vca (Pd patches by boochow).
-- K1 and K2 the two notes the vocoder adds above the key (semitones), K3 how long its bands ring, K4 the tempo.
-- PLAY starts and stops the beat.

local drums, voc, gain
local playing, tick, held = true, -1, nil
local s = {note1 = 7, note2 = 12, ring = 0.5}
local beat = {                                  -- a step a sixteenth: kick, snare, hat
  {36, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
  {38, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
  {42, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
}
local lit = 0
local GAIN = 0.14                               -- (the Pd patches play at full scale)

local function apply()
  voc:set("note1", s.note1)
  voc:set("note2", s.note2)
  voc:set("shape_f", 0.99 + 0.009 * s.ring)
end

function init()
  drums = current.load("drums")
  voc = current.load("vocoder")
  gain = current.load("vca")
  flow.set(drums, voc, gain)
  gain:set("depth_f", GAIN)                     -- the vocoder's bands add up above full scale: turned down
  flow.level(0.6)
  clock.set_tempo(96)
  apply()
  voc:note(48, 1)                               -- C3 until a key says otherwise
  held = 48
  led.button("PLAY", playing)
  clock.run(function()
    while true do
      clock.sync(1 / 4)
      if playing then
        tick = tick + 1
        local st = tick % 16 + 2
        for _, tr in ipairs(beat) do
          if tr[st] == 1 then drums:note(tr[1], tr[1] == 42 and 0.5 or 0.9) end
        end
        if tick % 4 == 0 then lit = 3 end
      end
    end
  end)
end

function frame()
  if lit > 0 then lit = lit - 1 end
  redraw()
end

function key(k, vel)
  if vel > 0 then
    held = util.note(k)
    voc:note(held, 1)
  end
end

function button(name, z)
  if name == "PLAY" and z == 1 then
    playing = not playing
    tick = -1
    led.button("PLAY", playing)
  end
end

function enc(n, d)
  if n == 1 then s.note1 = util.clamp(s.note1 + d, 0, 12)
  elseif n == 2 then s.note2 = util.clamp(s.note2 + d, 0, 12)
  elseif n == 3 then s.ring = util.clamp(s.ring + d / 20, 0, 1)
  elseif n == 4 then clock.set_tempo(clock.tempo + d) end
  apply()
end

local names = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"}

function redraw()
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 4, "robot")
  screen.font(1)
  screen.level(6)
  screen.text(12, 40, "drums > vocoder > vca")
  -- the three notes it sings, as bars
  local root = held or 48
  for i, iv in ipairs({0, s.note1, s.note2}) do
    local h = 30 + iv * 6
    screen.level(i == 1 and (12 + lit) or 8)
    screen.rect(40 + (i - 1) * 60, 170 - h, 40, h)
    screen.level(10)
    screen.text_center(60 + (i - 1) * 60, 178, names[(root + iv) % 12 + 1])
  end
  screen.level(8)
  screen.text(12, 210, "ring " .. math.floor(s.ring * 100 + 0.5) .. "%")
  screen.text_right(228, 210, math.floor(clock.tempo) .. " bpm")
  screen.update()
end
