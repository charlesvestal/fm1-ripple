/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside nts-freqshift.pd) */

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
  numBytes += sBiquad_k_init(&sBiquad_k_sJnx0X7Y, 0.94657f, -1.94632f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_JjdgwOF3, 0.06338f, -0.83774f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_WFdT1cZe, -0.260502f, 0.02569f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_f06tMEAk, 0.870686f, -1.8685f, 1.0f, 0.0f, 0.0f);
  numBytes += sPhasor_init(&sPhasor_Jzkx3nsi, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_uYeKWmJx, 0.94657f, -1.94632f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_B8PLYauQ, 0.06338f, -0.83774f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_Y63xNEmJ, -0.260502f, 0.02569f, 1.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_efoMSPXF, 0.870686f, -1.8685f, 1.0f, 0.0f, 0.0f);
  numBytes += sPhasor_init(&sPhasor_fkKQ6Gsv, sampleRate);
  numBytes += cSlice_init(&cSlice_Nb4D5rvB, 0, 1);
  numBytes += cSlice_init(&cSlice_ddMBSPbZ, 1, 1);
  numBytes += cSlice_init(&cSlice_lkxve9MC, 2, 1);
  numBytes += cSlice_init(&cSlice_dxCDknRI, 3, 1);
  numBytes += cSlice_init(&cSlice_YfA94Ufz, 4, 1);
  numBytes += cVar_init_f(&cVar_QgqZPISl, 0.83774f);
  numBytes += cVar_init_f(&cVar_0SCyabZN, -0.06338f);
  numBytes += cSlice_init(&cSlice_r7TDV1ii, 0, 1);
  numBytes += cSlice_init(&cSlice_nATP9oWE, 1, 1);
  numBytes += cSlice_init(&cSlice_mMYjRHlV, 2, 1);
  numBytes += cSlice_init(&cSlice_LCECQz3X, 3, 1);
  numBytes += cSlice_init(&cSlice_5HTeJW53, 4, 1);
  numBytes += cVar_init_f(&cVar_OoZSw6Ms, 1.94632f);
  numBytes += cVar_init_f(&cVar_2v9Vwapo, -0.94657f);
  numBytes += cSlice_init(&cSlice_NPEO9prd, 0, 1);
  numBytes += cSlice_init(&cSlice_FNAXtUY9, 1, 1);
  numBytes += cSlice_init(&cSlice_X4COlfDA, 2, 1);
  numBytes += cSlice_init(&cSlice_auSo2k2R, 3, 1);
  numBytes += cSlice_init(&cSlice_X1SIzFBC, 4, 1);
  numBytes += cVar_init_f(&cVar_X9BEPEIo, -0.02569f);
  numBytes += cVar_init_f(&cVar_bCwYTmDg, 0.260502f);
  numBytes += cSlice_init(&cSlice_4fBR8bjT, 0, 1);
  numBytes += cSlice_init(&cSlice_Q8wedTBS, 1, 1);
  numBytes += cSlice_init(&cSlice_Z9yg7Dg8, 2, 1);
  numBytes += cSlice_init(&cSlice_90GF9oho, 3, 1);
  numBytes += cSlice_init(&cSlice_7C3AfMTa, 4, 1);
  numBytes += cVar_init_f(&cVar_vAmzdQTa, 1.8685f);
  numBytes += cVar_init_f(&cVar_OZFG91LE, -0.870686f);
  numBytes += sVarf_init(&sVarf_HM7y3vKJ, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_DDC8v9yO, 0, 1);
  numBytes += cSlice_init(&cSlice_oqD9mQKj, 1, 1);
  numBytes += cSlice_init(&cSlice_1QNORPG3, 2, 1);
  numBytes += cSlice_init(&cSlice_a0a5FdlT, 3, 1);
  numBytes += cSlice_init(&cSlice_2guNeVHx, 4, 1);
  numBytes += cVar_init_f(&cVar_Qpo76c8f, 0.83774f);
  numBytes += cVar_init_f(&cVar_7qGzdxGs, -0.06338f);
  numBytes += cSlice_init(&cSlice_uDKP2t4J, 0, 1);
  numBytes += cSlice_init(&cSlice_QJBfLdHP, 1, 1);
  numBytes += cSlice_init(&cSlice_yssTu6Tx, 2, 1);
  numBytes += cSlice_init(&cSlice_dbA0aBnP, 3, 1);
  numBytes += cSlice_init(&cSlice_EadvNix1, 4, 1);
  numBytes += cVar_init_f(&cVar_CaU3c4Kx, 1.94632f);
  numBytes += cVar_init_f(&cVar_bkNNIheC, -0.94657f);
  numBytes += cSlice_init(&cSlice_ATtJ95Lp, 0, 1);
  numBytes += cSlice_init(&cSlice_F8aEjz6t, 1, 1);
  numBytes += cSlice_init(&cSlice_EoQWNzzh, 2, 1);
  numBytes += cSlice_init(&cSlice_pVoY4zBR, 3, 1);
  numBytes += cSlice_init(&cSlice_mcqMJANg, 4, 1);
  numBytes += cVar_init_f(&cVar_R5uu7yfp, -0.02569f);
  numBytes += cVar_init_f(&cVar_hQFyv6ad, 0.260502f);
  numBytes += cSlice_init(&cSlice_vs5glErs, 0, 1);
  numBytes += cSlice_init(&cSlice_ZVYup0Hq, 1, 1);
  numBytes += cSlice_init(&cSlice_Es6AEmhy, 2, 1);
  numBytes += cSlice_init(&cSlice_MH1UtCUi, 3, 1);
  numBytes += cSlice_init(&cSlice_3pQDp6Kb, 4, 1);
  numBytes += cVar_init_f(&cVar_znJw9Jzn, 1.8685f);
  numBytes += cVar_init_f(&cVar_F8HGylRp, -0.870686f);
  numBytes += sVarf_init(&sVarf_q1Y4gPN0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5debQHz9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6kuAU5RB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2edGRDvs, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_E1LPEUQ8_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NSEQEa3H_sendMessage);
      break;
    }
    case 0x8E55AA5F: { // time
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_RPWuUMfQ_sendMessage);
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


