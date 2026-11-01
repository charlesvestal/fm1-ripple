/* SPDX-License-Identifier: MIT
 * Copyright (c) 2026 Matt Estela
 * Copyright (c) 2026 digisophie contributors
 * Copyright (C) 2026 Charles Vestal */
/* sophie: sixteen pads of metallic FM percussion, from Sophie 0.6.0 by Matt Estela and the digisophie contributors
 * (github.com/mestela/schwung-sophie, MIT), as SPH-16 ported it to the FM-1 (fm1-sph dsp/sophie.c): the voice is
 * Sophie's render_voice() sample for sample, in fastmath.h's maths.
 *
 * Notes 36 to 51 hit pads 1 to 16 (any other note: its pad modulo 16); velocity is the level. Each pad has its own
 * sound: set "pad" to a pad's number (1..16) and the parameters after it change that pad; "pad" 0 (where it starts)
 * changes every pad. The parameters are SPH-16's pots, the numbers its kits are written in: model 0..5 (fuse, stack,
 * split, shard, pipe, boom), tune 0..48 (24: as written), decay 0..127 (30 ms to 4 s), time 0..127 (the ring's,
 * 0.5 to 30 ms), mdecay 0..127 (0: off, else 5 ms to 2 s), filter 0..4 (LPF, HPF, notch, DJ, BPF), fbmode and tail
 * 0..1, pan 0..127, the rest 0..100 (sweep 0..200, 100: none; ring 0..95). A hit takes a snapshot of its pad (tail
 * 0); tail 1 lets colour, metal, feedback, cutoff and resonance follow the pad as it rings.
 *
 * Twelve voices; "voices" caps how many new hits use (the oldest is taken). In two parts (voices 0-5 and 6-11, filled
 * in turn): one for each core. Sophie's reverb and delay sends are not here: put the flow's effects after it. */
#include "ripple_current.h"
#include "fastmath.h"

#define SR 44100.0f
#define TAU FM_TWO_PI
#define STEAL 66                        /* 1.5 ms: a stolen voice fades into the new hit */
#define CTRL 16                         /* Live tails: the controls follow the pad every 16 samples */
#define SPH_PADS 16
#define SPH_VOICES 12
#define SPH_DELAY 1536                  /* the ring delay: ~34 ms */
#define SPH_QUIET 0.00012f              /* a voice ends under this envelope (Sophie's: -78 dB) */

enum { SP_MODEL, SP_TUNE, SP_DECAY, SP_LEVEL, SP_COLOR, SP_METAL, SP_FDBK, SP_SWEEP, SP_CUTOFF, SP_RESO, SP_FILTER,
       SP_DRIVE, SP_RTIME, SP_RING, SP_RMIX, SP_RTONE, SP_CRUSH, SP_MDECAY, SP_FBMODE, SP_TAIL, SP_PAN, SP_NPARAMS };
enum { MODEL_FUSE, MODEL_STACK, MODEL_SPLIT, MODEL_SHARD, MODEL_PIPE, MODEL_BOOM, NMODELS };
enum { P_PAD = SP_NPARAMS, P_VOICES, NP };

static const rc_param_t P[NP] = {
    {"model", 0, NMODELS - 1, 0}, {"tune", 0, 48, 24}, {"decay", 0, 127, 60}, {"level", 0, 100, 100},
    {"color", 0, 100, 50}, {"metal", 0, 100, 50}, {"fdbk", 0, 100, 20}, {"sweep", 0, 200, 100},
    {"cutoff", 0, 100, 100}, {"reso", 0, 100, 0}, {"filter", 0, 4, 0}, {"drive", 0, 100, 50},
    {"time", 0, 127, 77}, {"ring", 0, 95, 0}, {"mix", 0, 100, 0}, {"tone", 0, 100, 70},
    {"crush", 0, 100, 0}, {"mdecay", 0, 127, 0}, {"fbmode", 0, 1, 0}, {"tail", 0, 1, 0}, {"pan", 0, 127, 64},
    {"pad", 0, SPH_PADS, 0}, {"voices", 1, SPH_VOICES, SPH_VOICES},
};

