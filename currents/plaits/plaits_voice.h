/* SPDX-License-Identifier: MIT */
/* LOOM-8: one Mutable Instruments Plaits engine as one voice, for C (plaits_voice.cc). Plaits' own voice
 * (engine selection, LPG, decay envelope, trigger delay) is left out: LOOM has its envelopes and filter
 * after the engine. A voice holds exactly one engine instance and its buffers, in memory the caller owns
 * (no heap, no statics written at run time), so voices can render on either core and in the audio
 * interrupt.
 *
 * Engine ids are Plaits 1.2's order (the module's two banks, then the third):
 *   0 va-vcf   1 phase-dist  2 six-op 0  3 six-op 1  4 six-op 2  5 wave-terrain  6 string-machine  7 chiptune
 *   8 va       9 waveshape  10 fm        11 grain    12 additive 13 wavetable    14 chord           15 speech
 *  16 swarm   17 noise      18 particle  19 string   20 modal    21 bass-drum    22 snare-drum      23 hi-hat
 * PLAITS_ENGINES (a bit mask, default all) picks the engines compiled in; init fails for the others. */
#pragma once
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PLAITS_NENGINE 24
#ifndef PLAITS_ENGINES
#define PLAITS_ENGINES 0xFFFFFFu
#endif
/* frames per engine call (Plaits' kBlockSize is 12, at 48 kHz; its most is 24): the parameters are
 * taken once per call and the engines ramp inside it */
#ifndef PLAITS_BLOCK
#define PLAITS_BLOCK 24
#endif

typedef struct {
    float note;                       /* MIDI note, fractional */
    float harmonics, timbre, morph;   /* 0..1, Plaits' three knobs */
    float accent;                     /* 0..1: Plaits' level CV / velocity (strike strength, FM velocity) */
    int gate;                         /* 1 while the note is held: the engine sees a trigger on its rise */
} plaits_params_t;

/* bytes a voice of this engine needs (the engine object, its buffers, the wrapper's state); 0 = not
 * compiled in */
size_t plaits_voice_bytes(int engine);
/* sizeof the engine object alone, and the buffer bytes it allocates at init (for the memory plan) */
size_t plaits_engine_object_bytes(int engine);
size_t plaits_engine_buffer_bytes(int engine);
/* build a voice of the engine in mem (8-aligned, at least plaits_voice_bytes(engine)): 0 ok, -1 no */
int plaits_voice_init(void *mem, size_t bytes, int engine);
/* n frames of the engine's main output (out) and its aux output (aux, may be NULL), overwritten.
 * Engines whose sound already carries an envelope (string, modal, the drums; speech's words) decay by
 * themselves after the gate's rise. */
void plaits_voice_render(void *mem, const plaits_params_t *p, float *out, float *aux, uint32_t n);
/* a new note on a sounding voice: the next render sees the gate rise again (a fresh strike) */
void plaits_voice_retrigger(void *mem);
const char *plaits_engine_name(int engine);
size_t plaits_voice_buffer_used(const void *mem);   /* what the engine's init took (the host test's check) */

#ifdef __cplusplus
}
#endif
