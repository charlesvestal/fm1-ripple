/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside reflect.pd) */

#include "Heavy_reflect.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_reflect *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_reflect_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_reflect));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_reflect(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_reflect_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_reflect));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_reflect(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_reflect_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_reflect();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_reflect::Heavy_reflect(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sTabread_init(&sTabread_bl2921ZG, &hTable_66jgqKgZ, true);
  numBytes += sTabwrite_init(&sTabwrite_rVl1OaNE, &hTable_66jgqKgZ);
  numBytes += sTabread_init(&sTabread_upGrkTHQ, &hTable_zEKRvtAD, true);
  numBytes += sTabwrite_init(&sTabwrite_6L8j23fF, &hTable_zEKRvtAD);
  numBytes += cDelay_init(this, &cDelay_cCnSRbdW, 0.0f);
  numBytes += cDelay_init(this, &cDelay_v9IZPozT, 0.0f);
  numBytes += hTable_init(&hTable_66jgqKgZ, 256);
  numBytes += cTabhead_init(&cTabhead_qJNOcvAl, &hTable_66jgqKgZ);
  numBytes += cVar_init_s(&cVar_H0QbYrbb, "del-buf1");
  numBytes += cDelay_init(this, &cDelay_5MbLQ0vX, 50.0f);
  numBytes += cDelay_init(this, &cDelay_tUGGrsiM, 0.0f);
  numBytes += cBinop_init(&cBinop_LArGsEb7, 50.0f); // __mul
  numBytes += cBinop_init(&cBinop_MBPF6ytc, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_BSEjCCXM, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_0UwybGkK, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_qOZWO4ZG, 0.0f);
  numBytes += cDelay_init(this, &cDelay_oQqL5CYR, 0.0f);
  numBytes += hTable_init(&hTable_zEKRvtAD, 256);
  numBytes += cTabhead_init(&cTabhead_7CyomDbG, &hTable_zEKRvtAD);
  numBytes += cVar_init_s(&cVar_riT7a78F, "del-buf2");
  numBytes += cDelay_init(this, &cDelay_65xcPSSM, 50.0f);
  numBytes += cDelay_init(this, &cDelay_PjPMr1Cg, 0.0f);
  numBytes += cBinop_init(&cBinop_ebMVW1eR, 50.0f); // __mul
  numBytes += cBinop_init(&cBinop_shd96NkF, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_jBZJ9hcH, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_kKtZVEuI, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_4nO9PoiJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_h7CjDwmw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8yHd491R, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nNZo6q2P, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_reflect::~Heavy_reflect() {
  hTable_free(&hTable_66jgqKgZ);
  hTable_free(&hTable_zEKRvtAD);
}

HvTable *Heavy_reflect::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x7CE9FE80: return &hTable_66jgqKgZ; // del-buf1
    case 0x20DBBA68: return &hTable_zEKRvtAD; // del-buf2
    default: return nullptr;
  }
}

void Heavy_reflect::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qWlN63qA_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4CjtkUsL_sendMessage);
      break;
    }
    case 0x2641F460: { // time_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rhzyENv0_sendMessage);
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


void Heavy_reflect::cMsg_xsNBlGLX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qteLeH2U_sendMessage);
}

void Heavy_reflect::cSystem_qteLeH2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VYSLDjwN_sendMessage);
}

void Heavy_reflect::cDelay_cCnSRbdW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cCnSRbdW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_v9IZPozT, 0, m, &cDelay_v9IZPozT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cCnSRbdW, 0, m, &cDelay_cCnSRbdW_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rVl1OaNE, 1, m, NULL);
}

void Heavy_reflect::cDelay_v9IZPozT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_v9IZPozT, m);
  cMsg_tKUoseZF_sendMessage(_c, 0, m);
}

void Heavy_reflect::cSwitchcase_9i19YwkP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_nPb1HV0c_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_reflect::cBinop_Rrag31S4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BvbdAkdR_sendMessage(_c, 0, m);
}

