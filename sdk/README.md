# Writing currents

A current is a piece of sound: a voice, a drum kit, a filter or a delay. Droplets load currents from the
`currents` folder on Ripple's disk. You write a current in Faust, in Pd or in C, build it into a `.cur` file on the
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
podman or Docker, as fm1-base does. Faust currents need `faust` on the path. Pd patches need hvcc in the Python that
runs `currents.py` (for how to install it, see "In Pd").

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

Faust code is compiled to C, then built like a C current. The parameters, their ranges and the number of inputs
come from Faust's own description of the sound (`faust -json`). The build keeps the C and that description in a
`gen` folder beside the `.dsp`: it makes them again where Faust is installed and uses them as they are where it
isn't, so commit them if others build your current without Faust.

A few things are different from Faust on a computer:

- There is no `double`: Faust is run with `-single`.
- The maths functions are fast approximations (`fastmath.h`), close enough for sound, not for science.
- Memory is limited. A droplet's currents share 132 KB: their code and data in 84 KB, their state in 48 KB more
  (then in what is left of the 84). Long delay lines are the usual problem: 16,000 float samples is 64 KB (the
  built-in `delay` is in C to keep its line at half the rate in 16 bits: 16 KB). Faust's table oscillators (`os.osc`) keep a
  65,536-sample table, too big here; use `os.sawtooth`, `os.square`, `os.triangle` or a sine from `ma.PI`.

## In Pd

A Pd patch becomes a current through [Heavy (hvcc)](https://github.com/Wasted-Audio/hvcc), Wasted Audio's
Pd compiler, which compiles it to C. Install the hvcc version Ripple is made for with
`pip install -r sdk/heavy/requirements.txt` (hvcc 0.17.3, which needs Python 3.10 or newer), then build the patch like
any other current:

```sh
sdk/tools/currents.py mysound.pd --out build/      # build/mysound.cur, for the FM-1
```

Heavy takes Pd vanilla's objects, but not all of them: no externals, no GUI objects, and some table and message
objects are limited. [Heavy's documentation](https://github.com/Wasted-Audio/hvcc/blob/develop/docs/reference/objects/supported.md)
lists them, and hvcc names any object it doesn't know.

The patch talks to Ripple through a few objects:

- `[r NAME @hv_param MIN MAX DEFAULT]` is a parameter that droplets set with `c:set("NAME", value)`. Connect it to
  something, or hvcc removes it.
- `[notein]` gets the notes a droplet plays with `c:note`: note, velocity 0 to 127 (0 releases), channel 1. The
  patch handles its own voices, with `[poly]` as usual.
- `[dac~]` is the sound out, one or two channels. With `[adc~]` the patch is an effect and works on the sound before
  it in the flow; without it, it adds its sound.

Patches written for Korg's logue SDK with boochow's [hvcc_loguesdk](https://github.com/boochow/hvcc_loguesdk_v1)
work as they are. The note goes to
`[r pitch @hv_param]` (in Hz) or `[r pitch_note @hv_param]`, with a bang on `[r noteon_trig @hv_param]` and
`[r noteoff_trig @hv_param]`, and a `[table NAME_r @hv_table]` is filled with white noise before each block. A
logue oscillator has no envelope of its own, so it sounds as long as the current runs.

Put the patch's abstractions in a `lib` folder beside it, so that the build doesn't take them for currents.
Wasted Audio's heavylib (`hv.reverb~`, `hv.compressor~`, `hv.lfo` and the rest) is in the SDK, and patches can use
it without copying it.
`currents/pd/community/` has patches by others, and `examples/pd/` droplets that play them. `currents/pd/pdpoly.pd`
is an example of your own: four voices from `[poly 4 1]`, each one `lib/pdvoice.pd`.

A few things are different from Pd on a computer:

- There is no `double`, and the maths functions are the fast approximations Faust currents use.
- `[print]` prints nothing.
- Heavy keeps its messages, delay lines and tables in memory of its own. The build measures how much a patch takes
  by running it on the computer and gives it that much and a quarter more. A table that grows while the patch runs
  can run out.
- Delay lines are the usual problem, as in Faust: `[delwrite~ d 1000]` is a second, 176 KB. The build says when a
  current is too big to load, and a droplet that loads it gets "no room". Shorten the delay to fit.

The build compiles each patch with hvcc every time, so the Python that runs it needs hvcc
(`pip install -r sdk/heavy/requirements.txt`: hvcc 0.17.3, Python 3.10 or newer). It runs hvcc as a library, with
Ripple's own generator (`sdk/heavy/c2ripple.py`, from the template `sdk/heavy/templates/current.cc`) writing the
wrapper that makes the patch a current; hvcc's C for the patch is built as hvcc writes it. The output is the same on
every run, and the same on a Mac and on Linux with the same Python version (the release builder has 3.12).
Nothing the build generates is committed: it goes to `sdk/build/heavy/`. Ripple's changes to Heavy's
runtime are the files in `sdk/heavy/static/`, which `sdk/heavy/PATCHES.md` lists. The runtime is Enzien Audio's and
Wasted Audio's, under the ISC licence; the C made from your patch is yours. Put a `LICENSE` beside the patch and the
build writes its copyright lines into that C.

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

## In C++

A current may be C++ (`.cc`), freestanding: no exceptions, RTTI, thread-safe statics or C++ library, and nothing that
needs a constructor run before it starts (the build refuses a current that does). Export the descriptor with
`extern "C" RC_EXPORT(D)`. There is no C library either: a current that needs `memset` or `memcpy` (C++ calls them
for its zeroing and copies) brings its own.

A current made of more files names them, and its flags, in lines of its own:

```c
// ripple-sources: plaits/plaits/**/*.cc plaits/stmlib/**/*.cc
// ripple-cflags: -Iplaits/shim -Iplaits -DTEST
```

The paths are relative to the current's file, and the other files are built once for each set of flags; only what
the current uses is kept. `currents/macro-va.cc` and `currents/plaits/plaits_current.h` are an example: one of
Plaits' engines a current, from the same shared source.

## In the emulator

The emulator on Ripple's site has every built-in current linked in. To try your own there, its panel **Write your
own** takes:

- a Faust current: write it there (choose "a current (Faust)") or drop the `.dsp` on it, and Run compiles it in the
  browser (Faust's WebAssembly compiler, loaded the first time). A droplet then loads it by its name.
- a C, C++ or Pd current, built for the browser on your computer:

  ```sh
  sdk/tools/currents.py mysound.c --web-module build/      # build/mysound.wasm (Emscripten's emcc)
  ```

  Drop the `.wasm` on the panel. (The FM-1 takes the `.cur`, the emulator the `.wasm`: the same source.)

The page keeps them in your browser and puts them back each time the emulator starts.

## How a current loads

The `.cur` file is the current's code and data, linked at address 0, with a list of the addresses inside it. Its
header also says what the current is (it makes sound or processes it, its voices, its state's size), so a droplet
can list the currents without loading them (`current.list`). The firmware copies it into RAM, adds its own address
to each one, checks the descriptor and calls `init`. The current's
code then runs in the audio interrupt.
