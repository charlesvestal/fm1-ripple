-- life: Conway's Game of Life on a 16 x 12 grid; a cell being born plays a plucked note, its column the note in
-- the scale, its row the octave. The keys plant seeds in their column. PLAY pauses; a quiet grid seeds itself.
-- K1 the tempo, K2 how many births may sound at once, K3 how long the strings ring, K4 the space.

local pluck, plate
local W, H = 16, 12
local scale = {0, 2, 3, 5, 7, 8, 10}            -- natural minor
local grid, born = {}, {}
local s = {voices = 3, ring = 0.995, space = 0.5}
local running = true
local gen, quiet = 0, 0

local function idx(x, y) return ((y - 1) % H) * W + ((x - 1) % W) + 1 end

local function seed(cx, n)
  for _ = 1, n do
    local x, y = cx + math.random(-1, 1), math.random(1, H)
    grid[idx(x, y)] = true
    grid[idx(x + 1, y)] = true
    grid[idx(x, y + 1)] = math.random() < 0.6
  end
end

local function note_of(x, y)
  local d = x - 1
  return 48 + 12 * ((H - y) // 4) + 12 * (d // #scale) + scale[d % #scale + 1]
end

local function step()
  local nxt = {}
  born = {}
  local alive = 0
  for y = 1, H do
    for x = 1, W do
      local c = 0
      for dy = -1, 1 do for dx = -1, 1 do
        if (dx ~= 0 or dy ~= 0) and grid[idx(x + dx, y + dy)] then c = c + 1 end
      end end
      local i = idx(x, y)
      local live = grid[i] and (c == 2 or c == 3) or (not grid[i] and c == 3)
      nxt[i] = live or nil
      if live then alive = alive + 1 end
      if live and not grid[i] then born[#born + 1] = {x, y} end
    end
  end
  grid = nxt
  gen = gen + 1
  if #born == 0 then quiet = quiet + 1 else quiet = 0 end
  if alive == 0 or quiet > 6 then seed(math.random(1, W), 3); quiet = 0 end
end

local function apply()
  pluck:set("decay", s.ring)
  plate:set("mix", 0.15 + 0.45 * s.space)
end

function init()
  pluck = current.load("pluck")
  plate = current.load("plate")
  plate:set("decay", 0.85)
  local saved = data.load()
  if saved then for k, v in pairs(saved) do s[k] = v end end
  apply()
  flow.set(pluck, plate)
  seed(5, 3)
  seed(12, 3)
  clock.set_tempo(90)
  led.button("PLAY", running)
  clock.run(function()
    while true do
      clock.sync(1 / 2)
      if running then
        step()
        -- a few of the births sound (a crowd of them would be noise), picked at random
        for i = 1, math.min(s.voices, #born) do
          local j = math.random(i, #born)
          born[i], born[j] = born[j], born[i]
          pluck:note(note_of(born[i][1], born[i][2]), 0.35 + 0.3 * math.random())
        end
        redraw()
      end
    end
  end)
end

function key(k, vel)
  if vel > 0 then
    seed(k * W // 27 + 1, 2)
    redraw()
  end
end

function button(name, z)
  if z == 0 then return end
  if name == "PLAY" then running = not running; led.button("PLAY", running)
  elseif name == "SAVE" then data.save(s) end
end

function enc(n, d)
  if n == 1 then clock.set_tempo(clock.tempo + d)
  elseif n == 2 then s.voices = util.clamp(s.voices + d, 1, 6)
  elseif n == 3 then s.ring = util.clamp(s.ring + d * 0.0005, 0.98, 0.9995)
  elseif n == 4 then s.space = util.clamp(s.space + d * 0.02, 0, 1) end
  apply()
end

function redraw()
  screen.clear()
  local cw = 14
  for y = 1, H do
    for x = 1, W do
      if grid[idx(x, y)] then
        screen.level(9)
        screen.rect(8 + (x - 1) * cw, 30 + (y - 1) * cw, cw - 2, cw - 2)
      end
    end
  end
  for _, b in ipairs(born) do
    screen.level(15)
    screen.rect(8 + (b[1] - 1) * cw, 30 + (b[2] - 1) * cw, cw - 2, cw - 2)
  end
  screen.font(4)
  screen.level(15)
  screen.text(12, 2, "life")
  screen.font(1)
  screen.level(8)
  screen.text_right(228, 6, "generation " .. gen)
  screen.text(12, 204, running and "" or "paused")
  screen.text(12, 224, math.floor(clock.tempo) .. " bpm   " .. s.voices .. " at once")
  screen.update()
end
