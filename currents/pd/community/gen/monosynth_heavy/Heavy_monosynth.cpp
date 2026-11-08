/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside monosynth.pd) */

#include "Heavy_monosynth.hpp"



#define Context(_c) static_cast<Heavy_monosynth *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_monosynth::Heavy_monosynth(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_init(&sPhasor_BBO1i5zX, sampleRate);
  numBytes += sLine_init(&sLine_8prVuuq1);
  numBytes += sCPole_init(&sCPole_1egQ33SA);
  numBytes += sCPole_init(&sCPole_V3fTvbtL);
  numBytes += cSlice_init(&cSlice_qUdOgkAc, 2, 1);
  numBytes += cSlice_init(&cSlice_VGHGxKOU, 1, 1);
  numBytes += cSlice_init(&cSlice_IFYTI6G8, 0, 1);
  numBytes += cVar_init_f(&cVar_VSfxams3, 0.0f);
  numBytes += cIf_init(&cIf_DW4alz7B, false);
  numBytes += cIf_init(&cIf_lMFUTh6Y, false);
  numBytes += cIf_init(&cIf_5um8yXaT, false);
  numBytes += cIf_init(&cIf_6dM6OEs2, false);
  numBytes += cIf_init(&cIf_FXsOi8CQ, false);
  numBytes += cBinop_init(&cBinop_zhBcdayC, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_CWsziEwU, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_B8Uleb8r, 0.0f, 0.0f, false);
  numBytes += cExpr_init(&cExpr_FRC486nf, &Heavy_monosynth::cExpr_FRC486nf_evaluate);
  numBytes += cExpr_init(&cExpr_p3VIWGTG, &Heavy_monosynth::cExpr_p3VIWGTG_evaluate);
  numBytes += sVarf_init(&sVarf_z8zpjddP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KGLJr3ZS, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fS1Wln3l, 0.5f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_2l6CDLy6, 0.0f);
  numBytes += cVar_init_f(&cVar_QMY4Ggzg, 0.0f);
  numBytes += cIf_init(&cIf_n5YfUWQD, false);
  numBytes += sVarf_init(&sVarf_hzRdtW2E, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XwrxV3j9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_s125NIxo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KcB5rLFd, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_95UCrsWy, 0.0f);
  numBytes += cIf_init(&cIf_NWgrqZe3, false);
  numBytes += sVarf_init(&sVarf_AQlhxHp1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GA3osnfR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kRWD6jUO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wMig5v2o, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_xKsiCVlA, 0.707f);
  numBytes += cExpr_init(&cExpr_TMzRHgEB, &Heavy_monosynth::cExpr_TMzRHgEB_evaluate);
  numBytes += cVar_init_f(&cVar_hndAACsC, 0.0f);
  numBytes += cVar_init_f(&cVar_giAkG6l3, 0.0f);
  numBytes += cVar_init_f(&cVar_aBK3nt8r, 0.0f);
  numBytes += cVar_init_f(&cVar_y37kE4Wk, 0.0f);
  numBytes += cVar_init_f(&cVar_B2qgqmLP, 0.0f);
  numBytes += cPack_init(&cPack_7kx740DA, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_IQCjo6sg, 0.0f);
  numBytes += cVar_init_f(&cVar_jNz6Q2G7, 0.0f);
  numBytes += cVar_init_f(&cVar_m5IJ5Ihq, 0.0f);
  numBytes += cVar_init_f(&cVar_jUppPZLK, 0.0f);
  numBytes += cVar_init_f(&cVar_5dhh83sZ, 0.0f);
  numBytes += cExpr_init(&cExpr_P6YKKPiA, &Heavy_monosynth::cExpr_P6YKKPiA_evaluate);
  numBytes += cExpr_init(&cExpr_DseywbcZ, &Heavy_monosynth::cExpr_DseywbcZ_evaluate);
  numBytes += cExpr_init(&cExpr_CJLkY1vC, &Heavy_monosynth::cExpr_CJLkY1vC_evaluate);
  numBytes += cVar_init_f(&cVar_KznjI4bV, 0.0f);
  numBytes += sVarf_init(&sVarf_Et7gkvRE, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_G1cSNLVq, 0.0f);
  numBytes += cVar_init_f(&cVar_JQNmzJVQ, 0.0f);
  numBytes += cExpr_init(&cExpr_DlgCv3Ip, &Heavy_monosynth::cExpr_DlgCv3Ip_evaluate);
  numBytes += sVarf_init(&sVarf_afQ3ituN, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_monosynth::~Heavy_monosynth() {
  cExpr_free(&cExpr_FRC486nf);
  cExpr_free(&cExpr_p3VIWGTG);
  cExpr_free(&cExpr_TMzRHgEB);
  cPack_free(&cPack_7kx740DA);
  cExpr_free(&cExpr_P6YKKPiA);
  cExpr_free(&cExpr_DseywbcZ);
  cExpr_free(&cExpr_CJLkY1vC);
  cExpr_free(&cExpr_DlgCv3Ip);
}

HvTable *Heavy_monosynth::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_monosynth::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xE0DDF12E: { // _1_wvform_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KBSsdSkl_sendMessage);
      break;
    }
    case 0xAEA003E7: { // _2_PWM_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_67dOCskv_sendMessage);
      break;
    }
    case 0x1400CF4A: { // _3_cutoff_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SrAHwRo0_sendMessage);
      break;
    }
    case 0x76662EAD: { // _4_Attack_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gWTtaS78_sendMessage);
      break;
    }
    case 0xEDB1071A: { // _5_Decay_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kPYjXeeF_sendMessage);
      break;
    }
    case 0x46C2E2B6: { // _6_Sustain_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_czagpNLf_sendMessage);
      break;
    }
    case 0x59614F9D: { // _7_Release_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3dccnCC3_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9kTnKoWY_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pMQ3YC0X_sendMessage);
      break;
    }
    case 0x9ABB563A: { // fltrenv_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FiLhHVOs_sendMessage);
      break;
    }
    case 0x3E80BBC2: { // fltrrez_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zTPOUaOw_sendMessage);
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


void Heavy_monosynth::cSlice_qUdOgkAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_lozKpbBX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cSlice_VGHGxKOU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_6dM6OEs2, 0, m, &cIf_6dM6OEs2_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_lMFUTh6Y, 0, m, &cIf_lMFUTh6Y_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cSlice_IFYTI6G8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_FXsOi8CQ, 0, m, &cIf_FXsOi8CQ_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_5um8yXaT, 0, m, &cIf_5um8yXaT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cVar_VSfxams3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_hmn1VDyO_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_DW4alz7B, 0, m, &cIf_DW4alz7B_sendMessage);
}

