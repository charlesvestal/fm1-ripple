#!/bin/sh
# SPDX-License-Identifier: MPL-2.0
# Copyright (C) 2026 Charles Vestal
# The manual's screenshots, from the simulator (./build.sh --host first): tests/scenarios/screens.txt into app/docs/img
set -e
cd "$(dirname "$0")/.."
out=app/build/scenarios/screens
mkdir -p $out app/docs/img
RIPPLE_CURRENTS=app/build/currents-host app/build/host/ripple_host tests/scenarios/screens.txt $out
for f in list awake euclid chords bells loop life rain disk; do cp $out/$f.png app/docs/img/; done
# the error screen, from a droplet with a mistake in it
cat > $out/oops.lua <<'LUA'
function init()
  print("starting")
  local t = nil
  print(t.x)
end
LUA
mkdir -p $out/errdisk/droplets && cp $out/oops.lua $out/errdisk/droplets/
python3 tools/mkdisk.py $out/errdisk --img $out/err.img >/dev/null
printf 'wait 600\ndata %s 0x97000\nreboot\nwait 600\nstart oops\nwait 300\nshot error.png\n' "$out/err.img" > $out/err.txt
RIPPLE_CURRENTS=app/build/currents-host app/build/host/ripple_host $out/err.txt $out >/dev/null
cp $out/error.png app/docs/img/
echo "screens in app/docs/img"
