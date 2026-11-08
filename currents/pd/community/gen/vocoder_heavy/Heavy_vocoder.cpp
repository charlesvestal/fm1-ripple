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
  numBytes += sPhasor_k_init(&sPhasor_Pik4EYvA, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_9jLy5LEK, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_FAK7fF7I, 0.0f, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_Ri3CEGBS, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_Guj4khII, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_SqzpNSsp, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_lvXEF4zP, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_3m5lKHSu, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_uN1yFMaP, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_g5f9n8qL, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_5h29RA2w, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_BwJkrTr3, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_meSDiDM7, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_GSPs6uoj, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_T6DXBkUY, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_nyhM3Adw, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_yBclURri, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sRPole_init(&sRPole_KRl2pFdV);
  numBytes += sDel1_init(&sDel1_2T777gCu);
  numBytes += sRPole_init(&sRPole_cHnC3ky1);
  numBytes += sDel1_init(&sDel1_VVSrgcFR);
  numBytes += sVarf_init(&sVarf_VQiOBwCe, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jTwdN0Th, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_lA28VsQI, 267.0f);
  numBytes += cVar_init_f(&cVar_s5gRa4Ip, 15.0f);
  numBytes += cBinop_init(&cBinop_s5unQgcl, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_22B6gIkY, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_OR4OZYzw, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_vM1TUj53, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_iarYfFxj, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Enkq2aBF, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_M8IOB6BN, 267.0f);
  numBytes += cVar_init_f(&cVar_8YYq4EtF, 15.0f);
  numBytes += cBinop_init(&cBinop_DrK1YMVq, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_8jwKmgfk, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_HMHnkrgK, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_i25luzQZ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Y5uFbeUF, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_MEvrIlzj, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_WCdOfrUs, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uNXn0XIi, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ZcXZKOvy, 444.0f);
  numBytes += cVar_init_f(&cVar_bbdN3enh, 15.0f);
  numBytes += cBinop_init(&cBinop_h6AvssXC, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_VEMVVmLq, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_XoS0NXDn, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_V6uUoSWh, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_h2B1IteD, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_bppTWQ5J, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Tnxd1qCQ, 444.0f);
  numBytes += cVar_init_f(&cVar_JVBOIf9o, 15.0f);
  numBytes += cBinop_init(&cBinop_gN1MMOJP, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_xthI2VBW, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ZC7vAufq, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_fUjRUHO8, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_DZ1HVBVd, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_UIRrjApH, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_kuqWm33Q, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BOVAhMSK, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_wFLAdfy5, 741.0f);
  numBytes += cVar_init_f(&cVar_LbvvYVC1, 15.0f);
  numBytes += cBinop_init(&cBinop_5XenkRBo, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_nrVe6NkB, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_h7SAq4DG, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_vN4wR52o, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_56neLnu1, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_wWdLflT5, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ZgdH9lEf, 741.0f);
  numBytes += cVar_init_f(&cVar_EesOoulh, 15.0f);
  numBytes += cBinop_init(&cBinop_oHIucR1S, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_mSUldcFU, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_k1e2Gsgc, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_xzgr6Ya7, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_eOtWfvxA, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_E8i5aNzN, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_DJM5VG73, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_e77BfEZG, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_uK4uRXzg, 1235.0f);
  numBytes += cVar_init_f(&cVar_wViiHGG6, 15.0f);
  numBytes += cBinop_init(&cBinop_RLiYEymq, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_DIkpILUU, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_hVzjvmj4, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_HWnFaDN8, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_mpP7dmZk, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Lis3W2hc, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_1Jdpdnw0, 1235.0f);
  numBytes += cVar_init_f(&cVar_gmGx5h67, 15.0f);
  numBytes += cBinop_init(&cBinop_7Ed2d5xJ, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_dG0fqT4k, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_P97a1j4f, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Z8S15zvZ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_UQvl1Pge, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_4qTa8kDR, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_t3KwmEMP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iTva6sn5, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_wdlgAsZl, 2058.0f);
  numBytes += cVar_init_f(&cVar_slPAmLNF, 15.0f);
  numBytes += cBinop_init(&cBinop_Jj6wsdow, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_b0bSNMXz, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_bfNc7i2q, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ONnkaZH3, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Y2RFeefk, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_8hCXHTWd, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_d4sekGOH, 2058.0f);
  numBytes += cVar_init_f(&cVar_Cz5KzcTu, 15.0f);
  numBytes += cBinop_init(&cBinop_7bf0UITk, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_v803sgn0, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_n9bBLFiS, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_SlWScYBJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_To6eHPXa, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_8qDSZdjZ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_8xxjCvlH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_k3epWjI9, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_oITpSCMw, 3429.0f);
  numBytes += cVar_init_f(&cVar_yZMWgIi5, 15.0f);
  numBytes += cBinop_init(&cBinop_39xVrTlr, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_NNWTvQFL, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_JdADtjFf, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_pTmj3znL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_AOPahqLa, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_MGGSEbNH, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_u9WVKyv0, 3429.0f);
  numBytes += cVar_init_f(&cVar_HxCmzX5j, 15.0f);
  numBytes += cBinop_init(&cBinop_8laRO5vO, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_TKaBjsMr, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_gtZwFXlT, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_lIvHqd54, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_1bzXijOu, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_kfYIa8lJ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_DVKKGx96, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uUNkLiIe, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_sf3f8WiK, 5716.0f);
  numBytes += cVar_init_f(&cVar_QbhqHa4z, 15.0f);
  numBytes += cBinop_init(&cBinop_t1rKVYQa, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Hm9dukBb, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_U2i8SJhI, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_3cVB070W, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ljGKlisY, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_zeDkpDSE, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_jqLpUI6S, 5716.0f);
  numBytes += cVar_init_f(&cVar_pbZrGqGp, 15.0f);
  numBytes += cBinop_init(&cBinop_CzhQWXfl, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_40U8VYgi, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_FPkQg5e3, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_bMrGlcUx, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_eVBMUoM5, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_jQIaC5Zf, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_l9lvucR1, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_qyLyhgf6, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_LgrXiRmw, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_gA4311Bp, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_f1QMnor3, 10000.0f);
  numBytes += cBinop_init(&cBinop_7aiD6wPX, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_O8eXPm8R, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_EbM8gqqZ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_kgqmpBxm, 10000.0f);
  numBytes += cBinop_init(&cBinop_EsWMbZSa, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_Ju0XfHcx, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_KEJnOT5K, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_mmRVNnCJ, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_8EiE3ALc, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GIoC5ihk_sendMessage);
      break;
    }
    case 0x6C87328F: { // alt_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eVbROJLM_sendMessage);
      break;
    }
    case 0x3FD8ECD5: { // note1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EuVJkitn_sendMessage);
      break;
    }
    case 0x97165D01: { // note2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LMI6kpyg_sendMessage);
      break;
    }
    case 0xA23B621F: { // pitch_note
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Xslnlzdw_sendMessage);
      break;
    }
    case 0xCE9531B0: { // shape_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NRN0bqor_sendMessage);
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


void Heavy_vocoder::cMsg_Mh9dZ9XE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_U8VsPcmn_sendMessage);
}

void Heavy_vocoder::cSystem_U8VsPcmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s5unQgcl, HV_BINOP_DIVIDE, 1, m, &cBinop_s5unQgcl_sendMessage);
}

void Heavy_vocoder::cVar_lA28VsQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_z4OE7Qih_sendMessage);
}

void Heavy_vocoder::cVar_s5gRa4Ip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_cdmcxYaK_sendMessage);
}

void Heavy_vocoder::cUnop_IEygYx2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_YlNATcgN_sendMessage);
}

void Heavy_vocoder::cBinop_s5unQgcl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vM1TUj53, HV_BINOP_MULTIPLY, 1, m, &cBinop_vM1TUj53_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_IEygYx2M_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_22B6gIkY, HV_BINOP_DIVIDE, 0, m, &cBinop_22B6gIkY_sendMessage);
}

void Heavy_vocoder::cBinop_z4OE7Qih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s5unQgcl, HV_BINOP_DIVIDE, 0, m, &cBinop_s5unQgcl_sendMessage);
}

void Heavy_vocoder::cBinop_22B6gIkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LdNtGZMJ_sendMessage);
}

void Heavy_vocoder::cBinop_1hUYE4vj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_f8n1IdWD_sendMessage);
}

void Heavy_vocoder::cBinop_f8n1IdWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_ruSMbE0f_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OR4OZYzw, HV_BINOP_MULTIPLY, 0, m, &cBinop_OR4OZYzw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vM1TUj53, HV_BINOP_MULTIPLY, 0, m, &cBinop_vM1TUj53_sendMessage);
}

