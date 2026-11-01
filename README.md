# Ripple

A firmware for the M-VAVE FM-1 that runs **droplets** (instruments written in Lua) playing **currents** (sounds
written in Faust or C), both loaded from a disk in the FM-1's own flash. In disk mode, the FM-1 shows up on a
computer as a USB drive: copy a droplet or a current onto it, eject it, and it's there. Nothing needs reflashing.

Droplets and currents are separate on purpose: any droplet can load any currents and chain them as it likes, so a
new instrument is often just a few lines of Lua over sounds that already exist. The FM bells from one droplet can
play a drum machine's pattern in another, through the same delay.

Inspired by monome's norns: Lua scripts over compiled sound engines.

**[Try it in the browser, install it and read the manual](https://charlesvestal.github.io/fm1-ripple)** on Ripple's
site. The latest release is on [GitHub](https://github.com/charlesvestal/fm1-ripple/releases/latest).

## On the FM-1

The list shows the droplets: the ones built into Ripple (an outlined mark) and yours on the disk (a filled one).
Turn SELECT (or press OCT- / OCT+) to pick one and press PLAY to start it. Hold HOME for a second to go back to the
list.

At the end of the list, **disk mode** shows the disk to a computer as a drive called RIPPLE, with the folders
`droplets`, `currents`, `data` and `lib`. Eject the drive when you're done, and Ripple comes back to the list. The
whole disk (276 KB) is yours: the built-in droplets and currents live in the firmware, not on it. A droplet or a
current on the disk with the same name as a built-in one is used instead of it, so to change a built-in droplet,
copy it from `builtin/droplets` in this repository onto the disk and edit it there.

**Empty the disk** (press PLAY twice) erases everything on the disk and leaves the empty folders. The built-in
droplets stay.

The built-in droplets:

| Droplet | What it is |
| --- | --- |
| arp | Hold keys and they play one after another |
| awake | A melody that wanders a scale on its own |
| beat | A 16-step drum machine on the white keys |
| bells | FM bells on loops of different lengths, drifting in and out of step |
| chords | A chord of the scale on every white key |
| drone | Three slow FM voices that change colour by themselves |
| euclid | Three Euclidean drum tracks |
| life | Conway's Game of Life, a note for each cell born |
| loop | A note looper |
| midi | The FM-1 as a USB MIDI controller, no sound of its own |
| monk | A singing voice (MonkSynth, as MONK-1 has it): lean on a key to open the vowel |
| poly | A six-voice synth through a delay |
| rack | Build an instrument on the FM-1: MIDI effects (chords, arp, echo, feel, loop and beat stretch) into any voice, then two effects |
| rain | Plucked notes falling on a scale into a reverb |
| sophie | Sixteen pads of metallic FM percussion (Sophie, as SPH-16 has it) with a 16-step pattern |

For their controls, see [the manual](app/docs/MANUAL.md).

Besides the six currents of 0.1 and `monk` and `sophie`, seventeen of Mutable Instruments Plaits' engines are built in
as currents of their own (`plaits-va`, `plaits-modal`, `plaits-kick` and the rest): play them with the rack. Three more
(`plaits-wave`, `plaits-dx`, `plaits-speech`) are on each release as files to copy into `currents` on the disk: the
firmware has no room left for them.

Each keeps its settings when you press SAVE (beat, euclid and loop their patterns too).

## Writing your own

For droplets, see [docs/DROPLETS.md](docs/DROPLETS.md). For currents, see [sdk/README.md](sdk/README.md).

## Build and test

```sh
export PATH=~/github/fm1-parent/bin:$PATH        # bin/docker runs podman
./build.sh                                        # app/build/ripple.fwsc
./build.sh --host && sh tests/run_tests.sh        # the simulator and its tests
python3 base/tools/fm1_install.py app/build/ripple.fwsc --yes
```

`build.sh` builds the currents (`currents/`), puts them and the droplets (`builtin/`) into the built-in volume, then
builds the firmware with fm1-base (`base/`). `disk/` is the empty disk a new FM-1 starts with.

## Licences

Ripple is MPL-2.0, on fm1-base and felucca-bsp (from Felucca by Leo Kuroshita, Hügelton Instruments). The SDK
(`sdk/`), the built-in currents and droplets are MIT: `sophie` from Sophie by Matt Estela and the digisophie
contributors, `monk` from MonkSynth by Jonathan Taylor, the `plaits-*` currents from Mutable Instruments Plaits by
Emilie Gillet. The MIDI effects are e16-launcher's engine (MIT). Lua 5.4 is MIT (Lua.org, PUC-Rio), with the changes listed in
`app/third_party/lua-5.4.7/PATCHES.md`. Currents are written in Faust (GRAME); the code Faust generates is the
current's own. For details, see [LICENSING.md](LICENSING.md).

Ripple needs fm1-base's disk mode and code window, in review as charlesvestal/fm1-base#32 and
hugelton/felucca-bsp#25; until they merge, `base/` follows their branches.
