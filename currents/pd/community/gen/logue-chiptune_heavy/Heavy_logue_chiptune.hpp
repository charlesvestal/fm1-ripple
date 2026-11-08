/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside logue-chiptune.pd) */

#ifndef _HEAVY_CONTEXT_LOGUE_CHIPTUNE_HPP_
#define _HEAVY_CONTEXT_LOGUE_CHIPTUNE_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalLine.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlBinop.h"
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
  static void cBinop_1a71Ygnz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5nt96xjH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cgmsAIVT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aBenQnZE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6t2hHGKC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XCNswlb8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_EwrlDDbC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_qIPHyBJQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_h5JY1ejU;
  SignalLine sLine_LpyM1KIX;
  SignalLine sLine_zd7k6GQn;
  SignalLine sLine_ZNKLBpXT;
  ControlBinop cBinop_1a71Ygnz;
  ControlBinop cBinop_5nt96xjH;
  ControlBinop cBinop_cgmsAIVT;
};

#endif // _HEAVY_CONTEXT_LOGUE_CHIPTUNE_HPP_
