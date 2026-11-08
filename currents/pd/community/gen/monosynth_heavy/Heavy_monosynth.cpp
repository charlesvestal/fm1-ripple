/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside monosynth.pd) */

#include "Heavy_monosynth.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_monosynth *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_monosynth_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_monosynth));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_monosynth(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_monosynth_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_monosynth));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_monosynth(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_monosynth_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_monosynth();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_monosynth::Heavy_monosynth(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_init(&sPhasor_AhkrEBT4, sampleRate);
  numBytes += sLine_init(&sLine_yPuM6XGy);
  numBytes += sCPole_init(&sCPole_F51i6lxF);
  numBytes += sCPole_init(&sCPole_TQP9qrDu);
  numBytes += cSlice_init(&cSlice_dqx0IRNu, 2, 1);
  numBytes += cSlice_init(&cSlice_dRXEpwNm, 1, 1);
  numBytes += cSlice_init(&cSlice_yomxeLPz, 0, 1);
  numBytes += cVar_init_f(&cVar_C6Zzv2dy, 0.0f);
  numBytes += cIf_init(&cIf_wa8CjGMh, false);
  numBytes += cIf_init(&cIf_JPDMqHog, false);
  numBytes += cIf_init(&cIf_RxQVm1kp, false);
  numBytes += cIf_init(&cIf_d87gSIwM, false);
  numBytes += cIf_init(&cIf_F9WSt0dB, false);
  numBytes += cBinop_init(&cBinop_9zD46AGu, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_5CwRBxtr, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_c4XmZCdb, 0.0f, 0.0f, false);
  numBytes += cExpr_init(&cExpr_7gHyuud3, &Heavy_monosynth::cExpr_7gHyuud3_evaluate);
  numBytes += cExpr_init(&cExpr_1iyW31Ep, &Heavy_monosynth::cExpr_1iyW31Ep_evaluate);
  numBytes += sVarf_init(&sVarf_1t9fh7l5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_U2OSUZQd, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nAPXke0d, 0.5f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_dgGP1WBN, 0.0f);
  numBytes += cVar_init_f(&cVar_hNqzFvtm, 0.0f);
  numBytes += cIf_init(&cIf_8jPAhab7, false);
  numBytes += sVarf_init(&sVarf_zTaPmsjY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_yKwamrMn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4uLrJyE7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YK6LVGoT, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8SBEnQgl, 0.0f);
  numBytes += cIf_init(&cIf_GuwfE2hL, false);
  numBytes += sVarf_init(&sVarf_9KTyluoT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_31y2T22g, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pkl6PyxM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WGw3ndVk, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_q4Dj0oa0, 0.707f);
  numBytes += cExpr_init(&cExpr_JontdOEC, &Heavy_monosynth::cExpr_JontdOEC_evaluate);
  numBytes += cVar_init_f(&cVar_7Siu1pfS, 0.0f);
  numBytes += cVar_init_f(&cVar_14Osm7nO, 0.0f);
  numBytes += cVar_init_f(&cVar_Zn2Z5yrx, 0.0f);
  numBytes += cVar_init_f(&cVar_BeuC9cR1, 0.0f);
  numBytes += cVar_init_f(&cVar_mMejDmnF, 0.0f);
  numBytes += cPack_init(&cPack_coCZV7Yn, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_WYoyXQzB, 0.0f);
  numBytes += cVar_init_f(&cVar_SA0KNx1P, 0.0f);
  numBytes += cVar_init_f(&cVar_pyS109Sg, 0.0f);
  numBytes += cVar_init_f(&cVar_SlbCm4wk, 0.0f);
  numBytes += cVar_init_f(&cVar_IP8bkfl6, 0.0f);
  numBytes += cExpr_init(&cExpr_9rH65PKz, &Heavy_monosynth::cExpr_9rH65PKz_evaluate);
  numBytes += cExpr_init(&cExpr_Oxtvxtcv, &Heavy_monosynth::cExpr_Oxtvxtcv_evaluate);
  numBytes += cExpr_init(&cExpr_yBm9p1nL, &Heavy_monosynth::cExpr_yBm9p1nL_evaluate);
  numBytes += cVar_init_f(&cVar_9UzhtynI, 0.0f);
  numBytes += sVarf_init(&sVarf_Pz9RC4ns, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_s3tJnu9a, 0.0f);
  numBytes += cVar_init_f(&cVar_pEGj70BF, 0.0f);
  numBytes += cExpr_init(&cExpr_9FV7fpB5, &Heavy_monosynth::cExpr_9FV7fpB5_evaluate);
  numBytes += sVarf_init(&sVarf_3CCuVowI, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_monosynth::~Heavy_monosynth() {
  cExpr_free(&cExpr_7gHyuud3);
  cExpr_free(&cExpr_1iyW31Ep);
  cExpr_free(&cExpr_JontdOEC);
  cPack_free(&cPack_coCZV7Yn);
  cExpr_free(&cExpr_9rH65PKz);
  cExpr_free(&cExpr_Oxtvxtcv);
  cExpr_free(&cExpr_yBm9p1nL);
  cExpr_free(&cExpr_9FV7fpB5);
}

HvTable *Heavy_monosynth::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_monosynth::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xE0DDF12E: { // _1_wvform_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_79IZlRSf_sendMessage);
      break;
    }
    case 0xAEA003E7: { // _2_PWM_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6kQRHjCQ_sendMessage);
      break;
    }
    case 0x1400CF4A: { // _3_cutoff_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_G0BIx0ex_sendMessage);
      break;
    }
    case 0x76662EAD: { // _4_Attack_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aQXPK7fZ_sendMessage);
      break;
    }
    case 0xEDB1071A: { // _5_Decay_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PNBS6kHg_sendMessage);
      break;
    }
    case 0x46C2E2B6: { // _6_Sustain_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FXaAFwdX_sendMessage);
      break;
    }
    case 0x59614F9D: { // _7_Release_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ubx5E0c2_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VwsY7cBJ_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fU70p9fd_sendMessage);
      break;
    }
    case 0x9ABB563A: { // fltrenv_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LmU7vLUI_sendMessage);
      break;
    }
    case 0x3E80BBC2: { // fltrrez_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AsZIoJKp_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_monosynth::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "_1_wvform_f";
        info->hash = 0xE0DDF12E;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 1: {
        info->name = "_2_PWM_f";
        info->hash = 0xAEA003E7;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 2: {
        info->name = "_3_cutoff_f";
        info->hash = 0x1400CF4A;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -1.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 3: {
        info->name = "_4_Attack_f";
        info->hash = 0x76662EAD;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 4: {
        info->name = "_5_Decay_f";
        info->hash = 0xEDB1071A;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 5: {
        info->name = "_6_Sustain_f";
        info->hash = 0x46C2E2B6;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 1.0f;
        break;
      }
      case 6: {
        info->name = "_7_Release_f";
        info->hash = 0x59614F9D;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 7: {
        info->name = "fltrenv_f";
        info->hash = 0x9ABB563A;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -1.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 8: {
        info->name = "fltrrez_f";
        info->hash = 0x3E80BBC2;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -1.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
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
  return 9;
}



/*
 * Send Function Implementations
 */


void Heavy_monosynth::cSlice_dqx0IRNu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_hPD3C2BH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cSlice_dRXEpwNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_d87gSIwM, 0, m, &cIf_d87gSIwM_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_JPDMqHog, 0, m, &cIf_JPDMqHog_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cSlice_yomxeLPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_F9WSt0dB, 0, m, &cIf_F9WSt0dB_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_RxQVm1kp, 0, m, &cIf_RxQVm1kp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cVar_C6Zzv2dy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_oAD5wXUC_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_wa8CjGMh, 0, m, &cIf_wa8CjGMh_sendMessage);
}

void Heavy_monosynth::cUnop_YfP3NrhQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_n7IQ3hxT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9zD46AGu, HV_BINOP_EQ, 1, m, &cBinop_9zD46AGu_sendMessage);
}

void Heavy_monosynth::cUnop_B6rbwTsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_n7IQ3hxT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9zD46AGu, HV_BINOP_EQ, 1, m, &cBinop_9zD46AGu_sendMessage);
}

void Heavy_monosynth::cIf_wa8CjGMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_B6rbwTsR_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_YfP3NrhQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cBinop_oAD5wXUC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wa8CjGMh, 1, m, &cIf_wa8CjGMh_sendMessage);
}

