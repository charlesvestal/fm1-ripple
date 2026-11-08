/**
 * Copyright (c) 2014-2018 Enzien Audio Ltd.
 * Copyright (C) 2026 Charles Vestal (the Ripple current's version)
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/* Heavy's HvUtils.h for a Ripple current (sdk/tools/currents.py puts it in place of hvcc's): no C library, no
 * SIMD, no atomics (set and note never run during the render), the maths from fastmath.h through faust_shim.h, and
 * memory from the current's own arena (heavy_shim.c: rc_hv_malloc). */
#ifndef _HEAVY_UTILS_H_
#define _HEAVY_UTILS_H_

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "faust_shim.h"

#define hv_uint8_t uint8_t
#define hv_int16_t int16_t
#define hv_uint16_t uint16_t
#define hv_int32_t int32_t
#define hv_uint32_t uint32_t
#define hv_uint64_t uint64_t
#define hv_size_t size_t
#define hv_uintptr_t uintptr_t

#define HV_SIMD_NONE 1
#define HV_N_SIMD 1
#define hv_bufferf_t float
#define hv_bufferi_t int
#define hv_bInf_t float
#define hv_bOutf_t float*
#define hv_bIni_t int
#define hv_bOuti_t int*
#define VIf(_x) (_x)
#define VOf(_x) (&_x)
#define VIi(_x) (_x)
#define VOi(_x) (&_x)
#define HV_N_SIMD_MASK (HV_N_SIMD-1)

#ifdef __cplusplus
extern "C" {
#endif
void *rc_hv_malloc(size_t n);
void *rc_hv_realloc(void *p, size_t n);
size_t rc_hv_strlen(const char *s);
int rc_hv_strcmp(const char *a, const char *b);
char *rc_hv_strncpy(char *d, const char *s, size_t n);
void *rc_hv_memcpy(void *d, const void *s, size_t n);
void *rc_hv_memset(void *d, int c, size_t n);
float rc_hv_va_double(uint64_t bits);
int rc_hv_snprintf(char *s, size_t n);
hv_uint32_t hv_string_to_hash(const char *str);
#ifdef __cplusplus
}
#endif

#define memset rc_hv_memset                             /* (a few of Heavy's files call these by name) */
#define memcpy rc_hv_memcpy
#define hv_strlen(a) rc_hv_strlen(a)
#define hv_strcmp(a, b) rc_hv_strcmp(a, b)
#define hv_snprintf(a, b, c, ...) rc_hv_snprintf(a, b)  /* no text formatting: [print] says nothing */
#define hv_strncpy(_dst, _src, _len) rc_hv_strncpy(_dst, _src, _len)
#define hv_memcpy(a, b, c) rc_hv_memcpy(a, b, c)
#define hv_memclear(a, b) rc_hv_memset(a, 0, b)
#define hv_alloca(_n) __builtin_alloca(_n)
#define hv_malloc(_n) rc_hv_malloc(_n)
#define hv_realloc(a, b) rc_hv_realloc(a, b)
#define hv_free(x) ((void)(x))                          /* the arena goes with the current */
#define hv_assert(e) ((void)0)
/* a float passed through "..." arrives as a double: its bits, made a float without a double operation */
#define RC_HV_VA_FLOAT(ap) rc_hv_va_double(va_arg(ap, uint64_t))

#define HV_EXPORT
#define HV_FORCE_INLINE inline __attribute__((always_inline))

static inline hv_size_t __hv_utils_max_ui(hv_size_t x, hv_size_t y) { return (x > y) ? x : y; }
static inline hv_size_t __hv_utils_min_ui(hv_size_t x, hv_size_t y) { return (x < y) ? x : y; }
static inline hv_int32_t __hv_utils_max_i(hv_int32_t x, hv_int32_t y) { return (x > y) ? x : y; }
static inline hv_int32_t __hv_utils_min_i(hv_int32_t x, hv_int32_t y) { return (x < y) ? x : y; }
static inline float rc_hv_fmaf(float a, float b, float c) { return a * b + c; }
static inline float rc_hv_cbrtf(float x) { return x < 0.0f ? -fm_powf(-x, 1.0f / 3.0f) : x > 0.0f ? fm_powf(x, 1.0f / 3.0f) : 0.0f; }
static inline float rc_hv_copysignf(float a, float b) { return (b < 0.0f) != (a < 0.0f) ? -a : a; }
static inline float rc_hv_expm1f(float x) { return fm_expf(x) - 1.0f; }
static inline float rc_hv_log1pf(float x) { return rc_logf(1.0f + x); }
static inline float rc_hv_ldexpf(float x, int e) { return x * fm_exp2f((float)e); }
static inline float rc_hv_erff(float x)             /* Abramowitz and Stegun 7.1.26 */
{
    float t = 1.0f / (1.0f + 0.3275911f * fm_fabsf(x));
    float y = 1.0f - t * (0.254829592f + t * (-0.284496736f + t * (1.421413741f + t * (-1.453152027f + t * 1.061405429f))))
                     * fm_expf(-x * x);
    return x < 0.0f ? -y : y;
}
static inline float rc_hv_asinhf(float x) { return rc_logf(x + fm_sqrtf(x * x + 1.0f)); }
static inline float rc_hv_acoshf(float x) { return rc_logf(x + fm_sqrtf(x * x - 1.0f)); }
static inline float rc_hv_atanhf(float x) { return 0.5f * rc_logf((1.0f + x) / (1.0f - x)); }
static inline float rc_hv_modff(float x, float *ip)
{
    float t = fm_fabsf(x) < 8388608.0f ? (float)(int32_t)x : x;
    *ip = t;
    return x - t;
}
#define modff rc_hv_modff
#ifndef INFINITY
#define INFINITY __builtin_inff()
#endif
static inline int rc_hv_isnan(float x) { return x != x; }
static inline int rc_hv_isinf(float x) { return x == x && x - x != 0.0f; }

