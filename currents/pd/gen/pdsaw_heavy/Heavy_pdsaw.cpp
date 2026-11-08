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
  numBytes += sPhasor_k_init(&sPhasor_hbkzo038, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_6Mg7fcL6);
  numBytes += sRPole_init(&sRPole_5UvVHRTG);
  numBytes += sLine_init(&sLine_b1rIhcf8);
  numBytes += cSlice_init(&cSlice_xLbtwR4Z, 2, 1);
  numBytes += cSlice_init(&cSlice_aQZQwOb7, 1, 1);
  numBytes += cSlice_init(&cSlice_678CCVQL, 0, 1);
  numBytes += cVar_init_f(&cVar_Rh6D4HfK, 0.0f);
  numBytes += cIf_init(&cIf_unrYsnsU, false);
  numBytes += cIf_init(&cIf_mGHw4LtZ, false);
  numBytes += cIf_init(&cIf_yEDrA5lL, false);
  numBytes += cIf_init(&cIf_kBgIBkJI, false);
  numBytes += cIf_init(&cIf_N89A4T7g, false);
  numBytes += cBinop_init(&cBinop_UscDYobC, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_rVLoSt2i, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_1e684rX4, 22050.0f);
  numBytes += cBinop_init(&cBinop_Tnr6TqRK, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_nQTzDnmp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fEeBzckf, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_QubDuo1a, 22050.0f);
  numBytes += cBinop_init(&cBinop_gGVxuMP3, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_SfLb6SOZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nrQtjUpO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sHDHWCMy, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Na6NbkI6_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EO0bBHQe_sendMessage);
      break;
    }
    case 0xF89F9F3E: { // cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CzzTMzOO_sendMessage);
      break;
    }
    case 0xB1642755: { // volume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xlbSCN1A_sendMessage);
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


void Heavy_pdsaw::cSlice_xLbtwR4Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_HcwrDtPR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_aQZQwOb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_kBgIBkJI, 0, m, &cIf_kBgIBkJI_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_mGHw4LtZ, 0, m, &cIf_mGHw4LtZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_678CCVQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_N89A4T7g, 0, m, &cIf_N89A4T7g_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_yEDrA5lL, 0, m, &cIf_yEDrA5lL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cVar_Rh6D4HfK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_kM47NJU4_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_unrYsnsU, 0, m, &cIf_unrYsnsU_sendMessage);
}

void Heavy_pdsaw::cUnop_7XM23Onz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_JYoxyqc8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UscDYobC, HV_BINOP_EQ, 1, m, &cBinop_UscDYobC_sendMessage);
}

void Heavy_pdsaw::cUnop_moAXjNLX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_JYoxyqc8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UscDYobC, HV_BINOP_EQ, 1, m, &cBinop_UscDYobC_sendMessage);
}

void Heavy_pdsaw::cIf_unrYsnsU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_moAXjNLX_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7XM23Onz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_kM47NJU4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_unrYsnsU, 1, m, &cIf_unrYsnsU_sendMessage);
}

void Heavy_pdsaw::cIf_mGHw4LtZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_Mb6E4V5w_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_yEDrA5lL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_5GQIFCFZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_kBgIBkJI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_Mb6E4V5w_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_N89A4T7g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_5GQIFCFZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_HcwrDtPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UscDYobC, HV_BINOP_EQ, 0, m, &cBinop_UscDYobC_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_GufctK9Y_sendMessage);
}

void Heavy_pdsaw::cBinop_JYoxyqc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IdingQXa_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_C5w4U9z3_sendMessage);
}

void Heavy_pdsaw::cBinop_UscDYobC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MhgRPOho_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qjT8JhfR_sendMessage);
}

void Heavy_pdsaw::cCast_qjT8JhfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_N89A4T7g, 1, m, &cIf_N89A4T7g_sendMessage);
}

void Heavy_pdsaw::cCast_MhgRPOho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mGHw4LtZ, 1, m, &cIf_mGHw4LtZ_sendMessage);
}

void Heavy_pdsaw::cCast_C5w4U9z3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yEDrA5lL, 1, m, &cIf_yEDrA5lL_sendMessage);
}

void Heavy_pdsaw::cCast_IdingQXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kBgIBkJI, 1, m, &cIf_kBgIBkJI_sendMessage);
}

void Heavy_pdsaw::cBinop_GufctK9Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdsaw::cBinop_PdHklCR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_hbkzo038, 0, m);
}

void Heavy_pdsaw::cBinop_5GQIFCFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_ITJ6REiz_sendMessage);
}

