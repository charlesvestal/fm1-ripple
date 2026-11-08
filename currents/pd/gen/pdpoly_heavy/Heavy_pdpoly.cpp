/** the author of pdpoly.pd */

#include "Heavy_pdpoly.hpp"



#define Context(_c) static_cast<Heavy_pdpoly *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_pdpoly::Heavy_pdpoly(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_vyZIbQlk, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_WYrgTCjQ, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_ySZZ6RiE);
  numBytes += sRPole_init(&sRPole_lM2eE5uE);
  numBytes += sLine_init(&sLine_fR5CwoDS);
  numBytes += sPhasor_k_init(&sPhasor_MQzdNxNy, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_cgADDeVM, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_5SxbcECz);
  numBytes += sRPole_init(&sRPole_Gg1A5QgW);
  numBytes += sLine_init(&sLine_k8rBaXbn);
  numBytes += sPhasor_k_init(&sPhasor_TxzGZY9c, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_ZBnX5GiY, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_Bpt6Jydq);
  numBytes += sRPole_init(&sRPole_O5KIdSkr);
  numBytes += sLine_init(&sLine_jYMNuwLX);
  numBytes += sPhasor_k_init(&sPhasor_Mo05cnpf, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_nfXm5ZSi, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_C8IMQzMY);
  numBytes += sRPole_init(&sRPole_kyG2EgI5);
  numBytes += sLine_init(&sLine_YYlSodFP);
  numBytes += cSlice_init(&cSlice_vJM85at6, 2, 1);
  numBytes += cSlice_init(&cSlice_8yH8sMUs, 1, 1);
  numBytes += cSlice_init(&cSlice_SIHu9SRW, 0, 1);
  numBytes += cVar_init_f(&cVar_lsVZNUsl, 0.0f);
  numBytes += cIf_init(&cIf_pcLvKn7O, false);
  numBytes += cIf_init(&cIf_cmFGh6LY, false);
  numBytes += cIf_init(&cIf_tOM8kwXp, false);
  numBytes += cIf_init(&cIf_ElrtSIS4, false);
  numBytes += cIf_init(&cIf_dLcUDr1n, false);
  numBytes += cBinop_init(&cBinop_JAJH5CgK, 0.0f); // __eq
  numBytes += cVar_init_f(&cVar_AJ8R6Ur5, 1.0f);
  numBytes += cVar_init_f(&cVar_16omqKib, 0.0f);
  numBytes += cSlice_init(&cSlice_fn91j0Lt, 1, -1);
  numBytes += cSlice_init(&cSlice_HFS8GpLD, 1, -1);
  numBytes += cSlice_init(&cSlice_GoVkeFd8, 1, 1);
  numBytes += cSlice_init(&cSlice_ZqEVDnvU, 0, 1);
  numBytes += cVar_init_f(&cVar_o4A8F7fO, 0.0f);
  numBytes += cIf_init(&cIf_vugbmLQS, false);
  numBytes += cIf_init(&cIf_4NLqrAB1, false);
  numBytes += cIf_init(&cIf_XNvWa4w7, false);
  numBytes += cVar_init_f(&cVar_f5ijZRSo, 0.0f);
  numBytes += cIf_init(&cIf_TFiPpzp3, false);
  numBytes += cVar_init_f(&cVar_S6V7NVXq, 0.0f);
  numBytes += cIf_init(&cIf_9G1svXsG, false);
  numBytes += cBinop_init(&cBinop_Mvsrw0ao, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_Z2rv0r8w, 4.0f);
  numBytes += cTabread_init(&cTabread_MZefUgqR, &hTable_UVzMnHcd); // 1011-used
  numBytes += cSlice_init(&cSlice_VLZG45kM, 1, -1);
  numBytes += cVar_init_s(&cVar_GRIPDVDR, "1011-used");
  numBytes += cBinop_init(&cBinop_nDliHJwO, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_giqTwb7i, &hTable_ILTVyuDN); // 1011-ids
  numBytes += cSlice_init(&cSlice_FZwRP5tj, 1, -1);
  numBytes += cVar_init_s(&cVar_ubdxtYCC, "1011-ids");
  numBytes += cBinop_init(&cBinop_VKBaZlwR, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_LrgBi1hu, 0.0f);
  numBytes += cSlice_init(&cSlice_Mw90BSix, 1, 1);
  numBytes += cSlice_init(&cSlice_gR8TJcKQ, 0, 1);
  numBytes += cTabread_init(&cTabread_BYrWVaj3, &hTable_UiQjL6BL); // 1011-pitches
  numBytes += cSlice_init(&cSlice_LWwLlFdl, 1, -1);
  numBytes += cVar_init_s(&cVar_w9faYfeJ, "1011-pitches");
  numBytes += cBinop_init(&cBinop_0viNWCdX, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_MoiEd9fD, 0.0f);
  numBytes += cVar_init_f(&cVar_2nR2WoW4, 0.0f);
  numBytes += cIf_init(&cIf_sZbbTa4W, false);
  numBytes += cTabwrite_init(&cTabwrite_HAu1LTFD, &hTable_UVzMnHcd); // 1011-used
  numBytes += cSlice_init(&cSlice_9XxjgMt9, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_6xEJURw6, &hTable_ILTVyuDN); // 1011-ids
  numBytes += cSlice_init(&cSlice_egArjPIg, 1, -1);
  numBytes += cVar_init_f(&cVar_NAgeb8rw, 0.0f);
  numBytes += cVar_init_f(&cVar_n86xtYd8, 0.0f);
  numBytes += cSlice_init(&cSlice_fL5ixPbR, 1, 1);
  numBytes += cSlice_init(&cSlice_inb9EJmW, 0, 1);
  numBytes += cPack_init(&cPack_2vEu94Ky, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_l4NBqvlb, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_KWLvVCfL, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_Sm7jKR57, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_pQFIxNMB, 0.0f); // __lt
  numBytes += cIf_init(&cIf_zzlWGh0v, false);
  numBytes += cVar_init_f(&cVar_oznCTVn4, 0.0f);
  numBytes += cIf_init(&cIf_fzWd3iZ3, false);
  numBytes += cVar_init_f(&cVar_jZjAOfsg, 0.0f);
  numBytes += cIf_init(&cIf_2hsaSctM, false);
  numBytes += cBinop_init(&cBinop_jtbQ1oP7, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_t1A3WPPl, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_s742EvvW, &hTable_UVzMnHcd); // 1011-used
  numBytes += cSlice_init(&cSlice_jsXVsBOL, 1, -1);
  numBytes += cTabread_init(&cTabread_J3vKGbic, &hTable_UVzMnHcd); // 1011-used
  numBytes += cSlice_init(&cSlice_fICu9SAk, 1, -1);
  numBytes += cVar_init_s(&cVar_6OzXFFkx, "1011-used");
  numBytes += cBinop_init(&cBinop_jGawFu68, 0.0f); // __min
  numBytes += cIf_init(&cIf_ROEJnS7k, false);
  numBytes += cTabread_init(&cTabread_8DhxzOMb, &hTable_UiQjL6BL); // 1011-pitches
  numBytes += cSlice_init(&cSlice_s97yHvPy, 1, -1);
  numBytes += cVar_init_s(&cVar_gVKy8Uzm, "1011-pitches");
  numBytes += cBinop_init(&cBinop_mIVE4LBd, 0.0f); // __min
  numBytes += cIf_init(&cIf_hy4qjBy1, false);
  numBytes += cVar_init_f(&cVar_ztpOI6cn, 0.0f);
  numBytes += cIf_init(&cIf_YQAPv1kk, false);
  numBytes += cVar_init_f(&cVar_C9RFyzdo, 0.0f);
  numBytes += cIf_init(&cIf_dpHYjfjR, false);
  numBytes += cBinop_init(&cBinop_S8dmMzxr, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_x2bZBxDX, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_iwSJvXb3, &hTable_UVzMnHcd); // 1011-used
  numBytes += cSlice_init(&cSlice_SVc7E4Ds, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_tr6jprdh, &hTable_ILTVyuDN); // 1011-ids
  numBytes += cSlice_init(&cSlice_SbUc3StX, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_Bp33joQA, &hTable_UiQjL6BL); // 1011-pitches
  numBytes += cSlice_init(&cSlice_vA7PWkfX, 1, -1);
  numBytes += cIf_init(&cIf_zN5PYH16, false);
  numBytes += cVar_init_f(&cVar_cpdhe8ZC, 0.0f);
  numBytes += cIf_init(&cIf_ooDg5y7d, false);
  numBytes += cVar_init_f(&cVar_0gKtB7k1, 0.0f);
  numBytes += cIf_init(&cIf_fuctu4SK, false);
  numBytes += cBinop_init(&cBinop_NS0Dn92m, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_8edDaEgb, 4.0f);
  numBytes += cVar_init_f(&cVar_wvjYFKQQ, 0.0f);
  numBytes += cIf_init(&cIf_iqrMJoQS, false);
  numBytes += cVar_init_f(&cVar_rvcQKJ42, 0.0f);
  numBytes += cVar_init_f(&cVar_gKibkYmw, 0.0f);
  numBytes += cVar_init_f(&cVar_67rh20Bf, 0.0f);
  numBytes += cIf_init(&cIf_h4cJRF46, false);
  numBytes += cIf_init(&cIf_RYLVq2Rt, false);
  numBytes += cPack_init(&cPack_ngrzHWwN, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_uo6ghQ3Q, 0.0f);
  numBytes += cSlice_init(&cSlice_cLkXYoY0, 1, 1);
  numBytes += cSlice_init(&cSlice_CbuCtlS1, 0, 1);
  numBytes += cVar_init_f(&cVar_qEaE1CT6, 0.0f);
  numBytes += cIf_init(&cIf_3Q2Be6eu, false);
  numBytes += cVar_init_f(&cVar_wf4yciyL, 0.0f);
  numBytes += cVar_init_f(&cVar_mTomH9ii, 0.0f);
  numBytes += cTabread_init(&cTabread_sSwiX7Nj, &hTable_UVzMnHcd); // 1011-used
  numBytes += cSlice_init(&cSlice_uikpacSj, 1, -1);
  numBytes += cVar_init_s(&cVar_kmyV7htA, "1011-used");
  numBytes += cBinop_init(&cBinop_yBGWHbJo, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_X2pnH3XL, &hTable_ILTVyuDN); // 1011-ids
  numBytes += cSlice_init(&cSlice_dyMeu2E9, 1, -1);
  numBytes += cVar_init_s(&cVar_3v9ZKqeS, "1011-ids");
  numBytes += cBinop_init(&cBinop_ftcvamSX, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_9gyq1uoG, &hTable_UiQjL6BL); // 1011-pitches
  numBytes += cSlice_init(&cSlice_zAWUOGDG, 1, -1);
  numBytes += cTabread_init(&cTabread_yPjwMjra, &hTable_UiQjL6BL); // 1011-pitches
  numBytes += cSlice_init(&cSlice_sO0fymMm, 1, -1);
  numBytes += cVar_init_s(&cVar_xeE6z1qI, "1011-pitches");
  numBytes += cBinop_init(&cBinop_4ifpXarn, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_G0nXVqmg, &hTable_UiQjL6BL); // 1011-pitches
  numBytes += cSlice_init(&cSlice_nJvvO9cB, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_AVF98KHV, &hTable_UVzMnHcd); // 1011-used
  numBytes += cSlice_init(&cSlice_IVV0Tkap, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_l6jky5CB, &hTable_ILTVyuDN); // 1011-ids
  numBytes += cSlice_init(&cSlice_UXiIJI5B, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_0JmFPnsb, &hTable_ILTVyuDN); // 1011-ids
  numBytes += cSlice_init(&cSlice_NghvaPY9, 1, -1);
  numBytes += cVar_init_f(&cVar_6JGlNCru, 0.0f);
  numBytes += cTabwrite_init(&cTabwrite_6svlClAy, &hTable_UVzMnHcd); // 1011-used
  numBytes += cSlice_init(&cSlice_BdnyTuzX, 1, -1);
  numBytes += cVar_init_f(&cVar_eBaZ8Ttb, 0.0f);
  numBytes += cSlice_init(&cSlice_X5VxJnBN, 1, 1);
  numBytes += cSlice_init(&cSlice_7wVrmXng, 0, 1);
  numBytes += cVar_init_f(&cVar_BfSASXRQ, 0.0f);
  numBytes += cBinop_init(&cBinop_R8WMbiTP, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_o569gd1w, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_o8Po9J2G, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_g8Z6xoLR, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_7xPKHvEg, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_ZPylfuwm, 65535.0f); // __unimod
  numBytes += hTable_init(&hTable_UiQjL6BL, 4);
  numBytes += hTable_init(&hTable_UVzMnHcd, 4);
  numBytes += hTable_init(&hTable_ILTVyuDN, 4);
  numBytes += cPack_init(&cPack_H7Ike5Hf, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_CHPPg4KV, 1, -1);
  numBytes += cSlice_init(&cSlice_5yJR9VoD, 1, -1);
  numBytes += cSlice_init(&cSlice_w0UxxNkk, 1, -1);
  numBytes += cSlice_init(&cSlice_NEIWRten, 1, -1);
  numBytes += cSlice_init(&cSlice_C0DX7M2y, 1, 1);
  numBytes += cSlice_init(&cSlice_S7FY0Tm8, 0, 1);
  numBytes += cBinop_init(&cBinop_EK5kSOti, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_4lgoA68E, 22050.0f);
  numBytes += cBinop_init(&cBinop_NQgGnol4, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_KpTq09U6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RVOnR7Ce, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_JuF1I4no, 22050.0f);
  numBytes += cBinop_init(&cBinop_bWOQBgQd, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_E6NJLhOC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7mNFNAmQ, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_bOx8pVic, 1, 1);
  numBytes += cSlice_init(&cSlice_fhWAquQz, 0, 1);
  numBytes += cBinop_init(&cBinop_75xRWXbQ, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_iBDGtMYd, 22050.0f);
  numBytes += cBinop_init(&cBinop_KqqqczIQ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_QTk0OC5c, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NsJwtfMl, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_StpUpoZR, 22050.0f);
  numBytes += cBinop_init(&cBinop_AU5SxJbw, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_QPyUY6aK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mOIKXYD9, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_7UxooZCW, 1, 1);
  numBytes += cSlice_init(&cSlice_Cf0KELKj, 0, 1);
  numBytes += cBinop_init(&cBinop_VCccQzGO, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_VI93BZkW, 22050.0f);
  numBytes += cBinop_init(&cBinop_AvLrtITS, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Z7uCXwdz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iLFkkQs6, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_GmXRaqwm, 22050.0f);
  numBytes += cBinop_init(&cBinop_M8Vv71Zh, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_HGxtndEL, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tsdAAmaL, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_JAclRJwH, 1, 1);
  numBytes += cSlice_init(&cSlice_wELPeCDZ, 0, 1);
  numBytes += cBinop_init(&cBinop_Mube7JYJ, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_m3zEabfB, 22050.0f);
  numBytes += cBinop_init(&cBinop_V1WQCbrD, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_hreMP8Pc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3gYwbVLh, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_aIaKahr6, 22050.0f);
  numBytes += cBinop_init(&cBinop_DATPsdwr, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Pkwo2Df2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cYRdYRj7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7ksqJUyc, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_pdpoly::~Heavy_pdpoly() {
  cPack_free(&cPack_2vEu94Ky);
  cPack_free(&cPack_ngrzHWwN);
  hTable_free(&hTable_UiQjL6BL);
  hTable_free(&hTable_UVzMnHcd);
  hTable_free(&hTable_ILTVyuDN);
  cPack_free(&cPack_H7Ike5Hf);
}

HvTable *Heavy_pdpoly::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x7B847FB6: return &hTable_UiQjL6BL; // 1011-pitches
    case 0xA0EFCB1D: return &hTable_UVzMnHcd; // 1011-used
    case 0x73137BF4: return &hTable_ILTVyuDN; // 1011-ids
    default: return nullptr;
  }
}

