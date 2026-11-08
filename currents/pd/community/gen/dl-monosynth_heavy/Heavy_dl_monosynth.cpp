/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside dl-monosynth.pd) */

#include "Heavy_dl_monosynth.hpp"



#define Context(_c) static_cast<Heavy_dl_monosynth *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_dl_monosynth::Heavy_dl_monosynth(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_init(&sPhasor_7YfvkGIt, sampleRate);
  numBytes += sLine_init(&sLine_TUYhJdOp);
  numBytes += sCPole_init(&sCPole_HbOxtrgm);
  numBytes += sCPole_init(&sCPole_50TYMjLx);
  numBytes += cSlice_init(&cSlice_7NmDcDn0, 2, 1);
  numBytes += cSlice_init(&cSlice_pPNIbi8G, 1, 1);
  numBytes += cSlice_init(&cSlice_1qhhVfpe, 0, 1);
  numBytes += cVar_init_f(&cVar_pPJXxFBP, 0.0f);
  numBytes += cIf_init(&cIf_fyQzCwT5, false);
  numBytes += cIf_init(&cIf_uPF605Mx, false);
  numBytes += cIf_init(&cIf_QwFALaD0, false);
  numBytes += cIf_init(&cIf_Uy6pecqx, false);
  numBytes += cIf_init(&cIf_wrUxqXGE, false);
  numBytes += cBinop_init(&cBinop_6B4TfcAl, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_fngHOfzH, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_IPfaLFd0, 0.0f, 0.0f, false);
  numBytes += cExpr_init(&cExpr_ranjbsr4, &Heavy_dl_monosynth::cExpr_ranjbsr4_evaluate);
  numBytes += cExpr_init(&cExpr_jUxyT6To, &Heavy_dl_monosynth::cExpr_jUxyT6To_evaluate);
  numBytes += sVarf_init(&sVarf_dFJ2BDZX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_naeb9PWW, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tNYlQbVh, 0.5f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_hAl8xTgT, 0.0f);
  numBytes += cVar_init_f(&cVar_0qUoi2Vu, 0.0f);
  numBytes += cIf_init(&cIf_rYE8mPGx, false);
  numBytes += sVarf_init(&sVarf_E8Jh81cd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gMqAi5P6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_w6jJKtFs, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5ftm8qbK, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_bwP0OBTg, 0.0f);
  numBytes += cIf_init(&cIf_BbY1aOCX, false);
  numBytes += sVarf_init(&sVarf_hGcHvgKu, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qILMAMG5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4QCRJWfI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_09VJE80F, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ktdqyeVD, 0.707f);
  numBytes += cExpr_init(&cExpr_v3er7kg4, &Heavy_dl_monosynth::cExpr_v3er7kg4_evaluate);
  numBytes += cVar_init_f(&cVar_pnF9aFyD, 0.0f);
  numBytes += cVar_init_f(&cVar_dSpal0HF, 0.0f);
  numBytes += cVar_init_f(&cVar_MMEaqMuK, 0.0f);
  numBytes += cVar_init_f(&cVar_D1gs7t4V, 0.0f);
  numBytes += cVar_init_f(&cVar_rqIHCwT1, 0.0f);
  numBytes += cPack_init(&cPack_daGXYyHo, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Mz8f0rn5, 0.0f);
  numBytes += cVar_init_f(&cVar_ShwnkV2y, 0.0f);
  numBytes += cVar_init_f(&cVar_q6QKufhJ, 0.0f);
  numBytes += cVar_init_f(&cVar_2CYpOFYy, 0.0f);
  numBytes += cVar_init_f(&cVar_rxd6mUF1, 0.0f);
  numBytes += cExpr_init(&cExpr_RYnsZYiY, &Heavy_dl_monosynth::cExpr_RYnsZYiY_evaluate);
  numBytes += cExpr_init(&cExpr_hHrZ4D1s, &Heavy_dl_monosynth::cExpr_hHrZ4D1s_evaluate);
  numBytes += cExpr_init(&cExpr_m6tiz7Pj, &Heavy_dl_monosynth::cExpr_m6tiz7Pj_evaluate);
  numBytes += cVar_init_f(&cVar_nuy7lYnA, 0.0f);
  numBytes += sVarf_init(&sVarf_pGDa00LH, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_kKntqUHX, 0.0f);
  numBytes += cVar_init_f(&cVar_KpieRRF2, 0.0f);
  numBytes += cExpr_init(&cExpr_6CmIvRdy, &Heavy_dl_monosynth::cExpr_6CmIvRdy_evaluate);
  numBytes += sVarf_init(&sVarf_IZdtzN35, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_dl_monosynth::~Heavy_dl_monosynth() {
  cExpr_free(&cExpr_ranjbsr4);
  cExpr_free(&cExpr_jUxyT6To);
  cExpr_free(&cExpr_v3er7kg4);
  cPack_free(&cPack_daGXYyHo);
  cExpr_free(&cExpr_RYnsZYiY);
  cExpr_free(&cExpr_hHrZ4D1s);
  cExpr_free(&cExpr_m6tiz7Pj);
  cExpr_free(&cExpr_6CmIvRdy);
}

HvTable *Heavy_dl_monosynth::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_dl_monosynth::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xE0DDF12E: { // _1_wvform_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1VGemouj_sendMessage);
      break;
    }
    case 0xAEA003E7: { // _2_PWM_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lVSdmDAX_sendMessage);
      break;
    }
    case 0x1400CF4A: { // _3_cutoff_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ucayq2ay_sendMessage);
      break;
    }
    case 0x76662EAD: { // _4_Attack_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xpalY60f_sendMessage);
      break;
    }
    case 0xEDB1071A: { // _5_Decay_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2wZ9OPhj_sendMessage);
      break;
    }
    case 0x46C2E2B6: { // _6_Sustain_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xzHGfWZs_sendMessage);
      break;
    }
    case 0x59614F9D: { // _7_Release_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_i4XKaBwI_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eEdgmI1e_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qkjU1HHM_sendMessage);
      break;
    }
    case 0x9ABB563A: { // fltrenv_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_p6suGxM9_sendMessage);
      break;
    }
    case 0x3E80BBC2: { // fltrrez_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xmD4NhJL_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_dl_monosynth::getParameterInfo(int index, HvParameterInfo *info) {
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


void Heavy_dl_monosynth::cSlice_7NmDcDn0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_QLHFFgxF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cSlice_pPNIbi8G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_Uy6pecqx, 0, m, &cIf_Uy6pecqx_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_uPF605Mx, 0, m, &cIf_uPF605Mx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cSlice_1qhhVfpe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_wrUxqXGE, 0, m, &cIf_wrUxqXGE_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_QwFALaD0, 0, m, &cIf_QwFALaD0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cVar_pPJXxFBP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_farccMaA_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_fyQzCwT5, 0, m, &cIf_fyQzCwT5_sendMessage);
}

