/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside vocoder.pd) */

#include "Heavy_vocoder.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_vocoder *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_vocoder_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_vocoder));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_vocoder(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_vocoder_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_vocoder));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_vocoder(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_vocoder_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_vocoder();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_vocoder::Heavy_vocoder(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_9q1ZdE84, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_EilbAabD, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_oJoZ7Zvz, 0.0f, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_RAhWJhQc, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_k54u1RIk, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_RW5nDd6o, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_9RtxEjFB, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_CBeZBII0, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_w9oP6xYp, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_SLjtBVVo, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_HTuni816, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_mROPvisw, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_aoh1TRre, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_XyrhmZBj, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_JTdGbt2k, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_LVOeTib2, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_uXZunACf, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sRPole_init(&sRPole_EiFzmpKv);
  numBytes += sDel1_init(&sDel1_6BwPm6wX);
  numBytes += sRPole_init(&sRPole_JFaaVQSG);
  numBytes += sDel1_init(&sDel1_BYXpNMyk);
  numBytes += sVarf_init(&sVarf_8moTHL01, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_b3DQ7g8U, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_1MH9aAsR, 267.0f);
  numBytes += cVar_init_f(&cVar_jY2u1uER, 15.0f);
  numBytes += cBinop_init(&cBinop_DBGAiCwz, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_hWtt4OJI, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_TzydkR3x, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_hPimEKDN, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_spxZtnwR, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_OPVIjooj, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_YBtGG8Ly, 267.0f);
  numBytes += cVar_init_f(&cVar_8FxFjjxe, 15.0f);
  numBytes += cBinop_init(&cBinop_H2LobO6y, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_NGB4Hdet, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_8eGMJQNK, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_bLTmZ4K7, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_JyK8IFbH, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_EYPU1chN, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_rpbLp9wv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ibb9jVox, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_hKsz1oGb, 444.0f);
  numBytes += cVar_init_f(&cVar_xH7FmwtW, 15.0f);
  numBytes += cBinop_init(&cBinop_q5XZVlkp, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_xiZ2hkp4, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_bQVdo3Ur, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_xwger5YF, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_6QNMOw95, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_uQYCzjEp, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_3FyWEJSd, 444.0f);
  numBytes += cVar_init_f(&cVar_DKydOBpR, 15.0f);
  numBytes += cBinop_init(&cBinop_E2lfOpUP, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_3lGBxzhA, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_KzwfIjOi, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_GLxR6rw3, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_YTVfojLZ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_8yJdq6zI, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_dMkww6hL, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Mhbq3btS, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_wYgMid53, 741.0f);
  numBytes += cVar_init_f(&cVar_zZQSp3TM, 15.0f);
  numBytes += cBinop_init(&cBinop_Vu5JZxTk, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_b2EYkTJQ, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_TagAonu1, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_OXiDl6vo, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_RPWb6Yix, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_OLs6tVWW, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_p5fkXMXf, 741.0f);
  numBytes += cVar_init_f(&cVar_8VgFDDCS, 15.0f);
  numBytes += cBinop_init(&cBinop_WnAQuYtT, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_59360HY6, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_DbP4l4fX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_7NHHAgA0, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_aQ1aWGLi, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_K7xOLYXx, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_OdvBxV7s, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_djmIUyuF, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_54v5ZvjB, 1235.0f);
  numBytes += cVar_init_f(&cVar_OVtfa3AG, 15.0f);
  numBytes += cBinop_init(&cBinop_B2vyEhrA, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_rswq2VSV, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_wy0gNNB7, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_8U7pfXFe, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_bvKS7JCJ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Tmv0lcDH, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_phr1Kdp4, 1235.0f);
  numBytes += cVar_init_f(&cVar_X2Ct84GP, 15.0f);
  numBytes += cBinop_init(&cBinop_zo0yGUf0, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_mSC4YUPr, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_jmxQNc5h, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_oS7DUwo8, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_6ISjLfiI, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_1HLFFvM6, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Srze7Gvx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OKTC9Id8, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_sDY7u73b, 2058.0f);
  numBytes += cVar_init_f(&cVar_GxAYYuuc, 15.0f);
  numBytes += cBinop_init(&cBinop_hTvZCjgg, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ZJpAmB6Z, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_0q9aNLRJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_nxrM6s7N, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_hypKlxBy, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_AEZY6SWH, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_D72FiIaV, 2058.0f);
  numBytes += cVar_init_f(&cVar_giQ43rTf, 15.0f);
  numBytes += cBinop_init(&cBinop_gZIopxJi, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_acDmXC29, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_pNUphn3s, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_HB7G6Fxg, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_oWSUO7a0, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ImmMpfO3, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_5CFQBnMb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_oAj7HR84, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_fRegSoiG, 3429.0f);
  numBytes += cVar_init_f(&cVar_1VFgCRoI, 15.0f);
  numBytes += cBinop_init(&cBinop_QcJAPfd2, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_0hOyFRfr, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_XXVhCV16, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_FLYnobm3, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_nyrZSBUS, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_UQZNSHN0, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_BwnyXlun, 3429.0f);
  numBytes += cVar_init_f(&cVar_kvwOLajW, 15.0f);
  numBytes += cBinop_init(&cBinop_foozmwKT, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_LNwGJDNo, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_y0ds0Z3g, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_TPDwcvnh, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_tkFEd6VL, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_6XkjZTVb, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_8IAkqFcd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_oW87R61V, 0.97f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_iHMQwIRm, 5716.0f);
  numBytes += cVar_init_f(&cVar_Ic2EVZxw, 15.0f);
  numBytes += cBinop_init(&cBinop_s8ii0ujT, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_cHZZuOkj, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_OLrd6reV, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_iAkG6Lb9, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_FVSu7JAh, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_GTA8T9yT, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_r8Bm9vNB, 5716.0f);
  numBytes += cVar_init_f(&cVar_xBiX9dCH, 15.0f);
  numBytes += cBinop_init(&cBinop_48W7DeFg, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_YPO1Twu8, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_oOy8e2gj, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_2dYXPXZj, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_JUrRaNfB, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_SZ9mcg2T, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_MuAvEWLQ, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_suUeG7jg, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_LAhHjA2S, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_LuIvqAvN, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_smaIRmra, 10000.0f);
  numBytes += cBinop_init(&cBinop_UuSsqiRs, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_d0MvF8KC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PghmdXTB, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YumI8Qpw, 10000.0f);
  numBytes += cBinop_init(&cBinop_wJ9zHa0l, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_FU0bLcFc, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_1DCo1r5G, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_NgWVP8pG, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_isQJsbIN, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eNQN1kZ6_sendMessage);
      break;
    }
    case 0x6C87328F: { // alt_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_127Xkw7a_sendMessage);
      break;
    }
    case 0x3FD8ECD5: { // note1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xQgTZlOZ_sendMessage);
      break;
    }
    case 0x97165D01: { // note2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DyoViuig_sendMessage);
      break;
    }
    case 0xA23B621F: { // pitch_note
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5IdUN8vA_sendMessage);
      break;
    }
    case 0xCE9531B0: { // shape_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_m0WejA4M_sendMessage);
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


void Heavy_vocoder::cMsg_n0AHsaaN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_g7BEDMnq_sendMessage);
}

void Heavy_vocoder::cSystem_g7BEDMnq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DBGAiCwz, HV_BINOP_DIVIDE, 1, m, &cBinop_DBGAiCwz_sendMessage);
}

void Heavy_vocoder::cVar_1MH9aAsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_QgT2QToB_sendMessage);
}

void Heavy_vocoder::cVar_jY2u1uER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_c13XwFz6_sendMessage);
}

void Heavy_vocoder::cUnop_y0ENSzrL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ZBi3JidX_sendMessage);
}

void Heavy_vocoder::cBinop_DBGAiCwz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hPimEKDN, HV_BINOP_MULTIPLY, 1, m, &cBinop_hPimEKDN_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_y0ENSzrL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hWtt4OJI, HV_BINOP_DIVIDE, 0, m, &cBinop_hWtt4OJI_sendMessage);
}

void Heavy_vocoder::cBinop_QgT2QToB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DBGAiCwz, HV_BINOP_DIVIDE, 0, m, &cBinop_DBGAiCwz_sendMessage);
}

void Heavy_vocoder::cBinop_hWtt4OJI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_RS0xMw1i_sendMessage);
}

void Heavy_vocoder::cBinop_VCaThyXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_MPoARxi7_sendMessage);
}

void Heavy_vocoder::cBinop_MPoARxi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_vTVErlut_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TzydkR3x, HV_BINOP_MULTIPLY, 0, m, &cBinop_TzydkR3x_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hPimEKDN, HV_BINOP_MULTIPLY, 0, m, &cBinop_hPimEKDN_sendMessage);
}

