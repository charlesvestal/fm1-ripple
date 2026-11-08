/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside bitcrush.pd) */

#ifndef _HEAVY_CONTEXT_BITCRUSH_HPP_
#define _HEAVY_CONTEXT_BITCRUSH_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalVar.h"
#include "HvMath.h"
#include "HvControlBinop.h"

class Heavy_bitcrush : public HeavyContext {

 public:
  Heavy_bitcrush(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_bitcrush();

  const char *getName() override { return "bitcrush"; }
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
  static void cBinop_4VlPS6NO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Xu0uyXKC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2gzU6Xvf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r3UKsMsF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_u0AzTVCB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_kt9BynnL_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalVarf sVarf_YHLo4sBU;
  SignalVarf sVarf_GfY3bJxy;
  ControlBinop cBinop_4VlPS6NO;
  ControlBinop cBinop_Xu0uyXKC;
  ControlBinop cBinop_2gzU6Xvf;
  ControlBinop cBinop_r3UKsMsF;
  SignalVarf sVarf_U1dx6hs6;
  SignalVarf sVarf_nnxBBLci;
};

#endif // _HEAVY_CONTEXT_BITCRUSH_HPP_
