/* SPDX-License-Identifier: MIT
 * Copyright (c) 2026 Jonathan Taylor
 * Copyright (C) 2026 Charles Vestal */
/* monk: a singing voice, MonkSynth by Jonathan Taylor (github.com/JonET/monksynth, MIT) as MONK-1 ported it to the
 * FM-1 (fm1-monk dsp/monk.c): its FOF voice (a grain of three formants and a breath, laid down once a pitch period),
 * the monophonic note stack with its two glides, vibrato with jitter, the ADSR and the unison. The grain, the period
 * (32 steps a semitone), the vibrato and the envelope follow upstream step for step.
 *
 * Changed from MONK-1, to fit beside the flow's other currents: no delay of its own (put the flow's after it); the
 * formants' curve worked out when a grain is made, not kept in a table; the sine, the formants' decay and the breath
 * in 16-bit tables; up to four unison voices (MONK-1: ten), each with a 1280-sample overlap buffer (a grain lands at
 * most a block ahead of the read, and is 882 long); the output's gain ramped over each block (the two parts share
 * it), where MONK-1 stepped it, and no tanh (the flow's own soft clip is after it). Without the delay it is mono, on
 * both sides. Against MONK-1 with its delay off, the difference is 55 dB under the voice.
 *
 * Monophonic: notes stack, the last one held sings. Velocity sets the level (by "velsens"). "press" is the sounding
 * key's pressure (0..1, a droplet sets it from touch.pressure): with "route" 0 it opens the vowel by "depth", 1 bends
 * up to two semitones, 2 both, 3 closes the vowel and bends. The knobs MONK-1 slewed (vowel, head, vibrato, rate,
 * breath, detune, level, spread, tune) glide over ~35 ms.
 *
 * Two parts, the even and the odd unison voices: with two or more voices, one for each core. */
#include "ripple_current.h"
#include "fastmath.h"

#define MK_FS 44100.0f
#define NUM_FORMANTS 3
#define SINE_SIZE 1024
#define GRAIN_LEN 882                 /* 0.02 s at 44.1 kHz */
#define OLAP 1280u                    /* > a block (256) + a grain */
#define MAX_UNISON 4
#define MAX_NOTES 16
#define PITCH_TABLE_BASE 8.175799f    /* MIDI note 0 */
#define ENV_ANTICLICK 0.003f
#define RAMP_TICKS 10
#define Q15 (1.0f / 32767.0f)

enum {
    P_GLIDE, P_VOWEL, P_HEAD, P_VIBRATO, P_RATE, P_BREATH, P_ATTACK, P_DECAY, P_SUSTAIN, P_RELEASE, P_VOICES,
    P_DETUNE, P_LEVEL, P_SPREAD, P_TUNE, P_PRESS, P_ROUTE, P_DEPTH, P_VELSENS, NP
};
static const rc_param_t P[NP] = {     /* upstream's defaults (processor.h); voices as a count */
    {"glide", 0, 1, 0.5f}, {"vowel", 0, 1, 0.5f}, {"head", 0, 1, 0.5f}, {"vibrato", 0, 1, 0.0f},
    {"rate", 0, 1, 0.5f}, {"breath", 0, 1, 0.5f}, {"attack", 0, 1, 0.0f}, {"decay", 0, 1, 0.0f},
    {"sustain", 0, 1, 1.0f}, {"release", 0, 1, 0.0f}, {"voices", 1, MAX_UNISON, 1}, {"detune", 0, 1, 0.0f},
    {"level", 0, 1, 1.0f}, {"spread", 0, 1, 0.0f}, {"tune", 0, 1, 0.5f}, {"press", 0, 1, 0.0f},
    {"route", 0, 3, 0}, {"depth", 0, 1, 0.5f}, {"velsens", 0, 1, 0.5f},
};
enum { AT_VOWEL, AT_PITCH, AT_BOTH, AT_BOTH_INV };
static const uint8_t SMOOTH[NP] = {   /* knobs slewed rather than stepped (Schwung's choice) */
    [P_VOWEL] = 1, [P_HEAD] = 1, [P_VIBRATO] = 1, [P_RATE] = 1, [P_BREATH] = 1, [P_DETUNE] = 1, [P_LEVEL] = 1,
    [P_SPREAD] = 1, [P_TUNE] = 1, [P_PRESS] = 1,
};
#define SLEW_COEF 0.15f               /* per 256-sample block: ~35 ms */
#define SLEW_SNAP 0.002f
#define BEND_RANGE 2.0f