void Heavy_vocoder::cBinop_YlNATcgN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OR4OZYzw, HV_BINOP_MULTIPLY, 1, m, &cBinop_OR4OZYzw_sendMessage);
}

void Heavy_vocoder::cBinop_OR4OZYzw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fJL8Magk_sendMessage);
}

void Heavy_vocoder::cCast_SA6w20rY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lA28VsQI, 0, m, &cVar_lA28VsQI_sendMessage);
}

void Heavy_vocoder::cBinop_oO7yyI80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FFLO5y9j_sendMessage);
}

void Heavy_vocoder::cBinop_FFLO5y9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Guj4khII, 5, m);
}

void Heavy_vocoder::cBinop_fJL8Magk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Guj4khII, 4, m);
}

void Heavy_vocoder::cBinop_0cNGJJYf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Enkq2aBF, HV_BINOP_MULTIPLY, 0, m, &cBinop_Enkq2aBF_sendMessage);
}

void Heavy_vocoder::cBinop_vM1TUj53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iarYfFxj, HV_BINOP_ADD, 1, m, &cBinop_iarYfFxj_sendMessage);
}

void Heavy_vocoder::cBinop_ruSMbE0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_oO7yyI80_sendMessage);
}

void Heavy_vocoder::cBinop_iarYfFxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Enkq2aBF, HV_BINOP_MULTIPLY, 1, m, &cBinop_Enkq2aBF_sendMessage);
}

void Heavy_vocoder::cBinop_Enkq2aBF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Guj4khII, 1, m);
}

void Heavy_vocoder::cBinop_cdmcxYaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_22B6gIkY, HV_BINOP_DIVIDE, 1, m, &cBinop_22B6gIkY_sendMessage);
}

void Heavy_vocoder::cBinop_LdNtGZMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1hUYE4vj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_iarYfFxj, HV_BINOP_ADD, 0, m, &cBinop_iarYfFxj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_0cNGJJYf_sendMessage);
}

void Heavy_vocoder::cMsg_t9APe7x7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PXRRdwtI_sendMessage);
}

void Heavy_vocoder::cSystem_PXRRdwtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DrK1YMVq, HV_BINOP_DIVIDE, 1, m, &cBinop_DrK1YMVq_sendMessage);
}

void Heavy_vocoder::cVar_M8IOB6BN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_8yOEjLAa_sendMessage);
}

void Heavy_vocoder::cVar_8YYq4EtF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_yMpN86y2_sendMessage);
}

void Heavy_vocoder::cUnop_8eirNf52_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_rIU7yb7d_sendMessage);
}

void Heavy_vocoder::cBinop_DrK1YMVq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i25luzQZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_i25luzQZ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_8eirNf52_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8jwKmgfk, HV_BINOP_DIVIDE, 0, m, &cBinop_8jwKmgfk_sendMessage);
}

void Heavy_vocoder::cBinop_8yOEjLAa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DrK1YMVq, HV_BINOP_DIVIDE, 0, m, &cBinop_DrK1YMVq_sendMessage);
}

void Heavy_vocoder::cBinop_8jwKmgfk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_AoxrptRn_sendMessage);
}

void Heavy_vocoder::cBinop_Xa6ecugw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Bh8VWa9T_sendMessage);
}

void Heavy_vocoder::cBinop_Bh8VWa9T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_erj7FLEn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HMHnkrgK, HV_BINOP_MULTIPLY, 0, m, &cBinop_HMHnkrgK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_i25luzQZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_i25luzQZ_sendMessage);
}

void Heavy_vocoder::cBinop_rIU7yb7d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HMHnkrgK, HV_BINOP_MULTIPLY, 1, m, &cBinop_HMHnkrgK_sendMessage);
}

void Heavy_vocoder::cBinop_HMHnkrgK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_C2sIwYaE_sendMessage);
}

void Heavy_vocoder::cCast_V2KtwCpg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_M8IOB6BN, 0, m, &cVar_M8IOB6BN_sendMessage);
}

void Heavy_vocoder::cBinop_hey2NZ3b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1eXyewom_sendMessage);
}

void Heavy_vocoder::cBinop_1eXyewom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Ri3CEGBS, 5, m);
}

void Heavy_vocoder::cBinop_C2sIwYaE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Ri3CEGBS, 4, m);
}

void Heavy_vocoder::cBinop_7qvuAuIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MEvrIlzj, HV_BINOP_MULTIPLY, 0, m, &cBinop_MEvrIlzj_sendMessage);
}

void Heavy_vocoder::cBinop_i25luzQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y5uFbeUF, HV_BINOP_ADD, 1, m, &cBinop_Y5uFbeUF_sendMessage);
}

void Heavy_vocoder::cBinop_erj7FLEn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_hey2NZ3b_sendMessage);
}

void Heavy_vocoder::cBinop_Y5uFbeUF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MEvrIlzj, HV_BINOP_MULTIPLY, 1, m, &cBinop_MEvrIlzj_sendMessage);
}

void Heavy_vocoder::cBinop_MEvrIlzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Ri3CEGBS, 1, m);
}

void Heavy_vocoder::cBinop_yMpN86y2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8jwKmgfk, HV_BINOP_DIVIDE, 1, m, &cBinop_8jwKmgfk_sendMessage);
}

void Heavy_vocoder::cBinop_AoxrptRn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Xa6ecugw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y5uFbeUF, HV_BINOP_ADD, 0, m, &cBinop_Y5uFbeUF_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_7qvuAuIj_sendMessage);
}

void Heavy_vocoder::cMsg_XKTIep80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rwnk3fbf_sendMessage);
}

void Heavy_vocoder::cSystem_rwnk3fbf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h6AvssXC, HV_BINOP_DIVIDE, 1, m, &cBinop_h6AvssXC_sendMessage);
}

void Heavy_vocoder::cVar_ZcXZKOvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_JC9NvJjK_sendMessage);
}

void Heavy_vocoder::cVar_bbdN3enh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_YBwN3xd9_sendMessage);
}

void Heavy_vocoder::cUnop_uhPkSUxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_fXrz8Gf8_sendMessage);
}

void Heavy_vocoder::cBinop_h6AvssXC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V6uUoSWh, HV_BINOP_MULTIPLY, 1, m, &cBinop_V6uUoSWh_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_uhPkSUxE_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VEMVVmLq, HV_BINOP_DIVIDE, 0, m, &cBinop_VEMVVmLq_sendMessage);
}

void Heavy_vocoder::cBinop_JC9NvJjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h6AvssXC, HV_BINOP_DIVIDE, 0, m, &cBinop_h6AvssXC_sendMessage);
}

void Heavy_vocoder::cBinop_VEMVVmLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_fgBJgzhl_sendMessage);
}

void Heavy_vocoder::cBinop_ZE7mQR3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_aZjSDU5g_sendMessage);
}

void Heavy_vocoder::cBinop_aZjSDU5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_2Ch5CaxP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XoS0NXDn, HV_BINOP_MULTIPLY, 0, m, &cBinop_XoS0NXDn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_V6uUoSWh, HV_BINOP_MULTIPLY, 0, m, &cBinop_V6uUoSWh_sendMessage);
}

void Heavy_vocoder::cBinop_fXrz8Gf8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XoS0NXDn, HV_BINOP_MULTIPLY, 1, m, &cBinop_XoS0NXDn_sendMessage);
}

void Heavy_vocoder::cBinop_XoS0NXDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fQU8oJI6_sendMessage);
}

void Heavy_vocoder::cCast_7sLKxz0q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZcXZKOvy, 0, m, &cVar_ZcXZKOvy_sendMessage);
}

void Heavy_vocoder::cBinop_Fs8c1xe9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5h1HzsbE_sendMessage);
}

void Heavy_vocoder::cBinop_5h1HzsbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_lvXEF4zP, 5, m);
}

void Heavy_vocoder::cBinop_fQU8oJI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_lvXEF4zP, 4, m);
}

void Heavy_vocoder::cBinop_U9DRRqn5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bppTWQ5J, HV_BINOP_MULTIPLY, 0, m, &cBinop_bppTWQ5J_sendMessage);
}

void Heavy_vocoder::cBinop_V6uUoSWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h2B1IteD, HV_BINOP_ADD, 1, m, &cBinop_h2B1IteD_sendMessage);
}

void Heavy_vocoder::cBinop_2Ch5CaxP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Fs8c1xe9_sendMessage);
}

void Heavy_vocoder::cBinop_h2B1IteD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bppTWQ5J, HV_BINOP_MULTIPLY, 1, m, &cBinop_bppTWQ5J_sendMessage);
}

