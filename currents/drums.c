/* SPDX-License-Identifier: MIT
 * Copyright (C) 2026 Charles Vestal */
/* drums: a small kit for Ripple, written in C (the example of a current without Faust). Notes: 36 kick, 38 snare,
 * 42 closed hat, 46 open hat (any other note: the kick); velocity is the level. */
#include "ripple_current.h"
#include "fastmath.h"

enum { P_TUNE, P_DECAY, P_SNAP, P_LEVEL, NP };
static const rc_param_t P[NP] = {
    {"tune", 0.5f, 2.0f, 1.0f},          /* every drum's pitch */
    {"decay", 0.3f, 2.0f, 1.0f},         /* every drum's length */
    {"snap", 0.0f, 1.0f, 0.5f},          /* the snare's noise against its tone */
    {"level", 0.0f, 1.0f, 0.8f},
};

typedef struct {
    float p[NP], sr;
    float kick_ph, kick_env, kick_pitch, kick_vel;
    float sn_ph, sn_env, sn_tone, sn_vel;
    float hat_env, hat_vel, hat_decay, hp_x, hp_y;
    uint32_t noise;
} st_t;

static void init(void *s_, float sr)
{
    st_t *s = s_;
    s->sr = sr;
    s->noise = 0x12345u;
}

static void set(void *s_, int k, float v) { ((st_t *)s_)->p[k] = v; }

static void note(void *s_, int n, float vel)
{
    st_t *s = s_;
    if (vel <= 0.0f)
        return;
    if (n == 38) {
        s->sn_env = 1.0f;
        s->sn_tone = 1.0f;
        s->sn_vel = vel;
    } else if (n == 42 || n == 46) {
        s->hat_env = 1.0f;
        s->hat_vel = vel;
        s->hat_decay = n == 46 ? 0.9995f : 0.996f;
    } else {
        s->kick_env = 1.0f;
        s->kick_pitch = 1.0f;
        s->kick_vel = vel;
    }
}

static float noise(st_t *s)
{
    s->noise = s->noise * 1664525u + 1013904223u;
    return (float)(int32_t)s->noise * (1.0f / 2147483648.0f);
}

static void process(void *s_, float *l, float *r, int n)
{
    st_t *s = s_;
    float tune = s->p[P_TUNE], dk = s->p[P_DECAY], lv = s->p[P_LEVEL], snap = s->p[P_SNAP];
    float inv = 1.0f / s->sr;
    float k_dec = 1.0f - 0.00018f / dk, p_dec = 1.0f - 0.0016f, s_dec = 1.0f - 0.0004f / dk, t_dec = 1.0f - 0.0011f;
    float h_dec = 1.0f - (1.0f - s->hat_decay) / dk;
    int i;
    for (i = 0; i < n; i++) {
        float out = 0.0f, nz = noise(s);
        if (s->kick_env > 0.0005f) {     /* a sine falling from 150 Hz to 45 */
            float f = (45.0f + 105.0f * s->kick_pitch) * tune;
            s->kick_ph += f * inv;
            if (s->kick_ph >= 1.0f) s->kick_ph -= 1.0f;
            out += fm_sin_turns(s->kick_ph) * s->kick_env * s->kick_vel;
            s->kick_env *= k_dec;
            s->kick_pitch *= p_dec;
        }
        if (s->sn_env > 0.0005f) {       /* a tone at 190 Hz and noise */
            s->sn_ph += 190.0f * tune * inv;
            if (s->sn_ph >= 1.0f) s->sn_ph -= 1.0f;
            out += ((1.0f - snap) * fm_sin_turns(s->sn_ph) * s->sn_tone + snap * nz) * s->sn_env * s->sn_vel * 0.7f;
            s->sn_env *= s_dec;
            s->sn_tone *= t_dec;
        }
        if (s->hat_env > 0.0005f) {      /* noise through a highpass */
            float y = 0.86f * (s->hp_y + nz - s->hp_x);
            s->hp_x = nz;
            s->hp_y = y;
            out += y * s->hat_env * s->hat_vel * 0.35f;
            s->hat_env *= h_dec;
        }
        out *= lv;
        l[i] += out;
        r[i] += out;
    }
}

static const rc_desc_t D = {RC_MAGIC, RC_ABI, "drums", sizeof(st_t), 0, 8, NP, P, init, set, note, process};
RC_EXPORT(D)
