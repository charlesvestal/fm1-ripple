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
  numBytes += sPhasor_k_init(&sPhasor_SqW7AWbe, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_4nNw5nL4, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_R2OM5WNn);
  numBytes += sRPole_init(&sRPole_KSQtbukE);
  numBytes += sLine_init(&sLine_8P6th3i4);
  numBytes += sPhasor_k_init(&sPhasor_BbjCdVmN, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_1IXgKU4O, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_7pJPPfd5);
  numBytes += sRPole_init(&sRPole_y3UeZY7o);
  numBytes += sLine_init(&sLine_1aUhAbNv);
  numBytes += sPhasor_k_init(&sPhasor_vfX8Y5HI, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_sWC0CnU2, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_lgzfhJOC);
  numBytes += sRPole_init(&sRPole_fEw2tIme);
  numBytes += sLine_init(&sLine_ZFQzbsA8);
  numBytes += sPhasor_k_init(&sPhasor_YyW6q9Ry, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_VNV5obt5, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_NuNVYY8F);
  numBytes += sRPole_init(&sRPole_6TgGXVLb);
  numBytes += sLine_init(&sLine_em2G9Mmf);
  numBytes += cSlice_init(&cSlice_xMqtCnnD, 2, 1);
  numBytes += cSlice_init(&cSlice_YjsgJzol, 1, 1);
  numBytes += cSlice_init(&cSlice_Y54Vv5DU, 0, 1);
  numBytes += cVar_init_f(&cVar_T5BxLOeY, 0.0f);
  numBytes += cIf_init(&cIf_bVAGs5So, false);
  numBytes += cIf_init(&cIf_T6gyJ8zh, false);
  numBytes += cIf_init(&cIf_O8kZvCam, false);
  numBytes += cIf_init(&cIf_joRMIxY9, false);
  numBytes += cIf_init(&cIf_FFACCA0Q, false);
  numBytes += cBinop_init(&cBinop_KnnSabpw, 0.0f); // __eq
  numBytes += cVar_init_f(&cVar_hy9tgdWD, 1.0f);
  numBytes += cVar_init_f(&cVar_e8JTaShc, 0.0f);
  numBytes += cSlice_init(&cSlice_GJRSFEIZ, 1, -1);
  numBytes += cSlice_init(&cSlice_vi7QMyWf, 1, -1);
  numBytes += cSlice_init(&cSlice_mwus8ty3, 1, 1);
  numBytes += cSlice_init(&cSlice_Kh5OzrHJ, 0, 1);
  numBytes += cVar_init_f(&cVar_zoDcqWmK, 0.0f);
  numBytes += cIf_init(&cIf_BGq5OxpX, false);
  numBytes += cIf_init(&cIf_KNj9yDYE, false);
  numBytes += cIf_init(&cIf_yyIPY0bM, false);
  numBytes += cVar_init_f(&cVar_lB21Qbtj, 0.0f);
  numBytes += cIf_init(&cIf_tmDdGput, false);
  numBytes += cVar_init_f(&cVar_ot4kdTEz, 0.0f);
  numBytes += cIf_init(&cIf_ZqgZjdHf, false);
  numBytes += cBinop_init(&cBinop_uYaQa0O0, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_0n2lSxUu, 4.0f);
  numBytes += cTabread_init(&cTabread_In49JDjq, &hTable_6HrXRLdl); // 1011-used
  numBytes += cSlice_init(&cSlice_c3Ku5T5S, 1, -1);
  numBytes += cVar_init_s(&cVar_SocUoqJS, "1011-used");
  numBytes += cBinop_init(&cBinop_PNADTVCB, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_UDR5s4ow, &hTable_iIrw4Hkb); // 1011-ids
  numBytes += cSlice_init(&cSlice_PQgL1isj, 1, -1);
  numBytes += cVar_init_s(&cVar_5rUQLuzl, "1011-ids");
  numBytes += cBinop_init(&cBinop_Ty3sNu53, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_bnHH0KZw, 0.0f);
  numBytes += cSlice_init(&cSlice_xeJyob02, 1, 1);
  numBytes += cSlice_init(&cSlice_bYTu4Y0d, 0, 1);
  numBytes += cTabread_init(&cTabread_pWWBsKRx, &hTable_PB1TiHnc); // 1011-pitches
  numBytes += cSlice_init(&cSlice_F3bnVTMe, 1, -1);
  numBytes += cVar_init_s(&cVar_PApmkSDM, "1011-pitches");
  numBytes += cBinop_init(&cBinop_Yug0hDL2, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_hykfdovi, 0.0f);
  numBytes += cVar_init_f(&cVar_MaUWtsdy, 0.0f);
  numBytes += cIf_init(&cIf_92sISSxH, false);
  numBytes += cTabwrite_init(&cTabwrite_pg1Olq9K, &hTable_6HrXRLdl); // 1011-used
  numBytes += cSlice_init(&cSlice_O6U4u6UI, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_L4pHFWCZ, &hTable_iIrw4Hkb); // 1011-ids
  numBytes += cSlice_init(&cSlice_I4lVh7YP, 1, -1);
  numBytes += cVar_init_f(&cVar_61TaX9Ph, 0.0f);
  numBytes += cVar_init_f(&cVar_cnmBFUha, 0.0f);
  numBytes += cSlice_init(&cSlice_fsxwto3b, 1, 1);
  numBytes += cSlice_init(&cSlice_DSwRow6T, 0, 1);
  numBytes += cPack_init(&cPack_1E9tu1ru, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_GfptJqCx, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_QYmbSr9s, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_4DMN4Sz3, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_HuTMDMz5, 0.0f); // __lt
  numBytes += cIf_init(&cIf_aS2rNfdJ, false);
  numBytes += cVar_init_f(&cVar_bh23mpYj, 0.0f);
  numBytes += cIf_init(&cIf_P4KKxC6r, false);
  numBytes += cVar_init_f(&cVar_v1r9kQty, 0.0f);
  numBytes += cIf_init(&cIf_wvVcaGul, false);
  numBytes += cBinop_init(&cBinop_b6Z6kYcS, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_Un1EqSae, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_pkc8722v, &hTable_6HrXRLdl); // 1011-used
  numBytes += cSlice_init(&cSlice_Mp5lPi57, 1, -1);
  numBytes += cTabread_init(&cTabread_EI1VtSuJ, &hTable_6HrXRLdl); // 1011-used
  numBytes += cSlice_init(&cSlice_YlokyXP4, 1, -1);
  numBytes += cVar_init_s(&cVar_9iCe4lHb, "1011-used");
  numBytes += cBinop_init(&cBinop_lxDAvxME, 0.0f); // __min
  numBytes += cIf_init(&cIf_YqhtBI3s, false);
  numBytes += cTabread_init(&cTabread_19iOnV18, &hTable_PB1TiHnc); // 1011-pitches
  numBytes += cSlice_init(&cSlice_mzDvuPBT, 1, -1);
  numBytes += cVar_init_s(&cVar_EQDW8gdV, "1011-pitches");
  numBytes += cBinop_init(&cBinop_pME5QkA1, 0.0f); // __min
  numBytes += cIf_init(&cIf_8POzGn6L, false);
  numBytes += cVar_init_f(&cVar_Y0EVT6Vj, 0.0f);
  numBytes += cIf_init(&cIf_ByZqgKko, false);
  numBytes += cVar_init_f(&cVar_JCC84rKQ, 0.0f);
  numBytes += cIf_init(&cIf_6lqjeR4r, false);
  numBytes += cBinop_init(&cBinop_Cn02phhA, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_jb4Ee4Ln, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_UBvNmtla, &hTable_6HrXRLdl); // 1011-used
  numBytes += cSlice_init(&cSlice_tWMi6o48, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_Gwc5mDGn, &hTable_iIrw4Hkb); // 1011-ids
  numBytes += cSlice_init(&cSlice_my5YznKp, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_txrmxGTM, &hTable_PB1TiHnc); // 1011-pitches
  numBytes += cSlice_init(&cSlice_x0ZEzkii, 1, -1);
  numBytes += cIf_init(&cIf_eBurQiDc, false);
  numBytes += cVar_init_f(&cVar_hf34Pdnk, 0.0f);
  numBytes += cIf_init(&cIf_AKwSCUvh, false);
  numBytes += cVar_init_f(&cVar_ulaDgEGs, 0.0f);
  numBytes += cIf_init(&cIf_Tz3dNIC4, false);
  numBytes += cBinop_init(&cBinop_OHSN5v4Y, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_m6UIYUwU, 4.0f);
  numBytes += cVar_init_f(&cVar_ko63G7GC, 0.0f);
  numBytes += cIf_init(&cIf_OecPoSpJ, false);
  numBytes += cVar_init_f(&cVar_eWAapWcD, 0.0f);
  numBytes += cVar_init_f(&cVar_dv5fr0j0, 0.0f);
  numBytes += cVar_init_f(&cVar_T2ZOjLGV, 0.0f);
  numBytes += cIf_init(&cIf_bnlIivzf, false);
  numBytes += cIf_init(&cIf_nlj2Dpw5, false);
  numBytes += cPack_init(&cPack_VakCUO14, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_jExgi6ax, 0.0f);
  numBytes += cSlice_init(&cSlice_lAPLqYQp, 1, 1);
  numBytes += cSlice_init(&cSlice_pRAnbj95, 0, 1);
  numBytes += cVar_init_f(&cVar_1u7DN0hs, 0.0f);
  numBytes += cIf_init(&cIf_ZVgeKaVI, false);
  numBytes += cVar_init_f(&cVar_KQR8kLlL, 0.0f);
  numBytes += cVar_init_f(&cVar_Nzgnz2UW, 0.0f);
  numBytes += cTabread_init(&cTabread_EPnJX05k, &hTable_6HrXRLdl); // 1011-used
  numBytes += cSlice_init(&cSlice_5Re0AX7s, 1, -1);
  numBytes += cVar_init_s(&cVar_SZ8psw5r, "1011-used");
  numBytes += cBinop_init(&cBinop_yFAJZ8MM, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_liVHYrw2, &hTable_iIrw4Hkb); // 1011-ids
  numBytes += cSlice_init(&cSlice_kC6j9CYE, 1, -1);
  numBytes += cVar_init_s(&cVar_uvqIok7Z, "1011-ids");
  numBytes += cBinop_init(&cBinop_WNPtlDD5, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_cQCI7vDb, &hTable_PB1TiHnc); // 1011-pitches
  numBytes += cSlice_init(&cSlice_TpaDBc1p, 1, -1);
  numBytes += cTabread_init(&cTabread_5655dCsw, &hTable_PB1TiHnc); // 1011-pitches
  numBytes += cSlice_init(&cSlice_h6ZkDBXF, 1, -1);
  numBytes += cVar_init_s(&cVar_m8dOssmU, "1011-pitches");
  numBytes += cBinop_init(&cBinop_wIdLH0Fl, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_mICWqs1H, &hTable_PB1TiHnc); // 1011-pitches
  numBytes += cSlice_init(&cSlice_xOP02d7P, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_c6hes3ci, &hTable_6HrXRLdl); // 1011-used
  numBytes += cSlice_init(&cSlice_mT2KVYAo, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_D0EnNUiS, &hTable_iIrw4Hkb); // 1011-ids
  numBytes += cSlice_init(&cSlice_ER5AKDOC, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_WqNZFRuG, &hTable_iIrw4Hkb); // 1011-ids
  numBytes += cSlice_init(&cSlice_laD748gg, 1, -1);
  numBytes += cVar_init_f(&cVar_KMWOtRSG, 0.0f);
  numBytes += cTabwrite_init(&cTabwrite_EvR7BABV, &hTable_6HrXRLdl); // 1011-used
  numBytes += cSlice_init(&cSlice_J3TMptpe, 1, -1);
  numBytes += cVar_init_f(&cVar_UJkjZ2xL, 0.0f);
  numBytes += cSlice_init(&cSlice_sOerQJjs, 1, 1);
  numBytes += cSlice_init(&cSlice_EHr8TChV, 0, 1);
  numBytes += cVar_init_f(&cVar_jKsGUXlb, 0.0f);
  numBytes += cBinop_init(&cBinop_W7xI7FPK, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_7ObRqE0R, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_iN3sT3WX, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_lwR2ZfqN, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_5nDxVitF, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_g5cElcbi, 65535.0f); // __unimod
  numBytes += hTable_init(&hTable_PB1TiHnc, 4);
  numBytes += hTable_init(&hTable_6HrXRLdl, 4);
  numBytes += hTable_init(&hTable_iIrw4Hkb, 4);
  numBytes += cPack_init(&cPack_6qkVubI7, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_kWwtvJYH, 1, -1);
  numBytes += cSlice_init(&cSlice_KX7xXttV, 1, -1);
  numBytes += cSlice_init(&cSlice_BvAuOD5v, 1, -1);
  numBytes += cSlice_init(&cSlice_hZykDt61, 1, -1);
  numBytes += cSlice_init(&cSlice_Zlm9nkMZ, 1, 1);
  numBytes += cSlice_init(&cSlice_w5mLxSJs, 0, 1);
  numBytes += cBinop_init(&cBinop_6cxV3sJX, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_u4xMDAK8, 22050.0f);
  numBytes += cBinop_init(&cBinop_CBlFdbnp, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_wfm0jU9N, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HIcJSGjV, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_kHuCy9gj, 22050.0f);
  numBytes += cBinop_init(&cBinop_zrSqPJlQ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_0S8IaT5Y, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5tsWAFFc, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_EzB1y7lK, 1, 1);
  numBytes += cSlice_init(&cSlice_tFs2Zx1h, 0, 1);
  numBytes += cBinop_init(&cBinop_xCoNHbVk, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_BQjVTuuL, 22050.0f);
  numBytes += cBinop_init(&cBinop_7YQKT7HA, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_gOOdoUtp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Zg8c713D, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_8EibRl5O, 22050.0f);
  numBytes += cBinop_init(&cBinop_CjEKsvaV, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_k0gavGys, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KjdaOsMG, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_XsjS1ogV, 1, 1);
  numBytes += cSlice_init(&cSlice_8sXIBNnx, 0, 1);
  numBytes += cBinop_init(&cBinop_FyNnV1xM, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_PyqC2pGm, 22050.0f);
  numBytes += cBinop_init(&cBinop_6uwO0IwF, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ggvTPpQQ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Hdgs13ZD, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_G28VgPVo, 22050.0f);
  numBytes += cBinop_init(&cBinop_6QvQr8xv, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_DsXxYbcK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_l3j495a5, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_7PX3LRAR, 1, 1);
  numBytes += cSlice_init(&cSlice_5xBX0WaZ, 0, 1);
  numBytes += cBinop_init(&cBinop_Qdd6oi7w, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_2aHET9HK, 22050.0f);
  numBytes += cBinop_init(&cBinop_Q1sIePaf, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_jndwksQl, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_UMZYZq1N, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_4YYO6yLt, 22050.0f);
  numBytes += cBinop_init(&cBinop_dge6vSOr, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_eOYmIxN3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RE1AbFWj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RRa8P1EL, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_pdpoly::~Heavy_pdpoly() {
  cPack_free(&cPack_1E9tu1ru);
  cPack_free(&cPack_VakCUO14);
  hTable_free(&hTable_PB1TiHnc);
  hTable_free(&hTable_6HrXRLdl);
  hTable_free(&hTable_iIrw4Hkb);
  cPack_free(&cPack_6qkVubI7);
}

HvTable *Heavy_pdpoly::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x7B847FB6: return &hTable_PB1TiHnc; // 1011-pitches
    case 0xA0EFCB1D: return &hTable_6HrXRLdl; // 1011-used
    case 0x73137BF4: return &hTable_iIrw4Hkb; // 1011-ids
    default: return nullptr;
  }
}

