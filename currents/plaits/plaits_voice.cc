// SPDX-License-Identifier: MIT
// LOOM-8: one Plaits engine per voice, callable from C (plaits_voice.h). Freestanding C++: no exceptions,
// no RTTI, no C++ library (shim/ has the bits of <algorithm> and <cmath> Plaits uses), no global
// objects (nothing for a constructor list to run), no heap: the engine is built in the caller's memory
// with placement new.
//
// The engines and stmlib are Emilie Gillet's (MIT, firmware/src/plaits/LICENSE).

#include "plaits_voice.h"

#include "plaits/resources.h"
#include "plaits/dsp/engine/engine.h"
#include "plaits/dsp/engine/additive_engine.h"
#include "plaits/dsp/engine/bass_drum_engine.h"
#include "plaits/dsp/engine/chord_engine.h"
#include "plaits/dsp/engine/fm_engine.h"
#include "plaits/dsp/engine/grain_engine.h"
#include "plaits/dsp/engine/hi_hat_engine.h"
#include "plaits/dsp/engine/modal_engine.h"
#include "plaits/dsp/engine/noise_engine.h"
#include "plaits/dsp/engine/particle_engine.h"
#include "plaits/dsp/engine/snare_drum_engine.h"
#include "plaits/dsp/engine/speech_engine.h"
#include "plaits/dsp/engine/string_engine.h"
#include "plaits/dsp/engine/swarm_engine.h"
#include "plaits/dsp/engine/virtual_analog_engine.h"
#include "plaits/dsp/engine/waveshaping_engine.h"
#include "plaits/dsp/engine/wavetable_engine.h"
#include "plaits/dsp/engine2/chiptune_engine.h"
#include "plaits/dsp/engine2/phase_distortion_engine.h"
#include "plaits/dsp/engine2/six_op_engine.h"
#include "plaits/dsp/engine2/string_machine_engine.h"
#include "plaits/dsp/engine2/virtual_analog_vcf_engine.h"
#include "plaits/dsp/engine2/wave_terrain_engine.h"
#include "stmlib/dsp/limiter.h"
#include "stmlib/utils/buffer_allocator.h"
#include "stmlib/utils/random.h"

// placement new without <new>
inline void* operator new(size_t, void* p) throw() { return p; }

// an abstract class's vtable (Engine's, seen while a derived engine is being built) points here
#ifdef PLAT_WEB
__attribute__((weak))                       // (Ripple's emulator: one for every current linked in)
#endif
extern "C" void __cxa_pure_virtual(void) {
  for (;;) { }
}