void Heavy_nts_freqshift::cSlice_Nb4D5rvB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_z6DMK1nV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_ddMBSPbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1wUCHN2B_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_lkxve9MC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_B8PLYauQ, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_dxCDknRI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_B8PLYauQ, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_YfA94Ufz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_B8PLYauQ, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_QgqZPISl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_z6DMK1nV_sendMessage);
}

void Heavy_nts_freqshift::cVar_0SCyabZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_1wUCHN2B_sendMessage);
}

void Heavy_nts_freqshift::cBinop_z6DMK1nV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_B8PLYauQ, 4, m);
}

void Heavy_nts_freqshift::cBinop_1wUCHN2B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_B8PLYauQ, 5, m);
}

void Heavy_nts_freqshift::cSlice_r7TDV1ii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qGtsdvwL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_nATP9oWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_96nQAuor_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_mMYjRHlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uYeKWmJx, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_LCECQz3X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uYeKWmJx, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_5HTeJW53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uYeKWmJx, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_OoZSw6Ms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qGtsdvwL_sendMessage);
}

void Heavy_nts_freqshift::cVar_2v9Vwapo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_96nQAuor_sendMessage);
}

void Heavy_nts_freqshift::cBinop_qGtsdvwL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uYeKWmJx, 4, m);
}

void Heavy_nts_freqshift::cBinop_96nQAuor_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_uYeKWmJx, 5, m);
}

void Heavy_nts_freqshift::cSlice_NPEO9prd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Nz5ehGtf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_FNAXtUY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_O3FSydNl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_X4COlfDA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Y63xNEmJ, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_auSo2k2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Y63xNEmJ, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_X1SIzFBC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Y63xNEmJ, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_X9BEPEIo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Nz5ehGtf_sendMessage);
}

void Heavy_nts_freqshift::cVar_bCwYTmDg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_O3FSydNl_sendMessage);
}

void Heavy_nts_freqshift::cBinop_Nz5ehGtf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Y63xNEmJ, 4, m);
}

void Heavy_nts_freqshift::cBinop_O3FSydNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_Y63xNEmJ, 5, m);
}

void Heavy_nts_freqshift::cSlice_4fBR8bjT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Keu2DhEc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_Q8wedTBS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_q8zWav86_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_Z9yg7Dg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_efoMSPXF, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_90GF9oho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_efoMSPXF, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_7C3AfMTa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_efoMSPXF, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_vAmzdQTa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Keu2DhEc_sendMessage);
}

void Heavy_nts_freqshift::cVar_OZFG91LE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_q8zWav86_sendMessage);
}

void Heavy_nts_freqshift::cBinop_Keu2DhEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_efoMSPXF, 4, m);
}

void Heavy_nts_freqshift::cBinop_q8zWav86_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_efoMSPXF, 5, m);
}

void Heavy_nts_freqshift::cSlice_DDC8v9yO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_j9rEIF1A_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_oqD9mQKj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_iDYkN5oa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_1QNORPG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JjdgwOF3, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_a0a5FdlT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JjdgwOF3, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_2guNeVHx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JjdgwOF3, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_Qpo76c8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_j9rEIF1A_sendMessage);
}

void Heavy_nts_freqshift::cVar_7qGzdxGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_iDYkN5oa_sendMessage);
}

void Heavy_nts_freqshift::cBinop_j9rEIF1A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JjdgwOF3, 4, m);
}

void Heavy_nts_freqshift::cBinop_iDYkN5oa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_JjdgwOF3, 5, m);
}

void Heavy_nts_freqshift::cSlice_uDKP2t4J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Bb4M9Lu6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_QJBfLdHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9ea6Nbud_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_yssTu6Tx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_sJnx0X7Y, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_dbA0aBnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_sJnx0X7Y, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_EadvNix1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_sJnx0X7Y, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_CaU3c4Kx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Bb4M9Lu6_sendMessage);
}