void Heavy_vocoder::cBinop_ZBi3JidX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TzydkR3x, HV_BINOP_MULTIPLY, 1, m, &cBinop_TzydkR3x_sendMessage);
}

void Heavy_vocoder::cBinop_TzydkR3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xAiBkos2_sendMessage);
}

void Heavy_vocoder::cCast_I0XCblZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1MH9aAsR, 0, m, &cVar_1MH9aAsR_sendMessage);
}

void Heavy_vocoder::cBinop_jNOYlQxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nK4T6tnl_sendMessage);
}

void Heavy_vocoder::cBinop_nK4T6tnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_k54u1RIk, 5, m);
}

void Heavy_vocoder::cBinop_xAiBkos2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_k54u1RIk, 4, m);
}

void Heavy_vocoder::cBinop_5butugKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OPVIjooj, HV_BINOP_MULTIPLY, 0, m, &cBinop_OPVIjooj_sendMessage);
}

void Heavy_vocoder::cBinop_hPimEKDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_spxZtnwR, HV_BINOP_ADD, 1, m, &cBinop_spxZtnwR_sendMessage);
}

void Heavy_vocoder::cBinop_vTVErlut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_jNOYlQxm_sendMessage);
}

void Heavy_vocoder::cBinop_spxZtnwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OPVIjooj, HV_BINOP_MULTIPLY, 1, m, &cBinop_OPVIjooj_sendMessage);
}

void Heavy_vocoder::cBinop_OPVIjooj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_k54u1RIk, 1, m);
}

void Heavy_vocoder::cBinop_c13XwFz6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hWtt4OJI, HV_BINOP_DIVIDE, 1, m, &cBinop_hWtt4OJI_sendMessage);
}

void Heavy_vocoder::cBinop_RS0xMw1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VCaThyXs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_spxZtnwR, HV_BINOP_ADD, 0, m, &cBinop_spxZtnwR_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_5butugKw_sendMessage);
}

void Heavy_vocoder::cMsg_EmAmno2l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cYd9mN8r_sendMessage);
}

void Heavy_vocoder::cSystem_cYd9mN8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H2LobO6y, HV_BINOP_DIVIDE, 1, m, &cBinop_H2LobO6y_sendMessage);
}

void Heavy_vocoder::cVar_YBtGG8Ly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_Id1Vexsg_sendMessage);
}

void Heavy_vocoder::cVar_8FxFjjxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_ALenqQU4_sendMessage);
}

void Heavy_vocoder::cUnop_qtZDmm9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_Xtaxxc3P_sendMessage);
}

void Heavy_vocoder::cBinop_H2LobO6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bLTmZ4K7, HV_BINOP_MULTIPLY, 1, m, &cBinop_bLTmZ4K7_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_qtZDmm9w_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NGB4Hdet, HV_BINOP_DIVIDE, 0, m, &cBinop_NGB4Hdet_sendMessage);
}

void Heavy_vocoder::cBinop_Id1Vexsg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H2LobO6y, HV_BINOP_DIVIDE, 0, m, &cBinop_H2LobO6y_sendMessage);
}

void Heavy_vocoder::cBinop_NGB4Hdet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_dgmDscRQ_sendMessage);
}

void Heavy_vocoder::cBinop_UtLb8qlf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_FotymqBW_sendMessage);
}

void Heavy_vocoder::cBinop_FotymqBW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_9eQw2Vsz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8eGMJQNK, HV_BINOP_MULTIPLY, 0, m, &cBinop_8eGMJQNK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bLTmZ4K7, HV_BINOP_MULTIPLY, 0, m, &cBinop_bLTmZ4K7_sendMessage);
}

void Heavy_vocoder::cBinop_Xtaxxc3P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8eGMJQNK, HV_BINOP_MULTIPLY, 1, m, &cBinop_8eGMJQNK_sendMessage);
}

void Heavy_vocoder::cBinop_8eGMJQNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FhyVagpG_sendMessage);
}

void Heavy_vocoder::cCast_Jyjae6jS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YBtGG8Ly, 0, m, &cVar_YBtGG8Ly_sendMessage);
}

void Heavy_vocoder::cBinop_jGmbZqFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RgGElyTu_sendMessage);
}

void Heavy_vocoder::cBinop_RgGElyTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_RAhWJhQc, 5, m);
}

void Heavy_vocoder::cBinop_FhyVagpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_RAhWJhQc, 4, m);
}

void Heavy_vocoder::cBinop_joVT3rQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EYPU1chN, HV_BINOP_MULTIPLY, 0, m, &cBinop_EYPU1chN_sendMessage);
}

void Heavy_vocoder::cBinop_bLTmZ4K7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JyK8IFbH, HV_BINOP_ADD, 1, m, &cBinop_JyK8IFbH_sendMessage);
}

void Heavy_vocoder::cBinop_9eQw2Vsz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_jGmbZqFs_sendMessage);
}

void Heavy_vocoder::cBinop_JyK8IFbH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EYPU1chN, HV_BINOP_MULTIPLY, 1, m, &cBinop_EYPU1chN_sendMessage);
}

void Heavy_vocoder::cBinop_EYPU1chN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_RAhWJhQc, 1, m);
}

void Heavy_vocoder::cBinop_ALenqQU4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NGB4Hdet, HV_BINOP_DIVIDE, 1, m, &cBinop_NGB4Hdet_sendMessage);
}

void Heavy_vocoder::cBinop_dgmDscRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UtLb8qlf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JyK8IFbH, HV_BINOP_ADD, 0, m, &cBinop_JyK8IFbH_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_joVT3rQM_sendMessage);
}

void Heavy_vocoder::cMsg_yvBf2h4G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NNxxr9nE_sendMessage);
}

void Heavy_vocoder::cSystem_NNxxr9nE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q5XZVlkp, HV_BINOP_DIVIDE, 1, m, &cBinop_q5XZVlkp_sendMessage);
}

void Heavy_vocoder::cVar_hKsz1oGb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_L9q7O351_sendMessage);
}

void Heavy_vocoder::cVar_xH7FmwtW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_zcfjxIWx_sendMessage);
}

void Heavy_vocoder::cUnop_wFlCerNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_5HQvLNZ6_sendMessage);
}

void Heavy_vocoder::cBinop_q5XZVlkp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xwger5YF, HV_BINOP_MULTIPLY, 1, m, &cBinop_xwger5YF_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_wFlCerNv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xiZ2hkp4, HV_BINOP_DIVIDE, 0, m, &cBinop_xiZ2hkp4_sendMessage);
}

void Heavy_vocoder::cBinop_L9q7O351_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q5XZVlkp, HV_BINOP_DIVIDE, 0, m, &cBinop_q5XZVlkp_sendMessage);
}

void Heavy_vocoder::cBinop_xiZ2hkp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_g22C54G6_sendMessage);
}

void Heavy_vocoder::cBinop_IPFpD8Es_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_lgRv6IE1_sendMessage);
}

void Heavy_vocoder::cBinop_lgRv6IE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_djt4mH9P_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bQVdo3Ur, HV_BINOP_MULTIPLY, 0, m, &cBinop_bQVdo3Ur_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xwger5YF, HV_BINOP_MULTIPLY, 0, m, &cBinop_xwger5YF_sendMessage);
}

void Heavy_vocoder::cBinop_5HQvLNZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bQVdo3Ur, HV_BINOP_MULTIPLY, 1, m, &cBinop_bQVdo3Ur_sendMessage);
}

void Heavy_vocoder::cBinop_bQVdo3Ur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0AnrbHil_sendMessage);
}

void Heavy_vocoder::cCast_twUcQw7U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hKsz1oGb, 0, m, &cVar_hKsz1oGb_sendMessage);
}

void Heavy_vocoder::cBinop_d339R6jX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_hmgUuJvG_sendMessage);
}

void Heavy_vocoder::cBinop_hmgUuJvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_9RtxEjFB, 5, m);
}

void Heavy_vocoder::cBinop_0AnrbHil_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_9RtxEjFB, 4, m);
}

void Heavy_vocoder::cBinop_gOXmJHlE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uQYCzjEp, HV_BINOP_MULTIPLY, 0, m, &cBinop_uQYCzjEp_sendMessage);
}

void Heavy_vocoder::cBinop_xwger5YF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6QNMOw95, HV_BINOP_ADD, 1, m, &cBinop_6QNMOw95_sendMessage);
}

void Heavy_vocoder::cBinop_djt4mH9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_d339R6jX_sendMessage);
}

void Heavy_vocoder::cBinop_6QNMOw95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uQYCzjEp, HV_BINOP_MULTIPLY, 1, m, &cBinop_uQYCzjEp_sendMessage);
}

