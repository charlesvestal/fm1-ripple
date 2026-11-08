/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside nts-vocoder.pd) */

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
  numBytes += sPhasor_k_init(&sPhasor_TyqUKcF4, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_FQ4HdbUX, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_2BWpseBP, 0.0f, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_MIKN1w6h, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_6roDtkdV, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_Pul7K8MO, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_Y8F4Omt0, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_YqjRNmpx, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_WD9b28V9, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_uyNKa9ek, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_hloqrH1u, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_sKFl40ow, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_PHTi9Kcn, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_c9zHzsX4, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_dALE1Rm6, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_7a84oXwO, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_Yaah7e9o, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sRPole_init(&sRPole_i99l2KSf);
  numBytes += sDel1_init(&sDel1_kcSQuRzn);
  numBytes += sRPole_init(&sRPole_n8Y1iZ2E);
  numBytes += sDel1_init(&sDel1_3ObEjSOR);
  numBytes += sVarf_init(&sVarf_z3S3ozJC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kLefpNOA, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_pEPcWenB, 267.0f);
  numBytes += cVar_init_f(&cVar_ZtK2XUZM, 15.0f);
  numBytes += cBinop_init(&cBinop_iflqcSU3, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_vCES4IGf, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_EGNtD4Sz, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_wbrxHdmE, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_kGoUgyg4, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_2Wy6Kd9h, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Mh765JU3, 267.0f);
  numBytes += cVar_init_f(&cVar_77cIuFbF, 15.0f);
  numBytes += cBinop_init(&cBinop_uRrR6CgE, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_UASquWoX, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_rVSrGsFx, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_nL5ibaAL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_VMxQQLqx, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_eZEyj448, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_sqXWapVX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_MDdjG5Bf, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ujt0DdPc, 444.0f);
  numBytes += cVar_init_f(&cVar_NY7HjhqW, 15.0f);
  numBytes += cBinop_init(&cBinop_09ptMw4k, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_lDE4ZYdM, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_bgWT3mdN, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_w8TdRbkB, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_v6c36O3s, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_N6iMiKCK, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_3gROEItu, 444.0f);
  numBytes += cVar_init_f(&cVar_snnWnZnp, 15.0f);
  numBytes += cBinop_init(&cBinop_4w4e9HW4, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_8mHHvFSH, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_P2jt7fjM, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_bxaprFvK, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_LGIuynjD, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Z4JlpCmu, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_1Q1yRVo5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jXXV6oTJ, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_3YMbSH3T, 741.0f);
  numBytes += cVar_init_f(&cVar_a3QAVfqM, 15.0f);
  numBytes += cBinop_init(&cBinop_89VkDh55, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_FkDtxaIS, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_oFDM1ep5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_p26GMcs2, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_g48KUWZG, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_jTzXNHG1, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_nYdcMWdl, 741.0f);
  numBytes += cVar_init_f(&cVar_GF7ZW658, 15.0f);
  numBytes += cBinop_init(&cBinop_mNaPB6rI, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_3Bqn1wGn, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_XV90oPfY, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_klJr5pKJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_SZHcCxAH, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_bJzfhNX3, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_55TnijGx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gObobFff, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_3qjTHw2q, 1235.0f);
  numBytes += cVar_init_f(&cVar_w3i8BPsh, 15.0f);
  numBytes += cBinop_init(&cBinop_CNURw6HA, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_nK8BIsH5, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_iQGJUIis, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_n2atDJFc, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_uVC8QAwx, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_dpHooYJP, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_YpCSdxAp, 1235.0f);
  numBytes += cVar_init_f(&cVar_qu9uKa9J, 15.0f);
  numBytes += cBinop_init(&cBinop_kslFL52V, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_VxL4Wo2Q, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_hwKNiB38, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_tksIwuBx, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_3330H3tV, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_uGW3018k, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_hiI57TiC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_D22hLhZj, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_cAx9ao5D, 2058.0f);
  numBytes += cVar_init_f(&cVar_v7IGrzEE, 15.0f);
  numBytes += cBinop_init(&cBinop_9df1BEbt, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ZodF1teF, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_47TnlLge, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_vCR0USyQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_3hV2mfzJ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_RDTc8ra6, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_1VO50FOo, 2058.0f);
  numBytes += cVar_init_f(&cVar_akZtvAOi, 15.0f);
  numBytes += cBinop_init(&cBinop_zHYycM9E, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ulxbZnC7, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_9O4oaDEZ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_5lXRFCde, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_B3ck914x, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_gbYySIwD, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_GRsdf6Xz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9eBBhtvh, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_OOEBLOML, 3429.0f);
  numBytes += cVar_init_f(&cVar_pzCS51hG, 15.0f);
  numBytes += cBinop_init(&cBinop_os82oE1z, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_uQ4gw9k8, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_0qAyRfGA, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_IijZBq1d, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_jVQcp5ob, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_qBtOF6wQ, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_1itXEmBP, 3429.0f);
  numBytes += cVar_init_f(&cVar_zddVLVYc, 15.0f);
  numBytes += cBinop_init(&cBinop_SljIuml0, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_vOJ5zWI2, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Jx66yuBJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_XAaqmr2H, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ij6ZMFdj, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_1U2adUuq, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_6Xdve5R2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4nr4pIBJ, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_VHd2yPaz, 5716.0f);
  numBytes += cVar_init_f(&cVar_OSxrBbWZ, 15.0f);
  numBytes += cBinop_init(&cBinop_V6KVOzdL, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_6qepHojt, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_nw8XYFV6, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_sjvfqYEJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_C3zZFymE, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_DS61Inet, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_nJKcvizr, 5716.0f);
  numBytes += cVar_init_f(&cVar_rSyJZX93, 15.0f);
  numBytes += cBinop_init(&cBinop_pRI03lPh, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_meqOM5LE, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_k2PaR3b5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_DgBA51SH, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_GS3C5le5, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Ic1a0xVq, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_aY0YZric, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_3G0eyWi4, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_XI1sIjgK, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_LzAZPXmn, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_UD0Og7PA, 10000.0f);
  numBytes += cBinop_init(&cBinop_gIYPgdB7, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_wNoUxERN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_N3bkA1MG, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_B5DTpKpN, 10000.0f);
  numBytes += cBinop_init(&cBinop_Sfhy7CnS, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_cx7tlUDE, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_dGhzEafU, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_PzTVzpQX, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_gpTajKTe, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OV5w9tcH_sendMessage);
      break;
    }
    case 0x6C87328F: { // alt_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_da7UeMHy_sendMessage);
      break;
    }
    case 0x3FD8ECD5: { // note1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_F8nEHCaa_sendMessage);
      break;
    }
    case 0x97165D01: { // note2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_csctOATt_sendMessage);
      break;
    }
    case 0xA23B621F: { // pitch_note
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DR6sEOfA_sendMessage);
      break;
    }
    case 0xCE9531B0: { // shape_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VatNf6Xr_sendMessage);
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


void Heavy_nts_vocoder::cMsg_N8u3aPmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oaiDzKfn_sendMessage);
}

void Heavy_nts_vocoder::cSystem_oaiDzKfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iflqcSU3, HV_BINOP_DIVIDE, 1, m, &cBinop_iflqcSU3_sendMessage);
}

void Heavy_nts_vocoder::cVar_pEPcWenB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_cFSYwxyW_sendMessage);
}

void Heavy_nts_vocoder::cVar_ZtK2XUZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_15qcPsTB_sendMessage);
}

void Heavy_nts_vocoder::cUnop_SVXfdMFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_AFvCIui6_sendMessage);
}

void Heavy_nts_vocoder::cBinop_iflqcSU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wbrxHdmE, HV_BINOP_MULTIPLY, 1, m, &cBinop_wbrxHdmE_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_SVXfdMFu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vCES4IGf, HV_BINOP_DIVIDE, 0, m, &cBinop_vCES4IGf_sendMessage);
}

void Heavy_nts_vocoder::cBinop_cFSYwxyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iflqcSU3, HV_BINOP_DIVIDE, 0, m, &cBinop_iflqcSU3_sendMessage);
}

void Heavy_nts_vocoder::cBinop_vCES4IGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_FXqeda9P_sendMessage);
}

void Heavy_nts_vocoder::cBinop_WWiB7y3c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Wpz5U9i5_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Wpz5U9i5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_R5HnGr2u_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EGNtD4Sz, HV_BINOP_MULTIPLY, 0, m, &cBinop_EGNtD4Sz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wbrxHdmE, HV_BINOP_MULTIPLY, 0, m, &cBinop_wbrxHdmE_sendMessage);
}

void Heavy_nts_vocoder::cBinop_AFvCIui6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EGNtD4Sz, HV_BINOP_MULTIPLY, 1, m, &cBinop_EGNtD4Sz_sendMessage);
}

