/* SPDX-License-Identifier: MIT
 * Copyright (C) 2026 Charles Vestal
 * From e16-launcher (github.com/charlesvestal/e16-launcher, apps/midifx/core, MIT): the MIDI effects engine,
 * unchanged but for its sizes (mfx.h: one track, smaller queues; README "Ripple's copy"). */
/*
 * midifx engine (mfx.h has the overview).
 *
 * The pipeline for a note-on on a track's channel:
 *
 *   input filter -> harmonize (unison, octaver, harmony 1/2) -> note offset
 *   -> scale quantize -> [arpeggiator: collects the notes; each step goes on]
 *   -> chance -> grid groove (step clock/gate/velocity/note) -> velocity
 *   -> timing (swing, clock shift, groove clock, humanize, + compensation)
 *   -> gate -> voices (unison copies) + MIDI delay chains -> mute/solo
 *   -> output (merged per port/channel/pitch) -> history (for the loop)
 *
 * Voices. A voice is one emitted note: pending (its note-on is in the
 * scheduler), on, or free. Its end is either fixed (arp steps, delay
 * repeats of a note whose length is known, loop notes) or "open": it waits
 * for the input note it came from (its owner) to end, then gets
 * on + f(input length). Open voices of a short gate (< 100%) also get a
 * provisional end (cap) at start. Every path that drops an input note
 * (note-off, a repeated note-on, panic) resolves its voices, and every
 * path that cancels a voice either never started it or ends it with an
 * off, so on/off pairs always balance.
 *
 * Negative timing (clock shift, swing, groove clock < 0, humanize's early
 * half) can't move a live note before "now": instead everything -- notes,
 * thru messages and the clock passed through -- is delayed by the largest
 * negative offset the current settings can produce (D, mfx_comp_delay()),
 * and offsets are applied relative to that. With every timing FX at zero
 * or positive, D is 0 and nothing waits.
 */
#include "mfx.h"

/* (Ripple) every 64-bit multiply out of line: on the FM-1, one inlined among loads now and then leaves a register a
 * bit off (felucca-bsp docs/CPU.md); in a function of its own it is clean */
static __attribute__((noinline)) int64_t mul64(int64_t a, int64_t b) { return a * b; }
static __attribute__((noinline)) uint64_t umul64(uint64_t a, uint64_t b) { return a * b; }

#define TLE(a, b) ((int32_t)((a) - (b)) <= 0)
#define TLT(a, b) ((int32_t)((a) - (b)) < 0)

enum { V_FREE, V_PENDING, V_ON };
#define VF_OFFK 1 /* off_t is set */
#define VF_OPEN 2 /* waits for its owner's note-off */
enum { K_LIVE, K_ARP, K_ECHO, K_LOOP, K_THRU };
#define TRACK_NONE 255

enum { EV_VOICE, EV_MSG, EV_ECHO };

#define HF_ARP 1

#define CF_LEN 1 /* chain's base length known */

#define UNISON_US 3000u /* spacing of unison copies */
#define QONE (1u << 24) /* multipliers are Q24 */
#define QMAX (255u << 24)
#define MAX_LEN 600000000u /* 10 minutes */

/* ---- small helpers ---- */

static void zero(void *p, uint32_t n)
{
    uint8_t *b = p;
    while (n--)
        *b++ = 0;
}

static int32_t clampi(int32_t v, int32_t lo, int32_t hi)
{
    return v < lo ? lo : v > hi ? hi : v;
}

static uint32_t pct_q(int32_t pct)
{
    return pct <= 0 ? 0u : (uint32_t)(((uint64_t)pct << 24) / 100u);
}

/* a * q (Q24), rounded, saturating. */
static uint32_t mul_q(uint32_t a, uint32_t q)
{
    uint64_t r = (umul64(a, q) + (1u << 23)) >> 24;
    return r > 0xFFFFFFFFu ? 0xFFFFFFFFu : (uint32_t)r;
}

static uint32_t mul_qq(uint32_t a, uint32_t b)
{
    uint32_t r = mul_q(a, b);
    return r > QMAX ? QMAX : r;
}

static uint32_t rnd(mfx_t *m)
{
    uint32_t x = m->rng;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    m->rng = x;
    return x;
}

/* Uniform in [lo, hi]. */
static int32_t rnd_range(mfx_t *m, int32_t lo, int32_t hi)
{
    if (hi <= lo)
        return lo;
    return lo + (int32_t)(rnd(m) % (uint32_t)(hi - lo + 1));
}

/* clocks -> microseconds at the current tempo (signed). */
static int32_t c2us(const mfx_t *m, int64_t clocks)
{
    return (int32_t)(mul64(clocks, m->uspq) / MFX_PPQN);
}

static uint32_t min_len(const mfx_t *m)
{
    uint32_t c = (uint32_t)c2us(m, 1);
    return c < 500u ? 500u : c;
}

#define TP(m, tr, id) ((m)->tp[(tr)][(id)])
#define GP(m, id) ((m)->gp[(id)])

/* ---- the scheduler: a binary heap ordered by (t, seq) ---- */

static int ev_less(const mfx_ev_t *a, const mfx_ev_t *b)
{
    int32_t d = (int32_t)(a->t - b->t);
    if (d)
        return d < 0;
    return (int32_t)(a->seq - b->seq) < 0;
}

static void ev_swap(mfx_ev_t *a, mfx_ev_t *b)
{
    mfx_ev_t t = *a;
    *a = *b;
    *b = t;
}

static void heap_up(mfx_t *m, int i)
{
    while (i > 0) {
        int p = (i - 1) / 2;
        if (!ev_less(&m->q[i], &m->q[p]))
            break;
        ev_swap(&m->q[i], &m->q[p]);
        i = p;
    }
}

static void heap_down(mfx_t *m, int i)
{
    for (;;) {
        int l = 2 * i + 1, r = l + 1, s = i;
        if (l < m->qn && ev_less(&m->q[l], &m->q[s]))
            s = l;
        if (r < m->qn && ev_less(&m->q[r], &m->q[s]))
            s = r;
        if (s == i)
            break;
        ev_swap(&m->q[i], &m->q[s]);
        i = s;
    }
}

static int ev_stale(const mfx_t *m, const mfx_ev_t *e)
{
    if (e->kind == EV_VOICE) {
        const mfx_voice_t *v = &m->v[e->a];
        return v->gen != e->b || v->state != V_PENDING;
    }
    if (e->kind == EV_ECHO) {
        const mfx_chain_t *c = &m->chain[e->a];
        return !c->used || c->gen != e->b;
    }
    return 0;
}

/* Drops entries that would be ignored anyway (cancelled voices/chains). */
static void heap_purge(mfx_t *m)
{
    int j = 0;
    for (int i = 0; i < m->qn; i++)
        if (!ev_stale(m, &m->q[i]))
            m->q[j++] = m->q[i];
    m->st.purged += (uint32_t)(m->qn - j);
    m->qn = j;
    for (int i = m->qn / 2 - 1; i >= 0; i--)
        heap_down(m, i);
}

/* 1 if queued. Note events leave MFX_QUEUE_MSG_RESERVE slots for plain
 * messages (thru, clock), so a flood of notes can't starve the clock. */
static int heap_push(mfx_t *m, const mfx_ev_t *e)
{
    int cap = e->kind == EV_MSG ? MFX_QUEUE : MFX_QUEUE - MFX_QUEUE_MSG_RESERVE;
    if (m->qn >= cap)
        heap_purge(m);
    if (m->qn >= cap) {
        m->st.drop_queue++;
        return 0;
    }
    m->q[m->qn] = *e;
    m->q[m->qn].seq = m->qseq++;
    heap_up(m, m->qn++);
    if ((uint32_t)m->qn > m->st.max_queue)
        m->st.max_queue = (uint32_t)m->qn;
    return 1;
}

