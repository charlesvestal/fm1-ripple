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
  numBytes += sTabwrite_init(&sTabwrite_d0NYmXVU, &hTable_o6VuhdY6);
  numBytes += sTabwrite_init(&sTabwrite_KCkzOZbD, &hTable_raVZXFNk);
  numBytes += sPhasor_k_init(&sPhasor_wwbiUeQs, 0.0f, sampleRate);
  numBytes += sTabhead_init(&sTabhead_hULHxfBp, &hTable_raVZXFNk);
  numBytes += sTabread_init(&sTabread_hiNHK8LY, &hTable_raVZXFNk, false);
  numBytes += sTabread_init(&sTabread_f5Q8Caoz, &hTable_raVZXFNk, false);
  numBytes += sTabhead_init(&sTabhead_RKKxc77X, &hTable_o6VuhdY6);
  numBytes += sTabread_init(&sTabread_Iv2oWmys, &hTable_o6VuhdY6, false);
  numBytes += sTabread_init(&sTabread_o1Qm9nZ1, &hTable_o6VuhdY6, false);
  numBytes += cDelay_init(this, &cDelay_vaqs5T42, 0.0f);
  numBytes += cDelay_init(this, &cDelay_gNsvQACJ, 0.0f);
  numBytes += hTable_init(&hTable_o6VuhdY6, 256);
  numBytes += cDelay_init(this, &cDelay_NAY0hklO, 0.0f);
  numBytes += cDelay_init(this, &cDelay_iFla15vg, 0.0f);
  numBytes += hTable_init(&hTable_raVZXFNk, 256);
  numBytes += cVar_init_s(&cVar_3DLgL8ck, "del-buf_l");
  numBytes += sVarf_init(&sVarf_3kmO2G1I, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eUp4AQZA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vmxj3paK, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_Jhk5HsQV, "del-buf_r");
  numBytes += sVarf_init(&sVarf_xUpmugPx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0IqNdN8A, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_s1BmUlzu, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_h9ohSLfn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_X8BQm8Kh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dmNrscD1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5Cd1b4sf, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VUy9GEmW, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_chorus::~Heavy_chorus() {
  hTable_free(&hTable_o6VuhdY6);
  hTable_free(&hTable_raVZXFNk);
}

HvTable *Heavy_chorus::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x9DAE02FD: return &hTable_o6VuhdY6; // del-buf_l
    case 0xCF57129D: return &hTable_raVZXFNk; // del-buf_r
    default: return nullptr;
  }
}

void Heavy_chorus::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CIQ5E6YL_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Bfrh7ivb_sendMessage);
      break;
    }
    case 0x9F29F22: { // mix_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UL6dgoS1_sendMessage);
      break;
    }
    case 0x2641F460: { // time_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QvWCyv7V_sendMessage);
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


void Heavy_chorus::cMsg_9eqTFcmD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_w3Wcm5aE_sendMessage);
}

void Heavy_chorus::cSystem_w3Wcm5aE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_CHu2CEUv_sendMessage);
}

void Heavy_chorus::cDelay_vaqs5T42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vaqs5T42, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gNsvQACJ, 0, m, &cDelay_gNsvQACJ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vaqs5T42, 0, m, &cDelay_vaqs5T42_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_d0NYmXVU, 1, m, NULL);
}

void Heavy_chorus::cDelay_gNsvQACJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gNsvQACJ, m);
  cMsg_NXEm42kv_sendMessage(_c, 0, m);
}

void Heavy_chorus::cSwitchcase_aZ0KYhMf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_TQPInrSa_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_chorus::cBinop_20H23XcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JHUPL7An_sendMessage(_c, 0, m);
}

void Heavy_chorus::hTable_o6VuhdY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FtOxhOku_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vaqs5T42, 2, m, &cDelay_vaqs5T42_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lkRBAZgl_sendMessage);
}

void Heavy_chorus::cMsg_JHUPL7An_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_o6VuhdY6, 0, m, &hTable_o6VuhdY6_sendMessage);
}

void Heavy_chorus::cBinop_CHu2CEUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_20H23XcA_sendMessage);
}

void Heavy_chorus::cMsg_NXEm42kv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_o6VuhdY6, 0, m, &hTable_o6VuhdY6_sendMessage);
}

void Heavy_chorus::cCast_lkRBAZgl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vaqs5T42, 0, m, &cDelay_vaqs5T42_sendMessage);
}

void Heavy_chorus::cMsg_FtOxhOku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_gNsvQACJ, 2, m, &cDelay_gNsvQACJ_sendMessage);
}

void Heavy_chorus::cMsg_TQPInrSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_d0NYmXVU, 1, m, NULL);
}

void Heavy_chorus::cMsg_jq3jGK7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Jrgt87Ce_sendMessage);
}

void Heavy_chorus::cSystem_Jrgt87Ce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_oXO0SwJu_sendMessage);
}

void Heavy_chorus::cDelay_NAY0hklO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NAY0hklO, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iFla15vg, 0, m, &cDelay_iFla15vg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NAY0hklO, 0, m, &cDelay_NAY0hklO_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_KCkzOZbD, 1, m, NULL);
}

void Heavy_chorus::cDelay_iFla15vg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iFla15vg, m);
  cMsg_A6gl8jhl_sendMessage(_c, 0, m);
}