void Heavy_nts_vocoder::cBinop_EGNtD4Sz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_AlQFOu7o_sendMessage);
}

void Heavy_nts_vocoder::cCast_wbVSDLjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pEPcWenB, 0, m, &cVar_pEPcWenB_sendMessage);
}

void Heavy_nts_vocoder::cBinop_mlaS5Kqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1n3nz1Q9_sendMessage);
}

void Heavy_nts_vocoder::cBinop_1n3nz1Q9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_6roDtkdV, 5, m);
}

void Heavy_nts_vocoder::cBinop_AlQFOu7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_6roDtkdV, 4, m);
}

void Heavy_nts_vocoder::cBinop_R3hIV197_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Wy6Kd9h, HV_BINOP_MULTIPLY, 0, m, &cBinop_2Wy6Kd9h_sendMessage);
}

void Heavy_nts_vocoder::cBinop_wbrxHdmE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kGoUgyg4, HV_BINOP_ADD, 1, m, &cBinop_kGoUgyg4_sendMessage);
}

void Heavy_nts_vocoder::cBinop_R5HnGr2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_mlaS5Kqr_sendMessage);
}

void Heavy_nts_vocoder::cBinop_kGoUgyg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Wy6Kd9h, HV_BINOP_MULTIPLY, 1, m, &cBinop_2Wy6Kd9h_sendMessage);
}

void Heavy_nts_vocoder::cBinop_2Wy6Kd9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_6roDtkdV, 1, m);
}

void Heavy_nts_vocoder::cBinop_15qcPsTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vCES4IGf, HV_BINOP_DIVIDE, 1, m, &cBinop_vCES4IGf_sendMessage);
}

void Heavy_nts_vocoder::cBinop_FXqeda9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WWiB7y3c_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_kGoUgyg4, HV_BINOP_ADD, 0, m, &cBinop_kGoUgyg4_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_R3hIV197_sendMessage);
}

void Heavy_nts_vocoder::cMsg_BfxZx84F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eKqjCxgV_sendMessage);
}

void Heavy_nts_vocoder::cSystem_eKqjCxgV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uRrR6CgE, HV_BINOP_DIVIDE, 1, m, &cBinop_uRrR6CgE_sendMessage);
}

void Heavy_nts_vocoder::cVar_Mh765JU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_R7FvbbO9_sendMessage);
}

void Heavy_nts_vocoder::cVar_77cIuFbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_Mej6MmUI_sendMessage);
}

void Heavy_nts_vocoder::cUnop_25be4Y5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_80mwS853_sendMessage);
}

void Heavy_nts_vocoder::cBinop_uRrR6CgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nL5ibaAL, HV_BINOP_MULTIPLY, 1, m, &cBinop_nL5ibaAL_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_25be4Y5v_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_UASquWoX, HV_BINOP_DIVIDE, 0, m, &cBinop_UASquWoX_sendMessage);
}

void Heavy_nts_vocoder::cBinop_R7FvbbO9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uRrR6CgE, HV_BINOP_DIVIDE, 0, m, &cBinop_uRrR6CgE_sendMessage);
}

void Heavy_nts_vocoder::cBinop_UASquWoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LvnyOpud_sendMessage);
}

void Heavy_nts_vocoder::cBinop_mwZBLgtC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_lX1Kzynr_sendMessage);
}

void Heavy_nts_vocoder::cBinop_lX1Kzynr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_UhoNZ2qB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rVSrGsFx, HV_BINOP_MULTIPLY, 0, m, &cBinop_rVSrGsFx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nL5ibaAL, HV_BINOP_MULTIPLY, 0, m, &cBinop_nL5ibaAL_sendMessage);
}

void Heavy_nts_vocoder::cBinop_80mwS853_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rVSrGsFx, HV_BINOP_MULTIPLY, 1, m, &cBinop_rVSrGsFx_sendMessage);
}

void Heavy_nts_vocoder::cBinop_rVSrGsFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_A8pZJhQ5_sendMessage);
}

void Heavy_nts_vocoder::cCast_bIbi9Hfa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Mh765JU3, 0, m, &cVar_Mh765JU3_sendMessage);
}

void Heavy_nts_vocoder::cBinop_GsZtv4pq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_IqW3Dtvz_sendMessage);
}

void Heavy_nts_vocoder::cBinop_IqW3Dtvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_MIKN1w6h, 5, m);
}

void Heavy_nts_vocoder::cBinop_A8pZJhQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_MIKN1w6h, 4, m);
}

void Heavy_nts_vocoder::cBinop_K4NSidJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eZEyj448, HV_BINOP_MULTIPLY, 0, m, &cBinop_eZEyj448_sendMessage);
}

void Heavy_nts_vocoder::cBinop_nL5ibaAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VMxQQLqx, HV_BINOP_ADD, 1, m, &cBinop_VMxQQLqx_sendMessage);
}

void Heavy_nts_vocoder::cBinop_UhoNZ2qB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GsZtv4pq_sendMessage);
}

void Heavy_nts_vocoder::cBinop_VMxQQLqx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eZEyj448, HV_BINOP_MULTIPLY, 1, m, &cBinop_eZEyj448_sendMessage);
}

void Heavy_nts_vocoder::cBinop_eZEyj448_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_MIKN1w6h, 1, m);
}

void Heavy_nts_vocoder::cBinop_Mej6MmUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UASquWoX, HV_BINOP_DIVIDE, 1, m, &cBinop_UASquWoX_sendMessage);
}

void Heavy_nts_vocoder::cBinop_LvnyOpud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_mwZBLgtC_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VMxQQLqx, HV_BINOP_ADD, 0, m, &cBinop_VMxQQLqx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_K4NSidJu_sendMessage);
}

void Heavy_nts_vocoder::cMsg_80rwU1tm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nOQTEww4_sendMessage);
}

void Heavy_nts_vocoder::cSystem_nOQTEww4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_09ptMw4k, HV_BINOP_DIVIDE, 1, m, &cBinop_09ptMw4k_sendMessage);
}

void Heavy_nts_vocoder::cVar_ujt0DdPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_1DOfajUl_sendMessage);
}

void Heavy_nts_vocoder::cVar_NY7HjhqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_GAmReQap_sendMessage);
}

void Heavy_nts_vocoder::cUnop_N4C0Xyuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_NcEy6uG8_sendMessage);
}

void Heavy_nts_vocoder::cBinop_09ptMw4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_w8TdRbkB, HV_BINOP_MULTIPLY, 1, m, &cBinop_w8TdRbkB_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_N4C0Xyuh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lDE4ZYdM, HV_BINOP_DIVIDE, 0, m, &cBinop_lDE4ZYdM_sendMessage);
}

void Heavy_nts_vocoder::cBinop_1DOfajUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_09ptMw4k, HV_BINOP_DIVIDE, 0, m, &cBinop_09ptMw4k_sendMessage);
}

void Heavy_nts_vocoder::cBinop_lDE4ZYdM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_rLzvQKDW_sendMessage);
}

void Heavy_nts_vocoder::cBinop_znqbGL5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_NNvphe0q_sendMessage);
}

void Heavy_nts_vocoder::cBinop_NNvphe0q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_HaCMlMNU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bgWT3mdN, HV_BINOP_MULTIPLY, 0, m, &cBinop_bgWT3mdN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_w8TdRbkB, HV_BINOP_MULTIPLY, 0, m, &cBinop_w8TdRbkB_sendMessage);
}

void Heavy_nts_vocoder::cBinop_NcEy6uG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bgWT3mdN, HV_BINOP_MULTIPLY, 1, m, &cBinop_bgWT3mdN_sendMessage);
}

void Heavy_nts_vocoder::cBinop_bgWT3mdN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5C7CmYQJ_sendMessage);
}

void Heavy_nts_vocoder::cCast_39hoFmJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ujt0DdPc, 0, m, &cVar_ujt0DdPc_sendMessage);
}

void Heavy_nts_vocoder::cBinop_S0wN2j75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_PbkzOylL_sendMessage);
}

void Heavy_nts_vocoder::cBinop_PbkzOylL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Y8F4Omt0, 5, m);
}

void Heavy_nts_vocoder::cBinop_5C7CmYQJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Y8F4Omt0, 4, m);
}

void Heavy_nts_vocoder::cBinop_b3yx7mOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N6iMiKCK, HV_BINOP_MULTIPLY, 0, m, &cBinop_N6iMiKCK_sendMessage);
}

void Heavy_nts_vocoder::cBinop_w8TdRbkB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_v6c36O3s, HV_BINOP_ADD, 1, m, &cBinop_v6c36O3s_sendMessage);
}

void Heavy_nts_vocoder::cBinop_HaCMlMNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_S0wN2j75_sendMessage);
}

