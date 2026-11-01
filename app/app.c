/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* Ripple: the droplets on the disk in a list, one running at a time with the panel, MIDI and the screen its own
 * (HOME held: back to the list); the currents it loaded play in the render. Part of the unity build (device/unity.c,
 * host/plat_host.c), after the platform: gfx.c and announce.c are in scope. */
#include "fastmath.h"
#include "ripple.h"

static void text_cat(char *d, const char *s)
{
    while (*d)
        d++;
    while (*s)
        *d++ = *s++;
    *d = 0;
}

#include "disk.c"
#include "screen.c"
#include "flow.c"

#define SET_MAGIC 0x52505031u            /* "1PPR": the settings record */
typedef struct {
    uint32_t magic;
    char last[40];                       /* the droplet last started: the list starts on it */
} settings_t;
static settings_t set;
static void int_cat(char *d, int32_t v)
{
    char t[12];
    int n = 0;
    uint32_t u = (uint32_t)(v < 0 ? -v : v);
    while (*d)
        d++;
    do
        t[n++] = (char)('0' + u % 10u);
    while ((u /= 10u) && n < 11);
    if (v < 0)
        *d++ = '-';
    while (n)
        *d++ = t[--n];
    *d = 0;
}
static uint32_t crumb_boot_step, crumb_boot_render, crumb_boot_sp, crumb_boot_spmin;
static char crumb_boot_what[24];

/* ------------------------------------------------------------ the console --- */
#define CON_LINES 6
static char con[CON_LINES][40];
static uint32_t con_n;                   /* lines written (the newest: (con_n - 1) % CON_LINES) */
static uint32_t con_col;
void rp_print(const char *s, size_t n)
{
    size_t i;
    for (i = 0; i < n; i++) {
        char *ln = con[con_n % CON_LINES];
        if (s[i] == '\n' || con_col >= sizeof con[0] - 1u) {
            ln[con_col] = 0;
#ifdef PLAT_HOST
            plat_log(ln);
#endif
            con_n++;
            con_col = 0;
            con[con_n % CON_LINES][0] = 0;
            if (s[i] == '\n')
                continue;
            ln = con[con_n % CON_LINES];
        }
        ln[con_col++] = s[i];
        ln[con_col] = 0;
    }
}

/* ------------------------------------------------------- glue (ripple.h) --- */
int rp_load(const char *name, const char **err)
{
    int h = flow_load(name);
    if (h < 0 && err)
        *err = flow_err;
    return h;
}
int rp_param(int h, const char *name) { return flow_param(h, name); }
int rp_nparams(int h) { const rc_desc_t *d = flow_desc(h); return d ? d->nparams : 0; }
const char *rp_param_info(int h, int p, float *mn, float *mx, float *df)
{
    const rc_desc_t *d = flow_desc(h);
    if (!d || p < 0 || p >= (int)d->nparams)
        return "";
    *mn = d->params[p].min;
    *mx = d->params[p].max;
    *df = d->params[p].def;
    return d->params[p].name;
}
const char *rp_name(int h) { return flow_desc(h) ? curs[h].name : ""; }
int rp_voices(int h) { const rc_desc_t *d = flow_desc(h); return d ? d->voices : 0; }
void rp_set(int h, int p, float v) { flow_set(h, p, v); }
void rp_note(int h, int note, float vel) { flow_note(h, note, vel); }
void rp_route(const int *hs, int n) { flow_route(hs, n); }
void rp_level(float v) { flow_gain = fm_clampf(v, 0.0f, 1.0f); }
float rp_peak(void) { return flow_peak; }

static uint32_t led_btn, led_key_bits;
void rp_midi(int b0, int b1, int b2)
{
    uint32_t st = (uint32_t)b0 & 0xFFu, cin = st >> 4;
    if (st < 0x80u)
        return;
    if (st >= 0xF0u)
        cin = 0xFu;                      /* one-byte system messages only (clock, start, stop) */
    plat_midi_send(cin | st << 8 | ((uint32_t)b1 & 0x7Fu) << 16 | ((uint32_t)b2 & 0x7Fu) << 24, TO_USB);
}
void rp_led_key(int k, int on)
{
    if (k < 0 || k >= NKEYS)
        return;
    led_key_bits = on ? led_key_bits | 1u << k : led_key_bits & ~(1u << k);
}
void rp_led_button(int b, int on) { led_btn = on ? led_btn | 1u << b : led_btn & ~(1u << b); }
static const char *const BTN_NAME[NB] = {"FX", "SEL", "ENV", "LFO", "EDIT", "GLO", "HOME", "SAVE", "ARP", "SEQ",
                                         "PLAY", "REC", "OCT-", "OCT+"};
