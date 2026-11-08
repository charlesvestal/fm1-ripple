/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside logue-wavefolder.pd) */

#ifndef _HEAVY_CONTEXT_LOGUE_WAVEFOLDER_HPP_
#define _HEAVY_CONTEXT_LOGUE_WAVEFOLDER_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvMath.h"
#include "HvSignalPhasor.h"
#include "HvSignalLine.h"
#include "HvSignalVar.h"

class Heavy_logue_wavefolder : public HeavyContext {

 public:
  Heavy_logue_wavefolder(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_logue_wavefolder();

  const char *getName() override { return "logue_wavefolder"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 1; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        ALT_F = 0x6C87328F, // alt_f
        PITCH = 0x8B2148DD, // pitch
        SCALE_F = 0x4C5B5D06, // scale_f
        SHAPE_F = 0xCE9531B0, // shape_f
        SLFO = 0x32F5C118, // slfo
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
  static void cMsg_QqBHe7oq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sYvw3AbU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_w53X4xyI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WJk43TsJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_QhDqryXR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_S9hBs5rR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_G70QHmji_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_AeotVo6w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_PorV2Prt_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_R7WNrk1F;
  SignalLine sLine_0m3G5PYn;
  SignalLine sLine_evXJRgob;
  SignalLine sLine_SFtwpL1a;
  SignalLine sLine_5eF5z6xW;
};

#endif // _HEAVY_CONTEXT_LOGUE_WAVEFOLDER_HPP_
