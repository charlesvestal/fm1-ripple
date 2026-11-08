/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside wavefolder.pd) */

#ifndef _HEAVY_CONTEXT_WAVEFOLDER_HPP_
#define _HEAVY_CONTEXT_WAVEFOLDER_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalVar.h"
#include "HvSignalLine.h"
#include "HvSignalPhasor.h"
#include "HvMath.h"

class Heavy_wavefolder : public HeavyContext {

 public:
  Heavy_wavefolder(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
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
  static void cMsg_i11tUvHp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CYwdc2VO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_F8VEp5uw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_630mp6BB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_wlqDi0lQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_zMZoxOLV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_sU4R4rrI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ar6sOS9p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_BRvYUyaZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_qGlalrc1;
  SignalLine sLine_72Pbr8yi;
  SignalLine sLine_vsfDnxFP;
  SignalLine sLine_uHzyVAen;
  SignalLine sLine_l2qkyjcW;
};

#endif // _HEAVY_CONTEXT_WAVEFOLDER_HPP_
