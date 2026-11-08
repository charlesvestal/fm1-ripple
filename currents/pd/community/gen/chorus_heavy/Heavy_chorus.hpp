/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside chorus.pd) */

#ifndef _HEAVY_CONTEXT_CHORUS_HPP_
#define _HEAVY_CONTEXT_CHORUS_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlCast.h"
#include "HvControlSystem.h"
#include "HvMath.h"
#include "HvSignalVar.h"
#include "HvControlVar.h"
#include "HvSignalPhasor.h"
#include "HvControlDelay.h"
#include "HvControlBinop.h"
#include "HvSignalTabread.h"
#include "HvSignalTabwrite.h"
#include "HvTable.h"

class Heavy_chorus : public HeavyContext {

 public:
  Heavy_chorus(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_chorus();

  const char *getName() override { return "chorus"; }
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
        MIX_F = 0x9F29F22, // mix_f
        TIME_F = 0x2641F460, // time_f
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
  static void cMsg_BJ7UVqpN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_iJ2Hl7zu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_6lKHiM7L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_vWeGjxis_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_z6NeUapZ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_MX7VuKzW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_ivre7FGv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_n8FMcpTz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IwYkVySm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NPxn2hdM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_59gxprvx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AMbYwqvv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aeioqGr7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_n4hXm0d0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_BqsDYCC5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_siX4At88_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_KHFR5mdW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_oDEirO6L_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_oYkzZ9tv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_CIAJtq9f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gmli6SlA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_twGC37F4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tk1mkzce_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DEbDdsBT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4sU64cbm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GOT6Pyef_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JYG5ss9Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_AybcyZD0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eoUOuNJ5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_PdA9uzKv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TwBWMDks_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2qhaQRle_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2nU2LuwL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ART3hkjM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_e1E9cacz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_R1DcLRrH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_BQVqVdea_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LWCDg9DS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_I3jxAWki_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LUM1XfBL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uxRGcf4w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZElZULas_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_rXnYn6Q6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_N8izXLE1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_vLk2Kpx6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_VUOFAl6i_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabwrite sTabwrite_FB4gzU7N;
  SignalTabwrite sTabwrite_JpuKhpqf;
  SignalPhasor sPhasor_HxSqqbUB;
  SignalTabhead sTabhead_qg6EEFI0;
  SignalTabread sTabread_gnVcGWsA;
  SignalTabread sTabread_Nx9iGOcj;
  SignalTabhead sTabhead_dyTrxgMR;
  SignalTabread sTabread_ZLlwqhe5;
  SignalTabread sTabread_9PJ91RKz;
  ControlDelay cDelay_6lKHiM7L;
  ControlDelay cDelay_vWeGjxis;
  ControlBinop cBinop_MX7VuKzW;
  HvTable hTable_ivre7FGv;
  ControlBinop cBinop_IwYkVySm;
  ControlDelay cDelay_siX4At88;
  ControlDelay cDelay_KHFR5mdW;
  ControlBinop cBinop_oYkzZ9tv;
  HvTable hTable_CIAJtq9f;
  ControlBinop cBinop_twGC37F4;
  ControlVar cVar_eoUOuNJ5;
  ControlBinop cBinop_TwBWMDks;
  ControlBinop cBinop_2nU2LuwL;
  SignalVarf sVarf_8CVQM73m;
  SignalVarf sVarf_3wNwNzvF;
  SignalVarf sVarf_8x6CIiHz;
  ControlVar cVar_R1DcLRrH;
  ControlBinop cBinop_LWCDg9DS;
  ControlBinop cBinop_LUM1XfBL;
  SignalVarf sVarf_HxnA0eLd;
  SignalVarf sVarf_PJjuoOi7;
  SignalVarf sVarf_Sx01lz0V;
  ControlBinop cBinop_uxRGcf4w;
  ControlBinop cBinop_ZElZULas;
  SignalVarf sVarf_nOBj8H02;
  SignalVarf sVarf_zkrfAnMS;
  SignalVarf sVarf_XRVaOyg0;
  SignalVarf sVarf_OXnwWaZx;
  SignalVarf sVarf_J3P2TKg3;
};

#endif // _HEAVY_CONTEXT_CHORUS_HPP_
