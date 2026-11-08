/** the author of pdsaw.pd */

#include "Heavy_pdsaw.hpp"



#define Context(_c) static_cast<Heavy_pdsaw *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_pdsaw::Heavy_pdsaw(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_74mfwU5F, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_kyrghJRE);
  numBytes += sRPole_init(&sRPole_04JfTES0);
  numBytes += sLine_init(&sLine_fu3INTaL);
  numBytes += cSlice_init(&cSlice_6ts2TWQP, 2, 1);
  numBytes += cSlice_init(&cSlice_LIHhLfFw, 1, 1);
  numBytes += cSlice_init(&cSlice_1PieBEOA, 0, 1);
  numBytes += cVar_init_f(&cVar_rouqzgNl, 0.0f);
  numBytes += cIf_init(&cIf_8EZ6dlQX, false);
  numBytes += cIf_init(&cIf_qdliOQSo, false);
  numBytes += cIf_init(&cIf_uOltA4t2, false);
  numBytes += cIf_init(&cIf_gGxCmhCi, false);
  numBytes += cIf_init(&cIf_K65KWu5Z, false);
  numBytes += cBinop_init(&cBinop_gIoYqEwk, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_x3ZiWvbU, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_LGKQRo9N, 22050.0f);
  numBytes += cBinop_init(&cBinop_PMIjHNuy, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_PsqfOm6K, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rlwkaNKU, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_JgoiKODY, 22050.0f);
  numBytes += cBinop_init(&cBinop_poz37oSx, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_eLjvU0zo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_miRAywdd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fjJv5Tsg, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6KFSZIXK_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6HliV4qE_sendMessage);
      break;
    }
    case 0xF89F9F3E: { // cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dBwbISsT_sendMessage);
      break;
    }
    case 0xB1642755: { // volume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0G3AU8Tl_sendMessage);
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


void Heavy_pdsaw::cSlice_6ts2TWQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_fwyMJvl8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_LIHhLfFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_gGxCmhCi, 0, m, &cIf_gGxCmhCi_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_qdliOQSo, 0, m, &cIf_qdliOQSo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_1PieBEOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_K65KWu5Z, 0, m, &cIf_K65KWu5Z_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_uOltA4t2, 0, m, &cIf_uOltA4t2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cVar_rouqzgNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_oZuTFOW1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_8EZ6dlQX, 0, m, &cIf_8EZ6dlQX_sendMessage);
}

void Heavy_pdsaw::cUnop_wFh83myk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_U8vlP622_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gIoYqEwk, HV_BINOP_EQ, 1, m, &cBinop_gIoYqEwk_sendMessage);
}

void Heavy_pdsaw::cUnop_RX3zFIet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_U8vlP622_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gIoYqEwk, HV_BINOP_EQ, 1, m, &cBinop_gIoYqEwk_sendMessage);
}

void Heavy_pdsaw::cIf_8EZ6dlQX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_RX3zFIet_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_wFh83myk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_oZuTFOW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8EZ6dlQX, 1, m, &cIf_8EZ6dlQX_sendMessage);
}

void Heavy_pdsaw::cIf_qdliOQSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_RVynMHbo_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_uOltA4t2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_L6D0Im5t_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_gGxCmhCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_RVynMHbo_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_K65KWu5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_L6D0Im5t_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_fwyMJvl8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gIoYqEwk, HV_BINOP_EQ, 0, m, &cBinop_gIoYqEwk_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_n4Mihamw_sendMessage);
}

void Heavy_pdsaw::cBinop_U8vlP622_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_t3G7m9DB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wsCaaOX8_sendMessage);
}

void Heavy_pdsaw::cBinop_gIoYqEwk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eU8HmpOG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XrMmuR0d_sendMessage);
}

void Heavy_pdsaw::cCast_XrMmuR0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_K65KWu5Z, 1, m, &cIf_K65KWu5Z_sendMessage);
}

void Heavy_pdsaw::cCast_eU8HmpOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qdliOQSo, 1, m, &cIf_qdliOQSo_sendMessage);
}

void Heavy_pdsaw::cCast_wsCaaOX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uOltA4t2, 1, m, &cIf_uOltA4t2_sendMessage);
}

void Heavy_pdsaw::cCast_t3G7m9DB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gGxCmhCi, 1, m, &cIf_gGxCmhCi_sendMessage);
}

void Heavy_pdsaw::cBinop_n4Mihamw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdsaw::cBinop_iYshTINg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_74mfwU5F, 0, m);
}

void Heavy_pdsaw::cBinop_L6D0Im5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_gK28eChs_sendMessage);
}

