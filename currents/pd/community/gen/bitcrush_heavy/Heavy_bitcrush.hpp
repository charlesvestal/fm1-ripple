/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside bitcrush.pd) */

#ifndef _HEAVY_CONTEXT_BITCRUSH_HPP_
#define _HEAVY_CONTEXT_BITCRUSH_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvMath.h"
#include "HvControlBinop.h"
#include "HvSignalVar.h"

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
  static void cBinop_8HDE5G97_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ploCuFwo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gJpQyF7X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_J0nKZfmK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_wd5AunpO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_3VTdhJh9_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalVarf sVarf_AHtwmgGg;
  SignalVarf sVarf_ldA1tTQb;
  ControlBinop cBinop_8HDE5G97;
  ControlBinop cBinop_ploCuFwo;
  ControlBinop cBinop_gJpQyF7X;
  ControlBinop cBinop_J0nKZfmK;
  SignalVarf sVarf_u5aYxCz4;
  SignalVarf sVarf_y1ePLCHx;
};

#endif // _HEAVY_CONTEXT_BITCRUSH_HPP_
