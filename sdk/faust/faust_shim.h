/* SPDX-License-Identifier: MIT
 * Copyright (C) 2026 Charles Vestal */
/* What Faust's C output (faust -lang c -single) needs, for a Ripple current: its maths from fastmath.h (no libm on
 * the FM-1), no allocation (the firmware hands the state), and the UI glue types the generated code calls through.
 * sdk/tools/faust2cur.py puts this in place of the generated file's <math.h> and <stdlib.h>. */
#ifndef RIPPLE_FAUST_SHIM_H
#define RIPPLE_FAUST_SHIM_H
#include <stdint.h>
#include "fastmath.h"

static inline float rc_fmodf(float a, float b)
{
    float q = a / b;
    float t = (float)(int32_t)q;
    return a - t * b;
}
static inline float rc_floorf(float x)
{
    float t;
    if (!(fm_fabsf(x) < 8388608.0f)) return x;
    t = (float)(int32_t)x;
    return t > x ? t - 1.0f : t;
}
static inline float rc_ceilf(float x) { return -rc_floorf(-x); }
static inline float rc_roundf(float x) { return x < 0.0f ? -rc_floorf(-x + 0.5f) : rc_floorf(x + 0.5f); }
static inline float rc_rintf(float x) { return rc_roundf(x); }
static inline float rc_log10f(float x) { return fm_log2f(x) * 0.30103f; }
static inline float rc_exp10f(float x) { return fm_exp2f(x * 3.3219281f); }
static inline float rc_atanf(float x)
{
    float ax = fm_fabsf(x), r, z;
    int inv = ax > 1.0f;
    if (inv) ax = 1.0f / ax;
    z = ax * ax;
    r = ax * (0.99997726f + z * (-0.33262347f + z * (0.19354346f + z * (-0.11643287f + z * (0.05265332f + z * -0.01172120f)))));
    if (inv) r = 1.5707963f - r;
    return x < 0.0f ? -r : r;
}
static inline float rc_atan2f(float y, float x)
{
    if (x > 0.0f) return rc_atanf(y / x);
    if (x < 0.0f) return y >= 0.0f ? rc_atanf(y / x) + 3.1415927f : rc_atanf(y / x) - 3.1415927f;
    return y > 0.0f ? 1.5707963f : y < 0.0f ? -1.5707963f : 0.0f;
}
static inline float rc_asinf(float x) { return rc_atan2f(x, fm_sqrtf(1.0f - x * x)); }
static inline float rc_acosf(float x) { return rc_atan2f(fm_sqrtf(1.0f - x * x), x); }
static inline float rc_sqrtf(float x) { return x > 0.0f ? fm_sqrtf(x) : 0.0f; }
static inline float rc_logf(float x) { return x > 0.0f ? fm_logf(x) : -87.0f; }
static inline float rc_log2f(float x) { return x > 0.0f ? fm_log2f(x) : -126.0f; }
static inline float rc_sinhf(float x) { float e = fm_expf(x); return 0.5f * (e - 1.0f / e); }
static inline float rc_coshf(float x) { float e = fm_expf(x); return 0.5f * (e + 1.0f / e); }
static inline float rc_remainderf(float a, float b) { return a - b * rc_roundf(a / b); }

#define sinf fm_sinf
#define cosf fm_cosf
#define tanf fm_tanf
#define expf fm_expf
#define exp2f fm_exp2f
#define powf fm_powf
#define tanhf fm_tanhf
#define fabsf fm_fabsf
#define fminf fm_minf
#define fmaxf fm_maxf
#define sqrtf rc_sqrtf
#define logf rc_logf
#define log2f rc_log2f
#define log10f rc_log10f
#define exp10f rc_exp10f
#define floorf rc_floorf
#define ceilf rc_ceilf
#define roundf rc_roundf
#define rintf rc_rintf
#define fmodf rc_fmodf
#define remainderf rc_remainderf
#define atanf rc_atanf
#define atan2f rc_atan2f
#define asinf rc_asinf
#define acosf rc_acosf
#define sinhf rc_sinhf
#define coshf rc_coshf
#define calloc(n, s) ((void *)0)        /* new*(): not used (the firmware hands the state) */
#define free(p) ((void)(p))

/* Faust's C UI glue: the generated buildUserInterface calls these by name */
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif
typedef struct {
    void *uiInterface;
    void (*openTabBox)(void *, const char *);
    void (*openHorizontalBox)(void *, const char *);
    void (*openVerticalBox)(void *, const char *);
    void (*closeBox)(void *);
    void (*addButton)(void *, const char *, FAUSTFLOAT *);
    void (*addCheckButton)(void *, const char *, FAUSTFLOAT *);
    void (*addVerticalSlider)(void *, const char *, FAUSTFLOAT *, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT);
    void (*addHorizontalSlider)(void *, const char *, FAUSTFLOAT *, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT);
    void (*addNumEntry)(void *, const char *, FAUSTFLOAT *, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT, FAUSTFLOAT);
    void (*addHorizontalBargraph)(void *, const char *, FAUSTFLOAT *, FAUSTFLOAT, FAUSTFLOAT);
    void (*addVerticalBargraph)(void *, const char *, FAUSTFLOAT *, FAUSTFLOAT, FAUSTFLOAT);
    void (*addSoundfile)(void *, const char *, const char *, void **);
    void (*declare)(void *, FAUSTFLOAT *, const char *, const char *);
} UIGlue;
typedef struct {
    void *metaInterface;
    void (*declare)(void *, const char *, const char *);
} MetaGlue;

#endif
