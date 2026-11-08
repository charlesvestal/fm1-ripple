/** the author of nts-vca.pd */

#ifndef _HEAVY_CONTEXT_NTS_VCA_HPP_
#define _HEAVY_CONTEXT_NTS_VCA_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalLine.h"
#include "HvMath.h"

class Heavy_nts_vca : public HeavyContext {

 public:
  Heavy_nts_vca(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_nts_vca();

  const char *getName() override { return "nts_vca"; }
  int getNumInputChannels() override { return 2; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        DEPTH_F = 0xC21FE6A3, // depth_f
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;


  /*
  * Code for expr~ implementation
  * Write out the generic header code
  */

  // per class code

  // per object code


  // static sendMessage functions
  static void cMsg_ihAxPs1X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_jce0ag5G_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalLine sLine_QR1xHupr;
};

#endif // _HEAVY_CONTEXT_NTS_VCA_HPP_
