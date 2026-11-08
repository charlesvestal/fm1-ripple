/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside chorus.pd) */

#ifndef _HEAVY_CONTEXT_CHORUS_HPP_
#define _HEAVY_CONTEXT_CHORUS_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalVar.h"
#include "HvTable.h"
#include "HvSignalPhasor.h"
#include "HvMath.h"
#include "HvControlVar.h"
#include "HvControlCast.h"
#include "HvSignalTabwrite.h"
#include "HvControlSystem.h"
#include "HvSignalTabread.h"
#include "HvControlBinop.h"
#include "HvControlDelay.h"

class Heavy_chorus : public HeavyContext {

 public:
  Heavy_chorus(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
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
  static void cMsg_mSQpuz33_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_dijCXizx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_5rOAk9J6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_cFE1NSuk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_zEikg0jj_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_l9LRuS1w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_SUIbGVwa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UinLiv4X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4s1DKZZQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pkI76fqY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Si104SvA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aUnmU6rh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CXYKtqbj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IjVuf3uJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_TBQyKr1m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_oYGgexwW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_BPLCANkv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_yor7JyEC_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_nE5qsaYb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_HNJtT3Jo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8AfdKxE7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dmFbQueG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fmocKOq1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vec7zPjw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OBt36oNH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_z0DCCtwS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yUeWIGAE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_eEJ6LJQF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_SAlvdtpt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_0puRm3BG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_V6K8ekav_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rcmOFFPo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_W63MXUvT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1vAhUuTy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_823HDVpZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_y7BodWgw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_QP1AwK0D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yi7rl47T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ur6jbYPx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rRZFhdvP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Q6ujPYkZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YTLSOr8W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_rd0Ggdbo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_yimetNWM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_CCwfPsbi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_87GOP9zZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabwrite sTabwrite_leFdM7xR;
  SignalTabwrite sTabwrite_N29DE2Mo;
  SignalPhasor sPhasor_lBQR2Wtg;
  SignalTabhead sTabhead_FxjUjDOA;
  SignalTabread sTabread_kJYBrK8u;
  SignalTabread sTabread_cYzNru2S;
  SignalTabhead sTabhead_QTdmUhfF;
  SignalTabread sTabread_qC9joe79;
  SignalTabread sTabread_Cc4N1gyb;
  ControlDelay cDelay_5rOAk9J6;
  ControlDelay cDelay_cFE1NSuk;
  ControlBinop cBinop_l9LRuS1w;
  HvTable hTable_SUIbGVwa;
  ControlBinop cBinop_4s1DKZZQ;
  ControlDelay cDelay_oYGgexwW;
  ControlDelay cDelay_BPLCANkv;
  ControlBinop cBinop_nE5qsaYb;
  HvTable hTable_HNJtT3Jo;
  ControlBinop cBinop_dmFbQueG;
  ControlVar cVar_SAlvdtpt;
  ControlBinop cBinop_V6K8ekav;
  ControlBinop cBinop_W63MXUvT;
  SignalVarf sVarf_1pVEfLNB;
  SignalVarf sVarf_qCzggjvt;
  SignalVarf sVarf_53ylUTrY;
  ControlVar cVar_y7BodWgw;
  ControlBinop cBinop_yi7rl47T;
  ControlBinop cBinop_rRZFhdvP;
  SignalVarf sVarf_qesXFR3i;
  SignalVarf sVarf_DOVRKP2a;
  SignalVarf sVarf_sCSA56Zs;
  ControlBinop cBinop_Q6ujPYkZ;
  ControlBinop cBinop_YTLSOr8W;
  SignalVarf sVarf_PaMLCdgX;
  SignalVarf sVarf_C2VPb9i3;
  SignalVarf sVarf_Bl3ugIEP;
  SignalVarf sVarf_rTZ3ZKrH;
  SignalVarf sVarf_EPgWINIR;
};

#endif // _HEAVY_CONTEXT_CHORUS_HPP_
