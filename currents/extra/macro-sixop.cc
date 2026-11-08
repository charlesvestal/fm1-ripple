// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// macro-sixop: Mutable Instruments Plaits (Emilie Gillet, MIT): six-operator FM with the module's three DX7 banks (model picks the bank, harmonics the patch). The current: currents/plaits/plaits_current.h.
// ripple-sources: ../plaits/plaits/**/*.cc ../plaits/stmlib/**/*.cc
// ripple-cflags: -I../plaits/shim -I../plaits -DTEST
#define PLAITS_ENGINES 0x1cu
#define PC_NAME "macro-sixop"
#define PC_ENGINES 2,3,4
#define PC_VOICES 3
#define PC_STRUCK (0)
#include "../plaits/plaits_current.h"