void Heavy_dl_monosynth::cUnop_rY8TkhLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_k3Lo08pO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6B4TfcAl, HV_BINOP_EQ, 1, m, &cBinop_6B4TfcAl_sendMessage);
}

void Heavy_dl_monosynth::cUnop_uecBgNqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_k3Lo08pO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6B4TfcAl, HV_BINOP_EQ, 1, m, &cBinop_6B4TfcAl_sendMessage);
}

void Heavy_dl_monosynth::cIf_fyQzCwT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_uecBgNqo_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_rY8TkhLk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cBinop_farccMaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_fyQzCwT5, 1, m, &cIf_fyQzCwT5_sendMessage);
}

void Heavy_dl_monosynth::cIf_uPF605Mx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_Jr2dKB8C_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cIf_QwFALaD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_q940tnwP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cIf_Uy6pecqx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_Jr2dKB8C_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cIf_wrUxqXGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_q940tnwP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cBinop_QLHFFgxF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6B4TfcAl, HV_BINOP_EQ, 0, m, &cBinop_6B4TfcAl_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_zOSIQ3Cu_sendMessage);
}

void Heavy_dl_monosynth::cBinop_k3Lo08pO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zv8QiPwy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Fe36djB9_sendMessage);
}

void Heavy_dl_monosynth::cBinop_6B4TfcAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_i8Sg0Zcc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rC0QGqSv_sendMessage);
}

