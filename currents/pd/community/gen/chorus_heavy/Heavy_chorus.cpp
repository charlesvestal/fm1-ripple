/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside chorus.pd) */

#include "Heavy_chorus.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_chorus *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_chorus_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_chorus));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_chorus(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_chorus_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_chorus));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_chorus(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_chorus_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_chorus();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_chorus::Heavy_chorus(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sTabwrite_init(&sTabwrite_leFdM7xR, &hTable_SUIbGVwa);
  numBytes += sTabwrite_init(&sTabwrite_N29DE2Mo, &hTable_HNJtT3Jo);
  numBytes += sPhasor_k_init(&sPhasor_lBQR2Wtg, 0.0f, sampleRate);
  numBytes += sTabhead_init(&sTabhead_FxjUjDOA, &hTable_HNJtT3Jo);
  numBytes += sTabread_init(&sTabread_kJYBrK8u, &hTable_HNJtT3Jo, false);
  numBytes += sTabread_init(&sTabread_cYzNru2S, &hTable_HNJtT3Jo, false);
  numBytes += sTabhead_init(&sTabhead_QTdmUhfF, &hTable_SUIbGVwa);
  numBytes += sTabread_init(&sTabread_qC9joe79, &hTable_SUIbGVwa, false);
  numBytes += sTabread_init(&sTabread_Cc4N1gyb, &hTable_SUIbGVwa, false);
  numBytes += cDelay_init(this, &cDelay_5rOAk9J6, 0.0f);
  numBytes += cDelay_init(this, &cDelay_cFE1NSuk, 0.0f);
  numBytes += hTable_init(&hTable_SUIbGVwa, 256);
  numBytes += cDelay_init(this, &cDelay_oYGgexwW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_BPLCANkv, 0.0f);
  numBytes += hTable_init(&hTable_HNJtT3Jo, 256);
  numBytes += cVar_init_s(&cVar_SAlvdtpt, "del-buf_l");
  numBytes += sVarf_init(&sVarf_1pVEfLNB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qCzggjvt, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_53ylUTrY, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_y7BodWgw, "del-buf_r");
  numBytes += sVarf_init(&sVarf_qesXFR3i, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_DOVRKP2a, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sCSA56Zs, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PaMLCdgX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_C2VPb9i3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Bl3ugIEP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rTZ3ZKrH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_EPgWINIR, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_chorus::~Heavy_chorus() {
  hTable_free(&hTable_SUIbGVwa);
  hTable_free(&hTable_HNJtT3Jo);
}

HvTable *Heavy_chorus::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x9DAE02FD: return &hTable_SUIbGVwa; // del-buf_l
    case 0xCF57129D: return &hTable_HNJtT3Jo; // del-buf_r
    default: return nullptr;
  }
}

void Heavy_chorus::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CCwfPsbi_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rd0Ggdbo_sendMessage);
      break;
    }
    case 0x9F29F22: { // mix_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_87GOP9zZ_sendMessage);
      break;
    }
    case 0x2641F460: { // time_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_yimetNWM_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_chorus::getParameterInfo(int index, HvParameterInfo *info) {
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


void Heavy_chorus::cMsg_mSQpuz33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dijCXizx_sendMessage);
}

void Heavy_chorus::cSystem_dijCXizx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4s1DKZZQ_sendMessage);
}

void Heavy_chorus::cDelay_5rOAk9J6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5rOAk9J6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cFE1NSuk, 0, m, &cDelay_cFE1NSuk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5rOAk9J6, 0, m, &cDelay_5rOAk9J6_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_leFdM7xR, 1, m, NULL);
}

void Heavy_chorus::cDelay_cFE1NSuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cFE1NSuk, m);
  cMsg_pkI76fqY_sendMessage(_c, 0, m);
}

void Heavy_chorus::cSwitchcase_zEikg0jj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_CXYKtqbj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_chorus::cBinop_l9LRuS1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UinLiv4X_sendMessage(_c, 0, m);
}

void Heavy_chorus::hTable_SUIbGVwa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aUnmU6rh_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5rOAk9J6, 2, m, &cDelay_5rOAk9J6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Si104SvA_sendMessage);
}

void Heavy_chorus::cMsg_UinLiv4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_SUIbGVwa, 0, m, &hTable_SUIbGVwa_sendMessage);
}

void Heavy_chorus::cBinop_4s1DKZZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_l9LRuS1w_sendMessage);
}

void Heavy_chorus::cMsg_pkI76fqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_SUIbGVwa, 0, m, &hTable_SUIbGVwa_sendMessage);
}

void Heavy_chorus::cCast_Si104SvA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5rOAk9J6, 0, m, &cDelay_5rOAk9J6_sendMessage);
}

void Heavy_chorus::cMsg_aUnmU6rh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_cFE1NSuk, 2, m, &cDelay_cFE1NSuk_sendMessage);
}

void Heavy_chorus::cMsg_CXYKtqbj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_leFdM7xR, 1, m, NULL);
}

void Heavy_chorus::cMsg_IjVuf3uJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TBQyKr1m_sendMessage);
}

void Heavy_chorus::cSystem_TBQyKr1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dmFbQueG_sendMessage);
}

void Heavy_chorus::cDelay_oYGgexwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oYGgexwW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BPLCANkv, 0, m, &cDelay_BPLCANkv_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oYGgexwW, 0, m, &cDelay_oYGgexwW_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_N29DE2Mo, 1, m, NULL);
}

