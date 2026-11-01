-- drone: three FM voices on a root, its fifth and its octave, held, slowly changing colour on their own.
-- The keys move the root. K1 how fast it moves, K2 how bright it is, K3 the FM ratio, K4 the space.

local fm, plate
local ratios = {1, 1.5, 2, 2.5, 3, 3.5, 4}
local s = {motion = 0.3, bright = 0.4, ratio = 3, space = 0.7}
local root = 41                                 -- F2
local playing = {}
local ph = {0, 0.33, 0.66}
local now_index = 0

local function sound(r)
  for _, n in ipairs(playing) do fm:note(n, 0) end
  playing = {r, r + 7, r + 12}
  for _, n in ipairs(playing) do fm:note(n, 0.5) end
end

local function apply()
  fm:set("ratio", ratios[s.ratio])
  plate:set("mix", 0.2 + 0.6 * s.space)
  plate:set("size", 0.5 + 0.5 * s.space)
end

function init()
  fm = current.load("fm")
  plate = current.load("plate")
  fm:set("attack", 1.5)
  fm:set("release", 4)
  fm:set("floor", 1)                             -- the index stays where it is set: no fall after the start
  fm:set("feedback", 0.1)
  plate:set("decay", 0.9)
  local saved = data.load()
  if saved then
    for k, v in pairs(saved) do s[k] = v end
    root = saved.root or root
  end
  apply()
  flow.set(fm, plate)
  sound(root)
  clock.run(function()                          -- the colour: three slow waves on the index
    while true do
      clock.sleep(0.05)
      for i = 1, 3 do ph[i] = (ph[i] + 0.0006 * (1 + i * 0.37) * (0.2 + 4 * s.motion)) % 1 end
      local w = (math.sin(ph[1] * 2 * math.pi) + math.sin(ph[2] * 2 * math.pi) * 0.6 + math.sin(ph[3] * 2 * math.pi) * 0.3) / 1.9
      now_index = util.clamp(0.3 + 5 * s.bright * (1 + 0.7 * w), 0, 12)
      fm:set("index", now_index)
    end
  end)
end

function frame() redraw() end

function key(k, vel)
  if vel > 0 then
    root = util.note(k) - 12
    sound(root)
  end
end

function button(name, z)
  if name == "SAVE" and z == 1 then
    local t = {root = root}
    for k, v in pairs(s) do t[k] = v end
    data.save(t)
  end
end

function enc(n, d)
  if n == 1 then s.motion = util.clamp(s.motion + d * 0.02, 0, 1)
  elseif n == 2 then s.bright = util.clamp(s.bright + d * 0.02, 0, 1)
  elseif n == 3 then s.ratio = util.clamp(s.ratio + d, 1, #ratios)
  elseif n == 4 then s.space = util.clamp(s.space + d * 0.02, 0, 1) end
  apply()
end

local NAMES = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"}

function redraw()
  screen.clear()
  -- three rings breathing with the waves
  for i = 1, 3 do
    local r = 30 + i * 18 + 10 * math.sin(ph[i] * 2 * math.pi)
    screen.level(4 + i * 3)
    screen.circle(120, 120, r, false)
  end
  screen.level(15)
  screen.circle(120, 120, 6 + now_index * 2, true)
  screen.font(4)
  screen.level(15)
  screen.text(12, 4, "drone")
  screen.font(1)
  screen.level(8)
  screen.text_right(228, 6, NAMES[root % 12 + 1] .. (root // 12 - 1))
  screen.text(12, 224, string.format("motion %d%%  bright %d%%  ratio %s  space %d%%", s.motion * 100 // 1,
    s.bright * 100 // 1, tostring(ratios[s.ratio]), s.space * 100 // 1))
  screen.update()
end