static void heap_pop(mfx_t *m, mfx_ev_t *out)
{
    *out = m->q[0];
    m->q[0] = m->q[--m->qn];
    heap_down(m, 0);
}

/* ---- output ---- */

static void out_msg(mfx_t *m, uint32_t t, int ports, uint8_t b0, uint8_t b1, uint8_t b2, int len)
{
    uint8_t msg[3] = {b0, b1, b2};
    for (int p = 0; p < 3; p++)
        if (ports & (1 << p)) {
            m->emit(m->ctx, t, p, msg, len);
            m->st.out_msgs++;
        }
}

static int ch_audible(const mfx_t *m, int ch)
{
    uint32_t bit = 1u << ch;
    if (GP(m, MFX_G_SOLO))
        return (GP(m, MFX_G_SOLO) & bit) != 0;
    return !(GP(m, MFX_G_MUTE) & bit);
}

/* Another sounding voice on port p with v's channel and pitch? */
static int key_shared(const mfx_t *m, const mfx_voice_t *v, int p)
{
    for (int i = 0; i < MFX_VOICES; i++) {
        const mfx_voice_t *o = &m->v[i];
        if (o != v && o->state == V_ON && o->ch == v->ch && o->pitch == v->pitch && (o->ports & (1 << p)))
            return 1;
    }
    return 0;
}

static void voice_free(mfx_t *m, mfx_voice_t *v)
{
    if (v->state == V_ON)
        m->n_on--;
    if (v->state != V_FREE)
        m->n_used--;
    v->state = V_FREE;
    v->gen++;
}

/* Sends the off (where no other voice still holds the key) and frees. */
static void voice_end(mfx_t *m, mfx_voice_t *v, uint32_t t)
{
    if (v->state == V_ON) {
        for (int p = 0; p < 3; p++)
            if ((v->ports & (1 << p)) && !key_shared(m, v, p))
                out_msg(m, t, 1 << p, (uint8_t)(0x80 | v->ch), v->pitch, 0, 3);
        if (v->hist_seq) {
            mfx_hist_t *h = &m->hist[v->hist_seq % MFX_HIST];
            if (h->seq == v->hist_seq && h->open) {
                h->off_t = t;
                h->open = 0;
            }
        }
    }
    voice_free(m, v);
}

static void voice_start(mfx_t *m, mfx_voice_t *v, uint32_t t)
{
    if ((m->loop.active && v->kind != K_LOOP && v->kind != K_THRU) || !ch_audible(m, v->ch)) {
        if (!ch_audible(m, v->ch))
            m->st.muted++;
        voice_free(m, v);
        return;
    }
    for (int p = 0; p < 3; p++)
        if (v->ports & (1 << p)) {
            if (key_shared(m, v, p)) /* retrigger: the key is already sounding */
                out_msg(m, t, 1 << p, (uint8_t)(0x80 | v->ch), v->pitch, 0, 3);
            out_msg(m, t, 1 << p, (uint8_t)(0x90 | v->ch), v->pitch, v->vel, 3);
        }
    v->state = V_ON;
    v->on_t = t;
    m->n_on++;
    if ((uint32_t)m->n_on > m->st.max_voices)
        m->st.max_voices = (uint32_t)m->n_on;
    v->hist_seq = 0;
    if (v->kind != K_LOOP && v->kind != K_THRU) {
        uint32_t seq = ++m->hist_seq;
        if (!seq)
            seq = ++m->hist_seq;
        mfx_hist_t *h = &m->hist[seq % MFX_HIST];
        h->seq = seq;
        h->on_t = t;
        h->off_t = t;
        h->open = 1;
        h->ch = v->ch;
        h->pitch = v->pitch;
        h->vel = v->vel;
        h->ports = v->ports;
        v->hist_seq = seq;
    }
    /* a provisional end already in the past (a tiny cap): next advance */
}

static mfx_voice_t *voice_alloc(mfx_t *m)
{
    for (int i = 0; i < MFX_VOICES; i++)
        if (m->v[i].state == V_FREE) {
            mfx_voice_t *v = &m->v[i];
            v->state = V_PENDING;
            v->flags = 0;
            v->owner = 0;
            v->lmul = QONE;
            v->cap = 0;
            v->hist_seq = 0;
            m->n_used++;
            return v;
        }
    m->st.drop_voice++;
    return 0;
}

/* How a voice ends: fixed length, or open (owner) with lmul/cap. */
typedef struct {
    uint32_t fixed;  /* > 0: fixed length in us */
    uint32_t lmul;   /* QONE multiplier of the owner's length */
    uint32_t cap;    /* 0 or the longest it may get (us) */
    uint16_t owner;
} lenrule_t;

static void voice_set_len(mfx_t *m, mfx_voice_t *v, uint32_t on, const lenrule_t *r)
{
    if (r->fixed) {
        v->off_t = on + (r->fixed > MAX_LEN ? MAX_LEN : r->fixed);
        v->flags = VF_OFFK;
    } else {
        v->owner = r->owner;
        v->lmul = r->lmul;
        v->cap = r->cap > MAX_LEN ? MAX_LEN : r->cap;
        v->flags = VF_OPEN;
        if (v->cap) {
            v->off_t = on + v->cap;
            v->flags |= VF_OFFK;
        }
    }
    (void)m;
}

/* A voice whose note-on is due at t_on (scheduled). */
static void voice_schedule(mfx_t *m, uint32_t t_on, int kind, int track, int ch, int pitch, int vel, int ports,
                           const lenrule_t *r)
{
    mfx_voice_t *v = voice_alloc(m);
    if (!v)
        return;
    v->kind = (uint8_t)kind;
    v->track = (uint8_t)track;
    v->ch = (uint8_t)ch;
    v->pitch = (uint8_t)pitch;
    v->vel = (uint8_t)vel;
    v->ports = (uint8_t)ports;
    v->on_t = t_on;
    voice_set_len(m, v, t_on, r);
    mfx_ev_t e;
    zero(&e, sizeof e);
    e.t = t_on;
    e.kind = EV_VOICE;
    e.a = (uint16_t)(v - m->v);
    e.b = v->gen;
    if (!heap_push(m, &e))
        voice_free(m, v);
}

/* ---- the grid ---- */

static uint32_t int_uspq(const mfx_t *m)
{
    return 60000000u / (uint32_t)GP(m, MFX_G_BPM);
}

static uint32_t int_tick_time(const mfx_t *m, int64_t n)
{
    return m->anchor_t + (uint32_t)(mul64(n - m->anchor_tick, m->uspq) / 24);
}

static uint32_t ext_timeout(const mfx_t *m)
{
    uint32_t t = 3u * (m->uspq / 24u) + 20000u;
    return t < 100000u ? 100000u : t;
}

/* Position at time t, in clocks << 8 (t at or after the last tick). */
static int64_t pos_q8(const mfx_t *m, uint32_t t)
{
    int64_t base = mul64(m->ticks, MFX_CLK_PER_TICK * 256);
    int32_t dt = (int32_t)(t - m->last_tick_t);
    if (dt <= 0)
        return base;
    int64_t frac = mul64(dt, MFX_PPQN * 256) / m->uspq;
    if (frac > MFX_CLK_PER_TICK * 256 - 1)
        frac = MFX_CLK_PER_TICK * 256 - 1;
    return base + frac;
}

int64_t mfx_pos(const mfx_t *m, uint32_t now)
{
    return pos_q8(m, now) >> 8;
}

/* Time of a position (clocks << 8): from the tick history when it's
 * past, extrapolated with the current tempo otherwise. */
