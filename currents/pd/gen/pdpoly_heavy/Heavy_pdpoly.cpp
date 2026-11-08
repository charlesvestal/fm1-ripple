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
  numBytes += sPhasor_k_init(&sPhasor_ZOZzDmTx, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_WaM3EAbS, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_tpBtjx5s);
  numBytes += sRPole_init(&sRPole_9de4vrgK);
  numBytes += sLine_init(&sLine_Ty0jmkKK);
  numBytes += sPhasor_k_init(&sPhasor_NAz5gPbt, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_NqR4dUUT, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_lHrqooKd);
  numBytes += sRPole_init(&sRPole_zRic5bp7);
  numBytes += sLine_init(&sLine_T18vNNH6);
  numBytes += sPhasor_k_init(&sPhasor_F5IRsyMT, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_IpoUzNo2, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_n9CZfL83);
  numBytes += sRPole_init(&sRPole_n8xc9Sts);
  numBytes += sLine_init(&sLine_eSoZbyoi);
  numBytes += sPhasor_k_init(&sPhasor_EJtSZUnJ, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_wM69hs6i, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_5v19PQB4);
  numBytes += sRPole_init(&sRPole_zSejl4Hc);
  numBytes += sLine_init(&sLine_wSBYyNor);
  numBytes += cSlice_init(&cSlice_RDnPx5YW, 2, 1);
  numBytes += cSlice_init(&cSlice_aoRCF4gj, 1, 1);
  numBytes += cSlice_init(&cSlice_itMwSL6a, 0, 1);
  numBytes += cVar_init_f(&cVar_atHJdUVA, 0.0f);
  numBytes += cIf_init(&cIf_YiJnyv3h, false);
  numBytes += cIf_init(&cIf_UfTkpaES, false);
  numBytes += cIf_init(&cIf_Ocycz2fX, false);
  numBytes += cIf_init(&cIf_ZvR0xLFI, false);
  numBytes += cIf_init(&cIf_ZMc0fLJr, false);
  numBytes += cBinop_init(&cBinop_7xnHAzrN, 0.0f); // __eq
  numBytes += cVar_init_f(&cVar_YYvTuJxq, 1.0f);
  numBytes += cVar_init_f(&cVar_shKozkoE, 0.0f);
  numBytes += cSlice_init(&cSlice_MkGjmLwm, 1, -1);
  numBytes += cSlice_init(&cSlice_txmBKPNe, 1, -1);
  numBytes += cSlice_init(&cSlice_thYgs6Tb, 1, 1);
  numBytes += cSlice_init(&cSlice_fxG4Utnv, 0, 1);
  numBytes += cVar_init_f(&cVar_Sx0vzwhL, 0.0f);
  numBytes += cIf_init(&cIf_9UoyO7vJ, false);
  numBytes += cIf_init(&cIf_ii9wt7Pw, false);
  numBytes += cIf_init(&cIf_01mpzKrI, false);
  numBytes += cVar_init_f(&cVar_YfEKDhga, 0.0f);
  numBytes += cIf_init(&cIf_mroAVBT9, false);
  numBytes += cVar_init_f(&cVar_CRNy7HHb, 0.0f);
  numBytes += cIf_init(&cIf_3y5FQoAz, false);
  numBytes += cBinop_init(&cBinop_wgLnvTgk, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_KACdI9GT, 4.0f);
  numBytes += cTabread_init(&cTabread_x3TXFnGt, &hTable_ZOjEP2YV); // 1011-used
  numBytes += cSlice_init(&cSlice_vghZhmfa, 1, -1);
  numBytes += cVar_init_s(&cVar_xpLLVhVY, "1011-used");
  numBytes += cBinop_init(&cBinop_gmzO4zdG, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_Lp6ESZwF, &hTable_WFqpxauu); // 1011-ids
  numBytes += cSlice_init(&cSlice_kVOzxulh, 1, -1);
  numBytes += cVar_init_s(&cVar_b4B2qv6b, "1011-ids");
  numBytes += cBinop_init(&cBinop_WMdCGkgb, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_WpSJRuP9, 0.0f);
  numBytes += cSlice_init(&cSlice_7OgLTk1V, 1, 1);
  numBytes += cSlice_init(&cSlice_HdX2yVla, 0, 1);
  numBytes += cTabread_init(&cTabread_8xrcGpSC, &hTable_2R00hG4y); // 1011-pitches
  numBytes += cSlice_init(&cSlice_f56sNuU3, 1, -1);
  numBytes += cVar_init_s(&cVar_JxOg5F5A, "1011-pitches");
  numBytes += cBinop_init(&cBinop_m9NFqV2v, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_Y2vRgeav, 0.0f);
  numBytes += cVar_init_f(&cVar_Z070eZZJ, 0.0f);
  numBytes += cIf_init(&cIf_FE71SD3i, false);
  numBytes += cTabwrite_init(&cTabwrite_uHXTxI1G, &hTable_ZOjEP2YV); // 1011-used
  numBytes += cSlice_init(&cSlice_KIdBJaET, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_jx30yT3g, &hTable_WFqpxauu); // 1011-ids
  numBytes += cSlice_init(&cSlice_vQnVJahU, 1, -1);
  numBytes += cVar_init_f(&cVar_TNnql8ws, 0.0f);
  numBytes += cVar_init_f(&cVar_qrmGLNEZ, 0.0f);
  numBytes += cSlice_init(&cSlice_6bKR5z2x, 1, 1);
  numBytes += cSlice_init(&cSlice_KZQ7edgb, 0, 1);
  numBytes += cPack_init(&cPack_14xjIdlo, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_WlD4ZWWD, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_vpgAOvcO, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_gzZG5qx4, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_qpwOk7L4, 0.0f); // __lt
  numBytes += cIf_init(&cIf_sYhcK7sf, false);
  numBytes += cVar_init_f(&cVar_uYIWa7AR, 0.0f);
  numBytes += cIf_init(&cIf_WxKV3Wxv, false);
  numBytes += cVar_init_f(&cVar_Md5r0T7T, 0.0f);
  numBytes += cIf_init(&cIf_1fNqQ3x8, false);
  numBytes += cBinop_init(&cBinop_7RfUeHrA, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_JS8cj4Oy, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_z27JHxSi, &hTable_ZOjEP2YV); // 1011-used
  numBytes += cSlice_init(&cSlice_TgoJ3fRq, 1, -1);
  numBytes += cTabread_init(&cTabread_R3zfFFhz, &hTable_ZOjEP2YV); // 1011-used
  numBytes += cSlice_init(&cSlice_K8Bi2tlb, 1, -1);
  numBytes += cVar_init_s(&cVar_shh7TkcQ, "1011-used");
  numBytes += cBinop_init(&cBinop_HAmBHl9N, 0.0f); // __min
  numBytes += cIf_init(&cIf_ZmPINRzj, false);
  numBytes += cTabread_init(&cTabread_hkPBoklh, &hTable_2R00hG4y); // 1011-pitches
  numBytes += cSlice_init(&cSlice_luqdwBb6, 1, -1);
  numBytes += cVar_init_s(&cVar_8mHV5l5F, "1011-pitches");
  numBytes += cBinop_init(&cBinop_NhzGdYoF, 0.0f); // __min
  numBytes += cIf_init(&cIf_VLf0FPbP, false);
  numBytes += cVar_init_f(&cVar_9gNvYS7y, 0.0f);
  numBytes += cIf_init(&cIf_xsJ89HwY, false);
  numBytes += cVar_init_f(&cVar_opOdIECq, 0.0f);
  numBytes += cIf_init(&cIf_zsXecSKe, false);
  numBytes += cBinop_init(&cBinop_OlmObO45, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_vlJ8TygL, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_TeehkMxc, &hTable_ZOjEP2YV); // 1011-used
  numBytes += cSlice_init(&cSlice_ZWOz090j, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_fsTT8mMt, &hTable_WFqpxauu); // 1011-ids
  numBytes += cSlice_init(&cSlice_2MOFWxz6, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_8N1iseQm, &hTable_2R00hG4y); // 1011-pitches
  numBytes += cSlice_init(&cSlice_hH8KRYtM, 1, -1);
  numBytes += cIf_init(&cIf_0eAlUVXJ, false);
  numBytes += cVar_init_f(&cVar_vklKFdgc, 0.0f);
  numBytes += cIf_init(&cIf_hFfBJxYU, false);
  numBytes += cVar_init_f(&cVar_40UKmqGZ, 0.0f);
  numBytes += cIf_init(&cIf_ZS29qAGq, false);
  numBytes += cBinop_init(&cBinop_PKBPkeL4, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_YnvM1fAh, 4.0f);
  numBytes += cVar_init_f(&cVar_mhE3YoWH, 0.0f);
  numBytes += cIf_init(&cIf_fIFb4kRA, false);
  numBytes += cVar_init_f(&cVar_QSzY4L1d, 0.0f);
  numBytes += cVar_init_f(&cVar_ZI9sDIc4, 0.0f);
  numBytes += cVar_init_f(&cVar_ADRio44E, 0.0f);
  numBytes += cIf_init(&cIf_iDOVnkov, false);
  numBytes += cIf_init(&cIf_pmtF54Rm, false);
  numBytes += cPack_init(&cPack_2obG09kK, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_mCFP2oFP, 0.0f);
  numBytes += cSlice_init(&cSlice_S2Ep7BzN, 1, 1);
  numBytes += cSlice_init(&cSlice_0w0Tfart, 0, 1);
  numBytes += cVar_init_f(&cVar_AzAjOQV2, 0.0f);
  numBytes += cIf_init(&cIf_MQ0fwAWH, false);
  numBytes += cVar_init_f(&cVar_7jZVlfqS, 0.0f);
  numBytes += cVar_init_f(&cVar_zupn0q8O, 0.0f);
  numBytes += cTabread_init(&cTabread_foz53Hzi, &hTable_ZOjEP2YV); // 1011-used
  numBytes += cSlice_init(&cSlice_Hpe4Xyl6, 1, -1);
  numBytes += cVar_init_s(&cVar_x9IxniLq, "1011-used");
  numBytes += cBinop_init(&cBinop_HdmyvDQK, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_msQ7SsdS, &hTable_WFqpxauu); // 1011-ids
  numBytes += cSlice_init(&cSlice_fZ1ILJlK, 1, -1);
  numBytes += cVar_init_s(&cVar_8WfMc5YK, "1011-ids");
  numBytes += cBinop_init(&cBinop_Wbx5fglh, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_UJL2WKSE, &hTable_2R00hG4y); // 1011-pitches
  numBytes += cSlice_init(&cSlice_zya4VDMx, 1, -1);
  numBytes += cTabread_init(&cTabread_2Kb6Td91, &hTable_2R00hG4y); // 1011-pitches
  numBytes += cSlice_init(&cSlice_HjJzJDwf, 1, -1);
  numBytes += cVar_init_s(&cVar_2EEhh3YX, "1011-pitches");
  numBytes += cBinop_init(&cBinop_FmvvvC77, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_PMaPrMVI, &hTable_2R00hG4y); // 1011-pitches
  numBytes += cSlice_init(&cSlice_ZYGxrtgq, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_3U82r7b3, &hTable_ZOjEP2YV); // 1011-used
  numBytes += cSlice_init(&cSlice_xdZ0aKBt, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_jMBXhJE1, &hTable_WFqpxauu); // 1011-ids
  numBytes += cSlice_init(&cSlice_Crg4GN1M, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_0HC5abm9, &hTable_WFqpxauu); // 1011-ids
  numBytes += cSlice_init(&cSlice_ltrdISlC, 1, -1);
  numBytes += cVar_init_f(&cVar_mpIm5Q3w, 0.0f);
  numBytes += cTabwrite_init(&cTabwrite_aWdUPGHv, &hTable_ZOjEP2YV); // 1011-used
  numBytes += cSlice_init(&cSlice_AeqLNz64, 1, -1);
  numBytes += cVar_init_f(&cVar_6HQ7mFRv, 0.0f);
  numBytes += cSlice_init(&cSlice_cbHdEfnO, 1, 1);
  numBytes += cSlice_init(&cSlice_lzfhWgdA, 0, 1);
  numBytes += cVar_init_f(&cVar_7ojIMy5Y, 0.0f);
  numBytes += cBinop_init(&cBinop_Wj8JVjDE, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_03pCmUD5, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_0VvM9QCV, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_5eK67iwN, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_IcSJ2ase, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_dcZcguYH, 65535.0f); // __unimod
  numBytes += hTable_init(&hTable_2R00hG4y, 4);
  numBytes += hTable_init(&hTable_ZOjEP2YV, 4);
  numBytes += hTable_init(&hTable_WFqpxauu, 4);
  numBytes += cPack_init(&cPack_GSMd5pB2, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_2iJRL3Ou, 1, -1);
  numBytes += cSlice_init(&cSlice_l0024PwI, 1, -1);
  numBytes += cSlice_init(&cSlice_mI0e8Cic, 1, -1);
  numBytes += cSlice_init(&cSlice_vfnCSAYZ, 1, -1);
  numBytes += cSlice_init(&cSlice_Px6AWHZl, 1, 1);
  numBytes += cSlice_init(&cSlice_3s846F1P, 0, 1);
  numBytes += cBinop_init(&cBinop_EWo0lYZi, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_0MSeXxQN, 22050.0f);
  numBytes += cBinop_init(&cBinop_jmPtYr4C, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ak33qfDJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NOGXLkMo, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_4XMUFZIR, 22050.0f);
  numBytes += cBinop_init(&cBinop_sRU52o2w, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_fyLhG6WL, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Yhbwgzk4, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_488bPkdV, 1, 1);
  numBytes += cSlice_init(&cSlice_oE6TidP5, 0, 1);
  numBytes += cBinop_init(&cBinop_20BrF21b, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_CwgnP55l, 22050.0f);
  numBytes += cBinop_init(&cBinop_2Vb6OYqY, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_My7xwkdE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OXp11SEl, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_914SdQkF, 22050.0f);
  numBytes += cBinop_init(&cBinop_AEd4ZR10, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_PlTU9cYa, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1HJxQXeX, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_FUrzZvun, 1, 1);
  numBytes += cSlice_init(&cSlice_2RMOtAil, 0, 1);
  numBytes += cBinop_init(&cBinop_806FaMvZ, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_pPO2LSge, 22050.0f);
  numBytes += cBinop_init(&cBinop_sLbt2hBN, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_6Lrt8Kv9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_DpIfNdz0, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_cHbZkICZ, 22050.0f);
  numBytes += cBinop_init(&cBinop_Tx7fbUKl, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_PUp7RWup, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_h45QRLBH, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_WAjGlulW, 1, 1);
  numBytes += cSlice_init(&cSlice_hMwsxfHO, 0, 1);
  numBytes += cBinop_init(&cBinop_1h7hT8Fa, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_7dkiillj, 22050.0f);
  numBytes += cBinop_init(&cBinop_YCcDWx7G, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_qqhC334x, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fB4jXMxD, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Ex9WqsGC, 22050.0f);
  numBytes += cBinop_init(&cBinop_eQtLuKHc, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_2WHHaEGT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HOmA5spJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dna7pG92, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_pdpoly::~Heavy_pdpoly() {
  cPack_free(&cPack_14xjIdlo);
  cPack_free(&cPack_2obG09kK);
  hTable_free(&hTable_2R00hG4y);
  hTable_free(&hTable_ZOjEP2YV);
  hTable_free(&hTable_WFqpxauu);
  cPack_free(&cPack_GSMd5pB2);
}

HvTable *Heavy_pdpoly::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x7B847FB6: return &hTable_2R00hG4y; // 1011-pitches
    case 0xA0EFCB1D: return &hTable_ZOjEP2YV; // 1011-used
    case 0x73137BF4: return &hTable_WFqpxauu; // 1011-ids
    default: return nullptr;
  }
}

