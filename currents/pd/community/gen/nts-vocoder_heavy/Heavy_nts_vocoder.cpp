/** the author of nts-vocoder.pd */

#include "Heavy_nts_vocoder.hpp"



#define Context(_c) static_cast<Heavy_nts_vocoder *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_nts_vocoder::Heavy_nts_vocoder(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_6iw1wmET, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_CqkdowBO, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_hmsttqVV, 0.0f, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_SQnToxe0, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_EDia1r6g, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_3yJJV2h6, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_5KrHzr2j, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_I9mcd1SN, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_o2tTVK5r, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_DOm7q3Md, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_nQECQHie, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_cbCs9w56, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_7WTnJaDX, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_9fmjbm79, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_j6VhDOaT, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_gtW1cbay, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_DPmibssi, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sRPole_init(&sRPole_obZtO8sy);
  numBytes += sDel1_init(&sDel1_YTjCulcc);
  numBytes += sRPole_init(&sRPole_Cm8bi1Ee);
  numBytes += sDel1_init(&sDel1_2d9EB9b0);
  numBytes += sVarf_init(&sVarf_Oz4n1uVG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_d4VwX28y, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YixK1Rmt, 267.0f);
  numBytes += cVar_init_f(&cVar_RM5FdSBs, 15.0f);
  numBytes += cBinop_init(&cBinop_RTFuMdrf, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_pGwwcCot, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_3yJcDzph, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_4KafuUxW, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_NCKv1UHj, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_6STNye6p, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_p9tHzTMv, 267.0f);
  numBytes += cVar_init_f(&cVar_FdBs7ebD, 15.0f);
  numBytes += cBinop_init(&cBinop_gHymJn8O, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_KEFN603K, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_hraHiIeO, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_2kmw5Y02, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_kZ2qPUEY, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_av6SgbXQ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_OGxuROUM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OEtjjU3V, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_T2Tj8CSr, 444.0f);
  numBytes += cVar_init_f(&cVar_mHNi7AqA, 15.0f);
  numBytes += cBinop_init(&cBinop_QUJPlV1O, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_nMjciqt9, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_So0GDQnN, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_hxZjUfPw, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_wLYo04vg, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_pP6T1svP, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_esXdxme8, 444.0f);
  numBytes += cVar_init_f(&cVar_JtEKoDhX, 15.0f);
  numBytes += cBinop_init(&cBinop_TaA3X42e, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_GnNysi3E, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Dhaoy0FY, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_sRAXWNE5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_93tFPSqz, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_MQJD8X8f, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_4MQe9Q9c, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_w2nXvRR9, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_HVKlP3ru, 741.0f);
  numBytes += cVar_init_f(&cVar_tg69EZ3u, 15.0f);
  numBytes += cBinop_init(&cBinop_AxdbTQmt, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_xZQD6kbh, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_TMrEkzp8, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_dyx00ejj, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_EJB7lirT, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_gvG82103, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_gM8ejy9j, 741.0f);
  numBytes += cVar_init_f(&cVar_fiNgKfSB, 15.0f);
  numBytes += cBinop_init(&cBinop_mug4bLQC, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_tzSGmCF0, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_wSogky8i, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Xc4qR66W, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_5m1KIiUU, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_B4exkvNI, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_j0HFUdtC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cLtMPWBx, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mDw0wg55, 1235.0f);
  numBytes += cVar_init_f(&cVar_jHDIMGW8, 15.0f);
  numBytes += cBinop_init(&cBinop_oN5LVAtu, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ZgzEDE4D, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_7MYmK8yV, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_6XNRT10s, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ugPk176l, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Mwdv6efh, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_anDjKHRe, 1235.0f);
  numBytes += cVar_init_f(&cVar_o3R3vHG6, 15.0f);
  numBytes += cBinop_init(&cBinop_Yl1Csfrx, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_0wnC7OLY, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_HFHlhrIK, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_nLTY7DvY, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Hu5gwuVX, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_l15DnFwc, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_i7C78kGP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8snY8SG1, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_88TEvAfv, 2058.0f);
  numBytes += cVar_init_f(&cVar_fwaLcR1G, 15.0f);
  numBytes += cBinop_init(&cBinop_U8HsPYc5, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_gT1KMmuT, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_EbTSdyGY, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Abe2TXQW, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_MlphFeJd, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_IRnDPpMa, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_TwTXGK9n, 2058.0f);
  numBytes += cVar_init_f(&cVar_IjaqvDfo, 15.0f);
  numBytes += cBinop_init(&cBinop_db4aeu7i, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_7bLkxqrL, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_5UM4Mbt6, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_DjxAN0X1, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_updNAD7S, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_BzF1nXAz, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_letvboYU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kKUWflUm, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_CrURPHej, 3429.0f);
  numBytes += cVar_init_f(&cVar_RRmE9Xkp, 15.0f);
  numBytes += cBinop_init(&cBinop_4QnRzVIq, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_43Mla2hA, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_3VIPDl2s, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Gt31lx5c, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_422pdeA5, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_GBmVXmzL, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_HXsREdRg, 3429.0f);
  numBytes += cVar_init_f(&cVar_X3Xnh4EK, 15.0f);
  numBytes += cBinop_init(&cBinop_pNB8QkpX, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_EwGfa4vy, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_z8cJtzkH, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_MDf78fgy, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_p5nIJEUD, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_vGe0U5ju, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_p6BhtjAB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_etyI9IeY, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_OKGNGmpr, 5716.0f);
  numBytes += cVar_init_f(&cVar_ac1LgYUJ, 15.0f);
  numBytes += cBinop_init(&cBinop_4xcuEToW, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_10cAXJHl, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_rRDIagEy, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_9DFJcpm5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_mEwWWuy4, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_qvKd5C5r, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_x0n69pAZ, 5716.0f);
  numBytes += cVar_init_f(&cVar_cfIPneq7, 15.0f);
  numBytes += cBinop_init(&cBinop_aWziDoKS, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_5rkh0X2U, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_fZdQdvtT, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_8xczqoXn, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_AMDjZ5Y5, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_hIt1T54X, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_KVsD6jfI, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_iSRQnJpq, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_g02IfEOR, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_rY7VxsJI, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_7pk3Cj4v, 10000.0f);
  numBytes += cBinop_init(&cBinop_j4gFQY9b, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_qTzgevzt, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RwWuedIc, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_NbJvFOX3, 10000.0f);
  numBytes += cBinop_init(&cBinop_A0sC3zC1, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_adhKK5Qv, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_zN7Hi0OE, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_CJ0Wn9yw, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_OiSbRadd, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_nts_vocoder::~Heavy_nts_vocoder() {
  // nothing to free
}

HvTable *Heavy_nts_vocoder::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_nts_vocoder::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FHIm9JMy_sendMessage);
      break;
    }
    case 0x6C87328F: { // alt_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TVKmZdSp_sendMessage);
      break;
    }
    case 0x3FD8ECD5: { // note1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QhGyeGqm_sendMessage);
      break;
    }
    case 0x97165D01: { // note2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_T9pyh69s_sendMessage);
      break;
    }
    case 0xA23B621F: { // pitch_note
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ROPElXc0_sendMessage);
      break;
    }
    case 0xCE9531B0: { // shape_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HB72VhcS_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_nts_vocoder::getParameterInfo(int index, HvParameterInfo *info) {
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


void Heavy_nts_vocoder::cMsg_AsMzVna6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_keK41bpr_sendMessage);
}

void Heavy_nts_vocoder::cSystem_keK41bpr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RTFuMdrf, HV_BINOP_DIVIDE, 1, m, &cBinop_RTFuMdrf_sendMessage);
}

void Heavy_nts_vocoder::cVar_YixK1Rmt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_8yxkkyU4_sendMessage);
}

void Heavy_nts_vocoder::cVar_RM5FdSBs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_hBQPAfkV_sendMessage);
}

void Heavy_nts_vocoder::cUnop_zShCAqJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_G7pTmAvc_sendMessage);
}

void Heavy_nts_vocoder::cBinop_RTFuMdrf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4KafuUxW, HV_BINOP_MULTIPLY, 1, m, &cBinop_4KafuUxW_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_zShCAqJ9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pGwwcCot, HV_BINOP_DIVIDE, 0, m, &cBinop_pGwwcCot_sendMessage);
}

void Heavy_nts_vocoder::cBinop_8yxkkyU4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RTFuMdrf, HV_BINOP_DIVIDE, 0, m, &cBinop_RTFuMdrf_sendMessage);
}

void Heavy_nts_vocoder::cBinop_pGwwcCot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_sZDmhOs3_sendMessage);
}

void Heavy_nts_vocoder::cBinop_6kNwpL4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_faPvDqN0_sendMessage);
}

void Heavy_nts_vocoder::cBinop_faPvDqN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_iQnMl686_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3yJcDzph, HV_BINOP_MULTIPLY, 0, m, &cBinop_3yJcDzph_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4KafuUxW, HV_BINOP_MULTIPLY, 0, m, &cBinop_4KafuUxW_sendMessage);
}