static uint32_t time_of_q8(const mfx_t *m, int64_t pq)
{
    int64_t ref = mul64(m->ticks, MFX_CLK_PER_TICK * 256);
    int64_t aref = mul64(m->anchor_tick, MFX_CLK_PER_TICK * 256);
    if (!m->ext && pq >= aref) /* the internal clock: exact from its anchor */
        return m->anchor_t + (uint32_t)(mul64(pq - aref, m->uspq) / (MFX_PPQN * 256));
    if (pq >= ref) {
        if (m->ext && m->fit_ok) { /* the fitted line, not the last (jittery) arrival */
            int64_t fref = mul64(m->fit_tick, MFX_CLK_PER_TICK * 256);
            return m->fit_t + (uint32_t)(mul64(pq - fref, m->uspq) / (MFX_PPQN * 256));
        }
        return m->last_tick_t + (uint32_t)(mul64(pq - ref, m->uspq) / (MFX_PPQN * 256));
    }
    int64_t n = pq / (MFX_CLK_PER_TICK * 256);
    if (pq < 0 && pq % (MFX_CLK_PER_TICK * 256))
        n--;
    if (m->ticks - n < MFX_TICK_HIST - 1 && n >= 0) {
        int64_t rem = pq - mul64(n, MFX_CLK_PER_TICK * 256);
        return m->th[n % MFX_TICK_HIST] + (uint32_t)(mul64(rem, m->uspq) / (MFX_PPQN * 256));
    }
    return m->last_tick_t - (uint32_t)(mul64(ref - pq, m->uspq) / (MFX_PPQN * 256));
}

/* ---- compensation delay D ---- */

static void update_D(mfx_t *m)
{
    uint32_t worst = 0;
    for (int tr = 0; tr < MFX_TRACKS; tr++) {
        const int32_t *p = m->tp[tr];
        if (!p[MFX_P_CHANNEL])
            continue;
        int32_t neg = 0;
        if (p[MFX_P_SHIFT_ON] && p[MFX_P_SHIFT] < 0)
            neg += -p[MFX_P_SHIFT];
        if (p[MFX_P_SWING_ON] && p[MFX_P_SWING] < 0)
            neg += -p[MFX_P_SWING];
        if (p[MFX_P_GRV_ON]) {
            int32_t lo = 0;
            for (int s = 0; s < MFX_STEPS; s++)
                if (p[MFX_P_GRV_CLK0 + s] < lo)
                    lo = p[MFX_P_GRV_CLK0 + s];
            neg += -lo;
        }
        uint32_t us = (uint32_t)c2us(m, neg);
        if (p[MFX_P_HUM_ON])
            us += (uint32_t)p[MFX_P_HUM_TIME] * 1000u;
        if (us > worst)
            worst = us;
    }
    m->D = worst;
    m->D_uspq = m->uspq;
}

uint32_t mfx_comp_delay(const mfx_t *m)
{
    return m->D;
}

/* ---- tracks and routing ---- */

static int match_track(const mfx_t *m, int ch)
{
    for (int tr = 0; tr < MFX_TRACKS; tr++)
        if (m->tp[tr][MFX_P_CHANNEL] == ch + 1)
            return tr;
    for (int tr = 0; tr < MFX_TRACKS; tr++)
        if (m->tp[tr][MFX_P_CHANNEL] == 17)
            return tr;
    return -1;
}

static int track_ports(const mfx_t *m, int tr)
{
    if (tr >= 0 && tr < MFX_TRACKS && m->tp[tr][MFX_P_OUT_PORTS])
        return m->tp[tr][MFX_P_OUT_PORTS];
    return GP(m, MFX_G_OUT_PORTS);
}

static int track_ch(const mfx_t *m, int tr, int ch)
{
    if (tr >= 0 && tr < MFX_TRACKS && m->tp[tr][MFX_P_OUT_CH])
        return m->tp[tr][MFX_P_OUT_CH] - 1;
    return ch;
}

static int clock_ports(const mfx_t *m)
{
    int p = GP(m, MFX_G_OUT_PORTS);
    for (int tr = 0; tr < MFX_TRACKS; tr++)
        if (m->tp[tr][MFX_P_CHANNEL])
            p |= track_ports(m, tr);
    return p;
}

static void sched_msg(mfx_t *m, uint32_t t, int ports, const uint8_t *b, int len)
{
    mfx_ev_t e;
    zero(&e, sizeof e);
    e.t = t;
    e.kind = EV_MSG;
    e.ports = (uint8_t)ports;
    e.len = (uint8_t)len;
    for (int i = 0; i < len && i < 3; i++)
        e.d[i] = b[i];
    heap_push(m, &e);
}

/* ---- scales ---- */

static const uint16_t scale_mask[MFX_SCALES] = {
    0xAB5, /* major       C D E F G A B */
    0x5AD, /* minor       C D Eb F G Ab Bb */
    0x6AD, /* dorian */
    0x5AB, /* phrygian */
    0xAD5, /* lydian */
    0x6B5, /* mixolydian */
    0x56B, /* locrian */
    0x9AD, /* harmonic minor */
    0xAAD, /* melodic minor */
    0x295, /* pentatonic major */
    0x4A9, /* pentatonic minor */
    0x4E9, /* blues */
    0x555, /* whole tone */
};

/* Nearest scale tone (ties go down). */
static int quantize(int pitch, int scale, int root)
{
    uint16_t mask = scale_mask[scale];
    for (int d = 0; d < 12; d++) {
        int lo = pitch - d, hi = pitch + d;
        if (lo >= 0 && (mask >> (((lo - root) % 12 + 12) % 12) & 1))
            return lo;
        if (hi < 128 && (mask >> (((hi - root) % 12 + 12) % 12) & 1))
            return hi;
    }
    return pitch;
}

/* The pitches one input note becomes before the arp: itself, octaver,
 * harmony 1 and 2; then note offset and scale. Duplicates removed;
 * out-of-range ones dropped. */
static int note_pitches(mfx_t *m, int tr, int pitch, int out[4])
{
    const int32_t *p = m->tp[tr];
    int cand[4], n = 0, k = 0;
    cand[n++] = pitch;
    if (p[MFX_P_HARM_ON]) {
        if (p[MFX_P_OCTAVER])
            cand[n++] = pitch + 12 * p[MFX_P_OCTAVER];
        if (p[MFX_P_HARM1])
            cand[n++] = pitch + p[MFX_P_HARM1];
        if (p[MFX_P_HARM2])
            cand[n++] = pitch + p[MFX_P_HARM2];
    }
    for (int i = 0; i < n; i++) {
        int x = cand[i];
        if (p[MFX_P_NOTE_ON])
            x += p[MFX_P_NOTE_OFS];
        if (x < 0 || x > 127) {
            m->st.drop_range++;
            continue;
        }
        if (p[MFX_P_SCALE_ON])
            x = quantize(x, p[MFX_P_SCALE], p[MFX_P_ROOT]);
        int dup = 0;
        for (int j = 0; j < k; j++)
            if (out[j] == x)
                dup = 1;
        if (!dup)
            out[k++] = x;
    }
    return k;
}

/* ---- MIDI delay chains ---- */

static mfx_chain_t *chain_alloc(mfx_t *m)
{
    for (int i = 0; i < MFX_CHAINS; i++)
        if (!m->chain[i].used) {
            mfx_chain_t *c = &m->chain[i];
            c->used = 1;
            c->flags = 0;
            c->owner = 0;
            return c;
        }
    m->st.drop_chain++;
    return 0;
}

static void chain_cancel(mfx_t *m, mfx_chain_t *c)
{
    (void)m;
    c->used = 0;
    c->gen++;
}

static void chain_start(mfx_t *m, int tr, uint32_t t0, int ch, int pitch, int vel, int ports, const lenrule_t *r)
{
    const int32_t *p = m->tp[tr];
    if (m->loop.active)
        return;
    mfx_chain_t *c = chain_alloc(m);
    if (!c)
        return;
    c->track = (uint8_t)tr;
    c->ch = (uint8_t)ch;
    c->pitch = (uint8_t)pitch;
    c->ports = (uint8_t)ports;
    c->total = c->remaining = (uint8_t)p[MFX_P_DLY_REPEAT];
    c->vel = (int16_t)(vel * p[MFX_P_DLY_LEVEL] / 100);
    c->delay = (uint32_t)c2us(m, p[MFX_P_DLY_TIME]);
    c->gmul = pct_q(100 + p[MFX_P_FB_GATE]);
    if (r->fixed) {
        c->base_len = r->fixed;
        c->flags = CF_LEN;
    } else {
        c->owner = r->owner;
        c->lmul0 = r->lmul;
        c->cap0 = r->cap;
    }
    mfx_ev_t e;
    zero(&e, sizeof e);
    e.t = t0 + c->delay;
    e.kind = EV_ECHO;
    e.a = (uint16_t)(c - m->chain);
    e.b = c->gen;
    if (!heap_push(m, &e))
        chain_cancel(m, c);
}

