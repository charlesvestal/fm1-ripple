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
  numBytes += sPhasor_init(&sPhasor_8EgUUrf2, sampleRate);
  numBytes += sLine_init(&sLine_WUe70ZtI);
  numBytes += sCPole_init(&sCPole_OIB0bhlr);
  numBytes += sCPole_init(&sCPole_lDz5CpiA);
  numBytes += cSlice_init(&cSlice_oZSgk1Os, 2, 1);
  numBytes += cSlice_init(&cSlice_u9ofHdPn, 1, 1);
  numBytes += cSlice_init(&cSlice_t2qPYfPc, 0, 1);
  numBytes += cVar_init_f(&cVar_V27mdvbb, 0.0f);
  numBytes += cIf_init(&cIf_sXEuzTS9, false);
  numBytes += cIf_init(&cIf_bpKD3EGL, false);
  numBytes += cIf_init(&cIf_CMMHM19H, false);
  numBytes += cIf_init(&cIf_Id2I314n, false);
  numBytes += cIf_init(&cIf_7pN3myWB, false);
  numBytes += cBinop_init(&cBinop_KWVOSPpj, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_GVgDij1M, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_6Cjd9u7Y, 0.0f, 0.0f, false);
  numBytes += cExpr_init(&cExpr_rdcOi8KB, &Heavy_monosynth::cExpr_rdcOi8KB_evaluate);
  numBytes += cExpr_init(&cExpr_YjUnVMrk, &Heavy_monosynth::cExpr_YjUnVMrk_evaluate);
  numBytes += sVarf_init(&sVarf_7e7KeGRT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3t4nHor0, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_EpO0Wdvl, 0.5f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_T20a6bZC, 0.0f);
  numBytes += cVar_init_f(&cVar_Ghx8ZwSZ, 0.0f);
  numBytes += cIf_init(&cIf_SgKgRelV, false);
  numBytes += sVarf_init(&sVarf_lmYjoFKO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Ry21ZBv4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_yeg3zno8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TOe6v1Ph, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Jsrpl2fy, 0.0f);
  numBytes += cIf_init(&cIf_vkWW0COg, false);
  numBytes += sVarf_init(&sVarf_sINFgpne, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LXJyscWA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_DJKj7UD3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3lsdJ72i, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_9Xuo8KpD, 0.707f);
  numBytes += cExpr_init(&cExpr_5SkLQ7CY, &Heavy_monosynth::cExpr_5SkLQ7CY_evaluate);
  numBytes += cVar_init_f(&cVar_Y2yjzhI6, 0.0f);
  numBytes += cVar_init_f(&cVar_FpOStlgm, 0.0f);
  numBytes += cVar_init_f(&cVar_97FQZMPP, 0.0f);
  numBytes += cVar_init_f(&cVar_QkMOklh6, 0.0f);
  numBytes += cVar_init_f(&cVar_o0MgnFlV, 0.0f);
  numBytes += cPack_init(&cPack_YVcURIer, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_7necLe9w, 0.0f);
  numBytes += cVar_init_f(&cVar_Xcd2jm0s, 0.0f);
  numBytes += cVar_init_f(&cVar_wjPIYRos, 0.0f);
  numBytes += cVar_init_f(&cVar_kuJ0Hkl2, 0.0f);
  numBytes += cVar_init_f(&cVar_7DuElKRU, 0.0f);
  numBytes += cExpr_init(&cExpr_isBwYll6, &Heavy_monosynth::cExpr_isBwYll6_evaluate);
  numBytes += cExpr_init(&cExpr_EX90xDhd, &Heavy_monosynth::cExpr_EX90xDhd_evaluate);
  numBytes += cExpr_init(&cExpr_7HZX0nrK, &Heavy_monosynth::cExpr_7HZX0nrK_evaluate);
  numBytes += cVar_init_f(&cVar_eOGoq542, 0.0f);
  numBytes += sVarf_init(&sVarf_PjqoedRN, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_xR03DItS, 0.0f);
  numBytes += cVar_init_f(&cVar_ym6fRlhk, 0.0f);
  numBytes += cExpr_init(&cExpr_ZbAa0fze, &Heavy_monosynth::cExpr_ZbAa0fze_evaluate);
  numBytes += sVarf_init(&sVarf_GRVRyUWq, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_monosynth::~Heavy_monosynth() {
  cExpr_free(&cExpr_rdcOi8KB);
  cExpr_free(&cExpr_YjUnVMrk);
  cExpr_free(&cExpr_5SkLQ7CY);
  cPack_free(&cPack_YVcURIer);
  cExpr_free(&cExpr_isBwYll6);
  cExpr_free(&cExpr_EX90xDhd);
  cExpr_free(&cExpr_7HZX0nrK);
  cExpr_free(&cExpr_ZbAa0fze);
}

HvTable *Heavy_monosynth::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_monosynth::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xE0DDF12E: { // _1_wvform_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_M3ec8UCa_sendMessage);
      break;
    }
    case 0xAEA003E7: { // _2_PWM_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2vTiZ12Q_sendMessage);
      break;
    }
    case 0x1400CF4A: { // _3_cutoff_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_t1qZ95Im_sendMessage);
      break;
    }
    case 0x76662EAD: { // _4_Attack_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xMVHVwa7_sendMessage);
      break;
    }
    case 0xEDB1071A: { // _5_Decay_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_J3tJzPOL_sendMessage);
      break;
    }
    case 0x46C2E2B6: { // _6_Sustain_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bFs19Zmf_sendMessage);
      break;
    }
    case 0x59614F9D: { // _7_Release_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7kog7rFG_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_l3bjyCOy_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jhlXEKnk_sendMessage);
      break;
    }
    case 0x9ABB563A: { // fltrenv_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SAtkxD8X_sendMessage);
      break;
    }
    case 0x3E80BBC2: { // fltrrez_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_j5fIZbxQ_sendMessage);
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


void Heavy_monosynth::cSlice_oZSgk1Os_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_JArBJ3fa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cSlice_u9ofHdPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_Id2I314n, 0, m, &cIf_Id2I314n_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_bpKD3EGL, 0, m, &cIf_bpKD3EGL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cSlice_t2qPYfPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_7pN3myWB, 0, m, &cIf_7pN3myWB_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_CMMHM19H, 0, m, &cIf_CMMHM19H_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cVar_V27mdvbb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_gWXpM65M_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_sXEuzTS9, 0, m, &cIf_sXEuzTS9_sendMessage);
}

