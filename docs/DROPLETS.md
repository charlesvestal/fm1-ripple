# Writing droplets

A droplet is a Lua file in the `droplets` folder on Ripple's disk. It decides what the keys, knobs and buttons do,
what the screen shows and when notes play. The sound comes from currents, which the droplet loads and wires
together.

To add a droplet, put Ripple in disk mode, copy the `.lua` file into `droplets`, then eject the drive. The droplet
appears in the list. Hold HOME for a second to leave a droplet.

Ripple also has droplets and currents built in. They aren't on the disk, but your droplets can still use the
built-in currents. If a file on the disk has the same name as a built-in one, Ripple uses the file instead. The
built-in droplets are in `builtin/droplets` in Ripple's repository. To start from one, copy it onto the disk.

Ripple runs Lua 5.4 with 32-bit integers and 32-bit floats. There is no `io`, `os` or `debug` library. `require`
finds modules in the `lib` and `droplets` folders, on the disk or built in.

## Trying one in the emulator

The emulator on Ripple's site has a panel under the FM-1 called **Write your own**. Write a droplet there, or drop a
`.lua` file on it, and press Run to put it on the emulator's disk and start it. Anything the droplet prints, and the
error it stops on, show below the panel. Your browser keeps what you write. When it works, copy it to the FM-1 in
disk mode.

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

Define any of these functions and Ripple calls them. Leave out the ones you don't need.

| Function | When |
|---|---|
| `init()` | Ripple calls it once, when the droplet starts. |
| `redraw()` | Ripple calls it once after `init`. After that, call it yourself whenever the screen should change. |
| `key(k, vel)` | A key was pressed, with `vel` from 1 to 127, or released, with `vel` 0. `k` runs from 0 for the lowest key (F3) up to 26. |
| `button(name, z)` | A button was pressed (`z` is 1) or released (`z` is 0). `name` is the button's name as printed on the FM-1: `"PLAY"`, `"REC"`, `"OCT-"`, `"OCT+"`, `"FX"`, `"SEL"`, `"ENV"`, `"LFO"`, `"EDIT"`, `"GLO"`, `"HOME"`, `"SAVE"`, `"ARP"` or `"SEQ"`. |
| `enc(n, d)` | A knob turned by `d` steps. `n` is 1 to 4 for K1 to K4, 5 for SELECT, 6 for ALGORITHM and 7 for PRESET. |
| `midi_in(b0, b1, b2, port)` | A MIDI message arrived. `port` is `"usb"` for USB or `"trs"` for the MIDI jack. MIDI clock (`0xF8`), start and stop arrive here too. |
| `frame()` | Ripple calls it about 30 times a second. Use it for animation. |
| `cleanup()` | Ripple calls it when the droplet stops. |

Your droplet gets HOME presses too, but holding HOME for a second always takes you back to the list.

## Currents

Use `current.load(name)` to load a current. It loads `currents/NAME.cur` from the disk, or the built-in current with
that name, and returns it.

| Call | What it does |
|---|---|
| `c:set(param, value)` | Sets a parameter. Name it (`"cutoff"`) or give its number (1 for the first). |
| `c:note(n, vel)` | Plays MIDI note `n` at a velocity from 0 to 1. Velocity 0 releases the note. This works only for currents that play notes. |
| `c:params()` | Returns the current's parameters as a list of tables, each with `name`, `min`, `max` and `default`. |
| `c.name`, `c.voices` | These are the current's name and how many notes it plays at once (0 for an effect). |
| `current.list()` | Returns every current there is, on the disk and built in, without loading any of them. Each one is a table with `name`, `kind` (`"voice"`, `"effect"` or `"sound"`), `voices` (the notes it plays at once) and `kb`, the room it would take. |
| `current.fits(name)` | Tells you whether that current would load now. |
| `current.room()` | Returns the KB left for currents. |
| `flow.clear()` | Takes every current out so the droplet can load others. The currents it had stop working, and using one of them is an error. The sound stops for a moment. |

Use `flow.set(a, b, ...)` to set the order the currents run in. A current that makes sound adds it to the mix, and
an effect works on everything before it. So `flow.set(drums, bass, delay)` puts the delay over both. Use
`flow.level(v)` to set the droplet's volume, from 0 to 1 (0.5 by default). `flow.peak()` returns the loudest sample
of the last block.

These currents are built in:

