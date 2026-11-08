-- chip: an arpeggiator on a chiptune oscillator, crushed and widened. Hold keys and it plays them, up an octave and
-- back. Currents: logue-chiptune, nts-vca, nts-bitcrush, nts-chorus (Pd patches by boochow).
-- ALGORITHM the wave (pulse, triangle, noise), K1 how much it crushes, K2 its rate, K3 the gate length, K4 the tempo.

local osc, vca, crush, chorus
local held = {}
local s = {wave = 0, crush = 0.3, rate = 4, gate = 0.5}
local step, now = 0, nil
local waves = {"pulse", "triangle", "noise"}

local function order()
  local t = {}
  for n in pairs(held) do t[#t + 1] = n end
  table.sort(t)
  local up = {}
  for _, n in ipairs(t) do up[#up + 1] = n end
  for _, n in ipairs(t) do up[#up + 1] = n + 12 end
  return up
end

local function apply()
  osc:set("waveform", s.wave)
  crush:set("depth_f", s.crush)
  crush:set("time", s.rate)
end

function init()
  osc = current.load("logue-chiptune")
  vca = current.load("nts-vca")
  crush = current.load("nts-bitcrush")
  chorus = current.load("nts-chorus")
  flow.set(osc, vca, crush, chorus)
  flow.level(0.3)
  vca:set("depth_f", 0)                         -- the oscillator never stops: the VCA is its gate
  chorus:set("mix_f", 0.5)
  clock.set_tempo(132)
  apply()
  clock.run(function()
    while true do
      clock.sync(1 / 4)
      local seq = order()
      if #seq > 0 then
        now = seq[step % #seq + 1]
        step = step + 1
        osc:note(now, 1)
        vca:set("depth_f", 1)
        clock.sleep(60 / clock.tempo / 4 * s.gate)
        vca:set("depth_f", 0)
      else
        now, step = nil, 0
      end
    end
  end)
end

function frame() redraw() end

function key(k, vel)
  if vel > 0 then held[util.note(k)] = true else held[util.note(k)] = nil end
end

function enc(n, d)
  if n == 6 then s.wave = (s.wave + d) % 3
  elseif n == 1 then s.crush = util.clamp(s.crush + d / 20, 0, 1)
  elseif n == 2 then s.rate = util.clamp(s.rate + d, 1, 8)
  elseif n == 3 then s.gate = util.clamp(s.gate + d / 20, 0.1, 1)
  elseif n == 4 then clock.set_tempo(clock.tempo + d) end
  apply()
end

function redraw()
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 4, "chip")
  screen.font(1)
  screen.level(6)
  screen.text(12, 40, "chiptune > vca > crush > chorus")
  -- the arpeggio: a block a note, the one playing lit
  local seq = order()
  local w = #seq > 0 and math.min(28, 216 // #seq) or 0
  for i, n in ipairs(seq) do
    screen.level(n == now and 15 or 5)
    local h = 20 + (n % 24) * 3
    screen.rect(12 + (i - 1) * w, 170 - h, w - 3, h)
  end
  if #seq == 0 then
    screen.level(6)
    screen.text_center(120, 110, "hold some keys")
  end
  screen.level(10)
  screen.text(12, 190, waves[s.wave + 1])
  screen.level(8)
  screen.text(12, 210, "crush " .. math.floor(s.crush * 100 + 0.5) .. "%  rate " .. s.rate)
  screen.text_right(228, 210, math.floor(clock.tempo) .. " bpm")
  screen.update()
end
