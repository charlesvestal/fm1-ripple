/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside reflect.pd) */

#include "Heavy_reflect.hpp"



#define Context(_c) static_cast<Heavy_reflect *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_reflect::Heavy_reflect(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sTabread_init(&sTabread_ZUHf3wJM, &hTable_zI4CXAXw, true);
  numBytes += sTabwrite_init(&sTabwrite_AsPnjCOG, &hTable_zI4CXAXw);
  numBytes += sTabread_init(&sTabread_ven12Qxp, &hTable_ICQXDpxH, true);
  numBytes += sTabwrite_init(&sTabwrite_obac4Zom, &hTable_ICQXDpxH);
  numBytes += cDelay_init(this, &cDelay_UQVZDr50, 0.0f);
  numBytes += cDelay_init(this, &cDelay_lBkqLzXl, 0.0f);
  numBytes += hTable_init(&hTable_zI4CXAXw, 256);
  numBytes += cTabhead_init(&cTabhead_daTtHsvt, &hTable_zI4CXAXw);
  numBytes += cVar_init_s(&cVar_qGZhZ2mG, "del-buf1");
  numBytes += cDelay_init(this, &cDelay_20weZhp9, 50.0f);
  numBytes += cDelay_init(this, &cDelay_zYwq0jl3, 0.0f);
  numBytes += cBinop_init(&cBinop_sBwadLne, 50.0f); // __mul
  numBytes += cBinop_init(&cBinop_0g1BQoau, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_kl0juxbA, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_1WONfUrX, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_51IGLI5e, 0.0f);
  numBytes += cDelay_init(this, &cDelay_m9YBVwtg, 0.0f);
  numBytes += hTable_init(&hTable_ICQXDpxH, 256);
  numBytes += cTabhead_init(&cTabhead_k2N1tnnP, &hTable_ICQXDpxH);
  numBytes += cVar_init_s(&cVar_N4C8rx5P, "del-buf2");
  numBytes += cDelay_init(this, &cDelay_LmVTw3u5, 50.0f);
  numBytes += cDelay_init(this, &cDelay_vIq0EZH3, 0.0f);
  numBytes += cBinop_init(&cBinop_dWieNSGM, 50.0f); // __mul
  numBytes += cBinop_init(&cBinop_iJCxlUSY, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_o2ZgmRAb, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_l8eNf6kK, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_OBSD9ovq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GppTFbUU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_prOQBY9v, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4c3YLSu5, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_reflect::~Heavy_reflect() {
  hTable_free(&hTable_zI4CXAXw);
  hTable_free(&hTable_ICQXDpxH);
}

HvTable *Heavy_reflect::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x7CE9FE80: return &hTable_zI4CXAXw; // del-buf1
    case 0x20DBBA68: return &hTable_ICQXDpxH; // del-buf2
    default: return nullptr;
  }
}

void Heavy_reflect::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Gy440SD1_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Rt3PZD2T_sendMessage);
      break;
    }
    case 0x2641F460: { // time_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_L6s4umuu_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_reflect::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "depth_f";
        info->hash = 0xC21FE6A3;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 1: {
        info->name = "time_f";
        info->hash = 0x2641F460;
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


void Heavy_reflect::cMsg_7Lc94SRe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_u7dPxYhM_sendMessage);
}

void Heavy_reflect::cSystem_u7dPxYhM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ARJPe4P6_sendMessage);
}

void Heavy_reflect::cDelay_UQVZDr50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UQVZDr50, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lBkqLzXl, 0, m, &cDelay_lBkqLzXl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UQVZDr50, 0, m, &cDelay_UQVZDr50_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AsPnjCOG, 1, m, NULL);
}

void Heavy_reflect::cDelay_lBkqLzXl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lBkqLzXl, m);
  cMsg_2HaFtTfP_sendMessage(_c, 0, m);
}

void Heavy_reflect::cSwitchcase_tO44hCTX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ic8gkgia_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_reflect::cBinop_nfiGKNFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DH7AqDuT_sendMessage(_c, 0, m);
}

