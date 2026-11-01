/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* The disk (disk.h): FAT12 read in place from the data flash. The geometry comes from the boot sector, so a volume
 * the computer formatted again still reads. Long names (VFAT) are read; writes come only from disk mode (msc.c) and
 * from disk_format_default. Part of the unity build (app.c). */
#include "disk.h"
#include "disk_image.h"                     /* the shipped volume (tools/mkdisk.py) */

static struct {
    uint32_t fat_lba, root_lba, root_n, data_lba, nclusters, spc;   /* in sectors; spc: sectors a cluster */
    uint8_t ok;
} dk;

const uint8_t *disk_sector(uint32_t lba)
{
    return lba < DISK_SECTORS ? plat_data(DISK_LO + lba * 512u) : 0;
}

static uint16_t rd16(const uint8_t *p) { return (uint16_t)(p[0] | p[1] << 8); }
static uint32_t rd32(const uint8_t *p) { return (uint32_t)(p[0] | p[1] << 8 | p[2] << 16 | (uint32_t)p[3] << 24); }

static void disk_mount(void)
{
    const uint8_t *b = disk_sector(0);
    uint32_t bps, rsv, nfat, nroot, tot, spf;
    dk.ok = 0;
    if (!b || b[510] != 0x55 || b[511] != 0xAA)
        return;
    bps = rd16(b + 11);
    dk.spc = b[13];
    rsv = rd16(b + 14);
    nfat = b[16];
    nroot = rd16(b + 17);
    tot = rd16(b + 19) ? rd16(b + 19) : rd32(b + 32);
    spf = rd16(b + 22);
    if (bps != 512u || !dk.spc || !nfat || !spf || tot > DISK_SECTORS)
        return;
    dk.fat_lba = rsv;
    dk.root_lba = rsv + nfat * spf;
    dk.root_n = (nroot * 32u + 511u) / 512u;
    dk.data_lba = dk.root_lba + dk.root_n;
    if (dk.data_lba >= tot)
        return;
    dk.nclusters = (tot - dk.data_lba) / dk.spc;
    if (dk.nclusters >= 4085u)              /* FAT12 only */
        return;
    dk.ok = 1;
}

int disk_ok(void)
{
    disk_mount();
    return dk.ok;
}

static uint32_t fat_next(uint32_t c)
{
    uint32_t off = c + c / 2u, v;
    const uint8_t *s0 = disk_sector(dk.fat_lba + off / 512u), *s1 = disk_sector(dk.fat_lba + (off + 1u) / 512u);
    if (!s0 || !s1)
        return 0xFFFu;
    v = s0[off % 512u] | (uint32_t)s1[(off + 1u) % 512u] << 8;
    return c & 1u ? v >> 4 : v & 0xFFFu;
}

static int cl_ok(uint32_t c) { return c >= 2u && c < dk.nclusters + 2u; }

/* sector k of a chain (the root directory when cluster 0): 0 past the end */
static const uint8_t *chain_sector(uint32_t cluster, uint32_t k)
{
    uint32_t hops;
    if (!cluster)
        return k < dk.root_n ? disk_sector(dk.root_lba + k) : 0;
    for (hops = k / dk.spc; hops; hops--) {
        if (!cl_ok(cluster))
            return 0;
        cluster = fat_next(cluster);
    }
    if (!cl_ok(cluster))
        return 0;
    return disk_sector(dk.data_lba + (cluster - 2u) * dk.spc + k % dk.spc);
}

uint32_t disk_read(const disk_file_t *f, uint32_t off, void *dst, uint32_t n)
{
    uint8_t *o = dst;
    uint32_t got = 0, cluster = f->cluster, cl_bytes = dk.spc * 512u, ci = 0;
    if (!dk.ok || off >= f->size)
        return 0;
    if (n > f->size - off)
        n = f->size - off;
    while (got < n) {                       /* walk to the cluster that holds off + got */
        uint32_t at = off + got, want = at / cl_bytes, in, k;
        const uint8_t *s;
        while (ci < want) {
            if (!cl_ok(cluster))
                return got;
            cluster = fat_next(cluster);
            ci++;
        }
        if (!cl_ok(cluster))
            return got;
        in = at % cl_bytes;
        s = disk_sector(dk.data_lba + (cluster - 2u) * dk.spc + in / 512u);
        if (!s)
            return got;
        k = 512u - in % 512u;
        if (k > n - got)
            k = n - got;
        memcpy(o + got, s + in % 512u, k);
        got += k;
    }
    return got;
}