void Heavy_nts_vocoder::cBinop_v6c36O3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N6iMiKCK, HV_BINOP_MULTIPLY, 1, m, &cBinop_N6iMiKCK_sendMessage);
}

void Heavy_nts_vocoder::cBinop_N6iMiKCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Y8F4Omt0, 1, m);
}

void Heavy_nts_vocoder::cBinop_GAmReQap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lDE4ZYdM, HV_BINOP_DIVIDE, 1, m, &cBinop_lDE4ZYdM_sendMessage);
}

void Heavy_nts_vocoder::cBinop_rLzvQKDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_znqbGL5g_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_v6c36O3s, HV_BINOP_ADD, 0, m, &cBinop_v6c36O3s_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_b3yx7mOJ_sendMessage);
}

void Heavy_nts_vocoder::cMsg_cbACvuvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wJKclEPS_sendMessage);
}

void Heavy_nts_vocoder::cSystem_wJKclEPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4w4e9HW4, HV_BINOP_DIVIDE, 1, m, &cBinop_4w4e9HW4_sendMessage);
}

void Heavy_nts_vocoder::cVar_3gROEItu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_02pV355a_sendMessage);
}

void Heavy_nts_vocoder::cVar_snnWnZnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_MGGo55L9_sendMessage);
}

void Heavy_nts_vocoder::cUnop_i2H2Glwk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_djqQ82qb_sendMessage);
}

void Heavy_nts_vocoder::cBinop_4w4e9HW4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bxaprFvK, HV_BINOP_MULTIPLY, 1, m, &cBinop_bxaprFvK_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_i2H2Glwk_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8mHHvFSH, HV_BINOP_DIVIDE, 0, m, &cBinop_8mHHvFSH_sendMessage);
}

void Heavy_nts_vocoder::cBinop_02pV355a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4w4e9HW4, HV_BINOP_DIVIDE, 0, m, &cBinop_4w4e9HW4_sendMessage);
}

void Heavy_nts_vocoder::cBinop_8mHHvFSH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_HSAqR67d_sendMessage);
}

void Heavy_nts_vocoder::cBinop_pwpVPnCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Vgr9Ll16_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Vgr9Ll16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_8IGDpZl9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_P2jt7fjM, HV_BINOP_MULTIPLY, 0, m, &cBinop_P2jt7fjM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bxaprFvK, HV_BINOP_MULTIPLY, 0, m, &cBinop_bxaprFvK_sendMessage);
}

void Heavy_nts_vocoder::cBinop_djqQ82qb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P2jt7fjM, HV_BINOP_MULTIPLY, 1, m, &cBinop_P2jt7fjM_sendMessage);
}

void Heavy_nts_vocoder::cBinop_P2jt7fjM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2d3Ibj7l_sendMessage);
}

void Heavy_nts_vocoder::cCast_L4LpFPNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3gROEItu, 0, m, &cVar_3gROEItu_sendMessage);
}

void Heavy_nts_vocoder::cBinop_4XT2dNCL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fsSo9jJl_sendMessage);
}

void Heavy_nts_vocoder::cBinop_fsSo9jJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Pul7K8MO, 5, m);
}

void Heavy_nts_vocoder::cBinop_2d3Ibj7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Pul7K8MO, 4, m);
}

void Heavy_nts_vocoder::cBinop_EORHc6Kg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z4JlpCmu, HV_BINOP_MULTIPLY, 0, m, &cBinop_Z4JlpCmu_sendMessage);
}

void Heavy_nts_vocoder::cBinop_bxaprFvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LGIuynjD, HV_BINOP_ADD, 1, m, &cBinop_LGIuynjD_sendMessage);
}

void Heavy_nts_vocoder::cBinop_8IGDpZl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4XT2dNCL_sendMessage);
}

void Heavy_nts_vocoder::cBinop_LGIuynjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z4JlpCmu, HV_BINOP_MULTIPLY, 1, m, &cBinop_Z4JlpCmu_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Z4JlpCmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Pul7K8MO, 1, m);
}

void Heavy_nts_vocoder::cBinop_MGGo55L9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8mHHvFSH, HV_BINOP_DIVIDE, 1, m, &cBinop_8mHHvFSH_sendMessage);
}

void Heavy_nts_vocoder::cBinop_HSAqR67d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pwpVPnCx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LGIuynjD, HV_BINOP_ADD, 0, m, &cBinop_LGIuynjD_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_EORHc6Kg_sendMessage);
}

void Heavy_nts_vocoder::cMsg_SWhbKBBO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_L2z7zxR3_sendMessage);
}

void Heavy_nts_vocoder::cSystem_L2z7zxR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_89VkDh55, HV_BINOP_DIVIDE, 1, m, &cBinop_89VkDh55_sendMessage);
}

void Heavy_nts_vocoder::cVar_3YMbSH3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_GigHCznC_sendMessage);
}

void Heavy_nts_vocoder::cVar_a3QAVfqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_6J5ySdp6_sendMessage);
}

void Heavy_nts_vocoder::cUnop_IbHMJ0Ij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_EBMJ6hS4_sendMessage);
}

void Heavy_nts_vocoder::cBinop_89VkDh55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p26GMcs2, HV_BINOP_MULTIPLY, 1, m, &cBinop_p26GMcs2_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_IbHMJ0Ij_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FkDtxaIS, HV_BINOP_DIVIDE, 0, m, &cBinop_FkDtxaIS_sendMessage);
}

void Heavy_nts_vocoder::cBinop_GigHCznC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_89VkDh55, HV_BINOP_DIVIDE, 0, m, &cBinop_89VkDh55_sendMessage);
}

void Heavy_nts_vocoder::cBinop_FkDtxaIS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_vqyiUadY_sendMessage);
}

void Heavy_nts_vocoder::cBinop_pQj4zMtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_bDdaAnFb_sendMessage);
}

void Heavy_nts_vocoder::cBinop_bDdaAnFb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_Hr64Tg90_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oFDM1ep5, HV_BINOP_MULTIPLY, 0, m, &cBinop_oFDM1ep5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_p26GMcs2, HV_BINOP_MULTIPLY, 0, m, &cBinop_p26GMcs2_sendMessage);
}

void Heavy_nts_vocoder::cBinop_EBMJ6hS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oFDM1ep5, HV_BINOP_MULTIPLY, 1, m, &cBinop_oFDM1ep5_sendMessage);
}

void Heavy_nts_vocoder::cBinop_oFDM1ep5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_L32pRzxV_sendMessage);
}

void Heavy_nts_vocoder::cCast_fEjNjWCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3YMbSH3T, 0, m, &cVar_3YMbSH3T_sendMessage);
}

void Heavy_nts_vocoder::cBinop_E5WYym5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xeNK4rD6_sendMessage);
}

void Heavy_nts_vocoder::cBinop_xeNK4rD6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_WD9b28V9, 5, m);
}

void Heavy_nts_vocoder::cBinop_L32pRzxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_WD9b28V9, 4, m);
}

void Heavy_nts_vocoder::cBinop_kWqXjBMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jTzXNHG1, HV_BINOP_MULTIPLY, 0, m, &cBinop_jTzXNHG1_sendMessage);
}

void Heavy_nts_vocoder::cBinop_p26GMcs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g48KUWZG, HV_BINOP_ADD, 1, m, &cBinop_g48KUWZG_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Hr64Tg90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_E5WYym5z_sendMessage);
}

void Heavy_nts_vocoder::cBinop_g48KUWZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jTzXNHG1, HV_BINOP_MULTIPLY, 1, m, &cBinop_jTzXNHG1_sendMessage);
}

void Heavy_nts_vocoder::cBinop_jTzXNHG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_WD9b28V9, 1, m);
}

void Heavy_nts_vocoder::cBinop_6J5ySdp6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FkDtxaIS, HV_BINOP_DIVIDE, 1, m, &cBinop_FkDtxaIS_sendMessage);
}

void Heavy_nts_vocoder::cBinop_vqyiUadY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pQj4zMtX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_g48KUWZG, HV_BINOP_ADD, 0, m, &cBinop_g48KUWZG_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_kWqXjBMR_sendMessage);
}

void Heavy_nts_vocoder::cMsg_NjdxvhHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ySCfTBk4_sendMessage);
}

void Heavy_nts_vocoder::cSystem_ySCfTBk4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mNaPB6rI, HV_BINOP_DIVIDE, 1, m, &cBinop_mNaPB6rI_sendMessage);
}

void Heavy_nts_vocoder::cVar_nYdcMWdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_9QOxUyBY_sendMessage);
}

void Heavy_nts_vocoder::cVar_GF7ZW658_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_LzMvpfvF_sendMessage);
}

