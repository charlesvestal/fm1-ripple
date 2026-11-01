#!/bin/sh
# SPDX-License-Identifier: MPL-2.0
# Copyright (C) 2026 Charles Vestal
# Build Ripple with fm1-base (base/, a git submodule): the currents (sdk/tools/currents.py), the built-in volume
# (builtin/ and the currents: app/build/builtin), then the firmware (the empty disk: disk/).
#   ./build.sh [--release X.Y] [--host | --web]
#   JIELI_TOOLCHAIN  JieLi Linux toolchain (default: ~/.jieli/toolchain)
#   AC79_SDK         JieLi AC79 SDK checkout (default: ~/fw-AC79_AIoT_SDK)
#   PYTHON           a Python with Pillow (and libraqm, for the fonts)
set -e
cd "$(dirname "$0")"
export JIELI_TOOLCHAIN="${JIELI_TOOLCHAIN:-$HOME/.jieli/toolchain}"
export AC79_SDK="${AC79_SDK:-$HOME/fw-AC79_AIoT_SDK}"
PY="${PYTHON:-python3}"
[ -f base/tools/build.py ] || { echo "build.sh: no fm1-base in base/ (git submodule update --init --recursive)"; exit 1; }
"$PY" -c 'import PIL' 2>/dev/null || { echo "build.sh: $PY has no Pillow (pip3 install Pillow)"; exit 1; }
rm -rf app/build/builtin
mkdir -p app/build/builtin
cp -R builtin/. app/build/builtin/
"$PY" sdk/tools/currents.py currents/*.dsp currents/*.c --out app/build/builtin/currents
case " $* " in
    *" --host "*|*" --web "*) "$PY" sdk/tools/currents.py currents/*.dsp currents/*.c --host app/build/currents-host ;;
esac
exec "$PY" base/tools/build.py app "$@"
