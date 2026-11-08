/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside reflect.pd) */

#ifndef _HEAVY_CONTEXT_REFLECT_HPP_
#define _HEAVY_CONTEXT_REFLECT_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalVar.h"
#include "HvTable.h"
#include "HvControlVar.h"
#include "HvMath.h"
#include "HvControlCast.h"
#include "HvSignalTabwrite.h"
#include "HvControlTabhead.h"
#include "HvControlSystem.h"
#include "HvSignalTabread.h"
#include "HvControlBinop.h"
#include "HvControlDelay.h"

class Heavy_reflect : public HeavyContext {

 public:
  Heavy_reflect(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_reflect();

  const char *getName() override { return "reflect"; }
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
  static void cMsg_xsNBlGLX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_qteLeH2U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_cCnSRbdW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_v9IZPozT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_9i19YwkP_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_Rrag31S4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_66jgqKgZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BvbdAkdR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VYSLDjwN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tKUoseZF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LPCyt0MW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d2jnvtBm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nPb1HV0c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_qJNOcvAl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UI7Z60Id_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_5dPS80GB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_H0QbYrbb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_5MbLQ0vX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_tUGGrsiM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_bl2921ZG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LArGsEb7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_T174yZbQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MBPF6ytc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_6cpI1mnk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_25EOKXy7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_q1OhkE59_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pb2ZfAwE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BSEjCCXM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XgcVYZrg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dXyEz0hf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0UwybGkK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wxaGobYI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hlUXffFI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_p79mnrBR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_qOZWO4ZG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_oQqL5CYR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_g90Yjqg1_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_3MD4oBYD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_zEKRvtAD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QiQn2Wf4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_td2lIas4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YubKG3a3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Ki0VwOqL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_o1vChPCP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_B7ohpcxJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_7CyomDbG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wPvbsbMN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_1A5yMyDC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_riT7a78F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_65xcPSSM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_PjPMr1Cg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_upGrkTHQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ebMVW1eR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_L10s4yeu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_shd96NkF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_CP0nTwT0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YxZWSCvB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6kxV2yuy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kV5ZrQEe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jBZJ9hcH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DhCUVrwf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_54RaJMuF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kKtZVEuI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HixgWfgi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_B9lGblG2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pO9qqVMr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kpzxbDdO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_in4xaLT9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_x2y1jGqE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_4CjtkUsL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_rhzyENv0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_qWlN63qA_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabread sTabread_bl2921ZG;
  SignalTabwrite sTabwrite_rVl1OaNE;
  SignalTabread sTabread_upGrkTHQ;
  SignalTabwrite sTabwrite_6L8j23fF;
  ControlDelay cDelay_cCnSRbdW;
  ControlDelay cDelay_v9IZPozT;
  ControlBinop cBinop_Rrag31S4;
  HvTable hTable_66jgqKgZ;
  ControlBinop cBinop_VYSLDjwN;
  ControlTabhead cTabhead_qJNOcvAl;
  ControlVar cVar_H0QbYrbb;
  ControlDelay cDelay_5MbLQ0vX;
  ControlDelay cDelay_tUGGrsiM;
  ControlBinop cBinop_LArGsEb7;
  ControlBinop cBinop_T174yZbQ;
  ControlBinop cBinop_MBPF6ytc;
  ControlBinop cBinop_BSEjCCXM;
  ControlBinop cBinop_dXyEz0hf;
  ControlBinop cBinop_0UwybGkK;
  ControlDelay cDelay_qOZWO4ZG;
  ControlDelay cDelay_oQqL5CYR;
  ControlBinop cBinop_3MD4oBYD;
  HvTable hTable_zEKRvtAD;
  ControlBinop cBinop_td2lIas4;
  ControlTabhead cTabhead_7CyomDbG;
  ControlVar cVar_riT7a78F;
  ControlDelay cDelay_65xcPSSM;
  ControlDelay cDelay_PjPMr1Cg;
  ControlBinop cBinop_ebMVW1eR;
  ControlBinop cBinop_L10s4yeu;
  ControlBinop cBinop_shd96NkF;
  ControlBinop cBinop_jBZJ9hcH;
  ControlBinop cBinop_54RaJMuF;
  ControlBinop cBinop_kKtZVEuI;
  SignalVarf sVarf_4nO9PoiJ;
  ControlBinop cBinop_B9lGblG2;
  ControlBinop cBinop_pO9qqVMr;
  ControlBinop cBinop_kpzxbDdO;
  SignalVarf sVarf_h7CjDwmw;
  ControlBinop cBinop_in4xaLT9;
  ControlBinop cBinop_x2y1jGqE;
  SignalVarf sVarf_8yHd491R;
  SignalVarf sVarf_nNZo6q2P;
};

#endif // _HEAVY_CONTEXT_REFLECT_HPP_
