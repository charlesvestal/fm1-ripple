# Writing currents

A current is a piece of sound: a voice, a drum kit, a filter or a delay. Droplets load currents from the
`currents` folder on Ripple's disk. You write a current in Faust or in C, build it into a `.cur` file on the
computer, and copy that file onto the disk in disk mode. Nothing on the FM-1 needs updating. A current on the disk
with the same name as a built-in one (`voice`, `delay`, `drums`, `fm`, `pluck`, `plate`) is used instead of it.

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
- Memory is limited. Everything a current holds comes from an 84 KB arena that all of a droplet's currents share.
  Long delay lines are the usual problem: 16,000 samples is 64 KB. Faust's table oscillators (`os.osc`) keep a
  65,536-sample table, too big here; use `os.sawtooth`, `os.square`, `os.triangle` or a sine from `ma.PI`.

## In C

A C current fills in an `rc_desc_t` (`include/ripple_current.h`) and exports it with `RC_EXPORT`. The firmware hands
it a block of zeroed state (`state_size` bytes) and calls:

- `init(state, sr)` once, after loading,
- `set(state, param, value)` when a droplet sets a parameter,
- `note(state, note, velocity)` for a voice (velocity 0 releases), and
- `process(state, left, right, n)` for each block of `n` frames.

A current that makes sound adds to `left` and `right`; an effect replaces them with what it makes of them.
`currents/drums.c` is a complete example.

A current has no C library and no calls into the firmware. Use `fastmath.h` for maths, keep everything in the state,
and use `float`, never `double`: the FM-1's FPU is single precision, and the build refuses a current with a double
in it.

## How a current loads

The `.cur` file is the current's code and data, linked at address 0, with a list of the addresses inside it. The
firmware copies it into RAM, adds its own address to each one, checks the descriptor and calls `init`. The current's
code then runs in the audio interrupt.
