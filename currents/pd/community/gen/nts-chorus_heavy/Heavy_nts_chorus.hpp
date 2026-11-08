/** the author of nts-chorus.pd */

#ifndef _HEAVY_CONTEXT_NTS_CHORUS_HPP_
#define _HEAVY_CONTEXT_NTS_CHORUS_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalTabread.h"
#include "HvControlDelay.h"
#include "HvControlBinop.h"
#include "HvSignalVar.h"
#include "HvControlVar.h"
#include "HvSignalPhasor.h"
#include "HvControlSystem.h"
#include "HvMath.h"
#include "HvTable.h"
#include "HvControlCast.h"
#include "HvSignalTabwrite.h"

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
  static void cMsg_sws0eKGb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_tcT0o7M0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_ALD3bT84_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_kRMZh3i9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_pVMbvEyo_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_7hSHLEap_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_dXT0v5Af_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wsAhU6df_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JIm3o9se_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pXPJgMTO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_t6LQIO19_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oGT4ZE7e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PCJaPEte_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6F6yy19c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_OOY3ijkL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_bAml0Skd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_a0YZKzOP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_GihAEcNa_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_0iaq4zvo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_Xd8x58aY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gH96eACz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pDdsGn0M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_j8qfTFiq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5z9D8uKl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PAGu7lUs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ObDszSce_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qhttj5RS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_T4Fhz2P4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QK0fVjoa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_wt35sdEa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6LwOytsC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_C7hGgM6w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VuLWjjXq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vc5IqF8T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_K202xsNl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Hp0ES4UV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_I3tO8F22_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dCF8Da9c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CD9IcQQj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hOoc8F28_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_moRDKFpC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HTUlzGuz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_R1VK8b5D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_7ogfGaDd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_cgJ7kCQX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_7Wfaclik_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabwrite sTabwrite_UfIRWYTX;
  SignalTabwrite sTabwrite_L2sr42Lx;
  SignalPhasor sPhasor_aMzpJjmz;
  SignalTabhead sTabhead_163MHuNq;
  SignalTabread sTabread_Gzs5rxwM;
  SignalTabread sTabread_fSKuo8dk;
  SignalTabhead sTabhead_9nKR2OhA;
  SignalTabread sTabread_SwtpMxwW;
  SignalTabread sTabread_IddX9U7L;
  ControlDelay cDelay_ALD3bT84;
  ControlDelay cDelay_kRMZh3i9;
  ControlBinop cBinop_7hSHLEap;
  HvTable hTable_dXT0v5Af;
  ControlBinop cBinop_JIm3o9se;
  ControlDelay cDelay_bAml0Skd;
  ControlDelay cDelay_a0YZKzOP;
  ControlBinop cBinop_0iaq4zvo;
  HvTable hTable_Xd8x58aY;
  ControlBinop cBinop_pDdsGn0M;
  ControlVar cVar_QK0fVjoa;
  ControlBinop cBinop_6LwOytsC;
  ControlBinop cBinop_VuLWjjXq;
  SignalVarf sVarf_vgoWK4Kp;
  SignalVarf sVarf_piamRIKX;
  SignalVarf sVarf_RIN8o1lV;
  ControlVar cVar_Hp0ES4UV;
  ControlBinop cBinop_dCF8Da9c;
  ControlBinop cBinop_hOoc8F28;
  SignalVarf sVarf_6PdNy3Pd;
  SignalVarf sVarf_HQl0lMtO;
  SignalVarf sVarf_8X2PpgF2;
  ControlBinop cBinop_moRDKFpC;
  ControlBinop cBinop_HTUlzGuz;
  SignalVarf sVarf_NLRWghvV;
  SignalVarf sVarf_V2QYzpE3;
  SignalVarf sVarf_ebRhpbzN;
  SignalVarf sVarf_cwdAxBkr;
  SignalVarf sVarf_lqZGAeVX;
};

#endif // _HEAVY_CONTEXT_NTS_CHORUS_HPP_
