-- macrotest: every macro current in turn (tests/scenarios/selftest.txt): EDIT loads the next one alone (its model
-- knob, if it has one, at each of its models in turn), the keys play it.
local names, at, model, c = {}, 0, 0, nil

function init()
  for _, x in ipairs(current.list()) do
    if x.name:sub(1, 6) == "macro-" then names[#names + 1] = x.name end
  end
  print(#names .. " macro currents")
end

function button(name, z)
  if name ~= "EDIT" or z == 0 then return end
  local models = c and c:params()[1].name == "model" and c:params()[1].max or 0
  if c and model < models then
    model = model + 1
    c:set("model", model)
  else
    at, model = at % #names + 1, 0
    flow.clear()
    c = current.load(names[at])
    flow.set(c)
  end
  print(names[at] .. " " .. model)
end

function key(k, vel) if c then c:note(util.note(k), vel / 127) end end

function redraw()
  screen.clear()
  screen.text(12, 20, "macrotest")
  screen.update()
end