void Heavy_pdpoly::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x7EA4AD17: { // 1011-currentVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_weNI5WmG_sendMessage);
      break;
    }
    case 0x9B1DF8F3: { // 1011-indexOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9wiOdh1P_sendMessage);
      break;
    }
    case 0xF7855D22: { // 1011-indexOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Aiw3Bh8g_sendMessage);
      break;
    }
    case 0xEB1BA925: { // 1011-isFirstOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hzTJd0wA_sendMessage);
      break;
    }
    case 0x7426D59: { // 1011-isFirstOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_O53SSTpX_sendMessage);
      break;
    }
    case 0x199E738B: { // 1011-maxVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_F3CosXnX_sendMessage);
      break;
    }
    case 0x979E98C4: { // 1011-shouldSteal
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TbaGHDcz_sendMessage);
      break;
    }
    case 0xDB67A714: { // 1011-voiceId++
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_joGY7NQC_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_z1jAlaNl_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0X2lQlB6_sendMessage);
      break;
    }
    case 0xF89F9F3E: { // cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cInKZtXx_sendMessage);
      break;
    }
    case 0xC2C62B6: { // vcut
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ira3726J_sendMessage);
      break;
    }
    case 0xB1642755: { // volume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_l8C3ThDT_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_pdpoly::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "cutoff";
        info->hash = 0xF89F9F3E;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 100.0f;
        info->maxVal = 8000.0f;
        info->defaultVal = 1500.0f;
        break;
      }
      case 1: {
        info->name = "volume";
        info->hash = 0xB1642755;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.3f;
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


void Heavy_pdpoly::cSlice_vJM85at6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_RnVkQ1w2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_8yH8sMUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_ElrtSIS4, 0, m, &cIf_ElrtSIS4_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_cmFGh6LY, 0, m, &cIf_cmFGh6LY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_SIHu9SRW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_dLcUDr1n, 0, m, &cIf_dLcUDr1n_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_tOM8kwXp, 0, m, &cIf_tOM8kwXp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_lsVZNUsl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_qRq37GB7_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_pcLvKn7O, 0, m, &cIf_pcLvKn7O_sendMessage);
}

void Heavy_pdpoly::cUnop_647sz9uE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_ZFbLSOQw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JAJH5CgK, HV_BINOP_EQ, 1, m, &cBinop_JAJH5CgK_sendMessage);
}

void Heavy_pdpoly::cUnop_aW0RR8Kg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_ZFbLSOQw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JAJH5CgK, HV_BINOP_EQ, 1, m, &cBinop_JAJH5CgK_sendMessage);
}

void Heavy_pdpoly::cIf_pcLvKn7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_aW0RR8Kg_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_647sz9uE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_qRq37GB7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_pcLvKn7O, 1, m, &cIf_pcLvKn7O_sendMessage);
}

void Heavy_pdpoly::cIf_cmFGh6LY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_o4A8F7fO, 0, m, &cVar_o4A8F7fO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_tOM8kwXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_17Id76wu_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_ElrtSIS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_o4A8F7fO, 0, m, &cVar_o4A8F7fO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_dLcUDr1n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_17Id76wu_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_RnVkQ1w2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JAJH5CgK, HV_BINOP_EQ, 0, m, &cBinop_JAJH5CgK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_TYptHtko_sendMessage);
}

void Heavy_pdpoly::cBinop_ZFbLSOQw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HMeM4Ifn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pFXgHEGh_sendMessage);
}

void Heavy_pdpoly::cBinop_JAJH5CgK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7QfOKu4a_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tkiQaPZA_sendMessage);
}

void Heavy_pdpoly::cCast_7QfOKu4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cmFGh6LY, 1, m, &cIf_cmFGh6LY_sendMessage);
}

void Heavy_pdpoly::cCast_tkiQaPZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dLcUDr1n, 1, m, &cIf_dLcUDr1n_sendMessage);
}

void Heavy_pdpoly::cCast_HMeM4Ifn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ElrtSIS4, 1, m, &cIf_ElrtSIS4_sendMessage);
}

void Heavy_pdpoly::cCast_pFXgHEGh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tOM8kwXp, 1, m, &cIf_tOM8kwXp_sendMessage);
}

void Heavy_pdpoly::cBinop_TYptHtko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cVar_AJ8R6Ur5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_5MzHk9H8_sendMessage);
}

void Heavy_pdpoly::cVar_16omqKib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZPylfuwm, HV_BINOP_MOD_UNIPOLAR, 0, m, &cBinop_ZPylfuwm_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_17Id76wu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fn91j0Lt, 0, m, &cSlice_fn91j0Lt_sendMessage);
      break;
    }
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_HFS8GpLD, 0, m, &cSlice_HFS8GpLD_sendMessage);
      break;
    }
    default: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_GoVkeFd8, 0, m, &cSlice_GoVkeFd8_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZqEVDnvU, 0, m, &cSlice_ZqEVDnvU_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_fn91j0Lt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dmrXV7hw_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6JcKbea5_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dmrXV7hw_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6JcKbea5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_HFS8GpLD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZPdUMILE_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nrSFanHv_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZPdUMILE_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nrSFanHv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_GoVkeFd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_o4A8F7fO, 0, m, &cVar_o4A8F7fO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_ZqEVDnvU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_vugbmLQS, 0, m, &cIf_vugbmLQS_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_4NLqrAB1, 0, m, &cIf_4NLqrAB1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_o4A8F7fO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ngrzHWwN, 1, m, &cPack_ngrzHWwN_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_2vEu94Ky, 1, m, &cPack_2vEu94Ky_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_B3UiFze4_sendMessage);
}

void Heavy_pdpoly::cIf_vugbmLQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yrfyxWEG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NuS6jMWt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5jEp7KiE_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_ngrzHWwN, 0, m, &cPack_ngrzHWwN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_4NLqrAB1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_2vEu94Ky, 0, m, &cPack_2vEu94Ky_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_XNvWa4w7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4dqT9KfS_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pAq7s9RH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_f5ijZRSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wnQ4RQnC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rngq0ZYP_sendMessage);
}

