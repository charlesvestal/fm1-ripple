// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// plaits-snare: Mutable Instruments Plaits (Emilie Gillet, MIT): analog snare drum. The current: currents/plaits/plaits_current.h.
// ripple-sources: plaits/plaits/**/*.cc plaits/stmlib/**/*.cc
// ripple-cflags: -Iplaits/shim -Iplaits -DTEST
#define PLAITS_ENGINES 0x400000u
#define PC_NAME "plaits-snare"
#define PC_ENGINES 22
#define PC_VOICES 6
#define PC_STRUCK ((1u << 22))
#include "plaits/plaits_current.h"