int rp_button_index(const char *name)
{
    int b;
    for (b = 0; b < NB; b++)
        if (!strcmp(BTN_NAME[b], name))
            return b;
    return -1;
}
const char *rp_button_name(int b) { return b >= 0 && b < NB ? BTN_NAME[b] : "?"; }
uint32_t rp_ms(void) { return plat_ms(); }
void rp_crumb(uint32_t step, const char *what) { crumb_set(step, what); }

/* the running droplet's data file: its name in 8.3, from the droplet's ("awake.lua" -> AWAKE.DAT) */
static char run_name[40];
static void data_name(char *n83)
{
    uint32_t i, k = 0;
    memset(n83, ' ', 11u);
    for (i = 0; run_name[i] && run_name[i] != '.' && k < 8u; i++) {
        char c = run_name[i];
        if (c >= 'a' && c <= 'z')
            c = (char)(c - 32);
        if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_' || c == '-')
            n83[k++] = c;
    }
    if (!k)
        n83[k++] = 'X';
    n83[8] = 'D';
    n83[9] = 'A';
    n83[10] = 'T';
}
int rp_data_write(const char *s, size_t n)
{
    char n83[11];
    int rc;
    data_name(n83);
    route_n = 0;                             /* (the sound pauses while the flash is written) */
    rc = disk_write_file("/data", n83, s, (uint32_t)n);
    flow_route_restore();
    return rc;
}
int rp_data_read(char *d, size_t max)
{
    char n83[11], path[24] = "/data/";
    disk_file_t f;
    uint32_t i, k = 6;
    data_name(n83);
    for (i = 0; i < 8u && n83[i] != ' '; i++)
        path[k++] = n83[i];
    memcpy(path + k, ".DAT", 5u);
    if (disk_open(path, &f) != 0 || f.dir)
        return -1;
    return (int)disk_read(&f, 0, d, (uint32_t)(f.size < max ? f.size : max));
}

/* ------------------------------------------------------------- the sound --- */
void app_render(int32_t *lr, uint32_t n, uint32_t master_q12) { flow_render(lr, n, master_q12); }
void app_panic(void) { route_n = 0; }

void app_init(void)
{
    if (plat_store_load(OBJ_SETTINGS, &set, sizeof set) != (int)sizeof set || set.magic != SET_MAGIC) {
        memset(&set, 0, sizeof set);
        set.magic = SET_MAGIC;
    }
    set.last[sizeof set.last - 1u] = 0;
    if (crumb.magic == CRUMB_MAGIC) {        /* where the last start got to (a watchdog reset keeps it) */
        crumb_boot_step = crumb.step;
        crumb_boot_render = crumb.in_render;
        crumb_boot_sp = crumb.sp;
        crumb_boot_spmin = crumb.sp_min;
        memcpy(crumb_boot_what, crumb.what, sizeof crumb_boot_what);
        crumb_boot_what[sizeof crumb_boot_what - 1u] = 0;
    }
    if (crumb.magic != CRUMB_MAGIC)
        crumb.boots = 0;
    crumb.boots++;
    crumb.sp_min = 0;
    crumb_set(0, "boot");
    crumb.in_render = 0;
    plat_code_window(arena + sizeof arena);   /* the currents' code may run in the arena */
    if (!disk_ok())                      /* a new FM-1, or a disk the computer broke: an empty one */
        disk_format_default();
}

/* ---------------------------------------------------------------- the UI --- */
enum { MODE_LIST, MODE_RUN, MODE_ERROR, MODE_DISK };
#define NLIST 24
static struct {
    uint8_t mode, redraw;
    char names[NLIST][40];               /* the droplets (the disk's, then the built-in ones not replaced), in order */
    uint8_t mine[NLIST];                 /* 1: on the disk, 0: built in */
    int n, sel, top;
    uint32_t confirm_until;              /* "empty the disk" asked once: a second press within this does it */
    uint32_t keys, btn, home_t;
    char msg[2][24];
    uint32_t msg_until;
} ui;
enum { SYS_DISK, SYS_RESTORE, NSYS };    /* the entries after the droplets */
#define SYS_N NSYS