typedef struct {                        /* a pad in the engine's units (Sophie's) */
    int model, filter_type, feedback_mode, tail_mode;
    float tune, color, metal, feedback, sweep, decay, crush, drive, level, cutoff, resonance;
    float ring_time, ring_feedback, ring_mix, ring_tone, metal_decay;
} sph_patch_t;

typedef struct {
    float carrier, mod1, mod2, mod3, sub, upper, split;     /* phases, radians */
    float metal_env, metal_mul, amp_mul, pitch_mul;
    float color_s, metal_s, feedback_s, cutoff_s, resonance_s;
    float last, steal_tail;
    float amp_env, pitch_env, attack, feedback_z, filter_low, filter_band, noise_z, base_hz, velocity;
    float crush_hold, delay_lp;
    float gl, gr;                       /* the pad's pan, gliding */
    float drive_gain, drive_norm, crush_levels, crush_step, delay_samples, f_coef, q_coef;   /* (Hit: fixed at the hit) */
    int steal_left, crush_count, crush_div, delay_pos, pad, active;
    uint32_t age, rng;
    sph_patch_t p;
    int16_t delay_buf[SPH_DELAY];
} sph_voice_t;

typedef struct {
    sph_voice_t v[SPH_VOICES];
    sph_patch_t pad[SPH_PADS];
    float pl[SPH_PADS], pr[SPH_PADS];   /* each pad's pan */
    uint32_t age, rng;
    int nvoices;                        /* new hits take the first nvoices (sph_limit) */
    float quiet;
    int sel;                            /* the pad the parameters change: 0 every pad, else 1..16 */
} sph_t;

/* the pan: a balance law, pot 0..127, 64 = centre (1 on both sides); toward a side the other fades along a quarter
 * cosine (SPH-16's x0x_pan_gains) */
static void pan_gains(int pot, float *l, float *r)
{
    float q = pot >= 64 ? (float)(pot - 64) / 63.0f : (float)(pot - 64) / 64.0f, x, c;
    x = q * 1.5707963f;
    x *= x;
    c = 1.0f + x * (-0.5f + x * (0.041666667f + x * (-0.0013888889f + x * 0.0000248016f)));
    if (pot <= 0 || pot >= 127)
        c = 0.0f;
    *l = q > 0.0f ? c : 1.0f;
    *r = q < 0.0f ? c : 1.0f;
}

/* a gain gliding toward its target over a block of n samples (~10 ms): the per-sample step, *cur moved to where the
 * block ends */
static float glide_block(float *cur, float tgt, int n)
{
    float c = *cur, e;
    if (c == tgt)
        return 0.0f;
    e = (tgt - c) * (n >= 441 ? 1.0f : (float)n * (1.0f / 441.0f));
    if (tgt - (c + e) < 1e-5f && (c + e) - tgt < 1e-5f)
        e = tgt - c;
    *cur = c + e;
    return e / (float)n;
}

/* the exponential ranges: DECAY 0.03-4 s, TIME 0.5-30 ms, M.DECAY 5-2000 ms (0: off) */
#define DECAY_OCT 7.05889369f                       /* log2(4 / 0.03) */
#define RTIME_OCT 5.90689060f                       /* log2(60) */
#define MDECAY_OCT 8.64385619f                      /* log2(400) */

static float sph_value(int i, int pot)
{
    float v = (float)pot;
    switch (i) {
    case SP_TUNE: return v - 24.0f;
    case SP_SWEEP: return v - 100.0f;
    case SP_DECAY: return 0.03f * fm_exp2f(v * (DECAY_OCT / 127.0f));
    case SP_RTIME: return 0.5f * fm_exp2f(v * (RTIME_OCT / 127.0f));
    case SP_MDECAY: return pot ? 5.0f * fm_exp2f((v - 1.0f) * (MDECAY_OCT / 126.0f)) : 0.0f;
    default: return v;
    }
}

