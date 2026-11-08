/** the author of pdsaw.pd */

#ifndef _HEAVY_CONTEXT_PDSAW_HPP_
#define _HEAVY_CONTEXT_PDSAW_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalPhasor.h"
#include "HvSignalDel1.h"
#include "HvControlBinop.h"
#include "HvControlSlice.h"
#include "HvSignalRPole.h"
#include "HvControlSystem.h"
#include "HvSignalLine.h"
#include "HvControlCast.h"
#include "HvSignalVar.h"
#include "HvControlVar.h"
#include "HvControlUnop.h"
#include "HvControlIf.h"
#include "HvMath.h"

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
  static void cSlice_uSJgk3ih_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_0ahmVCwC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_cZWNwnW2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_tWJgUrqj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_WDOFl8p9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_qkoRWVDc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_APEk8FUZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7cvJZqLr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_FLsky6Jc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_CJkmkLg3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_XfmN9aMP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_k2I9Tfdv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wk5ZJiH6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jksMEaq5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bkgTalTT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UtfwcSkV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jNmAloBM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_l3Ed1OGr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fdlGnNVg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZaGDldiK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_K03Uc4rB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Pa0Y4mh8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nlBqciJy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hN40GhyP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sy8V58VJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_J3gKxGFx_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_S5iDpaa9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UoetIkJC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5JB6n7DV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_J4A6V2Ws_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XM5YqKq5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l1E8RUWn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tDoF2isr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mx8QDMHw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oHNEdx6B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RkGgJHBw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FQsR3S89_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_J7JnqAVK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_YVPFuWJc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PaOlwCpf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_24PX6mgp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_duhqyo8x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lx61Aq0g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NUEWS2ZH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Nf9YshWk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RszJCbIt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FOeSvlJn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wLmlbJgq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_NlDkoWgo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_jcLndLyb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xiOIabVT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_x43qbKDZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_e5ZtaeZ6;
  SignalRPole sRPole_9RcU99J0;
  SignalRPole sRPole_5F2vEGAc;
  SignalLine sLine_yCRNTHeS;
  ControlSlice cSlice_uSJgk3ih;
  ControlSlice cSlice_0ahmVCwC;
  ControlSlice cSlice_cZWNwnW2;
  ControlVar cVar_tWJgUrqj;
  ControlIf cIf_APEk8FUZ;
  ControlBinop cBinop_7cvJZqLr;
  ControlIf cIf_FLsky6Jc;
  ControlIf cIf_CJkmkLg3;
  ControlIf cIf_XfmN9aMP;
  ControlIf cIf_k2I9Tfdv;
  ControlBinop cBinop_wk5ZJiH6;
  ControlBinop cBinop_jksMEaq5;
  ControlBinop cBinop_bkgTalTT;
  ControlBinop cBinop_ZaGDldiK;
  ControlBinop cBinop_K03Uc4rB;
  ControlBinop cBinop_Pa0Y4mh8;
  ControlBinop cBinop_nlBqciJy;
  ControlBinop cBinop_hN40GhyP;
  ControlVar cVar_UoetIkJC;
  ControlBinop cBinop_XM5YqKq5;
  ControlBinop cBinop_l1E8RUWn;
  SignalVarf sVarf_hUo9bqls;
  ControlBinop cBinop_mx8QDMHw;
  ControlBinop cBinop_oHNEdx6B;
  ControlBinop cBinop_RkGgJHBw;
  SignalVarf sVarf_bNkVXFvz;
  ControlVar cVar_FQsR3S89;
  ControlBinop cBinop_PaOlwCpf;
  ControlBinop cBinop_24PX6mgp;
  SignalVarf sVarf_UWpm7yIp;
  ControlBinop cBinop_lx61Aq0g;
  ControlBinop cBinop_NUEWS2ZH;
  ControlBinop cBinop_Nf9YshWk;
  SignalVarf sVarf_9aJ7hQ3Y;
  ControlBinop cBinop_FOeSvlJn;
  SignalVarf sVarf_4csZpSDW;
};

#endif // _HEAVY_CONTEXT_PDSAW_HPP_
