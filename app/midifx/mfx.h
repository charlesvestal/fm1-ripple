/* SPDX-License-Identifier: MIT
 * Copyright (C) 2026 Charles Vestal
 * From e16-launcher (github.com/charlesvestal/e16-launcher, apps/midifx/core, MIT): the MIDI effects engine,
 * unchanged but for its sizes (mfx.h: one track, smaller queues; README "Ripple's copy"). */
/*
 * midifx core: a MIDI effects engine (Yamaha RS7000 "Play FX"-style plus
 * an arpeggiator, MIDI delay, grid groove, humanize and a loop remix).
 *
 * Portable C99: no libc, no malloc, no hardware. The app (apps/midifx/
 * app.c) and the host tests (test/midifx/) drive it the same way:
 *
 *   mfx_init(m, now, seed, emit, ctx);
 *   mfx_input(m, now, in_port, bytes, len);   for every received message
 *   mfx_advance(m, now);                      often (every loop pass)
 *   mfx_set(m, track, id, value, now);        parameter changes
 *   mfx_loop(m, now, on);                     the momentary loop/repeat
 *
 * Time is a free-running uint32_t in microseconds (wraps every ~71 min;
 * every comparison is wrap-safe). Output goes through emit(): each message
 * carries the time it was due, which is <= the `now` of the call that
 * produced it (the host tests check exact timelines with it).
 *
 * Musical positions are in "clocks", 480 per quarter note (the RS7000's
 * resolution). The grid comes from incoming MIDI clock (24 ppqn, so one
 * MIDI clock = 20 clocks, interpolated between ticks with the measured
 * tempo) when it is running, else from an internal tempo (G_BPM).
 *
 * Notes: every note-on the engine emits is matched by exactly one note-off
 * on the same port/channel/pitch. Each emitted note is a "voice" that owns
 * its own end (a fixed length, or the end of the input note it came from),
 * so parameter changes never orphan a note. Two voices that land on the
 * same port/channel/pitch are merged at the output: the second retriggers
 * (off, on) and only the last one to end sends the final off, so on/off
 * strictly alternate per key.
 */
#ifndef MFX_H
#define MFX_H
#include <stdint.h>

#define MFX_PPQN 480       /* clocks per quarter note */
#define MFX_CLK_PER_TICK 20 /* clocks per MIDI clock (24 ppqn) */
#define MFX_TRACKS 1        /* (Ripple; the E16: 4) */
#define MFX_STEPS 16       /* grid groove steps (16ths of a 4/4 bar) */

#define MFX_QUEUE 256       /* scheduler capacity (Ripple; the E16: 512) */
#define MFX_QUEUE_MSG_RESERVE 32 /* slots only plain messages may use */
#define MFX_VOICES 64       /* (Ripple; the E16: 256) */
#define MFX_HELD 32         /* input notes held at once (Ripple; the E16: 64) */
#define MFX_CHAINS 32       /* MIDI-delay repeat chains (Ripple; the E16: 128) */
#define MFX_ARP_MAX 32     /* notes in one arpeggio */
#define MFX_HIST 128        /* recent output notes (for the loop) (Ripple; the E16: 256) */
#define MFX_LOOP_MAX 96    /* notes captured into the loop */
#define MFX_TICK_HIST 128  /* recent MIDI clock tick times */
#define MFX_FIT 48         /* ticks in the tempo fit */

/* Input ports. */
#define MFX_IN_TRS 0
#define MFX_IN_USB 1
/* Output ports (emit()'s port; bit n of a port mask). */
#define MFX_OUT_TRS1 0
#define MFX_OUT_TRS2 1
#define MFX_OUT_USB 2