void Heavy_nts_vocoder::cBinop_G7pTmAvc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3yJcDzph, HV_BINOP_MULTIPLY, 1, m, &cBinop_3yJcDzph_sendMessage);
}

void Heavy_nts_vocoder::cBinop_3yJcDzph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1hY51DY1_sendMessage);
}

void Heavy_nts_vocoder::cCast_gR1KGUTP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YixK1Rmt, 0, m, &cVar_YixK1Rmt_sendMessage);
}

void Heavy_nts_vocoder::cBinop_FbukzvZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RZfogCVZ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_RZfogCVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_EDia1r6g, 5, m);
}

void Heavy_nts_vocoder::cBinop_1hY51DY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_EDia1r6g, 4, m);
}

void Heavy_nts_vocoder::cBinop_WWSVYczJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6STNye6p, HV_BINOP_MULTIPLY, 0, m, &cBinop_6STNye6p_sendMessage);
}

void Heavy_nts_vocoder::cBinop_4KafuUxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NCKv1UHj, HV_BINOP_ADD, 1, m, &cBinop_NCKv1UHj_sendMessage);
}

void Heavy_nts_vocoder::cBinop_iQnMl686_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FbukzvZr_sendMessage);
}

void Heavy_nts_vocoder::cBinop_NCKv1UHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6STNye6p, HV_BINOP_MULTIPLY, 1, m, &cBinop_6STNye6p_sendMessage);
}

void Heavy_nts_vocoder::cBinop_6STNye6p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_EDia1r6g, 1, m);
}

void Heavy_nts_vocoder::cBinop_hBQPAfkV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pGwwcCot, HV_BINOP_DIVIDE, 1, m, &cBinop_pGwwcCot_sendMessage);
}

void Heavy_nts_vocoder::cBinop_sZDmhOs3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_6kNwpL4Y_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NCKv1UHj, HV_BINOP_ADD, 0, m, &cBinop_NCKv1UHj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_WWSVYczJ_sendMessage);
}

void Heavy_nts_vocoder::cMsg_IC9Aut0e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qVLsGaht_sendMessage);
}

void Heavy_nts_vocoder::cSystem_qVLsGaht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gHymJn8O, HV_BINOP_DIVIDE, 1, m, &cBinop_gHymJn8O_sendMessage);
}

void Heavy_nts_vocoder::cVar_p9tHzTMv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_x256y68k_sendMessage);
}

void Heavy_nts_vocoder::cVar_FdBs7ebD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_2CPejXVI_sendMessage);
}

void Heavy_nts_vocoder::cUnop_VSqSYdz2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_3qRLsgpD_sendMessage);
}

void Heavy_nts_vocoder::cBinop_gHymJn8O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2kmw5Y02, HV_BINOP_MULTIPLY, 1, m, &cBinop_2kmw5Y02_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_VSqSYdz2_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KEFN603K, HV_BINOP_DIVIDE, 0, m, &cBinop_KEFN603K_sendMessage);
}

void Heavy_nts_vocoder::cBinop_x256y68k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gHymJn8O, HV_BINOP_DIVIDE, 0, m, &cBinop_gHymJn8O_sendMessage);
}

void Heavy_nts_vocoder::cBinop_KEFN603K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_dinnLUgl_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Hj2WBcMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_NZBrEj83_sendMessage);
}

void Heavy_nts_vocoder::cBinop_NZBrEj83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_7doz5fY9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hraHiIeO, HV_BINOP_MULTIPLY, 0, m, &cBinop_hraHiIeO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2kmw5Y02, HV_BINOP_MULTIPLY, 0, m, &cBinop_2kmw5Y02_sendMessage);
}

void Heavy_nts_vocoder::cBinop_3qRLsgpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hraHiIeO, HV_BINOP_MULTIPLY, 1, m, &cBinop_hraHiIeO_sendMessage);
}

void Heavy_nts_vocoder::cBinop_hraHiIeO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_W9197Iti_sendMessage);
}

void Heavy_nts_vocoder::cCast_dYlq2jzS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p9tHzTMv, 0, m, &cVar_p9tHzTMv_sendMessage);
}

void Heavy_nts_vocoder::cBinop_KgDtp59L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FJDA8Os5_sendMessage);
}

void Heavy_nts_vocoder::cBinop_FJDA8Os5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_SQnToxe0, 5, m);
}

void Heavy_nts_vocoder::cBinop_W9197Iti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_SQnToxe0, 4, m);
}

void Heavy_nts_vocoder::cBinop_vU5w7RjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_av6SgbXQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_av6SgbXQ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_2kmw5Y02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kZ2qPUEY, HV_BINOP_ADD, 1, m, &cBinop_kZ2qPUEY_sendMessage);
}

void Heavy_nts_vocoder::cBinop_7doz5fY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_KgDtp59L_sendMessage);
}

void Heavy_nts_vocoder::cBinop_kZ2qPUEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_av6SgbXQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_av6SgbXQ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_av6SgbXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_SQnToxe0, 1, m);
}

void Heavy_nts_vocoder::cBinop_2CPejXVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KEFN603K, HV_BINOP_DIVIDE, 1, m, &cBinop_KEFN603K_sendMessage);
}

void Heavy_nts_vocoder::cBinop_dinnLUgl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Hj2WBcMh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_kZ2qPUEY, HV_BINOP_ADD, 0, m, &cBinop_kZ2qPUEY_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_vU5w7RjP_sendMessage);
}

void Heavy_nts_vocoder::cMsg_8gmUS9DS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dnRZW4Cq_sendMessage);
}

void Heavy_nts_vocoder::cSystem_dnRZW4Cq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QUJPlV1O, HV_BINOP_DIVIDE, 1, m, &cBinop_QUJPlV1O_sendMessage);
}

void Heavy_nts_vocoder::cVar_T2Tj8CSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_gjPDG9VH_sendMessage);
}

void Heavy_nts_vocoder::cVar_mHNi7AqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_Q52NS7u4_sendMessage);
}

void Heavy_nts_vocoder::cUnop_2vs6LaVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_uInMw81a_sendMessage);
}

void Heavy_nts_vocoder::cBinop_QUJPlV1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hxZjUfPw, HV_BINOP_MULTIPLY, 1, m, &cBinop_hxZjUfPw_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_2vs6LaVn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nMjciqt9, HV_BINOP_DIVIDE, 0, m, &cBinop_nMjciqt9_sendMessage);
}

void Heavy_nts_vocoder::cBinop_gjPDG9VH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QUJPlV1O, HV_BINOP_DIVIDE, 0, m, &cBinop_QUJPlV1O_sendMessage);
}

void Heavy_nts_vocoder::cBinop_nMjciqt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_NKcCErV4_sendMessage);
}

void Heavy_nts_vocoder::cBinop_YduyFxBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_aWexSpXS_sendMessage);
}

void Heavy_nts_vocoder::cBinop_aWexSpXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_GMqzXypi_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_So0GDQnN, HV_BINOP_MULTIPLY, 0, m, &cBinop_So0GDQnN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hxZjUfPw, HV_BINOP_MULTIPLY, 0, m, &cBinop_hxZjUfPw_sendMessage);
}

void Heavy_nts_vocoder::cBinop_uInMw81a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_So0GDQnN, HV_BINOP_MULTIPLY, 1, m, &cBinop_So0GDQnN_sendMessage);
}

void Heavy_nts_vocoder::cBinop_So0GDQnN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_IR5fLIXS_sendMessage);
}

void Heavy_nts_vocoder::cCast_oUqF1E5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T2Tj8CSr, 0, m, &cVar_T2Tj8CSr_sendMessage);
}

void Heavy_nts_vocoder::cBinop_NVs3kfcg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_X8yyxGfZ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_X8yyxGfZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_5KrHzr2j, 5, m);
}

void Heavy_nts_vocoder::cBinop_IR5fLIXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_5KrHzr2j, 4, m);
}

void Heavy_nts_vocoder::cBinop_HRjZ4d4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pP6T1svP, HV_BINOP_MULTIPLY, 0, m, &cBinop_pP6T1svP_sendMessage);
}

void Heavy_nts_vocoder::cBinop_hxZjUfPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wLYo04vg, HV_BINOP_ADD, 1, m, &cBinop_wLYo04vg_sendMessage);
}

void Heavy_nts_vocoder::cBinop_GMqzXypi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_NVs3kfcg_sendMessage);
}

void Heavy_nts_vocoder::cBinop_wLYo04vg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pP6T1svP, HV_BINOP_MULTIPLY, 1, m, &cBinop_pP6T1svP_sendMessage);
}

void Heavy_nts_vocoder::cBinop_pP6T1svP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_5KrHzr2j, 1, m);
}

void Heavy_nts_vocoder::cBinop_Q52NS7u4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nMjciqt9, HV_BINOP_DIVIDE, 1, m, &cBinop_nMjciqt9_sendMessage);
}