void Heavy_pdsaw::cBinop_ITJ6REiz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rVLoSt2i, HV_BINOP_POW, 1, m, &cBinop_rVLoSt2i_sendMessage);
  cMsg_iRp55xpE_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_rVLoSt2i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_PdHklCR9_sendMessage);
}

void Heavy_pdsaw::cMsg_iRp55xpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rVLoSt2i, HV_BINOP_POW, 0, m, &cBinop_rVLoSt2i_sendMessage);
}

void Heavy_pdsaw::cSwitchcase_Mb6E4V5w_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IUNXhhLu_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_Uwupubm7_sendMessage);
      break;
    }
  }
}

void Heavy_pdsaw::cCast_IUNXhhLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_x1F8b14r_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cVar_1e684rX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tnr6TqRK, HV_BINOP_MULTIPLY, 0, m, &cBinop_Tnr6TqRK_sendMessage);
}

void Heavy_pdsaw::cMsg_azDf0ghw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RNtFCKlM_sendMessage);
}

void Heavy_pdsaw::cSystem_RNtFCKlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3ZG1wpfF_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_Tnr6TqRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_BtJVmpQ0_sendMessage);
}

void Heavy_pdsaw::cBinop_BFhOA3el_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tnr6TqRK, HV_BINOP_MULTIPLY, 1, m, &cBinop_Tnr6TqRK_sendMessage);
}

void Heavy_pdsaw::cMsg_3ZG1wpfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_BFhOA3el_sendMessage);
}

void Heavy_pdsaw::cBinop_BtJVmpQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_IZq8qrjj_sendMessage);
}

void Heavy_pdsaw::cBinop_IZq8qrjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ceN3tRNe_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fEeBzckf, m);
}

void Heavy_pdsaw::cBinop_ceN3tRNe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nQTzDnmp, m);
}

void Heavy_pdsaw::cVar_QubDuo1a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gGVxuMP3, HV_BINOP_MULTIPLY, 0, m, &cBinop_gGVxuMP3_sendMessage);
}

void Heavy_pdsaw::cMsg_lFDWZk1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LRCQYlYs_sendMessage);
}

void Heavy_pdsaw::cSystem_LRCQYlYs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZtZiWgEn_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_gGVxuMP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_11UCNVbC_sendMessage);
}

void Heavy_pdsaw::cBinop_fBfY80tT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gGVxuMP3, HV_BINOP_MULTIPLY, 1, m, &cBinop_gGVxuMP3_sendMessage);
}

void Heavy_pdsaw::cMsg_ZtZiWgEn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_fBfY80tT_sendMessage);
}

void Heavy_pdsaw::cBinop_11UCNVbC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_3tQpqzrP_sendMessage);
}

void Heavy_pdsaw::cBinop_3tQpqzrP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_SRHR0rCN_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_nrQtjUpO, m);
}

void Heavy_pdsaw::cBinop_SRHR0rCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SfLb6SOZ, m);
}

void Heavy_pdsaw::cMsg_x1F8b14r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 300.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_b1rIhcf8, 0, m, NULL);
}

void Heavy_pdsaw::cBinop_Uwupubm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Mw2w1UwA_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cMsg_Mw2w1UwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 5.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_b1rIhcf8, 0, m, NULL);
}

void Heavy_pdsaw::cReceive_Na6NbkI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Rh6D4HfK, 0, m, &cVar_Rh6D4HfK_sendMessage);
  cMsg_azDf0ghw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1e684rX4, 0, m, &cVar_1e684rX4_sendMessage);
  cMsg_lFDWZk1Y_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QubDuo1a, 0, m, &cVar_QubDuo1a_sendMessage);
}

void Heavy_pdsaw::cReceive_EO0bBHQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_xLbtwR4Z, 0, m, &cSlice_xLbtwR4Z_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_aQZQwOb7, 0, m, &cSlice_aQZQwOb7_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_678CCVQL, 0, m, &cSlice_678CCVQL_sendMessage);
}

void Heavy_pdsaw::cReceive_CzzTMzOO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1e684rX4, 0, m, &cVar_1e684rX4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_QubDuo1a, 0, m, &cVar_QubDuo1a_sendMessage);
}

void Heavy_pdsaw::cReceive_xlbSCN1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sHDHWCMy, m);
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
    __hv_phasor_k_f(&sPhasor_hbkzo038, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_fEeBzckf, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_nQTzDnmp, VOf(Bf1));
    __hv_rpole_f(&sRPole_6Mg7fcL6, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_nrQtjUpO, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_SfLb6SOZ, VOf(Bf1));
    __hv_rpole_f(&sRPole_5UvVHRTG, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_b1rIhcf8, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_sHDHWCMy, VOf(Bf1));
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
