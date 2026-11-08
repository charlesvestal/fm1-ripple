/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside wavefolder.pd) */

#ifndef _HEAVY_CONTEXT_WAVEFOLDER_HPP_
#define _HEAVY_CONTEXT_WAVEFOLDER_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalPhasor.h"
#include "HvSignalVar.h"
#include "HvSignalLine.h"
#include "HvMath.h"

class Heavy_wavefolder : public HeavyContext {

 public:
  Heavy_wavefolder(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_wavefolder();

  const char *getName() override { return "wavefolder"; }
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
  static void cMsg_LABhLjh4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YxgETOqW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_psUpTBs2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_haIcVZSw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_phDSYo94_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_mGPo96oM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_7eGOD5Q3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_gg3If44O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_o7jWdFLA_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_3d2uRqYT;
  SignalLine sLine_gdtHg9QU;
  SignalLine sLine_hcZo5z9g;
  SignalLine sLine_CcmlAnkP;
  SignalLine sLine_l4OXbj63;
};

#endif // _HEAVY_CONTEXT_WAVEFOLDER_HPP_
