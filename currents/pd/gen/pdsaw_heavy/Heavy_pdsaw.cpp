/** Copyright (c) 2026 Charles Vestal. MIT License (LICENSE beside pdsaw.pd) */

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
  numBytes += sPhasor_k_init(&sPhasor_guCbPqrs, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_udMyNx3K);
  numBytes += sRPole_init(&sRPole_rzGRXSFe);
  numBytes += sLine_init(&sLine_ZoqHT2md);
  numBytes += cSlice_init(&cSlice_RT6Upskq, 2, 1);
  numBytes += cSlice_init(&cSlice_Y6liGSej, 1, 1);
  numBytes += cSlice_init(&cSlice_PAOiRFGc, 0, 1);
  numBytes += cVar_init_f(&cVar_OmbvJTTr, 0.0f);
  numBytes += cIf_init(&cIf_R7aylFEw, false);
  numBytes += cIf_init(&cIf_WuluvWqb, false);
  numBytes += cIf_init(&cIf_I2bsS9A6, false);
  numBytes += cIf_init(&cIf_cSUJM1uk, false);
  numBytes += cIf_init(&cIf_QBlFntVT, false);
  numBytes += cBinop_init(&cBinop_m9mS8Zw7, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_o1KE4RYF, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_zT8hbv4N, 22050.0f);
  numBytes += cBinop_init(&cBinop_vYlylkXb, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_5aZTuV5M, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Ci638nhZ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_C27IoRBp, 22050.0f);
  numBytes += cBinop_init(&cBinop_ImoFNAjW, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_J485wQCY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mckXmZxj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_yGtNQ2WB, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UTpsitm2_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Hs0mB5ZV_sendMessage);
      break;
    }
    case 0xF89F9F3E: { // cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0npCX0bx_sendMessage);
      break;
    }
    case 0xB1642755: { // volume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xkZW9lAl_sendMessage);
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


void Heavy_pdsaw::cSlice_RT6Upskq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_XqxyEt8i_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_Y6liGSej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_cSUJM1uk, 0, m, &cIf_cSUJM1uk_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_WuluvWqb, 0, m, &cIf_WuluvWqb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_PAOiRFGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_QBlFntVT, 0, m, &cIf_QBlFntVT_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_I2bsS9A6, 0, m, &cIf_I2bsS9A6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cVar_OmbvJTTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_swoiU18B_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_R7aylFEw, 0, m, &cIf_R7aylFEw_sendMessage);
}

void Heavy_pdsaw::cUnop_KlmUriPu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_58WvwtNX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_m9mS8Zw7, HV_BINOP_EQ, 1, m, &cBinop_m9mS8Zw7_sendMessage);
}

void Heavy_pdsaw::cUnop_vDryi49M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_58WvwtNX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_m9mS8Zw7, HV_BINOP_EQ, 1, m, &cBinop_m9mS8Zw7_sendMessage);
}

void Heavy_pdsaw::cIf_R7aylFEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_vDryi49M_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_KlmUriPu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_swoiU18B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_R7aylFEw, 1, m, &cIf_R7aylFEw_sendMessage);
}

void Heavy_pdsaw::cIf_WuluvWqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_qoneRSIx_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_I2bsS9A6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_tvuEXuiN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_cSUJM1uk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_qoneRSIx_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_QBlFntVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_tvuEXuiN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_XqxyEt8i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m9mS8Zw7, HV_BINOP_EQ, 0, m, &cBinop_m9mS8Zw7_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_4RPB315m_sendMessage);
}

void Heavy_pdsaw::cBinop_58WvwtNX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9gPLIit9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vQOytrAP_sendMessage);
}

void Heavy_pdsaw::cBinop_m9mS8Zw7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iAedzozj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yZJerLcC_sendMessage);
}

void Heavy_pdsaw::cCast_yZJerLcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_QBlFntVT, 1, m, &cIf_QBlFntVT_sendMessage);
}

void Heavy_pdsaw::cCast_iAedzozj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WuluvWqb, 1, m, &cIf_WuluvWqb_sendMessage);
}

void Heavy_pdsaw::cCast_vQOytrAP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_I2bsS9A6, 1, m, &cIf_I2bsS9A6_sendMessage);
}

void Heavy_pdsaw::cCast_9gPLIit9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cSUJM1uk, 1, m, &cIf_cSUJM1uk_sendMessage);
}

void Heavy_pdsaw::cBinop_4RPB315m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdsaw::cBinop_KQkBongo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_guCbPqrs, 0, m);
}

void Heavy_pdsaw::cBinop_tvuEXuiN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_WUg7CJAs_sendMessage);
}

