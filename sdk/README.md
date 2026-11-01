# Writing currents

A current is a piece of sound: a voice, a drum kit, a filter or a delay. Droplets load currents from the
`currents` folder on Ripple's disk. You write a current in Faust or in C, build it into a `.cur` file on the
computer, and copy that file onto the disk in disk mode. Nothing on the FM-1 needs updating. A current on the disk
with the same name as a built-in one (`voice`, `delay`, `drums`, `fm`, `monk`, `pluck`, `plate`, `sophie`) is used
instead of it.

The SDK is MIT-licensed, so currents may use any licence.

## Build

From Ripple's repository:

```sh
sdk/tools/currents.py mysound.dsp --out build/      # build/mysound.cur, for the FM-1
sdk/tools/currents.py mysound.dsp --host build/     # build/mysound.so, for the simulator
```

Copy `mysound.cur` into `currents` on Ripple's disk, in disk mode, and a droplet can load it with
`current.load("mysound")`.

Building for the FM-1 needs the JieLi toolchain (`JIELI_TOOLCHAIN`, default `~/.jieli/toolchain`) and, on a Mac,
podman or Docker, as fm1-base does. Faust currents need `faust` on the path.

## In Faust

Write the sound as usual. Its sliders become the current's parameters, with their names, ranges and defaults.

A current with sliders called `freq`, `gain` and `gate` and no inputs is a voice: droplets play it with notes, which
set those three. It plays six notes at once, or as many as `declare voices "N";` says. A current with inputs is
an effect and works on the sound before it in the flow. Anything else just makes sound.

```faust
declare name "pluck";
declare voices "4";
import("stdfaust.lib");

freq = hslider("freq", 440, 20, 8000, 0.01);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");
damp = hslider("damp", 0.5, 0, 1, 0.01);

process = os.sawtooth(freq) : fi.lowpass(1, 400 + 8000 * (1 - damp))
        * en.ar(0.002, 0.4, gate) * gain <: _, _;
```

Faust code is compiled to C, then built like a C current. A few things are different from Faust on a computer:

- There is no `double`: Faust is run with `-single`.
- The maths functions are fast approximations (`fastmath.h`), close enough for sound, not for science.
- Memory is limited. A droplet's currents share 132 KB: their code and data in 84 KB, their state in 48 KB more
  (then in what is left of the 84). Long delay lines are the usual problem: 16,000 float samples is 64 KB (the
  built-in `delay` is in C to keep its line at half the rate in 16 bits: 16 KB). Faust's table oscillators (`os.osc`) keep a
  65,536-sample table, too big here; use `os.sawtooth`, `os.square`, `os.triangle` or a sine from `ma.PI`.

## In C

A C current fills in an `rc_desc_t` (`include/ripple_current.h`) and exports it with `RC_EXPORT`. The firmware hands
it a block of zeroed state (`state_size` bytes) and calls:

- `init(state, sr)` once, after loading,
- `set(state, param, value)` when a droplet sets a parameter,
- `note(state, note, velocity)` for a voice (velocity 0 releases), and
- `process(state, left, right, n)` for each block of `n` frames.

A current that makes sound adds to `left` and `right`; an effect replaces them with what it makes of them. It may
have up to 64 parameters.

The FM-1 has two cores. A current that makes sound can let the second take half its work: set `parts` to 2 and give
`process_part(state, left, right, n, part)`, which adds part 0 or part 1 (usually the even and the odd voices) into
`left` and `right`. The two parts run at the same time, so each touches only its own voices and scratch, and reads
what `set` and `note` write (they run before the block, never during it). Work that must happen once a block before
either part (a knob's slew) goes in `begin(state, n)`. Ripple runs the parts on the two cores, and `process` when it
has one. A Faust voice is split this way by itself; `currents/sophie.c` and `currents/monk.c` show it in C.
`currents/drums.c` is a complete example.

A current has no C library and no calls into the firmware. Use `fastmath.h` for maths, keep everything in the state,
and use `float`, never `double`: the FM-1's FPU is single precision, and the build refuses a current with a double
in it.

## How a current loads

The `.cur` file is the current's code and data, linked at address 0, with a list of the addresses inside it. Its
header also says what the current is (it makes sound or processes it, its voices, its state's size), so a droplet
can list the currents without loading them (`current.list`). The firmware copies it into RAM, adds its own address
to each one, checks the descriptor and calls `init`. The current's
code then runs in the audio interrupt.