/* Repeat number total-remaining+1 is due at t. */
static void chain_step(mfx_t *m, mfx_chain_t *c, uint32_t t)
{
    const int32_t *p = m->tp[c->track];
    int pitch = c->pitch;
    if (p[MFX_P_FB_NOTE] == MFX_FB_NOTE_RND)
        pitch += rnd_range(m, -12, 12);
    else
        pitch += p[MFX_P_FB_NOTE];
    int vel = c->vel;
    if (pitch >= 0 && pitch <= 127) {
        c->pitch = (uint8_t)pitch;
        int out = p[MFX_P_SCALE_ON] ? quantize(pitch, p[MFX_P_SCALE], p[MFX_P_ROOT]) : pitch;
        if (vel >= 1) {
            lenrule_t r;
            zero(&r, sizeof r);
            uint32_t ml = min_len(m);
            if (c->flags & CF_LEN) {
                r.fixed = mul_q(c->base_len, c->gmul);
                if (r.fixed < ml)
                    r.fixed = ml;
            } else {
                r.owner = c->owner;
                r.lmul = mul_qq(c->lmul0, c->gmul);
                r.cap = c->cap0 ? mul_q(c->cap0, c->gmul) : 0;
                if (c->cap0 && r.cap < ml)
                    r.cap = ml;
            }
            mfx_voice_t *v = voice_alloc(m);
            if (v) {
                v->kind = K_ECHO;
                v->track = c->track;
                v->ch = c->ch;
                v->pitch = (uint8_t)out;
                v->vel = (uint8_t)(vel > 127 ? 127 : vel);
                v->ports = c->ports;
                v->on_t = t;
                voice_set_len(m, v, t, &r);
                voice_start(m, v, t);
            }
        }
    } else {
        m->st.drop_range++;
    }
    /* next repeat */
    c->vel = (int16_t)clampi(c->vel + p[MFX_P_FB_VEL], -1000, 1000);
    c->gmul = mul_qq(c->gmul, pct_q(100 + p[MFX_P_FB_GATE]));
    if (c->remaining)
        c->remaining--;
    if (!c->remaining) {
        chain_cancel(m, c);
        return;
    }
    uint32_t d = mul_q(c->delay, pct_q(100 + p[MFX_P_FB_CLOCK]));
    if (d < 1000u)
        d = 1000u;
    c->delay = d;
    mfx_ev_t e;
    zero(&e, sizeof e);
    e.t = t + d;
    e.kind = EV_ECHO;
    e.a = (uint16_t)(c - m->chain);
    e.b = c->gen;
    if (!heap_push(m, &e))
        chain_cancel(m, c);
}

/* ---- the note group: everything after the arp ---- */

static int groove_step(int64_t posc)
{
    int64_t s = (posc + 60) / 120;
    return (int)(((s % MFX_STEPS) + MFX_STEPS) % MFX_STEPS);
}

/*
 * pitches[] played at nominal time t (grid position posc) on track tr.
 * fixed_len > 0: the notes' length is known (arp); else they're open,
 * owned by input note `owner`.
 */
static void emit_group(mfx_t *m, int tr, uint32_t t, int64_t posc, int ch, const int *pitches, int n, int vel,
                       uint16_t owner, int kind, uint32_t fixed_len)
{
    const int32_t *p = m->tp[tr];
    if (p[MFX_P_HUM_ON] && p[MFX_P_PROB] < 100) {
        if ((int32_t)(rnd(m) % 100u) >= p[MFX_P_PROB]) {
            m->st.prob_skip++;
            return;
        }
    }
    int step = groove_step(posc);
    int grv = p[MFX_P_GRV_ON] != 0;

    /* velocity */
    int32_t v = vel;
    if (p[MFX_P_VEL_ON]) {
        v = v * p[MFX_P_VEL_SCALE] / 100;
        v = v + (64 - v) * p[MFX_P_VEL_COMP] / 100;
        v += p[MFX_P_VEL_OFS];
        if (p[MFX_P_VEL_RAND])
            v += rnd_range(m, -p[MFX_P_VEL_RAND], p[MFX_P_VEL_RAND]);
    }
    if (grv)
        v = v * p[MFX_P_GRV_VEL0 + step] / 100;
    v = clampi(v, 1, 127);

    /* timing */
    int32_t off_clk = 0;
    if (p[MFX_P_SWING_ON] && p[MFX_P_SWING]) {
        int grid = p[MFX_P_SWING_GRID] ? 120 : 240;
        int64_t idx = (posc + grid / 2) / grid;
        if (idx & 1)
            off_clk += p[MFX_P_SWING];
    }
    if (grv)
        off_clk += p[MFX_P_GRV_CLK0 + step];
    if (p[MFX_P_SHIFT_ON])
        off_clk += p[MFX_P_SHIFT];
    int32_t off_us = c2us(m, off_clk);
    if (p[MFX_P_HUM_ON] && p[MFX_P_HUM_TIME])
        off_us += rnd_range(m, -p[MFX_P_HUM_TIME] * 1000, p[MFX_P_HUM_TIME] * 1000);
    int32_t total = (int32_t)m->D + off_us;
    uint32_t t_on = t + (uint32_t)(total > 0 ? total : 0);

    /* gate */
    uint32_t gm = QONE;
    if (p[MFX_P_GATE_ON])
        gm = mul_q(gm, pct_q(p[MFX_P_GATE]));
    if (grv)
        gm = mul_q(gm, pct_q(p[MFX_P_GRV_GATE0 + step]));
    uint32_t ml = min_len(m);
    lenrule_t r;
    zero(&r, sizeof r);
    if (fixed_len) {
        r.fixed = mul_q(fixed_len, gm);
        if (r.fixed < ml)
            r.fixed = ml;
    } else {
        r.owner = owner;
        if (gm >= QONE) {
            r.lmul = gm;
        } else {
            /* can't know the played length yet: cap at gate% of a quarter */
            r.lmul = QONE;
            r.cap = mul_q(m->uspq, gm);
            if (r.cap < ml)
                r.cap = ml;
        }
    }

    int ports = track_ports(m, tr);
    int och = track_ch(m, tr, ch);
    int uni = p[MFX_P_HARM_ON] ? p[MFX_P_UNISON] : 1;
    for (int i = 0; i < n; i++) {
        int x = pitches[i];
        if (grv)
            x += p[MFX_P_GRV_NOTE0 + step];
        if (x < 0 || x > 127) {
            m->st.drop_range++;
            continue;
        }
        for (int u = 0; u < uni; u++)
            voice_schedule(m, t_on + (uint32_t)u * UNISON_US, kind, tr, och, x, v, ports, &r);
        if (p[MFX_P_DLY_ON] && p[MFX_P_DLY_REPEAT] > 0)
            chain_start(m, tr, t_on, och, x, v, ports, &r);
    }
}

/* ---- input notes ---- */

static mfx_held_t *held_find(mfx_t *m, int in_port, int ch, int pitch)
{
    for (int i = 0; i < MFX_HELD; i++) {
        mfx_held_t *h = &m->held[i];
        if (h->used && h->in_port == in_port && h->ch == ch && h->pitch == pitch)
            return h;
    }
    return 0;
}

/* The input note `inst` ended after L us: every open voice and chain it
 * owns gets its length. */