static const float FORMANT_FREQS[NUM_FORMANTS][5] = {
    {280.0f, 450.0f, 800.0f, 350.0f, 270.0f},
    {600.0f, 800.0f, 1150.0f, 2000.0f, 2140.0f},
    {2240.0f, 2830.0f, 2900.0f, 2800.0f, 2950.0f},
};
static const float FORMANT_BW[NUM_FORMANTS] = {32.5f, 47.5f, 62.5f};

enum { ENV_IDLE, ENV_ATTACK, ENV_DECAY, ENV_SUSTAIN, ENV_RELEASE };

typedef struct {
    uint8_t active;
    float current_pitch, target_pitch;   /* note units */
    float pitch_bend_offset;
    float glide_param, min_glide;
    float pitch_step;
    int pitch_ramp_ticks;
    float vowel_step;
    int vowel_ramp_ticks;
    int ramp_counter, ramp_period;
    float vibrato_phase, vibrato_depth, vibrato_rate, rate_scale;
    float random_jitter;
    uint32_t jitter_counter, jitter_period;
    uint32_t rng_state;
    uint32_t overlap_write_pos, overlap_read_pos, overlap_offset;
    float current_vowel, target_vowel, current_voice, aspiration_amp;
    uint8_t grain_dirty;
    float g_vowel, g_voice, g_asp;       /* what the grain in grain[] was made of (-1: none yet) */
    int last_step;                       /* the period's quantized pitch step, and its period */
    uint32_t last_period;
    int env_stage;
    float env_level, env_attack, env_decay, env_sustain, env_release;
    float overlap_buf[OLAP];
    float grain[GRAIN_LEN];
} mk_voice_t;

typedef struct {
    int16_t sine[SINE_SIZE];                 /* Q15 */
    int16_t env[NUM_FORMANTS][GRAIN_LEN];    /* the formant's decay times the window, Q15 */
    int16_t asp[GRAIN_LEN];                  /* the breath times the window, Q15 */
    float p2[384];                           /* 2^(k / 384) */
    mk_voice_t v[MAX_UNISON];
    int unison_count;
    float unison_detune, unison_voice_spread, base_voice, last_base_note;
    uint8_t held[MAX_NOTES], held_count;
    float level, cur_gain, target_gain;
    /* the wrapper: the knobs' targets and slewed values, velocity, the bend */
    float p[NP], cur[NP];
    float vel_gain, vel_target, bend_cur;
    float g0, gstep;                         /* this block's output gain and its step (begin) */
    float mono[2][256];                      /* each part's voices */
} mk_t;

static inline float clampf(float x, float lo, float hi) { return x < lo ? lo : (x > hi ? hi : x); }
static float clamp01(float v) { return clampf(v, 0.0f, 1.0f); }
static int16_t q15(float x) { return (int16_t)(clampf(x, -1.0f, 1.0f) * 32767.0f + (x < 0.0f ? -0.5f : 0.5f)); }

