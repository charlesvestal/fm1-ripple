# Droplets on Pd patches

These four droplets play the community Pd patches in `currents/pd/community/` (by boochow, MIT). Each one chains
several of them together:

| Droplet | Its currents | What it does |
| --- | --- | --- |
| `robot.lua` | `drums` (built in), `vocoder`, `vca` | A drum beat sung through a vocoder. The keys set the note it sings, and K1 and K2 set the two notes above it. |
| `chip.lua` | `chiptune`, `vca`, `bitcrush`, `chorus` | An arpeggiator on a chiptune oscillator. Hold keys and it plays them, up an octave and back. |
| `fold.lua` | `wavefolder`, `vca`, `freqshift`, `reflect` | A slowly moving wavefolded drone, frequency-shifted and played in a small room. The keys move its root. |
| `mono.lua` | `monosynth`, `chorus` | A monophonic synth with a filter and an envelope. SAVE keeps the sound. |

To try them, put the FM-1 in disk mode. Copy the droplets into `droplets` and the `.cur` files they use into
`currents`. You'll find the `.cur` files attached to each release, or you can build them with `./build.sh` (they go
to `app/build/extra`).

The logue oscillators sound all the time, as they do on a logue synth, where the synth's own envelope comes after them.
`chip` puts `vca` after its oscillator and opens it for each note. `fold` leaves its drone running.

These patches play at full scale, as their hardware expects, so a chain of them adds up to more than full scale.
Ripple then softens the peaks, which sounds crushed. Because `flow.level` comes after that softening, `robot`, `chip`
and `fold` turn the sound down inside the chain instead, with `vca`.
