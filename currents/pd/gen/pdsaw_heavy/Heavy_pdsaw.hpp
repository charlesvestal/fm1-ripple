/** the author of pdsaw.pd */

#ifndef _HEAVY_CONTEXT_PDSAW_HPP_
#define _HEAVY_CONTEXT_PDSAW_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlUnop.h"
#include "HvSignalDel1.h"
#include "HvControlSlice.h"
#include "HvSignalRPole.h"
#include "HvControlCast.h"
#include "HvControlBinop.h"
#include "HvControlSystem.h"
#include "HvControlIf.h"
#include "HvSignalPhasor.h"
#include "HvControlVar.h"
#include "HvSignalVar.h"
#include "HvMath.h"
#include "HvSignalLine.h"

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
  static void cSlice_CNA0RwE0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_dWtlai88_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_u9Jz7dGV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_icpq3p2Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_kxyBJsHJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_lOUEA0Ps_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_EyRxz4Rm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9f7jXoOF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_t9jGN4Vu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_hNZtUrKm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_y2BVTxU9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_SGtkvh49_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pwW4hExW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DgoWSpQt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2BE2w89S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cURJFNTL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_YwcsVuks_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4dvg1aqp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Jp1HSEGA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MYx2izks_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BX9RxXSe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_irGpwyO6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3hVsBK4b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5FgbUd85_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RTkcV7f8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_a9Ps8ato_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_OGvcTB1G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_yMRAvGhX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tdnp7sA3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_peeXX0e4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dYMbzDG8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MYFfCLzK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QXfn47IH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2TI3C5CS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PHDNjrgm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Gz4FhqS3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DDMKfEOA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7MkdQmnz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_n7t5F4kx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l3iCdQgp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4NJ9lwiO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_B5m7JwIv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XeqgcyFI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ciBUnYp6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Wch4Df2I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ILEGyfHZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Fj86qnpp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_EfmLbh1x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_zQLR41HP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_dpr45y4O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Fl7WU8Yf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_FnJrGlJI_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_Ps70cSqA;
  SignalRPole sRPole_lDFf1duD;
  SignalRPole sRPole_PI2zDaLA;
  SignalLine sLine_mFzLRumb;
  ControlSlice cSlice_CNA0RwE0;
  ControlSlice cSlice_dWtlai88;
  ControlSlice cSlice_u9Jz7dGV;
  ControlVar cVar_icpq3p2Q;
  ControlIf cIf_EyRxz4Rm;
  ControlBinop cBinop_9f7jXoOF;
  ControlIf cIf_t9jGN4Vu;
  ControlIf cIf_hNZtUrKm;
  ControlIf cIf_y2BVTxU9;
  ControlIf cIf_SGtkvh49;
  ControlBinop cBinop_pwW4hExW;
  ControlBinop cBinop_DgoWSpQt;
  ControlBinop cBinop_2BE2w89S;
  ControlBinop cBinop_MYx2izks;
  ControlBinop cBinop_BX9RxXSe;
  ControlBinop cBinop_irGpwyO6;
  ControlBinop cBinop_3hVsBK4b;
  ControlBinop cBinop_5FgbUd85;
  ControlVar cVar_yMRAvGhX;
  ControlBinop cBinop_dYMbzDG8;
  ControlBinop cBinop_MYFfCLzK;
  SignalVarf sVarf_yl8fLFvC;
  ControlBinop cBinop_2TI3C5CS;
  ControlBinop cBinop_PHDNjrgm;
  ControlBinop cBinop_Gz4FhqS3;
  SignalVarf sVarf_caor9Wn3;
  ControlVar cVar_DDMKfEOA;
  ControlBinop cBinop_l3iCdQgp;
  ControlBinop cBinop_4NJ9lwiO;
  SignalVarf sVarf_dN0uU7RN;
  ControlBinop cBinop_XeqgcyFI;
  ControlBinop cBinop_ciBUnYp6;
  ControlBinop cBinop_Wch4Df2I;
  SignalVarf sVarf_7YgJIA2A;
  ControlBinop cBinop_Fj86qnpp;
  SignalVarf sVarf_PRZNbI7Q;
};

#endif // _HEAVY_CONTEXT_PDSAW_HPP_
