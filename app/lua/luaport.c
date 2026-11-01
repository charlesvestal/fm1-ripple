/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* What Lua needs from a C library, in float and small (luaport.h): number formatting and parsing, maths, the few
 * string functions it calls, and a stdio over the disk (disk.h) for loadfile / require. Included by lua_one.c. */
#include <stddef.h>
#include <stdint.h>
#include "fastmath.h"
#include "disk.h"

float lp_ldexp(float x, int e);

/* ------------------------------------------------------------------ format --- */
typedef struct {
    int left, plus, space, zero, alt, width, prec;
    char conv;
} spec_t;

static const char *spec_parse(const char *f, spec_t *sp)
{
    sp->left = sp->plus = sp->space = sp->zero = sp->alt = 0;
    sp->width = 0;
    sp->prec = -1;
    while (*f && *f != '%')
        f++;
    if (*f == '%')
        f++;
    for (;; f++) {
        if (*f == '-') sp->left = 1;
        else if (*f == '+') sp->plus = 1;
        else if (*f == ' ') sp->space = 1;
        else if (*f == '0') sp->zero = 1;
        else if (*f == '#') sp->alt = 1;
        else break;
    }
    while (*f >= '0' && *f <= '9')
        sp->width = sp->width * 10 + (*f++ - '0');
    if (*f == '.') {
        f++;
        sp->prec = 0;
        while (*f >= '0' && *f <= '9')
            sp->prec = sp->prec * 10 + (*f++ - '0');
    }
    while (*f == 'l' || *f == 'h')
        f++;
    sp->conv = *f;
    return f;
}

/* body (sign excluded) padded to the spec into b; returns the length it wanted */
static int emit(char *b, size_t sz, const spec_t *sp, char sign, const char *body, int n)
{
    int len = n + (sign ? 1 : 0), pad = sp->width > len ? sp->width - len : 0, o = 0, i;
    char t[160];
    if (!sp->left && !sp->zero)
        for (i = 0; i < pad && o < 159; i++) t[o++] = ' ';
    if (sign && o < 159) t[o++] = sign;
    if (!sp->left && sp->zero)
        for (i = 0; i < pad && o < 159; i++) t[o++] = '0';
    for (i = 0; i < n && o < 159; i++) t[o++] = body[i];
    if (sp->left)
        for (i = 0; i < pad && o < 159; i++) t[o++] = ' ';
    t[o] = 0;
    if (sz) {
        size_t k = (size_t)o < sz - 1 ? (size_t)o : sz - 1;
        for (i = 0; i < (int)k; i++) b[i] = t[i];
        b[k] = 0;
    }
    return o;
}

static int utoa_base(uint32_t u, unsigned base, int upper, char *d)
{
    char t[12];
    int n = 0, i;
    const char *dig = upper ? "0123456789ABCDEF" : "0123456789abcdef";
    do t[n++] = dig[u % base]; while ((u /= base));
    for (i = 0; i < n; i++) d[i] = t[n - 1 - i];
    return n;
}

int lp_fmti(char *b, size_t sz, const char *fmt, int v)
{
    spec_t sp;
    char body[40], sign = 0;
    int n = 0;
    spec_parse(fmt, &sp);
    if (sp.conv == 'c') {
        body[0] = (char)v;
        return emit(b, sz, &sp, 0, body, 1);
    }
    if (sp.conv == 'd' || sp.conv == 'i') {
        uint32_t u = v < 0 ? 0u - (uint32_t)v : (uint32_t)v;
        sign = v < 0 ? '-' : sp.plus ? '+' : sp.space ? ' ' : 0;
        n = utoa_base(u, 10, 0, body);
    } else if (sp.conv == 'x' || sp.conv == 'X') {
        n = utoa_base((uint32_t)v, 16, sp.conv == 'X', body);
    } else if (sp.conv == 'o') {
        n = utoa_base((uint32_t)v, 8, 0, body);
    } else {
        n = utoa_base((uint32_t)v, 10, 0, body);
    }
    if (sp.prec > n) {                      /* precision: at least that many digits */
        int z = sp.prec - n, i;
        for (i = n - 1; i >= 0; i--) body[i + z] = body[i];
        for (i = 0; i < z; i++) body[i] = '0';
        n += z;
    }
    return emit(b, sz, &sp, sign, body, n);
}

int lp_fmts(char *b, size_t sz, const char *fmt, const char *s)
{
    spec_t sp;
    int n = 0;
    spec_parse(fmt, &sp);
    while (s[n] && (sp.prec < 0 || n < sp.prec) && n < 150)
        n++;
    return emit(b, sz, &sp, 0, s, n);
}

