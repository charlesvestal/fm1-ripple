/* SPDX-License-Identifier: MIT
 * Copyright (C) 2026 Charles Vestal
 * From e16-launcher (github.com/charlesvestal/e16-launcher, apps/midifx/core, MIT): the MIDI effects engine,
 * unchanged but for its sizes (mfx.h: one track, smaller queues; README "Ripple's copy"). */
/*
 * midifx parameter metadata: names, ranges, defaults and how each value
 * reads on the OLED. RS7000 Play FX names and ranges where the RS7000 has
 * the parameter (docs/midifx.md lists them).
 */
#include "mfx.h"

static const char *const n_grid[] = {"8th", "16th"};
static const char *const n_scale[MFX_SCALES] = {"major", "minor", "dorian", "phrygian", "lydian",
                                                "mixolyd", "locrian", "harm min", "mel min",
                                                "pent maj", "pent min", "blues", "whole"};
static const char *const n_root[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
static const char *const n_arp[MFX_ARP_MODES] = {"up", "down", "up/down", "random", "played"};
static const char *const n_rate[MFX_ARP_RATES] = {"1/4", "1/8", "1/8T", "1/16", "1/16T", "1/32"};
static const char *const n_grv[MFX_GRV_PRESETS] = {"flat", "shuffle", "push", "lazy", "funk", "stacc"};
static const char *const n_loop[MFX_LOOP_TYPES] = {"rpt 1/2", "rpt 1/4", "rpt 1/8", "rpt 1/16",
                                                   "rmx rev", "rmx 1133", "rmx skip", "rmx roll",
                                                   "rmx shuf", "rmx half"};
static const char *const n_stretch[MFX_STRETCHES] = {"25%", "33%", "50%", "66%", "75%", "100%",
                                                     "125%", "150%", "200%", "300%", "400%"};
static const char *const n_unison[8] = {"off", "x2", "x3", "x4", "x5", "x6", "x7", "x8"};

const int16_t mfx_arp_rate_clk[MFX_ARP_RATES] = {480, 240, 160, 120, 80, 60};
const uint16_t mfx_stretch_pct[MFX_STRETCHES] = {25, 33, 50, 66, 75, 100, 125, 150, 200, 300, 400};

#define P(nm, lo, hi, d, f) {nm, lo, hi, d, f, 0}
#define E(nm, lo, hi, d, tbl) {nm, lo, hi, d, MFX_F_ENUM, tbl}

static mfx_param_t tparams[MFX_TP_COUNT] = {
    [MFX_P_SWING_ON] = P("Swing", 0, 1, 0, MFX_F_ONOFF),
    [MFX_P_SWING] = P("Swing", -120, 120, 40, MFX_F_CLK),
    [MFX_P_SWING_GRID] = E("Swing grid", 0, 1, 0, n_grid),
    [MFX_P_SHIFT_ON] = P("Clk shift", 0, 1, 0, MFX_F_ONOFF),
    [MFX_P_SHIFT] = P("Clk shift", -480, 480, 0, MFX_F_CLK),
    [MFX_P_GATE_ON] = P("Gate", 0, 1, 0, MFX_F_ONOFF),
    [MFX_P_GATE] = P("Gate", 0, 200, 100, MFX_F_PCT),
    [MFX_P_GRV_ON] = P("Groove", 0, 1, 0, MFX_F_ONOFF),
    [MFX_P_GRV_PRESET] = E("Groove", 0, MFX_GRV_PRESETS - 1, 1, n_grv),
    [MFX_P_VEL_ON] = P("Velocity", 0, 1, 0, MFX_F_ONOFF),
    [MFX_P_VEL_OFS] = P("Velocity", -127, 127, 0, MFX_F_SIGNED),
    [MFX_P_VEL_SCALE] = P("Vel scale", 25, 200, 100, MFX_F_PCT),
    [MFX_P_VEL_COMP] = P("Vel comp", 0, 100, 0, MFX_F_PCT),
    [MFX_P_VEL_RAND] = P("Vel random", 0, 64, 0, MFX_F_INT),
    [MFX_P_NOTE_ON] = P("Note ofs", 0, 1, 0, MFX_F_ONOFF),
    [MFX_P_NOTE_OFS] = P("Note ofs", -99, 99, 0, MFX_F_SIGNED),
    [MFX_P_SCALE_ON] = P("Scale", 0, 1, 0, MFX_F_ONOFF),
    [MFX_P_SCALE] = E("Scale", 0, MFX_SCALES - 1, 0, n_scale),
    [MFX_P_ROOT] = E("Root", 0, 11, 0, n_root),
    [MFX_P_HARM_ON] = P("Harmonize", 0, 1, 0, MFX_F_ONOFF),
    [MFX_P_UNISON] = E("Unison", 1, 8, 1, n_unison),
    [MFX_P_OCTAVER] = P("Octaver", -10, 10, 0, MFX_F_SIGNED),
    [MFX_P_HARM1] = P("Harmony 1", -99, 99, 7, MFX_F_SIGNED),
    [MFX_P_HARM2] = P("Harmony 2", -99, 99, 0, MFX_F_SIGNED),
    [MFX_P_ARP_ON] = P("Arp", 0, 1, 0, MFX_F_ONOFF),
    [MFX_P_ARP_MODE] = E("Arp mode", 0, MFX_ARP_MODES - 1, 0, n_arp),
    [MFX_P_ARP_RATE] = E("Arp rate", 0, MFX_ARP_RATES - 1, 3, n_rate),
    [MFX_P_ARP_OCT] = P("Arp oct", 1, 4, 1, MFX_F_INT),
    [MFX_P_ARP_GATE] = P("Arp gate", 5, 200, 50, MFX_F_PCT),
    [MFX_P_ARP_LATCH] = P("Arp latch", 0, 1, 0, MFX_F_ONOFF),
    [MFX_P_DLY_ON] = P("Delay", 0, 1, 0, MFX_F_ONOFF),
    [MFX_P_DLY_TIME] = P("Dly time", 30, 1920, 240, MFX_F_CLK),
    [MFX_P_DLY_LEVEL] = P("Dly level", 0, 127, 80, MFX_F_PCT),
    [MFX_P_DLY_REPEAT] = P("Repeats", 0, 64, 3, MFX_F_INT),
    [MFX_P_FB_VEL] = P("FB vel", -127, 127, -10, MFX_F_SIGNED),
    [MFX_P_FB_NOTE] = P("FB note", -24, MFX_FB_NOTE_RND, 0, MFX_F_SIGNED),
    [MFX_P_FB_GATE] = P("FB gate", -100, 100, 0, MFX_F_PCT),
    [MFX_P_FB_CLOCK] = P("FB clock", -100, 100, 0, MFX_F_PCT),
    [MFX_P_HUM_ON] = P("Humanize", 0, 1, 0, MFX_F_ONOFF),
    [MFX_P_HUM_TIME] = P("Humanize", 0, 30, 8, MFX_F_MS),
    [MFX_P_PROB] = P("Chance", 0, 100, 100, MFX_F_PCT),
    [MFX_P_CHANNEL] = P("Channel", 0, 17, 0, MFX_F_CHAN),
    [MFX_P_OUT_PORTS] = P("Out port", 0, 7, 0, MFX_F_PORTS),
    [MFX_P_OUT_CH] = P("Out ch", 0, 16, 0, MFX_F_OUTCH),
};

static const mfx_param_t gparams[MFX_GP_COUNT] = {
    [MFX_G_IN_PORTS] = P("In port", 1, 3, 3, MFX_F_PORTS),
    [MFX_G_OUT_PORTS] = P("Out port", 1, 7, 7, MFX_F_PORTS),
    [MFX_G_BPM] = P("Tempo", 30, 300, 120, MFX_F_BPM),
    [MFX_G_THRU] = P("Thru", 0, 31, 31, MFX_F_MASK),
    [MFX_G_MUTE] = P("Mute", 0, 0xFFFF, 0, MFX_F_MASK),
    [MFX_G_SOLO] = P("Solo", 0, 0xFFFF, 0, MFX_F_MASK),
    [MFX_G_LOOP_TYPE] = E("Loop", 0, MFX_LOOP_TYPES - 1, 1, n_loop),
    [MFX_G_STRETCH] = E("Stretch", 0, MFX_STRETCHES - 1, 5, n_stretch),
};

static int g_tparams_done;

/* The groove-table entries share one description each. */
static void fill_tparams(void)
{
    if (g_tparams_done)
        return;
    for (int s = 0; s < MFX_STEPS; s++) {
        tparams[MFX_P_GRV_CLK0 + s] = (mfx_param_t)P("Grv clock", -120, 120, 0, MFX_F_CLK);
        tparams[MFX_P_GRV_GATE0 + s] = (mfx_param_t)P("Grv gate", 0, 200, 100, MFX_F_PCT);
        tparams[MFX_P_GRV_VEL0 + s] = (mfx_param_t)P("Grv vel", 0, 200, 100, MFX_F_PCT);
        tparams[MFX_P_GRV_NOTE0 + s] = (mfx_param_t)P("Grv note", -24, 24, 0, MFX_F_SIGNED);
    }
    g_tparams_done = 1;
}

const mfx_param_t *mfx_tparam(int id)
{
    fill_tparams();
    return id >= 0 && id < MFX_TP_COUNT ? &tparams[id] : 0;
}

const mfx_param_t *mfx_gparam(int id)
{
    return id >= 0 && id < MFX_GP_COUNT ? &gparams[id] : 0;
}

/* ---- formatting (no libc) ---- */

static char *put_s(char *p, char *end, const char *s)
{
    while (*s && p < end)
        *p++ = *s++;
    return p;
}

static char *put_i(char *p, char *end, int32_t v, int plus)
{
    char tmp[12];
    int n = 0;
    uint32_t u;
    if (v < 0) {
        if (p < end)
            *p++ = '-';
        u = (uint32_t)(-(v + 1)) + 1u;
    } else {
        if (plus && v > 0 && p < end)
            *p++ = '+';
        u = (uint32_t)v;
    }
    do {
        tmp[n++] = (char)('0' + u % 10u);
        u /= 10u;
    } while (u);
    while (n && p < end)
        *p++ = tmp[--n];
    return p;
}

void mfx_format(const mfx_param_t *p, int32_t v, char *out, int n)
{
    char *o = out, *end = out + n - 1;
    if (!p || n <= 0)
        return;
    switch (p->fmt) {
    case MFX_F_ONOFF:
        o = put_s(o, end, v ? "on" : "off");
        break;
    case MFX_F_SIGNED:
        if (p->min == -24 && p->max == MFX_FB_NOTE_RND && v == MFX_FB_NOTE_RND)
            o = put_s(o, end, "RND");
        else if (v == 0 && p->min < 0 && p->max > 0 && p->def == 0)
            o = put_s(o, end, "off");
        else
            o = put_i(o, end, v, 1);
        break;
    case MFX_F_PCT:
        o = put_i(o, end, v, p->min < 0);
        o = put_s(o, end, "%");
        break;
    case MFX_F_MS:
        o = put_i(o, end, v, 0);
        o = put_s(o, end, " ms");
        break;
    case MFX_F_CLK:
        o = put_i(o, end, v, p->min < 0);
        o = put_s(o, end, " clk");
        break;
    case MFX_F_NOTE: {
        static const char *const nn[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
        if (v >= 0 && v < 128) {
            o = put_s(o, end, nn[v % 12]);
            o = put_i(o, end, v / 12 - 1, 0);
        }
        break;
    }
    case MFX_F_ENUM:
        if (p->names && v >= p->min && v <= p->max)
            o = put_s(o, end, p->names[v - p->min]);
        break;
    case MFX_F_CHAN:
        if (v == 0)
            o = put_s(o, end, "off");
        else if (v == 17)
            o = put_s(o, end, "all");
        else
            o = put_i(o, end, v, 0);
        break;
    case MFX_F_OUTCH:
        if (v == 0)
            o = put_s(o, end, "same");
        else
            o = put_i(o, end, v, 0);
        break;
    case MFX_F_PORTS:
        if (v == 0) {
            o = put_s(o, end, "global");
        } else if (p->max == 3) { /* inputs */
            o = put_s(o, end, (v & 1) && (v & 2) ? "TRS+USB" : (v & 1) ? "TRS" : "USB");
        } else {
            int first = 1;
            if (v & 4) {
                o = put_s(o, end, "USB");
                first = 0;
            }
            if (v & 1) {
                o = put_s(o, end, first ? "T1" : "+T1");
                first = 0;
            }
            if (v & 2)
                o = put_s(o, end, first ? "T2" : "+T2");
        }
        break;
    case MFX_F_BPM:
        o = put_i(o, end, v, 0);
        o = put_s(o, end, " bpm");
        break;
    case MFX_F_MASK:
    case MFX_F_INT:
    default:
        o = put_i(o, end, v, 0);
        break;
    }
    *o = '\0';
}