void Heavy_vocoder::cBinop_uQYCzjEp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_9RtxEjFB, 1, m);
}

void Heavy_vocoder::cBinop_zcfjxIWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xiZ2hkp4, HV_BINOP_DIVIDE, 1, m, &cBinop_xiZ2hkp4_sendMessage);
}

void Heavy_vocoder::cBinop_g22C54G6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_IPFpD8Es_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6QNMOw95, HV_BINOP_ADD, 0, m, &cBinop_6QNMOw95_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_gOXmJHlE_sendMessage);
}

void Heavy_vocoder::cMsg_IAYcEqtL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5uT6Z7qp_sendMessage);
}

void Heavy_vocoder::cSystem_5uT6Z7qp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E2lfOpUP, HV_BINOP_DIVIDE, 1, m, &cBinop_E2lfOpUP_sendMessage);
}

void Heavy_vocoder::cVar_3FyWEJSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_jLXED4eD_sendMessage);
}

void Heavy_vocoder::cVar_DKydOBpR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_oLfpaJrf_sendMessage);
}

void Heavy_vocoder::cUnop_ziSoEWIo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ZEg3CVwv_sendMessage);
}

void Heavy_vocoder::cBinop_E2lfOpUP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GLxR6rw3, HV_BINOP_MULTIPLY, 1, m, &cBinop_GLxR6rw3_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_ziSoEWIo_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3lGBxzhA, HV_BINOP_DIVIDE, 0, m, &cBinop_3lGBxzhA_sendMessage);
}

void Heavy_vocoder::cBinop_jLXED4eD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E2lfOpUP, HV_BINOP_DIVIDE, 0, m, &cBinop_E2lfOpUP_sendMessage);
}

void Heavy_vocoder::cBinop_3lGBxzhA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_XMWxTdxe_sendMessage);
}

void Heavy_vocoder::cBinop_7fImawBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_OVC55WzA_sendMessage);
}

void Heavy_vocoder::cBinop_OVC55WzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_Xyl4P95R_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KzwfIjOi, HV_BINOP_MULTIPLY, 0, m, &cBinop_KzwfIjOi_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GLxR6rw3, HV_BINOP_MULTIPLY, 0, m, &cBinop_GLxR6rw3_sendMessage);
}

void Heavy_vocoder::cBinop_ZEg3CVwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KzwfIjOi, HV_BINOP_MULTIPLY, 1, m, &cBinop_KzwfIjOi_sendMessage);
}

void Heavy_vocoder::cBinop_KzwfIjOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RmQL8r6Y_sendMessage);
}

void Heavy_vocoder::cCast_JgEHd22N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3FyWEJSd, 0, m, &cVar_3FyWEJSd_sendMessage);
}

void Heavy_vocoder::cBinop_iDY3eOQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RNKKnQEb_sendMessage);
}

void Heavy_vocoder::cBinop_RNKKnQEb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_RW5nDd6o, 5, m);
}

void Heavy_vocoder::cBinop_RmQL8r6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_RW5nDd6o, 4, m);
}

void Heavy_vocoder::cBinop_6jTWwDhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8yJdq6zI, HV_BINOP_MULTIPLY, 0, m, &cBinop_8yJdq6zI_sendMessage);
}

void Heavy_vocoder::cBinop_GLxR6rw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YTVfojLZ, HV_BINOP_ADD, 1, m, &cBinop_YTVfojLZ_sendMessage);
}

void Heavy_vocoder::cBinop_Xyl4P95R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_iDY3eOQF_sendMessage);
}

void Heavy_vocoder::cBinop_YTVfojLZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8yJdq6zI, HV_BINOP_MULTIPLY, 1, m, &cBinop_8yJdq6zI_sendMessage);
}

void Heavy_vocoder::cBinop_8yJdq6zI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_RW5nDd6o, 1, m);
}

void Heavy_vocoder::cBinop_oLfpaJrf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3lGBxzhA, HV_BINOP_DIVIDE, 1, m, &cBinop_3lGBxzhA_sendMessage);
}

void Heavy_vocoder::cBinop_XMWxTdxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7fImawBx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YTVfojLZ, HV_BINOP_ADD, 0, m, &cBinop_YTVfojLZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_6jTWwDhs_sendMessage);
}

void Heavy_vocoder::cMsg_bbMt2bgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sWYhET5K_sendMessage);
}

void Heavy_vocoder::cSystem_sWYhET5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vu5JZxTk, HV_BINOP_DIVIDE, 1, m, &cBinop_Vu5JZxTk_sendMessage);
}

void Heavy_vocoder::cVar_wYgMid53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_AXKiM5Vr_sendMessage);
}

void Heavy_vocoder::cVar_zZQSp3TM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_h64rVgUx_sendMessage);
}

void Heavy_vocoder::cUnop_wEWHbU9m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_spcyqXUi_sendMessage);
}

void Heavy_vocoder::cBinop_Vu5JZxTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OXiDl6vo, HV_BINOP_MULTIPLY, 1, m, &cBinop_OXiDl6vo_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_wEWHbU9m_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_b2EYkTJQ, HV_BINOP_DIVIDE, 0, m, &cBinop_b2EYkTJQ_sendMessage);
}

void Heavy_vocoder::cBinop_AXKiM5Vr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vu5JZxTk, HV_BINOP_DIVIDE, 0, m, &cBinop_Vu5JZxTk_sendMessage);
}

void Heavy_vocoder::cBinop_b2EYkTJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_0coyjIbj_sendMessage);
}

void Heavy_vocoder::cBinop_0kb02F8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_CvOx9hXf_sendMessage);
}

void Heavy_vocoder::cBinop_CvOx9hXf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_xlBGho9N_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TagAonu1, HV_BINOP_MULTIPLY, 0, m, &cBinop_TagAonu1_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OXiDl6vo, HV_BINOP_MULTIPLY, 0, m, &cBinop_OXiDl6vo_sendMessage);
}

void Heavy_vocoder::cBinop_spcyqXUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TagAonu1, HV_BINOP_MULTIPLY, 1, m, &cBinop_TagAonu1_sendMessage);
}

void Heavy_vocoder::cBinop_TagAonu1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DsuZfRTz_sendMessage);
}

void Heavy_vocoder::cCast_tkwVSXnU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wYgMid53, 0, m, &cVar_wYgMid53_sendMessage);
}

void Heavy_vocoder::cBinop_64c7a832_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Lc0Tz6ey_sendMessage);
}

void Heavy_vocoder::cBinop_Lc0Tz6ey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_w9oP6xYp, 5, m);
}

void Heavy_vocoder::cBinop_DsuZfRTz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_w9oP6xYp, 4, m);
}

void Heavy_vocoder::cBinop_u31kJud4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OLs6tVWW, HV_BINOP_MULTIPLY, 0, m, &cBinop_OLs6tVWW_sendMessage);
}

void Heavy_vocoder::cBinop_OXiDl6vo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RPWb6Yix, HV_BINOP_ADD, 1, m, &cBinop_RPWb6Yix_sendMessage);
}

void Heavy_vocoder::cBinop_xlBGho9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_64c7a832_sendMessage);
}

void Heavy_vocoder::cBinop_RPWb6Yix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OLs6tVWW, HV_BINOP_MULTIPLY, 1, m, &cBinop_OLs6tVWW_sendMessage);
}

void Heavy_vocoder::cBinop_OLs6tVWW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_w9oP6xYp, 1, m);
}

void Heavy_vocoder::cBinop_h64rVgUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b2EYkTJQ, HV_BINOP_DIVIDE, 1, m, &cBinop_b2EYkTJQ_sendMessage);
}

void Heavy_vocoder::cBinop_0coyjIbj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0kb02F8T_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RPWb6Yix, HV_BINOP_ADD, 0, m, &cBinop_RPWb6Yix_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_u31kJud4_sendMessage);
}

void Heavy_vocoder::cMsg_1NYt3pHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fNsEXRtn_sendMessage);
}

void Heavy_vocoder::cSystem_fNsEXRtn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WnAQuYtT, HV_BINOP_DIVIDE, 1, m, &cBinop_WnAQuYtT_sendMessage);
}

void Heavy_vocoder::cVar_p5fkXMXf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_xFKFQPf3_sendMessage);
}

void Heavy_vocoder::cVar_8VgFDDCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_PX8VwePK_sendMessage);
}

void Heavy_vocoder::cUnop_ohwsbhWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_iUL8HvNl_sendMessage);
}

void Heavy_vocoder::cBinop_WnAQuYtT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7NHHAgA0, HV_BINOP_MULTIPLY, 1, m, &cBinop_7NHHAgA0_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_ohwsbhWH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_59360HY6, HV_BINOP_DIVIDE, 0, m, &cBinop_59360HY6_sendMessage);
}