void Heavy_vocoder::cBinop_bppTWQ5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_lvXEF4zP, 1, m);
}

void Heavy_vocoder::cBinop_YBwN3xd9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VEMVVmLq, HV_BINOP_DIVIDE, 1, m, &cBinop_VEMVVmLq_sendMessage);
}

void Heavy_vocoder::cBinop_fgBJgzhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZE7mQR3E_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_h2B1IteD, HV_BINOP_ADD, 0, m, &cBinop_h2B1IteD_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_U9DRRqn5_sendMessage);
}

void Heavy_vocoder::cMsg_aijI00Wg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LHh2BBaB_sendMessage);
}

void Heavy_vocoder::cSystem_LHh2BBaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gN1MMOJP, HV_BINOP_DIVIDE, 1, m, &cBinop_gN1MMOJP_sendMessage);
}

void Heavy_vocoder::cVar_Tnxd1qCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_FkSKwl7I_sendMessage);
}

void Heavy_vocoder::cVar_JVBOIf9o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_Q4LhGhhG_sendMessage);
}

void Heavy_vocoder::cUnop_sD69Z56P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_NJBVSbmm_sendMessage);
}

void Heavy_vocoder::cBinop_gN1MMOJP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fUjRUHO8, HV_BINOP_MULTIPLY, 1, m, &cBinop_fUjRUHO8_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_sD69Z56P_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xthI2VBW, HV_BINOP_DIVIDE, 0, m, &cBinop_xthI2VBW_sendMessage);
}

void Heavy_vocoder::cBinop_FkSKwl7I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gN1MMOJP, HV_BINOP_DIVIDE, 0, m, &cBinop_gN1MMOJP_sendMessage);
}

void Heavy_vocoder::cBinop_xthI2VBW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_QYINFyv3_sendMessage);
}

void Heavy_vocoder::cBinop_ss31wsEq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_iQYwGR1Y_sendMessage);
}

void Heavy_vocoder::cBinop_iQYwGR1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_mFO4nmKd_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZC7vAufq, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZC7vAufq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fUjRUHO8, HV_BINOP_MULTIPLY, 0, m, &cBinop_fUjRUHO8_sendMessage);
}

void Heavy_vocoder::cBinop_NJBVSbmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZC7vAufq, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZC7vAufq_sendMessage);
}

void Heavy_vocoder::cBinop_ZC7vAufq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_aKnR3lxb_sendMessage);
}

void Heavy_vocoder::cCast_Ymnw7WUB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Tnxd1qCQ, 0, m, &cVar_Tnxd1qCQ_sendMessage);
}

void Heavy_vocoder::cBinop_0juSgDh3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_H8aQpDey_sendMessage);
}

void Heavy_vocoder::cBinop_H8aQpDey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_SqzpNSsp, 5, m);
}

void Heavy_vocoder::cBinop_aKnR3lxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_SqzpNSsp, 4, m);
}

void Heavy_vocoder::cBinop_ktSCwJlq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UIRrjApH, HV_BINOP_MULTIPLY, 0, m, &cBinop_UIRrjApH_sendMessage);
}

void Heavy_vocoder::cBinop_fUjRUHO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DZ1HVBVd, HV_BINOP_ADD, 1, m, &cBinop_DZ1HVBVd_sendMessage);
}

void Heavy_vocoder::cBinop_mFO4nmKd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0juSgDh3_sendMessage);
}

void Heavy_vocoder::cBinop_DZ1HVBVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UIRrjApH, HV_BINOP_MULTIPLY, 1, m, &cBinop_UIRrjApH_sendMessage);
}

void Heavy_vocoder::cBinop_UIRrjApH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_SqzpNSsp, 1, m);
}

void Heavy_vocoder::cBinop_Q4LhGhhG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xthI2VBW, HV_BINOP_DIVIDE, 1, m, &cBinop_xthI2VBW_sendMessage);
}

void Heavy_vocoder::cBinop_QYINFyv3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ss31wsEq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DZ1HVBVd, HV_BINOP_ADD, 0, m, &cBinop_DZ1HVBVd_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ktSCwJlq_sendMessage);
}

void Heavy_vocoder::cMsg_GgdVuRCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4lM7T5tj_sendMessage);
}

void Heavy_vocoder::cSystem_4lM7T5tj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5XenkRBo, HV_BINOP_DIVIDE, 1, m, &cBinop_5XenkRBo_sendMessage);
}

void Heavy_vocoder::cVar_wFLAdfy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_7OXgqBgu_sendMessage);
}

void Heavy_vocoder::cVar_LbvvYVC1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_bsjKSYNW_sendMessage);
}

void Heavy_vocoder::cUnop_FryjW1sS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_sbomIqDH_sendMessage);
}

void Heavy_vocoder::cBinop_5XenkRBo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vN4wR52o, HV_BINOP_MULTIPLY, 1, m, &cBinop_vN4wR52o_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_FryjW1sS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nrVe6NkB, HV_BINOP_DIVIDE, 0, m, &cBinop_nrVe6NkB_sendMessage);
}

void Heavy_vocoder::cBinop_7OXgqBgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5XenkRBo, HV_BINOP_DIVIDE, 0, m, &cBinop_5XenkRBo_sendMessage);
}

void Heavy_vocoder::cBinop_nrVe6NkB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_wQNotNtY_sendMessage);
}

void Heavy_vocoder::cBinop_P713vpKf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_LUqk6Do8_sendMessage);
}

void Heavy_vocoder::cBinop_LUqk6Do8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_ZaFV5AVM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_h7SAq4DG, HV_BINOP_MULTIPLY, 0, m, &cBinop_h7SAq4DG_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vN4wR52o, HV_BINOP_MULTIPLY, 0, m, &cBinop_vN4wR52o_sendMessage);
}

void Heavy_vocoder::cBinop_sbomIqDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h7SAq4DG, HV_BINOP_MULTIPLY, 1, m, &cBinop_h7SAq4DG_sendMessage);
}

void Heavy_vocoder::cBinop_h7SAq4DG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Ua2E3irU_sendMessage);
}

void Heavy_vocoder::cCast_CvwOmbA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wFLAdfy5, 0, m, &cVar_wFLAdfy5_sendMessage);
}

void Heavy_vocoder::cBinop_8Vpok2is_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_oC3O9fm4_sendMessage);
}

void Heavy_vocoder::cBinop_oC3O9fm4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uN1yFMaP, 5, m);
}

void Heavy_vocoder::cBinop_Ua2E3irU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uN1yFMaP, 4, m);
}

void Heavy_vocoder::cBinop_aU6TPd25_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wWdLflT5, HV_BINOP_MULTIPLY, 0, m, &cBinop_wWdLflT5_sendMessage);
}

void Heavy_vocoder::cBinop_vN4wR52o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_56neLnu1, HV_BINOP_ADD, 1, m, &cBinop_56neLnu1_sendMessage);
}

void Heavy_vocoder::cBinop_ZaFV5AVM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8Vpok2is_sendMessage);
}

void Heavy_vocoder::cBinop_56neLnu1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wWdLflT5, HV_BINOP_MULTIPLY, 1, m, &cBinop_wWdLflT5_sendMessage);
}

void Heavy_vocoder::cBinop_wWdLflT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uN1yFMaP, 1, m);
}

void Heavy_vocoder::cBinop_bsjKSYNW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nrVe6NkB, HV_BINOP_DIVIDE, 1, m, &cBinop_nrVe6NkB_sendMessage);
}

void Heavy_vocoder::cBinop_wQNotNtY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_P713vpKf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_56neLnu1, HV_BINOP_ADD, 0, m, &cBinop_56neLnu1_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_aU6TPd25_sendMessage);
}

void Heavy_vocoder::cMsg_kYnvLf51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_M9eafPPM_sendMessage);
}

void Heavy_vocoder::cSystem_M9eafPPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oHIucR1S, HV_BINOP_DIVIDE, 1, m, &cBinop_oHIucR1S_sendMessage);
}

void Heavy_vocoder::cVar_ZgdH9lEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_MpEW5OWn_sendMessage);
}

void Heavy_vocoder::cVar_EesOoulh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_JqXbmceJ_sendMessage);
}

void Heavy_vocoder::cUnop_2rZ2xZHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ewggDozf_sendMessage);
}

void Heavy_vocoder::cBinop_oHIucR1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xzgr6Ya7, HV_BINOP_MULTIPLY, 1, m, &cBinop_xzgr6Ya7_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_2rZ2xZHM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mSUldcFU, HV_BINOP_DIVIDE, 0, m, &cBinop_mSUldcFU_sendMessage);
}

