#!/bin/sh
# the selftest disk (tests/disk and the built currents) into the simulator: tests/scenarios/selftest.txt
set -e
cd "$(dirname "$0")/.."
out=app/build/scenarios/selftest
mkdir -p $out
rm -rf $out/disk && cp -R tests/disk $out/disk
mkdir -p $out/disk/currents && cp app/build/extra/*.cur $out/disk/currents/   # (the currents not built in)
python3 tools/mkdisk.py $out/disk --img $out/selftest.img >/dev/null
RIPPLE_CURRENTS=app/build/currents-host app/build/host/ripple_host tests/scenarios/selftest.txt $out