void Heavy_reflect::hTable_66jgqKgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d2jnvtBm_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cCnSRbdW, 2, m, &cDelay_cCnSRbdW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LPCyt0MW_sendMessage);
}

void Heavy_reflect::cMsg_BvbdAkdR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_66jgqKgZ, 0, m, &hTable_66jgqKgZ_sendMessage);
}

void Heavy_reflect::cBinop_VYSLDjwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_Rrag31S4_sendMessage);
}

void Heavy_reflect::cMsg_tKUoseZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_66jgqKgZ, 0, m, &hTable_66jgqKgZ_sendMessage);
}

void Heavy_reflect::cCast_LPCyt0MW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cCnSRbdW, 0, m, &cDelay_cCnSRbdW_sendMessage);
}

void Heavy_reflect::cMsg_d2jnvtBm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_v9IZPozT, 2, m, &cDelay_v9IZPozT_sendMessage);
}

void Heavy_reflect::cMsg_nPb1HV0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_rVl1OaNE, 1, m, NULL);
}

void Heavy_reflect::cTabhead_qJNOcvAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MBPF6ytc, HV_BINOP_SUBTRACT, 0, m, &cBinop_MBPF6ytc_sendMessage);
}

void Heavy_reflect::cMsg_UI7Z60Id_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5dPS80GB_sendMessage);
}

void Heavy_reflect::cSystem_5dPS80GB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_T174yZbQ_sendMessage);
}

void Heavy_reflect::cVar_H0QbYrbb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_25EOKXy7_sendMessage(_c, 0, m);
}

void Heavy_reflect::cDelay_5MbLQ0vX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5MbLQ0vX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tUGGrsiM, 0, m, &cDelay_tUGGrsiM_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bl2921ZG, 0, m, &sTabread_bl2921ZG_sendMessage);
}

void Heavy_reflect::cDelay_tUGGrsiM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tUGGrsiM, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bl2921ZG, 0, m, &sTabread_bl2921ZG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tUGGrsiM, 0, m, &cDelay_tUGGrsiM_sendMessage);
}

void Heavy_reflect::sTabread_bl2921ZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_0UwybGkK, HV_BINOP_SUBTRACT, 0, m, &cBinop_0UwybGkK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_reflect::cBinop_LArGsEb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BSEjCCXM, HV_BINOP_MAX, 0, m, &cBinop_BSEjCCXM_sendMessage);
}

void Heavy_reflect::cBinop_T174yZbQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LArGsEb7, HV_BINOP_MULTIPLY, 0, m, &cBinop_LArGsEb7_sendMessage);
}

void Heavy_reflect::cBinop_MBPF6ytc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q1OhkE59_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_bl2921ZG, 0, m, &sTabread_bl2921ZG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XgcVYZrg_sendMessage);
}

void Heavy_reflect::cSystem_6cpI1mnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0UwybGkK, HV_BINOP_SUBTRACT, 1, m, &cBinop_0UwybGkK_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tUGGrsiM, 2, m, &cDelay_tUGGrsiM_sendMessage);
}

void Heavy_reflect::cMsg_25EOKXy7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6cpI1mnk_sendMessage);
}

void Heavy_reflect::cMsg_q1OhkE59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5MbLQ0vX, 0, m, &cDelay_5MbLQ0vX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tUGGrsiM, 0, m, &cDelay_tUGGrsiM_sendMessage);
}

void Heavy_reflect::cMsg_pb2ZfAwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_BSEjCCXM, HV_BINOP_MAX, 1, m, &cBinop_BSEjCCXM_sendMessage);
}

void Heavy_reflect::cBinop_BSEjCCXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MBPF6ytc, HV_BINOP_SUBTRACT, 1, m, &cBinop_MBPF6ytc_sendMessage);
}

void Heavy_reflect::cCast_XgcVYZrg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5MbLQ0vX, 0, m, &cDelay_5MbLQ0vX_sendMessage);
}

