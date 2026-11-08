/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside monosynth.pd) */

#ifndef _HEAVY_CONTEXT_MONOSYNTH_HPP_
#define _HEAVY_CONTEXT_MONOSYNTH_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalCPole.h"
#include "HvSignalLine.h"
#include "HvControlUnop.h"
#include "HvControlExpr.h"
#include "HvControlCast.h"
#include "HvControlSystem.h"
#include "HvControlVar.h"
#include "HvControlBinop.h"
#include "HvSignalDel1.h"
#include "HvControlIf.h"
#include "HvControlDelay.h"
#include "HvControlSlice.h"
#include "HvSignalPhasor.h"
#include "HvMath.h"
#include "HvSignalVar.h"
#include "HvControlPack.h"

class Heavy_monosynth : public HeavyContext {

 public:
  Heavy_monosynth(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
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
  static void cSlice_qUdOgkAc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_VGHGxKOU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_IFYTI6G8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VSfxams3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_zflCJyDL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_y1pt6zFi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_DW4alz7B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hmn1VDyO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_lMFUTh6Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_5um8yXaT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_6dM6OEs2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_FXsOi8CQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lozKpbBX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vH5E66QX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zhBcdayC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ewKGzM7d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HVZtIhpB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_x9oXEb8O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EEWRbZZW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DCAT8cI4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tNc8VFQr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_b6ONZU3v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gENwZuDe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CWsziEwU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ctMfT5ou_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_FRC486nf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_p3VIWGTG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2l6CDLy6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_n4K1MKjR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_rTgPhpE0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QMY4Ggzg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_n5YfUWQD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tgRAL2fV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZJowdL08_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RbupiEJe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KZM2TsF0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_w6mFhFn7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Im61vpvj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UbGEOpM5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3NdWBMUx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gDTUiI3t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XCbEP0mi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tIaoGoRE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lqRaIRDG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fUcyIoWq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_WvsLSOFJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_95UCrsWy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_NWgrqZe3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QA67dBPv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HnnxLN2i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_g9XHfoRJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5YBtiPn8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KoKbyzCP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GEGmHTY2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CcblmiYb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OaQf3OZX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xtBLM9SF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Py8dyRp7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OOY7FVJR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vwbftYCD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xKsiCVlA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_TMzRHgEB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hndAACsC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_giAkG6l3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aBK3nt8r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_y37kE4Wk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_B2qgqmLP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_7kx740DA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DduyPFqu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Q7yzbo6J_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_ShWcOzXS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_otkHPbH7_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_IQCjo6sg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IKgkyohN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3brJOABW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jNz6Q2G7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_m5IJ5Ihq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jUppPZLK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5dhh83sZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_P6YKKPiA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_DseywbcZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_CJLkY1vC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RzGwFQAZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Hxvmgoyc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qiOac40Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CjHTu4RT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CtRUJw7Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KznjI4bV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_G1cSNLVq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JQNmzJVQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_DlgCv3Ip_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_9kTnKoWY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_pMQ3YC0X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_67dOCskv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_zTPOUaOw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_FiLhHVOs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_kPYjXeeF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_czagpNLf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_3dccnCC3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_SrAHwRo0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_KBSsdSkl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_gWTtaS78_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_BBO1i5zX;
  SignalLine sLine_8prVuuq1;
  SignalCPole sCPole_1egQ33SA;
  SignalCPole sCPole_V3fTvbtL;
  ControlSlice cSlice_qUdOgkAc;
  ControlSlice cSlice_VGHGxKOU;
  ControlSlice cSlice_IFYTI6G8;
  ControlVar cVar_VSfxams3;
  ControlIf cIf_DW4alz7B;
  ControlBinop cBinop_hmn1VDyO;
  ControlIf cIf_lMFUTh6Y;
  ControlIf cIf_5um8yXaT;
  ControlIf cIf_6dM6OEs2;
  ControlIf cIf_FXsOi8CQ;
  ControlBinop cBinop_lozKpbBX;
  ControlBinop cBinop_vH5E66QX;
  ControlBinop cBinop_zhBcdayC;
  ControlBinop cBinop_DCAT8cI4;
  ControlBinop cBinop_tNc8VFQr;
  ControlBinop cBinop_b6ONZU3v;
  ControlBinop cBinop_gENwZuDe;
  ControlBinop cBinop_CWsziEwU;
  SignalVarf sVarf_B8Uleb8r;
  ControlExpr cExpr_FRC486nf;
  static float cExpr_FRC486nf_evaluate(const float* args);
  ControlExpr cExpr_p3VIWGTG;
  static float cExpr_p3VIWGTG_evaluate(const float* args);
  SignalVarf sVarf_z8zpjddP;
  SignalVarf sVarf_KGLJr3ZS;
  SignalVarf sVarf_fS1Wln3l;
  ControlVar cVar_2l6CDLy6;
  ControlVar cVar_QMY4Ggzg;
  ControlIf cIf_n5YfUWQD;
  ControlBinop cBinop_tgRAL2fV;
  ControlBinop cBinop_RbupiEJe;
  ControlBinop cBinop_KZM2TsF0;
  ControlBinop cBinop_Im61vpvj;
  ControlBinop cBinop_3NdWBMUx;
  ControlBinop cBinop_gDTUiI3t;
  SignalVarf sVarf_hzRdtW2E;
  SignalVarf sVarf_XwrxV3j9;
  SignalVarf sVarf_s125NIxo;
  SignalVarf sVarf_KcB5rLFd;
  ControlVar cVar_95UCrsWy;
  ControlIf cIf_NWgrqZe3;
  ControlBinop cBinop_QA67dBPv;
  ControlBinop cBinop_g9XHfoRJ;
  ControlBinop cBinop_5YBtiPn8;
  ControlBinop cBinop_GEGmHTY2;
  ControlBinop cBinop_OaQf3OZX;
  ControlBinop cBinop_xtBLM9SF;
  SignalVarf sVarf_AQlhxHp1;
  SignalVarf sVarf_GA3osnfR;
  SignalVarf sVarf_kRWD6jUO;
  SignalVarf sVarf_wMig5v2o;
  ControlVar cVar_xKsiCVlA;
  ControlExpr cExpr_TMzRHgEB;
  static float cExpr_TMzRHgEB_evaluate(const float* args);
  ControlVar cVar_hndAACsC;
  ControlVar cVar_giAkG6l3;
  ControlVar cVar_aBK3nt8r;
  ControlVar cVar_y37kE4Wk;
  ControlVar cVar_B2qgqmLP;
  ControlPack cPack_7kx740DA;
  ControlDelay cDelay_IQCjo6sg;
  ControlVar cVar_jNz6Q2G7;
  ControlVar cVar_m5IJ5Ihq;
  ControlVar cVar_jUppPZLK;
  ControlVar cVar_5dhh83sZ;
  ControlExpr cExpr_P6YKKPiA;
  static float cExpr_P6YKKPiA_evaluate(const float* args);
  ControlExpr cExpr_DseywbcZ;
  static float cExpr_DseywbcZ_evaluate(const float* args);
  ControlExpr cExpr_CJLkY1vC;
  static float cExpr_CJLkY1vC_evaluate(const float* args);
  ControlVar cVar_KznjI4bV;
  SignalVarf sVarf_Et7gkvRE;
  ControlVar cVar_G1cSNLVq;
  ControlVar cVar_JQNmzJVQ;
  ControlExpr cExpr_DlgCv3Ip;
  static float cExpr_DlgCv3Ip_evaluate(const float* args);
  SignalVarf sVarf_afQ3ituN;
};

#endif // _HEAVY_CONTEXT_MONOSYNTH_HPP_