void Heavy_pdpoly::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x7EA4AD17: { // 1011-currentVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wtKahcpc_sendMessage);
      break;
    }
    case 0x9B1DF8F3: { // 1011-indexOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9nMPxDw3_sendMessage);
      break;
    }
    case 0xF7855D22: { // 1011-indexOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_SNHoxJH6_sendMessage);
      break;
    }
    case 0xEB1BA925: { // 1011-isFirstOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zEXM0ByL_sendMessage);
      break;
    }
    case 0x7426D59: { // 1011-isFirstOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Sj13Wffc_sendMessage);
      break;
    }
    case 0x199E738B: { // 1011-maxVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_au7K5KYr_sendMessage);
      break;
    }
    case 0x979E98C4: { // 1011-shouldSteal
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tj1hNtbj_sendMessage);
      break;
    }
    case 0xDB67A714: { // 1011-voiceId++
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QlIJtYfQ_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3jEqz6Kz_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_syMceADb_sendMessage);
      break;
    }
    case 0xF89F9F3E: { // cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EgLHY3oJ_sendMessage);
      break;
    }
    case 0xC2C62B6: { // vcut
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mfB46JF4_sendMessage);
      break;
    }
    case 0xB1642755: { // volume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Itwp0nm8_sendMessage);
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


void Heavy_pdpoly::cSlice_xMqtCnnD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_zh9wlLsq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_YjsgJzol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_joRMIxY9, 0, m, &cIf_joRMIxY9_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_T6gyJ8zh, 0, m, &cIf_T6gyJ8zh_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_Y54Vv5DU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_FFACCA0Q, 0, m, &cIf_FFACCA0Q_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_O8kZvCam, 0, m, &cIf_O8kZvCam_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_T5BxLOeY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_iWya1KsR_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_bVAGs5So, 0, m, &cIf_bVAGs5So_sendMessage);
}

void Heavy_pdpoly::cUnop_saA5WVMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_bUTwy1JP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KnnSabpw, HV_BINOP_EQ, 1, m, &cBinop_KnnSabpw_sendMessage);
}

void Heavy_pdpoly::cUnop_ldCexy36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_bUTwy1JP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KnnSabpw, HV_BINOP_EQ, 1, m, &cBinop_KnnSabpw_sendMessage);
}

void Heavy_pdpoly::cIf_bVAGs5So_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_ldCexy36_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_saA5WVMl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_iWya1KsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_bVAGs5So, 1, m, &cIf_bVAGs5So_sendMessage);
}

void Heavy_pdpoly::cIf_T6gyJ8zh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_zoDcqWmK, 0, m, &cVar_zoDcqWmK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_O8kZvCam_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_pnc8iSjc_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_joRMIxY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_zoDcqWmK, 0, m, &cVar_zoDcqWmK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_FFACCA0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_pnc8iSjc_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_zh9wlLsq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KnnSabpw, HV_BINOP_EQ, 0, m, &cBinop_KnnSabpw_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_bToPN17D_sendMessage);
}

void Heavy_pdpoly::cBinop_bUTwy1JP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RDpENB2h_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oN2V3m9f_sendMessage);
}

void Heavy_pdpoly::cBinop_KnnSabpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1S7bxFVe_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_juq4nhaJ_sendMessage);
}

void Heavy_pdpoly::cCast_juq4nhaJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_FFACCA0Q, 1, m, &cIf_FFACCA0Q_sendMessage);
}

void Heavy_pdpoly::cCast_1S7bxFVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_T6gyJ8zh, 1, m, &cIf_T6gyJ8zh_sendMessage);
}

void Heavy_pdpoly::cCast_RDpENB2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_joRMIxY9, 1, m, &cIf_joRMIxY9_sendMessage);
}

void Heavy_pdpoly::cCast_oN2V3m9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_O8kZvCam, 1, m, &cIf_O8kZvCam_sendMessage);
}

void Heavy_pdpoly::cBinop_bToPN17D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cVar_hy9tgdWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_XJ37vEIU_sendMessage);
}

void Heavy_pdpoly::cVar_e8JTaShc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g5cElcbi, HV_BINOP_MOD_UNIPOLAR, 0, m, &cBinop_g5cElcbi_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_pnc8iSjc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GJRSFEIZ, 0, m, &cSlice_GJRSFEIZ_sendMessage);
      break;
    }
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vi7QMyWf, 0, m, &cSlice_vi7QMyWf_sendMessage);
      break;
    }
    default: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_mwus8ty3, 0, m, &cSlice_mwus8ty3_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Kh5OzrHJ, 0, m, &cSlice_Kh5OzrHJ_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_GJRSFEIZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1ehSqUHo_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aFdRvYfD_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1ehSqUHo_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aFdRvYfD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_vi7QMyWf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y3m6vSyO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U5xpXffy_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y3m6vSyO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U5xpXffy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_mwus8ty3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_zoDcqWmK, 0, m, &cVar_zoDcqWmK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_Kh5OzrHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_BGq5OxpX, 0, m, &cIf_BGq5OxpX_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_KNj9yDYE, 0, m, &cIf_KNj9yDYE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_zoDcqWmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_VakCUO14, 1, m, &cPack_VakCUO14_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_1E9tu1ru, 1, m, &cPack_1E9tu1ru_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_3mxAH1Z6_sendMessage);
}

void Heavy_pdpoly::cIf_BGq5OxpX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sJjUy6g9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JgsuoQt5_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eIEATLyo_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_VakCUO14, 0, m, &cPack_VakCUO14_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_KNj9yDYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_1E9tu1ru, 0, m, &cPack_1E9tu1ru_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_yyIPY0bM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Bjjvzajt_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vCwJWmBp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_lB21Qbtj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hnXL77Vi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zVWFdWBp_sendMessage);
}

void Heavy_pdpoly::cIf_tmDdGput_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_it5seRQM_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zeZ4MoLB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_SvjP2qeL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_tmDdGput, 1, m, &cIf_tmDdGput_sendMessage);
}