void Heavy_reflect::cBinop_dXyEz0hf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5MbLQ0vX, 2, m, &cDelay_5MbLQ0vX_sendMessage);
}

void Heavy_reflect::cBinop_0UwybGkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dXyEz0hf_sendMessage);
}

void Heavy_reflect::cCast_wxaGobYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H0QbYrbb, 0, m, &cVar_H0QbYrbb_sendMessage);
  cMsg_UI7Z60Id_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_qJNOcvAl, 0, m, &cTabhead_qJNOcvAl_sendMessage);
}

void Heavy_reflect::cMsg_hlUXffFI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_p79mnrBR_sendMessage);
}

void Heavy_reflect::cSystem_p79mnrBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_td2lIas4_sendMessage);
}

void Heavy_reflect::cDelay_qOZWO4ZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qOZWO4ZG, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_oQqL5CYR, 0, m, &cDelay_oQqL5CYR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qOZWO4ZG, 0, m, &cDelay_qOZWO4ZG_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_6L8j23fF, 1, m, NULL);
}

void Heavy_reflect::cDelay_oQqL5CYR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_oQqL5CYR, m);
  cMsg_YubKG3a3_sendMessage(_c, 0, m);
}

void Heavy_reflect::cSwitchcase_g90Yjqg1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_B7ohpcxJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_reflect::cBinop_3MD4oBYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QiQn2Wf4_sendMessage(_c, 0, m);
}

void Heavy_reflect::hTable_zEKRvtAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o1vChPCP_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qOZWO4ZG, 2, m, &cDelay_qOZWO4ZG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ki0VwOqL_sendMessage);
}

void Heavy_reflect::cMsg_QiQn2Wf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_zEKRvtAD, 0, m, &hTable_zEKRvtAD_sendMessage);
}

void Heavy_reflect::cBinop_td2lIas4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_3MD4oBYD_sendMessage);
}

void Heavy_reflect::cMsg_YubKG3a3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_zEKRvtAD, 0, m, &hTable_zEKRvtAD_sendMessage);
}

void Heavy_reflect::cCast_Ki0VwOqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qOZWO4ZG, 0, m, &cDelay_qOZWO4ZG_sendMessage);
}

void Heavy_reflect::cMsg_o1vChPCP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_oQqL5CYR, 2, m, &cDelay_oQqL5CYR_sendMessage);
}

void Heavy_reflect::cMsg_B7ohpcxJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_6L8j23fF, 1, m, NULL);
}

void Heavy_reflect::cTabhead_7CyomDbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_shd96NkF, HV_BINOP_SUBTRACT, 0, m, &cBinop_shd96NkF_sendMessage);
}

void Heavy_reflect::cMsg_wPvbsbMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1A5yMyDC_sendMessage);
}

void Heavy_reflect::cSystem_1A5yMyDC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_L10s4yeu_sendMessage);
}

void Heavy_reflect::cVar_riT7a78F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YxZWSCvB_sendMessage(_c, 0, m);
}

void Heavy_reflect::cDelay_65xcPSSM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_65xcPSSM, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PjPMr1Cg, 0, m, &cDelay_PjPMr1Cg_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_upGrkTHQ, 0, m, &sTabread_upGrkTHQ_sendMessage);
}

void Heavy_reflect::cDelay_PjPMr1Cg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PjPMr1Cg, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_upGrkTHQ, 0, m, &sTabread_upGrkTHQ_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PjPMr1Cg, 0, m, &cDelay_PjPMr1Cg_sendMessage);
}

void Heavy_reflect::sTabread_upGrkTHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kKtZVEuI, HV_BINOP_SUBTRACT, 0, m, &cBinop_kKtZVEuI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_reflect::cBinop_ebMVW1eR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jBZJ9hcH, HV_BINOP_MAX, 0, m, &cBinop_jBZJ9hcH_sendMessage);
}

void Heavy_reflect::cBinop_L10s4yeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ebMVW1eR, HV_BINOP_MULTIPLY, 0, m, &cBinop_ebMVW1eR_sendMessage);
}