void Heavy_chorus::cDelay_BPLCANkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BPLCANkv, m);
  cMsg_fmocKOq1_sendMessage(_c, 0, m);
}

void Heavy_chorus::cSwitchcase_yor7JyEC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_z0DCCtwS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_chorus::cBinop_nE5qsaYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8AfdKxE7_sendMessage(_c, 0, m);
}

void Heavy_chorus::hTable_HNJtT3Jo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OBt36oNH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oYGgexwW, 2, m, &cDelay_oYGgexwW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vec7zPjw_sendMessage);
}

void Heavy_chorus::cMsg_8AfdKxE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_HNJtT3Jo, 0, m, &hTable_HNJtT3Jo_sendMessage);
}

void Heavy_chorus::cBinop_dmFbQueG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_nE5qsaYb_sendMessage);
}

void Heavy_chorus::cMsg_fmocKOq1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_HNJtT3Jo, 0, m, &hTable_HNJtT3Jo_sendMessage);
}

void Heavy_chorus::cCast_vec7zPjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_oYGgexwW, 0, m, &cDelay_oYGgexwW_sendMessage);
}

void Heavy_chorus::cMsg_OBt36oNH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_BPLCANkv, 2, m, &cDelay_BPLCANkv_sendMessage);
}

void Heavy_chorus::cMsg_z0DCCtwS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_N29DE2Mo, 1, m, NULL);
}

void Heavy_chorus::cMsg_yUeWIGAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eEJ6LJQF_sendMessage);
}

void Heavy_chorus::cSystem_eEJ6LJQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_V6K8ekav_sendMessage);
}

void Heavy_chorus::cVar_SAlvdtpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rcmOFFPo_sendMessage(_c, 0, m);
}

void Heavy_chorus::cSystem_0puRm3BG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_W63MXUvT_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1pVEfLNB, m);
}

void Heavy_chorus::cBinop_V6K8ekav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qCzggjvt, m);
}

void Heavy_chorus::cMsg_rcmOFFPo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0puRm3BG_sendMessage);
}

void Heavy_chorus::cBinop_W63MXUvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_53ylUTrY, m);
}

void Heavy_chorus::cMsg_1vAhUuTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_823HDVpZ_sendMessage);
}

void Heavy_chorus::cSystem_823HDVpZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yi7rl47T_sendMessage);
}

void Heavy_chorus::cVar_y7BodWgw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ur6jbYPx_sendMessage(_c, 0, m);
}

void Heavy_chorus::cSystem_QP1AwK0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_rRZFhdvP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_qesXFR3i, m);
}

void Heavy_chorus::cBinop_yi7rl47T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DOVRKP2a, m);
}

void Heavy_chorus::cMsg_Ur6jbYPx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QP1AwK0D_sendMessage);
}

void Heavy_chorus::cBinop_rRZFhdvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sCSA56Zs, m);
}

void Heavy_chorus::cBinop_Q6ujPYkZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_YTLSOr8W_sendMessage);
}

void Heavy_chorus::cBinop_YTLSOr8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Bl3ugIEP, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rTZ3ZKrH, m);
}

void Heavy_chorus::cReceive_rd0Ggdbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PaMLCdgX, m);
}

void Heavy_chorus::cReceive_yimetNWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_lBQR2Wtg, 0, m);
}

void Heavy_chorus::cReceive_CCwfPsbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mSQpuz33_sendMessage(_c, 0, m);
  cMsg_IjVuf3uJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SAlvdtpt, 0, m, &cVar_SAlvdtpt_sendMessage);
  cMsg_yUeWIGAE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_y7BodWgw, 0, m, &cVar_y7BodWgw_sendMessage);
  cMsg_1vAhUuTy_sendMessage(_c, 0, m);
}

void Heavy_chorus::cReceive_87GOP9zZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Q6ujPYkZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_C2VPb9i3, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_EPgWINIR, m);
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

int Heavy_chorus::process(float **inputBuffers, float **outputBuffers, int n) {
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
    __hv_tabwrite_f(&sTabwrite_leFdM7xR, VIf(I0));
    __hv_tabwrite_f(&sTabwrite_N29DE2Mo, VIf(I1));
    __hv_varread_f(&sVarf_rTZ3ZKrH, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_lBQR2Wtg, VOf(Bf1));
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
    __hv_varread_f(&sVarf_PaMLCdgX, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_neg_f(VIf(Bf4), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_tabhead_f(&sTabhead_FxjUjDOA, VOf(Bf2));
    __hv_var_k_f_r(VOf(Bf5), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_DOVRKP2a, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_sCSA56Zs, VOf(Bf1));
    __hv_min_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf5));
    __hv_varread_f(&sVarf_qesXFR3i, VOf(Bf1));
    __hv_zero_f(VOf(Bf3));
    __hv_lt_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_kJYBrK8u, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_cYzNru2S, VIi(Bi0), VOf(Bf1));
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf3));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_EPgWINIR, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(I1), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O1), VOf(O1));
    __hv_var_k_f(VOf(Bf5), 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_tabhead_f(&sTabhead_QTdmUhfF, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf0), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_qCzggjvt, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_53ylUTrY, VOf(Bf5));
    __hv_min_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf0));
    __hv_varread_f(&sVarf_1pVEfLNB, VOf(Bf5));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_qC9joe79, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_Cc4N1gyb, VIi(Bi0), VOf(Bf5));
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf1));
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_C2VPb9i3, VOf(Bf0));
    __hv_varread_f(&sVarf_Bl3ugIEP, VOf(Bf1));
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

int Heavy_chorus::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_chorus::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
