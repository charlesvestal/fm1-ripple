/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* Ripple: a firmware that runs droplets (Lua, from its disk) playing currents (Faust or C sound, from its disk),
 * with a disk mode that shows the disk to a computer as a USB drive. Built on fm1-base (base/). */
#pragma once
#include <stdint.h>
#include "plat.h"

#define APP_NAME "RIPPLE"
#define APP_SPLASH_RGB RGB(120, 200, 220)
#define APP_TAGLINE "droplets and currents"
#define APP_BLOCK 256u                   /* frames per audio block: 5.8 ms at 44.1 kHz */
#define APP_TOUCH                        /* velocity from the keys (lib/touch.h) */
#define APP_CANVAS_PX (240u * 80u)       /* two bands of 40 rows (screen.c dl_show) */
#define APP_LOOP                         /* every pass of the main loop: disk mode's USB (app_loop) */
void app_loop(void);

/* the store: the settings in Felucca's settings sector, the panel calibration below the disk (disk.h DISK_HI) */
enum { OBJ_SETTINGS, OBJ_PANEL, OBJ_NOBJ };
#define APP_STORE_MAP {0xFC000u, 0xDC000u}

void app_init(void);
void app_render(int32_t *lr, uint32_t n, uint32_t master_q12);
void app_panic(void);
void app_ui_init(void);
void app_frame(void);
void app_input_only(void);
void app_say(const char *a, const char *b);

#define APP_HOST_EXPECT
int app_expect(const char *what, int *got);
#define APP_HOST_CMD                     /* the simulator's "start NAME": a droplet started by its name */
int app_host_cmd(const char *cmd, const char *a, const char *b, const char *c, const char *d);
