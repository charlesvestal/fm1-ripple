/* SPDX-License-Identifier: MIT
 * Copyright (C) 2026 Charles Vestal */
/* A Ripple current: a piece of sound (a voice, a drum kit, a delay) that a droplet loads from the disk and puts in
 * its flow. Written in C against this header, or in Faust (sdk/faust/), and built into a .cur file by the SDK.
 *
 * The flow is one stereo bus. Each block (256 frames at 44.1 kHz), the currents in the flow run in order on it:
 * a current with no inputs (a voice, drums) adds its sound to the bus; a current with inputs (a filter, a delay)
 * replaces the bus with what it makes of it. So "drums, bass, delay" is drums and bass mixed, then the delay over
 * both.
 *
 * A current gets no C library and no firmware calls: everything it needs is in its own code (fastmath.h for the
 * maths), and its memory is the state the firmware hands it (state_size bytes, zeroed). Single-precision floats
 * only: no double anywhere (the FM-1's FPU has single precision; a double is slow and the SDK refuses it).
 *
 * The FM-1 has two cores. A current that makes sound may say it comes in two parts (parts = 2: usually half its
 * voices each) and give process_part: the render may then run part 1 on the second core while the first runs part
 * 0, each adding into its own bus. A part touches only its own share of the state (its voices, its scratch), and
 * reads what set and note write, which run before the block, never during it. Without the second core, or for a
 * current without parts, the render calls process. Work that must happen once a block before either part (a knob's
 * slew) goes in begin, which the first core calls before process or the parts. */
#ifndef RIPPLE_CURRENT_H
#define RIPPLE_CURRENT_H
#include <stdint.h>

#define RC_MAGIC 0x52435231u            /* "1RCR": the descriptor */
#define RC_ABI 2u                       /* this header's version (the firmware loads 1 and 2: 1 has no parts) */
#define RC_MAX_PARAMS 64

typedef struct {
    const char *name;                   /* "cutoff": how a droplet names it */
    float min, max, def;
} rc_param_t;

typedef struct {
    uint32_t magic, abi;                /* RC_MAGIC, RC_ABI */
    const char *name;                   /* "voice" */
    uint32_t state_size;                /* the bytes of state it wants (zeroed before init) */
    uint8_t ins;                        /* 0: it adds to the bus (a voice); 2: it processes the bus (an effect) */
    uint8_t voices;                     /* the notes it plays at once (0: it takes no notes) */
    uint16_t nparams;
    const rc_param_t *params;
    void (*init)(void *st, float sr);   /* once, after loading: set up at sample rate sr */
    void (*set)(void *st, int p, float v);    /* parameter p (0..nparams-1) to v (within min..max) */
    void (*note)(void *st, int note, float vel);   /* MIDI note; vel 0..1, 0 = note off; 0 when voices is 0 */
    void (*process)(void *st, float *l, float *r, int n);   /* n frames of the bus */
    /* ABI 2 */
    uint8_t parts;                      /* 2: process_part(st, l, r, n, 0) and (.., 1) together make process; else 0 */
    uint8_t rsv[3];
    void (*process_part)(void *st, float *l, float *r, int n, int part);   /* adds part 0 or 1 into l, r */
    void (*begin)(void *st, int n);     /* or 0: once a block, before process or the parts (the first core) */
} rc_desc_t;

/* each current defines this one symbol: the SDK finds it and the firmware starts there */
#define RC_EXPORT(d) const rc_desc_t *rc_entry(void) { return &(d); }

#endif
