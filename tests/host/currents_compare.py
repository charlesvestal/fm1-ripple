#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# Copyright (C) 2026 Charles Vestal
"""Two currents snapshots (currents_snapshot.py) the same: every current's name, ins, voices, params and state;
its image within 5%. A current added or changed on purpose: make the baseline again.
  currents_compare.py BASELINE.json NEW.json"""
import json, sys

a, b = (json.load(open(f)) for f in sys.argv[1:3])
bad = []
for k in sorted(set(a) | set(b)):
    if k not in a or k not in b:
        bad.append(f"{k}: only in {'the new' if k in b else 'the baseline'}")
        continue
    for f in ("name", "ins", "voices", "params", "state"):
        if a[k][f] != b[k][f]:
            bad.append(f"{k}: {f} {a[k][f]} -> {b[k][f]}")
    if abs(a[k]["image"] - b[k]["image"]) > 0.05 * a[k]["image"]:
        bad.append(f"{k}: image {a[k]['image']} -> {b[k]['image']}")
print("\n".join(bad) or f"{len(b)} currents as the baseline")
sys.exit(1 if bad else 0)