void Heavy_pdpoly::cIf_TFiPpzp3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J95EW3et_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aksJtW8Q_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_zko5Vu5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TFiPpzp3, 1, m, &cIf_TFiPpzp3_sendMessage);
}

void Heavy_pdpoly::cVar_S6V7NVXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_1PJ0NBPL_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_9G1svXsG, 0, m, &cIf_9G1svXsG_sendMessage);
}

void Heavy_pdpoly::cUnop_2WaH0mYt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_zko5Vu5R_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_TFiPpzp3, 0, m, &cIf_TFiPpzp3_sendMessage);
}

void Heavy_pdpoly::cUnop_5fmOtBWt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_zko5Vu5R_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_TFiPpzp3, 0, m, &cIf_TFiPpzp3_sendMessage);
}

void Heavy_pdpoly::cIf_9G1svXsG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_5fmOtBWt_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2WaH0mYt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_1PJ0NBPL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9G1svXsG, 1, m, &cIf_9G1svXsG_sendMessage);
}

void Heavy_pdpoly::cCast_rngq0ZYP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XNvWa4w7, 0, m, &cIf_XNvWa4w7_sendMessage);
}

void Heavy_pdpoly::cCast_wnQ4RQnC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mvsrw0ao, HV_BINOP_LESS_THAN, 0, m, &cBinop_Mvsrw0ao_sendMessage);
}

void Heavy_pdpoly::cBinop_Mvsrw0ao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XNvWa4w7, 1, m, &cIf_XNvWa4w7_sendMessage);
}

void Heavy_pdpoly::cCast_J95EW3et_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mvsrw0ao, HV_BINOP_LESS_THAN, 1, m, &cBinop_Mvsrw0ao_sendMessage);
}

void Heavy_pdpoly::cCast_aksJtW8Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NYyeLgOn_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_1j7nSIRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_f5ijZRSo, 0, m, &cVar_f5ijZRSo_sendMessage);
}

void Heavy_pdpoly::cMsg_NYyeLgOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_f5ijZRSo, 0, m, &cVar_f5ijZRSo_sendMessage);
}

void Heavy_pdpoly::cCast_pAq7s9RH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_1j7nSIRi_sendMessage);
}

void Heavy_pdpoly::cCast_4dqT9KfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d8clmKgC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wvcYiYpC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aauWDaUj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Uhe0ObQa_sendMessage);
}

void Heavy_pdpoly::cVar_Z2rv0r8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_S6V7NVXq, 0, m, &cVar_S6V7NVXq_sendMessage);
}

void Heavy_pdpoly::cTabread_MZefUgqR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sm7jKR57, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_Sm7jKR57_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_61rMPCrB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VLZG45kM, 0, m, &cSlice_VLZG45kM_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JAZ5FEhP_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hnGn9j70_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_VLZG45kM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_MZefUgqR, 1, m, &cTabread_MZefUgqR_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_MZefUgqR, 1, m, &cTabread_MZefUgqR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_GRIPDVDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ax7bIT2I_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_yus4MqLW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_0BFnu7ms_sendMessage);
}

void Heavy_pdpoly::cBinop_iIyngaCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nDliHJwO, HV_BINOP_MIN, 0, m, &cBinop_nDliHJwO_sendMessage);
}

void Heavy_pdpoly::cCast_hnGn9j70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_iIyngaCz_sendMessage);
}

void Heavy_pdpoly::cCast_JAZ5FEhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GRIPDVDR, 0, m, &cVar_GRIPDVDR_sendMessage);
}

void Heavy_pdpoly::cBinop_nDliHJwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_MZefUgqR, 0, m, &cTabread_MZefUgqR_sendMessage);
}

void Heavy_pdpoly::cMsg_ax7bIT2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yus4MqLW_sendMessage);
}

void Heavy_pdpoly::cBinop_0BFnu7ms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nDliHJwO, HV_BINOP_MIN, 1, m, &cBinop_nDliHJwO_sendMessage);
}

void Heavy_pdpoly::cTabread_giqTwb7i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EYKWtLrZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yizGfE0P_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_SJkDgTlw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_FZwRP5tj, 0, m, &cSlice_FZwRP5tj_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KNbkfk2M_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AgVUujdO_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_FZwRP5tj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_giqTwb7i, 1, m, &cTabread_giqTwb7i_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_giqTwb7i, 1, m, &cTabread_giqTwb7i_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_ubdxtYCC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z35ArqHs_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_18P0hVHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_jtDhMWip_sendMessage);
}

void Heavy_pdpoly::cBinop_aVBwaJ41_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VKBaZlwR, HV_BINOP_MIN, 0, m, &cBinop_VKBaZlwR_sendMessage);
}

void Heavy_pdpoly::cCast_AgVUujdO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_aVBwaJ41_sendMessage);
}

void Heavy_pdpoly::cCast_KNbkfk2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ubdxtYCC, 0, m, &cVar_ubdxtYCC_sendMessage);
}

void Heavy_pdpoly::cBinop_VKBaZlwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_giqTwb7i, 0, m, &cTabread_giqTwb7i_sendMessage);
}

void Heavy_pdpoly::cMsg_z35ArqHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_18P0hVHJ_sendMessage);
}

void Heavy_pdpoly::cBinop_jtDhMWip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VKBaZlwR, HV_BINOP_MIN, 1, m, &cBinop_VKBaZlwR_sendMessage);
}

void Heavy_pdpoly::cVar_LrgBi1hu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_HAu1LTFD, 1, m, &cTabwrite_HAu1LTFD_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_6xEJURw6, 1, m, &cTabwrite_6xEJURw6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_n86xtYd8, 1, m, &cVar_n86xtYd8_sendMessage);
}

void Heavy_pdpoly::cSlice_Mw90BSix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_gR8TJcKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7HKPJpLo_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZnNrVCjm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_BYrWVaj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l4NBqvlb, HV_BINOP_EQ, 0, m, &cBinop_l4NBqvlb_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_fp98i4vA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LWwLlFdl, 0, m, &cSlice_LWwLlFdl_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bv4VfscZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_llcmcuBv_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_LWwLlFdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_BYrWVaj3, 1, m, &cTabread_BYrWVaj3_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_BYrWVaj3, 1, m, &cTabread_BYrWVaj3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_w9faYfeJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SJiDG332_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_eRrx5OHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_uReLVofN_sendMessage);
}

void Heavy_pdpoly::cBinop_1z0xZzpe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0viNWCdX, HV_BINOP_MIN, 0, m, &cBinop_0viNWCdX_sendMessage);
}

void Heavy_pdpoly::cCast_bv4VfscZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_w9faYfeJ, 0, m, &cVar_w9faYfeJ_sendMessage);
}

void Heavy_pdpoly::cCast_llcmcuBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_1z0xZzpe_sendMessage);
}

void Heavy_pdpoly::cBinop_0viNWCdX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_BYrWVaj3, 0, m, &cTabread_BYrWVaj3_sendMessage);
}

void Heavy_pdpoly::cMsg_SJiDG332_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eRrx5OHk_sendMessage);
}

void Heavy_pdpoly::cBinop_uReLVofN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0viNWCdX, HV_BINOP_MIN, 1, m, &cBinop_0viNWCdX_sendMessage);
}

void Heavy_pdpoly::cVar_MoiEd9fD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pQFIxNMB, HV_BINOP_LESS_THAN, 1, m, &cBinop_pQFIxNMB_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_BQFY0wzi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zBkc3wos_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_zBkc3wos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3v99QoWW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5Ony2LmF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zISVXYjd_sendMessage);
}

void Heavy_pdpoly::cVar_2nR2WoW4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pQFIxNMB, HV_BINOP_LESS_THAN, 1, m, &cBinop_pQFIxNMB_sendMessage);
}

void Heavy_pdpoly::cIf_sZbbTa4W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_efkkTjHm_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ATEqZSbE_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q6DnCbVf_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fL5ixPbR, 0, m, &cSlice_fL5ixPbR_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_inb9EJmW, 0, m, &cSlice_inb9EJmW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FHLDXMjA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_HAu1LTFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_ROmJbjzj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9XxjgMt9, 0, m, &cSlice_9XxjgMt9_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_HAu1LTFD, 0, m, &cTabwrite_HAu1LTFD_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_9XxjgMt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_HAu1LTFD, 2, m, &cTabwrite_HAu1LTFD_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_HAu1LTFD, 2, m, &cTabwrite_HAu1LTFD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_6xEJURw6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_DDe9HcUl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_egArjPIg, 0, m, &cSlice_egArjPIg_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_6xEJURw6, 0, m, &cTabwrite_6xEJURw6_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_egArjPIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_6xEJURw6, 2, m, &cTabwrite_6xEJURw6_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_6xEJURw6, 2, m, &cTabwrite_6xEJURw6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_NAgeb8rw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DDe9HcUl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cVar_n86xtYd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TiYf8idP_sendMessage);
}

void Heavy_pdpoly::cSlice_fL5ixPbR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_inb9EJmW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_H7Ike5Hf, 1, m, &cPack_H7Ike5Hf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cPack_2vEu94Ky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mjTCsfkp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3GaugyQy_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Mw90BSix, 0, m, &cSlice_Mw90BSix_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_gR8TJcKQ, 0, m, &cSlice_gR8TJcKQ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_sZbbTa4W, 0, m, &cIf_sZbbTa4W_sendMessage);
}

void Heavy_pdpoly::cCast_wvcYiYpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SJkDgTlw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_aauWDaUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_61rMPCrB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_d8clmKgC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LrgBi1hu, 1, m, &cVar_LrgBi1hu_sendMessage);
}

void Heavy_pdpoly::cCast_Uhe0ObQa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fp98i4vA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_TtEz5J3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_sZbbTa4W, 1, m, &cIf_sZbbTa4W_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LrgBi1hu, 0, m, &cVar_LrgBi1hu_sendMessage);
}

void Heavy_pdpoly::cMsg_hGCbNU2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_sZbbTa4W, 1, m, &cIf_sZbbTa4W_sendMessage);
}

void Heavy_pdpoly::cCast_mjTCsfkp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MoiEd9fD, 0, m, &cVar_MoiEd9fD_sendMessage);
}

void Heavy_pdpoly::cCast_3GaugyQy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TtEz5J3q_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_ZnNrVCjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z2rv0r8w, 0, m, &cVar_Z2rv0r8w_sendMessage);
}

void Heavy_pdpoly::cCast_7HKPJpLo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l4NBqvlb, HV_BINOP_EQ, 1, m, &cBinop_l4NBqvlb_sendMessage);
}

void Heavy_pdpoly::cBinop_l4NBqvlb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KWLvVCfL, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_KWLvVCfL_sendMessage);
}

