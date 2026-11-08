/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside nts-chorus.pd) */

#ifndef _HEAVY_CONTEXT_NTS_CHORUS_HPP_
#define _HEAVY_CONTEXT_NTS_CHORUS_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalPhasor.h"
#include "HvControlBinop.h"
#include "HvMath.h"
#include "HvSignalTabread.h"
#include "HvControlSystem.h"
#include "HvSignalTabwrite.h"
#include "HvSignalVar.h"
#include "HvTable.h"
#include "HvControlDelay.h"
#include "HvControlCast.h"
#include "HvControlVar.h"

class Heavy_nts_chorus : public HeavyContext {

 public:
  Heavy_nts_chorus(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_nts_chorus();

  const char *getName() override { return "nts_chorus"; }
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
  static void cMsg_oZRTBk7V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_1lBjZ55d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_ggXmXIJn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_idB8VENu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_uiFcGUev_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_Q2MjroYO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_C3kJa94z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zIvjN8hE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VwA4FP0b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TYX5iWH8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0Ykmuio1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zCU4bAGL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gU31FVro_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_EipAYeBW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_6nYUWNku_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_6MkXZMvE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_WnLCmVNd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_vu1P4Xw9_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_l1wXzTUl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_Ifb9zaEr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BVmj1ALS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tWUstddg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_P8d3yrrL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nUVIK96A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LqfBd9eb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9Fu8i2Rm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_faCFEuHo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_1hXKHftC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bC5FwhnG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_FH0fepsC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kpRhX27K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oNa4XmvF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HclFfg5m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nHDotYki_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_0MumP8B2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CtmIrSqt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_xdGTqEQV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HvqoPKdG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8g5DknP0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mk0uJ8CM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WXoYLJti_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pPx0Xpjb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_AoXb4qIZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_8qOJkLkp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_aqsj0iwN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_7i574q69_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabwrite sTabwrite_3O6kPMlm;
  SignalTabwrite sTabwrite_J9M0rWhz;
  SignalPhasor sPhasor_bkGUy7O2;
  SignalTabhead sTabhead_igx4cM1G;
  SignalTabread sTabread_7zb2d6dz;
  SignalTabread sTabread_cW2uhdnC;
  SignalTabhead sTabhead_j5D3RFKV;
  SignalTabread sTabread_rkxrJ1fP;
  SignalTabread sTabread_fMireAnV;
  ControlDelay cDelay_ggXmXIJn;
  ControlDelay cDelay_idB8VENu;
  ControlBinop cBinop_Q2MjroYO;
  HvTable hTable_C3kJa94z;
  ControlBinop cBinop_VwA4FP0b;
  ControlDelay cDelay_6MkXZMvE;
  ControlDelay cDelay_WnLCmVNd;
  ControlBinop cBinop_l1wXzTUl;
  HvTable hTable_Ifb9zaEr;
  ControlBinop cBinop_tWUstddg;
  ControlVar cVar_bC5FwhnG;
  ControlBinop cBinop_kpRhX27K;
  ControlBinop cBinop_HclFfg5m;
  SignalVarf sVarf_tNTm5Pkq;
  SignalVarf sVarf_kHMQ1qdx;
  SignalVarf sVarf_9GRCKvdW;
  ControlVar cVar_CtmIrSqt;
  ControlBinop cBinop_HvqoPKdG;
  ControlBinop cBinop_mk0uJ8CM;
  SignalVarf sVarf_m26FMwph;
  SignalVarf sVarf_TT0QyzhS;
  SignalVarf sVarf_EdZ9yia7;
  ControlBinop cBinop_WXoYLJti;
  ControlBinop cBinop_pPx0Xpjb;
  SignalVarf sVarf_nk1gRvrm;
  SignalVarf sVarf_iMXo8YAU;
  SignalVarf sVarf_bOFg65zF;
  SignalVarf sVarf_7SWPWEAy;
  SignalVarf sVarf_uLwZyoEq;
};

#endif // _HEAVY_CONTEXT_NTS_CHORUS_HPP_