void Heavy_monosynth::cUnop_zflCJyDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_vH5E66QX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zhBcdayC, HV_BINOP_EQ, 1, m, &cBinop_zhBcdayC_sendMessage);
}

void Heavy_monosynth::cUnop_y1pt6zFi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_vH5E66QX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zhBcdayC, HV_BINOP_EQ, 1, m, &cBinop_zhBcdayC_sendMessage);
}

void Heavy_monosynth::cIf_DW4alz7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_y1pt6zFi_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_zflCJyDL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cBinop_hmn1VDyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_DW4alz7B, 1, m, &cIf_DW4alz7B_sendMessage);
}

void Heavy_monosynth::cIf_lMFUTh6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_Q7yzbo6J_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cIf_5um8yXaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_b6ONZU3v_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cIf_6dM6OEs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_Q7yzbo6J_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cIf_FXsOi8CQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_b6ONZU3v_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cBinop_lozKpbBX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zhBcdayC, HV_BINOP_EQ, 0, m, &cBinop_zhBcdayC_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_DCAT8cI4_sendMessage);
}

void Heavy_monosynth::cBinop_vH5E66QX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_x9oXEb8O_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EEWRbZZW_sendMessage);
}

void Heavy_monosynth::cBinop_zhBcdayC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HVZtIhpB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ewKGzM7d_sendMessage);
}

void Heavy_monosynth::cCast_ewKGzM7d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_FXsOi8CQ, 1, m, &cIf_FXsOi8CQ_sendMessage);
}

void Heavy_monosynth::cCast_HVZtIhpB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lMFUTh6Y, 1, m, &cIf_lMFUTh6Y_sendMessage);
}

void Heavy_monosynth::cCast_x9oXEb8O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6dM6OEs2, 1, m, &cIf_6dM6OEs2_sendMessage);
}

void Heavy_monosynth::cCast_EEWRbZZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5um8yXaT, 1, m, &cIf_5um8yXaT_sendMessage);
}

void Heavy_monosynth::cBinop_DCAT8cI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_monosynth::cBinop_tNc8VFQr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_B8Uleb8r, m);
}

void Heavy_monosynth::cBinop_b6ONZU3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_gENwZuDe_sendMessage);
}