void Heavy_monosynth::cIf_JPDMqHog_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_Bq89IMEo_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cIf_RxQVm1kp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_mhWFbSdg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cIf_d87gSIwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_Bq89IMEo_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cIf_F9WSt0dB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_mhWFbSdg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cBinop_hPD3C2BH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9zD46AGu, HV_BINOP_EQ, 0, m, &cBinop_9zD46AGu_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_3wnziwHh_sendMessage);
}

void Heavy_monosynth::cBinop_n7IQ3hxT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pWR0Vkr9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cUrilS4O_sendMessage);
}

void Heavy_monosynth::cBinop_9zD46AGu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1O4U56rV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kZADFeow_sendMessage);
}

void Heavy_monosynth::cCast_1O4U56rV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JPDMqHog, 1, m, &cIf_JPDMqHog_sendMessage);
}

void Heavy_monosynth::cCast_kZADFeow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_F9WSt0dB, 1, m, &cIf_F9WSt0dB_sendMessage);
}

void Heavy_monosynth::cCast_cUrilS4O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RxQVm1kp, 1, m, &cIf_RxQVm1kp_sendMessage);
}

void Heavy_monosynth::cCast_pWR0Vkr9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_d87gSIwM, 1, m, &cIf_d87gSIwM_sendMessage);
}

