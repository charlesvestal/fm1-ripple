-- bells: FM bells on loops of different lengths (13, 17, 23, 29 ... sixteenths), drifting in and out of step, into
-- a reverb. Each bell now and then moves to a neighbouring note of the scale.
-- K1 the tempo, K2 how bright they ring, K3 the space, K4 how many bells. The keys ring a bell too.

local fm, plate
local scale = {0, 2, 4, 7, 9}                   -- pentatonic
local loops = {13, 17, 23, 29, 31, 37}
local bells = {}
local s = {bright = 0.5, space = 0.6, count = 4}
local tick = 0

local function note_of(d) return 60 + 12 * (d // #scale) + scale[d % #scale + 1] end

local function apply()
  fm:set("index", 1 + 7 * s.bright)
  plate:set("mix", 0.2 + 0.5 * s.space)
  plate:set("size", 0.4 + 0.6 * s.space)
end

function init()
  fm = current.load("fm")
  plate = current.load("plate")
  fm:set("ratio", 3.5)                          -- not a whole number: the partials of a bell, not a string
  fm:set("fall", 1.5)
  fm:set("floor", 0)
  fm:set("release", 3)
  fm:set("attack", 0.001)
  plate:set("decay", 0.88)
  for i = 1, #loops do bells[i] = {deg = math.random(0, 9), glow = 0} end
  local saved = data.load()
  if saved then for k, v in pairs(saved) do s[k] = v end end
  apply()
  flow.set(fm, plate)
  clock.set_tempo(84)
  clock.run(function()
    while true do
      clock.sync(1 / 4)
      tick = tick + 1
      for i = 1, s.count do
        local b = bells[i]
        if tick % loops[i] == 0 then
          if math.random() < 0.25 then b.deg = util.clamp(b.deg + math.random(-1, 1), 0, 9) end
          local n = note_of(b.deg)
          fm:note(n, 0.4 + 0.3 * math.random())
          b.glow = 15
          clock.run(function() clock.sleep(0.2); fm:note(n, 0) end)
        end
      end
    end
  end)
end

function frame()
  for _, b in ipairs(bells) do if b.glow > 0 then b.glow = b.glow - 1 end end
  redraw()
end

function key(k, vel)
  if vel > 0 then fm:note(util.note(k) + 12, vel / 127)
  else fm:note(util.note(k) + 12, 0) end
end

function button(name, z)
  if name == "SAVE" and z == 1 then data.save(s) end
end

function enc(n, d)
  if n == 1 then clock.set_tempo(clock.tempo + d)
  elseif n == 2 then s.bright = util.clamp(s.bright + d * 0.02, 0, 1)
  elseif n == 3 then s.space = util.clamp(s.space + d * 0.02, 0, 1)
  elseif n == 4 then s.count = util.clamp(s.count + d, 1, #loops) end
  apply()
end

function redraw()
  screen.clear()
  -- each bell a ring; a dot goes round it once a loop, and the bell glows when it rings
  for i = 1, s.count do
    local r = 18 + i * 14
    local a = (tick % loops[i]) / loops[i] * 2 * math.pi - math.pi / 2
    screen.level(2 + bells[i].glow // 3)
    screen.circle(120, 126, r, false)
    screen.level(math.max(6, bells[i].glow))
    screen.circle(120 + r * math.cos(a), 126 + r * math.sin(a), 3 + bells[i].glow // 5, true)
  end
  screen.font(4)
  screen.level(15)
  screen.text(12, 4, "bells")
  screen.font(1)
  screen.level(8)
  screen.text_right(228, 6, math.floor(clock.tempo) .. " bpm")
  screen.text(12, 224, s.count .. " bells   bright " .. math.floor(s.bright * 100) .. "%   space " .. math.floor(s.space * 100) .. "%")
  screen.update()
end