/* one pot of one pad */
static void pad_set(sph_t *s, int pad, int i, int pot)
{
    sph_patch_t *p = &s->pad[pad];
    float v = sph_value(i, pot);
    switch (i) {
    case SP_MODEL: p->model = pot; break;
    case SP_TUNE: p->tune = v; break;
    case SP_DECAY: p->decay = v; break;
    case SP_LEVEL: p->level = v; break;
    case SP_COLOR: p->color = v; break;
    case SP_METAL: p->metal = v; break;
    case SP_FDBK: p->feedback = v; break;
    case SP_SWEEP: p->sweep = v; break;
    case SP_CUTOFF: p->cutoff = v; break;
    case SP_RESO: p->resonance = v; break;
    case SP_FILTER: p->filter_type = pot; break;
    case SP_DRIVE: p->drive = v; break;
    case SP_RTIME: p->ring_time = v; break;
    case SP_RING: p->ring_feedback = v; break;
    case SP_RMIX: p->ring_mix = v; break;
    case SP_RTONE: p->ring_tone = v; break;
    case SP_CRUSH: p->crush = v; break;
    case SP_MDECAY: p->metal_decay = v; break;
    case SP_FBMODE: p->feedback_mode = pot; break;
    case SP_TAIL: p->tail_mode = pot; break;
    default: pan_gains(pot, &s->pl[pad], &s->pr[pad]); break;
    }
}

/* --------------------------------------------------------------- voices --- */
static uint32_t xorshift32(uint32_t *state)
{
    uint32_t x = *state ? *state : 0x6d2b79f5u;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *state = x;
    return x;
}
static float noise_bipolar(uint32_t *state)
{
    return (float)(xorshift32(state) & 0x00ffffffu) * (2.0f / 16777215.0f) - 1.0f;
}
static float soft_clip(float x) { return x / (1.0f + fm_fabsf(x)); }

/* sine of any angle: to [-1/4, 1/4] of a turn, then a degree-7 polynomial (|error| < 1e-4, -80 dB:
 * half the cost of fm_sinf, and a voice takes four to seven of these a sample) */
static inline float qsin(float x)
{
    float t = x * 0.159154943f, y, y2;
    t -= (float)(int32_t)(t + (t >= 0.0f ? 0.5f : -0.5f));
    if (t > 0.25f)
        t = 0.5f - t;
    else if (t < -0.25f)
        t = -0.5f - t;
    y = t * 6.28318531f;
    y2 = y * y;
    return y * (1.0f + y2 * (-0.1666665668f + y2 * (0.008332075f + y2 * -0.000195152959f)));
}

/* the filter's coefficients from the (smoothed) cutoff and resonance */
static void filter_coefs(sph_voice_t *v)
{
    float fc = 40.0f * fm_exp2f(v->cutoff_s * 0.01f * 8.64385619f);   /* 40 * 400^(c/100) */
    v->f_coef = fm_clampf(2.0f * fm_sinf(FM_PI * fc / SR), 0.001f, 0.95f);
    v->q_coef = fm_clampf(1.0f - v->resonance_s * 0.009f, 0.05f, 1.0f);
}

/* a free voice, else the oldest, among the first s->nvoices in the order 0, 6, 1, 7 ..: the two
 * halves (one per core) fill evenly, however many voices are allowed */
static sph_voice_t *allocate(sph_t *s)
{
    sph_voice_t *oldest = 0;
    int k;
    for (k = 0; k < s->nvoices; k++) {
        sph_voice_t *v = &s->v[(k & 1) ? SPH_VOICES / 2 + k / 2 : k / 2];
        if (!v->active)
            return v;
        if (!oldest || v->age < oldest->age)
            oldest = v;
    }
    return oldest;
}

