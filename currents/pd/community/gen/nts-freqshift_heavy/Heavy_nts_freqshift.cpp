/** the author of nts-freqshift.pd */

#include "Heavy_nts_freqshift.hpp"



#define Context(_c) static_cast<Heavy_nts_freqshift *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_nts_freqshift::Heavy_nts_freqshift(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sBiquad_k_init(&sBiquad_k_ywzj7Xg1, 0.94657f, -1.94632f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_QyuA3fxH, 0.06338f, -0.83774f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_3iuRBO9c, -0.260502f, 0.02569f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_TRAPOQGY, 0.870686f, -1.8685f, 1.0f, 0.0f, 0.0f);
  numBytes += sPhasor_init(&sPhasor_QWgIEGyM, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_8RgmhIA7, 0.94657f, -1.94632f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_NtRe0Rox, 0.06338f, -0.83774f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_JKXPGTh5, -0.260502f, 0.02569f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_T0TgcPr8, 0.870686f, -1.8685f, 1.0f, 0.0f, 0.0f);
  numBytes += sPhasor_init(&sPhasor_XAHd6vle, sampleRate);
  numBytes += cSlice_init(&cSlice_bZhqi0mP, 0, 1);
  numBytes += cSlice_init(&cSlice_jrH52Qz8, 1, 1);
  numBytes += cSlice_init(&cSlice_IJTYeIpt, 2, 1);
  numBytes += cSlice_init(&cSlice_s1A0NPvZ, 3, 1);
  numBytes += cSlice_init(&cSlice_cjzMq7I8, 4, 1);
  numBytes += cVar_init_f(&cVar_pnhv2bCn, 0.83774f);
  numBytes += cVar_init_f(&cVar_xN2Fgd05, -0.06338f);
  numBytes += cSlice_init(&cSlice_WNaHUaOx, 0, 1);
  numBytes += cSlice_init(&cSlice_pZNZK53u, 1, 1);
  numBytes += cSlice_init(&cSlice_zLxFdLcq, 2, 1);
  numBytes += cSlice_init(&cSlice_IYIGQdBL, 3, 1);
  numBytes += cSlice_init(&cSlice_0jeOcKKx, 4, 1);
  numBytes += cVar_init_f(&cVar_cTmbyabo, 1.94632f);
  numBytes += cVar_init_f(&cVar_s7OVqjp3, -0.94657f);
  numBytes += cSlice_init(&cSlice_TzZfBmor, 0, 1);
  numBytes += cSlice_init(&cSlice_UWO2gL4F, 1, 1);
  numBytes += cSlice_init(&cSlice_QKj6PHRG, 2, 1);
  numBytes += cSlice_init(&cSlice_3S4OES8C, 3, 1);
  numBytes += cSlice_init(&cSlice_BNfUDBRW, 4, 1);
  numBytes += cVar_init_f(&cVar_2Q9iBp5Q, -0.02569f);
  numBytes += cVar_init_f(&cVar_UUY0irHY, 0.260502f);
  numBytes += cSlice_init(&cSlice_RJUYZ9Ss, 0, 1);
  numBytes += cSlice_init(&cSlice_9HLN1Hgu, 1, 1);
  numBytes += cSlice_init(&cSlice_swnR4doZ, 2, 1);
  numBytes += cSlice_init(&cSlice_rUBU7lK8, 3, 1);
  numBytes += cSlice_init(&cSlice_7w772y5A, 4, 1);
  numBytes += cVar_init_f(&cVar_ukf6nPBg, 1.8685f);
  numBytes += cVar_init_f(&cVar_bw6TVQ1Y, -0.870686f);
  numBytes += sVarf_init(&sVarf_t8tUMDdn, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_GSFYjg7C, 0, 1);
  numBytes += cSlice_init(&cSlice_Jt3LKHkb, 1, 1);
  numBytes += cSlice_init(&cSlice_LBJIbr7O, 2, 1);
  numBytes += cSlice_init(&cSlice_LSgBMKO6, 3, 1);
  numBytes += cSlice_init(&cSlice_Hxa0Ng9c, 4, 1);
  numBytes += cVar_init_f(&cVar_WF9UfRRt, 0.83774f);
  numBytes += cVar_init_f(&cVar_VxQx69rT, -0.06338f);
  numBytes += cSlice_init(&cSlice_TWiSjnGc, 0, 1);
  numBytes += cSlice_init(&cSlice_KlCl36Y0, 1, 1);
  numBytes += cSlice_init(&cSlice_azXFCZCx, 2, 1);
  numBytes += cSlice_init(&cSlice_txBrQteg, 3, 1);
  numBytes += cSlice_init(&cSlice_R7DPiv45, 4, 1);
  numBytes += cVar_init_f(&cVar_DMfEWWtC, 1.94632f);
  numBytes += cVar_init_f(&cVar_kBm5ZCE5, -0.94657f);
  numBytes += cSlice_init(&cSlice_jxZyYJY4, 0, 1);
  numBytes += cSlice_init(&cSlice_F79Z15e2, 1, 1);
  numBytes += cSlice_init(&cSlice_Ijr2fYD0, 2, 1);
  numBytes += cSlice_init(&cSlice_dOwjpLAh, 3, 1);
  numBytes += cSlice_init(&cSlice_F3BtKyN7, 4, 1);
  numBytes += cVar_init_f(&cVar_C00Ucj78, -0.02569f);
  numBytes += cVar_init_f(&cVar_CwDJI3Ok, 0.260502f);
  numBytes += cSlice_init(&cSlice_lEtKgzNM, 0, 1);
  numBytes += cSlice_init(&cSlice_mVRTy1KK, 1, 1);
  numBytes += cSlice_init(&cSlice_vRzlAH26, 2, 1);
  numBytes += cSlice_init(&cSlice_Fciew1cC, 3, 1);
  numBytes += cSlice_init(&cSlice_1teNvYmV, 4, 1);
  numBytes += cVar_init_f(&cVar_Av8f2WdS, 1.8685f);
  numBytes += cVar_init_f(&cVar_hXNZSBug, -0.870686f);
  numBytes += sVarf_init(&sVarf_gUE2E8aC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dFB291wQ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eMmYjD6k, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_erqTGmzm, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_nts_freqshift::~Heavy_nts_freqshift() {
  // nothing to free
}

HvTable *Heavy_nts_freqshift::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_nts_freqshift::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ae61MeSf_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_goXDVYm7_sendMessage);
      break;
    }
    case 0x8E55AA5F: { // time
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_apelDefC_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_nts_freqshift::getParameterInfo(int index, HvParameterInfo *info) {
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


void Heavy_nts_freqshift::cSlice_bZhqi0mP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_oYjaAtCW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_jrH52Qz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5jYG4Y1d_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_IJTYeIpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_NtRe0Rox, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_s1A0NPvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_NtRe0Rox, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_cjzMq7I8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_NtRe0Rox, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_pnhv2bCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_oYjaAtCW_sendMessage);
}

