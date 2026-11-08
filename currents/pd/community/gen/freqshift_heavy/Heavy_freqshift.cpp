/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside freqshift.pd) */

#include "Heavy_freqshift.hpp"



#define Context(_c) static_cast<Heavy_freqshift *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_freqshift::Heavy_freqshift(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sBiquad_k_init(&sBiquad_k_kadZgCnI, 0.94657f, -1.94632f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_6TPO0D16, 0.06338f, -0.83774f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_t5Zc8EYE, -0.260502f, 0.02569f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_8NRfq78m, 0.870686f, -1.8685f, 1.0f, 0.0f, 0.0f);
  numBytes += sPhasor_init(&sPhasor_R8EPtlmf, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_VJSdvEVl, 0.94657f, -1.94632f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_tWKoS4rb, 0.06338f, -0.83774f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_RIgOvdLS, -0.260502f, 0.02569f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_POCe48tK, 0.870686f, -1.8685f, 1.0f, 0.0f, 0.0f);
  numBytes += sPhasor_init(&sPhasor_FJI8fGvL, sampleRate);
  numBytes += cSlice_init(&cSlice_r25q1cR0, 0, 1);
  numBytes += cSlice_init(&cSlice_CPSqF13l, 1, 1);
  numBytes += cSlice_init(&cSlice_dShFd4rN, 2, 1);
  numBytes += cSlice_init(&cSlice_5hW5y60O, 3, 1);
  numBytes += cSlice_init(&cSlice_fk3vOadP, 4, 1);
  numBytes += cVar_init_f(&cVar_XZ9yNleI, 0.83774f);
  numBytes += cVar_init_f(&cVar_ceLbVe6R, -0.06338f);
  numBytes += cSlice_init(&cSlice_BEg8xqdU, 0, 1);
  numBytes += cSlice_init(&cSlice_2OMT3YMu, 1, 1);
  numBytes += cSlice_init(&cSlice_MZYEqkO3, 2, 1);
  numBytes += cSlice_init(&cSlice_PdZZZjuP, 3, 1);
  numBytes += cSlice_init(&cSlice_dkuyVIKO, 4, 1);
  numBytes += cVar_init_f(&cVar_fIm89XSQ, 1.94632f);
  numBytes += cVar_init_f(&cVar_L4tQ3qGq, -0.94657f);
  numBytes += cSlice_init(&cSlice_4LkVj1Wd, 0, 1);
  numBytes += cSlice_init(&cSlice_Dh1s5PuD, 1, 1);
  numBytes += cSlice_init(&cSlice_gMCwuPoj, 2, 1);
  numBytes += cSlice_init(&cSlice_6glajwhj, 3, 1);
  numBytes += cSlice_init(&cSlice_0AU9jxOr, 4, 1);
  numBytes += cVar_init_f(&cVar_UWVHlhbr, -0.02569f);
  numBytes += cVar_init_f(&cVar_9He9AfLG, 0.260502f);
  numBytes += cSlice_init(&cSlice_E7YOZRvf, 0, 1);
  numBytes += cSlice_init(&cSlice_jGzRTzSr, 1, 1);
  numBytes += cSlice_init(&cSlice_IoGVlplU, 2, 1);
  numBytes += cSlice_init(&cSlice_ShwMhAdX, 3, 1);
  numBytes += cSlice_init(&cSlice_XIUhovYp, 4, 1);
  numBytes += cVar_init_f(&cVar_syektQkD, 1.8685f);
  numBytes += cVar_init_f(&cVar_zBWm38Bu, -0.870686f);
  numBytes += sVarf_init(&sVarf_arQi4UQF, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_7sIJFObY, 0, 1);
  numBytes += cSlice_init(&cSlice_lgFRgTpZ, 1, 1);
  numBytes += cSlice_init(&cSlice_cle9xVug, 2, 1);
  numBytes += cSlice_init(&cSlice_Zuy7bcTo, 3, 1);
  numBytes += cSlice_init(&cSlice_RktZSuyr, 4, 1);
  numBytes += cVar_init_f(&cVar_PtrJpHWx, 0.83774f);
  numBytes += cVar_init_f(&cVar_OESrTpar, -0.06338f);
  numBytes += cSlice_init(&cSlice_ssgqlAfo, 0, 1);
  numBytes += cSlice_init(&cSlice_9VETvhN0, 1, 1);
  numBytes += cSlice_init(&cSlice_kIiBQnPJ, 2, 1);
  numBytes += cSlice_init(&cSlice_bVffeGrB, 3, 1);
  numBytes += cSlice_init(&cSlice_YhmsGsWa, 4, 1);
  numBytes += cVar_init_f(&cVar_XQNCac4r, 1.94632f);
  numBytes += cVar_init_f(&cVar_eI5nJSnY, -0.94657f);
  numBytes += cSlice_init(&cSlice_0q7OWr4U, 0, 1);
  numBytes += cSlice_init(&cSlice_JzYPO4Qf, 1, 1);
  numBytes += cSlice_init(&cSlice_iKrCub8P, 2, 1);
  numBytes += cSlice_init(&cSlice_ZObwSnQZ, 3, 1);
  numBytes += cSlice_init(&cSlice_wM9zhlWH, 4, 1);
  numBytes += cVar_init_f(&cVar_P9RxvqjJ, -0.02569f);
  numBytes += cVar_init_f(&cVar_5mOzxKNO, 0.260502f);
  numBytes += cSlice_init(&cSlice_sPatcMi7, 0, 1);
  numBytes += cSlice_init(&cSlice_C7rjMUGR, 1, 1);
  numBytes += cSlice_init(&cSlice_tGrwLPHN, 2, 1);
  numBytes += cSlice_init(&cSlice_CUgENnnI, 3, 1);
  numBytes += cSlice_init(&cSlice_JPsA4SRs, 4, 1);
  numBytes += cVar_init_f(&cVar_vQ48dHur, 1.8685f);
  numBytes += cVar_init_f(&cVar_n9JMVAzG, -0.870686f);
  numBytes += sVarf_init(&sVarf_tAmNwxuR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7loLTHXH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VYD2sAQ8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uDGpoQjg, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_p3X08Hbv_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vBVJ3Rmb_sendMessage);
      break;
    }
    case 0x8E55AA5F: { // time
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xmifGTRf_sendMessage);
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


