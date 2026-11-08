/** the author of dl-monosynth.pd */

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
  numBytes += sPhasor_init(&sPhasor_jMK7kzew, sampleRate);
  numBytes += sLine_init(&sLine_TdVtE9FG);
  numBytes += sCPole_init(&sCPole_akvqsoP8);
  numBytes += sCPole_init(&sCPole_YXgkvksL);
  numBytes += cSlice_init(&cSlice_DtWGP1MA, 2, 1);
  numBytes += cSlice_init(&cSlice_5NoIww6F, 1, 1);
  numBytes += cSlice_init(&cSlice_nq2HZAw5, 0, 1);
  numBytes += cVar_init_f(&cVar_B67ThVJf, 0.0f);
  numBytes += cIf_init(&cIf_dOdtGdnA, false);
  numBytes += cIf_init(&cIf_E1mIrAiU, false);
  numBytes += cIf_init(&cIf_NzwsQ0vp, false);
  numBytes += cIf_init(&cIf_ZjAiwssu, false);
  numBytes += cIf_init(&cIf_2zCuKBTd, false);
  numBytes += cBinop_init(&cBinop_5tOnmfk4, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_1wHEoUPT, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_dZmyJT01, 0.0f, 0.0f, false);
  numBytes += cExpr_init(&cExpr_7Zd5VS3U, &Heavy_dl_monosynth::cExpr_7Zd5VS3U_evaluate);
  numBytes += cExpr_init(&cExpr_DxEFVhJu, &Heavy_dl_monosynth::cExpr_DxEFVhJu_evaluate);
  numBytes += sVarf_init(&sVarf_BdqT3TG9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rpR3lgDB, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dQSmxp1z, 0.5f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_lGRIpoXM, 0.0f);
  numBytes += cVar_init_f(&cVar_yflrNPze, 0.0f);
  numBytes += cIf_init(&cIf_Wyhk5LOr, false);
  numBytes += sVarf_init(&sVarf_hLK5jsho, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sj66phiy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1SyNHtmP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZcKyO8ex, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_lYJxZ7Of, 0.0f);
  numBytes += cIf_init(&cIf_kuljscoh, false);
  numBytes += sVarf_init(&sVarf_HZVB0f2v, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_K6MkRgel, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RG7k0hhU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LWl6mHte, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_b4VKF93N, 0.707f);
  numBytes += cExpr_init(&cExpr_CMQMQLzq, &Heavy_dl_monosynth::cExpr_CMQMQLzq_evaluate);
  numBytes += cVar_init_f(&cVar_iPIsdrsI, 0.0f);
  numBytes += cVar_init_f(&cVar_H8mC32zz, 0.0f);
  numBytes += cVar_init_f(&cVar_OnjquUco, 0.0f);
  numBytes += cVar_init_f(&cVar_xnwHikDM, 0.0f);
  numBytes += cVar_init_f(&cVar_X5t4J8hY, 0.0f);
  numBytes += cPack_init(&cPack_PlGj19xl, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_6wEOcohl, 0.0f);
  numBytes += cVar_init_f(&cVar_vNsIlgwG, 0.0f);
  numBytes += cVar_init_f(&cVar_LzHTY9pL, 0.0f);
  numBytes += cVar_init_f(&cVar_aGzeN8Do, 0.0f);
  numBytes += cVar_init_f(&cVar_sCQdfuT8, 0.0f);
  numBytes += cExpr_init(&cExpr_zigrAtV4, &Heavy_dl_monosynth::cExpr_zigrAtV4_evaluate);
  numBytes += cExpr_init(&cExpr_e7oQw0jy, &Heavy_dl_monosynth::cExpr_e7oQw0jy_evaluate);
  numBytes += cExpr_init(&cExpr_OtytRF3X, &Heavy_dl_monosynth::cExpr_OtytRF3X_evaluate);
  numBytes += cVar_init_f(&cVar_fOIUEBTu, 0.0f);
  numBytes += sVarf_init(&sVarf_fao7gZRI, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_P3QJdgbp, 0.0f);
  numBytes += cVar_init_f(&cVar_YkAiMQdT, 0.0f);
  numBytes += cExpr_init(&cExpr_n21Zgi1q, &Heavy_dl_monosynth::cExpr_n21Zgi1q_evaluate);
  numBytes += sVarf_init(&sVarf_IK16YqnB, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_dl_monosynth::~Heavy_dl_monosynth() {
  cExpr_free(&cExpr_7Zd5VS3U);
  cExpr_free(&cExpr_DxEFVhJu);
  cExpr_free(&cExpr_CMQMQLzq);
  cPack_free(&cPack_PlGj19xl);
  cExpr_free(&cExpr_zigrAtV4);
  cExpr_free(&cExpr_e7oQw0jy);
  cExpr_free(&cExpr_OtytRF3X);
  cExpr_free(&cExpr_n21Zgi1q);
}

HvTable *Heavy_dl_monosynth::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_dl_monosynth::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xE0DDF12E: { // _1_wvform_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mHaK6bJ6_sendMessage);
      break;
    }
    case 0xAEA003E7: { // _2_PWM_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FDHzds8N_sendMessage);
      break;
    }
    case 0x1400CF4A: { // _3_cutoff_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_W9c1pvRM_sendMessage);
      break;
    }
    case 0x76662EAD: { // _4_Attack_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wStRXQzE_sendMessage);
      break;
    }
    case 0xEDB1071A: { // _5_Decay_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JFdfAvQR_sendMessage);
      break;
    }
    case 0x46C2E2B6: { // _6_Sustain_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Hd0tgrxf_sendMessage);
      break;
    }
    case 0x59614F9D: { // _7_Release_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_itom2HiF_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BCXBOQQM_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iXAs8Joh_sendMessage);
      break;
    }
    case 0x9ABB563A: { // fltrenv_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Oc1Ts7nZ_sendMessage);
      break;
    }
    case 0x3E80BBC2: { // fltrrez_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zkujFune_sendMessage);
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


void Heavy_dl_monosynth::cSlice_DtWGP1MA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_vIaoIaQy_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cSlice_5NoIww6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_ZjAiwssu, 0, m, &cIf_ZjAiwssu_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_E1mIrAiU, 0, m, &cIf_E1mIrAiU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cSlice_nq2HZAw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_2zCuKBTd, 0, m, &cIf_2zCuKBTd_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_NzwsQ0vp, 0, m, &cIf_NzwsQ0vp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cVar_B67ThVJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_aqIKwhH7_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_dOdtGdnA, 0, m, &cIf_dOdtGdnA_sendMessage);
}

