/** Copyright (c) 2026 Charles Vestal. MIT License (LICENSE beside pdsaw.pd) */

#ifndef _HEAVY_CONTEXT_PDSAW_HPP_
#define _HEAVY_CONTEXT_PDSAW_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlBinop.h"
#include "HvControlIf.h"
#include "HvControlCast.h"
#include "HvControlSystem.h"
#include "HvSignalPhasor.h"
#include "HvSignalRPole.h"
#include "HvControlSlice.h"
#include "HvSignalDel1.h"
#include "HvControlUnop.h"
#include "HvSignalLine.h"
#include "HvMath.h"
#include "HvControlVar.h"
#include "HvSignalVar.h"

class Heavy_pdsaw : public HeavyContext {

 public:
  Heavy_pdsaw(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
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
  static void cSlice_RT6Upskq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Y6liGSej_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_PAOiRFGc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OmbvJTTr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_KlmUriPu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_vDryi49M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_R7aylFEw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_swoiU18B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_WuluvWqb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_I2bsS9A6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_cSUJM1uk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_QBlFntVT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XqxyEt8i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_58WvwtNX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_m9mS8Zw7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yZJerLcC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iAedzozj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vQOytrAP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9gPLIit9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4RPB315m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KQkBongo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tvuEXuiN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WUg7CJAs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_o1KE4RYF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OHDjy0cW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_qoneRSIx_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_H3A2MKlo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zT8hbv4N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8xs4yIkP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_736QBsE3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vYlylkXb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5dYzmTdb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wMEmmzz0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Et6B0XKT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cebT4lbx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AbMzgwTw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_C27IoRBp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YHqVgla7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_L5uX3rQo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ImoFNAjW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nr48BoXs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MP8q3PSl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Gi3YYEvn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_26uWWW6M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4WBFyqbM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZseAab8x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VbNMvKCM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7h0l5II5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_UTpsitm2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Hs0mB5ZV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_0npCX0bx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xkZW9lAl_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_guCbPqrs;
  SignalRPole sRPole_udMyNx3K;
  SignalRPole sRPole_rzGRXSFe;
  SignalLine sLine_ZoqHT2md;
  ControlSlice cSlice_RT6Upskq;
  ControlSlice cSlice_Y6liGSej;
  ControlSlice cSlice_PAOiRFGc;
  ControlVar cVar_OmbvJTTr;
  ControlIf cIf_R7aylFEw;
  ControlBinop cBinop_swoiU18B;
  ControlIf cIf_WuluvWqb;
  ControlIf cIf_I2bsS9A6;
  ControlIf cIf_cSUJM1uk;
  ControlIf cIf_QBlFntVT;
  ControlBinop cBinop_XqxyEt8i;
  ControlBinop cBinop_58WvwtNX;
  ControlBinop cBinop_m9mS8Zw7;
  ControlBinop cBinop_4RPB315m;
  ControlBinop cBinop_KQkBongo;
  ControlBinop cBinop_tvuEXuiN;
  ControlBinop cBinop_WUg7CJAs;
  ControlBinop cBinop_o1KE4RYF;
  ControlVar cVar_zT8hbv4N;
  ControlBinop cBinop_vYlylkXb;
  ControlBinop cBinop_5dYzmTdb;
  SignalVarf sVarf_5aZTuV5M;
  ControlBinop cBinop_Et6B0XKT;
  ControlBinop cBinop_cebT4lbx;
  ControlBinop cBinop_AbMzgwTw;
  SignalVarf sVarf_Ci638nhZ;
  ControlVar cVar_C27IoRBp;
  ControlBinop cBinop_ImoFNAjW;
  ControlBinop cBinop_nr48BoXs;
  SignalVarf sVarf_J485wQCY;
  ControlBinop cBinop_Gi3YYEvn;
  ControlBinop cBinop_26uWWW6M;
  ControlBinop cBinop_4WBFyqbM;
  SignalVarf sVarf_mckXmZxj;
  ControlBinop cBinop_VbNMvKCM;
  SignalVarf sVarf_yGtNQ2WB;
};

#endif // _HEAVY_CONTEXT_PDSAW_HPP_
