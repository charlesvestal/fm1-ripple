# Droplets on Pd patches

Four droplets that play the community Pd patches in `currents/pd/community/` (boochow's, MIT), each a chain of
them:

| Droplet | Its currents | What it does |
| --- | --- | --- |
| `robot.lua` | `drums` (built in), `nts-vocoder`, `nts-vca` | A drum beat sung through a vocoder: the keys set the note it sings, K1 and K2 the two notes above it. |
| `chip.lua` | `logue-chiptune`, `nts-vca`, `nts-bitcrush`, `nts-chorus` | An arpeggiator on a chiptune oscillator: hold keys and it plays them, up an octave and back. |
| `fold.lua` | `logue-wavefolder`, `nts-vca`, `nts-freqshift`, `nts-reflection` | A slowly moving wavefolded drone, frequency-shifted in a small room. The keys move its root. |
| `mono.lua` | `dl-monosynth`, `nts-chorus` | A monophonic synth with a filter and envelope. SAVE keeps the sound. |

To try them, put the FM-1 in disk mode, copy the droplets into `droplets` and the `.cur` files they use into
`currents`. The `.cur` files are attached to each release, or build them with `./build.sh` (`app/build/extra`).

The logue oscillators sound all the time, as they do on a logue synth, where the synth's own envelope follows them.
`chip` puts `nts-vca` after its oscillator and opens it for each note; `fold` leaves its drone running.

These patches play at full scale, as their hardware expects, and a chain of them adds up past it: Ripple then
softens the peaks, which sounds crushed. `flow.level` comes after that, so `robot`, `chip` and `fold` turn the sound
down inside the chain instead, with `nts-vca`.
