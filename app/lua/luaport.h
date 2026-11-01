/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* Lua 5.4 on the FM-1: the local configuration luaconf.h includes last (LUA_FM1, third_party/lua-5.4.7/PATCHES.md).
 * 32-bit integers and floats (the FPU is single precision: no double anywhere, the build fails on a soft-double
 * routine); numbers formatted and read by luaport.c, not the C library (there is none on the device); errors by our
 * own setjmp (lj.S) on the device; files from the disk (disk.c) through a small stdio of our own. */
#ifndef LUAPORT_H
#define LUAPORT_H
#include <stddef.h>

/* Lua as one unit (lua_one.c): its internal functions static */
#ifdef LUA_ONE
#undef LUAI_FUNC
#undef LUAI_DDEC
#undef LUAI_DDEF
#define LUAI_FUNC static
#define LUAI_DDEC(def) /* empty */
#define LUAI_DDEF static
#endif

/* numbers: format and parse in float */
int lp_fmtf(char *b, size_t sz, const char *fmt, float v);
int lp_fmti(char *b, size_t sz, const char *fmt, int v);
int lp_fmts(char *b, size_t sz, const char *fmt, const char *s);
int lp_fmtp(char *b, size_t sz, const char *fmt, const void *p);
float lp_str2num(const char *s, char **end);

#undef LUAI_UACNUMBER
#define LUAI_UACNUMBER float
#undef lua_number2str
#define lua_number2str(s, sz, n) lp_fmtf((s), (sz), "%.7g", (float)(n))
#undef lua_str2number
#define lua_str2number(s, p) lp_str2num((s), (p))
#undef lua_strx2number
#define lua_strx2number(s, p) lp_str2num((s), (p))
#undef lua_number2strx
#define lua_number2strx(L, b, sz, f, n) ((void)(L), lp_fmtf((b), (sz), "%g", (float)(n)))
#undef lua_getlocaledecpoint
#define lua_getlocaledecpoint() '.'
/* l_sprintf always has one value: its type picks the formatter, so a float never passes through "..." (which would
 * make it a double) */
#undef l_sprintf
#define l_sprintf(s, sz, f, i) _Generic((i), float: lp_fmtf, char *: lp_fmts, const char *: lp_fmts, \
                                        void *: lp_fmtp, const void *: lp_fmtp, default: lp_fmti)((s), (sz), (f), (i))

/* maths in float, ours (no libm) */
float lp_floor(float), lp_ceil(float), lp_fmod(float, float), lp_sqrt(float), lp_sin(float), lp_cos(float),
    lp_tan(float), lp_asin(float), lp_acos(float), lp_atan(float), lp_atan2(float, float), lp_exp(float),
    lp_log(float), lp_log2(float), lp_log10(float), lp_pow(float, float), lp_fabs(float), lp_frexp(float, int *),
    lp_ldexp(float, int);
/* l_mathop(floor) is floorf, l_mathop(1.0) is 1.0f: the float functions are ours */
#define floorf lp_floor
#define ceilf lp_ceil
#define fmodf lp_fmod
#define sqrtf lp_sqrt
#define sinf lp_sin
#define cosf lp_cos
#define tanf lp_tan
#define asinf lp_asin
#define acosf lp_acos
#define atanf lp_atan
#define atan2f lp_atan2
#define expf lp_exp
#define logf lp_log
#define log2f lp_log2
#define log10f lp_log10
#define powf lp_pow
#define fabsf lp_fabs
#define frexpf lp_frexp
#define ldexpf lp_ldexp

/* the interpreter dispatches with a switch: the computed gotos of its jump table (ljumptab.h) are not trusted on the
 * FM-1's compiler */
#undef LUA_USE_JUMPTABLE
#define LUA_USE_JUMPTABLE 0

/* math.random on 32-bit integers (no 64-bit arithmetic on the FM-1) */
#define LUA_RAND32 1

/* the seed of the hash and of math.random */
unsigned lp_seed(void);
#define luai_makeseed(L) ((void)(L), lp_seed())

/* print and errors go to the droplet console (droplet.c) */
void lp_write(const char *s, size_t n);
void lp_writeerr(const char *fmt, const char *p);
#define lua_writestring(s, l) lp_write((s), (l))
#define lua_writeline() lp_write("\n", 1)
#define lua_writestringerror(s, p) lp_writeerr((s), (p))

/* the C stack: the main loop's is 24 KB */
#undef LUAI_MAXCCALLS
#define LUAI_MAXCCALLS 80

/* require: scripts and libraries on the disk */
#undef LUA_PATH_DEFAULT
#define LUA_PATH_DEFAULT "/lib/?.lua;/droplets/?.lua"
#undef LUA_CPATH_DEFAULT
#define LUA_CPATH_DEFAULT ""

#ifndef PLAT_HOST
/* errors: setjmp / longjmp of our own (lj.S; r4..r15, sp and rets) */
typedef int lj_buf[18];
int lj_setjmp(lj_buf b) __attribute__((returns_twice));
void lj_longjmp(lj_buf b, int v) __attribute__((noreturn));
#define LUAI_THROW(L, c) lj_longjmp((c)->b, 1)
#define LUAI_TRY(L, c, a) if (lj_setjmp((c)->b) == 0) { a }
#define luai_jmpbuf lj_buf
#endif

#endif
