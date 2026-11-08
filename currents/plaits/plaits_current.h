// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// A Ripple current of Mutable Instruments Plaits engines (Emilie Gillet, MIT; LOOM-8's freestanding build of
// Plaits 1.2, plaits_voice.cc). A group's file defines, then includes this:
//   PC_NAME      "macro-synth"
//   PC_ENGINES   its engines, Plaits' numbers (plaits_voice.h), in the order "model" picks them
//   PC_VOICES    notes at once (each voice room for the group's largest engine)
//   PC_STRUCK    the engines that decay by themselves (a bit each, Plaits' numbers): struck, not held
// and PLAITS_ENGINES, the same engines as a mask (plaits_voice.cc compiles only those).
//
// Knobs: model (only with more than one engine), harmonics, timbre, morph (Plaits' three), attack and release (the envelope for the engines that do
// not decay by themselves; the others ring out as struck), level. Velocity is Plaits' accent (strike strength) and
// the level. In two parts, the even voices and the odd: one for each core.
#include "ripple_current.h"
#ifdef PLAT_WEB   // the emulator links every current into one program: each one's C names made its own (RC_WEB_ID)
#define PC_JOIN2(a, b) a##b
#define PC_JOIN(a, b) PC_JOIN2(a, b)
#define plaits_engine_name PC_JOIN(plaits_engine_name_, RC_WEB_ID)
#define plaits_engine_object_bytes PC_JOIN(plaits_engine_object_bytes_, RC_WEB_ID)
#define plaits_engine_buffer_bytes PC_JOIN(plaits_engine_buffer_bytes_, RC_WEB_ID)
#define plaits_voice_bytes PC_JOIN(plaits_voice_bytes_, RC_WEB_ID)
#define plaits_voice_init PC_JOIN(plaits_voice_init_, RC_WEB_ID)
#define plaits_voice_buffer_used PC_JOIN(plaits_voice_buffer_used_, RC_WEB_ID)
#define plaits_voice_retrigger PC_JOIN(plaits_voice_retrigger_, RC_WEB_ID)
#define plaits_voice_render PC_JOIN(plaits_voice_render_, RC_WEB_ID)
#define plaits_core_sp PC_JOIN(plaits_core_sp_, RC_WEB_ID)
#endif
#include "plaits_voice.cc"

extern "C" {
uintptr_t plaits_core_sp[2];   // where each part's core has its stack (stmlib/utils/random.h)

// what the compiler calls for C++'s zeroing and copies: a current has no C library (loops: -fno-builtin keeps them
// from being turned back into these calls)
#if !defined(XY_HOST) && !defined(PLAT_HOST) && !defined(__APPLE__) && !defined(__linux__)
void* memset(void* d, int c, size_t n) {
  uint8_t* p = static_cast<uint8_t*>(d);
  while (n--) *p++ = static_cast<uint8_t>(c);
  return d;
}
void* memcpy(void* d, const void* s, size_t n) {
  uint8_t* p = static_cast<uint8_t*>(d);
  const uint8_t* q = static_cast<const uint8_t*>(s);
  while (n--) *p++ = *q++;
  return d;
}
void* memmove(void* d, const void* s, size_t n) {
  uint8_t* p = static_cast<uint8_t*>(d);
  const uint8_t* q = static_cast<const uint8_t*>(s);
  if (p < q) { while (n--) *p++ = *q++; } else { p += n; q += n; while (n--) *--p = *--q; }
  return d;
}
#endif
}

