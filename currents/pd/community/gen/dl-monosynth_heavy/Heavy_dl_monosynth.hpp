/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside dl-monosynth.pd) */

#ifndef _HEAVY_CONTEXT_DL_MONOSYNTH_HPP_
#define _HEAVY_CONTEXT_DL_MONOSYNTH_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlUnop.h"
#include "HvSignalVar.h"
#include "HvControlExpr.h"
#include "HvControlPack.h"
#include "HvControlVar.h"
#include "HvSignalPhasor.h"
#include "HvControlBinop.h"
#include "HvMath.h"
#include "HvSignalCPole.h"
#include "HvSignalLine.h"
#include "HvSignalDel1.h"
#include "HvControlSlice.h"
#include "HvControlIf.h"
#include "HvControlDelay.h"
#include "HvControlCast.h"
#include "HvControlSystem.h"

class Heavy_dl_monosynth : public HeavyContext {

 public:
  Heavy_dl_monosynth(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_dl_monosynth();

  const char *getName() override { return "dl_monosynth"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        _1_WVFORM_F = 0xE0DDF12E, // _1_wvform_f
        _2_PWM_F = 0xAEA003E7, // _2_PWM_f
        _3_CUTOFF_F = 0x1400CF4A, // _3_cutoff_f
        _4_ATTACK_F = 0x76662EAD, // _4_Attack_f
        _5_DECAY_F = 0xEDB1071A, // _5_Decay_f
        _6_SUSTAIN_F = 0x46C2E2B6, // _6_Sustain_f
        _7_RELEASE_F = 0x59614F9D, // _7_Release_f
        FLTRENV_F = 0x9ABB563A, // fltrenv_f
        FLTRREZ_F = 0x3E80BBC2, // fltrrez_f
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
  static void cSlice_7NmDcDn0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_pPNIbi8G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_1qhhVfpe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pPJXxFBP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_rY8TkhLk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_uecBgNqo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_fyQzCwT5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_farccMaA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_uPF605Mx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_QwFALaD0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_Uy6pecqx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_wrUxqXGE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QLHFFgxF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_k3Lo08pO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6B4TfcAl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rC0QGqSv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_i8Sg0Zcc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Fe36djB9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zv8QiPwy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zOSIQ3Cu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YD9qm0Fp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_q940tnwP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yyYBwNDQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fngHOfzH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kMdm3WCq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_ranjbsr4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_jUxyT6To_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hAl8xTgT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iTS0a9Vg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_OKOlaEUN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0qUoi2Vu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_rYE8mPGx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_h1tygeHC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fjD3s436_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_L0XuFPiD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BpfPOhF9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1abazFFB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yBq34Ev0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iGbhyWih_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1hJ75H42_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zXlwHxal_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vBcCsNSl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_01ORAOuV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ow3XB07L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LdPcqCvw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_vovKkuHE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bwP0OBTg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_BbY1aOCX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Q2yE8fYd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZXW0qNeC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r8WytHfm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4zi7rFV3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4Dlm0bkQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_W5X3PHAe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JbkNIAe6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ulcPwypy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zX5tGFgf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qR26VIhz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8lY4JMFW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8dNzrShq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ktdqyeVD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_v3er7kg4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pnF9aFyD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dSpal0HF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MMEaqMuK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_D1gs7t4V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rqIHCwT1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_daGXYyHo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cql1z6pN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Jr2dKB8C_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_cFnLZRc0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_iQ0lwIY0_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_Mz8f0rn5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_a1P5Bb2b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FR7ubPuN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ShwnkV2y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_q6QKufhJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2CYpOFYy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rxd6mUF1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_RYnsZYiY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_hHrZ4D1s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_m6tiz7Pj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CLluoA3a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nRWZG7D6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TBzCF1E0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Bhr746FA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OcIuzlkG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nuy7lYnA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kKntqUHX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KpieRRF2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_6CmIvRdy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_eEdgmI1e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_qkjU1HHM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_lVSdmDAX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xmD4NhJL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_p6suGxM9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2wZ9OPhj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xzHGfWZs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_i4XKaBwI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Ucayq2ay_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_1VGemouj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xpalY60f_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_7YfvkGIt;
  SignalLine sLine_TUYhJdOp;
  SignalCPole sCPole_HbOxtrgm;
  SignalCPole sCPole_50TYMjLx;
  ControlSlice cSlice_7NmDcDn0;
  ControlSlice cSlice_pPNIbi8G;
  ControlSlice cSlice_1qhhVfpe;
  ControlVar cVar_pPJXxFBP;
  ControlIf cIf_fyQzCwT5;
  ControlBinop cBinop_farccMaA;
  ControlIf cIf_uPF605Mx;
  ControlIf cIf_QwFALaD0;
  ControlIf cIf_Uy6pecqx;
  ControlIf cIf_wrUxqXGE;
  ControlBinop cBinop_QLHFFgxF;
  ControlBinop cBinop_k3Lo08pO;
  ControlBinop cBinop_6B4TfcAl;
  ControlBinop cBinop_zOSIQ3Cu;
  ControlBinop cBinop_YD9qm0Fp;
  ControlBinop cBinop_q940tnwP;
  ControlBinop cBinop_yyYBwNDQ;
  ControlBinop cBinop_fngHOfzH;
  SignalVarf sVarf_IPfaLFd0;
  ControlExpr cExpr_ranjbsr4;
  static float cExpr_ranjbsr4_evaluate(const float* args);
  ControlExpr cExpr_jUxyT6To;
  static float cExpr_jUxyT6To_evaluate(const float* args);
  SignalVarf sVarf_dFJ2BDZX;
  SignalVarf sVarf_naeb9PWW;
  SignalVarf sVarf_tNYlQbVh;
  ControlVar cVar_hAl8xTgT;
  ControlVar cVar_0qUoi2Vu;
  ControlIf cIf_rYE8mPGx;
  ControlBinop cBinop_h1tygeHC;
  ControlBinop cBinop_L0XuFPiD;
  ControlBinop cBinop_BpfPOhF9;
  ControlBinop cBinop_yBq34Ev0;
  ControlBinop cBinop_1hJ75H42;
  ControlBinop cBinop_zXlwHxal;
  SignalVarf sVarf_E8Jh81cd;
  SignalVarf sVarf_gMqAi5P6;
  SignalVarf sVarf_w6jJKtFs;
  SignalVarf sVarf_5ftm8qbK;
  ControlVar cVar_bwP0OBTg;
  ControlIf cIf_BbY1aOCX;
  ControlBinop cBinop_Q2yE8fYd;
  ControlBinop cBinop_r8WytHfm;
  ControlBinop cBinop_4zi7rFV3;
  ControlBinop cBinop_W5X3PHAe;
  ControlBinop cBinop_ulcPwypy;
  ControlBinop cBinop_zX5tGFgf;
  SignalVarf sVarf_hGcHvgKu;
  SignalVarf sVarf_qILMAMG5;
  SignalVarf sVarf_4QCRJWfI;
  SignalVarf sVarf_09VJE80F;
  ControlVar cVar_ktdqyeVD;
  ControlExpr cExpr_v3er7kg4;
  static float cExpr_v3er7kg4_evaluate(const float* args);
  ControlVar cVar_pnF9aFyD;
  ControlVar cVar_dSpal0HF;
  ControlVar cVar_MMEaqMuK;
  ControlVar cVar_D1gs7t4V;
  ControlVar cVar_rqIHCwT1;
  ControlPack cPack_daGXYyHo;
  ControlDelay cDelay_Mz8f0rn5;
  ControlVar cVar_ShwnkV2y;
  ControlVar cVar_q6QKufhJ;
  ControlVar cVar_2CYpOFYy;
  ControlVar cVar_rxd6mUF1;
  ControlExpr cExpr_RYnsZYiY;
  static float cExpr_RYnsZYiY_evaluate(const float* args);
  ControlExpr cExpr_hHrZ4D1s;
  static float cExpr_hHrZ4D1s_evaluate(const float* args);
  ControlExpr cExpr_m6tiz7Pj;
  static float cExpr_m6tiz7Pj_evaluate(const float* args);
  ControlVar cVar_nuy7lYnA;
  SignalVarf sVarf_pGDa00LH;
  ControlVar cVar_kKntqUHX;
  ControlVar cVar_KpieRRF2;
  ControlExpr cExpr_6CmIvRdy;
  static float cExpr_6CmIvRdy_evaluate(const float* args);
  SignalVarf sVarf_IZdtzN35;
};

#endif // _HEAVY_CONTEXT_DL_MONOSYNTH_HPP_