void Heavy_monosynth::cBinop_3wnziwHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_monosynth::cBinop_aZ4zbhhh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_c4XmZCdb, m);
}

void Heavy_monosynth::cBinop_mhWFbSdg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_ShIvkkpQ_sendMessage);
}

void Heavy_monosynth::cBinop_ShIvkkpQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5CwRBxtr, HV_BINOP_POW, 1, m, &cBinop_5CwRBxtr_sendMessage);
  cMsg_CUpk4x51_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cBinop_5CwRBxtr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_aZ4zbhhh_sendMessage);
}

void Heavy_monosynth::cMsg_CUpk4x51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5CwRBxtr, HV_BINOP_POW, 0, m, &cBinop_5CwRBxtr_sendMessage);
}

void Heavy_monosynth::cExpr_7gHyuud3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_U2OSUZQd, m);
}

float Heavy_monosynth::cExpr_7gHyuud3_evaluate(const float* args) {
  	return 1-((float)(args[0]));
}

void Heavy_monosynth::cExpr_1iyW31Ep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nAPXke0d, m);
}

float Heavy_monosynth::cExpr_1iyW31Ep_evaluate(const float* args) {
  	return ((float)(args[0]))*0.5+0.5;
}

void Heavy_monosynth::cVar_dgGP1WBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_1iyW31Ep, 0, m, &cExpr_1iyW31Ep_sendMessage);
}

void Heavy_monosynth::cMsg_NP0qMD2e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sfoVH789_sendMessage);
}

void Heavy_monosynth::cSystem_sfoVH789_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N2fBjtz3_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_hNqzFvtm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_B2YDCCcy_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_8jPAhab7, 0, m, &cIf_8jPAhab7_sendMessage);
}

void Heavy_monosynth::cIf_8jPAhab7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_1SxtBpRo_sendMessage(_c, 0, m);
      cMsg_mCQ46wyh_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_n9byTDgo_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Cay0ehEi_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_YK6LVGoT, m);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cBinop_B2YDCCcy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8jPAhab7, 1, m, &cIf_8jPAhab7_sendMessage);
}

void Heavy_monosynth::cMsg_n9byTDgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Arvpi12B_sendMessage);
}