/* ------------------------------------------------------------------- tables */
static void build_tables(mk_t *S)
{
    int f, i;
    for (i = 0; i < SINE_SIZE; i++)
        S->sine[i] = q15(fm_sinf(FM_TWO_PI * (float)i / SINE_SIZE));
    {   /* the grain window: a short cosine attack, flat, a cosine release that stops short of zero */
        float sr = MK_FS, bw = 50.0f * FM_PI, p1 = sr * 0.000202f, p2 = sr * 0.000263f;
        uint32_t attack_len = (uint32_t)(sr * 0.0018f), release_start = (uint32_t)(sr * 0.013f);
        uint32_t release_len = (uint32_t)(sr * 0.007f), decay_len = GRAIN_LEN * 4u, n;
        for (n = 0; n < GRAIN_LEN; n++) {
            float w = 1.0f, s1, s2, d1 = 0.0f, d2 = 0.0f;
            uint32_t i1, i2;
            if (n < attack_len)
                w = 0.5f * (1.0f - fm_cosf(FM_PI * (float)n / (float)attack_len));
            if (n >= release_start)
                w = 0.5f * (1.0f - fm_cosf(FM_PI * (float)(release_len + n) / (float)release_len));
            for (f = 0; f < NUM_FORMANTS; f++) {
                uint32_t di = (uint32_t)(FORMANT_BW[f] * (float)n / 50.0f);
                S->env[f][n] = q15((di < decay_len ? fm_expf(-bw * (float)di / sr) : 0.0f) * w);
            }
            s1 = fm_sinf(FM_TWO_PI * (float)n / p1);   /* the breath: two inharmonic decaying sines */
            i1 = (uint32_t)((float)n * 3.0f);
            if (i1 < decay_len)
                d1 = fm_expf(-bw * (float)i1 / sr);
            s2 = fm_sinf(FM_TWO_PI * (float)n / p2);
            i2 = (uint32_t)((float)n * 3.5f);
            if (i2 < decay_len)
                d2 = fm_expf(-bw * (float)i2 / sr);
            S->asp[n] = q15((s1 * d1 + s2 * d2) * w);
        }
    }
    for (i = 0; i < 384; i++)
        S->p2[i] = fm_exp2f((float)i / 384.0f);
}

/* ------------------------------------------------------------------- voice */
static float next_rand(mk_voice_t *v)
{
    v->rng_state = v->rng_state * 1103515245u + 12345u;
    return (float)((v->rng_state >> 16) & 0x7FFF) / 32768.0f;
}

static float env_tick(mk_voice_t *v)
{
    float rate;
    switch (v->env_stage) {
    case ENV_ATTACK:
        rate = 1.0f / (fm_maxf(v->env_attack, ENV_ANTICLICK) * MK_FS);
        v->env_level += rate;
        if (v->env_level >= 1.0f) {
            v->env_level = 1.0f;
            v->env_stage = v->env_decay > 0.0f ? ENV_DECAY : ENV_SUSTAIN;
        }
        break;
    case ENV_DECAY:
        rate = v->env_decay > 0.0f ? 1.0f / (v->env_decay * MK_FS) : 1.0f;
        v->env_level -= rate * (1.0f - v->env_sustain);
        if (v->env_level <= v->env_sustain) {
            v->env_level = v->env_sustain;
            v->env_stage = ENV_SUSTAIN;
        }
        break;
    case ENV_RELEASE:
        rate = 1.0f / (fm_maxf(v->env_release, ENV_ANTICLICK) * MK_FS);
        v->env_level -= rate;
        if (v->env_level <= 0.0f) {
            v->env_level = 0.0f;
            v->env_stage = ENV_IDLE;
            v->active = 0;
        }
        break;
    default:
        break;
    }
    return v->env_level;
}

/* a formant's frequency at vowel 0..1: Catmull-Rom across the five vowels. MONK-1 kept the curve in a table of 1280
 * points (320 a segment) and read it with a straight line between two; here the two points are worked out when a
 * grain is made, the same values without the table */
#define SPLINE_SIZE 1280
#define SPLINE_SEG 320
static float spline_point(int f, int at)
{
    const float *pts = FORMANT_FREQS[f];
    float padded[7] = {pts[0], pts[0], pts[1], pts[2], pts[3], pts[4], pts[4]};
    int seg = at / SPLINE_SEG, i = at - seg * SPLINE_SEG;
    float p0 = padded[seg], p1 = padded[seg + 1], p2 = padded[seg + 2], p3 = padded[seg + 3];
    float t = (float)i / SPLINE_SEG, t2 = t * t, t3 = t2 * t;
    return 0.5f * ((2.0f * p1) + (-p0 + p2) * t + (2.0f * p0 - 5.0f * p1 + 4.0f * p2 - p3) * t2 +
                   (-p0 + 3.0f * p1 - 3.0f * p2 + p3) * t3);
}

