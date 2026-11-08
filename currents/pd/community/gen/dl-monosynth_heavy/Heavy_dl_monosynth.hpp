/** the author of dl-monosynth.pd */

#ifndef _HEAVY_CONTEXT_DL_MONOSYNTH_HPP_
#define _HEAVY_CONTEXT_DL_MONOSYNTH_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlIf.h"
#include "HvSignalDel1.h"
#include "HvSignalPhasor.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvControlExpr.h"
#include "HvControlBinop.h"
#include "HvSignalLine.h"
#include "HvSignalVar.h"
#include "HvControlPack.h"
#include "HvControlCast.h"
#include "HvControlDelay.h"
#include "HvSignalCPole.h"
#include "HvControlUnop.h"
#include "HvControlVar.h"
#include "HvMath.h"

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
  static void cSlice_DtWGP1MA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_5NoIww6F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_nq2HZAw5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_B67ThVJf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_iAZXQyr8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_YGiPD8YP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_dOdtGdnA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aqIKwhH7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_E1mIrAiU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_NzwsQ0vp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_ZjAiwssu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_2zCuKBTd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vIaoIaQy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_45f9PrS1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5tOnmfk4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RYiU0Ebp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_czNp1peA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tLy3OgtX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IhjHjNcR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oegfUN1n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eUyuxm1D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8BLu49fw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jdPRYojY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1wHEoUPT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gCvc4U7I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_7Zd5VS3U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_DxEFVhJu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lGRIpoXM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_znntK8Gg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ncxrkQfQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_yflrNPze_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_Wyhk5LOr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rS8novJ9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_u3TSHnDi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OuOzT9Lr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3kWYMlCL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MPfZ23Sn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dXr4j2fW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ItqGdxQi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5vv3PTkn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dthaDz0X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TayoltLu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_y909qPNq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OVo033C0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_stkRbrd4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_zXwMQ97g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lYJxZ7Of_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_kuljscoh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bCbaZuRi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gWbtsnfM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RxkY3DUS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OGzh3Svf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DlGOGZPc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HAeGmCH1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VJXxWtEz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6hec2Ejp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OMhVB3gS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qH58ZQ1O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5fAYkf1e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JkzYW0lC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_b4VKF93N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_CMQMQLzq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_iPIsdrsI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_H8mC32zz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OnjquUco_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xnwHikDM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_X5t4J8hY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_PlGj19xl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_w4YX3xBZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_kizANFNr_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_50cpiN5r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_o2LviSbN_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_6wEOcohl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4toScu0N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QalNDQCX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vNsIlgwG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LzHTY9pL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aGzeN8Do_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sCQdfuT8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_zigrAtV4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_e7oQw0jy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_OtytRF3X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2464m5IT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CxYg1IGV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YSrNBNoG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LgTzm9su_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_f94fLc18_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fOIUEBTu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_P3QJdgbp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YkAiMQdT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_n21Zgi1q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_BCXBOQQM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_iXAs8Joh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_FDHzds8N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_zkujFune_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Oc1Ts7nZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_JFdfAvQR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Hd0tgrxf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_itom2HiF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_W9c1pvRM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_mHaK6bJ6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_wStRXQzE_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_jMK7kzew;
  SignalLine sLine_TdVtE9FG;
  SignalCPole sCPole_akvqsoP8;
  SignalCPole sCPole_YXgkvksL;
  ControlSlice cSlice_DtWGP1MA;
  ControlSlice cSlice_5NoIww6F;
  ControlSlice cSlice_nq2HZAw5;
  ControlVar cVar_B67ThVJf;
  ControlIf cIf_dOdtGdnA;
  ControlBinop cBinop_aqIKwhH7;
  ControlIf cIf_E1mIrAiU;
  ControlIf cIf_NzwsQ0vp;
  ControlIf cIf_ZjAiwssu;
  ControlIf cIf_2zCuKBTd;
  ControlBinop cBinop_vIaoIaQy;
  ControlBinop cBinop_45f9PrS1;
  ControlBinop cBinop_5tOnmfk4;
  ControlBinop cBinop_oegfUN1n;
  ControlBinop cBinop_eUyuxm1D;
  ControlBinop cBinop_8BLu49fw;
  ControlBinop cBinop_jdPRYojY;
  ControlBinop cBinop_1wHEoUPT;
  SignalVarf sVarf_dZmyJT01;
  ControlExpr cExpr_7Zd5VS3U;
  static float cExpr_7Zd5VS3U_evaluate(const float* args);
  ControlExpr cExpr_DxEFVhJu;
  static float cExpr_DxEFVhJu_evaluate(const float* args);
  SignalVarf sVarf_BdqT3TG9;
  SignalVarf sVarf_rpR3lgDB;
  SignalVarf sVarf_dQSmxp1z;
  ControlVar cVar_lGRIpoXM;
  ControlVar cVar_yflrNPze;
  ControlIf cIf_Wyhk5LOr;
  ControlBinop cBinop_rS8novJ9;
  ControlBinop cBinop_OuOzT9Lr;
  ControlBinop cBinop_3kWYMlCL;
  ControlBinop cBinop_dXr4j2fW;
  ControlBinop cBinop_5vv3PTkn;
  ControlBinop cBinop_dthaDz0X;
  SignalVarf sVarf_hLK5jsho;
  SignalVarf sVarf_sj66phiy;
  SignalVarf sVarf_1SyNHtmP;
  SignalVarf sVarf_ZcKyO8ex;
  ControlVar cVar_lYJxZ7Of;
  ControlIf cIf_kuljscoh;
  ControlBinop cBinop_bCbaZuRi;
  ControlBinop cBinop_RxkY3DUS;
  ControlBinop cBinop_OGzh3Svf;
  ControlBinop cBinop_HAeGmCH1;
  ControlBinop cBinop_6hec2Ejp;
  ControlBinop cBinop_OMhVB3gS;
  SignalVarf sVarf_HZVB0f2v;
  SignalVarf sVarf_K6MkRgel;
  SignalVarf sVarf_RG7k0hhU;
  SignalVarf sVarf_LWl6mHte;
  ControlVar cVar_b4VKF93N;
  ControlExpr cExpr_CMQMQLzq;
  static float cExpr_CMQMQLzq_evaluate(const float* args);
  ControlVar cVar_iPIsdrsI;
  ControlVar cVar_H8mC32zz;
  ControlVar cVar_OnjquUco;
  ControlVar cVar_xnwHikDM;
  ControlVar cVar_X5t4J8hY;
  ControlPack cPack_PlGj19xl;
  ControlDelay cDelay_6wEOcohl;
  ControlVar cVar_vNsIlgwG;
  ControlVar cVar_LzHTY9pL;
  ControlVar cVar_aGzeN8Do;
  ControlVar cVar_sCQdfuT8;
  ControlExpr cExpr_zigrAtV4;
  static float cExpr_zigrAtV4_evaluate(const float* args);
  ControlExpr cExpr_e7oQw0jy;
  static float cExpr_e7oQw0jy_evaluate(const float* args);
  ControlExpr cExpr_OtytRF3X;
  static float cExpr_OtytRF3X_evaluate(const float* args);
  ControlVar cVar_fOIUEBTu;
  SignalVarf sVarf_fao7gZRI;
  ControlVar cVar_P3QJdgbp;
  ControlVar cVar_YkAiMQdT;
  ControlExpr cExpr_n21Zgi1q;
  static float cExpr_n21Zgi1q_evaluate(const float* args);
  SignalVarf sVarf_IK16YqnB;
};

#endif // _HEAVY_CONTEXT_DL_MONOSYNTH_HPP_
