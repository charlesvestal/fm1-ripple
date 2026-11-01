-- rain: plucked notes falling on a scale into a small reverb. The keys play along.
-- K1 how hard it rains, K2 how bright the drops are, K3 the reverb's size, K4 how long the strings ring.
-- PLAY stops and starts the rain; SAVE keeps the knobs for next time.

local pluck, plate
local scale = {0, 3, 5, 7, 10}
local s = {rate = 0.35, bright = 0.6, size = 0.8, ring = 0.996}
local raining = true
local drops = {}

local function apply()
  pluck:set("bright", s.bright)
  pluck:set("decay", s.ring)
  plate:set("size", s.size)
end

function init()
  pluck = current.load("pluck")
  plate = current.load("plate")
  plate:set("mix", 0.35)
  plate:set("decay", 0.85)
  flow.set(pluck, plate)
  local saved = data.load()
  if saved then for k, v in pairs(saved) do s[k] = v end end
  apply()
  led.button("PLAY", raining)
  clock.run(function()
    while true do
      clock.sleep(0.08 + (1 - s.rate) * 0.9 * math.random())
      if raining then
        local d = scale[math.random(#scale)] + 12 * math.random(0, 2)
        pluck:note(60 + d, 0.3 + 0.5 * math.random())
        drops[#drops + 1] = {x = math.random(12, 228), y = 40 + math.random(150), r = 1}
        if #drops > 24 then table.remove(drops, 1) end
      end
    end
  end)
end

function frame()
  for _, d in ipairs(drops) do d.r = d.r + 0.6 end
  while drops[1] and drops[1].r > 40 do table.remove(drops, 1) end
  redraw()
end

function key(k, vel)
  if vel > 0 then
    pluck:note(util.note(k), vel / 127)
    drops[#drops + 1] = {x = 8 + k * 8.6, y = 200, r = 1}
  end
end

function button(name, z)
  if z == 0 then return end
  if name == "PLAY" then
    raining = not raining
    led.button("PLAY", raining)
  elseif name == "SAVE" then
    data.save(s)
  end
end

function enc(n, d)
  if n == 1 then s.rate = util.clamp(s.rate + d * 0.02, 0, 1)
  elseif n == 2 then s.bright = util.clamp(s.bright + d * 0.02, 0, 1)
  elseif n == 3 then s.size = util.clamp(s.size + d * 0.02, 0.2, 1)
  elseif n == 4 then s.ring = util.clamp(s.ring + d * 0.0005, 0.98, 0.9995) end
  apply()
end

function redraw()
  screen.clear()
  for _, d in ipairs(drops) do
    screen.level(math.max(1, 14 - d.r // 3))
    screen.circle(d.x, d.y, d.r // 1, false)
  end
  screen.font(4)
  screen.level(15)
  screen.text(12, 14, "rain")
  screen.font(1)
  screen.level(8)
  screen.text(12, 222, string.format("rain %d%%  bright %d%%  space %d%%", s.rate * 100 // 1, s.bright * 100 // 1,
    s.size * 100 // 1))
  if not raining then screen.text_right(228, 22, "stopped") end
  screen.update()
end
