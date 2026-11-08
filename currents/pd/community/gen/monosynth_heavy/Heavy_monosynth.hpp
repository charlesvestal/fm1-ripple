/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside monosynth.pd) */

#ifndef _HEAVY_CONTEXT_MONOSYNTH_HPP_
#define _HEAVY_CONTEXT_MONOSYNTH_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlVar.h"
#include "HvSignalLine.h"
#include "HvControlUnop.h"
#include "HvControlBinop.h"
#include "HvMath.h"
#include "HvControlExpr.h"
#include "HvControlPack.h"
#include "HvControlDelay.h"
#include "HvSignalVar.h"
#include "HvSignalCPole.h"
#include "HvSignalPhasor.h"
#include "HvControlSlice.h"
#include "HvControlSystem.h"
#include "HvControlIf.h"
#include "HvSignalDel1.h"
#include "HvControlCast.h"

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
  static void cSlice_oZSgk1Os_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_u9ofHdPn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_t2qPYfPc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_V27mdvbb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_pge9jDrg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_QOTMpCrq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_sXEuzTS9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gWXpM65M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_bpKD3EGL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_CMMHM19H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_Id2I314n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_7pN3myWB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JArBJ3fa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IenQiU4j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KWVOSPpj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4iCxaJDr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_w0NgJaID_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OW78KzLg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_eyBmRcGV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XdjGtM65_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XwconTnF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_V3GJq1L4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nW16h0iL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GVgDij1M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OZuZABis_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_rdcOi8KB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_YjUnVMrk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_T20a6bZC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_n9nruiuu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_YxaKdDZs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Ghx8ZwSZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_SgKgRelV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FUfBPZgc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Z8xtTnta_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XbatqCse_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_avWMP43l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_divthaSL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1xYMV0ru_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tj1C1vXq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kC2OVkVO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AeUT2J1Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FqJjiPL5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xNEnrkv1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4uJj2c0H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0COqeSFU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Eo23XJZ7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Jsrpl2fy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_vkWW0COg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CpVjitbW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lpOoCsyl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l39Qp5Yl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zXgpfb4o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OlZW6zQ3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dyxZQNYJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7EYw9Ggk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Wu2qpmqL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eWkdqJsZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JhVNDkjk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZkCVNFJj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3JXfrO37_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9Xuo8KpD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_5SkLQ7CY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Y2yjzhI6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FpOStlgm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_97FQZMPP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QkMOklh6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_o0MgnFlV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_YVcURIer_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LjjMg0wL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_SsUckaFx_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_xVQ7BMTi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_4AOlrAYk_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_7necLe9w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_INRtwHFr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ljhs0o5R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Xcd2jm0s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wjPIYRos_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kuJ0Hkl2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_7DuElKRU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_isBwYll6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_EX90xDhd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_7HZX0nrK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Mtw4gewD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Jb2417TT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fz6EPXrU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DFk3IcPU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Zu13asPO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eOGoq542_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xR03DItS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ym6fRlhk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cExpr_ZbAa0fze_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_l3bjyCOy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_jhlXEKnk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2vTiZ12Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_j5fIZbxQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_SAtkxD8X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_J3tJzPOL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_bFs19Zmf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_7kog7rFG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_t1qZ95Im_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_M3ec8UCa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xMVHVwa7_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_8EgUUrf2;
  SignalLine sLine_WUe70ZtI;
  SignalCPole sCPole_OIB0bhlr;
  SignalCPole sCPole_lDz5CpiA;
  ControlSlice cSlice_oZSgk1Os;
  ControlSlice cSlice_u9ofHdPn;
  ControlSlice cSlice_t2qPYfPc;
  ControlVar cVar_V27mdvbb;
  ControlIf cIf_sXEuzTS9;
  ControlBinop cBinop_gWXpM65M;
  ControlIf cIf_bpKD3EGL;
  ControlIf cIf_CMMHM19H;
  ControlIf cIf_Id2I314n;
  ControlIf cIf_7pN3myWB;
  ControlBinop cBinop_JArBJ3fa;
  ControlBinop cBinop_IenQiU4j;
  ControlBinop cBinop_KWVOSPpj;
  ControlBinop cBinop_XdjGtM65;
  ControlBinop cBinop_XwconTnF;
  ControlBinop cBinop_V3GJq1L4;
  ControlBinop cBinop_nW16h0iL;
  ControlBinop cBinop_GVgDij1M;
  SignalVarf sVarf_6Cjd9u7Y;
  ControlExpr cExpr_rdcOi8KB;
  static float cExpr_rdcOi8KB_evaluate(const float* args);
  ControlExpr cExpr_YjUnVMrk;
  static float cExpr_YjUnVMrk_evaluate(const float* args);
  SignalVarf sVarf_7e7KeGRT;
  SignalVarf sVarf_3t4nHor0;
  SignalVarf sVarf_EpO0Wdvl;
  ControlVar cVar_T20a6bZC;
  ControlVar cVar_Ghx8ZwSZ;
  ControlIf cIf_SgKgRelV;
  ControlBinop cBinop_FUfBPZgc;
  ControlBinop cBinop_XbatqCse;
  ControlBinop cBinop_avWMP43l;
  ControlBinop cBinop_1xYMV0ru;
  ControlBinop cBinop_kC2OVkVO;
  ControlBinop cBinop_AeUT2J1Z;
  SignalVarf sVarf_lmYjoFKO;
  SignalVarf sVarf_Ry21ZBv4;
  SignalVarf sVarf_yeg3zno8;
  SignalVarf sVarf_TOe6v1Ph;
  ControlVar cVar_Jsrpl2fy;
  ControlIf cIf_vkWW0COg;
  ControlBinop cBinop_CpVjitbW;
  ControlBinop cBinop_l39Qp5Yl;
  ControlBinop cBinop_zXgpfb4o;
  ControlBinop cBinop_dyxZQNYJ;
  ControlBinop cBinop_Wu2qpmqL;
  ControlBinop cBinop_eWkdqJsZ;
  SignalVarf sVarf_sINFgpne;
  SignalVarf sVarf_LXJyscWA;
  SignalVarf sVarf_DJKj7UD3;
  SignalVarf sVarf_3lsdJ72i;
  ControlVar cVar_9Xuo8KpD;
  ControlExpr cExpr_5SkLQ7CY;
  static float cExpr_5SkLQ7CY_evaluate(const float* args);
  ControlVar cVar_Y2yjzhI6;
  ControlVar cVar_FpOStlgm;
  ControlVar cVar_97FQZMPP;
  ControlVar cVar_QkMOklh6;
  ControlVar cVar_o0MgnFlV;
  ControlPack cPack_YVcURIer;
  ControlDelay cDelay_7necLe9w;
  ControlVar cVar_Xcd2jm0s;
  ControlVar cVar_wjPIYRos;
  ControlVar cVar_kuJ0Hkl2;
  ControlVar cVar_7DuElKRU;
  ControlExpr cExpr_isBwYll6;
  static float cExpr_isBwYll6_evaluate(const float* args);
  ControlExpr cExpr_EX90xDhd;
  static float cExpr_EX90xDhd_evaluate(const float* args);
  ControlExpr cExpr_7HZX0nrK;
  static float cExpr_7HZX0nrK_evaluate(const float* args);
  ControlVar cVar_eOGoq542;
  SignalVarf sVarf_PjqoedRN;
  ControlVar cVar_xR03DItS;
  ControlVar cVar_ym6fRlhk;
  ControlExpr cExpr_ZbAa0fze;
  static float cExpr_ZbAa0fze_evaluate(const float* args);
  SignalVarf sVarf_GRVRyUWq;
};

#endif // _HEAVY_CONTEXT_MONOSYNTH_HPP_