void Heavy_dl_monosynth::cCast_rC0QGqSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wrUxqXGE, 1, m, &cIf_wrUxqXGE_sendMessage);
}

void Heavy_dl_monosynth::cCast_i8Sg0Zcc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uPF605Mx, 1, m, &cIf_uPF605Mx_sendMessage);
}

void Heavy_dl_monosynth::cCast_Fe36djB9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_QwFALaD0, 1, m, &cIf_QwFALaD0_sendMessage);
}

void Heavy_dl_monosynth::cCast_zv8QiPwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Uy6pecqx, 1, m, &cIf_Uy6pecqx_sendMessage);
}

void Heavy_dl_monosynth::cBinop_zOSIQ3Cu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_dl_monosynth::cBinop_YD9qm0Fp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IPfaLFd0, m);
}

void Heavy_dl_monosynth::cBinop_q940tnwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_yyYBwNDQ_sendMessage);
}

void Heavy_dl_monosynth::cBinop_yyYBwNDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fngHOfzH, HV_BINOP_POW, 1, m, &cBinop_fngHOfzH_sendMessage);
  cMsg_kMdm3WCq_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cBinop_fngHOfzH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_YD9qm0Fp_sendMessage);
}

void Heavy_dl_monosynth::cMsg_kMdm3WCq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fngHOfzH, HV_BINOP_POW, 0, m, &cBinop_fngHOfzH_sendMessage);
}

void Heavy_dl_monosynth::cExpr_ranjbsr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_naeb9PWW, m);
}

float Heavy_dl_monosynth::cExpr_ranjbsr4_evaluate(const float* args) {
  	return 1-((float)(args[0]));
}

void Heavy_dl_monosynth::cExpr_jUxyT6To_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tNYlQbVh, m);
}

float Heavy_dl_monosynth::cExpr_jUxyT6To_evaluate(const float* args) {
  	return ((float)(args[0]))*0.5f+0.5f;
}

void Heavy_dl_monosynth::cVar_hAl8xTgT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_jUxyT6To, 0, m, &cExpr_jUxyT6To_sendMessage);
}

void Heavy_dl_monosynth::cMsg_iTS0a9Vg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OKOlaEUN_sendMessage);
}

void Heavy_dl_monosynth::cSystem_OKOlaEUN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vBcCsNSl_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cVar_0qUoi2Vu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_h1tygeHC_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_rYE8mPGx, 0, m, &cIf_rYE8mPGx_sendMessage);
}

void Heavy_dl_monosynth::cIf_rYE8mPGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_01ORAOuV_sendMessage(_c, 0, m);
      cMsg_Ow3XB07L_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_fjD3s436_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_BpfPOhF9_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_5ftm8qbK, m);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cBinop_h1tygeHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rYE8mPGx, 1, m, &cIf_rYE8mPGx_sendMessage);
}

void Heavy_dl_monosynth::cMsg_fjD3s436_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_L0XuFPiD_sendMessage);
}

void Heavy_dl_monosynth::cBinop_L0XuFPiD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gMqAi5P6, m);
}

void Heavy_dl_monosynth::cBinop_BpfPOhF9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1abazFFB_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cMsg_1abazFFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_yBq34Ev0_sendMessage);
}

void Heavy_dl_monosynth::cBinop_yBq34Ev0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iGbhyWih_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cMsg_iGbhyWih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_1hJ75H42_sendMessage);
}

void Heavy_dl_monosynth::cBinop_1hJ75H42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_w6jJKtFs, m);
}

