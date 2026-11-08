#!/bin/sh
# SPDX-License-Identifier: MPL-2.0
# Copyright (C) 2026 Charles Vestal
# Ripple's tests: the simulator (./build.sh --host first) with the shipped disk (tests/scenarios/droplets.txt: the
# list, each droplet started, played and left, disk mode) and with the self-test disk (tests/disk: Lua on Ripple's
# port, tests/selftest.sh). Screenshots and audio in app/build/scenarios/. fm1-base's own: base/tests/run_tests.sh.
#   PYTHON=... tests/run_tests.sh      a Python with hvcc and Pillow, as build.sh takes (default python3)
set -u
cd "$(dirname "$0")/.."
PY="${PYTHON:-python3}"
OUT=app/build/tests
FAIL=0
mkdir -p "$OUT" app/build/scenarios/droplets
run() {
    name="$1"; shift
    if "$@" > "$OUT/$name.log" 2>&1 && ! grep -q "^FAIL" "$OUT/$name.log"; then
        echo "  ok   $name"
    else
        echo "  FAIL $name (see $OUT/$name.log)"
        tail -15 "$OUT/$name.log" | sed 's/^/       /'
        FAIL=1
    fi
}
run host-build sh build.sh --host
run pd-determinism "$PY" tests/host/determinism.py     # (a patch compiled twice: the same files)
run pd-currents "$PY" sdk/tools/currents.py currents/pd --host app/build/currents-host
run currents-snapshot sh -c "$PY tests/host/currents_snapshot.py --out $OUT/snap.json &&
    $PY tests/host/currents_compare.py tests/host/currents_baseline.json $OUT/snap.json"
run droplets env RIPPLE_CURRENTS=app/build/currents-host app/build/host/ripple_host tests/scenarios/droplets.txt \
    app/build/scenarios/droplets
mkdir -p app/build/scenarios/examples
run examples env RIPPLE_CURRENTS=app/build/currents-host app/build/host/ripple_host tests/scenarios/examples.txt \
    app/build/scenarios/examples
run selftest sh tests/selftest.sh
run pd-examples sh tests/pd_examples.sh
if command -v emcc >/dev/null 2>&1 && command -v node >/dev/null 2>&1; then
    run emu sh -c "sh build.sh --web && node tests/host/emu_test.mjs app/build/emu/app.wasm"
    run emu-upload sh -c "$PY sdk/tools/currents.py tests/host/webbeep.c --web-module app/build/tests >/dev/null &&
        node tests/host/emu_upload.mjs app/build/emu/app.wasm app/build/tests/webbeep.wasm"
else
    echo "  skip emu (no emcc or node)"
fi
[ $FAIL -eq 0 ] && echo "all tests passed" || echo "TESTS FAILED"
exit $FAIL