void Heavy_nts_freqshift::cVar_xN2Fgd05_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5jYG4Y1d_sendMessage);
}

void Heavy_nts_freqshift::cBinop_oYjaAtCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_NtRe0Rox, 4, m);
}

void Heavy_nts_freqshift::cBinop_5jYG4Y1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_NtRe0Rox, 5, m);
}

void Heavy_nts_freqshift::cSlice_WNaHUaOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vjKYOF7m_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_pZNZK53u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kaZ6xr0g_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_zLxFdLcq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_8RgmhIA7, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_IYIGQdBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_8RgmhIA7, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_0jeOcKKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_8RgmhIA7, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_cTmbyabo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vjKYOF7m_sendMessage);
}

void Heavy_nts_freqshift::cVar_s7OVqjp3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kaZ6xr0g_sendMessage);
}

void Heavy_nts_freqshift::cBinop_vjKYOF7m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_8RgmhIA7, 4, m);
}

void Heavy_nts_freqshift::cBinop_kaZ6xr0g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_8RgmhIA7, 5, m);
}

void Heavy_nts_freqshift::cSlice_TzZfBmor_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_icwYv6pc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_UWO2gL4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UUnde6g4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_QKj6PHRG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JKXPGTh5, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_3S4OES8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JKXPGTh5, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_BNfUDBRW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JKXPGTh5, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_2Q9iBp5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_icwYv6pc_sendMessage);
}

