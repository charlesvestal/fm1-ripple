/* SPDX-License-Identifier: MIT
 * Copyright (C) 2026 Charles Vestal */
/* The MIDI effects engine as one unit of its own (fm1.toml o2): main loop only, never the render (app/fx.c). */
#include "mfx.c"
#include "mfx_params.c"

#ifndef PLAT_HOST
/* 64-bit division (the engine's positions are int64 clocks << 8): the compiler calls it, and a firmware without
 * Bluetooth links no compiler runtime. Shift and subtract: main loop only, a few a note */
long long __divdi3(long long a, long long b);
long long __divdi3(long long a, long long b)
{
    unsigned long long n = a < 0 ? 0ull - (unsigned long long)a : (unsigned long long)a;
    unsigned long long d = b < 0 ? 0ull - (unsigned long long)b : (unsigned long long)b, q = 0, r = 0;
    int i, neg = (a < 0) != (b < 0);
    if (!d)
        return 0;
    for (i = 63; i >= 0; i--) {
        r = r << 1 | (n >> i & 1u);
        if (r >= d) {
            r -= d;
            q |= 1ull << i;
        }
    }
    return neg ? (long long)(0ull - q) : (long long)q;
}
#endif
