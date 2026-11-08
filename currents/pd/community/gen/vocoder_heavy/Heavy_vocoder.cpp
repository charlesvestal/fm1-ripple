/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside vocoder.pd) */

#include "Heavy_vocoder.hpp"



#define Context(_c) static_cast<Heavy_vocoder *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_vocoder::Heavy_vocoder(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_I6QdZpBx, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_8DlQSu4C, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_3ZQLMLQE, 0.0f, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_d6KHWaeZ, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_PLvj8Bwq, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_KbQArNnJ, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_dTZVUgdM, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_739r17jG, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_NpVVprYy, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_nDwlVgXU, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_0WZCY8v6, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_8v0Yxpmx, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_W7m5eK9j, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_qzIGXxaU, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_05Q27N78, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_rkrYuhAQ, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_hPo81WmE, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sRPole_init(&sRPole_zdIGDVnp);
  numBytes += sDel1_init(&sDel1_z0iPhCA2);
  numBytes += sRPole_init(&sRPole_UxG6JsOJ);
  numBytes += sDel1_init(&sDel1_Ie9sASqY);
  numBytes += sVarf_init(&sVarf_FAC0Mld6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_H7uA5rCb, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_fvIDeK6W, 267.0f);
  numBytes += cVar_init_f(&cVar_6uO896Q0, 15.0f);
  numBytes += cBinop_init(&cBinop_voKcsfSe, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_WCyjQr8A, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_9PrJMFKX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_1D8C20WR, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_9Tq72C8q, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_BNFQRRpN, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_I7seJcky, 267.0f);
  numBytes += cVar_init_f(&cVar_rHrYonve, 15.0f);
  numBytes += cBinop_init(&cBinop_erD3vk6D, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_OhdxETmD, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_dncE6Esb, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_NXTcGuTc, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_lnpdHESZ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_CK6eI55u, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_xF0aadOr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zE4nqwOY, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_9JQdFhFs, 444.0f);
  numBytes += cVar_init_f(&cVar_tMQ1rKWO, 15.0f);
  numBytes += cBinop_init(&cBinop_RNyDbGhd, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_78xUqw7V, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_dY3cJu3K, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_nGOYOuur, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_CbbZHHH4, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_bsPrZFqo, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_PjH2iEPb, 444.0f);
  numBytes += cVar_init_f(&cVar_ahDcmFrZ, 15.0f);
  numBytes += cBinop_init(&cBinop_R7zkFDQy, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_VP3PbyNn, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_1xfwbohr, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_PxsEMQWx, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_aCKgH2te, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_XGbeLJfo, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_94DEBMTv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_f2VRGyiu, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_tyhTP9fM, 741.0f);
  numBytes += cVar_init_f(&cVar_kZ3XCnL1, 15.0f);
  numBytes += cBinop_init(&cBinop_yQIPDRFB, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_LEMZO0eI, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_3Y7ZwSbh, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_cqJp6e0d, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_numcxMNn, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_TGQS3hlm, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_s9mABigP, 741.0f);
  numBytes += cVar_init_f(&cVar_yosBGH5U, 15.0f);
  numBytes += cBinop_init(&cBinop_W8Pc3Yii, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_jIcWKMcE, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_lAZzaSoJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_nNYkrBno, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_uQSVeBnm, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_y9AvdGMn, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_6dZiTnsL, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rdkmcD98, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_wmoExvtg, 1235.0f);
  numBytes += cVar_init_f(&cVar_Nst9GO0K, 15.0f);
  numBytes += cBinop_init(&cBinop_UHO3yoMR, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_5yq7sjGa, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_4bp28TYV, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_kOxDrG1a, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_szjV3qh9, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_i9gjKL3y, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ydUNarMS, 1235.0f);
  numBytes += cVar_init_f(&cVar_NbSqTwgS, 15.0f);
  numBytes += cBinop_init(&cBinop_iqdxu57m, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_PkBy0qv9, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_BqLeJgD3, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_p8iFN0pm, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_SnZgY61o, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_dLWLRTuV, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_pnZd5RXQ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_g5ewJ2sc, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_rHUyKjZF, 2058.0f);
  numBytes += cVar_init_f(&cVar_BjV51JTr, 15.0f);
  numBytes += cBinop_init(&cBinop_V3HvvTj2, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_irF1mJiB, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_tw8zwuZQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_OyfVfdbX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_bvfvEqi8, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_tTqDypAr, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_qumArxdx, 2058.0f);
  numBytes += cVar_init_f(&cVar_eN7G6jmO, 15.0f);
  numBytes += cBinop_init(&cBinop_Hv4VaFV5, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_EvYOFJPi, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_EFzCpiNm, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_xqm66SI5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_rsZcQjT6, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_dKjdrEt6, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_t3rwDapQ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dVyfZOld, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_EF4bl0JC, 3429.0f);
  numBytes += cVar_init_f(&cVar_0l36Qx6g, 15.0f);
  numBytes += cBinop_init(&cBinop_rZqeAUwX, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_lemMJxgZ, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_whFHHXk6, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_55Bk4fua, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_2UtJk1ZF, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ktwMZ8ly, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_qOInCZIY, 3429.0f);
  numBytes += cVar_init_f(&cVar_8fqgXf1h, 15.0f);
  numBytes += cBinop_init(&cBinop_20MiFVvy, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_leWiNPFe, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_xwGFsnFX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_8W24VRAU, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_8Vri4xnw, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ZY4Qsvft, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_u6LLafHB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vcCSWB0t, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_RDICHSuh, 5716.0f);
  numBytes += cVar_init_f(&cVar_PkAd2mmz, 15.0f);
  numBytes += cBinop_init(&cBinop_dvURc5T0, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_fzIy1Vwn, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_CCy2DT4K, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_o8PpxhSU, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_paAwLCQC, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Ln9z2FiE, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_y6wPJydI, 5716.0f);
  numBytes += cVar_init_f(&cVar_DO0L2k3u, 15.0f);
  numBytes += cBinop_init(&cBinop_n43j8P6s, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_oIBDxQUr, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_LzKqsg0G, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_eGUhI6rU, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_KG5PoxAC, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ZSwxWC13, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_3Ch8MoHZ, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_GrRkPjMr, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_6pHsWvlM, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_bM7bgDiJ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_VuiAWtkg, 10000.0f);
  numBytes += cBinop_init(&cBinop_XbX16hta, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_Uj3JLSfo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4Q9HCGuP, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ADXPFHjY, 10000.0f);
  numBytes += cBinop_init(&cBinop_LOqwGh3P, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_OnizP16p, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_hzdxxBiS, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_SM4h4JbT, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_GNw0pM2k, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_vocoder::~Heavy_vocoder() {
  // nothing to free
}

HvTable *Heavy_vocoder::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_vocoder::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_C2UgN2mB_sendMessage);
      break;
    }
    case 0x6C87328F: { // alt_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GWgFXb00_sendMessage);
      break;
    }
    case 0x3FD8ECD5: { // note1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ESAAHOVS_sendMessage);
      break;
    }
    case 0x97165D01: { // note2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FAQpssX8_sendMessage);
      break;
    }
    case 0xA23B621F: { // pitch_note
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1SKHmu8Y_sendMessage);
      break;
    }
    case 0xCE9531B0: { // shape_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GnK5qt7W_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_vocoder::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "alt_f";
        info->hash = 0x6C87328F;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 1.0f;
        info->maxVal = 3.0f;
        info->defaultVal = 2.0f;
        break;
      }
      case 1: {
        info->name = "note1";
        info->hash = 0x3FD8ECD5;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 12.0f;
        info->defaultVal = 7.0f;
        break;
      }
      case 2: {
        info->name = "note2";
        info->hash = 0x97165D01;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 12.0f;
        info->defaultVal = 12.0f;
        break;
      }
      case 3: {
        info->name = "pitch_note";
        info->hash = 0xA23B621F;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 4: {
        info->name = "shape_f";
        info->hash = 0xCE9531B0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.99f;
        info->maxVal = 0.999f;
        info->defaultVal = 0.995f;
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
  return 5;
}



/*
 * Send Function Implementations
 */


void Heavy_vocoder::cMsg_5BuEmt3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UaVt1Tgw_sendMessage);
}

void Heavy_vocoder::cSystem_UaVt1Tgw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_voKcsfSe, HV_BINOP_DIVIDE, 1, m, &cBinop_voKcsfSe_sendMessage);
}

void Heavy_vocoder::cVar_fvIDeK6W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_fXS4MwPa_sendMessage);
}

void Heavy_vocoder::cVar_6uO896Q0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_SiLXaOmP_sendMessage);
}

void Heavy_vocoder::cUnop_ks25zYr8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_frG5SLbd_sendMessage);
}