| Current | Parameters |
|---|---|
| `voice` | Six voices, each two saws through a lowpass filter. Its parameters are `cutoff`, `res`, `detune`, `attack`, `release` and `envamt`. |
| `delay` | A delay of up to 0.36 seconds, with `time`, `feedback`, `tone` and `mix`. |
| `monk` | A singing voice (MonkSynth) that sings one note at a time. Its parameters are `vowel`, `head`, `breath`, `level`, `vibrato`, `rate`, `glide`, `tune`, `attack`, `decay`, `sustain`, `release`, `voices` (unison, 1 to 4), `detune`, `spread` and `velsens`. Set `press` to a key's pressure, from 0 to 1, to open the vowel or bend the pitch. `route` (0 to 3) picks which, and `depth` sets how far. |
| `macro-va`, `-vcf`, `-pd`, `-chip`, `-shape`, `-fm`, `-grain`, `-additive`, `-strings`, `-swarm`, `-noise`, `-particle`, `-string`, `-modal`, `-kick`, `-snare`, `-hat` | Macro-oscillator engines from Emilie Gillet's open-source Plaits code, one engine each: virtual analog, VA through a filter, phase distortion, chiptune, waveshaping, FM, grain, additive, string machine, swarm, noise, particle, string, modal resonator, bass drum, snare and hi-hat. Each plays six notes at once, except particle and string, which play two. Their parameters are `harmonics`, `timbre` and `morph` (the engine's three controls), `attack`, `release` and `level`. The strings, the modal resonator and the drums ring out by themselves. |
| `macro-wave`, `macro-sixop`, `macro-speech` | These aren't built in, because there's no room for them. Each release includes them as files to copy onto the disk. `macro-wave` plays wavetables, wave terrains and chords, and `model` picks which. `macro-sixop` is six-operator FM with three banks of DX7-compatible patches. `model` picks the bank and `harmonics` the patch. `macro-speech` speaks. |
| `sophie` | Sixteen pads of metallic FM percussion (Sophie) on notes 36 to 51. Set `pad` to a pad's number (1 to 16), and the parameters you set after it change that pad. Set `pad` to 0 to change every pad. The pad parameters are `model`, `tune`, `decay`, `level`, `color`, `metal`, `fdbk`, `sweep`, `cutoff`, `reso`, `filter`, `drive`, `time`, `ring`, `mix`, `tone`, `crush`, `mdecay`, `fbmode`, `tail` and `pan`, with the same values as on SPH-16. `voices` (1 to 12) sets how many hits sound at once. |
| `drums` | Kick (note 36), snare (38), closed hat (42) and open hat (46), with `tune`, `decay`, `snap` and `level`. |
| `fm` | Six voices of two-operator FM that start bright and settle. Its parameters are `ratio`, `index`, `fall`, `floor`, `feedback`, `attack` and `release`. |
| `pluck` | Six plucked strings, from 56 Hz up, with `damp`, `decay` and `bright`. |
| `plate` | A small reverb with `size`, `decay`, `damp` and `mix`. |

All of a droplet's currents share 132 KB. The plate takes 38 KB of that and the delay 16 KB, so a droplet can have
both, with a voice or two (or two delays).

To write your own currents, see [the SDK](../sdk/README.md).

## MIDI effects

Use `midifx.new()` to make a chain of MIDI effects. A droplet can have two chains at most. The notes you send into
a chain go through its effects, and what comes out plays a current. The effects follow the RS7000's Play FX, as
e16-launcher has them: harmonize, note offset, scale, velocity, chance, swing, clock shift, grid groove, humanize,
gate, an arpeggiator, a MIDI delay with feedback, and a loop (beat repeat and remix) with beat stretch. The chain
keeps time at its own tempo, or follows MIDI clock when you pass the clock to it.

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
| `fx:note(n, vel, ch)` | Sends a note into the chain, at a velocity from 0 to 1. Velocity 0 lets the note go. Give `ch` to send it on a MIDI channel other than 1. |
| `fx:midi(b0, b1, b2)` | Sends any MIDI message into the chain, such as a keyboard's notes or the clock to follow. |
| `fx:connect(c)` | Plays current `c` with what comes out. Pass `nil` to play nothing. |
| `fx:midi_out(on)` | Also sends what comes out over USB. |
| `fx:set(name, v)`, `fx:get(name)` | Sets or reads a setting. Give `fx:set` the value as a number, as `true` or `false`, or as it is shown (`"1/16"`, `"up"`). `fx:get` returns a number. |
| `fx:text(name, v)` | Returns a setting as it is shown. Give `v` to see how that value would be shown instead. |
| `fx:loop(on)` | Holds the loop. While it's held, what you just played repeats, as `loop` and `stretch` set it. |
| `fx:panic()` | Ends every note the chain is playing. |
| `fx:params()` | Returns the settings as a list of tables, each with `name`, `min`, `max` and `default`. |
| `fx:tempo()` | Returns the tempo the chain keeps, in BPM. When it follows MIDI clock, this is the clock's tempo. |