void Heavy_dl_monosynth::cBinop_zXlwHxal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_E8Jh81cd, m);
}

void Heavy_dl_monosynth::cMsg_vBcCsNSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zXlwHxal_sendMessage);
}

void Heavy_dl_monosynth::cMsg_01ORAOuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_BpfPOhF9_sendMessage);
}

void Heavy_dl_monosynth::cMsg_Ow3XB07L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gMqAi5P6, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_5ftm8qbK, m);
}

void Heavy_dl_monosynth::cMsg_LdPcqCvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vovKkuHE_sendMessage);
}

void Heavy_dl_monosynth::cSystem_vovKkuHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qR26VIhz_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cVar_bwP0OBTg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_Q2yE8fYd_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_BbY1aOCX, 0, m, &cIf_BbY1aOCX_sendMessage);
}

void Heavy_dl_monosynth::cIf_BbY1aOCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_8lY4JMFW_sendMessage(_c, 0, m);
      cMsg_8dNzrShq_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_ZXW0qNeC_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_4zi7rFV3_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_09VJE80F, m);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cBinop_Q2yE8fYd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BbY1aOCX, 1, m, &cIf_BbY1aOCX_sendMessage);
}

void Heavy_dl_monosynth::cMsg_ZXW0qNeC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_r8WytHfm_sendMessage);
}

void Heavy_dl_monosynth::cBinop_r8WytHfm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qILMAMG5, m);
}

void Heavy_dl_monosynth::cBinop_4zi7rFV3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4Dlm0bkQ_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cMsg_4Dlm0bkQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_W5X3PHAe_sendMessage);
}

void Heavy_dl_monosynth::cBinop_W5X3PHAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JbkNIAe6_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cMsg_JbkNIAe6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ulcPwypy_sendMessage);
}

void Heavy_dl_monosynth::cBinop_ulcPwypy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4QCRJWfI, m);
}

void Heavy_dl_monosynth::cBinop_zX5tGFgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hGcHvgKu, m);
}

void Heavy_dl_monosynth::cMsg_qR26VIhz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zX5tGFgf_sendMessage);
}

void Heavy_dl_monosynth::cMsg_8lY4JMFW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_4zi7rFV3_sendMessage);
}

void Heavy_dl_monosynth::cMsg_8dNzrShq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_qILMAMG5, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_09VJE80F, m);
}

void Heavy_dl_monosynth::cVar_ktdqyeVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0qUoi2Vu, 0, m, &cVar_0qUoi2Vu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bwP0OBTg, 0, m, &cVar_bwP0OBTg_sendMessage);
}

void Heavy_dl_monosynth::cExpr_v3er7kg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ktdqyeVD, 0, m, &cVar_ktdqyeVD_sendMessage);
}

float Heavy_dl_monosynth::cExpr_v3er7kg4_evaluate(const float* args) {
  	return hv_pow_f(8 , ((float)(args[0])));
}

void Heavy_dl_monosynth::cVar_pnF9aFyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_v3er7kg4, 0, m, &cExpr_v3er7kg4_sendMessage);
}

void Heavy_dl_monosynth::cVar_dSpal0HF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IZdtzN35, m);
}

void Heavy_dl_monosynth::cVar_MMEaqMuK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_hHrZ4D1s, 0, m, &cExpr_hHrZ4D1s_sendMessage);
}

void Heavy_dl_monosynth::cVar_D1gs7t4V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2CYpOFYy, 1, m, &cVar_2CYpOFYy_sendMessage);
}

void Heavy_dl_monosynth::cVar_rqIHCwT1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_RYnsZYiY, 0, m, &cExpr_RYnsZYiY_sendMessage);
}

void Heavy_dl_monosynth::cPack_daGXYyHo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_TUYhJdOp, 0, m, NULL);
}

void Heavy_dl_monosynth::cCast_cql1z6pN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ShwnkV2y, 0, m, &cVar_ShwnkV2y_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Bhr746FA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OcIuzlkG_sendMessage);
}

