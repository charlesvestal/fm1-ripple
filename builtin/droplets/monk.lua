-- monk: a singing voice (the monk current, MonkSynth by Jonathan Taylor, as MONK-1 has it) through the delay.
-- The keys sing, one note at a time; velocity is the level, and leaning on a key opens the vowel (or bends it,
-- ALGORITHM picks which). OCT- and OCT+ move the keys an octave.
-- Pages of knobs: EDIT sing, LFO vibrato, ENV envelope, GLO choir, FX echo. SAVE keeps the knobs.

local monk, delay
local PAGES = {
  {name = "sing", button = "EDIT", knobs = {"vowel", "head", "breath", "level"}},
  {name = "vibrato", button = "LFO", knobs = {"vibrato", "rate", "glide", "tune"}},
  {name = "envelope", button = "ENV", knobs = {"attack", "decay", "sustain", "release"}},
  {name = "choir", button = "GLO", knobs = {"voices", "detune", "spread", "depth"}},
  {name = "echo", button = "FX", echo = true, knobs = {"time", "feedback", "tone", "mix"}},
}
local ROUTES = {"vowel", "bend", "both", "both, closing"}
local v = {}                          -- the monk's knobs
local echo = {time = 0.3, feedback = 0.45, tone = 0.6, mix = 0.3}
local erange = {}
local range = {}
local page, octave = 1, 0
local held, sounding = {}, nil       -- keys held (in order), the one singing
local mouth = 0                      -- how far it opens (the level, smoothed)

function init()
  monk = current.load("monk")
  delay = current.load("delay")
  flow.set(monk, delay)
  for _, p in ipairs(monk:params()) do range[p.name] = {p.min, p.max}; v[p.name] = p.default end
  for _, p in ipairs(delay:params()) do erange[p.name] = {p.min, p.max} end
  v.voices, v.velsens = 2, 0.5
  local saved = data.load()
  if saved and saved.v then
    for k, x in pairs(saved.v) do if v[k] then v[k] = x end end
    for k, x in pairs(saved.echo or {}) do echo[k] = x end
    octave = saved.octave or 0
  end
  for k, x in pairs(v) do if k ~= "press" then monk:set(k, x) end end
  for k, x in pairs(echo) do delay:set(k, x) end
  lights()
end

function lights()
  for i, pg in ipairs(PAGES) do led.button(pg.button, i == page) end
  for k = 0, 26 do led.key(k, held[#held] == k) end
end

local function note_of(k) return util.note(k) + 12 * octave end

function key(k, vel)
  if vel > 0 then
    held[#held + 1] = k
    monk:note(note_of(k), vel / 127)
    sounding = k
  else
    for i = #held, 1, -1 do if held[i] == k then table.remove(held, i) end end
    monk:note(note_of(k), 0)
    sounding = held[#held]
    if not sounding then monk:set("press", 0) end
  end
  lights()
end

function button(name, z)
  if z == 0 then return end
  if name == "OCT-" or name == "OCT+" then
    for _, k in ipairs(held) do monk:note(note_of(k), 0) end
    held, sounding = {}, nil
    octave = util.clamp(octave + (name == "OCT+" and 1 or -1), -2, 2)
  end
  for i, pg in ipairs(PAGES) do if name == pg.button then page = i end end
  if name == "SAVE" then data.save({v = v, echo = echo, octave = octave}) end
  lights()
end

function enc(n, d)
  local pg = PAGES[page]
  if n == 6 then
    v.route = (v.route + d) % 4
    monk:set("route", v.route)
  elseif n <= 4 and pg.echo then
    local k = pg.knobs[n]
    local r = erange[k]
    echo[k] = util.clamp(echo[k] + d * (r[2] - r[1]) / 100, r[1], r[2])
    delay:set(k, echo[k])
  elseif n <= 4 then
    local k = pg.knobs[n]
    local r = range[k]
    local step = k == "voices" and 1 or (r[2] - r[1]) / 100
    v[k] = util.clamp(v[k] + d * step, r[1], r[2])
    monk:set(k, v[k])
  end
end

function frame()
  if sounding then monk:set("press", touch.pressure(sounding) / 127) end
  mouth = mouth + (math.min(1, flow.peak() * 3) - mouth) * 0.4
  redraw()
end

local function knob(x, label, val, lo, hi)
  local t = (val - lo) / (hi - lo)
  screen.level(3)
  screen.rect(x, 178, 50, 5)
  screen.level(12)
  screen.rect(x, 178, math.floor(50 * t + 0.5), 5)
  screen.font(1)
  screen.level(8)
  screen.text(x, 160, label)
  screen.level(15)
  local s = (label == "voices") and tostring(math.floor(val)) or string.format("%d%%", math.floor(t * 100 + 0.5))
  screen.text(x, 188, s)
end

function redraw()
  local pg = PAGES[page]
  screen.clear()
  screen.font(4)
  screen.level(15)
  screen.text(12, 10, "monk")
  screen.font(1)
  screen.level(8)
  screen.text_right(228, 12, "cpu " .. util.cpu() .. "%  " .. util.cores() .. " cores")
  screen.text_right(228, 26, "octave " .. (octave > 0 and "+" or "") .. octave)
  -- the face: the mouth opens with the sound, round on the open vowels
  screen.level(10)
  screen.circle(120, 86, 44, false)
  screen.circle(104, 74, 4, true)
  screen.circle(136, 74, 4, true)
  local w = 10 + math.floor(16 * (1 - math.abs(v.vowel - 0.5) * 2))
  local h = 2 + math.floor(18 * mouth)
  screen.level(sounding and 15 or 6)
  screen.rect(120 - w // 2, 104 - h // 2, w, h)
  screen.level(12)
  screen.text(12, 142, pg.name .. "   lean: " .. ROUTES[math.floor(v.route) + 1])
  for i, k in ipairs(pg.knobs) do
    if pg.echo then knob(12 + (i - 1) * 56, k, echo[k], erange[k][1], erange[k][2])
    else knob(12 + (i - 1) * 56, k, v[k], range[k][1], range[k][2]) end
  end
  screen.level(8)
  screen.text(12, 220, "keys: sing   ALGORITHM: what leaning does")
  screen.update()
end
