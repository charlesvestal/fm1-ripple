/* SPDX-License-Identifier: MIT
 * Copyright (C) 2026 Charles Vestal */
/* What Heavy's runtime needs of a C library, for a Ripple current made from a Pd patch: string and memory routines,
 * and memory from the current's arena. The current (sdk/tools/currents.py's wrapper) points rc_hv_arena at the
 * arena in its state before it builds the patch; Heavy takes what it needs then, and a little more later (message
 * queue nodes), and never gives it back: the arena goes with the current. */
#include "HvUtils.h"

typedef struct { char *base; size_t size, used, peak_fail; } rc_hv_arena_t;
rc_hv_arena_t *rc_hv_arena;

void *rc_hv_malloc(size_t n)
{
    rc_hv_arena_t *a = rc_hv_arena;
    size_t at = (a->used + 7u) & ~(size_t)7u;
    if (at + n > a->size) {
        a->peak_fail = at + n;
        return 0;
    }
    a->used = at + n;
    return a->base + at;
}

void *rc_hv_realloc(void *p, size_t n)
{
    void *q = rc_hv_malloc(n);
    if (q && p) {
        /* (a table grows: copy what the old block can hold; the arena knows no block sizes, so copy up to the
         * old end of the arena) */
        size_t room = (size_t)(rc_hv_arena->base + rc_hv_arena->used - n - (char *)p);
        rc_hv_memcpy(q, p, room < n ? room : n);
    }
    return q;
}

size_t rc_hv_strlen(const char *s) { size_t n = 0; while (s[n]) n++; return n; }

int rc_hv_strcmp(const char *a, const char *b)
{
    while (*a && *a == *b) a++, b++;
    return (unsigned char)*a - (unsigned char)*b;
}

char *rc_hv_strncpy(char *d, const char *s, size_t n)
{
    size_t i = 0;
    for (; i < n && s[i]; i++) d[i] = s[i];
    for (; i < n; i++) d[i] = 0;
    return d;
}

void *rc_hv_memcpy(void *d, const void *s, size_t n)
{
    char *o = d;
    const char *i = s;
    while (n--) *o++ = *i++;
    return d;
}

void *rc_hv_memset(void *d, int c, size_t n)
{
    char *o = d;
    while (n--) *o++ = (char)c;
    return d;
}

int rc_hv_snprintf(char *s, size_t n)
{
    if (s && n) s[0] = 0;
    return 0;
}

float rc_hv_va_double(uint64_t b)
{
    uint32_t sign = (uint32_t)(b >> 63) << 31;
    int32_t e = (int32_t)((b >> 52) & 0x7FF);
    uint32_t m = (uint32_t)(b >> 29) & 0x7FFFFF;
    union { uint32_t u; float f; } r;
    if (e == 0) r.u = sign;                                 /* zero (and doubles too small for a float) */
    else if (e == 0x7FF) r.u = sign | 0x7F800000u | m;      /* infinity, NaN */
    else {
        e = e - 1023 + 127;
        if (e >= 255) r.u = sign | 0x7F800000u;
        else if (e <= 0) r.u = sign;
        else r.u = sign | (uint32_t)e << 23 | m;
    }
    return r.f;
}

/* nothing calls a pure virtual function: Heavy's classes are always whole */
void __cxa_pure_virtual(void) { for (;;) {} }