void Heavy_vocoder::cBinop_xFKFQPf3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WnAQuYtT, HV_BINOP_DIVIDE, 0, m, &cBinop_WnAQuYtT_sendMessage);
}

void Heavy_vocoder::cBinop_59360HY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_MbSxnegn_sendMessage);
}

void Heavy_vocoder::cBinop_LLLSVWtn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_o6CwO1QX_sendMessage);
}

void Heavy_vocoder::cBinop_o6CwO1QX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_AQnbrwZQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DbP4l4fX, HV_BINOP_MULTIPLY, 0, m, &cBinop_DbP4l4fX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7NHHAgA0, HV_BINOP_MULTIPLY, 0, m, &cBinop_7NHHAgA0_sendMessage);
}

void Heavy_vocoder::cBinop_iUL8HvNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DbP4l4fX, HV_BINOP_MULTIPLY, 1, m, &cBinop_DbP4l4fX_sendMessage);
}

void Heavy_vocoder::cBinop_DbP4l4fX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_IYF7w0EY_sendMessage);
}

void Heavy_vocoder::cCast_0lJtptEU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_p5fkXMXf, 0, m, &cVar_p5fkXMXf_sendMessage);
}

void Heavy_vocoder::cBinop_GbuiiUwL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dQ4s01ub_sendMessage);
}

void Heavy_vocoder::cBinop_dQ4s01ub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_CBeZBII0, 5, m);
}

void Heavy_vocoder::cBinop_IYF7w0EY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_CBeZBII0, 4, m);
}

void Heavy_vocoder::cBinop_98scgt0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K7xOLYXx, HV_BINOP_MULTIPLY, 0, m, &cBinop_K7xOLYXx_sendMessage);
}

void Heavy_vocoder::cBinop_7NHHAgA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aQ1aWGLi, HV_BINOP_ADD, 1, m, &cBinop_aQ1aWGLi_sendMessage);
}

void Heavy_vocoder::cBinop_AQnbrwZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GbuiiUwL_sendMessage);
}

void Heavy_vocoder::cBinop_aQ1aWGLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K7xOLYXx, HV_BINOP_MULTIPLY, 1, m, &cBinop_K7xOLYXx_sendMessage);
}

void Heavy_vocoder::cBinop_K7xOLYXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_CBeZBII0, 1, m);
}

void Heavy_vocoder::cBinop_PX8VwePK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_59360HY6, HV_BINOP_DIVIDE, 1, m, &cBinop_59360HY6_sendMessage);
}

void Heavy_vocoder::cBinop_MbSxnegn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_LLLSVWtn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aQ1aWGLi, HV_BINOP_ADD, 0, m, &cBinop_aQ1aWGLi_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_98scgt0J_sendMessage);
}

void Heavy_vocoder::cMsg_oOkWL6dc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CazU4KiM_sendMessage);
}

void Heavy_vocoder::cSystem_CazU4KiM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B2vyEhrA, HV_BINOP_DIVIDE, 1, m, &cBinop_B2vyEhrA_sendMessage);
}

void Heavy_vocoder::cVar_54v5ZvjB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_UeEVtrNI_sendMessage);
}

void Heavy_vocoder::cVar_OVtfa3AG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_TttxssXj_sendMessage);
}

void Heavy_vocoder::cUnop_Qkg1k6gk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_qqNFfm0n_sendMessage);
}

void Heavy_vocoder::cBinop_B2vyEhrA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8U7pfXFe, HV_BINOP_MULTIPLY, 1, m, &cBinop_8U7pfXFe_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_Qkg1k6gk_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rswq2VSV, HV_BINOP_DIVIDE, 0, m, &cBinop_rswq2VSV_sendMessage);
}

void Heavy_vocoder::cBinop_UeEVtrNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B2vyEhrA, HV_BINOP_DIVIDE, 0, m, &cBinop_B2vyEhrA_sendMessage);
}

void Heavy_vocoder::cBinop_rswq2VSV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_w8qhMVwr_sendMessage);
}

void Heavy_vocoder::cBinop_ag4puYhf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_wBMrsL7y_sendMessage);
}

void Heavy_vocoder::cBinop_wBMrsL7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_NO6T6wlw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wy0gNNB7, HV_BINOP_MULTIPLY, 0, m, &cBinop_wy0gNNB7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8U7pfXFe, HV_BINOP_MULTIPLY, 0, m, &cBinop_8U7pfXFe_sendMessage);
}

void Heavy_vocoder::cBinop_qqNFfm0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wy0gNNB7, HV_BINOP_MULTIPLY, 1, m, &cBinop_wy0gNNB7_sendMessage);
}

void Heavy_vocoder::cBinop_wy0gNNB7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_TgoxAJVZ_sendMessage);
}

void Heavy_vocoder::cCast_kFgZ7kyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_54v5ZvjB, 0, m, &cVar_54v5ZvjB_sendMessage);
}

void Heavy_vocoder::cBinop_44buhUIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZtMJnsEg_sendMessage);
}

void Heavy_vocoder::cBinop_ZtMJnsEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_HTuni816, 5, m);
}

void Heavy_vocoder::cBinop_TgoxAJVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_HTuni816, 4, m);
}

void Heavy_vocoder::cBinop_UDCEUQyd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tmv0lcDH, HV_BINOP_MULTIPLY, 0, m, &cBinop_Tmv0lcDH_sendMessage);
}

void Heavy_vocoder::cBinop_8U7pfXFe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bvKS7JCJ, HV_BINOP_ADD, 1, m, &cBinop_bvKS7JCJ_sendMessage);
}

void Heavy_vocoder::cBinop_NO6T6wlw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_44buhUIN_sendMessage);
}

void Heavy_vocoder::cBinop_bvKS7JCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tmv0lcDH, HV_BINOP_MULTIPLY, 1, m, &cBinop_Tmv0lcDH_sendMessage);
}

void Heavy_vocoder::cBinop_Tmv0lcDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_HTuni816, 1, m);
}

void Heavy_vocoder::cBinop_TttxssXj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rswq2VSV, HV_BINOP_DIVIDE, 1, m, &cBinop_rswq2VSV_sendMessage);
}

void Heavy_vocoder::cBinop_w8qhMVwr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ag4puYhf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bvKS7JCJ, HV_BINOP_ADD, 0, m, &cBinop_bvKS7JCJ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_UDCEUQyd_sendMessage);
}

void Heavy_vocoder::cMsg_veebwSeb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KeNsI457_sendMessage);
}

void Heavy_vocoder::cSystem_KeNsI457_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zo0yGUf0, HV_BINOP_DIVIDE, 1, m, &cBinop_zo0yGUf0_sendMessage);
}

void Heavy_vocoder::cVar_phr1Kdp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_dbB0f63d_sendMessage);
}

void Heavy_vocoder::cVar_X2Ct84GP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_67MYk8c5_sendMessage);
}

void Heavy_vocoder::cUnop_LsuQ20Ar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_gihTIqlS_sendMessage);
}

void Heavy_vocoder::cBinop_zo0yGUf0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oS7DUwo8, HV_BINOP_MULTIPLY, 1, m, &cBinop_oS7DUwo8_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_LsuQ20Ar_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mSC4YUPr, HV_BINOP_DIVIDE, 0, m, &cBinop_mSC4YUPr_sendMessage);
}

void Heavy_vocoder::cBinop_dbB0f63d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zo0yGUf0, HV_BINOP_DIVIDE, 0, m, &cBinop_zo0yGUf0_sendMessage);
}

void Heavy_vocoder::cBinop_mSC4YUPr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_gmflFXZW_sendMessage);
}

void Heavy_vocoder::cBinop_Imtx0hKd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_WKtlzLWs_sendMessage);
}

void Heavy_vocoder::cBinop_WKtlzLWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_OSoyMOVj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jmxQNc5h, HV_BINOP_MULTIPLY, 0, m, &cBinop_jmxQNc5h_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oS7DUwo8, HV_BINOP_MULTIPLY, 0, m, &cBinop_oS7DUwo8_sendMessage);
}

void Heavy_vocoder::cBinop_gihTIqlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jmxQNc5h, HV_BINOP_MULTIPLY, 1, m, &cBinop_jmxQNc5h_sendMessage);
}

void Heavy_vocoder::cBinop_jmxQNc5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_r09w3rCo_sendMessage);
}

void Heavy_vocoder::cCast_Noj8KCvN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_phr1Kdp4, 0, m, &cVar_phr1Kdp4_sendMessage);
}

void Heavy_vocoder::cBinop_e3gNOQcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BBROK63e_sendMessage);
}

void Heavy_vocoder::cBinop_BBROK63e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_SLjtBVVo, 5, m);
}

void Heavy_vocoder::cBinop_r09w3rCo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_SLjtBVVo, 4, m);
}

