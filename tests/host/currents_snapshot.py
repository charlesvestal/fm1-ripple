#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
# Copyright (C) 2026 Charles Vestal
"""Every Faust and Pd current built for the FM-1, and what each one is, as JSON: its name, inputs, voices,
parameters, state and image size. tests/host/currents_baseline.json is this from before the hvcc generator; a
change to how currents are made must give the same, but for image sizes within a few percent.
  currents_snapshot.py --out FILE.json"""
import argparse
import json
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SOURCES = sorted(ROOT.glob("currents/*.dsp")) + sorted(ROOT.glob("currents/pd/*.pd")) + \
    sorted(ROOT.glob("currents/pd/community/*.pd"))


def describe(cur):
    """the .cur file read as app/flow.c reads it: header, then the descriptor found by its magic"""
    b = cur.read_bytes()
    magic, _ver, _info, image, bss, _entry, _nrel, _sum, state = struct.unpack_from("<IHHIIIIII", b, 0)
    assert magic == 0x52554352, cur
    img = b[32:32 + image]
    for k in range(0, len(img) - 32, 4):
        m, abi, name_p, st, ins, voices, nparams, params_p = struct.unpack_from("<IIIIBBHI", img, k)
        if m == 0x52435231 and abi in (1, 2):
            break
    else:
        raise SystemExit(f"{cur}: no descriptor")

    def cstr(p):
        return img[p:img.index(b"\0", p)].decode()
    params = []
    for i in range(nparams):
        n_p, lo, hi, de = struct.unpack_from("<Ifff", img, params_p + 16 * i)
        params.append([cstr(n_p), round(lo, 6), round(hi, 6), round(de, 6)])
    assert st == state, f"{cur}: header state {state} != descriptor state_size {st}"
    return {"name": cstr(name_p), "ins": ins, "voices": voices, "params": params, "state": st,
            "image": image + bss}


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--out", type=Path, required=True)
    a = ap.parse_args()
    out = Path(tempfile.mkdtemp(prefix="snap-"))
    r = subprocess.run([sys.executable, str(ROOT / "sdk/tools/currents.py"), *map(str, SOURCES), "--out", str(out)],
                       cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        sys.stderr.write(r.stdout[-3000:] + r.stderr[-3000:])
        return 1
    snap = {s.stem: describe(out / f"{s.stem}.cur") for s in SOURCES}
    a.out.write_text(json.dumps(snap, indent=1, sort_keys=True) + "\n")
    print(f"{len(snap)} currents")
    return 0


if __name__ == "__main__":
    sys.exit(main())
