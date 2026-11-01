# Writing droplets

A droplet is a Lua file in the `droplets` folder on Ripple's disk. It decides what the keys, knobs and buttons do,
what the screen shows and when notes play. The sound comes from currents, which the droplet loads and wires
together.

To add a droplet, put Ripple in disk mode, copy the `.lua` file into `droplets`, then eject the drive. It appears in
the list. Hold HOME for a second to leave a droplet.

Ripple also has droplets and currents built in. They aren't on the disk, but droplets on the disk can use the
built-in currents, and a file on the disk with the same name as a built-in one is used instead of it. The built-in
droplets are in `builtin/droplets` in Ripple's repository: copy one onto the disk to start from it.

Ripple runs Lua 5.4 with 32-bit integers and 32-bit floats. There is no `io`, `os` or `debug` library. `require`
finds modules in `lib` and `droplets`, on the disk or built in.

## A small droplet

```lua
-- tone: the keys play a voice
local voice

function init()
  voice = current.load("voice")
  flow.set(voice)
end

function key(k, vel)
  voice:note(util.note(k), vel / 127)
end

function redraw()
  screen.clear()
  screen.level(15)
  screen.text(12, 20, "tone")
  screen.update()
end
```

## What Ripple calls

Define any of these and Ripple calls them. Leave out the ones you don't need.

| Function | When |
|---|---|
| `init()` | Once, when the droplet starts |
| `redraw()` | Once after `init`; call it yourself whenever the screen should change |
| `key(k, vel)` | A key is pressed (`vel` 1 to 127) or released (`vel` 0). `k` is 0 for the lowest key (F3) to 26 |
| `button(name, z)` | A button is pressed (`z` 1) or released (`z` 0). Names as printed: `"PLAY"`, `"REC"`, `"OCT-"`, `"OCT+"`, `"FX"`, `"SEL"`, `"ENV"`, `"LFO"`, `"EDIT"`, `"GLO"`, `"HOME"`, `"SAVE"`, `"ARP"`, `"SEQ"` |
| `enc(n, d)` | A knob turns by `d` steps. `n` is 1 to 4 for K1 to K4, 5 for SELECT, 6 for ALGORITHM, 7 for PRESET |
| `midi_in(b0, b1, b2, port)` | A MIDI message arrives, `port` saying where from: `"usb"` or `"trs"` (the MIDI jack). The clock (`0xF8`), start and stop come this way too |
| `frame()` | About 30 times a second, for animation |
| `cleanup()` | When the droplet stops |

HOME is passed to the droplet too, but holding it for a second always goes back to the list.

## Currents

`current.load(name)` loads `currents/NAME.cur` from the disk, or the built-in current of that name, and returns the
current.

| Call | What it does |
|---|---|
| `c:set(param, value)` | Sets a parameter, by name (`"cutoff"`) or number (1 for the first) |
| `c:note(n, vel)` | Plays MIDI note `n` at velocity 0 to 1; velocity 0 releases it. Only for currents that play notes |
| `c:params()` | The parameters: a list of tables with `name`, `min`, `max` and `default` |
| `c.name`, `c.voices` | Its name, and how many notes it plays at once (0 for an effect) |
| `current.list()` | Every current there is, on the disk and built in, without loading them: a list of tables with `name`, `kind` (`"voice"`, `"effect"` or `"sound"`) and `kb` (what it would take) |
| `current.fits(name)` | Whether that current would load now |
| `current.room()` | KB left for currents |
| `flow.clear()` | Every current out: the droplet loads others. The ones it had stop working (using one is an error), and the sound stops for a moment |

`flow.set(a, b, ...)` sets the order the currents run in. A current that makes sound adds it to the mix; an effect
works on everything before it. So `flow.set(drums, bass, delay)` puts the delay over both. `flow.level(v)` sets
the droplet's volume (0 to 1, default 0.5), and `flow.peak()` gives the last block's loudest sample.

The built-in currents:

