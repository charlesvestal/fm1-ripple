/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside chorus.pd) */

#ifndef _HEAVY_CONTEXT_CHORUS_HPP_
#define _HEAVY_CONTEXT_CHORUS_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalTabwrite.h"
#include "HvMath.h"
#include "HvSignalTabread.h"
#include "HvControlVar.h"
#include "HvSignalPhasor.h"
#include "HvControlBinop.h"
#include "HvSignalVar.h"
#include "HvControlDelay.h"
#include "HvTable.h"
#include "HvControlSystem.h"
#include "HvControlCast.h"

class Heavy_chorus : public HeavyContext {

 public:
  Heavy_chorus(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_chorus();

  const char *getName() override { return "chorus"; }
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
        MIX_F = 0x9F29F22, // mix_f
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
  static void cMsg_9eqTFcmD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_w3Wcm5aE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_vaqs5T42_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_gNsvQACJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_aZ0KYhMf_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_20H23XcA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_o6VuhdY6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JHUPL7An_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CHu2CEUv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NXEm42kv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lkRBAZgl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FtOxhOku_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TQPInrSa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jq3jGK7Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Jrgt87Ce_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_NAY0hklO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_iFla15vg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_g9zmwk76_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_Yfgd2WZm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_raVZXFNk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_89Rn8sUL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oXO0SwJu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_A6gl8jhl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4cwxUqnj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ftil3U7Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_c4AqGhtw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aE2MKSBc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_r7aGPjq5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3DLgL8ck_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_5NpTUbXN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hcXxBQju_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3BPqVvm8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WrC0hfbV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dpDQJInm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_6YK1vwAv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Jhk5HsQV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Z2N6NMWY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Dx9WbNwa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zfOTblZe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tdNgoKLP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kUDT9yeh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sMRs7Xtg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Bfrh7ivb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_QvWCyv7V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_CIQ5E6YL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_UL6dgoS1_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabwrite sTabwrite_d0NYmXVU;
  SignalTabwrite sTabwrite_KCkzOZbD;
  SignalPhasor sPhasor_wwbiUeQs;
  SignalTabhead sTabhead_hULHxfBp;
  SignalTabread sTabread_hiNHK8LY;
  SignalTabread sTabread_f5Q8Caoz;
  SignalTabhead sTabhead_RKKxc77X;
  SignalTabread sTabread_Iv2oWmys;
  SignalTabread sTabread_o1Qm9nZ1;
  ControlDelay cDelay_vaqs5T42;
  ControlDelay cDelay_gNsvQACJ;
  ControlBinop cBinop_20H23XcA;
  HvTable hTable_o6VuhdY6;
  ControlBinop cBinop_CHu2CEUv;
  ControlDelay cDelay_NAY0hklO;
  ControlDelay cDelay_iFla15vg;
  ControlBinop cBinop_Yfgd2WZm;
  HvTable hTable_raVZXFNk;
  ControlBinop cBinop_oXO0SwJu;
  ControlVar cVar_3DLgL8ck;
  ControlBinop cBinop_hcXxBQju;
  ControlBinop cBinop_WrC0hfbV;
  SignalVarf sVarf_3kmO2G1I;
  SignalVarf sVarf_eUp4AQZA;
  SignalVarf sVarf_vmxj3paK;
  ControlVar cVar_Jhk5HsQV;
  ControlBinop cBinop_Dx9WbNwa;
  ControlBinop cBinop_tdNgoKLP;
  SignalVarf sVarf_xUpmugPx;
  SignalVarf sVarf_0IqNdN8A;
  SignalVarf sVarf_s1BmUlzu;
  ControlBinop cBinop_kUDT9yeh;
  ControlBinop cBinop_sMRs7Xtg;
  SignalVarf sVarf_h9ohSLfn;
  SignalVarf sVarf_X8BQm8Kh;
  SignalVarf sVarf_dmNrscD1;
  SignalVarf sVarf_5Cd1b4sf;
  SignalVarf sVarf_VUy9GEmW;
};

#endif // _HEAVY_CONTEXT_CHORUS_HPP_
