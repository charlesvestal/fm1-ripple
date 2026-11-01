-- arp: hold keys and they play one after another. PRESET picks the order: up, down, up and down, random, or as
-- played. ARP holds the notes after you let go (press it again to stop). ALGORITHM switches the sound.
-- K1 the rate, K2 how many octaves, K3 how long each note lasts, K4 the brightness.

local voice, fm, delay, synth
local orders = {"up", "down", "up down", "random", "as played"}
local rates = {1 / 2, 1 / 3, 1 / 4, 1 / 6, 1 / 8}
local rate_names = {"8ths", "8th triplets", "16ths", "16th triplets", "32nds"}
local s = {order = 1, rate = 3, octaves = 1, gate = 0.5, bright = 0.5}
local down, order, latched = {}, {}, false     -- keys held, the notes in the order played, ARP's hold
local pos, last = 0, nil

local function notes()
  local list = {}
  for _, n in ipairs(order) do list[#list + 1] = n end
  if s.order <= 3 then table.sort(list) end
  local all = {}
  for o = 0, s.octaves - 1 do for _, n in ipairs(list) do all[#all + 1] = n + 12 * o end end
  if s.order == 2 then
    local r = {}
    for i = #all, 1, -1 do r[#r + 1] = all[i] end
    all = r
  elseif s.order == 3 and #all > 2 then
    for i = #all - 1, 2, -1 do all[#all + 1] = all[i] end
  end
  return all
end

local function apply()
  voice:set("cutoff", 300 + 7000 * s.bright ^ 2)
  fm:set("index", 0.5 + 6 * s.bright)
end

function init()
  voice = current.load("voice")
  fm = current.load("fm")
  delay = current.load("delay")
  delay:set("mix", 0.2)
  synth = voice
  local saved = data.load()
  if saved then for k, v in pairs(saved) do s[k] = v end end
  apply()
  flow.set(synth, delay)
  clock.run(function()
    while true do
      clock.sync(rates[s.rate])
      local all = notes()
      if #all > 0 then
        pos = pos % #all + 1
        local n = s.order == 4 and all[math.random(#all)] or all[pos]
        synth:note(n, 0.75)
        last = n
        redraw()
        clock.sleep(rates[s.rate] * 60 / clock.tempo * s.gate)
        synth:note(n, 0)
      else
        pos = 0
      end
    end
  end)
end

function key(k, vel)
  local n = util.note(k)
  if vel > 0 then
    if latched and next(down) == nil then order = {} end   -- a new chord after letting go replaces the held one
    down[k] = true
    order[#order + 1] = n
  else
    down[k] = nil
    if not latched then
      for i = #order, 1, -1 do if order[i] == n then table.remove(order, i) end end
    end
  end
  redraw()
end

function button(name, z)
  if z == 0 then return end
  if name == "ARP" then
    latched = not latched
    if not latched then order = {}; for k in pairs(down) do order[#order + 1] = util.note(k) end end
    led.button("ARP", latched)
  elseif name == "SAVE" then data.save(s) end
  redraw()
end

function enc(n, d)
  if n == 7 then s.order = (s.order - 1 + d) % #orders + 1
  elseif n == 6 then synth = (synth == voice) and fm or voice; flow.set(synth, delay)
  elseif n == 1 then s.rate = util.clamp(s.rate + d, 1, #rates)
  elseif n == 2 then s.octaves = util.clamp(s.octaves + d, 1, 3)
  elseif n == 3 then s.gate = util.clamp(s.gate + d * 0.05, 0.1, 1)
  elseif n == 4 then s.bright = util.clamp(s.bright + d * 0.02, 0, 1) end
  apply()
  redraw()
end

function redraw()
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 4, "arp")
  screen.font(1)
  screen.level(8)
  screen.text_right(228, 6, orders[s.order])
  screen.text_right(228, 22, latched and "held" or "")
  -- the notes it goes through, as a row of drops; the one sounding the brightest
  local all = notes()
  local w = math.min(24, 216 // math.max(1, #all))
  for i, n in ipairs(all) do
    local x = 12 + (i - 1) * w + w // 2
    local y = 190 - (n - 48) * 3
    screen.level(n == last and 15 or 6)
    screen.circle(x, y, n == last and 6 or 4, true)
  end
  screen.level(8)
  screen.text(12, 208, rate_names[s.rate] .. "   " .. s.octaves .. " octave" .. (s.octaves > 1 and "s" or "") ..
    "   gate " .. math.floor(s.gate * 100) .. "%")
  screen.text(12, 224, synth == voice and "saws" or "fm")
  screen.update()
end