void Heavy_monosynth::cBinop_gENwZuDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CWsziEwU, HV_BINOP_POW, 1, m, &cBinop_CWsziEwU_sendMessage);
  cMsg_ctMfT5ou_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cBinop_CWsziEwU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_tNc8VFQr_sendMessage);
}

void Heavy_monosynth::cMsg_ctMfT5ou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CWsziEwU, HV_BINOP_POW, 0, m, &cBinop_CWsziEwU_sendMessage);
}

void Heavy_monosynth::cExpr_FRC486nf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KGLJr3ZS, m);
}

float Heavy_monosynth::cExpr_FRC486nf_evaluate(const float* args) {
  	return 1-((float)(args[0]));
}

void Heavy_monosynth::cExpr_p3VIWGTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fS1Wln3l, m);
}

float Heavy_monosynth::cExpr_p3VIWGTG_evaluate(const float* args) {
  	return ((float)(args[0]))*0.5f+0.5f;
}

void Heavy_monosynth::cVar_2l6CDLy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_p3VIWGTG, 0, m, &cExpr_p3VIWGTG_sendMessage);
}

void Heavy_monosynth::cMsg_n4K1MKjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rTgPhpE0_sendMessage);
}

void Heavy_monosynth::cSystem_rTgPhpE0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XCbEP0mi_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_QMY4Ggzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_tgRAL2fV_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_n5YfUWQD, 0, m, &cIf_n5YfUWQD_sendMessage);
}

void Heavy_monosynth::cIf_n5YfUWQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_tIaoGoRE_sendMessage(_c, 0, m);
      cMsg_lqRaIRDG_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_ZJowdL08_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_KZM2TsF0_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_KcB5rLFd, m);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cBinop_tgRAL2fV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_n5YfUWQD, 1, m, &cIf_n5YfUWQD_sendMessage);
}

void Heavy_monosynth::cMsg_ZJowdL08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_RbupiEJe_sendMessage);
}

void Heavy_monosynth::cBinop_RbupiEJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XwrxV3j9, m);
}

void Heavy_monosynth::cBinop_KZM2TsF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w6mFhFn7_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cMsg_w6mFhFn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Im61vpvj_sendMessage);
}

void Heavy_monosynth::cBinop_Im61vpvj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UbGEOpM5_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cMsg_UbGEOpM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_3NdWBMUx_sendMessage);
}

void Heavy_monosynth::cBinop_3NdWBMUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_s125NIxo, m);
}

void Heavy_monosynth::cBinop_gDTUiI3t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hzRdtW2E, m);
}

void Heavy_monosynth::cMsg_XCbEP0mi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_gDTUiI3t_sendMessage);
}

void Heavy_monosynth::cMsg_tIaoGoRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_KZM2TsF0_sendMessage);
}

void Heavy_monosynth::cMsg_lqRaIRDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_XwrxV3j9, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_KcB5rLFd, m);
}

void Heavy_monosynth::cMsg_fUcyIoWq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WvsLSOFJ_sendMessage);
}

void Heavy_monosynth::cSystem_WvsLSOFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Py8dyRp7_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_95UCrsWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_QA67dBPv_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NWgrqZe3, 0, m, &cIf_NWgrqZe3_sendMessage);
}

void Heavy_monosynth::cIf_NWgrqZe3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_OOY7FVJR_sendMessage(_c, 0, m);
      cMsg_vwbftYCD_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_HnnxLN2i_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_5YBtiPn8_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_wMig5v2o, m);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cBinop_QA67dBPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NWgrqZe3, 1, m, &cIf_NWgrqZe3_sendMessage);
}

void Heavy_monosynth::cMsg_HnnxLN2i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_g9XHfoRJ_sendMessage);
}

void Heavy_monosynth::cBinop_g9XHfoRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GA3osnfR, m);
}

void Heavy_monosynth::cBinop_5YBtiPn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KoKbyzCP_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cMsg_KoKbyzCP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_GEGmHTY2_sendMessage);
}

void Heavy_monosynth::cBinop_GEGmHTY2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CcblmiYb_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cMsg_CcblmiYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_OaQf3OZX_sendMessage);
}

void Heavy_monosynth::cBinop_OaQf3OZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kRWD6jUO, m);
}

void Heavy_monosynth::cBinop_xtBLM9SF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AQlhxHp1, m);
}

void Heavy_monosynth::cMsg_Py8dyRp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_xtBLM9SF_sendMessage);
}

void Heavy_monosynth::cMsg_OOY7FVJR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_5YBtiPn8_sendMessage);
}