static void resolve_owner(mfx_t *m, uint16_t inst, uint32_t L, uint32_t now)
{
    uint32_t ml = min_len(m);
    for (int i = 0; i < MFX_VOICES; i++) {
        mfx_voice_t *v = &m->v[i];
        if (v->state == V_FREE || !(v->flags & VF_OPEN) || v->owner != inst)
            continue;
        uint64_t len = mul_q(L, v->lmul);
        if (v->cap && len > v->cap)
            len = v->cap;
        if (len < ml)
            len = ml;
        uint32_t off = v->on_t + (uint32_t)(len > MAX_LEN ? MAX_LEN : len);
        if (v->state == V_ON && TLT(off, now))
            off = now;
        if ((v->flags & VF_OFFK) && TLT(v->off_t, off))
            off = v->off_t; /* the cap came first */
        if (v->state == V_ON && TLT(off, now))
            off = now;
        v->off_t = off;
        v->flags = VF_OFFK;
        v->owner = 0;
    }
    for (int i = 0; i < MFX_CHAINS; i++) {
        mfx_chain_t *c = &m->chain[i];
        if (!c->used || (c->flags & CF_LEN) || c->owner != inst)
            continue;
        uint64_t len = mul_q(L, c->lmul0);
        if (c->cap0 && len > c->cap0)
            len = c->cap0;
        if (len < ml)
            len = ml;
        c->base_len = (uint32_t)(len > MAX_LEN ? MAX_LEN : len);
        c->flags |= CF_LEN;
        c->owner = 0;
    }
}

/* ---- arpeggiator ---- */

static int arp_phys_held(const mfx_t *m, int tr, const mfx_held_t *except)
{
    int n = 0;
    for (int i = 0; i < MFX_HELD; i++) {
        const mfx_held_t *h = &m->held[i];
        if (h != except && h->used && h->track == tr && (h->flags & HF_ARP))
            n++;
    }
    return n;
}

static void arp_add(mfx_t *m, int tr, const mfx_held_t *h, const int *pitches, int n, int vel)
{
    mfx_arp_t *a = &m->arp[tr];
    if (m->tp[tr][MFX_P_ARP_LATCH] && arp_phys_held(m, tr, h) == 0)
        a->count = 0; /* latched: a new chord replaces the old one */
    if (a->count == 0)
        a->idx = 0;
    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < a->count; j++)
            if (a->n[j].pitch == pitches[i] && a->n[j].ch == h->ch)
                found = j;
        if (found < 0) {
            if (a->count >= MFX_ARP_MAX)
                continue;
            found = a->count++;
        }
        a->n[found].pitch = (uint8_t)pitches[i];
        a->n[found].vel = (uint8_t)vel;
        a->n[found].ch = h->ch;
        a->n[found].inst = h->inst;
        a->n[found].order = a->order_ctr++;
    }
}

static void arp_remove_inst(mfx_t *m, int tr, uint16_t inst)
{
    mfx_arp_t *a = &m->arp[tr];
    int j = 0;
    for (int i = 0; i < a->count; i++)
        if (a->n[i].inst != inst)
            a->n[j++] = a->n[i];
    a->count = j;
    if (!a->count)
        a->idx = 0;
}

/* Drops arp notes whose key is no longer held (latch turned off, stop). */
static void arp_prune(mfx_t *m, int tr)
{
    mfx_arp_t *a = &m->arp[tr];
    int j = 0;
    for (int i = 0; i < a->count; i++) {
        int held = 0;
        for (int k = 0; k < MFX_HELD; k++)
            if (m->held[k].used && m->held[k].inst == a->n[i].inst)
                held = 1;
        if (held)
            a->n[j++] = a->n[i];
    }
    a->count = j;
    if (!a->count)
        a->idx = 0;
}

static void arp_step(mfx_t *m, int tr, uint32_t t, int64_t posc)
{
    mfx_arp_t *a = &m->arp[tr];
    const int32_t *p = m->tp[tr];
    int n = a->count;
    if (!n)
        return;
    /* the notes in pitch order (or played order) */
    mfx_arp_note_t s[MFX_ARP_MAX];
    for (int i = 0; i < n; i++) {
        mfx_arp_note_t x = a->n[i];
        int j = i;
        while (j > 0) {
            int less = p[MFX_P_ARP_MODE] == MFX_ARP_ORDER ? (uint8_t)(x.order - a->order_ctr) < (uint8_t)(s[j - 1].order - a->order_ctr)
                                                           : x.pitch < s[j - 1].pitch;
            if (!less)
                break;
            s[j] = s[j - 1];
            j--;
        }
        s[j] = x;
    }
    int oct = p[MFX_P_ARP_OCT];
    uint32_t total = (uint32_t)(n * oct);
    uint32_t k;
    switch (p[MFX_P_ARP_MODE]) {
    case MFX_ARP_DOWN:
        k = total - 1u - a->idx % total;
        break;
    case MFX_ARP_UPDOWN: {
        uint32_t per = total > 1 ? 2u * total - 2u : 1u;
        k = a->idx % per;
        if (k >= total)
            k = per - k;
        break;
    }
    case MFX_ARP_RANDOM:
        k = rnd(m) % total;
        break;
    default:
        k = a->idx % total;
        break;
    }
    a->idx++;
    const mfx_arp_note_t *x = &s[k % (uint32_t)n];
    int pitch = x->pitch + 12 * (int)(k / (uint32_t)n);
    if (pitch > 127) {
        m->st.drop_range++;
        return;
    }
    uint32_t len = (uint32_t)c2us(m, mul64(mfx_arp_rate_clk[p[MFX_P_ARP_RATE]], p[MFX_P_ARP_GATE]) / 100);
    if (!len)
        len = 1;
    emit_group(m, tr, t, posc, x->ch, &pitch, 1, x->vel, 0, K_ARP, len);
}

/* ---- the loop / beat repeat / remix ---- */

static const int8_t pat_one[1] = {0};
static const int8_t pat_rev[16] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
static const int8_t pat_1133[16] = {0, 0, 2, 2, 4, 4, 6, 6, 8, 8, 10, 10, 12, 12, 14, 14};
static const int8_t pat_skip[16] = {0, -1, 2, -1, 4, -1, 6, -1, 8, -1, 10, -1, 12, -1, 14, -1};
static const int8_t pat_roll[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 12, 12};
static const int8_t pat_shuf[16] = {0, 3, 2, 1, 4, 7, 6, 5, 8, 11, 10, 9, 12, 15, 14, 13};
static const int8_t pat_half[16] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7};

static int64_t slot_pos_q8(const mfx_t *m, uint32_t k)
{
    const mfx_loop_t *L = &m->loop;
    return L->base_q8 + mul64(mul64(k, L->slot_len * 256), L->stretch) / 100;
}

static uint32_t slot_time(const mfx_t *m, uint32_t k)
{
    return time_of_q8(m, slot_pos_q8(m, k)) + m->D;
}

static void loop_play_slot(mfx_t *m, uint32_t k, uint32_t t_min)
{
    mfx_loop_t *L = &m->loop;
    int slice = L->pattern[k % (uint32_t)L->nslots];
    if (slice < 0)
        return;
    int64_t start = slot_pos_q8(m, k);
    for (int i = 0; i < L->n; i++) {
        const mfx_loop_note_t *x = &L->notes[i];
        if (x->slice != slice)
            continue;
        int64_t on_q = start + mul64(x->off * 256, L->stretch) / 100;
        uint32_t t_on = time_of_q8(m, on_q) + m->D;
        if (TLT(t_on, t_min))
            continue;
        lenrule_t r;
        zero(&r, sizeof r);
        r.fixed = (uint32_t)c2us(m, mul64(x->len, L->stretch) / 100);
        if (r.fixed < min_len(m))
            r.fixed = min_len(m);
        voice_schedule(m, t_on, K_LOOP, TRACK_NONE, x->ch, x->pitch, x->vel, x->ports, &r);
    }
}