void Heavy_nts_vocoder::cUnop_QUVnTqlP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_SPCVL6fm_sendMessage);
}

void Heavy_nts_vocoder::cBinop_mNaPB6rI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_klJr5pKJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_klJr5pKJ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_QUVnTqlP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Bqn1wGn, HV_BINOP_DIVIDE, 0, m, &cBinop_3Bqn1wGn_sendMessage);
}

void Heavy_nts_vocoder::cBinop_9QOxUyBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mNaPB6rI, HV_BINOP_DIVIDE, 0, m, &cBinop_mNaPB6rI_sendMessage);
}

void Heavy_nts_vocoder::cBinop_3Bqn1wGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_5ogPIk7I_sendMessage);
}

void Heavy_nts_vocoder::cBinop_cIDKVSNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_jnxpH6gl_sendMessage);
}

void Heavy_nts_vocoder::cBinop_jnxpH6gl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_mBwjVc4n_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XV90oPfY, HV_BINOP_MULTIPLY, 0, m, &cBinop_XV90oPfY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_klJr5pKJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_klJr5pKJ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_SPCVL6fm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XV90oPfY, HV_BINOP_MULTIPLY, 1, m, &cBinop_XV90oPfY_sendMessage);
}

void Heavy_nts_vocoder::cBinop_XV90oPfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2MlRW2Ni_sendMessage);
}

void Heavy_nts_vocoder::cCast_8YN0UckB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nYdcMWdl, 0, m, &cVar_nYdcMWdl_sendMessage);
}

void Heavy_nts_vocoder::cBinop_RJRHQrig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OhqM51Ru_sendMessage);
}

void Heavy_nts_vocoder::cBinop_OhqM51Ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_YqjRNmpx, 5, m);
}

void Heavy_nts_vocoder::cBinop_2MlRW2Ni_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_YqjRNmpx, 4, m);
}

void Heavy_nts_vocoder::cBinop_75pSNNbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bJzfhNX3, HV_BINOP_MULTIPLY, 0, m, &cBinop_bJzfhNX3_sendMessage);
}

void Heavy_nts_vocoder::cBinop_klJr5pKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SZHcCxAH, HV_BINOP_ADD, 1, m, &cBinop_SZHcCxAH_sendMessage);
}

void Heavy_nts_vocoder::cBinop_mBwjVc4n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RJRHQrig_sendMessage);
}

void Heavy_nts_vocoder::cBinop_SZHcCxAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bJzfhNX3, HV_BINOP_MULTIPLY, 1, m, &cBinop_bJzfhNX3_sendMessage);
}

void Heavy_nts_vocoder::cBinop_bJzfhNX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_YqjRNmpx, 1, m);
}

void Heavy_nts_vocoder::cBinop_LzMvpfvF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Bqn1wGn, HV_BINOP_DIVIDE, 1, m, &cBinop_3Bqn1wGn_sendMessage);
}

void Heavy_nts_vocoder::cBinop_5ogPIk7I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cIDKVSNI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SZHcCxAH, HV_BINOP_ADD, 0, m, &cBinop_SZHcCxAH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_75pSNNbZ_sendMessage);
}

void Heavy_nts_vocoder::cMsg_qYpmwohD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_x3WmmQ9U_sendMessage);
}

void Heavy_nts_vocoder::cSystem_x3WmmQ9U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CNURw6HA, HV_BINOP_DIVIDE, 1, m, &cBinop_CNURw6HA_sendMessage);
}

void Heavy_nts_vocoder::cVar_3qjTHw2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_sOkY8PjT_sendMessage);
}

void Heavy_nts_vocoder::cVar_w3i8BPsh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_lW1GAeNp_sendMessage);
}

void Heavy_nts_vocoder::cUnop_EpkNlgD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_728WMkwp_sendMessage);
}

void Heavy_nts_vocoder::cBinop_CNURw6HA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n2atDJFc, HV_BINOP_MULTIPLY, 1, m, &cBinop_n2atDJFc_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_EpkNlgD3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nK8BIsH5, HV_BINOP_DIVIDE, 0, m, &cBinop_nK8BIsH5_sendMessage);
}

void Heavy_nts_vocoder::cBinop_sOkY8PjT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CNURw6HA, HV_BINOP_DIVIDE, 0, m, &cBinop_CNURw6HA_sendMessage);
}

void Heavy_nts_vocoder::cBinop_nK8BIsH5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_CvMmyUhu_sendMessage);
}

void Heavy_nts_vocoder::cBinop_GZRqHDdr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ZXDt9LfY_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ZXDt9LfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_xIF1D75Q_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_iQGJUIis, HV_BINOP_MULTIPLY, 0, m, &cBinop_iQGJUIis_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_n2atDJFc, HV_BINOP_MULTIPLY, 0, m, &cBinop_n2atDJFc_sendMessage);
}

void Heavy_nts_vocoder::cBinop_728WMkwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iQGJUIis, HV_BINOP_MULTIPLY, 1, m, &cBinop_iQGJUIis_sendMessage);
}

void Heavy_nts_vocoder::cBinop_iQGJUIis_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DOoHi0DG_sendMessage);
}

void Heavy_nts_vocoder::cCast_aU9n9yQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3qjTHw2q, 0, m, &cVar_3qjTHw2q_sendMessage);
}

void Heavy_nts_vocoder::cBinop_k0gzZzK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UOJwhEeH_sendMessage);
}

void Heavy_nts_vocoder::cBinop_UOJwhEeH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_hloqrH1u, 5, m);
}

void Heavy_nts_vocoder::cBinop_DOoHi0DG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_hloqrH1u, 4, m);
}

void Heavy_nts_vocoder::cBinop_Ce1THyLd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dpHooYJP, HV_BINOP_MULTIPLY, 0, m, &cBinop_dpHooYJP_sendMessage);
}

void Heavy_nts_vocoder::cBinop_n2atDJFc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uVC8QAwx, HV_BINOP_ADD, 1, m, &cBinop_uVC8QAwx_sendMessage);
}

void Heavy_nts_vocoder::cBinop_xIF1D75Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_k0gzZzK5_sendMessage);
}

void Heavy_nts_vocoder::cBinop_uVC8QAwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dpHooYJP, HV_BINOP_MULTIPLY, 1, m, &cBinop_dpHooYJP_sendMessage);
}

void Heavy_nts_vocoder::cBinop_dpHooYJP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_hloqrH1u, 1, m);
}

void Heavy_nts_vocoder::cBinop_lW1GAeNp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nK8BIsH5, HV_BINOP_DIVIDE, 1, m, &cBinop_nK8BIsH5_sendMessage);
}

void Heavy_nts_vocoder::cBinop_CvMmyUhu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GZRqHDdr_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uVC8QAwx, HV_BINOP_ADD, 0, m, &cBinop_uVC8QAwx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_Ce1THyLd_sendMessage);
}

void Heavy_nts_vocoder::cMsg_RyBGVACH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_l48kQnEV_sendMessage);
}

void Heavy_nts_vocoder::cSystem_l48kQnEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kslFL52V, HV_BINOP_DIVIDE, 1, m, &cBinop_kslFL52V_sendMessage);
}

void Heavy_nts_vocoder::cVar_YpCSdxAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_g8pCcyRJ_sendMessage);
}

void Heavy_nts_vocoder::cVar_qu9uKa9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_SmeyTx2R_sendMessage);
}

void Heavy_nts_vocoder::cUnop_5V6JCEMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_9tNvfYSr_sendMessage);
}

void Heavy_nts_vocoder::cBinop_kslFL52V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tksIwuBx, HV_BINOP_MULTIPLY, 1, m, &cBinop_tksIwuBx_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_5V6JCEMe_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VxL4Wo2Q, HV_BINOP_DIVIDE, 0, m, &cBinop_VxL4Wo2Q_sendMessage);
}

void Heavy_nts_vocoder::cBinop_g8pCcyRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kslFL52V, HV_BINOP_DIVIDE, 0, m, &cBinop_kslFL52V_sendMessage);
}

void Heavy_nts_vocoder::cBinop_VxL4Wo2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Lx85dRbv_sendMessage);
}

void Heavy_nts_vocoder::cBinop_7ZpXLpYs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Dy2LODKh_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Dy2LODKh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_BBvhNlVN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hwKNiB38, HV_BINOP_MULTIPLY, 0, m, &cBinop_hwKNiB38_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tksIwuBx, HV_BINOP_MULTIPLY, 0, m, &cBinop_tksIwuBx_sendMessage);
}

void Heavy_nts_vocoder::cBinop_9tNvfYSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hwKNiB38, HV_BINOP_MULTIPLY, 1, m, &cBinop_hwKNiB38_sendMessage);
}

void Heavy_nts_vocoder::cBinop_hwKNiB38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_U4T8vYrW_sendMessage);
}

