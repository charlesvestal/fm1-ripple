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
  numBytes += sPhasor_k_init(&sPhasor_e5ZtaeZ6, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_9RcU99J0);
  numBytes += sRPole_init(&sRPole_5F2vEGAc);
  numBytes += sLine_init(&sLine_yCRNTHeS);
  numBytes += cSlice_init(&cSlice_uSJgk3ih, 2, 1);
  numBytes += cSlice_init(&cSlice_0ahmVCwC, 1, 1);
  numBytes += cSlice_init(&cSlice_cZWNwnW2, 0, 1);
  numBytes += cVar_init_f(&cVar_tWJgUrqj, 0.0f);
  numBytes += cIf_init(&cIf_APEk8FUZ, false);
  numBytes += cIf_init(&cIf_FLsky6Jc, false);
  numBytes += cIf_init(&cIf_CJkmkLg3, false);
  numBytes += cIf_init(&cIf_XfmN9aMP, false);
  numBytes += cIf_init(&cIf_k2I9Tfdv, false);
  numBytes += cBinop_init(&cBinop_bkgTalTT, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_hN40GhyP, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_UoetIkJC, 22050.0f);
  numBytes += cBinop_init(&cBinop_XM5YqKq5, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_hUo9bqls, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bNkVXFvz, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_FQsR3S89, 22050.0f);
  numBytes += cBinop_init(&cBinop_PaOlwCpf, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_UWpm7yIp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9aJ7hQ3Y, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4csZpSDW, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NlDkoWgo_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jcLndLyb_sendMessage);
      break;
    }
    case 0xF89F9F3E: { // cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xiOIabVT_sendMessage);
      break;
    }
    case 0xB1642755: { // volume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_x43qbKDZ_sendMessage);
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


void Heavy_pdsaw::cSlice_uSJgk3ih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_wk5ZJiH6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_0ahmVCwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_XfmN9aMP, 0, m, &cIf_XfmN9aMP_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_FLsky6Jc, 0, m, &cIf_FLsky6Jc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cSlice_cZWNwnW2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_k2I9Tfdv, 0, m, &cIf_k2I9Tfdv_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_CJkmkLg3, 0, m, &cIf_CJkmkLg3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cVar_tWJgUrqj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_7cvJZqLr_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_APEk8FUZ, 0, m, &cIf_APEk8FUZ_sendMessage);
}

void Heavy_pdsaw::cUnop_WDOFl8p9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_jksMEaq5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bkgTalTT, HV_BINOP_EQ, 1, m, &cBinop_bkgTalTT_sendMessage);
}

void Heavy_pdsaw::cUnop_qkoRWVDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_jksMEaq5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bkgTalTT, HV_BINOP_EQ, 1, m, &cBinop_bkgTalTT_sendMessage);
}

void Heavy_pdsaw::cIf_APEk8FUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_qkoRWVDc_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_WDOFl8p9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_7cvJZqLr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_APEk8FUZ, 1, m, &cIf_APEk8FUZ_sendMessage);
}

void Heavy_pdsaw::cIf_FLsky6Jc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_J3gKxGFx_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_CJkmkLg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Pa0Y4mh8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_XfmN9aMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_J3gKxGFx_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cIf_k2I9Tfdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Pa0Y4mh8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdsaw::cBinop_wk5ZJiH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bkgTalTT, HV_BINOP_EQ, 0, m, &cBinop_bkgTalTT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ZaGDldiK_sendMessage);
}

void Heavy_pdsaw::cBinop_jksMEaq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fdlGnNVg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_l3Ed1OGr_sendMessage);
}

void Heavy_pdsaw::cBinop_bkgTalTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jNmAloBM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UtfwcSkV_sendMessage);
}

void Heavy_pdsaw::cCast_UtfwcSkV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_k2I9Tfdv, 1, m, &cIf_k2I9Tfdv_sendMessage);
}

void Heavy_pdsaw::cCast_jNmAloBM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_FLsky6Jc, 1, m, &cIf_FLsky6Jc_sendMessage);
}

void Heavy_pdsaw::cCast_l3Ed1OGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CJkmkLg3, 1, m, &cIf_CJkmkLg3_sendMessage);
}

void Heavy_pdsaw::cCast_fdlGnNVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XfmN9aMP, 1, m, &cIf_XfmN9aMP_sendMessage);
}

void Heavy_pdsaw::cBinop_ZaGDldiK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdsaw::cBinop_K03Uc4rB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_e5ZtaeZ6, 0, m);
}

void Heavy_pdsaw::cBinop_Pa0Y4mh8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_nlBqciJy_sendMessage);
}

