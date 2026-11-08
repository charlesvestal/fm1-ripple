/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside nts-reflection.pd) */

#ifndef _HEAVY_CONTEXT_NTS_REFLECTION_HPP_
#define _HEAVY_CONTEXT_NTS_REFLECTION_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlBinop.h"
#include "HvTable.h"
#include "HvControlSystem.h"
#include "HvControlVar.h"
#include "HvControlDelay.h"
#include "HvSignalTabread.h"
#include "HvSignalTabwrite.h"
#include "HvControlTabhead.h"
#include "HvControlCast.h"
#include "HvSignalVar.h"
#include "HvMath.h"

class Heavy_nts_reflection : public HeavyContext {

 public:
  Heavy_nts_reflection(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_nts_reflection();

  const char *getName() override { return "nts_reflection"; }
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
  static void cMsg_D6viUVFz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_o7kkvfoU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_2f3QI4hL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_3GXCaVCK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_yISIg6b9_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_7hm6bE8W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_EzXMWjUN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nIKyQGhH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KhBrjUMj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_f7fqLLvo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HqAVmMHf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Z0DrpVQu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7GoG1puk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_etMakGVg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nYaS3YUF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_FVXb9wuE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5SpHfOqE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_hVoVUF7u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_E3Z6XVTN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_V80XcJBu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3fJ7mUjD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_glM9OSHf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YXyUABEa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_vvF0JzHK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kAwkjJNb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YmgsqGQg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9cb3OyuB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ozZSdmSe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PAPZKuVW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EUxuub1b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6vTDpXvD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1xmunSdV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_u3WKRH4X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_3WV8IwEt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_gC9hdb16_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_vUgtVz7M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_r7r8bGeE_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_01V9mDHn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_acO2lMDU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lFMveY1J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_svjuniU4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YywLn2Cb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Dk4tYQpZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PXfhzX0K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_It5bWGUw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_7OrlWfoI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aKg2nU9C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_JTp8XGxb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_G70JFD5c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_1Oa4XcLw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_Bdd576vW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_hDreVA6o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MKLvnlty_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ye6YsYjQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GRZDYzrz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_xanfLggG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SCPyiJkx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_blYwcVcr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FvXmpVzk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s3VKRs40_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7y7odVP3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VmHaa7Ze_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ugb1HN0u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_y3o4qek1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3Nlrw7Jx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cSTPhsSm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xDnrUa1L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_J6cNGDHO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KSAMFYos_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_wzqcXI3j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_JxowD5BX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_sQg2ro0s_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabread sTabread_V80XcJBu;
  SignalTabwrite sTabwrite_V9a0wHWV;
  SignalTabread sTabread_hDreVA6o;
  SignalTabwrite sTabwrite_WQHPw4tL;
  ControlDelay cDelay_2f3QI4hL;
  ControlDelay cDelay_3GXCaVCK;
  ControlBinop cBinop_7hm6bE8W;
  HvTable hTable_EzXMWjUN;
  ControlBinop cBinop_KhBrjUMj;
  ControlTabhead cTabhead_etMakGVg;
  ControlVar cVar_5SpHfOqE;
  ControlDelay cDelay_hVoVUF7u;
  ControlDelay cDelay_E3Z6XVTN;
  ControlBinop cBinop_3fJ7mUjD;
  ControlBinop cBinop_glM9OSHf;
  ControlBinop cBinop_YXyUABEa;
  ControlBinop cBinop_ozZSdmSe;
  ControlBinop cBinop_EUxuub1b;
  ControlBinop cBinop_6vTDpXvD;
  ControlDelay cDelay_gC9hdb16;
  ControlDelay cDelay_vUgtVz7M;
  ControlBinop cBinop_01V9mDHn;
  HvTable hTable_acO2lMDU;
  ControlBinop cBinop_svjuniU4;
  ControlTabhead cTabhead_7OrlWfoI;
  ControlVar cVar_G70JFD5c;
  ControlDelay cDelay_1Oa4XcLw;
  ControlDelay cDelay_Bdd576vW;
  ControlBinop cBinop_MKLvnlty;
  ControlBinop cBinop_Ye6YsYjQ;
  ControlBinop cBinop_GRZDYzrz;
  ControlBinop cBinop_s3VKRs40;
  ControlBinop cBinop_VmHaa7Ze;
  ControlBinop cBinop_Ugb1HN0u;
  SignalVarf sVarf_VVbmcQ4s;
  ControlBinop cBinop_3Nlrw7Jx;
  ControlBinop cBinop_cSTPhsSm;
  ControlBinop cBinop_xDnrUa1L;
  SignalVarf sVarf_Dt4lLqx5;
  ControlBinop cBinop_J6cNGDHO;
  ControlBinop cBinop_KSAMFYos;
  SignalVarf sVarf_5PEWkAoa;
  SignalVarf sVarf_1QSAi3lw;
};

#endif // _HEAVY_CONTEXT_NTS_REFLECTION_HPP_