/* Ends the track voices (not thru) now and cancels pending ones and the
 * delay chains. */
static void flush_track_voices(mfx_t *m, uint32_t t, int only_kind)
{
    for (int i = 0; i < MFX_VOICES; i++) {
        mfx_voice_t *v = &m->v[i];
        if (v->state == V_FREE || v->kind == K_THRU)
            continue;
        if (only_kind >= 0 && v->kind != only_kind)
            continue;
        voice_end(m, v, t);
    }
    if (only_kind < 0)
        for (int i = 0; i < MFX_CHAINS; i++)
            if (m->chain[i].used)
                chain_cancel(m, &m->chain[i]);
}

static void loop_engage(mfx_t *m, uint32_t t)
{
    mfx_loop_t *L = &m->loop;
    int type = GP(m, MFX_G_LOOP_TYPE);
    static const int16_t rpt_len[4] = {240, 120, 60, 30};
    L->type = type;
    L->stretch = mfx_stretch_pct[GP(m, MFX_G_STRETCH)];
    int64_t win;
    if (type < 4) {
        win = rpt_len[type];
        L->nslots = 1;
        L->slot_len = (int)win;
        L->pattern = pat_one;
    } else {
        static const int8_t *const pats[6] = {pat_rev, pat_1133, pat_skip, pat_roll, pat_shuf, pat_half};
        win = 4 * MFX_PPQN;
        L->nslots = 16;
        L->slot_len = 120;
        L->pattern = pats[type - 4];
    }
    /* the window: the last whole `win` before now (grid-aligned) */
    int64_t pos = pos_q8(m, t) >> 8;
    int64_t B = pos >= 0 ? mul64(pos / win, win) : -mul64((-pos + win - 1) / win, win);
    uint32_t tw0 = time_of_q8(m, mul64(B - win, 256)) + m->D;
    uint32_t tw1 = time_of_q8(m, mul64(B, 256)) + m->D;
    L->n = 0;
    for (uint32_t i = 0; i < MFX_HIST && L->n < MFX_LOOP_MAX; i++) {
        uint32_t seq = m->hist_seq - (MFX_HIST - 1) + i; /* oldest first */
        const mfx_hist_t *h = &m->hist[seq % MFX_HIST];
        if (!seq || h->seq != seq)
            continue;
        if (TLT(h->on_t, tw0) || !TLT(h->on_t, tw1))
            continue;
        int64_t rel = mul64((int32_t)(h->on_t - tw0), MFX_PPQN) / m->uspq;
        int64_t len = mul64((int32_t)((h->open ? t : h->off_t) - h->on_t), MFX_PPQN) / m->uspq;
        int slice = (int)(rel / L->slot_len);
        if (slice >= L->nslots)
            slice = L->nslots - 1;
        int64_t off = rel - mul64(slice, L->slot_len);
        if (len > L->slot_len - off)
            len = L->slot_len - off;
        if (len < 1)
            len = 1;
        mfx_loop_note_t *x = &L->notes[L->n++];
        x->slice = (uint8_t)slice;
        x->off = (uint16_t)off;
        x->len = (uint16_t)len;
        x->ch = h->ch;
        x->pitch = h->pitch;
        x->vel = h->vel;
        x->ports = h->ports;
    }
    flush_track_voices(m, t, -1);
    L->active = 1;
    L->base_q8 = B * 256;
    /* skip the slots already over; play what's left of the current one */
    uint32_t k = 0;
    while (TLE(slot_time(m, k + 1), t))
        k++;
    loop_play_slot(m, k, t);
    L->k = k + 1;
}

static void loop_release(mfx_t *m, uint32_t t)
{
    if (!m->loop.active)
        return;
    m->loop.active = 0;
    flush_track_voices(m, t, K_LOOP);
}

/* ---- ticks ---- */

static void on_tick(mfx_t *m, uint32_t t)
{
    m->ticks++;
    m->last_tick_t = t;
    m->th[((m->ticks % MFX_TICK_HIST) + MFX_TICK_HIST) % MFX_TICK_HIST] = t;
    if (m->uspq > m->D_uspq + m->D_uspq / 64 || m->uspq + m->D_uspq / 64 < m->D_uspq)
        update_D(m);
    int64_t posc = mul64(m->ticks, MFX_CLK_PER_TICK);
    for (int tr = 0; tr < MFX_TRACKS; tr++) {
        if (!m->tp[tr][MFX_P_CHANNEL] || !m->tp[tr][MFX_P_ARP_ON])
            continue;
        int rate = mfx_arp_rate_clk[m->tp[tr][MFX_P_ARP_RATE]];
        if (posc % rate == 0)
            arp_step(m, tr, t, posc);
    }
}

static void go_internal(mfx_t *m, uint32_t t)
{
    m->ext = 0;
    m->uspq = int_uspq(m);
    m->anchor_t = t;
    m->anchor_tick = m->ticks;
    /* the first internal tick a full period after t */
    m->anchor_t = t;
    update_D(m);
}

/* ---- processing in time order ---- */

static mfx_voice_t *next_off(mfx_t *m, uint32_t *t)
{
    mfx_voice_t *best = 0;
    if (!m->n_on)
        return 0;
    for (int i = 0; i < MFX_VOICES; i++) {
        mfx_voice_t *v = &m->v[i];
        if (v->state != V_ON || !(v->flags & VF_OFFK))
            continue;
        if (!best || TLT(v->off_t, best->off_t))
            best = v;
    }
    if (best)
        *t = best->off_t;
    return best;
}

enum { H_NONE, H_OFF, H_TIMEOUT, H_TICK, H_SLOT, H_QUEUE };

void mfx_advance(mfx_t *m, uint32_t now)
{
    for (int guard = 0; guard < 200000; guard++) {
        int what = H_NONE;
        uint32_t best = 0, t;
        mfx_voice_t *off = next_off(m, &t);
        if (off) {
            best = t;
            what = H_OFF;
        }
#define CAND(tt, w)                                    \
    do {                                               \
        if (what == H_NONE || TLT((tt), best)) {       \
            best = (tt);                               \
            what = (w);                                \
        }                                              \
    } while (0)
        if (m->ext)
            CAND(m->ext_last_t + ext_timeout(m), H_TIMEOUT);
        else
            CAND(int_tick_time(m, m->ticks + 1), H_TICK);
        if (m->loop.active)
            CAND(slot_time(m, m->loop.k), H_SLOT);
        if (m->qn)
            CAND(m->q[0].t, H_QUEUE);
#undef CAND
        if (what == H_NONE || !TLE(best, now))
            break;
        /* never step backwards (a cap that was already due) */
        if (TLT(best, m->now))
            best = m->now;
        m->now = best;
        switch (what) {
        case H_OFF:
            voice_end(m, off, best);
            break;
        case H_TIMEOUT:
            go_internal(m, best);
            break;
        case H_TICK:
            on_tick(m, best);
            break;
        case H_SLOT:
            loop_play_slot(m, m->loop.k, best);
            m->loop.k++;
            break;
        case H_QUEUE: {
            mfx_ev_t e;
            heap_pop(m, &e);
            if (ev_stale(m, &e))
                break;
            if (e.kind == EV_VOICE)
                voice_start(m, &m->v[e.a], best);
            else if (e.kind == EV_ECHO)
                chain_step(m, &m->chain[e.a], best);
            else
                out_msg(m, best, e.ports, e.d[0], e.d[1], e.d[2], e.len);
            break;
        }
        }
    }
    if (TLT(m->now, now))
        m->now = now;
}

/* ---- input ---- */

static void note_off_in(mfx_t *m, uint32_t t, mfx_held_t *h)
{
    resolve_owner(m, h->inst, t - h->on_t, t);
    if (h->track >= 0 && (h->flags & HF_ARP) && !m->tp[h->track][MFX_P_ARP_LATCH])
        arp_remove_inst(m, h->track, h->inst);
    h->used = 0;
}

