/** Copyright (c) 2026 Charles Vestal. MIT License (LICENSE beside pdsaw.pd) */

#ifndef _HEAVY_CONTEXT_PDSAW_HPP_
#define _HEAVY_CONTEXT_PDSAW_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalVar.h"
#include "HvControlVar.h"
#include "HvSignalPhasor.h"
#include "HvMath.h"
#include "HvSignalRPole.h"
#include "HvControlCast.h"
#include "HvControlIf.h"
#include "HvSignalDel1.h"
#include "HvControlSystem.h"
#include "HvSignalLine.h"
#include "HvControlSlice.h"
#include "HvControlBinop.h"
#include "HvControlUnop.h"

class Heavy_pdsaw : public HeavyContext {

 public:
  Heavy_pdsaw(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_pdsaw();

  const char *getName() override { return "pdsaw"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        CUTOFF = 0xF89F9F3E, // cutoff
        VOLUME = 0xB1642755, // volume
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
  static void cSlice_kurZ5LwT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_VGXy8p8p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_iMgsV9qY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KberwbEf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_OnkRhI0m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_BUZxF642_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_vDvOqh4O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AKgLZB0F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_2tISY5AZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_XgIFNrYG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_nHQQI7fP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_jCgveRtn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bjGhTJLH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VNbvrdgS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sUjOLVIF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cFQBO6Jl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_b1fgwfEY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wdGOC9Wb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_C0QlzX9J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_a93dWYWn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DsWDWtrd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OguDciRa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YEQbjSge_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AkQc8Q05_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_im3qnviX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ZnH0svOp_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_c27KytTL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QgpFzdnK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NkP356fz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_SmXKohsH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jJco5vtj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zskrvCJ3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cb9SZNNr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aMDabU4t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qySxbF3l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wrsoQ4JB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_c0wEnanR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mLa2wGkT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ELeM7UDn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OxyRCc5C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YBsQ27J8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IoLtbZCU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Xb3e27XD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OQjFOpIA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_46VV0Cnp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xgI48XgM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vsvAn1Tv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VqhXJpDp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_rVtIpJDU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_aALCa4n2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_QGnEkZRr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_nb9uH864_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_Zz5day5C;
  SignalRPole sRPole_7rpj7Ehl;
  SignalRPole sRPole_MPeS2y1m;
  SignalLine sLine_h8K4lcro;
  ControlSlice cSlice_kurZ5LwT;
  ControlSlice cSlice_VGXy8p8p;
  ControlSlice cSlice_iMgsV9qY;
  ControlVar cVar_KberwbEf;
  ControlIf cIf_vDvOqh4O;
  ControlBinop cBinop_AKgLZB0F;
  ControlIf cIf_2tISY5AZ;
  ControlIf cIf_XgIFNrYG;
  ControlIf cIf_nHQQI7fP;
  ControlIf cIf_jCgveRtn;
  ControlBinop cBinop_bjGhTJLH;
  ControlBinop cBinop_VNbvrdgS;
  ControlBinop cBinop_sUjOLVIF;
  ControlBinop cBinop_a93dWYWn;
  ControlBinop cBinop_DsWDWtrd;
  ControlBinop cBinop_OguDciRa;
  ControlBinop cBinop_YEQbjSge;
  ControlBinop cBinop_AkQc8Q05;
  ControlVar cVar_QgpFzdnK;
  ControlBinop cBinop_jJco5vtj;
  ControlBinop cBinop_zskrvCJ3;
  SignalVarf sVarf_001UPHhx;
  ControlBinop cBinop_aMDabU4t;
  ControlBinop cBinop_qySxbF3l;
  ControlBinop cBinop_wrsoQ4JB;
  SignalVarf sVarf_S1o93s5c;
  ControlVar cVar_c0wEnanR;
  ControlBinop cBinop_OxyRCc5C;
  ControlBinop cBinop_YBsQ27J8;
  SignalVarf sVarf_J8BXJ3Lu;
  ControlBinop cBinop_Xb3e27XD;
  ControlBinop cBinop_OQjFOpIA;
  ControlBinop cBinop_46VV0Cnp;
  SignalVarf sVarf_qRiiELvQ;
  ControlBinop cBinop_vsvAn1Tv;
  SignalVarf sVarf_TNAPkP4g;
};

#endif // _HEAVY_CONTEXT_PDSAW_HPP_
