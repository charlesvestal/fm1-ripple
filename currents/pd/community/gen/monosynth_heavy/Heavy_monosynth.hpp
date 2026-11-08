/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside monosynth.pd) */

#ifndef _HEAVY_CONTEXT_MONOSYNTH_HPP_
#define _HEAVY_CONTEXT_MONOSYNTH_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalVar.h"
#include "HvSignalCPole.h"
#include "HvControlDelay.h"
#include "HvControlVar.h"
#include "HvSignalPhasor.h"
#include "HvMath.h"
#include "HvControlCast.h"
#include "HvControlIf.h"
#include "HvControlPack.h"
#include "HvSignalDel1.h"
#include "HvControlExpr.h"
#include "HvControlSystem.h"
#include "HvSignalLine.h"
#include "HvControlSlice.h"
#include "HvControlBinop.h"
#include "HvControlUnop.h"

class Heavy_monosynth : public HeavyContext {

 public:
  Heavy_monosynth(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_monosynth();

  const char *getName() override { return "monosynth"; }
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
  static void cSlice_dqx0IRNu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_dRXEpwNm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_yomxeLPz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_C6Zzv2dy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_YfP3NrhQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_B6rbwTsR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_wa8CjGMh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oAD5wXUC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_JPDMqHog_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_RxQVm1kp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_d87gSIwM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_F9WSt0dB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hPD3C2BH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_n7IQ3hxT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9zD46AGu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1O4U56rV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kZADFeow_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cUrilS4O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pWR0Vkr9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3wnziwHh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aZ4zbhhh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mhWFbSdg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ShIvkkpQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5CwRBxtr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CUpk4x51_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_7gHyuud3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_1iyW31Ep_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dgGP1WBN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NP0qMD2e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_sfoVH789_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hNqzFvtm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_8jPAhab7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_B2YDCCcy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_n9byTDgo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Arvpi12B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Cay0ehEi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jHo2ccb6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nq0bztO9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ACseorjK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LwaKbcIV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dbfZaE55_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_N2fBjtz3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1SxtBpRo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mCQ46wyh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yf8nbX7Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_cBaUfizR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8SBEnQgl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_GuwfE2hL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LdhDiFe3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_y4YCohHu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DF6qbezJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_d59qc7ci_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6u32Y9Bt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_e5F5ZMom_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aLejSJDi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rMo9qQEf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QAfPOoha_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GLB8elJr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_S4hpUmO7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zBGtxW1O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_q4Dj0oa0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_JontdOEC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_7Siu1pfS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_14Osm7nO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Zn2Z5yrx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BeuC9cR1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mMejDmnF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_coCZV7Yn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rxxqFBFQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Bq89IMEo_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_9nA3vbX2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_eWItIGsK_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_WYoyXQzB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3pe84Fmy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1VknISnl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_SA0KNx1P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pyS109Sg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_SlbCm4wk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_IP8bkfl6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_9rH65PKz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_Oxtvxtcv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_yBm9p1nL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_D8Kq8LI8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SHZCtQRp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ur0gGxi9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SKpGU0jj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0IdHd3Lc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9UzhtynI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_s3tJnu9a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pEGj70BF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_9FV7fpB5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_VwsY7cBJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_fU70p9fd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_6kQRHjCQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_AsZIoJKp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_LmU7vLUI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_PNBS6kHg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_FXaAFwdX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Ubx5E0c2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_G0BIx0ex_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_79IZlRSf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_aQXPK7fZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_AhkrEBT4;
  SignalLine sLine_yPuM6XGy;
  SignalCPole sCPole_F51i6lxF;
  SignalCPole sCPole_TQP9qrDu;
  ControlSlice cSlice_dqx0IRNu;
  ControlSlice cSlice_dRXEpwNm;
  ControlSlice cSlice_yomxeLPz;
  ControlVar cVar_C6Zzv2dy;
  ControlIf cIf_wa8CjGMh;
  ControlBinop cBinop_oAD5wXUC;
  ControlIf cIf_JPDMqHog;
  ControlIf cIf_RxQVm1kp;
  ControlIf cIf_d87gSIwM;
  ControlIf cIf_F9WSt0dB;
  ControlBinop cBinop_hPD3C2BH;
  ControlBinop cBinop_n7IQ3hxT;
  ControlBinop cBinop_9zD46AGu;
  ControlBinop cBinop_3wnziwHh;
  ControlBinop cBinop_aZ4zbhhh;
  ControlBinop cBinop_mhWFbSdg;
  ControlBinop cBinop_ShIvkkpQ;
  ControlBinop cBinop_5CwRBxtr;
  SignalVarf sVarf_c4XmZCdb;
  ControlExpr cExpr_7gHyuud3;
  static float cExpr_7gHyuud3_evaluate(const float* args);
  ControlExpr cExpr_1iyW31Ep;
  static float cExpr_1iyW31Ep_evaluate(const float* args);
  SignalVarf sVarf_1t9fh7l5;
  SignalVarf sVarf_U2OSUZQd;
  SignalVarf sVarf_nAPXke0d;
  ControlVar cVar_dgGP1WBN;
  ControlVar cVar_hNqzFvtm;
  ControlIf cIf_8jPAhab7;
  ControlBinop cBinop_B2YDCCcy;
  ControlBinop cBinop_Arvpi12B;
  ControlBinop cBinop_Cay0ehEi;
  ControlBinop cBinop_nq0bztO9;
  ControlBinop cBinop_LwaKbcIV;
  ControlBinop cBinop_dbfZaE55;
  SignalVarf sVarf_zTaPmsjY;
  SignalVarf sVarf_yKwamrMn;
  SignalVarf sVarf_4uLrJyE7;
  SignalVarf sVarf_YK6LVGoT;
  ControlVar cVar_8SBEnQgl;
  ControlIf cIf_GuwfE2hL;
  ControlBinop cBinop_LdhDiFe3;
  ControlBinop cBinop_DF6qbezJ;
  ControlBinop cBinop_d59qc7ci;
  ControlBinop cBinop_e5F5ZMom;
  ControlBinop cBinop_rMo9qQEf;
  ControlBinop cBinop_QAfPOoha;
  SignalVarf sVarf_9KTyluoT;
  SignalVarf sVarf_31y2T22g;
  SignalVarf sVarf_pkl6PyxM;
  SignalVarf sVarf_WGw3ndVk;
  ControlVar cVar_q4Dj0oa0;
  ControlExpr cExpr_JontdOEC;
  static float cExpr_JontdOEC_evaluate(const float* args);
  ControlVar cVar_7Siu1pfS;
  ControlVar cVar_14Osm7nO;
  ControlVar cVar_Zn2Z5yrx;
  ControlVar cVar_BeuC9cR1;
  ControlVar cVar_mMejDmnF;
  ControlPack cPack_coCZV7Yn;
  ControlDelay cDelay_WYoyXQzB;
  ControlVar cVar_SA0KNx1P;
  ControlVar cVar_pyS109Sg;
  ControlVar cVar_SlbCm4wk;
  ControlVar cVar_IP8bkfl6;
  ControlExpr cExpr_9rH65PKz;
  static float cExpr_9rH65PKz_evaluate(const float* args);
  ControlExpr cExpr_Oxtvxtcv;
  static float cExpr_Oxtvxtcv_evaluate(const float* args);
  ControlExpr cExpr_yBm9p1nL;
  static float cExpr_yBm9p1nL_evaluate(const float* args);
  ControlVar cVar_9UzhtynI;
  SignalVarf sVarf_Pz9RC4ns;
  ControlVar cVar_s3tJnu9a;
  ControlVar cVar_pEGj70BF;
  ControlExpr cExpr_9FV7fpB5;
  static float cExpr_9FV7fpB5_evaluate(const float* args);
  SignalVarf sVarf_3CCuVowI;
};

#endif // _HEAVY_CONTEXT_MONOSYNTH_HPP_
