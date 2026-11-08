#!/bin/sh
# the droplets on Pd patches (examples/pd) and their currents (app/build/extra, from currents/pd/community) on a disk
# in the simulator: tests/scenarios/pd_examples.txt
set -e
cd "$(dirname "$0")/.."
out=app/build/scenarios/pd_examples
rm -rf $out && mkdir -p $out/disk/droplets $out/disk/currents
cp examples/pd/droplets/*.lua $out/disk/droplets/
for c in dl-monosynth logue-chiptune logue-wavefolder nts-bitcrush nts-chorus nts-freqshift nts-reflection nts-vca nts-vocoder; do
    cp app/build/extra/$c.cur $out/disk/currents/
done
python3 tools/mkdisk.py $out/disk --img $out/pd.img >/dev/null
RIPPLE_CURRENTS=app/build/currents-host app/build/host/ripple_host tests/scenarios/pd_examples.txt $out