static void note_on_in(mfx_t *m, uint32_t t, int in_port, int ch, int pitch, int vel)
{
    mfx_held_t *h = held_find(m, in_port, ch, pitch);
    if (h) /* a repeated note-on: the first one ends here */
        note_off_in(m, t, h);
    h = 0;
    for (int i = 0; i < MFX_HELD; i++)
        if (!m->held[i].used) {
            h = &m->held[i];
            break;
        }
    if (!h) {
        m->st.drop_held++;
        return;
    }
    if (++m->inst_ctr == 0)
        m->inst_ctr = 1;
    h->used = 1;
    h->inst = m->inst_ctr;
    h->in_port = (uint8_t)in_port;
    h->ch = (uint8_t)ch;
    h->pitch = (uint8_t)pitch;
    h->on_t = t;
    h->flags = 0;
    int tr = match_track(m, ch);
    h->track = (int8_t)tr;
    if (tr < 0) { /* another channel: straight through */
        lenrule_t r;
        zero(&r, sizeof r);
        r.owner = h->inst;
        r.lmul = QONE;
        voice_schedule(m, t + m->D, K_THRU, TRACK_NONE, ch, pitch, vel, GP(m, MFX_G_OUT_PORTS), &r);
        return;
    }
    int ps[4];
    int n = note_pitches(m, tr, pitch, ps);
    if (!n)
        return;
    if (m->tp[tr][MFX_P_ARP_ON]) {
        h->flags |= HF_ARP;
        arp_add(m, tr, h, ps, n, vel);
        return;
    }
    emit_group(m, tr, t, pos_q8(m, t) >> 8, ch, ps, n, vel, h->inst, K_LIVE, 0);
}

static void flush_all(mfx_t *m, uint32_t t)
{
    loop_release(m, t);
    for (int i = 0; i < MFX_VOICES; i++)
        if (m->v[i].state != V_FREE)
            voice_end(m, &m->v[i], t);
    for (int i = 0; i < MFX_CHAINS; i++)
        if (m->chain[i].used)
            chain_cancel(m, &m->chain[i]);
}

static void transport_stop(mfx_t *m, uint32_t t)
{
    flush_all(m, t);
    for (int tr = 0; tr < MFX_TRACKS; tr++)
        arp_prune(m, tr); /* latched notes go; held keys stay */
}

static void clock_thru(mfx_t *m, uint32_t t, const uint8_t *msg, int len)
{
    if (!(GP(m, MFX_G_THRU) & MFX_THRU_CLOCK))
        return;
    uint32_t tt = t + m->D;
    if (TLT(tt, m->clock_out_t))
        tt = m->clock_out_t;
    m->clock_out_t = tt;
    sched_msg(m, tt, clock_ports(m), msg, len);
}

/*
 * Tempo from MIDI clock: a least-squares line through the arrival times of
 * the last MFX_FIT ticks (USB and the sender jitter each tick by a ms or
 * two; the fit averages that out where a first-to-last average wouldn't).
 * Two ticks in a row far off the line (a tempo jump) restart the fit.
 * The line also gives the loop its slot times (fit_t at tick fit_tick).
 */
static void ext_fit(mfx_t *m)
{
    int k = m->ext_n;
    if (k < 2)
        return;
    uint32_t t0 = m->ext_t[(m->ext_i - k + 2 * MFX_FIT) % MFX_FIT];
    int64_t sxt = 0, sxx = 0, st = 0;
    for (int i = 0; i < k; i++) {
        int64_t x = 2 * i - (k - 1);
        int64_t dt = (int32_t)(m->ext_t[(m->ext_i - k + i + 2 * MFX_FIT) % MFX_FIT] - t0);
        sxt += mul64(x, dt);
        sxx += mul64(x, x);
        st += dt;
    }
    int64_t uspq = mul64(48, sxt) / sxx; /* 24 ticks x (2 sxt / sxx) us per tick */
    if (uspq < 20000 || uspq > 6000000)
        return;
    m->uspq = (uint32_t)uspq;
    m->fit_t = t0 + (uint32_t)(st / k + sxt * (k - 1) / sxx);
    m->fit_tick = m->ticks;
    m->fit_ok = 1;
}

static void ext_tick(mfx_t *m, uint32_t t, int port)
{
    if (!m->ext) {
        m->ext = 1;
        m->ext_port = port;
        m->ext_n = m->ext_i = 0;
        m->ext_off = 0;
        m->fit_ok = 0;
    } else if (m->ext_n >= 4) {
        uint32_t iv = t - m->ext_last_t, est = m->uspq / 24u;
        if (iv > est + est / 3 || iv + est / 3 < est) {
            if (++m->ext_off >= 2) { /* a new tempo: keep only the last tick */
                uint32_t last = m->ext_last_t;
                m->ext_n = m->ext_i = 0;
                m->ext_t[m->ext_i++] = last;
                m->ext_n = 1;
                m->ext_off = 0;
            }
        } else {
            m->ext_off = 0;
        }
    }
    m->ext_t[m->ext_i] = t;
    m->ext_i = (m->ext_i + 1) % MFX_FIT;
    if (m->ext_n < MFX_FIT)
        m->ext_n++;
    m->ext_last_t = t;
    if (m->pending_pos >= 0) {
        m->ticks = m->pending_pos - 1;
        m->pending_pos = -1;
    }
    m->ticks++;
    ext_fit(m);
    m->ticks--;
    on_tick(m, t);
}

void mfx_input(mfx_t *m, uint32_t now, int in_port, const uint8_t *msg, int len)
{
    mfx_advance(m, now);
    m->st.in_msgs++;
    if (len < 1)
        return;
    uint8_t s = msg[0];
    /* A note-off always reaches a note already held, even if its port was
     * switched off meanwhile: otherwise that note would hang. */
    if (len >= 3 && ((s & 0xF0) == 0x80 || ((s & 0xF0) == 0x90 && msg[2] == 0))) {
        mfx_held_t *h = held_find(m, in_port, s & 15, msg[1] & 127);
        if (h)
            note_off_in(m, now, h);
        mfx_advance(m, now);
        return;
    }
    if (!(GP(m, MFX_G_IN_PORTS) & (1 << in_port)))
        return;
    if (s >= 0xF8) {
        /* realtime: the clock follows one port (the first one heard) */
        if (m->ext && in_port != m->ext_port && (s == 0xF8 || s == 0xFA || s == 0xFB || s == 0xFC))
            return;
        switch (s) {
        case 0xF8:
            ext_tick(m, now, in_port);
            clock_thru(m, now, msg, 1);
            break;
        case 0xFA:
            m->pending_pos = 0;
            clock_thru(m, now, msg, 1);
            break;
        case 0xFB:
            clock_thru(m, now, msg, 1);
            break;
        case 0xFC:
            transport_stop(m, now);
            clock_thru(m, now, msg, 1);
            break;
        default:
            break; /* active sensing, reset: not passed */
        }
        mfx_advance(m, now);
        return;
    }
    if (s == 0xF2 && len >= 3) {
        m->pending_pos = mul64((int64_t)msg[1] | (int64_t)msg[2] << 7, 6);
        clock_thru(m, now, msg, 3);
        mfx_advance(m, now);
        return;
    }
    if (s < 0x80 || s >= 0xF0)
        return; /* SysEx and system common: dropped */
    int ch = s & 15, type = s & 0xF0;
    if ((type == 0x90 || type == 0x80) && len >= 3) {
        if (type == 0x90 && msg[2] > 0) {
            note_on_in(m, now, in_port, ch, msg[1] & 127, msg[2]);
        } else {
            mfx_held_t *h = held_find(m, in_port, ch, msg[1] & 127);
            if (h)
                note_off_in(m, now, h);
        }
        mfx_advance(m, now);
        return;
    }
    int bit = type == 0xB0 ? MFX_THRU_CC : type == 0xE0 ? MFX_THRU_PB : (type == 0xD0 || type == 0xA0) ? MFX_THRU_AT : MFX_THRU_PC;
    if (!(GP(m, MFX_G_THRU) & bit))
        return;
    int tr = match_track(m, ch);
    int32_t d = (int32_t)m->D;
    if (tr >= 0 && m->tp[tr][MFX_P_SHIFT_ON])
        d += c2us(m, m->tp[tr][MFX_P_SHIFT]);
    uint8_t b[3] = {(uint8_t)(type | track_ch(m, tr, ch)), len > 1 ? msg[1] : 0, len > 2 ? msg[2] : 0};
    int n = (type == 0xC0 || type == 0xD0) ? 2 : 3;
    sched_msg(m, now + (uint32_t)(d > 0 ? d : 0), track_ports(m, tr), b, n);
    mfx_advance(m, now);
}

