/** the author of nts-reflection.pd */

#ifndef _HEAVY_CONTEXT_NTS_REFLECTION_HPP_
#define _HEAVY_CONTEXT_NTS_REFLECTION_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlBinop.h"
#include "HvMath.h"
#include "HvSignalTabread.h"
#include "HvControlSystem.h"
#include "HvTable.h"
#include "HvControlTabhead.h"
#include "HvSignalVar.h"
#include "HvControlVar.h"
#include "HvSignalTabwrite.h"
#include "HvControlDelay.h"
#include "HvControlCast.h"

class Heavy_nts_reflection : public HeavyContext {

 public:
  Heavy_nts_reflection(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_nts_reflection();

  const char *getName() override { return "nts_reflection"; }
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
        TIME_F = 0x2641F460, // time_f
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
  static void cMsg_GzGR0hTQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_50r1PvUj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_CDgOUJlx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_IN3cB1ZC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_IkqPQlCC_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_dDULJo4Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_iMCWv60V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aTyxI1QL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fG9Q0Dsg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zeo3sqvD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qUiJMUqT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Zcn4bRg0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_i0koMI4p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_Xxfj74pK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HAjtaeAR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_tvUG5Drq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RzdIH43R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_RhO0lECe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_SeHS9oXg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_MJ7usO4o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OqG9ux7d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LOAAeWmn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SwwJMHMC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GBkLgYVl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2V3Zu4E4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3HOuksD3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_m6bcpn9V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9ygWDP12_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1s9vcaDU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_b63Db5Xg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N1AyBnFC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_sOVfaX5y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tvjnWnwG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ABCdBGCM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_SHlizbOw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_zitiW3U0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_yq6IJ5CX_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_3V8OjkHD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_Q24sB4bV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ntwyNYKT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ayoORi0t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YzW1QcEt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hsCbErsm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_L6tjx917_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yahrYcDf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_OegdHhEr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DXZ8P4ys_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_mh1ZxYIi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JAKXAORa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_qNQlLZby_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_VV9ucoFY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_NvmUIKvR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dFA0m5kG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mbYIqlrf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AP8M8IT9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ZPRjRjuq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uvxAtlJc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ms1vgeJw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8OkNnqle_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bwyrueOk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_I9lGqv70_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_601WHUh0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Se0QPFw7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EUxZYIcv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KeCWvEji_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mkfvAq0K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9qEzvInH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gl56KMlz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3oIlPye6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_vniOq5KR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_jQHxbHHh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_GL5evOjQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabread sTabread_MJ7usO4o;
  SignalTabwrite sTabwrite_vCOQRffI;
  SignalTabread sTabread_NvmUIKvR;
  SignalTabwrite sTabwrite_VCRXSEiA;
  ControlDelay cDelay_CDgOUJlx;
  ControlDelay cDelay_IN3cB1ZC;
  ControlBinop cBinop_dDULJo4Q;
  HvTable hTable_iMCWv60V;
  ControlBinop cBinop_fG9Q0Dsg;
  ControlTabhead cTabhead_Xxfj74pK;
  ControlVar cVar_RzdIH43R;
  ControlDelay cDelay_RhO0lECe;
  ControlDelay cDelay_SeHS9oXg;
  ControlBinop cBinop_OqG9ux7d;
  ControlBinop cBinop_LOAAeWmn;
  ControlBinop cBinop_SwwJMHMC;
  ControlBinop cBinop_9ygWDP12;
  ControlBinop cBinop_b63Db5Xg;
  ControlBinop cBinop_N1AyBnFC;
  ControlDelay cDelay_SHlizbOw;
  ControlDelay cDelay_zitiW3U0;
  ControlBinop cBinop_3V8OjkHD;
  HvTable hTable_Q24sB4bV;
  ControlBinop cBinop_ayoORi0t;
  ControlTabhead cTabhead_OegdHhEr;
  ControlVar cVar_JAKXAORa;
  ControlDelay cDelay_qNQlLZby;
  ControlDelay cDelay_VV9ucoFY;
  ControlBinop cBinop_dFA0m5kG;
  ControlBinop cBinop_mbYIqlrf;
  ControlBinop cBinop_AP8M8IT9;
  ControlBinop cBinop_bwyrueOk;
  ControlBinop cBinop_601WHUh0;
  ControlBinop cBinop_Se0QPFw7;
  SignalVarf sVarf_XcpC9koR;
  ControlBinop cBinop_KeCWvEji;
  ControlBinop cBinop_mkfvAq0K;
  ControlBinop cBinop_9qEzvInH;
  SignalVarf sVarf_tvCu0ahS;
  ControlBinop cBinop_gl56KMlz;
  ControlBinop cBinop_3oIlPye6;
  SignalVarf sVarf_aO8kI9Dz;
  SignalVarf sVarf_kNqr9lLv;
};

#endif // _HEAVY_CONTEXT_NTS_REFLECTION_HPP_