void app_say(const char *a, const char *b)
{
    uint32_t i;
    for (i = 0; i < 23u && a && a[i]; i++)
        ui.msg[0][i] = a[i];
    ui.msg[0][i] = 0;
    for (i = 0; i < 23u && b && b[i]; i++)
        ui.msg[1][i] = b[i];
    ui.msg[1][i] = 0;
    ui.msg_until = plat_ms() + 1500u;
    ui.redraw = 1;
    if (ann_on())
        ann_say(ui.msg[0], ui.msg[1], ANN_NOW);
}

static int ends_lua(const char *s)
{
    size_t n = strlen(s);
    return n > 4u && (s[n - 4] == '.') && (s[n - 3] | 32) == 'l' && (s[n - 2] | 32) == 'u' && (s[n - 1] | 32) == 'a';
}

static void list_scan(void)
{
    char name[40];
    disk_file_t f;
    int i, v, k, j;
    ui.n = 0;
    for (v = DISK_VOL; v <= BUILTIN_VOL; v++)     /* the disk's first: a built-in one of the same name is replaced */
        for (i = 0; ui.n < NLIST - 1 && disk_entry(v, "/droplets", i, name, sizeof name, &f); i++) {
            if (f.dir || !ends_lua(name))
                continue;
            for (k = 0; k < ui.n && strcmp(ui.names[k], name); k++)
                ;
            if (k < ui.n)
                continue;
            k = ui.n++;
            strcpy(ui.names[k], name);
            ui.mine[k] = v == DISK_VOL;
            for (j = k; j > 0 && strcmp(ui.names[j - 1], ui.names[j]) > 0; j--) {   /* in order */
                char t[40];
                uint8_t m = ui.mine[j];
                strcpy(t, ui.names[j]);
                strcpy(ui.names[j], ui.names[j - 1]);
                strcpy(ui.names[j - 1], t);
                ui.mine[j] = ui.mine[j - 1];
                ui.mine[j - 1] = m;
            }
        }
    ui.sel = 0;
    for (i = 0; i < ui.n; i++)
        if (!strcmp(ui.names[i], set.last))
            ui.sel = i;
    ui.redraw = 1;
}

static void stem(const char *name, char *out)  /* "poly.lua" -> "poly" */
{
    size_t n = strlen(name);
    memcpy(out, name, n - 4u);
    out[n - 4u] = 0;
}

static void go_list(void)
{
    lr_stop();
    flow_reset();
    led_btn = led_key_bits = 0;
    ui.mode = MODE_LIST;
    scr_defaults();
    list_scan();
}

static void start(int i)
{
    char path[64] = "/droplets/", t[40];
    text_cat(path, ui.names[i]);
    crumb_set(1, ui.names[i]);
    if (strcmp(set.last, ui.names[i])) {
        strcpy(set.last, ui.names[i]);
        plat_store_save(OBJ_SETTINGS, &set, sizeof set);
    }
    crumb_set(2, ui.names[i]);
    flow_reset();
    scr_defaults();
    con_n = con_col = 0;
    con[0][0] = 0;
    led_btn = led_key_bits = 0;
    stem(ui.names[i], t);
    strcpy(run_name, ui.names[i]);
    crumb_set(3, ui.names[i]);
    if (lr_start(path) != 0) {
        flow_reset();
        ui.mode = MODE_ERROR;
    } else {
        crumb_set(9, "running");
        ui.mode = MODE_RUN;
        if (ann_on())
            ann_say(t, 0, ANN_NOW);
    }
    ui.redraw = 1;
}

