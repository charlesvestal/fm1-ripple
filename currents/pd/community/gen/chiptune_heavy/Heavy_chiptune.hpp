/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside chiptune.pd) */

#ifndef _HEAVY_CONTEXT_CHIPTUNE_HPP_
#define _HEAVY_CONTEXT_CHIPTUNE_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvSignalLine.h"
#include "HvMath.h"
#include "HvControlBinop.h"

class Heavy_chiptune : public HeavyContext {

 public:
  Heavy_chiptune(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_chiptune();

  const char *getName() override { return "chiptune"; }
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
  static void cBinop_oSdHtx3o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FToegvlI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rWPqo5UX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mAW1xPKR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_C5c4xDKd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SWhZzrVw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_4LPtOIeV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_u7foLy73_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_quvkUTxS;
  SignalLine sLine_UdfMFwte;
  SignalLine sLine_xxoPtx5S;
  SignalLine sLine_d8ZpEz2W;
  ControlBinop cBinop_oSdHtx3o;
  ControlBinop cBinop_FToegvlI;
  ControlBinop cBinop_rWPqo5UX;
};

#endif // _HEAVY_CONTEXT_CHIPTUNE_HPP_
