#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# Copyright (C) 2026 Charles Vestal
"""A Pd patch compiled twice, each time in a process of its own, gives the same files: hvcc's C for the patch, the
wrapper, ripple_heavy.h and Heavy's runtime (sdk/build/heavy/). Prints "same", or the files that differ (exit 1).
Run it with a Python that has hvcc (pip install -r sdk/heavy/requirements.txt).
  determinism.py [PATCH.pd]          (default currents/pd/pdpoly.pd, with lib/ and LICENSE beside it)"""
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.dont_write_bytecode = True                      # (no __pycache__ in sdk/tools)
sys.path.insert(0, str(ROOT / "sdk" / "tools"))
import currents                                     # noqa: E402  (where the generated files go)


def files(d):
    return {str(f.relative_to(d)): f.read_bytes() for f in sorted(d.rglob("*")) if f.is_file()}


def run(pd, tmp, n):
    """the patch, with what is beside it, built in a folder of its own; the files it made, read"""
    src = tmp / f"src{n}"
    src.mkdir()
    shutil.copy(pd, src)
    for extra in ("lib", "LICENSE"):
        p = pd.parent / extra
        if p.is_dir():
            shutil.copytree(p, src / extra)
        elif p.exists():
            shutil.copy(p, src)
    patch = src / pd.name
    if currents.HV_RUNTIME.exists():                # (the runtime made again too)
        shutil.rmtree(currents.HV_RUNTIME)
    r = subprocess.run([sys.executable, str(ROOT / "sdk" / "tools" / "currents.py"), str(patch), "--host", str(tmp / f"host{n}")],
                       capture_output=True, text=True)
    if r.returncode:
        sys.stderr.write(r.stdout + r.stderr)
        raise SystemExit(f"determinism: building {pd.name} failed")
    return {**{f"{currents.pd_name(patch)}/{k}": v for k, v in files(currents.pd_dir(patch)).items()},
            **{f"runtime/{k}": v for k, v in files(currents.HV_RUNTIME).items()}}


def main():
    pd = Path(sys.argv[1]).resolve() if len(sys.argv) > 1 else ROOT / "currents" / "pd" / "pdpoly.pd"
    tmp = Path(tempfile.mkdtemp(prefix="determinism-"))
    try:
        a, b = run(pd, tmp, 1), run(pd, tmp, 2)
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    differ = sorted(k for k in a.keys() | b.keys() if a.get(k) != b.get(k))
    if differ:
        print("differ: " + " ".join(differ))
        return 1
    print("same")
    return 0


if __name__ == "__main__":
    sys.exit(main())