void Heavy_vocoder::cBinop_voKcsfSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1D8C20WR, HV_BINOP_MULTIPLY, 1, m, &cBinop_1D8C20WR_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_ks25zYr8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WCyjQr8A, HV_BINOP_DIVIDE, 0, m, &cBinop_WCyjQr8A_sendMessage);
}

void Heavy_vocoder::cBinop_fXS4MwPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_voKcsfSe, HV_BINOP_DIVIDE, 0, m, &cBinop_voKcsfSe_sendMessage);
}

void Heavy_vocoder::cBinop_WCyjQr8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_MB6jZ6gq_sendMessage);
}

void Heavy_vocoder::cBinop_SBnGI6dr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Zuv0ZSPp_sendMessage);
}

void Heavy_vocoder::cBinop_Zuv0ZSPp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_RaVJySPR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9PrJMFKX, HV_BINOP_MULTIPLY, 0, m, &cBinop_9PrJMFKX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1D8C20WR, HV_BINOP_MULTIPLY, 0, m, &cBinop_1D8C20WR_sendMessage);
}

void Heavy_vocoder::cBinop_frG5SLbd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9PrJMFKX, HV_BINOP_MULTIPLY, 1, m, &cBinop_9PrJMFKX_sendMessage);
}

void Heavy_vocoder::cBinop_9PrJMFKX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RBQGOCmt_sendMessage);
}

void Heavy_vocoder::cCast_JxWUS3rL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fvIDeK6W, 0, m, &cVar_fvIDeK6W_sendMessage);
}

void Heavy_vocoder::cBinop_XsZeAHfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1UrX1w3D_sendMessage);
}

void Heavy_vocoder::cBinop_1UrX1w3D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_PLvj8Bwq, 5, m);
}

void Heavy_vocoder::cBinop_RBQGOCmt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_PLvj8Bwq, 4, m);
}

void Heavy_vocoder::cBinop_PVKzzHiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BNFQRRpN, HV_BINOP_MULTIPLY, 0, m, &cBinop_BNFQRRpN_sendMessage);
}

void Heavy_vocoder::cBinop_1D8C20WR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9Tq72C8q, HV_BINOP_ADD, 1, m, &cBinop_9Tq72C8q_sendMessage);
}

void Heavy_vocoder::cBinop_RaVJySPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XsZeAHfR_sendMessage);
}

void Heavy_vocoder::cBinop_9Tq72C8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BNFQRRpN, HV_BINOP_MULTIPLY, 1, m, &cBinop_BNFQRRpN_sendMessage);
}

void Heavy_vocoder::cBinop_BNFQRRpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_PLvj8Bwq, 1, m);
}

void Heavy_vocoder::cBinop_SiLXaOmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WCyjQr8A, HV_BINOP_DIVIDE, 1, m, &cBinop_WCyjQr8A_sendMessage);
}

void Heavy_vocoder::cBinop_MB6jZ6gq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SBnGI6dr_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9Tq72C8q, HV_BINOP_ADD, 0, m, &cBinop_9Tq72C8q_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_PVKzzHiP_sendMessage);
}

void Heavy_vocoder::cMsg_99MBCGxR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Rhn4F5Gf_sendMessage);
}

void Heavy_vocoder::cSystem_Rhn4F5Gf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_erD3vk6D, HV_BINOP_DIVIDE, 1, m, &cBinop_erD3vk6D_sendMessage);
}

void Heavy_vocoder::cVar_I7seJcky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_C5a9jBTw_sendMessage);
}

void Heavy_vocoder::cVar_rHrYonve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_Vu9nU3ny_sendMessage);
}

void Heavy_vocoder::cUnop_R2wAX7QN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_pRTPM4NX_sendMessage);
}

void Heavy_vocoder::cBinop_erD3vk6D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NXTcGuTc, HV_BINOP_MULTIPLY, 1, m, &cBinop_NXTcGuTc_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_R2wAX7QN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OhdxETmD, HV_BINOP_DIVIDE, 0, m, &cBinop_OhdxETmD_sendMessage);
}

void Heavy_vocoder::cBinop_C5a9jBTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_erD3vk6D, HV_BINOP_DIVIDE, 0, m, &cBinop_erD3vk6D_sendMessage);
}

void Heavy_vocoder::cBinop_OhdxETmD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_QeVISSss_sendMessage);
}

void Heavy_vocoder::cBinop_7PP6q7L4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_87yCYN0Q_sendMessage);
}

void Heavy_vocoder::cBinop_87yCYN0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_g2CK0349_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dncE6Esb, HV_BINOP_MULTIPLY, 0, m, &cBinop_dncE6Esb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NXTcGuTc, HV_BINOP_MULTIPLY, 0, m, &cBinop_NXTcGuTc_sendMessage);
}

void Heavy_vocoder::cBinop_pRTPM4NX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dncE6Esb, HV_BINOP_MULTIPLY, 1, m, &cBinop_dncE6Esb_sendMessage);
}

void Heavy_vocoder::cBinop_dncE6Esb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_85M98l6L_sendMessage);
}

void Heavy_vocoder::cCast_ryeZHoRR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_I7seJcky, 0, m, &cVar_I7seJcky_sendMessage);
}

void Heavy_vocoder::cBinop_4OWKv8hT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qLcPst0c_sendMessage);
}

void Heavy_vocoder::cBinop_qLcPst0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_d6KHWaeZ, 5, m);
}

void Heavy_vocoder::cBinop_85M98l6L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_d6KHWaeZ, 4, m);
}

void Heavy_vocoder::cBinop_wzLIcZTK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CK6eI55u, HV_BINOP_MULTIPLY, 0, m, &cBinop_CK6eI55u_sendMessage);
}

void Heavy_vocoder::cBinop_NXTcGuTc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lnpdHESZ, HV_BINOP_ADD, 1, m, &cBinop_lnpdHESZ_sendMessage);
}

void Heavy_vocoder::cBinop_g2CK0349_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4OWKv8hT_sendMessage);
}

void Heavy_vocoder::cBinop_lnpdHESZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CK6eI55u, HV_BINOP_MULTIPLY, 1, m, &cBinop_CK6eI55u_sendMessage);
}

void Heavy_vocoder::cBinop_CK6eI55u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_d6KHWaeZ, 1, m);
}

void Heavy_vocoder::cBinop_Vu9nU3ny_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OhdxETmD, HV_BINOP_DIVIDE, 1, m, &cBinop_OhdxETmD_sendMessage);
}

void Heavy_vocoder::cBinop_QeVISSss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7PP6q7L4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lnpdHESZ, HV_BINOP_ADD, 0, m, &cBinop_lnpdHESZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_wzLIcZTK_sendMessage);
}

void Heavy_vocoder::cMsg_bMcs2rgv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vTRclZkP_sendMessage);
}

void Heavy_vocoder::cSystem_vTRclZkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RNyDbGhd, HV_BINOP_DIVIDE, 1, m, &cBinop_RNyDbGhd_sendMessage);
}

void Heavy_vocoder::cVar_9JQdFhFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_k7oXNQSL_sendMessage);
}

void Heavy_vocoder::cVar_tMQ1rKWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_6hB8OLpd_sendMessage);
}

void Heavy_vocoder::cUnop_d1KQJYQt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_a1Ks76ri_sendMessage);
}

void Heavy_vocoder::cBinop_RNyDbGhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nGOYOuur, HV_BINOP_MULTIPLY, 1, m, &cBinop_nGOYOuur_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_d1KQJYQt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_78xUqw7V, HV_BINOP_DIVIDE, 0, m, &cBinop_78xUqw7V_sendMessage);
}

void Heavy_vocoder::cBinop_k7oXNQSL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RNyDbGhd, HV_BINOP_DIVIDE, 0, m, &cBinop_RNyDbGhd_sendMessage);
}

void Heavy_vocoder::cBinop_78xUqw7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_9WwUh10z_sendMessage);
}

void Heavy_vocoder::cBinop_ti8q0jey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_YYVeZXNW_sendMessage);
}

void Heavy_vocoder::cBinop_YYVeZXNW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_yHGt2OVU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dY3cJu3K, HV_BINOP_MULTIPLY, 0, m, &cBinop_dY3cJu3K_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nGOYOuur, HV_BINOP_MULTIPLY, 0, m, &cBinop_nGOYOuur_sendMessage);
}

void Heavy_vocoder::cBinop_a1Ks76ri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dY3cJu3K, HV_BINOP_MULTIPLY, 1, m, &cBinop_dY3cJu3K_sendMessage);
}

void Heavy_vocoder::cBinop_dY3cJu3K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Rd9BzHxg_sendMessage);
}

void Heavy_vocoder::cCast_FysD3gKX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9JQdFhFs, 0, m, &cVar_9JQdFhFs_sendMessage);
}

void Heavy_vocoder::cBinop_oJJnHAyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Ur2n0onG_sendMessage);
}

void Heavy_vocoder::cBinop_Ur2n0onG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_dTZVUgdM, 5, m);
}