| Current | Parameters |
|---|---|
| `voice` | Six voices of two saws through a lowpass filter: `cutoff`, `res`, `detune`, `attack`, `release`, `envamt` |
| `delay` | A delay of up to 0.36 seconds: `time`, `feedback`, `tone`, `mix` |
| `monk` | A singing voice (MonkSynth), one note at a time: `vowel`, `head`, `breath`, `level`, `vibrato`, `rate`, `glide`, `tune`, `attack`, `decay`, `sustain`, `release`, `voices` (unison, 1 to 4), `detune`, `spread`; `press` (a key's pressure, 0 to 1) opens the vowel or bends, as `route` (0 to 3) and `depth` say; `velsens` |
| `sophie` | Sixteen pads of metallic FM percussion (Sophie), notes 36 to 51. `pad` (1 to 16; 0, every pad) picks the pad the parameters after it change: `model`, `tune`, `decay`, `level`, `color`, `metal`, `fdbk`, `sweep`, `cutoff`, `reso`, `filter`, `drive`, `time`, `ring`, `mix`, `tone`, `crush`, `mdecay`, `fbmode`, `tail`, `pan`, in SPH-16's numbers; `voices` (1 to 12) |
| `drums` | Kick (note 36), snare (38), closed hat (42), open hat (46): `tune`, `decay`, `snap`, `level` |
| `fm` | Six voices of two-operator FM, bright at the start and settling: `ratio`, `index`, `fall`, `floor`, `feedback`, `attack`, `release` |
| `pluck` | Six plucked strings, from 56 Hz up: `damp`, `decay`, `bright` |
| `plate` | A small reverb: `size`, `decay`, `damp`, `mix` |

All of a droplet's currents share 132 KB. The plate takes 38 KB of it and the delay 16 KB, so a droplet can have
both, with a voice or two (or two delays).

To write your own, see [the SDK](../sdk/README.md).

## MIDI effects

`midifx.new()` makes a chain of MIDI effects (two at most): the notes a droplet plays go through it, and what comes
out plays a current. It is the RS7000's Play FX, as e16-launcher has them: harmonize, note offset, scale, velocity,
chance, swing, clock shift, grid groove, humanize, gate, an arpeggiator, a MIDI delay with feedback, and a loop
(beat repeat and remix) with beat stretch. It keeps time by itself, at its own tempo, or follows MIDI clock passed
to it.

```lua
local fx, voice
function init()
  voice = current.load("voice")
  flow.set(voice)
  fx = midifx.new()
  fx:connect(voice)
  fx:set("harm_on", true)
  fx:set("harm1", 7)                 -- a fifth above every note
  fx:set("arp_on", true)
  fx:set("arp_rate", "1/16")
end
function key(k, vel) fx:note(util.note(k), vel / 127) end
function midi_in(b0, b1, b2) fx:midi(b0, b1, b2) end
```

| Call | What it does |
|---|---|
| `fx:note(n, vel)` | A note in (velocity 0 to 1; 0 lets it go) |
| `fx:midi(b0, b1, b2)` | Any message in: a keyboard's notes, the clock to follow |
| `fx:connect(c)` | What comes out plays current `c` (`nil`: nothing) |
| `fx:midi_out(on)` | And goes out over USB |
| `fx:set(name, v)`, `fx:get(name)` | A setting: a number, `true`/`false`, or as it is shown (`"1/16"`, `"up"`) |
| `fx:text(name)` | A setting as it is shown |
| `fx:loop(on)` | The loop held: what was just played repeats, as `loop` and `stretch` say |
| `fx:panic()` | Every note it plays ends |
| `fx:params()` | The settings: a list of tables with `name`, `min`, `max` and `default` |
| `fx:tempo()` | The tempo it keeps, BPM (MIDI clock's when it follows it) |

The settings (each effect also has an `_on` switch: `harm_on`, `arp_on`, `delay_on`, ...):

| Effect | Settings |
|---|---|
| Harmonize | `harm_on`, `unison` (1 to 8 copies), `octaver` (-10 to 10), `harm1`, `harm2` (semitones) |
| Note | `note_on`, `note` (semitones); `scale_on`, `scale` (13 scales), `root` |
| Velocity | `vel_on`, `vel`, `vel_scale`, `vel_comp`, `vel_random`; `chance` (0 to 100 %) |
| Timing | `swing_on`, `swing`, `swing_grid`; `shift_on`, `shift` (clocks, 480 a beat); `humanize_on`, `humanize` (ms); `gate_on`, `gate` (%); `groove_on`, `groove` (six grooves) |
| Arpeggiator | `arp_on`, `arp_mode` (up, down, up/down, random, played), `arp_rate`, `arp_oct`, `arp_gate`, `arp_latch` |
| MIDI delay | `delay_on`, `delay_time` (clocks), `delay_level`, `repeats`, `fb_vel`, `fb_note`, `fb_gate`, `fb_clock` |
| Loop | `loop` (repeat 1/2 to 1/16 of a beat, or a remix of the last bar), `stretch` (25 to 400 %) |
| Tempo | `tempo` (30 to 300) |

## Screen

The screen is 240 by 240 pixels. Drawing happens off screen; `screen.update()` shows it. What is drawn without
`screen.clear()` first adds to what is there, as on paper (Ripple keeps up to 1536 things drawn a screen).

| Call | What it does |
|---|---|
| `screen.clear()` | Fills the screen with level 0 |
| `screen.level(n)` | Draws in level `n`, 0 (the background) to 15 (the brightest) |
| `screen.color(r, g, b)` | Draws in any colour instead |
| `screen.palette(n, r, g, b)` | Changes level `n`'s colour |
| `screen.font(n)` | Text size, 1 (small) to 5 (large) |
| `screen.rect(x, y, w, h)`, `screen.frame(x, y, w, h)` | A filled rectangle, an outline |
| `screen.line(x0, y0, x1, y1)`, `screen.pixel(x, y)` | A line, a pixel |
| `screen.circle(x, y, r, fill)` | A circle, filled when `fill` is true |
| `screen.text(x, y, s)` | Text with its top left at `x`, `y`; returns its width |
| `screen.text_center(x, y, s)`, `screen.text_right(x, y, s)` | Text centred on `x`, or ending at `x` |
| `screen.text_width(s)` | The width text would take |
| `screen.update()` | Shows what was drawn |

## Clocks

Clocks are coroutines: a function that runs alongside everything else and waits when it wants to.

```lua
clock.run(function()
  while true do
    clock.sync(1 / 4)          -- wait for the next sixteenth note
    drums:note(36, 1)
  end
end)
```

| Call | What it does |
|---|---|
| `clock.run(fn, ...)` | Starts `fn` as a clock; returns its id |
| `clock.sleep(s)` | Inside a clock: waits `s` seconds |
| `clock.sync(beats)` | Inside a clock: waits for the next multiple of `beats` at the tempo |
| `clock.cancel(id)` | Stops a clock |
| `clock.set_tempo(bpm)`, `clock.tempo` | The tempo, 20 to 300 |
| `clock.beats()` | Beats since Ripple started |

## Saving

`data.save(t)` writes table `t` to the droplet's own file on the disk (`data/NAME.DAT`, named after the droplet), and
`data.load()` reads it back, or gives `nil` when there is none. Numbers, strings, booleans and tables of them are
kept, up to 8 KB. The sound pauses for a moment while the flash is written, so save when asked (SAVE is the obvious
button), not on every knob turn.

```lua
function init()
  local saved = data.load()
  if saved then tempo = saved.tempo end
end

function button(name, z)
  if name == "SAVE" and z == 1 then data.save({tempo = tempo}) end
end
```

In disk mode the files are in `data`: delete one to give its droplet its defaults back.

## Lights, MIDI and helpers

| Call | What it does |
|---|---|
| `led.key(k, on)` | Lights key `k` |
| `led.button(name, on)` | Lights a button |
| `midi.send(b0, b1, b2)` | Sends a MIDI message over USB |
| `util.note(k)` | The MIDI note of key `k`: 53 (F3) + `k` |
| `util.ms()` | Milliseconds since Ripple started |
| `util.clamp(x, a, b)`, `util.round(x)`, `util.linlin(x, a, b, c, d)` | Small maths helpers |
| `touch.pressure(k)` | How hard held key `k` is pressed, beyond where it rests: 0 to 127 (0 for the top row, C#5 to G5, which has no reading) |
| `util.cpu()`, `util.cores()` | How busy the sound is (% of the first core), and the cores it is on (2, or 1) |
| `print(...)` | Shown on the error screen if the droplet stops |

## When something goes wrong

An error stops the droplet and shows a red screen with the message, the line it came from, and the last lines the
droplet printed. Press HOME to go back to the list, fix the file in disk mode, and try again.