/* ---- parameters ---- */

static const int8_t grv_presets[MFX_GRV_PRESETS][4][MFX_STEPS] = {
    /* flat */
    {{0}, {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100},
     {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}, {0}},
    /* shuffle: late off-beat 16ths, soft */
    {{0, 40, 0, 40, 0, 40, 0, 40, 0, 40, 0, 40, 0, 40, 0, 40},
     {100, 80, 100, 80, 100, 80, 100, 80, 100, 80, 100, 80, 100, 80, 100, 80},
     {110, 80, 100, 80, 110, 80, 100, 80, 110, 80, 100, 80, 110, 80, 100, 80}, {0}},
    /* push: off-beats early, accents ahead */
    {{0, -10, -15, -10, 0, -10, -15, -10, 0, -10, -15, -10, 0, -10, -15, -10},
     {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100},
     {115, 90, 105, 90, 115, 90, 105, 90, 115, 90, 105, 90, 115, 90, 105, 90}, {0}},
    /* lazy: backbeats late, long */
    {{0, 10, 5, 15, 30, 10, 5, 15, 0, 10, 5, 15, 30, 10, 5, 15},
     {120, 110, 110, 110, 125, 110, 110, 110, 120, 110, 110, 110, 125, 110, 110, 110},
     {100, 85, 95, 85, 120, 85, 95, 85, 100, 85, 95, 85, 120, 85, 95, 85}, {0}},
    /* funk */
    {{0, 20, 0, 30, 0, 20, 10, 30, 0, 20, 0, 30, 0, 20, 10, 30},
     {80, 60, 120, 60, 80, 60, 120, 60, 80, 60, 120, 60, 80, 60, 120, 60},
     {125, 60, 90, 75, 110, 60, 95, 75, 125, 60, 90, 75, 110, 60, 95, 75},
     {0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 12, 0}},
    /* staccato off-beats */
    {{0}, {100, 40, 70, 40, 100, 40, 70, 40, 100, 40, 70, 40, 100, 40, 70, 40},
     {110, 90, 100, 90, 110, 90, 100, 90, 110, 90, 100, 90, 110, 90, 100, 90}, {0}},
};

static void load_groove(mfx_t *m, int tr, int preset)
{
    for (int s = 0; s < MFX_STEPS; s++) {
        m->tp[tr][MFX_P_GRV_CLK0 + s] = grv_presets[preset][0][s];
        m->tp[tr][MFX_P_GRV_GATE0 + s] = (uint8_t)grv_presets[preset][1][s];
        m->tp[tr][MFX_P_GRV_VEL0 + s] = (uint8_t)grv_presets[preset][2][s];
        m->tp[tr][MFX_P_GRV_NOTE0 + s] = grv_presets[preset][3][s];
    }
}

static void mute_flush(mfx_t *m, uint32_t t)
{
    for (int i = 0; i < MFX_VOICES; i++)
        if (m->v[i].state == V_ON && !ch_audible(m, m->v[i].ch))
            voice_end(m, &m->v[i], t);
}

void mfx_set(mfx_t *m, int track, int id, int32_t v, uint32_t now)
{
    mfx_advance(m, now);
    if (track == MFX_GLOBAL) {
        const mfx_param_t *p = mfx_gparam(id);
        if (!p)
            return;
        v = clampi(v, p->min, p->max);
        int32_t old = m->gp[id];
        m->gp[id] = v;
        if (id == MFX_G_BPM && !m->ext && v != old) {
            /* re-anchor the internal clock at the last tick */
            m->anchor_t = m->last_tick_t;
            m->anchor_tick = m->ticks;
            m->uspq = int_uspq(m);
            update_D(m);
        } else if (id == MFX_G_MUTE || id == MFX_G_SOLO) {
            mute_flush(m, now);
        }
        mfx_advance(m, now);
        return;
    }
    if (track < 0 || track >= MFX_TRACKS)
        return;
    const mfx_param_t *p = mfx_tparam(id);
    if (!p)
        return;
    v = clampi(v, p->min, p->max);
    int32_t old = m->tp[track][id];
    m->tp[track][id] = v;
    if (v == old)
        return;
    switch (id) {
    case MFX_P_ARP_ON:
        if (!v)
            m->arp[track].count = 0;
        break;
    case MFX_P_ARP_LATCH:
        if (!v)
            arp_prune(m, track);
        break;
    case MFX_P_DLY_ON:
        if (!v)
            for (int i = 0; i < MFX_CHAINS; i++)
                if (m->chain[i].used && m->chain[i].track == track)
                    chain_cancel(m, &m->chain[i]);
        break;
    case MFX_P_GRV_PRESET:
        load_groove(m, track, v);
        break;
    case MFX_P_CHANNEL:
        if (!v)
            m->arp[track].count = 0;
        break;
    default:
        break;
    }
    update_D(m);
    mfx_advance(m, now);
}

int32_t mfx_get(const mfx_t *m, int track, int id)
{
    if (track == MFX_GLOBAL)
        return id >= 0 && id < MFX_GP_COUNT ? m->gp[id] : 0;
    if (track < 0 || track >= MFX_TRACKS || id < 0 || id >= MFX_TP_COUNT)
        return 0;
    return m->tp[track][id];
}

void mfx_loop(mfx_t *m, uint32_t now, int on)
{
    mfx_advance(m, now);
    if (on && !m->loop.active)
        loop_engage(m, now);
    else if (!on && m->loop.active)
        loop_release(m, now);
    mfx_advance(m, now);
}

void mfx_panic(mfx_t *m, uint32_t now)
{
    mfx_advance(m, now);
    flush_all(m, now);
    for (int i = 0; i < MFX_HELD; i++)
        m->held[i].used = 0;
    for (int tr = 0; tr < MFX_TRACKS; tr++)
        m->arp[tr].count = 0;
}

int mfx_bpm10(const mfx_t *m)
{
    return (int)((600000000ull + m->uspq / 2) / m->uspq);
}

int mfx_ext_clock(const mfx_t *m)
{
    return m->ext;
}

int mfx_voices_on(const mfx_t *m)
{
    return m->n_on;
}

void mfx_init(mfx_t *m, uint32_t now, uint32_t seed, mfx_emit_fn emit, void *ctx)
{
    zero(m, sizeof *m);
    m->emit = emit;
    m->ctx = ctx;
    m->rng = seed ? seed : 0x12345678u;
    for (int id = 0; id < MFX_GP_COUNT; id++)
        m->gp[id] = mfx_gparam(id)->def;
    for (int tr = 0; tr < MFX_TRACKS; tr++) {
        for (int id = 0; id < MFX_TP_COUNT; id++)
            m->tp[tr][id] = mfx_tparam(id)->def;
        load_groove(m, tr, m->tp[tr][MFX_P_GRV_PRESET]);
    }
    m->tp[0][MFX_P_CHANNEL] = 17; /* track 1: all channels */
    m->now = now;
    m->ticks = 0;
    m->last_tick_t = now;
    m->th[0] = now;
    m->pending_pos = -1;
    m->clock_out_t = now;
    go_internal(m, now);
}