static float lookup_formant(int f, float vowel)
{
    float pos = clampf(vowel, 0.0f, 1.0f) * (SPLINE_SIZE - 1), frac;
    int idx = (int)pos;
    if (idx > SPLINE_SIZE - 2)
        idx = SPLINE_SIZE - 2;
    frac = pos - (float)idx;
    return spline_point(f, idx) * (1.0f - frac) + spline_point(f, idx + 1) * frac;
}

/* the grain period: the pitch quantized to 32 steps a semitone (audible, and intended) */
static uint32_t grain_period(const mk_t *S, mk_voice_t *v, float note)
{
    int step = (int)((note - 12.0f) * 32.0f), oct, k;
    float freq;
    if (step == v->last_step)
        return v->last_period;
    v->last_step = step;
    oct = step >= 0 ? step / 384 : -((-step + 383) / 384);
    k = step - oct * 384;
    freq = S->p2[k] * PITCH_TABLE_BASE;
    freq = oct >= 0 ? freq * (float)(1u << (oct > 20 ? 20 : oct)) : freq / (float)(1u << (-oct > 20 ? 20 : -oct));
    v->last_period = (uint32_t)(MK_FS / freq);
    return v->last_period;
}

static void apply_portamento(mk_voice_t *v)
{
    if (v->min_glide > 0.001f) {
        if (--v->ramp_counter > 0)
            return;
        v->ramp_counter = v->ramp_period;
        if (v->pitch_ramp_ticks > 0) {
            v->pitch_ramp_ticks--;
            v->current_pitch += v->pitch_step;
            if (v->pitch_ramp_ticks == 0)
                v->current_pitch = v->target_pitch;
        }
        if (v->vowel_ramp_ticks > 0) {
            v->vowel_ramp_ticks--;
            v->current_vowel += v->vowel_step;
            if (v->vowel_ramp_ticks == 0)
                v->current_vowel = v->target_vowel;
        }
    } else if (v->glide_param > 0.001f) {
        float diff = v->target_pitch - v->current_pitch;
        float rate = 12.0f / ((v->glide_param + 0.01f) * MK_FS);
        if (diff > 0.2f)
            v->current_pitch += rate;
        else if (diff < -0.2f)
            v->current_pitch -= rate;
        else
            v->current_pitch = v->target_pitch;
        v->current_vowel = v->target_vowel;
    } else {
        v->current_pitch = v->target_pitch;
        v->current_vowel = v->target_vowel;
    }
}

static float compute_vibrato(const mk_t *S, mk_voice_t *v)
{
    float rate = (v->vibrato_depth * 0.2f + 1.0f) * v->random_jitter * v->rate_scale;
    v->vibrato_phase += rate * ((float)SINE_SIZE / MK_FS);
    while (v->vibrato_phase >= (float)SINE_SIZE)
        v->vibrato_phase -= (float)SINE_SIZE;
    if (++v->jitter_counter >= v->jitter_period) {
        v->jitter_counter = 0;
        v->random_jitter = next_rand(v) * 2.0f + 5.0f;
    }
    return (v->vibrato_depth + 0.2f) * (float)S->sine[(int)v->vibrato_phase % SINE_SIZE] * Q15;
}

