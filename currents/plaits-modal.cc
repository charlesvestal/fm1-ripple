// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// plaits-modal: Mutable Instruments Plaits (Emilie Gillet, MIT): a modal resonator: bells, bars, plates. The current: currents/plaits/plaits_current.h.
// ripple-sources: plaits/plaits/**/*.cc plaits/stmlib/**/*.cc
// ripple-cflags: -Iplaits/shim -Iplaits -DTEST
#define PLAITS_ENGINES 0x100000u
#define PC_NAME "plaits-modal"
#define PC_ENGINES 20
#define PC_VOICES 6
#define PC_STRUCK ((1u << 20))
#include "plaits/plaits_current.h"
