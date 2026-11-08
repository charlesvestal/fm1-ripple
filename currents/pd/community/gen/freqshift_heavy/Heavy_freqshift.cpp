/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside freqshift.pd) */

#include "Heavy_freqshift.hpp"



#define Context(_c) static_cast<Heavy_freqshift *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_freqshift::Heavy_freqshift(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sBiquad_k_init(&sBiquad_k_PI8WyTTG, 0.94657f, -1.94632f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_DjIi8Efl, 0.06338f, -0.83774f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_bi7p4TKC, -0.260502f, 0.02569f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_9tgxZ5x0, 0.870686f, -1.8685f, 1.0f, 0.0f, 0.0f);
  numBytes += sPhasor_init(&sPhasor_AixPp99F, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_htROYoEq, 0.94657f, -1.94632f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_n9hunAW9, 0.06338f, -0.83774f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_2AgFtKNy, -0.260502f, 0.02569f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_MlimPGtt, 0.870686f, -1.8685f, 1.0f, 0.0f, 0.0f);
  numBytes += sPhasor_init(&sPhasor_587fIpGg, sampleRate);
  numBytes += cSlice_init(&cSlice_s29zjYdM, 0, 1);
  numBytes += cSlice_init(&cSlice_2MVAY46G, 1, 1);
  numBytes += cSlice_init(&cSlice_YsoWLOXN, 2, 1);
  numBytes += cSlice_init(&cSlice_ux8FB3os, 3, 1);
  numBytes += cSlice_init(&cSlice_UwRzoCdD, 4, 1);
  numBytes += cVar_init_f(&cVar_7SJEtIlN, 0.83774f);
  numBytes += cVar_init_f(&cVar_7CFYpZTw, -0.06338f);
  numBytes += cSlice_init(&cSlice_FqYVGDrt, 0, 1);
  numBytes += cSlice_init(&cSlice_5E1YkF22, 1, 1);
  numBytes += cSlice_init(&cSlice_ThBhejfb, 2, 1);
  numBytes += cSlice_init(&cSlice_FTRyoZZ9, 3, 1);
  numBytes += cSlice_init(&cSlice_j6AFyAPw, 4, 1);
  numBytes += cVar_init_f(&cVar_rat4OGjp, 1.94632f);
  numBytes += cVar_init_f(&cVar_Af3I3boE, -0.94657f);
  numBytes += cSlice_init(&cSlice_VP4lTpcK, 0, 1);
  numBytes += cSlice_init(&cSlice_6fql86aN, 1, 1);
  numBytes += cSlice_init(&cSlice_sMSUbM7v, 2, 1);
  numBytes += cSlice_init(&cSlice_K7S8n7cA, 3, 1);
  numBytes += cSlice_init(&cSlice_BeFYLVop, 4, 1);
  numBytes += cVar_init_f(&cVar_1bxn0Cig, -0.02569f);
  numBytes += cVar_init_f(&cVar_Lh0miJPC, 0.260502f);
  numBytes += cSlice_init(&cSlice_fimcYnLy, 0, 1);
  numBytes += cSlice_init(&cSlice_G1S40gRU, 1, 1);
  numBytes += cSlice_init(&cSlice_UV2VnJu3, 2, 1);
  numBytes += cSlice_init(&cSlice_p5AulvrM, 3, 1);
  numBytes += cSlice_init(&cSlice_M6gpJKq9, 4, 1);
  numBytes += cVar_init_f(&cVar_8Ayeo02H, 1.8685f);
  numBytes += cVar_init_f(&cVar_cyK03Y1g, -0.870686f);
  numBytes += sVarf_init(&sVarf_OFGXdVLO, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_QjwScnEw, 0, 1);
  numBytes += cSlice_init(&cSlice_FMhyKYMy, 1, 1);
  numBytes += cSlice_init(&cSlice_o7dUKdlV, 2, 1);
  numBytes += cSlice_init(&cSlice_fHpgcRIG, 3, 1);
  numBytes += cSlice_init(&cSlice_zVG06i74, 4, 1);
  numBytes += cVar_init_f(&cVar_ScHjMtXq, 0.83774f);
  numBytes += cVar_init_f(&cVar_bUWgLvhy, -0.06338f);
  numBytes += cSlice_init(&cSlice_0MEcjP2X, 0, 1);
  numBytes += cSlice_init(&cSlice_YFH3nK4e, 1, 1);
  numBytes += cSlice_init(&cSlice_PnXp49RH, 2, 1);
  numBytes += cSlice_init(&cSlice_uw8bClv9, 3, 1);
  numBytes += cSlice_init(&cSlice_FxVJGpHL, 4, 1);
  numBytes += cVar_init_f(&cVar_OFmt0zc1, 1.94632f);
  numBytes += cVar_init_f(&cVar_zV5dMW95, -0.94657f);
  numBytes += cSlice_init(&cSlice_lD2CieAr, 0, 1);
  numBytes += cSlice_init(&cSlice_iB3b0uOz, 1, 1);
  numBytes += cSlice_init(&cSlice_lu3auprr, 2, 1);
  numBytes += cSlice_init(&cSlice_NC5mLOsu, 3, 1);
  numBytes += cSlice_init(&cSlice_SkBHFvLY, 4, 1);
  numBytes += cVar_init_f(&cVar_H7jHPzWm, -0.02569f);
  numBytes += cVar_init_f(&cVar_j5xeYXlk, 0.260502f);
  numBytes += cSlice_init(&cSlice_QXbGPXDk, 0, 1);
  numBytes += cSlice_init(&cSlice_3WZIgggw, 1, 1);
  numBytes += cSlice_init(&cSlice_IizOEFv4, 2, 1);
  numBytes += cSlice_init(&cSlice_mF9Wm7Qf, 3, 1);
  numBytes += cSlice_init(&cSlice_r9ABpzBY, 4, 1);
  numBytes += cVar_init_f(&cVar_hfJ0sgZ9, 1.8685f);
  numBytes += cVar_init_f(&cVar_kddeelKt, -0.870686f);
  numBytes += sVarf_init(&sVarf_d1Axcjpq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1UI36q5t, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fT1uXdqF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_CaFL7IO3, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_freqshift::~Heavy_freqshift() {
  // nothing to free
}

HvTable *Heavy_freqshift::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_freqshift::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_b2DCgMIL_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GNjwU66S_sendMessage);
      break;
    }
    case 0x8E55AA5F: { // time
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_14hweeUJ_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_freqshift::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "depth_f";
        info->hash = 0xC21FE6A3;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 1.0f;
        break;
      }
      case 1: {
        info->name = "time";
        info->hash = 0x8E55AA5F;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -200.0f;
        info->maxVal = 200.0f;
        info->defaultVal = 100.0f;
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
  return 2;
}



