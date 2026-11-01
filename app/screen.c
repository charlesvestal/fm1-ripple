/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* A droplet's screen (ripple.h scr_*): the whole 240 x 240 canvas (app.h APP_CANVAS_PX) drawn with gfx.c, shown by
 * scr_update. Sixteen levels like norns's, from the deep to the foam, or any colour. Part of the unity build. */

static const uint8_t PAL0[16][3] = {   /* the water: 0 the deep (the background) .. 15 the foam */
    {6, 14, 24}, {10, 24, 38}, {14, 34, 52}, {18, 46, 68}, {22, 58, 84}, {26, 72, 100}, {30, 88, 116}, {34, 104, 132},
    {40, 122, 148}, {50, 140, 162}, {66, 158, 176}, {88, 176, 190}, {116, 194, 204}, {150, 212, 218},
    {190, 230, 232}, {236, 248, 248}};
static uint16_t scr_pal[16];
static uint16_t scr_c;                      /* the colour being drawn with */
static const felucca_font_t *scr_f;
static uint8_t scr_open;                    /* the canvas is the droplet's (cv_begin done) */

static void scr_defaults(void)
{
    uint32_t i;
    for (i = 0; i < 16u; i++)
        scr_pal[i] = RGB(PAL0[i][0], PAL0[i][1], PAL0[i][2]);
    scr_c = scr_pal[15];
    scr_f = &FONT_S;
    scr_open = 0;
}

static void scr_need(void)
{
    if (!scr_open) {
        cv_begin(240, 240, scr_pal[0]);
        scr_open = 1;
    } else {
        lcd_sync();                         /* the last update may still be reading the canvas */
    }
}

void scr_clear(void)
{
    cv_begin(240, 240, scr_pal[0]);
    scr_open = 1;
}
void scr_level(int l) { scr_c = scr_pal[clamp(l, 0, 15)]; }
void scr_color(int r, int g, int b) { scr_c = RGB(clamp(r, 0, 255), clamp(g, 0, 255), clamp(b, 0, 255)); }
void scr_palette(int l, int r, int g, int b)
{
    scr_pal[clamp(l, 0, 15)] = RGB(clamp(r, 0, 255), clamp(g, 0, 255), clamp(b, 0, 255));
}
void scr_font(int f)
{
    static const felucca_font_t *const F[5] = {&FONT_XS, &FONT_S, &FONT_B, &FONT_M, &FONT_L};
    scr_f = F[clamp(f, 1, 5) - 1];
}
void scr_rect(int x, int y, int w, int h) { scr_need(); cv_rect(x, y, w, h, scr_c); }
void scr_frame(int x, int y, int w, int h)
{
    scr_need();
    cv_rect(x, y, w, 1, scr_c);
    cv_rect(x, y + h - 1, w, 1, scr_c);
    cv_rect(x, y, 1, h, scr_c);
    cv_rect(x + w - 1, y, 1, h, scr_c);
}
void scr_line(int x0, int y0, int x1, int y1) { scr_need(); cv_line(x0, y0, x1, y1, scr_c); }
void scr_pixel(int x, int y) { scr_need(); cv_pset(x, y, scr_c); }
void scr_circle(int cx, int cy, int r, int fill)
{
    int x = r, y = 0, err = 1 - r;
    scr_need();
    if (r <= 0) {
        cv_pset(cx, cy, scr_c);
        return;
    }
    while (x >= y) {                        /* midpoint: eight octants at once */
        if (fill) {
            cv_rect(cx - x, cy + y, 2 * x + 1, 1, scr_c);
            cv_rect(cx - x, cy - y, 2 * x + 1, 1, scr_c);
            cv_rect(cx - y, cy + x, 2 * y + 1, 1, scr_c);
            cv_rect(cx - y, cy - x, 2 * y + 1, 1, scr_c);
        } else {
            cv_pset(cx + x, cy + y, scr_c); cv_pset(cx - x, cy + y, scr_c);
            cv_pset(cx + x, cy - y, scr_c); cv_pset(cx - x, cy - y, scr_c);
            cv_pset(cx + y, cy + x, scr_c); cv_pset(cx - y, cy + x, scr_c);
            cv_pset(cx + y, cy - x, scr_c); cv_pset(cx - y, cy - x, scr_c);
        }
        y++;
        if (err < 0)
            err += 2 * y + 1;
        else {
            x--;
            err += 2 * (y - x) + 1;
        }
    }
}
int scr_text_w(const char *s) { return (int)text_w(scr_f, s); }
int scr_text(int x, int y, const char *s, int align)
{
    int w = scr_text_w(s);
    scr_need();
    if (align == 1)
        x -= w / 2;
    else if (align == 2)
        x -= w;
    cv_text(x, y, scr_f, s, scr_c);
    return w;
}
void scr_update(void)
{
    scr_need();
    cv_blit(0, 0);
}
