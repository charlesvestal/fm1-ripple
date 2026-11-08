/** Copyright (c) 2026 Charles Vestal. MIT License (LICENSE beside pdsaw.pd) */

#include "Heavy_pdsaw.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_pdsaw *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_pdsaw_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_pdsaw));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_pdsaw(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_pdsaw_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_pdsaw));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_pdsaw(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_pdsaw_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_pdsaw();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_pdsaw::Heavy_pdsaw(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_Zz5day5C, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_7rpj7Ehl);
  numBytes += sRPole_init(&sRPole_MPeS2y1m);
  numBytes += sLine_init(&sLine_h8K4lcro);
  numBytes += cSlice_init(&cSlice_kurZ5LwT, 2, 1);
  numBytes += cSlice_init(&cSlice_VGXy8p8p, 1, 1);
  numBytes += cSlice_init(&cSlice_iMgsV9qY, 0, 1);
  numBytes += cVar_init_f(&cVar_KberwbEf, 0.0f);
  numBytes += cIf_init(&cIf_vDvOqh4O, false);
  numBytes += cIf_init(&cIf_2tISY5AZ, false);
  numBytes += cIf_init(&cIf_XgIFNrYG, false);
  numBytes += cIf_init(&cIf_nHQQI7fP, false);
  numBytes += cIf_init(&cIf_jCgveRtn, false);
  numBytes += cBinop_init(&cBinop_sUjOLVIF, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_AkQc8Q05, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_QgpFzdnK, 22050.0f);
  numBytes += cBinop_init(&cBinop_jJco5vtj, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_001UPHhx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_S1o93s5c, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_c0wEnanR, 22050.0f);
  numBytes += cBinop_init(&cBinop_OxyRCc5C, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_J8BXJ3Lu, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qRiiELvQ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TNAPkP4g, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rVtIpJDU_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aALCa4n2_sendMessage);
      break;
    }
    case 0xF89F9F3E: { // cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QGnEkZRr_sendMessage);
      break;
    }
    case 0xB1642755: { // volume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nb9uH864_sendMessage);
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


void Heavy_pdsaw::cSlice_kurZ5LwT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_bjGhTJLH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_VGXy8p8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_nHQQI7fP, 0, m, &cIf_nHQQI7fP_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_2tISY5AZ, 0, m, &cIf_2tISY5AZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_iMgsV9qY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_jCgveRtn, 0, m, &cIf_jCgveRtn_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_XgIFNrYG, 0, m, &cIf_XgIFNrYG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cVar_KberwbEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_AKgLZB0F_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_vDvOqh4O, 0, m, &cIf_vDvOqh4O_sendMessage);
}

void Heavy_pdsaw::cUnop_OnkRhI0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_VNbvrdgS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sUjOLVIF, HV_BINOP_EQ, 1, m, &cBinop_sUjOLVIF_sendMessage);
}

void Heavy_pdsaw::cUnop_BUZxF642_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_VNbvrdgS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sUjOLVIF, HV_BINOP_EQ, 1, m, &cBinop_sUjOLVIF_sendMessage);
}

void Heavy_pdsaw::cIf_vDvOqh4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_BUZxF642_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_OnkRhI0m_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_AKgLZB0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vDvOqh4O, 1, m, &cIf_vDvOqh4O_sendMessage);
}

void Heavy_pdsaw::cIf_2tISY5AZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_ZnH0svOp_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_XgIFNrYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_OguDciRa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_nHQQI7fP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_ZnH0svOp_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_jCgveRtn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_OguDciRa_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_bjGhTJLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sUjOLVIF, HV_BINOP_EQ, 0, m, &cBinop_sUjOLVIF_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_a93dWYWn_sendMessage);
}

void Heavy_pdsaw::cBinop_VNbvrdgS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wdGOC9Wb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_C0QlzX9J_sendMessage);
}

void Heavy_pdsaw::cBinop_sUjOLVIF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b1fgwfEY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cFQBO6Jl_sendMessage);
}

void Heavy_pdsaw::cCast_cFQBO6Jl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jCgveRtn, 1, m, &cIf_jCgveRtn_sendMessage);
}

void Heavy_pdsaw::cCast_b1fgwfEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2tISY5AZ, 1, m, &cIf_2tISY5AZ_sendMessage);
}

void Heavy_pdsaw::cCast_wdGOC9Wb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nHQQI7fP, 1, m, &cIf_nHQQI7fP_sendMessage);
}

void Heavy_pdsaw::cCast_C0QlzX9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XgIFNrYG, 1, m, &cIf_XgIFNrYG_sendMessage);
}

void Heavy_pdsaw::cBinop_a93dWYWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdsaw::cBinop_DsWDWtrd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Zz5day5C, 0, m);
}