namespace {

using namespace plaits;

struct Info {
  const char* name;
  float out_gain;           // Plaits' post-processing gain; negative: through the limiter at -gain
  uint32_t object_bytes;    // sizeof the engine
  uint32_t buffer_bytes;    // what its Init takes from the allocator (tests/host/plaits_test.c checks)
};

// the out gains are Plaits 1.2's (voice.cc RegisterInstance); the buffer bytes are what each Init
// allocates, measured (kMaxBlockSize = 24 floats of scratch; string: 3 strings of 1024 + 256 floats of delay;
// speech: 1024 LPC frames for its words; particle: its diffuser's 8192 samples; six-op: a bank of 32
// unpacked patches; string machine: the ensemble's 1024-sample line + its chord bank)
#define OBJ(T) static_cast<uint32_t>(sizeof(T))
constexpr Info kInfo[PLAITS_NENGINE] = {
  { "va-vcf", 1.0f, OBJ(VirtualAnalogVCFEngine), 0 },
  { "phase-dist", 0.7f, OBJ(PhaseDistortionEngine), 4 * 24 * 4 },
  { "six-op 0", 1.0f, OBJ(SixOpEngine), 24 * 4 + 32 * sizeof(fm::Patch) },
  { "six-op 1", 1.0f, OBJ(SixOpEngine), 24 * 4 + 32 * sizeof(fm::Patch) },
  { "six-op 2", 1.0f, OBJ(SixOpEngine), 24 * 4 + 32 * sizeof(fm::Patch) },
  { "wave-terrain", 0.7f, OBJ(WaveTerrainEngine), 4 * 24 * 4 },
  { "string-mach", 0.8f, OBJ(StringMachineEngine), 4332 },
  { "chiptune", 0.5f, OBJ(ChiptuneEngine), 236 },
  { "va", 0.8f, OBJ(VirtualAnalogEngine), 24 * 4 },
  { "waveshape", 0.7f, OBJ(WaveshapingEngine), 0 },
  { "fm", 0.6f, OBJ(FMEngine), 0 },
  { "grain", 0.7f, OBJ(GrainEngine), 0 },
  { "additive", 0.8f, OBJ(AdditiveEngine), 144 },
  { "wavetable", 0.6f, OBJ(WavetableEngine), 4 * 64 * sizeof(void*) },   // (Ripple: the four banks' maps)
  { "chord", 0.8f, OBJ(ChordEngine), 236 },
  { "speech", -0.7f, OBJ(SpeechEngine), 14656 },
  { "swarm", -3.0f, OBJ(SwarmEngine), 512 },
  { "noise", -1.0f, OBJ(NoiseEngine), 24 * 4 },
  { "particle", -2.0f, OBJ(ParticleEngine), 8192 * 2 },
  { "string", -1.0f, OBJ(StringEngine), 15520 },
  { "modal", -1.0f, OBJ(ModalEngine), 24 * 4 },
  { "bass-drum", 0.8f, OBJ(BassDrumEngine), 0 },
  { "snare-drum", 0.8f, OBJ(SnareDrumEngine), 0 },
  { "hi-hat", 0.8f, OBJ(HiHatEngine), 2 * 24 * 4 },
};
#undef OBJ

struct Voice {
  Engine* engine;
  int32_t id;
  int32_t gate;             // the last block's gate
  float gain;
  stmlib::Limiter limiter;
  stmlib::BufferAllocator allocator;
  uint32_t buffer_used;     // what Init took (the host test compares it with kInfo)
  uint32_t rng;             // the voice's own random state (stmlib/utils/random.h)
  float aux[kMaxBlockSize];
};

constexpr size_t round8(size_t n) { return (n + 7u) & ~size_t(7); }
inline bool compiled(int id) {
  return id >= 0 && id < PLAITS_NENGINE && ((PLAITS_ENGINES >> id) & 1u);
}

// build engine id at p; NULL if it is not compiled in
Engine* construct(int id, void* p) {
#define CASE(n, T) case n: if ((PLAITS_ENGINES >> n) & 1u) return new (p) T(); break;
  switch (id) {
    CASE(0, VirtualAnalogVCFEngine)
    CASE(1, PhaseDistortionEngine)
    CASE(2, SixOpEngine)
    CASE(3, SixOpEngine)
    CASE(4, SixOpEngine)
    CASE(5, WaveTerrainEngine)
    CASE(6, StringMachineEngine)
    CASE(7, ChiptuneEngine)
    CASE(8, VirtualAnalogEngine)
    CASE(9, WaveshapingEngine)
    CASE(10, FMEngine)
    CASE(11, GrainEngine)
    CASE(12, AdditiveEngine)
    CASE(13, WavetableEngine)
    CASE(14, ChordEngine)
    CASE(15, SpeechEngine)
    CASE(16, SwarmEngine)
    CASE(17, NoiseEngine)
    CASE(18, ParticleEngine)
    CASE(19, StringEngine)
    CASE(20, ModalEngine)
    CASE(21, BassDrumEngine)
    CASE(22, SnareDrumEngine)
    CASE(23, HiHatEngine)
    default: break;
  }
#undef CASE
  return NULL;
}

}  // namespace

#ifdef PLAITS_SIZE_PROBE
// the bytes of a voice of each engine on the target (tools/plaits_sizes.sh reads it from the object)
#define VB(i) static_cast<uint32_t>(round8(sizeof(Voice)) + round8(kInfo[i].object_bytes) + round8(kInfo[i].buffer_bytes))
extern "C" const uint32_t plaits_voice_bytes_tab[PLAITS_NENGINE + 1] = {
  VB(0), VB(1), VB(2), VB(3), VB(4), VB(5), VB(6), VB(7), VB(8), VB(9), VB(10), VB(11),
  VB(12), VB(13), VB(14), VB(15), VB(16), VB(17), VB(18), VB(19), VB(20), VB(21), VB(22), VB(23),
  static_cast<uint32_t>(sizeof(Voice)) };
#undef VB
#endif

