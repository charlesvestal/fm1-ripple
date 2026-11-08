# Heavy's runtime for the FM-1

Ripple builds hvcc 0.17.3's runtime (its `generators/ir2c/static` files, ISC, Enzien Audio and Wasted Audio) with
some of its files replaced by the copies in `static/`. A current runs on the FM-1's single-precision FPU, with no C
library and no allocator, and the changes below are what that requires. `sdk/tools/currents.py` copies hvcc's runtime
files into `sdk/build/heavy/runtime/`, except the few it cannot build (`HV_LEAVE_OUT` in `currents.py`). It lays
`static/` over them and puts Ripple's own files (`HvUtils.h`, `heavy_shim.c`, `new`) beside them. Nothing there is
committed. The build makes it again whenever hvcc's version or a file in `static/` changes. `requirements.txt` pins
the hvcc version.

The patch's own files (`Heavy_NAME.*`) are built as hvcc writes them, with two flags (`HV_CFLAGS` in `currents.py`,
on the wrapper's `ripple-cflags` line):

- `-cl-single-precision-constant` (GCC's `-fsingle-precision-constant`, when the computer's compiler is GCC) is there
  because an `[expr]` puts the patch's numbers into the C as they are, so `0.5` is a double.
- `-Wno-delete-non-virtual-dtor` is there for `hv_NAME_free`, which destroys the patch through the destructor that
  `HeavyContext.hpp` makes non-virtual. A current never calls it.

`static/` holds only the files that differ from hvcc's. To move to a new hvcc version, diff each hvcc file named
below between the old version and the new one, carry the changes listed here over to the new file, and keep the
copy in `static/`. A file that no longer needs a change leaves `static/`. Then build the Pd currents again and compare
them with `tests/host/currents_snapshot.py`.

| File | Change | Why |
|---|---|---|
| `HvUtils.h` | Rewritten for Ripple from hvcc's (Enzien Audio's notice kept): no platform detection, no SIMD and no atomics; the math from `fastmath.h` (through `faust_shim.h`); `hv_malloc` and the string and memory routines from `heavy_shim.c`; spinlocks that set a flag and never wait; `RC_HV_VA_FLOAT`; last, `#define double float` | A current has no C library, and its memory is an arena in its own state. Set and note never run during the render, so nothing needs a lock. The patch's own files (`Heavy_NAME.*`), kept as hvcc writes them, take the sample rate as a `double`, and the define makes it a `float`. It can come last because every build of a current, including the computer's, is freestanding (`-nostdinc++`), so no C++ library header follows it. |
| `HvUtils.c` | `hv_string_to_hash` always takes the byte-by-byte path (hvcc's Emscripten path): `#if HV_EMSCRIPTEN` is `#if 1` | The other path loads a word at a time from any address, and the FM-1 faults on an unaligned word load. |
| `HvLightPipe.c` | `hv_sfence()` is always a compiler barrier (`__asm__ volatile("" : : : "memory")`), hvcc's last case; the SSE, ARM and Windows cases are gone, with their `xmmintrin.h` and `arm_acle.h` | Set and render never run at once, so the pipe needs no hardware fence. On an x86 computer the SSE header brought in `stdlib.h`, which a current cannot include. |
| `HeavyContextInterface.hpp` | The destructor is not virtual; `getSampleRate`, `sendMessageToReceiver` and `sendMessageToReceiverV` take and return `float`, not `double` | A virtual destructor makes the compiler emit a deleting destructor, which calls `operator delete`. A `double` needs soft-double routines on the FM-1. |
| `HeavyContext.hpp` | The destructor is not virtual; the sample rate, the delays and `getSampleRate` are `float`, not `double`; `1000.0` is `1000.0f` | The same as `HeavyContextInterface.hpp`. |
| `HeavyContext.cpp` | The constructor's sample rate and the delays are `float`; the double literals (`0.0`, `1000.0`) are float; `va_arg(ap, double)` is `RC_HV_VA_FLOAT(ap)` | No soft-double routines in a current. `RC_HV_VA_FLOAT` (`HvUtils.h`) reads the promoted argument's 64 bits and converts them to a float without a double operation. |
| `HvHeavy.cpp` | The C API's sample rate, time, delays and data are `float`; the double literals are float; `va_arg(ap, double)` is `RC_HV_VA_FLOAT(ap)`; `hv_delete` no longer calls `delete c` (it is `(void) c;`) | No soft-double routines and no `operator delete` in a current. The current's wrapper builds the patch in its own state, so there is nothing to free. |
| `HvHeavy.h` | The declarations of `HvHeavy.cpp`'s functions with `float` in place of `double` | To match `HvHeavy.cpp`. |
| `HvControlPack.c` | `va_arg(ap, double)` is `RC_HV_VA_FLOAT(ap)` | No soft-double routines in a current. |
| `HvMath.h` | `#include <math.h>` is removed (the line left blank) | A current has no C library. `HvUtils.h` gives the math functions Heavy uses. |
| `HvSignalBiquad.c` | The coefficients are computed in `float`, not `double` (the five locals and the `coeffs` table, and the word "double" in a comment reads "float") | No soft-double routines in a current. |
| `HvSignalEnvelope.c` | `M_PI` and `2.0` are float literals (and the word "double" in a comment reads "float") | No soft-double routines in a current. |
| `HvSignalPhasor.c` | The sample rate is `float`; `HV_PHASOR_2_32` and `1.0` are float literals | No soft-double routines in a current. |
| `HvSignalPhasor.h` | `sPhasor_init` and `sPhasor_k_init` take the sample rate as `float` | To match `HvSignalPhasor.c`. |
| `heavy_shim.c` | Ripple's own: the arena allocator (`rc_hv_malloc`, `rc_hv_realloc`), the string and memory routines `HvUtils.h` names, `rc_hv_va_double`, and `__cxa_pure_virtual` | A current has no C library. |
| `new` | Ripple's own: placement `new`, defined once (`RIPPLE_NEW`, which the wrapper checks) | A current is built with `-nostdinc++`, on the FM-1 and on the computer (the simulator, the emulator and the heap measure in `currents.py`), so the C++ library's `<new>` is never there and this one is found on the runtime's `-I`. `Heavy_NAME.cpp` includes `<new>` for the placement `new` in its `hv_NAME_new`. |