void Heavy_pdpoly::cBinop_KWLvVCfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BQFY0wzi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_Sm7jKR57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KWLvVCfL, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_KWLvVCfL_sendMessage);
}

void Heavy_pdpoly::cBinop_pQFIxNMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sm7jKR57, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_Sm7jKR57_sendMessage);
}

void Heavy_pdpoly::cCast_5Ony2LmF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hGCbNU2d_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_3v99QoWW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2nR2WoW4, 0, m, &cVar_2nR2WoW4_sendMessage);
}

void Heavy_pdpoly::cCast_zISVXYjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LrgBi1hu, 0, m, &cVar_LrgBi1hu_sendMessage);
}

void Heavy_pdpoly::cCast_EYKWtLrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2nR2WoW4, 1, m, &cVar_2nR2WoW4_sendMessage);
}

void Heavy_pdpoly::cCast_yizGfE0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pQFIxNMB, HV_BINOP_LESS_THAN, 0, m, &cBinop_pQFIxNMB_sendMessage);
}

void Heavy_pdpoly::cCast_zl3HMaBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Wf5DpmoG_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_lcUSw6QL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NAgeb8rw, 0, m, &cVar_NAgeb8rw_sendMessage);
}

void Heavy_pdpoly::cSend_Wf5DpmoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_joGY7NQC_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_efkkTjHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_onk7eU8I_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_ATEqZSbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zl3HMaBR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lcUSw6QL_sendMessage);
}

void Heavy_pdpoly::cMsg_onk7eU8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_ROmJbjzj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_q6DnCbVf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zstZhaqO_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_FHLDXMjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_n86xtYd8, 0, m, &cVar_n86xtYd8_sendMessage);
}

void Heavy_pdpoly::cMsg_zstZhaqO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_H7Ike5Hf, 2, m, &cPack_H7Ike5Hf_sendMessage);
}

void Heavy_pdpoly::cIf_zzlWGh0v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xAjouacx_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RR6PqGih_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_oznCTVn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AYEJFvGs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5FsMFpJg_sendMessage);
}

void Heavy_pdpoly::cIf_fzWd3iZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_w2vOMyaX_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JNuLebvi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_q5CQ3FzW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_fzWd3iZ3, 1, m, &cIf_fzWd3iZ3_sendMessage);
}

void Heavy_pdpoly::cVar_jZjAOfsg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_yO3xaOfk_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_2hsaSctM, 0, m, &cIf_2hsaSctM_sendMessage);
}

void Heavy_pdpoly::cUnop_FmRrIUTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_q5CQ3FzW_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_fzWd3iZ3, 0, m, &cIf_fzWd3iZ3_sendMessage);
}

void Heavy_pdpoly::cUnop_sUjZTcit_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_q5CQ3FzW_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_fzWd3iZ3, 0, m, &cIf_fzWd3iZ3_sendMessage);
}

void Heavy_pdpoly::cIf_2hsaSctM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_sUjZTcit_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_FmRrIUTf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_yO3xaOfk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2hsaSctM, 1, m, &cIf_2hsaSctM_sendMessage);
}

void Heavy_pdpoly::cCast_AYEJFvGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jtbQ1oP7, HV_BINOP_LESS_THAN, 0, m, &cBinop_jtbQ1oP7_sendMessage);
}

void Heavy_pdpoly::cCast_5FsMFpJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zzlWGh0v, 0, m, &cIf_zzlWGh0v_sendMessage);
}

void Heavy_pdpoly::cBinop_jtbQ1oP7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zzlWGh0v, 1, m, &cIf_zzlWGh0v_sendMessage);
}

void Heavy_pdpoly::cCast_w2vOMyaX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jtbQ1oP7, HV_BINOP_LESS_THAN, 1, m, &cBinop_jtbQ1oP7_sendMessage);
}

void Heavy_pdpoly::cCast_JNuLebvi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZKV4Tyep_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_3199AxnY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oznCTVn4, 0, m, &cVar_oznCTVn4_sendMessage);
}

void Heavy_pdpoly::cMsg_ZKV4Tyep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_oznCTVn4, 0, m, &cVar_oznCTVn4_sendMessage);
}

void Heavy_pdpoly::cCast_xAjouacx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_F0mBPima_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yWxj7Sds_sendMessage);
}

void Heavy_pdpoly::cCast_RR6PqGih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_3199AxnY_sendMessage);
}

void Heavy_pdpoly::cVar_t1A3WPPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jZjAOfsg, 0, m, &cVar_jZjAOfsg_sendMessage);
}

void Heavy_pdpoly::cTabwrite_s742EvvW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_AclXLYA4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jsXVsBOL, 0, m, &cSlice_jsXVsBOL_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_s742EvvW, 0, m, &cTabwrite_s742EvvW_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_jsXVsBOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_s742EvvW, 2, m, &cTabwrite_s742EvvW_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_s742EvvW, 2, m, &cTabwrite_s742EvvW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_J3vKGbic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_JQGR7ltv_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_EbvCwwa8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fICu9SAk, 0, m, &cSlice_fICu9SAk_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4BuIwBWJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UDsgADcX_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_fICu9SAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_J3vKGbic, 1, m, &cTabread_J3vKGbic_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_J3vKGbic, 1, m, &cTabread_J3vKGbic_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_6OzXFFkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pwNvyW0B_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_54e9YNNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hNtwiHGG_sendMessage);
}

void Heavy_pdpoly::cBinop_jZXCV1AW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jGawFu68, HV_BINOP_MIN, 0, m, &cBinop_jGawFu68_sendMessage);
}

void Heavy_pdpoly::cCast_4BuIwBWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6OzXFFkx, 0, m, &cVar_6OzXFFkx_sendMessage);
}

void Heavy_pdpoly::cCast_UDsgADcX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_jZXCV1AW_sendMessage);
}

void Heavy_pdpoly::cBinop_jGawFu68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_J3vKGbic, 0, m, &cTabread_J3vKGbic_sendMessage);
}

void Heavy_pdpoly::cMsg_pwNvyW0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_54e9YNNh_sendMessage);
}

void Heavy_pdpoly::cBinop_hNtwiHGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jGawFu68, HV_BINOP_MIN, 1, m, &cBinop_jGawFu68_sendMessage);
}

void Heavy_pdpoly::cIf_ROEJnS7k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CJ9SpBt3_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FsIabJLF_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7wh0JK0Q_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lllxFZFs_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JIiLj3CA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_8DhxzOMb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_H7Ike5Hf, 1, m, &cPack_H7Ike5Hf_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_GhFEi671_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_s97yHvPy, 0, m, &cSlice_s97yHvPy_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2cSduOgT_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6eA0GFcR_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_s97yHvPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_8DhxzOMb, 1, m, &cTabread_8DhxzOMb_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_8DhxzOMb, 1, m, &cTabread_8DhxzOMb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_gVKy8Uzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X6K46fJr_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_zaFzTMF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_laMy8BPz_sendMessage);
}

void Heavy_pdpoly::cBinop_SA4XoX4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mIVE4LBd, HV_BINOP_MIN, 0, m, &cBinop_mIVE4LBd_sendMessage);
}

void Heavy_pdpoly::cCast_2cSduOgT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gVKy8Uzm, 0, m, &cVar_gVKy8Uzm_sendMessage);
}

void Heavy_pdpoly::cCast_6eA0GFcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_SA4XoX4E_sendMessage);
}

void Heavy_pdpoly::cBinop_mIVE4LBd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_8DhxzOMb, 0, m, &cTabread_8DhxzOMb_sendMessage);
}

void Heavy_pdpoly::cMsg_X6K46fJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zaFzTMF7_sendMessage);
}

void Heavy_pdpoly::cBinop_laMy8BPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mIVE4LBd, HV_BINOP_MIN, 1, m, &cBinop_mIVE4LBd_sendMessage);
}

void Heavy_pdpoly::cCast_6JcKbea5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t1A3WPPl, 0, m, &cVar_t1A3WPPl_sendMessage);
}

void Heavy_pdpoly::cCast_dmrXV7hw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Vint1Fw1_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_Vint1Fw1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_Sa37yErR_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_Sa37yErR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_joGY7NQC_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_JQGR7ltv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ROEJnS7k, 1, m, &cIf_ROEJnS7k_sendMessage);
}

void Heavy_pdpoly::cCast_yWxj7Sds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ROEJnS7k, 0, m, &cIf_ROEJnS7k_sendMessage);
}

void Heavy_pdpoly::cCast_F0mBPima_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_EbvCwwa8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_L192gnx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_H7Ike5Hf, 2, m, &cPack_H7Ike5Hf_sendMessage);
}

void Heavy_pdpoly::cCast_FsIabJLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GhFEi671_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_7wh0JK0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TiYf8idP_sendMessage);
}

void Heavy_pdpoly::cCast_lllxFZFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VlXRJYNv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wa0v0sKJ_sendMessage);
}

void Heavy_pdpoly::cCast_CJ9SpBt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L192gnx4_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_JIiLj3CA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Pr4MW1o1_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_VlXRJYNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_s742EvvW, 1, m, &cTabwrite_s742EvvW_sendMessage);
}

void Heavy_pdpoly::cCast_Wa0v0sKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZgBCJsRK_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_ZgBCJsRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_AclXLYA4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSend_Pr4MW1o1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_joGY7NQC_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_hy4qjBy1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2maUbkCZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fF82hIPz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_ztpOI6cn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zV40Vih2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OFXwH39S_sendMessage);
}

void Heavy_pdpoly::cIf_YQAPv1kk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ADTeYk1P_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_C06iSnrK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_Czu0HD0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YQAPv1kk, 1, m, &cIf_YQAPv1kk_sendMessage);
}

void Heavy_pdpoly::cVar_C9RFyzdo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_xuRuGcRc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_dpHYjfjR, 0, m, &cIf_dpHYjfjR_sendMessage);
}

void Heavy_pdpoly::cUnop_zoBDJJ1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_Czu0HD0E_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_YQAPv1kk, 0, m, &cIf_YQAPv1kk_sendMessage);
}

void Heavy_pdpoly::cUnop_ohwWoX3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_Czu0HD0E_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_YQAPv1kk, 0, m, &cIf_YQAPv1kk_sendMessage);
}

void Heavy_pdpoly::cIf_dpHYjfjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_ohwWoX3R_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_zoBDJJ1H_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_xuRuGcRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dpHYjfjR, 1, m, &cIf_dpHYjfjR_sendMessage);
}

void Heavy_pdpoly::cCast_zV40Vih2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S8dmMzxr, HV_BINOP_LESS_THAN, 0, m, &cBinop_S8dmMzxr_sendMessage);
}

void Heavy_pdpoly::cCast_OFXwH39S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hy4qjBy1, 0, m, &cIf_hy4qjBy1_sendMessage);
}

void Heavy_pdpoly::cBinop_S8dmMzxr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hy4qjBy1, 1, m, &cIf_hy4qjBy1_sendMessage);
}

void Heavy_pdpoly::cCast_ADTeYk1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S8dmMzxr, HV_BINOP_LESS_THAN, 1, m, &cBinop_S8dmMzxr_sendMessage);
}