void Heavy_vocoder::cBinop_Rd9BzHxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_dTZVUgdM, 4, m);
}

void Heavy_vocoder::cBinop_ZU9PZxzF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bsPrZFqo, HV_BINOP_MULTIPLY, 0, m, &cBinop_bsPrZFqo_sendMessage);
}

void Heavy_vocoder::cBinop_nGOYOuur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CbbZHHH4, HV_BINOP_ADD, 1, m, &cBinop_CbbZHHH4_sendMessage);
}

void Heavy_vocoder::cBinop_yHGt2OVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_oJJnHAyh_sendMessage);
}

void Heavy_vocoder::cBinop_CbbZHHH4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bsPrZFqo, HV_BINOP_MULTIPLY, 1, m, &cBinop_bsPrZFqo_sendMessage);
}

void Heavy_vocoder::cBinop_bsPrZFqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_dTZVUgdM, 1, m);
}

void Heavy_vocoder::cBinop_6hB8OLpd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_78xUqw7V, HV_BINOP_DIVIDE, 1, m, &cBinop_78xUqw7V_sendMessage);
}

void Heavy_vocoder::cBinop_9WwUh10z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ti8q0jey_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CbbZHHH4, HV_BINOP_ADD, 0, m, &cBinop_CbbZHHH4_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ZU9PZxzF_sendMessage);
}

void Heavy_vocoder::cMsg_xzmJHqwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gbhfT4wC_sendMessage);
}

void Heavy_vocoder::cSystem_gbhfT4wC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R7zkFDQy, HV_BINOP_DIVIDE, 1, m, &cBinop_R7zkFDQy_sendMessage);
}

void Heavy_vocoder::cVar_PjH2iEPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_j0NJitte_sendMessage);
}

void Heavy_vocoder::cVar_ahDcmFrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_s01ktTA9_sendMessage);
}

void Heavy_vocoder::cUnop_t5fFtHF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ewn9szwH_sendMessage);
}

void Heavy_vocoder::cBinop_R7zkFDQy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PxsEMQWx, HV_BINOP_MULTIPLY, 1, m, &cBinop_PxsEMQWx_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_t5fFtHF4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VP3PbyNn, HV_BINOP_DIVIDE, 0, m, &cBinop_VP3PbyNn_sendMessage);
}

void Heavy_vocoder::cBinop_j0NJitte_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R7zkFDQy, HV_BINOP_DIVIDE, 0, m, &cBinop_R7zkFDQy_sendMessage);
}

void Heavy_vocoder::cBinop_VP3PbyNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_IgBS5qJb_sendMessage);
}

void Heavy_vocoder::cBinop_Kj7bp5oN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_mW1A1rEA_sendMessage);
}

void Heavy_vocoder::cBinop_mW1A1rEA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_MgnxyfUW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1xfwbohr, HV_BINOP_MULTIPLY, 0, m, &cBinop_1xfwbohr_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PxsEMQWx, HV_BINOP_MULTIPLY, 0, m, &cBinop_PxsEMQWx_sendMessage);
}

void Heavy_vocoder::cBinop_ewn9szwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1xfwbohr, HV_BINOP_MULTIPLY, 1, m, &cBinop_1xfwbohr_sendMessage);
}

void Heavy_vocoder::cBinop_1xfwbohr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4wP1WMsz_sendMessage);
}

void Heavy_vocoder::cCast_iyim1stm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PjH2iEPb, 0, m, &cVar_PjH2iEPb_sendMessage);
}

void Heavy_vocoder::cBinop_joWwBheG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_wyqg9m3U_sendMessage);
}

void Heavy_vocoder::cBinop_wyqg9m3U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_KbQArNnJ, 5, m);
}

void Heavy_vocoder::cBinop_4wP1WMsz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_KbQArNnJ, 4, m);
}

void Heavy_vocoder::cBinop_j5DpZZ4U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XGbeLJfo, HV_BINOP_MULTIPLY, 0, m, &cBinop_XGbeLJfo_sendMessage);
}

void Heavy_vocoder::cBinop_PxsEMQWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aCKgH2te, HV_BINOP_ADD, 1, m, &cBinop_aCKgH2te_sendMessage);
}

void Heavy_vocoder::cBinop_MgnxyfUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_joWwBheG_sendMessage);
}

void Heavy_vocoder::cBinop_aCKgH2te_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XGbeLJfo, HV_BINOP_MULTIPLY, 1, m, &cBinop_XGbeLJfo_sendMessage);
}

void Heavy_vocoder::cBinop_XGbeLJfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_KbQArNnJ, 1, m);
}

void Heavy_vocoder::cBinop_s01ktTA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VP3PbyNn, HV_BINOP_DIVIDE, 1, m, &cBinop_VP3PbyNn_sendMessage);
}

void Heavy_vocoder::cBinop_IgBS5qJb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Kj7bp5oN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aCKgH2te, HV_BINOP_ADD, 0, m, &cBinop_aCKgH2te_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_j5DpZZ4U_sendMessage);
}

void Heavy_vocoder::cMsg_KkLZ5tKR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CrdzL2Ia_sendMessage);
}

void Heavy_vocoder::cSystem_CrdzL2Ia_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yQIPDRFB, HV_BINOP_DIVIDE, 1, m, &cBinop_yQIPDRFB_sendMessage);
}

void Heavy_vocoder::cVar_tyhTP9fM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_sS1iCcMt_sendMessage);
}

void Heavy_vocoder::cVar_kZ3XCnL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_e2b84xaq_sendMessage);
}

void Heavy_vocoder::cUnop_NBbIU90a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ot5Pt1A5_sendMessage);
}

void Heavy_vocoder::cBinop_yQIPDRFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cqJp6e0d, HV_BINOP_MULTIPLY, 1, m, &cBinop_cqJp6e0d_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_NBbIU90a_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LEMZO0eI, HV_BINOP_DIVIDE, 0, m, &cBinop_LEMZO0eI_sendMessage);
}

void Heavy_vocoder::cBinop_sS1iCcMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yQIPDRFB, HV_BINOP_DIVIDE, 0, m, &cBinop_yQIPDRFB_sendMessage);
}

void Heavy_vocoder::cBinop_LEMZO0eI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ou34LNrj_sendMessage);
}

void Heavy_vocoder::cBinop_4NFvGgGe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_9dibg2sJ_sendMessage);
}

void Heavy_vocoder::cBinop_9dibg2sJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_KsxXwBde_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Y7ZwSbh, HV_BINOP_MULTIPLY, 0, m, &cBinop_3Y7ZwSbh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cqJp6e0d, HV_BINOP_MULTIPLY, 0, m, &cBinop_cqJp6e0d_sendMessage);
}

void Heavy_vocoder::cBinop_ot5Pt1A5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Y7ZwSbh, HV_BINOP_MULTIPLY, 1, m, &cBinop_3Y7ZwSbh_sendMessage);
}

void Heavy_vocoder::cBinop_3Y7ZwSbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_yV2lP23W_sendMessage);
}

void Heavy_vocoder::cCast_bEwWbpH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tyhTP9fM, 0, m, &cVar_tyhTP9fM_sendMessage);
}

void Heavy_vocoder::cBinop_a47y4Zml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9b5mR2dL_sendMessage);
}

void Heavy_vocoder::cBinop_9b5mR2dL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_NpVVprYy, 5, m);
}

void Heavy_vocoder::cBinop_yV2lP23W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_NpVVprYy, 4, m);
}

void Heavy_vocoder::cBinop_iK9Ww5ep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TGQS3hlm, HV_BINOP_MULTIPLY, 0, m, &cBinop_TGQS3hlm_sendMessage);
}

void Heavy_vocoder::cBinop_cqJp6e0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_numcxMNn, HV_BINOP_ADD, 1, m, &cBinop_numcxMNn_sendMessage);
}

void Heavy_vocoder::cBinop_KsxXwBde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_a47y4Zml_sendMessage);
}

void Heavy_vocoder::cBinop_numcxMNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TGQS3hlm, HV_BINOP_MULTIPLY, 1, m, &cBinop_TGQS3hlm_sendMessage);
}

void Heavy_vocoder::cBinop_TGQS3hlm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_NpVVprYy, 1, m);
}

void Heavy_vocoder::cBinop_e2b84xaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LEMZO0eI, HV_BINOP_DIVIDE, 1, m, &cBinop_LEMZO0eI_sendMessage);
}

void Heavy_vocoder::cBinop_ou34LNrj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4NFvGgGe_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_numcxMNn, HV_BINOP_ADD, 0, m, &cBinop_numcxMNn_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_iK9Ww5ep_sendMessage);
}

void Heavy_vocoder::cMsg_XkqNsJgQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4QSEFFbx_sendMessage);
}

void Heavy_vocoder::cSystem_4QSEFFbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W8Pc3Yii, HV_BINOP_DIVIDE, 1, m, &cBinop_W8Pc3Yii_sendMessage);
}

