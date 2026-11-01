// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// plaits-kick: Mutable Instruments Plaits (Emilie Gillet, MIT): analog bass drum. The current: currents/plaits/plaits_current.h.
// ripple-sources: plaits/plaits/**/*.cc plaits/stmlib/**/*.cc
// ripple-cflags: -Iplaits/shim -Iplaits -DTEST
#define PLAITS_ENGINES 0x200000u
#define PC_NAME "plaits-kick"
#define PC_ENGINES 21
#define PC_VOICES 6
#define PC_STRUCK ((1u << 21))
#include "plaits/plaits_current.h"
