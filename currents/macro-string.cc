// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// macro-string: Mutable Instruments Plaits (Emilie Gillet, MIT): a plucked string (Karplus-Strong). The current: currents/plaits/plaits_current.h.
// ripple-sources: plaits/plaits/**/*.cc plaits/stmlib/**/*.cc
// ripple-cflags: -Iplaits/shim -Iplaits -DTEST
#define PLAITS_ENGINES 0x80000u
#define PC_NAME "macro-string"
#define PC_ENGINES 19
#define PC_VOICES 2
#define PC_STRUCK ((1u << 19))
#include "plaits/plaits_current.h"