int lp_fmtp(char *b, size_t sz, const char *fmt, const void *p)
{
    spec_t sp;
    char body[12] = "0x";
    (void)fmt;
    spec_parse("%s", &sp);
    return emit(b, sz, &sp, 0, body, 2 + utoa_base((uint32_t)(uintptr_t)p, 16, 0, body + 2));
}

static const float P10[] = {1e0f, 1e1f, 1e2f, 1e3f, 1e4f, 1e5f, 1e6f, 1e7f, 1e8f, 1e9f, 1e10f};

static float pow10i(int e)                  /* 10^e in float, e in -45..38 */
{
    float r = 1.0f;
    int neg = e < 0;
    if (neg) e = -e;
    while (e > 10) { r *= 1e10f; e -= 10; }
    r *= P10[e];
    return neg ? 1.0f / r : r;
}

/* the decimal digits of x > 0: d[0..n) with x ~ 0.d * 10^e10 (e10 the exponent of the first digit + 1) */
static int digits(float x, int n, char *d, int *e10)
{
    int e = 0, i;
    uint32_t m;
    float lo = P10[n - 1], hi = P10[n];
    /* scale into [10^(n-1), 10^n) */
    if (x >= hi) {
        while (x >= hi * 1e10f) { x /= 1e10f; e += 10; }
        while (x >= hi) { x /= 10.0f; e++; }
    } else {
        while (x < lo / 1e10f) { x *= 1e10f; e -= 10; }
        while (x < lo) { x *= 10.0f; e--; }
    }
    m = (uint32_t)(x + 0.5f);
    if (m >= (uint32_t)hi) { m /= 10u; e++; }
    for (i = n - 1; i >= 0; i--) { d[i] = (char)('0' + m % 10u); m /= 10u; }
    *e10 = e + n;
    return n;
}

/* %f with prec decimals into body (no sign) */
static int fmt_fixed(float x, int prec, int alt, char *body)
{
    int n = 0, i;
    float scale = pow10i(prec);
    float r = x * scale + 0.5f;
    if (prec > 9 || r >= 4.0e9f) {          /* beyond 32 bits: the digits we have, then zeros */
        char d[9];
        int e10, k;
        digits(x, 8, d, &e10);
        for (k = 0; k < e10 && n < 60; k++) body[n++] = k < 8 ? d[k] : '0';
        if (!n) body[n++] = '0';
        if (prec || alt) body[n++] = '.';
        for (i = 0; i < prec && n < 140; i++) {
            k = e10 + i;
            body[n++] = k >= 0 && k < 8 ? d[k] : '0';
        }
        return n;
    }
    {
        uint32_t v = (uint32_t)r, ip = 0, fp = 0, p10 = 1;
        char t[12];
        for (i = 0; i < prec; i++) p10 *= 10u;
        ip = v / p10;
        fp = v % p10;
        n = utoa_base(ip, 10, 0, body);
        if (prec || alt) body[n++] = '.';
        for (i = prec - 1; i >= 0; i--) { t[i] = (char)('0' + fp % 10u); fp /= 10u; }
        for (i = 0; i < prec; i++) body[n++] = t[i];
    }
    return n;
}

static int fmt_exp(float x, int prec, int upper, int alt, char *body)
{
    char d[10];
    int e10 = 0, n = 0, i, nd = prec + 1 > 9 ? 9 : prec + 1, ex;
    if (x == 0.0f) {
        for (i = 0; i < nd; i++) d[i] = '0';
        e10 = 1;
    } else
        digits(x, nd, d, &e10);
    body[n++] = d[0];
    if (prec || alt) body[n++] = '.';
    for (i = 1; i <= prec; i++) body[n++] = i < nd ? d[i] : '0';
    body[n++] = upper ? 'E' : 'e';
    ex = e10 - 1;
    body[n++] = ex < 0 ? '-' : '+';
    if (ex < 0) ex = -ex;
    if (ex < 10) body[n++] = '0';
    n += utoa_base((uint32_t)ex, 10, 0, body + n);
    return n;
}