void Heavy_pdsaw::cBinop_OguDciRa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_YEQbjSge_sendMessage);
}

void Heavy_pdsaw::cBinop_YEQbjSge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AkQc8Q05, HV_BINOP_POW, 1, m, &cBinop_AkQc8Q05_sendMessage);
  cMsg_im3qnviX_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_AkQc8Q05_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_DsWDWtrd_sendMessage);
}

void Heavy_pdsaw::cMsg_im3qnviX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AkQc8Q05, HV_BINOP_POW, 0, m, &cBinop_AkQc8Q05_sendMessage);
}

void Heavy_pdsaw::cSwitchcase_ZnH0svOp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c27KytTL_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_vsvAn1Tv_sendMessage);
      break;
    }
  }
}

void Heavy_pdsaw::cCast_c27KytTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xgI48XgM_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cVar_QgpFzdnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jJco5vtj, HV_BINOP_MULTIPLY, 0, m, &cBinop_jJco5vtj_sendMessage);
}

void Heavy_pdsaw::cMsg_NkP356fz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SmXKohsH_sendMessage);
}

void Heavy_pdsaw::cSystem_SmXKohsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cb9SZNNr_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_jJco5vtj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_aMDabU4t_sendMessage);
}

void Heavy_pdsaw::cBinop_zskrvCJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jJco5vtj, HV_BINOP_MULTIPLY, 1, m, &cBinop_jJco5vtj_sendMessage);
}

void Heavy_pdsaw::cMsg_cb9SZNNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zskrvCJ3_sendMessage);
}

void Heavy_pdsaw::cBinop_aMDabU4t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_qySxbF3l_sendMessage);
}

void Heavy_pdsaw::cBinop_qySxbF3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_wrsoQ4JB_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_S1o93s5c, m);
}

void Heavy_pdsaw::cBinop_wrsoQ4JB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_001UPHhx, m);
}

void Heavy_pdsaw::cVar_c0wEnanR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OxyRCc5C, HV_BINOP_MULTIPLY, 0, m, &cBinop_OxyRCc5C_sendMessage);
}

void Heavy_pdsaw::cMsg_mLa2wGkT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ELeM7UDn_sendMessage);
}

void Heavy_pdsaw::cSystem_ELeM7UDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IoLtbZCU_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_OxyRCc5C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Xb3e27XD_sendMessage);
}

void Heavy_pdsaw::cBinop_YBsQ27J8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OxyRCc5C, HV_BINOP_MULTIPLY, 1, m, &cBinop_OxyRCc5C_sendMessage);
}

void Heavy_pdsaw::cMsg_IoLtbZCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YBsQ27J8_sendMessage);
}

void Heavy_pdsaw::cBinop_Xb3e27XD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OQjFOpIA_sendMessage);
}

void Heavy_pdsaw::cBinop_OQjFOpIA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_46VV0Cnp_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_qRiiELvQ, m);
}

void Heavy_pdsaw::cBinop_46VV0Cnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_J8BXJ3Lu, m);
}

void Heavy_pdsaw::cMsg_xgI48XgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 300.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_h8K4lcro, 0, m, NULL);
}

void Heavy_pdsaw::cBinop_vsvAn1Tv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VqhXJpDp_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cMsg_VqhXJpDp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 5.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_h8K4lcro, 0, m, NULL);
}

void Heavy_pdsaw::cReceive_rVtIpJDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KberwbEf, 0, m, &cVar_KberwbEf_sendMessage);
  cMsg_NkP356fz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QgpFzdnK, 0, m, &cVar_QgpFzdnK_sendMessage);
  cMsg_mLa2wGkT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_c0wEnanR, 0, m, &cVar_c0wEnanR_sendMessage);
}

void Heavy_pdsaw::cReceive_aALCa4n2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_kurZ5LwT, 0, m, &cSlice_kurZ5LwT_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_VGXy8p8p, 0, m, &cSlice_VGXy8p8p_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_iMgsV9qY, 0, m, &cSlice_iMgsV9qY_sendMessage);
}

void Heavy_pdsaw::cReceive_QGnEkZRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QgpFzdnK, 0, m, &cVar_QgpFzdnK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_c0wEnanR, 0, m, &cVar_c0wEnanR_sendMessage);
}

void Heavy_pdsaw::cReceive_nb9uH864_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TNAPkP4g, m);
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
    __hv_phasor_k_f(&sPhasor_Zz5day5C, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_S1o93s5c, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_001UPHhx, VOf(Bf1));
    __hv_rpole_f(&sRPole_7rpj7Ehl, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_qRiiELvQ, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_J8BXJ3Lu, VOf(Bf1));
    __hv_rpole_f(&sRPole_MPeS2y1m, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_h8K4lcro, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_TNAPkP4g, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));

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
