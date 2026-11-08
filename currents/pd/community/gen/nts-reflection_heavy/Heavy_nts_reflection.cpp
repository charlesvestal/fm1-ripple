/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside nts-reflection.pd) */

#include "Heavy_nts_reflection.hpp"



#define Context(_c) static_cast<Heavy_nts_reflection *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_nts_reflection::Heavy_nts_reflection(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sTabread_init(&sTabread_V80XcJBu, &hTable_EzXMWjUN, true);
  numBytes += sTabwrite_init(&sTabwrite_V9a0wHWV, &hTable_EzXMWjUN);
  numBytes += sTabread_init(&sTabread_hDreVA6o, &hTable_acO2lMDU, true);
  numBytes += sTabwrite_init(&sTabwrite_WQHPw4tL, &hTable_acO2lMDU);
  numBytes += cDelay_init(this, &cDelay_2f3QI4hL, 0.0f);
  numBytes += cDelay_init(this, &cDelay_3GXCaVCK, 0.0f);
  numBytes += hTable_init(&hTable_EzXMWjUN, 256);
  numBytes += cTabhead_init(&cTabhead_etMakGVg, &hTable_EzXMWjUN);
  numBytes += cVar_init_s(&cVar_5SpHfOqE, "del-buf1");
  numBytes += cDelay_init(this, &cDelay_hVoVUF7u, 50.0f);
  numBytes += cDelay_init(this, &cDelay_E3Z6XVTN, 0.0f);
  numBytes += cBinop_init(&cBinop_3fJ7mUjD, 50.0f); // __mul
  numBytes += cBinop_init(&cBinop_YXyUABEa, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ozZSdmSe, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_6vTDpXvD, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_gC9hdb16, 0.0f);
  numBytes += cDelay_init(this, &cDelay_vUgtVz7M, 0.0f);
  numBytes += hTable_init(&hTable_acO2lMDU, 256);
  numBytes += cTabhead_init(&cTabhead_7OrlWfoI, &hTable_acO2lMDU);
  numBytes += cVar_init_s(&cVar_G70JFD5c, "del-buf2");
  numBytes += cDelay_init(this, &cDelay_1Oa4XcLw, 50.0f);
  numBytes += cDelay_init(this, &cDelay_Bdd576vW, 0.0f);
  numBytes += cBinop_init(&cBinop_MKLvnlty, 50.0f); // __mul
  numBytes += cBinop_init(&cBinop_GRZDYzrz, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_s3VKRs40, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Ugb1HN0u, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_VVbmcQ4s, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Dt4lLqx5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5PEWkAoa, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1QSAi3lw, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_nts_reflection::~Heavy_nts_reflection() {
  hTable_free(&hTable_EzXMWjUN);
  hTable_free(&hTable_acO2lMDU);
}

HvTable *Heavy_nts_reflection::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x7CE9FE80: return &hTable_EzXMWjUN; // del-buf1
    case 0x20DBBA68: return &hTable_acO2lMDU; // del-buf2
    default: return nullptr;
  }
}

void Heavy_nts_reflection::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_sQg2ro0s_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wzqcXI3j_sendMessage);
      break;
    }
    case 0x2641F460: { // time_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JxowD5BX_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_nts_reflection::getParameterInfo(int index, HvParameterInfo *info) {
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


void Heavy_nts_reflection::cMsg_D6viUVFz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_o7kkvfoU_sendMessage);
}

void Heavy_nts_reflection::cSystem_o7kkvfoU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KhBrjUMj_sendMessage);
}

void Heavy_nts_reflection::cDelay_2f3QI4hL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2f3QI4hL, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3GXCaVCK, 0, m, &cDelay_3GXCaVCK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2f3QI4hL, 0, m, &cDelay_2f3QI4hL_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_V9a0wHWV, 1, m, NULL);
}

void Heavy_nts_reflection::cDelay_3GXCaVCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3GXCaVCK, m);
  cMsg_f7fqLLvo_sendMessage(_c, 0, m);
}

void Heavy_nts_reflection::cSwitchcase_yISIg6b9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_7GoG1puk_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_nts_reflection::cBinop_7hm6bE8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nIKyQGhH_sendMessage(_c, 0, m);
}