int lp_fmtf(char *b, size_t sz, const char *fmt, float v)
{
    spec_t sp;
    char body[160], sign;
    int n = 0, neg;
    union { float f; uint32_t u; } bits;
    spec_parse(fmt, &sp);
    bits.f = v;
    neg = (int)(bits.u >> 31);
    if (neg) v = -v;
    sign = neg ? '-' : sp.plus ? '+' : sp.space ? ' ' : 0;
    if ((bits.u & 0x7F800000u) == 0x7F800000u) {   /* inf, nan */
        const char *s = (bits.u & 0x007FFFFFu) ? "nan" : "inf";
        sp.zero = 0;
        if (sp.conv == 'E' || sp.conv == 'F' || sp.conv == 'G') s = (bits.u & 0x007FFFFFu) ? "NAN" : "INF";
        return emit(b, sz, &sp, (bits.u & 0x007FFFFFu) ? 0 : sign, s, 3);
    }
    if (sp.prec < 0) sp.prec = 6;
    if (sp.conv == 'f' || sp.conv == 'F') {
        n = fmt_fixed(v, sp.prec, sp.alt, body);
    } else if (sp.conv == 'e' || sp.conv == 'E') {
        n = fmt_exp(v, sp.prec, sp.conv == 'E', sp.alt, body);
    } else {                                /* g: the shorter, trailing zeros dropped */
        int p = sp.prec ? sp.prec : 1, e10 = 0, x;
        char d[10];
        if (p > 9) p = 9;
        if (v == 0.0f) e10 = 1;
        else digits(v, p, d, &e10);
        x = e10 - 1;
        if (x < -4 || x >= p)
            n = fmt_exp(v, p - 1, sp.conv == 'G', sp.alt, body);
        else
            n = fmt_fixed(v, p - 1 - x, sp.alt, body);
        if (!sp.alt) {                      /* drop trailing zeros of the fraction */
            int dot = -1, ep = n, i;
            for (i = 0; i < n; i++) {
                if (body[i] == '.') dot = i;
                if (body[i] == 'e' || body[i] == 'E') { ep = i; break; }
            }
            if (dot >= 0) {
                int k = ep;
                while (k > dot + 1 && body[k - 1] == '0') k--;
                if (k == dot + 1) k = dot;
                for (i = ep; i < n; i++) body[k + i - ep] = body[i];
                n = k + n - ep;
            }
        }
    }
    return emit(b, sz, &sp, sign, body, n);
}

float lp_str2num(const char *s, char **end)
{
    const char *p = s;
    float v = 0.0f;
    int neg = 0, any = 0, e = 0, es = 0, en = 0;
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r' || *p == '\f' || *p == '\v')
        p++;
    if (*p == '-' || *p == '+') neg = *p++ == '-';
    if (p[0] == '0' && (p[1] == 'x' || p[1] == 'X')) {   /* hex float: 0x1.8p3 */
        const char *q = p + 2;
        int h;
        p = q;
        for (;; p++) {
            h = *p >= '0' && *p <= '9' ? *p - '0' : *p >= 'a' && *p <= 'f' ? *p - 'a' + 10 :
                *p >= 'A' && *p <= 'F' ? *p - 'A' + 10 : -1;
            if (h >= 0) { v = v * 16.0f + (float)h; e -= es; any = 1; }
            else if (*p == '.' && !es) es = 4;
            else break;
            if (h >= 0 && es) e -= 0;
        }
        if (!any) { if (end) *end = (char *)s; return 0.0f; }
        if (*p == 'p' || *p == 'P') {
            const char *q2 = p + 1;
            int ns = 0;
            if (*q2 == '-' || *q2 == '+') ns = *q2++ == '-';
            if (*q2 >= '0' && *q2 <= '9') {
                while (*q2 >= '0' && *q2 <= '9') en = en * 10 + (*q2++ - '0');
                e += ns ? -en : en;
                p = q2;
            }
        }
        v = lp_ldexp(v, e);
        if (end) *end = (char *)p;
        return neg ? -v : v;
    }
    {
        int dot = 0, nd = 0;
        uint32_t m = 0;
        int scale = 0;
        for (;; p++) {
            if (*p >= '0' && *p <= '9') {
                any = 1;
                if (nd < 9) { m = m * 10u + (uint32_t)(*p - '0'); if (m) nd++; if (dot) scale--; }
                else if (!dot) scale++;
            } else if (*p == '.' && !dot) dot = 1;
            else break;
        }
        if (!any) { if (end) *end = (char *)s; return 0.0f; }
        if (*p == 'e' || *p == 'E') {
            const char *q = p + 1;
            int ns = 0;
            if (*q == '-' || *q == '+') ns = *q++ == '-';
            if (*q >= '0' && *q <= '9') {
                while (*q >= '0' && *q <= '9') { if (en < 1000) en = en * 10 + (*q - '0'); q++; }
                scale += ns ? -en : en;
                p = q;
            }
        }
        v = (float)m;
        if (scale > 38 + 9) v = v ? 1.0f / 0.0f : 0.0f;
        else if (scale < -45 - 9) v = 0.0f;
        else if (scale < -38) v = (v * pow10i(-38)) * pow10i(scale + 38);
        else if (scale) v = scale > 0 ? v * pow10i(scale) : v / pow10i(-scale);
    }
    if (end) *end = (char *)p;
    return neg ? -v : v;
}