/*
 * Send Function Implementations
 */


void Heavy_freqshift::cSlice_s29zjYdM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vYWQdik3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_2MVAY46G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_X3JWPhDp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_YsoWLOXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_DjIi8Efl, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_ux8FB3os_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_DjIi8Efl, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_UwRzoCdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_DjIi8Efl, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_7SJEtIlN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vYWQdik3_sendMessage);
}

void Heavy_freqshift::cVar_7CFYpZTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_X3JWPhDp_sendMessage);
}

void Heavy_freqshift::cBinop_vYWQdik3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_DjIi8Efl, 4, m);
}

void Heavy_freqshift::cBinop_X3JWPhDp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_DjIi8Efl, 5, m);
}

void Heavy_freqshift::cSlice_FqYVGDrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_jjAP933f_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_5E1YkF22_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0k0ewJwY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_ThBhejfb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_PI8WyTTG, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_FTRyoZZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_PI8WyTTG, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_j6AFyAPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_PI8WyTTG, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_rat4OGjp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_jjAP933f_sendMessage);
}

void Heavy_freqshift::cVar_Af3I3boE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_0k0ewJwY_sendMessage);
}

void Heavy_freqshift::cBinop_jjAP933f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_PI8WyTTG, 4, m);
}

void Heavy_freqshift::cBinop_0k0ewJwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_PI8WyTTG, 5, m);
}

