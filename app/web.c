/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* Ripple's own exports for its emulator page (app.h APP_WEB: base/web/emu/emu_web.c includes this): droplets put on
 * the disk and started by name, what went wrong, and the bridge for currents the page runs itself (flow.c's PLAT_WEB
 * proxy: an uploaded .wasm build of a current, or a Faust current compiled in the page). web/emu/app_worklet.js
 * calls these. */
#define WEB_EXPORT __attribute__((used, visibility("default")))

static uint8_t web_buf[65536 + 256];   /* a name at 0, a file's bytes at 256 */

WEB_EXPORT uint8_t *rp_web_buf(void) { return web_buf; }
WEB_EXPORT uint32_t rp_web_buf_max(void) { return 65536u; }

/* "MySynth.lua" -> "MYSYNTH LUA": the letters, digits, _ and - of its name, eight at most */
static void web_83(const char *name, uint32_t n, const char *ext, char *n83)
{
    uint32_t i, k = 0;
    memset(n83, ' ', 11u);
    for (i = 0; i < n && name[i] != '.' && k < 8u; i++) {
        char c = name[i];
        if (c >= 'a' && c <= 'z')
            c = (char)(c - 32);
        if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_' || c == '-')
            n83[k++] = c;
    }
    if (!k)
        n83[k++] = 'X';
    memcpy(n83 + 8, ext, 3u);
}

/* the file whose name is web_buf[0..name_len) and bytes web_buf[256..256+len) onto the disk, in droplets (where 0)
 * or lib (1): 0 = written (the list again), else disk_write_file's error */
WEB_EXPORT int rp_web_put(int where, uint32_t name_len, uint32_t len)
{
    char n83[11];
    int rc;
    if (name_len > 255u || len > 65536u)
        return -9;
    web_83((const char *)web_buf, name_len, "LUA", n83);
    rc = disk_write_file(where ? "/lib" : "/droplets", n83, web_buf + 256, len);
    if (rc == 0 && ui.mode == MODE_LIST)
        list_scan();
    return rc;
}

/* the droplet named web_buf[0..name_len) (as the list has it, "mysynth"): started, from wherever Ripple is; 1 =
 * started (or it stopped at once on an error: rp_web_error), 0 = no such droplet */
WEB_EXPORT int rp_web_start(uint32_t name_len)
{
    char want[48];
    int i;
    if (name_len > 40u)
        return 0;
    memcpy(want, web_buf, name_len);
    memcpy(want + name_len, ".lua", 5u);
    for (i = 0; want[i]; i++)
        if (want[i] >= 'A' && want[i] <= 'Z')
            want[i] = (char)(want[i] + 32);
    if (ui.mode != MODE_LIST)
        go_list();
    list_scan();
    for (i = 0; i < ui.n; i++)
        if (!strcmp(ui.names[i], want)) {
            ui.sel = i;
            start(i);
            return 1;
        }
    return 0;
}

WEB_EXPORT void rp_web_stop(void) { if (ui.mode != MODE_LIST) go_list(); }
WEB_EXPORT int rp_web_mode(void) { return ui.mode; }          /* 0 list, 1 a droplet runs, 2 it stopped on an error, 3 disk */
WEB_EXPORT const char *rp_web_error(void) { return lr_error(); }
WEB_EXPORT const char *rp_web_running(void) { return ui.mode == MODE_RUN ? run_name : ""; }
/* the console: the last lines the droplet printed (k = 0 the newest) */
WEB_EXPORT const char *rp_web_console(int k) { return k >= 0 && k < CON_LINES ? con[(con_n + CON_LINES - (uint32_t)k) % CON_LINES] : ""; }
