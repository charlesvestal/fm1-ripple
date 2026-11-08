/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside nts-freqshift.pd) */

#ifndef _HEAVY_CONTEXT_NTS_FREQSHIFT_HPP_
#define _HEAVY_CONTEXT_NTS_FREQSHIFT_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalBiquad.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvMath.h"

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
  static void cSlice_Nb4D5rvB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ddMBSPbZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lkxve9MC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_dxCDknRI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YfA94Ufz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QgqZPISl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0SCyabZN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_z6DMK1nV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1wUCHN2B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_r7TDV1ii_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_nATP9oWE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_mMYjRHlV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_LCECQz3X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_5HTeJW53_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OoZSw6Ms_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2v9Vwapo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qGtsdvwL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_96nQAuor_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_NPEO9prd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_FNAXtUY9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_X4COlfDA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_auSo2k2R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_X1SIzFBC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_X9BEPEIo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bCwYTmDg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Nz5ehGtf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_O3FSydNl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_4fBR8bjT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Q8wedTBS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Z9yg7Dg8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_90GF9oho_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_7C3AfMTa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vAmzdQTa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OZFG91LE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Keu2DhEc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_q8zWav86_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_DDC8v9yO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_oqD9mQKj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_1QNORPG3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_a0a5FdlT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_2guNeVHx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Qpo76c8f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_7qGzdxGs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_j9rEIF1A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iDYkN5oa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_uDKP2t4J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QJBfLdHP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_yssTu6Tx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_dbA0aBnP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_EadvNix1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CaU3c4Kx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bkNNIheC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Bb4M9Lu6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9ea6Nbud_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ATtJ95Lp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_F8aEjz6t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_EoQWNzzh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_pVoY4zBR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_mcqMJANg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_R5uu7yfp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hQFyv6ad_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_x9dAyNRE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cKZLk2uB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_vs5glErs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ZVYup0Hq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Es6AEmhy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_MH1UtCUi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_3pQDp6Kb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_znJw9Jzn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_F8HGylRp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uPzELTtn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pqItlDFn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UmIbUvTo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vp3Lv5hQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_E1LPEUQ8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_NSEQEa3H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_RPWuUMfQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalBiquad_k sBiquad_k_sJnx0X7Y;
  SignalBiquad_k sBiquad_k_JjdgwOF3;
  SignalBiquad_k sBiquad_k_WFdT1cZe;
  SignalBiquad_k sBiquad_k_f06tMEAk;
  SignalPhasor sPhasor_Jzkx3nsi;
  SignalBiquad_k sBiquad_k_uYeKWmJx;
  SignalBiquad_k sBiquad_k_B8PLYauQ;
  SignalBiquad_k sBiquad_k_Y63xNEmJ;
  SignalBiquad_k sBiquad_k_efoMSPXF;
  SignalPhasor sPhasor_fkKQ6Gsv;
  ControlSlice cSlice_Nb4D5rvB;
  ControlSlice cSlice_ddMBSPbZ;
  ControlSlice cSlice_lkxve9MC;
  ControlSlice cSlice_dxCDknRI;
  ControlSlice cSlice_YfA94Ufz;
  ControlVar cVar_QgqZPISl;
  ControlVar cVar_0SCyabZN;
  ControlBinop cBinop_z6DMK1nV;
  ControlBinop cBinop_1wUCHN2B;
  ControlSlice cSlice_r7TDV1ii;
  ControlSlice cSlice_nATP9oWE;
  ControlSlice cSlice_mMYjRHlV;
  ControlSlice cSlice_LCECQz3X;
  ControlSlice cSlice_5HTeJW53;
  ControlVar cVar_OoZSw6Ms;
  ControlVar cVar_2v9Vwapo;
  ControlBinop cBinop_qGtsdvwL;
  ControlBinop cBinop_96nQAuor;
  ControlSlice cSlice_NPEO9prd;
  ControlSlice cSlice_FNAXtUY9;
  ControlSlice cSlice_X4COlfDA;
  ControlSlice cSlice_auSo2k2R;
  ControlSlice cSlice_X1SIzFBC;
  ControlVar cVar_X9BEPEIo;
  ControlVar cVar_bCwYTmDg;
  ControlBinop cBinop_Nz5ehGtf;
  ControlBinop cBinop_O3FSydNl;
  ControlSlice cSlice_4fBR8bjT;
  ControlSlice cSlice_Q8wedTBS;
  ControlSlice cSlice_Z9yg7Dg8;
  ControlSlice cSlice_90GF9oho;
  ControlSlice cSlice_7C3AfMTa;
  ControlVar cVar_vAmzdQTa;
  ControlVar cVar_OZFG91LE;
  ControlBinop cBinop_Keu2DhEc;
  ControlBinop cBinop_q8zWav86;
  SignalVarf sVarf_HM7y3vKJ;
  ControlSlice cSlice_DDC8v9yO;
  ControlSlice cSlice_oqD9mQKj;
  ControlSlice cSlice_1QNORPG3;
  ControlSlice cSlice_a0a5FdlT;
  ControlSlice cSlice_2guNeVHx;
  ControlVar cVar_Qpo76c8f;
  ControlVar cVar_7qGzdxGs;
  ControlBinop cBinop_j9rEIF1A;
  ControlBinop cBinop_iDYkN5oa;
  ControlSlice cSlice_uDKP2t4J;
  ControlSlice cSlice_QJBfLdHP;
  ControlSlice cSlice_yssTu6Tx;
  ControlSlice cSlice_dbA0aBnP;
  ControlSlice cSlice_EadvNix1;
  ControlVar cVar_CaU3c4Kx;
  ControlVar cVar_bkNNIheC;
  ControlBinop cBinop_Bb4M9Lu6;
  ControlBinop cBinop_9ea6Nbud;
  ControlSlice cSlice_ATtJ95Lp;
  ControlSlice cSlice_F8aEjz6t;
  ControlSlice cSlice_EoQWNzzh;
  ControlSlice cSlice_pVoY4zBR;
  ControlSlice cSlice_mcqMJANg;
  ControlVar cVar_R5uu7yfp;
  ControlVar cVar_hQFyv6ad;
  ControlBinop cBinop_x9dAyNRE;
  ControlBinop cBinop_cKZLk2uB;
  ControlSlice cSlice_vs5glErs;
  ControlSlice cSlice_ZVYup0Hq;
  ControlSlice cSlice_Es6AEmhy;
  ControlSlice cSlice_MH1UtCUi;
  ControlSlice cSlice_3pQDp6Kb;
  ControlVar cVar_znJw9Jzn;
  ControlVar cVar_F8HGylRp;
  ControlBinop cBinop_uPzELTtn;
  ControlBinop cBinop_pqItlDFn;
  ControlBinop cBinop_UmIbUvTo;
  ControlBinop cBinop_vp3Lv5hQ;
  SignalVarf sVarf_q1Y4gPN0;
  SignalVarf sVarf_5debQHz9;
  SignalVarf sVarf_6kuAU5RB;
  SignalVarf sVarf_2edGRDvs;
};

#endif // _HEAVY_CONTEXT_NTS_FREQSHIFT_HPP_
