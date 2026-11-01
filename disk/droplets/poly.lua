-- poly: the keys play a six-voice synth through a delay.
-- K1 cutoff, K2 resonance, K3 delay time, K4 feedback. OCT- and OCT+ move the keys an octave.
-- ALGORITHM switches the synth: voice (saws and a filter) or fm (two sines; K1 its brightness, K2 the ratio).

local voice, fm, delay, synth
local cutoff, res, time, fb = 2400, 1.5, 0.28, 0.45
local octave = 0
local held = {}

local ratio, index = 2, 3

function init()
  voice = current.load("voice")
  fm = current.load("fm")
  delay = current.load("delay")
  synth = voice
  flow.set(voice, delay)
end

function key(k, vel)
  local n = util.note(k) + 12 * octave
  if vel > 0 then
    held[k] = n
    synth:note(n, vel / 127)
  elseif held[k] then
    synth:note(held[k], 0)
    held[k] = nil
  end
  redraw()
end

function button(name, z)
  if z == 0 then return end
  if name == "OCT-" then octave = math.max(-2, octave - 1) end
  if name == "OCT+" then octave = math.min(2, octave + 1) end
  redraw()
end

function enc(n, d)
  if n == 6 then
    for k, h in pairs(held) do synth:note(h, 0) end
    held = {}
    synth = (synth == voice) and fm or voice
    flow.set(synth, delay)
  elseif synth == fm and n == 1 then index = util.clamp(index + d * 0.2, 0, 12); fm:set("index", index)
  elseif synth == fm and n == 2 then ratio = util.clamp(ratio + d * 0.5, 0.5, 8); fm:set("ratio", ratio)
  elseif n == 1 then cutoff = util.clamp(cutoff * 1.04 ^ d, 60, 12000); voice:set("cutoff", cutoff)
  elseif n == 2 then res = util.clamp(res + d * 0.1, 0.5, 8); voice:set("res", res)
  elseif n == 3 then time = util.clamp(time + d * 0.005, 0.01, 0.36); delay:set("time", time)
  elseif n == 4 then fb = util.clamp(fb + d * 0.02, 0, 0.92); delay:set("feedback", fb) end
  redraw()
end

local function knob(x, label, v, lo, hi, text)
  local t = (v - lo) / (hi - lo)
  screen.level(3)
  screen.rect(x, 150, 48, 6)
  screen.level(12)
  screen.rect(x, 150, math.floor(48 * t + 0.5), 6)
  screen.font(1)
  screen.level(8)
  screen.text(x, 162, label)
  screen.level(15)
  screen.text(x, 176, text)
end

function redraw()
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 14, synth == voice and "poly" or "poly fm")
  screen.font(1)
  screen.level(8)
  screen.text_right(228, 22, "octave " .. (octave >= 0 and "+" or "") .. octave)
  -- a ripple for each held key
  for k, n in pairs(held) do
    screen.level(6 + (n % 12) // 2)
    screen.circle(20 + k * 7.5, 96, 4 + (n % 12), false)
  end
  if synth == voice then
    knob(12, "cutoff", math.log(cutoff), math.log(60), math.log(12000), math.floor(cutoff) .. " Hz")
    knob(66, "resonance", res, 0.5, 8, string.format("%.1f", res))
  else
    knob(12, "index", index, 0, 12, string.format("%.1f", index))
    knob(66, "ratio", ratio, 0.5, 8, string.format("%.1f", ratio))
  end
  knob(120, "time", time, 0.01, 0.36, math.floor(time * 1000) .. " ms")
  knob(174, "feedback", fb, 0, 0.92, math.floor(fb * 100) .. "%")
  screen.update()
end
