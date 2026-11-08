/** the author of logue-chiptune.pd */

#ifndef _HEAVY_CONTEXT_LOGUE_CHIPTUNE_HPP_
#define _HEAVY_CONTEXT_LOGUE_CHIPTUNE_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalVar.h"
#include "HvControlBinop.h"
#include "HvSignalPhasor.h"
#include "HvSignalLine.h"
#include "HvMath.h"

class Heavy_logue_chiptune : public HeavyContext {

 public:
  Heavy_logue_chiptune(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_logue_chiptune();

  const char *getName() override { return "logue_chiptune"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 1; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        PITCH = 0x8B2148DD, // pitch
        WAVEFORM = 0xCE6D0368, // waveform
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
  static void cBinop_teicgtK9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_S7D2bQmn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_z2Nrd5qq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iUiM5ZPG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Nt61CCOZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_i9JVryyT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_fxvhc9LV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_HetBPjXM_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_bbXS8PpO;
  SignalLine sLine_MHd42UYE;
  SignalLine sLine_NA8PQgEj;
  SignalLine sLine_mT9bCayt;
  ControlBinop cBinop_teicgtK9;
  ControlBinop cBinop_S7D2bQmn;
  ControlBinop cBinop_z2Nrd5qq;
};

#endif // _HEAVY_CONTEXT_LOGUE_CHIPTUNE_HPP_