void Heavy_vocoder::cBinop_MpEW5OWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oHIucR1S, HV_BINOP_DIVIDE, 0, m, &cBinop_oHIucR1S_sendMessage);
}

void Heavy_vocoder::cBinop_mSUldcFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LUyBG4xp_sendMessage);
}

void Heavy_vocoder::cBinop_PhZZCJiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_VNuLS3ir_sendMessage);
}

void Heavy_vocoder::cBinop_VNuLS3ir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_M6RRTawr_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_k1e2Gsgc, HV_BINOP_MULTIPLY, 0, m, &cBinop_k1e2Gsgc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xzgr6Ya7, HV_BINOP_MULTIPLY, 0, m, &cBinop_xzgr6Ya7_sendMessage);
}

void Heavy_vocoder::cBinop_ewggDozf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k1e2Gsgc, HV_BINOP_MULTIPLY, 1, m, &cBinop_k1e2Gsgc_sendMessage);
}

void Heavy_vocoder::cBinop_k1e2Gsgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_lVYiBE5R_sendMessage);
}

void Heavy_vocoder::cCast_k6NjaJPf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZgdH9lEf, 0, m, &cVar_ZgdH9lEf_sendMessage);
}

void Heavy_vocoder::cBinop_vIKLnKKD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_zM575OSk_sendMessage);
}

void Heavy_vocoder::cBinop_zM575OSk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3m5lKHSu, 5, m);
}

void Heavy_vocoder::cBinop_lVYiBE5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3m5lKHSu, 4, m);
}

void Heavy_vocoder::cBinop_5bO0O2R4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E8i5aNzN, HV_BINOP_MULTIPLY, 0, m, &cBinop_E8i5aNzN_sendMessage);
}

void Heavy_vocoder::cBinop_xzgr6Ya7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eOtWfvxA, HV_BINOP_ADD, 1, m, &cBinop_eOtWfvxA_sendMessage);
}

void Heavy_vocoder::cBinop_M6RRTawr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vIKLnKKD_sendMessage);
}

void Heavy_vocoder::cBinop_eOtWfvxA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E8i5aNzN, HV_BINOP_MULTIPLY, 1, m, &cBinop_E8i5aNzN_sendMessage);
}

void Heavy_vocoder::cBinop_E8i5aNzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3m5lKHSu, 1, m);
}

void Heavy_vocoder::cBinop_JqXbmceJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mSUldcFU, HV_BINOP_DIVIDE, 1, m, &cBinop_mSUldcFU_sendMessage);
}

void Heavy_vocoder::cBinop_LUyBG4xp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_PhZZCJiT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_eOtWfvxA, HV_BINOP_ADD, 0, m, &cBinop_eOtWfvxA_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_5bO0O2R4_sendMessage);
}

void Heavy_vocoder::cMsg_l3wUIgQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XqyFobFB_sendMessage);
}

void Heavy_vocoder::cSystem_XqyFobFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RLiYEymq, HV_BINOP_DIVIDE, 1, m, &cBinop_RLiYEymq_sendMessage);
}

void Heavy_vocoder::cVar_uK4uRXzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_IDeg7FNe_sendMessage);
}

void Heavy_vocoder::cVar_wViiHGG6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_Sj9lswID_sendMessage);
}

void Heavy_vocoder::cUnop_b5JDSmwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_imgfoGip_sendMessage);
}

void Heavy_vocoder::cBinop_RLiYEymq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HWnFaDN8, HV_BINOP_MULTIPLY, 1, m, &cBinop_HWnFaDN8_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_b5JDSmwe_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DIkpILUU, HV_BINOP_DIVIDE, 0, m, &cBinop_DIkpILUU_sendMessage);
}

void Heavy_vocoder::cBinop_IDeg7FNe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RLiYEymq, HV_BINOP_DIVIDE, 0, m, &cBinop_RLiYEymq_sendMessage);
}

void Heavy_vocoder::cBinop_DIkpILUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_GkyhZ5kl_sendMessage);
}

void Heavy_vocoder::cBinop_GhWELZuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_sRXWPzfz_sendMessage);
}

void Heavy_vocoder::cBinop_sRXWPzfz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_ox3bTZVh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hVzjvmj4, HV_BINOP_MULTIPLY, 0, m, &cBinop_hVzjvmj4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HWnFaDN8, HV_BINOP_MULTIPLY, 0, m, &cBinop_HWnFaDN8_sendMessage);
}

void Heavy_vocoder::cBinop_imgfoGip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hVzjvmj4, HV_BINOP_MULTIPLY, 1, m, &cBinop_hVzjvmj4_sendMessage);
}

void Heavy_vocoder::cBinop_hVzjvmj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_PKLNcMjI_sendMessage);
}

void Heavy_vocoder::cCast_CQIBj4lX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uK4uRXzg, 0, m, &cVar_uK4uRXzg_sendMessage);
}

void Heavy_vocoder::cBinop_rAbSjn4j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_G1b5nHZs_sendMessage);
}

void Heavy_vocoder::cBinop_G1b5nHZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_5h29RA2w, 5, m);
}

void Heavy_vocoder::cBinop_PKLNcMjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_5h29RA2w, 4, m);
}

void Heavy_vocoder::cBinop_dgticfdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lis3W2hc, HV_BINOP_MULTIPLY, 0, m, &cBinop_Lis3W2hc_sendMessage);
}

void Heavy_vocoder::cBinop_HWnFaDN8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mpP7dmZk, HV_BINOP_ADD, 1, m, &cBinop_mpP7dmZk_sendMessage);
}

void Heavy_vocoder::cBinop_ox3bTZVh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_rAbSjn4j_sendMessage);
}

void Heavy_vocoder::cBinop_mpP7dmZk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lis3W2hc, HV_BINOP_MULTIPLY, 1, m, &cBinop_Lis3W2hc_sendMessage);
}

void Heavy_vocoder::cBinop_Lis3W2hc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_5h29RA2w, 1, m);
}

void Heavy_vocoder::cBinop_Sj9lswID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DIkpILUU, HV_BINOP_DIVIDE, 1, m, &cBinop_DIkpILUU_sendMessage);
}

void Heavy_vocoder::cBinop_GkyhZ5kl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GhWELZuI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mpP7dmZk, HV_BINOP_ADD, 0, m, &cBinop_mpP7dmZk_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_dgticfdy_sendMessage);
}

void Heavy_vocoder::cMsg_1a6bCQpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sLCoKrzO_sendMessage);
}

void Heavy_vocoder::cSystem_sLCoKrzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Ed2d5xJ, HV_BINOP_DIVIDE, 1, m, &cBinop_7Ed2d5xJ_sendMessage);
}

void Heavy_vocoder::cVar_1Jdpdnw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_QVrhthxX_sendMessage);
}

void Heavy_vocoder::cVar_gmGx5h67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_5ajIaQaW_sendMessage);
}

void Heavy_vocoder::cUnop_YmO7BtU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_RKyfGTYY_sendMessage);
}

void Heavy_vocoder::cBinop_7Ed2d5xJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z8S15zvZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_Z8S15zvZ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_YmO7BtU6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dG0fqT4k, HV_BINOP_DIVIDE, 0, m, &cBinop_dG0fqT4k_sendMessage);
}

void Heavy_vocoder::cBinop_QVrhthxX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7Ed2d5xJ, HV_BINOP_DIVIDE, 0, m, &cBinop_7Ed2d5xJ_sendMessage);
}

void Heavy_vocoder::cBinop_dG0fqT4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_QSF1CB2u_sendMessage);
}

void Heavy_vocoder::cBinop_s6dYtRYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_YkIL6JTX_sendMessage);
}

void Heavy_vocoder::cBinop_YkIL6JTX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_jFtoPoY7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_P97a1j4f, HV_BINOP_MULTIPLY, 0, m, &cBinop_P97a1j4f_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z8S15zvZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Z8S15zvZ_sendMessage);
}

void Heavy_vocoder::cBinop_RKyfGTYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P97a1j4f, HV_BINOP_MULTIPLY, 1, m, &cBinop_P97a1j4f_sendMessage);
}

void Heavy_vocoder::cBinop_P97a1j4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_teJLDiCS_sendMessage);
}

void Heavy_vocoder::cCast_q9StouZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1Jdpdnw0, 0, m, &cVar_1Jdpdnw0_sendMessage);
}

void Heavy_vocoder::cBinop_0EtJietU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1JsZn6HG_sendMessage);
}

void Heavy_vocoder::cBinop_1JsZn6HG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_g5f9n8qL, 5, m);
}

void Heavy_vocoder::cBinop_teJLDiCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_g5f9n8qL, 4, m);
}