#define hv_max_ui(a, b) __hv_utils_max_ui(a, b)
#define hv_min_ui(a, b) __hv_utils_min_ui(a, b)
#define hv_max_i(a, b) __hv_utils_max_i(a, b)
#define hv_min_i(a, b) __hv_utils_min_i(a, b)
#define hv_max_f(a, b) fm_maxf(a, b)
#define hv_min_f(a, b) fm_minf(a, b)
#define hv_max_d(a, b) fm_maxf(a, b)
#define hv_min_d(a, b) fm_minf(a, b)
#define hv_sin_f(a) fm_sinf(a)
#define hv_sinh_f(a) rc_sinhf(a)
#define hv_cos_f(a) fm_cosf(a)
#define hv_cosh_f(a) rc_coshf(a)
#define hv_tan_f(a) fm_tanf(a)
#define hv_tanh_f(a) fm_tanhf(a)
#define hv_asin_f(a) rc_asinf(a)
#define hv_asinh_f(a) rc_hv_asinhf(a)
#define hv_acos_f(a) rc_acosf(a)
#define hv_acosh_f(a) rc_hv_acoshf(a)
#define hv_atan_f(a) rc_atanf(a)
#define hv_atanh_f(a) rc_hv_atanhf(a)
#define hv_atan2_f(a, b) rc_atan2f(a, b)
#define hv_exp_f(a) fm_expf(a)
#define hv_abs_f(a) fm_fabsf(a)
#define hv_sqrt_f(a) rc_sqrtf(a)
#define hv_log_f(a) rc_logf(a)
#define hv_ceil_f(a) rc_ceilf(a)
#define hv_floor_f(a) rc_floorf(a)
#define hv_round_f(a) rc_roundf(a)
#define hv_pow_f(a, b) fm_powf(a, b)
#define hv_fma_f(a, b, c) rc_hv_fmaf(a, b, c)
#define hv_min_max_log2(a) ((hv_uint32_t) (32 - __builtin_clz((a)-1)))
#define hv_if_f(a, b, c) ((a) ? (b) : (c))
#define hv_modf_f(a) rc_fmodf(a, 1.0f)
#define hv_cbrt_f(a) rc_hv_cbrtf(a)
#define hv_copysign_f(a, b) rc_hv_copysignf(a, b)
#define hv_remainder_f(a, b) rc_remainderf(a, b)
#define hv_erf_f(a) rc_hv_erff(a)
#define hv_erfc_f(a) (1.0f - rc_hv_erff(a))
#define hv_expm1_f(a) rc_hv_expm1f(a)
#define hv_finite_f(a) (!rc_hv_isnan(a) && !rc_hv_isinf(a))
#define hv_fmod_f(a, b) rc_fmodf(a, b)
#define hv_ldexp_f(a, b) rc_hv_ldexpf(a, b)
#define hv_isinf_f(a) rc_hv_isinf(a)
#define hv_isnan_f(a) rc_hv_isnan(a)
#define hv_ln_f(a) rc_logf(a)
#define hv_log10_f(a) rc_log10f(a)
#define hv_log1p_f(a) rc_hv_log1pf(a)
#define hv_rint_f(a) rc_rintf(a)
#define hv_shl_i(a, b) ((a) << (b))
#define hv_shr_i(a, b) ((a) >> (b))
#define hv_bit_not_i(a) ~a
#define hv_not_f(a) !a

#define hv_atomic_bool volatile bool
#define HV_SPINLOCK_ACQUIRE(_x) (_x = true)
#define HV_SPINLOCK_TRY(_x) return (_x = true)
#define HV_SPINLOCK_RELEASE(_x) (_x = false)

#endif // _HEAVY_UTILS_H_
