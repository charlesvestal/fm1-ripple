/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside chiptune.pd) */

#ifndef _HEAVY_CONTEXT_CHIPTUNE_HPP_
#define _HEAVY_CONTEXT_CHIPTUNE_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlBinop.h"
#include "HvSignalLine.h"
#include "HvSignalPhasor.h"
#include "HvSignalVar.h"
#include "HvMath.h"

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
  static void cBinop_ySAv9Jdb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2otfYm1j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_54NHpoIZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gpns2UVC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xwkwxCN9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8u10LyE0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Nx8dfTdu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_VUi2IIEA_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_tRhPAxzW;
  SignalLine sLine_sOweG7yM;
  SignalLine sLine_RGkDHOIj;
  SignalLine sLine_p1u6ZVKZ;
  ControlBinop cBinop_ySAv9Jdb;
  ControlBinop cBinop_2otfYm1j;
  ControlBinop cBinop_54NHpoIZ;
};

#endif // _HEAVY_CONTEXT_CHIPTUNE_HPP_