void Heavy_pdsaw::cBinop_WUg7CJAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o1KE4RYF, HV_BINOP_POW, 1, m, &cBinop_o1KE4RYF_sendMessage);
  cMsg_OHDjy0cW_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_o1KE4RYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_KQkBongo_sendMessage);
}

void Heavy_pdsaw::cMsg_OHDjy0cW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_o1KE4RYF, HV_BINOP_POW, 0, m, &cBinop_o1KE4RYF_sendMessage);
}

void Heavy_pdsaw::cSwitchcase_qoneRSIx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H3A2MKlo_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_VbNMvKCM_sendMessage);
      break;
    }
  }
}

void Heavy_pdsaw::cCast_H3A2MKlo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZseAab8x_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cVar_zT8hbv4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vYlylkXb, HV_BINOP_MULTIPLY, 0, m, &cBinop_vYlylkXb_sendMessage);
}

void Heavy_pdsaw::cMsg_8xs4yIkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_736QBsE3_sendMessage);
}

void Heavy_pdsaw::cSystem_736QBsE3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wMEmmzz0_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_vYlylkXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Et6B0XKT_sendMessage);
}

void Heavy_pdsaw::cBinop_5dYzmTdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vYlylkXb, HV_BINOP_MULTIPLY, 1, m, &cBinop_vYlylkXb_sendMessage);
}

void Heavy_pdsaw::cMsg_wMEmmzz0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_5dYzmTdb_sendMessage);
}

void Heavy_pdsaw::cBinop_Et6B0XKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_cebT4lbx_sendMessage);
}

void Heavy_pdsaw::cBinop_cebT4lbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_AbMzgwTw_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ci638nhZ, m);
}

void Heavy_pdsaw::cBinop_AbMzgwTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5aZTuV5M, m);
}

void Heavy_pdsaw::cVar_C27IoRBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ImoFNAjW, HV_BINOP_MULTIPLY, 0, m, &cBinop_ImoFNAjW_sendMessage);
}

void Heavy_pdsaw::cMsg_YHqVgla7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_L5uX3rQo_sendMessage);
}

void Heavy_pdsaw::cSystem_L5uX3rQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MP8q3PSl_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_ImoFNAjW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Gi3YYEvn_sendMessage);
}

void Heavy_pdsaw::cBinop_nr48BoXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ImoFNAjW, HV_BINOP_MULTIPLY, 1, m, &cBinop_ImoFNAjW_sendMessage);
}

void Heavy_pdsaw::cMsg_MP8q3PSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_nr48BoXs_sendMessage);
}

void Heavy_pdsaw::cBinop_Gi3YYEvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_26uWWW6M_sendMessage);
}

void Heavy_pdsaw::cBinop_26uWWW6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_4WBFyqbM_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mckXmZxj, m);
}

void Heavy_pdsaw::cBinop_4WBFyqbM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_J485wQCY, m);
}

void Heavy_pdsaw::cMsg_ZseAab8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 300.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZoqHT2md, 0, m, NULL);
}

void Heavy_pdsaw::cBinop_VbNMvKCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7h0l5II5_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cMsg_7h0l5II5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 5.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZoqHT2md, 0, m, NULL);
}

void Heavy_pdsaw::cReceive_UTpsitm2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OmbvJTTr, 0, m, &cVar_OmbvJTTr_sendMessage);
  cMsg_8xs4yIkP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zT8hbv4N, 0, m, &cVar_zT8hbv4N_sendMessage);
  cMsg_YHqVgla7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_C27IoRBp, 0, m, &cVar_C27IoRBp_sendMessage);
}

void Heavy_pdsaw::cReceive_Hs0mB5ZV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_RT6Upskq, 0, m, &cSlice_RT6Upskq_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Y6liGSej, 0, m, &cSlice_Y6liGSej_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_PAOiRFGc, 0, m, &cSlice_PAOiRFGc_sendMessage);
}

void Heavy_pdsaw::cReceive_0npCX0bx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zT8hbv4N, 0, m, &cVar_zT8hbv4N_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_C27IoRBp, 0, m, &cVar_C27IoRBp_sendMessage);
}

void Heavy_pdsaw::cReceive_xkZW9lAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yGtNQ2WB, m);
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
    __hv_phasor_k_f(&sPhasor_guCbPqrs, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_Ci638nhZ, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_5aZTuV5M, VOf(Bf1));
    __hv_rpole_f(&sRPole_udMyNx3K, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_mckXmZxj, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_J485wQCY, VOf(Bf1));
    __hv_rpole_f(&sRPole_rzGRXSFe, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_ZoqHT2md, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_yGtNQ2WB, VOf(Bf1));
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