void Heavy_vocoder::cVar_s9mABigP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_GspLcDSF_sendMessage);
}

void Heavy_vocoder::cVar_yosBGH5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_1b8SQjan_sendMessage);
}

void Heavy_vocoder::cUnop_fNkteq3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_35auf2jY_sendMessage);
}

void Heavy_vocoder::cBinop_W8Pc3Yii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nNYkrBno, HV_BINOP_MULTIPLY, 1, m, &cBinop_nNYkrBno_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_fNkteq3v_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jIcWKMcE, HV_BINOP_DIVIDE, 0, m, &cBinop_jIcWKMcE_sendMessage);
}

void Heavy_vocoder::cBinop_GspLcDSF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W8Pc3Yii, HV_BINOP_DIVIDE, 0, m, &cBinop_W8Pc3Yii_sendMessage);
}

void Heavy_vocoder::cBinop_jIcWKMcE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_IeUkIhsP_sendMessage);
}

void Heavy_vocoder::cBinop_ogZJbMUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_AH4f4UrF_sendMessage);
}

void Heavy_vocoder::cBinop_AH4f4UrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_5wewkjK4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lAZzaSoJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_lAZzaSoJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nNYkrBno, HV_BINOP_MULTIPLY, 0, m, &cBinop_nNYkrBno_sendMessage);
}

void Heavy_vocoder::cBinop_35auf2jY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lAZzaSoJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_lAZzaSoJ_sendMessage);
}

void Heavy_vocoder::cBinop_lAZzaSoJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5d0GiTfQ_sendMessage);
}

void Heavy_vocoder::cCast_18BJwGJI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s9mABigP, 0, m, &cVar_s9mABigP_sendMessage);
}

void Heavy_vocoder::cBinop_ftbE346K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_el8O0QTd_sendMessage);
}

void Heavy_vocoder::cBinop_el8O0QTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_739r17jG, 5, m);
}

void Heavy_vocoder::cBinop_5d0GiTfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_739r17jG, 4, m);
}

void Heavy_vocoder::cBinop_yIPwB7Tc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y9AvdGMn, HV_BINOP_MULTIPLY, 0, m, &cBinop_y9AvdGMn_sendMessage);
}

void Heavy_vocoder::cBinop_nNYkrBno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uQSVeBnm, HV_BINOP_ADD, 1, m, &cBinop_uQSVeBnm_sendMessage);
}

void Heavy_vocoder::cBinop_5wewkjK4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ftbE346K_sendMessage);
}

void Heavy_vocoder::cBinop_uQSVeBnm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y9AvdGMn, HV_BINOP_MULTIPLY, 1, m, &cBinop_y9AvdGMn_sendMessage);
}

void Heavy_vocoder::cBinop_y9AvdGMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_739r17jG, 1, m);
}

void Heavy_vocoder::cBinop_1b8SQjan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jIcWKMcE, HV_BINOP_DIVIDE, 1, m, &cBinop_jIcWKMcE_sendMessage);
}

void Heavy_vocoder::cBinop_IeUkIhsP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ogZJbMUj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uQSVeBnm, HV_BINOP_ADD, 0, m, &cBinop_uQSVeBnm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_yIPwB7Tc_sendMessage);
}

void Heavy_vocoder::cMsg_0uPuw2ZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8hM5rnVr_sendMessage);
}

void Heavy_vocoder::cSystem_8hM5rnVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UHO3yoMR, HV_BINOP_DIVIDE, 1, m, &cBinop_UHO3yoMR_sendMessage);
}

void Heavy_vocoder::cVar_wmoExvtg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_VKw83x0O_sendMessage);
}

void Heavy_vocoder::cVar_Nst9GO0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_cRID82m7_sendMessage);
}

void Heavy_vocoder::cUnop_M577b7Wu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_IwbvR5nB_sendMessage);
}

void Heavy_vocoder::cBinop_UHO3yoMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kOxDrG1a, HV_BINOP_MULTIPLY, 1, m, &cBinop_kOxDrG1a_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_M577b7Wu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5yq7sjGa, HV_BINOP_DIVIDE, 0, m, &cBinop_5yq7sjGa_sendMessage);
}

void Heavy_vocoder::cBinop_VKw83x0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UHO3yoMR, HV_BINOP_DIVIDE, 0, m, &cBinop_UHO3yoMR_sendMessage);
}

void Heavy_vocoder::cBinop_5yq7sjGa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_nWAqkdLh_sendMessage);
}

void Heavy_vocoder::cBinop_bcNdkOox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_u79KXdl3_sendMessage);
}

void Heavy_vocoder::cBinop_u79KXdl3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_ADBTHxGn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4bp28TYV, HV_BINOP_MULTIPLY, 0, m, &cBinop_4bp28TYV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_kOxDrG1a, HV_BINOP_MULTIPLY, 0, m, &cBinop_kOxDrG1a_sendMessage);
}

void Heavy_vocoder::cBinop_IwbvR5nB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4bp28TYV, HV_BINOP_MULTIPLY, 1, m, &cBinop_4bp28TYV_sendMessage);
}

void Heavy_vocoder::cBinop_4bp28TYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WFI8WbPU_sendMessage);
}

void Heavy_vocoder::cCast_kfXw3OVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wmoExvtg, 0, m, &cVar_wmoExvtg_sendMessage);
}

void Heavy_vocoder::cBinop_UF1x8dV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kTtchlDs_sendMessage);
}

void Heavy_vocoder::cBinop_kTtchlDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_0WZCY8v6, 5, m);
}

void Heavy_vocoder::cBinop_WFI8WbPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_0WZCY8v6, 4, m);
}

void Heavy_vocoder::cBinop_3QlzTJmt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i9gjKL3y, HV_BINOP_MULTIPLY, 0, m, &cBinop_i9gjKL3y_sendMessage);
}

void Heavy_vocoder::cBinop_kOxDrG1a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_szjV3qh9, HV_BINOP_ADD, 1, m, &cBinop_szjV3qh9_sendMessage);
}

void Heavy_vocoder::cBinop_ADBTHxGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UF1x8dV5_sendMessage);
}

void Heavy_vocoder::cBinop_szjV3qh9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i9gjKL3y, HV_BINOP_MULTIPLY, 1, m, &cBinop_i9gjKL3y_sendMessage);
}

void Heavy_vocoder::cBinop_i9gjKL3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_0WZCY8v6, 1, m);
}

void Heavy_vocoder::cBinop_cRID82m7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5yq7sjGa, HV_BINOP_DIVIDE, 1, m, &cBinop_5yq7sjGa_sendMessage);
}

void Heavy_vocoder::cBinop_nWAqkdLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bcNdkOox_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_szjV3qh9, HV_BINOP_ADD, 0, m, &cBinop_szjV3qh9_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_3QlzTJmt_sendMessage);
}

void Heavy_vocoder::cMsg_kGRXQ7vM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_b0HmQien_sendMessage);
}

void Heavy_vocoder::cSystem_b0HmQien_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iqdxu57m, HV_BINOP_DIVIDE, 1, m, &cBinop_iqdxu57m_sendMessage);
}

void Heavy_vocoder::cVar_ydUNarMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_z0dlho7P_sendMessage);
}

void Heavy_vocoder::cVar_NbSqTwgS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_PEjM0JDx_sendMessage);
}

void Heavy_vocoder::cUnop_fdITX4BW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_8Edq1nzr_sendMessage);
}

void Heavy_vocoder::cBinop_iqdxu57m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p8iFN0pm, HV_BINOP_MULTIPLY, 1, m, &cBinop_p8iFN0pm_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_fdITX4BW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PkBy0qv9, HV_BINOP_DIVIDE, 0, m, &cBinop_PkBy0qv9_sendMessage);
}

void Heavy_vocoder::cBinop_z0dlho7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iqdxu57m, HV_BINOP_DIVIDE, 0, m, &cBinop_iqdxu57m_sendMessage);
}

void Heavy_vocoder::cBinop_PkBy0qv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_e6zjnQ1u_sendMessage);
}

void Heavy_vocoder::cBinop_qfw03vr3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_UuJZZmlL_sendMessage);
}

void Heavy_vocoder::cBinop_UuJZZmlL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_I3D10M4k_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BqLeJgD3, HV_BINOP_MULTIPLY, 0, m, &cBinop_BqLeJgD3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_p8iFN0pm, HV_BINOP_MULTIPLY, 0, m, &cBinop_p8iFN0pm_sendMessage);
}

void Heavy_vocoder::cBinop_8Edq1nzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BqLeJgD3, HV_BINOP_MULTIPLY, 1, m, &cBinop_BqLeJgD3_sendMessage);
}

void Heavy_vocoder::cBinop_BqLeJgD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_zaZSxOij_sendMessage);
}

void Heavy_vocoder::cCast_t8KXKchz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ydUNarMS, 0, m, &cVar_ydUNarMS_sendMessage);
}

