-- beat: a 16-step drum machine on the drums current.
-- The white keys are the 16 steps; ALGORITHM picks the drum (kick, snare, hat). PLAY starts and stops.
-- K1 tempo, K2 tune, K3 decay, K4 snap.

local drums
local names = {"kick", "snare", "hat"}
local notes = {36, 38, 42}
local pattern = {}
local track, step, playing = 1, 0, false
local white = {0, 2, 4, 6, 7, 9, 11, 12, 14, 16, 18, 19, 21, 23, 24, 26}
local tune, decay, snap = 1, 1, 0.5

function init()
  drums = current.load("drums")
  flow.set(drums)
  for t = 1, 3 do pattern[t] = {} for s = 1, 16 do pattern[t][s] = false end end
  for _, s in ipairs({1, 5, 9, 13}) do pattern[1][s] = true end
  pattern[2][5], pattern[2][13] = true, true
  for s = 1, 16, 2 do pattern[3][s] = true end
  clock.set_tempo(112)
  clock.run(function()
    while true do
      clock.sync(1 / 4)
      if playing then
        step = step % 16 + 1
        for t = 1, 3 do if pattern[t][step] then drums:note(notes[t], t == 3 and 0.6 or 0.9) end end
        lights()
        redraw()
      end
    end
  end)
  lights()
end

function lights()
  for s = 1, 16 do led.key(white[s], pattern[track][s] ~= (s == step and playing)) end
  led.button("PLAY", playing)
end

function key(k, vel)
  if vel == 0 then return end
  for s = 1, 16 do
    if white[s] == k then
      pattern[track][s] = not pattern[track][s]
      if pattern[track][s] then drums:note(notes[track], vel / 127) end
    end
  end
  lights()
  redraw()
end

function button(name, z)
  if z == 0 then return end
  if name == "PLAY" then playing = not playing; step = 0 end
  lights()
  redraw()
end

function enc(n, d)
  if n == 6 then track = (track - 1 + d) % 3 + 1
  elseif n == 1 then clock.set_tempo(clock.tempo + d)
  elseif n == 2 then tune = util.clamp(tune + d * 0.02, 0.5, 2); drums:set("tune", tune)
  elseif n == 3 then decay = util.clamp(decay + d * 0.05, 0.3, 2); drums:set("decay", decay)
  elseif n == 4 then snap = util.clamp(snap + d * 0.05, 0, 1); drums:set("snap", snap) end
  lights()
  redraw()
end

function redraw()
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 14, "beat")
  screen.font(1)
  screen.level(8)
  screen.text_right(228, 22, math.floor(clock.tempo) .. " bpm")
  for t = 1, 3 do
    local y = 60 + (t - 1) * 40
    screen.level(t == track and 15 or 7)
    screen.text(12, y + 4, names[t])
    for s = 1, 16 do
      local x = 58 + (s - 1) * 11
      if pattern[t][s] then
        screen.level(s == step and 15 or (t == track and 12 or 8))
        screen.rect(x, y, 9, 18)
      else
        screen.level(s == step and 10 or 3)
        screen.frame(x, y, 9, 18)
      end
    end
  end
  screen.level(8)
  screen.text(12, 204, "ALGORITHM: drum   keys: steps")
  screen.text(12, 220, playing and "PLAY: stop" or "PLAY: start")
  screen.update()
end
