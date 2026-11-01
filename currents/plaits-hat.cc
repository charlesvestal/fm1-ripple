// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// plaits-hat: Mutable Instruments Plaits (Emilie Gillet, MIT): analog hi-hat. The current: currents/plaits/plaits_current.h.
// ripple-sources: plaits/plaits/**/*.cc plaits/stmlib/**/*.cc
// ripple-cflags: -Iplaits/shim -Iplaits -DTEST
#define PLAITS_ENGINES 0x800000u
#define PC_NAME "plaits-hat"
#define PC_ENGINES 23
#define PC_VOICES 6
#define PC_STRUCK ((1u << 23))
#include "plaits/plaits_current.h"
