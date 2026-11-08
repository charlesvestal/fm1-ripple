/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside nts-chorus.pd) */

#include "Heavy_nts_chorus.hpp"



#define Context(_c) static_cast<Heavy_nts_chorus *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_nts_chorus::Heavy_nts_chorus(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sTabwrite_init(&sTabwrite_3O6kPMlm, &hTable_C3kJa94z);
  numBytes += sTabwrite_init(&sTabwrite_J9M0rWhz, &hTable_Ifb9zaEr);
  numBytes += sPhasor_k_init(&sPhasor_bkGUy7O2, 0.0f, sampleRate);
  numBytes += sTabhead_init(&sTabhead_igx4cM1G, &hTable_Ifb9zaEr);
  numBytes += sTabread_init(&sTabread_7zb2d6dz, &hTable_Ifb9zaEr, false);
  numBytes += sTabread_init(&sTabread_cW2uhdnC, &hTable_Ifb9zaEr, false);
  numBytes += sTabhead_init(&sTabhead_j5D3RFKV, &hTable_C3kJa94z);
  numBytes += sTabread_init(&sTabread_rkxrJ1fP, &hTable_C3kJa94z, false);
  numBytes += sTabread_init(&sTabread_fMireAnV, &hTable_C3kJa94z, false);
  numBytes += cDelay_init(this, &cDelay_ggXmXIJn, 0.0f);
  numBytes += cDelay_init(this, &cDelay_idB8VENu, 0.0f);
  numBytes += hTable_init(&hTable_C3kJa94z, 256);
  numBytes += cDelay_init(this, &cDelay_6MkXZMvE, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WnLCmVNd, 0.0f);
  numBytes += hTable_init(&hTable_Ifb9zaEr, 256);
  numBytes += cVar_init_s(&cVar_bC5FwhnG, "del-buf_l");
  numBytes += sVarf_init(&sVarf_tNTm5Pkq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kHMQ1qdx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9GRCKvdW, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_CtmIrSqt, "del-buf_r");
  numBytes += sVarf_init(&sVarf_m26FMwph, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TT0QyzhS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_EdZ9yia7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nk1gRvrm, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iMXo8YAU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bOFg65zF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7SWPWEAy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uLwZyoEq, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_nts_chorus::~Heavy_nts_chorus() {
  hTable_free(&hTable_C3kJa94z);
  hTable_free(&hTable_Ifb9zaEr);
}

HvTable *Heavy_nts_chorus::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x9DAE02FD: return &hTable_C3kJa94z; // del-buf_l
    case 0xCF57129D: return &hTable_Ifb9zaEr; // del-buf_r
    default: return nullptr;
  }
}

void Heavy_nts_chorus::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aqsj0iwN_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AoXb4qIZ_sendMessage);
      break;
    }
    case 0x9F29F22: { // mix_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7i574q69_sendMessage);
      break;
    }
    case 0x2641F460: { // time_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8qOJkLkp_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_nts_chorus::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "depth_f";
        info->hash = 0xC21FE6A3;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.5f;
        info->maxVal = 1.5f;
        info->defaultVal = 1.0f;
        break;
      }
      case 1: {
        info->name = "mix_f";
        info->hash = 0x9F29F22;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 2: {
        info->name = "time_f";
        info->hash = 0x2641F460;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.1f;
        info->maxVal = 10.0f;
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
  return 3;
}



/*
 * Send Function Implementations
 */


void Heavy_nts_chorus::cMsg_oZRTBk7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1lBjZ55d_sendMessage);
}

void Heavy_nts_chorus::cSystem_1lBjZ55d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VwA4FP0b_sendMessage);
}

void Heavy_nts_chorus::cDelay_ggXmXIJn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ggXmXIJn, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_idB8VENu, 0, m, &cDelay_idB8VENu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ggXmXIJn, 0, m, &cDelay_ggXmXIJn_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_3O6kPMlm, 1, m, NULL);
}

void Heavy_nts_chorus::cDelay_idB8VENu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_idB8VENu, m);
  cMsg_TYX5iWH8_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::cSwitchcase_uiFcGUev_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_gU31FVro_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_nts_chorus::cBinop_Q2MjroYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zIvjN8hE_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::hTable_C3kJa94z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zCU4bAGL_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ggXmXIJn, 2, m, &cDelay_ggXmXIJn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0Ykmuio1_sendMessage);
}

void Heavy_nts_chorus::cMsg_zIvjN8hE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_C3kJa94z, 0, m, &hTable_C3kJa94z_sendMessage);
}

void Heavy_nts_chorus::cBinop_VwA4FP0b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_Q2MjroYO_sendMessage);
}

void Heavy_nts_chorus::cMsg_TYX5iWH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_C3kJa94z, 0, m, &hTable_C3kJa94z_sendMessage);
}

void Heavy_nts_chorus::cCast_0Ykmuio1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ggXmXIJn, 0, m, &cDelay_ggXmXIJn_sendMessage);
}

void Heavy_nts_chorus::cMsg_zCU4bAGL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_idB8VENu, 2, m, &cDelay_idB8VENu_sendMessage);
}

void Heavy_nts_chorus::cMsg_gU31FVro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_3O6kPMlm, 1, m, NULL);
}

void Heavy_nts_chorus::cMsg_EipAYeBW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6nYUWNku_sendMessage);
}

void Heavy_nts_chorus::cSystem_6nYUWNku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_tWUstddg_sendMessage);
}

void Heavy_nts_chorus::cDelay_6MkXZMvE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6MkXZMvE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WnLCmVNd, 0, m, &cDelay_WnLCmVNd_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6MkXZMvE, 0, m, &cDelay_6MkXZMvE_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_J9M0rWhz, 1, m, NULL);
}

