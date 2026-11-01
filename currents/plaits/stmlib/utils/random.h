// Copyright 2012 Emilie Gillet.
//
// Author: Emilie Gillet (emilie.o.gillet@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 
// See http://creativecommons.org/licenses/MIT/ for more information.
//
// -----------------------------------------------------------------------------
//
// Fast 16-bit pseudo random number generator.

#ifndef STMLIB_UTILS_RANDOM_H_
#define STMLIB_UTILS_RANDOM_H_

#include "stmlib/stmlib.h"

namespace stmlib {

// LOOM-8: the state is per core (the FM-1 renders voices on both cores at once), and plaits_voice.cc
// swaps each voice's own state in around its render, so a voice draws the same numbers whichever core
// renders it (LOOM's one-core and two-core renders stay bit-identical). The core is told by the stack
// the render runs on: core 1's is _c1_ustack.._c1_sstack_top (hal/fm1_cpu1.S); the host has one.
#if defined(XY_HOST) || defined(TEST_HOST)
inline int RandomCore() { return 0; }
#elif defined(RIPPLE_CURRENT)
// Ripple: a current sees none of the firmware's symbols. Each part of the current notes where its core's stack is
// as it starts (plaits_core_sp, plaits_current.h), and the core is the one whose note is nearer: the two stacks are
// kilobytes apart, a render's depth is a few hundred bytes.
extern "C" uintptr_t plaits_core_sp[2];
inline int RandomCore() {
  char here;
  uintptr_t sp = reinterpret_cast<uintptr_t>(&here), a = plaits_core_sp[0], b = plaits_core_sp[1];
  if (!b) return 0;
  return (sp > a ? sp - a : a - sp) > (sp > b ? sp - b : b - sp);
}
#else
extern "C" uint32_t _c1_ustack[], _c1_sstack_top[];
inline int RandomCore() {
  char here;    // a local's address (__builtin_frame_address crashes the JieLi clang 4)
  uintptr_t sp = reinterpret_cast<uintptr_t>(&here);
  return sp >= reinterpret_cast<uintptr_t>(_c1_ustack) && sp < reinterpret_cast<uintptr_t>(_c1_sstack_top);
}
#endif

class Random {
 public:
  static inline uint32_t& state_ref() { return rng_state_[RandomCore()]; }
  static inline uint32_t state() { return state_ref(); }

  static inline void Seed(uint32_t seed) {
    state_ref() = seed;
  }

  static inline uint32_t GetWord() {
    uint32_t& s = state_ref();
    s = s * 1664525L + 1013904223L;
    return s;
  }
  
  static inline int16_t GetSample() {
    return static_cast<int16_t>(GetWord() >> 16);
  }

  static inline float GetFloat() {
    // LOOM-8: through a signed int (the JieLi clang 4 crashes on unsigned-to-float); the same [0, 1)
    // to the 31 bits a float can tell apart anyway
    return static_cast<float>(static_cast<int32_t>(GetWord() >> 1)) * (1.0f / 2147483648.0f);
  }

 private:
  static uint32_t rng_state_[2];

  DISALLOW_COPY_AND_ASSIGN(Random);
};

}  // namespace stmlib

#endif  // STMLIB_UTILS_RANDOM_H_
