# Ripple

Ripple is a firmware for the M-VAVE FM-1 that runs **droplets** and **currents**. Droplets are instruments written in
Lua, and currents are the sounds they play, written in Faust, Pd or C. Both load from a disk in the FM-1's own flash.
In disk mode, the FM-1 shows up on your computer as a USB drive. Copy a droplet or a current onto it, eject it, and
it's there, with nothing to reflash.

Droplets and currents are kept separate on purpose. Any droplet can load any currents and chain them however it
likes, so a new instrument is often just a few lines of Lua over sounds that already exist. The FM bells from one
droplet can play a drum machine's pattern in another, through the same delay.

Ripple is inspired by monome's norns, which runs Lua scripts over compiled sound engines.

To try Ripple in your browser, install it or read the manual, go to
**[Ripple's site](https://charlesvestal.github.io/fm1-ripple)**. You can also download the latest release from
[GitHub](https://github.com/charlesvestal/fm1-ripple/releases/latest).

## On the FM-1

The list shows the droplets. The ones built into Ripple have an outlined mark, and yours on the disk have a filled
one. Turn SELECT (or press OCT- / OCT+) to pick one, and press PLAY to start it. Hold HOME for a second to go back to
the list.

Use **disk mode**, at the end of the list, to open the disk on your computer. It shows up as a drive called RIPPLE,
with the folders `droplets`, `currents`, `data` and `lib`. Eject the drive when you're done, and Ripple comes back to
the list. The whole disk (276 KB) is yours, because the built-in droplets and currents live in the firmware, not on
the disk. If a droplet or a current on the disk has the same name as a built-in one, Ripple uses yours instead. To
change a built-in droplet, copy it from `builtin/droplets` in this repository onto the disk and edit it there.

Use **Empty the disk** (press PLAY twice) to erase everything on the disk. It leaves the empty folders, and the
built-in droplets stay.

These droplets are built in:

| Droplet | What it is |
| --- | --- |
| arp | Hold keys and they play one after another |
| awake | A melody that wanders a scale on its own |
| beat | A 16-step drum machine on the white keys |
| bells | FM bells on loops of different lengths, drifting in and out of step |
| chords | A chord of the scale on every white key |
| drone | Three slow FM voices that change color by themselves |
| euclid | Three Euclidean drum tracks |
| life | Conway's Game of Life, playing a note for each cell born |
| loop | A note looper |
| midi | The FM-1 as a USB MIDI controller, with no sound of its own |
| monk | A singing voice from MonkSynth, as in MONK-1. Lean on a key to open the vowel |
| poly | A six-voice synth through a delay |
| rack | Build an instrument on the FM-1. Run MIDI effects (chords, arp, echo, feel, loop and beat stretch) into any voice, then through two effects |
| rain | Plucked notes falling on a scale into a reverb |
| sophie | Sixteen pads of metallic FM percussion from Sophie, as in SPH-16, with a 16-step pattern |

Every droplet but poly keeps its settings when you press SAVE. beat, euclid, loop and sophie keep their patterns too,
and rack keeps the whole rack. For their
controls, see [the manual](app/docs/MANUAL.md).

Besides `voice`, `delay`, `drums`, `fm`, `pluck`, `plate`, `monk` and `sophie`, Ripple has seventeen more currents built in (`macro-va`,
`macro-modal`, `macro-kick` and the rest). They are macro-oscillator engines from Emilie Gillet's open-source Plaits
code, and you play them with the rack. Three more (`macro-wave`, `macro-sixop`, `macro-speech`) don't fit in the
firmware. They come with each release as files, so copy them into `currents` on the disk to use them.

## Writing your own

To write a droplet, see [docs/DROPLETS.md](docs/DROPLETS.md). To write a current, see [sdk/README.md](sdk/README.md).

Use the emulator on the site to try your own right away. Its panel runs a droplet in Lua or a current in Faust as
you write it. You can also build a C or C++ current for it (`currents.py --web-module`) and drop it on the panel.

## Build and test

```sh
export PATH=~/github/fm1-parent/bin:$PATH        # bin/docker runs podman
./build.sh                                        # app/build/ripple.fwsc
./build.sh --host && sh tests/run_tests.sh        # the simulator and its tests
python3 base/tools/fm1_install.py app/build/ripple.fwsc --yes
```

The build compiles the Pd currents with hvcc every time, so the Python that runs `build.sh` and the tests needs it.
Install it with `pip install -r sdk/heavy/requirements.txt` (Python 3.10 or newer). Nothing generated from a Pd
patch is committed.

`build.sh` builds the currents (`currents/`) and puts them into the built-in volume with the droplets (`builtin/`).
Then it builds the firmware with fm1-base (`base/`). `disk/` is the empty disk a new FM-1 starts with.

## Licenses

Ripple is MPL-2.0. It's built on fm1-base and felucca-bsp, which come from Felucca by Leo Kuroshita (Hügelton
Instruments). The SDK (`sdk/`) and the built-in currents and droplets are MIT. `sophie` comes from Sophie by Matt
Estela and the digisophie contributors, `monk` from MonkSynth by Jonathan Taylor, and the `macro-*` currents from
Emilie Gillet's Plaits code. The MIDI effects are e16-launcher's engine (MIT). Lua 5.4 is MIT (Lua.org, PUC-Rio),
with the changes listed in `app/third_party/lua-5.4.7/PATCHES.md`.

Currents are written in Faust (GRAME) or in Pd. Pd currents are compiled by [hvcc](https://github.com/Wasted-Audio/hvcc),
Wasted Audio's continuation of Enzien Audio's Heavy, whose runtime is ISC. The code that Faust and Heavy generate
belongs to the current. For details, see [LICENSING.md](LICENSING.md).

