# Writing currents

A current is a piece of sound, such as a voice, a drum kit, a filter or a delay. Droplets load currents from the
`currents` folder on Ripple's disk. You write a current in Faust, Pd, C or C++, build it into a `.cur` file on the
computer, and copy that file onto the disk in disk mode. Nothing on the FM-1 needs updating. If a current on the disk
has the same name as a built-in one (`voice`, `delay`, `drums`, `fm`, `monk`, `pluck`, `plate`, `sophie` and the
`macro-` engines), droplets use yours instead.

The SDK is MIT-licensed, so your currents may use any license.

## Build

From Ripple's repository:

```sh
sdk/tools/currents.py mysound.dsp --out build/      # build/mysound.cur, for the FM-1
sdk/tools/currents.py mysound.dsp --host build/     # build/mysound.so, for the simulator
```

Put the FM-1 in disk mode and copy `mysound.cur` into `currents` on Ripple's disk. A droplet can then load it with
`current.load("mysound")`.

To build for the FM-1, you need the JieLi toolchain (`JIELI_TOOLCHAIN`, default `~/.jieli/toolchain`) and, on a Mac,
podman or Docker, as for fm1-base. Faust currents need `faust` on the path. Pd patches need hvcc in the Python that
runs `currents.py`. For how to install it, see "In Pd".

## In Faust

Write the sound as usual. Its sliders become the current's parameters, with their names, ranges and defaults.

A current with sliders called `freq`, `gain` and `gate` and no inputs is a voice. Droplets play it with notes, which
set those three. It plays six notes at once, or as many as `declare voices "N";` says. A current with inputs is an
effect, and it works on the sound that comes before it in the flow. Anything else just makes sound.

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

The build compiles your Faust code to C, then builds it like a C current. The parameters, their ranges and the number
of inputs come from Faust's own description of the sound (`faust -json`). The build keeps the C and that description
in a `gen` folder beside the `.dsp`. Where Faust is installed, it makes them again; where it isn't, it uses them as
they are. Commit them if other people will build your current without Faust.

A few things are different from Faust on a computer:

- There is no `double`. The build runs Faust with `-single`.
- The math functions are fast approximations (`fastmath.h`). They're close enough for sound, but not for science.
- Memory is limited. A droplet's currents share 132 KB. Their code and data go in 84 KB, and their state in another
  48 KB (and past that, in whatever is left of the 84 KB). Long delay lines are the usual problem: 16,000 float
  samples take 64 KB. The built-in `delay` is written in C so that it can keep its line at half the rate in 16 bits,
  which takes 16 KB.
- Faust's table oscillators (`os.osc`) keep a 65,536-sample table, which is too big here. Use `os.sawtooth`,
  `os.square`, `os.triangle` or a sine made from `ma.PI` instead.

## In Pd