void Heavy_vocoder::cBinop_GsfgI5R5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4qTa8kDR, HV_BINOP_MULTIPLY, 0, m, &cBinop_4qTa8kDR_sendMessage);
}

void Heavy_vocoder::cBinop_Z8S15zvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UQvl1Pge, HV_BINOP_ADD, 1, m, &cBinop_UQvl1Pge_sendMessage);
}

void Heavy_vocoder::cBinop_jFtoPoY7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0EtJietU_sendMessage);
}

void Heavy_vocoder::cBinop_UQvl1Pge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4qTa8kDR, HV_BINOP_MULTIPLY, 1, m, &cBinop_4qTa8kDR_sendMessage);
}

void Heavy_vocoder::cBinop_4qTa8kDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_g5f9n8qL, 1, m);
}

void Heavy_vocoder::cBinop_5ajIaQaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dG0fqT4k, HV_BINOP_DIVIDE, 1, m, &cBinop_dG0fqT4k_sendMessage);
}

void Heavy_vocoder::cBinop_QSF1CB2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_s6dYtRYL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UQvl1Pge, HV_BINOP_ADD, 0, m, &cBinop_UQvl1Pge_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_GsfgI5R5_sendMessage);
}

void Heavy_vocoder::cMsg_lOi2VmXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Cbk8CRyB_sendMessage);
}

void Heavy_vocoder::cSystem_Cbk8CRyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jj6wsdow, HV_BINOP_DIVIDE, 1, m, &cBinop_Jj6wsdow_sendMessage);
}

void Heavy_vocoder::cVar_wdlgAsZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_kkNNqqNX_sendMessage);
}

void Heavy_vocoder::cVar_slPAmLNF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_xJ8l5BEe_sendMessage);
}

void Heavy_vocoder::cUnop_zF6Ie43a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_DmJ8NC79_sendMessage);
}

void Heavy_vocoder::cBinop_Jj6wsdow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ONnkaZH3, HV_BINOP_MULTIPLY, 1, m, &cBinop_ONnkaZH3_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_zF6Ie43a_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_b0bSNMXz, HV_BINOP_DIVIDE, 0, m, &cBinop_b0bSNMXz_sendMessage);
}

void Heavy_vocoder::cBinop_kkNNqqNX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jj6wsdow, HV_BINOP_DIVIDE, 0, m, &cBinop_Jj6wsdow_sendMessage);
}

void Heavy_vocoder::cBinop_b0bSNMXz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LTOPJrHG_sendMessage);
}

void Heavy_vocoder::cBinop_LqVp66RQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_HyqNwxww_sendMessage);
}

void Heavy_vocoder::cBinop_HyqNwxww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_mmw90AUD_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bfNc7i2q, HV_BINOP_MULTIPLY, 0, m, &cBinop_bfNc7i2q_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ONnkaZH3, HV_BINOP_MULTIPLY, 0, m, &cBinop_ONnkaZH3_sendMessage);
}

void Heavy_vocoder::cBinop_DmJ8NC79_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bfNc7i2q, HV_BINOP_MULTIPLY, 1, m, &cBinop_bfNc7i2q_sendMessage);
}

void Heavy_vocoder::cBinop_bfNc7i2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5dE1zO9d_sendMessage);
}

void Heavy_vocoder::cCast_c51suoAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wdlgAsZl, 0, m, &cVar_wdlgAsZl_sendMessage);
}

void Heavy_vocoder::cBinop_xdVMYarX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dVPrsFyv_sendMessage);
}

void Heavy_vocoder::cBinop_dVPrsFyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_meSDiDM7, 5, m);
}

void Heavy_vocoder::cBinop_5dE1zO9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_meSDiDM7, 4, m);
}

void Heavy_vocoder::cBinop_YHQzzhUe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8hCXHTWd, HV_BINOP_MULTIPLY, 0, m, &cBinop_8hCXHTWd_sendMessage);
}

void Heavy_vocoder::cBinop_ONnkaZH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y2RFeefk, HV_BINOP_ADD, 1, m, &cBinop_Y2RFeefk_sendMessage);
}

void Heavy_vocoder::cBinop_mmw90AUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xdVMYarX_sendMessage);
}

void Heavy_vocoder::cBinop_Y2RFeefk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8hCXHTWd, HV_BINOP_MULTIPLY, 1, m, &cBinop_8hCXHTWd_sendMessage);
}

void Heavy_vocoder::cBinop_8hCXHTWd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_meSDiDM7, 1, m);
}

void Heavy_vocoder::cBinop_xJ8l5BEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b0bSNMXz, HV_BINOP_DIVIDE, 1, m, &cBinop_b0bSNMXz_sendMessage);
}

void Heavy_vocoder::cBinop_LTOPJrHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_LqVp66RQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y2RFeefk, HV_BINOP_ADD, 0, m, &cBinop_Y2RFeefk_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_YHQzzhUe_sendMessage);
}

void Heavy_vocoder::cMsg_JqqJNTI3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WlRXdYff_sendMessage);
}

void Heavy_vocoder::cSystem_WlRXdYff_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7bf0UITk, HV_BINOP_DIVIDE, 1, m, &cBinop_7bf0UITk_sendMessage);
}

void Heavy_vocoder::cVar_d4sekGOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_yOJSnnJC_sendMessage);
}

void Heavy_vocoder::cVar_Cz5KzcTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_N8SJg7td_sendMessage);
}

void Heavy_vocoder::cUnop_TLL7A9Yi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_DiNfkeYY_sendMessage);
}

void Heavy_vocoder::cBinop_7bf0UITk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SlWScYBJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_SlWScYBJ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_TLL7A9Yi_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_v803sgn0, HV_BINOP_DIVIDE, 0, m, &cBinop_v803sgn0_sendMessage);
}

void Heavy_vocoder::cBinop_yOJSnnJC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7bf0UITk, HV_BINOP_DIVIDE, 0, m, &cBinop_7bf0UITk_sendMessage);
}

void Heavy_vocoder::cBinop_v803sgn0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_D2b1cJ8x_sendMessage);
}

void Heavy_vocoder::cBinop_sA7lUJeg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_D7UXCqJx_sendMessage);
}

void Heavy_vocoder::cBinop_D7UXCqJx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_WTNTt4Tc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_n9bBLFiS, HV_BINOP_MULTIPLY, 0, m, &cBinop_n9bBLFiS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SlWScYBJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_SlWScYBJ_sendMessage);
}

void Heavy_vocoder::cBinop_DiNfkeYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n9bBLFiS, HV_BINOP_MULTIPLY, 1, m, &cBinop_n9bBLFiS_sendMessage);
}

void Heavy_vocoder::cBinop_n9bBLFiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GwXVitVR_sendMessage);
}

void Heavy_vocoder::cCast_tsJSpoGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d4sekGOH, 0, m, &cVar_d4sekGOH_sendMessage);
}

void Heavy_vocoder::cBinop_nvxNA33s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_43jK5Rg9_sendMessage);
}

void Heavy_vocoder::cBinop_43jK5Rg9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_BwJkrTr3, 5, m);
}

void Heavy_vocoder::cBinop_GwXVitVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_BwJkrTr3, 4, m);
}

void Heavy_vocoder::cBinop_kW78A3jV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8qDSZdjZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_8qDSZdjZ_sendMessage);
}

void Heavy_vocoder::cBinop_SlWScYBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_To6eHPXa, HV_BINOP_ADD, 1, m, &cBinop_To6eHPXa_sendMessage);
}

void Heavy_vocoder::cBinop_WTNTt4Tc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nvxNA33s_sendMessage);
}

void Heavy_vocoder::cBinop_To6eHPXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8qDSZdjZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_8qDSZdjZ_sendMessage);
}

void Heavy_vocoder::cBinop_8qDSZdjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_BwJkrTr3, 1, m);
}

void Heavy_vocoder::cBinop_N8SJg7td_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_v803sgn0, HV_BINOP_DIVIDE, 1, m, &cBinop_v803sgn0_sendMessage);
}

void Heavy_vocoder::cBinop_D2b1cJ8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_sA7lUJeg_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_To6eHPXa, HV_BINOP_ADD, 0, m, &cBinop_To6eHPXa_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_kW78A3jV_sendMessage);
}

void Heavy_vocoder::cMsg_k8XntiyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eJea8sbN_sendMessage);
}

void Heavy_vocoder::cSystem_eJea8sbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_39xVrTlr, HV_BINOP_DIVIDE, 1, m, &cBinop_39xVrTlr_sendMessage);
}

void Heavy_vocoder::cVar_oITpSCMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_SDNKCr3J_sendMessage);
}

