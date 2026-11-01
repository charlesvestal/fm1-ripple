/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* Ripple's C library headers for Lua on the FM-1 (the device has no C library): declarations only, the code is
 * luaport.c's and felucca-bsp's libc.c. fm1.toml device_include. */
#pragma once
typedef long time_t;
typedef long clock_t;
#define CLOCKS_PER_SEC 1000