void Heavy_nts_vocoder::cCast_21j9tNJF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YpCSdxAp, 0, m, &cVar_YpCSdxAp_sendMessage);
}

void Heavy_nts_vocoder::cBinop_tPyEXKcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Emmqzmai_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Emmqzmai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uyNKa9ek, 5, m);
}

void Heavy_nts_vocoder::cBinop_U4T8vYrW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uyNKa9ek, 4, m);
}

void Heavy_nts_vocoder::cBinop_ja2u8vkQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uGW3018k, HV_BINOP_MULTIPLY, 0, m, &cBinop_uGW3018k_sendMessage);
}

void Heavy_nts_vocoder::cBinop_tksIwuBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3330H3tV, HV_BINOP_ADD, 1, m, &cBinop_3330H3tV_sendMessage);
}

void Heavy_nts_vocoder::cBinop_BBvhNlVN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_tPyEXKcP_sendMessage);
}

void Heavy_nts_vocoder::cBinop_3330H3tV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uGW3018k, HV_BINOP_MULTIPLY, 1, m, &cBinop_uGW3018k_sendMessage);
}

void Heavy_nts_vocoder::cBinop_uGW3018k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uyNKa9ek, 1, m);
}

void Heavy_nts_vocoder::cBinop_SmeyTx2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VxL4Wo2Q, HV_BINOP_DIVIDE, 1, m, &cBinop_VxL4Wo2Q_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Lx85dRbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7ZpXLpYs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3330H3tV, HV_BINOP_ADD, 0, m, &cBinop_3330H3tV_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ja2u8vkQ_sendMessage);
}

void Heavy_nts_vocoder::cMsg_g0bmTF3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XqCZrc1w_sendMessage);
}

void Heavy_nts_vocoder::cSystem_XqCZrc1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9df1BEbt, HV_BINOP_DIVIDE, 1, m, &cBinop_9df1BEbt_sendMessage);
}

void Heavy_nts_vocoder::cVar_cAx9ao5D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_UwUwcymq_sendMessage);
}

void Heavy_nts_vocoder::cVar_v7IGrzEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_xVgpzIKl_sendMessage);
}

void Heavy_nts_vocoder::cUnop_DVoJP8no_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_YhMu9q1b_sendMessage);
}

void Heavy_nts_vocoder::cBinop_9df1BEbt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vCR0USyQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_vCR0USyQ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_DVoJP8no_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZodF1teF, HV_BINOP_DIVIDE, 0, m, &cBinop_ZodF1teF_sendMessage);
}

void Heavy_nts_vocoder::cBinop_UwUwcymq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9df1BEbt, HV_BINOP_DIVIDE, 0, m, &cBinop_9df1BEbt_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ZodF1teF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_pSUHHny8_sendMessage);
}

void Heavy_nts_vocoder::cBinop_u00wI3xO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_T9TPKtuW_sendMessage);
}

void Heavy_nts_vocoder::cBinop_T9TPKtuW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_BlNSL2Vc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_47TnlLge, HV_BINOP_MULTIPLY, 0, m, &cBinop_47TnlLge_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vCR0USyQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_vCR0USyQ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_YhMu9q1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_47TnlLge, HV_BINOP_MULTIPLY, 1, m, &cBinop_47TnlLge_sendMessage);
}

void Heavy_nts_vocoder::cBinop_47TnlLge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2AO2HvSq_sendMessage);
}

void Heavy_nts_vocoder::cCast_6ezDr4Dp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cAx9ao5D, 0, m, &cVar_cAx9ao5D_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Rgq9BKUF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_em19kPgu_sendMessage);
}

void Heavy_nts_vocoder::cBinop_em19kPgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_PHTi9Kcn, 5, m);
}

void Heavy_nts_vocoder::cBinop_2AO2HvSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_PHTi9Kcn, 4, m);
}

void Heavy_nts_vocoder::cBinop_VoTn5Np8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RDTc8ra6, HV_BINOP_MULTIPLY, 0, m, &cBinop_RDTc8ra6_sendMessage);
}

void Heavy_nts_vocoder::cBinop_vCR0USyQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3hV2mfzJ, HV_BINOP_ADD, 1, m, &cBinop_3hV2mfzJ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_BlNSL2Vc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Rgq9BKUF_sendMessage);
}

void Heavy_nts_vocoder::cBinop_3hV2mfzJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RDTc8ra6, HV_BINOP_MULTIPLY, 1, m, &cBinop_RDTc8ra6_sendMessage);
}

void Heavy_nts_vocoder::cBinop_RDTc8ra6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_PHTi9Kcn, 1, m);
}

void Heavy_nts_vocoder::cBinop_xVgpzIKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZodF1teF, HV_BINOP_DIVIDE, 1, m, &cBinop_ZodF1teF_sendMessage);
}

void Heavy_nts_vocoder::cBinop_pSUHHny8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_u00wI3xO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3hV2mfzJ, HV_BINOP_ADD, 0, m, &cBinop_3hV2mfzJ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_VoTn5Np8_sendMessage);
}

void Heavy_nts_vocoder::cMsg_Rs4omhpk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_P9FwBSQQ_sendMessage);
}

void Heavy_nts_vocoder::cSystem_P9FwBSQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zHYycM9E, HV_BINOP_DIVIDE, 1, m, &cBinop_zHYycM9E_sendMessage);
}

void Heavy_nts_vocoder::cVar_1VO50FOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_WbTijgU3_sendMessage);
}

void Heavy_nts_vocoder::cVar_akZtvAOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_Mf0tvC1I_sendMessage);
}

void Heavy_nts_vocoder::cUnop_J2Iwoiyo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_nCD3yR7H_sendMessage);
}

void Heavy_nts_vocoder::cBinop_zHYycM9E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5lXRFCde, HV_BINOP_MULTIPLY, 1, m, &cBinop_5lXRFCde_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_J2Iwoiyo_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ulxbZnC7, HV_BINOP_DIVIDE, 0, m, &cBinop_ulxbZnC7_sendMessage);
}

void Heavy_nts_vocoder::cBinop_WbTijgU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zHYycM9E, HV_BINOP_DIVIDE, 0, m, &cBinop_zHYycM9E_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ulxbZnC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_237OBXAs_sendMessage);
}

void Heavy_nts_vocoder::cBinop_WFtbkzic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_jEv8YA2H_sendMessage);
}

void Heavy_nts_vocoder::cBinop_jEv8YA2H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_mD1Pxiv4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9O4oaDEZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_9O4oaDEZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5lXRFCde, HV_BINOP_MULTIPLY, 0, m, &cBinop_5lXRFCde_sendMessage);
}

void Heavy_nts_vocoder::cBinop_nCD3yR7H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9O4oaDEZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_9O4oaDEZ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_9O4oaDEZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dQ4muLKq_sendMessage);
}

void Heavy_nts_vocoder::cCast_NK9W47g3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1VO50FOo, 0, m, &cVar_1VO50FOo_sendMessage);
}

void Heavy_nts_vocoder::cBinop_sOrd0lUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kOz5jnqy_sendMessage);
}

void Heavy_nts_vocoder::cBinop_kOz5jnqy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_sKFl40ow, 5, m);
}

void Heavy_nts_vocoder::cBinop_dQ4muLKq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_sKFl40ow, 4, m);
}

void Heavy_nts_vocoder::cBinop_jq82uTYz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gbYySIwD, HV_BINOP_MULTIPLY, 0, m, &cBinop_gbYySIwD_sendMessage);
}

void Heavy_nts_vocoder::cBinop_5lXRFCde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B3ck914x, HV_BINOP_ADD, 1, m, &cBinop_B3ck914x_sendMessage);
}

void Heavy_nts_vocoder::cBinop_mD1Pxiv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_sOrd0lUJ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_B3ck914x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gbYySIwD, HV_BINOP_MULTIPLY, 1, m, &cBinop_gbYySIwD_sendMessage);
}

void Heavy_nts_vocoder::cBinop_gbYySIwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_sKFl40ow, 1, m);
}

void Heavy_nts_vocoder::cBinop_Mf0tvC1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ulxbZnC7, HV_BINOP_DIVIDE, 1, m, &cBinop_ulxbZnC7_sendMessage);
}

void Heavy_nts_vocoder::cBinop_237OBXAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WFtbkzic_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_B3ck914x, HV_BINOP_ADD, 0, m, &cBinop_B3ck914x_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_jq82uTYz_sendMessage);
}

void Heavy_nts_vocoder::cMsg_lgE32lmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3FuXtTV1_sendMessage);
}

void Heavy_nts_vocoder::cSystem_3FuXtTV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_os82oE1z, HV_BINOP_DIVIDE, 1, m, &cBinop_os82oE1z_sendMessage);
}