void Heavy_nts_chorus::cDelay_WnLCmVNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WnLCmVNd, m);
  cMsg_P8d3yrrL_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::cSwitchcase_vu1P4Xw9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_9Fu8i2Rm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_nts_chorus::cBinop_l1wXzTUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BVmj1ALS_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::hTable_Ifb9zaEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LqfBd9eb_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6MkXZMvE, 2, m, &cDelay_6MkXZMvE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nUVIK96A_sendMessage);
}

void Heavy_nts_chorus::cMsg_BVmj1ALS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Ifb9zaEr, 0, m, &hTable_Ifb9zaEr_sendMessage);
}

void Heavy_nts_chorus::cBinop_tWUstddg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_l1wXzTUl_sendMessage);
}

void Heavy_nts_chorus::cMsg_P8d3yrrL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Ifb9zaEr, 0, m, &hTable_Ifb9zaEr_sendMessage);
}

void Heavy_nts_chorus::cCast_nUVIK96A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6MkXZMvE, 0, m, &cDelay_6MkXZMvE_sendMessage);
}

void Heavy_nts_chorus::cMsg_LqfBd9eb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_WnLCmVNd, 2, m, &cDelay_WnLCmVNd_sendMessage);
}

void Heavy_nts_chorus::cMsg_9Fu8i2Rm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_J9M0rWhz, 1, m, NULL);
}

void Heavy_nts_chorus::cMsg_faCFEuHo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1hXKHftC_sendMessage);
}

void Heavy_nts_chorus::cSystem_1hXKHftC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kpRhX27K_sendMessage);
}

void Heavy_nts_chorus::cVar_bC5FwhnG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oNa4XmvF_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::cSystem_FH0fepsC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HclFfg5m_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_tNTm5Pkq, m);
}

void Heavy_nts_chorus::cBinop_kpRhX27K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kHMQ1qdx, m);
}

void Heavy_nts_chorus::cMsg_oNa4XmvF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FH0fepsC_sendMessage);
}

void Heavy_nts_chorus::cBinop_HclFfg5m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9GRCKvdW, m);
}

void Heavy_nts_chorus::cMsg_nHDotYki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0MumP8B2_sendMessage);
}

void Heavy_nts_chorus::cSystem_0MumP8B2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HvqoPKdG_sendMessage);
}

void Heavy_nts_chorus::cVar_CtmIrSqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8g5DknP0_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::cSystem_xdGTqEQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mk0uJ8CM_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_m26FMwph, m);
}

void Heavy_nts_chorus::cBinop_HvqoPKdG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TT0QyzhS, m);
}

void Heavy_nts_chorus::cMsg_8g5DknP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xdGTqEQV_sendMessage);
}

void Heavy_nts_chorus::cBinop_mk0uJ8CM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EdZ9yia7, m);
}

void Heavy_nts_chorus::cBinop_WXoYLJti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_pPx0Xpjb_sendMessage);
}

void Heavy_nts_chorus::cBinop_pPx0Xpjb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bOFg65zF, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7SWPWEAy, m);
}

void Heavy_nts_chorus::cReceive_AoXb4qIZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nk1gRvrm, m);
}

void Heavy_nts_chorus::cReceive_8qOJkLkp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_bkGUy7O2, 0, m);
}

void Heavy_nts_chorus::cReceive_aqsj0iwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oZRTBk7V_sendMessage(_c, 0, m);
  cMsg_EipAYeBW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bC5FwhnG, 0, m, &cVar_bC5FwhnG_sendMessage);
  cMsg_faCFEuHo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CtmIrSqt, 0, m, &cVar_CtmIrSqt_sendMessage);
  cMsg_nHDotYki_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::cReceive_7i574q69_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WXoYLJti_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_iMXo8YAU, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_uLwZyoEq, m);
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

int Heavy_nts_chorus::process(float **inputBuffers, float **outputBuffers, int n) {
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5;
  hv_bufferi_t Bi0, Bi1;

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
    __hv_tabwrite_f(&sTabwrite_3O6kPMlm, VIf(I0));
    __hv_tabwrite_f(&sTabwrite_J9M0rWhz, VIf(I1));
    __hv_varread_f(&sVarf_7SWPWEAy, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_bkGUy7O2, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_nk1gRvrm, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_neg_f(VIf(Bf4), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_tabhead_f(&sTabhead_igx4cM1G, VOf(Bf2));
    __hv_var_k_f_r(VOf(Bf5), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_TT0QyzhS, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_EdZ9yia7, VOf(Bf1));
    __hv_min_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf5));
    __hv_varread_f(&sVarf_m26FMwph, VOf(Bf1));
    __hv_zero_f(VOf(Bf3));
    __hv_lt_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_7zb2d6dz, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_cW2uhdnC, VIi(Bi0), VOf(Bf1));
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf3));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_uLwZyoEq, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(I1), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O1), VOf(O1));
    __hv_var_k_f(VOf(Bf5), 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_tabhead_f(&sTabhead_j5D3RFKV, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf0), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_kHMQ1qdx, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_9GRCKvdW, VOf(Bf5));
    __hv_min_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf0));
    __hv_varread_f(&sVarf_tNTm5Pkq, VOf(Bf5));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_rkxrJ1fP, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_fMireAnV, VIi(Bi0), VOf(Bf5));
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf1));
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_iMXo8YAU, VOf(Bf0));
    __hv_varread_f(&sVarf_bOFg65zF, VOf(Bf1));
    __hv_mul_f(VIf(I0), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf5), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_nts_chorus::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_nts_chorus::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