void Heavy_nts_vocoder::cBinop_NKcCErV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_YduyFxBG_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wLYo04vg, HV_BINOP_ADD, 0, m, &cBinop_wLYo04vg_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_HRjZ4d4s_sendMessage);
}

void Heavy_nts_vocoder::cMsg_NDBAivB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NXslXRbN_sendMessage);
}

void Heavy_nts_vocoder::cSystem_NXslXRbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TaA3X42e, HV_BINOP_DIVIDE, 1, m, &cBinop_TaA3X42e_sendMessage);
}

void Heavy_nts_vocoder::cVar_esXdxme8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_eyJk4bro_sendMessage);
}

void Heavy_nts_vocoder::cVar_JtEKoDhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_4OHmZBId_sendMessage);
}

void Heavy_nts_vocoder::cUnop_cEwzi902_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_d37N0hHg_sendMessage);
}

void Heavy_nts_vocoder::cBinop_TaA3X42e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sRAXWNE5, HV_BINOP_MULTIPLY, 1, m, &cBinop_sRAXWNE5_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_cEwzi902_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GnNysi3E, HV_BINOP_DIVIDE, 0, m, &cBinop_GnNysi3E_sendMessage);
}

void Heavy_nts_vocoder::cBinop_eyJk4bro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TaA3X42e, HV_BINOP_DIVIDE, 0, m, &cBinop_TaA3X42e_sendMessage);
}

void Heavy_nts_vocoder::cBinop_GnNysi3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Ptx7bGKb_sendMessage);
}

void Heavy_nts_vocoder::cBinop_LX6fuBnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TlYZWNUU_sendMessage);
}

void Heavy_nts_vocoder::cBinop_TlYZWNUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_6gAw2i9g_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dhaoy0FY, HV_BINOP_MULTIPLY, 0, m, &cBinop_Dhaoy0FY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sRAXWNE5, HV_BINOP_MULTIPLY, 0, m, &cBinop_sRAXWNE5_sendMessage);
}

void Heavy_nts_vocoder::cBinop_d37N0hHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dhaoy0FY, HV_BINOP_MULTIPLY, 1, m, &cBinop_Dhaoy0FY_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Dhaoy0FY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_odNnMrmM_sendMessage);
}

void Heavy_nts_vocoder::cCast_kxGDjqWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_esXdxme8, 0, m, &cVar_esXdxme8_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Ki3cRWMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_N1DppNkr_sendMessage);
}

void Heavy_nts_vocoder::cBinop_N1DppNkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3yJJV2h6, 5, m);
}

void Heavy_nts_vocoder::cBinop_odNnMrmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3yJJV2h6, 4, m);
}

void Heavy_nts_vocoder::cBinop_tbLgw1Wn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MQJD8X8f, HV_BINOP_MULTIPLY, 0, m, &cBinop_MQJD8X8f_sendMessage);
}

void Heavy_nts_vocoder::cBinop_sRAXWNE5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_93tFPSqz, HV_BINOP_ADD, 1, m, &cBinop_93tFPSqz_sendMessage);
}

void Heavy_nts_vocoder::cBinop_6gAw2i9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Ki3cRWMg_sendMessage);
}

void Heavy_nts_vocoder::cBinop_93tFPSqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MQJD8X8f, HV_BINOP_MULTIPLY, 1, m, &cBinop_MQJD8X8f_sendMessage);
}

void Heavy_nts_vocoder::cBinop_MQJD8X8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3yJJV2h6, 1, m);
}

void Heavy_nts_vocoder::cBinop_4OHmZBId_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GnNysi3E, HV_BINOP_DIVIDE, 1, m, &cBinop_GnNysi3E_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Ptx7bGKb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_LX6fuBnp_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_93tFPSqz, HV_BINOP_ADD, 0, m, &cBinop_93tFPSqz_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_tbLgw1Wn_sendMessage);
}

void Heavy_nts_vocoder::cMsg_U7nQc2Dd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zqPtIxwB_sendMessage);
}

void Heavy_nts_vocoder::cSystem_zqPtIxwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AxdbTQmt, HV_BINOP_DIVIDE, 1, m, &cBinop_AxdbTQmt_sendMessage);
}

void Heavy_nts_vocoder::cVar_HVKlP3ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_4V886oXw_sendMessage);
}

void Heavy_nts_vocoder::cVar_tg69EZ3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_BzRy7p5X_sendMessage);
}

void Heavy_nts_vocoder::cUnop_JmXgUl4o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_7s2aCUas_sendMessage);
}

void Heavy_nts_vocoder::cBinop_AxdbTQmt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dyx00ejj, HV_BINOP_MULTIPLY, 1, m, &cBinop_dyx00ejj_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_JmXgUl4o_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xZQD6kbh, HV_BINOP_DIVIDE, 0, m, &cBinop_xZQD6kbh_sendMessage);
}

void Heavy_nts_vocoder::cBinop_4V886oXw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AxdbTQmt, HV_BINOP_DIVIDE, 0, m, &cBinop_AxdbTQmt_sendMessage);
}

void Heavy_nts_vocoder::cBinop_xZQD6kbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1V4u316u_sendMessage);
}

void Heavy_nts_vocoder::cBinop_vecFj77o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_jg2TR7vK_sendMessage);
}

void Heavy_nts_vocoder::cBinop_jg2TR7vK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_lJex7nb4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TMrEkzp8, HV_BINOP_MULTIPLY, 0, m, &cBinop_TMrEkzp8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dyx00ejj, HV_BINOP_MULTIPLY, 0, m, &cBinop_dyx00ejj_sendMessage);
}

void Heavy_nts_vocoder::cBinop_7s2aCUas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TMrEkzp8, HV_BINOP_MULTIPLY, 1, m, &cBinop_TMrEkzp8_sendMessage);
}

void Heavy_nts_vocoder::cBinop_TMrEkzp8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_zlnjIpEG_sendMessage);
}

void Heavy_nts_vocoder::cCast_xAfWK5ZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HVKlP3ru, 0, m, &cVar_HVKlP3ru_sendMessage);
}

void Heavy_nts_vocoder::cBinop_9Ngryqtx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1ApLlipJ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_1ApLlipJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_o2tTVK5r, 5, m);
}

void Heavy_nts_vocoder::cBinop_zlnjIpEG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_o2tTVK5r, 4, m);
}

void Heavy_nts_vocoder::cBinop_Vt4jogKM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gvG82103, HV_BINOP_MULTIPLY, 0, m, &cBinop_gvG82103_sendMessage);
}

void Heavy_nts_vocoder::cBinop_dyx00ejj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EJB7lirT, HV_BINOP_ADD, 1, m, &cBinop_EJB7lirT_sendMessage);
}

void Heavy_nts_vocoder::cBinop_lJex7nb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9Ngryqtx_sendMessage);
}

void Heavy_nts_vocoder::cBinop_EJB7lirT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gvG82103, HV_BINOP_MULTIPLY, 1, m, &cBinop_gvG82103_sendMessage);
}

void Heavy_nts_vocoder::cBinop_gvG82103_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_o2tTVK5r, 1, m);
}

void Heavy_nts_vocoder::cBinop_BzRy7p5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xZQD6kbh, HV_BINOP_DIVIDE, 1, m, &cBinop_xZQD6kbh_sendMessage);
}

void Heavy_nts_vocoder::cBinop_1V4u316u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vecFj77o_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EJB7lirT, HV_BINOP_ADD, 0, m, &cBinop_EJB7lirT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_Vt4jogKM_sendMessage);
}

void Heavy_nts_vocoder::cMsg_tMbUIG3m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Qhs7YXEU_sendMessage);
}

void Heavy_nts_vocoder::cSystem_Qhs7YXEU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mug4bLQC, HV_BINOP_DIVIDE, 1, m, &cBinop_mug4bLQC_sendMessage);
}

void Heavy_nts_vocoder::cVar_gM8ejy9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_sRlpOej0_sendMessage);
}

void Heavy_nts_vocoder::cVar_fiNgKfSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_V5VGQUwL_sendMessage);
}

void Heavy_nts_vocoder::cUnop_1v8oZftb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_VVsJMYd9_sendMessage);
}

void Heavy_nts_vocoder::cBinop_mug4bLQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xc4qR66W, HV_BINOP_MULTIPLY, 1, m, &cBinop_Xc4qR66W_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_1v8oZftb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tzSGmCF0, HV_BINOP_DIVIDE, 0, m, &cBinop_tzSGmCF0_sendMessage);
}

void Heavy_nts_vocoder::cBinop_sRlpOej0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mug4bLQC, HV_BINOP_DIVIDE, 0, m, &cBinop_mug4bLQC_sendMessage);
}

void Heavy_nts_vocoder::cBinop_tzSGmCF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2YQfQCdg_sendMessage);
}