void Heavy_nts_vocoder::cVar_OOEBLOML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_CALI5pyk_sendMessage);
}

void Heavy_nts_vocoder::cVar_pzCS51hG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_ilqt0UBe_sendMessage);
}

void Heavy_nts_vocoder::cUnop_G8Fsx14r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_WoFeIOC7_sendMessage);
}

void Heavy_nts_vocoder::cBinop_os82oE1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IijZBq1d, HV_BINOP_MULTIPLY, 1, m, &cBinop_IijZBq1d_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_G8Fsx14r_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uQ4gw9k8, HV_BINOP_DIVIDE, 0, m, &cBinop_uQ4gw9k8_sendMessage);
}

void Heavy_nts_vocoder::cBinop_CALI5pyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_os82oE1z, HV_BINOP_DIVIDE, 0, m, &cBinop_os82oE1z_sendMessage);
}

void Heavy_nts_vocoder::cBinop_uQ4gw9k8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_hUN0qdpv_sendMessage);
}

void Heavy_nts_vocoder::cBinop_E2C9wkid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_JjprhsBI_sendMessage);
}

void Heavy_nts_vocoder::cBinop_JjprhsBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_6cSDh7sL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0qAyRfGA, HV_BINOP_MULTIPLY, 0, m, &cBinop_0qAyRfGA_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IijZBq1d, HV_BINOP_MULTIPLY, 0, m, &cBinop_IijZBq1d_sendMessage);
}

void Heavy_nts_vocoder::cBinop_WoFeIOC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0qAyRfGA, HV_BINOP_MULTIPLY, 1, m, &cBinop_0qAyRfGA_sendMessage);
}

void Heavy_nts_vocoder::cBinop_0qAyRfGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_L5LWbNID_sendMessage);
}

void Heavy_nts_vocoder::cCast_q3xalpud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OOEBLOML, 0, m, &cVar_OOEBLOML_sendMessage);
}

void Heavy_nts_vocoder::cBinop_O4Cm5gRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nil8x8mg_sendMessage);
}

void Heavy_nts_vocoder::cBinop_nil8x8mg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_dALE1Rm6, 5, m);
}

void Heavy_nts_vocoder::cBinop_L5LWbNID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_dALE1Rm6, 4, m);
}

void Heavy_nts_vocoder::cBinop_CMpXJRRD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qBtOF6wQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_qBtOF6wQ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_IijZBq1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jVQcp5ob, HV_BINOP_ADD, 1, m, &cBinop_jVQcp5ob_sendMessage);
}

void Heavy_nts_vocoder::cBinop_6cSDh7sL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_O4Cm5gRE_sendMessage);
}

void Heavy_nts_vocoder::cBinop_jVQcp5ob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qBtOF6wQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_qBtOF6wQ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_qBtOF6wQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_dALE1Rm6, 1, m);
}

void Heavy_nts_vocoder::cBinop_ilqt0UBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uQ4gw9k8, HV_BINOP_DIVIDE, 1, m, &cBinop_uQ4gw9k8_sendMessage);
}

void Heavy_nts_vocoder::cBinop_hUN0qdpv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_E2C9wkid_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jVQcp5ob, HV_BINOP_ADD, 0, m, &cBinop_jVQcp5ob_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_CMpXJRRD_sendMessage);
}

void Heavy_nts_vocoder::cMsg_A4m7NXub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JopbhiKB_sendMessage);
}

void Heavy_nts_vocoder::cSystem_JopbhiKB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SljIuml0, HV_BINOP_DIVIDE, 1, m, &cBinop_SljIuml0_sendMessage);
}

void Heavy_nts_vocoder::cVar_1itXEmBP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_1tj6ePYl_sendMessage);
}

void Heavy_nts_vocoder::cVar_zddVLVYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_jYuz594r_sendMessage);
}

void Heavy_nts_vocoder::cUnop_oHfPZTWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_jtn5SIMA_sendMessage);
}

void Heavy_nts_vocoder::cBinop_SljIuml0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XAaqmr2H, HV_BINOP_MULTIPLY, 1, m, &cBinop_XAaqmr2H_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_oHfPZTWB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vOJ5zWI2, HV_BINOP_DIVIDE, 0, m, &cBinop_vOJ5zWI2_sendMessage);
}

void Heavy_nts_vocoder::cBinop_1tj6ePYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SljIuml0, HV_BINOP_DIVIDE, 0, m, &cBinop_SljIuml0_sendMessage);
}

void Heavy_nts_vocoder::cBinop_vOJ5zWI2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1Ns4udC7_sendMessage);
}

void Heavy_nts_vocoder::cBinop_UgQkn4ix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_01Im7E9q_sendMessage);
}

void Heavy_nts_vocoder::cBinop_01Im7E9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_z3yo3WQc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jx66yuBJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Jx66yuBJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XAaqmr2H, HV_BINOP_MULTIPLY, 0, m, &cBinop_XAaqmr2H_sendMessage);
}

void Heavy_nts_vocoder::cBinop_jtn5SIMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jx66yuBJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_Jx66yuBJ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Jx66yuBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BAWRFYcR_sendMessage);
}

void Heavy_nts_vocoder::cCast_SbzKDHGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1itXEmBP, 0, m, &cVar_1itXEmBP_sendMessage);
}

void Heavy_nts_vocoder::cBinop_JEs9WI0R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZsvR6RlP_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ZsvR6RlP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_c9zHzsX4, 5, m);
}

void Heavy_nts_vocoder::cBinop_BAWRFYcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_c9zHzsX4, 4, m);
}

void Heavy_nts_vocoder::cBinop_4zg46two_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1U2adUuq, HV_BINOP_MULTIPLY, 0, m, &cBinop_1U2adUuq_sendMessage);
}

void Heavy_nts_vocoder::cBinop_XAaqmr2H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ij6ZMFdj, HV_BINOP_ADD, 1, m, &cBinop_ij6ZMFdj_sendMessage);
}

void Heavy_nts_vocoder::cBinop_z3yo3WQc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JEs9WI0R_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ij6ZMFdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1U2adUuq, HV_BINOP_MULTIPLY, 1, m, &cBinop_1U2adUuq_sendMessage);
}

void Heavy_nts_vocoder::cBinop_1U2adUuq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_c9zHzsX4, 1, m);
}

void Heavy_nts_vocoder::cBinop_jYuz594r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vOJ5zWI2, HV_BINOP_DIVIDE, 1, m, &cBinop_vOJ5zWI2_sendMessage);
}

void Heavy_nts_vocoder::cBinop_1Ns4udC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UgQkn4ix_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ij6ZMFdj, HV_BINOP_ADD, 0, m, &cBinop_ij6ZMFdj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_4zg46two_sendMessage);
}

void Heavy_nts_vocoder::cMsg_oX6BrhwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kMjuIrAL_sendMessage);
}

void Heavy_nts_vocoder::cSystem_kMjuIrAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V6KVOzdL, HV_BINOP_DIVIDE, 1, m, &cBinop_V6KVOzdL_sendMessage);
}

void Heavy_nts_vocoder::cVar_VHd2yPaz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_3FFJU9QQ_sendMessage);
}

void Heavy_nts_vocoder::cVar_OSxrBbWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_aSm5KxIl_sendMessage);
}

void Heavy_nts_vocoder::cUnop_WUKx879b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ooQ9a81b_sendMessage);
}

void Heavy_nts_vocoder::cBinop_V6KVOzdL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sjvfqYEJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_sjvfqYEJ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_WUKx879b_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6qepHojt, HV_BINOP_DIVIDE, 0, m, &cBinop_6qepHojt_sendMessage);
}

void Heavy_nts_vocoder::cBinop_3FFJU9QQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V6KVOzdL, HV_BINOP_DIVIDE, 0, m, &cBinop_V6KVOzdL_sendMessage);
}

void Heavy_nts_vocoder::cBinop_6qepHojt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_0CjMsiCx_sendMessage);
}

void Heavy_nts_vocoder::cBinop_yEFuspP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TAj2LGSn_sendMessage);
}

void Heavy_nts_vocoder::cBinop_TAj2LGSn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_NyZLovHd_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nw8XYFV6, HV_BINOP_MULTIPLY, 0, m, &cBinop_nw8XYFV6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sjvfqYEJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_sjvfqYEJ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ooQ9a81b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nw8XYFV6, HV_BINOP_MULTIPLY, 1, m, &cBinop_nw8XYFV6_sendMessage);
}

void Heavy_nts_vocoder::cBinop_nw8XYFV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_CYxOtpdJ_sendMessage);
}

void Heavy_nts_vocoder::cCast_hc2rd4lp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VHd2yPaz, 0, m, &cVar_VHd2yPaz_sendMessage);
}