void Heavy_vocoder::cBinop_P9DC38mG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1HLFFvM6, HV_BINOP_MULTIPLY, 0, m, &cBinop_1HLFFvM6_sendMessage);
}

void Heavy_vocoder::cBinop_oS7DUwo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6ISjLfiI, HV_BINOP_ADD, 1, m, &cBinop_6ISjLfiI_sendMessage);
}

void Heavy_vocoder::cBinop_OSoyMOVj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_e3gNOQcA_sendMessage);
}

void Heavy_vocoder::cBinop_6ISjLfiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1HLFFvM6, HV_BINOP_MULTIPLY, 1, m, &cBinop_1HLFFvM6_sendMessage);
}

void Heavy_vocoder::cBinop_1HLFFvM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_SLjtBVVo, 1, m);
}

void Heavy_vocoder::cBinop_67MYk8c5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mSC4YUPr, HV_BINOP_DIVIDE, 1, m, &cBinop_mSC4YUPr_sendMessage);
}

void Heavy_vocoder::cBinop_gmflFXZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Imtx0hKd_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6ISjLfiI, HV_BINOP_ADD, 0, m, &cBinop_6ISjLfiI_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_P9DC38mG_sendMessage);
}

void Heavy_vocoder::cMsg_6vw2n1ok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zYgTM6g0_sendMessage);
}

void Heavy_vocoder::cSystem_zYgTM6g0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hTvZCjgg, HV_BINOP_DIVIDE, 1, m, &cBinop_hTvZCjgg_sendMessage);
}

void Heavy_vocoder::cVar_sDY7u73b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_RXil7O8u_sendMessage);
}

void Heavy_vocoder::cVar_GxAYYuuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_lCUOqHG9_sendMessage);
}

void Heavy_vocoder::cUnop_GTS2ct80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_fR6OyN1A_sendMessage);
}

void Heavy_vocoder::cBinop_hTvZCjgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nxrM6s7N, HV_BINOP_MULTIPLY, 1, m, &cBinop_nxrM6s7N_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_GTS2ct80_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZJpAmB6Z, HV_BINOP_DIVIDE, 0, m, &cBinop_ZJpAmB6Z_sendMessage);
}

void Heavy_vocoder::cBinop_RXil7O8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hTvZCjgg, HV_BINOP_DIVIDE, 0, m, &cBinop_hTvZCjgg_sendMessage);
}

void Heavy_vocoder::cBinop_ZJpAmB6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_pnbrsqMv_sendMessage);
}

void Heavy_vocoder::cBinop_7ferpxRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_OFiOSnzU_sendMessage);
}

void Heavy_vocoder::cBinop_OFiOSnzU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_H3VtzcDH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0q9aNLRJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_0q9aNLRJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nxrM6s7N, HV_BINOP_MULTIPLY, 0, m, &cBinop_nxrM6s7N_sendMessage);
}

void Heavy_vocoder::cBinop_fR6OyN1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0q9aNLRJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_0q9aNLRJ_sendMessage);
}

void Heavy_vocoder::cBinop_0q9aNLRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5mNsu0IQ_sendMessage);
}

void Heavy_vocoder::cCast_Udut4EkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sDY7u73b, 0, m, &cVar_sDY7u73b_sendMessage);
}

void Heavy_vocoder::cBinop_mnvxjJgy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_MhhHMkay_sendMessage);
}

void Heavy_vocoder::cBinop_MhhHMkay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_aoh1TRre, 5, m);
}

void Heavy_vocoder::cBinop_5mNsu0IQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_aoh1TRre, 4, m);
}

void Heavy_vocoder::cBinop_kW9xML74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AEZY6SWH, HV_BINOP_MULTIPLY, 0, m, &cBinop_AEZY6SWH_sendMessage);
}

void Heavy_vocoder::cBinop_nxrM6s7N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hypKlxBy, HV_BINOP_ADD, 1, m, &cBinop_hypKlxBy_sendMessage);
}

void Heavy_vocoder::cBinop_H3VtzcDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_mnvxjJgy_sendMessage);
}

void Heavy_vocoder::cBinop_hypKlxBy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AEZY6SWH, HV_BINOP_MULTIPLY, 1, m, &cBinop_AEZY6SWH_sendMessage);
}

void Heavy_vocoder::cBinop_AEZY6SWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_aoh1TRre, 1, m);
}

void Heavy_vocoder::cBinop_lCUOqHG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZJpAmB6Z, HV_BINOP_DIVIDE, 1, m, &cBinop_ZJpAmB6Z_sendMessage);
}

void Heavy_vocoder::cBinop_pnbrsqMv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7ferpxRP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hypKlxBy, HV_BINOP_ADD, 0, m, &cBinop_hypKlxBy_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_kW9xML74_sendMessage);
}

void Heavy_vocoder::cMsg_IwYoj3Zz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_v8yTJlss_sendMessage);
}

void Heavy_vocoder::cSystem_v8yTJlss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gZIopxJi, HV_BINOP_DIVIDE, 1, m, &cBinop_gZIopxJi_sendMessage);
}

void Heavy_vocoder::cVar_D72FiIaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_kvgVmOZn_sendMessage);
}

void Heavy_vocoder::cVar_giQ43rTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_UjTcb8kE_sendMessage);
}

void Heavy_vocoder::cUnop_D5GONBkz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_fpMGWfdt_sendMessage);
}

void Heavy_vocoder::cBinop_gZIopxJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HB7G6Fxg, HV_BINOP_MULTIPLY, 1, m, &cBinop_HB7G6Fxg_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_D5GONBkz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_acDmXC29, HV_BINOP_DIVIDE, 0, m, &cBinop_acDmXC29_sendMessage);
}

void Heavy_vocoder::cBinop_kvgVmOZn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gZIopxJi, HV_BINOP_DIVIDE, 0, m, &cBinop_gZIopxJi_sendMessage);
}

void Heavy_vocoder::cBinop_acDmXC29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_A3wghVDS_sendMessage);
}

void Heavy_vocoder::cBinop_VEFqxgI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_y7RRHyfm_sendMessage);
}

void Heavy_vocoder::cBinop_y7RRHyfm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_REv1N4ok_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pNUphn3s, HV_BINOP_MULTIPLY, 0, m, &cBinop_pNUphn3s_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HB7G6Fxg, HV_BINOP_MULTIPLY, 0, m, &cBinop_HB7G6Fxg_sendMessage);
}

void Heavy_vocoder::cBinop_fpMGWfdt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pNUphn3s, HV_BINOP_MULTIPLY, 1, m, &cBinop_pNUphn3s_sendMessage);
}

void Heavy_vocoder::cBinop_pNUphn3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qpT47Dqh_sendMessage);
}

void Heavy_vocoder::cCast_ffu7ZslO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_D72FiIaV, 0, m, &cVar_D72FiIaV_sendMessage);
}

void Heavy_vocoder::cBinop_0OcvmKRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cFCK4cxi_sendMessage);
}

void Heavy_vocoder::cBinop_cFCK4cxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_mROPvisw, 5, m);
}

void Heavy_vocoder::cBinop_qpT47Dqh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_mROPvisw, 4, m);
}

void Heavy_vocoder::cBinop_25sfMAih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ImmMpfO3, HV_BINOP_MULTIPLY, 0, m, &cBinop_ImmMpfO3_sendMessage);
}

void Heavy_vocoder::cBinop_HB7G6Fxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oWSUO7a0, HV_BINOP_ADD, 1, m, &cBinop_oWSUO7a0_sendMessage);
}

void Heavy_vocoder::cBinop_REv1N4ok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0OcvmKRA_sendMessage);
}

void Heavy_vocoder::cBinop_oWSUO7a0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ImmMpfO3, HV_BINOP_MULTIPLY, 1, m, &cBinop_ImmMpfO3_sendMessage);
}

void Heavy_vocoder::cBinop_ImmMpfO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_mROPvisw, 1, m);
}

void Heavy_vocoder::cBinop_UjTcb8kE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_acDmXC29, HV_BINOP_DIVIDE, 1, m, &cBinop_acDmXC29_sendMessage);
}

void Heavy_vocoder::cBinop_A3wghVDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VEFqxgI7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oWSUO7a0, HV_BINOP_ADD, 0, m, &cBinop_oWSUO7a0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_25sfMAih_sendMessage);
}

void Heavy_vocoder::cMsg_9BbFb7JN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dBFXtP3Y_sendMessage);
}

void Heavy_vocoder::cSystem_dBFXtP3Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QcJAPfd2, HV_BINOP_DIVIDE, 1, m, &cBinop_QcJAPfd2_sendMessage);
}

void Heavy_vocoder::cVar_fRegSoiG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_B2NC7Arb_sendMessage);
}