void Heavy_nts_vocoder::cBinop_7WLQNR3b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_uPjp7tMD_sendMessage);
}

void Heavy_nts_vocoder::cBinop_uPjp7tMD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_TbmHrkFD_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wSogky8i, HV_BINOP_MULTIPLY, 0, m, &cBinop_wSogky8i_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xc4qR66W, HV_BINOP_MULTIPLY, 0, m, &cBinop_Xc4qR66W_sendMessage);
}

void Heavy_nts_vocoder::cBinop_VVsJMYd9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wSogky8i, HV_BINOP_MULTIPLY, 1, m, &cBinop_wSogky8i_sendMessage);
}

void Heavy_nts_vocoder::cBinop_wSogky8i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XE4LWGkb_sendMessage);
}

void Heavy_nts_vocoder::cCast_oCDEkumE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gM8ejy9j, 0, m, &cVar_gM8ejy9j_sendMessage);
}

void Heavy_nts_vocoder::cBinop_GJjvSyJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vOdGzpbc_sendMessage);
}

void Heavy_nts_vocoder::cBinop_vOdGzpbc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_I9mcd1SN, 5, m);
}

void Heavy_nts_vocoder::cBinop_XE4LWGkb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_I9mcd1SN, 4, m);
}

void Heavy_nts_vocoder::cBinop_teYo3fhS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B4exkvNI, HV_BINOP_MULTIPLY, 0, m, &cBinop_B4exkvNI_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Xc4qR66W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5m1KIiUU, HV_BINOP_ADD, 1, m, &cBinop_5m1KIiUU_sendMessage);
}

void Heavy_nts_vocoder::cBinop_TbmHrkFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GJjvSyJl_sendMessage);
}

void Heavy_nts_vocoder::cBinop_5m1KIiUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B4exkvNI, HV_BINOP_MULTIPLY, 1, m, &cBinop_B4exkvNI_sendMessage);
}

void Heavy_nts_vocoder::cBinop_B4exkvNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_I9mcd1SN, 1, m);
}

void Heavy_nts_vocoder::cBinop_V5VGQUwL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tzSGmCF0, HV_BINOP_DIVIDE, 1, m, &cBinop_tzSGmCF0_sendMessage);
}

void Heavy_nts_vocoder::cBinop_2YQfQCdg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7WLQNR3b_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5m1KIiUU, HV_BINOP_ADD, 0, m, &cBinop_5m1KIiUU_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_teYo3fhS_sendMessage);
}

void Heavy_nts_vocoder::cMsg_3zVwYrnY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8CGKHQBp_sendMessage);
}

void Heavy_nts_vocoder::cSystem_8CGKHQBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oN5LVAtu, HV_BINOP_DIVIDE, 1, m, &cBinop_oN5LVAtu_sendMessage);
}

void Heavy_nts_vocoder::cVar_mDw0wg55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_rbSNttsi_sendMessage);
}

void Heavy_nts_vocoder::cVar_jHDIMGW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_YSHX1uln_sendMessage);
}

void Heavy_nts_vocoder::cUnop_6gntcrFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_AZkv24Pv_sendMessage);
}

void Heavy_nts_vocoder::cBinop_oN5LVAtu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6XNRT10s, HV_BINOP_MULTIPLY, 1, m, &cBinop_6XNRT10s_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_6gntcrFT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZgzEDE4D, HV_BINOP_DIVIDE, 0, m, &cBinop_ZgzEDE4D_sendMessage);
}

void Heavy_nts_vocoder::cBinop_rbSNttsi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oN5LVAtu, HV_BINOP_DIVIDE, 0, m, &cBinop_oN5LVAtu_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ZgzEDE4D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_dKaaXBIX_sendMessage);
}

void Heavy_nts_vocoder::cBinop_UaJJ6NQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_AbRoGANk_sendMessage);
}

void Heavy_nts_vocoder::cBinop_AbRoGANk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_JUv3mGH6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7MYmK8yV, HV_BINOP_MULTIPLY, 0, m, &cBinop_7MYmK8yV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6XNRT10s, HV_BINOP_MULTIPLY, 0, m, &cBinop_6XNRT10s_sendMessage);
}

void Heavy_nts_vocoder::cBinop_AZkv24Pv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7MYmK8yV, HV_BINOP_MULTIPLY, 1, m, &cBinop_7MYmK8yV_sendMessage);
}

void Heavy_nts_vocoder::cBinop_7MYmK8yV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_lKt9yHxn_sendMessage);
}

void Heavy_nts_vocoder::cCast_3mZ3fl4D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mDw0wg55, 0, m, &cVar_mDw0wg55_sendMessage);
}

void Heavy_nts_vocoder::cBinop_eLySb88h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_71zJ133Y_sendMessage);
}

void Heavy_nts_vocoder::cBinop_71zJ133Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nQECQHie, 5, m);
}

void Heavy_nts_vocoder::cBinop_lKt9yHxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nQECQHie, 4, m);
}

void Heavy_nts_vocoder::cBinop_iwZLsRgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mwdv6efh, HV_BINOP_MULTIPLY, 0, m, &cBinop_Mwdv6efh_sendMessage);
}

void Heavy_nts_vocoder::cBinop_6XNRT10s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ugPk176l, HV_BINOP_ADD, 1, m, &cBinop_ugPk176l_sendMessage);
}

void Heavy_nts_vocoder::cBinop_JUv3mGH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_eLySb88h_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ugPk176l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mwdv6efh, HV_BINOP_MULTIPLY, 1, m, &cBinop_Mwdv6efh_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Mwdv6efh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nQECQHie, 1, m);
}

void Heavy_nts_vocoder::cBinop_YSHX1uln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZgzEDE4D, HV_BINOP_DIVIDE, 1, m, &cBinop_ZgzEDE4D_sendMessage);
}

void Heavy_nts_vocoder::cBinop_dKaaXBIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UaJJ6NQT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ugPk176l, HV_BINOP_ADD, 0, m, &cBinop_ugPk176l_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_iwZLsRgf_sendMessage);
}

void Heavy_nts_vocoder::cMsg_4MxFCvWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_njVaeMwo_sendMessage);
}

void Heavy_nts_vocoder::cSystem_njVaeMwo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yl1Csfrx, HV_BINOP_DIVIDE, 1, m, &cBinop_Yl1Csfrx_sendMessage);
}

void Heavy_nts_vocoder::cVar_anDjKHRe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_xf70sCN1_sendMessage);
}

void Heavy_nts_vocoder::cVar_o3R3vHG6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_cBNW24Ng_sendMessage);
}

void Heavy_nts_vocoder::cUnop_kaqIHMgv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_Iszwlzdf_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Yl1Csfrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nLTY7DvY, HV_BINOP_MULTIPLY, 1, m, &cBinop_nLTY7DvY_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_kaqIHMgv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0wnC7OLY, HV_BINOP_DIVIDE, 0, m, &cBinop_0wnC7OLY_sendMessage);
}

void Heavy_nts_vocoder::cBinop_xf70sCN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yl1Csfrx, HV_BINOP_DIVIDE, 0, m, &cBinop_Yl1Csfrx_sendMessage);
}

void Heavy_nts_vocoder::cBinop_0wnC7OLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_RHow6KpI_sendMessage);
}

void Heavy_nts_vocoder::cBinop_KtUz3gQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_FI9mRYTH_sendMessage);
}

void Heavy_nts_vocoder::cBinop_FI9mRYTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_bduQKPvS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HFHlhrIK, HV_BINOP_MULTIPLY, 0, m, &cBinop_HFHlhrIK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nLTY7DvY, HV_BINOP_MULTIPLY, 0, m, &cBinop_nLTY7DvY_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Iszwlzdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HFHlhrIK, HV_BINOP_MULTIPLY, 1, m, &cBinop_HFHlhrIK_sendMessage);
}

void Heavy_nts_vocoder::cBinop_HFHlhrIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uZf4XMZ1_sendMessage);
}

void Heavy_nts_vocoder::cCast_hbFBNT7n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_anDjKHRe, 0, m, &cVar_anDjKHRe_sendMessage);
}

void Heavy_nts_vocoder::cBinop_o1cBWFdR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bP3O5EEi_sendMessage);
}

void Heavy_nts_vocoder::cBinop_bP3O5EEi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_DOm7q3Md, 5, m);
}

void Heavy_nts_vocoder::cBinop_uZf4XMZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_DOm7q3Md, 4, m);
}

void Heavy_nts_vocoder::cBinop_qVUlbwcg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l15DnFwc, HV_BINOP_MULTIPLY, 0, m, &cBinop_l15DnFwc_sendMessage);
}

void Heavy_nts_vocoder::cBinop_nLTY7DvY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hu5gwuVX, HV_BINOP_ADD, 1, m, &cBinop_Hu5gwuVX_sendMessage);
}

void Heavy_nts_vocoder::cBinop_bduQKPvS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_o1cBWFdR_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Hu5gwuVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l15DnFwc, HV_BINOP_MULTIPLY, 1, m, &cBinop_l15DnFwc_sendMessage);
}

