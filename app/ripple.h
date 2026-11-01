/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* Between the droplet API (lua/api.c, its own unit with Lua) and the firmware (the unity build: screen.c, flow.c,
 * droplet.c): what a droplet can do, in C. */
#pragma once
#include <stddef.h>
#include <stdint.h>
#ifndef PLAT_HOST
/* the string calls the firmware makes (lua/luaport.c on the device; the host has its own) */
size_t strlen(const char *);
int strcmp(const char *, const char *);
char *strcpy(char *, const char *);
#endif

/* the screen: 240 x 240, drawn off screen and shown by scr_update */
void scr_clear(void);
void scr_level(int level);                  /* the colour: 0 (the background) .. 15 (the brightest) */
void scr_color(int r, int g, int b);        /* or any colour */
void scr_palette(int level, int r, int g, int b);
void scr_font(int font);                    /* 1 small .. 5 large */
void scr_rect(int x, int y, int w, int h);  /* filled */
void scr_frame(int x, int y, int w, int h); /* outlined */
void scr_line(int x0, int y0, int x1, int y1);
void scr_pixel(int x, int y);
void scr_circle(int x, int y, int r, int fill);
int scr_text(int x, int y, const char *s, int align);   /* align 0 left, 1 centre, 2 right: the text's width */
int scr_text_w(const char *s);
void scr_update(void);

/* the flow (flow.c) */
int rp_load(const char *name, const char **err);   /* a current: its handle, or -1 */
int rp_param(int h, const char *name);      /* its parameter's number, or -1 */
int rp_nparams(int h);
const char *rp_param_info(int h, int p, float *min, float *max, float *def);
const char *rp_name(int h);
int rp_voices(int h);
void rp_set(int h, int p, float v);
void rp_note(int h, int note, float vel);
void rp_route(const int *hs, int n);
void rp_level(float v);
float rp_peak(void);

/* the panel and MIDI */
void rp_midi(int b0, int b1, int b2);
void rp_led_key(int k, int on);
void rp_led_button(int b, int on);
int rp_button_index(const char *name);      /* "PLAY" -> B_PLAY, -1 none */
const char *rp_button_name(int b);
uint32_t rp_ms(void);
int rp_data_write(const char *s, size_t n);  /* the droplet's file (/data/NAME.DAT): 0 = written */
int rp_data_read(char *d, size_t max);       /* its bytes (at most max), or -1 none */
void rp_print(const char *s, size_t n);     /* print: the console */
void rp_crumb(uint32_t step, const char *what);   /* where a start got to (kept through a watchdog reset) */

/* the droplet's Lua side (lua/api.c), called by droplet.c */
int lr_start(const char *path);             /* a fresh Lua, the droplet loaded and init() run: 0, or -1 (lr_error) */
void lr_stop(void);                         /* cleanup(), then Lua gone */
int lr_running(void);
const char *lr_error(void);                 /* the last error's text */
void lr_key(int k, int vel);                /* key k (0 = F3) pressed with vel 1..127, or released (0) */
void lr_button(int b, int z);
void lr_enc(int n, int d);                  /* n 1..4: K1..K4; 5 SELECT, 6 ALGORITHM, 7 PRESET */
void lr_midi(int b0, int b1, int b2);
void lr_tick(uint32_t ms);                  /* the clocks, and frame() at ~30 fps */
uint32_t lr_mem(uint32_t *peak);            /* the heap: bytes in use (and the most) */