static char lower(char c) { return c >= 'A' && c <= 'Z' ? (char)(c + 32) : c; }

/* the entries of a directory, long names assembled; fn(name, entry, arg) returns 1 to stop */
typedef int (*dir_fn)(const char *name, const uint8_t *e, void *arg);
static int dir_walk(uint32_t cluster, dir_fn fn, void *arg)
{
    char lfn[64];
    uint8_t lfn_sum = 0, have_lfn = 0;
    uint32_t k, j;
    const uint8_t *s;
    for (k = 0; (s = chain_sector(cluster, k)) != 0; k++)
        for (j = 0; j < 512u; j += 32u) {
            const uint8_t *e = s + j;
            char name[64];
            int n = 0, i;
            if (e[0] == 0)
                return 0;                   /* the end of the directory */
            if (e[0] == 0xE5) {
                have_lfn = 0;
                continue;
            }
            if ((e[11] & 0x3Fu) == 0x0Fu) { /* a long name part: 13 UTF-16 characters */
                static const uint8_t AT[13] = {1, 3, 5, 7, 9, 14, 16, 18, 20, 22, 24, 28, 30};
                uint32_t seq = e[0] & 0x1Fu, c;
                if (e[0] & 0x40u) {
                    memset(lfn, 0, sizeof lfn);
                    lfn_sum = e[13];
                    have_lfn = 1;
                }
                if (!seq || seq > 4u || e[13] != lfn_sum)
                    continue;
                for (c = 0; c < 13u; c++) {
                    uint32_t ch = rd16(e + AT[c]), at = (seq - 1u) * 13u + c;
                    if (at < sizeof lfn - 1u && ch != 0xFFFFu)
                        lfn[at] = ch == 0 ? 0 : ch < 128u ? (char)ch : '?';
                }
                continue;
            }
            if (e[11] & 0x08u) {            /* the volume label */
                have_lfn = 0;
                continue;
            }
            if (have_lfn) {                 /* the long name, if its checksum matches the short one */
                uint8_t sum = 0;
                for (i = 0; i < 11; i++)
                    sum = (uint8_t)(((sum & 1u) << 7) + (sum >> 1) + e[i]);
                if (sum == lfn_sum) {
                    for (i = 0; lfn[i] && i < 63; i++)
                        name[n++] = lfn[i];
                }
                have_lfn = 0;
            }
            if (!n) {                       /* the 8.3 name, lower case */
                for (i = 0; i < 8 && e[i] != ' '; i++)
                    name[n++] = lower((char)e[i]);
                if (e[8] != ' ') {
                    name[n++] = '.';
                    for (i = 8; i < 11 && e[i] != ' '; i++)
                        name[n++] = lower((char)e[i]);
                }
            }
            name[n] = 0;
            if (name[0] == '.')             /* ".", "..", and the computer's hidden files (._x, .Trashes...) */
                continue;
            if (fn(name, e, arg))
                return 1;
        }
    return 0;
}

static int name_eq(const char *a, const char *b, int bn)
{
    int i;
    for (i = 0; i < bn; i++)
        if (lower(a[i]) != lower(b[i]) || !a[i])
            return 0;
    return a[bn] == 0;
}

typedef struct {
    const char *want;
    int want_n;
    const uint8_t *found;
} find_t;
static int find_fn(const char *name, const uint8_t *e, void *arg)
{
    find_t *f = arg;
    if (!name_eq(name, f->want, f->want_n))
        return 0;
    f->found = e;
    return 1;
}

static void entry_file(const uint8_t *e, disk_file_t *f)
{
    f->cluster = rd16(e + 26);
    f->dir = (e[11] & 0x10u) != 0;
    f->size = f->dir ? 0 : rd32(e + 28);
}