void Heavy_pdpoly::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x7EA4AD17: { // 1011-currentVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NrH1G6pg_sendMessage);
      break;
    }
    case 0x9B1DF8F3: { // 1011-indexOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_S7mnQCBs_sendMessage);
      break;
    }
    case 0xF7855D22: { // 1011-indexOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_9EHRLrqK_sendMessage);
      break;
    }
    case 0xEB1BA925: { // 1011-isFirstOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bpN4Wtfh_sendMessage);
      break;
    }
    case 0x7426D59: { // 1011-isFirstOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YeZydjIf_sendMessage);
      break;
    }
    case 0x199E738B: { // 1011-maxVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EPSsyBF2_sendMessage);
      break;
    }
    case 0x979E98C4: { // 1011-shouldSteal
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EgTWGg6Q_sendMessage);
      break;
    }
    case 0xDB67A714: { // 1011-voiceId++
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_02n3iKi2_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7ajL75ej_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Dju0yEP0_sendMessage);
      break;
    }
    case 0xF89F9F3E: { // cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wWPjApNu_sendMessage);
      break;
    }
    case 0xC2C62B6: { // vcut
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Hi9PKeor_sendMessage);
      break;
    }
    case 0xB1642755: { // volume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ARa3n9mv_sendMessage);
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


void Heavy_pdpoly::cSlice_RDnPx5YW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_6s7EAE7a_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_aoRCF4gj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_ZvR0xLFI, 0, m, &cIf_ZvR0xLFI_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_UfTkpaES, 0, m, &cIf_UfTkpaES_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_itMwSL6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_ZMc0fLJr, 0, m, &cIf_ZMc0fLJr_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_Ocycz2fX, 0, m, &cIf_Ocycz2fX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_atHJdUVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Gv2ENbkl_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_YiJnyv3h, 0, m, &cIf_YiJnyv3h_sendMessage);
}

void Heavy_pdpoly::cUnop_6Pzim5TR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_wmrBehNI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7xnHAzrN, HV_BINOP_EQ, 1, m, &cBinop_7xnHAzrN_sendMessage);
}

void Heavy_pdpoly::cUnop_v0vvJT2P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_wmrBehNI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7xnHAzrN, HV_BINOP_EQ, 1, m, &cBinop_7xnHAzrN_sendMessage);
}

void Heavy_pdpoly::cIf_YiJnyv3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_v0vvJT2P_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_6Pzim5TR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_Gv2ENbkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YiJnyv3h, 1, m, &cIf_YiJnyv3h_sendMessage);
}

void Heavy_pdpoly::cIf_UfTkpaES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_Sx0vzwhL, 0, m, &cVar_Sx0vzwhL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_Ocycz2fX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_jyO4HOJX_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_ZvR0xLFI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_Sx0vzwhL, 0, m, &cVar_Sx0vzwhL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_ZMc0fLJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_jyO4HOJX_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_6s7EAE7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7xnHAzrN, HV_BINOP_EQ, 0, m, &cBinop_7xnHAzrN_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_dc2vjPgh_sendMessage);
}

void Heavy_pdpoly::cBinop_wmrBehNI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_v3XGmjMe_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KCSjn4VO_sendMessage);
}

void Heavy_pdpoly::cBinop_7xnHAzrN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WXP4U1Wy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kRQ1TXxk_sendMessage);
}

void Heavy_pdpoly::cCast_WXP4U1Wy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UfTkpaES, 1, m, &cIf_UfTkpaES_sendMessage);
}

void Heavy_pdpoly::cCast_kRQ1TXxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZMc0fLJr, 1, m, &cIf_ZMc0fLJr_sendMessage);
}

void Heavy_pdpoly::cCast_v3XGmjMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZvR0xLFI, 1, m, &cIf_ZvR0xLFI_sendMessage);
}

void Heavy_pdpoly::cCast_KCSjn4VO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Ocycz2fX, 1, m, &cIf_Ocycz2fX_sendMessage);
}

void Heavy_pdpoly::cBinop_dc2vjPgh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cVar_YYvTuJxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_MbBXutYi_sendMessage);
}

void Heavy_pdpoly::cVar_shKozkoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dcZcguYH, HV_BINOP_MOD_UNIPOLAR, 0, m, &cBinop_dcZcguYH_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_jyO4HOJX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MkGjmLwm, 0, m, &cSlice_MkGjmLwm_sendMessage);
      break;
    }
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_txmBKPNe, 0, m, &cSlice_txmBKPNe_sendMessage);
      break;
    }
    default: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_thYgs6Tb, 0, m, &cSlice_thYgs6Tb_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fxG4Utnv, 0, m, &cSlice_fxG4Utnv_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_MkGjmLwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TtSuoG9U_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_16SdAzsL_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TtSuoG9U_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_16SdAzsL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_txmBKPNe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QFZLgRM2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BQlcHCEP_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QFZLgRM2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BQlcHCEP_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_thYgs6Tb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_Sx0vzwhL, 0, m, &cVar_Sx0vzwhL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_fxG4Utnv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_9UoyO7vJ, 0, m, &cIf_9UoyO7vJ_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_ii9wt7Pw, 0, m, &cIf_ii9wt7Pw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_Sx0vzwhL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2obG09kK, 1, m, &cPack_2obG09kK_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_14xjIdlo, 1, m, &cPack_14xjIdlo_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ScKudNoI_sendMessage);
}

void Heavy_pdpoly::cIf_9UoyO7vJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DI4xfV6R_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pm9VULLU_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MFa12vW2_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_2obG09kK, 0, m, &cPack_2obG09kK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_ii9wt7Pw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_14xjIdlo, 0, m, &cPack_14xjIdlo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_01mpzKrI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pOtipIyq_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4goX1oLL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_YfEKDhga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uukt3xvd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OTvSKqXK_sendMessage);
}

void Heavy_pdpoly::cIf_mroAVBT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kDRdXzIN_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hF9hXJwj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_wDgEYUn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_mroAVBT9, 1, m, &cIf_mroAVBT9_sendMessage);
}