void Heavy_nts_vocoder::cBinop_l15DnFwc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_DOm7q3Md, 1, m);
}

void Heavy_nts_vocoder::cBinop_cBNW24Ng_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0wnC7OLY, HV_BINOP_DIVIDE, 1, m, &cBinop_0wnC7OLY_sendMessage);
}

void Heavy_nts_vocoder::cBinop_RHow6KpI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_KtUz3gQW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hu5gwuVX, HV_BINOP_ADD, 0, m, &cBinop_Hu5gwuVX_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_qVUlbwcg_sendMessage);
}

void Heavy_nts_vocoder::cMsg_RFqvjib8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_w80A4eWX_sendMessage);
}

void Heavy_nts_vocoder::cSystem_w80A4eWX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U8HsPYc5, HV_BINOP_DIVIDE, 1, m, &cBinop_U8HsPYc5_sendMessage);
}

void Heavy_nts_vocoder::cVar_88TEvAfv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_wac2HJQH_sendMessage);
}

void Heavy_nts_vocoder::cVar_fwaLcR1G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_sakW7Rjk_sendMessage);
}

void Heavy_nts_vocoder::cUnop_YU6h3joC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_rFG9v0UE_sendMessage);
}

void Heavy_nts_vocoder::cBinop_U8HsPYc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Abe2TXQW, HV_BINOP_MULTIPLY, 1, m, &cBinop_Abe2TXQW_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_YU6h3joC_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gT1KMmuT, HV_BINOP_DIVIDE, 0, m, &cBinop_gT1KMmuT_sendMessage);
}

void Heavy_nts_vocoder::cBinop_wac2HJQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U8HsPYc5, HV_BINOP_DIVIDE, 0, m, &cBinop_U8HsPYc5_sendMessage);
}

void Heavy_nts_vocoder::cBinop_gT1KMmuT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_HBPPvrVE_sendMessage);
}

void Heavy_nts_vocoder::cBinop_avgzTn2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_dBO3uwc9_sendMessage);
}

void Heavy_nts_vocoder::cBinop_dBO3uwc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_uwqhFs7I_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EbTSdyGY, HV_BINOP_MULTIPLY, 0, m, &cBinop_EbTSdyGY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Abe2TXQW, HV_BINOP_MULTIPLY, 0, m, &cBinop_Abe2TXQW_sendMessage);
}

void Heavy_nts_vocoder::cBinop_rFG9v0UE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EbTSdyGY, HV_BINOP_MULTIPLY, 1, m, &cBinop_EbTSdyGY_sendMessage);
}

void Heavy_nts_vocoder::cBinop_EbTSdyGY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BUA03LiQ_sendMessage);
}

void Heavy_nts_vocoder::cCast_MUpjMWQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_88TEvAfv, 0, m, &cVar_88TEvAfv_sendMessage);
}

void Heavy_nts_vocoder::cBinop_MS5mt71n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_o5Qw6WnP_sendMessage);
}

void Heavy_nts_vocoder::cBinop_o5Qw6WnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_7WTnJaDX, 5, m);
}

void Heavy_nts_vocoder::cBinop_BUA03LiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_7WTnJaDX, 4, m);
}

void Heavy_nts_vocoder::cBinop_mpN68ZcJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IRnDPpMa, HV_BINOP_MULTIPLY, 0, m, &cBinop_IRnDPpMa_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Abe2TXQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MlphFeJd, HV_BINOP_ADD, 1, m, &cBinop_MlphFeJd_sendMessage);
}

void Heavy_nts_vocoder::cBinop_uwqhFs7I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_MS5mt71n_sendMessage);
}

void Heavy_nts_vocoder::cBinop_MlphFeJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IRnDPpMa, HV_BINOP_MULTIPLY, 1, m, &cBinop_IRnDPpMa_sendMessage);
}

void Heavy_nts_vocoder::cBinop_IRnDPpMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_7WTnJaDX, 1, m);
}

void Heavy_nts_vocoder::cBinop_sakW7Rjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gT1KMmuT, HV_BINOP_DIVIDE, 1, m, &cBinop_gT1KMmuT_sendMessage);
}

void Heavy_nts_vocoder::cBinop_HBPPvrVE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_avgzTn2Q_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MlphFeJd, HV_BINOP_ADD, 0, m, &cBinop_MlphFeJd_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_mpN68ZcJ_sendMessage);
}

void Heavy_nts_vocoder::cMsg_Xv9BmJPj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HJnn1lDx_sendMessage);
}

void Heavy_nts_vocoder::cSystem_HJnn1lDx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_db4aeu7i, HV_BINOP_DIVIDE, 1, m, &cBinop_db4aeu7i_sendMessage);
}

void Heavy_nts_vocoder::cVar_TwTXGK9n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_EkmbSS4c_sendMessage);
}

void Heavy_nts_vocoder::cVar_IjaqvDfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_kZKdpXNM_sendMessage);
}

void Heavy_nts_vocoder::cUnop_kRkhTRdH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_yrvzYenz_sendMessage);
}

void Heavy_nts_vocoder::cBinop_db4aeu7i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DjxAN0X1, HV_BINOP_MULTIPLY, 1, m, &cBinop_DjxAN0X1_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_kRkhTRdH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7bLkxqrL, HV_BINOP_DIVIDE, 0, m, &cBinop_7bLkxqrL_sendMessage);
}

void Heavy_nts_vocoder::cBinop_EkmbSS4c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_db4aeu7i, HV_BINOP_DIVIDE, 0, m, &cBinop_db4aeu7i_sendMessage);
}

void Heavy_nts_vocoder::cBinop_7bLkxqrL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_rglTgaeX_sendMessage);
}

void Heavy_nts_vocoder::cBinop_dAzdn9VT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_wa9i3rwl_sendMessage);
}

void Heavy_nts_vocoder::cBinop_wa9i3rwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_ajlTdnZG_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5UM4Mbt6, HV_BINOP_MULTIPLY, 0, m, &cBinop_5UM4Mbt6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DjxAN0X1, HV_BINOP_MULTIPLY, 0, m, &cBinop_DjxAN0X1_sendMessage);
}

void Heavy_nts_vocoder::cBinop_yrvzYenz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5UM4Mbt6, HV_BINOP_MULTIPLY, 1, m, &cBinop_5UM4Mbt6_sendMessage);
}

void Heavy_nts_vocoder::cBinop_5UM4Mbt6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VxCyMygR_sendMessage);
}

void Heavy_nts_vocoder::cCast_81g2ueWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TwTXGK9n, 0, m, &cVar_TwTXGK9n_sendMessage);
}

void Heavy_nts_vocoder::cBinop_qDlWkYfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_rrZDptIV_sendMessage);
}

void Heavy_nts_vocoder::cBinop_rrZDptIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_cbCs9w56, 5, m);
}

void Heavy_nts_vocoder::cBinop_VxCyMygR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_cbCs9w56, 4, m);
}

void Heavy_nts_vocoder::cBinop_jxXHEPMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BzF1nXAz, HV_BINOP_MULTIPLY, 0, m, &cBinop_BzF1nXAz_sendMessage);
}

void Heavy_nts_vocoder::cBinop_DjxAN0X1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_updNAD7S, HV_BINOP_ADD, 1, m, &cBinop_updNAD7S_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ajlTdnZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qDlWkYfS_sendMessage);
}

void Heavy_nts_vocoder::cBinop_updNAD7S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BzF1nXAz, HV_BINOP_MULTIPLY, 1, m, &cBinop_BzF1nXAz_sendMessage);
}

void Heavy_nts_vocoder::cBinop_BzF1nXAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_cbCs9w56, 1, m);
}

void Heavy_nts_vocoder::cBinop_kZKdpXNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7bLkxqrL, HV_BINOP_DIVIDE, 1, m, &cBinop_7bLkxqrL_sendMessage);
}

void Heavy_nts_vocoder::cBinop_rglTgaeX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dAzdn9VT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_updNAD7S, HV_BINOP_ADD, 0, m, &cBinop_updNAD7S_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_jxXHEPMx_sendMessage);
}

void Heavy_nts_vocoder::cMsg_Ewp5S2LP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tafXhk3H_sendMessage);
}

void Heavy_nts_vocoder::cSystem_tafXhk3H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4QnRzVIq, HV_BINOP_DIVIDE, 1, m, &cBinop_4QnRzVIq_sendMessage);
}

void Heavy_nts_vocoder::cVar_CrURPHej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_GS428Z7H_sendMessage);
}

void Heavy_nts_vocoder::cVar_RRmE9Xkp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_X5hSYupI_sendMessage);
}

void Heavy_nts_vocoder::cUnop_7Q2TtWEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ZEx4jCve_sendMessage);
}

