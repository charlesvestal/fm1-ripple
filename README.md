# Ripple

A firmware for the M-VAVE FM-1 that runs **droplets** (instruments written in Lua) playing **currents** (sounds
written in Faust or C), both loaded from a disk in the FM-1's own flash. In disk mode, the FM-1 shows up on a
computer as a USB drive: copy a droplet or a current onto it, eject it, and it's there. Nothing needs reflashing.

Inspired by monome's norns: Lua scripts over compiled sound engines.

## On the FM-1

The list shows the droplets on the disk. Turn SELECT (or press OCT- / OCT+) to pick one and press PLAY to start it.
Hold HOME for a second to go back to the list.

At the end of the list, **disk mode** shows the disk to a computer as a drive called RIPPLE, with the folders
`droplets` and `currents`. Eject the drive when you're done, and Ripple comes back to the list. **Restore the disk**
puts the shipped droplets and currents back, and erases everything else on the disk.

The shipped droplets:

- awake: a melody that wanders a scale on its own. K1 tempo, K2 how far it wanders, K3 how often it rests, K4 the
  filter; PLAY stops and starts it.
- beat: a 16-step drum machine. The white keys are the steps, ALGORITHM picks the drum, PLAY starts and stops it.
- poly: the keys play a six-voice synth through a delay. K1 to K4 set cutoff, resonance, delay time and feedback.

## Writing your own

For droplets, see [docs/DROPLETS.md](docs/DROPLETS.md). For currents, see [sdk/README.md](sdk/README.md).

## Build and test

```sh
export PATH=~/github/fm1-parent/bin:$PATH        # bin/docker runs podman
./build.sh                                        # app/build/ripple.fwsc
./build.sh --host && sh tests/run_tests.sh        # the simulator and its tests
python3 base/tools/fm1_install.py app/build/ripple.fwsc --yes
```

`build.sh` builds the currents (`currents/`), puts them and `disk/` into the shipped disk image, then builds the
firmware with fm1-base (`base/`).

## Licences

Ripple is MPL-2.0, on fm1-base and felucca-bsp (from Felucca by Leo Kuroshita, Hügelton Instruments). The SDK
(`sdk/`), the shipped currents and droplets are MIT. Lua 5.4 is MIT (Lua.org, PUC-Rio), with the changes listed in
`app/third_party/lua-5.4.7/PATCHES.md`. Currents are written in Faust (GRAME); the code Faust generates is the
current's own.