void Heavy_pdpoly::cVar_CRNy7HHb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_yAUCo0NJ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_3y5FQoAz, 0, m, &cIf_3y5FQoAz_sendMessage);
}

void Heavy_pdpoly::cUnop_2y0trnbM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_wDgEYUn2_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_mroAVBT9, 0, m, &cIf_mroAVBT9_sendMessage);
}

void Heavy_pdpoly::cUnop_otQE8GPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_wDgEYUn2_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_mroAVBT9, 0, m, &cIf_mroAVBT9_sendMessage);
}

void Heavy_pdpoly::cIf_3y5FQoAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_otQE8GPD_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2y0trnbM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_yAUCo0NJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3y5FQoAz, 1, m, &cIf_3y5FQoAz_sendMessage);
}

void Heavy_pdpoly::cCast_OTvSKqXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_01mpzKrI, 0, m, &cIf_01mpzKrI_sendMessage);
}

void Heavy_pdpoly::cCast_uukt3xvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wgLnvTgk, HV_BINOP_LESS_THAN, 0, m, &cBinop_wgLnvTgk_sendMessage);
}

void Heavy_pdpoly::cBinop_wgLnvTgk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_01mpzKrI, 1, m, &cIf_01mpzKrI_sendMessage);
}

void Heavy_pdpoly::cCast_hF9hXJwj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j9z1VIL2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_kDRdXzIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wgLnvTgk, HV_BINOP_LESS_THAN, 1, m, &cBinop_wgLnvTgk_sendMessage);
}

void Heavy_pdpoly::cBinop_GeJdkIUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YfEKDhga, 0, m, &cVar_YfEKDhga_sendMessage);
}

void Heavy_pdpoly::cMsg_j9z1VIL2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_YfEKDhga, 0, m, &cVar_YfEKDhga_sendMessage);
}

void Heavy_pdpoly::cCast_4goX1oLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_GeJdkIUR_sendMessage);
}

void Heavy_pdpoly::cCast_pOtipIyq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HeKFjE0V_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KulBZF3Z_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TqncNe4P_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CJbTGuiQ_sendMessage);
}

void Heavy_pdpoly::cVar_KACdI9GT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CRNy7HHb, 0, m, &cVar_CRNy7HHb_sendMessage);
}

void Heavy_pdpoly::cTabread_x3TXFnGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gzZG5qx4, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_gzZG5qx4_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_d66WJWGJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vghZhmfa, 0, m, &cSlice_vghZhmfa_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mHuqRYG5_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iV0vx5b4_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_vghZhmfa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_x3TXFnGt, 1, m, &cTabread_x3TXFnGt_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_x3TXFnGt, 1, m, &cTabread_x3TXFnGt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_xpLLVhVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KJS5zmS1_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_2JYG9dwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HokL9Ypi_sendMessage);
}

void Heavy_pdpoly::cBinop_F2PK4o5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gmzO4zdG, HV_BINOP_MIN, 0, m, &cBinop_gmzO4zdG_sendMessage);
}

void Heavy_pdpoly::cCast_iV0vx5b4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_F2PK4o5l_sendMessage);
}

void Heavy_pdpoly::cCast_mHuqRYG5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xpLLVhVY, 0, m, &cVar_xpLLVhVY_sendMessage);
}

void Heavy_pdpoly::cBinop_gmzO4zdG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_x3TXFnGt, 0, m, &cTabread_x3TXFnGt_sendMessage);
}

void Heavy_pdpoly::cMsg_KJS5zmS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2JYG9dwM_sendMessage);
}

void Heavy_pdpoly::cBinop_HokL9Ypi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gmzO4zdG, HV_BINOP_MIN, 1, m, &cBinop_gmzO4zdG_sendMessage);
}

void Heavy_pdpoly::cTabread_Lp6ESZwF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qW5U1hMl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mdFujYn1_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_GsgZ6tIw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_kVOzxulh, 0, m, &cSlice_kVOzxulh_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TRF3wiAR_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yvmd07Mp_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_kVOzxulh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_Lp6ESZwF, 1, m, &cTabread_Lp6ESZwF_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_Lp6ESZwF, 1, m, &cTabread_Lp6ESZwF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_b4B2qv6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ztJMYp2O_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_GB9nOcQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_U9mnqIFF_sendMessage);
}

void Heavy_pdpoly::cBinop_0KK0gKCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WMdCGkgb, HV_BINOP_MIN, 0, m, &cBinop_WMdCGkgb_sendMessage);
}

void Heavy_pdpoly::cCast_TRF3wiAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_b4B2qv6b, 0, m, &cVar_b4B2qv6b_sendMessage);
}

void Heavy_pdpoly::cCast_yvmd07Mp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0KK0gKCr_sendMessage);
}

void Heavy_pdpoly::cBinop_WMdCGkgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_Lp6ESZwF, 0, m, &cTabread_Lp6ESZwF_sendMessage);
}

void Heavy_pdpoly::cMsg_ztJMYp2O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GB9nOcQW_sendMessage);
}

void Heavy_pdpoly::cBinop_U9mnqIFF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WMdCGkgb, HV_BINOP_MIN, 1, m, &cBinop_WMdCGkgb_sendMessage);
}

void Heavy_pdpoly::cVar_WpSJRuP9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_uHXTxI1G, 1, m, &cTabwrite_uHXTxI1G_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jx30yT3g, 1, m, &cTabwrite_jx30yT3g_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qrmGLNEZ, 1, m, &cVar_qrmGLNEZ_sendMessage);
}

void Heavy_pdpoly::cSlice_7OgLTk1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_pdpoly::cSlice_HdX2yVla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PwcubG3t_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DbtVX8On_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_8xrcGpSC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WlD4ZWWD, HV_BINOP_EQ, 0, m, &cBinop_WlD4ZWWD_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_ProiyJ0k_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_f56sNuU3, 0, m, &cSlice_f56sNuU3_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GRf4jqFS_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WudO5cRA_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_f56sNuU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_8xrcGpSC, 1, m, &cTabread_8xrcGpSC_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_8xrcGpSC, 1, m, &cTabread_8xrcGpSC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_JxOg5F5A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Lg21MrzQ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_C7CJKfmr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_iTwLPy14_sendMessage);
}

void Heavy_pdpoly::cBinop_JDOSSFkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m9NFqV2v, HV_BINOP_MIN, 0, m, &cBinop_m9NFqV2v_sendMessage);
}

void Heavy_pdpoly::cCast_GRf4jqFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JxOg5F5A, 0, m, &cVar_JxOg5F5A_sendMessage);
}

void Heavy_pdpoly::cCast_WudO5cRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_JDOSSFkH_sendMessage);
}

void Heavy_pdpoly::cBinop_m9NFqV2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_8xrcGpSC, 0, m, &cTabread_8xrcGpSC_sendMessage);
}

void Heavy_pdpoly::cMsg_Lg21MrzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_C7CJKfmr_sendMessage);
}

void Heavy_pdpoly::cBinop_iTwLPy14_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m9NFqV2v, HV_BINOP_MIN, 1, m, &cBinop_m9NFqV2v_sendMessage);
}

void Heavy_pdpoly::cVar_Y2vRgeav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qpwOk7L4, HV_BINOP_LESS_THAN, 1, m, &cBinop_qpwOk7L4_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_u6jSmhE6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i1OTbwMo_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_i1OTbwMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G8dZ6sEM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CjVqKFZ2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pIhpFR2L_sendMessage);
}

void Heavy_pdpoly::cVar_Z070eZZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qpwOk7L4, HV_BINOP_LESS_THAN, 1, m, &cBinop_qpwOk7L4_sendMessage);
}

void Heavy_pdpoly::cIf_FE71SD3i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aroNcydc_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JGjnwP0N_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LLXqV1f4_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_6bKR5z2x, 0, m, &cSlice_6bKR5z2x_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_KZQ7edgb, 0, m, &cSlice_KZQ7edgb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_78cEMSUr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_uHXTxI1G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_IvxB9oQL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KIdBJaET, 0, m, &cSlice_KIdBJaET_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_uHXTxI1G, 0, m, &cTabwrite_uHXTxI1G_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_KIdBJaET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_uHXTxI1G, 2, m, &cTabwrite_uHXTxI1G_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_uHXTxI1G, 2, m, &cTabwrite_uHXTxI1G_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_jx30yT3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_xmKtkd6f_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vQnVJahU, 0, m, &cSlice_vQnVJahU_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jx30yT3g, 0, m, &cTabwrite_jx30yT3g_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_vQnVJahU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jx30yT3g, 2, m, &cTabwrite_jx30yT3g_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jx30yT3g, 2, m, &cTabwrite_jx30yT3g_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_TNnql8ws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xmKtkd6f_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cVar_qrmGLNEZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_GWKfs9vR_sendMessage);
}

void Heavy_pdpoly::cSlice_6bKR5z2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_pdpoly::cSlice_KZQ7edgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_GSMd5pB2, 1, m, &cPack_GSMd5pB2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cPack_14xjIdlo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_njqOpH7j_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jFPVTRjG_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_7OgLTk1V, 0, m, &cSlice_7OgLTk1V_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_HdX2yVla, 0, m, &cSlice_HdX2yVla_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_FE71SD3i, 0, m, &cIf_FE71SD3i_sendMessage);
}

void Heavy_pdpoly::cCast_TqncNe4P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_d66WJWGJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_CJbTGuiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ProiyJ0k_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_HeKFjE0V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WpSJRuP9, 1, m, &cVar_WpSJRuP9_sendMessage);
}

void Heavy_pdpoly::cCast_KulBZF3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GsgZ6tIw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_p2klCPIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_FE71SD3i, 1, m, &cIf_FE71SD3i_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WpSJRuP9, 0, m, &cVar_WpSJRuP9_sendMessage);
}

void Heavy_pdpoly::cMsg_UL8RQeJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_FE71SD3i, 1, m, &cIf_FE71SD3i_sendMessage);
}

void Heavy_pdpoly::cCast_jFPVTRjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p2klCPIy_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_njqOpH7j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y2vRgeav, 0, m, &cVar_Y2vRgeav_sendMessage);
}

void Heavy_pdpoly::cCast_PwcubG3t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WlD4ZWWD, HV_BINOP_EQ, 1, m, &cBinop_WlD4ZWWD_sendMessage);
}

void Heavy_pdpoly::cCast_DbtVX8On_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KACdI9GT, 0, m, &cVar_KACdI9GT_sendMessage);
}

void Heavy_pdpoly::cBinop_WlD4ZWWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vpgAOvcO, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_vpgAOvcO_sendMessage);
}

void Heavy_pdpoly::cBinop_vpgAOvcO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_u6jSmhE6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_gzZG5qx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vpgAOvcO, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_vpgAOvcO_sendMessage);
}

void Heavy_pdpoly::cBinop_qpwOk7L4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gzZG5qx4, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_gzZG5qx4_sendMessage);
}