void Heavy_pdsaw::cBinop_gK28eChs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x3ZiWvbU, HV_BINOP_POW, 1, m, &cBinop_x3ZiWvbU_sendMessage);
  cMsg_ygabFWoS_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_x3ZiWvbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_iYshTINg_sendMessage);
}

void Heavy_pdsaw::cMsg_ygabFWoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_x3ZiWvbU, HV_BINOP_POW, 0, m, &cBinop_x3ZiWvbU_sendMessage);
}

void Heavy_pdsaw::cSwitchcase_RVynMHbo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mUh9j2P3_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_5PgAcK2Q_sendMessage);
      break;
    }
  }
}

void Heavy_pdsaw::cCast_mUh9j2P3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QrRXPwn8_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cVar_LGKQRo9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PMIjHNuy, HV_BINOP_MULTIPLY, 0, m, &cBinop_PMIjHNuy_sendMessage);
}

void Heavy_pdsaw::cMsg_N9rqEHkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8Pczldhr_sendMessage);
}

void Heavy_pdsaw::cSystem_8Pczldhr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SNVe1NgZ_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_PMIjHNuy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_cH2Hj7iD_sendMessage);
}

void Heavy_pdsaw::cBinop_OxTLnYx0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PMIjHNuy, HV_BINOP_MULTIPLY, 1, m, &cBinop_PMIjHNuy_sendMessage);
}

void Heavy_pdsaw::cMsg_SNVe1NgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_OxTLnYx0_sendMessage);
}

void Heavy_pdsaw::cBinop_cH2Hj7iD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_BpiZluT1_sendMessage);
}

void Heavy_pdsaw::cBinop_BpiZluT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_3AAIuYT6_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rlwkaNKU, m);
}

void Heavy_pdsaw::cBinop_3AAIuYT6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PsqfOm6K, m);
}

void Heavy_pdsaw::cVar_JgoiKODY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_poz37oSx, HV_BINOP_MULTIPLY, 0, m, &cBinop_poz37oSx_sendMessage);
}

void Heavy_pdsaw::cMsg_i6M4FBiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vFrDGTJG_sendMessage);
}

void Heavy_pdsaw::cSystem_vFrDGTJG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dKdYN1lv_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_poz37oSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_wjB6IR1Z_sendMessage);
}

void Heavy_pdsaw::cBinop_neFivVI3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_poz37oSx, HV_BINOP_MULTIPLY, 1, m, &cBinop_poz37oSx_sendMessage);
}

void Heavy_pdsaw::cMsg_dKdYN1lv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_neFivVI3_sendMessage);
}

void Heavy_pdsaw::cBinop_wjB6IR1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gv9S2ZjB_sendMessage);
}

void Heavy_pdsaw::cBinop_gv9S2ZjB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_gXjMgidP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_miRAywdd, m);
}

void Heavy_pdsaw::cBinop_gXjMgidP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eLjvU0zo, m);
}

void Heavy_pdsaw::cMsg_QrRXPwn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 300.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fu3INTaL, 0, m, NULL);
}

void Heavy_pdsaw::cBinop_5PgAcK2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V4nEmIlE_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cMsg_V4nEmIlE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 5.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fu3INTaL, 0, m, NULL);
}

void Heavy_pdsaw::cReceive_6KFSZIXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rouqzgNl, 0, m, &cVar_rouqzgNl_sendMessage);
  cMsg_N9rqEHkY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LGKQRo9N, 0, m, &cVar_LGKQRo9N_sendMessage);
  cMsg_i6M4FBiI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JgoiKODY, 0, m, &cVar_JgoiKODY_sendMessage);
}

void Heavy_pdsaw::cReceive_6HliV4qE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_6ts2TWQP, 0, m, &cSlice_6ts2TWQP_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_LIHhLfFw, 0, m, &cSlice_LIHhLfFw_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1PieBEOA, 0, m, &cSlice_1PieBEOA_sendMessage);
}

void Heavy_pdsaw::cReceive_dBwbISsT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LGKQRo9N, 0, m, &cVar_LGKQRo9N_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JgoiKODY, 0, m, &cVar_JgoiKODY_sendMessage);
}

void Heavy_pdsaw::cReceive_0G3AU8Tl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fjJv5Tsg, m);
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
    __hv_phasor_k_f(&sPhasor_74mfwU5F, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_rlwkaNKU, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_PsqfOm6K, VOf(Bf1));
    __hv_rpole_f(&sRPole_kyrghJRE, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_miRAywdd, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_eLjvU0zo, VOf(Bf1));
    __hv_rpole_f(&sRPole_04JfTES0, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_fu3INTaL, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_fjJv5Tsg, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));

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
