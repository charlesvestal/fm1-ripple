/** the author of nts-reflection.pd */

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
  numBytes += sTabread_init(&sTabread_MJ7usO4o, &hTable_iMCWv60V, true);
  numBytes += sTabwrite_init(&sTabwrite_vCOQRffI, &hTable_iMCWv60V);
  numBytes += sTabread_init(&sTabread_NvmUIKvR, &hTable_Q24sB4bV, true);
  numBytes += sTabwrite_init(&sTabwrite_VCRXSEiA, &hTable_Q24sB4bV);
  numBytes += cDelay_init(this, &cDelay_CDgOUJlx, 0.0f);
  numBytes += cDelay_init(this, &cDelay_IN3cB1ZC, 0.0f);
  numBytes += hTable_init(&hTable_iMCWv60V, 256);
  numBytes += cTabhead_init(&cTabhead_Xxfj74pK, &hTable_iMCWv60V);
  numBytes += cVar_init_s(&cVar_RzdIH43R, "del-buf1");
  numBytes += cDelay_init(this, &cDelay_RhO0lECe, 50.0f);
  numBytes += cDelay_init(this, &cDelay_SeHS9oXg, 0.0f);
  numBytes += cBinop_init(&cBinop_OqG9ux7d, 50.0f); // __mul
  numBytes += cBinop_init(&cBinop_SwwJMHMC, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9ygWDP12, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_N1AyBnFC, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_SHlizbOw, 0.0f);
  numBytes += cDelay_init(this, &cDelay_zitiW3U0, 0.0f);
  numBytes += hTable_init(&hTable_Q24sB4bV, 256);
  numBytes += cTabhead_init(&cTabhead_OegdHhEr, &hTable_Q24sB4bV);
  numBytes += cVar_init_s(&cVar_JAKXAORa, "del-buf2");
  numBytes += cDelay_init(this, &cDelay_qNQlLZby, 50.0f);
  numBytes += cDelay_init(this, &cDelay_VV9ucoFY, 0.0f);
  numBytes += cBinop_init(&cBinop_dFA0m5kG, 50.0f); // __mul
  numBytes += cBinop_init(&cBinop_AP8M8IT9, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_bwyrueOk, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Se0QPFw7, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_XcpC9koR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tvCu0ahS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aO8kI9Dz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kNqr9lLv, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_nts_reflection::~Heavy_nts_reflection() {
  hTable_free(&hTable_iMCWv60V);
  hTable_free(&hTable_Q24sB4bV);
}

HvTable *Heavy_nts_reflection::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x7CE9FE80: return &hTable_iMCWv60V; // del-buf1
    case 0x20DBBA68: return &hTable_Q24sB4bV; // del-buf2
    default: return nullptr;
  }
}

void Heavy_nts_reflection::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GL5evOjQ_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vniOq5KR_sendMessage);
      break;
    }
    case 0x2641F460: { // time_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jQHxbHHh_sendMessage);
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


void Heavy_nts_reflection::cMsg_GzGR0hTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_50r1PvUj_sendMessage);
}

void Heavy_nts_reflection::cSystem_50r1PvUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fG9Q0Dsg_sendMessage);
}

void Heavy_nts_reflection::cDelay_CDgOUJlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CDgOUJlx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IN3cB1ZC, 0, m, &cDelay_IN3cB1ZC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CDgOUJlx, 0, m, &cDelay_CDgOUJlx_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vCOQRffI, 1, m, NULL);
}

void Heavy_nts_reflection::cDelay_IN3cB1ZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IN3cB1ZC, m);
  cMsg_zeo3sqvD_sendMessage(_c, 0, m);
}

void Heavy_nts_reflection::cSwitchcase_IkqPQlCC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_i0koMI4p_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_nts_reflection::cBinop_dDULJo4Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aTyxI1QL_sendMessage(_c, 0, m);
}

void Heavy_nts_reflection::hTable_iMCWv60V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Zcn4bRg0_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CDgOUJlx, 2, m, &cDelay_CDgOUJlx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qUiJMUqT_sendMessage);
}

