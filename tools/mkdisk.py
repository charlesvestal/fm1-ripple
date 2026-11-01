#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# Copyright (C) 2026 Charles Vestal
"""Ripple's disk: a FAT12 volume of 552 sectors (the FM-1's data area, app/disk.h) holding a folder's files.

  mkdisk.py DIR --img OUT.img          the whole volume, for the host simulator or a test
  mkdisk.py DIR --header OUT.h         the firmware's shipped volume (disk_image.h): its used sectors only

DIR's files and folders go in as they are (long names: VFAT), each file in consecutive clusters."""
import argparse
import struct
import sys
from pathlib import Path

SECTORS = 552                      # (0xDC000 - 0x97000) / 512: app/disk.h
SPC = 1                            # sectors a cluster
RSV, NFAT, NROOT = 1, 2, 64
CLUSTERS_MAX = SECTORS             # enough for the FAT's size below
SPF = ((CLUSTERS_MAX + 2) * 3 // 2 + 511) // 512   # sectors a FAT (2)
ROOT_LBA = RSV + NFAT * SPF
ROOT_N = NROOT * 32 // 512
DATA_LBA = ROOT_LBA + ROOT_N
NCLUSTERS = (SECTORS - DATA_LBA) // SPC
LABEL = b"RIPPLE     "


def short_name(name, taken):
    """an 8.3 alias: the name itself if it fits, else BASE~N.EXT"""
    stem, dot, ext = name.rpartition(".") if "." in name[1:] else (name, "", "")
    if not dot:
        stem, ext = name, ""
    ok = lambda s: "".join(c for c in s.upper() if c.isalnum() or c in "_-")
    s, e = ok(stem), ok(ext)[:3]
    fits = s == stem.upper() and len(stem) <= 8 and ok(ext) == ext.upper() and len(ext) <= 3 and stem == stem.lower()
    if fits and (s.ljust(8) + e.ljust(3)) not in taken:
        return (s.ljust(8) + e.ljust(3)).encode(), False
    for n in range(1, 100):
        t = f"~{n}"
        cand = (s[:8 - len(t)] + t).ljust(8) + e.ljust(3)
        if cand not in taken:
            return cand.encode(), True
    raise SystemExit(f"mkdisk: too many names like {name}")


def lfn_entries(name, short):
    s = 0
    for b in short:
        s = (((s & 1) << 7) + (s >> 1) + b) & 0xFF
    u = name.encode("utf-16-le") + b"\0\0"
    chars = [u[i:i + 2] for i in range(0, len(u), 2)]
    while len(chars) % 13:
        chars.append(b"\xff\xff")
    parts = [chars[i:i + 13] for i in range(0, len(chars), 13)]
    out = []
    for i, p in reversed(list(enumerate(parts))):
        seq = (i + 1) | (0x40 if i == len(parts) - 1 else 0)
        c = b"".join(p)
        out.append(bytes([seq]) + c[0:10] + b"\x0f\x00" + bytes([s]) + c[10:22] + b"\0\0" + c[22:26])
    return out


def dirent(short, attr, cluster, size):
    return short + bytes([attr, 0, 0]) + b"\0" * 6 + b"\0\0" + b"\0" * 4 + struct.pack("<HI", cluster, size)


class Vol:
    def __init__(self):
        self.img = bytearray(SECTORS * 512)
        self.fat = [0] * (NCLUSTERS + 2)
        self.fat[0], self.fat[1] = 0xFF8, 0xFFF
        self.next = 2

    def alloc(self, nbytes):
        n = max(1, (nbytes + SPC * 512 - 1) // (SPC * 512))
        if self.next + n > NCLUSTERS + 2:
            raise SystemExit("mkdisk: the disk is full (276 KB)")
        first = self.next
        for c in range(first, first + n):
            self.fat[c] = c + 1 if c < first + n - 1 else 0xFFF
        self.next += n
        return first, n

    def put(self, cluster, data):
        off = (DATA_LBA + (cluster - 2) * SPC) * 512
        self.img[off:off + len(data)] = data

    def entries(self, folder, self_cl=None, parent_cl=0):
        ents, taken = [], set()
        if self_cl is not None:
            ents.append(dirent(b".          ", 0x10, self_cl, 0))
            ents.append(dirent(b"..         ", 0x10, parent_cl, 0))
        for p in sorted(folder.iterdir()):
            if p.name.startswith("."):
                continue
            short, longn = short_name(p.name, taken)
            taken.add(short.decode())
            if p.is_dir():
                sub = self.write_dir(p, parent_cl=self_cl or 0)
                body = dirent(short, 0x10, sub, 0)
            else:
                data = p.read_bytes()
                cl, _ = self.alloc(len(data)) if data else (0, 0)
                if data:
                    self.put(cl, data)
                body = dirent(short, 0x20, cl, len(data))
            if longn or p.name != short_disp(short):   # a long name when the 8.3 one does not say it exactly
                ents += lfn_entries(p.name, short)
            ents.append(body)
        return ents

    def write_dir(self, folder, parent_cl):
        # size the directory first: one cluster per 16 entries
        probe = sum(1 + (len(p.name) + 12) // 13 for p in folder.iterdir() if not p.name.startswith(".")) + 2
        cl, n = self.alloc(probe * 32)
        ents = self.entries(folder, self_cl=cl, parent_cl=parent_cl)
        data = b"".join(ents)
        if len(data) > n * SPC * 512:
            raise SystemExit(f"mkdisk: {folder}: too many entries")
        self.put(cl, data)
        return cl

    def build(self, root):
        ents = [LABEL + bytes([0x08]) + b"\0" * 20]
        ents += self.entries(root)
        if len(ents) > NROOT:
            raise SystemExit("mkdisk: too many entries in the root")
        r = b"".join(ents)
        self.img[ROOT_LBA * 512:ROOT_LBA * 512 + len(r)] = r
        fat = bytearray(SPF * 512)
        for c in range(0, len(self.fat), 2):
            a = self.fat[c]
            b = self.fat[c + 1] if c + 1 < len(self.fat) else 0
            o = c * 3 // 2
            fat[o:o + 3] = bytes([a & 0xFF, (a >> 8) | ((b & 0xF) << 4), b >> 4])
        for i in range(NFAT):
            o = (RSV + i * SPF) * 512
            self.img[o:o + len(fat)] = fat
        bs = bytearray(512)
        bs[0:3] = b"\xEB\x3C\x90"
        bs[3:11] = b"RIPPLE  "
        struct.pack_into("<HBHBHHBHHHII", bs, 11, 512, SPC, RSV, NFAT, NROOT, SECTORS, 0xF8, SPF, 32, 2, 0, 0)
        struct.pack_into("<BBBI11s8s", bs, 36, 0x80, 0, 0x29, 0x52495050, LABEL, b"FAT12   ")
        bs[510:512] = b"\x55\xAA"
        self.img[0:512] = bs
        return bytes(self.img)


def short_disp(short):
    s = short.decode()
    b, e = s[:8].rstrip(), s[8:].rstrip()
    return (b + ("." + e if e else "")).lower()


def header(img, out):
    secs = [img[i * 512:(i + 1) * 512] for i in range(SECTORS)]
    runs, data = [], []
    i = 0
    while i < SECTORS:
        if any(secs[i]):
            j = i
            while j < SECTORS and any(secs[j]):
                j += 1
            runs.append((i, j - i, len(data)))
            data += secs[i:j]
            i = j
        else:
            i += 1
    blob = b"".join(data)
    lines = ["/* generated by tools/mkdisk.py: the shipped disk (app/disk.c disk_format_default) */", "#pragma once",
             f"#define DISK_IMAGE_RUNS {len(runs)}u",
             "static const uint32_t DISK_IMAGE_RUN[][3] = {" + ", ".join(f"{{{a}u, {n}u, {s}u}}" for a, n, s in runs) + "};",
             f"static const uint8_t DISK_IMAGE[{len(blob)}] = {{"]
    for k in range(0, len(blob), 24):
        lines.append("    " + ", ".join(f"0x{b:02X}" for b in blob[k:k + 24]) + ",")
    lines.append("};")
    Path(out).write_text("\n".join(lines) + "\n")
    print(f"mkdisk: {len(blob) // 512} sectors used of {SECTORS} ({len(blob) // 1024} KB)")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("dir", type=Path)
    ap.add_argument("--img")
    ap.add_argument("--header")
    a = ap.parse_args()
    img = Vol().build(a.dir)
    if a.img:
        Path(a.img).write_bytes(img)
    if a.header:
        header(img, a.header)
    return 0


if __name__ == "__main__":
    sys.exit(main())