static void draw_list(void)
{
    int i, rows = 9, y;
    char t[40];
    uint32_t used, peak;
    cv_begin(240, 240, scr_pal[0]);
    cv_text(12, 10, &FONT_B, "RIPPLE", scr_pal[14]);
    cv_text(84, 12, &FONT_XS, "droplets", scr_pal[8]);
    cv_rect(12, 32, 216, 1, scr_pal[3]);
    if (ui.sel < ui.top)
        ui.top = ui.sel;
    if (ui.sel >= ui.top + rows)
        ui.top = ui.sel - rows + 1;
    for (i = ui.top, y = 40; i < ui.n + SYS_N && i < ui.top + rows; i++, y += 20) {
        int on = i == ui.sel;
        if (on)
            cv_rect(8, y - 2, 224, 20, scr_pal[4]);
        if (i < ui.n) {
            stem(ui.names[i], t);
            if (ui.mine[i])                  /* yours: a filled drop; built in: an outline */
                cv_rect(16, y + 6, 5, 5, on ? scr_pal[15] : scr_pal[9]);
            else {
                cv_rect(16, y + 6, 5, 1, on ? scr_pal[15] : scr_pal[6]);
                cv_rect(16, y + 10, 5, 1, on ? scr_pal[15] : scr_pal[6]);
                cv_rect(16, y + 6, 1, 5, on ? scr_pal[15] : scr_pal[6]);
                cv_rect(20, y + 6, 1, 5, on ? scr_pal[15] : scr_pal[6]);
            }
            cv_text(30, y, &FONT_S, t, on ? scr_pal[15] : scr_pal[12]);
        } else {
            cv_text(30, y, &FONT_S, i - ui.n == SYS_DISK ? "disk mode" :
                    plat_ms() < ui.confirm_until ? "PLAY again: erase your files" : "empty the disk",
                    on ? scr_pal[15] : scr_pal[8]);
        }
    }
    if (!ui.n)
        cv_text(30, 60, &FONT_S, "no droplets", scr_pal[10]);
    cv_rect(12, 220, 216, 1, scr_pal[3]);
    used = lr_mem(&peak);
    (void)used;
    cv_text(12, 224, &FONT_XS, "PLAY start   HOME held: back", scr_pal[8]);
    if (plat_ms() < ui.msg_until) {
        cv_rect(0, 196, 240, 22, scr_pal[2]);
        cv_text(12, 199, &FONT_S, ui.msg[0], scr_pal[15]);
        cv_text(12 + text_w(&FONT_S, ui.msg[0]) + 8, 199, &FONT_S, ui.msg[1], scr_pal[11]);
    }
    cv_blit(0, 0);
}

/* disk mode: the FM-1 as a USB drive until the computer ejects it (or HOME) */
static uint8_t disk_state;
static void disk_mode(int on)
{
    if (on) {
        lr_stop();
        flow_reset();
        ui.mode = MODE_DISK;
        disk_state = PLAT_DISK_WAITING;
        plat_disk_mode(&DISK_MODE);
    } else {
        plat_disk_mode(0);
        disk_mount();
        go_list();
        app_say("DISK", "BACK");
    }
    ui.redraw = 1;
}

void app_loop(void)
{
    int st;
    if (ui.mode != MODE_DISK)
        return;
    st = plat_disk_poll();
    if (wc_dirty && plat_disk_idle_ms() > 400u)
        wc_flush();                      /* a pause: what the computer wrote, in the flash */
    if (st != disk_state) {
        disk_state = (uint8_t)st;
        ui.redraw = 1;
        if (st == PLAT_DISK_EJECTED)
            disk_mode(0);
    }
}

static void draw_disk(void)
{
    static const char *const SAY[] = {"", "connect the FM-1 to a computer", "on the computer: a drive called RIPPLE",
                                      ""};
    cv_begin(240, 240, scr_pal[0]);
    cv_text(12, 10, &FONT_B, "RIPPLE", scr_pal[14]);
    cv_text(84, 12, &FONT_XS, "disk mode", scr_pal[8]);
    cv_rect(12, 32, 216, 1, scr_pal[3]);
    cv_rect(84, 70, 72, 52, scr_pal[2]);     /* a drive */
    cv_rect(92, 78, 56, 26, scr_pal[disk_state == PLAT_DISK_MOUNTED ? 12 : 5]);
    cv_rect(140, 110, 8, 4, scr_pal[disk_state == PLAT_DISK_MOUNTED ? 15 : 6]);
    cv_text(120 - text_w(&FONT_S, SAY[disk_state & 3u]) / 2, 140, &FONT_S, SAY[disk_state & 3u], scr_pal[13]);
    cv_text(12, 168, &FONT_XS, "droplets go in /droplets, currents in /currents", scr_pal[9]);
    cv_text(12, 184, &FONT_XS, "eject the drive when done: Ripple comes back", scr_pal[9]);
    cv_rect(12, 220, 216, 1, scr_pal[3]);
    cv_text(12, 224, &FONT_XS, "HOME: back now", scr_pal[8]);
    cv_blit(0, 0);
}

