#!/bin/sh
# SPDX-License-Identifier: MPL-2.0
# Copyright (C) 2026 Charles Vestal
# Ripple's tests: the simulator (./build.sh --host first) with the shipped disk (tests/scenarios/droplets.txt: the
# list, each droplet started, played and left, disk mode) and with the self-test disk (tests/disk: Lua on Ripple's
# port, tests/selftest.sh). Screenshots and audio in app/build/scenarios/. fm1-base's own: base/tests/run_tests.sh.
#   tests/run_tests.sh
set -u
cd "$(dirname "$0")/.."
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
run droplets env RIPPLE_CURRENTS=app/build/currents-host app/build/host/ripple_host tests/scenarios/droplets.txt \
    app/build/scenarios/droplets
mkdir -p app/build/scenarios/examples
run examples env RIPPLE_CURRENTS=app/build/currents-host app/build/host/ripple_host tests/scenarios/examples.txt \
    app/build/scenarios/examples
run selftest sh tests/selftest.sh
[ $FAIL -eq 0 ] && echo "all tests passed" || echo "TESTS FAILED"
exit $FAIL