void Heavy_dl_monosynth::cUnop_iAZXQyr8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_45f9PrS1_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5tOnmfk4, HV_BINOP_EQ, 1, m, &cBinop_5tOnmfk4_sendMessage);
}

void Heavy_dl_monosynth::cUnop_YGiPD8YP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_45f9PrS1_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5tOnmfk4, HV_BINOP_EQ, 1, m, &cBinop_5tOnmfk4_sendMessage);
}

void Heavy_dl_monosynth::cIf_dOdtGdnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_YGiPD8YP_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_iAZXQyr8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cBinop_aqIKwhH7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dOdtGdnA, 1, m, &cIf_dOdtGdnA_sendMessage);
}

void Heavy_dl_monosynth::cIf_E1mIrAiU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_kizANFNr_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cIf_NzwsQ0vp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_8BLu49fw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cIf_ZjAiwssu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_kizANFNr_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cIf_2zCuKBTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_8BLu49fw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cBinop_vIaoIaQy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5tOnmfk4, HV_BINOP_EQ, 0, m, &cBinop_5tOnmfk4_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_oegfUN1n_sendMessage);
}

void Heavy_dl_monosynth::cBinop_45f9PrS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IhjHjNcR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tLy3OgtX_sendMessage);
}

void Heavy_dl_monosynth::cBinop_5tOnmfk4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_czNp1peA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RYiU0Ebp_sendMessage);
}

