/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside freqshift.pd) */

#include "Heavy_freqshift.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_freqshift *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_freqshift_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_freqshift));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_freqshift(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_freqshift_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_freqshift));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_freqshift(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_freqshift_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_freqshift();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_freqshift::Heavy_freqshift(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sBiquad_k_init(&sBiquad_k_fZSJ31xI, 0.94657f, -1.94632f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_CHfnP3Zx, 0.06338f, -0.83774f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_dXxyG5sV, -0.260502f, 0.02569f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_nxigEjGf, 0.870686f, -1.8685f, 1.0f, 0.0f, 0.0f);
  numBytes += sPhasor_init(&sPhasor_YZVwUc84, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_lYb9AJGS, 0.94657f, -1.94632f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_CRMDgrrs, 0.06338f, -0.83774f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_EjjNmA5R, -0.260502f, 0.02569f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_xEkcGra0, 0.870686f, -1.8685f, 1.0f, 0.0f, 0.0f);
  numBytes += sPhasor_init(&sPhasor_ebgmsahX, sampleRate);
  numBytes += cSlice_init(&cSlice_CYMNFGlb, 0, 1);
  numBytes += cSlice_init(&cSlice_Xg0Sz7eo, 1, 1);
  numBytes += cSlice_init(&cSlice_7wncQWgG, 2, 1);
  numBytes += cSlice_init(&cSlice_7mlnNh6b, 3, 1);
  numBytes += cSlice_init(&cSlice_TFydbg6R, 4, 1);
  numBytes += cVar_init_f(&cVar_CQGdlzR3, 0.83774f);
  numBytes += cVar_init_f(&cVar_NzFycy3X, -0.06338f);
  numBytes += cSlice_init(&cSlice_BsbykEJ6, 0, 1);
  numBytes += cSlice_init(&cSlice_vJcehItf, 1, 1);
  numBytes += cSlice_init(&cSlice_92ijvdbd, 2, 1);
  numBytes += cSlice_init(&cSlice_dMibDz4w, 3, 1);
  numBytes += cSlice_init(&cSlice_uiLqHToB, 4, 1);
  numBytes += cVar_init_f(&cVar_KBjocDGm, 1.94632f);
  numBytes += cVar_init_f(&cVar_4OqmXlgO, -0.94657f);
  numBytes += cSlice_init(&cSlice_m3u83cGT, 0, 1);
  numBytes += cSlice_init(&cSlice_uchwsE5O, 1, 1);
  numBytes += cSlice_init(&cSlice_gZsQTqgr, 2, 1);
  numBytes += cSlice_init(&cSlice_qpBrrlje, 3, 1);
  numBytes += cSlice_init(&cSlice_8ulHPYIJ, 4, 1);
  numBytes += cVar_init_f(&cVar_s3xgVZXm, -0.02569f);
  numBytes += cVar_init_f(&cVar_C1a6YCzy, 0.260502f);
  numBytes += cSlice_init(&cSlice_zlmB14qZ, 0, 1);
  numBytes += cSlice_init(&cSlice_Vw694MY8, 1, 1);
  numBytes += cSlice_init(&cSlice_OZtrOxrF, 2, 1);
  numBytes += cSlice_init(&cSlice_ivPdXMvx, 3, 1);
  numBytes += cSlice_init(&cSlice_9v3F1FYX, 4, 1);
  numBytes += cVar_init_f(&cVar_UYtH1auU, 1.8685f);
  numBytes += cVar_init_f(&cVar_7jPvFdLa, -0.870686f);
  numBytes += sVarf_init(&sVarf_Z6BW2mjc, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_DRmBACL9, 0, 1);
  numBytes += cSlice_init(&cSlice_SO0BhNnP, 1, 1);
  numBytes += cSlice_init(&cSlice_cLBAh6D4, 2, 1);
  numBytes += cSlice_init(&cSlice_HUQ3J1QZ, 3, 1);
  numBytes += cSlice_init(&cSlice_KOiHu81v, 4, 1);
  numBytes += cVar_init_f(&cVar_9eMAuZpQ, 0.83774f);
  numBytes += cVar_init_f(&cVar_B2yCYadg, -0.06338f);
  numBytes += cSlice_init(&cSlice_gK7jYLLA, 0, 1);
  numBytes += cSlice_init(&cSlice_K5RAseF4, 1, 1);
  numBytes += cSlice_init(&cSlice_OzfhGqWg, 2, 1);
  numBytes += cSlice_init(&cSlice_2iuGVjOs, 3, 1);
  numBytes += cSlice_init(&cSlice_4SJhCcsz, 4, 1);
  numBytes += cVar_init_f(&cVar_bw5F9Qr6, 1.94632f);
  numBytes += cVar_init_f(&cVar_LQifR4NG, -0.94657f);
  numBytes += cSlice_init(&cSlice_AJoGrI0y, 0, 1);
  numBytes += cSlice_init(&cSlice_vru8YW5h, 1, 1);
  numBytes += cSlice_init(&cSlice_EesByoug, 2, 1);
  numBytes += cSlice_init(&cSlice_XIvlWCS2, 3, 1);
  numBytes += cSlice_init(&cSlice_sZIiNxGz, 4, 1);
  numBytes += cVar_init_f(&cVar_5dWFpbCW, -0.02569f);
  numBytes += cVar_init_f(&cVar_R9AvWlTo, 0.260502f);
  numBytes += cSlice_init(&cSlice_zhunDcRj, 0, 1);
  numBytes += cSlice_init(&cSlice_bXGFx9xh, 1, 1);
  numBytes += cSlice_init(&cSlice_WMRg28MU, 2, 1);
  numBytes += cSlice_init(&cSlice_CsTOL39N, 3, 1);
  numBytes += cSlice_init(&cSlice_XGORuhvS, 4, 1);
  numBytes += cVar_init_f(&cVar_VUCksBQr, 1.8685f);
  numBytes += cVar_init_f(&cVar_bLCfXhq1, -0.870686f);
  numBytes += sVarf_init(&sVarf_WHo107Id, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GYhvWwgm, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aI27uwAB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jnRSm4Gf, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_freqshift::~Heavy_freqshift() {
  // nothing to free
}

HvTable *Heavy_freqshift::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_freqshift::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SBfpmykz_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VLnhe9Cm_sendMessage);
      break;
    }
    case 0x8E55AA5F: { // time
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mWoyrMms_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_freqshift::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "depth_f";
        info->hash = 0xC21FE6A3;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 1.0f;
        break;
      }
      case 1: {
        info->name = "time";
        info->hash = 0x8E55AA5F;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -200.0f;
        info->maxVal = 200.0f;
        info->defaultVal = 100.0f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 2;
}