void Heavy_monosynth::cBinop_Arvpi12B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yKwamrMn, m);
}

void Heavy_monosynth::cBinop_Cay0ehEi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jHo2ccb6_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cMsg_jHo2ccb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_nq0bztO9_sendMessage);
}

void Heavy_monosynth::cBinop_nq0bztO9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ACseorjK_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cMsg_ACseorjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_LwaKbcIV_sendMessage);
}

void Heavy_monosynth::cBinop_LwaKbcIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4uLrJyE7, m);
}

void Heavy_monosynth::cBinop_dbfZaE55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zTaPmsjY, m);
}

void Heavy_monosynth::cMsg_N2fBjtz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_dbfZaE55_sendMessage);
}

void Heavy_monosynth::cMsg_1SxtBpRo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Cay0ehEi_sendMessage);
}

void Heavy_monosynth::cMsg_mCQ46wyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_yKwamrMn, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YK6LVGoT, m);
}

void Heavy_monosynth::cMsg_yf8nbX7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cBaUfizR_sendMessage);
}

void Heavy_monosynth::cSystem_cBaUfizR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GLB8elJr_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_8SBEnQgl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_LdhDiFe3_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_GuwfE2hL, 0, m, &cIf_GuwfE2hL_sendMessage);
}

void Heavy_monosynth::cIf_GuwfE2hL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_S4hpUmO7_sendMessage(_c, 0, m);
      cMsg_zBGtxW1O_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_y4YCohHu_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_d59qc7ci_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_WGw3ndVk, m);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cBinop_LdhDiFe3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GuwfE2hL, 1, m, &cIf_GuwfE2hL_sendMessage);
}

void Heavy_monosynth::cMsg_y4YCohHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_DF6qbezJ_sendMessage);
}

void Heavy_monosynth::cBinop_DF6qbezJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_31y2T22g, m);
}

void Heavy_monosynth::cBinop_d59qc7ci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6u32Y9Bt_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cMsg_6u32Y9Bt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_e5F5ZMom_sendMessage);
}

void Heavy_monosynth::cBinop_e5F5ZMom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aLejSJDi_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cMsg_aLejSJDi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_rMo9qQEf_sendMessage);
}

void Heavy_monosynth::cBinop_rMo9qQEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pkl6PyxM, m);
}

void Heavy_monosynth::cBinop_QAfPOoha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9KTyluoT, m);
}

void Heavy_monosynth::cMsg_GLB8elJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_QAfPOoha_sendMessage);
}

void Heavy_monosynth::cMsg_S4hpUmO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_d59qc7ci_sendMessage);
}

void Heavy_monosynth::cMsg_zBGtxW1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_31y2T22g, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WGw3ndVk, m);
}

void Heavy_monosynth::cVar_q4Dj0oa0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hNqzFvtm, 0, m, &cVar_hNqzFvtm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8SBEnQgl, 0, m, &cVar_8SBEnQgl_sendMessage);
}

void Heavy_monosynth::cExpr_JontdOEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_q4Dj0oa0, 0, m, &cVar_q4Dj0oa0_sendMessage);
}

float Heavy_monosynth::cExpr_JontdOEC_evaluate(const float* args) {
  	return hv_pow_f(8 , ((float)(args[0])));
}

void Heavy_monosynth::cVar_7Siu1pfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_JontdOEC, 0, m, &cExpr_JontdOEC_sendMessage);
}

void Heavy_monosynth::cVar_14Osm7nO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3CCuVowI, m);
}

void Heavy_monosynth::cVar_Zn2Z5yrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_Oxtvxtcv, 0, m, &cExpr_Oxtvxtcv_sendMessage);
}

void Heavy_monosynth::cVar_BeuC9cR1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SlbCm4wk, 1, m, &cVar_SlbCm4wk_sendMessage);
}

void Heavy_monosynth::cVar_mMejDmnF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_9rH65PKz, 0, m, &cExpr_9rH65PKz_sendMessage);
}