static void compute_grain(const mk_t *S, mk_voice_t *v)
{
    float fs = v->current_voice * 0.5f + 0.75f, k[NUM_FORMANTS], asp = v->aspiration_amp * Q15;
    const int16_t *e0 = S->env[0], *e1 = S->env[1], *e2 = S->env[2], *sn = S->sine, *as = S->asp;
    float *g = v->grain;
    int f;
    uint32_t i;
    for (f = 0; f < NUM_FORMANTS; f++)          /* sine-table steps per sample */
        k[f] = lookup_formant(f, v->current_vowel) * fs * ((float)SINE_SIZE / MK_FS);
    for (i = 0; i < GRAIN_LEN; i++) {
        float fi = (float)i;
        g[i] = ((float)sn[(uint32_t)(fi * k[0]) & (SINE_SIZE - 1)] * (float)e0[i] +
                (float)sn[(uint32_t)(fi * k[1]) & (SINE_SIZE - 1)] * (float)e1[i] +
                (float)sn[(uint32_t)(fi * k[2]) & (SINE_SIZE - 1)] * (float)e2[i]) * (Q15 * Q15) +
               (float)as[i] * asp;
    }
    v->g_vowel = v->current_vowel;
    v->g_voice = v->current_voice;
    v->g_asp = v->aspiration_amp;
    v->grain_dirty = 0;
}

static void overlap_add(mk_voice_t *v)
{
    uint32_t s, i, n1;
    s = v->overlap_write_pos + v->overlap_offset;
    while (s >= OLAP)
        s -= OLAP;
    v->overlap_write_pos = s;
    n1 = OLAP - s < GRAIN_LEN ? OLAP - s : GRAIN_LEN;
    for (i = 0; i < n1; i++)
        v->overlap_buf[s + i] += v->grain[i];
    for (; i < GRAIN_LEN; i++)
        v->overlap_buf[i - n1] += v->grain[i];
}

static void voice_init(mk_voice_t *v, int i)
{
    v->active = 0;
    v->current_pitch = v->target_pitch = 57.0f;   /* 220 Hz */
    v->random_jitter = 4.0f;
    v->jitter_period = 4586;
    v->rng_state = 12345u + (uint32_t)i * 7919u;  /* staggered: unison voices are separate singers */
    v->vibrato_phase = (float)(SINE_SIZE * i) / MAX_UNISON;
    v->vibrato_rate = 0.5f;
    v->rate_scale = 1.0f;
    v->ramp_period = (int)(MK_FS * 0.01f);
    v->ramp_counter = v->ramp_period;
    v->current_vowel = v->target_vowel = 0.5f;
    v->current_voice = 0.5f;
    v->aspiration_amp = 0.5f;
    v->grain_dirty = 1;
    v->g_vowel = -1.0f;
    v->last_step = 0x7FFFFFFF;
    v->env_stage = ENV_IDLE;
    v->env_sustain = 1.0f;
}

static int has_env(const mk_voice_t *v)
{
    return v->env_attack > 0.0f || v->env_decay > 0.0f || v->env_sustain < 1.0f || v->env_release > 0.0f;
}

static void voice_note_on(mk_voice_t *v, float note)
{
    uint8_t was = v->active;
    v->active = 1;
    v->target_pitch = note;
    if (!was) {
        v->current_pitch = note;
        v->current_vowel = v->target_vowel;   /* start on the vowel, not where the last note left it */
        v->vowel_ramp_ticks = 0;
        v->grain_dirty = 1;
        v->overlap_write_pos = v->overlap_read_pos;   /* the buffer drains by itself: no pop */
        v->overlap_offset = 0;
    }
    if (has_env(v)) {
        v->env_stage = ENV_ATTACK;            /* from where it is: no click on a retrigger */
    } else {
        v->env_level = 1.0f;
        v->env_stage = ENV_SUSTAIN;
    }
}

static void voice_note_off(mk_voice_t *v)
{
    if (has_env(v)) {
        v->env_stage = ENV_RELEASE;
    } else {
        v->active = 0;
        v->env_stage = ENV_IDLE;
        v->env_level = 0.0f;
    }
}

static int voice_is_active(const mk_voice_t *v) { return v->active || v->env_stage == ENV_RELEASE; }