static void draw_error(void)
{
    const char *e = lr_error();
    int y = 44, x;
    uint32_t i, k;
    cv_begin(240, 240, RGB(30, 10, 14));
    cv_text(12, 10, &FONT_B, "the droplet stopped", RGB(250, 150, 140));
    cv_rect(12, 32, 216, 1, RGB(110, 40, 44));
    /* the error, wrapped at the screen's edge */
    while (*e && y < 170) {
        char ln[48];
        int n = 0, cut = -1;
        x = 0;
        while (e[n] && e[n] != '\n' && n < 46) {
            char one[2] = {e[n], 0};
            x += text_w(&FONT_XS, one);
            if (x > 216)
                break;
            if (e[n] == ' ')
                cut = n;
            n++;
        }
        if (e[n] && e[n] != '\n' && cut > 0)
            n = cut;
        memcpy(ln, e, (size_t)n);
        ln[n] = 0;
        cv_text(12, y, &FONT_XS, ln, RGB(240, 220, 220));
        y += 14;
        e += n;
        while (*e == ' ' || *e == '\n')
            e++;
    }
    /* what it printed last */
    for (i = con_n > 2u ? con_n - 2u : 0, k = 0; i <= con_n; i++, k++)
        if (con[i % CON_LINES][0])
            cv_text(12, 178 + (int)k * 14, &FONT_XS, con[i % CON_LINES], RGB(170, 150, 150));
    cv_text(12, 224, &FONT_XS, "HOME: back to the droplets", RGB(200, 140, 140));
    cv_blit(0, 0);
}

static void input(void)
{
    uint32_t keys, btn = plat_buttons(), k, now = plat_ms();
    uint32_t pkt;
    int port, e;
    touch_poll();
    keys = touch_keys();
    if (ui.mode == MODE_RUN) {
        for (k = 0; k < NKEYS; k++) {
            uint32_t bit = 1u << k;
            if ((keys & bit) && !(ui.keys & bit))
                lr_key((int)k, touch_vel(k));
            else if (!(keys & bit) && (ui.keys & bit))
                lr_key((int)k, 0);
        }
        for (k = 0; k < NB; k++) {
            uint32_t bit = 1u << k;
            if ((btn ^ ui.btn) & bit)
                lr_button((int)k, (btn & bit) ? 1 : 0);
        }
        {
            static const uint8_t ROLE_N[NE] = {5, 6, 7, 1, 2, 3, 4};   /* EN_SELECT, EN_ALGO, EN_PRESET, K1..K4 */
            for (k = 0; k < NE; k++)
                if ((e = plat_enc((int)k)) != 0)
                    lr_enc(ROLE_N[k], e);
        }
        while (plat_midi_in(&pkt, &port))
            lr_midi((int)(pkt >> 8 & 0xFFu), (int)(pkt >> 16 & 0x7Fu), (int)(pkt >> 24 & 0x7Fu));
        lr_tick(now);
        if (!lr_running()) {             /* it stopped on an error */
            flow_reset();
            ui.mode = MODE_ERROR;
            ui.redraw = 1;
        }
    } else {
        while (plat_midi_in(&pkt, &port))
            ;
        for (k = 0; k < NE; k++)
            if ((e = plat_enc((int)k)) != 0 && ui.mode == MODE_LIST) {
                ui.sel = (int)clamp(ui.sel + e, 0, ui.n + SYS_N - 1);
                ui.redraw = 1;
            }
        if (ui.mode == MODE_LIST) {
            uint32_t press = btn & ~ui.btn;
            if (press & (1u << B_OCTDN)) { ui.sel = (int)clamp(ui.sel - 1, 0, ui.n + SYS_N - 1); ui.redraw = 1; }
            if (press & (1u << B_OCTUP)) { ui.sel = (int)clamp(ui.sel + 1, 0, ui.n + SYS_N - 1); ui.redraw = 1; }
            if (press & ((1u << B_PLAY) | (1u << B_SEL))) {
                if (ui.sel < ui.n)
                    start(ui.sel);
                else if (ui.sel - ui.n == SYS_DISK)
                    disk_mode(1);
                else if (plat_ms() < ui.confirm_until) {   /* asked twice: the disk emptied */
                    ui.confirm_until = 0;
                    disk_format_default();
                    list_scan();
                    app_say("DISK", "EMPTIED");
                } else {
                    ui.confirm_until = plat_ms() + 3000u;
                    ui.redraw = 1;
                }
            }
        } else if ((ui.mode == MODE_ERROR || ui.mode == MODE_DISK) && (btn & ~ui.btn & (1u << B_HOME))) {
            if (ui.mode == MODE_DISK)
                disk_mode(0);
            else
                go_list();
        }
    }
    /* HOME held a second: back to the list, from anywhere */
    if (btn & (1u << B_HOME)) {
        if (!(ui.btn & (1u << B_HOME)))
            ui.home_t = now;
        else if (ui.home_t && now - ui.home_t >= 1000u) {
            ui.home_t = 0;
            if (ui.mode == MODE_RUN)
                go_list();
        }
    }
    ui.keys = keys;
    ui.btn = btn;
    if (ui.mode == MODE_RUN)
        plat_lights(led_btn, led_key_bits, 0, 0, 0);
    else
        plat_leds(ui.mode == MODE_LIST ? 1u << B_PLAY : 1u << B_HOME, 0);
}