/* ------------------------------------------------------------------- maths --- */
float lp_fabs(float x) { return fm_fabsf(x); }
float lp_floor(float x)
{
    float t;
    if (!(fm_fabsf(x) < 8388608.0f)) return x;   /* already whole (or inf / nan) */
    t = (float)(int32_t)x;
    return t > x ? t - 1.0f : t;
}
float lp_ceil(float x) { return -lp_floor(-x); }
float lp_fmod(float a, float b)
{
    float q;
    if (b == 0.0f) return 0.0f / 0.0f;
    q = a / b;
    q = q < 0.0f ? -lp_floor(-q) : lp_floor(q);  /* toward zero */
    return a - q * b;
}
float lp_sqrt(float x) { return x <= 0.0f ? (x == 0.0f ? 0.0f : 0.0f / 0.0f) : fm_sqrtf(x); }
float lp_sin(float x) { return fm_sinf(x); }
float lp_cos(float x) { return fm_cosf(x); }
float lp_tan(float x) { return fm_tanf(x); }
float lp_atan(float x)
{
    /* atan on [-1, 1] by a minimax polynomial; outside, pi/2 - atan(1/x) */
    float ax = fm_fabsf(x), r, z;
    int inv = ax > 1.0f;
    if (inv) ax = 1.0f / ax;
    z = ax * ax;
    r = ax * (0.99997726f + z * (-0.33262347f + z * (0.19354346f + z * (-0.11643287f + z * (0.05265332f + z * -0.01172120f)))));
    if (inv) r = 1.5707963f - r;
    return x < 0.0f ? -r : r;
}
float lp_atan2(float y, float x)
{
    if (x > 0.0f) return lp_atan(y / x);
    if (x < 0.0f) return y >= 0.0f ? lp_atan(y / x) + 3.1415927f : lp_atan(y / x) - 3.1415927f;
    return y > 0.0f ? 1.5707963f : y < 0.0f ? -1.5707963f : 0.0f;
}
float lp_asin(float x) { return lp_atan2(x, lp_sqrt(1.0f - x * x)); }
float lp_acos(float x) { return lp_atan2(lp_sqrt(1.0f - x * x), x); }
float lp_exp(float x) { return fm_expf(x); }
float lp_log(float x) { return x > 0.0f ? fm_logf(x) : x == 0.0f ? -1.0f / 0.0f : 0.0f / 0.0f; }
float lp_log2(float x) { return x > 0.0f ? fm_log2f(x) : x == 0.0f ? -1.0f / 0.0f : 0.0f / 0.0f; }
float lp_log10(float x) { return lp_log2(x) * 0.30103f; }
float lp_pow(float a, float b)
{
    float fb = lp_floor(b);
    if (b == 0.0f) return 1.0f;
    if (fb == b && fm_fabsf(b) <= 64.0f) {  /* whole powers exactly, negative bases too */
        int n = (int)(b < 0.0f ? -b : b);
        float r = 1.0f, p = a;
        while (n) { if (n & 1) r *= p; p *= p; n >>= 1; }
        return b < 0.0f ? 1.0f / r : r;
    }
    if (a < 0.0f) return 0.0f / 0.0f;
    if (a == 0.0f) return 0.0f;
    return fm_exp2f(b * fm_log2f(a));
}
float lp_frexp(float x, int *e)
{
    union { float f; uint32_t u; } b;
    b.f = x;
    if (x == 0.0f || (b.u & 0x7F800000u) == 0x7F800000u) { *e = 0; return x; }
    *e = (int)((b.u >> 23) & 0xFFu) - 126;
    b.u = (b.u & 0x807FFFFFu) | (126u << 23);
    return b.f;
}
float lp_ldexp(float x, int e)
{
    while (e > 100) { x *= 1.2676506e30f; e -= 100; }
    while (e < -100) { x *= 7.888609e-31f; e += 100; }
    while (e > 0) { int k = e > 30 ? 30 : e; x *= (float)(1u << k); e -= k; }
    while (e < 0) { int k = -e > 30 ? 30 : -e; x /= (float)(1u << k); e += k; }
    return x;
}