int disk_open(const char *path, disk_file_t *f)
{
    disk_mount();
    if (!dk.ok)
        return -1;
    f->cluster = 0;
    f->dir = 1;
    f->size = 0;
    while (*path) {
        find_t ft;
        int n = 0;
        while (*path == '/')
            path++;
        if (!*path)
            break;
        while (path[n] && path[n] != '/')
            n++;
        if (!f->dir)
            return -1;
        ft.want = path;
        ft.want_n = n;
        ft.found = 0;
        dir_walk(f->cluster, find_fn, &ft);
        if (!ft.found)
            return -1;
        entry_file(ft.found, f);
        path += n;
    }
    return 0;
}

typedef struct {
    int want, at;
    char *name;
    int max;
    disk_file_t *f;
} nth_t;
static int nth_fn(const char *name, const uint8_t *e, void *arg)
{
    nth_t *t = arg;
    int i;
    if (t->at++ != t->want)
        return 0;
    for (i = 0; name[i] && i < t->max - 1; i++)
        t->name[i] = name[i];
    t->name[i] = 0;
    if (t->f)
        entry_file(e, t->f);
    return 1;
}

int disk_entry(const char *path, int i, char *name, int max, disk_file_t *f)
{
    disk_file_t d;
    nth_t t;
    if (disk_open(path, &d) != 0 || !d.dir)
        return 0;
    t.want = i;
    t.at = 0;
    t.name = name;
    t.max = max;
    t.f = f;
    return dir_walk(d.cluster, nth_fn, &t);
}

/* ------------------------------------------------------------ disk mode --- */
/* the computer's blocks: read in place, written through one 4 KB flash sector held in RAM (a write to another sector,
 * a sync, an eject or a pause writes it back: one erase for eight blocks) */
static uint8_t blk[4096] PLAT_POOL;
static int32_t wc_off = -1;                 /* the sector held (offset from DISK_LO), -1 none */
static uint8_t wc_dirty;

static void wc_flush(void)
{
    if (wc_off < 0 || !wc_dirty)
        return;
    if (memcmp(plat_data(DISK_LO + (uint32_t)wc_off), blk, sizeof blk)) {
        plat_data_erase(DISK_LO + (uint32_t)wc_off);
        plat_data_write(DISK_LO + (uint32_t)wc_off, blk, sizeof blk);
    }
    wc_dirty = 0;
}

static const uint8_t *dm_read(uint32_t lba)
{
    uint32_t off = lba * 512u;
    if (lba >= DISK_SECTORS)
        return 0;
    if ((int32_t)(off & ~4095u) == wc_off)
        return blk + (off & 4095u);
    return disk_sector(lba);
}

static int dm_write(uint32_t lba, const uint8_t *b)
{
    uint32_t off = lba * 512u, sec = off & ~4095u;
    if (lba >= DISK_SECTORS)
        return -1;
    if ((int32_t)sec != wc_off) {
        wc_flush();
        memcpy(blk, plat_data(DISK_LO + sec), sizeof blk);
        wc_off = (int32_t)sec;
    }
    memcpy(blk + (off & 4095u), b, 512u);
    wc_dirty = 1;
    return 0;
}

static void dm_flush(void)
{
    wc_flush();
    wc_off = -1;
}

static const plat_disk_t DISK_MODE = {DISK_SECTORS, dm_read, dm_write, dm_flush, "Ripple", "FM-1 disk"};

/* the shipped volume: DISK_IMAGE_RUNS runs of sectors (disk_image.h), everything else zero */
void disk_format_default(void)
{
    uint32_t off, s;
    for (off = DISK_LO; off < DISK_HI; off += 4096u) {
        uint32_t lba0 = (off - DISK_LO) / 512u, r;
        int any = 0;
        memset(blk, 0, sizeof blk);
        for (r = 0; r < DISK_IMAGE_RUNS; r++) {
            uint32_t a = DISK_IMAGE_RUN[r][0], n = DISK_IMAGE_RUN[r][1], src = DISK_IMAGE_RUN[r][2];
            for (s = 0; s < 8u; s++)
                if (lba0 + s >= a && lba0 + s < a + n) {
                    memcpy(blk + s * 512u, DISK_IMAGE + (src + lba0 + s - a) * 512u, 512u);
                    any = 1;
                }
        }
        plat_data_erase(off);
        (void)any;
        plat_data_write(off, blk, sizeof blk);
    }
    wc_off = -1;
    wc_dirty = 0;
    disk_mount();
}