void Heavy_nts_freqshift::cVar_UUY0irHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UUnde6g4_sendMessage);
}

void Heavy_nts_freqshift::cBinop_icwYv6pc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JKXPGTh5, 4, m);
}

void Heavy_nts_freqshift::cBinop_UUnde6g4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JKXPGTh5, 5, m);
}

void Heavy_nts_freqshift::cSlice_RJUYZ9Ss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_A6EmdNyd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_9HLN1Hgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_v8mQDFGz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_swnR4doZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_T0TgcPr8, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_rUBU7lK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_T0TgcPr8, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_7w772y5A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_T0TgcPr8, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_ukf6nPBg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_A6EmdNyd_sendMessage);
}

void Heavy_nts_freqshift::cVar_bw6TVQ1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_v8mQDFGz_sendMessage);
}

void Heavy_nts_freqshift::cBinop_A6EmdNyd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_T0TgcPr8, 4, m);
}

void Heavy_nts_freqshift::cBinop_v8mQDFGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_T0TgcPr8, 5, m);
}

void Heavy_nts_freqshift::cSlice_GSFYjg7C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Gem3tZf5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_Jt3LKHkb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bzJL3uGf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_LBJIbr7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_QyuA3fxH, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_LSgBMKO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_QyuA3fxH, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_Hxa0Ng9c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_QyuA3fxH, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_WF9UfRRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Gem3tZf5_sendMessage);
}

void Heavy_nts_freqshift::cVar_VxQx69rT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bzJL3uGf_sendMessage);
}

void Heavy_nts_freqshift::cBinop_Gem3tZf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_QyuA3fxH, 4, m);
}

void Heavy_nts_freqshift::cBinop_bzJL3uGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_QyuA3fxH, 5, m);
}

void Heavy_nts_freqshift::cSlice_TWiSjnGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DV0ByXVs_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_KlCl36Y0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cDWCZDfB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_azXFCZCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_ywzj7Xg1, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_txBrQteg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_ywzj7Xg1, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_R7DPiv45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_ywzj7Xg1, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_DMfEWWtC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DV0ByXVs_sendMessage);
}

void Heavy_nts_freqshift::cVar_kBm5ZCE5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cDWCZDfB_sendMessage);
}

void Heavy_nts_freqshift::cBinop_DV0ByXVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_ywzj7Xg1, 4, m);
}

void Heavy_nts_freqshift::cBinop_cDWCZDfB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_ywzj7Xg1, 5, m);
}

void Heavy_nts_freqshift::cSlice_jxZyYJY4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Xd94ZFaw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_F79Z15e2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5RB9xwFr_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_Ijr2fYD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3iuRBO9c, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_dOwjpLAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3iuRBO9c, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_F3BtKyN7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3iuRBO9c, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_C00Ucj78_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Xd94ZFaw_sendMessage);
}

void Heavy_nts_freqshift::cVar_CwDJI3Ok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5RB9xwFr_sendMessage);
}

void Heavy_nts_freqshift::cBinop_Xd94ZFaw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3iuRBO9c, 4, m);
}

void Heavy_nts_freqshift::cBinop_5RB9xwFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3iuRBO9c, 5, m);
}

void Heavy_nts_freqshift::cSlice_lEtKgzNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZJJYW1vf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_mVRTy1KK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_6eSJoMaC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_vRzlAH26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_TRAPOQGY, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_Fciew1cC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_TRAPOQGY, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_1teNvYmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_TRAPOQGY, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_Av8f2WdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZJJYW1vf_sendMessage);
}