void Heavy_pdpoly::cVar_ot4kdTEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_39ND7LCw_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ZqgZjdHf, 0, m, &cIf_ZqgZjdHf_sendMessage);
}

void Heavy_pdpoly::cUnop_Mudh1MaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_SvjP2qeL_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_tmDdGput, 0, m, &cIf_tmDdGput_sendMessage);
}

void Heavy_pdpoly::cUnop_Zab66g99_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_SvjP2qeL_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_tmDdGput, 0, m, &cIf_tmDdGput_sendMessage);
}

void Heavy_pdpoly::cIf_ZqgZjdHf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_Zab66g99_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Mudh1MaB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_39ND7LCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZqgZjdHf, 1, m, &cIf_ZqgZjdHf_sendMessage);
}

void Heavy_pdpoly::cCast_hnXL77Vi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uYaQa0O0, HV_BINOP_LESS_THAN, 0, m, &cBinop_uYaQa0O0_sendMessage);
}

void Heavy_pdpoly::cCast_zVWFdWBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yyIPY0bM, 0, m, &cIf_yyIPY0bM_sendMessage);
}

void Heavy_pdpoly::cBinop_uYaQa0O0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yyIPY0bM, 1, m, &cIf_yyIPY0bM_sendMessage);
}

void Heavy_pdpoly::cCast_it5seRQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uYaQa0O0, HV_BINOP_LESS_THAN, 1, m, &cBinop_uYaQa0O0_sendMessage);
}

void Heavy_pdpoly::cCast_zeZ4MoLB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N2ex2dVX_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_4PKwOqMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lB21Qbtj, 0, m, &cVar_lB21Qbtj_sendMessage);
}

void Heavy_pdpoly::cMsg_N2ex2dVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_lB21Qbtj, 0, m, &cVar_lB21Qbtj_sendMessage);
}

void Heavy_pdpoly::cCast_Bjjvzajt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QPXGrScD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EN0xfgqQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gvTUY6vM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DAVSqOss_sendMessage);
}

void Heavy_pdpoly::cCast_vCwJWmBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_4PKwOqMw_sendMessage);
}

void Heavy_pdpoly::cVar_0n2lSxUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ot4kdTEz, 0, m, &cVar_ot4kdTEz_sendMessage);
}

void Heavy_pdpoly::cTabread_In49JDjq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4DMN4Sz3, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_4DMN4Sz3_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_tamZ0Vaq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_c3Ku5T5S, 0, m, &cSlice_c3Ku5T5S_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_my31P2BO_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Gninbeen_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_c3Ku5T5S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_In49JDjq, 1, m, &cTabread_In49JDjq_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_In49JDjq, 1, m, &cTabread_In49JDjq_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_SocUoqJS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OjGawxQY_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_iu4QdB7X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_iaiPOwBC_sendMessage);
}

void Heavy_pdpoly::cBinop_CdJZVvlF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PNADTVCB, HV_BINOP_MIN, 0, m, &cBinop_PNADTVCB_sendMessage);
}

void Heavy_pdpoly::cCast_Gninbeen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CdJZVvlF_sendMessage);
}

void Heavy_pdpoly::cCast_my31P2BO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SocUoqJS, 0, m, &cVar_SocUoqJS_sendMessage);
}

void Heavy_pdpoly::cBinop_PNADTVCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_In49JDjq, 0, m, &cTabread_In49JDjq_sendMessage);
}

void Heavy_pdpoly::cMsg_OjGawxQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iu4QdB7X_sendMessage);
}

void Heavy_pdpoly::cBinop_iaiPOwBC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PNADTVCB, HV_BINOP_MIN, 1, m, &cBinop_PNADTVCB_sendMessage);
}

void Heavy_pdpoly::cTabread_UDR5s4ow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CfbXYF2b_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_p99REfey_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_fQ3ksQD4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PQgL1isj, 0, m, &cSlice_PQgL1isj_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dhrfFMkm_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_y3UGrqIy_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_PQgL1isj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_UDR5s4ow, 1, m, &cTabread_UDR5s4ow_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_UDR5s4ow, 1, m, &cTabread_UDR5s4ow_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_5rUQLuzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HFkFi0Nb_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_imArGZPk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_cx6qyB1T_sendMessage);
}

void Heavy_pdpoly::cBinop_OAZMF2if_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ty3sNu53, HV_BINOP_MIN, 0, m, &cBinop_Ty3sNu53_sendMessage);
}

void Heavy_pdpoly::cCast_y3UGrqIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OAZMF2if_sendMessage);
}

void Heavy_pdpoly::cCast_dhrfFMkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5rUQLuzl, 0, m, &cVar_5rUQLuzl_sendMessage);
}

void Heavy_pdpoly::cBinop_Ty3sNu53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_UDR5s4ow, 0, m, &cTabread_UDR5s4ow_sendMessage);
}

void Heavy_pdpoly::cMsg_HFkFi0Nb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_imArGZPk_sendMessage);
}

void Heavy_pdpoly::cBinop_cx6qyB1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ty3sNu53, HV_BINOP_MIN, 1, m, &cBinop_Ty3sNu53_sendMessage);
}

void Heavy_pdpoly::cVar_bnHH0KZw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pg1Olq9K, 1, m, &cTabwrite_pg1Olq9K_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_L4pHFWCZ, 1, m, &cTabwrite_L4pHFWCZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cnmBFUha, 1, m, &cVar_cnmBFUha_sendMessage);
}

void Heavy_pdpoly::cSlice_xeJyob02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_pdpoly::cSlice_bYTu4Y0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9wJjyhxQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AdFfKBWk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_pWWBsKRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GfptJqCx, HV_BINOP_EQ, 0, m, &cBinop_GfptJqCx_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_UVfpylFA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_F3bnVTMe, 0, m, &cSlice_F3bnVTMe_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PuZ2kNth_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hVwSShhO_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_F3bnVTMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_pWWBsKRx, 1, m, &cTabread_pWWBsKRx_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_pWWBsKRx, 1, m, &cTabread_pWWBsKRx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_PApmkSDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q5pVJut0_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_04rvAubz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_k34kyEd1_sendMessage);
}

void Heavy_pdpoly::cBinop_lcFFGMYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yug0hDL2, HV_BINOP_MIN, 0, m, &cBinop_Yug0hDL2_sendMessage);
}

void Heavy_pdpoly::cCast_PuZ2kNth_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PApmkSDM, 0, m, &cVar_PApmkSDM_sendMessage);
}

void Heavy_pdpoly::cCast_hVwSShhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lcFFGMYA_sendMessage);
}

void Heavy_pdpoly::cBinop_Yug0hDL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_pWWBsKRx, 0, m, &cTabread_pWWBsKRx_sendMessage);
}

void Heavy_pdpoly::cMsg_q5pVJut0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_04rvAubz_sendMessage);
}

void Heavy_pdpoly::cBinop_k34kyEd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yug0hDL2, HV_BINOP_MIN, 1, m, &cBinop_Yug0hDL2_sendMessage);
}

void Heavy_pdpoly::cVar_hykfdovi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HuTMDMz5, HV_BINOP_LESS_THAN, 1, m, &cBinop_HuTMDMz5_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_INcSN2fl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yUl9kmDr_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_yUl9kmDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7QaBCTXj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_k2PHPdHX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KkEpldzA_sendMessage);
}

void Heavy_pdpoly::cVar_MaUWtsdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HuTMDMz5, HV_BINOP_LESS_THAN, 1, m, &cBinop_HuTMDMz5_sendMessage);
}

void Heavy_pdpoly::cIf_92sISSxH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_y1SdhYqb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UuPB0FIs_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3efwXtvz_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fsxwto3b, 0, m, &cSlice_fsxwto3b_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_DSwRow6T, 0, m, &cSlice_DSwRow6T_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IccBndiD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_pg1Olq9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_HdfFCTVN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_O6U4u6UI, 0, m, &cSlice_O6U4u6UI_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pg1Olq9K, 0, m, &cTabwrite_pg1Olq9K_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_O6U4u6UI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pg1Olq9K, 2, m, &cTabwrite_pg1Olq9K_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pg1Olq9K, 2, m, &cTabwrite_pg1Olq9K_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_L4pHFWCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_qXlwonUQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_I4lVh7YP, 0, m, &cSlice_I4lVh7YP_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_L4pHFWCZ, 0, m, &cTabwrite_L4pHFWCZ_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_I4lVh7YP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_L4pHFWCZ, 2, m, &cTabwrite_L4pHFWCZ_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_L4pHFWCZ, 2, m, &cTabwrite_L4pHFWCZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_61TaX9Ph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qXlwonUQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cVar_cnmBFUha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_vVIjSw4S_sendMessage);
}

void Heavy_pdpoly::cSlice_fsxwto3b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_pdpoly::cSlice_DSwRow6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_6qkVubI7, 1, m, &cPack_6qkVubI7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cPack_1E9tu1ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6NFTQN6D_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7scQSCxb_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_xeJyob02, 0, m, &cSlice_xeJyob02_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_bYTu4Y0d, 0, m, &cSlice_bYTu4Y0d_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_92sISSxH, 0, m, &cIf_92sISSxH_sendMessage);
}

void Heavy_pdpoly::cCast_gvTUY6vM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_tamZ0Vaq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_EN0xfgqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fQ3ksQD4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_QPXGrScD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bnHH0KZw, 1, m, &cVar_bnHH0KZw_sendMessage);
}

void Heavy_pdpoly::cCast_DAVSqOss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_UVfpylFA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_GH8xXhpw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_92sISSxH, 1, m, &cIf_92sISSxH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bnHH0KZw, 0, m, &cVar_bnHH0KZw_sendMessage);
}

void Heavy_pdpoly::cMsg_DSsjwRFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_92sISSxH, 1, m, &cIf_92sISSxH_sendMessage);
}

void Heavy_pdpoly::cCast_6NFTQN6D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hykfdovi, 0, m, &cVar_hykfdovi_sendMessage);
}

void Heavy_pdpoly::cCast_7scQSCxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GH8xXhpw_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_9wJjyhxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GfptJqCx, HV_BINOP_EQ, 1, m, &cBinop_GfptJqCx_sendMessage);
}

void Heavy_pdpoly::cCast_AdFfKBWk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0n2lSxUu, 0, m, &cVar_0n2lSxUu_sendMessage);
}

void Heavy_pdpoly::cBinop_GfptJqCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QYmbSr9s, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_QYmbSr9s_sendMessage);
}

void Heavy_pdpoly::cBinop_QYmbSr9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_INcSN2fl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_4DMN4Sz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QYmbSr9s, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_QYmbSr9s_sendMessage);
}

void Heavy_pdpoly::cBinop_HuTMDMz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4DMN4Sz3, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_4DMN4Sz3_sendMessage);
}

void Heavy_pdpoly::cCast_7QaBCTXj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MaUWtsdy, 0, m, &cVar_MaUWtsdy_sendMessage);
}