void Heavy_dl_monosynth::cSwitchcase_Jr2dKB8C_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cFnLZRc0_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cql1z6pN_sendMessage);
      break;
    }
  }
}

void Heavy_dl_monosynth::cCast_cFnLZRc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TBzCF1E0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_q6QKufhJ, 0, m, &cVar_q6QKufhJ_sendMessage);
}

void Heavy_dl_monosynth::cSwitchcase_iQ0lwIY0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_a1P5Bb2b_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_a1P5Bb2b_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Mz8f0rn5, 1, m, &cDelay_Mz8f0rn5_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FR7ubPuN_sendMessage);
      break;
    }
  }
}

void Heavy_dl_monosynth::cDelay_Mz8f0rn5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Mz8f0rn5, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2CYpOFYy, 0, m, &cVar_2CYpOFYy_sendMessage);
}

void Heavy_dl_monosynth::cMsg_a1P5Bb2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Mz8f0rn5, 0, m, &cDelay_Mz8f0rn5_sendMessage);
}

void Heavy_dl_monosynth::cCast_FR7ubPuN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Mz8f0rn5, 0, m, &cDelay_Mz8f0rn5_sendMessage);
}

void Heavy_dl_monosynth::cVar_ShwnkV2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nRWZG7D6_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cVar_q6QKufhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CLluoA3a_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cVar_2CYpOFYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_daGXYyHo, 0, m, &cPack_daGXYyHo_sendMessage);
}

void Heavy_dl_monosynth::cVar_rxd6mUF1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_TUYhJdOp, 0, m, NULL);
}

void Heavy_dl_monosynth::cExpr_RYnsZYiY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_q6QKufhJ, 1, m, &cVar_q6QKufhJ_sendMessage);
}

float Heavy_dl_monosynth::cExpr_RYnsZYiY_evaluate(const float* args) {
  	return hv_pow_f(10 , 4.5f*((float)(args[0])));
}

void Heavy_dl_monosynth::cExpr_hHrZ4D1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_daGXYyHo, 1, m, &cPack_daGXYyHo_sendMessage);
}

float Heavy_dl_monosynth::cExpr_hHrZ4D1s_evaluate(const float* args) {
  	return hv_pow_f(10 , 4*((float)(args[0])));
}

void Heavy_dl_monosynth::cExpr_m6tiz7Pj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ShwnkV2y, 1, m, &cVar_ShwnkV2y_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Mz8f0rn5, 1, m, &cDelay_Mz8f0rn5_sendMessage);
}

float Heavy_dl_monosynth::cExpr_m6tiz7Pj_evaluate(const float* args) {
  	return 2+hv_pow_f(10 , 4*((float)(args[0])));
}

void Heavy_dl_monosynth::cMsg_CLluoA3a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_TUYhJdOp, 0, m, NULL);
}

void Heavy_dl_monosynth::cMsg_nRWZG7D6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_TUYhJdOp, 0, m, NULL);
}

void Heavy_dl_monosynth::cMsg_TBzCF1E0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_iQ0lwIY0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_dl_monosynth::cCast_Bhr746FA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TBzCF1E0_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cCast_OcIuzlkG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_iQ0lwIY0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_dl_monosynth::cVar_nuy7lYnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_6CmIvRdy, 0, m, &cExpr_6CmIvRdy_sendMessage);
}

void Heavy_dl_monosynth::cVar_kKntqUHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dFJ2BDZX, m);
  cExpr_onMessage(_c, &Context(_c)->cExpr_ranjbsr4, 0, m, &cExpr_ranjbsr4_sendMessage);
}

void Heavy_dl_monosynth::cVar_KpieRRF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_m6tiz7Pj, 0, m, &cExpr_m6tiz7Pj_sendMessage);
}

void Heavy_dl_monosynth::cExpr_6CmIvRdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pGDa00LH, m);
}