void Heavy_vocoder::cBinop_9g29rYtb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_TfhFUV5E_sendMessage);
}

void Heavy_vocoder::cBinop_TfhFUV5E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nDwlVgXU, 5, m);
}

void Heavy_vocoder::cBinop_zaZSxOij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nDwlVgXU, 4, m);
}

void Heavy_vocoder::cBinop_R6fqhZbz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dLWLRTuV, HV_BINOP_MULTIPLY, 0, m, &cBinop_dLWLRTuV_sendMessage);
}

void Heavy_vocoder::cBinop_p8iFN0pm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SnZgY61o, HV_BINOP_ADD, 1, m, &cBinop_SnZgY61o_sendMessage);
}

void Heavy_vocoder::cBinop_I3D10M4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9g29rYtb_sendMessage);
}

void Heavy_vocoder::cBinop_SnZgY61o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dLWLRTuV, HV_BINOP_MULTIPLY, 1, m, &cBinop_dLWLRTuV_sendMessage);
}

void Heavy_vocoder::cBinop_dLWLRTuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nDwlVgXU, 1, m);
}

void Heavy_vocoder::cBinop_PEjM0JDx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PkBy0qv9, HV_BINOP_DIVIDE, 1, m, &cBinop_PkBy0qv9_sendMessage);
}

void Heavy_vocoder::cBinop_e6zjnQ1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qfw03vr3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SnZgY61o, HV_BINOP_ADD, 0, m, &cBinop_SnZgY61o_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_R6fqhZbz_sendMessage);
}

void Heavy_vocoder::cMsg_ZfW8UEfk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bNZTs3jV_sendMessage);
}

void Heavy_vocoder::cSystem_bNZTs3jV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V3HvvTj2, HV_BINOP_DIVIDE, 1, m, &cBinop_V3HvvTj2_sendMessage);
}

void Heavy_vocoder::cVar_rHUyKjZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_e2koqnp4_sendMessage);
}

void Heavy_vocoder::cVar_BjV51JTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_v6xETwvL_sendMessage);
}

void Heavy_vocoder::cUnop_caJSVzvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_yLYCrkMm_sendMessage);
}

void Heavy_vocoder::cBinop_V3HvvTj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OyfVfdbX, HV_BINOP_MULTIPLY, 1, m, &cBinop_OyfVfdbX_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_caJSVzvh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_irF1mJiB, HV_BINOP_DIVIDE, 0, m, &cBinop_irF1mJiB_sendMessage);
}

void Heavy_vocoder::cBinop_e2koqnp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V3HvvTj2, HV_BINOP_DIVIDE, 0, m, &cBinop_V3HvvTj2_sendMessage);
}

void Heavy_vocoder::cBinop_irF1mJiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_uL0tBzfQ_sendMessage);
}

void Heavy_vocoder::cBinop_npEHnSQn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_oRKGJ536_sendMessage);
}

void Heavy_vocoder::cBinop_oRKGJ536_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_KYYCZs3Q_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tw8zwuZQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_tw8zwuZQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OyfVfdbX, HV_BINOP_MULTIPLY, 0, m, &cBinop_OyfVfdbX_sendMessage);
}

void Heavy_vocoder::cBinop_yLYCrkMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tw8zwuZQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_tw8zwuZQ_sendMessage);
}

void Heavy_vocoder::cBinop_tw8zwuZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_LrX0zU6A_sendMessage);
}

void Heavy_vocoder::cCast_hItF0At1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rHUyKjZF, 0, m, &cVar_rHUyKjZF_sendMessage);
}

void Heavy_vocoder::cBinop_UvWbaffN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7dy4f8Dk_sendMessage);
}

void Heavy_vocoder::cBinop_7dy4f8Dk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_W7m5eK9j, 5, m);
}

void Heavy_vocoder::cBinop_LrX0zU6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_W7m5eK9j, 4, m);
}

void Heavy_vocoder::cBinop_KlBalTHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tTqDypAr, HV_BINOP_MULTIPLY, 0, m, &cBinop_tTqDypAr_sendMessage);
}

void Heavy_vocoder::cBinop_OyfVfdbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bvfvEqi8, HV_BINOP_ADD, 1, m, &cBinop_bvfvEqi8_sendMessage);
}

void Heavy_vocoder::cBinop_KYYCZs3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UvWbaffN_sendMessage);
}

void Heavy_vocoder::cBinop_bvfvEqi8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tTqDypAr, HV_BINOP_MULTIPLY, 1, m, &cBinop_tTqDypAr_sendMessage);
}

void Heavy_vocoder::cBinop_tTqDypAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_W7m5eK9j, 1, m);
}

void Heavy_vocoder::cBinop_v6xETwvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_irF1mJiB, HV_BINOP_DIVIDE, 1, m, &cBinop_irF1mJiB_sendMessage);
}

void Heavy_vocoder::cBinop_uL0tBzfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_npEHnSQn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bvfvEqi8, HV_BINOP_ADD, 0, m, &cBinop_bvfvEqi8_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_KlBalTHg_sendMessage);
}

void Heavy_vocoder::cMsg_CCMLWCBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_W5QpQS1X_sendMessage);
}

void Heavy_vocoder::cSystem_W5QpQS1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hv4VaFV5, HV_BINOP_DIVIDE, 1, m, &cBinop_Hv4VaFV5_sendMessage);
}

void Heavy_vocoder::cVar_qumArxdx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_F6USDJfD_sendMessage);
}

void Heavy_vocoder::cVar_eN7G6jmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_irwgpL6n_sendMessage);
}

void Heavy_vocoder::cUnop_UfcREnva_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_2Z5elaFO_sendMessage);
}

void Heavy_vocoder::cBinop_Hv4VaFV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xqm66SI5, HV_BINOP_MULTIPLY, 1, m, &cBinop_xqm66SI5_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_UfcREnva_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EvYOFJPi, HV_BINOP_DIVIDE, 0, m, &cBinop_EvYOFJPi_sendMessage);
}

void Heavy_vocoder::cBinop_F6USDJfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hv4VaFV5, HV_BINOP_DIVIDE, 0, m, &cBinop_Hv4VaFV5_sendMessage);
}

void Heavy_vocoder::cBinop_EvYOFJPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_dPKVNpsd_sendMessage);
}

void Heavy_vocoder::cBinop_ltDRYQS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_hmmVM31z_sendMessage);
}

void Heavy_vocoder::cBinop_hmmVM31z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_Vld6ShXh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EFzCpiNm, HV_BINOP_MULTIPLY, 0, m, &cBinop_EFzCpiNm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xqm66SI5, HV_BINOP_MULTIPLY, 0, m, &cBinop_xqm66SI5_sendMessage);
}

void Heavy_vocoder::cBinop_2Z5elaFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EFzCpiNm, HV_BINOP_MULTIPLY, 1, m, &cBinop_EFzCpiNm_sendMessage);
}

void Heavy_vocoder::cBinop_EFzCpiNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_mqOjuBCU_sendMessage);
}

void Heavy_vocoder::cCast_IaTJxxub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qumArxdx, 0, m, &cVar_qumArxdx_sendMessage);
}

void Heavy_vocoder::cBinop_iVacoGXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_oG4svOB5_sendMessage);
}

void Heavy_vocoder::cBinop_oG4svOB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_8v0Yxpmx, 5, m);
}

void Heavy_vocoder::cBinop_mqOjuBCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_8v0Yxpmx, 4, m);
}

void Heavy_vocoder::cBinop_13baH9yd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dKjdrEt6, HV_BINOP_MULTIPLY, 0, m, &cBinop_dKjdrEt6_sendMessage);
}

void Heavy_vocoder::cBinop_xqm66SI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rsZcQjT6, HV_BINOP_ADD, 1, m, &cBinop_rsZcQjT6_sendMessage);
}

void Heavy_vocoder::cBinop_Vld6ShXh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_iVacoGXS_sendMessage);
}

void Heavy_vocoder::cBinop_rsZcQjT6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dKjdrEt6, HV_BINOP_MULTIPLY, 1, m, &cBinop_dKjdrEt6_sendMessage);
}

void Heavy_vocoder::cBinop_dKjdrEt6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_8v0Yxpmx, 1, m);
}

void Heavy_vocoder::cBinop_irwgpL6n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EvYOFJPi, HV_BINOP_DIVIDE, 1, m, &cBinop_EvYOFJPi_sendMessage);
}

void Heavy_vocoder::cBinop_dPKVNpsd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ltDRYQS9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rsZcQjT6, HV_BINOP_ADD, 0, m, &cBinop_rsZcQjT6_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_13baH9yd_sendMessage);
}

void Heavy_vocoder::cMsg_BDJB2mUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VTZ3aOZj_sendMessage);
}