void Heavy_reflect::cBinop_shd96NkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6kxV2yuy_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_upGrkTHQ, 0, m, &sTabread_upGrkTHQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DhCUVrwf_sendMessage);
}

void Heavy_reflect::cSystem_CP0nTwT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kKtZVEuI, HV_BINOP_SUBTRACT, 1, m, &cBinop_kKtZVEuI_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PjPMr1Cg, 2, m, &cDelay_PjPMr1Cg_sendMessage);
}

void Heavy_reflect::cMsg_YxZWSCvB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CP0nTwT0_sendMessage);
}

void Heavy_reflect::cMsg_6kxV2yuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_65xcPSSM, 0, m, &cDelay_65xcPSSM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PjPMr1Cg, 0, m, &cDelay_PjPMr1Cg_sendMessage);
}

void Heavy_reflect::cMsg_kV5ZrQEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_jBZJ9hcH, HV_BINOP_MAX, 1, m, &cBinop_jBZJ9hcH_sendMessage);
}

void Heavy_reflect::cBinop_jBZJ9hcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_shd96NkF, HV_BINOP_SUBTRACT, 1, m, &cBinop_shd96NkF_sendMessage);
}

void Heavy_reflect::cCast_DhCUVrwf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_65xcPSSM, 0, m, &cDelay_65xcPSSM_sendMessage);
}

void Heavy_reflect::cBinop_54RaJMuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_65xcPSSM, 2, m, &cDelay_65xcPSSM_sendMessage);
}

void Heavy_reflect::cBinop_kKtZVEuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_54RaJMuF_sendMessage);
}

void Heavy_reflect::cCast_HixgWfgi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_riT7a78F, 0, m, &cVar_riT7a78F_sendMessage);
  cMsg_wPvbsbMN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7CyomDbG, 0, m, &cTabhead_7CyomDbG_sendMessage);
}

void Heavy_reflect::cBinop_B9lGblG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nNZo6q2P, m);
}

void Heavy_reflect::cBinop_pO9qqVMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.5f, 0, m, &cBinop_B9lGblG2_sendMessage);
}

void Heavy_reflect::cBinop_kpzxbDdO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4nO9PoiJ, m);
}

void Heavy_reflect::cBinop_in4xaLT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_h7CjDwmw, m);
}

void Heavy_reflect::cBinop_x2y1jGqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8yHd491R, m);
}

void Heavy_reflect::cReceive_4CjtkUsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pO9qqVMr_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.2f, 0, m, &cBinop_x2y1jGqE_sendMessage);
}

void Heavy_reflect::cReceive_rhzyENv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.871402f, 0, m, &cBinop_kpzxbDdO_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.882762f, 0, m, &cBinop_in4xaLT9_sendMessage);
}

void Heavy_reflect::cReceive_qWlN63qA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xsNBlGLX_sendMessage(_c, 0, m);
  cMsg_hlUXffFI_sendMessage(_c, 0, m);
  cMsg_pb2ZfAwE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_H0QbYrbb, 0, m, &cVar_H0QbYrbb_sendMessage);
  cMsg_UI7Z60Id_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_qJNOcvAl, 0, m, &cTabhead_qJNOcvAl_sendMessage);
  cMsg_kV5ZrQEe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_riT7a78F, 0, m, &cVar_riT7a78F_sendMessage);
  cMsg_wPvbsbMN_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_7CyomDbG, 0, m, &cTabhead_7CyomDbG_sendMessage);
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
    __hv_tabread_f(&sTabread_bl2921ZG, VOf(Bf0));
    __hv_varread_f(&sVarf_4nO9PoiJ, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(I0), VIf(I1), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_rVl1OaNE, VIf(Bf2));
    __hv_tabread_f(&sTabread_upGrkTHQ, VOf(Bf2));
    __hv_varread_f(&sVarf_h7CjDwmw, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_6L8j23fF, VIf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_8yHd491R, VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_nNZo6q2P, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));

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
