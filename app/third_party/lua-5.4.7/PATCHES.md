# Lua 5.4.7 in Ripple

Lua 5.4.7 from lua.org (MIT, `LICENSE` below), unchanged but for these lines, all marked `LUA_FM1`:

- `src/luaconf.h`: the local configuration section includes `luaport.h` (Ripple's `app/lua/`) when `LUA_FM1` is
  defined: 32-bit integers and floats, our own number formatting and maths, our setjmp, the disk's paths.
- `src/luaconf.h`: `LUA_32BITS` is 1 with `LUA_FM1`.
- `src/lauxlib.c`: `luaL_tolstring` turns a float into text by `lua_tolstring` instead of `lua_pushfstring("%f")`,
  and `luaL_checkversion_`'s message has no numbers: a float passed through `...` becomes a double, and the FM-1's FPU
  has single precision only.
- `src/lstrlib.c`: `string.pack` and `string.unpack` refuse `d` (a double); `f` and `n` are floats.
- `src/lobject.c`: `lua_pushfstring`'s `%f` takes a pointer to a `lua_Number` (nothing in Lua uses it now).

The build uses the files `app/lua/lua_one.c` lists; `lua.c`, `luac.c`, `liolib.c`, `loslib.c` and `ldblib.c` are
not built.