void Heavy_dl_monosynth::cCast_RYiU0Ebp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2zCuKBTd, 1, m, &cIf_2zCuKBTd_sendMessage);
}

void Heavy_dl_monosynth::cCast_czNp1peA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_E1mIrAiU, 1, m, &cIf_E1mIrAiU_sendMessage);
}

void Heavy_dl_monosynth::cCast_tLy3OgtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NzwsQ0vp, 1, m, &cIf_NzwsQ0vp_sendMessage);
}

void Heavy_dl_monosynth::cCast_IhjHjNcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZjAiwssu, 1, m, &cIf_ZjAiwssu_sendMessage);
}

void Heavy_dl_monosynth::cBinop_oegfUN1n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_dl_monosynth::cBinop_eUyuxm1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dZmyJT01, m);
}

void Heavy_dl_monosynth::cBinop_8BLu49fw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_jdPRYojY_sendMessage);
}

void Heavy_dl_monosynth::cBinop_jdPRYojY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1wHEoUPT, HV_BINOP_POW, 1, m, &cBinop_1wHEoUPT_sendMessage);
  cMsg_gCvc4U7I_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cBinop_1wHEoUPT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_eUyuxm1D_sendMessage);
}

void Heavy_dl_monosynth::cMsg_gCvc4U7I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1wHEoUPT, HV_BINOP_POW, 0, m, &cBinop_1wHEoUPT_sendMessage);
}

void Heavy_dl_monosynth::cExpr_7Zd5VS3U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rpR3lgDB, m);
}

float Heavy_dl_monosynth::cExpr_7Zd5VS3U_evaluate(const float* args) {
  	return 1-((float)(args[0]));
}

void Heavy_dl_monosynth::cExpr_DxEFVhJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dQSmxp1z, m);
}

float Heavy_dl_monosynth::cExpr_DxEFVhJu_evaluate(const float* args) {
  	return ((float)(args[0]))*0.5f+0.5f;
}

void Heavy_dl_monosynth::cVar_lGRIpoXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_DxEFVhJu, 0, m, &cExpr_DxEFVhJu_sendMessage);
}

void Heavy_dl_monosynth::cMsg_znntK8Gg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ncxrkQfQ_sendMessage);
}

void Heavy_dl_monosynth::cSystem_ncxrkQfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TayoltLu_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cVar_yflrNPze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_rS8novJ9_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Wyhk5LOr, 0, m, &cIf_Wyhk5LOr_sendMessage);
}

void Heavy_dl_monosynth::cIf_Wyhk5LOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_y909qPNq_sendMessage(_c, 0, m);
      cMsg_OVo033C0_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_u3TSHnDi_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_3kWYMlCL_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_ZcKyO8ex, m);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cBinop_rS8novJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Wyhk5LOr, 1, m, &cIf_Wyhk5LOr_sendMessage);
}

void Heavy_dl_monosynth::cMsg_u3TSHnDi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_OuOzT9Lr_sendMessage);
}

void Heavy_dl_monosynth::cBinop_OuOzT9Lr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sj66phiy, m);
}

void Heavy_dl_monosynth::cBinop_3kWYMlCL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MPfZ23Sn_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cMsg_MPfZ23Sn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_dXr4j2fW_sendMessage);
}

void Heavy_dl_monosynth::cBinop_dXr4j2fW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ItqGdxQi_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cMsg_ItqGdxQi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_5vv3PTkn_sendMessage);
}

void Heavy_dl_monosynth::cBinop_5vv3PTkn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1SyNHtmP, m);
}

void Heavy_dl_monosynth::cBinop_dthaDz0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hLK5jsho, m);
}

