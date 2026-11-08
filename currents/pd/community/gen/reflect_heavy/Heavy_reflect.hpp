/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside reflect.pd) */

#ifndef _HEAVY_CONTEXT_REFLECT_HPP_
#define _HEAVY_CONTEXT_REFLECT_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvTable.h"
#include "HvControlTabhead.h"
#include "HvSignalVar.h"
#include "HvControlSystem.h"
#include "HvControlDelay.h"
#include "HvSignalTabread.h"
#include "HvControlVar.h"
#include "HvMath.h"
#include "HvSignalTabwrite.h"
#include "HvControlBinop.h"
#include "HvControlCast.h"

class Heavy_reflect : public HeavyContext {

 public:
  Heavy_reflect(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_reflect();

  const char *getName() override { return "reflect"; }
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
  static void cMsg_7Lc94SRe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_u7dPxYhM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_UQVZDr50_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_lBkqLzXl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_tO44hCTX_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_nfiGKNFl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_zI4CXAXw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DH7AqDuT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ARJPe4P6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2HaFtTfP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RVvXZehQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1nymNvFP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ic8gkgia_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_daTtHsvt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_v3JkdoML_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ggmV2efZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qGZhZ2mG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_20weZhp9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_zYwq0jl3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_ZUHf3wJM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sBwadLne_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rlJQyWu1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0g1BQoau_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_aIkZKaMu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZzS49y0a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_paQIeFkJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kM5L3F75_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kl0juxbA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QuhOdImW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_i6SerG2j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1WONfUrX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5vjHCDvU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vwXBS0HH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_I0eAXDHi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_51IGLI5e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_m9YBVwtg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_YzUoUAPp_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_gpPri7dT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_ICQXDpxH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8H0ShUYJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qIZa9nyc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bbfgDyI1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_W19qhRhK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ysnp6uFE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HAAFvwyq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_k2N1tnnP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5Y1YCf61_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_TDJlabYx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_N4C8rx5P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_LmVTw3u5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_vIq0EZH3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_ven12Qxp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dWieNSGM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VMFNN0PQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iJCxlUSY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_6U7WE3nB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_idDjlEgm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_N1lcCnU6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qgtjWAVT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_o2ZgmRAb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ScnbDvfT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2dEqv5I3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l8eNf6kK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_o2EdGQ0T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_creYlpfZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1Hhvj67h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_83fHaTfy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PqGpRSox_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_24ScdU15_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Rt3PZD2T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_L6s4umuu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Gy440SD1_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabread sTabread_ZUHf3wJM;
  SignalTabwrite sTabwrite_AsPnjCOG;
  SignalTabread sTabread_ven12Qxp;
  SignalTabwrite sTabwrite_obac4Zom;
  ControlDelay cDelay_UQVZDr50;
  ControlDelay cDelay_lBkqLzXl;
  ControlBinop cBinop_nfiGKNFl;
  HvTable hTable_zI4CXAXw;
  ControlBinop cBinop_ARJPe4P6;
  ControlTabhead cTabhead_daTtHsvt;
  ControlVar cVar_qGZhZ2mG;
  ControlDelay cDelay_20weZhp9;
  ControlDelay cDelay_zYwq0jl3;
  ControlBinop cBinop_sBwadLne;
  ControlBinop cBinop_rlJQyWu1;
  ControlBinop cBinop_0g1BQoau;
  ControlBinop cBinop_kl0juxbA;
  ControlBinop cBinop_i6SerG2j;
  ControlBinop cBinop_1WONfUrX;
  ControlDelay cDelay_51IGLI5e;
  ControlDelay cDelay_m9YBVwtg;
  ControlBinop cBinop_gpPri7dT;
  HvTable hTable_ICQXDpxH;
  ControlBinop cBinop_qIZa9nyc;
  ControlTabhead cTabhead_k2N1tnnP;
  ControlVar cVar_N4C8rx5P;
  ControlDelay cDelay_LmVTw3u5;
  ControlDelay cDelay_vIq0EZH3;
  ControlBinop cBinop_dWieNSGM;
  ControlBinop cBinop_VMFNN0PQ;
  ControlBinop cBinop_iJCxlUSY;
  ControlBinop cBinop_o2ZgmRAb;
  ControlBinop cBinop_2dEqv5I3;
  ControlBinop cBinop_l8eNf6kK;
  SignalVarf sVarf_OBSD9ovq;
  ControlBinop cBinop_creYlpfZ;
  ControlBinop cBinop_1Hhvj67h;
  ControlBinop cBinop_83fHaTfy;
  SignalVarf sVarf_GppTFbUU;
  ControlBinop cBinop_PqGpRSox;
  ControlBinop cBinop_24ScdU15;
  SignalVarf sVarf_prOQBY9v;
  SignalVarf sVarf_4c3YLSu5;
};

#endif // _HEAVY_CONTEXT_REFLECT_HPP_