void Heavy_monosynth::cUnop_pge9jDrg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_IenQiU4j_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KWVOSPpj, HV_BINOP_EQ, 1, m, &cBinop_KWVOSPpj_sendMessage);
}

void Heavy_monosynth::cUnop_QOTMpCrq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_IenQiU4j_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KWVOSPpj, HV_BINOP_EQ, 1, m, &cBinop_KWVOSPpj_sendMessage);
}

void Heavy_monosynth::cIf_sXEuzTS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_QOTMpCrq_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_pge9jDrg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cBinop_gWXpM65M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sXEuzTS9, 1, m, &cIf_sXEuzTS9_sendMessage);
}

void Heavy_monosynth::cIf_bpKD3EGL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_SsUckaFx_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cIf_CMMHM19H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_V3GJq1L4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cIf_Id2I314n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_SsUckaFx_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cIf_7pN3myWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_V3GJq1L4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cBinop_JArBJ3fa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KWVOSPpj, HV_BINOP_EQ, 0, m, &cBinop_KWVOSPpj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_XdjGtM65_sendMessage);
}

void Heavy_monosynth::cBinop_IenQiU4j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eyBmRcGV_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OW78KzLg_sendMessage);
}

void Heavy_monosynth::cBinop_KWVOSPpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_w0NgJaID_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4iCxaJDr_sendMessage);
}

void Heavy_monosynth::cCast_4iCxaJDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7pN3myWB, 1, m, &cIf_7pN3myWB_sendMessage);
}

void Heavy_monosynth::cCast_w0NgJaID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_bpKD3EGL, 1, m, &cIf_bpKD3EGL_sendMessage);
}

void Heavy_monosynth::cCast_OW78KzLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CMMHM19H, 1, m, &cIf_CMMHM19H_sendMessage);
}

void Heavy_monosynth::cCast_eyBmRcGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Id2I314n, 1, m, &cIf_Id2I314n_sendMessage);
}

void Heavy_monosynth::cBinop_XdjGtM65_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_monosynth::cBinop_XwconTnF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6Cjd9u7Y, m);
}

void Heavy_monosynth::cBinop_V3GJq1L4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_nW16h0iL_sendMessage);
}

void Heavy_monosynth::cBinop_nW16h0iL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GVgDij1M, HV_BINOP_POW, 1, m, &cBinop_GVgDij1M_sendMessage);
  cMsg_OZuZABis_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cBinop_GVgDij1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_XwconTnF_sendMessage);
}