void Heavy_dl_monosynth::cMsg_TayoltLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_dthaDz0X_sendMessage);
}

void Heavy_dl_monosynth::cMsg_y909qPNq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_3kWYMlCL_sendMessage);
}

void Heavy_dl_monosynth::cMsg_OVo033C0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_sj66phiy, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZcKyO8ex, m);
}

void Heavy_dl_monosynth::cMsg_stkRbrd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zXwMQ97g_sendMessage);
}

void Heavy_dl_monosynth::cSystem_zXwMQ97g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qH58ZQ1O_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cVar_lYJxZ7Of_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_bCbaZuRi_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_kuljscoh, 0, m, &cIf_kuljscoh_sendMessage);
}

void Heavy_dl_monosynth::cIf_kuljscoh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_5fAYkf1e_sendMessage(_c, 0, m);
      cMsg_JkzYW0lC_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_gWbtsnfM_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_OGzh3Svf_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_LWl6mHte, m);
      break;
    }
    default: return;
  }
}

void Heavy_dl_monosynth::cBinop_bCbaZuRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kuljscoh, 1, m, &cIf_kuljscoh_sendMessage);
}

void Heavy_dl_monosynth::cMsg_gWbtsnfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_RxkY3DUS_sendMessage);
}

void Heavy_dl_monosynth::cBinop_RxkY3DUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_K6MkRgel, m);
}

void Heavy_dl_monosynth::cBinop_OGzh3Svf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DlGOGZPc_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cMsg_DlGOGZPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_HAeGmCH1_sendMessage);
}

void Heavy_dl_monosynth::cBinop_HAeGmCH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VJXxWtEz_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cMsg_VJXxWtEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_6hec2Ejp_sendMessage);
}

void Heavy_dl_monosynth::cBinop_6hec2Ejp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RG7k0hhU, m);
}

void Heavy_dl_monosynth::cBinop_OMhVB3gS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HZVB0f2v, m);
}

void Heavy_dl_monosynth::cMsg_qH58ZQ1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_OMhVB3gS_sendMessage);
}

void Heavy_dl_monosynth::cMsg_5fAYkf1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_OGzh3Svf_sendMessage);
}

void Heavy_dl_monosynth::cMsg_JkzYW0lC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_K6MkRgel, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LWl6mHte, m);
}

void Heavy_dl_monosynth::cVar_b4VKF93N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yflrNPze, 0, m, &cVar_yflrNPze_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lYJxZ7Of, 0, m, &cVar_lYJxZ7Of_sendMessage);
}

void Heavy_dl_monosynth::cExpr_CMQMQLzq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_b4VKF93N, 0, m, &cVar_b4VKF93N_sendMessage);
}

float Heavy_dl_monosynth::cExpr_CMQMQLzq_evaluate(const float* args) {
  	return hv_pow_f(8 , ((float)(args[0])));
}

void Heavy_dl_monosynth::cVar_iPIsdrsI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_CMQMQLzq, 0, m, &cExpr_CMQMQLzq_sendMessage);
}

void Heavy_dl_monosynth::cVar_H8mC32zz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IK16YqnB, m);
}

void Heavy_dl_monosynth::cVar_OnjquUco_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_e7oQw0jy, 0, m, &cExpr_e7oQw0jy_sendMessage);
}

void Heavy_dl_monosynth::cVar_xnwHikDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aGzeN8Do, 1, m, &cVar_aGzeN8Do_sendMessage);
}

void Heavy_dl_monosynth::cVar_X5t4J8hY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_zigrAtV4, 0, m, &cExpr_zigrAtV4_sendMessage);
}

void Heavy_dl_monosynth::cPack_PlGj19xl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_TdVtE9FG, 0, m, NULL);
}

void Heavy_dl_monosynth::cCast_w4YX3xBZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vNsIlgwG, 0, m, &cVar_vNsIlgwG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_f94fLc18_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LgTzm9su_sendMessage);
}