void Heavy_monosynth::cPack_coCZV7Yn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_yPuM6XGy, 0, m, NULL);
}

void Heavy_monosynth::cCast_rxxqFBFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SA0KNx1P, 0, m, &cVar_SA0KNx1P_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0IdHd3Lc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SKpGU0jj_sendMessage);
}

void Heavy_monosynth::cSwitchcase_Bq89IMEo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9nA3vbX2_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rxxqFBFQ_sendMessage);
      break;
    }
  }
}

void Heavy_monosynth::cCast_9nA3vbX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ur0gGxi9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pyS109Sg, 0, m, &cVar_pyS109Sg_sendMessage);
}

void Heavy_monosynth::cSwitchcase_eWItIGsK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_3pe84Fmy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_3pe84Fmy_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_WYoyXQzB, 1, m, &cDelay_WYoyXQzB_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1VknISnl_sendMessage);
      break;
    }
  }
}

void Heavy_monosynth::cDelay_WYoyXQzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WYoyXQzB, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SlbCm4wk, 0, m, &cVar_SlbCm4wk_sendMessage);
}

void Heavy_monosynth::cMsg_3pe84Fmy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_WYoyXQzB, 0, m, &cDelay_WYoyXQzB_sendMessage);
}

void Heavy_monosynth::cCast_1VknISnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WYoyXQzB, 0, m, &cDelay_WYoyXQzB_sendMessage);
}

void Heavy_monosynth::cVar_SA0KNx1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SHZCtQRp_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_pyS109Sg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_D8Kq8LI8_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_SlbCm4wk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_coCZV7Yn, 0, m, &cPack_coCZV7Yn_sendMessage);
}

void Heavy_monosynth::cVar_IP8bkfl6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_yPuM6XGy, 0, m, NULL);
}

void Heavy_monosynth::cExpr_9rH65PKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pyS109Sg, 1, m, &cVar_pyS109Sg_sendMessage);
}

float Heavy_monosynth::cExpr_9rH65PKz_evaluate(const float* args) {
  	return hv_pow_f(10 , 4.5*((float)(args[0])));
}

void Heavy_monosynth::cExpr_Oxtvxtcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_coCZV7Yn, 1, m, &cPack_coCZV7Yn_sendMessage);
}

float Heavy_monosynth::cExpr_Oxtvxtcv_evaluate(const float* args) {
  	return hv_pow_f(10 , 4*((float)(args[0])));
}

void Heavy_monosynth::cExpr_yBm9p1nL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SA0KNx1P, 1, m, &cVar_SA0KNx1P_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WYoyXQzB, 1, m, &cDelay_WYoyXQzB_sendMessage);
}

float Heavy_monosynth::cExpr_yBm9p1nL_evaluate(const float* args) {
  	return 2+hv_pow_f(10 , 4*((float)(args[0])));
}

void Heavy_monosynth::cMsg_D8Kq8LI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_yPuM6XGy, 0, m, NULL);
}

void Heavy_monosynth::cMsg_SHZCtQRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_yPuM6XGy, 0, m, NULL);
}

void Heavy_monosynth::cMsg_Ur0gGxi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_eWItIGsK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_monosynth::cCast_SKpGU0jj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_eWItIGsK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_monosynth::cCast_0IdHd3Lc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ur0gGxi9_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_9UzhtynI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_9FV7fpB5, 0, m, &cExpr_9FV7fpB5_sendMessage);
}

void Heavy_monosynth::cVar_s3tJnu9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1t9fh7l5, m);
  cExpr_onMessage(_c, &Context(_c)->cExpr_7gHyuud3, 0, m, &cExpr_7gHyuud3_sendMessage);
}

void Heavy_monosynth::cVar_pEGj70BF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_yBm9p1nL, 0, m, &cExpr_yBm9p1nL_sendMessage);
}

void Heavy_monosynth::cExpr_9FV7fpB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Pz9RC4ns, m);
}

float Heavy_monosynth::cExpr_9FV7fpB5_evaluate(const float* args) {
  	return hv_pow_f(2 , 5*((float)(args[0])));
}

