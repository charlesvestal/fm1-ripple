// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// plaits-va: Mutable Instruments Plaits (Emilie Gillet, MIT): virtual analog: two variable-shape oscillators. The current: currents/plaits/plaits_current.h.
// ripple-sources: plaits/plaits/**/*.cc plaits/stmlib/**/*.cc
// ripple-cflags: -Iplaits/shim -Iplaits -DTEST
#define PLAITS_ENGINES 0x100u
#define PC_NAME "plaits-va"
#define PC_ENGINES 8
#define PC_VOICES 6
#define PC_STRUCK (0)
#include "plaits/plaits_current.h"