static void sph_limit(sph_t *s, int voices, float quiet)
{
    s->nvoices = voices < 1 ? 1 : voices > SPH_VOICES ? SPH_VOICES : voices;
    s->quiet = quiet;
}

static void sph_trigger(sph_t *s, int pad, float vel)
{
    sph_voice_t *v;
    const sph_patch_t *p;
    float tail, pitch_time, metal_ms, drive, units;
    int stolen, legacy_kick, ivel = (int)(vel * 127.0f + 0.5f), note = 36 + pad;
    uint32_t k;
    if (pad < 0 || pad >= SPH_PADS)
        return;
    v = allocate(s);
    tail = v->active ? v->last : 0.0f;
    stolen = v->active;
    for (k = 0; k < (uint32_t)((uint8_t *)v->delay_buf - (uint8_t *)v); k++)   /* (the delay line: below) */
        ((uint8_t *)v)[k] = 0;
    for (k = 0; k < SPH_DELAY; k++)
        v->delay_buf[k] = 0;
    v->steal_tail = tail;
    v->steal_left = stolen ? STEAL : 0;
    v->active = 1;
    v->age = ++s->age;
    v->velocity = fm_clampf(vel, 0.01f, 1.0f);
    for (k = 0; k < sizeof v->p / 4u; k++)            /* the pad's snapshot (a loop: no memcpy here) */
        ((uint32_t *)&v->p)[k] = ((const uint32_t *)&s->pad[pad])[k];
    p = &v->p;
    v->pad = pad;
    v->color_s = p->color;
    v->metal_s = p->metal;
    v->feedback_s = p->feedback;
    v->cutoff_s = p->cutoff;
    v->resonance_s = p->resonance;
    legacy_kick = pad == 0 && p->model < MODEL_PIPE;
    pitch_time = legacy_kick ? 0.075f : 0.028f;
    v->amp_mul = fm_expf(fm_logf(0.00012f) / (fm_clampf(p->decay, 0.03f, 4.0f) * SR));
    v->pitch_mul = fm_expf(-1.0f / (pitch_time * SR));
    metal_ms = p->metal_decay > 0.0f ? fm_maxf(5.0f, p->metal_decay) : 135.0f;
    v->metal_mul = fm_expf(-1.0f / (metal_ms * 0.001f * SR));
    v->metal_env = 1.0f;
    v->base_hz = fm_clampf(440.0f * fm_exp2f(((float)note - 69.0f) * (1.0f / 12.0f)) * fm_exp2f(p->tune * (1.0f / 12.0f)),
                           20.0f, 10000.0f);
    v->amp_env = 1.0f;
    v->pitch_env = 1.0f;
    v->rng = xorshift32(&s->rng) ^ ((uint32_t)note << 16) ^ (uint32_t)ivel;
    v->mod2 = noise_bipolar(&v->rng) * 0.12f;         /* a little phase variation: no machine gun */
    v->mod3 = noise_bipolar(&v->rng) * 0.08f;
    /* what stays fixed for the hit */
    drive = fm_clampf(p->drive * 0.01f, 0.0f, 1.0f);
    units = drive <= 0.5f ? drive * 100.0f : 50.0f + 250.0f * fm_powf((drive - 0.5f) * 2.0f, 1.5f);
    v->drive_gain = 1.0f + units * 0.075f;
    v->drive_norm = soft_clip(v->drive_gain);
    if (drive > 0.5f)
        v->drive_norm += (1.0f - v->drive_norm) * 0.72f * (drive - 0.5f) * 2.0f;
    v->drive_norm = 1.0f / v->drive_norm;
    v->crush_div = 1 + (int)(p->crush * 0.01f * p->crush * 0.01f * 31.0f);
    v->crush_levels = fm_exp2f(15.0f - p->crush * 0.01f * 12.0f);
    v->crush_step = 1.0f / v->crush_levels;
    v->delay_samples = fm_clampf(p->ring_time * 0.001f * SR, 1.0f, (float)(SPH_DELAY - 2));
    filter_coefs(v);
    v->gl = s->pl[pad];                                /* the pan: from where the pad is */
    v->gr = s->pr[pad];
}

