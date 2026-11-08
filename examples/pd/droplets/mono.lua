-- mono: a monophonic synth with a filter and an envelope, through a stereo chorus. The last key held plays.
-- Currents: monosynth and chorus (Pd patches by boochow).
-- ALGORITHM the wave (saw, pulse), K1 the cutoff, K2 the resonance, K3 how much the envelope opens the filter,
-- K4 the release. SAVE keeps the sound.

local synth, chorus
local s = {wave = 0, cutoff = 0.2, res = 0.3, env = 0.5, release = 0.3}
local down = {}

local function apply()
  synth:set("_1_wvform_f", s.wave)
  synth:set("_2_PWM_f", 0.3)
  synth:set("_3_cutoff_f", s.cutoff)
  synth:set("fltrrez_f", s.res)
  synth:set("fltrenv_f", s.env)
  synth:set("_4_Attack_f", 0)
  synth:set("_5_Decay_f", 0.4)
  synth:set("_6_Sustain_f", 0.6)
  synth:set("_7_Release_f", s.release)
end

function init()
  synth = current.load("monosynth")
  chorus = current.load("chorus")
  flow.set(synth, chorus)
  flow.level(0.6)
  chorus:set("mix_f", 0.45)
  local saved = data.load()
  if saved then for k, v in pairs(saved) do s[k] = v end end
  apply()
end

function key(k, vel)
  local n = util.note(k)
  if vel > 0 then
    down[#down + 1] = n
    synth:note(n, vel / 127)
  else
    for i = #down, 1, -1 do if down[i] == n then table.remove(down, i) end end
    if #down > 0 then synth:note(down[#down], 0.8) else synth:note(n, 0) end
  end
  redraw()
end

function button(name, z)
  if name == "SAVE" and z == 1 then data.save(s) end
end

function enc(n, d)
  if n == 6 then s.wave = 1 - s.wave
  elseif n == 1 then s.cutoff = util.clamp(s.cutoff + d / 40, -1, 1)
  elseif n == 2 then s.res = util.clamp(s.res + d / 40, -1, 1)
  elseif n == 3 then s.env = util.clamp(s.env + d / 40, -1, 1)
  elseif n == 4 then s.release = util.clamp(s.release + d / 40, 0, 1) end
  apply()
  redraw()
end

local function bar(y, label, v, lo, hi)
  screen.level(8)
  screen.text(12, y, label)
  screen.level(3)
  screen.rect(90, y + 2, 138, 8)
  screen.level(13)
  screen.rect(90, y + 2, math.floor(138 * (v - lo) / (hi - lo) + 0.5), 8)
end

function redraw()
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 4, "mono")
  screen.font(1)
  screen.level(6)
  screen.text(12, 40, "monosynth > chorus")
  screen.level(10)
  screen.text(12, 80, s.wave == 0 and "saw" or "pulse")
  if #down > 0 then
    screen.level(15)
    screen.text_right(228, 80, "note " .. down[#down])
  end
  bar(110, "cutoff", s.cutoff, -1, 1)
  bar(135, "resonance", s.res, -1, 1)
  bar(160, "envelope", s.env, -1, 1)
  bar(185, "release", s.release, 0, 1)
  screen.update()
end