/* Per-track parameters (mfx_set(m, track, id, v)). */
enum {
    /* timing */
    MFX_P_SWING_ON, MFX_P_SWING, MFX_P_SWING_GRID,
    MFX_P_SHIFT_ON, MFX_P_SHIFT,
    MFX_P_GATE_ON, MFX_P_GATE,
    MFX_P_GRV_ON, MFX_P_GRV_PRESET,
    /* velocity / note */
    MFX_P_VEL_ON, MFX_P_VEL_OFS, MFX_P_VEL_SCALE, MFX_P_VEL_COMP, MFX_P_VEL_RAND,
    MFX_P_NOTE_ON, MFX_P_NOTE_OFS,
    MFX_P_SCALE_ON, MFX_P_SCALE, MFX_P_ROOT,
    MFX_P_HARM_ON, MFX_P_UNISON, MFX_P_OCTAVER, MFX_P_HARM1, MFX_P_HARM2,
    /* arpeggiator */
    MFX_P_ARP_ON, MFX_P_ARP_MODE, MFX_P_ARP_RATE, MFX_P_ARP_OCT, MFX_P_ARP_GATE, MFX_P_ARP_LATCH,
    /* MIDI delay */
    MFX_P_DLY_ON, MFX_P_DLY_TIME, MFX_P_DLY_LEVEL, MFX_P_DLY_REPEAT,
    MFX_P_FB_VEL, MFX_P_FB_NOTE, MFX_P_FB_GATE, MFX_P_FB_CLOCK,
    /* humanize / probability */
    MFX_P_HUM_ON, MFX_P_HUM_TIME, MFX_P_PROB,
    /* routing */
    MFX_P_CHANNEL, MFX_P_OUT_PORTS, MFX_P_OUT_CH,
    /* grid groove tables */
    MFX_P_GRV_CLK0,
    MFX_P_GRV_GATE0 = MFX_P_GRV_CLK0 + MFX_STEPS,
    MFX_P_GRV_VEL0 = MFX_P_GRV_GATE0 + MFX_STEPS,
    MFX_P_GRV_NOTE0 = MFX_P_GRV_VEL0 + MFX_STEPS,
    MFX_TP_COUNT = MFX_P_GRV_NOTE0 + MFX_STEPS
};

/* Global parameters (mfx_set(m, MFX_GLOBAL, id, v)). */
#define MFX_GLOBAL (-1)
enum {
    MFX_G_IN_PORTS,  /* bit 0 TRS in, bit 1 USB */
    MFX_G_OUT_PORTS, /* bit 0 TRS 1, bit 1 TRS 2, bit 2 USB */
    MFX_G_BPM,       /* internal tempo */
    MFX_G_THRU,      /* MFX_THRU_* bits */
    MFX_G_MUTE,      /* bit n: channel n+1 muted */
    MFX_G_SOLO,      /* bit n: channel n+1 soloed (any solo: only soloed channels sound) */
    MFX_G_LOOP_TYPE,
    MFX_G_STRETCH,   /* index into mfx_stretch_pct[] */
    MFX_GP_COUNT
};

#define MFX_THRU_CC 1
#define MFX_THRU_PB 2
#define MFX_THRU_AT 4  /* channel and poly aftertouch */
#define MFX_THRU_PC 8
#define MFX_THRU_CLOCK 16 /* clock, start, continue, stop, song position */

/* Enumerations shown by name. */
enum { MFX_ARP_UP, MFX_ARP_DOWN, MFX_ARP_UPDOWN, MFX_ARP_RANDOM, MFX_ARP_ORDER, MFX_ARP_MODES };
#define MFX_ARP_RATES 6
#define MFX_SCALES 13
#define MFX_GRV_PRESETS 6
#define MFX_LOOP_TYPES 10
#define MFX_STRETCHES 11
#define MFX_FB_NOTE_RND 25 /* MFX_P_FB_NOTE value meaning "random" */

extern const int16_t mfx_arp_rate_clk[MFX_ARP_RATES];
extern const uint16_t mfx_stretch_pct[MFX_STRETCHES];

/* Parameter metadata (mfx_params.c). */
typedef enum { MFX_F_INT, MFX_F_SIGNED, MFX_F_ONOFF, MFX_F_PCT, MFX_F_MS, MFX_F_CLK, MFX_F_NOTE,
               MFX_F_ENUM, MFX_F_CHAN, MFX_F_PORTS, MFX_F_OUTCH, MFX_F_BPM, MFX_F_MASK } mfx_fmt_t;
typedef struct {
    const char *name;   /* short, for the OLED */
    int32_t min, max, def;
    uint8_t fmt;        /* mfx_fmt_t */
    const char *const *names; /* MFX_F_ENUM: value - min indexes it */
} mfx_param_t;

const mfx_param_t *mfx_tparam(int id);
const mfx_param_t *mfx_gparam(int id);
/* The value as text (at most 15 chars + NUL). */
void mfx_format(const mfx_param_t *p, int32_t v, char *out, int n);

typedef void (*mfx_emit_fn)(void *ctx, uint32_t t, int port, const uint8_t *msg, int len);

typedef struct {
    uint32_t in_msgs, out_msgs;
    uint32_t drop_voice;   /* no free voice: note not played */
    uint32_t drop_queue;   /* scheduler full: event not scheduled */
    uint32_t drop_held;    /* too many input notes held */
    uint32_t drop_chain;   /* no free delay chain */
    uint32_t drop_range;   /* a pitch went outside 0-127 */
    uint32_t prob_skip;    /* notes skipped by probability */
    uint32_t muted;        /* notes not played: muted channel */
    uint32_t purged;       /* stale scheduler entries removed on overflow */
    uint32_t max_queue, max_voices;
} mfx_stats_t;