void Heavy_reflect::hTable_zI4CXAXw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1nymNvFP_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UQVZDr50, 2, m, &cDelay_UQVZDr50_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RVvXZehQ_sendMessage);
}

void Heavy_reflect::cMsg_DH7AqDuT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_zI4CXAXw, 0, m, &hTable_zI4CXAXw_sendMessage);
}

void Heavy_reflect::cBinop_ARJPe4P6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_nfiGKNFl_sendMessage);
}

void Heavy_reflect::cMsg_2HaFtTfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_zI4CXAXw, 0, m, &hTable_zI4CXAXw_sendMessage);
}

void Heavy_reflect::cCast_RVvXZehQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_UQVZDr50, 0, m, &cDelay_UQVZDr50_sendMessage);
}

void Heavy_reflect::cMsg_1nymNvFP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_lBkqLzXl, 2, m, &cDelay_lBkqLzXl_sendMessage);
}

void Heavy_reflect::cMsg_ic8gkgia_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_AsPnjCOG, 1, m, NULL);
}

void Heavy_reflect::cTabhead_daTtHsvt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0g1BQoau, HV_BINOP_SUBTRACT, 0, m, &cBinop_0g1BQoau_sendMessage);
}

void Heavy_reflect::cMsg_v3JkdoML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ggmV2efZ_sendMessage);
}

void Heavy_reflect::cSystem_ggmV2efZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rlJQyWu1_sendMessage);
}

void Heavy_reflect::cVar_qGZhZ2mG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZzS49y0a_sendMessage(_c, 0, m);
}

void Heavy_reflect::cDelay_20weZhp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_20weZhp9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zYwq0jl3, 0, m, &cDelay_zYwq0jl3_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZUHf3wJM, 0, m, &sTabread_ZUHf3wJM_sendMessage);
}

void Heavy_reflect::cDelay_zYwq0jl3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zYwq0jl3, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZUHf3wJM, 0, m, &sTabread_ZUHf3wJM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zYwq0jl3, 0, m, &cDelay_zYwq0jl3_sendMessage);
}

void Heavy_reflect::sTabread_ZUHf3wJM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_1WONfUrX, HV_BINOP_SUBTRACT, 0, m, &cBinop_1WONfUrX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_reflect::cBinop_sBwadLne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kl0juxbA, HV_BINOP_MAX, 0, m, &cBinop_kl0juxbA_sendMessage);
}

void Heavy_reflect::cBinop_rlJQyWu1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sBwadLne, HV_BINOP_MULTIPLY, 0, m, &cBinop_sBwadLne_sendMessage);
}

void Heavy_reflect::cBinop_0g1BQoau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_paQIeFkJ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ZUHf3wJM, 0, m, &sTabread_ZUHf3wJM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QuhOdImW_sendMessage);
}

void Heavy_reflect::cSystem_aIkZKaMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1WONfUrX, HV_BINOP_SUBTRACT, 1, m, &cBinop_1WONfUrX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zYwq0jl3, 2, m, &cDelay_zYwq0jl3_sendMessage);
}

void Heavy_reflect::cMsg_ZzS49y0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aIkZKaMu_sendMessage);
}

void Heavy_reflect::cMsg_paQIeFkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_20weZhp9, 0, m, &cDelay_20weZhp9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zYwq0jl3, 0, m, &cDelay_zYwq0jl3_sendMessage);
}

void Heavy_reflect::cMsg_kM5L3F75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_kl0juxbA, HV_BINOP_MAX, 1, m, &cBinop_kl0juxbA_sendMessage);
}

void Heavy_reflect::cBinop_kl0juxbA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0g1BQoau, HV_BINOP_SUBTRACT, 1, m, &cBinop_0g1BQoau_sendMessage);
}

void Heavy_reflect::cCast_QuhOdImW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_20weZhp9, 0, m, &cDelay_20weZhp9_sendMessage);
}

void Heavy_reflect::cBinop_i6SerG2j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_20weZhp9, 2, m, &cDelay_20weZhp9_sendMessage);
}