void Heavy_vocoder::cVar_1VFgCRoI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_t1snoe3t_sendMessage);
}

void Heavy_vocoder::cUnop_8lK6OCda_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_FTObJEXW_sendMessage);
}

void Heavy_vocoder::cBinop_QcJAPfd2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FLYnobm3, HV_BINOP_MULTIPLY, 1, m, &cBinop_FLYnobm3_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_8lK6OCda_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0hOyFRfr, HV_BINOP_DIVIDE, 0, m, &cBinop_0hOyFRfr_sendMessage);
}

void Heavy_vocoder::cBinop_B2NC7Arb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QcJAPfd2, HV_BINOP_DIVIDE, 0, m, &cBinop_QcJAPfd2_sendMessage);
}

void Heavy_vocoder::cBinop_0hOyFRfr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_tKdLAcKw_sendMessage);
}

void Heavy_vocoder::cBinop_fubN9eG0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_yjOaOlpM_sendMessage);
}

void Heavy_vocoder::cBinop_yjOaOlpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_k4cK2wTr_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XXVhCV16, HV_BINOP_MULTIPLY, 0, m, &cBinop_XXVhCV16_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FLYnobm3, HV_BINOP_MULTIPLY, 0, m, &cBinop_FLYnobm3_sendMessage);
}

void Heavy_vocoder::cBinop_FTObJEXW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XXVhCV16, HV_BINOP_MULTIPLY, 1, m, &cBinop_XXVhCV16_sendMessage);
}

void Heavy_vocoder::cBinop_XXVhCV16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_82fYE49c_sendMessage);
}

void Heavy_vocoder::cCast_3hykI8V7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fRegSoiG, 0, m, &cVar_fRegSoiG_sendMessage);
}

void Heavy_vocoder::cBinop_dEt8uIv5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_f60TPqyw_sendMessage);
}

void Heavy_vocoder::cBinop_f60TPqyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JTdGbt2k, 5, m);
}

void Heavy_vocoder::cBinop_82fYE49c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JTdGbt2k, 4, m);
}

void Heavy_vocoder::cBinop_mTd88zaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UQZNSHN0, HV_BINOP_MULTIPLY, 0, m, &cBinop_UQZNSHN0_sendMessage);
}

void Heavy_vocoder::cBinop_FLYnobm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nyrZSBUS, HV_BINOP_ADD, 1, m, &cBinop_nyrZSBUS_sendMessage);
}

void Heavy_vocoder::cBinop_k4cK2wTr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_dEt8uIv5_sendMessage);
}

void Heavy_vocoder::cBinop_nyrZSBUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UQZNSHN0, HV_BINOP_MULTIPLY, 1, m, &cBinop_UQZNSHN0_sendMessage);
}

void Heavy_vocoder::cBinop_UQZNSHN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JTdGbt2k, 1, m);
}

void Heavy_vocoder::cBinop_t1snoe3t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0hOyFRfr, HV_BINOP_DIVIDE, 1, m, &cBinop_0hOyFRfr_sendMessage);
}

void Heavy_vocoder::cBinop_tKdLAcKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fubN9eG0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nyrZSBUS, HV_BINOP_ADD, 0, m, &cBinop_nyrZSBUS_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_mTd88zaI_sendMessage);
}

void Heavy_vocoder::cMsg_xRbF612H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0b8jeU40_sendMessage);
}

void Heavy_vocoder::cSystem_0b8jeU40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_foozmwKT, HV_BINOP_DIVIDE, 1, m, &cBinop_foozmwKT_sendMessage);
}

void Heavy_vocoder::cVar_BwnyXlun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_1oMDOHhE_sendMessage);
}

void Heavy_vocoder::cVar_kvwOLajW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_oRRaBBjz_sendMessage);
}

void Heavy_vocoder::cUnop_doc84pIt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_3y0dgt3i_sendMessage);
}

void Heavy_vocoder::cBinop_foozmwKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TPDwcvnh, HV_BINOP_MULTIPLY, 1, m, &cBinop_TPDwcvnh_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_doc84pIt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LNwGJDNo, HV_BINOP_DIVIDE, 0, m, &cBinop_LNwGJDNo_sendMessage);
}

void Heavy_vocoder::cBinop_1oMDOHhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_foozmwKT, HV_BINOP_DIVIDE, 0, m, &cBinop_foozmwKT_sendMessage);
}

void Heavy_vocoder::cBinop_LNwGJDNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_I5VWxvGl_sendMessage);
}

void Heavy_vocoder::cBinop_wBXOExfZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_AEbYBKMR_sendMessage);
}

void Heavy_vocoder::cBinop_AEbYBKMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_QlHtDWZT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_y0ds0Z3g, HV_BINOP_MULTIPLY, 0, m, &cBinop_y0ds0Z3g_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TPDwcvnh, HV_BINOP_MULTIPLY, 0, m, &cBinop_TPDwcvnh_sendMessage);
}

void Heavy_vocoder::cBinop_3y0dgt3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y0ds0Z3g, HV_BINOP_MULTIPLY, 1, m, &cBinop_y0ds0Z3g_sendMessage);
}

void Heavy_vocoder::cBinop_y0ds0Z3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HBvK1iXv_sendMessage);
}

void Heavy_vocoder::cCast_jgBATiyu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BwnyXlun, 0, m, &cVar_BwnyXlun_sendMessage);
}

void Heavy_vocoder::cBinop_EWBbMbl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fh4MDRIn_sendMessage);
}

void Heavy_vocoder::cBinop_fh4MDRIn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_XyrhmZBj, 5, m);
}

void Heavy_vocoder::cBinop_HBvK1iXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_XyrhmZBj, 4, m);
}

void Heavy_vocoder::cBinop_FwnDAu6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6XkjZTVb, HV_BINOP_MULTIPLY, 0, m, &cBinop_6XkjZTVb_sendMessage);
}

void Heavy_vocoder::cBinop_TPDwcvnh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tkFEd6VL, HV_BINOP_ADD, 1, m, &cBinop_tkFEd6VL_sendMessage);
}

void Heavy_vocoder::cBinop_QlHtDWZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_EWBbMbl2_sendMessage);
}

void Heavy_vocoder::cBinop_tkFEd6VL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6XkjZTVb, HV_BINOP_MULTIPLY, 1, m, &cBinop_6XkjZTVb_sendMessage);
}

void Heavy_vocoder::cBinop_6XkjZTVb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_XyrhmZBj, 1, m);
}

void Heavy_vocoder::cBinop_oRRaBBjz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LNwGJDNo, HV_BINOP_DIVIDE, 1, m, &cBinop_LNwGJDNo_sendMessage);
}

void Heavy_vocoder::cBinop_I5VWxvGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_wBXOExfZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tkFEd6VL, HV_BINOP_ADD, 0, m, &cBinop_tkFEd6VL_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_FwnDAu6A_sendMessage);
}

void Heavy_vocoder::cMsg_wmAeA3X2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qwcVcEAr_sendMessage);
}

void Heavy_vocoder::cSystem_qwcVcEAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s8ii0ujT, HV_BINOP_DIVIDE, 1, m, &cBinop_s8ii0ujT_sendMessage);
}

void Heavy_vocoder::cVar_iHMQwIRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_PfHzx3p1_sendMessage);
}

void Heavy_vocoder::cVar_Ic2EVZxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_3He53Euw_sendMessage);
}

void Heavy_vocoder::cUnop_SePi8DTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_1df3csb6_sendMessage);
}

void Heavy_vocoder::cBinop_s8ii0ujT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iAkG6Lb9, HV_BINOP_MULTIPLY, 1, m, &cBinop_iAkG6Lb9_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_SePi8DTf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cHZZuOkj, HV_BINOP_DIVIDE, 0, m, &cBinop_cHZZuOkj_sendMessage);
}

void Heavy_vocoder::cBinop_PfHzx3p1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s8ii0ujT, HV_BINOP_DIVIDE, 0, m, &cBinop_s8ii0ujT_sendMessage);
}

void Heavy_vocoder::cBinop_cHZZuOkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_UxiZrJw4_sendMessage);
}

void Heavy_vocoder::cBinop_odeqM2OZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_PdFEXX8I_sendMessage);
}

void Heavy_vocoder::cBinop_PdFEXX8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_ohrXM5jn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OLrd6reV, HV_BINOP_MULTIPLY, 0, m, &cBinop_OLrd6reV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_iAkG6Lb9, HV_BINOP_MULTIPLY, 0, m, &cBinop_iAkG6Lb9_sendMessage);
}

void Heavy_vocoder::cBinop_1df3csb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OLrd6reV, HV_BINOP_MULTIPLY, 1, m, &cBinop_OLrd6reV_sendMessage);
}

