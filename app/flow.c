/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* The flow: the currents a droplet loaded (sdk/include/ripple_current.h) and the order they run in on the stereo
 * bus, each audio block. A current is a .cur file on the disk (sdk/tools/curpack.py): its image is copied into the
 * arena (RAM, in the guard's code window: plat_code_window), relocated, and its descriptor checked. The main loop
 * loads and routes; parameter changes and notes go to the render through a queue, so the render alone calls into a
 * current once it plays. Leaving a droplet empties the arena. Part of the unity build (app.c).
 *
 * Memory: the images (code and data) go into the arena in the pool; the currents' states first into a second arena in
 * RAM (.bss, inside the code window too), then the pool's when that is full.
 *
 * Two cores (fm1.toml cpu2): in each run of currents that add to the bus (nothing between them that processes it),
 * the second core takes part 1 of each current in two parts (ripple_current.h: parts) and every other current not in
 * parts, into its own bus, while the first does the rest; the two buses are added before what comes next.
 *
 * The host simulator cannot run the FM-1's code: there a current is the same source built for the computer
 * (app/build/currents-host/NAME.so, sdk/tools/currents.py --host), opened by name; the .cur must still be on the
 * disk. */
#include "ripple_current.h"
#if defined(PLAT_HOST) && !defined(PLAT_WEB)
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
#define FLOW_STATE_KB 48                    /* the states' arena, in RAM */
#define CUR_MAGIC 0x52554352u               /* "RCUR": the .cur header */
#define CUR_VERSION 1u

typedef struct {
    uint32_t magic;
    uint16_t version, info;                 /* info (0: none): 0x8000 | 0x100 when it processes the bus | voices */
    uint32_t image_size, bss_size;          /* the image (code, constants, data), then zeroed bytes */
    uint32_t entry;                         /* rc_entry's offset in the image */
    uint32_t nrelocs;                       /* after the image: one word each, offset | type << 28 */
    uint32_t sum;                           /* the image's and the relocations' sum of bytes */
    uint32_t state_size;                    /* (with info) the state it asks for */
} cur_head_t;
enum { REL_ABS32 = 1, REL_MOV32 = 2 };      /* a word; the 32-bit immediate of a 6-byte move, at offset + 2 */

typedef struct {
    const rc_desc_t *d;
    void *st;
    uint8_t parts;                          /* 2: it splits (ABI 2, parts 2, process_part, adds to the bus) */
    void (*begin)(void *st, int n);         /* ABI 2's, or 0 */
    char name[16];
} cur_t;

static cur_t curs[FLOW_MAX];
static uint32_t ncurs;
static uint8_t arena[FLOW_ARENA_KB * 1024u] PLAT_POOL __attribute__((aligned(8)));
static uint32_t arena_top;
static uint8_t sarena[FLOW_STATE_KB * 1024u] __attribute__((aligned(8)));
static uint32_t sarena_top;
static volatile uint8_t route[FLOW_MAX], route_n;   /* the order on the bus (indexes into curs) */
static uint8_t route_set_n;                 /* what the droplet set (a pause sets route_n 0 a moment) */
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
#define EVQ 512u                            /* (a kit: 16 pads of a dozen settings, sent at once) */
static flow_ev_t evq[EVQ] PLAT_POOL;
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

/* a current's state: the RAM arena, else the pool's */
static void *state_take(uint32_t n)
{
    uint32_t at = (sarena_top + 7u) & ~7u;
    if (at + n > sizeof sarena)
        return arena_take(n);
    sarena_top = at + n;
    memset(sarena + at, 0, n);
    return sarena + at;
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
    route_set_n = 0;
    ncurs = 0;
    arena_top = 0;
    sarena_top = 0;
    memset(curs, 0, sizeof curs);
}

static const char *flow_err;                /* why the last load failed */
static uint32_t flow_gen;                   /* flow_clear's count: a droplet's handles from before it are stale */

/* a current on the disk or built in, without loading it: 0, or -1 (not there, not a current). kind: 0 makes sound,
 * 1 processes the bus, -1 not said (built before the SDK wrote it); code: the image and its zeroed data */
typedef struct {
    int kind, voices;
    uint32_t code, state;
} cur_info_t;
static int flow_info(const char *name, cur_info_t *in)
{
    char path[48] = "/currents/";
    disk_file_t f;
    cur_head_t h;
    text_cat(path, name);
    text_cat(path, ".cur");
    if (strlen(name) > 24u || disk_open(path, &f) != 0 || disk_read(&f, 0, &h, sizeof h) != sizeof h
        || h.magic != CUR_MAGIC)
        return -1;
    in->kind = h.info & 0x8000u ? (h.info >> 8 & 1) : -1;
    in->voices = h.info & 0x8000u ? (int)(h.info & 0xFFu) : 0;
    in->code = h.image_size + h.bss_size;
    in->state = h.info & 0x8000u ? h.state_size : 0;
    return 0;
}

/* whether it would load now (the image into the pool's arena; its state into RAM's, else after the image) */
static int flow_fits(const char *name)
{
    cur_info_t in;
    uint32_t a = (arena_top + 7u) & ~7u, s = (sarena_top + 7u) & ~7u;
    if (flow_info(name, &in) != 0 || ncurs >= FLOW_MAX || a + in.code > sizeof arena)
        return 0;
    if (s + in.state <= sizeof sarena)
        return 1;
    return ((a + in.code + 7u) & ~7u) + in.state <= sizeof arena;
}

/* the room left, bytes, both arenas */
static uint32_t flow_room(void) { return (uint32_t)(sizeof arena - arena_top + sizeof sarena - sarena_top); }

/* the droplet's currents all gone (it loads others): flow_reset, and its handles stale */
static void flow_clear(void)
{
    flow_reset();
    flow_gen++;
}

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
#elif defined(PLAT_WEB)
/* the browser's emulator: every current linked in (sdk/tools/currents.py --web), found by name */
struct rc_web { const char *name; const rc_desc_t *(*entry)(void); };
extern const struct rc_web rc_web_list[];
static const rc_desc_t *cur_link(const char *path)
{
    const char *base = strrchr(path, '/') + 1;
    disk_file_t f;
    uint32_t i, n = (uint32_t)strlen(base) - 4u;
    if (disk_open(path, &f) != 0) {
        flow_err = "not on the disk";
        return 0;
    }
    for (i = 0; rc_web_list[i].name; i++)
        if (strlen(rc_web_list[i].name) == n && !strncmp(rc_web_list[i].name, base, n))
            return rc_web_list[i].entry();
    flow_err = "not in the emulator";
    return 0;
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
    uint32_t i, top = arena_top, stop = sarena_top;
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
    if (d->magic != RC_MAGIC || (d->abi != 1u && d->abi != RC_ABI) || !d->process || !d->set || d->nparams > RC_MAX_PARAMS
        || (d->voices && !d->note)) {
        flow_err = "built for another Ripple";
        arena_top = top;
        return -1;
    }
    c = &curs[ncurs];
    if (!(c->st = state_take(d->state_size ? d->state_size : 4u))) {
        flow_err = "no room";
        arena_top = top;
        sarena_top = stop;
        return -1;
    }
    c->d = d;
    c->parts = d->abi >= 2u && d->parts == 2u && d->process_part && !d->ins ? 2u : 0u;
    c->begin = d->abi >= 2u ? d->begin : 0;
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
    route_set_n = (uint8_t)k;
    route_n = (uint8_t)k;
}

static void flow_route_restore(void) { route_n = route_set_n; }

/* --------------------------------------------------------------- the render --- */
static float bus_l[APP_BLOCK], bus_r[APP_BLOCK];
static float c2_l[APP_BLOCK], c2_r[APP_BLOCK];   /* the second core's bus */
static uint8_t c2_job[FLOW_MAX], c2_part[FLOW_MAX], c2_n;   /* its job: these currents (part 1, or whole: 0xFF) */
static uint32_t c2_frames;
static volatile uint32_t flow_c2_blocks;    /* blocks the second core took part in */

static void c2_run(uint32_t arg)
{
    uint32_t k, n = c2_frames;
    (void)arg;
    memset(c2_l, 0, n * sizeof(float));
    memset(c2_r, 0, n * sizeof(float));
    for (k = 0; k < c2_n; k++) {
        cur_t *c = &curs[c2_job[k]];
        if (c2_part[k] == 1u)
            c->d->process_part(c->st, c2_l, c2_r, (int)n, 1);
        else
            c->d->process(c->st, c2_l, c2_r, (int)n);
    }
}

/* the currents route[k0..k1), which all add to the bus: shared between the cores when the second runs */
static void render_run(uint32_t k0, uint32_t k1, uint32_t n)
{
    uint32_t k, i, mine[FLOW_MAX], nmine = 0, whole = 0;
    int on2;
    c2_n = 0;
    for (k = k0; k < k1; k++) {
        cur_t *c = &curs[route[k]];
        if (c->parts) {
            c2_job[c2_n] = route[k];
            c2_part[c2_n++] = 1u;
            mine[nmine++] = route[k];
        } else if (whole++ & 1u) {
            c2_job[c2_n] = route[k];
            c2_part[c2_n++] = 0xFFu;
        } else
            mine[nmine++] = route[k];
    }
    c2_frames = n;
    on2 = c2_n && plat_cpu2_on() && plat_cpu2_run(c2_run, 0);
    if (!on2) {                             /* one core: each current whole, in order */
        for (k = k0; k < k1; k++) {
            cur_t *c = &curs[route[k]];
            crumb.in_render = route[k] + 1u;
            c->d->process(c->st, bus_l, bus_r, (int)n);
        }
        crumb.in_render = 0;
        return;
    }
    for (k = 0; k < nmine; k++) {
        cur_t *c = &curs[mine[k]];
        crumb.in_render = mine[k] + 1u;
        if (c->parts)
            c->d->process_part(c->st, bus_l, bus_r, (int)n, 0);
        else
            c->d->process(c->st, bus_l, bus_r, (int)n);
    }
    crumb.in_render = 0;
    if (plat_cpu2_wait() != 0)              /* (given up: the job dropped) */
        c2_run(0);
    for (i = 0; i < n; i++) {
        bus_l[i] += c2_l[i];
        bus_r[i] += c2_r[i];
    }
    flow_c2_blocks++;
}

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
    for (k = 0; k < rn; k++) {              /* each current's once-a-block work, before any of them renders */
        cur_t *c = &curs[route[k]];
        if (c->begin)
            c->begin(c->st, (int)n);
    }
    for (k = 0; k < rn;) {
        cur_t *c = &curs[route[k]];
        if (!c->d) {
            k++;
        } else if (c->d->ins) {             /* an effect: on the bus as it is */
            crumb.in_render = route[k] + 1u;
            c->d->process(c->st, bus_l, bus_r, (int)n);
            crumb.in_render = 0;
            k++;
        } else {                            /* a run of currents that add to it */
            uint32_t k1 = k + 1u;
            while (k1 < rn && curs[route[k1]].d && !curs[route[k1]].d->ins)
                k1++;
            render_run(k, k1, n);
            k = k1;
        }
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