extern "C" {

const char* plaits_engine_name(int engine) {
  return engine >= 0 && engine < PLAITS_NENGINE ? kInfo[engine].name : "?";
}

size_t plaits_engine_object_bytes(int engine) {
  return compiled(engine) ? kInfo[engine].object_bytes : 0;
}

size_t plaits_engine_buffer_bytes(int engine) {
  return compiled(engine) ? kInfo[engine].buffer_bytes : 0;
}

size_t plaits_voice_bytes(int engine) {
  if (!compiled(engine)) {
    return 0;
  }
  return round8(sizeof(Voice)) + round8(kInfo[engine].object_bytes) + round8(kInfo[engine].buffer_bytes);
}

int plaits_voice_init(void* mem, size_t bytes, int engine) {
  if (!compiled(engine) || bytes < plaits_voice_bytes(engine) || (reinterpret_cast<uintptr_t>(mem) & 7u)) {
    return -1;
  }
  uint8_t* base = static_cast<uint8_t*>(mem);
  Voice* v = new (base) Voice();
  uint8_t* obj = base + round8(sizeof(Voice));
  uint8_t* buffers = obj + round8(kInfo[engine].object_bytes);
  size_t room = bytes - static_cast<size_t>(buffers - base);
  v->engine = construct(engine, obj);
  v->id = engine;
  v->gate = 0;
  v->rng = 0x21u;
  v->gain = kInfo[engine].out_gain;
  v->limiter.Init();
  v->allocator.Init(buffers, room);
  v->engine->Init(&v->allocator);
  v->buffer_used = static_cast<uint32_t>(room - v->allocator.free());
  // as Plaits' voice does on an engine change: the six-op banks are the module's three, the
  // wavetable engine's user bank is its default
  // (the mask test keeps the DX7 banks, 12 KB, out of a build without the six-op engines)
  v->engine->LoadUserData((PLAITS_ENGINES & 0x1Cu) && engine >= 2 && engine <= 4 ? fm_patches_table[engine - 2] : NULL);
  v->engine->Reset();
  if ((PLAITS_ENGINES >> 7) & 1u) {
    if (engine == 7) {          // the chiptune engine's own envelope off: LOOM's envelopes follow
      static_cast<ChiptuneEngine*>(v->engine)->set_envelope_shape(ChiptuneEngine::NO_ENVELOPE);
    }
  }
  if ((PLAITS_ENGINES >> 15) & 1u) {
    if (engine == 15) {         // speech: no prosody or speed modulation (Plaits' unpatched values)
      static_cast<SpeechEngine*>(v->engine)->set_prosody_amount(0.0f);
      static_cast<SpeechEngine*>(v->engine)->set_speed(0.0f);
    }
  }
  return 0;
}

// what Init allocated (the host test's check of kInfo's buffer bytes)
size_t plaits_voice_buffer_used(const void* mem) {
  return static_cast<const Voice*>(mem)->buffer_used;
}

void plaits_voice_retrigger(void* mem) {
  static_cast<Voice*>(mem)->gate = 0;
}

void plaits_voice_render(void* mem, const plaits_params_t* p, float* out, float* aux, uint32_t n) {
  Voice* v = static_cast<Voice*>(mem);
  EngineParameters e;
  e.note = p->note;
  e.harmonics = p->harmonics;
  e.timbre = p->timbre;
  e.morph = p->morph;
  e.accent = p->accent;
  uint32_t& rng = stmlib::Random::state_ref();
  rng = v->rng;
  while (n) {
    uint32_t k = n < PLAITS_BLOCK ? n : PLAITS_BLOCK;
    int gate = p->gate ? 1 : 0;
    // a gate, as Plaits sees its TRIG input patched: the rise once, high while held
    e.trigger = (gate && !v->gate ? TRIGGER_RISING_EDGE : TRIGGER_LOW) | (gate ? TRIGGER_HIGH : TRIGGER_LOW);
    v->gate = gate;
    float* a = aux ? aux : v->aux;
    bool enveloped = false;
    v->engine->Render(e, out, a, k, &enveloped);
    if (v->gain < 0.0f) {
      v->limiter.Process(-v->gain, out, k);
    } else {
      for (uint32_t i = 0; i < k; ++i) {
        out[i] *= v->gain;
      }
    }
    out += k;
    if (aux) {
      aux += k;
    }
    n -= k;
  }
  v->rng = rng;
}

}  // extern "C"