void Heavy_nts_reflection::hTable_EzXMWjUN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z0DrpVQu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_2f3QI4hL, 2, m, &cDelay_2f3QI4hL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HqAVmMHf_sendMessage);
}

void Heavy_nts_reflection::cMsg_nIKyQGhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_EzXMWjUN, 0, m, &hTable_EzXMWjUN_sendMessage);
}

void Heavy_nts_reflection::cBinop_KhBrjUMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_7hm6bE8W_sendMessage);
}

void Heavy_nts_reflection::cMsg_f7fqLLvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_EzXMWjUN, 0, m, &hTable_EzXMWjUN_sendMessage);
}

void Heavy_nts_reflection::cCast_HqAVmMHf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2f3QI4hL, 0, m, &cDelay_2f3QI4hL_sendMessage);
}

void Heavy_nts_reflection::cMsg_Z0DrpVQu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_3GXCaVCK, 2, m, &cDelay_3GXCaVCK_sendMessage);
}

void Heavy_nts_reflection::cMsg_7GoG1puk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_V9a0wHWV, 1, m, NULL);
}

void Heavy_nts_reflection::cTabhead_etMakGVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YXyUABEa, HV_BINOP_SUBTRACT, 0, m, &cBinop_YXyUABEa_sendMessage);
}

void Heavy_nts_reflection::cMsg_nYaS3YUF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FVXb9wuE_sendMessage);
}

void Heavy_nts_reflection::cSystem_FVXb9wuE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_glM9OSHf_sendMessage);
}

void Heavy_nts_reflection::cVar_5SpHfOqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kAwkjJNb_sendMessage(_c, 0, m);
}

void Heavy_nts_reflection::cDelay_hVoVUF7u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hVoVUF7u, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E3Z6XVTN, 0, m, &cDelay_E3Z6XVTN_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_V80XcJBu, 0, m, &sTabread_V80XcJBu_sendMessage);
}

void Heavy_nts_reflection::cDelay_E3Z6XVTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_E3Z6XVTN, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_V80XcJBu, 0, m, &sTabread_V80XcJBu_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E3Z6XVTN, 0, m, &cDelay_E3Z6XVTN_sendMessage);
}

void Heavy_nts_reflection::sTabread_V80XcJBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_6vTDpXvD, HV_BINOP_SUBTRACT, 0, m, &cBinop_6vTDpXvD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_nts_reflection::cBinop_3fJ7mUjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ozZSdmSe, HV_BINOP_MAX, 0, m, &cBinop_ozZSdmSe_sendMessage);
}

void Heavy_nts_reflection::cBinop_glM9OSHf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3fJ7mUjD, HV_BINOP_MULTIPLY, 0, m, &cBinop_3fJ7mUjD_sendMessage);
}

void Heavy_nts_reflection::cBinop_YXyUABEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YmgsqGQg_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_V80XcJBu, 0, m, &sTabread_V80XcJBu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PAPZKuVW_sendMessage);
}

void Heavy_nts_reflection::cSystem_vvF0JzHK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6vTDpXvD, HV_BINOP_SUBTRACT, 1, m, &cBinop_6vTDpXvD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E3Z6XVTN, 2, m, &cDelay_E3Z6XVTN_sendMessage);
}

void Heavy_nts_reflection::cMsg_kAwkjJNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vvF0JzHK_sendMessage);
}

void Heavy_nts_reflection::cMsg_YmgsqGQg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hVoVUF7u, 0, m, &cDelay_hVoVUF7u_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E3Z6XVTN, 0, m, &cDelay_E3Z6XVTN_sendMessage);
}

void Heavy_nts_reflection::cMsg_9cb3OyuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_ozZSdmSe, HV_BINOP_MAX, 1, m, &cBinop_ozZSdmSe_sendMessage);
}

void Heavy_nts_reflection::cBinop_ozZSdmSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YXyUABEa, HV_BINOP_SUBTRACT, 1, m, &cBinop_YXyUABEa_sendMessage);
}

void Heavy_nts_reflection::cCast_PAPZKuVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hVoVUF7u, 0, m, &cDelay_hVoVUF7u_sendMessage);
}