void Heavy_pdpoly::cCast_C06iSnrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hy2v72xK_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_exe6ee2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ztpOI6cn, 0, m, &cVar_ztpOI6cn_sendMessage);
}

void Heavy_pdpoly::cMsg_hy2v72xK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ztpOI6cn, 0, m, &cVar_ztpOI6cn_sendMessage);
}

void Heavy_pdpoly::cCast_2maUbkCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Bp33joQA, 1, m, &cTabwrite_Bp33joQA_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_tr6jprdh, 1, m, &cTabwrite_tr6jprdh_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_iwSJvXb3, 1, m, &cTabwrite_iwSJvXb3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6ERh8gaC_sendMessage);
}

void Heavy_pdpoly::cCast_fF82hIPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_exe6ee2I_sendMessage);
}

void Heavy_pdpoly::cVar_x2bZBxDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_C9RFyzdo, 0, m, &cVar_C9RFyzdo_sendMessage);
}

void Heavy_pdpoly::cTabwrite_iwSJvXb3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_yZ1aFHyg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SVc7E4Ds, 0, m, &cSlice_SVc7E4Ds_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_iwSJvXb3, 0, m, &cTabwrite_iwSJvXb3_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_SVc7E4Ds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_iwSJvXb3, 2, m, &cTabwrite_iwSJvXb3_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_iwSJvXb3, 2, m, &cTabwrite_iwSJvXb3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_tr6jprdh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_8sPXouvl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SbUc3StX, 0, m, &cSlice_SbUc3StX_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_tr6jprdh, 0, m, &cTabwrite_tr6jprdh_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_SbUc3StX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_tr6jprdh, 2, m, &cTabwrite_tr6jprdh_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_tr6jprdh, 2, m, &cTabwrite_tr6jprdh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_Bp33joQA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_t04ThLnY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vA7PWkfX, 0, m, &cSlice_vA7PWkfX_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Bp33joQA, 0, m, &cTabwrite_Bp33joQA_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_vA7PWkfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Bp33joQA, 2, m, &cTabwrite_Bp33joQA_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Bp33joQA, 2, m, &cTabwrite_Bp33joQA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cMsg_nlLMpytO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_t04ThLnY_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_8sPXouvl_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_yZ1aFHyg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_ZPdUMILE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VR4Wtbtw_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_nrSFanHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_x2bZBxDX, 0, m, &cVar_x2bZBxDX_sendMessage);
}

void Heavy_pdpoly::cMsg_VR4Wtbtw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_3UEw7RNf_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_3UEw7RNf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_joGY7NQC_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_6ERh8gaC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nlLMpytO_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_zN5PYH16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KR9OqCOL_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AHqzeEmm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_cpdhe8ZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zUj97Zme_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ug7AjIB7_sendMessage);
}

void Heavy_pdpoly::cIf_ooDg5y7d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vZOJ2lBi_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VDAIHmTx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_XA7bYD76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ooDg5y7d, 1, m, &cIf_ooDg5y7d_sendMessage);
}

void Heavy_pdpoly::cVar_0gKtB7k1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_SGVKh2cw_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_fuctu4SK, 0, m, &cIf_fuctu4SK_sendMessage);
}

void Heavy_pdpoly::cUnop_kqTIY7Jb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_XA7bYD76_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ooDg5y7d, 0, m, &cIf_ooDg5y7d_sendMessage);
}

void Heavy_pdpoly::cUnop_8ziAgxu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_XA7bYD76_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ooDg5y7d, 0, m, &cIf_ooDg5y7d_sendMessage);
}

void Heavy_pdpoly::cIf_fuctu4SK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_8ziAgxu9_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_kqTIY7Jb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_SGVKh2cw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_fuctu4SK, 1, m, &cIf_fuctu4SK_sendMessage);
}

void Heavy_pdpoly::cCast_zUj97Zme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NS0Dn92m, HV_BINOP_LESS_THAN, 0, m, &cBinop_NS0Dn92m_sendMessage);
}

void Heavy_pdpoly::cCast_ug7AjIB7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zN5PYH16, 0, m, &cIf_zN5PYH16_sendMessage);
}

void Heavy_pdpoly::cBinop_NS0Dn92m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zN5PYH16, 1, m, &cIf_zN5PYH16_sendMessage);
}

void Heavy_pdpoly::cCast_VDAIHmTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Hz6omdj5_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_vZOJ2lBi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NS0Dn92m, HV_BINOP_LESS_THAN, 1, m, &cBinop_NS0Dn92m_sendMessage);
}

void Heavy_pdpoly::cBinop_6cbOmzfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cpdhe8ZC, 0, m, &cVar_cpdhe8ZC_sendMessage);
}

void Heavy_pdpoly::cMsg_Hz6omdj5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_cpdhe8ZC, 0, m, &cVar_cpdhe8ZC_sendMessage);
}

void Heavy_pdpoly::cCast_KR9OqCOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TyEPwYiP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_j6NjRIJq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_z9ETyH4X_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PACL1vku_sendMessage);
}

void Heavy_pdpoly::cCast_AHqzeEmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_6cbOmzfg_sendMessage);
}

void Heavy_pdpoly::cVar_8edDaEgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0gKtB7k1, 0, m, &cVar_0gKtB7k1_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_bNrwf0ab_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mdOxsSJq_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_mdOxsSJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I2AAEU35_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rL2uCJc2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4kmdYlAe_sendMessage);
}

void Heavy_pdpoly::cVar_wvjYFKQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_F7S5nRBN_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_iqrMJoQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_Js3juUpZ_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_rvcQKJ42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0HINW6Yz_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSwitchcase_Js3juUpZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iI5VkAH9_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_iI5VkAH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7DLlpui1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zhAIHdkp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_67VcSeDz_sendMessage);
}

void Heavy_pdpoly::cVar_gKibkYmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o569gd1w, HV_BINOP_LESS_THAN, 1, m, &cBinop_o569gd1w_sendMessage);
}

void Heavy_pdpoly::cVar_67rh20Bf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g8Z6xoLR, HV_BINOP_LESS_THAN, 1, m, &cBinop_g8Z6xoLR_sendMessage);
}

void Heavy_pdpoly::cIf_h4cJRF46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_cLkXYoY0, 0, m, &cSlice_cLkXYoY0_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_CbuCtlS1, 0, m, &cSlice_CbuCtlS1_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZnzmtlCu_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cDRUrfrZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3feHY2MP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_RYLVq2Rt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PfyMPwTL_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_X5VxJnBN, 0, m, &cSlice_X5VxJnBN_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_7wVrmXng, 0, m, &cSlice_7wVrmXng_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nVRiEouT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EWjjLlET_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_voIKoV9P_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cPack_ngrzHWwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RYLVq2Rt, 0, m, &cIf_RYLVq2Rt_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_h4cJRF46, 0, m, &cIf_h4cJRF46_sendMessage);
}

void Heavy_pdpoly::cVar_uo6ghQ3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TiYf8idP_sendMessage);
}

void Heavy_pdpoly::cSlice_cLkXYoY0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_H7Ike5Hf, 2, m, &cPack_H7Ike5Hf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_CbuCtlS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_fyKtgco4_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_H7Ike5Hf, 1, m, &cPack_H7Ike5Hf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_qEaE1CT6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TiYf8idP_sendMessage);
}

void Heavy_pdpoly::cIf_3Q2Be6eu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_RYLVq2Rt, 1, m, &cIf_RYLVq2Rt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_wf4yciyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_LcLV2iSJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cVar_mTomH9ii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_LUVvEm6U_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cTabread_sSwiX7Nj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ENcumgt9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WTcBtZ5S_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_sndiIVht_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_uikpacSj, 0, m, &cSlice_uikpacSj_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oeJVgwEv_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_StCPPXlo_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_uikpacSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_sSwiX7Nj, 1, m, &cTabread_sSwiX7Nj_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_sSwiX7Nj, 1, m, &cTabread_sSwiX7Nj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_kmyV7htA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8sLP7YLJ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_LgjvcYSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_beMnRIxi_sendMessage);
}

void Heavy_pdpoly::cBinop_X0Bd7LZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yBGWHbJo, HV_BINOP_MIN, 0, m, &cBinop_yBGWHbJo_sendMessage);
}

void Heavy_pdpoly::cCast_StCPPXlo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_X0Bd7LZ3_sendMessage);
}

void Heavy_pdpoly::cCast_oeJVgwEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kmyV7htA, 0, m, &cVar_kmyV7htA_sendMessage);
}

void Heavy_pdpoly::cBinop_yBGWHbJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_sSwiX7Nj, 0, m, &cTabread_sSwiX7Nj_sendMessage);
}

void Heavy_pdpoly::cMsg_8sLP7YLJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LgjvcYSe_sendMessage);
}

void Heavy_pdpoly::cBinop_beMnRIxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yBGWHbJo, HV_BINOP_MIN, 1, m, &cBinop_yBGWHbJo_sendMessage);
}

void Heavy_pdpoly::cTabread_X2pnH3XL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_h2Va5kri_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dQ8LUNcU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8nuiCK86_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_mjWiNR37_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_dyMeu2E9, 0, m, &cSlice_dyMeu2E9_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cIJTN3vy_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3EuISBd3_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_dyMeu2E9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_X2pnH3XL, 1, m, &cTabread_X2pnH3XL_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_X2pnH3XL, 1, m, &cTabread_X2pnH3XL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_3v9ZKqeS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BkfMP6iJ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_Bspbd0cW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_GILfeQYb_sendMessage);
}

void Heavy_pdpoly::cBinop_kimUyGnv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ftcvamSX, HV_BINOP_MIN, 0, m, &cBinop_ftcvamSX_sendMessage);
}

void Heavy_pdpoly::cCast_3EuISBd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kimUyGnv_sendMessage);
}

void Heavy_pdpoly::cCast_cIJTN3vy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3v9ZKqeS, 0, m, &cVar_3v9ZKqeS_sendMessage);
}

void Heavy_pdpoly::cBinop_ftcvamSX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_X2pnH3XL, 0, m, &cTabread_X2pnH3XL_sendMessage);
}

void Heavy_pdpoly::cMsg_BkfMP6iJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Bspbd0cW_sendMessage);
}

void Heavy_pdpoly::cBinop_GILfeQYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ftcvamSX, HV_BINOP_MIN, 1, m, &cBinop_ftcvamSX_sendMessage);
}

void Heavy_pdpoly::cTabwrite_9gyq1uoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_Dksvu1it_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zAWUOGDG, 0, m, &cSlice_zAWUOGDG_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_9gyq1uoG, 0, m, &cTabwrite_9gyq1uoG_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_zAWUOGDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_9gyq1uoG, 2, m, &cTabwrite_9gyq1uoG_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_9gyq1uoG, 2, m, &cTabwrite_9gyq1uoG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_yPjwMjra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_H7Ike5Hf, 1, m, &cPack_H7Ike5Hf_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_LcLV2iSJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_sO0fymMm, 0, m, &cSlice_sO0fymMm_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cKytoO9H_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lerUZPaN_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_sO0fymMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_yPjwMjra, 1, m, &cTabread_yPjwMjra_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_yPjwMjra, 1, m, &cTabread_yPjwMjra_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_xeE6z1qI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aKFQ3WBk_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_jxySMLpU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nvmI5IjX_sendMessage);
}