void Heavy_nts_freqshift::cVar_bkNNIheC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9ea6Nbud_sendMessage);
}

void Heavy_nts_freqshift::cBinop_Bb4M9Lu6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_sJnx0X7Y, 4, m);
}

void Heavy_nts_freqshift::cBinop_9ea6Nbud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_sJnx0X7Y, 5, m);
}

void Heavy_nts_freqshift::cSlice_ATtJ95Lp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_x9dAyNRE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_F8aEjz6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cKZLk2uB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_EoQWNzzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_WFdT1cZe, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_pVoY4zBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_WFdT1cZe, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_mcqMJANg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_WFdT1cZe, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_R5uu7yfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_x9dAyNRE_sendMessage);
}

void Heavy_nts_freqshift::cVar_hQFyv6ad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cKZLk2uB_sendMessage);
}

void Heavy_nts_freqshift::cBinop_x9dAyNRE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_WFdT1cZe, 4, m);
}

void Heavy_nts_freqshift::cBinop_cKZLk2uB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_WFdT1cZe, 5, m);
}

void Heavy_nts_freqshift::cSlice_vs5glErs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uPzELTtn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_ZVYup0Hq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pqItlDFn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_Es6AEmhy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_f06tMEAk, 1, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_MH1UtCUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_f06tMEAk, 2, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cSlice_3pQDp6Kb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sBiquad_k_onMessage(&Context(_c)->sBiquad_k_f06tMEAk, 3, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_nts_freqshift::cVar_znJw9Jzn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uPzELTtn_sendMessage);
}

void Heavy_nts_freqshift::cVar_F8HGylRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_pqItlDFn_sendMessage);
}

void Heavy_nts_freqshift::cBinop_uPzELTtn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_f06tMEAk, 4, m);
}

void Heavy_nts_freqshift::cBinop_pqItlDFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_f06tMEAk, 5, m);
}

void Heavy_nts_freqshift::cBinop_UmIbUvTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_vp3Lv5hQ_sendMessage);
}

void Heavy_nts_freqshift::cBinop_vp3Lv5hQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5debQHz9, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6kuAU5RB, m);
}

void Heavy_nts_freqshift::cReceive_E1LPEUQ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QgqZPISl, 0, m, &cVar_QgqZPISl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0SCyabZN, 0, m, &cVar_0SCyabZN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OoZSw6Ms, 0, m, &cVar_OoZSw6Ms_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2v9Vwapo, 0, m, &cVar_2v9Vwapo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_X9BEPEIo, 0, m, &cVar_X9BEPEIo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bCwYTmDg, 0, m, &cVar_bCwYTmDg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vAmzdQTa, 0, m, &cVar_vAmzdQTa_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OZFG91LE, 0, m, &cVar_OZFG91LE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Qpo76c8f, 0, m, &cVar_Qpo76c8f_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7qGzdxGs, 0, m, &cVar_7qGzdxGs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CaU3c4Kx, 0, m, &cVar_CaU3c4Kx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bkNNIheC, 0, m, &cVar_bkNNIheC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_R5uu7yfp, 0, m, &cVar_R5uu7yfp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hQFyv6ad, 0, m, &cVar_hQFyv6ad_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_znJw9Jzn, 0, m, &cVar_znJw9Jzn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_F8HGylRp, 0, m, &cVar_F8HGylRp_sendMessage);
}

void Heavy_nts_freqshift::cReceive_NSEQEa3H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UmIbUvTo_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_q1Y4gPN0, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_2edGRDvs, m);
}

void Heavy_nts_freqshift::cReceive_RPWuUMfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HM7y3vKJ, m);
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
    __hv_varread_f(&sVarf_6kuAU5RB, VOf(Bf0));
    __hv_varread_f(&sVarf_HM7y3vKJ, VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_sJnx0X7Y, VIf(I1), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_JjdgwOF3, VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_WFdT1cZe, VIf(I1), VOf(Bf3));
    __hv_biquad_k_f(&sBiquad_k_f06tMEAk, VIf(Bf3), VOf(Bf3));
    __hv_phasor_f(&sPhasor_Jzkx3nsi, VIf(Bf1), VOf(Bf4));
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
    __hv_varread_f(&sVarf_2edGRDvs, VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(I1), VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf11), VIf(O1), VOf(O1));
    __hv_biquad_k_f(&sBiquad_k_uYeKWmJx, VIf(I0), VOf(Bf11));
    __hv_biquad_k_f(&sBiquad_k_B8PLYauQ, VIf(Bf11), VOf(Bf11));
    __hv_biquad_k_f(&sBiquad_k_Y63xNEmJ, VIf(I0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_efoMSPXF, VIf(Bf0), VOf(Bf0));
    __hv_phasor_f(&sPhasor_fkKQ6Gsv, VIf(Bf1), VOf(Bf1));
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
    __hv_varread_f(&sVarf_q1Y4gPN0, VOf(Bf9));
    __hv_varread_f(&sVarf_5debQHz9, VOf(Bf11));
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