void Heavy_monosynth::cMsg_OZuZABis_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GVgDij1M, HV_BINOP_POW, 0, m, &cBinop_GVgDij1M_sendMessage);
}

void Heavy_monosynth::cExpr_rdcOi8KB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3t4nHor0, m);
}

float Heavy_monosynth::cExpr_rdcOi8KB_evaluate(const float* args) {
  	return 1-((float)(args[0]));
}

void Heavy_monosynth::cExpr_YjUnVMrk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EpO0Wdvl, m);
}

float Heavy_monosynth::cExpr_YjUnVMrk_evaluate(const float* args) {
  	return ((float)(args[0]))*0.5f+0.5f;
}

void Heavy_monosynth::cVar_T20a6bZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_YjUnVMrk, 0, m, &cExpr_YjUnVMrk_sendMessage);
}

void Heavy_monosynth::cMsg_n9nruiuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YxaKdDZs_sendMessage);
}

void Heavy_monosynth::cSystem_YxaKdDZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FqJjiPL5_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_Ghx8ZwSZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_FUfBPZgc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_SgKgRelV, 0, m, &cIf_SgKgRelV_sendMessage);
}

void Heavy_monosynth::cIf_SgKgRelV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_xNEnrkv1_sendMessage(_c, 0, m);
      cMsg_4uJj2c0H_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_Z8xtTnta_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_avWMP43l_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_TOe6v1Ph, m);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cBinop_FUfBPZgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SgKgRelV, 1, m, &cIf_SgKgRelV_sendMessage);
}

void Heavy_monosynth::cMsg_Z8xtTnta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_XbatqCse_sendMessage);
}

void Heavy_monosynth::cBinop_XbatqCse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ry21ZBv4, m);
}

void Heavy_monosynth::cBinop_avWMP43l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_divthaSL_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cMsg_divthaSL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1xYMV0ru_sendMessage);
}

void Heavy_monosynth::cBinop_1xYMV0ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tj1C1vXq_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cMsg_tj1C1vXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_kC2OVkVO_sendMessage);
}

void Heavy_monosynth::cBinop_kC2OVkVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yeg3zno8, m);
}

void Heavy_monosynth::cBinop_AeUT2J1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lmYjoFKO, m);
}

void Heavy_monosynth::cMsg_FqJjiPL5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_AeUT2J1Z_sendMessage);
}

void Heavy_monosynth::cMsg_xNEnrkv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_avWMP43l_sendMessage);
}

void Heavy_monosynth::cMsg_4uJj2c0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ry21ZBv4, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TOe6v1Ph, m);
}

void Heavy_monosynth::cMsg_0COqeSFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Eo23XJZ7_sendMessage);
}

void Heavy_monosynth::cSystem_Eo23XJZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JhVNDkjk_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_Jsrpl2fy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_CpVjitbW_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_vkWW0COg, 0, m, &cIf_vkWW0COg_sendMessage);
}

void Heavy_monosynth::cIf_vkWW0COg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ZkCVNFJj_sendMessage(_c, 0, m);
      cMsg_3JXfrO37_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_lpOoCsyl_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_zXgpfb4o_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_3lsdJ72i, m);
      break;
    }
    default: return;
  }
}

void Heavy_monosynth::cBinop_CpVjitbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vkWW0COg, 1, m, &cIf_vkWW0COg_sendMessage);
}

void Heavy_monosynth::cMsg_lpOoCsyl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_l39Qp5Yl_sendMessage);
}

void Heavy_monosynth::cBinop_l39Qp5Yl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LXJyscWA, m);
}

void Heavy_monosynth::cBinop_zXgpfb4o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OlZW6zQ3_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cMsg_OlZW6zQ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_dyxZQNYJ_sendMessage);
}

void Heavy_monosynth::cBinop_dyxZQNYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7EYw9Ggk_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cMsg_7EYw9Ggk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Wu2qpmqL_sendMessage);
}

void Heavy_monosynth::cBinop_Wu2qpmqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DJKj7UD3, m);
}

void Heavy_monosynth::cBinop_eWkdqJsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sINFgpne, m);
}

void Heavy_monosynth::cMsg_JhVNDkjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_eWkdqJsZ_sendMessage);
}

void Heavy_monosynth::cMsg_ZkCVNFJj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_zXgpfb4o_sendMessage);
}

void Heavy_monosynth::cMsg_3JXfrO37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LXJyscWA, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3lsdJ72i, m);
}