void Heavy_vocoder::cVar_yZMWgIi5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_K1cID6jr_sendMessage);
}

void Heavy_vocoder::cUnop_XEUM1Ap9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_YpijSVKl_sendMessage);
}

void Heavy_vocoder::cBinop_39xVrTlr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pTmj3znL, HV_BINOP_MULTIPLY, 1, m, &cBinop_pTmj3znL_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_XEUM1Ap9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NNWTvQFL, HV_BINOP_DIVIDE, 0, m, &cBinop_NNWTvQFL_sendMessage);
}

void Heavy_vocoder::cBinop_SDNKCr3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_39xVrTlr, HV_BINOP_DIVIDE, 0, m, &cBinop_39xVrTlr_sendMessage);
}

void Heavy_vocoder::cBinop_NNWTvQFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_UNi2rQge_sendMessage);
}

void Heavy_vocoder::cBinop_p1dsW8Bi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_3MKiD1gN_sendMessage);
}

void Heavy_vocoder::cBinop_3MKiD1gN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_BBpsd47v_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JdADtjFf, HV_BINOP_MULTIPLY, 0, m, &cBinop_JdADtjFf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pTmj3znL, HV_BINOP_MULTIPLY, 0, m, &cBinop_pTmj3znL_sendMessage);
}

void Heavy_vocoder::cBinop_YpijSVKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JdADtjFf, HV_BINOP_MULTIPLY, 1, m, &cBinop_JdADtjFf_sendMessage);
}

void Heavy_vocoder::cBinop_JdADtjFf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4ZmNvLRB_sendMessage);
}

void Heavy_vocoder::cCast_FCn4I6uO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oITpSCMw, 0, m, &cVar_oITpSCMw_sendMessage);
}

void Heavy_vocoder::cBinop_KSgZJ1I1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kViM7nbN_sendMessage);
}

void Heavy_vocoder::cBinop_kViM7nbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_T6DXBkUY, 5, m);
}

void Heavy_vocoder::cBinop_4ZmNvLRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_T6DXBkUY, 4, m);
}

void Heavy_vocoder::cBinop_YNTgodM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MGGSEbNH, HV_BINOP_MULTIPLY, 0, m, &cBinop_MGGSEbNH_sendMessage);
}

void Heavy_vocoder::cBinop_pTmj3znL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AOPahqLa, HV_BINOP_ADD, 1, m, &cBinop_AOPahqLa_sendMessage);
}

void Heavy_vocoder::cBinop_BBpsd47v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_KSgZJ1I1_sendMessage);
}

void Heavy_vocoder::cBinop_AOPahqLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MGGSEbNH, HV_BINOP_MULTIPLY, 1, m, &cBinop_MGGSEbNH_sendMessage);
}

void Heavy_vocoder::cBinop_MGGSEbNH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_T6DXBkUY, 1, m);
}

void Heavy_vocoder::cBinop_K1cID6jr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NNWTvQFL, HV_BINOP_DIVIDE, 1, m, &cBinop_NNWTvQFL_sendMessage);
}

void Heavy_vocoder::cBinop_UNi2rQge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_p1dsW8Bi_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_AOPahqLa, HV_BINOP_ADD, 0, m, &cBinop_AOPahqLa_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_YNTgodM5_sendMessage);
}

void Heavy_vocoder::cMsg_VyQ3xiqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_i0PSKECQ_sendMessage);
}

void Heavy_vocoder::cSystem_i0PSKECQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8laRO5vO, HV_BINOP_DIVIDE, 1, m, &cBinop_8laRO5vO_sendMessage);
}

void Heavy_vocoder::cVar_u9WVKyv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_e901eaVc_sendMessage);
}

void Heavy_vocoder::cVar_HxCmzX5j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_cADHVaZG_sendMessage);
}

void Heavy_vocoder::cUnop_MEonj7cW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_9M3egQId_sendMessage);
}

void Heavy_vocoder::cBinop_8laRO5vO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lIvHqd54, HV_BINOP_MULTIPLY, 1, m, &cBinop_lIvHqd54_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_MEonj7cW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TKaBjsMr, HV_BINOP_DIVIDE, 0, m, &cBinop_TKaBjsMr_sendMessage);
}

void Heavy_vocoder::cBinop_e901eaVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8laRO5vO, HV_BINOP_DIVIDE, 0, m, &cBinop_8laRO5vO_sendMessage);
}

void Heavy_vocoder::cBinop_TKaBjsMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_vWp8fzdG_sendMessage);
}

void Heavy_vocoder::cBinop_iZYb6yUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_NAUPllOQ_sendMessage);
}

void Heavy_vocoder::cBinop_NAUPllOQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_ebh3t0Wa_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gtZwFXlT, HV_BINOP_MULTIPLY, 0, m, &cBinop_gtZwFXlT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lIvHqd54, HV_BINOP_MULTIPLY, 0, m, &cBinop_lIvHqd54_sendMessage);
}

void Heavy_vocoder::cBinop_9M3egQId_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gtZwFXlT, HV_BINOP_MULTIPLY, 1, m, &cBinop_gtZwFXlT_sendMessage);
}

void Heavy_vocoder::cBinop_gtZwFXlT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_LBTdsDiq_sendMessage);
}

void Heavy_vocoder::cCast_5iG1iE8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_u9WVKyv0, 0, m, &cVar_u9WVKyv0_sendMessage);
}

void Heavy_vocoder::cBinop_vB69DA6u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_QARaF7sS_sendMessage);
}

void Heavy_vocoder::cBinop_QARaF7sS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_GSPs6uoj, 5, m);
}

void Heavy_vocoder::cBinop_LBTdsDiq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_GSPs6uoj, 4, m);
}

void Heavy_vocoder::cBinop_7aP42vIM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kfYIa8lJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_kfYIa8lJ_sendMessage);
}

void Heavy_vocoder::cBinop_lIvHqd54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1bzXijOu, HV_BINOP_ADD, 1, m, &cBinop_1bzXijOu_sendMessage);
}

void Heavy_vocoder::cBinop_ebh3t0Wa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vB69DA6u_sendMessage);
}

void Heavy_vocoder::cBinop_1bzXijOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kfYIa8lJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_kfYIa8lJ_sendMessage);
}

void Heavy_vocoder::cBinop_kfYIa8lJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_GSPs6uoj, 1, m);
}

void Heavy_vocoder::cBinop_cADHVaZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TKaBjsMr, HV_BINOP_DIVIDE, 1, m, &cBinop_TKaBjsMr_sendMessage);
}

void Heavy_vocoder::cBinop_vWp8fzdG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_iZYb6yUp_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1bzXijOu, HV_BINOP_ADD, 0, m, &cBinop_1bzXijOu_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_7aP42vIM_sendMessage);
}

void Heavy_vocoder::cMsg_doGYURau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_unx0OmgK_sendMessage);
}

void Heavy_vocoder::cSystem_unx0OmgK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t1rKVYQa, HV_BINOP_DIVIDE, 1, m, &cBinop_t1rKVYQa_sendMessage);
}

void Heavy_vocoder::cVar_sf3f8WiK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_JAbUO3qp_sendMessage);
}

void Heavy_vocoder::cVar_QbhqHa4z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_xDDb44C5_sendMessage);
}

void Heavy_vocoder::cUnop_4MwZQY7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_thGTFyEy_sendMessage);
}

void Heavy_vocoder::cBinop_t1rKVYQa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3cVB070W, HV_BINOP_MULTIPLY, 1, m, &cBinop_3cVB070W_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_4MwZQY7M_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hm9dukBb, HV_BINOP_DIVIDE, 0, m, &cBinop_Hm9dukBb_sendMessage);
}

void Heavy_vocoder::cBinop_JAbUO3qp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t1rKVYQa, HV_BINOP_DIVIDE, 0, m, &cBinop_t1rKVYQa_sendMessage);
}

void Heavy_vocoder::cBinop_Hm9dukBb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_RXtugKeV_sendMessage);
}

void Heavy_vocoder::cBinop_8VZVZyBA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_qSWBSPvT_sendMessage);
}

void Heavy_vocoder::cBinop_qSWBSPvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_CHAXxyYL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_U2i8SJhI, HV_BINOP_MULTIPLY, 0, m, &cBinop_U2i8SJhI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3cVB070W, HV_BINOP_MULTIPLY, 0, m, &cBinop_3cVB070W_sendMessage);
}

void Heavy_vocoder::cBinop_thGTFyEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U2i8SJhI, HV_BINOP_MULTIPLY, 1, m, &cBinop_U2i8SJhI_sendMessage);
}

void Heavy_vocoder::cBinop_U2i8SJhI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_T4LUnpVt_sendMessage);
}