void Heavy_monosynth::cReceive_VwsY7cBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NP0qMD2e_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hNqzFvtm, 0, m, &cVar_hNqzFvtm_sendMessage);
  cMsg_yf8nbX7Z_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8SBEnQgl, 0, m, &cVar_8SBEnQgl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_C6Zzv2dy, 0, m, &cVar_C6Zzv2dy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IP8bkfl6, 0, m, &cVar_IP8bkfl6_sendMessage);
}

void Heavy_monosynth::cReceive_fU70p9fd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_dqx0IRNu, 0, m, &cSlice_dqx0IRNu_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_dRXEpwNm, 0, m, &cSlice_dRXEpwNm_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_yomxeLPz, 0, m, &cSlice_yomxeLPz_sendMessage);
}

void Heavy_monosynth::cReceive_6kQRHjCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dgGP1WBN, 0, m, &cVar_dgGP1WBN_sendMessage);
}

void Heavy_monosynth::cReceive_AsZIoJKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7Siu1pfS, 0, m, &cVar_7Siu1pfS_sendMessage);
}

void Heavy_monosynth::cReceive_LmU7vLUI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_14Osm7nO, 0, m, &cVar_14Osm7nO_sendMessage);
}

void Heavy_monosynth::cReceive_PNBS6kHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Zn2Z5yrx, 0, m, &cVar_Zn2Z5yrx_sendMessage);
}

void Heavy_monosynth::cReceive_FXaAFwdX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BeuC9cR1, 0, m, &cVar_BeuC9cR1_sendMessage);
}

void Heavy_monosynth::cReceive_Ubx5E0c2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mMejDmnF, 0, m, &cVar_mMejDmnF_sendMessage);
}

void Heavy_monosynth::cReceive_G0BIx0ex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9UzhtynI, 0, m, &cVar_9UzhtynI_sendMessage);
}

void Heavy_monosynth::cReceive_79IZlRSf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s3tJnu9a, 0, m, &cVar_s3tJnu9a_sendMessage);
}

void Heavy_monosynth::cReceive_aQXPK7fZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pEGj70BF, 0, m, &cVar_pEGj70BF_sendMessage);
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

int Heavy_monosynth::process(float **inputBuffers, float **outputBuffers, int n) {
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
    __hv_varread_f(&sVarf_c4XmZCdb, VOf(Bf0));
    __hv_phasor_f(&sPhasor_AhkrEBT4, VIf(Bf0), VOf(Bf1));
    __hv_varread_f(&sVarf_nAPXke0d, VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f);
    __hv_min_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f);
    __hv_max_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_1t9fh7l5, VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf1), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_U2OSUZQd, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_Pz9RC4ns, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_yPuM6XGy, VOf(Bf0));
    __hv_varread_f(&sVarf_3CCuVowI, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf1), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_pow_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 16000.0f, 16000.0f, 16000.0f, 16000.0f, 16000.0f, 16000.0f, 16000.0f, 16000.0f);
    __hv_min_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_zTaPmsjY, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_YK6LVGoT, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_yKwamrMn, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_varread_f(&sVarf_4uLrJyE7, VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf3));
    __hv_cos_f(VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf4));
    __hv_gt_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_sqrt_f(VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_cpole_f(&sCPole_F51i6lxF, VIf(Bf2), VIf(ZERO), VIf(Bf6), VIf(Bf5), VOf(Bf5), VOf(Bf6));
    __hv_varread_f(&sVarf_9KTyluoT, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_WGw3ndVk, VOf(Bf5));
    __hv_min_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_31y2T22g, VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf6));
    __hv_varread_f(&sVarf_pkl6PyxM, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf2));
    __hv_cos_f(VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf6));
    __hv_gt_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_sqrt_f(VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_cpole_f(&sCPole_TQP9qrDu, VIf(Bf5), VIf(ZERO), VIf(Bf3), VIf(Bf1), VOf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_monosynth::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_monosynth::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
