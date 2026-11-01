/* SPDX-License-Identifier: MIT
 * Copyright (C) 2026 Charles Vestal */
/* delay: a dub delay for Ripple. The bus summed into one line (0.36 s at most), darker on each repeat; the left hears
 * the time, the right three quarters of it. As delay.dsp was (the same parameters and the same path: the line's
 * repeats through a one-pole lowpass and the feedback), but the line runs at half the rate in 16 bits: 16 KB where
 * Faust's float line at the full rate took 66. Two input samples make one step of the line, and the taps come back
 * as a straight line between steps, so nothing above ~10 kHz repeats (the tone's ceiling). */
#include "ripple_current.h"
#include "fastmath.h"

enum { P_FEEDBACK, P_MIX, P_TIME, P_TONE, NP };   /* (delay.dsp's order: a droplet may set them by number) */
static const rc_param_t P[NP] = {
    {"feedback", 0.0f, 0.92f, 0.45f},
    {"mix", 0.0f, 1.0f, 0.3f},
    {"time", 0.01f, 0.36f, 0.28f},
    {"tone", 300.0f, 12000.0f, 3500.0f},
};

#define LINE 8192u                     /* half-rate steps: 0.37 s at 22.05 kHz */
#define SCALE 4096.0f                  /* the line holds +-8 */

typedef struct {
    float p[NP], hsr;                  /* the parameters; the line's rate */
    float d, d_target, d_coef;         /* the time in steps, smoothed (~5 ms, as si.smoo) */
    float b0, a1, x1, y1;              /* the repeats' lowpass (Faust's fi.lowpass(1, tone): bilinear) */
    float tl, tr;                      /* the last step's taps (the upsampling's other end) */
    uint32_t w;
    int16_t line[LINE];
} st_t;

static void tone_set(st_t *s)
{
    float fc = fm_minf(s->p[P_TONE], 0.45f * s->hsr), k = fm_tanf(FM_PI * fc / s->hsr);
    s->b0 = k / (1.0f + k);
    s->a1 = (k - 1.0f) / (k + 1.0f);
}

static void init(void *st, float sr)
{
    st_t *s = st;
    s->hsr = sr * 0.5f;
    s->d_coef = 1.0f - fm_expf(-1.0f / (0.005f * s->hsr));
}

static void set(void *st, int k, float v)
{
    st_t *s = st;
    s->p[k] = v;
    if (k == P_TIME) {
        s->d_target = v * s->hsr;
        if (s->d == 0.0f)
            s->d = s->d_target;        /* (the first time: no glide from nothing) */
    } else if (k == P_TONE)
        tone_set(s);
}

static float tap(const st_t *s, float d)
{
    float rd = (float)s->w - d, fr;
    uint32_t i;
    if (rd < 0.0f)
        rd += (float)LINE;
    i = (uint32_t)rd;
    fr = rd - (float)i;
    return ((float)s->line[i & (LINE - 1u)] * (1.0f - fr) + (float)s->line[(i + 1u) & (LINE - 1u)] * fr) *
           (1.0f / SCALE);
}

static void process(void *st, float *l, float *r, int n)
{
    st_t *s = st;
    float fb = s->p[P_FEEDBACK], mix = s->p[P_MIX], dry = 1.0f - mix;
    int i;
    for (i = 0; i + 1 < n; i += 2) {
        float x = 0.25f * (l[i] + r[i] + l[i + 1] + r[i + 1]), a, b, y, wv;
        s->d += (s->d_target - s->d) * s->d_coef;
        a = tap(s, s->d);
        b = tap(s, s->d * 0.75f);
        y = s->b0 * (a + s->x1) - s->a1 * s->y1;   /* the repeat, darker */
        s->x1 = a;
        s->y1 = fm_flush(y);
        wv = fm_clampf((x + y * fb) * SCALE, -32767.0f, 32767.0f);
        s->line[s->w] = (int16_t)(wv < 0.0f ? wv - 0.5f : wv + 0.5f);
        s->w = (s->w + 1u) & (LINE - 1u);
        l[i] = l[i] * dry + 0.5f * (s->tl + a) * mix;
        r[i] = r[i] * dry + 0.5f * (s->tr + b) * mix;
        l[i + 1] = l[i + 1] * dry + a * mix;
        r[i + 1] = r[i + 1] * dry + b * mix;
        s->tl = a;
        s->tr = b;
    }
}

static const rc_desc_t D = {RC_MAGIC, RC_ABI, "delay", sizeof(st_t), 2, 0, NP, P, init, set, 0, process,
                            0, {0}, 0, 0};
RC_EXPORT(D)
