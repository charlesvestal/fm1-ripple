/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside chorus.pd) */

#include "Heavy_chorus.hpp"



#define Context(_c) static_cast<Heavy_chorus *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_chorus::Heavy_chorus(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sTabwrite_init(&sTabwrite_FB4gzU7N, &hTable_ivre7FGv);
  numBytes += sTabwrite_init(&sTabwrite_JpuKhpqf, &hTable_CIAJtq9f);
  numBytes += sPhasor_k_init(&sPhasor_HxSqqbUB, 0.0f, sampleRate);
  numBytes += sTabhead_init(&sTabhead_qg6EEFI0, &hTable_ivre7FGv);
  numBytes += sTabread_init(&sTabread_gnVcGWsA, &hTable_ivre7FGv, false);
  numBytes += sTabread_init(&sTabread_Nx9iGOcj, &hTable_ivre7FGv, false);
  numBytes += sTabhead_init(&sTabhead_dyTrxgMR, &hTable_CIAJtq9f);
  numBytes += sTabread_init(&sTabread_ZLlwqhe5, &hTable_CIAJtq9f, false);
  numBytes += sTabread_init(&sTabread_9PJ91RKz, &hTable_CIAJtq9f, false);
  numBytes += cDelay_init(this, &cDelay_6lKHiM7L, 0.0f);
  numBytes += cDelay_init(this, &cDelay_vWeGjxis, 0.0f);
  numBytes += hTable_init(&hTable_ivre7FGv, 256);
  numBytes += cDelay_init(this, &cDelay_siX4At88, 0.0f);
  numBytes += cDelay_init(this, &cDelay_KHFR5mdW, 0.0f);
  numBytes += hTable_init(&hTable_CIAJtq9f, 256);
  numBytes += cVar_init_s(&cVar_eoUOuNJ5, "del-buf_l");
  numBytes += sVarf_init(&sVarf_8CVQM73m, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3wNwNzvF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8x6CIiHz, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_R1DcLRrH, "del-buf_r");
  numBytes += sVarf_init(&sVarf_HxnA0eLd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PJjuoOi7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Sx01lz0V, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nOBj8H02, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zkrfAnMS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XRVaOyg0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OXnwWaZx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_J3P2TKg3, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_chorus::~Heavy_chorus() {
  hTable_free(&hTable_ivre7FGv);
  hTable_free(&hTable_CIAJtq9f);
}

HvTable *Heavy_chorus::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x9DAE02FD: return &hTable_ivre7FGv; // del-buf_l
    case 0xCF57129D: return &hTable_CIAJtq9f; // del-buf_r
    default: return nullptr;
  }
}

void Heavy_chorus::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vLk2Kpx6_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rXnYn6Q6_sendMessage);
      break;
    }
    case 0x9F29F22: { // mix_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VUOFAl6i_sendMessage);
      break;
    }
    case 0x2641F460: { // time_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_N8izXLE1_sendMessage);
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


void Heavy_chorus::cMsg_BJ7UVqpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iJ2Hl7zu_sendMessage);
}

void Heavy_chorus::cSystem_iJ2Hl7zu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IwYkVySm_sendMessage);
}

void Heavy_chorus::cDelay_6lKHiM7L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6lKHiM7L, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vWeGjxis, 0, m, &cDelay_vWeGjxis_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6lKHiM7L, 0, m, &cDelay_6lKHiM7L_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_FB4gzU7N, 1, m, NULL);
}

void Heavy_chorus::cDelay_vWeGjxis_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vWeGjxis, m);
  cMsg_NPxn2hdM_sendMessage(_c, 0, m);
}

void Heavy_chorus::cSwitchcase_z6NeUapZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_aeioqGr7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_chorus::cBinop_MX7VuKzW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n8FMcpTz_sendMessage(_c, 0, m);
}

void Heavy_chorus::hTable_ivre7FGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AMbYwqvv_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6lKHiM7L, 2, m, &cDelay_6lKHiM7L_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_59gxprvx_sendMessage);
}

void Heavy_chorus::cMsg_n8FMcpTz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ivre7FGv, 0, m, &hTable_ivre7FGv_sendMessage);
}

void Heavy_chorus::cBinop_IwYkVySm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_MX7VuKzW_sendMessage);
}

void Heavy_chorus::cMsg_NPxn2hdM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ivre7FGv, 0, m, &hTable_ivre7FGv_sendMessage);
}

void Heavy_chorus::cCast_59gxprvx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6lKHiM7L, 0, m, &cDelay_6lKHiM7L_sendMessage);
}

void Heavy_chorus::cMsg_AMbYwqvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_vWeGjxis, 2, m, &cDelay_vWeGjxis_sendMessage);
}

void Heavy_chorus::cMsg_aeioqGr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_FB4gzU7N, 1, m, NULL);
}

void Heavy_chorus::cMsg_n4hXm0d0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BqsDYCC5_sendMessage);
}

void Heavy_chorus::cSystem_BqsDYCC5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_twGC37F4_sendMessage);
}

void Heavy_chorus::cDelay_siX4At88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_siX4At88, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KHFR5mdW, 0, m, &cDelay_KHFR5mdW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_siX4At88, 0, m, &cDelay_siX4At88_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JpuKhpqf, 1, m, NULL);
}

void Heavy_chorus::cDelay_KHFR5mdW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KHFR5mdW, m);
  cMsg_tk1mkzce_sendMessage(_c, 0, m);
}