void Heavy_nts_vocoder::cBinop_4QnRzVIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gt31lx5c, HV_BINOP_MULTIPLY, 1, m, &cBinop_Gt31lx5c_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_7Q2TtWEY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_43Mla2hA, HV_BINOP_DIVIDE, 0, m, &cBinop_43Mla2hA_sendMessage);
}

void Heavy_nts_vocoder::cBinop_GS428Z7H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4QnRzVIq, HV_BINOP_DIVIDE, 0, m, &cBinop_4QnRzVIq_sendMessage);
}

void Heavy_nts_vocoder::cBinop_43Mla2hA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_chfOAXO3_sendMessage);
}

void Heavy_nts_vocoder::cBinop_VEdyMiwq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_VEdzG4GB_sendMessage);
}

void Heavy_nts_vocoder::cBinop_VEdzG4GB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_1GJcThhY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3VIPDl2s, HV_BINOP_MULTIPLY, 0, m, &cBinop_3VIPDl2s_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gt31lx5c, HV_BINOP_MULTIPLY, 0, m, &cBinop_Gt31lx5c_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ZEx4jCve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3VIPDl2s, HV_BINOP_MULTIPLY, 1, m, &cBinop_3VIPDl2s_sendMessage);
}

void Heavy_nts_vocoder::cBinop_3VIPDl2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_M7jgABiq_sendMessage);
}

void Heavy_nts_vocoder::cCast_tu2W4o7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CrURPHej, 0, m, &cVar_CrURPHej_sendMessage);
}

void Heavy_nts_vocoder::cBinop_PoFUVYPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_hGmdIcHz_sendMessage);
}

void Heavy_nts_vocoder::cBinop_hGmdIcHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_j6VhDOaT, 5, m);
}

void Heavy_nts_vocoder::cBinop_M7jgABiq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_j6VhDOaT, 4, m);
}

void Heavy_nts_vocoder::cBinop_OrjXFaXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GBmVXmzL, HV_BINOP_MULTIPLY, 0, m, &cBinop_GBmVXmzL_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Gt31lx5c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_422pdeA5, HV_BINOP_ADD, 1, m, &cBinop_422pdeA5_sendMessage);
}

void Heavy_nts_vocoder::cBinop_1GJcThhY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_PoFUVYPd_sendMessage);
}

void Heavy_nts_vocoder::cBinop_422pdeA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GBmVXmzL, HV_BINOP_MULTIPLY, 1, m, &cBinop_GBmVXmzL_sendMessage);
}

void Heavy_nts_vocoder::cBinop_GBmVXmzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_j6VhDOaT, 1, m);
}

void Heavy_nts_vocoder::cBinop_X5hSYupI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_43Mla2hA, HV_BINOP_DIVIDE, 1, m, &cBinop_43Mla2hA_sendMessage);
}

void Heavy_nts_vocoder::cBinop_chfOAXO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VEdyMiwq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_422pdeA5, HV_BINOP_ADD, 0, m, &cBinop_422pdeA5_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_OrjXFaXg_sendMessage);
}

void Heavy_nts_vocoder::cMsg_2xiYdmv2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7BkZelCP_sendMessage);
}

void Heavy_nts_vocoder::cSystem_7BkZelCP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pNB8QkpX, HV_BINOP_DIVIDE, 1, m, &cBinop_pNB8QkpX_sendMessage);
}

void Heavy_nts_vocoder::cVar_HXsREdRg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_dB9lslpk_sendMessage);
}

void Heavy_nts_vocoder::cVar_X3Xnh4EK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_xkoRv20l_sendMessage);
}

void Heavy_nts_vocoder::cUnop_czF8ko1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_xBBUH9B8_sendMessage);
}

void Heavy_nts_vocoder::cBinop_pNB8QkpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MDf78fgy, HV_BINOP_MULTIPLY, 1, m, &cBinop_MDf78fgy_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_czF8ko1I_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EwGfa4vy, HV_BINOP_DIVIDE, 0, m, &cBinop_EwGfa4vy_sendMessage);
}

void Heavy_nts_vocoder::cBinop_dB9lslpk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pNB8QkpX, HV_BINOP_DIVIDE, 0, m, &cBinop_pNB8QkpX_sendMessage);
}

void Heavy_nts_vocoder::cBinop_EwGfa4vy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_9wh9Srqm_sendMessage);
}

void Heavy_nts_vocoder::cBinop_vSdzngIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_KBsYZarn_sendMessage);
}

void Heavy_nts_vocoder::cBinop_KBsYZarn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_LGC5F6Ta_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_z8cJtzkH, HV_BINOP_MULTIPLY, 0, m, &cBinop_z8cJtzkH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MDf78fgy, HV_BINOP_MULTIPLY, 0, m, &cBinop_MDf78fgy_sendMessage);
}

void Heavy_nts_vocoder::cBinop_xBBUH9B8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z8cJtzkH, HV_BINOP_MULTIPLY, 1, m, &cBinop_z8cJtzkH_sendMessage);
}

void Heavy_nts_vocoder::cBinop_z8cJtzkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_x4eN4ioF_sendMessage);
}

void Heavy_nts_vocoder::cCast_jkwrwORu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HXsREdRg, 0, m, &cVar_HXsREdRg_sendMessage);
}

void Heavy_nts_vocoder::cBinop_9Vt75UQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SWF3IuOi_sendMessage);
}

void Heavy_nts_vocoder::cBinop_SWF3IuOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_9fmjbm79, 5, m);
}

void Heavy_nts_vocoder::cBinop_x4eN4ioF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_9fmjbm79, 4, m);
}

void Heavy_nts_vocoder::cBinop_BRWxY68u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vGe0U5ju, HV_BINOP_MULTIPLY, 0, m, &cBinop_vGe0U5ju_sendMessage);
}

void Heavy_nts_vocoder::cBinop_MDf78fgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p5nIJEUD, HV_BINOP_ADD, 1, m, &cBinop_p5nIJEUD_sendMessage);
}

void Heavy_nts_vocoder::cBinop_LGC5F6Ta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9Vt75UQq_sendMessage);
}

void Heavy_nts_vocoder::cBinop_p5nIJEUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vGe0U5ju, HV_BINOP_MULTIPLY, 1, m, &cBinop_vGe0U5ju_sendMessage);
}

void Heavy_nts_vocoder::cBinop_vGe0U5ju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_9fmjbm79, 1, m);
}

void Heavy_nts_vocoder::cBinop_xkoRv20l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EwGfa4vy, HV_BINOP_DIVIDE, 1, m, &cBinop_EwGfa4vy_sendMessage);
}

void Heavy_nts_vocoder::cBinop_9wh9Srqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vSdzngIV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_p5nIJEUD, HV_BINOP_ADD, 0, m, &cBinop_p5nIJEUD_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_BRWxY68u_sendMessage);
}

void Heavy_nts_vocoder::cMsg_DFo4FK4P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BorYeV4u_sendMessage);
}

void Heavy_nts_vocoder::cSystem_BorYeV4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4xcuEToW, HV_BINOP_DIVIDE, 1, m, &cBinop_4xcuEToW_sendMessage);
}

void Heavy_nts_vocoder::cVar_OKGNGmpr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_ja5FEbIg_sendMessage);
}

void Heavy_nts_vocoder::cVar_ac1LgYUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_JWCC9gwH_sendMessage);
}

void Heavy_nts_vocoder::cUnop_GRjMq4Uu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_cptDNLdE_sendMessage);
}

void Heavy_nts_vocoder::cBinop_4xcuEToW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9DFJcpm5, HV_BINOP_MULTIPLY, 1, m, &cBinop_9DFJcpm5_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_GRjMq4Uu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_10cAXJHl, HV_BINOP_DIVIDE, 0, m, &cBinop_10cAXJHl_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ja5FEbIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4xcuEToW, HV_BINOP_DIVIDE, 0, m, &cBinop_4xcuEToW_sendMessage);
}

void Heavy_nts_vocoder::cBinop_10cAXJHl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_7MaEBg5u_sendMessage);
}

void Heavy_nts_vocoder::cBinop_YNppOs3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_MJj1o5gX_sendMessage);
}

void Heavy_nts_vocoder::cBinop_MJj1o5gX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_MOFyQGPw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rRDIagEy, HV_BINOP_MULTIPLY, 0, m, &cBinop_rRDIagEy_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9DFJcpm5, HV_BINOP_MULTIPLY, 0, m, &cBinop_9DFJcpm5_sendMessage);
}

void Heavy_nts_vocoder::cBinop_cptDNLdE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rRDIagEy, HV_BINOP_MULTIPLY, 1, m, &cBinop_rRDIagEy_sendMessage);
}

void Heavy_nts_vocoder::cBinop_rRDIagEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VO3gbSB5_sendMessage);
}

void Heavy_nts_vocoder::cCast_2j0iP7v6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OKGNGmpr, 0, m, &cVar_OKGNGmpr_sendMessage);
}

void Heavy_nts_vocoder::cBinop_9KxfGgME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_gsdC68te_sendMessage);
}