void Heavy_pdpoly::cBinop_dktPpD6P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4ifpXarn, HV_BINOP_MIN, 0, m, &cBinop_4ifpXarn_sendMessage);
}

void Heavy_pdpoly::cCast_lerUZPaN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_dktPpD6P_sendMessage);
}

void Heavy_pdpoly::cCast_cKytoO9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xeE6z1qI, 0, m, &cVar_xeE6z1qI_sendMessage);
}

void Heavy_pdpoly::cBinop_4ifpXarn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_yPjwMjra, 0, m, &cTabread_yPjwMjra_sendMessage);
}

void Heavy_pdpoly::cMsg_aKFQ3WBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jxySMLpU_sendMessage);
}

void Heavy_pdpoly::cBinop_nvmI5IjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4ifpXarn, HV_BINOP_MIN, 1, m, &cBinop_4ifpXarn_sendMessage);
}

void Heavy_pdpoly::cTabwrite_G0nXVqmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_fyKtgco4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_nJvvO9cB, 0, m, &cSlice_nJvvO9cB_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_G0nXVqmg, 0, m, &cTabwrite_G0nXVqmg_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_nJvvO9cB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_G0nXVqmg, 2, m, &cTabwrite_G0nXVqmg_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_G0nXVqmg, 2, m, &cTabwrite_G0nXVqmg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_AVF98KHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_1obdozah_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_IVV0Tkap, 0, m, &cSlice_IVV0Tkap_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_AVF98KHV, 0, m, &cTabwrite_AVF98KHV_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_IVV0Tkap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_AVF98KHV, 2, m, &cTabwrite_AVF98KHV_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_AVF98KHV, 2, m, &cTabwrite_AVF98KHV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_l6jky5CB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_LUVvEm6U_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UXiIJI5B, 0, m, &cSlice_UXiIJI5B_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_l6jky5CB, 0, m, &cTabwrite_l6jky5CB_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_UXiIJI5B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_l6jky5CB, 2, m, &cTabwrite_l6jky5CB_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_l6jky5CB, 2, m, &cTabwrite_l6jky5CB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_0JmFPnsb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_pQwVmlao_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_NghvaPY9, 0, m, &cSlice_NghvaPY9_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_0JmFPnsb, 0, m, &cTabwrite_0JmFPnsb_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_NghvaPY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_0JmFPnsb, 2, m, &cTabwrite_0JmFPnsb_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_0JmFPnsb, 2, m, &cTabwrite_0JmFPnsb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_6JGlNCru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pQwVmlao_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cTabwrite_6svlClAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_NKcaqFh8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BdnyTuzX, 0, m, &cSlice_BdnyTuzX_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_6svlClAy, 0, m, &cTabwrite_6svlClAy_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_BdnyTuzX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_6svlClAy, 2, m, &cTabwrite_6svlClAy_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_6svlClAy, 2, m, &cTabwrite_6svlClAy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_eBaZ8Ttb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_a2zReDM2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_veOCL0NB_sendMessage);
}

void Heavy_pdpoly::cSlice_X5VxJnBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_H7Ike5Hf, 2, m, &cPack_H7Ike5Hf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_7wVrmXng_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_Dksvu1it_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_H7Ike5Hf, 1, m, &cPack_H7Ike5Hf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_BfSASXRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7xPKHvEg, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_7xPKHvEg_sendMessage);
}

void Heavy_pdpoly::cBinop_R8WMbiTP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WEcENqEm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bSpiIkXU_sendMessage);
}

void Heavy_pdpoly::cBinop_o569gd1w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o8Po9J2G, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_o8Po9J2G_sendMessage);
}

void Heavy_pdpoly::cCast_PACL1vku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cCast_j6NjRIJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mjWiNR37_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_TyEPwYiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wvjYFKQQ, 1, m, &cVar_wvjYFKQQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rvcQKJ42, 1, m, &cVar_rvcQKJ42_sendMessage);
}

void Heavy_pdpoly::cCast_z9ETyH4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sndiIVht_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSend_F7S5nRBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Aiw3Bh8g_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_ENcumgt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R8WMbiTP, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_R8WMbiTP_sendMessage);
}

void Heavy_pdpoly::cCast_WTcBtZ5S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_DYOw4Z9w_sendMessage);
}

void Heavy_pdpoly::cBinop_o8Po9J2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iqrMJoQS, 0, m, &cIf_iqrMJoQS_sendMessage);
}

void Heavy_pdpoly::cBinop_DYOw4Z9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o8Po9J2G, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_o8Po9J2G_sendMessage);
}

void Heavy_pdpoly::cCast_WEcENqEm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bNrwf0ab_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_bSpiIkXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_D4gLLKb5_sendMessage);
}

void Heavy_pdpoly::cBinop_D4gLLKb5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iqrMJoQS, 1, m, &cIf_iqrMJoQS_sendMessage);
}

void Heavy_pdpoly::cSend_0HINW6Yz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9wiOdh1P_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_LFSdAeyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Aiw3Bh8g_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_K6FRzWj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9wiOdh1P_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_NuS6jMWt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eBaZ8Ttb, 0, m, &cVar_eBaZ8Ttb_sendMessage);
}

void Heavy_pdpoly::cCast_5jEp7KiE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8edDaEgb, 0, m, &cVar_8edDaEgb_sendMessage);
}

void Heavy_pdpoly::cCast_yrfyxWEG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FIA9kpfw_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_g8Z6xoLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R8WMbiTP, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_R8WMbiTP_sendMessage);
}

void Heavy_pdpoly::cCast_dQ8LUNcU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g8Z6xoLR, HV_BINOP_LESS_THAN, 0, m, &cBinop_g8Z6xoLR_sendMessage);
}

void Heavy_pdpoly::cCast_8nuiCK86_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o569gd1w, HV_BINOP_LESS_THAN, 0, m, &cBinop_o569gd1w_sendMessage);
}

void Heavy_pdpoly::cCast_h2Va5kri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gKibkYmw, 1, m, &cVar_gKibkYmw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_67rh20Bf, 1, m, &cVar_67rh20Bf_sendMessage);
}

void Heavy_pdpoly::cCast_a2zReDM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_67rh20Bf, 0, m, &cVar_67rh20Bf_sendMessage);
}

void Heavy_pdpoly::cCast_veOCL0NB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gKibkYmw, 0, m, &cVar_gKibkYmw_sendMessage);
}

void Heavy_pdpoly::cSend_jaFXeQlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hzTJd0wA_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_67VcSeDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rvcQKJ42, 0, m, &cVar_rvcQKJ42_sendMessage);
}

void Heavy_pdpoly::cCast_7DLlpui1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gKibkYmw, 0, m, &cVar_gKibkYmw_sendMessage);
}

void Heavy_pdpoly::cCast_zhAIHdkp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RwseoBCe_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_RwseoBCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_jaFXeQlS_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_Ko4vJVhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_195AlBEC_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_195AlBEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_O53SSTpX_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_rL2uCJc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ko4vJVhH_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_I2AAEU35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_67rh20Bf, 0, m, &cVar_67rh20Bf_sendMessage);
}

void Heavy_pdpoly::cCast_4kmdYlAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wvjYFKQQ, 0, m, &cVar_wvjYFKQQ_sendMessage);
}

void Heavy_pdpoly::cMsg_FIA9kpfw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_K6FRzWj2_sendMessage(_c, 0, m);
  cSend_LFSdAeyw_sendMessage(_c, 0, m);
  cSend_bSRcDJqy_sendMessage(_c, 0, m);
  cSend_QRdz0KeL_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_bSRcDJqy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_O53SSTpX_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_QRdz0KeL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_hzTJd0wA_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_7vPHFDV9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_h4cJRF46, 1, m, &cIf_h4cJRF46_sendMessage);
}

void Heavy_pdpoly::cCast_kTTqdaYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_hyiTe0sS_sendMessage);
}

void Heavy_pdpoly::cBinop_7xPKHvEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3Q2Be6eu, 0, m, &cIf_3Q2Be6eu_sendMessage);
}

void Heavy_pdpoly::cBinop_hyiTe0sS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BfSASXRQ, 0, m, &cVar_BfSASXRQ_sendMessage);
}

void Heavy_pdpoly::cMsg_YUm0JzGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_1obdozah_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_ekbWVbxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_NKcaqFh8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_coRto3GB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HgYcHOgg_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_GDU1ECpS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qEaE1CT6, 0, m, &cVar_qEaE1CT6_sendMessage);
}

void Heavy_pdpoly::cCast_cJnDl8Uu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wf4yciyL, 0, m, &cVar_wf4yciyL_sendMessage);
}

void Heavy_pdpoly::cMsg_HgYcHOgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_H7Ike5Hf, 2, m, &cPack_H7Ike5Hf_sendMessage);
}

void Heavy_pdpoly::cCast_cDRUrfrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YUm0JzGV_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_ZnzmtlCu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uo6ghQ3Q, 0, m, &cVar_uo6ghQ3Q_sendMessage);
}

void Heavy_pdpoly::cCast_3feHY2MP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6OxRI3W8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J5VOWdHg_sendMessage);
}

void Heavy_pdpoly::cCast_J5VOWdHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mTomH9ii, 0, m, &cVar_mTomH9ii_sendMessage);
}

void Heavy_pdpoly::cCast_6OxRI3W8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_AHXdg2lw_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_AHXdg2lw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_joGY7NQC_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_yBI9fYnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6JGlNCru, 0, m, &cVar_6JGlNCru_sendMessage);
}

void Heavy_pdpoly::cCast_T35JOzhC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_GQhqyCiJ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_GQhqyCiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_joGY7NQC_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_PfyMPwTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_coRto3GB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cJnDl8Uu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GDU1ECpS_sendMessage);
}

void Heavy_pdpoly::cCast_EWjjLlET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ekbWVbxI_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_voIKoV9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T35JOzhC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yBI9fYnp_sendMessage);
}

void Heavy_pdpoly::cCast_nVRiEouT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qEaE1CT6, 0, m, &cVar_qEaE1CT6_sendMessage);
}

void Heavy_pdpoly::cCast_tOBKahcT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7xPKHvEg, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_7xPKHvEg_sendMessage);
}

void Heavy_pdpoly::cCast_TavoNRSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BfSASXRQ, 0, m, &cVar_BfSASXRQ_sendMessage);
}

void Heavy_pdpoly::cSend_FeaSHZ5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_TbaGHDcz_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_h3D9Z5vV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_16omqKib, 1, m, &cVar_16omqKib_sendMessage);
}