void Heavy_freqshift::cSlice_VP4lTpcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_T2TDVpzo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_6fql86aN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_YsuIcerp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_sMSUbM7v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_bi7p4TKC, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_K7S8n7cA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_bi7p4TKC, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_BeFYLVop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_bi7p4TKC, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_1bxn0Cig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_T2TDVpzo_sendMessage);
}

void Heavy_freqshift::cVar_Lh0miJPC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_YsuIcerp_sendMessage);
}

void Heavy_freqshift::cBinop_T2TDVpzo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_bi7p4TKC, 4, m);
}

void Heavy_freqshift::cBinop_YsuIcerp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_bi7p4TKC, 5, m);
}

void Heavy_freqshift::cSlice_fimcYnLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_EtsLDTIZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_G1S40gRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_l7O0jCHZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_UV2VnJu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_9tgxZ5x0, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_p5AulvrM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_9tgxZ5x0, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_M6gpJKq9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_9tgxZ5x0, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_8Ayeo02H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_EtsLDTIZ_sendMessage);
}

void Heavy_freqshift::cVar_cyK03Y1g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_l7O0jCHZ_sendMessage);
}

void Heavy_freqshift::cBinop_EtsLDTIZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_9tgxZ5x0, 4, m);
}

void Heavy_freqshift::cBinop_l7O0jCHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_9tgxZ5x0, 5, m);
}

void Heavy_freqshift::cSlice_QjwScnEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nNgwtwP0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_FMhyKYMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_t5V4ZEPQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_o7dUKdlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_n9hunAW9, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_fHpgcRIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_n9hunAW9, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_zVG06i74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_n9hunAW9, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_ScHjMtXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nNgwtwP0_sendMessage);
}

void Heavy_freqshift::cVar_bUWgLvhy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_t5V4ZEPQ_sendMessage);
}

void Heavy_freqshift::cBinop_nNgwtwP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_n9hunAW9, 4, m);
}

void Heavy_freqshift::cBinop_t5V4ZEPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_n9hunAW9, 5, m);
}

void Heavy_freqshift::cSlice_0MEcjP2X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9dqx8gNC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_YFH3nK4e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZB5nxb06_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_PnXp49RH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_htROYoEq, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_uw8bClv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_htROYoEq, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_FxVJGpHL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_htROYoEq, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_OFmt0zc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9dqx8gNC_sendMessage);
}

void Heavy_freqshift::cVar_zV5dMW95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZB5nxb06_sendMessage);
}

void Heavy_freqshift::cBinop_9dqx8gNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_htROYoEq, 4, m);
}

void Heavy_freqshift::cBinop_ZB5nxb06_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_htROYoEq, 5, m);
}

void Heavy_freqshift::cSlice_lD2CieAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_B9M6mX69_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_iB3b0uOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_S3iey3wI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_lu3auprr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_2AgFtKNy, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_NC5mLOsu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_2AgFtKNy, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_SkBHFvLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_2AgFtKNy, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_H7jHPzWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_B9M6mX69_sendMessage);
}

void Heavy_freqshift::cVar_j5xeYXlk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_S3iey3wI_sendMessage);
}

void Heavy_freqshift::cBinop_B9M6mX69_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_2AgFtKNy, 4, m);
}

void Heavy_freqshift::cBinop_S3iey3wI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_2AgFtKNy, 5, m);
}