void Heavy_pdpoly::cCast_G8dZ6sEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z070eZZJ, 0, m, &cVar_Z070eZZJ_sendMessage);
}

void Heavy_pdpoly::cCast_CjVqKFZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UL8RQeJ9_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_pIhpFR2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WpSJRuP9, 0, m, &cVar_WpSJRuP9_sendMessage);
}

void Heavy_pdpoly::cCast_qW5U1hMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z070eZZJ, 1, m, &cVar_Z070eZZJ_sendMessage);
}

void Heavy_pdpoly::cCast_mdFujYn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qpwOk7L4, HV_BINOP_LESS_THAN, 0, m, &cBinop_qpwOk7L4_sendMessage);
}

void Heavy_pdpoly::cCast_sIVJda84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_fxYAEKjt_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_P50Zbn7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TNnql8ws, 0, m, &cVar_TNnql8ws_sendMessage);
}

void Heavy_pdpoly::cSend_fxYAEKjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_02n3iKi2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_JGjnwP0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sIVJda84_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P50Zbn7Z_sendMessage);
}

void Heavy_pdpoly::cCast_aroNcydc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RScHtjXJ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_RScHtjXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_IvxB9oQL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_LLXqV1f4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zSHL59eH_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_78cEMSUr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qrmGLNEZ, 0, m, &cVar_qrmGLNEZ_sendMessage);
}

void Heavy_pdpoly::cMsg_zSHL59eH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_GSMd5pB2, 2, m, &cPack_GSMd5pB2_sendMessage);
}

void Heavy_pdpoly::cIf_sYhcK7sf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ircjcTZ5_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vkmlYGbL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_uYIWa7AR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OjNfLaAQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_INAZbIOy_sendMessage);
}

void Heavy_pdpoly::cIf_WxKV3Wxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Cw8cEKcR_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_s1b69ODH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_WLQvJjiK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WxKV3Wxv, 1, m, &cIf_WxKV3Wxv_sendMessage);
}

void Heavy_pdpoly::cVar_Md5r0T7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_KGuT9G5k_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_1fNqQ3x8, 0, m, &cIf_1fNqQ3x8_sendMessage);
}

void Heavy_pdpoly::cUnop_4FeZLTdI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_WLQvJjiK_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_WxKV3Wxv, 0, m, &cIf_WxKV3Wxv_sendMessage);
}

void Heavy_pdpoly::cUnop_XApbN3qP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_WLQvJjiK_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_WxKV3Wxv, 0, m, &cIf_WxKV3Wxv_sendMessage);
}

void Heavy_pdpoly::cIf_1fNqQ3x8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_XApbN3qP_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_4FeZLTdI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_KGuT9G5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1fNqQ3x8, 1, m, &cIf_1fNqQ3x8_sendMessage);
}

void Heavy_pdpoly::cCast_OjNfLaAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7RfUeHrA, HV_BINOP_LESS_THAN, 0, m, &cBinop_7RfUeHrA_sendMessage);
}

void Heavy_pdpoly::cCast_INAZbIOy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sYhcK7sf, 0, m, &cIf_sYhcK7sf_sendMessage);
}

void Heavy_pdpoly::cBinop_7RfUeHrA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sYhcK7sf, 1, m, &cIf_sYhcK7sf_sendMessage);
}

void Heavy_pdpoly::cCast_Cw8cEKcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7RfUeHrA, HV_BINOP_LESS_THAN, 1, m, &cBinop_7RfUeHrA_sendMessage);
}

void Heavy_pdpoly::cCast_s1b69ODH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GxuPBDN9_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_b0HgylSX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uYIWa7AR, 0, m, &cVar_uYIWa7AR_sendMessage);
}

void Heavy_pdpoly::cMsg_GxuPBDN9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_uYIWa7AR, 0, m, &cVar_uYIWa7AR_sendMessage);
}

void Heavy_pdpoly::cCast_vkmlYGbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_b0HgylSX_sendMessage);
}

void Heavy_pdpoly::cCast_ircjcTZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7UFT6tXB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CTeH3hG3_sendMessage);
}

void Heavy_pdpoly::cVar_JS8cj4Oy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Md5r0T7T, 0, m, &cVar_Md5r0T7T_sendMessage);
}

void Heavy_pdpoly::cTabwrite_z27JHxSi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_qo6ZWNb9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TgoJ3fRq, 0, m, &cSlice_TgoJ3fRq_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_z27JHxSi, 0, m, &cTabwrite_z27JHxSi_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_TgoJ3fRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_z27JHxSi, 2, m, &cTabwrite_z27JHxSi_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_z27JHxSi, 2, m, &cTabwrite_z27JHxSi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_R3zfFFhz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_LXTLAO4e_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_TGm7AKRK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_K8Bi2tlb, 0, m, &cSlice_K8Bi2tlb_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GXEf4jcI_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZhGM51nx_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_K8Bi2tlb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_R3zfFFhz, 1, m, &cTabread_R3zfFFhz_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_R3zfFFhz, 1, m, &cTabread_R3zfFFhz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_shh7TkcQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_shG5wg34_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_x8eOvz8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_vHBrzn9n_sendMessage);
}

void Heavy_pdpoly::cBinop_bq73EePE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HAmBHl9N, HV_BINOP_MIN, 0, m, &cBinop_HAmBHl9N_sendMessage);
}

void Heavy_pdpoly::cCast_ZhGM51nx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_bq73EePE_sendMessage);
}

void Heavy_pdpoly::cCast_GXEf4jcI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_shh7TkcQ, 0, m, &cVar_shh7TkcQ_sendMessage);
}

void Heavy_pdpoly::cBinop_HAmBHl9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_R3zfFFhz, 0, m, &cTabread_R3zfFFhz_sendMessage);
}

void Heavy_pdpoly::cMsg_shG5wg34_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_x8eOvz8t_sendMessage);
}

void Heavy_pdpoly::cBinop_vHBrzn9n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HAmBHl9N, HV_BINOP_MIN, 1, m, &cBinop_HAmBHl9N_sendMessage);
}

void Heavy_pdpoly::cIf_ZmPINRzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lc4Hbfux_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_joWGKH5V_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wn7aZ3yl_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2eS7Q8k7_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hxplg4Eg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_hkPBoklh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_GSMd5pB2, 1, m, &cPack_GSMd5pB2_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_6U7Jhs24_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_luqdwBb6, 0, m, &cSlice_luqdwBb6_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dJ9bhOcE_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BhJcqvBx_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_luqdwBb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_hkPBoklh, 1, m, &cTabread_hkPBoklh_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_hkPBoklh, 1, m, &cTabread_hkPBoklh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_8mHV5l5F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fQ7wkvnE_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_ZEE1khol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_RsaFl9OH_sendMessage);
}

void Heavy_pdpoly::cBinop_TOswqDFi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NhzGdYoF, HV_BINOP_MIN, 0, m, &cBinop_NhzGdYoF_sendMessage);
}

void Heavy_pdpoly::cCast_BhJcqvBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_TOswqDFi_sendMessage);
}

void Heavy_pdpoly::cCast_dJ9bhOcE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8mHV5l5F, 0, m, &cVar_8mHV5l5F_sendMessage);
}

void Heavy_pdpoly::cBinop_NhzGdYoF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_hkPBoklh, 0, m, &cTabread_hkPBoklh_sendMessage);
}

void Heavy_pdpoly::cMsg_fQ7wkvnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZEE1khol_sendMessage);
}

void Heavy_pdpoly::cBinop_RsaFl9OH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NhzGdYoF, HV_BINOP_MIN, 1, m, &cBinop_NhzGdYoF_sendMessage);
}

void Heavy_pdpoly::cCast_16SdAzsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JS8cj4Oy, 0, m, &cVar_JS8cj4Oy_sendMessage);
}

void Heavy_pdpoly::cCast_TtSuoG9U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TFTjutJh_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_TFTjutJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_GZH7oJ56_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_GZH7oJ56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_02n3iKi2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_LXTLAO4e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZmPINRzj, 1, m, &cIf_ZmPINRzj_sendMessage);
}

void Heavy_pdpoly::cCast_7UFT6tXB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TGm7AKRK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_CTeH3hG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZmPINRzj, 0, m, &cIf_ZmPINRzj_sendMessage);
}

void Heavy_pdpoly::cMsg_mTqCMfhk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_GSMd5pB2, 2, m, &cPack_GSMd5pB2_sendMessage);
}

void Heavy_pdpoly::cCast_hxplg4Eg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tjPfdHUR_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_lc4Hbfux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mTqCMfhk_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_joWGKH5V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_6U7Jhs24_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_wn7aZ3yl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_GWKfs9vR_sendMessage);
}

void Heavy_pdpoly::cCast_2eS7Q8k7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bNkMi3t8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_E5Ztk7n7_sendMessage);
}

void Heavy_pdpoly::cCast_E5Ztk7n7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w2l6RxmQ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_bNkMi3t8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_z27JHxSi, 1, m, &cTabwrite_z27JHxSi_sendMessage);
}

void Heavy_pdpoly::cMsg_w2l6RxmQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_qo6ZWNb9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSend_tjPfdHUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_02n3iKi2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_VLf0FPbP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6SHvotBL_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Kzihg7bW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_9gNvYS7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jWzqTB9G_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SKK5mRRn_sendMessage);
}

void Heavy_pdpoly::cIf_xsJ89HwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_M2Y8a2U3_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VQ42R4PV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_GPKGeZ6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xsJ89HwY, 1, m, &cIf_xsJ89HwY_sendMessage);
}

void Heavy_pdpoly::cVar_opOdIECq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_GvxRIaBv_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_zsXecSKe, 0, m, &cIf_zsXecSKe_sendMessage);
}

void Heavy_pdpoly::cUnop_LOw0NZHx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_GPKGeZ6t_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_xsJ89HwY, 0, m, &cIf_xsJ89HwY_sendMessage);
}

void Heavy_pdpoly::cUnop_QkV0ylm8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_GPKGeZ6t_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_xsJ89HwY, 0, m, &cIf_xsJ89HwY_sendMessage);
}

void Heavy_pdpoly::cIf_zsXecSKe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_QkV0ylm8_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_LOw0NZHx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_GvxRIaBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zsXecSKe, 1, m, &cIf_zsXecSKe_sendMessage);
}

void Heavy_pdpoly::cCast_SKK5mRRn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VLf0FPbP, 0, m, &cIf_VLf0FPbP_sendMessage);
}

void Heavy_pdpoly::cCast_jWzqTB9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OlmObO45, HV_BINOP_LESS_THAN, 0, m, &cBinop_OlmObO45_sendMessage);
}

void Heavy_pdpoly::cBinop_OlmObO45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VLf0FPbP, 1, m, &cIf_VLf0FPbP_sendMessage);
}

void Heavy_pdpoly::cCast_VQ42R4PV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RnYBNC0D_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_M2Y8a2U3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OlmObO45, HV_BINOP_LESS_THAN, 1, m, &cBinop_OlmObO45_sendMessage);
}