/* one voice, n samples, added into the four buffers. What changes from sample to sample is kept in
 * locals and written back once: the stores into the buffers could alias the voice, and would make
 * the compiler load and store every field of it on every sample. */
static void render_voice(const sph_t *s, sph_voice_t *v, float *L, float *R, int n)
{
    const sph_patch_t *p = &v->p, *target = &s->pad[v->pad];
    const int model = p->model, ftype = p->filter_type;
    const int legacy_kick = v->pad == 0 && model < MODEL_PIPE, shaped = p->metal_decay > 0.0f || model >= MODEL_PIPE;
    const int smooth = p->feedback_mode == 1, live = p->tail_mode == 1;
    const int need_m2 = legacy_kick || model <= MODEL_SPLIT;
    const int need_m3 = !legacy_kick && (model == MODEL_STACK || model == MODEL_SPLIT);
    const float sweep_k = p->sweep * 0.01f * (legacy_kick ? 2.5f : 4.5f), level = p->level * 0.01f;
    const float tone = 0.02f + p->ring_tone * 0.0098f, ring_fb = p->ring_feedback * 0.01f, mix = p->ring_mix * 0.01f;
    const int crushing = p->crush * 0.01f >= 0.005f;
    const float quiet = s->quiet, base_hz = v->base_hz;
    const float amp_mul = v->amp_mul, pitch_mul = v->pitch_mul, metal_mul = v->metal_mul;
    const float drive_gain = v->drive_gain, drive_vel = v->drive_norm * v->velocity;
    const float crush_levels = v->crush_levels, crush_step = v->crush_step, delay_samples = v->delay_samples;
    const int crush_div = v->crush_div;
    float carrier = v->carrier, mod1 = v->mod1, mod2 = v->mod2, mod3 = v->mod3, sub = v->sub, upper = v->upper,
          split = v->split;
    float amp_env = v->amp_env, pitch_env = v->pitch_env, metal_env = v->metal_env, attack = v->attack;
    float feedback_z = v->feedback_z, filter_low = v->filter_low, filter_band = v->filter_band, noise_z = v->noise_z;
    float crush_hold = v->crush_hold, delay_lp = v->delay_lp, steal_tail = v->steal_tail, last = v->last;
    float gl = v->gl, gr = v->gr, f = v->f_coef, q = v->q_coef;
    float color = 0, metal = 0, feedback = 0, r1 = 0, r2 = 0, r3 = 0, dgl, dgr;
    int crush_count = v->crush_count, delay_pos = v->delay_pos, steal_left = v->steal_left, sweep = sweep_k != 0.0f;
    int i, active = 1;
    uint32_t rng = v->rng;
    int16_t *dbuf = v->delay_buf;
    {   /* the mixer: each gain glides to its pad's over this block */
        float a = gl, b = gr;
        dgl = glide_block(&a, s->pl[v->pad], n);
        dgr = glide_block(&b, s->pr[v->pad], n);
    }
    for (i = 0; i < n; i++) {
        float brightness, hz, inc, fb, m1, m2, m3, index, out, dry;
        if ((i & (CTRL - 1)) == 0) {                  /* control rate: Live's smoothing, the ratios */
            if (live) {
                const float a = 0.0699922f;                 /* 5 ms: 1 - exp(-16 / 220.5) */
                v->color_s += (target->color - v->color_s) * a;
                v->metal_s += (target->metal - v->metal_s) * a;
                v->feedback_s += (target->feedback - v->feedback_s) * a;
                v->cutoff_s += (target->cutoff - v->cutoff_s) * a;
                v->resonance_s += (target->resonance - v->resonance_s) * a;
                filter_coefs(v);
                f = v->f_coef;
                q = v->q_coef;
            }
            color = v->color_s * 0.01f;
            metal = v->metal_s * 0.01f;
            feedback = v->feedback_s * 0.01f;
            if (smooth)
                feedback *= feedback;
            r1 = model == MODEL_PIPE ? 1.31f + color * 6.0f : model == MODEL_BOOM ? 0.60f + color * 4.2f
                                                                                 : 0.47f + color * color * 7.6f;
            r2 = 1.31f + color * 11.17f;
            r3 = 2.07f + (1.0f - color) * 15.73f;
            if (sweep && fm_fabsf(sweep_k * pitch_env) < 1e-4f)
                sweep = 0;                             /* (under 0.0001 octave: off for good) */
        }
        amp_env *= amp_mul;
        pitch_env *= pitch_mul;
        metal_env *= metal_mul;
        if (metal_env < 0.000001f)
            metal_env = 0.0f;
        attack += (1.0f - attack) * 0.085f;
        if (amp_env < quiet) {
            active = 0;
            break;
        }
        brightness = shaped ? metal_env : pitch_env;
        hz = base_hz;
        if (sweep)
            hz = fm_clampf(hz * fm_exp2f(sweep_k * pitch_env), 18.0f, 18000.0f);
        inc = TAU * hz * (1.0f / SR);
#define WRAP(ph, d) do { ph += (d); if (ph >= TAU) ph -= TAU; } while (0)
        WRAP(carrier, inc);
        WRAP(mod1, inc * r1);
        WRAP(mod2, inc * r2);
        WRAP(mod3, inc * r3);
        if (smooth) {
            WRAP(sub, inc * (legacy_kick ? 0.503f : 0.501f));
            WRAP(upper, inc * (legacy_kick ? 2.01f : 1.997f));
            WRAP(split, inc * 1.003f);
        }
#undef WRAP
        fb = feedback_z * feedback * (2.0f + metal * 10.0f);
        m1 = qsin(mod1 + fb);
        m2 = need_m2 ? qsin(mod2 + m1 * metal * 2.5f) : 0.0f;    /* (a model that does not hear one */
        m3 = need_m3 ? qsin(mod3) : 0.0f;                        /* skips its sine) */
        index = metal * metal * (2.0f + 24.0f * (0.25f + brightness * 0.75f));
        if (smooth) {                                  /* an FM bandwidth ceiling (heuristic) */
            float bw = fm_maxf(100.0f, SR * 0.45f - hz), rate = hz * r1 * (1.0f + metal * 2.5f);
            index = fm_minf(index, bw / fm_maxf(rate, 1.0f));
        }
        if (legacy_kick) {                             /* pad 1: a sine body with a quiet FM texture */
            float body = qsin(carrier), folded = qsin(body * (1.0f + color * 2.2f));
            float texture = qsin(carrier + m2 * (0.18f + feedback * 1.35f)), nz = noise_bipolar(&rng);
            noise_z += (nz - noise_z) * 0.32f;
            out = body * (0.86f - color * 0.08f) + folded * (0.14f + color * 0.08f) +
                  texture * metal * 0.18f * (shaped ? brightness : 1.0f) + noise_z * pitch_env * (0.012f + metal * 0.035f);
            if (model == MODEL_STACK)
                out += 0.16f * qsin((smooth ? upper : carrier * 2.01f) + m1 * (0.4f + metal * 2.0f));
            else if (model == MODEL_SPLIT)
                out += 0.14f * qsin((smooth ? sub : carrier * 0.503f) - m2 * (0.3f + metal * 1.5f));
            else if (model == MODEL_SHARD) {
                float stair = fm_floorf(carrier * (24.0f / TAU)) * (TAU / 24.0f);
                out += 0.12f * qsin(stair + m1 * (0.5f + metal * 2.0f));
            }
        } else {
            switch (model) {
            default:                                   /* FUSE: two modulators in series */
                out = qsin(carrier + index * (m2 * 0.72f + m1 * 0.28f));
                break;
            case MODEL_STACK:
                out = qsin(carrier + index * 0.62f * m1) +
                      0.55f * qsin((smooth ? sub : carrier * 0.501f) + index * 0.35f * m2) +
                      0.32f * qsin((smooth ? upper : carrier * 1.997f) + index * 0.22f * m3);
                out *= 0.56f;
                break;
            case MODEL_SPLIT:
                out = 0.62f * qsin(carrier + index * m1) +
                      0.38f * qsin((smooth ? split : carrier * 1.003f) - index * 0.71f * m2) + 0.18f * m3;
                break;
            case MODEL_PIPE: {                         /* FM carrier and an inharmonic ring */
                float body = qsin(carrier + index * m1), rm = 0.3125f + metal * 0.5f + brightness * 0.125f;
                out = (body * (1.0f - rm) + body * m1 * rm) * 1.25f;
                break;
            }
            case MODEL_BOOM: {                         /* a clean fundamental, a metallic skin */
                float body = qsin(carrier), edge = qsin(carrier + index * m1);
                float em = 0.0625f + metal * brightness * 0.5f;
                out = body * (1.0f - em) + edge * em;
                break;
            }
            case MODEL_SHARD: {                        /* a 12-bit wavetable and noise */
                float stair = fm_floorf(carrier * (32.0f / TAU)) * (TAU / 32.0f), nz = noise_bipolar(&rng);
                noise_z += (nz - noise_z) * (0.02f + color * 0.35f);
                out = qsin(stair + index * 0.55f * m1) * (0.85f - metal * 0.25f) +
                      noise_z * metal * 0.42f * (shaped ? brightness : 1.0f);
                break;
            }
            }
        }
        {
            float fo = soft_clip(out * 1.4f);
            feedback_z = smooth ? feedback_z + (fo - feedback_z) * 0.0700921f : fo;   /* 1 - 0.875^(24000/44100) */
        }
        out *= amp_env * attack * level;
        if (crushing) {                                /* sample and hold, then fewer bits */
            if (crush_count <= 0) {
                crush_hold = out;
                crush_count = crush_div;
            }
            out = crush_hold;
            crush_count--;
            out = fm_floorf(out * crush_levels + 0.5f) * crush_step;
        }
        dry = soft_clip(out * drive_gain) * drive_vel;
        if (mix > 0.0f) {                              /* the ring: a short feedback delay (a comb at a few */
            float rd = (float)delay_pos - delay_samples, frac, delayed, w;   /* ms); at no MIX, not heard at all */
            int r0, rn;
            if (rd < 0.0f)
                rd += (float)SPH_DELAY;
            r0 = (int)rd;
            rn = r0 + 1 < SPH_DELAY ? r0 + 1 : 0;
            frac = rd - (float)r0;
            delayed = ((float)dbuf[r0] * (1.0f - frac) + (float)dbuf[rn] * frac) * (1.0f / 32767.0f);
            delay_lp += tone * (delayed - delay_lp);
            delayed = delay_lp;
            w = fm_clampf(dry + delayed * ring_fb, -1.0f, 1.0f) * 32767.0f;
            dbuf[delay_pos] = (int16_t)(w < 0.0f ? w - 0.5f : w + 0.5f);
            if (++delay_pos >= SPH_DELAY)
                delay_pos = 0;
            out = dry * (1.0f - mix) + delayed * mix;
        } else
            out = dry;
        {   /* the filter, last: it can tame everything above */
            float high;
            filter_low += f * filter_band;
            high = out - filter_low - q * filter_band;
            filter_band += f * high;
            switch (ftype) {
            case 0: out = filter_low; break;
            case 1: out = high; break;
            case 2: out = high + filter_low; break;
            case 4: out = filter_band; break;
            default: {                                 /* DJ: LP at the left, BP in the middle, HP at the right */
                float pos = fm_clampf(v->cutoff_s * 0.01f, 0.0f, 1.0f), t;
                if (pos < 0.5f) {
                    t = pos * 2.0f;
                    out = filter_low * (1.0f - t) + filter_band * t;
                } else {
                    t = (pos - 0.5f) * 2.0f;
                    out = filter_band * (1.0f - t) + high * t;
                }
                break;
            }
            }
        }
        if (steal_left) {
            float t = (float)steal_left-- * (1.0f / STEAL);
            out = out * (1.0f - t) + steal_tail * t;
        }
        last = out;
        out *= 0.24f;                                  /* Sophie's mix of twelve voices */
        L[i] += out * gl;
        R[i] += out * gr;
        gl += dgl;
        gr += dgr;
    }
    v->carrier = carrier;
    v->mod1 = mod1;
    v->mod2 = mod2;
    v->mod3 = mod3;
    v->sub = sub;
    v->upper = upper;
    v->split = split;
    v->amp_env = amp_env;
    v->pitch_env = pitch_env;
    v->metal_env = metal_env;
    v->attack = attack;
    v->feedback_z = feedback_z;
    v->filter_low = filter_low;
    v->filter_band = filter_band;
    v->noise_z = noise_z;
    v->crush_hold = crush_hold;
    v->crush_count = crush_count;
    v->delay_lp = delay_lp;
    v->delay_pos = delay_pos;
    v->steal_left = steal_left;
    v->last = last;
    v->rng = rng;
    v->active = active;
    /* (exact at the end of the glide) */
    v->gl = dgl != 0.0f && fm_fabsf(s->pl[v->pad] - gl) < 1e-5f ? s->pl[v->pad] : gl;
    v->gr = dgr != 0.0f && fm_fabsf(s->pr[v->pad] - gr) < 1e-5f ? s->pr[v->pad] : gr;
}


