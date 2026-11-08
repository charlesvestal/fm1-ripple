/** the author of pdsaw.pd */

#ifndef _HEAVY_CONTEXT_PDSAW_HPP_
#define _HEAVY_CONTEXT_PDSAW_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalDel1.h"
#include "HvSignalPhasor.h"
#include "HvControlIf.h"
#include "HvControlCast.h"
#include "HvControlBinop.h"
#include "HvSignalRPole.h"
#include "HvMath.h"
#include "HvControlVar.h"
#include "HvControlSlice.h"
#include "HvControlSystem.h"
#include "HvSignalVar.h"
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
  static void cSlice_6ts2TWQP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_LIHhLfFw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_1PieBEOA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rouqzgNl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_wFh83myk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_RX3zFIet_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_8EZ6dlQX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oZuTFOW1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_qdliOQSo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_uOltA4t2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_gGxCmhCi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_K65KWu5Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fwyMJvl8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_U8vlP622_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gIoYqEwk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XrMmuR0d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_eU8HmpOG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wsCaaOX8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_t3G7m9DB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_n4Mihamw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iYshTINg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_L6D0Im5t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gK28eChs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_x3ZiWvbU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ygabFWoS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_RVynMHbo_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_mUh9j2P3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LGKQRo9N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_N9rqEHkY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_8Pczldhr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PMIjHNuy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OxTLnYx0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SNVe1NgZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cH2Hj7iD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BpiZluT1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3AAIuYT6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JgoiKODY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_i6M4FBiI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_vFrDGTJG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_poz37oSx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_neFivVI3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dKdYN1lv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wjB6IR1Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gv9S2ZjB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gXjMgidP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QrRXPwn8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5PgAcK2Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_V4nEmIlE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_6KFSZIXK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_6HliV4qE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_dBwbISsT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_0G3AU8Tl_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_74mfwU5F;
  SignalRPole sRPole_kyrghJRE;
  SignalRPole sRPole_04JfTES0;
  SignalLine sLine_fu3INTaL;
  ControlSlice cSlice_6ts2TWQP;
  ControlSlice cSlice_LIHhLfFw;
  ControlSlice cSlice_1PieBEOA;
  ControlVar cVar_rouqzgNl;
  ControlIf cIf_8EZ6dlQX;
  ControlBinop cBinop_oZuTFOW1;
  ControlIf cIf_qdliOQSo;
  ControlIf cIf_uOltA4t2;
  ControlIf cIf_gGxCmhCi;
  ControlIf cIf_K65KWu5Z;
  ControlBinop cBinop_fwyMJvl8;
  ControlBinop cBinop_U8vlP622;
  ControlBinop cBinop_gIoYqEwk;
  ControlBinop cBinop_n4Mihamw;
  ControlBinop cBinop_iYshTINg;
  ControlBinop cBinop_L6D0Im5t;
  ControlBinop cBinop_gK28eChs;
  ControlBinop cBinop_x3ZiWvbU;
  ControlVar cVar_LGKQRo9N;
  ControlBinop cBinop_PMIjHNuy;
  ControlBinop cBinop_OxTLnYx0;
  SignalVarf sVarf_PsqfOm6K;
  ControlBinop cBinop_cH2Hj7iD;
  ControlBinop cBinop_BpiZluT1;
  ControlBinop cBinop_3AAIuYT6;
  SignalVarf sVarf_rlwkaNKU;
  ControlVar cVar_JgoiKODY;
  ControlBinop cBinop_poz37oSx;
  ControlBinop cBinop_neFivVI3;
  SignalVarf sVarf_eLjvU0zo;
  ControlBinop cBinop_wjB6IR1Z;
  ControlBinop cBinop_gv9S2ZjB;
  ControlBinop cBinop_gXjMgidP;
  SignalVarf sVarf_miRAywdd;
  ControlBinop cBinop_5PgAcK2Q;
  SignalVarf sVarf_fjJv5Tsg;
};

#endif // _HEAVY_CONTEXT_PDSAW_HPP_