void Heavy_pdpoly::cBinop_xlKReyP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9gNvYS7y, 0, m, &cVar_9gNvYS7y_sendMessage);
}

void Heavy_pdpoly::cMsg_RnYBNC0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_9gNvYS7y, 0, m, &cVar_9gNvYS7y_sendMessage);
}

void Heavy_pdpoly::cCast_6SHvotBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_8N1iseQm, 1, m, &cTabwrite_8N1iseQm_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_fsTT8mMt, 1, m, &cTabwrite_fsTT8mMt_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_TeehkMxc, 1, m, &cTabwrite_TeehkMxc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n1klAlzW_sendMessage);
}

void Heavy_pdpoly::cCast_Kzihg7bW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_xlKReyP6_sendMessage);
}

void Heavy_pdpoly::cVar_vlJ8TygL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_opOdIECq, 0, m, &cVar_opOdIECq_sendMessage);
}

void Heavy_pdpoly::cTabwrite_TeehkMxc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_SS4Eha15_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZWOz090j, 0, m, &cSlice_ZWOz090j_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_TeehkMxc, 0, m, &cTabwrite_TeehkMxc_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_ZWOz090j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_TeehkMxc, 2, m, &cTabwrite_TeehkMxc_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_TeehkMxc, 2, m, &cTabwrite_TeehkMxc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_fsTT8mMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_jhUy8geT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2MOFWxz6, 0, m, &cSlice_2MOFWxz6_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_fsTT8mMt, 0, m, &cTabwrite_fsTT8mMt_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_2MOFWxz6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_fsTT8mMt, 2, m, &cTabwrite_fsTT8mMt_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_fsTT8mMt, 2, m, &cTabwrite_fsTT8mMt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_8N1iseQm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_VmTdhPND_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hH8KRYtM, 0, m, &cSlice_hH8KRYtM_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_8N1iseQm, 0, m, &cTabwrite_8N1iseQm_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_hH8KRYtM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_8N1iseQm, 2, m, &cTabwrite_8N1iseQm_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_8N1iseQm, 2, m, &cTabwrite_8N1iseQm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cMsg_FrMBerq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_VmTdhPND_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_jhUy8geT_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_SS4Eha15_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_QFZLgRM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xP06bf5y_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_BQlcHCEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vlJ8TygL, 0, m, &cVar_vlJ8TygL_sendMessage);
}

void Heavy_pdpoly::cMsg_xP06bf5y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_gTvPjrrG_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_gTvPjrrG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_02n3iKi2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_n1klAlzW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FrMBerq8_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_0eAlUVXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tv7w5sdU_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rTn4qHtD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_vklKFdgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZYE4ND7t_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7xyqFkvL_sendMessage);
}

void Heavy_pdpoly::cIf_hFfBJxYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IN0kd1KQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KfrjjupM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_GDkxZPy9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hFfBJxYU, 1, m, &cIf_hFfBJxYU_sendMessage);
}

void Heavy_pdpoly::cVar_40UKmqGZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_arD9wQrK_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ZS29qAGq, 0, m, &cIf_ZS29qAGq_sendMessage);
}

void Heavy_pdpoly::cUnop_ZuKEpbde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_GDkxZPy9_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_hFfBJxYU, 0, m, &cIf_hFfBJxYU_sendMessage);
}

void Heavy_pdpoly::cUnop_J7rsZlFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_GDkxZPy9_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_hFfBJxYU, 0, m, &cIf_hFfBJxYU_sendMessage);
}

void Heavy_pdpoly::cIf_ZS29qAGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_J7rsZlFn_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ZuKEpbde_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_arD9wQrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZS29qAGq, 1, m, &cIf_ZS29qAGq_sendMessage);
}

void Heavy_pdpoly::cCast_7xyqFkvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0eAlUVXJ, 0, m, &cIf_0eAlUVXJ_sendMessage);
}

void Heavy_pdpoly::cCast_ZYE4ND7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PKBPkeL4, HV_BINOP_LESS_THAN, 0, m, &cBinop_PKBPkeL4_sendMessage);
}

void Heavy_pdpoly::cBinop_PKBPkeL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0eAlUVXJ, 1, m, &cIf_0eAlUVXJ_sendMessage);
}

void Heavy_pdpoly::cCast_KfrjjupM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lv9iKBzA_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_IN0kd1KQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PKBPkeL4, HV_BINOP_LESS_THAN, 1, m, &cBinop_PKBPkeL4_sendMessage);
}

void Heavy_pdpoly::cBinop_ce32HkyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vklKFdgc, 0, m, &cVar_vklKFdgc_sendMessage);
}

void Heavy_pdpoly::cMsg_lv9iKBzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_vklKFdgc, 0, m, &cVar_vklKFdgc_sendMessage);
}

void Heavy_pdpoly::cCast_tv7w5sdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mTDZ4GP2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SoHRi0Am_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oWGVBnJP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WGHml5iV_sendMessage);
}

void Heavy_pdpoly::cCast_rTn4qHtD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ce32HkyB_sendMessage);
}

void Heavy_pdpoly::cVar_YnvM1fAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_40UKmqGZ, 0, m, &cVar_40UKmqGZ_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_1NEhmUYc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sBxX2fEq_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_sBxX2fEq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_StITqw8i_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ISWK4Ey4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PvvnIh2W_sendMessage);
}

void Heavy_pdpoly::cVar_mhE3YoWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KqlPnI2T_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_fIFb4kRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_yvYcm23U_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_QSzY4L1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Ig41fMsh_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSwitchcase_yvYcm23U_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GFUWCvuc_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_GFUWCvuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3nVotMyD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mG5JGoX1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HtXyQvLv_sendMessage);
}

void Heavy_pdpoly::cVar_ZI9sDIc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_03pCmUD5, HV_BINOP_LESS_THAN, 1, m, &cBinop_03pCmUD5_sendMessage);
}

void Heavy_pdpoly::cVar_ADRio44E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5eK67iwN, HV_BINOP_LESS_THAN, 1, m, &cBinop_5eK67iwN_sendMessage);
}

void Heavy_pdpoly::cIf_iDOVnkov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_S2Ep7BzN, 0, m, &cSlice_S2Ep7BzN_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_0w0Tfart, 0, m, &cSlice_0w0Tfart_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I9gOHwPE_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TIMrY833_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_15xdP0zw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_pmtF54Rm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JAUZCiOX_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_cbHdEfnO, 0, m, &cSlice_cbHdEfnO_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_lzfhWgdA, 0, m, &cSlice_lzfhWgdA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m0PabC6C_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qNXZy5IF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tSbAX2Uh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cPack_2obG09kK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_pmtF54Rm, 0, m, &cIf_pmtF54Rm_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_iDOVnkov, 0, m, &cIf_iDOVnkov_sendMessage);
}

void Heavy_pdpoly::cVar_mCFP2oFP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_GWKfs9vR_sendMessage);
}

void Heavy_pdpoly::cSlice_S2Ep7BzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_GSMd5pB2, 2, m, &cPack_GSMd5pB2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_0w0Tfart_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_AfSdtJMD_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_GSMd5pB2, 1, m, &cPack_GSMd5pB2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_AzAjOQV2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_GWKfs9vR_sendMessage);
}

void Heavy_pdpoly::cIf_MQ0fwAWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_pmtF54Rm, 1, m, &cIf_pmtF54Rm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_7jZVlfqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_tRJhvyrx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cVar_zupn0q8O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_HpawxGMA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cTabread_foz53Hzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6Iw6ghfo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ylRHD01C_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_gLmkqsCF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Hpe4Xyl6, 0, m, &cSlice_Hpe4Xyl6_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NtNctu0a_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b8qk5ema_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_Hpe4Xyl6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_foz53Hzi, 1, m, &cTabread_foz53Hzi_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_foz53Hzi, 1, m, &cTabread_foz53Hzi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_x9IxniLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bDT15S2R_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_AvfgHd2N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_s2B6eBsg_sendMessage);
}

void Heavy_pdpoly::cBinop_XRzZRi8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HdmyvDQK, HV_BINOP_MIN, 0, m, &cBinop_HdmyvDQK_sendMessage);
}

void Heavy_pdpoly::cCast_b8qk5ema_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_XRzZRi8r_sendMessage);
}

void Heavy_pdpoly::cCast_NtNctu0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_x9IxniLq, 0, m, &cVar_x9IxniLq_sendMessage);
}

void Heavy_pdpoly::cBinop_HdmyvDQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_foz53Hzi, 0, m, &cTabread_foz53Hzi_sendMessage);
}

void Heavy_pdpoly::cMsg_bDT15S2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AvfgHd2N_sendMessage);
}

void Heavy_pdpoly::cBinop_s2B6eBsg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HdmyvDQK, HV_BINOP_MIN, 1, m, &cBinop_HdmyvDQK_sendMessage);
}

void Heavy_pdpoly::cTabread_msQ7SsdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aUBUKlox_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Nm6XRGm2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_I4vDd2HD_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_UWVOITxZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fZ1ILJlK, 0, m, &cSlice_fZ1ILJlK_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_olHUvDyW_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SE8nlFmc_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_fZ1ILJlK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_msQ7SsdS, 1, m, &cTabread_msQ7SsdS_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_msQ7SsdS, 1, m, &cTabread_msQ7SsdS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_8WfMc5YK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ddgh874z_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_F5uYvBDm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_GqU0LzAz_sendMessage);
}

void Heavy_pdpoly::cBinop_pOgc0HjV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wbx5fglh, HV_BINOP_MIN, 0, m, &cBinop_Wbx5fglh_sendMessage);
}

void Heavy_pdpoly::cCast_SE8nlFmc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_pOgc0HjV_sendMessage);
}

void Heavy_pdpoly::cCast_olHUvDyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8WfMc5YK, 0, m, &cVar_8WfMc5YK_sendMessage);
}

void Heavy_pdpoly::cBinop_Wbx5fglh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_msQ7SsdS, 0, m, &cTabread_msQ7SsdS_sendMessage);
}

void Heavy_pdpoly::cMsg_ddgh874z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_F5uYvBDm_sendMessage);
}

void Heavy_pdpoly::cBinop_GqU0LzAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wbx5fglh, HV_BINOP_MIN, 1, m, &cBinop_Wbx5fglh_sendMessage);
}

void Heavy_pdpoly::cTabwrite_UJL2WKSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_enCIRZ5O_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zya4VDMx, 0, m, &cSlice_zya4VDMx_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_UJL2WKSE, 0, m, &cTabwrite_UJL2WKSE_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_zya4VDMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_UJL2WKSE, 2, m, &cTabwrite_UJL2WKSE_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_UJL2WKSE, 2, m, &cTabwrite_UJL2WKSE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_2Kb6Td91_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_GSMd5pB2, 1, m, &cPack_GSMd5pB2_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_tRJhvyrx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_HjJzJDwf, 0, m, &cSlice_HjJzJDwf_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0FoZPy7y_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NDQjL6dd_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_HjJzJDwf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_2Kb6Td91, 1, m, &cTabread_2Kb6Td91_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_2Kb6Td91, 1, m, &cTabread_2Kb6Td91_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_2EEhh3YX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AMSUU4CB_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_JqPmlpWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nkHkxfyt_sendMessage);
}

