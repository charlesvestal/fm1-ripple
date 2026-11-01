/* SPDX-License-Identifier: MIT
 * Copyright (C) 2026 Charles Vestal */
/* webbeep: a test current for the emulator's uploaded currents (tests/host/emu_upload.mjs): a sine for each note,
 * built by sdk/tools/currents.py --web-module, never built in. */
#include "ripple_current.h"
#include "fastmath.h"

static const rc_param_t P[] = {{"level", 0.0f, 1.0f, 0.5f}};
typedef struct { float level, ph, inc, env; int note; } st_t;
static void init(void *s, float sr) { ((st_t *)s)->inc = 440.0f / sr; }
static void set(void *s, int k, float v) { (void)k; ((st_t *)s)->level = v; }
static void note(void *s_, int n, float vel)
{
    st_t *s = s_;
    if (vel > 0.0f) {
        s->note = n;
        s->inc = 440.0f * fm_exp2f((float)(n - 69) / 12.0f) / 44100.0f;
        s->env = vel;
    } else if (n == s->note)
        s->env = 0.0f;
}
static void process(void *s_, float *l, float *r, int n)
{
    st_t *s = s_;
    int i;
    for (i = 0; i < n; i++) {
        float x = fm_sin_turns(s->ph) * s->env * s->level;
        s->ph += s->inc;
        if (s->ph >= 1.0f) s->ph -= 1.0f;
        l[i] += x;
        r[i] += x;
    }
}
static const rc_desc_t D = {RC_MAGIC, RC_ABI, "webbeep", sizeof(st_t), 0, 1, 1, P, init, set, note, process, 0, {0}, 0, 0};
RC_EXPORT(D)
