/* SPDX-License-Identifier: MIT
 * Copyright (C) 2026 Charles Vestal */
/* A current as a WebAssembly module of its own, for Ripple's emulator page (sdk/tools/currents.py --web-module):
 * built with the current, so the page can run it without the current being linked into the emulator. The page makes
 * one instance of the module for each time a droplet loads the current, and calls these:
 *   rcw_name() rcw_ins() rcw_voices() rcw_nparams()            what it is
 *   rcw_param_name(i) rcw_param_min(i) .._max(i) .._def(i)     its parameters
 *   rcw_new(sr)                                                 its state, made and set up (once an instance)
 *   rcw_set(p, v) rcw_note(n, vel)                              as a droplet asks
 *   rcw_l() rcw_r()                                             the bus: n frames written here ..
 *   rcw_process(n)                                              .. processed in place, read back */
#include "ripple_current.h"

#define RCW(n) __attribute__((export_name(#n)))

const rc_desc_t *rc_entry(void);

static uint8_t rcw_heap[1u << 20] __attribute__((aligned(8)));   /* the state (1 MB at most) */
static float rcw_bl[256], rcw_br[256];
static void *rcw_st;

static const rc_desc_t *d(void) { return rc_entry(); }

RCW(rcw_name) const char *rcw_name(void) { return d()->name; }
RCW(rcw_ins) int rcw_ins(void) { return d()->ins; }
RCW(rcw_voices) int rcw_voices(void) { return d()->voices; }
RCW(rcw_nparams) int rcw_nparams(void) { return d()->nparams; }
RCW(rcw_param_name) const char *rcw_param_name(int i) { return d()->params[i].name; }
RCW(rcw_param_min) float rcw_param_min(int i) { return d()->params[i].min; }
RCW(rcw_param_max) float rcw_param_max(int i) { return d()->params[i].max; }
RCW(rcw_param_def) float rcw_param_def(int i) { return d()->params[i].def; }
RCW(rcw_l) float *rcw_l(void) { return rcw_bl; }
RCW(rcw_r) float *rcw_r(void) { return rcw_br; }

RCW(rcw_new) int rcw_new(float sr)
{
    uint32_t i, n = d()->state_size;
    if (n > sizeof rcw_heap)
        return -1;
    for (i = 0; i < n; i++)
        rcw_heap[i] = 0;
    rcw_st = rcw_heap;
    if (d()->init)
        d()->init(rcw_st, sr);
    for (i = 0; i < d()->nparams; i++)
        d()->set(rcw_st, (int)i, d()->params[i].def);
    return 0;
}
RCW(rcw_set) void rcw_set(int p, float v) { if (rcw_st && p >= 0 && p < d()->nparams) d()->set(rcw_st, p, v); }
RCW(rcw_note) void rcw_note(int n, float vel) { if (rcw_st && d()->note) d()->note(rcw_st, n, vel); }
RCW(rcw_process) void rcw_process(int n)
{
    if (!rcw_st || n > 256)
        return;
    if (d()->abi >= 2u && d()->begin)
        d()->begin(rcw_st, n);
    d()->process(rcw_st, rcw_bl, rcw_br, n);
}