void Heavy_nts_reflection::cMsg_aTyxI1QL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_iMCWv60V, 0, m, &hTable_iMCWv60V_sendMessage);
}

void Heavy_nts_reflection::cBinop_fG9Q0Dsg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_dDULJo4Q_sendMessage);
}

void Heavy_nts_reflection::cMsg_zeo3sqvD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_iMCWv60V, 0, m, &hTable_iMCWv60V_sendMessage);
}

void Heavy_nts_reflection::cCast_qUiJMUqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CDgOUJlx, 0, m, &cDelay_CDgOUJlx_sendMessage);
}

void Heavy_nts_reflection::cMsg_Zcn4bRg0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_IN3cB1ZC, 2, m, &cDelay_IN3cB1ZC_sendMessage);
}

void Heavy_nts_reflection::cMsg_i0koMI4p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vCOQRffI, 1, m, NULL);
}

void Heavy_nts_reflection::cTabhead_Xxfj74pK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SwwJMHMC, HV_BINOP_SUBTRACT, 0, m, &cBinop_SwwJMHMC_sendMessage);
}

void Heavy_nts_reflection::cMsg_HAjtaeAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tvUG5Drq_sendMessage);
}

void Heavy_nts_reflection::cSystem_tvUG5Drq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LOAAeWmn_sendMessage);
}

void Heavy_nts_reflection::cVar_RzdIH43R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2V3Zu4E4_sendMessage(_c, 0, m);
}

void Heavy_nts_reflection::cDelay_RhO0lECe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RhO0lECe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SeHS9oXg, 0, m, &cDelay_SeHS9oXg_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_MJ7usO4o, 0, m, &sTabread_MJ7usO4o_sendMessage);
}

void Heavy_nts_reflection::cDelay_SeHS9oXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SeHS9oXg, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_MJ7usO4o, 0, m, &sTabread_MJ7usO4o_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SeHS9oXg, 0, m, &cDelay_SeHS9oXg_sendMessage);
}

void Heavy_nts_reflection::sTabread_MJ7usO4o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_N1AyBnFC, HV_BINOP_SUBTRACT, 0, m, &cBinop_N1AyBnFC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_nts_reflection::cBinop_OqG9ux7d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9ygWDP12, HV_BINOP_MAX, 0, m, &cBinop_9ygWDP12_sendMessage);
}

void Heavy_nts_reflection::cBinop_LOAAeWmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OqG9ux7d, HV_BINOP_MULTIPLY, 0, m, &cBinop_OqG9ux7d_sendMessage);
}

void Heavy_nts_reflection::cBinop_SwwJMHMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3HOuksD3_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_MJ7usO4o, 0, m, &sTabread_MJ7usO4o_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1s9vcaDU_sendMessage);
}

void Heavy_nts_reflection::cSystem_GBkLgYVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N1AyBnFC, HV_BINOP_SUBTRACT, 1, m, &cBinop_N1AyBnFC_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SeHS9oXg, 2, m, &cDelay_SeHS9oXg_sendMessage);
}

void Heavy_nts_reflection::cMsg_2V3Zu4E4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GBkLgYVl_sendMessage);
}

void Heavy_nts_reflection::cMsg_3HOuksD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_RhO0lECe, 0, m, &cDelay_RhO0lECe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SeHS9oXg, 0, m, &cDelay_SeHS9oXg_sendMessage);
}

void Heavy_nts_reflection::cMsg_m6bcpn9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9ygWDP12, HV_BINOP_MAX, 1, m, &cBinop_9ygWDP12_sendMessage);
}

void Heavy_nts_reflection::cBinop_9ygWDP12_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SwwJMHMC, HV_BINOP_SUBTRACT, 1, m, &cBinop_SwwJMHMC_sendMessage);
}

void Heavy_nts_reflection::cCast_1s9vcaDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RhO0lECe, 0, m, &cDelay_RhO0lECe_sendMessage);
}

void Heavy_nts_reflection::cBinop_b63Db5Xg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RhO0lECe, 2, m, &cDelay_RhO0lECe_sendMessage);
}

