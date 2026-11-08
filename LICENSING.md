# Licensing

| What | Licence |
| --- | --- |
| The firmware: `app/` (but `app/third_party/`), `tools/`, `tests/`, `docs/` | MPL-2.0 (`LICENSE`) |
| fm1-base (`base/`) and felucca-bsp (`base/bsp/`) | MPL-2.0, their own files |
| Lua 5.4 (`app/third_party/lua-5.4.7/`) | MIT, Lua.org, PUC-Rio (`app/third_party/lua-5.4.7/LICENSE`); the changes in `PATCHES.md` |
| The SDK (`sdk/`), the currents (`currents/`), the built-in droplets (`builtin/`) and the example droplets (`examples/`) | MIT (`sdk/LICENSE`; `currents/pd/LICENSE` beside this repository's own Pd patches) |
| `currents/sophie.c` | MIT: from Sophie 0.6.0 (github.com/mestela/schwung-sophie), Copyright (c) 2026 Matt Estela and the digisophie contributors, as SPH-16 ported it |
| `currents/monk.c` | MIT: from MonkSynth (github.com/JonET/monksynth), Copyright (c) 2026 Jonathan Taylor, as MONK-1 ported it |
| Mutable Instruments Plaits and stmlib (`currents/plaits/`) | MIT, Copyright (c) Emilie Gillet (`currents/plaits/LICENSE`); Plaits 1.2's DSP as LOOM-8 built it freestanding for the FM-1 (44.1 kHz, no ARM code, the random state per core), and the wavetable engine's map sized for its four banks |
| Heavy's runtime (built from hvcc's files into `sdk/build/heavy/runtime/`, not committed; `sdk/heavy/static/` holds the files changed for the FM-1, listed in `sdk/heavy/PATCHES.md`, and `HvUtils.h` adapted from it) | ISC, Copyright (c) 2014-2018 Enzien Audio Ltd., (`HvControlExpr`) Copyright (c) 2022-2025 Daniel Billotte, Wasted Audio, and (`HvControlList`, `HvSignalSchmitt`) Copyright (c) 2026 Wasted Audio, as hvcc (github.com/Wasted-Audio/hvcc) 0.17.3 has it, made freestanding for the FM-1 |
| The community Pd patches (`currents/pd/community/`) and the C Heavy makes from them | MIT, Copyright (c) 2025 and 2026 boochow Instruments (`currents/pd/community/LICENSE`): his Heavy examples for the logue SDK, NTS-1 mk2 and drumlogue, renamed |
| heavylib (`sdk/heavy/heavylib/`) | MIT, Copyright (c) 2015 Enzien Audio Ltd. (`sdk/heavy/heavylib/LICENSE`): Wasted Audio's heavylib, its abstractions without their help patches |
| The MIDI effects engine (`app/midifx/`) | MIT: from e16-launcher (github.com/charlesvestal/e16-launcher, apps/midifx/core), its sizes and 64-bit multiplies changed for the FM-1 |

A current or a droplet you write can use any license you like. The SDK's header and tools are MIT, and the C that
Faust generates from your `.dsp`, or Heavy from your `.pd`, is yours. Heavy's compiler (hvcc) is GPL-3.0, but only
its output is in Ripple. That output is the runtime, under ISC, and the code made from each patch, under the patch's
own copyright, which `sdk/tools/currents.py` takes from the `LICENSE` beside the patch. The Faust output kept in
`currents/gen/` (the C and Faust's JSON description) is generated from this repository's `.dsp` files. Nothing
generated from a Pd patch is committed.

Ripple is not affiliated with M-VAVE or monome. M-VAVE and FM-1 are trademarks of their owners; norns is monome's.
