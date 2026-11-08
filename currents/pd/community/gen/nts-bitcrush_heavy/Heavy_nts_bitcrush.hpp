/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside nts-bitcrush.pd) */

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
  static void cBinop_Bxz2AZo3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_anhpxAna_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pwM2nCkE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ceY285i6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_BpTuQhHl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_RTb3SZvd_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalVarf sVarf_ZKGK1Vvy;
  SignalVarf sVarf_bGUtXRpE;
  ControlBinop cBinop_Bxz2AZo3;
  ControlBinop cBinop_anhpxAna;
  ControlBinop cBinop_pwM2nCkE;
  ControlBinop cBinop_ceY285i6;
  SignalVarf sVarf_er7qHcJq;
  SignalVarf sVarf_XwBJn0QJ;
};

#endif // _HEAVY_CONTEXT_NTS_BITCRUSH_HPP_