void Heavy_vocoder::cBinop_OLrd6reV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_V8A7HeNG_sendMessage);
}

void Heavy_vocoder::cCast_Ep9Yye4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iHMQwIRm, 0, m, &cVar_iHMQwIRm_sendMessage);
}

void Heavy_vocoder::cBinop_DKAgJ63A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Hmg331g7_sendMessage);
}

void Heavy_vocoder::cBinop_Hmg331g7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uXZunACf, 5, m);
}

void Heavy_vocoder::cBinop_V8A7HeNG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uXZunACf, 4, m);
}

void Heavy_vocoder::cBinop_v1So2Y0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GTA8T9yT, HV_BINOP_MULTIPLY, 0, m, &cBinop_GTA8T9yT_sendMessage);
}

void Heavy_vocoder::cBinop_iAkG6Lb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FVSu7JAh, HV_BINOP_ADD, 1, m, &cBinop_FVSu7JAh_sendMessage);
}

void Heavy_vocoder::cBinop_ohrXM5jn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DKAgJ63A_sendMessage);
}

void Heavy_vocoder::cBinop_FVSu7JAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GTA8T9yT, HV_BINOP_MULTIPLY, 1, m, &cBinop_GTA8T9yT_sendMessage);
}

void Heavy_vocoder::cBinop_GTA8T9yT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uXZunACf, 1, m);
}

void Heavy_vocoder::cBinop_3He53Euw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cHZZuOkj, HV_BINOP_DIVIDE, 1, m, &cBinop_cHZZuOkj_sendMessage);
}

void Heavy_vocoder::cBinop_UxiZrJw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_odeqM2OZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FVSu7JAh, HV_BINOP_ADD, 0, m, &cBinop_FVSu7JAh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_v1So2Y0D_sendMessage);
}

void Heavy_vocoder::cMsg_tzrdkuws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XJI1WrmM_sendMessage);
}

void Heavy_vocoder::cSystem_XJI1WrmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_48W7DeFg, HV_BINOP_DIVIDE, 1, m, &cBinop_48W7DeFg_sendMessage);
}

void Heavy_vocoder::cVar_r8Bm9vNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_VBHYcQXe_sendMessage);
}

void Heavy_vocoder::cVar_xBiX9dCH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_jOkpYe9f_sendMessage);
}

void Heavy_vocoder::cUnop_XYLWkuKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_xRkLUMqN_sendMessage);
}

void Heavy_vocoder::cBinop_48W7DeFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2dYXPXZj, HV_BINOP_MULTIPLY, 1, m, &cBinop_2dYXPXZj_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_XYLWkuKA_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YPO1Twu8, HV_BINOP_DIVIDE, 0, m, &cBinop_YPO1Twu8_sendMessage);
}

void Heavy_vocoder::cBinop_VBHYcQXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_48W7DeFg, HV_BINOP_DIVIDE, 0, m, &cBinop_48W7DeFg_sendMessage);
}

void Heavy_vocoder::cBinop_YPO1Twu8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_NS4RIqnz_sendMessage);
}

void Heavy_vocoder::cBinop_eQLhjSdr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_3HeTylQf_sendMessage);
}

void Heavy_vocoder::cBinop_3HeTylQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_ANhO1ZGX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oOy8e2gj, HV_BINOP_MULTIPLY, 0, m, &cBinop_oOy8e2gj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2dYXPXZj, HV_BINOP_MULTIPLY, 0, m, &cBinop_2dYXPXZj_sendMessage);
}

void Heavy_vocoder::cBinop_xRkLUMqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oOy8e2gj, HV_BINOP_MULTIPLY, 1, m, &cBinop_oOy8e2gj_sendMessage);
}

void Heavy_vocoder::cBinop_oOy8e2gj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RmTduhSd_sendMessage);
}

void Heavy_vocoder::cCast_4Ef9NmpW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_r8Bm9vNB, 0, m, &cVar_r8Bm9vNB_sendMessage);
}

void Heavy_vocoder::cBinop_v3GXebqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_LROZOTWN_sendMessage);
}

void Heavy_vocoder::cBinop_LROZOTWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_LVOeTib2, 5, m);
}

void Heavy_vocoder::cBinop_RmTduhSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_LVOeTib2, 4, m);
}

void Heavy_vocoder::cBinop_vcugXb4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SZ9mcg2T, HV_BINOP_MULTIPLY, 0, m, &cBinop_SZ9mcg2T_sendMessage);
}

void Heavy_vocoder::cBinop_2dYXPXZj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JUrRaNfB, HV_BINOP_ADD, 1, m, &cBinop_JUrRaNfB_sendMessage);
}

void Heavy_vocoder::cBinop_ANhO1ZGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_v3GXebqH_sendMessage);
}

void Heavy_vocoder::cBinop_JUrRaNfB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SZ9mcg2T, HV_BINOP_MULTIPLY, 1, m, &cBinop_SZ9mcg2T_sendMessage);
}

void Heavy_vocoder::cBinop_SZ9mcg2T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_LVOeTib2, 1, m);
}

void Heavy_vocoder::cBinop_jOkpYe9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YPO1Twu8, HV_BINOP_DIVIDE, 1, m, &cBinop_YPO1Twu8_sendMessage);
}

void Heavy_vocoder::cBinop_NS4RIqnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_eQLhjSdr_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JUrRaNfB, HV_BINOP_ADD, 0, m, &cBinop_JUrRaNfB_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_vcugXb4w_sendMessage);
}

void Heavy_vocoder::cBinop_FQDXTcWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_9q1ZdE84, 0, m);
}

void Heavy_vocoder::cBinop_BAZwnwNw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_zTe9JyoG_sendMessage);
}

void Heavy_vocoder::cBinop_zTe9JyoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MuAvEWLQ, HV_BINOP_POW, 1, m, &cBinop_MuAvEWLQ_sendMessage);
  cMsg_1hi6Gr8x_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_MuAvEWLQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_FQDXTcWv_sendMessage);
}

void Heavy_vocoder::cMsg_1hi6Gr8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MuAvEWLQ, HV_BINOP_POW, 0, m, &cBinop_MuAvEWLQ_sendMessage);
}

void Heavy_vocoder::cBinop_brCrTy8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_oJoZ7Zvz, 0, m);
}

void Heavy_vocoder::cBinop_EPeQ1kcg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_1tGyVHlm_sendMessage);
}

void Heavy_vocoder::cBinop_1tGyVHlm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_suUeG7jg, HV_BINOP_POW, 1, m, &cBinop_suUeG7jg_sendMessage);
  cMsg_xHqOYWEf_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_suUeG7jg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_brCrTy8q_sendMessage);
}

void Heavy_vocoder::cMsg_xHqOYWEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_suUeG7jg, HV_BINOP_POW, 0, m, &cBinop_suUeG7jg_sendMessage);
}

void Heavy_vocoder::cBinop_ReQNr50L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_EilbAabD, 0, m);
}

void Heavy_vocoder::cBinop_WyJwmoIi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_TwEAHk9l_sendMessage);
}

void Heavy_vocoder::cBinop_TwEAHk9l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LAhHjA2S, HV_BINOP_POW, 1, m, &cBinop_LAhHjA2S_sendMessage);
  cMsg_or9kXtMx_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_LAhHjA2S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_ReQNr50L_sendMessage);
}

void Heavy_vocoder::cMsg_or9kXtMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LAhHjA2S, HV_BINOP_POW, 0, m, &cBinop_LAhHjA2S_sendMessage);
}

void Heavy_vocoder::cBinop_GuaT3601_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_zGfbrWm7_sendMessage);
}

void Heavy_vocoder::cBinop_zGfbrWm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_KN65pGTB_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9QSYAF9O_sendMessage);
}

void Heavy_vocoder::cVar_smaIRmra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_a1zhAvGX_sendMessage);
}

void Heavy_vocoder::cMsg_RgocPcH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0L6xUhCp_sendMessage);
}

void Heavy_vocoder::cSystem_0L6xUhCp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UuSsqiRs, HV_BINOP_DIVIDE, 1, m, &cBinop_UuSsqiRs_sendMessage);
}

void Heavy_vocoder::cBinop_KN65pGTB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_CM9RMHH5_sendMessage);
}

void Heavy_vocoder::cBinop_CM9RMHH5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_d0MvF8KC, m);
}

void Heavy_vocoder::cMsg_1at9XnUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_V2VWap72_sendMessage);
}

void Heavy_vocoder::cBinop_V2VWap72_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_GuaT3601_sendMessage);
}

void Heavy_vocoder::cBinop_9QSYAF9O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LuIvqAvN, m);
}

void Heavy_vocoder::cBinop_a1zhAvGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_kwg4kIht_sendMessage);
}