float Heavy_dl_monosynth::cExpr_6CmIvRdy_evaluate(const float* args) {
  	return hv_pow_f(2 , 5*((float)(args[0])));
}

void Heavy_dl_monosynth::cReceive_eEdgmI1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iTS0a9Vg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0qUoi2Vu, 0, m, &cVar_0qUoi2Vu_sendMessage);
  cMsg_LdPcqCvw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bwP0OBTg, 0, m, &cVar_bwP0OBTg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pPJXxFBP, 0, m, &cVar_pPJXxFBP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rxd6mUF1, 0, m, &cVar_rxd6mUF1_sendMessage);
}

void Heavy_dl_monosynth::cReceive_qkjU1HHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_7NmDcDn0, 0, m, &cSlice_7NmDcDn0_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_pPNIbi8G, 0, m, &cSlice_pPNIbi8G_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1qhhVfpe, 0, m, &cSlice_1qhhVfpe_sendMessage);
}

void Heavy_dl_monosynth::cReceive_lVSdmDAX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hAl8xTgT, 0, m, &cVar_hAl8xTgT_sendMessage);
}

void Heavy_dl_monosynth::cReceive_xmD4NhJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pnF9aFyD, 0, m, &cVar_pnF9aFyD_sendMessage);
}

void Heavy_dl_monosynth::cReceive_p6suGxM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dSpal0HF, 0, m, &cVar_dSpal0HF_sendMessage);
}

void Heavy_dl_monosynth::cReceive_2wZ9OPhj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MMEaqMuK, 0, m, &cVar_MMEaqMuK_sendMessage);
}

void Heavy_dl_monosynth::cReceive_xzHGfWZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_D1gs7t4V, 0, m, &cVar_D1gs7t4V_sendMessage);
}

void Heavy_dl_monosynth::cReceive_i4XKaBwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rqIHCwT1, 0, m, &cVar_rqIHCwT1_sendMessage);
}

void Heavy_dl_monosynth::cReceive_Ucayq2ay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nuy7lYnA, 0, m, &cVar_nuy7lYnA_sendMessage);
}

void Heavy_dl_monosynth::cReceive_1VGemouj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kKntqUHX, 0, m, &cVar_kKntqUHX_sendMessage);
}

void Heavy_dl_monosynth::cReceive_xpalY60f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KpieRRF2, 0, m, &cVar_KpieRRF2_sendMessage);
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

int Heavy_dl_monosynth::process(float **inputBuffers, float **outputBuffers, int n) {
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
    __hv_varread_f(&sVarf_IPfaLFd0, VOf(Bf0));
    __hv_phasor_f(&sPhasor_7YfvkGIt, VIf(Bf0), VOf(Bf1));
    __hv_varread_f(&sVarf_tNYlQbVh, VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f);
    __hv_min_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f);
    __hv_max_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_dFJ2BDZX, VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf1), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_naeb9PWW, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_pGDa00LH, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_TUYhJdOp, VOf(Bf0));
    __hv_varread_f(&sVarf_IZdtzN35, VOf(Bf3));
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
    __hv_varread_f(&sVarf_E8Jh81cd, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_5ftm8qbK, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_gMqAi5P6, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_varread_f(&sVarf_w6jJKtFs, VOf(Bf2));
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
    __hv_cpole_f(&sCPole_HbOxtrgm, VIf(Bf2), VIf(ZERO), VIf(Bf6), VIf(Bf5), VOf(Bf5), VOf(Bf6));
    __hv_varread_f(&sVarf_hGcHvgKu, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_09VJE80F, VOf(Bf5));
    __hv_min_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_qILMAMG5, VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf6));
    __hv_varread_f(&sVarf_4QCRJWfI, VOf(Bf5));
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
    __hv_cpole_f(&sCPole_50TYMjLx, VIf(Bf5), VIf(ZERO), VIf(Bf3), VIf(Bf1), VOf(Bf1), VOf(Bf3));
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

int Heavy_dl_monosynth::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_dl_monosynth::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
