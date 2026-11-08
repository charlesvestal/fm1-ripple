/** the author of pdsaw.pd */

#ifndef _HEAVY_CONTEXT_PDSAW_HPP_
#define _HEAVY_CONTEXT_PDSAW_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvMath.h"
#include "HvControlBinop.h"
#include "HvControlCast.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalPhasor.h"
#include "HvSignalRPole.h"
#include "HvControlVar.h"
#include "HvSignalVar.h"
#include "HvSignalDel1.h"
#include "HvControlIf.h"
#include "HvControlUnop.h"
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
  static void cSlice_xLbtwR4Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_aQZQwOb7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_678CCVQL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Rh6D4HfK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_7XM23Onz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_moAXjNLX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_unrYsnsU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kM47NJU4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_mGHw4LtZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_yEDrA5lL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_kBgIBkJI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_N89A4T7g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HcwrDtPR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JYoxyqc8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UscDYobC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qjT8JhfR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MhgRPOho_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_C5w4U9z3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IdingQXa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GufctK9Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PdHklCR9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5GQIFCFZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ITJ6REiz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rVLoSt2i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iRp55xpE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Mb6E4V5w_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_IUNXhhLu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1e684rX4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_azDf0ghw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_RNtFCKlM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Tnr6TqRK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BFhOA3el_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3ZG1wpfF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BtJVmpQ0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IZq8qrjj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ceN3tRNe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QubDuo1a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lFDWZk1Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_LRCQYlYs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gGVxuMP3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fBfY80tT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZtZiWgEn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_11UCNVbC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3tQpqzrP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SRHR0rCN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_x1F8b14r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Uwupubm7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Mw2w1UwA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Na6NbkI6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_EO0bBHQe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_CzzTMzOO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xlbSCN1A_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_hbkzo038;
  SignalRPole sRPole_6Mg7fcL6;
  SignalRPole sRPole_5UvVHRTG;
  SignalLine sLine_b1rIhcf8;
  ControlSlice cSlice_xLbtwR4Z;
  ControlSlice cSlice_aQZQwOb7;
  ControlSlice cSlice_678CCVQL;
  ControlVar cVar_Rh6D4HfK;
  ControlIf cIf_unrYsnsU;
  ControlBinop cBinop_kM47NJU4;
  ControlIf cIf_mGHw4LtZ;
  ControlIf cIf_yEDrA5lL;
  ControlIf cIf_kBgIBkJI;
  ControlIf cIf_N89A4T7g;
  ControlBinop cBinop_HcwrDtPR;
  ControlBinop cBinop_JYoxyqc8;
  ControlBinop cBinop_UscDYobC;
  ControlBinop cBinop_GufctK9Y;
  ControlBinop cBinop_PdHklCR9;
  ControlBinop cBinop_5GQIFCFZ;
  ControlBinop cBinop_ITJ6REiz;
  ControlBinop cBinop_rVLoSt2i;
  ControlVar cVar_1e684rX4;
  ControlBinop cBinop_Tnr6TqRK;
  ControlBinop cBinop_BFhOA3el;
  SignalVarf sVarf_nQTzDnmp;
  ControlBinop cBinop_BtJVmpQ0;
  ControlBinop cBinop_IZq8qrjj;
  ControlBinop cBinop_ceN3tRNe;
  SignalVarf sVarf_fEeBzckf;
  ControlVar cVar_QubDuo1a;
  ControlBinop cBinop_gGVxuMP3;
  ControlBinop cBinop_fBfY80tT;
  SignalVarf sVarf_SfLb6SOZ;
  ControlBinop cBinop_11UCNVbC;
  ControlBinop cBinop_3tQpqzrP;
  ControlBinop cBinop_SRHR0rCN;
  SignalVarf sVarf_nrQtjUpO;
  ControlBinop cBinop_Uwupubm7;
  SignalVarf sVarf_sHDHWCMy;
};

#endif // _HEAVY_CONTEXT_PDSAW_HPP_