/*
 * Send Function Implementations
 */


void Heavy_freqshift::cSlice_CYMNFGlb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qbTetwDV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_Xg0Sz7eo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_k3nmbSHa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_7wncQWgG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_CHfnP3Zx, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_7mlnNh6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_CHfnP3Zx, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_TFydbg6R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_CHfnP3Zx, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_CQGdlzR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qbTetwDV_sendMessage);
}

void Heavy_freqshift::cVar_NzFycy3X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_k3nmbSHa_sendMessage);
}

void Heavy_freqshift::cBinop_qbTetwDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_CHfnP3Zx, 4, m);
}

void Heavy_freqshift::cBinop_k3nmbSHa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_CHfnP3Zx, 5, m);
}

void Heavy_freqshift::cSlice_BsbykEJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XFvh9Py2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_vJcehItf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RBLqbgGn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_92ijvdbd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_fZSJ31xI, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_dMibDz4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_fZSJ31xI, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_uiLqHToB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_fZSJ31xI, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_KBjocDGm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XFvh9Py2_sendMessage);
}

void Heavy_freqshift::cVar_4OqmXlgO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RBLqbgGn_sendMessage);
}

void Heavy_freqshift::cBinop_XFvh9Py2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_fZSJ31xI, 4, m);
}

void Heavy_freqshift::cBinop_RBLqbgGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_fZSJ31xI, 5, m);
}

void Heavy_freqshift::cSlice_m3u83cGT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0Bo0Ec1T_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_uchwsE5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bR4Thgre_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_gZsQTqgr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_dXxyG5sV, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_qpBrrlje_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_dXxyG5sV, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_8ulHPYIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_dXxyG5sV, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_s3xgVZXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0Bo0Ec1T_sendMessage);
}