A Pd patch becomes a current through [Heavy (hvcc)](https://github.com/Wasted-Audio/hvcc), Wasted Audio's
compiler from Pd to C. Install the hvcc version Ripple is made for with `pip install -r sdk/heavy/requirements.txt`
(hvcc 0.17.3, which needs Python 3.10 or newer). Then build the patch like any other current:

```sh
sdk/tools/currents.py mysound.pd --out build/      # build/mysound.cur, for the FM-1
```

Heavy takes most of Pd vanilla's objects. It has no externals and no GUI objects, and some table and message objects
are limited. For the full list, see
[Heavy's documentation](https://github.com/Wasted-Audio/hvcc/blob/develop/docs/reference/objects/supported.md).
If your patch uses an object Heavy doesn't know, hvcc tells you its name.

Your patch talks to Ripple through a few objects:

- Use `[r NAME @hv_param MIN MAX DEFAULT]` for a parameter, which droplets set with `c:set("NAME", value)`. Connect it
  to something, or hvcc removes it.
- `[notein]` receives the notes a droplet plays with `c:note`. Each note comes with a velocity from 0 to 127 (0
  releases it) on channel 1. The patch handles its own voices, with `[poly]` as usual.
- `[dac~]` is the sound out, with one or two channels. If the patch has an `[adc~]`, it's an effect and works on the
  sound that comes before it in the flow. Without one, it adds its own sound.

Patches written for Korg's logue SDK with boochow's [hvcc_loguesdk](https://github.com/boochow/hvcc_loguesdk_v1)
play as they are. The note goes to `[r pitch @hv_param]` (in Hz) or `[r pitch_note @hv_param]`, with a bang on
`[r noteon_trig @hv_param]` and `[r noteoff_trig @hv_param]`. Ripple fills each `[table NAME_r @hv_table]` with white
noise before each block. A logue oscillator has no envelope of its own, so it sounds for as long as the current runs.

Put the patch's abstractions in a `lib` folder beside it, so that the build doesn't take them for currents. Wasted
Audio's heavylib (`hv.reverb~`, `hv.compressor~`, `hv.lfo` and the rest) comes with the SDK, and your patches can use
it without copying it.

For patches by other people, see `currents/pd/community/`, and for droplets that play them, see `examples/pd/`. For an
example of your own, see `currents/pd/pdpoly.pd`. It makes four voices with `[poly 4 1]`, and each voice is
`lib/pdvoice.pd`.

A few things are different from Pd on a computer:

- There is no `double`, and the math functions are the same fast approximations Faust currents use.
- `[print]` prints nothing.
- Heavy keeps its messages, delay lines and tables in memory of its own. The build measures how much a patch needs by
  running it on the computer, and gives it that much plus a quarter more. A table that grows while the patch runs can
  run out of room.
- Delay lines are the usual problem, as in Faust. `[delwrite~ d 1000]` holds a second, which takes 176 KB. The build
  tells you when a current is too big to load, and a droplet that loads it anyway gets "no room". Shorten the delay
  until it fits.

The build compiles each patch with hvcc every time. It runs hvcc as a library, and Ripple's own generator
(`sdk/heavy/c2ripple.py`, from the template `sdk/heavy/templates/current.cc`) writes the wrapper that makes the patch
a current. hvcc's C for the patch is built just as hvcc writes it. The output is the same on every run, and the same on
a Mac and on Linux with the same Python version (the release builder uses 3.12). Nothing the build generates is
committed. It all goes to `sdk/build/heavy/`.

Ripple's changes to Heavy's runtime are the files in `sdk/heavy/static/`. For the list, see `sdk/heavy/PATCHES.md`.
The runtime is Enzien Audio's and Wasted Audio's, under the ISC license. The C made from your patch is yours. If you
put a `LICENSE` beside the patch, the build writes its copyright lines into that C.

## In C

A C current fills in an `rc_desc_t` (`include/ripple_current.h`) and exports it with `RC_EXPORT`. The firmware hands
it a block of zeroed state (`state_size` bytes) and calls these functions:

- `init(state, sr)` once, after loading.
- `set(state, param, value)` when a droplet sets a parameter.
- `note(state, note, velocity)` for a voice (velocity 0 releases the note).
- `process(state, left, right, n)` for each block of `n` frames.

A current that makes sound adds to `left` and `right`. An effect replaces them with its own output. A current can
have up to 64 parameters.

The FM-1 has two cores, and a current that makes sound can hand half its work to the second one. Set `parts` to 2 and
give it `process_part(state, left, right, n, part)`, which adds part 0 or part 1 (usually the even or the odd voices)
into `left` and `right`. The two parts run at the same time, so each one must touch only its own voices and scratch
memory. Both can read what `set` and `note` write, because those run before the block, never during it. Put any work
that must happen once a block, before either part, in `begin(state, n)` (a knob's slew, for example). Ripple runs the
parts on the two cores, and calls `process` instead when it has only one. A Faust voice is split this way
automatically. To see it done in C, look at `currents/sophie.c` and `currents/monk.c`. For a complete example, see
`currents/drums.c`.

A current has no C library and can't call into the firmware. Use `fastmath.h` for math, and keep everything in the
state. Use `float`, never `double`. The FM-1's FPU is single precision, and the build refuses a current with a double
in it.

## In C++

A current can be written in C++ (`.cc`), freestanding. That means no exceptions, no RTTI, no thread-safe statics, no
C++ library, and nothing that needs a constructor run before it starts (the build refuses a current that has one).
Export the descriptor with `extern "C" RC_EXPORT(D)`. There is no C library either, so if your current needs `memset`
or `memcpy`, it has to bring its own. C++ calls them when it zeroes and copies things.

A current made of several files names them, and its flags, in lines of their own:

```c
// ripple-sources: plaits/plaits/**/*.cc plaits/stmlib/**/*.cc
// ripple-cflags: -Iplaits/shim -Iplaits -DTEST
```

The paths are relative to the current's file. The other files are built once for each set of flags, and only what
the current uses is kept. For an example, see `currents/macro-va.cc` and `currents/plaits/plaits_current.h`. They
make one of the macro-oscillator engines from Emilie Gillet's open-source Plaits code into a current, from the same
shared source as the others.

## In the emulator

The emulator on Ripple's site has every built-in current linked in. To try your own there, use its **Write your
own** panel.

- For a Faust current, choose "a current (Faust)" and write it there, or drop the `.dsp` on the panel. Run compiles it
  in the browser with Faust's WebAssembly compiler, which loads the first time you use it. A droplet can then load
  the current by its name.
- For a C, C++ or Pd current, build it for the browser on your computer, then drop the `.wasm` on the panel:

  ```sh
  sdk/tools/currents.py mysound.c --web-module build/      # build/mysound.wasm (Emscripten's emcc)
  ```

  The `.wasm` for the emulator and the `.cur` for the FM-1 come from the same source.

The page keeps your currents in your browser and loads them again each time the emulator starts.

## How a current loads

The `.cur` file holds the current's code and data, linked at address 0, with a list of the addresses inside it. Its
header also says what kind of current it is: whether it makes sound or processes it, how many voices it has and how
big its state is. That way a droplet can list the currents with `current.list` without loading them. To load a
current, the firmware copies it into RAM, adds the load address to each address in the list, checks the descriptor
and calls `init`. From then on, the current's code runs in the audio interrupt.
