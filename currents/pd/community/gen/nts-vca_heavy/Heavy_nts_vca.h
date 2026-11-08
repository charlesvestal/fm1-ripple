/** the author of nts-vca.pd */

#ifndef _HEAVY_NTS_VCA_H_
#define _HEAVY_NTS_VCA_H_

#include "HvHeavy.h"

#ifdef __cplusplus
extern "C" {
#endif

#if HV_APPLE
#pragma mark - Heavy Context
#endif

typedef enum {
  HV_NTS_VCA_PARAM_IN_DEPTH_F = 0xC21FE6A3, // depth_f
} Hv_nts_vca_ParameterIn;


/**
 * Creates a new patch instance.
 * Sample rate should be positive and in Hertz, e.g. 44100.0.
 */
HeavyContextInterface *hv_nts_vca_new(float sampleRate);

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
HeavyContextInterface *hv_nts_vca_new_with_options(float sampleRate, int poolKb, int inQueueKb, int outQueueKb);

/**
 * Free the patch instance.
 */
void hv_nts_vca_free(HeavyContextInterface *instance);


#ifdef __cplusplus
} // extern "C"
#endif

#endif // _HEAVY_NTS_VCA_H_