void Heavy_pdpoly::cCast_KkEpldzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bnHH0KZw, 0, m, &cVar_bnHH0KZw_sendMessage);
}

void Heavy_pdpoly::cCast_k2PHPdHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DSsjwRFr_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_CfbXYF2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MaUWtsdy, 1, m, &cVar_MaUWtsdy_sendMessage);
}

void Heavy_pdpoly::cCast_p99REfey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HuTMDMz5, HV_BINOP_LESS_THAN, 0, m, &cBinop_HuTMDMz5_sendMessage);
}

void Heavy_pdpoly::cCast_2GgOwBIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0FDZaWas_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_bXSUL0uV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_61TaX9Ph, 0, m, &cVar_61TaX9Ph_sendMessage);
}

void Heavy_pdpoly::cSend_0FDZaWas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QlIJtYfQ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_UuPB0FIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2GgOwBIv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bXSUL0uV_sendMessage);
}

void Heavy_pdpoly::cCast_y1SdhYqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WG5WJQyG_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_WG5WJQyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_HdfFCTVN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_3efwXtvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ruq5idj4_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_IccBndiD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cnmBFUha, 0, m, &cVar_cnmBFUha_sendMessage);
}

void Heavy_pdpoly::cMsg_Ruq5idj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_6qkVubI7, 2, m, &cPack_6qkVubI7_sendMessage);
}

void Heavy_pdpoly::cIf_aS2rNfdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uPR6NX1y_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QvfiWOAg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_bh23mpYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XgKvQBv2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rt8KxaYo_sendMessage);
}

void Heavy_pdpoly::cIf_P4KKxC6r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_okJI1bII_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6EY9xpY2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_al3eQ250_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_P4KKxC6r, 1, m, &cIf_P4KKxC6r_sendMessage);
}

void Heavy_pdpoly::cVar_v1r9kQty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_uFkOAABZ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_wvVcaGul, 0, m, &cIf_wvVcaGul_sendMessage);
}

void Heavy_pdpoly::cUnop_u0tcSOXk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_al3eQ250_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_P4KKxC6r, 0, m, &cIf_P4KKxC6r_sendMessage);
}

void Heavy_pdpoly::cUnop_Jq9rccjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_al3eQ250_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_P4KKxC6r, 0, m, &cIf_P4KKxC6r_sendMessage);
}

void Heavy_pdpoly::cIf_wvVcaGul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_Jq9rccjl_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_u0tcSOXk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_uFkOAABZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wvVcaGul, 1, m, &cIf_wvVcaGul_sendMessage);
}

void Heavy_pdpoly::cCast_XgKvQBv2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b6Z6kYcS, HV_BINOP_LESS_THAN, 0, m, &cBinop_b6Z6kYcS_sendMessage);
}

void Heavy_pdpoly::cCast_rt8KxaYo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aS2rNfdJ, 0, m, &cIf_aS2rNfdJ_sendMessage);
}

void Heavy_pdpoly::cBinop_b6Z6kYcS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aS2rNfdJ, 1, m, &cIf_aS2rNfdJ_sendMessage);
}

void Heavy_pdpoly::cCast_okJI1bII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b6Z6kYcS, HV_BINOP_LESS_THAN, 1, m, &cBinop_b6Z6kYcS_sendMessage);
}

void Heavy_pdpoly::cCast_6EY9xpY2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4Lq3BtFj_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_iIbUcNdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bh23mpYj, 0, m, &cVar_bh23mpYj_sendMessage);
}

void Heavy_pdpoly::cMsg_4Lq3BtFj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_bh23mpYj, 0, m, &cVar_bh23mpYj_sendMessage);
}

void Heavy_pdpoly::cCast_QvfiWOAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_iIbUcNdS_sendMessage);
}

void Heavy_pdpoly::cCast_uPR6NX1y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S0ZZspIg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_y3P177Ne_sendMessage);
}

void Heavy_pdpoly::cVar_Un1EqSae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_v1r9kQty, 0, m, &cVar_v1r9kQty_sendMessage);
}

void Heavy_pdpoly::cTabwrite_pkc8722v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_MFbSNBk8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Mp5lPi57, 0, m, &cSlice_Mp5lPi57_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pkc8722v, 0, m, &cTabwrite_pkc8722v_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_Mp5lPi57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pkc8722v, 2, m, &cTabwrite_pkc8722v_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pkc8722v, 2, m, &cTabwrite_pkc8722v_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_EI1VtSuJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_lFeValK6_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_Lle037Pr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YlokyXP4, 0, m, &cSlice_YlokyXP4_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kWxUwAUo_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LU4VeZDL_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_YlokyXP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_EI1VtSuJ, 1, m, &cTabread_EI1VtSuJ_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_EI1VtSuJ, 1, m, &cTabread_EI1VtSuJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_9iCe4lHb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HaEh9sLs_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_BwaRNY3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ahumAQmn_sendMessage);
}

void Heavy_pdpoly::cBinop_WMC7uyZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lxDAvxME, HV_BINOP_MIN, 0, m, &cBinop_lxDAvxME_sendMessage);
}

void Heavy_pdpoly::cCast_kWxUwAUo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9iCe4lHb, 0, m, &cVar_9iCe4lHb_sendMessage);
}

void Heavy_pdpoly::cCast_LU4VeZDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_WMC7uyZc_sendMessage);
}

void Heavy_pdpoly::cBinop_lxDAvxME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_EI1VtSuJ, 0, m, &cTabread_EI1VtSuJ_sendMessage);
}

void Heavy_pdpoly::cMsg_HaEh9sLs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BwaRNY3E_sendMessage);
}

void Heavy_pdpoly::cBinop_ahumAQmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lxDAvxME, HV_BINOP_MIN, 1, m, &cBinop_lxDAvxME_sendMessage);
}

void Heavy_pdpoly::cIf_YqhtBI3s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LkVhx1ht_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Qk1Y17bX_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_H1w078PX_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uZ24CC3g_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nkHHJEnC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_19iOnV18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6qkVubI7, 1, m, &cPack_6qkVubI7_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_a2g0Yo9x_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mzDvuPBT, 0, m, &cSlice_mzDvuPBT_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6WJIQi2V_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LIEISm1E_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_mzDvuPBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_19iOnV18, 1, m, &cTabread_19iOnV18_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_19iOnV18, 1, m, &cTabread_19iOnV18_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_EQDW8gdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Dqizv2i6_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_XtJpzEvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_EZAZQssN_sendMessage);
}

void Heavy_pdpoly::cBinop_EbXu2Y90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pME5QkA1, HV_BINOP_MIN, 0, m, &cBinop_pME5QkA1_sendMessage);
}

void Heavy_pdpoly::cCast_LIEISm1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EbXu2Y90_sendMessage);
}

void Heavy_pdpoly::cCast_6WJIQi2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EQDW8gdV, 0, m, &cVar_EQDW8gdV_sendMessage);
}

void Heavy_pdpoly::cBinop_pME5QkA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_19iOnV18, 0, m, &cTabread_19iOnV18_sendMessage);
}

void Heavy_pdpoly::cMsg_Dqizv2i6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XtJpzEvu_sendMessage);
}

void Heavy_pdpoly::cBinop_EZAZQssN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pME5QkA1, HV_BINOP_MIN, 1, m, &cBinop_pME5QkA1_sendMessage);
}

void Heavy_pdpoly::cCast_1ehSqUHo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5dxTFNDZ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_aFdRvYfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Un1EqSae, 0, m, &cVar_Un1EqSae_sendMessage);
}

void Heavy_pdpoly::cMsg_5dxTFNDZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_BrVJcSXR_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_BrVJcSXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QlIJtYfQ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_lFeValK6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YqhtBI3s, 1, m, &cIf_YqhtBI3s_sendMessage);
}

void Heavy_pdpoly::cCast_S0ZZspIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Lle037Pr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_y3P177Ne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YqhtBI3s, 0, m, &cIf_YqhtBI3s_sendMessage);
}

void Heavy_pdpoly::cMsg_MkKTM04e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_6qkVubI7, 2, m, &cPack_6qkVubI7_sendMessage);
}

void Heavy_pdpoly::cCast_Qk1Y17bX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_a2g0Yo9x_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_LkVhx1ht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MkKTM04e_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_uZ24CC3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vjORhL7h_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L5R3Zgkg_sendMessage);
}

void Heavy_pdpoly::cCast_nkHHJEnC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_4SdTqODg_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_H1w078PX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_vVIjSw4S_sendMessage);
}

void Heavy_pdpoly::cCast_vjORhL7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pkc8722v, 1, m, &cTabwrite_pkc8722v_sendMessage);
}

void Heavy_pdpoly::cCast_L5R3Zgkg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N8xfJbOX_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_N8xfJbOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_MFbSNBk8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSend_4SdTqODg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QlIJtYfQ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_8POzGn6L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1vol3Pq6_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5odjEWZE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_Y0EVT6Vj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fESdziYX_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_74X1DwpI_sendMessage);
}

void Heavy_pdpoly::cIf_ByZqgKko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NBnL39mQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YmvXjevG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_KfmlzfBO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ByZqgKko, 1, m, &cIf_ByZqgKko_sendMessage);
}

void Heavy_pdpoly::cVar_JCC84rKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_LPU486GH_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_6lqjeR4r, 0, m, &cIf_6lqjeR4r_sendMessage);
}

void Heavy_pdpoly::cUnop_Q64BjiLs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_KfmlzfBO_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ByZqgKko, 0, m, &cIf_ByZqgKko_sendMessage);
}

void Heavy_pdpoly::cUnop_K64U5aUY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_KfmlzfBO_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ByZqgKko, 0, m, &cIf_ByZqgKko_sendMessage);
}

void Heavy_pdpoly::cIf_6lqjeR4r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_K64U5aUY_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Q64BjiLs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_LPU486GH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6lqjeR4r, 1, m, &cIf_6lqjeR4r_sendMessage);
}

void Heavy_pdpoly::cCast_74X1DwpI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8POzGn6L, 0, m, &cIf_8POzGn6L_sendMessage);
}

void Heavy_pdpoly::cCast_fESdziYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cn02phhA, HV_BINOP_LESS_THAN, 0, m, &cBinop_Cn02phhA_sendMessage);
}

void Heavy_pdpoly::cBinop_Cn02phhA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8POzGn6L, 1, m, &cIf_8POzGn6L_sendMessage);
}

void Heavy_pdpoly::cCast_NBnL39mQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cn02phhA, HV_BINOP_LESS_THAN, 1, m, &cBinop_Cn02phhA_sendMessage);
}

void Heavy_pdpoly::cCast_YmvXjevG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y5S5lsJB_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_tF9ZgYUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y0EVT6Vj, 0, m, &cVar_Y0EVT6Vj_sendMessage);
}