void Heavy_nts_vocoder::cBinop_gsdC68te_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_DPmibssi, 5, m);
}

void Heavy_nts_vocoder::cBinop_VO3gbSB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_DPmibssi, 4, m);
}

void Heavy_nts_vocoder::cBinop_zHTHParE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qvKd5C5r, HV_BINOP_MULTIPLY, 0, m, &cBinop_qvKd5C5r_sendMessage);
}

void Heavy_nts_vocoder::cBinop_9DFJcpm5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mEwWWuy4, HV_BINOP_ADD, 1, m, &cBinop_mEwWWuy4_sendMessage);
}

void Heavy_nts_vocoder::cBinop_MOFyQGPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9KxfGgME_sendMessage);
}

void Heavy_nts_vocoder::cBinop_mEwWWuy4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qvKd5C5r, HV_BINOP_MULTIPLY, 1, m, &cBinop_qvKd5C5r_sendMessage);
}

void Heavy_nts_vocoder::cBinop_qvKd5C5r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_DPmibssi, 1, m);
}

void Heavy_nts_vocoder::cBinop_JWCC9gwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_10cAXJHl, HV_BINOP_DIVIDE, 1, m, &cBinop_10cAXJHl_sendMessage);
}

void Heavy_nts_vocoder::cBinop_7MaEBg5u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_YNppOs3V_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mEwWWuy4, HV_BINOP_ADD, 0, m, &cBinop_mEwWWuy4_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_zHTHParE_sendMessage);
}

void Heavy_nts_vocoder::cMsg_eTY8izfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xcqFAzAT_sendMessage);
}

void Heavy_nts_vocoder::cSystem_xcqFAzAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aWziDoKS, HV_BINOP_DIVIDE, 1, m, &cBinop_aWziDoKS_sendMessage);
}

void Heavy_nts_vocoder::cVar_x0n69pAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_dIdE4OXF_sendMessage);
}

void Heavy_nts_vocoder::cVar_cfIPneq7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_hL89vDZF_sendMessage);
}

void Heavy_nts_vocoder::cUnop_mGLtS3Dj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ZQZlBLDZ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_aWziDoKS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8xczqoXn, HV_BINOP_MULTIPLY, 1, m, &cBinop_8xczqoXn_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_mGLtS3Dj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5rkh0X2U, HV_BINOP_DIVIDE, 0, m, &cBinop_5rkh0X2U_sendMessage);
}

void Heavy_nts_vocoder::cBinop_dIdE4OXF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aWziDoKS, HV_BINOP_DIVIDE, 0, m, &cBinop_aWziDoKS_sendMessage);
}

void Heavy_nts_vocoder::cBinop_5rkh0X2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zBAxeAhB_sendMessage);
}

void Heavy_nts_vocoder::cBinop_pxsESoX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_oHUr0iZB_sendMessage);
}

void Heavy_nts_vocoder::cBinop_oHUr0iZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_SKmw7eeM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fZdQdvtT, HV_BINOP_MULTIPLY, 0, m, &cBinop_fZdQdvtT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8xczqoXn, HV_BINOP_MULTIPLY, 0, m, &cBinop_8xczqoXn_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ZQZlBLDZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fZdQdvtT, HV_BINOP_MULTIPLY, 1, m, &cBinop_fZdQdvtT_sendMessage);
}

void Heavy_nts_vocoder::cBinop_fZdQdvtT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Y0Q2yz0g_sendMessage);
}

void Heavy_nts_vocoder::cCast_CkiYgGi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_x0n69pAZ, 0, m, &cVar_x0n69pAZ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_HbotbAly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_PAm2fo2r_sendMessage);
}

void Heavy_nts_vocoder::cBinop_PAm2fo2r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_gtW1cbay, 5, m);
}

void Heavy_nts_vocoder::cBinop_Y0Q2yz0g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_gtW1cbay, 4, m);
}

void Heavy_nts_vocoder::cBinop_vCeBDWIo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hIt1T54X, HV_BINOP_MULTIPLY, 0, m, &cBinop_hIt1T54X_sendMessage);
}

void Heavy_nts_vocoder::cBinop_8xczqoXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AMDjZ5Y5, HV_BINOP_ADD, 1, m, &cBinop_AMDjZ5Y5_sendMessage);
}

void Heavy_nts_vocoder::cBinop_SKmw7eeM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HbotbAly_sendMessage);
}

void Heavy_nts_vocoder::cBinop_AMDjZ5Y5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hIt1T54X, HV_BINOP_MULTIPLY, 1, m, &cBinop_hIt1T54X_sendMessage);
}

void Heavy_nts_vocoder::cBinop_hIt1T54X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_gtW1cbay, 1, m);
}

void Heavy_nts_vocoder::cBinop_hL89vDZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5rkh0X2U, HV_BINOP_DIVIDE, 1, m, &cBinop_5rkh0X2U_sendMessage);
}

void Heavy_nts_vocoder::cBinop_zBAxeAhB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pxsESoX0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AMDjZ5Y5, HV_BINOP_ADD, 0, m, &cBinop_AMDjZ5Y5_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_vCeBDWIo_sendMessage);
}

void Heavy_nts_vocoder::cBinop_WE8b7PHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_6iw1wmET, 0, m);
}

void Heavy_nts_vocoder::cBinop_9IyYPtMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_abbepkcz_sendMessage);
}

void Heavy_nts_vocoder::cBinop_abbepkcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KVsD6jfI, HV_BINOP_POW, 1, m, &cBinop_KVsD6jfI_sendMessage);
  cMsg_JhTrFGL8_sendMessage(_c, 0, m);
}

void Heavy_nts_vocoder::cBinop_KVsD6jfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_WE8b7PHN_sendMessage);
}

void Heavy_nts_vocoder::cMsg_JhTrFGL8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KVsD6jfI, HV_BINOP_POW, 0, m, &cBinop_KVsD6jfI_sendMessage);
}

void Heavy_nts_vocoder::cBinop_U1yuK351_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_hmsttqVV, 0, m);
}

void Heavy_nts_vocoder::cBinop_HftoWihF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_GS0Vaylq_sendMessage);
}

void Heavy_nts_vocoder::cBinop_GS0Vaylq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iSRQnJpq, HV_BINOP_POW, 1, m, &cBinop_iSRQnJpq_sendMessage);
  cMsg_NY92vpDv_sendMessage(_c, 0, m);
}

void Heavy_nts_vocoder::cBinop_iSRQnJpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_U1yuK351_sendMessage);
}

void Heavy_nts_vocoder::cMsg_NY92vpDv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_iSRQnJpq, HV_BINOP_POW, 0, m, &cBinop_iSRQnJpq_sendMessage);
}

void Heavy_nts_vocoder::cBinop_FAXqb1DL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_CqkdowBO, 0, m);
}

void Heavy_nts_vocoder::cBinop_mQqdETII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_8ebNbBIE_sendMessage);
}

void Heavy_nts_vocoder::cBinop_8ebNbBIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g02IfEOR, HV_BINOP_POW, 1, m, &cBinop_g02IfEOR_sendMessage);
  cMsg_tMDT0qFQ_sendMessage(_c, 0, m);
}

void Heavy_nts_vocoder::cBinop_g02IfEOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_FAXqb1DL_sendMessage);
}

void Heavy_nts_vocoder::cMsg_tMDT0qFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_g02IfEOR, HV_BINOP_POW, 0, m, &cBinop_g02IfEOR_sendMessage);
}

void Heavy_nts_vocoder::cBinop_aieaoY14_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VJ6OfJV7_sendMessage);
}

void Heavy_nts_vocoder::cBinop_VJ6OfJV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_7Jk2WpSh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_c2ODjM0P_sendMessage);
}

void Heavy_nts_vocoder::cVar_7pk3Cj4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_L2vTVdub_sendMessage);
}

void Heavy_nts_vocoder::cMsg_rAPB2u5S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Wig2kdVl_sendMessage);
}

void Heavy_nts_vocoder::cSystem_Wig2kdVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j4gFQY9b, HV_BINOP_DIVIDE, 1, m, &cBinop_j4gFQY9b_sendMessage);
}

void Heavy_nts_vocoder::cBinop_7Jk2WpSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_usDweLKg_sendMessage);
}

void Heavy_nts_vocoder::cBinop_usDweLKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qTzgevzt, m);
}

void Heavy_nts_vocoder::cMsg_9UE8arVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_C964WAWz_sendMessage);
}

void Heavy_nts_vocoder::cBinop_C964WAWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_aieaoY14_sendMessage);
}

void Heavy_nts_vocoder::cBinop_c2ODjM0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rY7VxsJI, m);
}

void Heavy_nts_vocoder::cBinop_L2vTVdub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_9BHJdhgr_sendMessage);
}

void Heavy_nts_vocoder::cBinop_9BHJdhgr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j4gFQY9b, HV_BINOP_DIVIDE, 0, m, &cBinop_j4gFQY9b_sendMessage);
}