void Heavy_monosynth::cVar_9Xuo8KpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ghx8ZwSZ, 0, m, &cVar_Ghx8ZwSZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Jsrpl2fy, 0, m, &cVar_Jsrpl2fy_sendMessage);
}

void Heavy_monosynth::cExpr_5SkLQ7CY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9Xuo8KpD, 0, m, &cVar_9Xuo8KpD_sendMessage);
}

float Heavy_monosynth::cExpr_5SkLQ7CY_evaluate(const float* args) {
  	return hv_pow_f(8 , ((float)(args[0])));
}

void Heavy_monosynth::cVar_Y2yjzhI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_5SkLQ7CY, 0, m, &cExpr_5SkLQ7CY_sendMessage);
}

void Heavy_monosynth::cVar_FpOStlgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GRVRyUWq, m);
}

void Heavy_monosynth::cVar_97FQZMPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_EX90xDhd, 0, m, &cExpr_EX90xDhd_sendMessage);
}

void Heavy_monosynth::cVar_QkMOklh6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kuJ0Hkl2, 1, m, &cVar_kuJ0Hkl2_sendMessage);
}

void Heavy_monosynth::cVar_o0MgnFlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_isBwYll6, 0, m, &cExpr_isBwYll6_sendMessage);
}

void Heavy_monosynth::cPack_YVcURIer_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_WUe70ZtI, 0, m, NULL);
}

void Heavy_monosynth::cCast_LjjMg0wL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Xcd2jm0s, 0, m, &cVar_Xcd2jm0s_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DFk3IcPU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Zu13asPO_sendMessage);
}

void Heavy_monosynth::cSwitchcase_SsUckaFx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xVQ7BMTi_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LjjMg0wL_sendMessage);
      break;
    }
  }
}

void Heavy_monosynth::cCast_xVQ7BMTi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fz6EPXrU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wjPIYRos, 0, m, &cVar_wjPIYRos_sendMessage);
}

void Heavy_monosynth::cSwitchcase_4AOlrAYk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_INRtwHFr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_INRtwHFr_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_7necLe9w, 1, m, &cDelay_7necLe9w_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ljhs0o5R_sendMessage);
      break;
    }
  }
}

void Heavy_monosynth::cDelay_7necLe9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7necLe9w, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kuJ0Hkl2, 0, m, &cVar_kuJ0Hkl2_sendMessage);
}

void Heavy_monosynth::cMsg_INRtwHFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_7necLe9w, 0, m, &cDelay_7necLe9w_sendMessage);
}

void Heavy_monosynth::cCast_ljhs0o5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7necLe9w, 0, m, &cDelay_7necLe9w_sendMessage);
}

void Heavy_monosynth::cVar_Xcd2jm0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Jb2417TT_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_wjPIYRos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Mtw4gewD_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cVar_kuJ0Hkl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YVcURIer, 0, m, &cPack_YVcURIer_sendMessage);
}

void Heavy_monosynth::cVar_7DuElKRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_WUe70ZtI, 0, m, NULL);
}

void Heavy_monosynth::cExpr_isBwYll6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wjPIYRos, 1, m, &cVar_wjPIYRos_sendMessage);
}

float Heavy_monosynth::cExpr_isBwYll6_evaluate(const float* args) {
  	return hv_pow_f(10 , 4.5f*((float)(args[0])));
}

void Heavy_monosynth::cExpr_EX90xDhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YVcURIer, 1, m, &cPack_YVcURIer_sendMessage);
}

float Heavy_monosynth::cExpr_EX90xDhd_evaluate(const float* args) {
  	return hv_pow_f(10 , 4*((float)(args[0])));
}

void Heavy_monosynth::cExpr_7HZX0nrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Xcd2jm0s, 1, m, &cVar_Xcd2jm0s_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7necLe9w, 1, m, &cDelay_7necLe9w_sendMessage);
}

float Heavy_monosynth::cExpr_7HZX0nrK_evaluate(const float* args) {
  	return 2+hv_pow_f(10 , 4*((float)(args[0])));
}

void Heavy_monosynth::cMsg_Mtw4gewD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_WUe70ZtI, 0, m, NULL);
}

void Heavy_monosynth::cMsg_Jb2417TT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_WUe70ZtI, 0, m, NULL);
}

void Heavy_monosynth::cMsg_fz6EPXrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_4AOlrAYk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_monosynth::cCast_DFk3IcPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fz6EPXrU_sendMessage(_c, 0, m);
}

