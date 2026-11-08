/** Copyright (c) 2026 Charles Vestal. MIT License (LICENSE beside pdsaw.pd) */

#ifndef _HEAVY_CONTEXT_PDSAW_HPP_
#define _HEAVY_CONTEXT_PDSAW_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalLine.h"
#include "HvControlCast.h"
#include "HvControlIf.h"
#include "HvControlSlice.h"
#include "HvControlBinop.h"
#include "HvSignalRPole.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlUnop.h"
#include "HvMath.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvSignalDel1.h"

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
  static void cSlice_r11d2E0d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_NqRsfq73_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lZ2A2aCV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GNWsGOcI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_WthMU6wH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_uBYO7Tpt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_grW2zatO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dofg1Tt1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_jKRu109d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_BDAMpGhw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_sDrQ0XuD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_96Gc4Pdf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_saeofySJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_G1GPB1uL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sFsgJhow_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4fsanHnL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JEfsUdn8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TUiW7J6d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CqdGbaQ3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vG6ehvDL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6IhrZWN5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HeIBfiHo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9TNjpUdg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cMEZYxNi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aJhT9F3u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_JTyBeJhx_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_W3PkNhPb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_yYAp1Ssb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OOkMbAuM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Kwmu1KBx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KxxY9zbc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ep8qN2j1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PvYhsBZ5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6Ab3idV8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0IFi5AWL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Fn3pFOMV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5aBDZiNQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uUhRKJkG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_CEzhRsnU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ikO9GwnP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rcPfssei_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7GRDAQ0k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NAjMMR0S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ffF4Isfd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bEo2FZlO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_thVt3c6Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WEMgHAdn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sVDtY2Yj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_4yR2NfdB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_a1Gs5xET_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_JF76JLoQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_H7dFrlhh_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_Zjp1CKCJ;
  SignalRPole sRPole_vhqCX8XR;
  SignalRPole sRPole_S4YRptZA;
  SignalLine sLine_JnRORbN9;
  ControlSlice cSlice_r11d2E0d;
  ControlSlice cSlice_NqRsfq73;
  ControlSlice cSlice_lZ2A2aCV;
  ControlVar cVar_GNWsGOcI;
  ControlIf cIf_grW2zatO;
  ControlBinop cBinop_dofg1Tt1;
  ControlIf cIf_jKRu109d;
  ControlIf cIf_BDAMpGhw;
  ControlIf cIf_sDrQ0XuD;
  ControlIf cIf_96Gc4Pdf;
  ControlBinop cBinop_saeofySJ;
  ControlBinop cBinop_G1GPB1uL;
  ControlBinop cBinop_sFsgJhow;
  ControlBinop cBinop_vG6ehvDL;
  ControlBinop cBinop_6IhrZWN5;
  ControlBinop cBinop_HeIBfiHo;
  ControlBinop cBinop_9TNjpUdg;
  ControlBinop cBinop_cMEZYxNi;
  ControlVar cVar_yYAp1Ssb;
  ControlBinop cBinop_KxxY9zbc;
  ControlBinop cBinop_ep8qN2j1;
  SignalVarf sVarf_U2lbsruq;
  ControlBinop cBinop_6Ab3idV8;
  ControlBinop cBinop_0IFi5AWL;
  ControlBinop cBinop_Fn3pFOMV;
  SignalVarf sVarf_QwKsBRol;
  ControlVar cVar_5aBDZiNQ;
  ControlBinop cBinop_ikO9GwnP;
  ControlBinop cBinop_rcPfssei;
  SignalVarf sVarf_fTDH3Pfi;
  ControlBinop cBinop_NAjMMR0S;
  ControlBinop cBinop_ffF4Isfd;
  ControlBinop cBinop_bEo2FZlO;
  SignalVarf sVarf_fjoVNDUU;
  ControlBinop cBinop_WEMgHAdn;
  SignalVarf sVarf_hiXMwwtz;
};

#endif // _HEAVY_CONTEXT_PDSAW_HPP_
