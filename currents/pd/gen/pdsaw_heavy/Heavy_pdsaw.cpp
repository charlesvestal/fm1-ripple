/** the author of pdsaw.pd */

#include "Heavy_pdsaw.hpp"



#define Context(_c) static_cast<Heavy_pdsaw *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_pdsaw::Heavy_pdsaw(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_Ps70cSqA, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_lDFf1duD);
  numBytes += sRPole_init(&sRPole_PI2zDaLA);
  numBytes += sLine_init(&sLine_mFzLRumb);
  numBytes += cSlice_init(&cSlice_CNA0RwE0, 2, 1);
  numBytes += cSlice_init(&cSlice_dWtlai88, 1, 1);
  numBytes += cSlice_init(&cSlice_u9Jz7dGV, 0, 1);
  numBytes += cVar_init_f(&cVar_icpq3p2Q, 0.0f);
  numBytes += cIf_init(&cIf_EyRxz4Rm, false);
  numBytes += cIf_init(&cIf_t9jGN4Vu, false);
  numBytes += cIf_init(&cIf_hNZtUrKm, false);
  numBytes += cIf_init(&cIf_y2BVTxU9, false);
  numBytes += cIf_init(&cIf_SGtkvh49, false);
  numBytes += cBinop_init(&cBinop_2BE2w89S, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_5FgbUd85, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_yMRAvGhX, 22050.0f);
  numBytes += cBinop_init(&cBinop_dYMbzDG8, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_yl8fLFvC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_caor9Wn3, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_DDMKfEOA, 22050.0f);
  numBytes += cBinop_init(&cBinop_l3iCdQgp, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_dN0uU7RN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7YgJIA2A, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PRZNbI7Q, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_pdsaw::~Heavy_pdsaw() {
  // nothing to free
}

HvTable *Heavy_pdsaw::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_pdsaw::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zQLR41HP_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dpr45y4O_sendMessage);
      break;
    }
    case 0xF89F9F3E: { // cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Fl7WU8Yf_sendMessage);
      break;
    }
    case 0xB1642755: { // volume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FnJrGlJI_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_pdsaw::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "cutoff";
        info->hash = 0xF89F9F3E;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 100.0f;
        info->maxVal = 8000.0f;
        info->defaultVal = 1200.0f;
        break;
      }
      case 1: {
        info->name = "volume";
        info->hash = 0xB1642755;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
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


void Heavy_pdsaw::cSlice_CNA0RwE0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_pwW4hExW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_dWtlai88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_y2BVTxU9, 0, m, &cIf_y2BVTxU9_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_t9jGN4Vu, 0, m, &cIf_t9jGN4Vu_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_u9Jz7dGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_SGtkvh49, 0, m, &cIf_SGtkvh49_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_hNZtUrKm, 0, m, &cIf_hNZtUrKm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cVar_icpq3p2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_9f7jXoOF_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_EyRxz4Rm, 0, m, &cIf_EyRxz4Rm_sendMessage);
}

void Heavy_pdsaw::cUnop_kxyBJsHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_DgoWSpQt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2BE2w89S, HV_BINOP_EQ, 1, m, &cBinop_2BE2w89S_sendMessage);
}

void Heavy_pdsaw::cUnop_lOUEA0Ps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_DgoWSpQt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2BE2w89S, HV_BINOP_EQ, 1, m, &cBinop_2BE2w89S_sendMessage);
}

void Heavy_pdsaw::cIf_EyRxz4Rm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_lOUEA0Ps_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_kxyBJsHJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_9f7jXoOF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EyRxz4Rm, 1, m, &cIf_EyRxz4Rm_sendMessage);
}

void Heavy_pdsaw::cIf_t9jGN4Vu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_a9Ps8ato_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_hNZtUrKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_irGpwyO6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_y2BVTxU9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_a9Ps8ato_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_SGtkvh49_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_irGpwyO6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_pwW4hExW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2BE2w89S, HV_BINOP_EQ, 0, m, &cBinop_2BE2w89S_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_MYx2izks_sendMessage);
}

void Heavy_pdsaw::cBinop_DgoWSpQt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4dvg1aqp_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Jp1HSEGA_sendMessage);
}

void Heavy_pdsaw::cBinop_2BE2w89S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YwcsVuks_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cURJFNTL_sendMessage);
}

void Heavy_pdsaw::cCast_cURJFNTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SGtkvh49, 1, m, &cIf_SGtkvh49_sendMessage);
}

void Heavy_pdsaw::cCast_YwcsVuks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_t9jGN4Vu, 1, m, &cIf_t9jGN4Vu_sendMessage);
}

void Heavy_pdsaw::cCast_4dvg1aqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_y2BVTxU9, 1, m, &cIf_y2BVTxU9_sendMessage);
}

void Heavy_pdsaw::cCast_Jp1HSEGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hNZtUrKm, 1, m, &cIf_hNZtUrKm_sendMessage);
}

void Heavy_pdsaw::cBinop_MYx2izks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdsaw::cBinop_BX9RxXSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Ps70cSqA, 0, m);
}

