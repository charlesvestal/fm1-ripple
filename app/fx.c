/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* MIDI effects for droplets (ripple.h rp_fx_*, Lua's midifx): e16-launcher's engine (midifx/, MIT) between the notes
 * a droplet plays and a current: harmonize, note offset, scale, chance, grid groove, velocity, swing, clock shift,
 * humanize, gate, the arpeggiator, MIDI delay with feedback, and the loop (beat repeat and remix, with beat stretch).
 * Up to FX_MAX at once; they go when the droplet does (fx_free_all). The engine counts time in microseconds, from the
 * main loop (fx_tick); what it plays goes to the current it is connected to, and to MIDI out when asked. Part of the
 * unity build (app.c). */
#include "midifx/mfx.h"

#define FX_MAX 2
static mfx_t fx_m[FX_MAX] PLAT_POOL;
static struct {
    uint8_t used, midi_out;
    int8_t cur;                             /* the current it plays (a flow handle), -1 none */
    uint32_t gen;                           /* flow_gen when connected: a cleared flow drops it */
} fx_s[FX_MAX];
static uint32_t fx_us, fx_t24, fx_rem;      /* the engine's clock: microseconds, from plat_ticks24 */

static uint32_t fx_now(void)
{
#ifdef PLAT_HOST
    return plat_ms() * 1000u;               /* (the simulator's time: plat_ticks24 is the computer's, which runs apart) */
#endif
    uint32_t t = plat_ticks24();
    fx_rem += t - fx_t24;
    fx_t24 = t;
    fx_us += fx_rem / PLAT_TICKS_PER_US;
    fx_rem %= PLAT_TICKS_PER_US;
    return fx_us;
}

/* what the engine plays, as it falls due */
static void fx_emit(void *ctx, uint32_t t, int port, const uint8_t *msg, int len)
{
    int i = (int)(uintptr_t)ctx;
    uint8_t st = msg[0] & 0xF0u;
    (void)t, (void)port;
    if (fx_s[i].midi_out)
        rp_midi(msg[0], len > 1 ? msg[1] : 0, len > 2 ? msg[2] : 0);
    if (fx_s[i].cur < 0 || fx_s[i].gen != flow_gen || len < 3)
        return;
    if (st == 0x90u && msg[2])
        flow_note(fx_s[i].cur, msg[1], (float)msg[2] * (1.0f / 127.0f));
    else if (st == 0x80u || st == 0x90u)
        flow_note(fx_s[i].cur, msg[1], 0.0f);
}

/* the parameters by the names droplets use: a track's (the engine's one track) or global */
#define FX_G 0x100
static const struct { const char *name; uint16_t id; } FX_NAMES[] = {
    {"harm_on", MFX_P_HARM_ON}, {"unison", MFX_P_UNISON}, {"octaver", MFX_P_OCTAVER}, {"harm1", MFX_P_HARM1},
    {"harm2", MFX_P_HARM2},
    {"note_on", MFX_P_NOTE_ON}, {"note", MFX_P_NOTE_OFS},
    {"scale_on", MFX_P_SCALE_ON}, {"scale", MFX_P_SCALE}, {"root", MFX_P_ROOT},
    {"vel_on", MFX_P_VEL_ON}, {"vel", MFX_P_VEL_OFS}, {"vel_scale", MFX_P_VEL_SCALE}, {"vel_comp", MFX_P_VEL_COMP},
    {"vel_random", MFX_P_VEL_RAND},
    {"chance", MFX_P_PROB},
    {"gate_on", MFX_P_GATE_ON}, {"gate", MFX_P_GATE},
    {"swing_on", MFX_P_SWING_ON}, {"swing", MFX_P_SWING}, {"swing_grid", MFX_P_SWING_GRID},
    {"shift_on", MFX_P_SHIFT_ON}, {"shift", MFX_P_SHIFT},
    {"groove_on", MFX_P_GRV_ON}, {"groove", MFX_P_GRV_PRESET},
    {"humanize_on", MFX_P_HUM_ON}, {"humanize", MFX_P_HUM_TIME},
    {"arp_on", MFX_P_ARP_ON}, {"arp_mode", MFX_P_ARP_MODE}, {"arp_rate", MFX_P_ARP_RATE}, {"arp_oct", MFX_P_ARP_OCT},
    {"arp_gate", MFX_P_ARP_GATE}, {"arp_latch", MFX_P_ARP_LATCH},
    {"delay_on", MFX_P_DLY_ON}, {"delay_time", MFX_P_DLY_TIME}, {"delay_level", MFX_P_DLY_LEVEL},
    {"repeats", MFX_P_DLY_REPEAT}, {"fb_vel", MFX_P_FB_VEL}, {"fb_note", MFX_P_FB_NOTE}, {"fb_gate", MFX_P_FB_GATE},
    {"fb_clock", MFX_P_FB_CLOCK},
    {"tempo", FX_G | MFX_G_BPM}, {"loop", FX_G | MFX_G_LOOP_TYPE}, {"stretch", FX_G | MFX_G_STRETCH},
};
#define FX_NNAMES ((int)(sizeof FX_NAMES / sizeof FX_NAMES[0]))

static const mfx_param_t *fx_meta(int k)
{
    return FX_NAMES[k].id & FX_G ? mfx_gparam(FX_NAMES[k].id & 0xFFu) : mfx_tparam(FX_NAMES[k].id);
}

static void fx_free_all(void)
{
    int i;
    for (i = 0; i < FX_MAX; i++)
        fx_s[i].used = 0;
}

/* every pass of the main loop: what is due */
static void fx_tick(void)
{
    uint32_t now;
    int i;
    for (i = 0; i < FX_MAX && !fx_s[i].used; i++)
        ;
    if (i == FX_MAX)
        return;
    now = fx_now();
    for (i = 0; i < FX_MAX; i++)
        if (fx_s[i].used)
            mfx_advance(&fx_m[i], now);
}

/* ------------------------------------------------------ glue (ripple.h) --- */
int rp_fx_new(void)
{
    int i;
    for (i = 0; i < FX_MAX && fx_s[i].used; i++)
        ;
    if (i == FX_MAX)
        return -1;
    fx_s[i].used = 1;
    fx_s[i].midi_out = 0;
    fx_s[i].cur = -1;
    mfx_init(&fx_m[i], fx_now(), 0x52495050u + (uint32_t)i * 7919u, fx_emit, (void *)(uintptr_t)i);
    mfx_set(&fx_m[i], MFX_GLOBAL, MFX_G_OUT_PORTS, 1, fx_now());   /* one output: each note once */
    return i;
}
static int fx_ok(int i) { return i >= 0 && i < FX_MAX && fx_s[i].used; }
int rp_fx_param(const char *name)
{
    int k;
    for (k = 0; k < FX_NNAMES; k++)
        if (!strcmp(FX_NAMES[k].name, name))
            return k;
    return -1;
}
int rp_fx_nparams(void) { return FX_NNAMES; }
const char *rp_fx_param_info(int k, int *mn, int *mx, int *df)
{
    const mfx_param_t *p;
    if (k < 0 || k >= FX_NNAMES)
        return "";
    p = fx_meta(k);
    *mn = (int)p->min, *mx = (int)p->max, *df = (int)p->def;
    return FX_NAMES[k].name;
}
void rp_fx_set(int i, int k, int v)
{
    uint16_t id;
    if (!fx_ok(i) || k < 0 || k >= FX_NNAMES)
        return;
    id = FX_NAMES[k].id;
    mfx_set(&fx_m[i], id & FX_G ? MFX_GLOBAL : 0, id & 0xFFu, v, fx_now());
}
int rp_fx_get(int i, int k)
{
    uint16_t id;
    if (!fx_ok(i) || k < 0 || k >= FX_NNAMES)
        return 0;
    id = FX_NAMES[k].id;
    return (int)mfx_get(&fx_m[i], id & FX_G ? MFX_GLOBAL : 0, id & 0xFFu);
}
void rp_fx_format(int k, int v, char *out, int n)
{
    if (k >= 0 && k < FX_NNAMES)
        mfx_format(fx_meta(k), v, out, n);
    else if (n > 0)
        out[0] = 0;
}
void rp_fx_midi(int i, int b0, int b1, int b2)
{
    uint8_t m[3];
    int len;
    if (!fx_ok(i))
        return;
    m[0] = (uint8_t)b0, m[1] = (uint8_t)(b1 & 0x7F), m[2] = (uint8_t)(b2 & 0x7F);
    len = b0 >= 0xF8 ? 1 : (b0 & 0xF0) == 0xC0 || (b0 & 0xF0) == 0xD0 || b0 == 0xF3 ? 2 : 3;
    mfx_input(&fx_m[i], fx_now(), MFX_IN_USB, m, len);
    mfx_advance(&fx_m[i], fx_now());        /* (what is due at once goes now, not at the next pass) */
}
void rp_fx_connect(int i, int h)
{
    if (!fx_ok(i))
        return;
    if (fx_s[i].cur >= 0)
        mfx_panic(&fx_m[i], fx_now());     /* (its notes end on the current they started on) */
    fx_s[i].cur = (int8_t)(flow_desc(h) ? h : -1);
    fx_s[i].gen = flow_gen;
}
void rp_fx_midi_out(int i, int on) { if (fx_ok(i)) fx_s[i].midi_out = (uint8_t)(on != 0); }
void rp_fx_loop(int i, int on) { if (fx_ok(i)) mfx_loop(&fx_m[i], fx_now(), on); }
void rp_fx_panic(int i) { if (fx_ok(i)) mfx_panic(&fx_m[i], fx_now()); }
int rp_fx_bpm10(int i) { return fx_ok(i) ? mfx_bpm10(&fx_m[i]) : 0; }