void Heavy_reflect::cBinop_1WONfUrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_i6SerG2j_sendMessage);
}

void Heavy_reflect::cCast_5vjHCDvU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qGZhZ2mG, 0, m, &cVar_qGZhZ2mG_sendMessage);
  cMsg_v3JkdoML_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_daTtHsvt, 0, m, &cTabhead_daTtHsvt_sendMessage);
}

void Heavy_reflect::cMsg_vwXBS0HH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_I0eAXDHi_sendMessage);
}

void Heavy_reflect::cSystem_I0eAXDHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qIZa9nyc_sendMessage);
}

void Heavy_reflect::cDelay_51IGLI5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_51IGLI5e, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m9YBVwtg, 0, m, &cDelay_m9YBVwtg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_51IGLI5e, 0, m, &cDelay_51IGLI5e_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_obac4Zom, 1, m, NULL);
}

void Heavy_reflect::cDelay_m9YBVwtg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_m9YBVwtg, m);
  cMsg_bbfgDyI1_sendMessage(_c, 0, m);
}

void Heavy_reflect::cSwitchcase_YzUoUAPp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_HAAFvwyq_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_reflect::cBinop_gpPri7dT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8H0ShUYJ_sendMessage(_c, 0, m);
}

void Heavy_reflect::hTable_ICQXDpxH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ysnp6uFE_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_51IGLI5e, 2, m, &cDelay_51IGLI5e_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W19qhRhK_sendMessage);
}

void Heavy_reflect::cMsg_8H0ShUYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ICQXDpxH, 0, m, &hTable_ICQXDpxH_sendMessage);
}

void Heavy_reflect::cBinop_qIZa9nyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_gpPri7dT_sendMessage);
}

void Heavy_reflect::cMsg_bbfgDyI1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ICQXDpxH, 0, m, &hTable_ICQXDpxH_sendMessage);
}

void Heavy_reflect::cCast_W19qhRhK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_51IGLI5e, 0, m, &cDelay_51IGLI5e_sendMessage);
}

void Heavy_reflect::cMsg_ysnp6uFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_m9YBVwtg, 2, m, &cDelay_m9YBVwtg_sendMessage);
}

void Heavy_reflect::cMsg_HAAFvwyq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_obac4Zom, 1, m, NULL);
}

void Heavy_reflect::cTabhead_k2N1tnnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iJCxlUSY, HV_BINOP_SUBTRACT, 0, m, &cBinop_iJCxlUSY_sendMessage);
}

void Heavy_reflect::cMsg_5Y1YCf61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TDJlabYx_sendMessage);
}

void Heavy_reflect::cSystem_TDJlabYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VMFNN0PQ_sendMessage);
}

void Heavy_reflect::cVar_N4C8rx5P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_idDjlEgm_sendMessage(_c, 0, m);
}

void Heavy_reflect::cDelay_LmVTw3u5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LmVTw3u5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vIq0EZH3, 0, m, &cDelay_vIq0EZH3_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ven12Qxp, 0, m, &sTabread_ven12Qxp_sendMessage);
}

void Heavy_reflect::cDelay_vIq0EZH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vIq0EZH3, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ven12Qxp, 0, m, &sTabread_ven12Qxp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vIq0EZH3, 0, m, &cDelay_vIq0EZH3_sendMessage);
}

void Heavy_reflect::sTabread_ven12Qxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_l8eNf6kK, HV_BINOP_SUBTRACT, 0, m, &cBinop_l8eNf6kK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_reflect::cBinop_dWieNSGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o2ZgmRAb, HV_BINOP_MAX, 0, m, &cBinop_o2ZgmRAb_sendMessage);
}

void Heavy_reflect::cBinop_VMFNN0PQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dWieNSGM, HV_BINOP_MULTIPLY, 0, m, &cBinop_dWieNSGM_sendMessage);
}

void Heavy_reflect::cBinop_iJCxlUSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N1lcCnU6_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_ven12Qxp, 0, m, &sTabread_ven12Qxp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ScnbDvfT_sendMessage);
}