void Heavy_pdpoly::cBinop_xnOIUlYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FmvvvC77, HV_BINOP_MIN, 0, m, &cBinop_FmvvvC77_sendMessage);
}

void Heavy_pdpoly::cCast_NDQjL6dd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_xnOIUlYk_sendMessage);
}

void Heavy_pdpoly::cCast_0FoZPy7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2EEhh3YX, 0, m, &cVar_2EEhh3YX_sendMessage);
}

void Heavy_pdpoly::cBinop_FmvvvC77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_2Kb6Td91, 0, m, &cTabread_2Kb6Td91_sendMessage);
}

void Heavy_pdpoly::cMsg_AMSUU4CB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JqPmlpWi_sendMessage);
}

void Heavy_pdpoly::cBinop_nkHkxfyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FmvvvC77, HV_BINOP_MIN, 1, m, &cBinop_FmvvvC77_sendMessage);
}

void Heavy_pdpoly::cTabwrite_PMaPrMVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_AfSdtJMD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZYGxrtgq, 0, m, &cSlice_ZYGxrtgq_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_PMaPrMVI, 0, m, &cTabwrite_PMaPrMVI_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_ZYGxrtgq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_PMaPrMVI, 2, m, &cTabwrite_PMaPrMVI_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_PMaPrMVI, 2, m, &cTabwrite_PMaPrMVI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_3U82r7b3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_8UoB44Yu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xdZ0aKBt, 0, m, &cSlice_xdZ0aKBt_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_3U82r7b3, 0, m, &cTabwrite_3U82r7b3_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_xdZ0aKBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_3U82r7b3, 2, m, &cTabwrite_3U82r7b3_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_3U82r7b3, 2, m, &cTabwrite_3U82r7b3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_jMBXhJE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_HpawxGMA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Crg4GN1M, 0, m, &cSlice_Crg4GN1M_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jMBXhJE1, 0, m, &cTabwrite_jMBXhJE1_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_Crg4GN1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jMBXhJE1, 2, m, &cTabwrite_jMBXhJE1_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jMBXhJE1, 2, m, &cTabwrite_jMBXhJE1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_0HC5abm9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_WN3g4qrN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ltrdISlC, 0, m, &cSlice_ltrdISlC_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_0HC5abm9, 0, m, &cTabwrite_0HC5abm9_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_ltrdISlC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_0HC5abm9, 2, m, &cTabwrite_0HC5abm9_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_0HC5abm9, 2, m, &cTabwrite_0HC5abm9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_mpIm5Q3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WN3g4qrN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cTabwrite_aWdUPGHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_dHZBuTfu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_AeqLNz64, 0, m, &cSlice_AeqLNz64_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_aWdUPGHv, 0, m, &cTabwrite_aWdUPGHv_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_AeqLNz64_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_aWdUPGHv, 2, m, &cTabwrite_aWdUPGHv_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_aWdUPGHv, 2, m, &cTabwrite_aWdUPGHv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_6HQ7mFRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dXZUMC4X_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HvGNKhxQ_sendMessage);
}

void Heavy_pdpoly::cSlice_cbHdEfnO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_GSMd5pB2, 2, m, &cPack_GSMd5pB2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_lzfhWgdA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_enCIRZ5O_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_GSMd5pB2, 1, m, &cPack_GSMd5pB2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_7ojIMy5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IcSJ2ase, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_IcSJ2ase_sendMessage);
}

void Heavy_pdpoly::cBinop_Wj8JVjDE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MYndHCUY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d8DkasOh_sendMessage);
}

void Heavy_pdpoly::cBinop_03pCmUD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0VvM9QCV, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_0VvM9QCV_sendMessage);
}

void Heavy_pdpoly::cCast_WGHml5iV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cCast_SoHRi0Am_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_UWVOITxZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_mTDZ4GP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mhE3YoWH, 1, m, &cVar_mhE3YoWH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_QSzY4L1d, 1, m, &cVar_QSzY4L1d_sendMessage);
}

void Heavy_pdpoly::cCast_oWGVBnJP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_gLmkqsCF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSend_KqlPnI2T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9EHRLrqK_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_ylRHD01C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_QmL8zuTQ_sendMessage);
}

void Heavy_pdpoly::cCast_6Iw6ghfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wj8JVjDE, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_Wj8JVjDE_sendMessage);
}

void Heavy_pdpoly::cBinop_0VvM9QCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_fIFb4kRA, 0, m, &cIf_fIFb4kRA_sendMessage);
}

void Heavy_pdpoly::cBinop_QmL8zuTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0VvM9QCV, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_0VvM9QCV_sendMessage);
}

void Heavy_pdpoly::cCast_MYndHCUY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1NEhmUYc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_d8DkasOh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_PrR4cdLn_sendMessage);
}

void Heavy_pdpoly::cBinop_PrR4cdLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_fIFb4kRA, 1, m, &cIf_fIFb4kRA_sendMessage);
}

void Heavy_pdpoly::cSend_Ig41fMsh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_S7mnQCBs_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_ALOBdzty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_9EHRLrqK_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_MPXq6rRW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_S7mnQCBs_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_MFa12vW2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YnvM1fAh, 0, m, &cVar_YnvM1fAh_sendMessage);
}

void Heavy_pdpoly::cCast_pm9VULLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6HQ7mFRv, 0, m, &cVar_6HQ7mFRv_sendMessage);
}

void Heavy_pdpoly::cCast_DI4xfV6R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_h4ZpfXid_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_5eK67iwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wj8JVjDE, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_Wj8JVjDE_sendMessage);
}

void Heavy_pdpoly::cCast_aUBUKlox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZI9sDIc4, 1, m, &cVar_ZI9sDIc4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ADRio44E, 1, m, &cVar_ADRio44E_sendMessage);
}

void Heavy_pdpoly::cCast_I4vDd2HD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_03pCmUD5, HV_BINOP_LESS_THAN, 0, m, &cBinop_03pCmUD5_sendMessage);
}

void Heavy_pdpoly::cCast_Nm6XRGm2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5eK67iwN, HV_BINOP_LESS_THAN, 0, m, &cBinop_5eK67iwN_sendMessage);
}

void Heavy_pdpoly::cCast_dXZUMC4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ADRio44E, 0, m, &cVar_ADRio44E_sendMessage);
}

void Heavy_pdpoly::cCast_HvGNKhxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZI9sDIc4, 0, m, &cVar_ZI9sDIc4_sendMessage);
}

void Heavy_pdpoly::cSend_BumMtoj6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bpN4Wtfh_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_3nVotMyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZI9sDIc4, 0, m, &cVar_ZI9sDIc4_sendMessage);
}

void Heavy_pdpoly::cCast_HtXyQvLv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QSzY4L1d, 0, m, &cVar_QSzY4L1d_sendMessage);
}

void Heavy_pdpoly::cCast_mG5JGoX1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z73dchSx_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_Z73dchSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_BumMtoj6_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_RyMvdz2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_d0PHSian_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_d0PHSian_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YeZydjIf_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_PvvnIh2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mhE3YoWH, 0, m, &cVar_mhE3YoWH_sendMessage);
}

void Heavy_pdpoly::cCast_ISWK4Ey4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RyMvdz2b_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_StITqw8i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ADRio44E, 0, m, &cVar_ADRio44E_sendMessage);
}

void Heavy_pdpoly::cMsg_h4ZpfXid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_MPXq6rRW_sendMessage(_c, 0, m);
  cSend_ALOBdzty_sendMessage(_c, 0, m);
  cSend_UTbfCxks_sendMessage(_c, 0, m);
  cSend_XSlW48DP_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_UTbfCxks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YeZydjIf_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_XSlW48DP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_bpN4Wtfh_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_0nsM2AHa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_iDOVnkov, 1, m, &cIf_iDOVnkov_sendMessage);
}

void Heavy_pdpoly::cCast_xxejURg0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_WjUXUFBB_sendMessage);
}

void Heavy_pdpoly::cBinop_IcSJ2ase_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MQ0fwAWH, 0, m, &cIf_MQ0fwAWH_sendMessage);
}

void Heavy_pdpoly::cBinop_WjUXUFBB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7ojIMy5Y, 0, m, &cVar_7ojIMy5Y_sendMessage);
}

void Heavy_pdpoly::cMsg_FfyBiKtK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_8UoB44Yu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_3KsQTA84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_dHZBuTfu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_ycXWn6hh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AzAjOQV2, 0, m, &cVar_AzAjOQV2_sendMessage);
}

void Heavy_pdpoly::cCast_e4PL9zBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7jZVlfqS, 0, m, &cVar_7jZVlfqS_sendMessage);
}

void Heavy_pdpoly::cCast_2YDTM0YW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I5Ftzqsg_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_I5Ftzqsg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_GSMd5pB2, 2, m, &cPack_GSMd5pB2_sendMessage);
}

void Heavy_pdpoly::cCast_15xdP0zw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MUe08vGy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_841qaiGw_sendMessage);
}

void Heavy_pdpoly::cCast_TIMrY833_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FfyBiKtK_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_I9gOHwPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mCFP2oFP, 0, m, &cVar_mCFP2oFP_sendMessage);
}

void Heavy_pdpoly::cCast_841qaiGw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zupn0q8O, 0, m, &cVar_zupn0q8O_sendMessage);
}

void Heavy_pdpoly::cCast_MUe08vGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_8BdiFQTu_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_8BdiFQTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_02n3iKi2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_mYL4qLJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mpIm5Q3w, 0, m, &cVar_mpIm5Q3w_sendMessage);
}

void Heavy_pdpoly::cCast_7vVc3EZk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Dimr8khe_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_Dimr8khe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_02n3iKi2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_JAUZCiOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2YDTM0YW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_e4PL9zBG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ycXWn6hh_sendMessage);
}

void Heavy_pdpoly::cCast_m0PabC6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AzAjOQV2, 0, m, &cVar_AzAjOQV2_sendMessage);
}

void Heavy_pdpoly::cCast_tSbAX2Uh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7vVc3EZk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mYL4qLJL_sendMessage);
}

void Heavy_pdpoly::cCast_qNXZy5IF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3KsQTA84_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_OL4NjfHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IcSJ2ase, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_IcSJ2ase_sendMessage);
}

void Heavy_pdpoly::cCast_WJFc1wc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7ojIMy5Y, 0, m, &cVar_7ojIMy5Y_sendMessage);
}

void Heavy_pdpoly::cSend_dJY5J6u9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EgTWGg6Q_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_KoAQ9KeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_shKozkoE, 1, m, &cVar_shKozkoE_sendMessage);
}