void Heavy_vocoder::cCast_jXE5rV57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sf3f8WiK, 0, m, &cVar_sf3f8WiK_sendMessage);
}

void Heavy_vocoder::cBinop_SPB8MlV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RaJ98ksD_sendMessage);
}

void Heavy_vocoder::cBinop_RaJ98ksD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_yBclURri, 5, m);
}

void Heavy_vocoder::cBinop_T4LUnpVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_yBclURri, 4, m);
}

void Heavy_vocoder::cBinop_DScOdDUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zeDkpDSE, HV_BINOP_MULTIPLY, 0, m, &cBinop_zeDkpDSE_sendMessage);
}

void Heavy_vocoder::cBinop_3cVB070W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ljGKlisY, HV_BINOP_ADD, 1, m, &cBinop_ljGKlisY_sendMessage);
}

void Heavy_vocoder::cBinop_CHAXxyYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SPB8MlV4_sendMessage);
}

void Heavy_vocoder::cBinop_ljGKlisY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zeDkpDSE, HV_BINOP_MULTIPLY, 1, m, &cBinop_zeDkpDSE_sendMessage);
}

void Heavy_vocoder::cBinop_zeDkpDSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_yBclURri, 1, m);
}

void Heavy_vocoder::cBinop_xDDb44C5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hm9dukBb, HV_BINOP_DIVIDE, 1, m, &cBinop_Hm9dukBb_sendMessage);
}

void Heavy_vocoder::cBinop_RXtugKeV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8VZVZyBA_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ljGKlisY, HV_BINOP_ADD, 0, m, &cBinop_ljGKlisY_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_DScOdDUZ_sendMessage);
}

void Heavy_vocoder::cMsg_l5bapfEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uSdtW8cC_sendMessage);
}

void Heavy_vocoder::cSystem_uSdtW8cC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CzhQWXfl, HV_BINOP_DIVIDE, 1, m, &cBinop_CzhQWXfl_sendMessage);
}

void Heavy_vocoder::cVar_jqLpUI6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_E28vdBxE_sendMessage);
}

void Heavy_vocoder::cVar_pbZrGqGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_hVkizBiu_sendMessage);
}

void Heavy_vocoder::cUnop_1ulbFDhp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_Fh4Byksq_sendMessage);
}

void Heavy_vocoder::cBinop_CzhQWXfl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bMrGlcUx, HV_BINOP_MULTIPLY, 1, m, &cBinop_bMrGlcUx_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_1ulbFDhp_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_40U8VYgi, HV_BINOP_DIVIDE, 0, m, &cBinop_40U8VYgi_sendMessage);
}

void Heavy_vocoder::cBinop_E28vdBxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CzhQWXfl, HV_BINOP_DIVIDE, 0, m, &cBinop_CzhQWXfl_sendMessage);
}

void Heavy_vocoder::cBinop_40U8VYgi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_tVkjNu9s_sendMessage);
}

void Heavy_vocoder::cBinop_8ma9yqx8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_6EE04NVM_sendMessage);
}

void Heavy_vocoder::cBinop_6EE04NVM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_vEnkARsJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FPkQg5e3, HV_BINOP_MULTIPLY, 0, m, &cBinop_FPkQg5e3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bMrGlcUx, HV_BINOP_MULTIPLY, 0, m, &cBinop_bMrGlcUx_sendMessage);
}

void Heavy_vocoder::cBinop_Fh4Byksq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FPkQg5e3, HV_BINOP_MULTIPLY, 1, m, &cBinop_FPkQg5e3_sendMessage);
}

void Heavy_vocoder::cBinop_FPkQg5e3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_s1jogWfd_sendMessage);
}

void Heavy_vocoder::cCast_DJoarRx7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jqLpUI6S, 0, m, &cVar_jqLpUI6S_sendMessage);
}

void Heavy_vocoder::cBinop_fIcTXq44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_wEjVVUxk_sendMessage);
}

void Heavy_vocoder::cBinop_wEjVVUxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nyhM3Adw, 5, m);
}

void Heavy_vocoder::cBinop_s1jogWfd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nyhM3Adw, 4, m);
}

void Heavy_vocoder::cBinop_u9g2i7SU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jQIaC5Zf, HV_BINOP_MULTIPLY, 0, m, &cBinop_jQIaC5Zf_sendMessage);
}

void Heavy_vocoder::cBinop_bMrGlcUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eVBMUoM5, HV_BINOP_ADD, 1, m, &cBinop_eVBMUoM5_sendMessage);
}

void Heavy_vocoder::cBinop_vEnkARsJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fIcTXq44_sendMessage);
}

void Heavy_vocoder::cBinop_eVBMUoM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jQIaC5Zf, HV_BINOP_MULTIPLY, 1, m, &cBinop_jQIaC5Zf_sendMessage);
}

void Heavy_vocoder::cBinop_jQIaC5Zf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nyhM3Adw, 1, m);
}

void Heavy_vocoder::cBinop_hVkizBiu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_40U8VYgi, HV_BINOP_DIVIDE, 1, m, &cBinop_40U8VYgi_sendMessage);
}

void Heavy_vocoder::cBinop_tVkjNu9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8ma9yqx8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_eVBMUoM5, HV_BINOP_ADD, 0, m, &cBinop_eVBMUoM5_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_u9g2i7SU_sendMessage);
}

void Heavy_vocoder::cBinop_Ur1cQeGQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Pik4EYvA, 0, m);
}

void Heavy_vocoder::cBinop_27ueuoAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_NMnl8YaV_sendMessage);
}

void Heavy_vocoder::cBinop_NMnl8YaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l9lvucR1, HV_BINOP_POW, 1, m, &cBinop_l9lvucR1_sendMessage);
  cMsg_1a4VrGFu_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_l9lvucR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Ur1cQeGQ_sendMessage);
}

void Heavy_vocoder::cMsg_1a4VrGFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_l9lvucR1, HV_BINOP_POW, 0, m, &cBinop_l9lvucR1_sendMessage);
}

void Heavy_vocoder::cBinop_EhXvhEeC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_FAK7fF7I, 0, m);
}

void Heavy_vocoder::cBinop_x7nlnMZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_LNPIU8Qf_sendMessage);
}

void Heavy_vocoder::cBinop_LNPIU8Qf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qyLyhgf6, HV_BINOP_POW, 1, m, &cBinop_qyLyhgf6_sendMessage);
  cMsg_W3UpPlF8_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_qyLyhgf6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_EhXvhEeC_sendMessage);
}

void Heavy_vocoder::cMsg_W3UpPlF8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qyLyhgf6, HV_BINOP_POW, 0, m, &cBinop_qyLyhgf6_sendMessage);
}

void Heavy_vocoder::cBinop_hxo2DhL8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_9jLy5LEK, 0, m);
}

void Heavy_vocoder::cBinop_Gkv8p8jg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_qbH5fU5N_sendMessage);
}

void Heavy_vocoder::cBinop_qbH5fU5N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LgrXiRmw, HV_BINOP_POW, 1, m, &cBinop_LgrXiRmw_sendMessage);
  cMsg_l5SF8XFh_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_LgrXiRmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_hxo2DhL8_sendMessage);
}

void Heavy_vocoder::cMsg_l5SF8XFh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LgrXiRmw, HV_BINOP_POW, 0, m, &cBinop_LgrXiRmw_sendMessage);
}

void Heavy_vocoder::cBinop_Csphgmcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_n8nEn6hD_sendMessage);
}

void Heavy_vocoder::cBinop_n8nEn6hD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_QrLrTO1I_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xCxc0oaZ_sendMessage);
}

void Heavy_vocoder::cVar_f1QMnor3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_NtcFcnOy_sendMessage);
}

void Heavy_vocoder::cMsg_eLuhGf9T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XAQ0gqfq_sendMessage);
}

void Heavy_vocoder::cSystem_XAQ0gqfq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7aiD6wPX, HV_BINOP_DIVIDE, 1, m, &cBinop_7aiD6wPX_sendMessage);
}

void Heavy_vocoder::cBinop_QrLrTO1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_lc1MpM8U_sendMessage);
}

void Heavy_vocoder::cBinop_lc1MpM8U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_O8eXPm8R, m);
}

void Heavy_vocoder::cMsg_rDVMiKPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_zEEdYpB5_sendMessage);
}

void Heavy_vocoder::cBinop_zEEdYpB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Csphgmcn_sendMessage);
}

void Heavy_vocoder::cBinop_xCxc0oaZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gA4311Bp, m);
}

void Heavy_vocoder::cBinop_NtcFcnOy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_Mx9MzzbZ_sendMessage);
}