void Heavy_pdpoly::cSend_eGcoeAeF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_weNI5WmG_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_TiYf8idP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_H7Ike5Hf, 0, m, &cPack_H7Ike5Hf_sendMessage);
}

void Heavy_pdpoly::cBinop_ZPylfuwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_h3D9Z5vV_sendMessage);
  cSend_eGcoeAeF_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::hTable_UiQjL6BL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::hTable_UVzMnHcd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::hTable_ILTVyuDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cCast_GNtRgcrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AJ8R6Ur5, 0, m, &cVar_AJ8R6Ur5_sendMessage);
}

void Heavy_pdpoly::cCast_gkyTOqnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rNxzlWiQ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_8A9XhUg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_F3CosXnX_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_rNxzlWiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 65535.0f);
  cSend_8A9XhUg7_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_B3UiFze4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vugbmLQS, 1, m, &cIf_vugbmLQS_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_NQqiGA6G_sendMessage);
}

void Heavy_pdpoly::cBinop_NQqiGA6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4NLqrAB1, 1, m, &cIf_4NLqrAB1_sendMessage);
}

void Heavy_pdpoly::cBinop_5MzHk9H8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_FeaSHZ5X_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cPack_H7Ike5Hf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5QRqIOYM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSwitchcase_5QRqIOYM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_CHPPg4KV, 0, m, &cSlice_CHPPg4KV_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5yJR9VoD, 0, m, &cSlice_5yJR9VoD_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_w0UxxNkk, 0, m, &cSlice_w0UxxNkk_sendMessage);
      break;
    }
    case 0x40800000: { // "4.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_NEIWRten, 0, m, &cSlice_NEIWRten_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_CHPPg4KV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_C0DX7M2y, 0, m, &cSlice_C0DX7M2y_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_S7FY0Tm8, 0, m, &cSlice_S7FY0Tm8_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_C0DX7M2y, 0, m, &cSlice_C0DX7M2y_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_S7FY0Tm8, 0, m, &cSlice_S7FY0Tm8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_5yJR9VoD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_bOx8pVic, 0, m, &cSlice_bOx8pVic_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fhWAquQz, 0, m, &cSlice_fhWAquQz_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_bOx8pVic, 0, m, &cSlice_bOx8pVic_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fhWAquQz, 0, m, &cSlice_fhWAquQz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_w0UxxNkk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_7UxooZCW, 0, m, &cSlice_7UxooZCW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Cf0KELKj, 0, m, &cSlice_Cf0KELKj_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_7UxooZCW, 0, m, &cSlice_7UxooZCW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Cf0KELKj, 0, m, &cSlice_Cf0KELKj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_NEIWRten_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_JAclRJwH, 0, m, &cSlice_JAclRJwH_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_wELPeCDZ, 0, m, &cSlice_wELPeCDZ_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_JAclRJwH, 0, m, &cSlice_JAclRJwH_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_wELPeCDZ, 0, m, &cSlice_wELPeCDZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_C0DX7M2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_SaVZIdYm_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_S7FY0Tm8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_jkVxzksa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_5uAIld6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_vyZIbQlk, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_LIjsEzjK_sendMessage);
}

void Heavy_pdpoly::cBinop_jkVxzksa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_vrNmZGv7_sendMessage);
}

void Heavy_pdpoly::cBinop_vrNmZGv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EK5kSOti, HV_BINOP_POW, 1, m, &cBinop_EK5kSOti_sendMessage);
  cMsg_bjxf6YQP_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_EK5kSOti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_5uAIld6l_sendMessage);
}

void Heavy_pdpoly::cMsg_bjxf6YQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EK5kSOti, HV_BINOP_POW, 0, m, &cBinop_EK5kSOti_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_SaVZIdYm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eytob7gx_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_o9DkyqOD_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_eytob7gx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hI1PrQIS_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_4lgoA68E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NQgGnol4, HV_BINOP_MULTIPLY, 0, m, &cBinop_NQgGnol4_sendMessage);
}

void Heavy_pdpoly::cMsg_xN4sXr9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9aF42lY9_sendMessage);
}

void Heavy_pdpoly::cSystem_9aF42lY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JNnrqwj0_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_NQgGnol4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_iDROFwbR_sendMessage);
}

void Heavy_pdpoly::cBinop_zTUURIIF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NQgGnol4, HV_BINOP_MULTIPLY, 1, m, &cBinop_NQgGnol4_sendMessage);
}

void Heavy_pdpoly::cMsg_JNnrqwj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zTUURIIF_sendMessage);
}

void Heavy_pdpoly::cBinop_iDROFwbR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_jMeN6mgl_sendMessage);
}

void Heavy_pdpoly::cBinop_jMeN6mgl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_KrQWzWJh_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_RVOnR7Ce, m);
}

void Heavy_pdpoly::cBinop_KrQWzWJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KpTq09U6, m);
}

void Heavy_pdpoly::cVar_JuF1I4no_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bWOQBgQd, HV_BINOP_MULTIPLY, 0, m, &cBinop_bWOQBgQd_sendMessage);
}

void Heavy_pdpoly::cMsg_1gGXUnun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nLNfkrbR_sendMessage);
}

void Heavy_pdpoly::cSystem_nLNfkrbR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TqwQrs6k_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_bWOQBgQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_qJ1hjWvB_sendMessage);
}

void Heavy_pdpoly::cBinop_yjzge3kx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bWOQBgQd, HV_BINOP_MULTIPLY, 1, m, &cBinop_bWOQBgQd_sendMessage);
}

void Heavy_pdpoly::cMsg_TqwQrs6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_yjzge3kx_sendMessage);
}

void Heavy_pdpoly::cBinop_qJ1hjWvB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_c4UwHA9P_sendMessage);
}

void Heavy_pdpoly::cBinop_c4UwHA9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_dzb3gf6E_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7mNFNAmQ, m);
}

void Heavy_pdpoly::cBinop_dzb3gf6E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_E6NJLhOC, m);
}

void Heavy_pdpoly::cMsg_hI1PrQIS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fR5CwoDS, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_o9DkyqOD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HCee2m7l_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_HCee2m7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fR5CwoDS, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_LIjsEzjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_WYrgTCjQ, 0, m);
}

void Heavy_pdpoly::cSlice_bOx8pVic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_PFDWwCAW_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_fhWAquQz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_4wq2aiKI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_O4tNnUyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_MQzdNxNy, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_3klEenG5_sendMessage);
}

void Heavy_pdpoly::cBinop_4wq2aiKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_xiSmiPch_sendMessage);
}

void Heavy_pdpoly::cBinop_xiSmiPch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_75xRWXbQ, HV_BINOP_POW, 1, m, &cBinop_75xRWXbQ_sendMessage);
  cMsg_WD1k9Igm_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_75xRWXbQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_O4tNnUyy_sendMessage);
}

void Heavy_pdpoly::cMsg_WD1k9Igm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_75xRWXbQ, HV_BINOP_POW, 0, m, &cBinop_75xRWXbQ_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_PFDWwCAW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xrN9PLfe_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_putUjDUE_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_xrN9PLfe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FhX25aoF_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_iBDGtMYd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KqqqczIQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_KqqqczIQ_sendMessage);
}

void Heavy_pdpoly::cMsg_x0gAPSew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VXP4W8QF_sendMessage);
}

void Heavy_pdpoly::cSystem_VXP4W8QF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BwvaADEF_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_KqqqczIQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_9PHpH4zs_sendMessage);
}

void Heavy_pdpoly::cBinop_uoZSKXcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KqqqczIQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_KqqqczIQ_sendMessage);
}

void Heavy_pdpoly::cMsg_BwvaADEF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_uoZSKXcA_sendMessage);
}

void Heavy_pdpoly::cBinop_9PHpH4zs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_JdURDanO_sendMessage);
}

void Heavy_pdpoly::cBinop_JdURDanO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_f5WcAx1Q_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NsJwtfMl, m);
}

void Heavy_pdpoly::cBinop_f5WcAx1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QTk0OC5c, m);
}

void Heavy_pdpoly::cVar_StpUpoZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AU5SxJbw, HV_BINOP_MULTIPLY, 0, m, &cBinop_AU5SxJbw_sendMessage);
}

void Heavy_pdpoly::cMsg_1NEwEubU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qw79gHiT_sendMessage);
}

void Heavy_pdpoly::cSystem_qw79gHiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QPyGohpr_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_AU5SxJbw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_43GXlbU5_sendMessage);
}

void Heavy_pdpoly::cBinop_nrEeWfBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AU5SxJbw, HV_BINOP_MULTIPLY, 1, m, &cBinop_AU5SxJbw_sendMessage);
}

void Heavy_pdpoly::cMsg_QPyGohpr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_nrEeWfBT_sendMessage);
}

void Heavy_pdpoly::cBinop_43GXlbU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_7Aq7VD3u_sendMessage);
}

void Heavy_pdpoly::cBinop_7Aq7VD3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ox0fh3Ns_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mOIKXYD9, m);
}

void Heavy_pdpoly::cBinop_ox0fh3Ns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QPyUY6aK, m);
}

void Heavy_pdpoly::cMsg_FhX25aoF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_k8rBaXbn, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_putUjDUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1PN0f0uQ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_1PN0f0uQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_k8rBaXbn, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_3klEenG5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_cgADDeVM, 0, m);
}

void Heavy_pdpoly::cSlice_7UxooZCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_gpxxrzEc_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_Cf0KELKj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_mD5RXBuI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_Na2WBk16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_TxzGZY9c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_Dw6i7prc_sendMessage);
}

void Heavy_pdpoly::cBinop_mD5RXBuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_60kMcLiF_sendMessage);
}

void Heavy_pdpoly::cBinop_60kMcLiF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VCccQzGO, HV_BINOP_POW, 1, m, &cBinop_VCccQzGO_sendMessage);
  cMsg_dxOyuopE_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_VCccQzGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Na2WBk16_sendMessage);
}

void Heavy_pdpoly::cMsg_dxOyuopE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VCccQzGO, HV_BINOP_POW, 0, m, &cBinop_VCccQzGO_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_gpxxrzEc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rWQ07S3x_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_jpZ5y2OR_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_rWQ07S3x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AFz8nuT5_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_VI93BZkW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AvLrtITS, HV_BINOP_MULTIPLY, 0, m, &cBinop_AvLrtITS_sendMessage);
}

void Heavy_pdpoly::cMsg_q7aJ3bfu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3sVDzrwU_sendMessage);
}

void Heavy_pdpoly::cSystem_3sVDzrwU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c7cxDJzw_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_AvLrtITS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_yF4RB2sF_sendMessage);
}

void Heavy_pdpoly::cBinop_BVu8gOzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AvLrtITS, HV_BINOP_MULTIPLY, 1, m, &cBinop_AvLrtITS_sendMessage);
}

void Heavy_pdpoly::cMsg_c7cxDJzw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_BVu8gOzf_sendMessage);
}

