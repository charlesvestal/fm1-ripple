/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* Ripple's C library headers for Lua on the FM-1 (the device has no C library): declarations only, the code is
 * luaport.c's and felucca-bsp's libc.c. fm1.toml device_include. */
#pragma once
#include <stddef.h>
void abort(void) __attribute__((noreturn));
int abs(int);
void *realloc(void *, size_t);
void free(void *);
char *getenv(const char *);
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