void Heavy_nts_vocoder::cBinop_kDTgFEQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_jRxG7nE0_sendMessage);
}

void Heavy_nts_vocoder::cBinop_jRxG7nE0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Yaah7e9o, 5, m);
}

void Heavy_nts_vocoder::cBinop_CYxOtpdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Yaah7e9o, 4, m);
}

void Heavy_nts_vocoder::cBinop_389ciYcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DS61Inet, HV_BINOP_MULTIPLY, 0, m, &cBinop_DS61Inet_sendMessage);
}

void Heavy_nts_vocoder::cBinop_sjvfqYEJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C3zZFymE, HV_BINOP_ADD, 1, m, &cBinop_C3zZFymE_sendMessage);
}

void Heavy_nts_vocoder::cBinop_NyZLovHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kDTgFEQZ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_C3zZFymE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DS61Inet, HV_BINOP_MULTIPLY, 1, m, &cBinop_DS61Inet_sendMessage);
}

void Heavy_nts_vocoder::cBinop_DS61Inet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Yaah7e9o, 1, m);
}

void Heavy_nts_vocoder::cBinop_aSm5KxIl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6qepHojt, HV_BINOP_DIVIDE, 1, m, &cBinop_6qepHojt_sendMessage);
}

void Heavy_nts_vocoder::cBinop_0CjMsiCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_yEFuspP0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_C3zZFymE, HV_BINOP_ADD, 0, m, &cBinop_C3zZFymE_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_389ciYcv_sendMessage);
}

void Heavy_nts_vocoder::cMsg_YsYKWfCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LBp0bkDi_sendMessage);
}

void Heavy_nts_vocoder::cSystem_LBp0bkDi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pRI03lPh, HV_BINOP_DIVIDE, 1, m, &cBinop_pRI03lPh_sendMessage);
}

void Heavy_nts_vocoder::cVar_nJKcvizr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_VxHDSOPJ_sendMessage);
}

void Heavy_nts_vocoder::cVar_rSyJZX93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_r3TVumSg_sendMessage);
}

void Heavy_nts_vocoder::cUnop_EWOTMliM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_qA9DfQp8_sendMessage);
}

void Heavy_nts_vocoder::cBinop_pRI03lPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DgBA51SH, HV_BINOP_MULTIPLY, 1, m, &cBinop_DgBA51SH_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_EWOTMliM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_meqOM5LE, HV_BINOP_DIVIDE, 0, m, &cBinop_meqOM5LE_sendMessage);
}

void Heavy_nts_vocoder::cBinop_VxHDSOPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pRI03lPh, HV_BINOP_DIVIDE, 0, m, &cBinop_pRI03lPh_sendMessage);
}

void Heavy_nts_vocoder::cBinop_meqOM5LE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zL0AWkO6_sendMessage);
}

void Heavy_nts_vocoder::cBinop_JD1PuZdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_kXQZBCtn_sendMessage);
}

void Heavy_nts_vocoder::cBinop_kXQZBCtn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_nXGBzMjs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_k2PaR3b5, HV_BINOP_MULTIPLY, 0, m, &cBinop_k2PaR3b5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DgBA51SH, HV_BINOP_MULTIPLY, 0, m, &cBinop_DgBA51SH_sendMessage);
}

void Heavy_nts_vocoder::cBinop_qA9DfQp8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_k2PaR3b5, HV_BINOP_MULTIPLY, 1, m, &cBinop_k2PaR3b5_sendMessage);
}

void Heavy_nts_vocoder::cBinop_k2PaR3b5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_o8XNGRBB_sendMessage);
}

void Heavy_nts_vocoder::cCast_fknY7vNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nJKcvizr, 0, m, &cVar_nJKcvizr_sendMessage);
}

void Heavy_nts_vocoder::cBinop_2KeXnAlv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_6VtmxjOo_sendMessage);
}

void Heavy_nts_vocoder::cBinop_6VtmxjOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_7a84oXwO, 5, m);
}

void Heavy_nts_vocoder::cBinop_o8XNGRBB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_7a84oXwO, 4, m);
}

void Heavy_nts_vocoder::cBinop_trzwDISy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ic1a0xVq, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ic1a0xVq_sendMessage);
}

void Heavy_nts_vocoder::cBinop_DgBA51SH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GS3C5le5, HV_BINOP_ADD, 1, m, &cBinop_GS3C5le5_sendMessage);
}

void Heavy_nts_vocoder::cBinop_nXGBzMjs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2KeXnAlv_sendMessage);
}

void Heavy_nts_vocoder::cBinop_GS3C5le5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ic1a0xVq, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ic1a0xVq_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Ic1a0xVq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_7a84oXwO, 1, m);
}

void Heavy_nts_vocoder::cBinop_r3TVumSg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_meqOM5LE, HV_BINOP_DIVIDE, 1, m, &cBinop_meqOM5LE_sendMessage);
}

void Heavy_nts_vocoder::cBinop_zL0AWkO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JD1PuZdV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GS3C5le5, HV_BINOP_ADD, 0, m, &cBinop_GS3C5le5_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_trzwDISy_sendMessage);
}

void Heavy_nts_vocoder::cBinop_6uhz7FGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_TyqUKcF4, 0, m);
}

void Heavy_nts_vocoder::cBinop_qlZVsBYH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_5yDhm8j3_sendMessage);
}

void Heavy_nts_vocoder::cBinop_5yDhm8j3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aY0YZric, HV_BINOP_POW, 1, m, &cBinop_aY0YZric_sendMessage);
  cMsg_OufwK34p_sendMessage(_c, 0, m);
}

void Heavy_nts_vocoder::cBinop_aY0YZric_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_6uhz7FGq_sendMessage);
}

void Heavy_nts_vocoder::cMsg_OufwK34p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aY0YZric, HV_BINOP_POW, 0, m, &cBinop_aY0YZric_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ACPsXYsq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_2BWpseBP, 0, m);
}

void Heavy_nts_vocoder::cBinop_VgbSvR4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_foI75SHZ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_foI75SHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3G0eyWi4, HV_BINOP_POW, 1, m, &cBinop_3G0eyWi4_sendMessage);
  cMsg_jGnecUmj_sendMessage(_c, 0, m);
}

void Heavy_nts_vocoder::cBinop_3G0eyWi4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_ACPsXYsq_sendMessage);
}

void Heavy_nts_vocoder::cMsg_jGnecUmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3G0eyWi4, HV_BINOP_POW, 0, m, &cBinop_3G0eyWi4_sendMessage);
}

void Heavy_nts_vocoder::cBinop_u2LXOFG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_FQ4HdbUX, 0, m);
}

void Heavy_nts_vocoder::cBinop_vAnI5KT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_RwlXo3Vy_sendMessage);
}

void Heavy_nts_vocoder::cBinop_RwlXo3Vy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XI1sIjgK, HV_BINOP_POW, 1, m, &cBinop_XI1sIjgK_sendMessage);
  cMsg_lh8ufqre_sendMessage(_c, 0, m);
}

void Heavy_nts_vocoder::cBinop_XI1sIjgK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_u2LXOFG3_sendMessage);
}

void Heavy_nts_vocoder::cMsg_lh8ufqre_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XI1sIjgK, HV_BINOP_POW, 0, m, &cBinop_XI1sIjgK_sendMessage);
}

void Heavy_nts_vocoder::cBinop_0qPn7AoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7Ys62vtT_sendMessage);
}

void Heavy_nts_vocoder::cBinop_7Ys62vtT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ZEG8Q5fA_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GWxJCpBu_sendMessage);
}

void Heavy_nts_vocoder::cVar_UD0Og7PA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_qSy4GYnl_sendMessage);
}

void Heavy_nts_vocoder::cMsg_pIIuqYmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_76vShnSW_sendMessage);
}

void Heavy_nts_vocoder::cSystem_76vShnSW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gIYPgdB7, HV_BINOP_DIVIDE, 1, m, &cBinop_gIYPgdB7_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ZEG8Q5fA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_AjgzkZT2_sendMessage);
}

void Heavy_nts_vocoder::cBinop_AjgzkZT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wNoUxERN, m);
}

void Heavy_nts_vocoder::cMsg_T8wviMua_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_KdoTW5lf_sendMessage);
}

void Heavy_nts_vocoder::cBinop_KdoTW5lf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_0qPn7AoE_sendMessage);
}

void Heavy_nts_vocoder::cBinop_GWxJCpBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LzAZPXmn, m);
}

void Heavy_nts_vocoder::cBinop_qSy4GYnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_rfvzxcBk_sendMessage);
}

void Heavy_nts_vocoder::cBinop_rfvzxcBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gIYPgdB7, HV_BINOP_DIVIDE, 0, m, &cBinop_gIYPgdB7_sendMessage);
}

