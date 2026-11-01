/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* The disk: a FAT12 volume in the FM-1's data flash, and the built-in volume beside it (disk.c), what the computer sees in disk mode (msc.c) and where
 * droplets (.lua files in /droplets) and currents (.cur files in /currents) live. Read in place, a file through its cluster chain. */
#pragma once
#include <stdint.h>

#define DISK_LO 0x97000u                    /* the data area up to the store's objects (app.h APP_STORE_MAP) */
#define DISK_HI 0xDC000u
#define DISK_SECTORS ((DISK_HI - DISK_LO) / 512u)   /* 552 sectors of 512 bytes: 276 KB */

enum { DISK_VOL, BUILTIN_VOL };             /* the disk (the user's), the built-in volume (the firmware's) */

typedef struct {
    uint8_t vol;                            /* the volume it is on */
    uint16_t cluster;                       /* the first cluster (0: an empty file, or the root directory) */
    uint8_t dir;                            /* a directory */
    uint32_t size;                          /* bytes (0 for a directory) */
} disk_file_t;

int disk_ok(void);                          /* the volume reads as FAT12 */
int disk_open(const char *path, disk_file_t *f);   /* "/droplets/poly.lua", any case, on the disk or else built
                                                    * in: 0 = found */
uint32_t disk_read(const disk_file_t *f, uint32_t off, void *dst, uint32_t n);   /* bytes read */
/* entry i of directory path on volume vol (no volume label, no "." / ".."): its long name (or 8.3, lower case) into
 * name (max bytes with the 0); 0 = no entry i */
int disk_entry(int vol, const char *path, int i, char *name, int max, disk_file_t *f);
void disk_format_default(void);             /* the disk emptied: its folders only (disk_image.h) */
const uint8_t *disk_sector(uint32_t lba);   /* sector lba read in place (0: past the end) */