namespace {

constexpr uint8_t kEngines[] = {PC_ENGINES};
constexpr int kNEngines = sizeof kEngines;

constexpr size_t voice_bytes(int id) {
  return round8(sizeof(Voice)) + round8(kInfo[id].object_bytes) + round8(kInfo[id].buffer_bytes);
}
constexpr size_t max_bytes(int i) {
  return i >= kNEngines ? 0 : (voice_bytes(kEngines[i]) > max_bytes(i + 1) ? voice_bytes(kEngines[i]) : max_bytes(i + 1));
}
constexpr size_t kSlot = max_bytes(0);

enum { P_MODEL, P_HARMONICS, P_TIMBRE, P_MORPH, P_ATTACK, P_RELEASE, P_LEVEL, NP };
constexpr int kFirst = kNEngines > 1 ? 0 : 1;   // one engine: no model knob (the parameters start at harmonics)
const rc_param_t P[NP] = {
    {"model", 0.0f, static_cast<float>(kNEngines - 1), 0.0f},
    {"harmonics", 0.0f, 1.0f, 0.5f},
    {"timbre", 0.0f, 1.0f, 0.5f},
    {"morph", 0.0f, 1.0f, 0.5f},
    {"attack", 0.0f, 1.0f, 0.0f},
    {"release", 0.0f, 1.0f, 0.3f},
    {"level", 0.0f, 1.0f, 0.7f},
};

struct Note {
  int note;                 // -1 free
  int gate;
  uint32_t age;
  float vel, env;
  int fresh;                // a new strike: the engine sees the gate rise
  int quiet;                // struck: blocks in a row under -80 dB (at 40 it stops: the voice is free)
};

struct State {
  alignas(8) uint8_t slot[PC_VOICES][kSlot];
  Note n[PC_VOICES];
  float p[NP];
  int engine;               // Plaits' number of the model playing
  int struck;               // it decays by itself
  float a_step, r_mul;      // the envelope, per sample
  uint32_t clock;
  float out[2][kMaxBlockSize], aux[2][kMaxBlockSize];   // each part's scratch
};

void build(State* s, int model) {
  int id = kEngines[model < 0 ? 0 : model >= kNEngines ? kNEngines - 1 : model];
  s->engine = id;
  s->struck = (PC_STRUCK >> id) & 1;
  for (int v = 0; v < PC_VOICES; ++v) {
    plaits_voice_init(s->slot[v], kSlot, id);
    s->n[v].note = -1;
    s->n[v].gate = 0;
    s->n[v].env = 0.0f;
  }
}

void envelope(State* s) {
  float a = s->p[P_ATTACK], r = s->p[P_RELEASE];
  float at = 0.001f + a * a * 2.0f, rt = 0.01f + r * r * 4.0f;   // 1 ms .. 2 s, 10 ms .. 4 s
  s->a_step = 1.0f / (at * 44100.0f);
  s->r_mul = fm_expf(-6.9f / (rt * 44100.0f));                  // -60 dB in rt
}

void init(void* st, float sr) {
  State* s = static_cast<State*>(st);
  (void)sr;                 // (Plaits here runs at 44.1 kHz: plaits/dsp/dsp.h)
  for (int i = 0; i < NP; ++i) s->p[i] = P[i].def;
  envelope(s);
  build(s, 0);
}

void set(void* st, int k, float v) {
  State* s = static_cast<State*>(st);
  k += kFirst;
  float was = s->p[k];
  s->p[k] = v;
  if (k == P_MODEL && static_cast<int>(v + 0.5f) != static_cast<int>(was + 0.5f)) build(s, static_cast<int>(v + 0.5f));
  if (k == P_ATTACK || k == P_RELEASE) envelope(s);
}

void note(void* st, int nt, float vel) {
  State* s = static_cast<State*>(st);
  int v, pick = -1;
  if (vel <= 0.0f) {
    for (v = 0; v < PC_VOICES; ++v)
      if (s->n[v].note == nt && s->n[v].gate) s->n[v].gate = 0;
    return;
  }
  for (v = 0; v < PC_VOICES; ++v)          // a voice already on this note, else a quiet one, else the oldest
    if (s->n[v].note == nt) pick = v;
  for (v = 0; pick < 0 && v < PC_VOICES; ++v)
    if (!s->n[v].gate && s->n[v].env < 0.0005f) pick = v;
  for (v = 0; pick < 0 && v < PC_VOICES; ++v)
    if (pick < 0 || s->n[v].age < s->n[pick].age) pick = v;
  if (pick < 0)
    pick = 0;
  s->n[pick].note = nt;
  s->n[pick].gate = 1;
  s->n[pick].vel = vel;
  s->n[pick].age = ++s->clock;
  s->n[pick].fresh = 1;
  s->n[pick].quiet = 0;
  if (s->struck) s->n[pick].env = 1.0f;
}

void process_part(void* st, float* l, float* r, int n, int part) {
  State* s = static_cast<State*>(st);
  char here;
  plaits_core_sp[part] = reinterpret_cast<uintptr_t>(&here);
  float level = s->p[P_LEVEL];
  for (int v = part; v < PC_VOICES; v += 2) {
    Note* q = &s->n[v];
    if (q->note < 0 || (!s->struck && !q->gate && q->env < 0.0005f))
      continue;
    plaits_params_t pp;
    pp.note = static_cast<float>(q->note);
    pp.harmonics = s->p[P_HARMONICS];
    pp.timbre = s->p[P_TIMBRE];
    pp.morph = s->p[P_MORPH];
    pp.accent = q->vel;
    if (q->fresh) {
      plaits_voice_retrigger(s->slot[v]);
      q->fresh = 0;
    }
    pp.gate = s->struck ? 1 : q->gate;   // (struck: one rise per note, it rings out by itself)
    float g = level * 0.5f * (0.4f + 0.6f * q->vel), peak = 0.0f;   // (0.5: six engines at once stay under full scale)
    for (int done = 0; done < n;) {
      int k = n - done < static_cast<int>(kMaxBlockSize) ? n - done : static_cast<int>(kMaxBlockSize);
      plaits_voice_render(s->slot[v], &pp, s->out[part], s->aux[part], static_cast<uint32_t>(k));
      for (int i = 0; i < k; ++i) {
        float e;
        if (s->struck) {
          e = 1.0f;
        } else {
          if (q->gate) {
            q->env += s->a_step;
            if (q->env > 1.0f) q->env = 1.0f;
          } else {
            q->env *= s->r_mul;
          }
          e = q->env;
        }
        float x = s->out[part][i] * e * g;
        peak = fm_maxf(peak, fm_fabsf(x));
        l[done + i] += x;
        r[done + i] += x;
      }
      done += k;
    }
    if (s->struck && !q->gate) {          // rung out: the voice stops rendering
      q->quiet = peak < 0.0001f ? q->quiet + 1 : 0;
      if (q->quiet >= 40) q->note = -1;
    }
  }
}

void process(void* st, float* l, float* r, int n) {
  process_part(st, l, r, n, 0);
  process_part(st, l, r, n, 1);
}

const rc_desc_t D = {RC_MAGIC, RC_ABI, PC_NAME, sizeof(State), 0, PC_VOICES, NP - kFirst, P + kFirst, init, set, note, process,
                     2, {0, 0, 0}, process_part, 0};

}  // namespace

extern "C" RC_EXPORT(D)