void Heavy_pdpoly::cSend_fBf6ptIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_NrH1G6pg_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_GWKfs9vR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_GSMd5pB2, 0, m, &cPack_GSMd5pB2_sendMessage);
}

void Heavy_pdpoly::cBinop_dcZcguYH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_KoAQ9KeP_sendMessage);
  cSend_fBf6ptIm_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::hTable_2R00hG4y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::hTable_ZOjEP2YV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::hTable_WFqpxauu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cCast_mFs5e0I4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YYvTuJxq, 0, m, &cVar_YYvTuJxq_sendMessage);
}

void Heavy_pdpoly::cCast_gkgmT4E9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X61dWxpG_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_5dUDQbRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_EPSsyBF2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_X61dWxpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 65535.0f);
  cSend_5dUDQbRS_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_ScKudNoI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9UoyO7vJ, 1, m, &cIf_9UoyO7vJ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_E4HGJVFx_sendMessage);
}

void Heavy_pdpoly::cBinop_E4HGJVFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ii9wt7Pw, 1, m, &cIf_ii9wt7Pw_sendMessage);
}

void Heavy_pdpoly::cBinop_MbBXutYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dJY5J6u9_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cPack_GSMd5pB2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zuaEKq4d_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSwitchcase_zuaEKq4d_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2iJRL3Ou, 0, m, &cSlice_2iJRL3Ou_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_l0024PwI, 0, m, &cSlice_l0024PwI_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mI0e8Cic, 0, m, &cSlice_mI0e8Cic_sendMessage);
      break;
    }
    case 0x40800000: { // "4.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vfnCSAYZ, 0, m, &cSlice_vfnCSAYZ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_2iJRL3Ou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Px6AWHZl, 0, m, &cSlice_Px6AWHZl_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_3s846F1P, 0, m, &cSlice_3s846F1P_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Px6AWHZl, 0, m, &cSlice_Px6AWHZl_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_3s846F1P, 0, m, &cSlice_3s846F1P_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_l0024PwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_488bPkdV, 0, m, &cSlice_488bPkdV_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_oE6TidP5, 0, m, &cSlice_oE6TidP5_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_488bPkdV, 0, m, &cSlice_488bPkdV_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_oE6TidP5, 0, m, &cSlice_oE6TidP5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_mI0e8Cic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_FUrzZvun, 0, m, &cSlice_FUrzZvun_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_2RMOtAil, 0, m, &cSlice_2RMOtAil_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_FUrzZvun, 0, m, &cSlice_FUrzZvun_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_2RMOtAil, 0, m, &cSlice_2RMOtAil_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_vfnCSAYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_WAjGlulW, 0, m, &cSlice_WAjGlulW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_hMwsxfHO, 0, m, &cSlice_hMwsxfHO_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_WAjGlulW, 0, m, &cSlice_WAjGlulW_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_hMwsxfHO, 0, m, &cSlice_hMwsxfHO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_Px6AWHZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_SC3vT3cG_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_3s846F1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_bi6TmxAp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_SsBxNfF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ZOZzDmTx, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_usNRktUE_sendMessage);
}

void Heavy_pdpoly::cBinop_bi6TmxAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_sIJg9OTy_sendMessage);
}

void Heavy_pdpoly::cBinop_sIJg9OTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EWo0lYZi, HV_BINOP_POW, 1, m, &cBinop_EWo0lYZi_sendMessage);
  cMsg_HtZzfRdv_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_EWo0lYZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_SsBxNfF4_sendMessage);
}

void Heavy_pdpoly::cMsg_HtZzfRdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EWo0lYZi, HV_BINOP_POW, 0, m, &cBinop_EWo0lYZi_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_SC3vT3cG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M0Vv0Mer_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_frihwI20_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_M0Vv0Mer_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9efhXU6c_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_0MSeXxQN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jmPtYr4C, HV_BINOP_MULTIPLY, 0, m, &cBinop_jmPtYr4C_sendMessage);
}

void Heavy_pdpoly::cMsg_iQtlWUVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wFgtQ9a9_sendMessage);
}

void Heavy_pdpoly::cSystem_wFgtQ9a9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kEHGWHRY_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_jmPtYr4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_0aSWw44l_sendMessage);
}

void Heavy_pdpoly::cBinop_rMCBCy7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jmPtYr4C, HV_BINOP_MULTIPLY, 1, m, &cBinop_jmPtYr4C_sendMessage);
}

void Heavy_pdpoly::cMsg_kEHGWHRY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rMCBCy7V_sendMessage);
}

void Heavy_pdpoly::cBinop_0aSWw44l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_usfd6t4Z_sendMessage);
}

void Heavy_pdpoly::cBinop_usfd6t4Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_XOLeMUGN_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NOGXLkMo, m);
}

void Heavy_pdpoly::cBinop_XOLeMUGN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ak33qfDJ, m);
}

void Heavy_pdpoly::cVar_4XMUFZIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sRU52o2w, HV_BINOP_MULTIPLY, 0, m, &cBinop_sRU52o2w_sendMessage);
}

void Heavy_pdpoly::cMsg_KyPb9poz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AlSpT3Lm_sendMessage);
}

void Heavy_pdpoly::cSystem_AlSpT3Lm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GO0LBL74_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_sRU52o2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_d5Ktpgn9_sendMessage);
}

void Heavy_pdpoly::cBinop_mRh3jt0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sRU52o2w, HV_BINOP_MULTIPLY, 1, m, &cBinop_sRU52o2w_sendMessage);
}

void Heavy_pdpoly::cMsg_GO0LBL74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_mRh3jt0S_sendMessage);
}

void Heavy_pdpoly::cBinop_d5Ktpgn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_LEDUnqOJ_sendMessage);
}

void Heavy_pdpoly::cBinop_LEDUnqOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_pobzTbIc_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Yhbwgzk4, m);
}

void Heavy_pdpoly::cBinop_pobzTbIc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fyLhG6WL, m);
}

void Heavy_pdpoly::cMsg_9efhXU6c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Ty0jmkKK, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_frihwI20_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Jyri85a3_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_Jyri85a3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Ty0jmkKK, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_usNRktUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_WaM3EAbS, 0, m);
}

void Heavy_pdpoly::cSlice_488bPkdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_meT3y9yH_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_oE6TidP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_RDv95Xd5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_Bad0fc5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_NAz5gPbt, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_VeAlfgpe_sendMessage);
}

void Heavy_pdpoly::cBinop_RDv95Xd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_pPmwe61z_sendMessage);
}

void Heavy_pdpoly::cBinop_pPmwe61z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_20BrF21b, HV_BINOP_POW, 1, m, &cBinop_20BrF21b_sendMessage);
  cMsg_2iiZhaHq_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_20BrF21b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Bad0fc5s_sendMessage);
}

void Heavy_pdpoly::cMsg_2iiZhaHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_20BrF21b, HV_BINOP_POW, 0, m, &cBinop_20BrF21b_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_meT3y9yH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bp0FUJE8_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_c5Cfyc96_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_bp0FUJE8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YGIUWnrP_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_CwgnP55l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Vb6OYqY, HV_BINOP_MULTIPLY, 0, m, &cBinop_2Vb6OYqY_sendMessage);
}

void Heavy_pdpoly::cMsg_Dy3yXabT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hWZANAgM_sendMessage);
}

void Heavy_pdpoly::cSystem_hWZANAgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0UDJr5Q6_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_2Vb6OYqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_RPLHJV8y_sendMessage);
}

void Heavy_pdpoly::cBinop_2Q0L7odV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2Vb6OYqY, HV_BINOP_MULTIPLY, 1, m, &cBinop_2Vb6OYqY_sendMessage);
}

void Heavy_pdpoly::cMsg_0UDJr5Q6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_2Q0L7odV_sendMessage);
}

void Heavy_pdpoly::cBinop_RPLHJV8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MDsN4z6H_sendMessage);
}

void Heavy_pdpoly::cBinop_MDsN4z6H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VwSDPrsZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OXp11SEl, m);
}

void Heavy_pdpoly::cBinop_VwSDPrsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_My7xwkdE, m);
}

void Heavy_pdpoly::cVar_914SdQkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AEd4ZR10, HV_BINOP_MULTIPLY, 0, m, &cBinop_AEd4ZR10_sendMessage);
}

void Heavy_pdpoly::cMsg_hXOaEBqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FaEHDr9F_sendMessage);
}

void Heavy_pdpoly::cSystem_FaEHDr9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wAcRCK16_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_AEd4ZR10_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_q9HsU9Ty_sendMessage);
}

void Heavy_pdpoly::cBinop_bTyYOTre_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AEd4ZR10, HV_BINOP_MULTIPLY, 1, m, &cBinop_AEd4ZR10_sendMessage);
}

void Heavy_pdpoly::cMsg_wAcRCK16_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_bTyYOTre_sendMessage);
}

void Heavy_pdpoly::cBinop_q9HsU9Ty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_3M84TFU9_sendMessage);
}

void Heavy_pdpoly::cBinop_3M84TFU9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_lvzUOWUG_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1HJxQXeX, m);
}

void Heavy_pdpoly::cBinop_lvzUOWUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PlTU9cYa, m);
}

void Heavy_pdpoly::cMsg_YGIUWnrP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_T18vNNH6, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_c5Cfyc96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MJWq6uim_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_MJWq6uim_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_T18vNNH6, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_VeAlfgpe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_NqR4dUUT, 0, m);
}

void Heavy_pdpoly::cSlice_FUrzZvun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_IwtodZ0W_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_2RMOtAil_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_3vfv1nfO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_XqMT2FHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_F5IRsyMT, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_RLsO4o0J_sendMessage);
}

void Heavy_pdpoly::cBinop_3vfv1nfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_BkE2Zom3_sendMessage);
}

void Heavy_pdpoly::cBinop_BkE2Zom3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_806FaMvZ, HV_BINOP_POW, 1, m, &cBinop_806FaMvZ_sendMessage);
  cMsg_swKy2ZQz_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_806FaMvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_XqMT2FHh_sendMessage);
}

void Heavy_pdpoly::cMsg_swKy2ZQz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_806FaMvZ, HV_BINOP_POW, 0, m, &cBinop_806FaMvZ_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_IwtodZ0W_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PVlivVgH_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_3yFuGL9o_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_PVlivVgH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8iUzFZH6_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_pPO2LSge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sLbt2hBN, HV_BINOP_MULTIPLY, 0, m, &cBinop_sLbt2hBN_sendMessage);
}

void Heavy_pdpoly::cMsg_DwMWwiyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zdBilDzi_sendMessage);
}

void Heavy_pdpoly::cSystem_zdBilDzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N4vSMH5j_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_sLbt2hBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_mYfdBNGC_sendMessage);
}

void Heavy_pdpoly::cBinop_OTaootnV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sLbt2hBN, HV_BINOP_MULTIPLY, 1, m, &cBinop_sLbt2hBN_sendMessage);
}