void Heavy_vocoder::cSystem_VTZ3aOZj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rZqeAUwX, HV_BINOP_DIVIDE, 1, m, &cBinop_rZqeAUwX_sendMessage);
}

void Heavy_vocoder::cVar_EF4bl0JC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_gUUzAwY0_sendMessage);
}

void Heavy_vocoder::cVar_0l36Qx6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_77PjEJcO_sendMessage);
}

void Heavy_vocoder::cUnop_MK4fa7DD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_EXkg2Jmr_sendMessage);
}

void Heavy_vocoder::cBinop_rZqeAUwX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_55Bk4fua, HV_BINOP_MULTIPLY, 1, m, &cBinop_55Bk4fua_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_MK4fa7DD_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lemMJxgZ, HV_BINOP_DIVIDE, 0, m, &cBinop_lemMJxgZ_sendMessage);
}

void Heavy_vocoder::cBinop_gUUzAwY0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rZqeAUwX, HV_BINOP_DIVIDE, 0, m, &cBinop_rZqeAUwX_sendMessage);
}

void Heavy_vocoder::cBinop_lemMJxgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_GPGaIyrf_sendMessage);
}

void Heavy_vocoder::cBinop_WwHJfZLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_hKzl1zDg_sendMessage);
}

void Heavy_vocoder::cBinop_hKzl1zDg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_G9LBYRGp_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_whFHHXk6, HV_BINOP_MULTIPLY, 0, m, &cBinop_whFHHXk6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_55Bk4fua, HV_BINOP_MULTIPLY, 0, m, &cBinop_55Bk4fua_sendMessage);
}

void Heavy_vocoder::cBinop_EXkg2Jmr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_whFHHXk6, HV_BINOP_MULTIPLY, 1, m, &cBinop_whFHHXk6_sendMessage);
}

void Heavy_vocoder::cBinop_whFHHXk6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_faaNhS85_sendMessage);
}

void Heavy_vocoder::cCast_5Llp9V8z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EF4bl0JC, 0, m, &cVar_EF4bl0JC_sendMessage);
}

void Heavy_vocoder::cBinop_TnTKZwd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bOW0bN09_sendMessage);
}

void Heavy_vocoder::cBinop_bOW0bN09_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_05Q27N78, 5, m);
}

void Heavy_vocoder::cBinop_faaNhS85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_05Q27N78, 4, m);
}

void Heavy_vocoder::cBinop_snx2Sr9O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ktwMZ8ly, HV_BINOP_MULTIPLY, 0, m, &cBinop_ktwMZ8ly_sendMessage);
}

void Heavy_vocoder::cBinop_55Bk4fua_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2UtJk1ZF, HV_BINOP_ADD, 1, m, &cBinop_2UtJk1ZF_sendMessage);
}

void Heavy_vocoder::cBinop_G9LBYRGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_TnTKZwd8_sendMessage);
}

void Heavy_vocoder::cBinop_2UtJk1ZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ktwMZ8ly, HV_BINOP_MULTIPLY, 1, m, &cBinop_ktwMZ8ly_sendMessage);
}

void Heavy_vocoder::cBinop_ktwMZ8ly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_05Q27N78, 1, m);
}

void Heavy_vocoder::cBinop_77PjEJcO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lemMJxgZ, HV_BINOP_DIVIDE, 1, m, &cBinop_lemMJxgZ_sendMessage);
}

void Heavy_vocoder::cBinop_GPGaIyrf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WwHJfZLk_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2UtJk1ZF, HV_BINOP_ADD, 0, m, &cBinop_2UtJk1ZF_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_snx2Sr9O_sendMessage);
}

void Heavy_vocoder::cMsg_HqWuyIKV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zwpTAPZx_sendMessage);
}

void Heavy_vocoder::cSystem_zwpTAPZx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_20MiFVvy, HV_BINOP_DIVIDE, 1, m, &cBinop_20MiFVvy_sendMessage);
}

void Heavy_vocoder::cVar_qOInCZIY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_cDT48I5i_sendMessage);
}

void Heavy_vocoder::cVar_8fqgXf1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_CCfSmeS7_sendMessage);
}

void Heavy_vocoder::cUnop_9nmtUcZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_wJXEwLw7_sendMessage);
}

void Heavy_vocoder::cBinop_20MiFVvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8W24VRAU, HV_BINOP_MULTIPLY, 1, m, &cBinop_8W24VRAU_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_9nmtUcZT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_leWiNPFe, HV_BINOP_DIVIDE, 0, m, &cBinop_leWiNPFe_sendMessage);
}

void Heavy_vocoder::cBinop_cDT48I5i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_20MiFVvy, HV_BINOP_DIVIDE, 0, m, &cBinop_20MiFVvy_sendMessage);
}

void Heavy_vocoder::cBinop_leWiNPFe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_WvUe4h7B_sendMessage);
}

void Heavy_vocoder::cBinop_bw5LSM8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_tyVYxxS1_sendMessage);
}

void Heavy_vocoder::cBinop_tyVYxxS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_PwCRANZ2_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xwGFsnFX, HV_BINOP_MULTIPLY, 0, m, &cBinop_xwGFsnFX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8W24VRAU, HV_BINOP_MULTIPLY, 0, m, &cBinop_8W24VRAU_sendMessage);
}

void Heavy_vocoder::cBinop_wJXEwLw7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xwGFsnFX, HV_BINOP_MULTIPLY, 1, m, &cBinop_xwGFsnFX_sendMessage);
}

void Heavy_vocoder::cBinop_xwGFsnFX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2EaXS6v1_sendMessage);
}

void Heavy_vocoder::cCast_YQ2KZU1n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qOInCZIY, 0, m, &cVar_qOInCZIY_sendMessage);
}

void Heavy_vocoder::cBinop_CEvBAn59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9f037cn6_sendMessage);
}

void Heavy_vocoder::cBinop_9f037cn6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_qzIGXxaU, 5, m);
}

void Heavy_vocoder::cBinop_2EaXS6v1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_qzIGXxaU, 4, m);
}

void Heavy_vocoder::cBinop_SuxBdc1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZY4Qsvft, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZY4Qsvft_sendMessage);
}

void Heavy_vocoder::cBinop_8W24VRAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8Vri4xnw, HV_BINOP_ADD, 1, m, &cBinop_8Vri4xnw_sendMessage);
}

void Heavy_vocoder::cBinop_PwCRANZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_CEvBAn59_sendMessage);
}

void Heavy_vocoder::cBinop_8Vri4xnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZY4Qsvft, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZY4Qsvft_sendMessage);
}

void Heavy_vocoder::cBinop_ZY4Qsvft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_qzIGXxaU, 1, m);
}

void Heavy_vocoder::cBinop_CCfSmeS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_leWiNPFe, HV_BINOP_DIVIDE, 1, m, &cBinop_leWiNPFe_sendMessage);
}

void Heavy_vocoder::cBinop_WvUe4h7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bw5LSM8C_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8Vri4xnw, HV_BINOP_ADD, 0, m, &cBinop_8Vri4xnw_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_SuxBdc1B_sendMessage);
}

void Heavy_vocoder::cMsg_9T4F4VbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_x7UxPAzr_sendMessage);
}

void Heavy_vocoder::cSystem_x7UxPAzr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dvURc5T0, HV_BINOP_DIVIDE, 1, m, &cBinop_dvURc5T0_sendMessage);
}

void Heavy_vocoder::cVar_RDICHSuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_qLdu1w84_sendMessage);
}

void Heavy_vocoder::cVar_PkAd2mmz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_Cd69AVfx_sendMessage);
}

void Heavy_vocoder::cUnop_91Juaxp2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_gbkUQTEv_sendMessage);
}

void Heavy_vocoder::cBinop_dvURc5T0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o8PpxhSU, HV_BINOP_MULTIPLY, 1, m, &cBinop_o8PpxhSU_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_91Juaxp2_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fzIy1Vwn, HV_BINOP_DIVIDE, 0, m, &cBinop_fzIy1Vwn_sendMessage);
}

void Heavy_vocoder::cBinop_qLdu1w84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dvURc5T0, HV_BINOP_DIVIDE, 0, m, &cBinop_dvURc5T0_sendMessage);
}

void Heavy_vocoder::cBinop_fzIy1Vwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_NNVRNdQW_sendMessage);
}

void Heavy_vocoder::cBinop_m37I4K8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_AY8wXHQN_sendMessage);
}

void Heavy_vocoder::cBinop_AY8wXHQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_KjOCFiCi_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CCy2DT4K, HV_BINOP_MULTIPLY, 0, m, &cBinop_CCy2DT4K_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_o8PpxhSU, HV_BINOP_MULTIPLY, 0, m, &cBinop_o8PpxhSU_sendMessage);
}

void Heavy_vocoder::cBinop_gbkUQTEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CCy2DT4K, HV_BINOP_MULTIPLY, 1, m, &cBinop_CCy2DT4K_sendMessage);
}