void Heavy_freqshift::cSlice_r25q1cR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_tqqIZk5x_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_CPSqF13l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xqSGwd3h_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_dShFd4rN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_tWKoS4rb, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_5hW5y60O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_tWKoS4rb, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_fk3vOadP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_tWKoS4rb, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_XZ9yNleI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_tqqIZk5x_sendMessage);
}

void Heavy_freqshift::cVar_ceLbVe6R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xqSGwd3h_sendMessage);
}

void Heavy_freqshift::cBinop_tqqIZk5x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_tWKoS4rb, 4, m);
}

void Heavy_freqshift::cBinop_xqSGwd3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_tWKoS4rb, 5, m);
}

void Heavy_freqshift::cSlice_BEg8xqdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SZ4AVSLG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_2OMT3YMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kjgHvleF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_MZYEqkO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_VJSdvEVl, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_PdZZZjuP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_VJSdvEVl, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_dkuyVIKO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_VJSdvEVl, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_fIm89XSQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SZ4AVSLG_sendMessage);
}

void Heavy_freqshift::cVar_L4tQ3qGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kjgHvleF_sendMessage);
}

void Heavy_freqshift::cBinop_SZ4AVSLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_VJSdvEVl, 4, m);
}

void Heavy_freqshift::cBinop_kjgHvleF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_VJSdvEVl, 5, m);
}

void Heavy_freqshift::cSlice_4LkVj1Wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_PMxdwTNb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_Dh1s5PuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9vCOkNjt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_gMCwuPoj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_RIgOvdLS, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_6glajwhj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_RIgOvdLS, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_0AU9jxOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_RIgOvdLS, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_UWVHlhbr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_PMxdwTNb_sendMessage);
}

void Heavy_freqshift::cVar_9He9AfLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9vCOkNjt_sendMessage);
}

void Heavy_freqshift::cBinop_PMxdwTNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_RIgOvdLS, 4, m);
}

void Heavy_freqshift::cBinop_9vCOkNjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_RIgOvdLS, 5, m);
}

void Heavy_freqshift::cSlice_E7YOZRvf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XnBx6ZOr_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_jGzRTzSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_b7wpxzK4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_IoGVlplU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_POCe48tK, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_ShwMhAdX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_POCe48tK, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_XIUhovYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_POCe48tK, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_syektQkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XnBx6ZOr_sendMessage);
}

void Heavy_freqshift::cVar_zBWm38Bu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_b7wpxzK4_sendMessage);
}

void Heavy_freqshift::cBinop_XnBx6ZOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_POCe48tK, 4, m);
}

void Heavy_freqshift::cBinop_b7wpxzK4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_POCe48tK, 5, m);
}

void Heavy_freqshift::cSlice_7sIJFObY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FhJN1g6f_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_lgFRgTpZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_sRImc7b2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_cle9xVug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_6TPO0D16, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_Zuy7bcTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_6TPO0D16, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_RktZSuyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_6TPO0D16, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_PtrJpHWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FhJN1g6f_sendMessage);
}

void Heavy_freqshift::cVar_OESrTpar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_sRImc7b2_sendMessage);
}

void Heavy_freqshift::cBinop_FhJN1g6f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_6TPO0D16, 4, m);
}

void Heavy_freqshift::cBinop_sRImc7b2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_6TPO0D16, 5, m);
}

void Heavy_freqshift::cSlice_ssgqlAfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_D087Vs5Q_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_9VETvhN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2Zt1jq0J_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_kIiBQnPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_kadZgCnI, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_bVffeGrB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_kadZgCnI, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_YhmsGsWa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_kadZgCnI, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_XQNCac4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_D087Vs5Q_sendMessage);
}