void Heavy_nts_reflection::cBinop_N1AyBnFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_b63Db5Xg_sendMessage);
}

void Heavy_nts_reflection::cCast_sOVfaX5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RzdIH43R, 0, m, &cVar_RzdIH43R_sendMessage);
  cMsg_HAjtaeAR_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Xxfj74pK, 0, m, &cTabhead_Xxfj74pK_sendMessage);
}

void Heavy_nts_reflection::cMsg_tvjnWnwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ABCdBGCM_sendMessage);
}

void Heavy_nts_reflection::cSystem_ABCdBGCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ayoORi0t_sendMessage);
}

void Heavy_nts_reflection::cDelay_SHlizbOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SHlizbOw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zitiW3U0, 0, m, &cDelay_zitiW3U0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SHlizbOw, 0, m, &cDelay_SHlizbOw_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_VCRXSEiA, 1, m, NULL);
}

void Heavy_nts_reflection::cDelay_zitiW3U0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zitiW3U0, m);
  cMsg_YzW1QcEt_sendMessage(_c, 0, m);
}

void Heavy_nts_reflection::cSwitchcase_yq6IJ5CX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_yahrYcDf_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_nts_reflection::cBinop_3V8OjkHD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ntwyNYKT_sendMessage(_c, 0, m);
}

void Heavy_nts_reflection::hTable_Q24sB4bV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L6tjx917_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SHlizbOw, 2, m, &cDelay_SHlizbOw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hsCbErsm_sendMessage);
}

void Heavy_nts_reflection::cMsg_ntwyNYKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Q24sB4bV, 0, m, &hTable_Q24sB4bV_sendMessage);
}

void Heavy_nts_reflection::cBinop_ayoORi0t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_3V8OjkHD_sendMessage);
}

void Heavy_nts_reflection::cMsg_YzW1QcEt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Q24sB4bV, 0, m, &hTable_Q24sB4bV_sendMessage);
}

void Heavy_nts_reflection::cCast_hsCbErsm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SHlizbOw, 0, m, &cDelay_SHlizbOw_sendMessage);
}

void Heavy_nts_reflection::cMsg_L6tjx917_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_zitiW3U0, 2, m, &cDelay_zitiW3U0_sendMessage);
}

void Heavy_nts_reflection::cMsg_yahrYcDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_VCRXSEiA, 1, m, NULL);
}

void Heavy_nts_reflection::cTabhead_OegdHhEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AP8M8IT9, HV_BINOP_SUBTRACT, 0, m, &cBinop_AP8M8IT9_sendMessage);
}

void Heavy_nts_reflection::cMsg_DXZ8P4ys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mh1ZxYIi_sendMessage);
}

void Heavy_nts_reflection::cSystem_mh1ZxYIi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mbYIqlrf_sendMessage);
}

void Heavy_nts_reflection::cVar_JAKXAORa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uvxAtlJc_sendMessage(_c, 0, m);
}

void Heavy_nts_reflection::cDelay_qNQlLZby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qNQlLZby, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VV9ucoFY, 0, m, &cDelay_VV9ucoFY_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NvmUIKvR, 0, m, &sTabread_NvmUIKvR_sendMessage);
}

void Heavy_nts_reflection::cDelay_VV9ucoFY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VV9ucoFY, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NvmUIKvR, 0, m, &sTabread_NvmUIKvR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VV9ucoFY, 0, m, &cDelay_VV9ucoFY_sendMessage);
}

void Heavy_nts_reflection::sTabread_NvmUIKvR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Se0QPFw7, HV_BINOP_SUBTRACT, 0, m, &cBinop_Se0QPFw7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_nts_reflection::cBinop_dFA0m5kG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bwyrueOk, HV_BINOP_MAX, 0, m, &cBinop_bwyrueOk_sendMessage);
}

void Heavy_nts_reflection::cBinop_mbYIqlrf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dFA0m5kG, HV_BINOP_MULTIPLY, 0, m, &cBinop_dFA0m5kG_sendMessage);
}