void Heavy_vocoder::cBinop_Mx9MzzbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7aiD6wPX, HV_BINOP_DIVIDE, 0, m, &cBinop_7aiD6wPX_sendMessage);
}

void Heavy_vocoder::cBinop_7aiD6wPX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rDVMiKPz_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_lBrG9iek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GRZVcCQp_sendMessage);
}

void Heavy_vocoder::cBinop_GRZVcCQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_pMajIkBp_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pgvw7mr1_sendMessage);
}

void Heavy_vocoder::cVar_kgqmpBxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ab1Lc1UD_sendMessage);
}

void Heavy_vocoder::cMsg_MvN9iTPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WB6yFX1m_sendMessage);
}

void Heavy_vocoder::cSystem_WB6yFX1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EsWMbZSa, HV_BINOP_DIVIDE, 1, m, &cBinop_EsWMbZSa_sendMessage);
}

void Heavy_vocoder::cBinop_pMajIkBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_oN5cJpuL_sendMessage);
}

void Heavy_vocoder::cBinop_oN5cJpuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ju0XfHcx, m);
}

void Heavy_vocoder::cMsg_PKcOsvyz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_TiT7q2NW_sendMessage);
}

void Heavy_vocoder::cBinop_TiT7q2NW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_lBrG9iek_sendMessage);
}

void Heavy_vocoder::cBinop_pgvw7mr1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EbM8gqqZ, m);
}

void Heavy_vocoder::cBinop_ab1Lc1UD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_nU2xADyc_sendMessage);
}

void Heavy_vocoder::cBinop_nU2xADyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EsWMbZSa, HV_BINOP_DIVIDE, 0, m, &cBinop_EsWMbZSa_sendMessage);
}

void Heavy_vocoder::cBinop_EsWMbZSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PKcOsvyz_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_KEJnOT5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_x7nlnMZ6_sendMessage);
}

void Heavy_vocoder::cBinop_mmRVNnCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Gkv8p8jg_sendMessage);
}

void Heavy_vocoder::cReceive_eVbROJLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8EiE3ALc, m);
}

void Heavy_vocoder::cReceive_GIoC5ihk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s5gRa4Ip, 0, m, &cVar_s5gRa4Ip_sendMessage);
  cMsg_Mh9dZ9XE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lA28VsQI, 0, m, &cVar_lA28VsQI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8YYq4EtF, 0, m, &cVar_8YYq4EtF_sendMessage);
  cMsg_t9APe7x7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_M8IOB6BN, 0, m, &cVar_M8IOB6BN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bbdN3enh, 0, m, &cVar_bbdN3enh_sendMessage);
  cMsg_XKTIep80_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZcXZKOvy, 0, m, &cVar_ZcXZKOvy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JVBOIf9o, 0, m, &cVar_JVBOIf9o_sendMessage);
  cMsg_aijI00Wg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Tnxd1qCQ, 0, m, &cVar_Tnxd1qCQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LbvvYVC1, 0, m, &cVar_LbvvYVC1_sendMessage);
  cMsg_GgdVuRCo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wFLAdfy5, 0, m, &cVar_wFLAdfy5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EesOoulh, 0, m, &cVar_EesOoulh_sendMessage);
  cMsg_kYnvLf51_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZgdH9lEf, 0, m, &cVar_ZgdH9lEf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wViiHGG6, 0, m, &cVar_wViiHGG6_sendMessage);
  cMsg_l3wUIgQs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uK4uRXzg, 0, m, &cVar_uK4uRXzg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gmGx5h67, 0, m, &cVar_gmGx5h67_sendMessage);
  cMsg_1a6bCQpl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1Jdpdnw0, 0, m, &cVar_1Jdpdnw0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_slPAmLNF, 0, m, &cVar_slPAmLNF_sendMessage);
  cMsg_lOi2VmXx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wdlgAsZl, 0, m, &cVar_wdlgAsZl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Cz5KzcTu, 0, m, &cVar_Cz5KzcTu_sendMessage);
  cMsg_JqqJNTI3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_d4sekGOH, 0, m, &cVar_d4sekGOH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yZMWgIi5, 0, m, &cVar_yZMWgIi5_sendMessage);
  cMsg_k8XntiyB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oITpSCMw, 0, m, &cVar_oITpSCMw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HxCmzX5j, 0, m, &cVar_HxCmzX5j_sendMessage);
  cMsg_VyQ3xiqw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_u9WVKyv0, 0, m, &cVar_u9WVKyv0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_QbhqHa4z, 0, m, &cVar_QbhqHa4z_sendMessage);
  cMsg_doGYURau_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sf3f8WiK, 0, m, &cVar_sf3f8WiK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pbZrGqGp, 0, m, &cVar_pbZrGqGp_sendMessage);
  cMsg_l5bapfEV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jqLpUI6S, 0, m, &cVar_jqLpUI6S_sendMessage);
  cMsg_eLuhGf9T_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_f1QMnor3, 0, m, &cVar_f1QMnor3_sendMessage);
  cMsg_MvN9iTPR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kgqmpBxm, 0, m, &cVar_kgqmpBxm_sendMessage);
}

void Heavy_vocoder::cReceive_Xslnlzdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_27ueuoAS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KEJnOT5K, HV_BINOP_ADD, 0, m, &cBinop_KEJnOT5K_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mmRVNnCJ, HV_BINOP_ADD, 0, m, &cBinop_mmRVNnCJ_sendMessage);
}

void Heavy_vocoder::cReceive_NRN0bqor_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jTwdN0Th, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_uNXn0XIi, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BOVAhMSK, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_e77BfEZG, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_iTva6sn5, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_k3epWjI9, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_uUNkLiIe, m);
}

void Heavy_vocoder::cReceive_EuVJkitn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mmRVNnCJ, HV_BINOP_ADD, 1, m, &cBinop_mmRVNnCJ_sendMessage);
}

void Heavy_vocoder::cReceive_LMI6kpyg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KEJnOT5K, HV_BINOP_ADD, 1, m, &cBinop_KEJnOT5K_sendMessage);
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
    __hv_varread_f(&sVarf_8EiE3ALc, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_Pik4EYvA, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_9jLy5LEK, VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_FAK7fF7I, VOf(Bf0));
    __hv_add_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_Ri3CEGBS, VIf(Bf2), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_Guj4khII, VIf(Bf1), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_VQiOBwCe, VOf(Bf4));
    __hv_varread_f(&sVarf_jTwdN0Th, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_max_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_VQiOBwCe, VIf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_SqzpNSsp, VIf(Bf2), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_lvXEF4zP, VIf(Bf1), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_WCdOfrUs, VOf(Bf4));
    __hv_varread_f(&sVarf_uNXn0XIi, VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_max_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_f(&sVarf_WCdOfrUs, VIf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_biquad_k_f(&sBiquad_k_3m5lKHSu, VIf(Bf2), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_uN1yFMaP, VIf(Bf1), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_kuqWm33Q, VOf(Bf3));
    __hv_varread_f(&sVarf_BOVAhMSK, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_max_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_kuqWm33Q, VIf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_g5f9n8qL, VIf(Bf2), VOf(Bf6));
    __hv_biquad_k_f(&sBiquad_k_5h29RA2w, VIf(Bf1), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_DJM5VG73, VOf(Bf0));
    __hv_varread_f(&sVarf_e77BfEZG, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_max_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_DJM5VG73, VIf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_biquad_k_f(&sBiquad_k_BwJkrTr3, VIf(Bf2), VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_meSDiDM7, VIf(Bf1), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_t3KwmEMP, VOf(Bf5));
    __hv_varread_f(&sVarf_iTva6sn5, VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_max_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_t3KwmEMP, VIf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_GSPs6uoj, VIf(Bf2), VOf(Bf3));
    __hv_biquad_k_f(&sBiquad_k_T6DXBkUY, VIf(Bf1), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_8xxjCvlH, VOf(Bf6));
    __hv_varread_f(&sVarf_k3epWjI9, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_max_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_8xxjCvlH, VIf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_nyhM3Adw, VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_yBclURri, VIf(Bf1), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_DVKKGx96, VOf(Bf3));
    __hv_varread_f(&sVarf_uUNkLiIe, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_max_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_DVKKGx96, VIf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f);
    __hv_varread_f(&sVarf_gA4311Bp, VOf(Bf2));
    __hv_rpole_f(&sRPole_KRl2pFdV, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_2T777gCu, VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_O8eXPm8R, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_EbM8gqqZ, VOf(Bf1));
    __hv_rpole_f(&sRPole_cHnC3ky1, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_VVSrgcFR, VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Ju0XfHcx, VOf(Bf1));
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
