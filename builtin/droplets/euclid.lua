-- euclid: three drum tracks, each spreading its hits as evenly as it can over its steps (Euclidean rhythms).
-- ALGORITHM picks the track. K1 its steps, K2 its hits, K3 turns it round, K4 the tempo.
-- Tracks of different lengths drift against each other. PLAY starts and stops; SAVE keeps it all.
-- The keys play the picked drum.

local drums
local t = {
  {name = "kick", note = 36, steps = 16, hits = 4, turn = 0},
  {name = "snare", note = 38, steps = 16, hits = 2, turn = 4},
  {name = "hat", note = 42, steps = 12, hits = 7, turn = 0},
}
local sel, playing, tick = 1, true, -1
local lit = {0, 0, 0}

-- hit i of steps when (i * hits) mod steps falls under hits: the hits as evenly spaced as whole steps allow
local function hit(tr, i)
  local j = (i - tr.turn) % tr.steps
  return (j * tr.hits) % tr.steps < tr.hits
end

function init()
  drums = current.load("drums")
  flow.set(drums)
  clock.set_tempo(108)
  local saved = data.load()
  if saved and saved.t then
    for i = 1, 3 do for k, v in pairs(saved.t[i] or {}) do t[i][k] = v end end
    clock.set_tempo(saved.tempo or 108)
  end
  led.button("PLAY", playing)
  clock.run(function()
    while true do
      clock.sync(1 / 4)
      if playing then
        tick = tick + 1
        for i, tr in ipairs(t) do
          if tr.hits > 0 and hit(tr, tick % tr.steps) then
            local accent = tick % tr.steps == 0
            drums:note(tr.note, accent and 1 or (i == 3 and 0.55 or 0.8))
            lit[i] = 4
          end
        end
      end
    end
  end)
end

function frame()
  for i = 1, 3 do if lit[i] > 0 then lit[i] = lit[i] - 1 end end
  redraw()
end

function key(k, vel)
  if vel > 0 then drums:note(t[sel].note, vel / 127) end
end

function button(name, z)
  if z == 0 then return end
  if name == "PLAY" then
    playing = not playing
    tick = -1
    led.button("PLAY", playing)
  elseif name == "SAVE" then
    data.save({t = t, tempo = clock.tempo})
  end
end

function enc(n, d)
  local tr = t[sel]
  if n == 6 then sel = (sel - 1 + d) % 3 + 1
  elseif n == 1 then tr.steps = util.clamp(tr.steps + d, 1, 16); tr.hits = math.min(tr.hits, tr.steps)
  elseif n == 2 then tr.hits = util.clamp(tr.hits + d, 0, tr.steps)
  elseif n == 3 then tr.turn = (tr.turn + d) % tr.steps
  elseif n == 4 then clock.set_tempo(clock.tempo + d) end
end

function redraw()
  screen.clear()
  -- three rings, the kick outside: a dot a step, lit where it hits, the step playing the brightest
  for i, tr in ipairs(t) do
    local r = 96 - (i - 1) * 26
    for s = 0, tr.steps - 1 do
      local a = s / tr.steps * 2 * math.pi - math.pi / 2
      local x, y = 120 + r * math.cos(a), 124 + r * math.sin(a)
      local now = playing and tick >= 0 and s == tick % tr.steps
      if hit(tr, s) then
        screen.level(now and 15 or (i == sel and 12 or 7))
        screen.circle(x, y, now and 6 or 4, true)
      else
        screen.level(now and 10 or (i == sel and 5 or 2))
        screen.circle(x, y, 2, true)
      end
    end
  end
  screen.font(4)
  screen.level(15)
  screen.text(12, 4, "euclid")
  screen.font(1)
  local tr = t[sel]
  screen.level(12)
  screen.text_right(228, 6, tr.name)
  screen.level(8)
  screen.text_right(228, 22, tr.hits .. " in " .. tr.steps .. "  turn " .. tr.turn)
  screen.text(12, 224, math.floor(clock.tempo) .. " bpm")
  screen.update()
end