void Heavy_freqshift::cVar_eI5nJSnY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2Zt1jq0J_sendMessage);
}

void Heavy_freqshift::cBinop_D087Vs5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_kadZgCnI, 4, m);
}

void Heavy_freqshift::cBinop_2Zt1jq0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_kadZgCnI, 5, m);
}

void Heavy_freqshift::cSlice_0q7OWr4U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_o2UwhFph_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_JzYPO4Qf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_tGg5IKN1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_iKrCub8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_t5Zc8EYE, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_ZObwSnQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_t5Zc8EYE, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_wM9zhlWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_t5Zc8EYE, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_P9RxvqjJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_o2UwhFph_sendMessage);
}

void Heavy_freqshift::cVar_5mOzxKNO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_tGg5IKN1_sendMessage);
}

void Heavy_freqshift::cBinop_o2UwhFph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_t5Zc8EYE, 4, m);
}

void Heavy_freqshift::cBinop_tGg5IKN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_t5Zc8EYE, 5, m);
}

void Heavy_freqshift::cSlice_sPatcMi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_p8ZrApLP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_C7rjMUGR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Wiuwu3ST_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_tGrwLPHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_8NRfq78m, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_CUgENnnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_8NRfq78m, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_JPsA4SRs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_8NRfq78m, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_vQ48dHur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_p8ZrApLP_sendMessage);
}

void Heavy_freqshift::cVar_n9JMVAzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Wiuwu3ST_sendMessage);
}

void Heavy_freqshift::cBinop_p8ZrApLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_8NRfq78m, 4, m);
}

void Heavy_freqshift::cBinop_Wiuwu3ST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_8NRfq78m, 5, m);
}

void Heavy_freqshift::cBinop_UjpMSG7U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_STAlKAU6_sendMessage);
}

void Heavy_freqshift::cBinop_STAlKAU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7loLTHXH, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VYD2sAQ8, m);
}

void Heavy_freqshift::cReceive_p3X08Hbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XZ9yNleI, 0, m, &cVar_XZ9yNleI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ceLbVe6R, 0, m, &cVar_ceLbVe6R_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fIm89XSQ, 0, m, &cVar_fIm89XSQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_L4tQ3qGq, 0, m, &cVar_L4tQ3qGq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UWVHlhbr, 0, m, &cVar_UWVHlhbr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9He9AfLG, 0, m, &cVar_9He9AfLG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_syektQkD, 0, m, &cVar_syektQkD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zBWm38Bu, 0, m, &cVar_zBWm38Bu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PtrJpHWx, 0, m, &cVar_PtrJpHWx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OESrTpar, 0, m, &cVar_OESrTpar_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XQNCac4r, 0, m, &cVar_XQNCac4r_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eI5nJSnY, 0, m, &cVar_eI5nJSnY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_P9RxvqjJ, 0, m, &cVar_P9RxvqjJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5mOzxKNO, 0, m, &cVar_5mOzxKNO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vQ48dHur, 0, m, &cVar_vQ48dHur_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_n9JMVAzG, 0, m, &cVar_n9JMVAzG_sendMessage);
}

void Heavy_freqshift::cReceive_vBVJ3Rmb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UjpMSG7U_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_tAmNwxuR, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_uDGpoQjg, m);
}

void Heavy_freqshift::cReceive_xmifGTRf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_arQi4UQF, m);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12;

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
    __hv_varread_f(&sVarf_VYD2sAQ8, VOf(Bf0));
    __hv_varread_f(&sVarf_arQi4UQF, VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_kadZgCnI, VIf(I1), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_6TPO0D16, VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_t5Zc8EYE, VIf(I1), VOf(Bf3));
    __hv_biquad_k_f(&sBiquad_k_8NRfq78m, VIf(Bf3), VOf(Bf3));
    __hv_phasor_f(&sPhasor_R8EPtlmf, VIf(Bf1), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf6));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf10), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf11), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf8), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf11), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf6), VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf4), VOf(Bf10));
    __hv_sub_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf10));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf10), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf10), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf8), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf5), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf12), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf10), VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_uDGpoQjg, VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(I1), VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf11), VIf(O1), VOf(O1));
    __hv_biquad_k_f(&sBiquad_k_VJSdvEVl, VIf(I0), VOf(Bf11));
    __hv_biquad_k_f(&sBiquad_k_tWKoS4rb, VIf(Bf11), VOf(Bf11));
    __hv_biquad_k_f(&sBiquad_k_RIgOvdLS, VIf(I0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_POCe48tK, VIf(Bf0), VOf(Bf0));
    __hv_phasor_f(&sPhasor_FJI8fGvL, VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_add_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf9), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf9), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf2), VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf1), VOf(Bf7));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf7), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf5), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf3), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf11), VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_tAmNwxuR, VOf(Bf9));
    __hv_varread_f(&sVarf_7loLTHXH, VOf(Bf11));
    __hv_mul_f(VIf(I0), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf11), VIf(O0), VOf(O0));

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
