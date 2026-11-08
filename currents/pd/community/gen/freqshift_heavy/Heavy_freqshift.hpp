/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside freqshift.pd) */

#ifndef _HEAVY_CONTEXT_FREQSHIFT_HPP_
#define _HEAVY_CONTEXT_FREQSHIFT_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlBinop.h"
#include "HvSignalPhasor.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvControlVar.h"
#include "HvSignalBiquad.h"
#include "HvMath.h"

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
  static void cSlice_r25q1cR0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_CPSqF13l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_dShFd4rN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_5hW5y60O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_fk3vOadP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XZ9yNleI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ceLbVe6R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tqqIZk5x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xqSGwd3h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_BEg8xqdU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_2OMT3YMu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_MZYEqkO3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_PdZZZjuP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_dkuyVIKO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fIm89XSQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_L4tQ3qGq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SZ4AVSLG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kjgHvleF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_4LkVj1Wd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Dh1s5PuD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_gMCwuPoj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_6glajwhj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_0AU9jxOr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UWVHlhbr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9He9AfLG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PMxdwTNb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9vCOkNjt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_E7YOZRvf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_jGzRTzSr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_IoGVlplU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ShwMhAdX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_XIUhovYp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_syektQkD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zBWm38Bu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XnBx6ZOr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_b7wpxzK4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_7sIJFObY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lgFRgTpZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_cle9xVug_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Zuy7bcTo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_RktZSuyr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PtrJpHWx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OESrTpar_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FhJN1g6f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sRImc7b2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ssgqlAfo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_9VETvhN0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_kIiBQnPJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_bVffeGrB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YhmsGsWa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XQNCac4r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eI5nJSnY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_D087Vs5Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2Zt1jq0J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_0q7OWr4U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_JzYPO4Qf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_iKrCub8P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ZObwSnQZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_wM9zhlWH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_P9RxvqjJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5mOzxKNO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_o2UwhFph_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tGg5IKN1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_sPatcMi7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_C7rjMUGR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_tGrwLPHN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_CUgENnnI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_JPsA4SRs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vQ48dHur_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_n9JMVAzG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_p8ZrApLP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Wiuwu3ST_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UjpMSG7U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_STAlKAU6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_p3X08Hbv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_vBVJ3Rmb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xmifGTRf_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalBiquad_k sBiquad_k_kadZgCnI;
  SignalBiquad_k sBiquad_k_6TPO0D16;
  SignalBiquad_k sBiquad_k_t5Zc8EYE;
  SignalBiquad_k sBiquad_k_8NRfq78m;
  SignalPhasor sPhasor_R8EPtlmf;
  SignalBiquad_k sBiquad_k_VJSdvEVl;
  SignalBiquad_k sBiquad_k_tWKoS4rb;
  SignalBiquad_k sBiquad_k_RIgOvdLS;
  SignalBiquad_k sBiquad_k_POCe48tK;
  SignalPhasor sPhasor_FJI8fGvL;
  ControlSlice cSlice_r25q1cR0;
  ControlSlice cSlice_CPSqF13l;
  ControlSlice cSlice_dShFd4rN;
  ControlSlice cSlice_5hW5y60O;
  ControlSlice cSlice_fk3vOadP;
  ControlVar cVar_XZ9yNleI;
  ControlVar cVar_ceLbVe6R;
  ControlBinop cBinop_tqqIZk5x;
  ControlBinop cBinop_xqSGwd3h;
  ControlSlice cSlice_BEg8xqdU;
  ControlSlice cSlice_2OMT3YMu;
  ControlSlice cSlice_MZYEqkO3;
  ControlSlice cSlice_PdZZZjuP;
  ControlSlice cSlice_dkuyVIKO;
  ControlVar cVar_fIm89XSQ;
  ControlVar cVar_L4tQ3qGq;
  ControlBinop cBinop_SZ4AVSLG;
  ControlBinop cBinop_kjgHvleF;
  ControlSlice cSlice_4LkVj1Wd;
  ControlSlice cSlice_Dh1s5PuD;
  ControlSlice cSlice_gMCwuPoj;
  ControlSlice cSlice_6glajwhj;
  ControlSlice cSlice_0AU9jxOr;
  ControlVar cVar_UWVHlhbr;
  ControlVar cVar_9He9AfLG;
  ControlBinop cBinop_PMxdwTNb;
  ControlBinop cBinop_9vCOkNjt;
  ControlSlice cSlice_E7YOZRvf;
  ControlSlice cSlice_jGzRTzSr;
  ControlSlice cSlice_IoGVlplU;
  ControlSlice cSlice_ShwMhAdX;
  ControlSlice cSlice_XIUhovYp;
  ControlVar cVar_syektQkD;
  ControlVar cVar_zBWm38Bu;
  ControlBinop cBinop_XnBx6ZOr;
  ControlBinop cBinop_b7wpxzK4;
  SignalVarf sVarf_arQi4UQF;
  ControlSlice cSlice_7sIJFObY;
  ControlSlice cSlice_lgFRgTpZ;
  ControlSlice cSlice_cle9xVug;
  ControlSlice cSlice_Zuy7bcTo;
  ControlSlice cSlice_RktZSuyr;
  ControlVar cVar_PtrJpHWx;
  ControlVar cVar_OESrTpar;
  ControlBinop cBinop_FhJN1g6f;
  ControlBinop cBinop_sRImc7b2;
  ControlSlice cSlice_ssgqlAfo;
  ControlSlice cSlice_9VETvhN0;
  ControlSlice cSlice_kIiBQnPJ;
  ControlSlice cSlice_bVffeGrB;
  ControlSlice cSlice_YhmsGsWa;
  ControlVar cVar_XQNCac4r;
  ControlVar cVar_eI5nJSnY;
  ControlBinop cBinop_D087Vs5Q;
  ControlBinop cBinop_2Zt1jq0J;
  ControlSlice cSlice_0q7OWr4U;
  ControlSlice cSlice_JzYPO4Qf;
  ControlSlice cSlice_iKrCub8P;
  ControlSlice cSlice_ZObwSnQZ;
  ControlSlice cSlice_wM9zhlWH;
  ControlVar cVar_P9RxvqjJ;
  ControlVar cVar_5mOzxKNO;
  ControlBinop cBinop_o2UwhFph;
  ControlBinop cBinop_tGg5IKN1;
  ControlSlice cSlice_sPatcMi7;
  ControlSlice cSlice_C7rjMUGR;
  ControlSlice cSlice_tGrwLPHN;
  ControlSlice cSlice_CUgENnnI;
  ControlSlice cSlice_JPsA4SRs;
  ControlVar cVar_vQ48dHur;
  ControlVar cVar_n9JMVAzG;
  ControlBinop cBinop_p8ZrApLP;
  ControlBinop cBinop_Wiuwu3ST;
  ControlBinop cBinop_UjpMSG7U;
  ControlBinop cBinop_STAlKAU6;
  SignalVarf sVarf_tAmNwxuR;
  SignalVarf sVarf_7loLTHXH;
  SignalVarf sVarf_VYD2sAQ8;
  SignalVarf sVarf_uDGpoQjg;
};

#endif // _HEAVY_CONTEXT_FREQSHIFT_HPP_