void Heavy_pdpoly::cMsg_Y5S5lsJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Y0EVT6Vj, 0, m, &cVar_Y0EVT6Vj_sendMessage);
}

void Heavy_pdpoly::cCast_5odjEWZE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_tF9ZgYUH_sendMessage);
}

void Heavy_pdpoly::cCast_1vol3Pq6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_txrmxGTM, 1, m, &cTabwrite_txrmxGTM_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Gwc5mDGn, 1, m, &cTabwrite_Gwc5mDGn_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_UBvNmtla, 1, m, &cTabwrite_UBvNmtla_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wmQnE2rk_sendMessage);
}

void Heavy_pdpoly::cVar_jb4Ee4Ln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JCC84rKQ, 0, m, &cVar_JCC84rKQ_sendMessage);
}

void Heavy_pdpoly::cTabwrite_UBvNmtla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_qi2kDUZx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_tWMi6o48, 0, m, &cSlice_tWMi6o48_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_UBvNmtla, 0, m, &cTabwrite_UBvNmtla_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_tWMi6o48_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_UBvNmtla, 2, m, &cTabwrite_UBvNmtla_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_UBvNmtla, 2, m, &cTabwrite_UBvNmtla_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_Gwc5mDGn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_NQJrU6Bd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_my5YznKp, 0, m, &cSlice_my5YznKp_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Gwc5mDGn, 0, m, &cTabwrite_Gwc5mDGn_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_my5YznKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Gwc5mDGn, 2, m, &cTabwrite_Gwc5mDGn_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Gwc5mDGn, 2, m, &cTabwrite_Gwc5mDGn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_txrmxGTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_zVJdCw0Z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_x0ZEzkii, 0, m, &cSlice_x0ZEzkii_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_txrmxGTM, 0, m, &cTabwrite_txrmxGTM_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_x0ZEzkii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_txrmxGTM, 2, m, &cTabwrite_txrmxGTM_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_txrmxGTM, 2, m, &cTabwrite_txrmxGTM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cMsg_KpmXr7KX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_zVJdCw0Z_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_NQJrU6Bd_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_qi2kDUZx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_U5xpXffy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jb4Ee4Ln, 0, m, &cVar_jb4Ee4Ln_sendMessage);
}

void Heavy_pdpoly::cCast_Y3m6vSyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OiBzm1cn_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_OiBzm1cn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_6onQsX3p_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_6onQsX3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QlIJtYfQ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_wmQnE2rk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KpmXr7KX_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_eBurQiDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6XelwIFT_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iwjwxzaY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_hf34Pdnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hh1HMpQF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NGYKcUzK_sendMessage);
}

void Heavy_pdpoly::cIf_AKwSCUvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zlbysa4E_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZWBB63rA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_CxB7nMbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_AKwSCUvh, 1, m, &cIf_AKwSCUvh_sendMessage);
}

void Heavy_pdpoly::cVar_ulaDgEGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_KqnTFNsB_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Tz3dNIC4, 0, m, &cIf_Tz3dNIC4_sendMessage);
}

void Heavy_pdpoly::cUnop_KtcGZqgw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_CxB7nMbD_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_AKwSCUvh, 0, m, &cIf_AKwSCUvh_sendMessage);
}

void Heavy_pdpoly::cUnop_Bu0tiohL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_CxB7nMbD_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_AKwSCUvh, 0, m, &cIf_AKwSCUvh_sendMessage);
}

void Heavy_pdpoly::cIf_Tz3dNIC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_Bu0tiohL_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_KtcGZqgw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_KqnTFNsB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Tz3dNIC4, 1, m, &cIf_Tz3dNIC4_sendMessage);
}

void Heavy_pdpoly::cCast_hh1HMpQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OHSN5v4Y, HV_BINOP_LESS_THAN, 0, m, &cBinop_OHSN5v4Y_sendMessage);
}

void Heavy_pdpoly::cCast_NGYKcUzK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eBurQiDc, 0, m, &cIf_eBurQiDc_sendMessage);
}

void Heavy_pdpoly::cBinop_OHSN5v4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eBurQiDc, 1, m, &cIf_eBurQiDc_sendMessage);
}

void Heavy_pdpoly::cCast_ZWBB63rA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_P5YUerFd_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_zlbysa4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OHSN5v4Y, HV_BINOP_LESS_THAN, 1, m, &cBinop_OHSN5v4Y_sendMessage);
}

void Heavy_pdpoly::cBinop_IWPauqLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hf34Pdnk, 0, m, &cVar_hf34Pdnk_sendMessage);
}

void Heavy_pdpoly::cMsg_P5YUerFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_hf34Pdnk, 0, m, &cVar_hf34Pdnk_sendMessage);
}

void Heavy_pdpoly::cCast_iwjwxzaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_IWPauqLa_sendMessage);
}

void Heavy_pdpoly::cCast_6XelwIFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SlzZDkEs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cgieCUFS_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_k9m81UUi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FLuoGsmn_sendMessage);
}

void Heavy_pdpoly::cVar_m6UIYUwU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ulaDgEGs, 0, m, &cVar_ulaDgEGs_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_QgTvS1Uc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UzBvowzF_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_UzBvowzF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mbWNEVf4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_N4rbFduk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5d7evMP7_sendMessage);
}

void Heavy_pdpoly::cVar_ko63G7GC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lzlpDXUO_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_OecPoSpJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_iYSqgIxy_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_eWAapWcD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_EpXihgKW_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSwitchcase_iYSqgIxy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LwBmdw0U_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_LwBmdw0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DgZX6pgn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4vKpLEa4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y16XILoj_sendMessage);
}

void Heavy_pdpoly::cVar_dv5fr0j0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7ObRqE0R, HV_BINOP_LESS_THAN, 1, m, &cBinop_7ObRqE0R_sendMessage);
}

void Heavy_pdpoly::cVar_T2ZOjLGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lwR2ZfqN, HV_BINOP_LESS_THAN, 1, m, &cBinop_lwR2ZfqN_sendMessage);
}

void Heavy_pdpoly::cIf_bnlIivzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_lAPLqYQp, 0, m, &cSlice_lAPLqYQp_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_pRAnbj95, 0, m, &cSlice_pRAnbj95_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fQ16rfhw_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RWbitJek_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HWYsBFHX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_nlj2Dpw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2uMDkMhD_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_sOerQJjs, 0, m, &cSlice_sOerQJjs_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_EHr8TChV, 0, m, &cSlice_EHr8TChV_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AwjZ87o1_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EVjaSQZD_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h8mOlMcM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cPack_VakCUO14_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nlj2Dpw5, 0, m, &cIf_nlj2Dpw5_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_bnlIivzf, 0, m, &cIf_bnlIivzf_sendMessage);
}

void Heavy_pdpoly::cVar_jExgi6ax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_vVIjSw4S_sendMessage);
}

void Heavy_pdpoly::cSlice_lAPLqYQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_6qkVubI7, 2, m, &cPack_6qkVubI7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_pRAnbj95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_7qYOpSWD_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_6qkVubI7, 1, m, &cPack_6qkVubI7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_1u7DN0hs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_vVIjSw4S_sendMessage);
}

void Heavy_pdpoly::cIf_ZVgeKaVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_nlj2Dpw5, 1, m, &cIf_nlj2Dpw5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_KQR8kLlL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_b6bDuA99_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cVar_Nzgnz2UW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3FWzWp45_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cTabread_EPnJX05k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AaNbBXE0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7q8N7fmj_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_7Vwik3Pe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5Re0AX7s, 0, m, &cSlice_5Re0AX7s_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tMBQLReD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UjcZGgRi_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_5Re0AX7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_EPnJX05k, 1, m, &cTabread_EPnJX05k_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_EPnJX05k, 1, m, &cTabread_EPnJX05k_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_SZ8psw5r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2JJrKvhE_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_VSY9yYqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_5qTNS0AR_sendMessage);
}

void Heavy_pdpoly::cBinop_0oKCnFi2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yFAJZ8MM, HV_BINOP_MIN, 0, m, &cBinop_yFAJZ8MM_sendMessage);
}

void Heavy_pdpoly::cCast_UjcZGgRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0oKCnFi2_sendMessage);
}

void Heavy_pdpoly::cCast_tMBQLReD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SZ8psw5r, 0, m, &cVar_SZ8psw5r_sendMessage);
}

void Heavy_pdpoly::cBinop_yFAJZ8MM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_EPnJX05k, 0, m, &cTabread_EPnJX05k_sendMessage);
}

void Heavy_pdpoly::cMsg_2JJrKvhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VSY9yYqT_sendMessage);
}

void Heavy_pdpoly::cBinop_5qTNS0AR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yFAJZ8MM, HV_BINOP_MIN, 1, m, &cBinop_yFAJZ8MM_sendMessage);
}

void Heavy_pdpoly::cTabread_liVHYrw2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_o7V3W3pi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DWZ56sl3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8ohECqnD_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_OtRezTAd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_kC6j9CYE, 0, m, &cSlice_kC6j9CYE_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eEdfmGU1_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9Ik9FiL3_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_kC6j9CYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_liVHYrw2, 1, m, &cTabread_liVHYrw2_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_liVHYrw2, 1, m, &cTabread_liVHYrw2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_uvqIok7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ko9O2gAJ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_m3dYgvqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_lKOw3gQX_sendMessage);
}

void Heavy_pdpoly::cBinop_kForQUJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WNPtlDD5, HV_BINOP_MIN, 0, m, &cBinop_WNPtlDD5_sendMessage);
}

void Heavy_pdpoly::cCast_eEdfmGU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uvqIok7Z, 0, m, &cVar_uvqIok7Z_sendMessage);
}

void Heavy_pdpoly::cCast_9Ik9FiL3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kForQUJA_sendMessage);
}

void Heavy_pdpoly::cBinop_WNPtlDD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_liVHYrw2, 0, m, &cTabread_liVHYrw2_sendMessage);
}

void Heavy_pdpoly::cMsg_Ko9O2gAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_m3dYgvqL_sendMessage);
}

void Heavy_pdpoly::cBinop_lKOw3gQX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WNPtlDD5, HV_BINOP_MIN, 1, m, &cBinop_WNPtlDD5_sendMessage);
}

void Heavy_pdpoly::cTabwrite_cQCI7vDb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_7zyDAUHf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TpaDBc1p, 0, m, &cSlice_TpaDBc1p_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_cQCI7vDb, 0, m, &cTabwrite_cQCI7vDb_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_TpaDBc1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_cQCI7vDb, 2, m, &cTabwrite_cQCI7vDb_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_cQCI7vDb, 2, m, &cTabwrite_cQCI7vDb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_5655dCsw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6qkVubI7, 1, m, &cPack_6qkVubI7_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_b6bDuA99_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_h6ZkDBXF, 0, m, &cSlice_h6ZkDBXF_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QIWRx330_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KNbERJCy_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_h6ZkDBXF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_5655dCsw, 1, m, &cTabread_5655dCsw_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_5655dCsw, 1, m, &cTabread_5655dCsw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_m8dOssmU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y5Lg38S2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_dMzpKbUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nLyuPGd1_sendMessage);
}

