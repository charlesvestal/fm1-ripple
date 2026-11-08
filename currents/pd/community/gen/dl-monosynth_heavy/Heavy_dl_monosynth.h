/** the author of dl-monosynth.pd */

#ifndef _HEAVY_DL_MONOSYNTH_H_
#define _HEAVY_DL_MONOSYNTH_H_

#include "HvHeavy.h"

#ifdef __cplusplus
extern "C" {
#endif

#if HV_APPLE
#pragma mark - Heavy Context
#endif

typedef enum {
  HV_DL_MONOSYNTH_PARAM_IN__1_WVFORM_F = 0xE0DDF12E, // _1_wvform_f
  HV_DL_MONOSYNTH_PARAM_IN__2_PWM_F = 0xAEA003E7, // _2_PWM_f
  HV_DL_MONOSYNTH_PARAM_IN__3_CUTOFF_F = 0x1400CF4A, // _3_cutoff_f
  HV_DL_MONOSYNTH_PARAM_IN__4_ATTACK_F = 0x76662EAD, // _4_Attack_f
  HV_DL_MONOSYNTH_PARAM_IN__5_DECAY_F = 0xEDB1071A, // _5_Decay_f
  HV_DL_MONOSYNTH_PARAM_IN__6_SUSTAIN_F = 0x46C2E2B6, // _6_Sustain_f
  HV_DL_MONOSYNTH_PARAM_IN__7_RELEASE_F = 0x59614F9D, // _7_Release_f
  HV_DL_MONOSYNTH_PARAM_IN_FLTRENV_F = 0x9ABB563A, // fltrenv_f
  HV_DL_MONOSYNTH_PARAM_IN_FLTRREZ_F = 0x3E80BBC2, // fltrrez_f
} Hv_dl_monosynth_ParameterIn;


/**
 * Creates a new patch instance.
 * Sample rate should be positive and in Hertz, e.g. 44100.0.
 */
HeavyContextInterface *hv_dl_monosynth_new(float sampleRate);

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
HeavyContextInterface *hv_dl_monosynth_new_with_options(float sampleRate, int poolKb, int inQueueKb, int outQueueKb);

/**
 * Free the patch instance.
 */
void hv_dl_monosynth_free(HeavyContextInterface *instance);


#ifdef __cplusplus
} // extern "C"
#endif

#endif // _HEAVY_DL_MONOSYNTH_H_