void Heavy_vocoder::cBinop_CCy2DT4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ktb5JjKE_sendMessage);
}

void Heavy_vocoder::cCast_ojLNjPft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RDICHSuh, 0, m, &cVar_RDICHSuh_sendMessage);
}

void Heavy_vocoder::cBinop_XIBuwKRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_KEPxim6O_sendMessage);
}

void Heavy_vocoder::cBinop_KEPxim6O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_hPo81WmE, 5, m);
}

void Heavy_vocoder::cBinop_ktb5JjKE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_hPo81WmE, 4, m);
}

void Heavy_vocoder::cBinop_yN2aq3HZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ln9z2FiE, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ln9z2FiE_sendMessage);
}

void Heavy_vocoder::cBinop_o8PpxhSU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_paAwLCQC, HV_BINOP_ADD, 1, m, &cBinop_paAwLCQC_sendMessage);
}

void Heavy_vocoder::cBinop_KjOCFiCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XIBuwKRS_sendMessage);
}

void Heavy_vocoder::cBinop_paAwLCQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ln9z2FiE, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ln9z2FiE_sendMessage);
}

void Heavy_vocoder::cBinop_Ln9z2FiE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_hPo81WmE, 1, m);
}

void Heavy_vocoder::cBinop_Cd69AVfx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fzIy1Vwn, HV_BINOP_DIVIDE, 1, m, &cBinop_fzIy1Vwn_sendMessage);
}

void Heavy_vocoder::cBinop_NNVRNdQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_m37I4K8K_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_paAwLCQC, HV_BINOP_ADD, 0, m, &cBinop_paAwLCQC_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_yN2aq3HZ_sendMessage);
}

void Heavy_vocoder::cMsg_S5GoAFMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JnlonRTQ_sendMessage);
}

void Heavy_vocoder::cSystem_JnlonRTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n43j8P6s, HV_BINOP_DIVIDE, 1, m, &cBinop_n43j8P6s_sendMessage);
}

void Heavy_vocoder::cVar_y6wPJydI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_5O1rA2T6_sendMessage);
}

void Heavy_vocoder::cVar_DO0L2k3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_OMDotnty_sendMessage);
}

void Heavy_vocoder::cUnop_S22rSJ9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_CoiLNpeT_sendMessage);
}

void Heavy_vocoder::cBinop_n43j8P6s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eGUhI6rU, HV_BINOP_MULTIPLY, 1, m, &cBinop_eGUhI6rU_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_S22rSJ9X_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oIBDxQUr, HV_BINOP_DIVIDE, 0, m, &cBinop_oIBDxQUr_sendMessage);
}

void Heavy_vocoder::cBinop_5O1rA2T6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n43j8P6s, HV_BINOP_DIVIDE, 0, m, &cBinop_n43j8P6s_sendMessage);
}

void Heavy_vocoder::cBinop_oIBDxQUr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ENPY864i_sendMessage);
}

void Heavy_vocoder::cBinop_VExBjnFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_gbF3i3mL_sendMessage);
}

void Heavy_vocoder::cBinop_gbF3i3mL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_988L8BuN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LzKqsg0G, HV_BINOP_MULTIPLY, 0, m, &cBinop_LzKqsg0G_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_eGUhI6rU, HV_BINOP_MULTIPLY, 0, m, &cBinop_eGUhI6rU_sendMessage);
}

void Heavy_vocoder::cBinop_CoiLNpeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LzKqsg0G, HV_BINOP_MULTIPLY, 1, m, &cBinop_LzKqsg0G_sendMessage);
}

void Heavy_vocoder::cBinop_LzKqsg0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vokPoX4h_sendMessage);
}

void Heavy_vocoder::cCast_T4YnFpKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y6wPJydI, 0, m, &cVar_y6wPJydI_sendMessage);
}

void Heavy_vocoder::cBinop_RkosqHc7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_KvMHxARA_sendMessage);
}

void Heavy_vocoder::cBinop_KvMHxARA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_rkrYuhAQ, 5, m);
}

void Heavy_vocoder::cBinop_vokPoX4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_rkrYuhAQ, 4, m);
}

void Heavy_vocoder::cBinop_YUQFtXk3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZSwxWC13, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZSwxWC13_sendMessage);
}

void Heavy_vocoder::cBinop_eGUhI6rU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KG5PoxAC, HV_BINOP_ADD, 1, m, &cBinop_KG5PoxAC_sendMessage);
}

void Heavy_vocoder::cBinop_988L8BuN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RkosqHc7_sendMessage);
}

void Heavy_vocoder::cBinop_KG5PoxAC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZSwxWC13, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZSwxWC13_sendMessage);
}

void Heavy_vocoder::cBinop_ZSwxWC13_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_rkrYuhAQ, 1, m);
}

void Heavy_vocoder::cBinop_OMDotnty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oIBDxQUr, HV_BINOP_DIVIDE, 1, m, &cBinop_oIBDxQUr_sendMessage);
}

void Heavy_vocoder::cBinop_ENPY864i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VExBjnFA_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KG5PoxAC, HV_BINOP_ADD, 0, m, &cBinop_KG5PoxAC_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_YUQFtXk3_sendMessage);
}

void Heavy_vocoder::cBinop_2FVPkkxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_I6QdZpBx, 0, m);
}

void Heavy_vocoder::cBinop_yWlZOFkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_NVERCl1V_sendMessage);
}

void Heavy_vocoder::cBinop_NVERCl1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Ch8MoHZ, HV_BINOP_POW, 1, m, &cBinop_3Ch8MoHZ_sendMessage);
  cMsg_Dwh14qdK_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_3Ch8MoHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_2FVPkkxn_sendMessage);
}

void Heavy_vocoder::cMsg_Dwh14qdK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Ch8MoHZ, HV_BINOP_POW, 0, m, &cBinop_3Ch8MoHZ_sendMessage);
}

void Heavy_vocoder::cBinop_MBdFkRWa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_3ZQLMLQE, 0, m);
}

void Heavy_vocoder::cBinop_nJPMAcze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_o2v5Dyck_sendMessage);
}

void Heavy_vocoder::cBinop_o2v5Dyck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GrRkPjMr, HV_BINOP_POW, 1, m, &cBinop_GrRkPjMr_sendMessage);
  cMsg_p1vBrty3_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_GrRkPjMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_MBdFkRWa_sendMessage);
}

void Heavy_vocoder::cMsg_p1vBrty3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GrRkPjMr, HV_BINOP_POW, 0, m, &cBinop_GrRkPjMr_sendMessage);
}

void Heavy_vocoder::cBinop_rtpzi7vO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_8DlQSu4C, 0, m);
}

void Heavy_vocoder::cBinop_5fCm4UJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_ikYLPI8X_sendMessage);
}

void Heavy_vocoder::cBinop_ikYLPI8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6pHsWvlM, HV_BINOP_POW, 1, m, &cBinop_6pHsWvlM_sendMessage);
  cMsg_tzO60Zxi_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_6pHsWvlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_rtpzi7vO_sendMessage);
}

void Heavy_vocoder::cMsg_tzO60Zxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6pHsWvlM, HV_BINOP_POW, 0, m, &cBinop_6pHsWvlM_sendMessage);
}

void Heavy_vocoder::cBinop_cbCyLQun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MAfhIFqP_sendMessage);
}

void Heavy_vocoder::cBinop_MAfhIFqP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_QG2Hhujk_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dsrka29y_sendMessage);
}

void Heavy_vocoder::cVar_VuiAWtkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_207KDZ8V_sendMessage);
}

void Heavy_vocoder::cMsg_rhKnj02f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Z5Tmi5Yh_sendMessage);
}

void Heavy_vocoder::cSystem_Z5Tmi5Yh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XbX16hta, HV_BINOP_DIVIDE, 1, m, &cBinop_XbX16hta_sendMessage);
}

void Heavy_vocoder::cBinop_QG2Hhujk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_4cxmD5y4_sendMessage);
}

void Heavy_vocoder::cBinop_4cxmD5y4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Uj3JLSfo, m);
}

void Heavy_vocoder::cMsg_iAthWvaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_loLw2InW_sendMessage);
}

void Heavy_vocoder::cBinop_loLw2InW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_cbCyLQun_sendMessage);
}

void Heavy_vocoder::cBinop_dsrka29y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bM7bgDiJ, m);
}

void Heavy_vocoder::cBinop_207KDZ8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_YP88YIwa_sendMessage);
}

void Heavy_vocoder::cBinop_YP88YIwa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XbX16hta, HV_BINOP_DIVIDE, 0, m, &cBinop_XbX16hta_sendMessage);
}

void Heavy_vocoder::cBinop_XbX16hta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iAthWvaq_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_KUZI6Cxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_wlBwoV33_sendMessage);
}

void Heavy_vocoder::cBinop_wlBwoV33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_DZzvQtgz_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_s6J5Rxc6_sendMessage);
}

