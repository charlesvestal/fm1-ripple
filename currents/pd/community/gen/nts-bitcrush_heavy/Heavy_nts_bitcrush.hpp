/** the author of nts-bitcrush.pd */

#ifndef _HEAVY_CONTEXT_NTS_BITCRUSH_HPP_
#define _HEAVY_CONTEXT_NTS_BITCRUSH_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvMath.h"
#include "HvSignalVar.h"
#include "HvControlBinop.h"

class Heavy_nts_bitcrush : public HeavyContext {

 public:
  Heavy_nts_bitcrush(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_nts_bitcrush();

  const char *getName() override { return "nts_bitcrush"; }
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
        TIME = 0x8E55AA5F, // time
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
  static void cBinop_w0m6FGty_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FiKkXCFR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nQaFaO1I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6UAt5J9B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_L6b13QRC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_B2JQwy6Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalVarf sVarf_rAeXTnsH;
  SignalVarf sVarf_nl11h4xx;
  ControlBinop cBinop_w0m6FGty;
  ControlBinop cBinop_FiKkXCFR;
  ControlBinop cBinop_nQaFaO1I;
  ControlBinop cBinop_6UAt5J9B;
  SignalVarf sVarf_hIN50NZb;
  SignalVarf sVarf_s9Sb2ief;
};

#endif // _HEAVY_CONTEXT_NTS_BITCRUSH_HPP_