void Heavy_monosynth::cMsg_vwbftYCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GA3osnfR, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_wMig5v2o, m);
}

void Heavy_monosynth::cVar_xKsiCVlA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QMY4Ggzg, 0, m, &cVar_QMY4Ggzg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_95UCrsWy, 0, m, &cVar_95UCrsWy_sendMessage);
}

void Heavy_monosynth::cExpr_TMzRHgEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xKsiCVlA, 0, m, &cVar_xKsiCVlA_sendMessage);
}

float Heavy_monosynth::cExpr_TMzRHgEB_evaluate(const float* args) {
  	return hv_pow_f(8 , ((float)(args[0])));
}

void Heavy_monosynth::cVar_hndAACsC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_TMzRHgEB, 0, m, &cExpr_TMzRHgEB_sendMessage);
}

void Heavy_monosynth::cVar_giAkG6l3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_afQ3ituN, m);
}

void Heavy_monosynth::cVar_aBK3nt8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_DseywbcZ, 0, m, &cExpr_DseywbcZ_sendMessage);
}

void Heavy_monosynth::cVar_y37kE4Wk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jUppPZLK, 1, m, &cVar_jUppPZLK_sendMessage);
}

void Heavy_monosynth::cVar_B2qgqmLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_P6YKKPiA, 0, m, &cExpr_P6YKKPiA_sendMessage);
}

void Heavy_monosynth::cPack_7kx740DA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_8prVuuq1, 0, m, NULL);
}

void Heavy_monosynth::cCast_DduyPFqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jNz6Q2G7, 0, m, &cVar_jNz6Q2G7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CtRUJw7Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CjHTu4RT_sendMessage);
}

void Heavy_monosynth::cSwitchcase_Q7yzbo6J_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ShWcOzXS_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DduyPFqu_sendMessage);
      break;
    }
  }
}

void Heavy_monosynth::cCast_ShWcOzXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qiOac40Z_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_m5IJ5Ihq, 0, m, &cVar_m5IJ5Ihq_sendMessage);
}

void Heavy_monosynth::cSwitchcase_otkHPbH7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_IKgkyohN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_IKgkyohN_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_IQCjo6sg, 1, m, &cDelay_IQCjo6sg_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3brJOABW_sendMessage);
      break;
    }
  }
}

void Heavy_monosynth::cDelay_IQCjo6sg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IQCjo6sg, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jUppPZLK, 0, m, &cVar_jUppPZLK_sendMessage);
}

void Heavy_monosynth::cMsg_IKgkyohN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_IQCjo6sg, 0, m, &cDelay_IQCjo6sg_sendMessage);
}

void Heavy_monosynth::cCast_3brJOABW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IQCjo6sg, 0, m, &cDelay_IQCjo6sg_sendMessage);
}

void Heavy_monosynth::cVar_jNz6Q2G7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Hxvmgoyc_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_m5IJ5Ihq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RzGwFQAZ_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_jUppPZLK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7kx740DA, 0, m, &cPack_7kx740DA_sendMessage);
}

void Heavy_monosynth::cVar_5dhh83sZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_8prVuuq1, 0, m, NULL);
}

void Heavy_monosynth::cExpr_P6YKKPiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_m5IJ5Ihq, 1, m, &cVar_m5IJ5Ihq_sendMessage);
}

float Heavy_monosynth::cExpr_P6YKKPiA_evaluate(const float* args) {
  	return hv_pow_f(10 , 4.5f*((float)(args[0])));
}

void Heavy_monosynth::cExpr_DseywbcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7kx740DA, 1, m, &cPack_7kx740DA_sendMessage);
}

float Heavy_monosynth::cExpr_DseywbcZ_evaluate(const float* args) {
  	return hv_pow_f(10 , 4*((float)(args[0])));
}

void Heavy_monosynth::cExpr_CJLkY1vC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jNz6Q2G7, 1, m, &cVar_jNz6Q2G7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IQCjo6sg, 1, m, &cDelay_IQCjo6sg_sendMessage);
}

float Heavy_monosynth::cExpr_CJLkY1vC_evaluate(const float* args) {
  	return 2+hv_pow_f(10 , 4*((float)(args[0])));
}

void Heavy_monosynth::cMsg_RzGwFQAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_8prVuuq1, 0, m, NULL);
}

void Heavy_monosynth::cMsg_Hxvmgoyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_8prVuuq1, 0, m, NULL);
}