static void voice_set_pitch_direct(mk_voice_t *v, float note) { v->target_pitch = v->current_pitch = note; }

static void voice_set_vowel(mk_voice_t *v, float vowel)
{
    float t = clamp01(vowel), eff = v->glide_param > v->min_glide ? v->glide_param : v->min_glide;
    if (eff < 0.001f) {
        v->current_vowel = t;
        v->vowel_ramp_ticks = 0;
    } else {
        int n = RAMP_TICKS;
        if (eff > 0.5f)
            n = RAMP_TICKS + (int)((eff - 0.5f) * 180.0f);
        v->vowel_step = (t - v->current_vowel) / (float)n;
        v->vowel_ramp_ticks = n;
    }
    v->target_vowel = t;
}

static float voice_amplitude(const mk_voice_t *v)   /* upstream's pitch compensation */
{
    return clampf((v->current_pitch - 12.0f) * (-1.0f / 72.0f) + 2.0f, 0.1f, 3.0f);
}

static void voice_process(const mk_t *S, mk_voice_t *v, float *out, uint32_t n)
{
    int env = has_env(v) || v->env_stage == ENV_RELEASE;
    uint32_t i;
    for (i = 0; i < n; i++) {
        if (v->active || v->env_stage == ENV_RELEASE) {
            float pitch;
            uint32_t period;
            apply_portamento(v);
            pitch = v->current_pitch + v->pitch_bend_offset + compute_vibrato(S, v);
            period = grain_period(S, v, pitch);
            if (v->overlap_offset >= period || v->grain_dirty) {
                if (v->grain_dirty || v->current_vowel != v->g_vowel || v->current_voice != v->g_voice ||
                    v->aspiration_amp != v->g_asp)
                    compute_grain(S, v);
                overlap_add(v);
                v->overlap_offset = 0;
            }
        }
        v->overlap_offset++;
    }
    for (i = 0; i < n; i++) {
        uint32_t r = v->overlap_read_pos;
        float s = v->overlap_buf[r];
        v->overlap_buf[r] = 0.0f;
        v->overlap_read_pos = r + 1u < OLAP ? r + 1u : 0u;
        if (env)
            s *= env_tick(v);
        out[i] += s;
    }
}

/* ------------------------------------------------------------------- synth */
static float detuned(const mk_t *S, float base, int i, int n)
{
    if (n <= 1)
        return base;
    return base + S->unison_detune * ((float)i / (float)(n - 1) * 2.0f - 1.0f) * 0.01f;   /* cents */
}

static void apply_voice_spread(mk_t *S)
{
    int n = S->unison_count, i;
    for (i = 0; i < n; i++) {
        float off = n > 1 ? S->unison_voice_spread * ((float)i / (float)(n - 1) * 2.0f - 1.0f) : 0.0f;
        S->v[i].current_voice = clamp01(S->base_voice + off);
    }
}

static void apply_unison(mk_t *S, float base)
{
    int n = S->unison_count, i;
    S->last_base_note = base;
    for (i = 0; i < n; i++)
        voice_note_on(&S->v[i], detuned(S, base, i, n));
}

static void remove_note(mk_t *S, uint8_t note)
{
    uint32_t i, j = 0;
    for (i = 0; i < S->held_count; i++)
        if (S->held[i] != note)
            S->held[j++] = S->held[i];
    S->held_count = (uint8_t)j;
}

static void synth_note_on(mk_t *S, uint8_t note)
{
    int i;
    for (i = 0; i < MAX_UNISON; i++)
        S->v[i].min_glide = 0.0f;
    remove_note(S, note);
    if (S->held_count < MAX_NOTES)
        S->held[S->held_count++] = note;
    apply_unison(S, (float)note);
}

static void synth_note_off(mk_t *S, uint8_t note)
{
    int i;
    remove_note(S, note);
    if (S->held_count) {
        apply_unison(S, (float)S->held[S->held_count - 1u]);
    } else {
        for (i = 0; i < MAX_UNISON; i++)
            voice_note_off(&S->v[i]);
    }
}