void Heavy_pdpoly::cMsg_N4vSMH5j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_OTaootnV_sendMessage);
}

void Heavy_pdpoly::cBinop_mYfdBNGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_eG1WLFbN_sendMessage);
}

void Heavy_pdpoly::cBinop_eG1WLFbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6Lp55oLt_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_DpIfNdz0, m);
}

void Heavy_pdpoly::cBinop_6Lp55oLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6Lrt8Kv9, m);
}

void Heavy_pdpoly::cVar_cHbZkICZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tx7fbUKl, HV_BINOP_MULTIPLY, 0, m, &cBinop_Tx7fbUKl_sendMessage);
}

void Heavy_pdpoly::cMsg_shQ7xnJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2IIXXGqI_sendMessage);
}

void Heavy_pdpoly::cSystem_2IIXXGqI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kXV1oIL7_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_Tx7fbUKl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_sXB3YGSC_sendMessage);
}

void Heavy_pdpoly::cBinop_Cza5EmFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tx7fbUKl, HV_BINOP_MULTIPLY, 1, m, &cBinop_Tx7fbUKl_sendMessage);
}

void Heavy_pdpoly::cMsg_kXV1oIL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Cza5EmFS_sendMessage);
}

void Heavy_pdpoly::cBinop_sXB3YGSC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8mVxHNYx_sendMessage);
}

void Heavy_pdpoly::cBinop_8mVxHNYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_NEI37ijh_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_h45QRLBH, m);
}

void Heavy_pdpoly::cBinop_NEI37ijh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PUp7RWup, m);
}

void Heavy_pdpoly::cMsg_8iUzFZH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_eSoZbyoi, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_3yFuGL9o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6iFnYJ6i_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_6iFnYJ6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_eSoZbyoi, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_RLsO4o0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_IpoUzNo2, 0, m);
}

void Heavy_pdpoly::cSlice_WAjGlulW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_gFyNbJbp_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_hMwsxfHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_0LWqArgQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_0xdKwTKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_EJtSZUnJ, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_59BjEvFc_sendMessage);
}

void Heavy_pdpoly::cBinop_0LWqArgQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_7OotHH86_sendMessage);
}

void Heavy_pdpoly::cBinop_7OotHH86_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1h7hT8Fa, HV_BINOP_POW, 1, m, &cBinop_1h7hT8Fa_sendMessage);
  cMsg_N1BxCWNV_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_1h7hT8Fa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_0xdKwTKF_sendMessage);
}

void Heavy_pdpoly::cMsg_N1BxCWNV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1h7hT8Fa, HV_BINOP_POW, 0, m, &cBinop_1h7hT8Fa_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_gFyNbJbp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lw16vFPi_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_v9l3Lmgm_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_lw16vFPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BMqQNiB3_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_7dkiillj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YCcDWx7G, HV_BINOP_MULTIPLY, 0, m, &cBinop_YCcDWx7G_sendMessage);
}

void Heavy_pdpoly::cMsg_dCFCZyxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xZz6CRYy_sendMessage);
}

void Heavy_pdpoly::cSystem_xZz6CRYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BnVy40az_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_YCcDWx7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_sv6zlcUj_sendMessage);
}

void Heavy_pdpoly::cBinop_wwv61M0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YCcDWx7G, HV_BINOP_MULTIPLY, 1, m, &cBinop_YCcDWx7G_sendMessage);
}

void Heavy_pdpoly::cMsg_BnVy40az_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_wwv61M0s_sendMessage);
}

void Heavy_pdpoly::cBinop_sv6zlcUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_vmmCevgp_sendMessage);
}

void Heavy_pdpoly::cBinop_vmmCevgp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_cnW1SZmo_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fB4jXMxD, m);
}

void Heavy_pdpoly::cBinop_cnW1SZmo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qqhC334x, m);
}

void Heavy_pdpoly::cVar_Ex9WqsGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eQtLuKHc, HV_BINOP_MULTIPLY, 0, m, &cBinop_eQtLuKHc_sendMessage);
}

void Heavy_pdpoly::cMsg_MlncW45a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vjXcX0K8_sendMessage);
}

void Heavy_pdpoly::cSystem_vjXcX0K8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kiyeo68G_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_eQtLuKHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LBK2TPAD_sendMessage);
}

void Heavy_pdpoly::cBinop_oETky9SP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eQtLuKHc, HV_BINOP_MULTIPLY, 1, m, &cBinop_eQtLuKHc_sendMessage);
}

void Heavy_pdpoly::cMsg_kiyeo68G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_oETky9SP_sendMessage);
}

void Heavy_pdpoly::cBinop_LBK2TPAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_bhMMO7we_sendMessage);
}

void Heavy_pdpoly::cBinop_bhMMO7we_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_97neWmau_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_HOmA5spJ, m);
}

void Heavy_pdpoly::cBinop_97neWmau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2WHHaEGT, m);
}

void Heavy_pdpoly::cMsg_BMqQNiB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wSBYyNor, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_v9l3Lmgm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JXPz7AbG_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_JXPz7AbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wSBYyNor, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_59BjEvFc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_wM69hs6i, 0, m);
}

void Heavy_pdpoly::cSend_6pEMqYPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Hi9PKeor_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cReceive_7ajL75ej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iQtlWUVP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0MSeXxQN, 0, m, &cVar_0MSeXxQN_sendMessage);
  cMsg_KyPb9poz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4XMUFZIR, 0, m, &cVar_4XMUFZIR_sendMessage);
  cMsg_Dy3yXabT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CwgnP55l, 0, m, &cVar_CwgnP55l_sendMessage);
  cMsg_hXOaEBqF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_914SdQkF, 0, m, &cVar_914SdQkF_sendMessage);
  cMsg_DwMWwiyp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pPO2LSge, 0, m, &cVar_pPO2LSge_sendMessage);
  cMsg_shQ7xnJB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cHbZkICZ, 0, m, &cVar_cHbZkICZ_sendMessage);
  cMsg_dCFCZyxE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7dkiillj, 0, m, &cVar_7dkiillj_sendMessage);
  cMsg_MlncW45a_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Ex9WqsGC, 0, m, &cVar_Ex9WqsGC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_atHJdUVA, 0, m, &cVar_atHJdUVA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gkgmT4E9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mFs5e0I4_sendMessage);
}

void Heavy_pdpoly::cReceive_Dju0yEP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_RDnPx5YW, 0, m, &cSlice_RDnPx5YW_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_aoRCF4gj, 0, m, &cSlice_aoRCF4gj_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_itMwSL6a, 0, m, &cSlice_itMwSL6a_sendMessage);
}

void Heavy_pdpoly::cReceive_EgTWGg6Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MQ0fwAWH, 1, m, &cIf_MQ0fwAWH_sendMessage);
}

void Heavy_pdpoly::cReceive_NrH1G6pg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TNnql8ws, 1, m, &cVar_TNnql8ws_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zupn0q8O, 1, m, &cVar_zupn0q8O_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mpIm5Q3w, 1, m, &cVar_mpIm5Q3w_sendMessage);
}

void Heavy_pdpoly::cReceive_02n3iKi2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_shKozkoE, 0, m, &cVar_shKozkoE_sendMessage);
}

void Heavy_pdpoly::cReceive_EPSsyBF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y2vRgeav, 1, m, &cVar_Y2vRgeav_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6HQ7mFRv, 1, m, &cVar_6HQ7mFRv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dcZcguYH, HV_BINOP_MOD_UNIPOLAR, 1, m, &cBinop_dcZcguYH_sendMessage);
}

void Heavy_pdpoly::cReceive_9EHRLrqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_UJL2WKSE, 1, m, &cTabwrite_UJL2WKSE_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_aWdUPGHv, 1, m, &cTabwrite_aWdUPGHv_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_0HC5abm9, 1, m, &cTabwrite_0HC5abm9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AzAjOQV2, 1, m, &cVar_AzAjOQV2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7jZVlfqS, 1, m, &cVar_7jZVlfqS_sendMessage);
}

void Heavy_pdpoly::cReceive_S7mnQCBs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mCFP2oFP, 1, m, &cVar_mCFP2oFP_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jMBXhJE1, 1, m, &cTabwrite_jMBXhJE1_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_PMaPrMVI, 1, m, &cTabwrite_PMaPrMVI_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_3U82r7b3, 1, m, &cTabwrite_3U82r7b3_sendMessage);
}

void Heavy_pdpoly::cReceive_bpN4Wtfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xxejURg0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0nsM2AHa_sendMessage);
}

void Heavy_pdpoly::cReceive_YeZydjIf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OL4NjfHO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WJFc1wc9_sendMessage);
}

void Heavy_pdpoly::cReceive_Hi9PKeor_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0MSeXxQN, 0, m, &cVar_0MSeXxQN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4XMUFZIR, 0, m, &cVar_4XMUFZIR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CwgnP55l, 0, m, &cVar_CwgnP55l_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_914SdQkF, 0, m, &cVar_914SdQkF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pPO2LSge, 0, m, &cVar_pPO2LSge_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cHbZkICZ, 0, m, &cVar_cHbZkICZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7dkiillj, 0, m, &cVar_7dkiillj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Ex9WqsGC, 0, m, &cVar_Ex9WqsGC_sendMessage);
}

void Heavy_pdpoly::cReceive_wWPjApNu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_6pEMqYPq_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cReceive_ARa3n9mv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dna7pG92, m);
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
    __hv_phasor_k_f(&sPhasor_ZOZzDmTx, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_WaM3EAbS, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_NOGXLkMo, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_ak33qfDJ, VOf(Bf2));
    __hv_rpole_f(&sRPole_tpBtjx5s, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Yhbwgzk4, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_fyLhG6WL, VOf(Bf2));
    __hv_rpole_f(&sRPole_9de4vrgK, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_Ty0jmkKK, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_NAz5gPbt, VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_NqR4dUUT, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_OXp11SEl, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_My7xwkdE, VOf(Bf3));
    __hv_rpole_f(&sRPole_lHrqooKd, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_1HJxQXeX, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_PlTU9cYa, VOf(Bf3));
    __hv_rpole_f(&sRPole_zRic5bp7, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_T18vNNH6, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_F5IRsyMT, VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_IpoUzNo2, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_DpIfNdz0, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_6Lrt8Kv9, VOf(Bf2));
    __hv_rpole_f(&sRPole_n9CZfL83, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_h45QRLBH, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_PUp7RWup, VOf(Bf2));
    __hv_rpole_f(&sRPole_n8xc9Sts, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_eSoZbyoi, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_EJtSZUnJ, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_wM69hs6i, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_fB4jXMxD, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_qqhC334x, VOf(Bf1));
    __hv_rpole_f(&sRPole_5v19PQB4, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_HOmA5spJ, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_2WHHaEGT, VOf(Bf1));
    __hv_rpole_f(&sRPole_zSejl4Hc, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_wSBYyNor, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_dna7pG92, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));

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