void Heavy_chorus::cSwitchcase_oDEirO6L_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_GOT6Pyef_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_chorus::cBinop_oYkzZ9tv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gmli6SlA_sendMessage(_c, 0, m);
}

void Heavy_chorus::hTable_CIAJtq9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4sU64cbm_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_siX4At88, 2, m, &cDelay_siX4At88_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DEbDdsBT_sendMessage);
}

void Heavy_chorus::cMsg_gmli6SlA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_CIAJtq9f, 0, m, &hTable_CIAJtq9f_sendMessage);
}

void Heavy_chorus::cBinop_twGC37F4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_oYkzZ9tv_sendMessage);
}

void Heavy_chorus::cMsg_tk1mkzce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_CIAJtq9f, 0, m, &hTable_CIAJtq9f_sendMessage);
}

void Heavy_chorus::cCast_DEbDdsBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_siX4At88, 0, m, &cDelay_siX4At88_sendMessage);
}

void Heavy_chorus::cMsg_4sU64cbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_KHFR5mdW, 2, m, &cDelay_KHFR5mdW_sendMessage);
}

void Heavy_chorus::cMsg_GOT6Pyef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JpuKhpqf, 1, m, NULL);
}

void Heavy_chorus::cMsg_JYG5ss9Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AybcyZD0_sendMessage);
}

void Heavy_chorus::cSystem_AybcyZD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TwBWMDks_sendMessage);
}

void Heavy_chorus::cVar_eoUOuNJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2qhaQRle_sendMessage(_c, 0, m);
}

void Heavy_chorus::cSystem_PdA9uzKv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_2nU2LuwL_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8CVQM73m, m);
}

void Heavy_chorus::cBinop_TwBWMDks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3wNwNzvF, m);
}

void Heavy_chorus::cMsg_2qhaQRle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PdA9uzKv_sendMessage);
}

void Heavy_chorus::cBinop_2nU2LuwL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8x6CIiHz, m);
}

void Heavy_chorus::cMsg_ART3hkjM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_e1E9cacz_sendMessage);
}

void Heavy_chorus::cSystem_e1E9cacz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LWCDg9DS_sendMessage);
}

void Heavy_chorus::cVar_R1DcLRrH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I3jxAWki_sendMessage(_c, 0, m);
}

void Heavy_chorus::cSystem_BQVqVdea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_LUM1XfBL_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_HxnA0eLd, m);
}

void Heavy_chorus::cBinop_LWCDg9DS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PJjuoOi7, m);
}

void Heavy_chorus::cMsg_I3jxAWki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BQVqVdea_sendMessage);
}

void Heavy_chorus::cBinop_LUM1XfBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Sx01lz0V, m);
}

void Heavy_chorus::cBinop_uxRGcf4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ZElZULas_sendMessage);
}

void Heavy_chorus::cBinop_ZElZULas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XRVaOyg0, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OXnwWaZx, m);
}

void Heavy_chorus::cReceive_rXnYn6Q6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nOBj8H02, m);
}

void Heavy_chorus::cReceive_N8izXLE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_HxSqqbUB, 0, m);
}

void Heavy_chorus::cReceive_vLk2Kpx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BJ7UVqpN_sendMessage(_c, 0, m);
  cMsg_n4hXm0d0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eoUOuNJ5, 0, m, &cVar_eoUOuNJ5_sendMessage);
  cMsg_JYG5ss9Q_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_R1DcLRrH, 0, m, &cVar_R1DcLRrH_sendMessage);
  cMsg_ART3hkjM_sendMessage(_c, 0, m);
}

void Heavy_chorus::cReceive_VUOFAl6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uxRGcf4w_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_zkrfAnMS, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_J3P2TKg3, m);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4;
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
    __hv_tabwrite_f(&sTabwrite_FB4gzU7N, VIf(I0));
    __hv_tabwrite_f(&sTabwrite_JpuKhpqf, VIf(I1));
    __hv_phasor_k_f(&sPhasor_HxSqqbUB, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_nOBj8H02, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_tabhead_f(&sTabhead_qg6EEFI0, VOf(Bf0));
    __hv_var_k_f_r(VOf(Bf4), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_3wNwNzvF, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_8x6CIiHz, VOf(Bf1));
    __hv_min_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf0));
    __hv_max_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf4));
    __hv_varread_f(&sVarf_8CVQM73m, VOf(Bf1));
    __hv_zero_f(VOf(Bf2));
    __hv_lt_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_and_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_gnVcGWsA, VIi(Bi1), VOf(Bf2));
    __hv_tabread_if(&sTabread_Nx9iGOcj, VIi(Bi0), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf2));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_zkrfAnMS, VOf(Bf4));
    __hv_varread_f(&sVarf_XRVaOyg0, VOf(Bf2));
    __hv_mul_f(VIf(I0), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_OXnwWaZx, VOf(Bf2));
    __hv_neg_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_tabhead_f(&sTabhead_dyTrxgMR, VOf(Bf3));
    __hv_var_k_f_r(VOf(Bf1), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_PJjuoOi7, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_Sx01lz0V, VOf(Bf4));
    __hv_min_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf1));
    __hv_varread_f(&sVarf_HxnA0eLd, VOf(Bf4));
    __hv_zero_f(VOf(Bf0));
    __hv_lt_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_ZLlwqhe5, VIi(Bi1), VOf(Bf0));
    __hv_tabread_if(&sTabread_9PJ91RKz, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf0));
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_J3P2TKg3, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(I1), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));

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