/* ---- internal state (exposed for sizing only) ---- */
typedef struct {
    uint32_t t, seq;
    uint16_t a, b;
    uint8_t kind, ports, len, d[3];
} mfx_ev_t;

typedef struct {
    uint32_t on_t, off_t, lmul, cap, hist_seq;
    uint16_t gen, owner;
    uint8_t state, flags, kind, track, ch, pitch, vel, ports;
} mfx_voice_t;

typedef struct {
    uint32_t on_t;
    uint16_t inst;
    uint8_t used, in_port, ch, pitch, flags;
    int8_t track;
} mfx_held_t;

typedef struct {
    uint32_t delay, base_len, lmul0, cap0, gmul;
    int16_t vel;
    uint16_t gen, owner;
    uint8_t used, flags, track, ch, pitch, ports, remaining, total;
} mfx_chain_t;

typedef struct {
    uint16_t inst;
    uint8_t pitch, vel, ch, order;
} mfx_arp_note_t;

typedef struct {
    mfx_arp_note_t n[MFX_ARP_MAX];
    int count;
    uint32_t idx;
    uint8_t order_ctr;
} mfx_arp_t;

typedef struct {
    uint32_t on_t, off_t, seq;
    uint8_t open, ch, pitch, vel, ports;
} mfx_hist_t;

typedef struct {
    uint16_t off, len; /* clocks within the slice */
    uint8_t slice, ch, pitch, vel, ports;
} mfx_loop_note_t;

typedef struct {
    int active, type, nslots, slot_len, stretch, n;
    const int8_t *pattern;
    int64_t base_q8;   /* position of slot 0, clocks << 8 */
    uint32_t k;        /* next slot to play */
    mfx_loop_note_t notes[MFX_LOOP_MAX];
} mfx_loop_t;

typedef struct mfx {
    mfx_emit_fn emit;
    void *ctx;
    int32_t gp[MFX_GP_COUNT];
    int32_t tp[MFX_TRACKS][MFX_TP_COUNT];

    uint32_t now;
    /* the grid */
    int64_t ticks;            /* MIDI clock ticks (20 clocks each) */
    uint32_t last_tick_t;
    uint32_t th[MFX_TICK_HIST];
    uint32_t uspq;            /* current tempo, microseconds per quarter */
    int ext;                  /* following external clock */
    int ext_port;
    uint32_t ext_last_t;
    uint32_t ext_t[MFX_FIT];  /* arrival times of the last ticks */
    int ext_n, ext_i, ext_off;
    uint32_t fit_t;           /* the fitted time of tick fit_tick */
    int64_t fit_tick;
    int fit_ok;
    int64_t pending_pos;      /* tick to jump to on the next F8 (start/SPP), -1 none */
    uint32_t anchor_t;
    int64_t anchor_tick;

    uint32_t D;               /* compensation delay (negative timing settings) */
    uint32_t D_uspq;
    uint32_t clock_out_t;

    mfx_ev_t q[MFX_QUEUE];
    int qn;
    uint32_t qseq;
    mfx_voice_t v[MFX_VOICES];
    int n_on, n_used;
    mfx_held_t held[MFX_HELD];
    uint16_t inst_ctr;
    mfx_chain_t chain[MFX_CHAINS];
    mfx_arp_t arp[MFX_TRACKS];
    mfx_hist_t hist[MFX_HIST];
    uint32_t hist_seq;
    mfx_loop_t loop;
    uint32_t rng;
    mfx_stats_t st;
} mfx_t;

void mfx_init(mfx_t *m, uint32_t now, uint32_t seed, mfx_emit_fn emit, void *ctx);
void mfx_input(mfx_t *m, uint32_t now, int in_port, const uint8_t *msg, int len);
void mfx_advance(mfx_t *m, uint32_t now);
/* Clamps; applies side effects (flushes notes it would otherwise orphan). */
void mfx_set(mfx_t *m, int track, int id, int32_t v, uint32_t now);
int32_t mfx_get(const mfx_t *m, int track, int id);
/* The momentary loop / beat repeat (MFX_G_LOOP_TYPE, MFX_G_STRETCH). */
void mfx_loop(mfx_t *m, uint32_t now, int on);
/* Ends every note now, cancels everything pending, forgets held input. */
void mfx_panic(mfx_t *m, uint32_t now);

/* Tempo in BPM x 10, and whether it comes from MIDI clock. */
int mfx_bpm10(const mfx_t *m);
int mfx_ext_clock(const mfx_t *m);
/* Position in clocks (since start / SPP), at `now`. */
int64_t mfx_pos(const mfx_t *m, uint32_t now);
int mfx_voices_on(const mfx_t *m);
/* The compensation delay (us) negative timing settings currently add. */
uint32_t mfx_comp_delay(const mfx_t *m);

#endif
