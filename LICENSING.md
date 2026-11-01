# Licensing

| What | Licence |
| --- | --- |
| The firmware: `app/` (but `app/third_party/`), `tools/`, `tests/`, `docs/` | MPL-2.0 (`LICENSE`) |
| fm1-base (`base/`) and felucca-bsp (`base/bsp/`) | MPL-2.0, their own files |
| Lua 5.4 (`app/third_party/lua-5.4.7/`) | MIT, Lua.org, PUC-Rio (`app/third_party/lua-5.4.7/LICENSE`); the changes in `PATCHES.md` |
| The SDK (`sdk/`), the currents (`currents/`) and the built-in droplets (`builtin/`) | MIT (`sdk/LICENSE`) |

A current or a droplet you write may use any licence: the SDK's header and tools are MIT, and the C that Faust
generates from your `.dsp` is yours. The kept Faust output in `currents/gen/` is generated from this repository's
`.dsp` files.

Ripple is not affiliated with M-VAVE or monome. M-VAVE and FM-1 are trademarks of their owners; norns is monome's.