void Heavy_vocoder::cBinop_kwg4kIht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UuSsqiRs, HV_BINOP_DIVIDE, 0, m, &cBinop_UuSsqiRs_sendMessage);
}

void Heavy_vocoder::cBinop_UuSsqiRs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1at9XnUI_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_Msy8kuBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6iUlGpax_sendMessage);
}

void Heavy_vocoder::cBinop_6iUlGpax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_UrrP8Qmm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vxD12ftH_sendMessage);
}

void Heavy_vocoder::cVar_YumI8Qpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_4CbXDwQk_sendMessage);
}

void Heavy_vocoder::cMsg_ourGENe0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OKz1AuXm_sendMessage);
}

void Heavy_vocoder::cSystem_OKz1AuXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wJ9zHa0l, HV_BINOP_DIVIDE, 1, m, &cBinop_wJ9zHa0l_sendMessage);
}

void Heavy_vocoder::cBinop_UrrP8Qmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_fj2wFUEp_sendMessage);
}

void Heavy_vocoder::cBinop_fj2wFUEp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_FU0bLcFc, m);
}

void Heavy_vocoder::cMsg_kZdIq03Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_G12cYcEC_sendMessage);
}

void Heavy_vocoder::cBinop_G12cYcEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Msy8kuBj_sendMessage);
}

void Heavy_vocoder::cBinop_vxD12ftH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PghmdXTB, m);
}

void Heavy_vocoder::cBinop_4CbXDwQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_rrxQizzm_sendMessage);
}

void Heavy_vocoder::cBinop_rrxQizzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wJ9zHa0l, HV_BINOP_DIVIDE, 0, m, &cBinop_wJ9zHa0l_sendMessage);
}

void Heavy_vocoder::cBinop_wJ9zHa0l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kZdIq03Z_sendMessage(_c, 0, m);
}

void Heavy_vocoder::cBinop_1DCo1r5G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_EPeQ1kcg_sendMessage);
}

void Heavy_vocoder::cBinop_NgWVP8pG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_WyJwmoIi_sendMessage);
}

void Heavy_vocoder::cReceive_127Xkw7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_isQJsbIN, m);
}

void Heavy_vocoder::cReceive_eNQN1kZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jY2u1uER, 0, m, &cVar_jY2u1uER_sendMessage);
  cMsg_n0AHsaaN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1MH9aAsR, 0, m, &cVar_1MH9aAsR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8FxFjjxe, 0, m, &cVar_8FxFjjxe_sendMessage);
  cMsg_EmAmno2l_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YBtGG8Ly, 0, m, &cVar_YBtGG8Ly_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xH7FmwtW, 0, m, &cVar_xH7FmwtW_sendMessage);
  cMsg_yvBf2h4G_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hKsz1oGb, 0, m, &cVar_hKsz1oGb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DKydOBpR, 0, m, &cVar_DKydOBpR_sendMessage);
  cMsg_IAYcEqtL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3FyWEJSd, 0, m, &cVar_3FyWEJSd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zZQSp3TM, 0, m, &cVar_zZQSp3TM_sendMessage);
  cMsg_bbMt2bgA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wYgMid53, 0, m, &cVar_wYgMid53_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8VgFDDCS, 0, m, &cVar_8VgFDDCS_sendMessage);
  cMsg_1NYt3pHY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_p5fkXMXf, 0, m, &cVar_p5fkXMXf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OVtfa3AG, 0, m, &cVar_OVtfa3AG_sendMessage);
  cMsg_oOkWL6dc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_54v5ZvjB, 0, m, &cVar_54v5ZvjB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_X2Ct84GP, 0, m, &cVar_X2Ct84GP_sendMessage);
  cMsg_veebwSeb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_phr1Kdp4, 0, m, &cVar_phr1Kdp4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GxAYYuuc, 0, m, &cVar_GxAYYuuc_sendMessage);
  cMsg_6vw2n1ok_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sDY7u73b, 0, m, &cVar_sDY7u73b_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_giQ43rTf, 0, m, &cVar_giQ43rTf_sendMessage);
  cMsg_IwYoj3Zz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_D72FiIaV, 0, m, &cVar_D72FiIaV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1VFgCRoI, 0, m, &cVar_1VFgCRoI_sendMessage);
  cMsg_9BbFb7JN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fRegSoiG, 0, m, &cVar_fRegSoiG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kvwOLajW, 0, m, &cVar_kvwOLajW_sendMessage);
  cMsg_xRbF612H_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BwnyXlun, 0, m, &cVar_BwnyXlun_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Ic2EVZxw, 0, m, &cVar_Ic2EVZxw_sendMessage);
  cMsg_wmAeA3X2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iHMQwIRm, 0, m, &cVar_iHMQwIRm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xBiX9dCH, 0, m, &cVar_xBiX9dCH_sendMessage);
  cMsg_tzrdkuws_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_r8Bm9vNB, 0, m, &cVar_r8Bm9vNB_sendMessage);
  cMsg_RgocPcH0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_smaIRmra, 0, m, &cVar_smaIRmra_sendMessage);
  cMsg_ourGENe0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YumI8Qpw, 0, m, &cVar_YumI8Qpw_sendMessage);
}

void Heavy_vocoder::cReceive_5IdUN8vA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_BAZwnwNw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1DCo1r5G, HV_BINOP_ADD, 0, m, &cBinop_1DCo1r5G_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NgWVP8pG, HV_BINOP_ADD, 0, m, &cBinop_NgWVP8pG_sendMessage);
}

void Heavy_vocoder::cReceive_m0WejA4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_b3DQ7g8U, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ibb9jVox, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Mhbq3btS, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_djmIUyuF, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OKTC9Id8, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_oAj7HR84, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_oW87R61V, m);
}

void Heavy_vocoder::cReceive_xQgTZlOZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NgWVP8pG, HV_BINOP_ADD, 1, m, &cBinop_NgWVP8pG_sendMessage);
}

void Heavy_vocoder::cReceive_DyoViuig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1DCo1r5G, HV_BINOP_ADD, 1, m, &cBinop_1DCo1r5G_sendMessage);
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
    __hv_varread_f(&sVarf_isQJsbIN, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_9q1ZdE84, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_EilbAabD, VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_oJoZ7Zvz, VOf(Bf0));
    __hv_add_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f, 1.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_RAhWJhQc, VIf(Bf2), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_k54u1RIk, VIf(Bf1), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_8moTHL01, VOf(Bf4));
    __hv_varread_f(&sVarf_b3DQ7g8U, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_max_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_8moTHL01, VIf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_RW5nDd6o, VIf(Bf2), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_9RtxEjFB, VIf(Bf1), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_rpbLp9wv, VOf(Bf4));
    __hv_varread_f(&sVarf_ibb9jVox, VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_max_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varwrite_f(&sVarf_rpbLp9wv, VIf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_biquad_k_f(&sBiquad_k_CBeZBII0, VIf(Bf2), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_w9oP6xYp, VIf(Bf1), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_dMkww6hL, VOf(Bf3));
    __hv_varread_f(&sVarf_Mhbq3btS, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_max_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_dMkww6hL, VIf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_SLjtBVVo, VIf(Bf2), VOf(Bf6));
    __hv_biquad_k_f(&sBiquad_k_HTuni816, VIf(Bf1), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_OdvBxV7s, VOf(Bf0));
    __hv_varread_f(&sVarf_djmIUyuF, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_max_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_OdvBxV7s, VIf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_biquad_k_f(&sBiquad_k_mROPvisw, VIf(Bf2), VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_aoh1TRre, VIf(Bf1), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_Srze7Gvx, VOf(Bf5));
    __hv_varread_f(&sVarf_OKTC9Id8, VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_max_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_Srze7Gvx, VIf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_XyrhmZBj, VIf(Bf2), VOf(Bf3));
    __hv_biquad_k_f(&sBiquad_k_JTdGbt2k, VIf(Bf1), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_5CFQBnMb, VOf(Bf6));
    __hv_varread_f(&sVarf_oAj7HR84, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_max_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_5CFQBnMb, VIf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_biquad_k_f(&sBiquad_k_LVOeTib2, VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_uXZunACf, VIf(Bf1), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_8IAkqFcd, VOf(Bf3));
    __hv_varread_f(&sVarf_oW87R61V, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_max_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_8IAkqFcd, VIf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f);
    __hv_varread_f(&sVarf_LuIvqAvN, VOf(Bf2));
    __hv_rpole_f(&sRPole_EiFzmpKv, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_6BwPm6wX, VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_d0MvF8KC, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_PghmdXTB, VOf(Bf1));
    __hv_rpole_f(&sRPole_JFaaVQSG, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_BYXpNMyk, VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_FU0bLcFc, VOf(Bf1));
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
