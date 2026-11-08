/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside logue-wavefolder.pd) */

#ifndef _HEAVY_LOGUE_WAVEFOLDER_H_
#define _HEAVY_LOGUE_WAVEFOLDER_H_

#include "HvHeavy.h"

#ifdef __cplusplus
extern "C" {
#endif

#if HV_APPLE
#pragma mark - Heavy Context
#endif

typedef enum {
  HV_LOGUE_WAVEFOLDER_PARAM_IN_ALT_F = 0x6C87328F, // alt_f
  HV_LOGUE_WAVEFOLDER_PARAM_IN_PITCH = 0x8B2148DD, // pitch
  HV_LOGUE_WAVEFOLDER_PARAM_IN_SCALE_F = 0x4C5B5D06, // scale_f
  HV_LOGUE_WAVEFOLDER_PARAM_IN_SHAPE_F = 0xCE9531B0, // shape_f
  HV_LOGUE_WAVEFOLDER_PARAM_IN_SLFO = 0x32F5C118, // slfo
} Hv_logue_wavefolder_ParameterIn;


/**
 * Creates a new patch instance.
 * Sample rate should be positive and in Hertz, e.g. 44100.0.
 */
HeavyContextInterface *hv_logue_wavefolder_new(float sampleRate);

/**
 * Creates a new patch instance.
 * @param sampleRate  Sample rate should be positive (> 0) and in Hertz, e.g. 48000.0.
 * @param poolKb  Pool size is in kilobytes, and determines the maximum amount of memory
 *   allocated to messages at any time. By default this is 10 KB.
 * @param inQueueKb  The size of the input message queue in kilobytes. It determines the
 *   amount of memory dedicated to holding scheduled messages between calls to
 *   process(). Default is 2 KB.
 * @param outQueueKb  The size of the output message queue in kilobytes. It determines the
 *   amount of memory dedicated to holding scheduled messages to the default sendHook.
 *   See getNextSentMessage() for info on accessing these messages. Default is 0 KB.
 */
HeavyContextInterface *hv_logue_wavefolder_new_with_options(float sampleRate, int poolKb, int inQueueKb, int outQueueKb);

/**
 * Free the patch instance.
 */
void hv_logue_wavefolder_free(HeavyContextInterface *instance);


#ifdef __cplusplus
} // extern "C"
#endif

#endif // _HEAVY_LOGUE_WAVEFOLDER_H_
