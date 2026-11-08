/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside freqshift.pd) */

#ifndef _HEAVY_CONTEXT_FREQSHIFT_HPP_
#define _HEAVY_CONTEXT_FREQSHIFT_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlBinop.h"
#include "HvControlSlice.h"
#include "HvMath.h"
#include "HvControlVar.h"
#include "HvSignalBiquad.h"
#include "HvSignalPhasor.h"
#include "HvSignalVar.h"

class Heavy_freqshift : public HeavyContext {

 public:
  Heavy_freqshift(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_freqshift();

  const char *getName() override { return "freqshift"; }
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
        TIME = 0x8E55AA5F, // time
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
  static void cSlice_s29zjYdM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_2MVAY46G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YsoWLOXN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ux8FB3os_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_UwRzoCdD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_7SJEtIlN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_7CFYpZTw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vYWQdik3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_X3JWPhDp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_FqYVGDrt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_5E1YkF22_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ThBhejfb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_FTRyoZZ9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_j6AFyAPw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rat4OGjp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Af3I3boE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jjAP933f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0k0ewJwY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_VP4lTpcK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_6fql86aN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_sMSUbM7v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_K7S8n7cA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_BeFYLVop_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1bxn0Cig_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Lh0miJPC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_T2TDVpzo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YsuIcerp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_fimcYnLy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_G1S40gRU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_UV2VnJu3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_p5AulvrM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_M6gpJKq9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8Ayeo02H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cyK03Y1g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EtsLDTIZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l7O0jCHZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QjwScnEw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_FMhyKYMy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_o7dUKdlV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_fHpgcRIG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_zVG06i74_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ScHjMtXq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bUWgLvhy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nNgwtwP0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_t5V4ZEPQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_0MEcjP2X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YFH3nK4e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_PnXp49RH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_uw8bClv9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_FxVJGpHL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OFmt0zc1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zV5dMW95_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9dqx8gNC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZB5nxb06_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lD2CieAr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_iB3b0uOz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lu3auprr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_NC5mLOsu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_SkBHFvLY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_H7jHPzWm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_j5xeYXlk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_B9M6mX69_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_S3iey3wI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QXbGPXDk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_3WZIgggw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_IizOEFv4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_mF9Wm7Qf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_r9ABpzBY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hfJ0sgZ9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kddeelKt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_W0ofody1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SxHjW2ic_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1or7h1DU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_78NXKufG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_b2DCgMIL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_GNjwU66S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_14hweeUJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalBiquad_k sBiquad_k_PI8WyTTG;
  SignalBiquad_k sBiquad_k_DjIi8Efl;
  SignalBiquad_k sBiquad_k_bi7p4TKC;
  SignalBiquad_k sBiquad_k_9tgxZ5x0;
  SignalPhasor sPhasor_AixPp99F;
  SignalBiquad_k sBiquad_k_htROYoEq;
  SignalBiquad_k sBiquad_k_n9hunAW9;
  SignalBiquad_k sBiquad_k_2AgFtKNy;
  SignalBiquad_k sBiquad_k_MlimPGtt;
  SignalPhasor sPhasor_587fIpGg;
  ControlSlice cSlice_s29zjYdM;
  ControlSlice cSlice_2MVAY46G;
  ControlSlice cSlice_YsoWLOXN;
  ControlSlice cSlice_ux8FB3os;
  ControlSlice cSlice_UwRzoCdD;
  ControlVar cVar_7SJEtIlN;
  ControlVar cVar_7CFYpZTw;
  ControlBinop cBinop_vYWQdik3;
  ControlBinop cBinop_X3JWPhDp;
  ControlSlice cSlice_FqYVGDrt;
  ControlSlice cSlice_5E1YkF22;
  ControlSlice cSlice_ThBhejfb;
  ControlSlice cSlice_FTRyoZZ9;
  ControlSlice cSlice_j6AFyAPw;
  ControlVar cVar_rat4OGjp;
  ControlVar cVar_Af3I3boE;
  ControlBinop cBinop_jjAP933f;
  ControlBinop cBinop_0k0ewJwY;
  ControlSlice cSlice_VP4lTpcK;
  ControlSlice cSlice_6fql86aN;
  ControlSlice cSlice_sMSUbM7v;
  ControlSlice cSlice_K7S8n7cA;
  ControlSlice cSlice_BeFYLVop;
  ControlVar cVar_1bxn0Cig;
  ControlVar cVar_Lh0miJPC;
  ControlBinop cBinop_T2TDVpzo;
  ControlBinop cBinop_YsuIcerp;
  ControlSlice cSlice_fimcYnLy;
  ControlSlice cSlice_G1S40gRU;
  ControlSlice cSlice_UV2VnJu3;
  ControlSlice cSlice_p5AulvrM;
  ControlSlice cSlice_M6gpJKq9;
  ControlVar cVar_8Ayeo02H;
  ControlVar cVar_cyK03Y1g;
  ControlBinop cBinop_EtsLDTIZ;
  ControlBinop cBinop_l7O0jCHZ;
  SignalVarf sVarf_OFGXdVLO;
  ControlSlice cSlice_QjwScnEw;
  ControlSlice cSlice_FMhyKYMy;
  ControlSlice cSlice_o7dUKdlV;
  ControlSlice cSlice_fHpgcRIG;
  ControlSlice cSlice_zVG06i74;
  ControlVar cVar_ScHjMtXq;
  ControlVar cVar_bUWgLvhy;
  ControlBinop cBinop_nNgwtwP0;
  ControlBinop cBinop_t5V4ZEPQ;
  ControlSlice cSlice_0MEcjP2X;
  ControlSlice cSlice_YFH3nK4e;
  ControlSlice cSlice_PnXp49RH;
  ControlSlice cSlice_uw8bClv9;
  ControlSlice cSlice_FxVJGpHL;
  ControlVar cVar_OFmt0zc1;
  ControlVar cVar_zV5dMW95;
  ControlBinop cBinop_9dqx8gNC;
  ControlBinop cBinop_ZB5nxb06;
  ControlSlice cSlice_lD2CieAr;
  ControlSlice cSlice_iB3b0uOz;
  ControlSlice cSlice_lu3auprr;
  ControlSlice cSlice_NC5mLOsu;
  ControlSlice cSlice_SkBHFvLY;
  ControlVar cVar_H7jHPzWm;
  ControlVar cVar_j5xeYXlk;
  ControlBinop cBinop_B9M6mX69;
  ControlBinop cBinop_S3iey3wI;
  ControlSlice cSlice_QXbGPXDk;
  ControlSlice cSlice_3WZIgggw;
  ControlSlice cSlice_IizOEFv4;
  ControlSlice cSlice_mF9Wm7Qf;
  ControlSlice cSlice_r9ABpzBY;
  ControlVar cVar_hfJ0sgZ9;
  ControlVar cVar_kddeelKt;
  ControlBinop cBinop_W0ofody1;
  ControlBinop cBinop_SxHjW2ic;
  ControlBinop cBinop_1or7h1DU;
  ControlBinop cBinop_78NXKufG;
  SignalVarf sVarf_d1Axcjpq;
  SignalVarf sVarf_1UI36q5t;
  SignalVarf sVarf_fT1uXdqF;
  SignalVarf sVarf_CaFL7IO3;
};

#endif // _HEAVY_CONTEXT_FREQSHIFT_HPP_