void Heavy_dl_monosynth::cSwitchcase_kizANFNr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_50cpiN5r_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_w4YX3xBZ_sendMessage);
      break;
    }
  }
}

void Heavy_dl_monosynth::cCast_50cpiN5r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YSrNBNoG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LzHTY9pL, 0, m, &cVar_LzHTY9pL_sendMessage);
}

void Heavy_dl_monosynth::cSwitchcase_o2LviSbN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_4toScu0N_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_4toScu0N_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_6wEOcohl, 1, m, &cDelay_6wEOcohl_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QalNDQCX_sendMessage);
      break;
    }
  }
}

void Heavy_dl_monosynth::cDelay_6wEOcohl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6wEOcohl, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aGzeN8Do, 0, m, &cVar_aGzeN8Do_sendMessage);
}

void Heavy_dl_monosynth::cMsg_4toScu0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_6wEOcohl, 0, m, &cDelay_6wEOcohl_sendMessage);
}

void Heavy_dl_monosynth::cCast_QalNDQCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6wEOcohl, 0, m, &cDelay_6wEOcohl_sendMessage);
}

void Heavy_dl_monosynth::cVar_vNsIlgwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CxYg1IGV_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cVar_LzHTY9pL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2464m5IT_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cVar_aGzeN8Do_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PlGj19xl, 0, m, &cPack_PlGj19xl_sendMessage);
}

void Heavy_dl_monosynth::cVar_sCQdfuT8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_TdVtE9FG, 0, m, NULL);
}

void Heavy_dl_monosynth::cExpr_zigrAtV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LzHTY9pL, 1, m, &cVar_LzHTY9pL_sendMessage);
}

float Heavy_dl_monosynth::cExpr_zigrAtV4_evaluate(const float* args) {
  	return hv_pow_f(10 , 4.5f*((float)(args[0])));
}

void Heavy_dl_monosynth::cExpr_e7oQw0jy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PlGj19xl, 1, m, &cPack_PlGj19xl_sendMessage);
}

float Heavy_dl_monosynth::cExpr_e7oQw0jy_evaluate(const float* args) {
  	return hv_pow_f(10 , 4*((float)(args[0])));
}

void Heavy_dl_monosynth::cExpr_OtytRF3X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vNsIlgwG, 1, m, &cVar_vNsIlgwG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6wEOcohl, 1, m, &cDelay_6wEOcohl_sendMessage);
}

float Heavy_dl_monosynth::cExpr_OtytRF3X_evaluate(const float* args) {
  	return 2+hv_pow_f(10 , 4*((float)(args[0])));
}

void Heavy_dl_monosynth::cMsg_2464m5IT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_TdVtE9FG, 0, m, NULL);
}

void Heavy_dl_monosynth::cMsg_CxYg1IGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_TdVtE9FG, 0, m, NULL);
}

void Heavy_dl_monosynth::cMsg_YSrNBNoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_o2LviSbN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_dl_monosynth::cCast_LgTzm9su_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_o2LviSbN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_dl_monosynth::cCast_f94fLc18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YSrNBNoG_sendMessage(_c, 0, m);
}

void Heavy_dl_monosynth::cVar_fOIUEBTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_n21Zgi1q, 0, m, &cExpr_n21Zgi1q_sendMessage);
}

void Heavy_dl_monosynth::cVar_P3QJdgbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BdqT3TG9, m);
  cExpr_onMessage(_c, &Context(_c)->cExpr_7Zd5VS3U, 0, m, &cExpr_7Zd5VS3U_sendMessage);
}

void Heavy_dl_monosynth::cVar_YkAiMQdT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_OtytRF3X, 0, m, &cExpr_OtytRF3X_sendMessage);
}

void Heavy_dl_monosynth::cExpr_n21Zgi1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fao7gZRI, m);
}

