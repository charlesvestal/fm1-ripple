/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside reflect.pd) */

#ifndef _HEAVY_CONTEXT_REFLECT_HPP_
#define _HEAVY_CONTEXT_REFLECT_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvMath.h"
#include "HvSignalVar.h"
#include "HvTable.h"
#include "HvControlSystem.h"
#include "HvControlVar.h"
#include "HvControlBinop.h"
#include "HvControlTabhead.h"
#include "HvSignalTabread.h"
#include "HvControlCast.h"
#include "HvControlDelay.h"
#include "HvSignalTabwrite.h"

class Heavy_reflect : public HeavyContext {

 public:
  Heavy_reflect(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
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
  static void cMsg_6inTDP6r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_7BvcLfxZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_bGBTbUPp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_rc3ZXUo4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_aXvnbcaP_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_anQ2dngO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_GoPyCGMw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jj8uCfu9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_V4IMVMR6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZQMsZH3Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_F5W4hNXT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Gl37TJAV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uGz3a4ZD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_1RpYWoRm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ds2QZXdg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_iQFi2hLu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KD6A1FFF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_y0kb2CmR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_CBvTdwIp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_iIhwhOlw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PYqkp6TO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BtFggTWx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4bQqfYHb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_vVf0z6Fk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xILb0C0U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xjvsTbVV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QMJxto7D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Vfew2xUg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TLg2bQaC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vCZH4WZH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZxCHosLr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XXSDaSp4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xc6X4DUm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Fm3Ke5TU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_BUj5hdZJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_yiinUXVR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_zhi6xTCS_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_uXOq1JBB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_81YWEENA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ix9GHDBU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nRZzhYON_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YBIRVlbm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Dzxv3ToL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Yd5g0ytZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xWlC7v6h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_BwLW4f0c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DgPF6KVT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_3OcUTGrl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_C4RvwzNk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_bGAHlwIp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_kD8cSJR8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_nUdDrSUF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CMsr0ljt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ksLAdPMm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rrX30TeD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_gJk5IYRH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4jDk8imT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TVerGwfQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_60hnsJkx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kvAaKLvx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1NkxY1y7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KnPkPE9p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_S1W1xEAk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fgdVZ1rb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EXE6cdyG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Y7bl7gvc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FiKtyZq8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WN67NWKQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jxtZtuA8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ItZ2gyFL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_VheR5vxb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_8KHxAtMF_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabread sTabread_iIhwhOlw;
  SignalTabwrite sTabwrite_BVXX5Jol;
  SignalTabread sTabread_nUdDrSUF;
  SignalTabwrite sTabwrite_ouZwnh1z;
  ControlDelay cDelay_bGBTbUPp;
  ControlDelay cDelay_rc3ZXUo4;
  ControlBinop cBinop_anQ2dngO;
  HvTable hTable_GoPyCGMw;
  ControlBinop cBinop_V4IMVMR6;
  ControlTabhead cTabhead_1RpYWoRm;
  ControlVar cVar_KD6A1FFF;
  ControlDelay cDelay_y0kb2CmR;
  ControlDelay cDelay_CBvTdwIp;
  ControlBinop cBinop_PYqkp6TO;
  ControlBinop cBinop_BtFggTWx;
  ControlBinop cBinop_4bQqfYHb;
  ControlBinop cBinop_Vfew2xUg;
  ControlBinop cBinop_vCZH4WZH;
  ControlBinop cBinop_ZxCHosLr;
  ControlDelay cDelay_BUj5hdZJ;
  ControlDelay cDelay_yiinUXVR;
  ControlBinop cBinop_uXOq1JBB;
  HvTable hTable_81YWEENA;
  ControlBinop cBinop_nRZzhYON;
  ControlTabhead cTabhead_BwLW4f0c;
  ControlVar cVar_C4RvwzNk;
  ControlDelay cDelay_bGAHlwIp;
  ControlDelay cDelay_kD8cSJR8;
  ControlBinop cBinop_CMsr0ljt;
  ControlBinop cBinop_ksLAdPMm;
  ControlBinop cBinop_rrX30TeD;
  ControlBinop cBinop_kvAaKLvx;
  ControlBinop cBinop_KnPkPE9p;
  ControlBinop cBinop_S1W1xEAk;
  SignalVarf sVarf_2TW69Q0B;
  ControlBinop cBinop_EXE6cdyG;
  ControlBinop cBinop_Y7bl7gvc;
  ControlBinop cBinop_FiKtyZq8;
  SignalVarf sVarf_0uj4OL39;
  ControlBinop cBinop_WN67NWKQ;
  ControlBinop cBinop_jxtZtuA8;
  SignalVarf sVarf_xepzYOK3;
  SignalVarf sVarf_VCqfNY6P;
};

#endif // _HEAVY_CONTEXT_REFLECT_HPP_