void Heavy_pdpoly::cBinop_RxA5XCrS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wIdLH0Fl, HV_BINOP_MIN, 0, m, &cBinop_wIdLH0Fl_sendMessage);
}

void Heavy_pdpoly::cCast_KNbERJCy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RxA5XCrS_sendMessage);
}

void Heavy_pdpoly::cCast_QIWRx330_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_m8dOssmU, 0, m, &cVar_m8dOssmU_sendMessage);
}

void Heavy_pdpoly::cBinop_wIdLH0Fl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_5655dCsw, 0, m, &cTabread_5655dCsw_sendMessage);
}

void Heavy_pdpoly::cMsg_y5Lg38S2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dMzpKbUl_sendMessage);
}

void Heavy_pdpoly::cBinop_nLyuPGd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wIdLH0Fl, HV_BINOP_MIN, 1, m, &cBinop_wIdLH0Fl_sendMessage);
}

void Heavy_pdpoly::cTabwrite_mICWqs1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_7qYOpSWD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xOP02d7P, 0, m, &cSlice_xOP02d7P_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_mICWqs1H, 0, m, &cTabwrite_mICWqs1H_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_xOP02d7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_mICWqs1H, 2, m, &cTabwrite_mICWqs1H_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_mICWqs1H, 2, m, &cTabwrite_mICWqs1H_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_c6hes3ci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_drKQV7nr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mT2KVYAo, 0, m, &cSlice_mT2KVYAo_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_c6hes3ci, 0, m, &cTabwrite_c6hes3ci_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_mT2KVYAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_c6hes3ci, 2, m, &cTabwrite_c6hes3ci_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_c6hes3ci, 2, m, &cTabwrite_c6hes3ci_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_D0EnNUiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_3FWzWp45_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ER5AKDOC, 0, m, &cSlice_ER5AKDOC_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_D0EnNUiS, 0, m, &cTabwrite_D0EnNUiS_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_ER5AKDOC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_D0EnNUiS, 2, m, &cTabwrite_D0EnNUiS_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_D0EnNUiS, 2, m, &cTabwrite_D0EnNUiS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_WqNZFRuG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_5A9yThLw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_laD748gg, 0, m, &cSlice_laD748gg_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_WqNZFRuG, 0, m, &cTabwrite_WqNZFRuG_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_laD748gg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_WqNZFRuG, 2, m, &cTabwrite_WqNZFRuG_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_WqNZFRuG, 2, m, &cTabwrite_WqNZFRuG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_KMWOtRSG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5A9yThLw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cTabwrite_EvR7BABV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_H7uNXnLr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_J3TMptpe, 0, m, &cSlice_J3TMptpe_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_EvR7BABV, 0, m, &cTabwrite_EvR7BABV_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_J3TMptpe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_EvR7BABV, 2, m, &cTabwrite_EvR7BABV_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_EvR7BABV, 2, m, &cTabwrite_EvR7BABV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_UJkjZ2xL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2inLHxdP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_p9HMkh4a_sendMessage);
}

void Heavy_pdpoly::cSlice_sOerQJjs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_6qkVubI7, 2, m, &cPack_6qkVubI7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_EHr8TChV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_7zyDAUHf_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_6qkVubI7, 1, m, &cPack_6qkVubI7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_jKsGUXlb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5nDxVitF, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_5nDxVitF_sendMessage);
}

void Heavy_pdpoly::cBinop_W7xI7FPK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oKlCi91H_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nCxATTko_sendMessage);
}

void Heavy_pdpoly::cBinop_7ObRqE0R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iN3sT3WX, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_iN3sT3WX_sendMessage);
}

void Heavy_pdpoly::cCast_FLuoGsmn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cCast_SlzZDkEs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ko63G7GC, 1, m, &cVar_ko63G7GC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eWAapWcD, 1, m, &cVar_eWAapWcD_sendMessage);
}

void Heavy_pdpoly::cCast_k9m81UUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_7Vwik3Pe_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_cgieCUFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OtRezTAd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSend_lzlpDXUO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SNHoxJH6_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_AaNbBXE0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W7xI7FPK, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_W7xI7FPK_sendMessage);
}

void Heavy_pdpoly::cCast_7q8N7fmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_DKW91CLx_sendMessage);
}

void Heavy_pdpoly::cBinop_iN3sT3WX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OecPoSpJ, 0, m, &cIf_OecPoSpJ_sendMessage);
}

void Heavy_pdpoly::cBinop_DKW91CLx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iN3sT3WX, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_iN3sT3WX_sendMessage);
}

void Heavy_pdpoly::cCast_nCxATTko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_qckD2W5z_sendMessage);
}

void Heavy_pdpoly::cCast_oKlCi91H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_QgTvS1Uc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_qckD2W5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OecPoSpJ, 1, m, &cIf_OecPoSpJ_sendMessage);
}

void Heavy_pdpoly::cSend_EpXihgKW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9nMPxDw3_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_QkjDTUdI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_SNHoxJH6_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_GmfvYuRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9nMPxDw3_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_JgsuoQt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UJkjZ2xL, 0, m, &cVar_UJkjZ2xL_sendMessage);
}

void Heavy_pdpoly::cCast_eIEATLyo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_m6UIYUwU, 0, m, &cVar_m6UIYUwU_sendMessage);
}

void Heavy_pdpoly::cCast_sJjUy6g9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_axNOiZIc_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_lwR2ZfqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W7xI7FPK, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_W7xI7FPK_sendMessage);
}

void Heavy_pdpoly::cCast_8ohECqnD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7ObRqE0R, HV_BINOP_LESS_THAN, 0, m, &cBinop_7ObRqE0R_sendMessage);
}

void Heavy_pdpoly::cCast_o7V3W3pi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dv5fr0j0, 1, m, &cVar_dv5fr0j0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_T2ZOjLGV, 1, m, &cVar_T2ZOjLGV_sendMessage);
}

void Heavy_pdpoly::cCast_DWZ56sl3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lwR2ZfqN, HV_BINOP_LESS_THAN, 0, m, &cBinop_lwR2ZfqN_sendMessage);
}

void Heavy_pdpoly::cCast_2inLHxdP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T2ZOjLGV, 0, m, &cVar_T2ZOjLGV_sendMessage);
}

void Heavy_pdpoly::cCast_p9HMkh4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dv5fr0j0, 0, m, &cVar_dv5fr0j0_sendMessage);
}

void Heavy_pdpoly::cSend_HpgKyNU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zEXM0ByL_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_DgZX6pgn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dv5fr0j0, 0, m, &cVar_dv5fr0j0_sendMessage);
}

void Heavy_pdpoly::cCast_Y16XILoj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eWAapWcD, 0, m, &cVar_eWAapWcD_sendMessage);
}

void Heavy_pdpoly::cCast_4vKpLEa4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KcgpLk8Q_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_KcgpLk8Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_HpgKyNU3_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_50Quck7U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_2I4LFoO3_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_2I4LFoO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Sj13Wffc_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_mbWNEVf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T2ZOjLGV, 0, m, &cVar_T2ZOjLGV_sendMessage);
}

void Heavy_pdpoly::cCast_5d7evMP7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ko63G7GC, 0, m, &cVar_ko63G7GC_sendMessage);
}

void Heavy_pdpoly::cCast_N4rbFduk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_50Quck7U_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_axNOiZIc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_GmfvYuRi_sendMessage(_c, 0, m);
  cSend_QkjDTUdI_sendMessage(_c, 0, m);
  cSend_VAWmxc0t_sendMessage(_c, 0, m);
  cSend_BcThEvkQ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_VAWmxc0t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Sj13Wffc_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_BcThEvkQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_zEXM0ByL_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_CuNGfZ9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_bnlIivzf, 1, m, &cIf_bnlIivzf_sendMessage);
}

void Heavy_pdpoly::cCast_UzKTKGpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_qpYgB6zW_sendMessage);
}

void Heavy_pdpoly::cBinop_5nDxVitF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZVgeKaVI, 0, m, &cIf_ZVgeKaVI_sendMessage);
}

void Heavy_pdpoly::cBinop_qpYgB6zW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jKsGUXlb, 0, m, &cVar_jKsGUXlb_sendMessage);
}

void Heavy_pdpoly::cMsg_WkIuwjGe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_drKQV7nr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_GtVoLvfb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_H7uNXnLr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_9MCnSNRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rgNfPmVM_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_PcXoT0yO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KQR8kLlL, 0, m, &cVar_KQR8kLlL_sendMessage);
}

void Heavy_pdpoly::cCast_GNqBBEaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1u7DN0hs, 0, m, &cVar_1u7DN0hs_sendMessage);
}

void Heavy_pdpoly::cMsg_rgNfPmVM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_6qkVubI7, 2, m, &cPack_6qkVubI7_sendMessage);
}

void Heavy_pdpoly::cCast_RWbitJek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WkIuwjGe_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_HWYsBFHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YTQpdgv3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MNIlwxt7_sendMessage);
}

void Heavy_pdpoly::cCast_fQ16rfhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jExgi6ax, 0, m, &cVar_jExgi6ax_sendMessage);
}

void Heavy_pdpoly::cCast_MNIlwxt7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Nzgnz2UW, 0, m, &cVar_Nzgnz2UW_sendMessage);
}

void Heavy_pdpoly::cCast_YTQpdgv3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_HFXbWo0d_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_HFXbWo0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QlIJtYfQ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_hIq547gs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KMWOtRSG, 0, m, &cVar_KMWOtRSG_sendMessage);
}

void Heavy_pdpoly::cCast_DH6286Em_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_wAaF1xvT_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_wAaF1xvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QlIJtYfQ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_h8mOlMcM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DH6286Em_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hIq547gs_sendMessage);
}

void Heavy_pdpoly::cCast_EVjaSQZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GtVoLvfb_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_AwjZ87o1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1u7DN0hs, 0, m, &cVar_1u7DN0hs_sendMessage);
}

void Heavy_pdpoly::cCast_2uMDkMhD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9MCnSNRA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PcXoT0yO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GNqBBEaV_sendMessage);
}

void Heavy_pdpoly::cCast_3AnrHrFX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jKsGUXlb, 0, m, &cVar_jKsGUXlb_sendMessage);
}

void Heavy_pdpoly::cCast_Nh7F4hj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5nDxVitF, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_5nDxVitF_sendMessage);
}

void Heavy_pdpoly::cSend_LUxjPQPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tj1hNtbj_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_I68P1Him_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_e8JTaShc, 1, m, &cVar_e8JTaShc_sendMessage);
}

void Heavy_pdpoly::cSend_53r99ba5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_wtKahcpc_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_vVIjSw4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_6qkVubI7, 0, m, &cPack_6qkVubI7_sendMessage);
}