void Heavy_monosynth::cMsg_qiOac40Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_otkHPbH7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_monosynth::cCast_CjHTu4RT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_otkHPbH7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_monosynth::cCast_CtRUJw7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qiOac40Z_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_KznjI4bV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_DlgCv3Ip, 0, m, &cExpr_DlgCv3Ip_sendMessage);
}

void Heavy_monosynth::cVar_G1cSNLVq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_z8zpjddP, m);
  cExpr_onMessage(_c, &Context(_c)->cExpr_FRC486nf, 0, m, &cExpr_FRC486nf_sendMessage);
}

void Heavy_monosynth::cVar_JQNmzJVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_CJLkY1vC, 0, m, &cExpr_CJLkY1vC_sendMessage);
}

void Heavy_monosynth::cExpr_DlgCv3Ip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Et7gkvRE, m);
}

float Heavy_monosynth::cExpr_DlgCv3Ip_evaluate(const float* args) {
  	return hv_pow_f(2 , 5*((float)(args[0])));
}

void Heavy_monosynth::cReceive_9kTnKoWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n4K1MKjR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QMY4Ggzg, 0, m, &cVar_QMY4Ggzg_sendMessage);
  cMsg_fUcyIoWq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_95UCrsWy, 0, m, &cVar_95UCrsWy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VSfxams3, 0, m, &cVar_VSfxams3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5dhh83sZ, 0, m, &cVar_5dhh83sZ_sendMessage);
}

void Heavy_monosynth::cReceive_pMQ3YC0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_qUdOgkAc, 0, m, &cSlice_qUdOgkAc_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_VGHGxKOU, 0, m, &cSlice_VGHGxKOU_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_IFYTI6G8, 0, m, &cSlice_IFYTI6G8_sendMessage);
}

void Heavy_monosynth::cReceive_67dOCskv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2l6CDLy6, 0, m, &cVar_2l6CDLy6_sendMessage);
}

void Heavy_monosynth::cReceive_zTPOUaOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hndAACsC, 0, m, &cVar_hndAACsC_sendMessage);
}

void Heavy_monosynth::cReceive_FiLhHVOs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_giAkG6l3, 0, m, &cVar_giAkG6l3_sendMessage);
}

void Heavy_monosynth::cReceive_kPYjXeeF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aBK3nt8r, 0, m, &cVar_aBK3nt8r_sendMessage);
}

void Heavy_monosynth::cReceive_czagpNLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y37kE4Wk, 0, m, &cVar_y37kE4Wk_sendMessage);
}

void Heavy_monosynth::cReceive_3dccnCC3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_B2qgqmLP, 0, m, &cVar_B2qgqmLP_sendMessage);
}

void Heavy_monosynth::cReceive_SrAHwRo0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KznjI4bV, 0, m, &cVar_KznjI4bV_sendMessage);
}

void Heavy_monosynth::cReceive_KBSsdSkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_G1cSNLVq, 0, m, &cVar_G1cSNLVq_sendMessage);
}

void Heavy_monosynth::cReceive_gWTtaS78_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JQNmzJVQ, 0, m, &cVar_JQNmzJVQ_sendMessage);
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
    __hv_varread_f(&sVarf_B8Uleb8r, VOf(Bf0));
    __hv_phasor_f(&sPhasor_BBO1i5zX, VIf(Bf0), VOf(Bf1));
    __hv_varread_f(&sVarf_fS1Wln3l, VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f);
    __hv_min_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f);
    __hv_max_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_z8zpjddP, VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf1), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_KGLJr3ZS, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_Et7gkvRE, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_8prVuuq1, VOf(Bf0));
    __hv_varread_f(&sVarf_afQ3ituN, VOf(Bf3));
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
    __hv_varread_f(&sVarf_hzRdtW2E, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_KcB5rLFd, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_XwrxV3j9, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_varread_f(&sVarf_s125NIxo, VOf(Bf2));
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
    __hv_cpole_f(&sCPole_1egQ33SA, VIf(Bf2), VIf(ZERO), VIf(Bf6), VIf(Bf5), VOf(Bf5), VOf(Bf6));
    __hv_varread_f(&sVarf_AQlhxHp1, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_wMig5v2o, VOf(Bf5));
    __hv_min_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_GA3osnfR, VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf6));
    __hv_varread_f(&sVarf_kRWD6jUO, VOf(Bf5));
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
    __hv_cpole_f(&sCPole_V3fTvbtL, VIf(Bf5), VIf(ZERO), VIf(Bf3), VIf(Bf1), VOf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));

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