static void synth_set_unison(mk_t *S, int count)
{
    int old = S->unison_count, i;
    count = count < 1 ? 1 : count > MAX_UNISON ? MAX_UNISON : count;
    S->unison_count = count;
    S->target_gain = fm_rsqrtf((float)count);
    if (old == count || !voice_is_active(&S->v[0]))
        return;
    for (i = count; i < old; i++)                  /* fade the ones let go (the 3 ms anti-click) */
        S->v[i].env_stage = ENV_RELEASE;
    for (i = 0; i < count && i < old; i++)
        voice_set_pitch_direct(&S->v[i], detuned(S, S->last_base_note, i, count));
    for (i = old; i < count; i++)
        voice_note_on(&S->v[i], detuned(S, S->last_base_note, i, count));
    apply_voice_spread(S);
}

static void synth_set_detune(mk_t *S, float cents)
{
    int n = S->unison_count, i;
    S->unison_detune = cents;
    if (voice_is_active(&S->v[0]) && n > 1)
        for (i = 0; i < n; i++)
            voice_set_pitch_direct(&S->v[i], detuned(S, S->last_base_note, i, n));
}

#define ALLV(stmt)                                                                                      \
    do {                                                                                                \
        int _i;                                                                                         \
        for (_i = 0; _i < MAX_UNISON; _i++) {                                                           \
            mk_voice_t *v = &S->v[_i];                                                                  \
            stmt;                                                                                       \
        }                                                                                               \
    } while (0)

/* a parameter into the engine, with the iOS port's curves (RenderContext.swift) */
static void engine_param(mk_t *S, int id, float x)
{
    switch (id) {
    case P_GLIDE: ALLV(v->glide_param = x); break;
    case P_HEAD: S->base_voice = x; apply_voice_spread(S); break;
    case P_VIBRATO: ALLV(v->vibrato_depth = clamp01(x)); break;
    case P_RATE: ALLV(v->vibrato_rate = clamp01(x); v->rate_scale = fm_exp2f((v->vibrato_rate * 2.0f - 1.0f) * 2.0f)); break;
    case P_BREATH: ALLV(v->aspiration_amp = clamp01(x)); break;
    case P_ATTACK: ALLV(v->env_attack = x * 5.0f); break;
    case P_DECAY: ALLV(v->env_decay = x * 5.0f); break;
    case P_SUSTAIN: ALLV(v->env_sustain = clamp01(x)); break;
    case P_RELEASE: ALLV(v->env_release = x * 5.0f); break;
    case P_VOICES: synth_set_unison(S, (int)(x + 0.5f)); break;
    case P_DETUNE: synth_set_detune(S, x * 50.0f); break;
    case P_LEVEL: S->level = x; break;
    case P_SPREAD: S->unison_voice_spread = x * 0.5f; apply_voice_spread(S); break;
    default: break;                                /* vowel, tune, press, route, depth, velsens: the wrapper's */
    }
}

/* ------------------------------------------------ the wrapper: slew, pressure, velocity */
static float vel_gain_of(const mk_t *S, float vel)
{
    float vs = S->p[P_VELSENS];
    return (1.0f - vs) + vs * vel * vel * 1.6f;     /* 1.6: a medium press (~100) keeps the level */
}

static float combined_vowel(const mk_t *S)
{
    float d = S->cur[P_PRESS] * S->p[P_DEPTH], v = S->cur[P_VOWEL];
    switch ((int)(S->p[P_ROUTE] + 0.5f)) {
    case AT_BOTH_INV: return clamp01(v - d);
    case AT_PITCH: return v;
    default: return clamp01(v + d);
    }
}

static void apply_bend(mk_t *S)
{
    float b = ((int)(S->p[P_ROUTE] + 0.5f) == AT_VOWEL ? 0.0f : S->cur[P_PRESS] * BEND_RANGE) +
              (S->cur[P_TUNE] - 0.5f) * 24.0f;
    if (b != S->bend_cur) {
        S->bend_cur = b;
        ALLV(v->pitch_bend_offset = clampf(b, -12.0f, 12.0f));
    }
}

