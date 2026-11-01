-- fxtest: the MIDI effects, their notes out over USB (tests/scenarios/selftest.txt checks them). Each button sets one
-- effect up from nothing: EDIT a chord (+7), ENV the arp (up, 1/16), LFO the echo (two repeats an 8th apart), FX
-- note offset (+12), GLO the scale (C major), SEL the loop as repeat 1/2, ARP as remix reversed. SEQ held: the loop.
local fx, voice
local ONS = {"harm_on", "arp_on", "delay_on", "note_on", "scale_on", "swing_on", "gate_on", "humanize_on", "vel_on",
             "shift_on", "groove_on"}

local function off()
  fx:panic()
  for _, k in ipairs(ONS) do fx:set(k, false) end
end

function init()
  voice = current.load("voice")
  flow.set(voice)
  fx = midifx.new()
  fx:connect(voice)
  fx:midi_out(true)
  fx:set("tempo", 120)
  off()
end

function key(k, vel) fx:note(util.note(k), vel / 127) end
function midi_in(b0, b1, b2) fx:midi(b0, b1, b2) end

function button(name, z)
  if name == "SEQ" then fx:loop(z == 1) return end
  if z == 0 then return end
  off()
  if name == "EDIT" then fx:set("harm_on", true); fx:set("harm1", 7); fx:set("harm2", 0)
  elseif name == "ENV" then fx:set("arp_on", true); fx:set("arp_mode", "up"); fx:set("arp_rate", "1/16")
  elseif name == "LFO" then
    fx:set("delay_on", true); fx:set("delay_time", 240); fx:set("repeats", 2); fx:set("delay_level", 64)
    fx:set("fb_vel", -10)
  elseif name == "FX" then fx:set("note_on", true); fx:set("note", 12)
  elseif name == "GLO" then fx:set("scale_on", true); fx:set("scale", "major"); fx:set("root", "C")
  elseif name == "SEL" then fx:set("loop", "rpt 1/2")
  elseif name == "ARP" then fx:set("loop", "rmx rev") end
  print(name .. " set")
end

function redraw()
  screen.clear()
  screen.level(15)
  screen.text(12, 20, "fxtest")
  screen.update()
end