void Heavy_chorus::cSwitchcase_g9zmwk76_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_c4AqGhtw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_chorus::cBinop_Yfgd2WZm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_89Rn8sUL_sendMessage(_c, 0, m);
}

void Heavy_chorus::hTable_raVZXFNk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ftil3U7Q_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NAY0hklO, 2, m, &cDelay_NAY0hklO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4cwxUqnj_sendMessage);
}

void Heavy_chorus::cMsg_89Rn8sUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_raVZXFNk, 0, m, &hTable_raVZXFNk_sendMessage);
}

void Heavy_chorus::cBinop_oXO0SwJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_Yfgd2WZm_sendMessage);
}

void Heavy_chorus::cMsg_A6gl8jhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_raVZXFNk, 0, m, &hTable_raVZXFNk_sendMessage);
}

void Heavy_chorus::cCast_4cwxUqnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NAY0hklO, 0, m, &cDelay_NAY0hklO_sendMessage);
}

void Heavy_chorus::cMsg_Ftil3U7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_iFla15vg, 2, m, &cDelay_iFla15vg_sendMessage);
}

void Heavy_chorus::cMsg_c4AqGhtw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_KCkzOZbD, 1, m, NULL);
}

void Heavy_chorus::cMsg_aE2MKSBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_r7aGPjq5_sendMessage);
}

void Heavy_chorus::cSystem_r7aGPjq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hcXxBQju_sendMessage);
}

void Heavy_chorus::cVar_3DLgL8ck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3BPqVvm8_sendMessage(_c, 0, m);
}

void Heavy_chorus::cSystem_5NpTUbXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_WrC0hfbV_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3kmO2G1I, m);
}

void Heavy_chorus::cBinop_hcXxBQju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eUp4AQZA, m);
}

void Heavy_chorus::cMsg_3BPqVvm8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5NpTUbXN_sendMessage);
}

void Heavy_chorus::cBinop_WrC0hfbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vmxj3paK, m);
}

void Heavy_chorus::cMsg_dpDQJInm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6YK1vwAv_sendMessage);
}

void Heavy_chorus::cSystem_6YK1vwAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Dx9WbNwa_sendMessage);
}

void Heavy_chorus::cVar_Jhk5HsQV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zfOTblZe_sendMessage(_c, 0, m);
}

void Heavy_chorus::cSystem_Z2N6NMWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tdNgoKLP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xUpmugPx, m);
}

void Heavy_chorus::cBinop_Dx9WbNwa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0IqNdN8A, m);
}

void Heavy_chorus::cMsg_zfOTblZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Z2N6NMWY_sendMessage);
}

void Heavy_chorus::cBinop_tdNgoKLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_s1BmUlzu, m);
}

void Heavy_chorus::cBinop_kUDT9yeh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_sMRs7Xtg_sendMessage);
}

void Heavy_chorus::cBinop_sMRs7Xtg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dmNrscD1, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_5Cd1b4sf, m);
}

void Heavy_chorus::cReceive_Bfrh7ivb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_h9ohSLfn, m);
}

void Heavy_chorus::cReceive_QvWCyv7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_wwbiUeQs, 0, m);
}

void Heavy_chorus::cReceive_CIQ5E6YL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9eqTFcmD_sendMessage(_c, 0, m);
  cMsg_jq3jGK7Y_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3DLgL8ck, 0, m, &cVar_3DLgL8ck_sendMessage);
  cMsg_aE2MKSBc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Jhk5HsQV, 0, m, &cVar_Jhk5HsQV_sendMessage);
  cMsg_dpDQJInm_sendMessage(_c, 0, m);
}

void Heavy_chorus::cReceive_UL6dgoS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kUDT9yeh_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_X8BQm8Kh, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VUy9GEmW, m);
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
    __hv_tabwrite_f(&sTabwrite_d0NYmXVU, VIf(I0));
    __hv_tabwrite_f(&sTabwrite_KCkzOZbD, VIf(I1));
    __hv_varread_f(&sVarf_5Cd1b4sf, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_wwbiUeQs, VOf(Bf1));
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
    __hv_varread_f(&sVarf_h9ohSLfn, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_neg_f(VIf(Bf4), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_tabhead_f(&sTabhead_hULHxfBp, VOf(Bf2));
    __hv_var_k_f_r(VOf(Bf5), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_0IqNdN8A, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_s1BmUlzu, VOf(Bf1));
    __hv_min_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf5));
    __hv_varread_f(&sVarf_xUpmugPx, VOf(Bf1));
    __hv_zero_f(VOf(Bf3));
    __hv_lt_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_hiNHK8LY, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_f5Q8Caoz, VIi(Bi0), VOf(Bf1));
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf3));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_VUy9GEmW, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(I1), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O1), VOf(O1));
    __hv_var_k_f(VOf(Bf5), 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f, 15.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_tabhead_f(&sTabhead_RKKxc77X, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf0), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_eUp4AQZA, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_vmxj3paK, VOf(Bf5));
    __hv_min_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf0));
    __hv_varread_f(&sVarf_3kmO2G1I, VOf(Bf5));
    __hv_zero_f(VOf(Bf1));
    __hv_lt_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_Iv2oWmys, VIi(Bi1), VOf(Bf1));
    __hv_tabread_if(&sTabread_o1Qm9nZ1, VIi(Bi0), VOf(Bf5));
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf1));
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_X8BQm8Kh, VOf(Bf0));
    __hv_varread_f(&sVarf_dmNrscD1, VOf(Bf1));
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