void Heavy_nts_reflection::cBinop_AP8M8IT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ms1vgeJw_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NvmUIKvR, 0, m, &sTabread_NvmUIKvR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I9lGqv70_sendMessage);
}

void Heavy_nts_reflection::cSystem_ZPRjRjuq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Se0QPFw7, HV_BINOP_SUBTRACT, 1, m, &cBinop_Se0QPFw7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VV9ucoFY, 2, m, &cDelay_VV9ucoFY_sendMessage);
}

void Heavy_nts_reflection::cMsg_uvxAtlJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZPRjRjuq_sendMessage);
}

void Heavy_nts_reflection::cMsg_ms1vgeJw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qNQlLZby, 0, m, &cDelay_qNQlLZby_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VV9ucoFY, 0, m, &cDelay_VV9ucoFY_sendMessage);
}

void Heavy_nts_reflection::cMsg_8OkNnqle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_bwyrueOk, HV_BINOP_MAX, 1, m, &cBinop_bwyrueOk_sendMessage);
}

void Heavy_nts_reflection::cBinop_bwyrueOk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AP8M8IT9, HV_BINOP_SUBTRACT, 1, m, &cBinop_AP8M8IT9_sendMessage);
}

void Heavy_nts_reflection::cCast_I9lGqv70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qNQlLZby, 0, m, &cDelay_qNQlLZby_sendMessage);
}

void Heavy_nts_reflection::cBinop_601WHUh0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qNQlLZby, 2, m, &cDelay_qNQlLZby_sendMessage);
}

void Heavy_nts_reflection::cBinop_Se0QPFw7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_601WHUh0_sendMessage);
}

void Heavy_nts_reflection::cCast_EUxZYIcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JAKXAORa, 0, m, &cVar_JAKXAORa_sendMessage);
  cMsg_DXZ8P4ys_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OegdHhEr, 0, m, &cTabhead_OegdHhEr_sendMessage);
}

void Heavy_nts_reflection::cBinop_KeCWvEji_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kNqr9lLv, m);
}

void Heavy_nts_reflection::cBinop_mkfvAq0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.5f, 0, m, &cBinop_KeCWvEji_sendMessage);
}

void Heavy_nts_reflection::cBinop_9qEzvInH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XcpC9koR, m);
}

void Heavy_nts_reflection::cBinop_gl56KMlz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tvCu0ahS, m);
}

void Heavy_nts_reflection::cBinop_3oIlPye6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aO8kI9Dz, m);
}

void Heavy_nts_reflection::cReceive_vniOq5KR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_mkfvAq0K_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.2f, 0, m, &cBinop_3oIlPye6_sendMessage);
}

void Heavy_nts_reflection::cReceive_jQHxbHHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.871402f, 0, m, &cBinop_9qEzvInH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.882762f, 0, m, &cBinop_gl56KMlz_sendMessage);
}

void Heavy_nts_reflection::cReceive_GL5evOjQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GzGR0hTQ_sendMessage(_c, 0, m);
  cMsg_tvjnWnwG_sendMessage(_c, 0, m);
  cMsg_m6bcpn9V_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RzdIH43R, 0, m, &cVar_RzdIH43R_sendMessage);
  cMsg_HAjtaeAR_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Xxfj74pK, 0, m, &cTabhead_Xxfj74pK_sendMessage);
  cMsg_8OkNnqle_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JAKXAORa, 0, m, &cVar_JAKXAORa_sendMessage);
  cMsg_DXZ8P4ys_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OegdHhEr, 0, m, &cTabhead_OegdHhEr_sendMessage);
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
    __hv_tabread_f(&sTabread_MJ7usO4o, VOf(Bf0));
    __hv_varread_f(&sVarf_XcpC9koR, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(I0), VIf(I1), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_vCOQRffI, VIf(Bf2));
    __hv_tabread_f(&sTabread_NvmUIKvR, VOf(Bf2));
    __hv_varread_f(&sVarf_tvCu0ahS, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_VCRXSEiA, VIf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_aO8kI9Dz, VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_kNqr9lLv, VOf(Bf3));
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
