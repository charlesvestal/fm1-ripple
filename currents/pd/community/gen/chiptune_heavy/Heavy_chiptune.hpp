/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside chiptune.pd) */

#ifndef _HEAVY_CONTEXT_CHIPTUNE_HPP_
#define _HEAVY_CONTEXT_CHIPTUNE_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvMath.h"
#include "HvSignalLine.h"
#include "HvControlBinop.h"

class Heavy_chiptune : public HeavyContext {

 public:
  Heavy_chiptune(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
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
  static void cBinop_ef3R2NWO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_x2PvUvpa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qglFjToC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uFvkoasD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DmMdzVie_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_EvtzN7tr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_gumaGlst_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_IBTLZ9EG_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_0Hu4yd9Q;
  SignalLine sLine_LjH7z3II;
  SignalLine sLine_Pw3FLdCi;
  SignalLine sLine_kid45yKh;
  ControlBinop cBinop_ef3R2NWO;
  ControlBinop cBinop_x2PvUvpa;
  ControlBinop cBinop_qglFjToC;
};

#endif // _HEAVY_CONTEXT_CHIPTUNE_HPP_
