-- loop: play a phrase and it plays back, over and over; play again over it to add to it.
-- REC starts and stops recording (it records over what is there). PLAY starts and stops the loop. EDIT clears it.
-- K1 the loop's length (1, 2 or 4 bars), K2 the tempo, K3 the strings' ring, K4 the space. SAVE keeps the loop.

local pluck, plate
local s = {bars = 2, ring = 0.996, space = 0.5}
local events = {}                               -- {step, note, vel, len}
local recording, playing = false, true
local step = 0
local open = {}                                 -- key -> the event still held
local glow = {}

local function steps() return s.bars * 16 end

local function apply()
  pluck:set("decay", s.ring)
  plate:set("mix", 0.15 + 0.4 * s.space)
  plate:set("size", 0.4 + 0.6 * s.space)
end

function init()
  pluck = current.load("pluck")
  plate = current.load("plate")
  plate:set("decay", 0.82)
  local saved = data.load()
  if saved then
    for k, v in pairs(saved.s or {}) do s[k] = v end
    events = saved.events or {}
    clock.set_tempo(saved.tempo or 100)
  else
    clock.set_tempo(100)
  end
  apply()
  flow.set(pluck, plate)
  led.button("PLAY", playing)
  clock.run(function()
    while true do
      clock.sync(1 / 4)
      if playing then
        step = step % steps() + 1
        for _, e in ipairs(events) do
          if e.step == step then
            pluck:note(e.note, e.vel)
            glow[#glow + 1] = {e = e, g = 15}
          end
        end
        led.button("REC", recording and step % 4 == 1)
      end
    end
  end)
end

function frame()
  for i = #glow, 1, -1 do
    glow[i].g = glow[i].g - 1
    if glow[i].g <= 0 then table.remove(glow, i) end
  end
  redraw()
end

function key(k, vel)
  local n = util.note(k)
  if vel > 0 then
    pluck:note(n, vel / 127)
    if recording and playing then
      local e = {step = math.max(1, step), note = n, vel = vel / 127}
      events[#events + 1] = e
      glow[#glow + 1] = {e = e, g = 15}
    end
  else
    pluck:note(n, 0)
  end
end

function button(name, z)
  if z == 0 then return end
  if name == "REC" then
    recording = not recording
    if recording and not playing then playing = true; step = 0 end
    led.button("REC", recording)
  elseif name == "PLAY" then
    playing = not playing
    step = 0
    if not playing then recording = false; led.button("REC", false) end
  elseif name == "EDIT" then
    events = {}
  elseif name == "SAVE" then
    data.save({s = s, events = events, tempo = clock.tempo})
  end
  led.button("PLAY", playing)
end

function enc(n, d)
  if n == 1 then
    local b = {1, 2, 4}
    local i = 1
    for j, v in ipairs(b) do if v == s.bars then i = j end end
    s.bars = b[util.clamp(i + d, 1, 3)]
  elseif n == 2 then clock.set_tempo(clock.tempo + d)
  elseif n == 3 then s.ring = util.clamp(s.ring + d * 0.0005, 0.98, 0.9995)
  elseif n == 4 then s.space = util.clamp(s.space + d * 0.02, 0, 1) end
  apply()
end

function redraw()
  screen.clear()
  -- the loop as a circle, time going round it; each note a drop at its time, higher notes further out
  local n = steps()
  screen.level(3)
  screen.circle(120, 126, 70, false)
  for _, e in ipairs(events) do
    if e.step <= n then
      local a = (e.step - 1) / n * 2 * math.pi - math.pi / 2
      local r = 40 + (e.note - 53) * 2
      screen.level(8)
      screen.circle(120 + r * math.cos(a), 126 + r * math.sin(a), 3, true)
    end
  end
  for _, g in ipairs(glow) do
    local a = (g.e.step - 1) / n * 2 * math.pi - math.pi / 2
    local r = 40 + (g.e.note - 53) * 2
    screen.level(g.g)
    screen.circle(120 + r * math.cos(a), 126 + r * math.sin(a), 3 + (15 - g.g) // 2, false)
  end
  if playing then
    local a = (math.max(1, step) - 1) / n * 2 * math.pi - math.pi / 2
    screen.level(15)
    screen.line(120, 126, 120 + 84 * math.cos(a), 126 + 84 * math.sin(a))
  end
  screen.font(4)
  screen.level(recording and 15 or 12)
  screen.text(12, 4, recording and "loop  rec" or "loop")
  screen.font(1)
  screen.level(8)
  screen.text_right(228, 6, s.bars .. " bar" .. (s.bars > 1 and "s" or "") .. "  " .. math.floor(clock.tempo) .. " bpm")
  screen.text(12, 224, #events .. " notes   REC record   EDIT clear")
  screen.update()
end
