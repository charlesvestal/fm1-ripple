// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// plaits-pd: Mutable Instruments Plaits (Emilie Gillet, MIT): phase distortion. The current: currents/plaits/plaits_current.h.
// ripple-sources: plaits/plaits/**/*.cc plaits/stmlib/**/*.cc
// ripple-cflags: -Iplaits/shim -Iplaits -DTEST
#define PLAITS_ENGINES 0x2u
#define PC_NAME "plaits-pd"
#define PC_ENGINES 1
#define PC_VOICES 6
#define PC_STRUCK (0)
#include "plaits/plaits_current.h"