void Heavy_pdpoly::cBinop_yF4RB2sF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Sl3evAcf_sendMessage);
}

void Heavy_pdpoly::cBinop_Sl3evAcf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_RdJchvLJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_iLFkkQs6, m);
}

void Heavy_pdpoly::cBinop_RdJchvLJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Z7uCXwdz, m);
}

void Heavy_pdpoly::cVar_GmXRaqwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M8Vv71Zh, HV_BINOP_MULTIPLY, 0, m, &cBinop_M8Vv71Zh_sendMessage);
}

void Heavy_pdpoly::cMsg_43NDRa2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2FUcDRS8_sendMessage);
}

void Heavy_pdpoly::cSystem_2FUcDRS8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1n0sHc8l_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_M8Vv71Zh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_FAeIcrYp_sendMessage);
}

void Heavy_pdpoly::cBinop_J9N6NyvE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M8Vv71Zh, HV_BINOP_MULTIPLY, 1, m, &cBinop_M8Vv71Zh_sendMessage);
}

void Heavy_pdpoly::cMsg_1n0sHc8l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_J9N6NyvE_sendMessage);
}

void Heavy_pdpoly::cBinop_FAeIcrYp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OSdM34yI_sendMessage);
}

void Heavy_pdpoly::cBinop_OSdM34yI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_AGjlDcWB_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_tsdAAmaL, m);
}

void Heavy_pdpoly::cBinop_AGjlDcWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HGxtndEL, m);
}

void Heavy_pdpoly::cMsg_AFz8nuT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_jYMNuwLX, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_jpZ5y2OR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_U2KLEmwK_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_U2KLEmwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_jYMNuwLX, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_Dw6i7prc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ZBnX5GiY, 0, m);
}

void Heavy_pdpoly::cSlice_JAclRJwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_4QPnD96u_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_wELPeCDZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_t9kxxJky_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_KOSJeDfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Mo05cnpf, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_25hwtArs_sendMessage);
}

void Heavy_pdpoly::cBinop_t9kxxJky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_7mXbvMH3_sendMessage);
}

void Heavy_pdpoly::cBinop_7mXbvMH3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mube7JYJ, HV_BINOP_POW, 1, m, &cBinop_Mube7JYJ_sendMessage);
  cMsg_bXx1kHcp_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_Mube7JYJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_KOSJeDfA_sendMessage);
}

void Heavy_pdpoly::cMsg_bXx1kHcp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mube7JYJ, HV_BINOP_POW, 0, m, &cBinop_Mube7JYJ_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_4QPnD96u_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EeHLzAAz_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_yZtxOkcM_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_EeHLzAAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_phRU3CGY_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_m3zEabfB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V1WQCbrD, HV_BINOP_MULTIPLY, 0, m, &cBinop_V1WQCbrD_sendMessage);
}

void Heavy_pdpoly::cMsg_5rJZXMBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8g1zjQ4Y_sendMessage);
}

void Heavy_pdpoly::cSystem_8g1zjQ4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IJ9QcBzx_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_V1WQCbrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_SxOo0vQ0_sendMessage);
}

void Heavy_pdpoly::cBinop_S2HFOt2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V1WQCbrD, HV_BINOP_MULTIPLY, 1, m, &cBinop_V1WQCbrD_sendMessage);
}

void Heavy_pdpoly::cMsg_IJ9QcBzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_S2HFOt2U_sendMessage);
}

void Heavy_pdpoly::cBinop_SxOo0vQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_WJp862Vn_sendMessage);
}

void Heavy_pdpoly::cBinop_WJp862Vn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mILXX4vz_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3gYwbVLh, m);
}

void Heavy_pdpoly::cBinop_mILXX4vz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hreMP8Pc, m);
}

void Heavy_pdpoly::cVar_aIaKahr6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DATPsdwr, HV_BINOP_MULTIPLY, 0, m, &cBinop_DATPsdwr_sendMessage);
}

void Heavy_pdpoly::cMsg_FQD7fGZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KLbwYujK_sendMessage);
}

void Heavy_pdpoly::cSystem_KLbwYujK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uGInp9HV_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_DATPsdwr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_E3xPbkcQ_sendMessage);
}

void Heavy_pdpoly::cBinop_cHgWSrJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DATPsdwr, HV_BINOP_MULTIPLY, 1, m, &cBinop_DATPsdwr_sendMessage);
}

void Heavy_pdpoly::cMsg_uGInp9HV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_cHgWSrJX_sendMessage);
}

void Heavy_pdpoly::cBinop_E3xPbkcQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_rh3dUFkx_sendMessage);
}

void Heavy_pdpoly::cBinop_rh3dUFkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_BH0miHZM_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cYRdYRj7, m);
}

void Heavy_pdpoly::cBinop_BH0miHZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Pkwo2Df2, m);
}

void Heavy_pdpoly::cMsg_phRU3CGY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_YYlSodFP, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_yZtxOkcM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_D0tiUMBR_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_D0tiUMBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_YYlSodFP, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_25hwtArs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_nfXm5ZSi, 0, m);
}

void Heavy_pdpoly::cSend_IvxyZoTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ira3726J_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cReceive_z1jAlaNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xN4sXr9N_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4lgoA68E, 0, m, &cVar_4lgoA68E_sendMessage);
  cMsg_1gGXUnun_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JuF1I4no, 0, m, &cVar_JuF1I4no_sendMessage);
  cMsg_x0gAPSew_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iBDGtMYd, 0, m, &cVar_iBDGtMYd_sendMessage);
  cMsg_1NEwEubU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_StpUpoZR, 0, m, &cVar_StpUpoZR_sendMessage);
  cMsg_q7aJ3bfu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VI93BZkW, 0, m, &cVar_VI93BZkW_sendMessage);
  cMsg_43NDRa2d_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GmXRaqwm, 0, m, &cVar_GmXRaqwm_sendMessage);
  cMsg_5rJZXMBG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_m3zEabfB, 0, m, &cVar_m3zEabfB_sendMessage);
  cMsg_FQD7fGZ9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aIaKahr6, 0, m, &cVar_aIaKahr6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lsVZNUsl, 0, m, &cVar_lsVZNUsl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gkyTOqnk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GNtRgcrD_sendMessage);
}

void Heavy_pdpoly::cReceive_0X2lQlB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_vJM85at6, 0, m, &cSlice_vJM85at6_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_8yH8sMUs, 0, m, &cSlice_8yH8sMUs_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SIHu9SRW, 0, m, &cSlice_SIHu9SRW_sendMessage);
}

void Heavy_pdpoly::cReceive_TbaGHDcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3Q2Be6eu, 1, m, &cIf_3Q2Be6eu_sendMessage);
}

void Heavy_pdpoly::cReceive_weNI5WmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NAgeb8rw, 1, m, &cVar_NAgeb8rw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mTomH9ii, 1, m, &cVar_mTomH9ii_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6JGlNCru, 1, m, &cVar_6JGlNCru_sendMessage);
}

void Heavy_pdpoly::cReceive_joGY7NQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_16omqKib, 0, m, &cVar_16omqKib_sendMessage);
}

void Heavy_pdpoly::cReceive_F3CosXnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MoiEd9fD, 1, m, &cVar_MoiEd9fD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eBaZ8Ttb, 1, m, &cVar_eBaZ8Ttb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZPylfuwm, HV_BINOP_MOD_UNIPOLAR, 1, m, &cBinop_ZPylfuwm_sendMessage);
}

void Heavy_pdpoly::cReceive_Aiw3Bh8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_9gyq1uoG, 1, m, &cTabwrite_9gyq1uoG_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_6svlClAy, 1, m, &cTabwrite_6svlClAy_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_0JmFPnsb, 1, m, &cTabwrite_0JmFPnsb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qEaE1CT6, 1, m, &cVar_qEaE1CT6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wf4yciyL, 1, m, &cVar_wf4yciyL_sendMessage);
}

void Heavy_pdpoly::cReceive_9wiOdh1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uo6ghQ3Q, 1, m, &cVar_uo6ghQ3Q_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_l6jky5CB, 1, m, &cTabwrite_l6jky5CB_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_G0nXVqmg, 1, m, &cTabwrite_G0nXVqmg_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_AVF98KHV, 1, m, &cTabwrite_AVF98KHV_sendMessage);
}

void Heavy_pdpoly::cReceive_hzTJd0wA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kTTqdaYl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7vPHFDV9_sendMessage);
}

void Heavy_pdpoly::cReceive_O53SSTpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tOBKahcT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TavoNRSI_sendMessage);
}

void Heavy_pdpoly::cReceive_Ira3726J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4lgoA68E, 0, m, &cVar_4lgoA68E_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JuF1I4no, 0, m, &cVar_JuF1I4no_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iBDGtMYd, 0, m, &cVar_iBDGtMYd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_StpUpoZR, 0, m, &cVar_StpUpoZR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VI93BZkW, 0, m, &cVar_VI93BZkW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GmXRaqwm, 0, m, &cVar_GmXRaqwm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_m3zEabfB, 0, m, &cVar_m3zEabfB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aIaKahr6, 0, m, &cVar_aIaKahr6_sendMessage);
}

void Heavy_pdpoly::cReceive_cInKZtXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IvxyZoTf_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cReceive_l8C3ThDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7ksqJUyc, m);
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

int Heavy_pdpoly::process(float **inputBuffers, float **outputBuffers, int n) {
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3;

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
    __hv_phasor_k_f(&sPhasor_vyZIbQlk, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_WYrgTCjQ, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_RVOnR7Ce, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_KpTq09U6, VOf(Bf2));
    __hv_rpole_f(&sRPole_ySZZ6RiE, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_7mNFNAmQ, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_E6NJLhOC, VOf(Bf2));
    __hv_rpole_f(&sRPole_lM2eE5uE, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_fR5CwoDS, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_MQzdNxNy, VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_cgADDeVM, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_NsJwtfMl, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_QTk0OC5c, VOf(Bf3));
    __hv_rpole_f(&sRPole_5SxbcECz, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_mOIKXYD9, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_QPyUY6aK, VOf(Bf3));
    __hv_rpole_f(&sRPole_Gg1A5QgW, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_k8rBaXbn, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_TxzGZY9c, VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_ZBnX5GiY, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_iLFkkQs6, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_Z7uCXwdz, VOf(Bf2));
    __hv_rpole_f(&sRPole_Bpt6Jydq, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_tsdAAmaL, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_HGxtndEL, VOf(Bf2));
    __hv_rpole_f(&sRPole_O5KIdSkr, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_jYMNuwLX, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_Mo05cnpf, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_nfXm5ZSi, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_3gYwbVLh, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_hreMP8Pc, VOf(Bf1));
    __hv_rpole_f(&sRPole_C8IMQzMY, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_cYRdYRj7, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Pkwo2Df2, VOf(Bf1));
    __hv_rpole_f(&sRPole_kyG2EgI5, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_YYlSodFP, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_7ksqJUyc, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_pdpoly::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_pdpoly::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