void Heavy_pdpoly::cBinop_g5cElcbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_I68P1Him_sendMessage);
  cSend_53r99ba5_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::hTable_PB1TiHnc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::hTable_6HrXRLdl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::hTable_iIrw4Hkb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cCast_w87Sd1ul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vGDeezJK_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_wLyGVGjr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hy9tgdWD, 0, m, &cVar_hy9tgdWD_sendMessage);
}

void Heavy_pdpoly::cSend_KWxw0NA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_au7K5KYr_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_vGDeezJK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 65535.0f);
  cSend_KWxw0NA9_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_3mxAH1Z6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BGq5OxpX, 1, m, &cIf_BGq5OxpX_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_NCicpO0J_sendMessage);
}

void Heavy_pdpoly::cBinop_NCicpO0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KNj9yDYE, 1, m, &cIf_KNj9yDYE_sendMessage);
}

void Heavy_pdpoly::cBinop_XJ37vEIU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_LUxjPQPm_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cPack_6qkVubI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SiDMsFaq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSwitchcase_SiDMsFaq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_kWwtvJYH, 0, m, &cSlice_kWwtvJYH_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KX7xXttV, 0, m, &cSlice_KX7xXttV_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BvAuOD5v, 0, m, &cSlice_BvAuOD5v_sendMessage);
      break;
    }
    case 0x40800000: { // "4.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hZykDt61, 0, m, &cSlice_hZykDt61_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_kWwtvJYH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Zlm9nkMZ, 0, m, &cSlice_Zlm9nkMZ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_w5mLxSJs, 0, m, &cSlice_w5mLxSJs_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Zlm9nkMZ, 0, m, &cSlice_Zlm9nkMZ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_w5mLxSJs, 0, m, &cSlice_w5mLxSJs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_KX7xXttV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_EzB1y7lK, 0, m, &cSlice_EzB1y7lK_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_tFs2Zx1h, 0, m, &cSlice_tFs2Zx1h_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_EzB1y7lK, 0, m, &cSlice_EzB1y7lK_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_tFs2Zx1h, 0, m, &cSlice_tFs2Zx1h_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_BvAuOD5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_XsjS1ogV, 0, m, &cSlice_XsjS1ogV_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_8sXIBNnx, 0, m, &cSlice_8sXIBNnx_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_XsjS1ogV, 0, m, &cSlice_XsjS1ogV_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_8sXIBNnx, 0, m, &cSlice_8sXIBNnx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_hZykDt61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_7PX3LRAR, 0, m, &cSlice_7PX3LRAR_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_5xBX0WaZ, 0, m, &cSlice_5xBX0WaZ_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_7PX3LRAR, 0, m, &cSlice_7PX3LRAR_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_5xBX0WaZ, 0, m, &cSlice_5xBX0WaZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_Zlm9nkMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_XwtMFDuE_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_w5mLxSJs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_0LArIYVS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_qH9jS3Og_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_SqW7AWbe, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_6YQY51KM_sendMessage);
}

void Heavy_pdpoly::cBinop_0LArIYVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_jHVNmp6W_sendMessage);
}

void Heavy_pdpoly::cBinop_jHVNmp6W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6cxV3sJX, HV_BINOP_POW, 1, m, &cBinop_6cxV3sJX_sendMessage);
  cMsg_6TzGUsx2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_6cxV3sJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_qH9jS3Og_sendMessage);
}

void Heavy_pdpoly::cMsg_6TzGUsx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6cxV3sJX, HV_BINOP_POW, 0, m, &cBinop_6cxV3sJX_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_XwtMFDuE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y5lUIA5U_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_g4lIu6We_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_Y5lUIA5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w3BA9xdR_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_u4xMDAK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CBlFdbnp, HV_BINOP_MULTIPLY, 0, m, &cBinop_CBlFdbnp_sendMessage);
}

void Heavy_pdpoly::cMsg_6rks4Pbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EB2whDxm_sendMessage);
}

void Heavy_pdpoly::cSystem_EB2whDxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BrzB1Eru_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_CBlFdbnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Iy6S7Fw4_sendMessage);
}

void Heavy_pdpoly::cBinop_pUbwTZoy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CBlFdbnp, HV_BINOP_MULTIPLY, 1, m, &cBinop_CBlFdbnp_sendMessage);
}

void Heavy_pdpoly::cMsg_BrzB1Eru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_pUbwTZoy_sendMessage);
}

void Heavy_pdpoly::cBinop_Iy6S7Fw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_qh6Ynmuw_sendMessage);
}

void Heavy_pdpoly::cBinop_qh6Ynmuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_5Z32xSrn_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_HIcJSGjV, m);
}

void Heavy_pdpoly::cBinop_5Z32xSrn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wfm0jU9N, m);
}

void Heavy_pdpoly::cVar_kHuCy9gj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zrSqPJlQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_zrSqPJlQ_sendMessage);
}

void Heavy_pdpoly::cMsg_ZVKZYLmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fMUA6ggP_sendMessage);
}

void Heavy_pdpoly::cSystem_fMUA6ggP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8f0YUzvK_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_zrSqPJlQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_vlsYrRUm_sendMessage);
}

void Heavy_pdpoly::cBinop_unarZunb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zrSqPJlQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_zrSqPJlQ_sendMessage);
}

void Heavy_pdpoly::cMsg_8f0YUzvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_unarZunb_sendMessage);
}

void Heavy_pdpoly::cBinop_vlsYrRUm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_aH629IyN_sendMessage);
}

void Heavy_pdpoly::cBinop_aH629IyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_v2YtkKsc_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_5tsWAFFc, m);
}

void Heavy_pdpoly::cBinop_v2YtkKsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0S8IaT5Y, m);
}

void Heavy_pdpoly::cMsg_w3BA9xdR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8P6th3i4, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_g4lIu6We_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BEr5GN0r_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_BEr5GN0r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8P6th3i4, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_6YQY51KM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_4nNw5nL4, 0, m);
}

void Heavy_pdpoly::cSlice_EzB1y7lK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_Ol7EqhJB_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_tFs2Zx1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_76Xsg7gy_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_4izdzYw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_BbjCdVmN, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_qQcmALGw_sendMessage);
}

void Heavy_pdpoly::cBinop_76Xsg7gy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_GCo5zXRQ_sendMessage);
}

void Heavy_pdpoly::cBinop_GCo5zXRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xCoNHbVk, HV_BINOP_POW, 1, m, &cBinop_xCoNHbVk_sendMessage);
  cMsg_t6JSKJXE_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_xCoNHbVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_4izdzYw3_sendMessage);
}

void Heavy_pdpoly::cMsg_t6JSKJXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xCoNHbVk, HV_BINOP_POW, 0, m, &cBinop_xCoNHbVk_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_Ol7EqhJB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aF3j8MXm_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_ktknoTU5_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_aF3j8MXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5gWnZRiK_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_BQjVTuuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7YQKT7HA, HV_BINOP_MULTIPLY, 0, m, &cBinop_7YQKT7HA_sendMessage);
}

void Heavy_pdpoly::cMsg_jcdwvdJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qLXVjDyk_sendMessage);
}

void Heavy_pdpoly::cSystem_qLXVjDyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5f4hEYg0_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_7YQKT7HA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_xHcxzDaS_sendMessage);
}

void Heavy_pdpoly::cBinop_BRQ8TOiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7YQKT7HA, HV_BINOP_MULTIPLY, 1, m, &cBinop_7YQKT7HA_sendMessage);
}

void Heavy_pdpoly::cMsg_5f4hEYg0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_BRQ8TOiS_sendMessage);
}

void Heavy_pdpoly::cBinop_xHcxzDaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_aHgRBY6p_sendMessage);
}

void Heavy_pdpoly::cBinop_aHgRBY6p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_BmJQHda7_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Zg8c713D, m);
}

void Heavy_pdpoly::cBinop_BmJQHda7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gOOdoUtp, m);
}

void Heavy_pdpoly::cVar_8EibRl5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CjEKsvaV, HV_BINOP_MULTIPLY, 0, m, &cBinop_CjEKsvaV_sendMessage);
}

void Heavy_pdpoly::cMsg_5RFOt2q9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3IUUK6Ow_sendMessage);
}

void Heavy_pdpoly::cSystem_3IUUK6Ow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MR5RQe8L_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_CjEKsvaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zjMAYxkj_sendMessage);
}

void Heavy_pdpoly::cBinop_FuSabOFP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CjEKsvaV, HV_BINOP_MULTIPLY, 1, m, &cBinop_CjEKsvaV_sendMessage);
}

void Heavy_pdpoly::cMsg_MR5RQe8L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_FuSabOFP_sendMessage);
}

void Heavy_pdpoly::cBinop_zjMAYxkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ENaROrBQ_sendMessage);
}

void Heavy_pdpoly::cBinop_ENaROrBQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mICNHj47_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_KjdaOsMG, m);
}

void Heavy_pdpoly::cBinop_mICNHj47_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_k0gavGys, m);
}

void Heavy_pdpoly::cMsg_5gWnZRiK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_1aUhAbNv, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_ktknoTU5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0Hu5yO2v_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_0Hu5yO2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_1aUhAbNv, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_qQcmALGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_1IXgKU4O, 0, m);
}

void Heavy_pdpoly::cSlice_XsjS1ogV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_71vY15xb_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_8sXIBNnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_XjNHgq3k_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_Z9IdtDqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_vfX8Y5HI, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_G9M2VnTu_sendMessage);
}

void Heavy_pdpoly::cBinop_XjNHgq3k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_mQ3GJOaB_sendMessage);
}

void Heavy_pdpoly::cBinop_mQ3GJOaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FyNnV1xM, HV_BINOP_POW, 1, m, &cBinop_FyNnV1xM_sendMessage);
  cMsg_1kw1P2YA_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_FyNnV1xM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Z9IdtDqU_sendMessage);
}

void Heavy_pdpoly::cMsg_1kw1P2YA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FyNnV1xM, HV_BINOP_POW, 0, m, &cBinop_FyNnV1xM_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_71vY15xb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ukzrIBNZ_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_XB1TdK2t_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_ukzrIBNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RNTBAwFJ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_PyqC2pGm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6uwO0IwF, HV_BINOP_MULTIPLY, 0, m, &cBinop_6uwO0IwF_sendMessage);
}

void Heavy_pdpoly::cMsg_0LhgnskD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CHZDxGI8_sendMessage);
}

void Heavy_pdpoly::cSystem_CHZDxGI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uOPmr08T_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_6uwO0IwF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_4CPKfjNn_sendMessage);
}

void Heavy_pdpoly::cBinop_aCbcEvUa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6uwO0IwF, HV_BINOP_MULTIPLY, 1, m, &cBinop_6uwO0IwF_sendMessage);
}

void Heavy_pdpoly::cMsg_uOPmr08T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_aCbcEvUa_sendMessage);
}