void Heavy_nts_vocoder::cBinop_gIYPgdB7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_T8wviMua_sendMessage(_c, 0, m);
}

void Heavy_nts_vocoder::cBinop_Bmxy15Oz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kJM4UFmZ_sendMessage);
}

void Heavy_nts_vocoder::cBinop_kJM4UFmZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_QxiqUJuz_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OzCmd9zG_sendMessage);
}

void Heavy_nts_vocoder::cVar_B5DTpKpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_9XR0GMM5_sendMessage);
}

void Heavy_nts_vocoder::cMsg_A5TG3Dtt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kEbLLWFK_sendMessage);
}

void Heavy_nts_vocoder::cSystem_kEbLLWFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sfhy7CnS, HV_BINOP_DIVIDE, 1, m, &cBinop_Sfhy7CnS_sendMessage);
}

void Heavy_nts_vocoder::cBinop_QxiqUJuz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_TBQJIu8x_sendMessage);
}

void Heavy_nts_vocoder::cBinop_TBQJIu8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cx7tlUDE, m);
}

void Heavy_nts_vocoder::cMsg_tC4EAthy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ZXexVN5R_sendMessage);
}

void Heavy_nts_vocoder::cBinop_ZXexVN5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Bmxy15Oz_sendMessage);
}

void Heavy_nts_vocoder::cBinop_OzCmd9zG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_N3bkA1MG, m);
}

void Heavy_nts_vocoder::cBinop_9XR0GMM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_d6iG1rE3_sendMessage);
}

void Heavy_nts_vocoder::cBinop_d6iG1rE3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sfhy7CnS, HV_BINOP_DIVIDE, 0, m, &cBinop_Sfhy7CnS_sendMessage);
}

void Heavy_nts_vocoder::cBinop_Sfhy7CnS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tC4EAthy_sendMessage(_c, 0, m);
}

void Heavy_nts_vocoder::cBinop_dGhzEafU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_VgbSvR4v_sendMessage);
}

void Heavy_nts_vocoder::cBinop_PzTVzpQX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_vAnI5KT0_sendMessage);
}

void Heavy_nts_vocoder::cReceive_da7UeMHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gpTajKTe, m);
}

void Heavy_nts_vocoder::cReceive_OV5w9tcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZtK2XUZM, 0, m, &cVar_ZtK2XUZM_sendMessage);
  cMsg_N8u3aPmG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pEPcWenB, 0, m, &cVar_pEPcWenB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_77cIuFbF, 0, m, &cVar_77cIuFbF_sendMessage);
  cMsg_BfxZx84F_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Mh765JU3, 0, m, &cVar_Mh765JU3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NY7HjhqW, 0, m, &cVar_NY7HjhqW_sendMessage);
  cMsg_80rwU1tm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ujt0DdPc, 0, m, &cVar_ujt0DdPc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_snnWnZnp, 0, m, &cVar_snnWnZnp_sendMessage);
  cMsg_cbACvuvd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3gROEItu, 0, m, &cVar_3gROEItu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_a3QAVfqM, 0, m, &cVar_a3QAVfqM_sendMessage);
  cMsg_SWhbKBBO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3YMbSH3T, 0, m, &cVar_3YMbSH3T_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GF7ZW658, 0, m, &cVar_GF7ZW658_sendMessage);
  cMsg_NjdxvhHs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nYdcMWdl, 0, m, &cVar_nYdcMWdl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_w3i8BPsh, 0, m, &cVar_w3i8BPsh_sendMessage);
  cMsg_qYpmwohD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3qjTHw2q, 0, m, &cVar_3qjTHw2q_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qu9uKa9J, 0, m, &cVar_qu9uKa9J_sendMessage);
  cMsg_RyBGVACH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YpCSdxAp, 0, m, &cVar_YpCSdxAp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_v7IGrzEE, 0, m, &cVar_v7IGrzEE_sendMessage);
  cMsg_g0bmTF3h_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cAx9ao5D, 0, m, &cVar_cAx9ao5D_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_akZtvAOi, 0, m, &cVar_akZtvAOi_sendMessage);
  cMsg_Rs4omhpk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1VO50FOo, 0, m, &cVar_1VO50FOo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pzCS51hG, 0, m, &cVar_pzCS51hG_sendMessage);
  cMsg_lgE32lmn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OOEBLOML, 0, m, &cVar_OOEBLOML_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zddVLVYc, 0, m, &cVar_zddVLVYc_sendMessage);
  cMsg_A4m7NXub_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1itXEmBP, 0, m, &cVar_1itXEmBP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OSxrBbWZ, 0, m, &cVar_OSxrBbWZ_sendMessage);
  cMsg_oX6BrhwR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VHd2yPaz, 0, m, &cVar_VHd2yPaz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rSyJZX93, 0, m, &cVar_rSyJZX93_sendMessage);
  cMsg_YsYKWfCf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nJKcvizr, 0, m, &cVar_nJKcvizr_sendMessage);
  cMsg_pIIuqYmJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_UD0Og7PA, 0, m, &cVar_UD0Og7PA_sendMessage);
  cMsg_A5TG3Dtt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_B5DTpKpN, 0, m, &cVar_B5DTpKpN_sendMessage);
}

void Heavy_nts_vocoder::cReceive_DR6sEOfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_qlZVsBYH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dGhzEafU, HV_BINOP_ADD, 0, m, &cBinop_dGhzEafU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PzTVzpQX, HV_BINOP_ADD, 0, m, &cBinop_PzTVzpQX_sendMessage);
}

void Heavy_nts_vocoder::cReceive_VatNf6Xr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kLefpNOA, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_MDdjG5Bf, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jXXV6oTJ, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gObobFff, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_D22hLhZj, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9eBBhtvh, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_4nr4pIBJ, m);
}

void Heavy_nts_vocoder::cReceive_F8nEHCaa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PzTVzpQX, HV_BINOP_ADD, 1, m, &cBinop_PzTVzpQX_sendMessage);
}

void Heavy_nts_vocoder::cReceive_csctOATt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dGhzEafU, HV_BINOP_ADD, 1, m, &cBinop_dGhzEafU_sendMessage);
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
    __hv_varread_f(&sVarf_gpTajKTe, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_TyqUKcF4, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_FQ4HdbUX, VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_2BWpseBP, VOf(Bf0));
    __hv_add_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_MIKN1w6h, VIf(Bf2), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_6roDtkdV, VIf(Bf1), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_z3S3ozJC, VOf(Bf4));
    __hv_varread_f(&sVarf_kLefpNOA, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_max_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_z3S3ozJC, VIf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_Pul7K8MO, VIf(Bf2), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_Y8F4Omt0, VIf(Bf1), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_sqXWapVX, VOf(Bf4));
    __hv_varread_f(&sVarf_MDdjG5Bf, VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_max_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_f(&sVarf_sqXWapVX, VIf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_biquad_k_f(&sBiquad_k_YqjRNmpx, VIf(Bf2), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_WD9b28V9, VIf(Bf1), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_1Q1yRVo5, VOf(Bf3));
    __hv_varread_f(&sVarf_jXXV6oTJ, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_max_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_1Q1yRVo5, VIf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_uyNKa9ek, VIf(Bf2), VOf(Bf6));
    __hv_biquad_k_f(&sBiquad_k_hloqrH1u, VIf(Bf1), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_55TnijGx, VOf(Bf0));
    __hv_varread_f(&sVarf_gObobFff, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_max_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_55TnijGx, VIf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_biquad_k_f(&sBiquad_k_sKFl40ow, VIf(Bf2), VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_PHTi9Kcn, VIf(Bf1), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_hiI57TiC, VOf(Bf5));
    __hv_varread_f(&sVarf_D22hLhZj, VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_max_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_hiI57TiC, VIf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_c9zHzsX4, VIf(Bf2), VOf(Bf3));
    __hv_biquad_k_f(&sBiquad_k_dALE1Rm6, VIf(Bf1), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_GRsdf6Xz, VOf(Bf6));
    __hv_varread_f(&sVarf_9eBBhtvh, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_max_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_GRsdf6Xz, VIf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_7a84oXwO, VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_Yaah7e9o, VIf(Bf1), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_6Xdve5R2, VOf(Bf3));
    __hv_varread_f(&sVarf_4nr4pIBJ, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_max_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_6Xdve5R2, VIf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f);
    __hv_varread_f(&sVarf_LzAZPXmn, VOf(Bf2));
    __hv_rpole_f(&sRPole_i99l2KSf, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_kcSQuRzn, VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_wNoUxERN, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_N3bkA1MG, VOf(Bf1));
    __hv_rpole_f(&sRPole_n8Y1iZ2E, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_3ObEjSOR, VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_cx7tlUDE, VOf(Bf1));
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