void Heavy_freqshift::cVar_C1a6YCzy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bR4Thgre_sendMessage);
}

void Heavy_freqshift::cBinop_0Bo0Ec1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_dXxyG5sV, 4, m);
}

void Heavy_freqshift::cBinop_bR4Thgre_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_dXxyG5sV, 5, m);
}

void Heavy_freqshift::cSlice_zlmB14qZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_G5YWboRP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_Vw694MY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XquxuU0n_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_OZtrOxrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nxigEjGf, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_ivPdXMvx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nxigEjGf, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_9v3F1FYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nxigEjGf, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_UYtH1auU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_G5YWboRP_sendMessage);
}

void Heavy_freqshift::cVar_7jPvFdLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XquxuU0n_sendMessage);
}

void Heavy_freqshift::cBinop_G5YWboRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nxigEjGf, 4, m);
}

void Heavy_freqshift::cBinop_XquxuU0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nxigEjGf, 5, m);
}

void Heavy_freqshift::cSlice_DRmBACL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4RuycSJN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_SO0BhNnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_S0t0ZIUw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_cLBAh6D4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_CRMDgrrs, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_HUQ3J1QZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_CRMDgrrs, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_KOiHu81v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_CRMDgrrs, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_9eMAuZpQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4RuycSJN_sendMessage);
}

void Heavy_freqshift::cVar_B2yCYadg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_S0t0ZIUw_sendMessage);
}

void Heavy_freqshift::cBinop_4RuycSJN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_CRMDgrrs, 4, m);
}

void Heavy_freqshift::cBinop_S0t0ZIUw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_CRMDgrrs, 5, m);
}

void Heavy_freqshift::cSlice_gK7jYLLA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9PSWJEiQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_K5RAseF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JoMSsDlV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_OzfhGqWg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_lYb9AJGS, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_2iuGVjOs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_lYb9AJGS, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_4SJhCcsz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_lYb9AJGS, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_bw5F9Qr6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9PSWJEiQ_sendMessage);
}

void Heavy_freqshift::cVar_LQifR4NG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JoMSsDlV_sendMessage);
}

void Heavy_freqshift::cBinop_9PSWJEiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_lYb9AJGS, 4, m);
}

void Heavy_freqshift::cBinop_JoMSsDlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_lYb9AJGS, 5, m);
}

void Heavy_freqshift::cSlice_AJoGrI0y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FWO5EXY0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_vru8YW5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_STnRefMM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_EesByoug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_EjjNmA5R, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_XIvlWCS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_EjjNmA5R, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_sZIiNxGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_EjjNmA5R, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_5dWFpbCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FWO5EXY0_sendMessage);
}

void Heavy_freqshift::cVar_R9AvWlTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_STnRefMM_sendMessage);
}

void Heavy_freqshift::cBinop_FWO5EXY0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_EjjNmA5R, 4, m);
}

void Heavy_freqshift::cBinop_STnRefMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_EjjNmA5R, 5, m);
}

void Heavy_freqshift::cSlice_zhunDcRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vV8YFVS8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_bXGFx9xh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HTckYRWH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_WMRg28MU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_xEkcGra0, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_CsTOL39N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_xEkcGra0, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_XGORuhvS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_xEkcGra0, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_VUCksBQr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vV8YFVS8_sendMessage);
}

void Heavy_freqshift::cVar_bLCfXhq1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HTckYRWH_sendMessage);
}

void Heavy_freqshift::cBinop_vV8YFVS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_xEkcGra0, 4, m);
}

void Heavy_freqshift::cBinop_HTckYRWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_xEkcGra0, 5, m);
}

void Heavy_freqshift::cBinop_NVwQrcmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_S7uWuEsP_sendMessage);
}

void Heavy_freqshift::cBinop_S7uWuEsP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GYhvWwgm, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_aI27uwAB, m);
}