static void init(void *st, float sr)
{
    mk_t *S = st;
    int i;
    (void)sr;                                      /* (44.1 kHz: the tables are sized for it) */
    build_tables(S);
    for (i = 0; i < MAX_UNISON; i++)
        voice_init(&S->v[i], i);
    S->unison_count = 1;
    S->cur_gain = S->target_gain = 1.0f;
    S->level = 1.0f;
    S->base_voice = 0.5f;
    S->vel_gain = S->vel_target = 1.0f;
    S->bend_cur = 1e9f;
    for (i = 0; i < NP; i++) {
        S->p[i] = S->cur[i] = P[i].def;
        engine_param(S, i, P[i].def);
    }
    ALLV(voice_set_vowel(v, 0.5f));
    apply_bend(S);
}

static void set(void *st, int k, float x)
{
    mk_t *S = st;
    S->p[k] = x;
    if (!SMOOTH[k]) {
        S->cur[k] = x;
        engine_param(S, k, x);
    }
}

static void note(void *st, int n, float vel)
{
    mk_t *S = st;
    if (n < 0 || n > 127)
        return;
    if (vel > 0.0f) {
        S->vel_target = vel_gain_of(S, vel);
        if (!S->held_count)
            S->vel_gain = S->vel_target;           /* a new phrase starts at its own level */
        synth_note_on(S, (uint8_t)n);
    } else
        synth_note_off(S, (uint8_t)n);
}

/* once a block, before the parts: the knobs' slew, the vowel and the bend, this block's gain */
static void begin(void *st, int n)
{
    mk_t *S = st;
    int i;
    float g1;
    for (i = 0; i < NP; i++) {
        float d;
        if (!SMOOTH[i])
            continue;
        d = S->p[i] - S->cur[i];
        if (d == 0.0f)
            continue;
        S->cur[i] = (d > -SLEW_SNAP && d < SLEW_SNAP) ? S->p[i] : S->cur[i] + d * SLEW_COEF;
        engine_param(S, i, S->cur[i]);
    }
    {
        float vw = combined_vowel(S);
        if (vw != S->v[0].target_vowel)
            ALLV(voice_set_vowel(v, vw));
    }
    apply_bend(S);
    S->vel_gain += (S->vel_target - S->vel_gain) * 0.2f;
    /* the output gain (MONK-1's: unison, pitch compensation, its volume 0.1, level, velocity), ramped over the block */
    g1 = S->target_gain * voice_amplitude(&S->v[0]) * 0.1f * S->level * S->vel_gain;
    S->g0 = S->cur_gain;
    S->gstep = (g1 - S->g0) / (float)n;
    S->cur_gain = g1;
}

/* the even (part 0) or odd (part 1) unison voices, on both sides */
static void process_part(void *st, float *l, float *r, int n, int part)
{
    mk_t *S = st;
    float *m = S->mono[part], g = S->g0;
    int i, k, any = 0;
    for (k = part; k < MAX_UNISON; k += 2) {
        if (k >= S->unison_count && !voice_is_active(&S->v[k]))
            continue;
        if (!any) {
            for (i = 0; i < n; i++)
                m[i] = 0.0f;
            any = 1;
        }
        voice_process(S, &S->v[k], m, (uint32_t)n);
    }
    if (!any)
        return;
    for (i = 0; i < n; i++) {
        float x = m[i] * g;
        l[i] += x;
        r[i] += x;
        g += S->gstep;
    }
}

static void process(void *st, float *l, float *r, int n)
{
    process_part(st, l, r, n, 0);
    process_part(st, l, r, n, 1);
}

static const rc_desc_t D = {RC_MAGIC, RC_ABI, "monk", sizeof(mk_t), 0, 1, NP, P, init, set, note, process,
                            2, {0}, process_part, begin};
RC_EXPORT(D)