void Heavy_reflect::cSystem_6U7WE3nB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l8eNf6kK, HV_BINOP_SUBTRACT, 1, m, &cBinop_l8eNf6kK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vIq0EZH3, 2, m, &cDelay_vIq0EZH3_sendMessage);
}

void Heavy_reflect::cMsg_idDjlEgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6U7WE3nB_sendMessage);
}

void Heavy_reflect::cMsg_N1lcCnU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LmVTw3u5, 0, m, &cDelay_LmVTw3u5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vIq0EZH3, 0, m, &cDelay_vIq0EZH3_sendMessage);
}

void Heavy_reflect::cMsg_qgtjWAVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_o2ZgmRAb, HV_BINOP_MAX, 1, m, &cBinop_o2ZgmRAb_sendMessage);
}

void Heavy_reflect::cBinop_o2ZgmRAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iJCxlUSY, HV_BINOP_SUBTRACT, 1, m, &cBinop_iJCxlUSY_sendMessage);
}

void Heavy_reflect::cCast_ScnbDvfT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LmVTw3u5, 0, m, &cDelay_LmVTw3u5_sendMessage);
}

void Heavy_reflect::cBinop_2dEqv5I3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LmVTw3u5, 2, m, &cDelay_LmVTw3u5_sendMessage);
}

void Heavy_reflect::cBinop_l8eNf6kK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2dEqv5I3_sendMessage);
}

void Heavy_reflect::cCast_o2EdGQ0T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_N4C8rx5P, 0, m, &cVar_N4C8rx5P_sendMessage);
  cMsg_5Y1YCf61_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_k2N1tnnP, 0, m, &cTabhead_k2N1tnnP_sendMessage);
}

void Heavy_reflect::cBinop_creYlpfZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4c3YLSu5, m);
}

void Heavy_reflect::cBinop_1Hhvj67h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.5f, 0, m, &cBinop_creYlpfZ_sendMessage);
}

void Heavy_reflect::cBinop_83fHaTfy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OBSD9ovq, m);
}

void Heavy_reflect::cBinop_PqGpRSox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GppTFbUU, m);
}

void Heavy_reflect::cBinop_24ScdU15_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_prOQBY9v, m);
}

void Heavy_reflect::cReceive_Rt3PZD2T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1Hhvj67h_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.2f, 0, m, &cBinop_24ScdU15_sendMessage);
}

void Heavy_reflect::cReceive_L6s4umuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.871402f, 0, m, &cBinop_83fHaTfy_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.882762f, 0, m, &cBinop_PqGpRSox_sendMessage);
}

void Heavy_reflect::cReceive_Gy440SD1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7Lc94SRe_sendMessage(_c, 0, m);
  cMsg_vwXBS0HH_sendMessage(_c, 0, m);
  cMsg_kM5L3F75_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qGZhZ2mG, 0, m, &cVar_qGZhZ2mG_sendMessage);
  cMsg_v3JkdoML_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_daTtHsvt, 0, m, &cTabhead_daTtHsvt_sendMessage);
  cMsg_qgtjWAVT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_N4C8rx5P, 0, m, &cVar_N4C8rx5P_sendMessage);
  cMsg_5Y1YCf61_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_k2N1tnnP, 0, m, &cTabhead_k2N1tnnP_sendMessage);
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

int Heavy_reflect::process(float **inputBuffers, float **outputBuffers, int n) {
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3;

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
    __hv_tabread_f(&sTabread_ZUHf3wJM, VOf(Bf0));
    __hv_varread_f(&sVarf_OBSD9ovq, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(I0), VIf(I1), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_AsPnjCOG, VIf(Bf2));
    __hv_tabread_f(&sTabread_ven12Qxp, VOf(Bf2));
    __hv_varread_f(&sVarf_GppTFbUU, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_obac4Zom, VIf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_prOQBY9v, VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_4c3YLSu5, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_reflect::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_reflect::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