void Heavy_freqshift::cReceive_SBfpmykz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CQGdlzR3, 0, m, &cVar_CQGdlzR3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NzFycy3X, 0, m, &cVar_NzFycy3X_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KBjocDGm, 0, m, &cVar_KBjocDGm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4OqmXlgO, 0, m, &cVar_4OqmXlgO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_s3xgVZXm, 0, m, &cVar_s3xgVZXm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_C1a6YCzy, 0, m, &cVar_C1a6YCzy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UYtH1auU, 0, m, &cVar_UYtH1auU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7jPvFdLa, 0, m, &cVar_7jPvFdLa_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9eMAuZpQ, 0, m, &cVar_9eMAuZpQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_B2yCYadg, 0, m, &cVar_B2yCYadg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bw5F9Qr6, 0, m, &cVar_bw5F9Qr6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LQifR4NG, 0, m, &cVar_LQifR4NG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5dWFpbCW, 0, m, &cVar_5dWFpbCW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_R9AvWlTo, 0, m, &cVar_R9AvWlTo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VUCksBQr, 0, m, &cVar_VUCksBQr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bLCfXhq1, 0, m, &cVar_bLCfXhq1_sendMessage);
}

void Heavy_freqshift::cReceive_VLnhe9Cm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NVwQrcmu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WHo107Id, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jnRSm4Gf, m);
}

void Heavy_freqshift::cReceive_mWoyrMms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Z6BW2mjc, m);
}



/*
 * Code for expr~ implementation
 * Write out the generic implementation code
 */

 // per class code

 // per object code


/*
 * Context Process Implementation
 */

int Heavy_freqshift::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }

  sendBangToReceiver(0xDD21C0EB); // send to __hv_bang~ on next cycle
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11;

  // input and output vars
  hv_bufferf_t O0, O1;
  hv_bufferf_t I0, I1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    // load input buffers
    __hv_load_f(inputBuffers[0]+n, VOf(I0));
    __hv_load_f(inputBuffers[1]+n, VOf(I1));

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_varread_f(&sVarf_Z6BW2mjc, VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_fZSJ31xI, VIf(I0), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_CHfnP3Zx, VIf(Bf1), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_dXxyG5sV, VIf(I0), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_nxigEjGf, VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_YZVwUc84, VIf(Bf0), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_add_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf10), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf7), VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf3), VOf(Bf9));
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf4), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf11), VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf9), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_WHo107Id, VOf(Bf10));
    __hv_varread_f(&sVarf_GYhvWwgm, VOf(Bf1));
    __hv_mul_f(VIf(I0), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf4), VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_aI27uwAB, VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_lYb9AJGS, VIf(I1), VOf(Bf10));
    __hv_biquad_k_f(&sBiquad_k_CRMDgrrs, VIf(Bf10), VOf(Bf10));
    __hv_biquad_k_f(&sBiquad_k_EjjNmA5R, VIf(I1), VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_xEkcGra0, VIf(Bf4), VOf(Bf4));
    __hv_phasor_f(&sPhasor_ebgmsahX, VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf7));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf11), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf3), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf7), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf0), VOf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf11));
    __hv_mul_f(VIf(Bf0), VIf(Bf11), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf6), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf2), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf11), VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf10), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_jnRSm4Gf, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(I1), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_freqshift::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s)
  float **const bIn = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bIn[0] = inputBuffers+(0*n4);
  bIn[1] = inputBuffers+(1*n4);

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_freqshift::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s), uninterleave
  float *const bIn = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));
  #if HV_SIMD_SSE || HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 a = _mm_load_ps(inputBuffers+i);                // LRLR
    __m128 b = _mm_load_ps(inputBuffers+4+i);              // LRLR
    __m128 x = _mm_shuffle_ps(a, b, _MM_SHUFFLE(2,0,2,0)); // LLLL
    __m128 y = _mm_shuffle_ps(a, b, _MM_SHUFFLE(3,1,3,1)); // RRRR
    _mm_store_ps(bIn+j, x);
    _mm_store_ps(bIn+n4+j, y);
  }
  #elif HV_SIMD_NEON
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4x2_t a = vld2q_f32(inputBuffers+i); // load and uninterleave
    vst1q_f32(bIn+j, a.val[0]);
    vst1q_f32(bIn+n4+j, a.val[1]);
  }
  #else // HV_SIMD_NONE
  for (int j = 0; j < n4; ++j) {
    bIn[0*n4+j] = inputBuffers[0+2*j];
    bIn[1*n4+j] = inputBuffers[1+2*j];
  }
  #endif

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