/* ------------------------------------------------------------ the current --- */
static void init(void *st, float sr)
{
    sph_t *s = st;
    int pad, i;
    (void)sr;                                          /* (44.1 kHz, as Sophie's constants are) */
    for (pad = 0; pad < SPH_PADS; pad++)
        for (i = 0; i < SP_NPARAMS; i++)
            pad_set(s, pad, i, (int)P[i].def);
    s->rng = 0x534f5048u;
    sph_limit(s, SPH_VOICES, SPH_QUIET);
}

static void set(void *st, int k, float v)
{
    sph_t *s = st;
    int pot = (int)(v + 0.5f), pad;
    if (k == P_PAD)
        s->sel = pot;
    else if (k == P_VOICES)
        sph_limit(s, pot, SPH_QUIET);
    else if (s->sel)
        pad_set(s, s->sel - 1, k, pot);
    else
        for (pad = 0; pad < SPH_PADS; pad++)
            pad_set(s, pad, k, pot);
}

static void note(void *st, int n, float vel)
{
    if (vel > 0.0f)
        sph_trigger(st, (n >= 36 ? n - 36 : n) & (SPH_PADS - 1), vel);
}

static void process_part(void *st, float *l, float *r, int n, int part)
{
    sph_t *s = st;
    int i;
    for (i = part * (SPH_VOICES / 2); i < (part + 1) * (SPH_VOICES / 2); i++)
        if (s->v[i].active)
            render_voice(s, &s->v[i], l, r, n);
}

static void process(void *st, float *l, float *r, int n)
{
    process_part(st, l, r, n, 0);
    process_part(st, l, r, n, 1);
}

static const rc_desc_t D = {RC_MAGIC, RC_ABI, "sophie", sizeof(sph_t), 0, SPH_VOICES, NP, P, init, set, note, process,
                            2, {0}, process_part, 0};
RC_EXPORT(D)
