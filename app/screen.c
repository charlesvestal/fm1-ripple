/* A droplet's screen (ripple.h scr_*), and Ripple's own (app.c: the list, disk mode, the error): drawing is recorded, a
 * small list of what to draw (dl_*), and shown by replaying it into six bands of 40 rows, two at a time in the canvas
 * (app.h APP_CANVAS_PX: 240 x 80, 38 KB where a whole screen was 112.5 KB), one band drawn while the one before is
 * sent. Drawing without clearing adds to what is there, as on a canvas, until the list is full (dl_lost counts what
 * did not fit). Sixteen levels like norns's, from the deep to the foam, or any colour. Part of the unity build. */

static const uint8_t PAL0[16][3] = {   /* the water: 0 the deep (the background) .. 15 the foam */
    {6, 14, 24}, {10, 24, 38}, {14, 34, 52}, {18, 46, 68}, {22, 58, 84}, {26, 72, 100}, {30, 88, 116}, {34, 104, 132},
    {40, 122, 148}, {50, 140, 162}, {66, 158, 176}, {88, 176, 190}, {116, 194, 204}, {150, 212, 218},
    {190, 230, 232}, {236, 248, 248}};
static uint16_t scr_pal[16];
static uint16_t scr_c;                      /* the colour being drawn with */
static const felucca_font_t *scr_f;

/* ------------------------------------------------------------ the list --- */
enum { OP_RECT, OP_LINE, OP_PIXEL, OP_CIRCLE, OP_DISC, OP_TEXT };
typedef struct {
    uint8_t op, font;                       /* font: an index into DL_FONTS (text) */
    uint16_t c;                             /* the colour, RGB565 */
    int16_t a, b, w, h;                     /* rect x y w h; line x0 y0 x1 y1; circle x y r; text x y, w: the string */
} dl_op_t;
#define DL_OPS 1536u
#define DL_STR 4096u
#define DL_BAND 40                          /* rows a band; the canvas holds two */
static dl_op_t dl[DL_OPS] PLAT_POOL;
static char dl_str[DL_STR] PLAT_POOL;
static uint32_t dl_n, dl_sn, dl_lost, dl_peak;   /* ops, string bytes, ops that did not fit, the most ops shown */
static uint16_t dl_bg;
static const felucca_font_t *const DL_FONTS[] = {&FONT_XS, &FONT_S, &FONT_B, &FONT_M, &FONT_L};

static void dl_begin(uint16_t bg)
{
    dl_n = dl_sn = 0;
    dl_bg = bg;
}

static dl_op_t *dl_add(int op, uint16_t c)
{
    dl_op_t *o;
    if (dl_n >= DL_OPS) {
        dl_lost++;
        return 0;
    }
    o = &dl[dl_n++];
    o->op = (uint8_t)op;
    o->c = c;
    return o;
}

static int16_t s16(int v) { return (int16_t)(v < -9999 ? -9999 : v > 9999 ? 9999 : v); }

static void dl_rect(int x, int y, int w, int h, uint16_t c)
{
    dl_op_t *o;
    if (w <= 0 || h <= 0 || x >= 240 || y >= 240 || x + w <= 0 || y + h <= 0 || !(o = dl_add(OP_RECT, c)))
        return;
    o->a = s16(x), o->b = s16(y), o->w = s16(w), o->h = s16(h);
}

static void dl_line(int x0, int y0, int x1, int y1, uint16_t c)
{
    dl_op_t *o = dl_add(OP_LINE, c);
    if (o)
        o->a = s16(x0), o->b = s16(y0), o->w = s16(x1), o->h = s16(y1);
}

static void dl_circle(int x, int y, int r, int fill, uint16_t c)
{
    dl_op_t *o = dl_add(fill ? OP_DISC : OP_CIRCLE, c);
    if (o)
        o->a = s16(x), o->b = s16(y), o->w = s16(r < 0 ? 0 : r > 400 ? 400 : r);
}

static int32_t dl_text(int32_t x, int32_t y, const felucca_font_t *f, const char *s, uint16_t c)
{
    uint32_t n = strlen(s), k;
    dl_op_t *o;
    for (k = 0; k < sizeof DL_FONTS / sizeof DL_FONTS[0] - 1u && DL_FONTS[k] != f; k++)
        ;
    if (dl_sn + n + 1u > DL_STR) {
        dl_lost++;
        return x + text_w(f, s);
    }
    if ((o = dl_add(OP_TEXT, c)) != 0) {
        o->a = s16(x), o->b = s16(y), o->w = (int16_t)dl_sn, o->font = (uint8_t)k;
        memcpy(dl_str + dl_sn, s, n + 1u);
        dl_sn += n + 1u;
    }
    return x + text_w(f, s);
}

