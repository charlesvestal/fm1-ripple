/** the author of nts-chorus.pd */

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
  numBytes += sTabwrite_init(&sTabwrite_UfIRWYTX, &hTable_dXT0v5Af);
  numBytes += sTabwrite_init(&sTabwrite_L2sr42Lx, &hTable_Xd8x58aY);
  numBytes += sPhasor_k_init(&sPhasor_aMzpJjmz, 0.0f, sampleRate);
  numBytes += sTabhead_init(&sTabhead_163MHuNq, &hTable_Xd8x58aY);
  numBytes += sTabread_init(&sTabread_Gzs5rxwM, &hTable_Xd8x58aY, false);
  numBytes += sTabread_init(&sTabread_fSKuo8dk, &hTable_Xd8x58aY, false);
  numBytes += sTabhead_init(&sTabhead_9nKR2OhA, &hTable_dXT0v5Af);
  numBytes += sTabread_init(&sTabread_SwtpMxwW, &hTable_dXT0v5Af, false);
  numBytes += sTabread_init(&sTabread_IddX9U7L, &hTable_dXT0v5Af, false);
  numBytes += cDelay_init(this, &cDelay_ALD3bT84, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kRMZh3i9, 0.0f);
  numBytes += hTable_init(&hTable_dXT0v5Af, 256);
  numBytes += cDelay_init(this, &cDelay_bAml0Skd, 0.0f);
  numBytes += cDelay_init(this, &cDelay_a0YZKzOP, 0.0f);
  numBytes += hTable_init(&hTable_Xd8x58aY, 256);
  numBytes += cVar_init_s(&cVar_QK0fVjoa, "del-buf_l");
  numBytes += sVarf_init(&sVarf_vgoWK4Kp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_piamRIKX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RIN8o1lV, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_Hp0ES4UV, "del-buf_r");
  numBytes += sVarf_init(&sVarf_6PdNy3Pd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HQl0lMtO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8X2PpgF2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NLRWghvV, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_V2QYzpE3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ebRhpbzN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cwdAxBkr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lqZGAeVX, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_nts_chorus::~Heavy_nts_chorus() {
  hTable_free(&hTable_dXT0v5Af);
  hTable_free(&hTable_Xd8x58aY);
}

HvTable *Heavy_nts_chorus::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x9DAE02FD: return &hTable_dXT0v5Af; // del-buf_l
    case 0xCF57129D: return &hTable_Xd8x58aY; // del-buf_r
    default: return nullptr;
  }
}

void Heavy_nts_chorus::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cgJ7kCQX_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_R1VK8b5D_sendMessage);
      break;
    }
    case 0x9F29F22: { // mix_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7Wfaclik_sendMessage);
      break;
    }
    case 0x2641F460: { // time_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7ogfGaDd_sendMessage);
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


void Heavy_nts_chorus::cMsg_sws0eKGb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tcT0o7M0_sendMessage);
}

void Heavy_nts_chorus::cSystem_tcT0o7M0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JIm3o9se_sendMessage);
}

void Heavy_nts_chorus::cDelay_ALD3bT84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ALD3bT84, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kRMZh3i9, 0, m, &cDelay_kRMZh3i9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ALD3bT84, 0, m, &cDelay_ALD3bT84_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_UfIRWYTX, 1, m, NULL);
}

void Heavy_nts_chorus::cDelay_kRMZh3i9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kRMZh3i9, m);
  cMsg_pXPJgMTO_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::cSwitchcase_pVMbvEyo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_PCJaPEte_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_nts_chorus::cBinop_7hSHLEap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wsAhU6df_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::hTable_dXT0v5Af_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oGT4ZE7e_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ALD3bT84, 2, m, &cDelay_ALD3bT84_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_t6LQIO19_sendMessage);
}

void Heavy_nts_chorus::cMsg_wsAhU6df_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_dXT0v5Af, 0, m, &hTable_dXT0v5Af_sendMessage);
}

void Heavy_nts_chorus::cBinop_JIm3o9se_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_7hSHLEap_sendMessage);
}

void Heavy_nts_chorus::cMsg_pXPJgMTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_dXT0v5Af, 0, m, &hTable_dXT0v5Af_sendMessage);
}

void Heavy_nts_chorus::cCast_t6LQIO19_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ALD3bT84, 0, m, &cDelay_ALD3bT84_sendMessage);
}

void Heavy_nts_chorus::cMsg_oGT4ZE7e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_kRMZh3i9, 2, m, &cDelay_kRMZh3i9_sendMessage);
}

void Heavy_nts_chorus::cMsg_PCJaPEte_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_UfIRWYTX, 1, m, NULL);
}

void Heavy_nts_chorus::cMsg_6F6yy19c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OOY3ijkL_sendMessage);
}

void Heavy_nts_chorus::cSystem_OOY3ijkL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pDdsGn0M_sendMessage);
}

void Heavy_nts_chorus::cDelay_bAml0Skd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bAml0Skd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_a0YZKzOP, 0, m, &cDelay_a0YZKzOP_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bAml0Skd, 0, m, &cDelay_bAml0Skd_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_L2sr42Lx, 1, m, NULL);
}