void Heavy_freqshift::cSlice_QXbGPXDk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_W0ofody1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_3WZIgggw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SxHjW2ic_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_IizOEFv4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_MlimPGtt, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_mF9Wm7Qf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_MlimPGtt, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cSlice_r9ABpzBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_MlimPGtt, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_freqshift::cVar_hfJ0sgZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_W0ofody1_sendMessage);
}

void Heavy_freqshift::cVar_kddeelKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SxHjW2ic_sendMessage);
}

void Heavy_freqshift::cBinop_W0ofody1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_MlimPGtt, 4, m);
}

void Heavy_freqshift::cBinop_SxHjW2ic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_MlimPGtt, 5, m);
}

void Heavy_freqshift::cBinop_1or7h1DU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_78NXKufG_sendMessage);
}

void Heavy_freqshift::cBinop_78NXKufG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1UI36q5t, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fT1uXdqF, m);
}

void Heavy_freqshift::cReceive_b2DCgMIL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7SJEtIlN, 0, m, &cVar_7SJEtIlN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7CFYpZTw, 0, m, &cVar_7CFYpZTw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rat4OGjp, 0, m, &cVar_rat4OGjp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Af3I3boE, 0, m, &cVar_Af3I3boE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1bxn0Cig, 0, m, &cVar_1bxn0Cig_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Lh0miJPC, 0, m, &cVar_Lh0miJPC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8Ayeo02H, 0, m, &cVar_8Ayeo02H_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cyK03Y1g, 0, m, &cVar_cyK03Y1g_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ScHjMtXq, 0, m, &cVar_ScHjMtXq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bUWgLvhy, 0, m, &cVar_bUWgLvhy_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OFmt0zc1, 0, m, &cVar_OFmt0zc1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zV5dMW95, 0, m, &cVar_zV5dMW95_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_H7jHPzWm, 0, m, &cVar_H7jHPzWm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_j5xeYXlk, 0, m, &cVar_j5xeYXlk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hfJ0sgZ9, 0, m, &cVar_hfJ0sgZ9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kddeelKt, 0, m, &cVar_kddeelKt_sendMessage);
}

void Heavy_freqshift::cReceive_GNjwU66S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1or7h1DU_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_d1Axcjpq, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_CaFL7IO3, m);
}

void Heavy_freqshift::cReceive_14hweeUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OFGXdVLO, m);
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

int Heavy_freqshift::process(float **inputBuffers, float **outputBuffers, int n) {
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11;

  // input and output vars
  hv_bufferf_t O0, O1;
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
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_varread_f(&sVarf_OFGXdVLO, VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_PI8WyTTG, VIf(I0), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_DjIi8Efl, VIf(Bf1), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_bi7p4TKC, VIf(I0), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_9tgxZ5x0, VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_AixPp99F, VIf(Bf0), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_add_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf10), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf7), VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf3), VOf(Bf9));
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf4), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf11), VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf9), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_d1Axcjpq, VOf(Bf10));
    __hv_varread_f(&sVarf_1UI36q5t, VOf(Bf1));
    __hv_mul_f(VIf(I0), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf4), VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));
    __hv_varread_f(&sVarf_fT1uXdqF, VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_htROYoEq, VIf(I1), VOf(Bf10));
    __hv_biquad_k_f(&sBiquad_k_n9hunAW9, VIf(Bf10), VOf(Bf10));
    __hv_biquad_k_f(&sBiquad_k_2AgFtKNy, VIf(I1), VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_MlimPGtt, VIf(Bf4), VOf(Bf4));
    __hv_phasor_f(&sPhasor_587fIpGg, VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf7));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf11), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf3), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf6), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf7), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf0), VOf(Bf11));
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf11));
    __hv_mul_f(VIf(Bf0), VIf(Bf11), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf6), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf2), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf11), VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf10), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_CaFL7IO3, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(I1), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_freqshift::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s)
  float **const bIn = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bIn[0] = inputBuffers+(0*n4);
  bIn[1] = inputBuffers+(1*n4);

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_freqshift::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