float Heavy_dl_monosynth::cExpr_n21Zgi1q_evaluate(const float* args) {
  	return hv_pow_f(2 , 5*((float)(args[0])));
}

void Heavy_dl_monosynth::cReceive_BCXBOQQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_znntK8Gg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yflrNPze, 0, m, &cVar_yflrNPze_sendMessage);
  cMsg_stkRbrd4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lYJxZ7Of, 0, m, &cVar_lYJxZ7Of_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_B67ThVJf, 0, m, &cVar_B67ThVJf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sCQdfuT8, 0, m, &cVar_sCQdfuT8_sendMessage);
}

void Heavy_dl_monosynth::cReceive_iXAs8Joh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_DtWGP1MA, 0, m, &cSlice_DtWGP1MA_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_5NoIww6F, 0, m, &cSlice_5NoIww6F_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_nq2HZAw5, 0, m, &cSlice_nq2HZAw5_sendMessage);
}

void Heavy_dl_monosynth::cReceive_FDHzds8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lGRIpoXM, 0, m, &cVar_lGRIpoXM_sendMessage);
}

void Heavy_dl_monosynth::cReceive_zkujFune_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iPIsdrsI, 0, m, &cVar_iPIsdrsI_sendMessage);
}

void Heavy_dl_monosynth::cReceive_Oc1Ts7nZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H8mC32zz, 0, m, &cVar_H8mC32zz_sendMessage);
}

void Heavy_dl_monosynth::cReceive_JFdfAvQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OnjquUco, 0, m, &cVar_OnjquUco_sendMessage);
}

void Heavy_dl_monosynth::cReceive_Hd0tgrxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xnwHikDM, 0, m, &cVar_xnwHikDM_sendMessage);
}

void Heavy_dl_monosynth::cReceive_itom2HiF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X5t4J8hY, 0, m, &cVar_X5t4J8hY_sendMessage);
}

void Heavy_dl_monosynth::cReceive_W9c1pvRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fOIUEBTu, 0, m, &cVar_fOIUEBTu_sendMessage);
}

void Heavy_dl_monosynth::cReceive_mHaK6bJ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_P3QJdgbp, 0, m, &cVar_P3QJdgbp_sendMessage);
}

void Heavy_dl_monosynth::cReceive_wStRXQzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YkAiMQdT, 0, m, &cVar_YkAiMQdT_sendMessage);
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
    __hv_varread_f(&sVarf_dZmyJT01, VOf(Bf0));
    __hv_phasor_f(&sPhasor_jMK7kzew, VIf(Bf0), VOf(Bf1));
    __hv_varread_f(&sVarf_dQSmxp1z, VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f);
    __hv_min_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f, -0.0001f);
    __hv_max_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f, 10000.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_BdqT3TG9, VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf1), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_rpR3lgDB, VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_fao7gZRI, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_TdVtE9FG, VOf(Bf0));
    __hv_varread_f(&sVarf_IK16YqnB, VOf(Bf3));
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
    __hv_varread_f(&sVarf_hLK5jsho, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_ZcKyO8ex, VOf(Bf2));
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_sj66phiy, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf4));
    __hv_varread_f(&sVarf_1SyNHtmP, VOf(Bf2));
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
    __hv_cpole_f(&sCPole_akvqsoP8, VIf(Bf2), VIf(ZERO), VIf(Bf6), VIf(Bf5), VOf(Bf5), VOf(Bf6));
    __hv_varread_f(&sVarf_HZVB0f2v, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_LWl6mHte, VOf(Bf5));
    __hv_min_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_K6MkRgel, VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf6));
    __hv_varread_f(&sVarf_RG7k0hhU, VOf(Bf5));
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
    __hv_cpole_f(&sCPole_YXgkvksL, VIf(Bf5), VIf(ZERO), VIf(Bf3), VIf(Bf1), VOf(Bf1), VOf(Bf3));
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