void app_input_only(void) { input(); }

void app_ui_init(void)
{
    touch_on(1);
    scr_defaults();
    if (ui.mode == MODE_RUN && lr_running()) {
        scr_clear();
        ui.redraw = 0;
        return;
    }
    go_list();
}

static void speak(void)
{
    char t[200], n[12];
    if (!ann_on() || !ann_where())
        return;
    t[0] = 0;
    text_cat(t, ui.mode == MODE_LIST ? "LIST" : ui.mode == MODE_RUN ? "RUN" : ui.mode == MODE_ERROR ? "ERROR " : "DISK");
    if (ui.mode == MODE_ERROR) {
        uint32_t k = strlen(t), i;
        for (i = 0; lr_error()[i] && k < 70u; i++)
            t[k++] = lr_error()[i];
        t[k] = 0;
    }
    text_cat(t, ". BEFORE: STEP ");
    n[0] = (char)('0' + crumb_boot_step / 10u % 10u);
    n[1] = (char)('0' + crumb_boot_step % 10u);
    n[2] = ' ';
    n[3] = (char)('0' + crumb_boot_render % 10u);
    n[4] = ' ';
    n[5] = 0;
    text_cat(t, n);
    text_cat(t, crumb_boot_what);
    {
        char u[80] = ". UP ";
        int_cat(u, (int32_t)(plat_ms() / 1000u));
        text_cat(u, " BOOTS ");
        int_cat(u, (int32_t)crumb.boots);
        text_cat(u, " SP ");
        int_cat(u, (int32_t)(crumb_boot_sp & 0xFFFFFu));
        text_cat(u, " MIN ");
        int_cat(u, (int32_t)(crumb_boot_spmin & 0xFFFFFu));
        text_cat(u, " CPU ");
        int_cat(u, (int32_t)plat_cpu_pct());
        text_cat(t, u);
    }
    ann_say(t, 0, ANN_NOW);
}

void app_frame(void)
{
    static uint32_t last_msg;
    input();
    speak();
    ann_tick(plat_ms());
    if (ui.confirm_until && plat_ms() >= ui.confirm_until) {   /* the question goes away */
        ui.confirm_until = 0;
        ui.redraw = 1;
    }
    if (ui.msg_until && plat_ms() >= ui.msg_until && last_msg != ui.msg_until) {
        last_msg = ui.msg_until;
        ui.redraw = 1;
    }
    if (ui.redraw) {
        ui.redraw = 0;
        if (ui.mode == MODE_LIST)
            draw_list();
        else if (ui.mode == MODE_ERROR)
            draw_error();
        else if (ui.mode == MODE_DISK)
            draw_disk();
    }
}

#ifdef PLAT_HOST
int app_expect(const char *what, int *got)
{
    if (!strcmp(what, "mode"))
        *got = ui.mode;
    else if (!strcmp(what, "droplets"))
        *got = ui.n;
    else if (!strcmp(what, "currents"))
        *got = (int)ncurs;
    else if (!strcmp(what, "route"))
        *got = route_n;
    else if (!strcmp(what, "mem_kb"))
        *got = (int)(lr_mem(0) / 1024u);
    else if (!strcmp(what, "peak_kb")) {
        uint32_t p;
        lr_mem(&p);
        *got = (int)(p / 1024u);
    } else if (!strcmp(what, "error")) {    /* 1: the droplet stopped with an error (printed) */
        *got = lr_error()[0] != 0;
        if (*got)
            printf("  droplet error: %s\n", lr_error());
    } else if (!strcmp(what, "arena_kb"))
        *got = (int)(arena_top / 1024u);
    else
        return 0;
    return 1;
}
#endif