void Heavy_vocoder::cVar_ADXPFHjY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_EYIFgc7J_sendMessage);
}

void Heavy_vocoder::cMsg_sL8dvfRd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zMz1ThXQ_sendMessage);
}

void Heavy_vocoder::cSystem_zMz1ThXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LOqwGh3P, HV_BINOP_DIVIDE, 1, m, &cBinop_LOqwGh3P_sendMessage);
}

void Heavy_vocoder::cBinop_DZzvQtgz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_W67w267q_sendMessage);
}

void Heavy_vocoder::cBinop_W67w267q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OnizP16p, m);
}

void Heavy_vocoder::cMsg_1z0CNXIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_6bLGSy9b_sendMessage);
}

void Heavy_vocoder::cBinop_6bLGSy9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_KUZI6Cxf_sendMessage);
}

void Heavy_vocoder::cBinop_s6J5Rxc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4Q9HCGuP, m);
}

void Heavy_vocoder::cBinop_EYIFgc7J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_0r7WE1K5_sendMessage);
}

void Heavy_vocoder::cBinop_0r7WE1K5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LOqwGh3P, HV_BINOP_DIVIDE, 0, m, &cBinop_LOqwGh3P_sendMessage);
}

void Heavy_vocoder::cBinop_LOqwGh3P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1z0CNXIN_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_hzdxxBiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_nJPMAcze_sendMessage);
}

void Heavy_vocoder::cBinop_SM4h4JbT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_5fCm4UJs_sendMessage);
}

void Heavy_vocoder::cReceive_GWgFXb00_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GNw0pM2k, m);
}

void Heavy_vocoder::cReceive_C2UgN2mB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6uO896Q0, 0, m, &cVar_6uO896Q0_sendMessage);
  cMsg_5BuEmt3i_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fvIDeK6W, 0, m, &cVar_fvIDeK6W_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rHrYonve, 0, m, &cVar_rHrYonve_sendMessage);
  cMsg_99MBCGxR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_I7seJcky, 0, m, &cVar_I7seJcky_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tMQ1rKWO, 0, m, &cVar_tMQ1rKWO_sendMessage);
  cMsg_bMcs2rgv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9JQdFhFs, 0, m, &cVar_9JQdFhFs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ahDcmFrZ, 0, m, &cVar_ahDcmFrZ_sendMessage);
  cMsg_xzmJHqwI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PjH2iEPb, 0, m, &cVar_PjH2iEPb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kZ3XCnL1, 0, m, &cVar_kZ3XCnL1_sendMessage);
  cMsg_KkLZ5tKR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tyhTP9fM, 0, m, &cVar_tyhTP9fM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yosBGH5U, 0, m, &cVar_yosBGH5U_sendMessage);
  cMsg_XkqNsJgQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_s9mABigP, 0, m, &cVar_s9mABigP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Nst9GO0K, 0, m, &cVar_Nst9GO0K_sendMessage);
  cMsg_0uPuw2ZX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wmoExvtg, 0, m, &cVar_wmoExvtg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NbSqTwgS, 0, m, &cVar_NbSqTwgS_sendMessage);
  cMsg_kGRXQ7vM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ydUNarMS, 0, m, &cVar_ydUNarMS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BjV51JTr, 0, m, &cVar_BjV51JTr_sendMessage);
  cMsg_ZfW8UEfk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rHUyKjZF, 0, m, &cVar_rHUyKjZF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eN7G6jmO, 0, m, &cVar_eN7G6jmO_sendMessage);
  cMsg_CCMLWCBb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qumArxdx, 0, m, &cVar_qumArxdx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0l36Qx6g, 0, m, &cVar_0l36Qx6g_sendMessage);
  cMsg_BDJB2mUW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EF4bl0JC, 0, m, &cVar_EF4bl0JC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8fqgXf1h, 0, m, &cVar_8fqgXf1h_sendMessage);
  cMsg_HqWuyIKV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qOInCZIY, 0, m, &cVar_qOInCZIY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PkAd2mmz, 0, m, &cVar_PkAd2mmz_sendMessage);
  cMsg_9T4F4VbL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RDICHSuh, 0, m, &cVar_RDICHSuh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DO0L2k3u, 0, m, &cVar_DO0L2k3u_sendMessage);
  cMsg_S5GoAFMp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_y6wPJydI, 0, m, &cVar_y6wPJydI_sendMessage);
  cMsg_rhKnj02f_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VuiAWtkg, 0, m, &cVar_VuiAWtkg_sendMessage);
  cMsg_sL8dvfRd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ADXPFHjY, 0, m, &cVar_ADXPFHjY_sendMessage);
}

void Heavy_vocoder::cReceive_1SKHmu8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_yWlZOFkR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hzdxxBiS, HV_BINOP_ADD, 0, m, &cBinop_hzdxxBiS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SM4h4JbT, HV_BINOP_ADD, 0, m, &cBinop_SM4h4JbT_sendMessage);
}

void Heavy_vocoder::cReceive_GnK5qt7W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_H7uA5rCb, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_zE4nqwOY, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_f2VRGyiu, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rdkmcD98, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_g5ewJ2sc, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_dVyfZOld, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vcCSWB0t, m);
}

void Heavy_vocoder::cReceive_ESAAHOVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SM4h4JbT, HV_BINOP_ADD, 1, m, &cBinop_SM4h4JbT_sendMessage);
}

void Heavy_vocoder::cReceive_FAQpssX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hzdxxBiS, HV_BINOP_ADD, 1, m, &cBinop_hzdxxBiS_sendMessage);
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

int Heavy_vocoder::process(float **inputBuffers, float **outputBuffers, int n) {
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6;

  // input and output vars
  hv_bufferf_t O0;
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

    // process all signal functions
    __hv_add_f(VIf(I0), VIf(I1), VOf(Bf0));
    __hv_varread_f(&sVarf_GNw0pM2k, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_I6QdZpBx, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_8DlQSu4C, VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_3ZQLMLQE, VOf(Bf0));
    __hv_add_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_d6KHWaeZ, VIf(Bf2), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_PLvj8Bwq, VIf(Bf1), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_FAC0Mld6, VOf(Bf4));
    __hv_varread_f(&sVarf_H7uA5rCb, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_max_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_FAC0Mld6, VIf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_KbQArNnJ, VIf(Bf2), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_dTZVUgdM, VIf(Bf1), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_xF0aadOr, VOf(Bf4));
    __hv_varread_f(&sVarf_zE4nqwOY, VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_max_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_f(&sVarf_xF0aadOr, VIf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_biquad_k_f(&sBiquad_k_739r17jG, VIf(Bf2), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_NpVVprYy, VIf(Bf1), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_94DEBMTv, VOf(Bf3));
    __hv_varread_f(&sVarf_f2VRGyiu, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_max_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_94DEBMTv, VIf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_nDwlVgXU, VIf(Bf2), VOf(Bf6));
    __hv_biquad_k_f(&sBiquad_k_0WZCY8v6, VIf(Bf1), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_6dZiTnsL, VOf(Bf0));
    __hv_varread_f(&sVarf_rdkmcD98, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_max_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_6dZiTnsL, VIf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_biquad_k_f(&sBiquad_k_8v0Yxpmx, VIf(Bf2), VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_W7m5eK9j, VIf(Bf1), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_pnZd5RXQ, VOf(Bf5));
    __hv_varread_f(&sVarf_g5ewJ2sc, VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_max_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_pnZd5RXQ, VIf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_qzIGXxaU, VIf(Bf2), VOf(Bf3));
    __hv_biquad_k_f(&sBiquad_k_05Q27N78, VIf(Bf1), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_t3rwDapQ, VOf(Bf6));
    __hv_varread_f(&sVarf_dVyfZOld, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_max_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_t3rwDapQ, VIf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_rkrYuhAQ, VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_hPo81WmE, VIf(Bf1), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_u6LLafHB, VOf(Bf3));
    __hv_varread_f(&sVarf_vcCSWB0t, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_max_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_u6LLafHB, VIf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f);
    __hv_varread_f(&sVarf_bM7bgDiJ, VOf(Bf2));
    __hv_rpole_f(&sRPole_zdIGDVnp, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_z0iPhCA2, VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_Uj3JLSfo, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_4Q9HCGuP, VOf(Bf1));
    __hv_rpole_f(&sRPole_UxG6JsOJ, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_Ie9sASqY, VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_OnizP16p, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_vocoder::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s)
  float **const bIn = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bIn[0] = inputBuffers+(0*n4);
  bIn[1] = inputBuffers+(1*n4);

  // define the heavy output buffer for 1 channel(s)
  float **const bOut = &outputBuffers;

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_vocoder::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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

  // define the heavy output buffer for 1 channel(s)
  float *const bOut = outputBuffers;

  int n = processInline(bIn, bOut, n4);

  

  return n;
}