/* a circle into the band (the midpoint way: eight octants at once) */
static void band_circle(int cx, int cy, int r, int fill, uint16_t c)
{
    int x = r, y = 0, err = 1 - r;
    if (r <= 0) {
        cv_pset(cx, cy, c);
        return;
    }
    while (x >= y) {
        if (fill) {
            cv_rect(cx - x, cy + y, 2 * x + 1, 1, c);
            cv_rect(cx - x, cy - y, 2 * x + 1, 1, c);
            cv_rect(cx - y, cy + x, 2 * y + 1, 1, c);
            cv_rect(cx - y, cy - x, 2 * y + 1, 1, c);
        } else {
            cv_pset(cx + x, cy + y, c); cv_pset(cx - x, cy + y, c);
            cv_pset(cx + x, cy - y, c); cv_pset(cx - x, cy - y, c);
            cv_pset(cx + y, cy + x, c); cv_pset(cx - y, cy + x, c);
            cv_pset(cx + y, cy - x, c); cv_pset(cx - y, cy - x, c);
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

/* the list onto the screen: each band cleared, every op that reaches it drawn (clipped to it), sent; the next band
 * is drawn into the canvas's other half while this one goes (lcd_blit returns at once; it waits for the one before) */
static void dl_show(void)
{
    uint32_t i, k, half = 0;
    int y;
    uint16_t bg = swap16(dl_bg);
    lcd_sync();                             /* (someone else's drawing may have the canvas: theirs sent first) */
    cv_w = 240u;
    cv_h = 2u * DL_BAND;
    for (y = 0; y < 240; y += DL_BAND, half ^= 1u) {
        uint16_t *px = cv_px + half * DL_BAND * 240u;
        int y1 = y + DL_BAND;
        for (i = 0; i < DL_BAND * 240u; i++)
            px[i] = bg;
        cv_oy = (int32_t)(half * DL_BAND) - y;
        cv_y0 = (int32_t)(half * DL_BAND);
        cv_y1 = cv_y0 + DL_BAND;
        for (k = 0; k < dl_n; k++) {
            const dl_op_t *o = &dl[k];
            switch (o->op) {
            case OP_RECT:
                if (o->b < y1 && o->b + o->h > y)
                    cv_rect(o->a, o->b, o->w, o->h, o->c);
                break;
            case OP_LINE:
                if ((o->b < y1 || o->h < y1) && (o->b >= y || o->h >= y))
                    cv_line(o->a, o->b, o->w, o->h, o->c);
                break;
            case OP_PIXEL:
                cv_pset(o->a, o->b, o->c);
                break;
            case OP_CIRCLE:
            case OP_DISC:
                if (o->b - o->w < y1 && o->b + o->w >= y)
                    band_circle(o->a, o->b, o->w, o->op == OP_DISC, o->c);
                break;
            default: {
                const felucca_font_t *f = DL_FONTS[o->font];
                if (o->b < y1 && o->b + (int)f->h > y)
                    cv_text(o->a, o->b, f, dl_str + o->w, o->c);
                break;
            }
            }
        }
        lcd_blit(0, (uint32_t)y, 240u, DL_BAND, px);
    }
    if (dl_n > dl_peak)
        dl_peak = dl_n;
}

static void scr_defaults(void)
{
    uint32_t i;
    for (i = 0; i < 16u; i++)
        scr_pal[i] = RGB(PAL0[i][0], PAL0[i][1], PAL0[i][2]);
    scr_c = scr_pal[15];
    scr_f = &FONT_S;
    dl_begin(scr_pal[0]);
}

void scr_clear(void) { dl_begin(scr_pal[0]); }
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
void scr_rect(int x, int y, int w, int h) { dl_rect(x, y, w, h, scr_c); }
void scr_frame(int x, int y, int w, int h)
{
    dl_rect(x, y, w, 1, scr_c);
    dl_rect(x, y + h - 1, w, 1, scr_c);
    dl_rect(x, y, 1, h, scr_c);
    dl_rect(x + w - 1, y, 1, h, scr_c);
}
void scr_line(int x0, int y0, int x1, int y1) { dl_line(x0, y0, x1, y1, scr_c); }
void scr_pixel(int x, int y)
{
    dl_op_t *o;
    if ((unsigned)x < 240u && (unsigned)y < 240u && (o = dl_add(OP_PIXEL, scr_c)) != 0)
        o->a = (int16_t)x, o->b = (int16_t)y;
}
void scr_circle(int cx, int cy, int r, int fill) { dl_circle(cx, cy, r, fill, scr_c); }
int scr_text_w(const char *s) { return (int)text_w(scr_f, s); }
int scr_text(int x, int y, const char *s, int align)
{
    int w = scr_text_w(s);
    if (align == 1)
        x -= w / 2;
    else if (align == 2)
        x -= w;
    dl_text(x, y, scr_f, s, scr_c);
    return w;
}
void scr_update(void) { dl_show(); }