void Heavy_pdsaw::cBinop_nlBqciJy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hN40GhyP, HV_BINOP_POW, 1, m, &cBinop_hN40GhyP_sendMessage);
  cMsg_sy8V58VJ_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_hN40GhyP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_K03Uc4rB_sendMessage);
}

void Heavy_pdsaw::cMsg_sy8V58VJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hN40GhyP, HV_BINOP_POW, 0, m, &cBinop_hN40GhyP_sendMessage);
}

void Heavy_pdsaw::cSwitchcase_J3gKxGFx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S5iDpaa9_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_FOeSvlJn_sendMessage);
      break;
    }
  }
}

void Heavy_pdsaw::cCast_S5iDpaa9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RszJCbIt_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cVar_UoetIkJC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XM5YqKq5, HV_BINOP_MULTIPLY, 0, m, &cBinop_XM5YqKq5_sendMessage);
}

void Heavy_pdsaw::cMsg_5JB6n7DV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_J4A6V2Ws_sendMessage);
}

void Heavy_pdsaw::cSystem_J4A6V2Ws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tDoF2isr_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_XM5YqKq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_mx8QDMHw_sendMessage);
}

void Heavy_pdsaw::cBinop_l1E8RUWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XM5YqKq5, HV_BINOP_MULTIPLY, 1, m, &cBinop_XM5YqKq5_sendMessage);
}

void Heavy_pdsaw::cMsg_tDoF2isr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_l1E8RUWn_sendMessage);
}

void Heavy_pdsaw::cBinop_mx8QDMHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_oHNEdx6B_sendMessage);
}

void Heavy_pdsaw::cBinop_oHNEdx6B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_RkGgJHBw_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bNkVXFvz, m);
}

void Heavy_pdsaw::cBinop_RkGgJHBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hUo9bqls, m);
}

void Heavy_pdsaw::cVar_FQsR3S89_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PaOlwCpf, HV_BINOP_MULTIPLY, 0, m, &cBinop_PaOlwCpf_sendMessage);
}

void Heavy_pdsaw::cMsg_J7JnqAVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YVPFuWJc_sendMessage);
}

void Heavy_pdsaw::cSystem_YVPFuWJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_duhqyo8x_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cBinop_PaOlwCpf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_lx61Aq0g_sendMessage);
}

void Heavy_pdsaw::cBinop_24PX6mgp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PaOlwCpf, HV_BINOP_MULTIPLY, 1, m, &cBinop_PaOlwCpf_sendMessage);
}

void Heavy_pdsaw::cMsg_duhqyo8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_24PX6mgp_sendMessage);
}

void Heavy_pdsaw::cBinop_lx61Aq0g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_NUEWS2ZH_sendMessage);
}

void Heavy_pdsaw::cBinop_NUEWS2ZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Nf9YshWk_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9aJ7hQ3Y, m);
}

void Heavy_pdsaw::cBinop_Nf9YshWk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UWpm7yIp, m);
}

void Heavy_pdsaw::cMsg_RszJCbIt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 300.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_yCRNTHeS, 0, m, NULL);
}

void Heavy_pdsaw::cBinop_FOeSvlJn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wLmlbJgq_sendMessage(_c, 0, m);
}

void Heavy_pdsaw::cMsg_wLmlbJgq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 5.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_yCRNTHeS, 0, m, NULL);
}

void Heavy_pdsaw::cReceive_NlDkoWgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tWJgUrqj, 0, m, &cVar_tWJgUrqj_sendMessage);
  cMsg_5JB6n7DV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UoetIkJC, 0, m, &cVar_UoetIkJC_sendMessage);
  cMsg_J7JnqAVK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FQsR3S89, 0, m, &cVar_FQsR3S89_sendMessage);
}

void Heavy_pdsaw::cReceive_jcLndLyb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_uSJgk3ih, 0, m, &cSlice_uSJgk3ih_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_0ahmVCwC, 0, m, &cSlice_0ahmVCwC_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_cZWNwnW2, 0, m, &cSlice_cZWNwnW2_sendMessage);
}

void Heavy_pdsaw::cReceive_xiOIabVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UoetIkJC, 0, m, &cVar_UoetIkJC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FQsR3S89, 0, m, &cVar_FQsR3S89_sendMessage);
}

void Heavy_pdsaw::cReceive_x43qbKDZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4csZpSDW, m);
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
    __hv_phasor_k_f(&sPhasor_e5ZtaeZ6, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_bNkVXFvz, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_hUo9bqls, VOf(Bf1));
    __hv_rpole_f(&sRPole_9RcU99J0, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_9aJ7hQ3Y, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_UWpm7yIp, VOf(Bf1));
    __hv_rpole_f(&sRPole_5F2vEGAc, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_yCRNTHeS, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_4csZpSDW, VOf(Bf1));
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