void Heavy_nts_reflection::cBinop_EUxuub1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hVoVUF7u, 2, m, &cDelay_hVoVUF7u_sendMessage);
}

void Heavy_nts_reflection::cBinop_6vTDpXvD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_EUxuub1b_sendMessage);
}

void Heavy_nts_reflection::cCast_1xmunSdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5SpHfOqE, 0, m, &cVar_5SpHfOqE_sendMessage);
  cMsg_nYaS3YUF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_etMakGVg, 0, m, &cTabhead_etMakGVg_sendMessage);
}

void Heavy_nts_reflection::cMsg_u3WKRH4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3WV8IwEt_sendMessage);
}

void Heavy_nts_reflection::cSystem_3WV8IwEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_svjuniU4_sendMessage);
}

void Heavy_nts_reflection::cDelay_gC9hdb16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gC9hdb16, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vUgtVz7M, 0, m, &cDelay_vUgtVz7M_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gC9hdb16, 0, m, &cDelay_gC9hdb16_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_WQHPw4tL, 1, m, NULL);
}

void Heavy_nts_reflection::cDelay_vUgtVz7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vUgtVz7M, m);
  cMsg_YywLn2Cb_sendMessage(_c, 0, m);
}

void Heavy_nts_reflection::cSwitchcase_r7r8bGeE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_It5bWGUw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_nts_reflection::cBinop_01V9mDHn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lFMveY1J_sendMessage(_c, 0, m);
}

void Heavy_nts_reflection::hTable_acO2lMDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PXfhzX0K_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gC9hdb16, 2, m, &cDelay_gC9hdb16_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dk4tYQpZ_sendMessage);
}

void Heavy_nts_reflection::cMsg_lFMveY1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_acO2lMDU, 0, m, &hTable_acO2lMDU_sendMessage);
}

void Heavy_nts_reflection::cBinop_svjuniU4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_01V9mDHn_sendMessage);
}

void Heavy_nts_reflection::cMsg_YywLn2Cb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_acO2lMDU, 0, m, &hTable_acO2lMDU_sendMessage);
}

void Heavy_nts_reflection::cCast_Dk4tYQpZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gC9hdb16, 0, m, &cDelay_gC9hdb16_sendMessage);
}

void Heavy_nts_reflection::cMsg_PXfhzX0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_vUgtVz7M, 2, m, &cDelay_vUgtVz7M_sendMessage);
}

void Heavy_nts_reflection::cMsg_It5bWGUw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_WQHPw4tL, 1, m, NULL);
}

void Heavy_nts_reflection::cTabhead_7OrlWfoI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GRZDYzrz, HV_BINOP_SUBTRACT, 0, m, &cBinop_GRZDYzrz_sendMessage);
}

void Heavy_nts_reflection::cMsg_aKg2nU9C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JTp8XGxb_sendMessage);
}

void Heavy_nts_reflection::cSystem_JTp8XGxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Ye6YsYjQ_sendMessage);
}

void Heavy_nts_reflection::cVar_G70JFD5c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SCPyiJkx_sendMessage(_c, 0, m);
}

void Heavy_nts_reflection::cDelay_1Oa4XcLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1Oa4XcLw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Bdd576vW, 0, m, &cDelay_Bdd576vW_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hDreVA6o, 0, m, &sTabread_hDreVA6o_sendMessage);
}

void Heavy_nts_reflection::cDelay_Bdd576vW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Bdd576vW, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hDreVA6o, 0, m, &sTabread_hDreVA6o_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Bdd576vW, 0, m, &cDelay_Bdd576vW_sendMessage);
}

void Heavy_nts_reflection::sTabread_hDreVA6o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Ugb1HN0u, HV_BINOP_SUBTRACT, 0, m, &cBinop_Ugb1HN0u_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_nts_reflection::cBinop_MKLvnlty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s3VKRs40, HV_BINOP_MAX, 0, m, &cBinop_s3VKRs40_sendMessage);
}

void Heavy_nts_reflection::cBinop_Ye6YsYjQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MKLvnlty, HV_BINOP_MULTIPLY, 0, m, &cBinop_MKLvnlty_sendMessage);
}