void Heavy_nts_chorus::cDelay_a0YZKzOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_a0YZKzOP, m);
  cMsg_j8qfTFiq_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::cSwitchcase_GihAEcNa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ObDszSce_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_nts_chorus::cBinop_0iaq4zvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gH96eACz_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::hTable_Xd8x58aY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PAGu7lUs_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bAml0Skd, 2, m, &cDelay_bAml0Skd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5z9D8uKl_sendMessage);
}

void Heavy_nts_chorus::cMsg_gH96eACz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Xd8x58aY, 0, m, &hTable_Xd8x58aY_sendMessage);
}

void Heavy_nts_chorus::cBinop_pDdsGn0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_0iaq4zvo_sendMessage);
}

void Heavy_nts_chorus::cMsg_j8qfTFiq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Xd8x58aY, 0, m, &hTable_Xd8x58aY_sendMessage);
}

void Heavy_nts_chorus::cCast_5z9D8uKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bAml0Skd, 0, m, &cDelay_bAml0Skd_sendMessage);
}

void Heavy_nts_chorus::cMsg_PAGu7lUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_a0YZKzOP, 2, m, &cDelay_a0YZKzOP_sendMessage);
}

void Heavy_nts_chorus::cMsg_ObDszSce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_L2sr42Lx, 1, m, NULL);
}

void Heavy_nts_chorus::cMsg_qhttj5RS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_T4Fhz2P4_sendMessage);
}

void Heavy_nts_chorus::cSystem_T4Fhz2P4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6LwOytsC_sendMessage);
}

void Heavy_nts_chorus::cVar_QK0fVjoa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_C7hGgM6w_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::cSystem_wt35sdEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VuLWjjXq_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vgoWK4Kp, m);
}

void Heavy_nts_chorus::cBinop_6LwOytsC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_piamRIKX, m);
}

void Heavy_nts_chorus::cMsg_C7hGgM6w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wt35sdEa_sendMessage);
}

void Heavy_nts_chorus::cBinop_VuLWjjXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RIN8o1lV, m);
}

void Heavy_nts_chorus::cMsg_vc5IqF8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_K202xsNl_sendMessage);
}

void Heavy_nts_chorus::cSystem_K202xsNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dCF8Da9c_sendMessage);
}

void Heavy_nts_chorus::cVar_Hp0ES4UV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CD9IcQQj_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::cSystem_I3tO8F22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hOoc8F28_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6PdNy3Pd, m);
}

void Heavy_nts_chorus::cBinop_dCF8Da9c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HQl0lMtO, m);
}

void Heavy_nts_chorus::cMsg_CD9IcQQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_I3tO8F22_sendMessage);
}

void Heavy_nts_chorus::cBinop_hOoc8F28_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8X2PpgF2, m);
}

void Heavy_nts_chorus::cBinop_moRDKFpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_HTUlzGuz_sendMessage);
}

void Heavy_nts_chorus::cBinop_HTUlzGuz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ebRhpbzN, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cwdAxBkr, m);
}

void Heavy_nts_chorus::cReceive_R1VK8b5D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NLRWghvV, m);
}

void Heavy_nts_chorus::cReceive_7ogfGaDd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_aMzpJjmz, 0, m);
}

void Heavy_nts_chorus::cReceive_cgJ7kCQX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sws0eKGb_sendMessage(_c, 0, m);
  cMsg_6F6yy19c_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QK0fVjoa, 0, m, &cVar_QK0fVjoa_sendMessage);
  cMsg_qhttj5RS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Hp0ES4UV, 0, m, &cVar_Hp0ES4UV_sendMessage);
  cMsg_vc5IqF8T_sendMessage(_c, 0, m);
}

void Heavy_nts_chorus::cReceive_7Wfaclik_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_moRDKFpC_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_V2QYzpE3, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_lqZGAeVX, m);
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
    __hv_tabwrite_f(&sTabwrite_UfIRWYTX, VIf(I0));
    __hv_tabwrite_f(&sTabwrite_L2sr42Lx, VIf(I1));
    __hv_varread_f(&sVarf_cwdAxBkr, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_aMzpJjmz, VOf(Bf1));
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
    __hv_varread_f(&sVarf_NLRWghvV, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_neg_f(VIf(Bf4), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_tabhead_f(&sTabhead_163MHuNq, VOf(Bf2));
    __hv_var_k_f_r(VOf(Bf5), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_HQl0lMtO, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_8X2PpgF2, VOf(Bf1));
    __hv_min_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf5));
    __hv_varread_f(&sVarf_6PdNy3Pd, VOf(Bf1));
    __hv_zero_f(VOf(Bf3));
    __hv_lt_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_Gzs5rxwM, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_fSKuo8dk, VIi(Bi0), VOf(Bf1));
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf3));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_lqZGAeVX, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(I1), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O1), VOf(O1));
    __hv_var_k_f(VOf(Bf5), 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_tabhead_f(&sTabhead_9nKR2OhA, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf0), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_piamRIKX, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_RIN8o1lV, VOf(Bf5));
    __hv_min_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf0));
    __hv_varread_f(&sVarf_vgoWK4Kp, VOf(Bf5));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_SwtpMxwW, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_IddX9U7L, VIi(Bi0), VOf(Bf5));
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf1));
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_V2QYzpE3, VOf(Bf0));
    __hv_varread_f(&sVarf_ebRhpbzN, VOf(Bf1));
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