void Heavy_pdsaw::cBinop_irGpwyO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_3hVsBK4b_sendMessage);
}

void Heavy_pdsaw::cBinop_3hVsBK4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5FgbUd85, HV_BINOP_POW, 1, m, &cBinop_5FgbUd85_sendMessage);
  cMsg_RTkcV7f8_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_5FgbUd85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_BX9RxXSe_sendMessage);
}

void Heavy_pdsaw::cMsg_RTkcV7f8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5FgbUd85, HV_BINOP_POW, 0, m, &cBinop_5FgbUd85_sendMessage);
}

void Heavy_pdsaw::cSwitchcase_a9Ps8ato_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OGvcTB1G_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_Fj86qnpp_sendMessage);
      break;
    }
  }
}

void Heavy_pdsaw::cCast_OGvcTB1G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ILEGyfHZ_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cVar_yMRAvGhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dYMbzDG8, HV_BINOP_MULTIPLY, 0, m, &cBinop_dYMbzDG8_sendMessage);
}

void Heavy_pdsaw::cMsg_tdnp7sA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_peeXX0e4_sendMessage);
}

void Heavy_pdsaw::cSystem_peeXX0e4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QXfn47IH_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_dYMbzDG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2TI3C5CS_sendMessage);
}

void Heavy_pdsaw::cBinop_MYFfCLzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dYMbzDG8, HV_BINOP_MULTIPLY, 1, m, &cBinop_dYMbzDG8_sendMessage);
}

void Heavy_pdsaw::cMsg_QXfn47IH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_MYFfCLzK_sendMessage);
}

void Heavy_pdsaw::cBinop_2TI3C5CS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_PHDNjrgm_sendMessage);
}

void Heavy_pdsaw::cBinop_PHDNjrgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Gz4FhqS3_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_caor9Wn3, m);
}

void Heavy_pdsaw::cBinop_Gz4FhqS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yl8fLFvC, m);
}

void Heavy_pdsaw::cVar_DDMKfEOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l3iCdQgp, HV_BINOP_MULTIPLY, 0, m, &cBinop_l3iCdQgp_sendMessage);
}

void Heavy_pdsaw::cMsg_7MkdQmnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_n7t5F4kx_sendMessage);
}

void Heavy_pdsaw::cSystem_n7t5F4kx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_B5m7JwIv_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_l3iCdQgp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_XeqgcyFI_sendMessage);
}

void Heavy_pdsaw::cBinop_4NJ9lwiO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l3iCdQgp, HV_BINOP_MULTIPLY, 1, m, &cBinop_l3iCdQgp_sendMessage);
}

void Heavy_pdsaw::cMsg_B5m7JwIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4NJ9lwiO_sendMessage);
}

void Heavy_pdsaw::cBinop_XeqgcyFI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ciBUnYp6_sendMessage);
}

void Heavy_pdsaw::cBinop_ciBUnYp6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Wch4Df2I_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7YgJIA2A, m);
}

void Heavy_pdsaw::cBinop_Wch4Df2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dN0uU7RN, m);
}

void Heavy_pdsaw::cMsg_ILEGyfHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 300.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mFzLRumb, 0, m, NULL);
}

void Heavy_pdsaw::cBinop_Fj86qnpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EfmLbh1x_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cMsg_EfmLbh1x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 5.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_mFzLRumb, 0, m, NULL);
}

void Heavy_pdsaw::cReceive_zQLR41HP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_icpq3p2Q, 0, m, &cVar_icpq3p2Q_sendMessage);
  cMsg_tdnp7sA3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yMRAvGhX, 0, m, &cVar_yMRAvGhX_sendMessage);
  cMsg_7MkdQmnz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DDMKfEOA, 0, m, &cVar_DDMKfEOA_sendMessage);
}

void Heavy_pdsaw::cReceive_dpr45y4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_CNA0RwE0, 0, m, &cSlice_CNA0RwE0_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_dWtlai88, 0, m, &cSlice_dWtlai88_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_u9Jz7dGV, 0, m, &cSlice_u9Jz7dGV_sendMessage);
}

void Heavy_pdsaw::cReceive_Fl7WU8Yf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yMRAvGhX, 0, m, &cVar_yMRAvGhX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DDMKfEOA, 0, m, &cVar_DDMKfEOA_sendMessage);
}

void Heavy_pdsaw::cReceive_FnJrGlJI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PRZNbI7Q, m);
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

int Heavy_pdsaw::process(float **inputBuffers, float **outputBuffers, int n) {
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
  hv_bufferf_t Bf0, Bf1;

  // input and output vars
  hv_bufferf_t O0, O1;

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

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_phasor_k_f(&sPhasor_Ps70cSqA, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_caor9Wn3, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_yl8fLFvC, VOf(Bf1));
    __hv_rpole_f(&sRPole_lDFf1duD, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_7YgJIA2A, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_dN0uU7RN, VOf(Bf1));
    __hv_rpole_f(&sRPole_PI2zDaLA, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_mFzLRumb, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_PRZNbI7Q, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_pdsaw::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_pdsaw::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

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
