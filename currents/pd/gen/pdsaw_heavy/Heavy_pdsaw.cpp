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
  numBytes += sPhasor_k_init(&sPhasor_Zjp1CKCJ, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_vhqCX8XR);
  numBytes += sRPole_init(&sRPole_S4YRptZA);
  numBytes += sLine_init(&sLine_JnRORbN9);
  numBytes += cSlice_init(&cSlice_r11d2E0d, 2, 1);
  numBytes += cSlice_init(&cSlice_NqRsfq73, 1, 1);
  numBytes += cSlice_init(&cSlice_lZ2A2aCV, 0, 1);
  numBytes += cVar_init_f(&cVar_GNWsGOcI, 0.0f);
  numBytes += cIf_init(&cIf_grW2zatO, false);
  numBytes += cIf_init(&cIf_jKRu109d, false);
  numBytes += cIf_init(&cIf_BDAMpGhw, false);
  numBytes += cIf_init(&cIf_sDrQ0XuD, false);
  numBytes += cIf_init(&cIf_96Gc4Pdf, false);
  numBytes += cBinop_init(&cBinop_sFsgJhow, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_cMEZYxNi, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_yYAp1Ssb, 22050.0f);
  numBytes += cBinop_init(&cBinop_KxxY9zbc, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_U2lbsruq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_QwKsBRol, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5aBDZiNQ, 22050.0f);
  numBytes += cBinop_init(&cBinop_ikO9GwnP, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_fTDH3Pfi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fjoVNDUU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hiXMwwtz, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4yR2NfdB_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_a1Gs5xET_sendMessage);
      break;
    }
    case 0xF89F9F3E: { // cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JF76JLoQ_sendMessage);
      break;
    }
    case 0xB1642755: { // volume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_H7dFrlhh_sendMessage);
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


void Heavy_pdsaw::cSlice_r11d2E0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_saeofySJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_NqRsfq73_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_sDrQ0XuD, 0, m, &cIf_sDrQ0XuD_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_jKRu109d, 0, m, &cIf_jKRu109d_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_lZ2A2aCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_96Gc4Pdf, 0, m, &cIf_96Gc4Pdf_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_BDAMpGhw, 0, m, &cIf_BDAMpGhw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cVar_GNWsGOcI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_dofg1Tt1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_grW2zatO, 0, m, &cIf_grW2zatO_sendMessage);
}

void Heavy_pdsaw::cUnop_WthMU6wH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_G1GPB1uL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sFsgJhow, HV_BINOP_EQ, 1, m, &cBinop_sFsgJhow_sendMessage);
}

void Heavy_pdsaw::cUnop_uBYO7Tpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_G1GPB1uL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sFsgJhow, HV_BINOP_EQ, 1, m, &cBinop_sFsgJhow_sendMessage);
}

void Heavy_pdsaw::cIf_grW2zatO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_uBYO7Tpt_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_WthMU6wH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_dofg1Tt1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_grW2zatO, 1, m, &cIf_grW2zatO_sendMessage);
}

void Heavy_pdsaw::cIf_jKRu109d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_JTyBeJhx_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_BDAMpGhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_HeIBfiHo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_sDrQ0XuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_JTyBeJhx_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_96Gc4Pdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_HeIBfiHo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_saeofySJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sFsgJhow, HV_BINOP_EQ, 0, m, &cBinop_sFsgJhow_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_vG6ehvDL_sendMessage);
}

void Heavy_pdsaw::cBinop_G1GPB1uL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CqdGbaQ3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TUiW7J6d_sendMessage);
}

void Heavy_pdsaw::cBinop_sFsgJhow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JEfsUdn8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4fsanHnL_sendMessage);
}

void Heavy_pdsaw::cCast_4fsanHnL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_96Gc4Pdf, 1, m, &cIf_96Gc4Pdf_sendMessage);
}

void Heavy_pdsaw::cCast_JEfsUdn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_jKRu109d, 1, m, &cIf_jKRu109d_sendMessage);
}

void Heavy_pdsaw::cCast_TUiW7J6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BDAMpGhw, 1, m, &cIf_BDAMpGhw_sendMessage);
}

void Heavy_pdsaw::cCast_CqdGbaQ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sDrQ0XuD, 1, m, &cIf_sDrQ0XuD_sendMessage);
}

void Heavy_pdsaw::cBinop_vG6ehvDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdsaw::cBinop_6IhrZWN5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Zjp1CKCJ, 0, m);
}

void Heavy_pdsaw::cBinop_HeIBfiHo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_9TNjpUdg_sendMessage);
}