void Heavy_monosynth::cCast_Zu13asPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4AOlrAYk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_monosynth::cVar_eOGoq542_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_ZbAa0fze, 0, m, &cExpr_ZbAa0fze_sendMessage);
}

void Heavy_monosynth::cVar_xR03DItS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7e7KeGRT, m);
  cExpr_onMessage(_c, &Context(_c)->cExpr_rdcOi8KB, 0, m, &cExpr_rdcOi8KB_sendMessage);
}

void Heavy_monosynth::cVar_ym6fRlhk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_7HZX0nrK, 0, m, &cExpr_7HZX0nrK_sendMessage);
}

void Heavy_monosynth::cExpr_ZbAa0fze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PjqoedRN, m);
}

float Heavy_monosynth::cExpr_ZbAa0fze_evaluate(const float* args) {
  	return hv_pow_f(2 , 5*((float)(args[0])));
}

void Heavy_monosynth::cReceive_l3bjyCOy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n9nruiuu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Ghx8ZwSZ, 0, m, &cVar_Ghx8ZwSZ_sendMessage);
  cMsg_0COqeSFU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Jsrpl2fy, 0, m, &cVar_Jsrpl2fy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_V27mdvbb, 0, m, &cVar_V27mdvbb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7DuElKRU, 0, m, &cVar_7DuElKRU_sendMessage);
}

void Heavy_monosynth::cReceive_jhlXEKnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_oZSgk1Os, 0, m, &cSlice_oZSgk1Os_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_u9ofHdPn, 0, m, &cSlice_u9ofHdPn_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_t2qPYfPc, 0, m, &cSlice_t2qPYfPc_sendMessage);
}

void Heavy_monosynth::cReceive_2vTiZ12Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T20a6bZC, 0, m, &cVar_T20a6bZC_sendMessage);
}

void Heavy_monosynth::cReceive_j5fIZbxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y2yjzhI6, 0, m, &cVar_Y2yjzhI6_sendMessage);
}

void Heavy_monosynth::cReceive_SAtkxD8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FpOStlgm, 0, m, &cVar_FpOStlgm_sendMessage);
}

void Heavy_monosynth::cReceive_J3tJzPOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_97FQZMPP, 0, m, &cVar_97FQZMPP_sendMessage);
}

void Heavy_monosynth::cReceive_bFs19Zmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QkMOklh6, 0, m, &cVar_QkMOklh6_sendMessage);
}

void Heavy_monosynth::cReceive_7kog7rFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_o0MgnFlV, 0, m, &cVar_o0MgnFlV_sendMessage);
}

void Heavy_monosynth::cReceive_t1qZ95Im_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eOGoq542, 0, m, &cVar_eOGoq542_sendMessage);
}

void Heavy_monosynth::cReceive_M3ec8UCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xR03DItS, 0, m, &cVar_xR03DItS_sendMessage);
}

void Heavy_monosynth::cReceive_xMVHVwa7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ym6fRlhk, 0, m, &cVar_ym6fRlhk_sendMessage);
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
    __hv_varread_f(&sVarf_6Cjd9u7Y, VOf(Bf0));
    __hv_phasor_f(&sPhasor_8EgUUrf2, VIf(Bf0), VOf(Bf1));
    __hv_varread_f(&sVarf_EpO0Wdvl, VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f);
    __hv_min_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f);
    __hv_max_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_7e7KeGRT, VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf1), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_3t4nHor0, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_PjqoedRN, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_WUe70ZtI, VOf(Bf0));
    __hv_varread_f(&sVarf_GRVRyUWq, VOf(Bf3));
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
    __hv_varread_f(&sVarf_lmYjoFKO, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_TOe6v1Ph, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Ry21ZBv4, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_varread_f(&sVarf_yeg3zno8, VOf(Bf2));
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
    __hv_cpole_f(&sCPole_OIB0bhlr, VIf(Bf2), VIf(ZERO), VIf(Bf6), VIf(Bf5), VOf(Bf5), VOf(Bf6));
    __hv_varread_f(&sVarf_sINFgpne, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_3lsdJ72i, VOf(Bf5));
    __hv_min_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_LXJyscWA, VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf6));
    __hv_varread_f(&sVarf_DJKj7UD3, VOf(Bf5));
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
    __hv_cpole_f(&sCPole_lDz5CpiA, VIf(Bf5), VIf(ZERO), VIf(Bf3), VIf(Bf1), VOf(Bf1), VOf(Bf3));
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