/* ------------------------------------------------------------- C library --- */
#ifndef PLAT_HOST                           /* (the host has its own) */
size_t strlen(const char *s) { const char *p = s; while (*p) p++; return (size_t)(p - s); }
int strcmp(const char *a, const char *b)
{
    while (*a && *a == *b) { a++; b++; }
    return (unsigned char)*a - (unsigned char)*b;
}
int strcoll(const char *a, const char *b) { return strcmp(a, b); }
int strncmp(const char *a, const char *b, size_t n)
{
    for (; n; n--, a++, b++) {
        if (*a != *b) return (unsigned char)*a - (unsigned char)*b;
        if (!*a) return 0;
    }
    return 0;
}
char *strchr(const char *s, int c)
{
    for (;; s++) {
        if (*s == (char)c) return (char *)s;
        if (!*s) return 0;
    }
}
char *strrchr(const char *s, int c)
{
    const char *r = 0;
    for (;; s++) {
        if (*s == (char)c) r = s;
        if (!*s) return (char *)r;
    }
}
void *memchr(const void *s, int c, size_t n)
{
    const unsigned char *p = s;
    for (; n; n--, p++) if (*p == (unsigned char)c) return (void *)p;
    return 0;
}
size_t strspn(const char *s, const char *acc)
{
    size_t n = 0;
    while (s[n] && strchr(acc, s[n])) n++;
    return n;
}
char *strpbrk(const char *s, const char *acc)
{
    for (; *s; s++) if (strchr(acc, *s)) return (char *)s;
    return 0;
}
char *strstr(const char *h, const char *n)
{
    size_t k = strlen(n);
    if (!k) return (char *)h;
    for (; *h; h++) if (*h == *n && !strncmp(h, n, k)) return (char *)h;
    return 0;
}
char *strcpy(char *d, const char *s)
{
    char *r = d;
    while ((*d++ = *s++) != 0)
        continue;
    return r;
}
int abs(int v) { return v < 0 ? -v : v; }
void *memmove(void *d, const void *s, size_t n)
{
    unsigned char *dp = d;
    const unsigned char *sp = s;
    if (dp < sp) while (n--) *dp++ = *sp++;
    else { dp += n; sp += n; while (n--) *--dp = *--sp; }
    return d;
}
__attribute__((noreturn)) void abort(void) { for (;;) { } }
#endif

/* -------------------------------------------------------------- the files --- */
/* a small stdio for lauxlib's loadfile (and so require): read-only files on the disk, read a chunk at a time */
typedef struct {
    disk_file_t f;
    uint32_t at;                            /* the file's next byte */
    uint8_t buf[128];
    uint32_t bn, bi;                        /* bytes in buf, the next one */
    int used, unget;
} LP_FILE;
static LP_FILE lp_files[3];

LP_FILE *lp_fopen(const char *name, const char *mode)
{
    disk_file_t f;
    int i;
    (void)mode;
    if (disk_open(name, &f) != 0 || f.dir)
        return 0;
    for (i = 0; i < 3; i++)
        if (!lp_files[i].used) {
            LP_FILE *o = &lp_files[i];
            o->f = f;
            o->at = o->bn = o->bi = 0;
            o->used = 1;
            o->unget = -1;
            return o;
        }
    return 0;
}
int lp_fclose(LP_FILE *f) { if (f) f->used = 0; return 0; }
int lp_getc(LP_FILE *f)
{
    if (!f) return -1;
    if (f->unget >= 0) { int c = f->unget; f->unget = -1; return c; }
    if (f->bi >= f->bn) {
        f->bn = disk_read(&f->f, f->at, f->buf, sizeof f->buf);
        f->at += f->bn;
        f->bi = 0;
        if (!f->bn) return -1;
    }
    return f->buf[f->bi++];
}
size_t lp_fread(void *d, size_t sz, size_t cnt, LP_FILE *f)
{
    size_t want = sz * cnt, k = 0;
    uint8_t *o = d;
    int c;
    if (!f) return 0;
    while (k < want && (c = lp_getc(f)) >= 0)
        o[k++] = (uint8_t)c;
    return sz ? k / sz : 0;
}
int lp_feof(LP_FILE *f) { return !f || (f->bi >= f->bn && f->at >= f->f.size && f->unget < 0); }
