/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* Lua 5.4 and the droplet API as one unit (fm1.toml o2): Lua's own files (third_party/lua-5.4.7, MIT; PATCHES.md),
 * what it needs from a C library (luaport.c), its heap (heap.c) and the bindings a droplet calls (api.c). */
#define LUA_FM1 1
#define LUA_ONE 1                           /* luaport.h: Lua's internal functions static */

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <time.h>
#include <ctype.h>
#include <errno.h>
#include <locale.h>
#include <math.h>

#include "heap.c"
#include "luaport.c"

/* stdio for lauxlib's loadfile and loadlib's searcher: the disk's files (luaport.c) */
#undef FILE
#undef getc
#undef feof
#undef ferror
#undef stdin
#undef fopen
#undef fclose
#undef fread
#undef freopen
#undef getenv
#undef realloc
#undef free
#undef strerror
#undef errno
#undef time
#undef clock
#define FILE LP_FILE
#define getc lp_getc
#define feof lp_feof
#define ferror(f) ((void)(f), 0)
#define stdin ((LP_FILE *)0)
#define fopen lp_fopen
#define fclose lp_fclose
#define fread lp_fread
#define freopen(n, m, f) (f)
#define getenv(n) ((char *)0)
#define realloc(p, n) lp_realloc((p), (n))
#define free(p) lp_free(p)
#define strerror(e) ((void)(e), "error")
static int lp_errno;
#define errno lp_errno
#define time(p) ((time_t)lp_seed())
#define clock() ((clock_t)lp_seed())

#ifndef PLAT_HOST
/* the ctype calls lstrlib makes (Lua's lexer has its own, lctype.c) */
#undef isalpha
#undef isdigit
#undef isalnum
#undef isspace
#undef iscntrl
#undef isgraph
#undef islower
#undef isupper
#undef ispunct
#undef isxdigit
#undef tolower
#undef toupper
#define isalpha lp_isalpha
#define isdigit lp_isdigit
#define isalnum lp_isalnum
#define isspace lp_isspace
#define iscntrl lp_iscntrl
#define isgraph lp_isgraph
#define islower lp_islower
#define isupper lp_isupper
#define ispunct lp_ispunct
#define isxdigit lp_isxdigit
#define tolower lp_tolower
#define toupper lp_toupper
static int lp_islower(int c) { return c >= 'a' && c <= 'z'; }
static int lp_isupper(int c) { return c >= 'A' && c <= 'Z'; }
static int lp_isalpha(int c) { return lp_islower(c) || lp_isupper(c); }
static int lp_isdigit(int c) { return c >= '0' && c <= '9'; }
static int lp_isalnum(int c) { return lp_isalpha(c) || lp_isdigit(c); }
static int lp_isspace(int c) { return c == ' ' || (c >= 9 && c <= 13); }
static int lp_iscntrl(int c) { return (c >= 0 && c < 32) || c == 127; }
static int lp_isgraph(int c) { return c > 32 && c < 127; }
static int lp_ispunct(int c) { return lp_isgraph(c) && !lp_isalnum(c); }
static int lp_isxdigit(int c) { return lp_isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'); }
static int lp_tolower(int c) { return lp_isupper(c) ? c + 32 : c; }
static int lp_toupper(int c) { return lp_islower(c) ? c - 32 : c; }
#endif

/* the core */
#include "../third_party/lua-5.4.7/src/lzio.c"
#include "../third_party/lua-5.4.7/src/lctype.c"
#include "../third_party/lua-5.4.7/src/lopcodes.c"
#include "../third_party/lua-5.4.7/src/lmem.c"
#include "../third_party/lua-5.4.7/src/lundump.c"
#include "../third_party/lua-5.4.7/src/ldump.c"
#include "../third_party/lua-5.4.7/src/lstate.c"
#include "../third_party/lua-5.4.7/src/lgc.c"
#include "../third_party/lua-5.4.7/src/llex.c"
#include "../third_party/lua-5.4.7/src/lcode.c"
#include "../third_party/lua-5.4.7/src/lparser.c"
#include "../third_party/lua-5.4.7/src/ldebug.c"
#include "../third_party/lua-5.4.7/src/lfunc.c"
#include "../third_party/lua-5.4.7/src/lobject.c"
#include "../third_party/lua-5.4.7/src/ltm.c"
#include "../third_party/lua-5.4.7/src/lstring.c"
#include "../third_party/lua-5.4.7/src/ltable.c"
#include "../third_party/lua-5.4.7/src/ldo.c"
#include "../third_party/lua-5.4.7/src/lvm.c"
#include "../third_party/lua-5.4.7/src/lapi.c"
/* the auxiliary and standard libraries (no io, os or debug) */
#include "../third_party/lua-5.4.7/src/lauxlib.c"
#include "../third_party/lua-5.4.7/src/lbaselib.c"
#include "../third_party/lua-5.4.7/src/lcorolib.c"
#include "../third_party/lua-5.4.7/src/lmathlib.c"
#include "../third_party/lua-5.4.7/src/loadlib.c"
#include "../third_party/lua-5.4.7/src/lstrlib.c"
#include "../third_party/lua-5.4.7/src/ltablib.c"
#include "../third_party/lua-5.4.7/src/lutf8lib.c"

#include "api.c"
