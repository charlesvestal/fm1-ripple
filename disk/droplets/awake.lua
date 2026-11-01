-- awake: a melody that wanders a scale on its own (after norns's awake).
-- K1 tempo, K2 how far it wanders, K3 how often it rests, K4 the filter.
-- PLAY stops and starts it. The keys play along.

local voice, delay
local scale = {0, 2, 3, 5, 7, 9, 10}
local pos, steps, step = 8, {}, 1
local wander, rest, cutoff = 2, 0.2, 1800
local playing = true
local last

local function degree(i)
  local o = (i - 1) // #scale
  return 48 + 12 * o + scale[(i - 1) % #scale + 1]
end

function init()
  voice = current.load("voice")
  delay = current.load("delay")
  voice:set("release", 0.6)
  voice:set("cutoff", cutoff)
  delay:set("mix", 0.35)
  delay:set("feedback", 0.55)
  flow.set(voice, delay)
  for i = 1, 16 do steps[i] = 0 end
  clock.set_tempo(96)
  clock.run(function()
    while true do
      clock.sync(1 / 4)
      if playing then
        if last then voice:note(last, 0); last = nil end
        pos = util.clamp(pos + math.random(-wander, wander), 1, 21)
        steps[step] = 0
        if math.random() >= rest then
          last = degree(pos)
          steps[step] = pos
          voice:note(last, 0.5 + math.random() * 0.4)
        end
        step = step % 16 + 1
        redraw()
      end
    end
  end)
end

function key(k, vel)
  local n = util.note(k)
  voice:note(n, vel / 127)
end

function button(name, z)
  if name == "PLAY" and z == 1 then
    playing = not playing
    if not playing and last then voice:note(last, 0); last = nil end
    led.button("PLAY", playing)
    redraw()
  end
end

function enc(n, d)
  if n == 1 then clock.set_tempo(clock.tempo + d)
  elseif n == 2 then wander = util.clamp(wander + d, 1, 5)
  elseif n == 3 then rest = util.clamp(rest + d * 0.05, 0, 0.9)
  elseif n == 4 then cutoff = util.clamp(cutoff * 1.05 ^ d, 200, 9000); voice:set("cutoff", cutoff) end
  redraw()
end

function redraw()
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 14, "awake")
  screen.font(1)
  screen.level(8)
  screen.text_right(228, 22, math.floor(clock.tempo) .. " bpm")
  for i = 1, 16 do
    local x = 8 + (i - 1) * 14
    local v = steps[i]
    screen.level(i == step and 15 or 3)
    screen.rect(x, 186, 12, 2)
    if v > 0 then
      screen.level(i == (step - 2) % 16 + 1 and 15 or 9)
      screen.circle(x + 6, 176 - v * 6, 3, true)
    end
  end
  screen.level(8)
  screen.text(12, 204, "wander " .. wander .. "   rest " .. math.floor(rest * 100) .. "%")
  screen.text(12, 220, playing and "PLAY: stop" or "PLAY: start")
  screen.update()
end

function cleanup()
  if last then voice:note(last, 0) end
end
