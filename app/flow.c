/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* The flow: the currents a droplet loaded (sdk/include/ripple_current.h) and the order they run in on the stereo
 * bus, each audio block. A current is a .cur file on the disk (sdk/tools/curpack.py): its image is copied into the
 * arena (RAM, in the guard's code window: plat_code_window), relocated, and its descriptor checked. The main loop
 * loads and routes; parameter changes and notes go to the render through a queue, so the render alone calls into a
 * current once it plays. Leaving a droplet empties the arena. Part of the unity build (app.c).
 *
 * The host simulator cannot run the FM-1's code: there a current is the same source built for the computer
 * (app/build/currents-host/NAME.so, sdk/tools/currents.py --host), opened by name; the .cur must still be on the
 * disk. */
#include "ripple_current.h"
#ifdef PLAT_HOST
#include <dlfcn.h>
#endif

/* where the last start got to, kept through a watchdog reset (.noinit): said at the next start (app.c speak) */
#ifdef PLAT_HOST
#define RP_NOINIT
#else
#define RP_NOINIT __attribute__((section(".noinit")))
#endif
static struct {
    uint32_t magic;
    uint32_t step;                          /* the last step started */
    uint32_t in_render;                     /* the current running in the render + 1 (0: none) */
    uint32_t boots;                         /* starts since this was first written */
    uint32_t sp, sp_min;                    /* the stack pointer at the last step, the lowest seen */
    char what[24];
} crumb RP_NOINIT;
#define CRUMB_MAGIC 0x43524D42u
static void crumb_set(uint32_t step, const char *what)
{
    uint32_t i;
    volatile uint32_t here = 0;
    crumb.magic = CRUMB_MAGIC;
    crumb.step = step;
    crumb.sp = (uint32_t)(uintptr_t)&here;
    if (!crumb.sp_min || crumb.sp < crumb.sp_min)
        crumb.sp_min = crumb.sp;
    for (i = 0; what && what[i] && i < sizeof crumb.what - 1u; i++)
        crumb.what[i] = what[i];
    crumb.what[i] = 0;
}

#define FLOW_MAX 8                          /* currents loaded at once */
#define FLOW_ARENA_KB 84
#define CUR_MAGIC 0x52554352u               /* "RCUR": the .cur header */
#define CUR_VERSION 1u

typedef struct {
    uint32_t magic;
    uint16_t version, rsv;
    uint32_t image_size, bss_size;          /* the image (code, constants, data), then zeroed bytes */
    uint32_t entry;                         /* rc_entry's offset in the image */
    uint32_t nrelocs;                       /* after the image: one word each, offset | type << 28 */
    uint32_t sum;                           /* the image's and the relocations' sum of bytes */
    uint32_t rsv2;
} cur_head_t;
enum { REL_ABS32 = 1, REL_MOV32 = 2 };      /* a word; the 32-bit immediate of a 6-byte move, at offset + 2 */

typedef struct {
    const rc_desc_t *d;
    void *st;
    char name[16];
} cur_t;

static cur_t curs[FLOW_MAX];
static uint32_t ncurs;
static uint8_t arena[FLOW_ARENA_KB * 1024u] PLAT_POOL __attribute__((aligned(8)));
static uint32_t arena_top;
static volatile uint8_t route[FLOW_MAX], route_n;   /* the order on the bus (indexes into curs) */
static volatile float flow_gain = 0.5f;     /* the droplet's level */
static volatile uint32_t flow_blocks;       /* blocks rendered (a reset waits for one) */
static float flow_peak;                     /* the last block's peak (the meter) */

/* the queue to the render: a parameter or a note */
enum { EV_SET, EV_NOTE };
typedef struct {
    uint8_t type, cur;
    int16_t a;
    float v;
} flow_ev_t;
#define EVQ 128u
static flow_ev_t evq[EVQ];
static volatile uint32_t evq_w, evq_r;

static void *arena_take(uint32_t n)
{
    uint32_t at = (arena_top + 7u) & ~7u;
    if (at + n > sizeof arena)
        return 0;
    arena_top = at + n;
    memset(arena + at, 0, n);
    return arena + at;
}

static void flow_push(uint8_t type, int cur, int a, float v)
{
    uint32_t w = evq_w;
    if (w - evq_r >= EVQ)
        return;                             /* full: dropped (the render is not running) */
    evq[w % EVQ].type = type;
    evq[w % EVQ].cur = (uint8_t)cur;
    evq[w % EVQ].a = (int16_t)a;
    evq[w % EVQ].v = v;
    evq_w = w + 1u;
}

/* everything out: no current plays, the arena is empty (leaving a droplet) */
static void flow_reset(void)
{
    route_n = 0;
#ifndef PLAT_HOST
    {   /* the render may be inside a current now: wait for it to finish a block without one */
        uint32_t b = flow_blocks, t0 = plat_ms();
        while (flow_blocks - b < 2u && plat_ms() - t0 < 50u)
            ;
    }
#endif
    evq_r = evq_w;
    ncurs = 0;
    arena_top = 0;
    memset(curs, 0, sizeof curs);
}

static const char *flow_err;                /* why the last load failed */

#ifndef PLAT_HOST
static const rc_desc_t *cur_link(const char *path)
{
    disk_file_t f;
    cur_head_t h;
    uint8_t *img;
    uint32_t i, sum = 0, rel;
    const rc_desc_t *(*entry)(void);
    crumb_set(20, path);
    if (disk_open(path, &f) != 0) {
        flow_err = "not on the disk";
        return 0;
    }
    if (disk_read(&f, 0, &h, sizeof h) != sizeof h || h.magic != CUR_MAGIC || h.version != CUR_VERSION
        || h.entry >= h.image_size || sizeof h + h.image_size + 4u * h.nrelocs > f.size) {
        flow_err = "not a current";
        return 0;
    }
    if (!(img = arena_take(h.image_size + h.bss_size))) {
        flow_err = "no room";
        return 0;
    }
    disk_read(&f, sizeof h, img, h.image_size);
    for (i = 0; i < h.image_size; i++)
        sum += img[i];
    for (i = 0; i < h.nrelocs; i++) {       /* each address in the image, plus where the image is */
        uint32_t off, at, v;
        disk_read(&f, sizeof h + h.image_size + 4u * i, &rel, 4u);
        sum += (rel & 0xFFu) + (rel >> 8 & 0xFFu) + (rel >> 16 & 0xFFu) + (rel >> 24);
        off = rel & 0x0FFFFFFFu;
        at = (rel >> 28) == REL_MOV32 ? off + 2u : off;
        if ((rel >> 28) != REL_ABS32 && (rel >> 28) != REL_MOV32) {
            flow_err = "unknown relocation";
            return 0;
        }
        if (at + 4u > h.image_size) {
            flow_err = "bad relocation";
            return 0;
        }
        v = (uint32_t)img[at] | (uint32_t)img[at + 1] << 8 | (uint32_t)img[at + 2] << 16 | (uint32_t)img[at + 3] << 24;
        v += (uint32_t)(uintptr_t)img;
        img[at] = (uint8_t)v;
        img[at + 1] = (uint8_t)(v >> 8);
        img[at + 2] = (uint8_t)(v >> 16);
        img[at + 3] = (uint8_t)(v >> 24);
    }
    if (sum != h.sum) {
        flow_err = "damaged";
        return 0;
    }
    entry = (const rc_desc_t *(*)(void))(uintptr_t)(img + h.entry);
    crumb_set(23, path);
    return entry();
}
#else
static const rc_desc_t *cur_link(const char *path)
{
    char so[512];
    const char *dir = getenv("RIPPLE_CURRENTS"), *base = strrchr(path, '/');
    disk_file_t f;
    void *h;
    const rc_desc_t *(*entry)(void);
    if (disk_open(path, &f) != 0) {
        flow_err = "not on the disk";
        return 0;
    }
    snprintf(so, sizeof so, "%s/%.*s.so", dir ? dir : "app/build/currents-host", (int)(strlen(base + 1) - 4u), base + 1);
    if (!(h = dlopen(so, RTLD_NOW | RTLD_LOCAL))) {
        flow_err = "no host build";
        return 0;
    }
    if (!(entry = (const rc_desc_t *(*)(void))dlsym(h, "rc_entry"))) {
        flow_err = "not a current";
        return 0;
    }
    return entry();
}
#endif

/* load current name ("voice": /currents/voice.cur) -> its handle, or -1 (flow_err says why) */
static int flow_load(const char *name)
{
    char path[48] = "/currents/";
    const rc_desc_t *d;
    cur_t *c;
    uint32_t i, top = arena_top;
    for (i = 0; name[i] && i < 24u; i++)
        path[10 + i] = name[i];
    path[10 + i] = 0;
    text_cat(path, ".cur");
    if (ncurs >= FLOW_MAX) {
        flow_err = "too many currents";
        return -1;
    }
    if (!(d = cur_link(path))) {
        arena_top = top;
        return -1;
    }
    if (d->magic != RC_MAGIC || d->abi != RC_ABI || !d->process || !d->set || d->nparams > RC_MAX_PARAMS
        || (d->voices && !d->note)) {
        flow_err = "built for another Ripple";
        arena_top = top;
        return -1;
    }
    c = &curs[ncurs];
    if (!(c->st = arena_take(d->state_size ? d->state_size : 4u))) {
        flow_err = "no room";
        arena_top = top;
        return -1;
    }
    c->d = d;
    for (i = 0; name[i] && i < sizeof c->name - 1u; i++)
        c->name[i] = name[i];
    c->name[i] = 0;
    crumb_set(25, name);
    if (d->init)
        d->init(c->st, 44100.0f);
    crumb_set(26, name);
    for (i = 0; i < d->nparams; i++)
        d->set(c->st, (int)i, d->params[i].def);
    crumb_set(27, name);
    return (int)ncurs++;
}

static const rc_desc_t *flow_desc(int h) { return h >= 0 && (uint32_t)h < ncurs ? curs[h].d : 0; }

static int flow_param(int h, const char *name)
{
    const rc_desc_t *d = flow_desc(h);
    uint32_t i;
    for (i = 0; d && i < d->nparams; i++)
        if (!strcmp(d->params[i].name, name))
            return (int)i;
    return -1;
}

static void flow_set(int h, int p, float v)
{
    const rc_desc_t *d = flow_desc(h);
    if (!d || p < 0 || (uint32_t)p >= d->nparams)
        return;
    v = fm_clampf(v, d->params[p].min, d->params[p].max);
    flow_push(EV_SET, h, p, v);
}

static void flow_note(int h, int note, float vel)
{
    const rc_desc_t *d = flow_desc(h);
    if (!d || !d->voices)
        return;
    flow_push(EV_NOTE, h, note, fm_clampf(vel, 0.0f, 1.0f));
}

static void flow_route(const int *hs, int n)
{
    uint8_t r[FLOW_MAX];
    int i, k = 0;
    for (i = 0; i < n && k < FLOW_MAX; i++)
        if (flow_desc(hs[i]))
            r[k++] = (uint8_t)hs[i];
    route_n = 0;                            /* the render sees no flow while it changes */
    for (i = 0; i < k; i++)
        route[i] = r[i];
    route_n = (uint8_t)k;
}

/* --------------------------------------------------------------- the render --- */
static float bus_l[APP_BLOCK], bus_r[APP_BLOCK];

static void flow_render(int32_t *lr, uint32_t n, uint32_t master_q12)
{
    uint32_t i, k, rn;
    float g, peak = 0.0f;
    while (evq_r != evq_w) {                /* what the main loop asked since the last block */
        const flow_ev_t *e = &evq[evq_r % EVQ];
        if (e->cur < ncurs) {
            cur_t *c = &curs[e->cur];
            if (e->type == EV_SET)
                c->d->set(c->st, e->a, e->v);
            else
                c->d->note(c->st, e->a, e->v);
        }
        evq_r++;
    }
    memset(bus_l, 0, n * sizeof(float));
    memset(bus_r, 0, n * sizeof(float));
    rn = route_n;
    for (k = 0; k < rn; k++) {
        cur_t *c = &curs[route[k]];
        crumb.in_render = route[k] + 1u;
        if (c->d)
            c->d->process(c->st, bus_l, bus_r, (int)n);
        crumb.in_render = 0;
    }
    g = flow_gain * (float)master_q12 / 4096.0f * 8388607.0f;
    for (i = 0; i < n; i++) {               /* soft above full scale, then 24-bit */
        float l = bus_l[i], r = bus_r[i], al = fm_fabsf(l), ar = fm_fabsf(r);
        if (al > peak) peak = al;
        if (ar > peak) peak = ar;
        if (al > 1.0f || ar > 1.0f) {
            l = fm_tanhf(l);
            r = fm_tanhf(r);
        }
        lr[2 * i] = (int32_t)(l * g);
        lr[2 * i + 1] = (int32_t)(r * g);
    }
    flow_peak = peak;
    flow_blocks++;
}