void Heavy_nts_reflection::cBinop_GRZDYzrz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_blYwcVcr_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_hDreVA6o, 0, m, &sTabread_hDreVA6o_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7y7odVP3_sendMessage);
}

void Heavy_nts_reflection::cSystem_xanfLggG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ugb1HN0u, HV_BINOP_SUBTRACT, 1, m, &cBinop_Ugb1HN0u_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Bdd576vW, 2, m, &cDelay_Bdd576vW_sendMessage);
}

void Heavy_nts_reflection::cMsg_SCPyiJkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xanfLggG_sendMessage);
}

void Heavy_nts_reflection::cMsg_blYwcVcr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1Oa4XcLw, 0, m, &cDelay_1Oa4XcLw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Bdd576vW, 0, m, &cDelay_Bdd576vW_sendMessage);
}

void Heavy_nts_reflection::cMsg_FvXmpVzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_s3VKRs40, HV_BINOP_MAX, 1, m, &cBinop_s3VKRs40_sendMessage);
}

void Heavy_nts_reflection::cBinop_s3VKRs40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GRZDYzrz, HV_BINOP_SUBTRACT, 1, m, &cBinop_GRZDYzrz_sendMessage);
}

void Heavy_nts_reflection::cCast_7y7odVP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1Oa4XcLw, 0, m, &cDelay_1Oa4XcLw_sendMessage);
}

void Heavy_nts_reflection::cBinop_VmHaa7Ze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1Oa4XcLw, 2, m, &cDelay_1Oa4XcLw_sendMessage);
}

void Heavy_nts_reflection::cBinop_Ugb1HN0u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VmHaa7Ze_sendMessage);
}

void Heavy_nts_reflection::cCast_y3o4qek1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_G70JFD5c, 0, m, &cVar_G70JFD5c_sendMessage);
  cMsg_aKg2nU9C_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7OrlWfoI, 0, m, &cTabhead_7OrlWfoI_sendMessage);
}

void Heavy_nts_reflection::cBinop_3Nlrw7Jx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1QSAi3lw, m);
}

void Heavy_nts_reflection::cBinop_cSTPhsSm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.5f, 0, m, &cBinop_3Nlrw7Jx_sendMessage);
}

void Heavy_nts_reflection::cBinop_xDnrUa1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VVbmcQ4s, m);
}

void Heavy_nts_reflection::cBinop_J6cNGDHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Dt4lLqx5, m);
}

void Heavy_nts_reflection::cBinop_KSAMFYos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5PEWkAoa, m);
}

void Heavy_nts_reflection::cReceive_wzqcXI3j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cSTPhsSm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.2f, 0, m, &cBinop_KSAMFYos_sendMessage);
}

void Heavy_nts_reflection::cReceive_JxowD5BX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.871402f, 0, m, &cBinop_xDnrUa1L_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.882762f, 0, m, &cBinop_J6cNGDHO_sendMessage);
}

void Heavy_nts_reflection::cReceive_sQg2ro0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_D6viUVFz_sendMessage(_c, 0, m);
  cMsg_u3WKRH4X_sendMessage(_c, 0, m);
  cMsg_9cb3OyuB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5SpHfOqE, 0, m, &cVar_5SpHfOqE_sendMessage);
  cMsg_nYaS3YUF_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_etMakGVg, 0, m, &cTabhead_etMakGVg_sendMessage);
  cMsg_FvXmpVzk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_G70JFD5c, 0, m, &cVar_G70JFD5c_sendMessage);
  cMsg_aKg2nU9C_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7OrlWfoI, 0, m, &cTabhead_7OrlWfoI_sendMessage);
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

int Heavy_nts_reflection::process(float **inputBuffers, float **outputBuffers, int n) {
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
    __hv_tabread_f(&sTabread_V80XcJBu, VOf(Bf0));
    __hv_varread_f(&sVarf_VVbmcQ4s, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(I0), VIf(I1), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_V9a0wHWV, VIf(Bf2));
    __hv_tabread_f(&sTabread_hDreVA6o, VOf(Bf2));
    __hv_varread_f(&sVarf_Dt4lLqx5, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_WQHPw4tL, VIf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_5PEWkAoa, VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_1QSAi3lw, VOf(Bf3));
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

int Heavy_nts_reflection::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_nts_reflection::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
