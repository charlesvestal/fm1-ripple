/** the author of nts-freqshift.pd */

#ifndef _HEAVY_CONTEXT_NTS_FREQSHIFT_HPP_
#define _HEAVY_CONTEXT_NTS_FREQSHIFT_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlSlice.h"
#include "HvMath.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvSignalBiquad.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"

class Heavy_nts_freqshift : public HeavyContext {

 public:
  Heavy_nts_freqshift(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_nts_freqshift();

  const char *getName() override { return "nts_freqshift"; }
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
  static void cSlice_bZhqi0mP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_jrH52Qz8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_IJTYeIpt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_s1A0NPvZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_cjzMq7I8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pnhv2bCn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xN2Fgd05_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oYjaAtCW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5jYG4Y1d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_WNaHUaOx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_pZNZK53u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_zLxFdLcq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_IYIGQdBL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_0jeOcKKx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cTmbyabo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_s7OVqjp3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vjKYOF7m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kaZ6xr0g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_TzZfBmor_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_UWO2gL4F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QKj6PHRG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_3S4OES8C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_BNfUDBRW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2Q9iBp5Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UUY0irHY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_icwYv6pc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UUnde6g4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_RJUYZ9Ss_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_9HLN1Hgu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_swnR4doZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_rUBU7lK8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_7w772y5A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ukf6nPBg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bw6TVQ1Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_A6EmdNyd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_v8mQDFGz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_GSFYjg7C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Jt3LKHkb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_LBJIbr7O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_LSgBMKO6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Hxa0Ng9c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WF9UfRRt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VxQx69rT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Gem3tZf5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bzJL3uGf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_TWiSjnGc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_KlCl36Y0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_azXFCZCx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_txBrQteg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_R7DPiv45_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DMfEWWtC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kBm5ZCE5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DV0ByXVs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cDWCZDfB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_jxZyYJY4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_F79Z15e2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Ijr2fYD0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_dOwjpLAh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_F3BtKyN7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_C00Ucj78_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CwDJI3Ok_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Xd94ZFaw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5RB9xwFr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lEtKgzNM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_mVRTy1KK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_vRzlAH26_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Fciew1cC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_1teNvYmV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Av8f2WdS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hXNZSBug_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZJJYW1vf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6eSJoMaC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_og7mOPbd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uLhbUs1i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Ae61MeSf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_goXDVYm7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_apelDefC_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalBiquad_k sBiquad_k_ywzj7Xg1;
  SignalBiquad_k sBiquad_k_QyuA3fxH;
  SignalBiquad_k sBiquad_k_3iuRBO9c;
  SignalBiquad_k sBiquad_k_TRAPOQGY;
  SignalPhasor sPhasor_QWgIEGyM;
  SignalBiquad_k sBiquad_k_8RgmhIA7;
  SignalBiquad_k sBiquad_k_NtRe0Rox;
  SignalBiquad_k sBiquad_k_JKXPGTh5;
  SignalBiquad_k sBiquad_k_T0TgcPr8;
  SignalPhasor sPhasor_XAHd6vle;
  ControlSlice cSlice_bZhqi0mP;
  ControlSlice cSlice_jrH52Qz8;
  ControlSlice cSlice_IJTYeIpt;
  ControlSlice cSlice_s1A0NPvZ;
  ControlSlice cSlice_cjzMq7I8;
  ControlVar cVar_pnhv2bCn;
  ControlVar cVar_xN2Fgd05;
  ControlBinop cBinop_oYjaAtCW;
  ControlBinop cBinop_5jYG4Y1d;
  ControlSlice cSlice_WNaHUaOx;
  ControlSlice cSlice_pZNZK53u;
  ControlSlice cSlice_zLxFdLcq;
  ControlSlice cSlice_IYIGQdBL;
  ControlSlice cSlice_0jeOcKKx;
  ControlVar cVar_cTmbyabo;
  ControlVar cVar_s7OVqjp3;
  ControlBinop cBinop_vjKYOF7m;
  ControlBinop cBinop_kaZ6xr0g;
  ControlSlice cSlice_TzZfBmor;
  ControlSlice cSlice_UWO2gL4F;
  ControlSlice cSlice_QKj6PHRG;
  ControlSlice cSlice_3S4OES8C;
  ControlSlice cSlice_BNfUDBRW;
  ControlVar cVar_2Q9iBp5Q;
  ControlVar cVar_UUY0irHY;
  ControlBinop cBinop_icwYv6pc;
  ControlBinop cBinop_UUnde6g4;
  ControlSlice cSlice_RJUYZ9Ss;
  ControlSlice cSlice_9HLN1Hgu;
  ControlSlice cSlice_swnR4doZ;
  ControlSlice cSlice_rUBU7lK8;
  ControlSlice cSlice_7w772y5A;
  ControlVar cVar_ukf6nPBg;
  ControlVar cVar_bw6TVQ1Y;
  ControlBinop cBinop_A6EmdNyd;
  ControlBinop cBinop_v8mQDFGz;
  SignalVarf sVarf_t8tUMDdn;
  ControlSlice cSlice_GSFYjg7C;
  ControlSlice cSlice_Jt3LKHkb;
  ControlSlice cSlice_LBJIbr7O;
  ControlSlice cSlice_LSgBMKO6;
  ControlSlice cSlice_Hxa0Ng9c;
  ControlVar cVar_WF9UfRRt;
  ControlVar cVar_VxQx69rT;
  ControlBinop cBinop_Gem3tZf5;
  ControlBinop cBinop_bzJL3uGf;
  ControlSlice cSlice_TWiSjnGc;
  ControlSlice cSlice_KlCl36Y0;
  ControlSlice cSlice_azXFCZCx;
  ControlSlice cSlice_txBrQteg;
  ControlSlice cSlice_R7DPiv45;
  ControlVar cVar_DMfEWWtC;
  ControlVar cVar_kBm5ZCE5;
  ControlBinop cBinop_DV0ByXVs;
  ControlBinop cBinop_cDWCZDfB;
  ControlSlice cSlice_jxZyYJY4;
  ControlSlice cSlice_F79Z15e2;
  ControlSlice cSlice_Ijr2fYD0;
  ControlSlice cSlice_dOwjpLAh;
  ControlSlice cSlice_F3BtKyN7;
  ControlVar cVar_C00Ucj78;
  ControlVar cVar_CwDJI3Ok;
  ControlBinop cBinop_Xd94ZFaw;
  ControlBinop cBinop_5RB9xwFr;
  ControlSlice cSlice_lEtKgzNM;
  ControlSlice cSlice_mVRTy1KK;
  ControlSlice cSlice_vRzlAH26;
  ControlSlice cSlice_Fciew1cC;
  ControlSlice cSlice_1teNvYmV;
  ControlVar cVar_Av8f2WdS;
  ControlVar cVar_hXNZSBug;
  ControlBinop cBinop_ZJJYW1vf;
  ControlBinop cBinop_6eSJoMaC;
  ControlBinop cBinop_og7mOPbd;
  ControlBinop cBinop_uLhbUs1i;
  SignalVarf sVarf_gUE2E8aC;
  SignalVarf sVarf_dFB291wQ;
  SignalVarf sVarf_eMmYjD6k;
  SignalVarf sVarf_erqTGmzm;
};

#endif // _HEAVY_CONTEXT_NTS_FREQSHIFT_HPP_
