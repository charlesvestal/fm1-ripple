/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside freqshift.pd) */

#ifndef _HEAVY_CONTEXT_FREQSHIFT_HPP_
#define _HEAVY_CONTEXT_FREQSHIFT_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvMath.h"
#include "HvControlVar.h"
#include "HvControlSlice.h"
#include "HvControlBinop.h"
#include "HvSignalBiquad.h"

class Heavy_freqshift : public HeavyContext {

 public:
  Heavy_freqshift(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
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
  static void cSlice_CYMNFGlb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Xg0Sz7eo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_7wncQWgG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_7mlnNh6b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_TFydbg6R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CQGdlzR3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NzFycy3X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qbTetwDV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_k3nmbSHa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_BsbykEJ6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_vJcehItf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_92ijvdbd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_dMibDz4w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_uiLqHToB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KBjocDGm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4OqmXlgO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XFvh9Py2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RBLqbgGn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_m3u83cGT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_uchwsE5O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_gZsQTqgr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_qpBrrlje_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_8ulHPYIJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_s3xgVZXm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_C1a6YCzy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0Bo0Ec1T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bR4Thgre_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_zlmB14qZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Vw694MY8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_OZtrOxrF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ivPdXMvx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_9v3F1FYX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UYtH1auU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_7jPvFdLa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_G5YWboRP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XquxuU0n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_DRmBACL9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_SO0BhNnP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_cLBAh6D4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_HUQ3J1QZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_KOiHu81v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9eMAuZpQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_B2yCYadg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4RuycSJN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_S0t0ZIUw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_gK7jYLLA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_K5RAseF4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_OzfhGqWg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_2iuGVjOs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_4SJhCcsz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bw5F9Qr6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LQifR4NG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9PSWJEiQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JoMSsDlV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_AJoGrI0y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_vru8YW5h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_EesByoug_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_XIvlWCS2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_sZIiNxGz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5dWFpbCW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_R9AvWlTo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FWO5EXY0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_STnRefMM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_zhunDcRj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_bXGFx9xh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_WMRg28MU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_CsTOL39N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_XGORuhvS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VUCksBQr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bLCfXhq1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vV8YFVS8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HTckYRWH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NVwQrcmu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_S7uWuEsP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_SBfpmykz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_VLnhe9Cm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_mWoyrMms_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalBiquad_k sBiquad_k_fZSJ31xI;
  SignalBiquad_k sBiquad_k_CHfnP3Zx;
  SignalBiquad_k sBiquad_k_dXxyG5sV;
  SignalBiquad_k sBiquad_k_nxigEjGf;
  SignalPhasor sPhasor_YZVwUc84;
  SignalBiquad_k sBiquad_k_lYb9AJGS;
  SignalBiquad_k sBiquad_k_CRMDgrrs;
  SignalBiquad_k sBiquad_k_EjjNmA5R;
  SignalBiquad_k sBiquad_k_xEkcGra0;
  SignalPhasor sPhasor_ebgmsahX;
  ControlSlice cSlice_CYMNFGlb;
  ControlSlice cSlice_Xg0Sz7eo;
  ControlSlice cSlice_7wncQWgG;
  ControlSlice cSlice_7mlnNh6b;
  ControlSlice cSlice_TFydbg6R;
  ControlVar cVar_CQGdlzR3;
  ControlVar cVar_NzFycy3X;
  ControlBinop cBinop_qbTetwDV;
  ControlBinop cBinop_k3nmbSHa;
  ControlSlice cSlice_BsbykEJ6;
  ControlSlice cSlice_vJcehItf;
  ControlSlice cSlice_92ijvdbd;
  ControlSlice cSlice_dMibDz4w;
  ControlSlice cSlice_uiLqHToB;
  ControlVar cVar_KBjocDGm;
  ControlVar cVar_4OqmXlgO;
  ControlBinop cBinop_XFvh9Py2;
  ControlBinop cBinop_RBLqbgGn;
  ControlSlice cSlice_m3u83cGT;
  ControlSlice cSlice_uchwsE5O;
  ControlSlice cSlice_gZsQTqgr;
  ControlSlice cSlice_qpBrrlje;
  ControlSlice cSlice_8ulHPYIJ;
  ControlVar cVar_s3xgVZXm;
  ControlVar cVar_C1a6YCzy;
  ControlBinop cBinop_0Bo0Ec1T;
  ControlBinop cBinop_bR4Thgre;
  ControlSlice cSlice_zlmB14qZ;
  ControlSlice cSlice_Vw694MY8;
  ControlSlice cSlice_OZtrOxrF;
  ControlSlice cSlice_ivPdXMvx;
  ControlSlice cSlice_9v3F1FYX;
  ControlVar cVar_UYtH1auU;
  ControlVar cVar_7jPvFdLa;
  ControlBinop cBinop_G5YWboRP;
  ControlBinop cBinop_XquxuU0n;
  SignalVarf sVarf_Z6BW2mjc;
  ControlSlice cSlice_DRmBACL9;
  ControlSlice cSlice_SO0BhNnP;
  ControlSlice cSlice_cLBAh6D4;
  ControlSlice cSlice_HUQ3J1QZ;
  ControlSlice cSlice_KOiHu81v;
  ControlVar cVar_9eMAuZpQ;
  ControlVar cVar_B2yCYadg;
  ControlBinop cBinop_4RuycSJN;
  ControlBinop cBinop_S0t0ZIUw;
  ControlSlice cSlice_gK7jYLLA;
  ControlSlice cSlice_K5RAseF4;
  ControlSlice cSlice_OzfhGqWg;
  ControlSlice cSlice_2iuGVjOs;
  ControlSlice cSlice_4SJhCcsz;
  ControlVar cVar_bw5F9Qr6;
  ControlVar cVar_LQifR4NG;
  ControlBinop cBinop_9PSWJEiQ;
  ControlBinop cBinop_JoMSsDlV;
  ControlSlice cSlice_AJoGrI0y;
  ControlSlice cSlice_vru8YW5h;
  ControlSlice cSlice_EesByoug;
  ControlSlice cSlice_XIvlWCS2;
  ControlSlice cSlice_sZIiNxGz;
  ControlVar cVar_5dWFpbCW;
  ControlVar cVar_R9AvWlTo;
  ControlBinop cBinop_FWO5EXY0;
  ControlBinop cBinop_STnRefMM;
  ControlSlice cSlice_zhunDcRj;
  ControlSlice cSlice_bXGFx9xh;
  ControlSlice cSlice_WMRg28MU;
  ControlSlice cSlice_CsTOL39N;
  ControlSlice cSlice_XGORuhvS;
  ControlVar cVar_VUCksBQr;
  ControlVar cVar_bLCfXhq1;
  ControlBinop cBinop_vV8YFVS8;
  ControlBinop cBinop_HTckYRWH;
  ControlBinop cBinop_NVwQrcmu;
  ControlBinop cBinop_S7uWuEsP;
  SignalVarf sVarf_WHo107Id;
  SignalVarf sVarf_GYhvWwgm;
  SignalVarf sVarf_aI27uwAB;
  SignalVarf sVarf_jnRSm4Gf;
};

#endif // _HEAVY_CONTEXT_FREQSHIFT_HPP_
