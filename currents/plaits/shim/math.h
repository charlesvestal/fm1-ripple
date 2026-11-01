/* SPDX-License-Identifier: MIT */
/* LOOM-8: the freestanding <math.h> the Plaits units see (shim/ comes first on their include path). The
 * firmware links no libm and its FPU is single precision: the few functions Plaits calls are mapped onto
 * fastmath.h's float versions. Nothing here takes or returns a double. */
#pragma once
#include "fastmath.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846   /* only ever used as float(M_PI) or folded at compile time */
#endif

static inline float fabsf(float x) { return fm_fabsf(x); }
static inline float sqrtf(float x) { return fm_sqrtf(x); }
static inline float sinf(float x) { return fm_sinf(x); }
static inline float cosf(float x) { return fm_cosf(x); }
static inline float tanf(float x) { return fm_tanf(x); }