void Heavy_pdsaw::cBinop_9TNjpUdg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cMEZYxNi, HV_BINOP_POW, 1, m, &cBinop_cMEZYxNi_sendMessage);
  cMsg_aJhT9F3u_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_cMEZYxNi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_6IhrZWN5_sendMessage);
}

void Heavy_pdsaw::cMsg_aJhT9F3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cMEZYxNi, HV_BINOP_POW, 0, m, &cBinop_cMEZYxNi_sendMessage);
}

void Heavy_pdsaw::cSwitchcase_JTyBeJhx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W3PkNhPb_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_WEMgHAdn_sendMessage);
      break;
    }
  }
}

void Heavy_pdsaw::cCast_W3PkNhPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_thVt3c6Q_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cVar_yYAp1Ssb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KxxY9zbc, HV_BINOP_MULTIPLY, 0, m, &cBinop_KxxY9zbc_sendMessage);
}

void Heavy_pdsaw::cMsg_OOkMbAuM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Kwmu1KBx_sendMessage);
}

void Heavy_pdsaw::cSystem_Kwmu1KBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PvYhsBZ5_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_KxxY9zbc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_6Ab3idV8_sendMessage);
}

void Heavy_pdsaw::cBinop_ep8qN2j1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KxxY9zbc, HV_BINOP_MULTIPLY, 1, m, &cBinop_KxxY9zbc_sendMessage);
}

void Heavy_pdsaw::cMsg_PvYhsBZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ep8qN2j1_sendMessage);
}

void Heavy_pdsaw::cBinop_6Ab3idV8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0IFi5AWL_sendMessage);
}

void Heavy_pdsaw::cBinop_0IFi5AWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Fn3pFOMV_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_QwKsBRol, m);
}

void Heavy_pdsaw::cBinop_Fn3pFOMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_U2lbsruq, m);
}

void Heavy_pdsaw::cVar_5aBDZiNQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ikO9GwnP, HV_BINOP_MULTIPLY, 0, m, &cBinop_ikO9GwnP_sendMessage);
}

void Heavy_pdsaw::cMsg_uUhRKJkG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CEzhRsnU_sendMessage);
}

void Heavy_pdsaw::cSystem_CEzhRsnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7GRDAQ0k_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_ikO9GwnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_NAjMMR0S_sendMessage);
}

void Heavy_pdsaw::cBinop_rcPfssei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ikO9GwnP, HV_BINOP_MULTIPLY, 1, m, &cBinop_ikO9GwnP_sendMessage);
}

void Heavy_pdsaw::cMsg_7GRDAQ0k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rcPfssei_sendMessage);
}

void Heavy_pdsaw::cBinop_NAjMMR0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ffF4Isfd_sendMessage);
}

void Heavy_pdsaw::cBinop_ffF4Isfd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_bEo2FZlO_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fjoVNDUU, m);
}

void Heavy_pdsaw::cBinop_bEo2FZlO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fTDH3Pfi, m);
}

void Heavy_pdsaw::cMsg_thVt3c6Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 300.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_JnRORbN9, 0, m, NULL);
}

void Heavy_pdsaw::cBinop_WEMgHAdn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sVDtY2Yj_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cMsg_sVDtY2Yj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 5.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_JnRORbN9, 0, m, NULL);
}

void Heavy_pdsaw::cReceive_4yR2NfdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GNWsGOcI, 0, m, &cVar_GNWsGOcI_sendMessage);
  cMsg_OOkMbAuM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yYAp1Ssb, 0, m, &cVar_yYAp1Ssb_sendMessage);
  cMsg_uUhRKJkG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5aBDZiNQ, 0, m, &cVar_5aBDZiNQ_sendMessage);
}

void Heavy_pdsaw::cReceive_a1Gs5xET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_r11d2E0d, 0, m, &cSlice_r11d2E0d_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_NqRsfq73, 0, m, &cSlice_NqRsfq73_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_lZ2A2aCV, 0, m, &cSlice_lZ2A2aCV_sendMessage);
}

void Heavy_pdsaw::cReceive_JF76JLoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yYAp1Ssb, 0, m, &cVar_yYAp1Ssb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5aBDZiNQ, 0, m, &cVar_5aBDZiNQ_sendMessage);
}

void Heavy_pdsaw::cReceive_H7dFrlhh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hiXMwwtz, m);
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
    __hv_phasor_k_f(&sPhasor_Zjp1CKCJ, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_QwKsBRol, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_U2lbsruq, VOf(Bf1));
    __hv_rpole_f(&sRPole_vhqCX8XR, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_fjoVNDUU, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_fTDH3Pfi, VOf(Bf1));
    __hv_rpole_f(&sRPole_S4YRptZA, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_JnRORbN9, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_hiXMwwtz, VOf(Bf1));
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