These are the settings. Most effects have an on/off switch whose name ends in `_on`, such as `harm_on`, `arp_on` or
`delay_on`.

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

The screen is 240 by 240 pixels. You draw off screen, and `screen.update()` shows what you drew. If you don't call
`screen.clear()` first, what you draw adds to what's already there, as on paper. Ripple keeps up to 1536 drawing
calls for each screen.

| Call | What it does |
|---|---|
| `screen.clear()` | Fills the screen with level 0. |
| `screen.level(n)` | Draws in level `n`, from 0 (the background) to 15 (the brightest). |
| `screen.color(r, g, b)` | Draws in any color instead of a level. |
| `screen.palette(n, r, g, b)` | Changes the color of level `n`. |
| `screen.font(n)` | Sets the text size, from 1 (small) to 5 (large). |
| `screen.rect(x, y, w, h)`, `screen.frame(x, y, w, h)` | Draws a filled rectangle, or just its outline. |
| `screen.line(x0, y0, x1, y1)`, `screen.pixel(x, y)` | Draws a line, or a single pixel. |
| `screen.circle(x, y, r, fill)` | Draws a circle, filled when `fill` is true. |
| `screen.text(x, y, s)` | Draws text with its top left corner at `x`, `y`, and returns its width. |
| `screen.text_center(x, y, s)`, `screen.text_right(x, y, s)` | Draws text centered on `x`, or ending at `x`. |
| `screen.text_width(s)` | Returns the width the text would take. |
| `screen.update()` | Shows what you drew. |

## Clocks

A clock is a coroutine. It's a function that runs alongside everything else and can wait whenever it wants to.

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
| `clock.run(fn, ...)` | Starts `fn` as a clock and returns its id. |
| `clock.sleep(s)` | Waits `s` seconds. Call it inside a clock. |
| `clock.sync(beats)` | Waits for the next multiple of `beats` at the tempo. Call it inside a clock. |
| `clock.cancel(id)` | Stops a clock. |
| `clock.set_tempo(bpm)`, `clock.tempo` | Sets the tempo, from 20 to 300, and `clock.tempo` reads it. |
| `clock.beats()` | Returns the beats since Ripple started. |

## Saving

Use `data.save(t)` to write table `t` to the droplet's own file on the disk. The file is `data/NAME.DAT`, after the
droplet's name. `data.load()` reads it back, or returns `nil` when there's no file yet. Numbers, strings, booleans
and tables of them are kept, up to 8 KB. The sound pauses for a moment while the flash is written, so save when the
player asks (SAVE is the obvious button), not on every knob turn.

```lua
function init()
  local saved = data.load()
  if saved then tempo = saved.tempo end
end

function button(name, z)
  if name == "SAVE" and z == 1 then data.save({tempo = tempo}) end
end
```

In disk mode, the files are in the `data` folder. Delete one to give its droplet its defaults back.

## Lights, MIDI and helpers

| Call | What it does |
|---|---|
| `led.key(k, on)` | Lights key `k` when `on` is true, and turns it off when it's false. |
| `led.button(name, on)` | Lights a button, or turns it off, by its name. |
| `midi.send(b0, b1, b2)` | Sends a MIDI message over USB. |
| `util.note(k)` | Returns the MIDI note of key `k`, which is 53 (F3) plus `k`. |
| `util.ms()` | Returns the milliseconds since Ripple started. |
| `util.clamp(x, a, b)`, `util.round(x)`, `util.linlin(x, a, b, c, d)` | These are small math helpers. They keep `x` between `a` and `b`, round `x` to the nearest whole number, and map `x` from the range `a` to `b` onto `c` to `d`. |
| `touch.pressure(k)` | Returns how hard held key `k` is pressed beyond where it rests, from 0 to 127. The top row (C#5 to G5) has no reading, so it always returns 0 there. |
| `util.cpu()`, `util.cores()` | `util.cpu()` returns how busy the sound keeps the first core, in percent. `util.cores()` returns how many cores the sound runs on, 2 or 1. |
| `print(...)` | Prints its arguments. If the droplet stops on an error, the last lines it printed show on the error screen. |

## When something goes wrong

An error stops the droplet. A red screen shows the message, the line it came from and the last lines the droplet
printed. Press HOME to go back to the list, fix the file in disk mode, and try again.