void Heavy_nts_freqshift::cVar_hXNZSBug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_6eSJoMaC_sendMessage);
}

void Heavy_nts_freqshift::cBinop_ZJJYW1vf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_TRAPOQGY, 4, m);
}

void Heavy_nts_freqshift::cBinop_6eSJoMaC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_TRAPOQGY, 5, m);
}

void Heavy_nts_freqshift::cBinop_og7mOPbd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_uLhbUs1i_sendMessage);
}

void Heavy_nts_freqshift::cBinop_uLhbUs1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dFB291wQ, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eMmYjD6k, m);
}

void Heavy_nts_freqshift::cReceive_Ae61MeSf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pnhv2bCn, 0, m, &cVar_pnhv2bCn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xN2Fgd05, 0, m, &cVar_xN2Fgd05_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cTmbyabo, 0, m, &cVar_cTmbyabo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_s7OVqjp3, 0, m, &cVar_s7OVqjp3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2Q9iBp5Q, 0, m, &cVar_2Q9iBp5Q_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UUY0irHY, 0, m, &cVar_UUY0irHY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ukf6nPBg, 0, m, &cVar_ukf6nPBg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bw6TVQ1Y, 0, m, &cVar_bw6TVQ1Y_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WF9UfRRt, 0, m, &cVar_WF9UfRRt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VxQx69rT, 0, m, &cVar_VxQx69rT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DMfEWWtC, 0, m, &cVar_DMfEWWtC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kBm5ZCE5, 0, m, &cVar_kBm5ZCE5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_C00Ucj78, 0, m, &cVar_C00Ucj78_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CwDJI3Ok, 0, m, &cVar_CwDJI3Ok_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Av8f2WdS, 0, m, &cVar_Av8f2WdS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hXNZSBug, 0, m, &cVar_hXNZSBug_sendMessage);
}

void Heavy_nts_freqshift::cReceive_goXDVYm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_og7mOPbd_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gUE2E8aC, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_erqTGmzm, m);
}

void Heavy_nts_freqshift::cReceive_apelDefC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_t8tUMDdn, m);
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

int Heavy_nts_freqshift::process(float **inputBuffers, float **outputBuffers, int n) {
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12;

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
    __hv_varread_f(&sVarf_eMmYjD6k, VOf(Bf0));
    __hv_varread_f(&sVarf_t8tUMDdn, VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_ywzj7Xg1, VIf(I1), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_QyuA3fxH, VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_3iuRBO9c, VIf(I1), VOf(Bf3));
    __hv_biquad_k_f(&sBiquad_k_TRAPOQGY, VIf(Bf3), VOf(Bf3));
    __hv_phasor_f(&sPhasor_QWgIEGyM, VIf(Bf1), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf6));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf10), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf11), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf8), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf11), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf6), VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf4), VOf(Bf10));
    __hv_sub_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf10));
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf10), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf10), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf8), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf5), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf12), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf10), VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_erqTGmzm, VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(I1), VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf11), VIf(O1), VOf(O1));
    __hv_biquad_k_f(&sBiquad_k_8RgmhIA7, VIf(I0), VOf(Bf11));
    __hv_biquad_k_f(&sBiquad_k_NtRe0Rox, VIf(Bf11), VOf(Bf11));
    __hv_biquad_k_f(&sBiquad_k_JKXPGTh5, VIf(I0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_T0TgcPr8, VIf(Bf0), VOf(Bf0));
    __hv_phasor_f(&sPhasor_XAHd6vle, VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_add_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf9), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf9), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf2), VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf1), VOf(Bf7));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf7), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f, 2.75573e-06f);
    __hv_var_k_f(VOf(Bf5), 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f, 0.00833333f);
    __hv_var_k_f(VOf(Bf3), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f, 0.000198413f);
    __hv_mul_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf11), VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_gUE2E8aC, VOf(Bf9));
    __hv_varread_f(&sVarf_dFB291wQ, VOf(Bf11));
    __hv_mul_f(VIf(I0), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf11), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_nts_freqshift::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_nts_freqshift::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