void Heavy_pdpoly::cBinop_4CPKfjNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_uQholSbe_sendMessage);
}

void Heavy_pdpoly::cBinop_uQholSbe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TvXbe2Hl_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Hdgs13ZD, m);
}

void Heavy_pdpoly::cBinop_TvXbe2Hl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ggvTPpQQ, m);
}

void Heavy_pdpoly::cVar_G28VgPVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6QvQr8xv, HV_BINOP_MULTIPLY, 0, m, &cBinop_6QvQr8xv_sendMessage);
}

void Heavy_pdpoly::cMsg_tKiAR2jq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ojUZXRxG_sendMessage);
}

void Heavy_pdpoly::cSystem_ojUZXRxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VBCYUvnx_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_6QvQr8xv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_PbE78xkJ_sendMessage);
}

void Heavy_pdpoly::cBinop_HVxcMq1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6QvQr8xv, HV_BINOP_MULTIPLY, 1, m, &cBinop_6QvQr8xv_sendMessage);
}

void Heavy_pdpoly::cMsg_VBCYUvnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_HVxcMq1Z_sendMessage);
}

void Heavy_pdpoly::cBinop_PbE78xkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_U2LrC3Sl_sendMessage);
}

void Heavy_pdpoly::cBinop_U2LrC3Sl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_psX6usmu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_l3j495a5, m);
}

void Heavy_pdpoly::cBinop_psX6usmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DsXxYbcK, m);
}

void Heavy_pdpoly::cMsg_RNTBAwFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZFQzbsA8, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_XB1TdK2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LkQCADGM_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_LkQCADGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZFQzbsA8, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_G9M2VnTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_sWC0CnU2, 0, m);
}

void Heavy_pdpoly::cSlice_7PX3LRAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_g7ENg0FI_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_5xBX0WaZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_4rA3TarM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_TCUw6EGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_YyW6q9Ry, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_NE9SRDuU_sendMessage);
}

void Heavy_pdpoly::cBinop_4rA3TarM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_rJbAuzyf_sendMessage);
}

void Heavy_pdpoly::cBinop_rJbAuzyf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qdd6oi7w, HV_BINOP_POW, 1, m, &cBinop_Qdd6oi7w_sendMessage);
  cMsg_Ie69A4Xh_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_Qdd6oi7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_TCUw6EGH_sendMessage);
}

void Heavy_pdpoly::cMsg_Ie69A4Xh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qdd6oi7w, HV_BINOP_POW, 0, m, &cBinop_Qdd6oi7w_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_g7ENg0FI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GTPmMRiI_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_fLvMfHtI_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_GTPmMRiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_urMxidM3_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_2aHET9HK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q1sIePaf, HV_BINOP_MULTIPLY, 0, m, &cBinop_Q1sIePaf_sendMessage);
}

void Heavy_pdpoly::cMsg_NhggsIib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2sWVQU6a_sendMessage);
}

void Heavy_pdpoly::cSystem_2sWVQU6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GNdtweBJ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_Q1sIePaf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_S59dsmYC_sendMessage);
}

void Heavy_pdpoly::cBinop_1Mj8D17n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Q1sIePaf, HV_BINOP_MULTIPLY, 1, m, &cBinop_Q1sIePaf_sendMessage);
}

void Heavy_pdpoly::cMsg_GNdtweBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1Mj8D17n_sendMessage);
}

void Heavy_pdpoly::cBinop_S59dsmYC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MzsVK87Q_sendMessage);
}

void Heavy_pdpoly::cBinop_MzsVK87Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HQmPZ7Ss_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_UMZYZq1N, m);
}

void Heavy_pdpoly::cBinop_HQmPZ7Ss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jndwksQl, m);
}

void Heavy_pdpoly::cVar_4YYO6yLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dge6vSOr, HV_BINOP_MULTIPLY, 0, m, &cBinop_dge6vSOr_sendMessage);
}

void Heavy_pdpoly::cMsg_SUlkPvFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cvbLJ0kE_sendMessage);
}

void Heavy_pdpoly::cSystem_cvbLJ0kE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J9i7oFBE_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_dge6vSOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Gqzv1ELs_sendMessage);
}

void Heavy_pdpoly::cBinop_gIBTEvFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dge6vSOr, HV_BINOP_MULTIPLY, 1, m, &cBinop_dge6vSOr_sendMessage);
}

void Heavy_pdpoly::cMsg_J9i7oFBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_gIBTEvFT_sendMessage);
}

void Heavy_pdpoly::cBinop_Gqzv1ELs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_SUaTB3OA_sendMessage);
}

void Heavy_pdpoly::cBinop_SUaTB3OA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_iKQBo3C9_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_RE1AbFWj, m);
}

void Heavy_pdpoly::cBinop_iKQBo3C9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eOYmIxN3, m);
}

void Heavy_pdpoly::cMsg_urMxidM3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_em2G9Mmf, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_fLvMfHtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Bb1R1zGK_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_Bb1R1zGK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_em2G9Mmf, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_NE9SRDuU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_VNV5obt5, 0, m);
}

void Heavy_pdpoly::cSend_rmXFtwdH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_mfB46JF4_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cReceive_3jEqz6Kz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6rks4Pbl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_u4xMDAK8, 0, m, &cVar_u4xMDAK8_sendMessage);
  cMsg_ZVKZYLmV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kHuCy9gj, 0, m, &cVar_kHuCy9gj_sendMessage);
  cMsg_jcdwvdJ3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BQjVTuuL, 0, m, &cVar_BQjVTuuL_sendMessage);
  cMsg_5RFOt2q9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8EibRl5O, 0, m, &cVar_8EibRl5O_sendMessage);
  cMsg_0LhgnskD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PyqC2pGm, 0, m, &cVar_PyqC2pGm_sendMessage);
  cMsg_tKiAR2jq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_G28VgPVo, 0, m, &cVar_G28VgPVo_sendMessage);
  cMsg_NhggsIib_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2aHET9HK, 0, m, &cVar_2aHET9HK_sendMessage);
  cMsg_SUlkPvFL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4YYO6yLt, 0, m, &cVar_4YYO6yLt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_T5BxLOeY, 0, m, &cVar_T5BxLOeY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_w87Sd1ul_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wLyGVGjr_sendMessage);
}

void Heavy_pdpoly::cReceive_syMceADb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_xMqtCnnD, 0, m, &cSlice_xMqtCnnD_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_YjsgJzol, 0, m, &cSlice_YjsgJzol_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Y54Vv5DU, 0, m, &cSlice_Y54Vv5DU_sendMessage);
}

void Heavy_pdpoly::cReceive_tj1hNtbj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZVgeKaVI, 1, m, &cIf_ZVgeKaVI_sendMessage);
}

void Heavy_pdpoly::cReceive_wtKahcpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_61TaX9Ph, 1, m, &cVar_61TaX9Ph_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Nzgnz2UW, 1, m, &cVar_Nzgnz2UW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KMWOtRSG, 1, m, &cVar_KMWOtRSG_sendMessage);
}

void Heavy_pdpoly::cReceive_QlIJtYfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_e8JTaShc, 0, m, &cVar_e8JTaShc_sendMessage);
}

void Heavy_pdpoly::cReceive_au7K5KYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hykfdovi, 1, m, &cVar_hykfdovi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UJkjZ2xL, 1, m, &cVar_UJkjZ2xL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_g5cElcbi, HV_BINOP_MOD_UNIPOLAR, 1, m, &cBinop_g5cElcbi_sendMessage);
}

void Heavy_pdpoly::cReceive_SNHoxJH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_cQCI7vDb, 1, m, &cTabwrite_cQCI7vDb_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_EvR7BABV, 1, m, &cTabwrite_EvR7BABV_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_WqNZFRuG, 1, m, &cTabwrite_WqNZFRuG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1u7DN0hs, 1, m, &cVar_1u7DN0hs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KQR8kLlL, 1, m, &cVar_KQR8kLlL_sendMessage);
}

void Heavy_pdpoly::cReceive_9nMPxDw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jExgi6ax, 1, m, &cVar_jExgi6ax_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_D0EnNUiS, 1, m, &cTabwrite_D0EnNUiS_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_mICWqs1H, 1, m, &cTabwrite_mICWqs1H_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_c6hes3ci, 1, m, &cTabwrite_c6hes3ci_sendMessage);
}

void Heavy_pdpoly::cReceive_zEXM0ByL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UzKTKGpD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CuNGfZ9P_sendMessage);
}

void Heavy_pdpoly::cReceive_Sj13Wffc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Nh7F4hj1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3AnrHrFX_sendMessage);
}

void Heavy_pdpoly::cReceive_mfB46JF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_u4xMDAK8, 0, m, &cVar_u4xMDAK8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kHuCy9gj, 0, m, &cVar_kHuCy9gj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BQjVTuuL, 0, m, &cVar_BQjVTuuL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8EibRl5O, 0, m, &cVar_8EibRl5O_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PyqC2pGm, 0, m, &cVar_PyqC2pGm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_G28VgPVo, 0, m, &cVar_G28VgPVo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2aHET9HK, 0, m, &cVar_2aHET9HK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4YYO6yLt, 0, m, &cVar_4YYO6yLt_sendMessage);
}

void Heavy_pdpoly::cReceive_EgLHY3oJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_rmXFtwdH_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cReceive_Itwp0nm8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RRa8P1EL, m);
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
    __hv_phasor_k_f(&sPhasor_SqW7AWbe, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_4nNw5nL4, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_HIcJSGjV, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_wfm0jU9N, VOf(Bf2));
    __hv_rpole_f(&sRPole_R2OM5WNn, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_5tsWAFFc, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_0S8IaT5Y, VOf(Bf2));
    __hv_rpole_f(&sRPole_KSQtbukE, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_8P6th3i4, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_BbjCdVmN, VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_1IXgKU4O, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_Zg8c713D, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_gOOdoUtp, VOf(Bf3));
    __hv_rpole_f(&sRPole_7pJPPfd5, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_KjdaOsMG, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_k0gavGys, VOf(Bf3));
    __hv_rpole_f(&sRPole_y3UeZY7o, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_1aUhAbNv, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_vfX8Y5HI, VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_sWC0CnU2, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Hdgs13ZD, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_ggvTPpQQ, VOf(Bf2));
    __hv_rpole_f(&sRPole_lgzfhJOC, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_l3j495a5, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_DsXxYbcK, VOf(Bf2));
    __hv_rpole_f(&sRPole_fEw2tIme, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_ZFQzbsA8, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_YyW6q9Ry, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_VNV5obt5, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_UMZYZq1N, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_jndwksQl, VOf(Bf1));
    __hv_rpole_f(&sRPole_NuNVYY8F, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_RE1AbFWj, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_eOYmIxN3, VOf(Bf1));
    __hv_rpole_f(&sRPole_6TgGXVLb, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_em2G9Mmf, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_RRa8P1EL, VOf(Bf3));
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
