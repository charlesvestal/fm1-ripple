-- fold: a drone through a wavefolder, slowly shifting in frequency and ringing in a small room. The keys move its
-- root. Currents: logue-wavefolder, nts-freqshift, nts-reflection (Pd patches by boochow).
-- K1 how hard it folds, K2 the frequency shift (Hz), K3 the room, K4 how fast it moves.

local osc, shift, room
local s = {fold = 5, shift = 3, room = 0.5, motion = 0.3}
local root = 41                                 -- F2
local ph, wob = 0, 0

local function apply()
  osc:set("scale_f", s.fold)
  shift:set("time", s.shift)
  room:set("depth_f", s.room)
  room:set("time_f", 0.3 + 0.6 * s.room)
end

function init()
  osc = current.load("logue-wavefolder")
  shift = current.load("nts-freqshift")
  room = current.load("nts-reflection")
  flow.set(osc, shift, room)
  flow.level(0.25)
  shift:set("depth_f", 0.6)
  apply()
  osc:note(root, 1)
  clock.run(function()                          -- the motion: the fold's shape and its LFO input, two slow waves
    while true do
      clock.sleep(0.05)
      ph = (ph + 0.002 * (0.2 + 3 * s.motion)) % 1
      wob = (math.sin(ph * 2 * math.pi) + 0.5 * math.sin(ph * 6 * math.pi + 1)) / 1.5
      osc:set("shape_f", 0.5 + 0.45 * wob)
      osc:set("slfo", 0.5 + 0.5 * math.sin(ph * 4 * math.pi))
    end
  end)
end

function frame() redraw() end

function key(k, vel)
  if vel > 0 then
    root = util.note(k) - 12
    osc:note(root, 1)
  end
end

function enc(n, d)
  if n == 1 then s.fold = util.clamp(s.fold + d / 4, 1, 10)
  elseif n == 2 then s.shift = util.clamp(s.shift + d, -50, 50)
  elseif n == 3 then s.room = util.clamp(s.room + d / 20, 0, 1)
  elseif n == 4 then s.motion = util.clamp(s.motion + d / 20, 0, 1) end
  apply()
end

function redraw()
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 4, "fold")
  screen.font(1)
  screen.level(6)
  screen.text(12, 40, "wavefolder > shift > room")
  -- a sine folded back on itself as hard as K1 says, moving with the motion
  local px, py
  for x = 0, 216, 3 do
    local v = math.sin((x / 216 * 2 + ph) * 2 * math.pi) * (1 + s.fold * (0.6 + 0.4 * wob))
    for _ = 1, 8 do                             -- fold into -1..1
      if v > 1 then v = 2 - v elseif v < -1 then v = -2 - v end
    end
    local y = 120 - v * 50
    if px then
      screen.level(12)
      screen.line(px, py, 12 + x, y)
    end
    px, py = 12 + x, y
  end
  screen.level(8)
  screen.text(12, 190, "fold " .. string.format("%.1f", s.fold) .. "   shift " .. s.shift .. " Hz")
  screen.text(12, 210, "room " .. math.floor(s.room * 100 + 0.5) .. "%")
  screen.text_right(228, 210, "motion " .. math.floor(s.motion * 100 + 0.5) .. "%")
  screen.update()
end