void Heavy_nts_vocoder::cBinop_j4gFQY9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9UE8arVD_sendMessage(_c, 0, m);
}

void Heavy_nts_vocoder::cBinop_9XBB2mc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MUW9YJpa_sendMessage);
}

void Heavy_nts_vocoder::cBinop_MUW9YJpa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_VVJU4RBE_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_6sMm71f7_sendMessage);
}

void Heavy_nts_vocoder::cVar_NbJvFOX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_4Nb1Xh8y_sendMessage);
}

void Heavy_nts_vocoder::cMsg_hQIBxuJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_W7RzkIYJ_sendMessage);
}

void Heavy_nts_vocoder::cSystem_W7RzkIYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A0sC3zC1, HV_BINOP_DIVIDE, 1, m, &cBinop_A0sC3zC1_sendMessage);
}

void Heavy_nts_vocoder::cBinop_VVJU4RBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_Ywisl0tM_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Ywisl0tM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_adhKK5Qv, m);
}

void Heavy_nts_vocoder::cMsg_3W1CX1GT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_P8eZPv1s_sendMessage);
}

void Heavy_nts_vocoder::cBinop_P8eZPv1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_9XBB2mc1_sendMessage);
}

void Heavy_nts_vocoder::cBinop_6sMm71f7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RwWuedIc, m);
}

void Heavy_nts_vocoder::cBinop_4Nb1Xh8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_VI9cl2Hh_sendMessage);
}

void Heavy_nts_vocoder::cBinop_VI9cl2Hh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A0sC3zC1, HV_BINOP_DIVIDE, 0, m, &cBinop_A0sC3zC1_sendMessage);
}

void Heavy_nts_vocoder::cBinop_A0sC3zC1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3W1CX1GT_sendMessage(_c, 0, m);
}

void Heavy_nts_vocoder::cBinop_zN7Hi0OE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_HftoWihF_sendMessage);
}

void Heavy_nts_vocoder::cBinop_CJ0Wn9yw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_mQqdETII_sendMessage);
}

void Heavy_nts_vocoder::cReceive_TVKmZdSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OiSbRadd, m);
}

void Heavy_nts_vocoder::cReceive_FHIm9JMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RM5FdSBs, 0, m, &cVar_RM5FdSBs_sendMessage);
  cMsg_AsMzVna6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YixK1Rmt, 0, m, &cVar_YixK1Rmt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FdBs7ebD, 0, m, &cVar_FdBs7ebD_sendMessage);
  cMsg_IC9Aut0e_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_p9tHzTMv, 0, m, &cVar_p9tHzTMv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mHNi7AqA, 0, m, &cVar_mHNi7AqA_sendMessage);
  cMsg_8gmUS9DS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_T2Tj8CSr, 0, m, &cVar_T2Tj8CSr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JtEKoDhX, 0, m, &cVar_JtEKoDhX_sendMessage);
  cMsg_NDBAivB6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_esXdxme8, 0, m, &cVar_esXdxme8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_tg69EZ3u, 0, m, &cVar_tg69EZ3u_sendMessage);
  cMsg_U7nQc2Dd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HVKlP3ru, 0, m, &cVar_HVKlP3ru_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fiNgKfSB, 0, m, &cVar_fiNgKfSB_sendMessage);
  cMsg_tMbUIG3m_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gM8ejy9j, 0, m, &cVar_gM8ejy9j_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jHDIMGW8, 0, m, &cVar_jHDIMGW8_sendMessage);
  cMsg_3zVwYrnY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mDw0wg55, 0, m, &cVar_mDw0wg55_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_o3R3vHG6, 0, m, &cVar_o3R3vHG6_sendMessage);
  cMsg_4MxFCvWY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_anDjKHRe, 0, m, &cVar_anDjKHRe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fwaLcR1G, 0, m, &cVar_fwaLcR1G_sendMessage);
  cMsg_RFqvjib8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_88TEvAfv, 0, m, &cVar_88TEvAfv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IjaqvDfo, 0, m, &cVar_IjaqvDfo_sendMessage);
  cMsg_Xv9BmJPj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TwTXGK9n, 0, m, &cVar_TwTXGK9n_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RRmE9Xkp, 0, m, &cVar_RRmE9Xkp_sendMessage);
  cMsg_Ewp5S2LP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CrURPHej, 0, m, &cVar_CrURPHej_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_X3Xnh4EK, 0, m, &cVar_X3Xnh4EK_sendMessage);
  cMsg_2xiYdmv2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HXsREdRg, 0, m, &cVar_HXsREdRg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ac1LgYUJ, 0, m, &cVar_ac1LgYUJ_sendMessage);
  cMsg_DFo4FK4P_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OKGNGmpr, 0, m, &cVar_OKGNGmpr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cfIPneq7, 0, m, &cVar_cfIPneq7_sendMessage);
  cMsg_eTY8izfM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_x0n69pAZ, 0, m, &cVar_x0n69pAZ_sendMessage);
  cMsg_rAPB2u5S_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7pk3Cj4v, 0, m, &cVar_7pk3Cj4v_sendMessage);
  cMsg_hQIBxuJ6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NbJvFOX3, 0, m, &cVar_NbJvFOX3_sendMessage);
}

void Heavy_nts_vocoder::cReceive_ROPElXc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_9IyYPtMA_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zN7Hi0OE, HV_BINOP_ADD, 0, m, &cBinop_zN7Hi0OE_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CJ0Wn9yw, HV_BINOP_ADD, 0, m, &cBinop_CJ0Wn9yw_sendMessage);
}

void Heavy_nts_vocoder::cReceive_HB72VhcS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_d4VwX28y, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OEtjjU3V, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_w2nXvRR9, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cLtMPWBx, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8snY8SG1, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kKUWflUm, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_etyI9IeY, m);
}

void Heavy_nts_vocoder::cReceive_QhGyeGqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CJ0Wn9yw, HV_BINOP_ADD, 1, m, &cBinop_CJ0Wn9yw_sendMessage);
}

void Heavy_nts_vocoder::cReceive_T9pyh69s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zN7Hi0OE, HV_BINOP_ADD, 1, m, &cBinop_zN7Hi0OE_sendMessage);
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

int Heavy_nts_vocoder::process(float **inputBuffers, float **outputBuffers, int n) {
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
    __hv_varread_f(&sVarf_OiSbRadd, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_6iw1wmET, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_CqkdowBO, VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_hmsttqVV, VOf(Bf0));
    __hv_add_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_SQnToxe0, VIf(Bf2), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_EDia1r6g, VIf(Bf1), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_Oz4n1uVG, VOf(Bf4));
    __hv_varread_f(&sVarf_d4VwX28y, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_max_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_Oz4n1uVG, VIf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_3yJJV2h6, VIf(Bf2), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_5KrHzr2j, VIf(Bf1), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_OGxuROUM, VOf(Bf4));
    __hv_varread_f(&sVarf_OEtjjU3V, VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_max_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_f(&sVarf_OGxuROUM, VIf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_biquad_k_f(&sBiquad_k_I9mcd1SN, VIf(Bf2), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_o2tTVK5r, VIf(Bf1), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_4MQe9Q9c, VOf(Bf3));
    __hv_varread_f(&sVarf_w2nXvRR9, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_max_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_4MQe9Q9c, VIf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_DOm7q3Md, VIf(Bf2), VOf(Bf6));
    __hv_biquad_k_f(&sBiquad_k_nQECQHie, VIf(Bf1), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_j0HFUdtC, VOf(Bf0));
    __hv_varread_f(&sVarf_cLtMPWBx, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_max_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_j0HFUdtC, VIf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_biquad_k_f(&sBiquad_k_cbCs9w56, VIf(Bf2), VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_7WTnJaDX, VIf(Bf1), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_i7C78kGP, VOf(Bf5));
    __hv_varread_f(&sVarf_8snY8SG1, VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_max_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_i7C78kGP, VIf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_9fmjbm79, VIf(Bf2), VOf(Bf3));
    __hv_biquad_k_f(&sBiquad_k_j6VhDOaT, VIf(Bf1), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_letvboYU, VOf(Bf6));
    __hv_varread_f(&sVarf_kKUWflUm, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_max_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_letvboYU, VIf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_gtW1cbay, VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_DPmibssi, VIf(Bf1), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_p6BhtjAB, VOf(Bf3));
    __hv_varread_f(&sVarf_etyI9IeY, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_max_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_p6BhtjAB, VIf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f);
    __hv_varread_f(&sVarf_rY7VxsJI, VOf(Bf2));
    __hv_rpole_f(&sRPole_obZtO8sy, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_YTjCulcc, VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_qTzgevzt, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_RwWuedIc, VOf(Bf1));
    __hv_rpole_f(&sRPole_Cm8bi1Ee, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_2d9EB9b0, VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_adhKK5Qv, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_nts_vocoder::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_nts_vocoder::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
