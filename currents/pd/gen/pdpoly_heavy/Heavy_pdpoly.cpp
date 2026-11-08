/** Copyright (c) 2026 Charles Vestal. MIT License (LICENSE beside pdpoly.pd) */

#include "Heavy_pdpoly.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_pdpoly *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_pdpoly_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_pdpoly));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_pdpoly(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_pdpoly_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_pdpoly));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_pdpoly(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_pdpoly_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_pdpoly();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_pdpoly::Heavy_pdpoly(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_nJXb0qiE, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_DfTNZJm9, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_SofnGBgU);
  numBytes += sRPole_init(&sRPole_goKP5JaM);
  numBytes += sLine_init(&sLine_03n31EqW);
  numBytes += sPhasor_k_init(&sPhasor_5z6fZQ53, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_RlcrU0PE, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_33ljBuDg);
  numBytes += sRPole_init(&sRPole_G4gaqNLE);
  numBytes += sLine_init(&sLine_YvVlOupd);
  numBytes += sPhasor_k_init(&sPhasor_ekic19xi, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_awoCAqDD, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_sRUvQkKb);
  numBytes += sRPole_init(&sRPole_e3iiWwN0);
  numBytes += sLine_init(&sLine_iTpxhYpN);
  numBytes += sPhasor_k_init(&sPhasor_DlMyAiOj, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_iKkYsIWE, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_aXqDhGbj);
  numBytes += sRPole_init(&sRPole_aApveVw4);
  numBytes += sLine_init(&sLine_eCjCXXhx);
  numBytes += cSlice_init(&cSlice_QOjO4xj4, 2, 1);
  numBytes += cSlice_init(&cSlice_qJk4Wdcs, 1, 1);
  numBytes += cSlice_init(&cSlice_goGccCX2, 0, 1);
  numBytes += cVar_init_f(&cVar_cZD5jLrO, 0.0f);
  numBytes += cIf_init(&cIf_WHuMf71b, false);
  numBytes += cIf_init(&cIf_9keZMPFL, false);
  numBytes += cIf_init(&cIf_yGsjnzDT, false);
  numBytes += cIf_init(&cIf_JQNnkCAA, false);
  numBytes += cIf_init(&cIf_NYOZtNqY, false);
  numBytes += cBinop_init(&cBinop_u0jYGUVA, 0.0f); // __eq
  numBytes += cVar_init_f(&cVar_6RDs48fS, 1.0f);
  numBytes += cVar_init_f(&cVar_s4vXQDHN, 0.0f);
  numBytes += cSlice_init(&cSlice_Tub4RRby, 1, -1);
  numBytes += cSlice_init(&cSlice_z1PYy6Fk, 1, -1);
  numBytes += cSlice_init(&cSlice_kWIMZmEE, 1, 1);
  numBytes += cSlice_init(&cSlice_Oq8Lzc5k, 0, 1);
  numBytes += cVar_init_f(&cVar_Q3ywzOJv, 0.0f);
  numBytes += cIf_init(&cIf_sr0A4Sdw, false);
  numBytes += cIf_init(&cIf_Bxgq9cfa, false);
  numBytes += cIf_init(&cIf_ClfUQ5iL, false);
  numBytes += cVar_init_f(&cVar_9zWWIijq, 0.0f);
  numBytes += cIf_init(&cIf_ihVttPMk, false);
  numBytes += cVar_init_f(&cVar_TZcPTXxg, 0.0f);
  numBytes += cIf_init(&cIf_zqkIB5Ez, false);
  numBytes += cBinop_init(&cBinop_oGZofClE, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_C6VnRRJO, 4.0f);
  numBytes += cTabread_init(&cTabread_AEUlpSuv, &hTable_GssIKZPv); // 1011-used
  numBytes += cSlice_init(&cSlice_87vpm7W3, 1, -1);
  numBytes += cVar_init_s(&cVar_16VqhRNH, "1011-used");
  numBytes += cBinop_init(&cBinop_6bg7A7qx, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_FGb9foUy, &hTable_MFv7IEzq); // 1011-ids
  numBytes += cSlice_init(&cSlice_Y2s53bDQ, 1, -1);
  numBytes += cVar_init_s(&cVar_CDwDOcx3, "1011-ids");
  numBytes += cBinop_init(&cBinop_2L6G78XI, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_L0M5j1nf, 0.0f);
  numBytes += cSlice_init(&cSlice_OneMkb08, 1, 1);
  numBytes += cSlice_init(&cSlice_a7ecUdnz, 0, 1);
  numBytes += cTabread_init(&cTabread_MpFY0HZc, &hTable_GDWa1XQ3); // 1011-pitches
  numBytes += cSlice_init(&cSlice_5tD150Ri, 1, -1);
  numBytes += cVar_init_s(&cVar_r819D9Ec, "1011-pitches");
  numBytes += cBinop_init(&cBinop_3sjkcMXm, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_qck7iEtX, 0.0f);
  numBytes += cVar_init_f(&cVar_YqBOqqOX, 0.0f);
  numBytes += cIf_init(&cIf_IVFveHER, false);
  numBytes += cTabwrite_init(&cTabwrite_CNl76jXS, &hTable_GssIKZPv); // 1011-used
  numBytes += cSlice_init(&cSlice_Km5FcRM4, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_YOp2pK0x, &hTable_MFv7IEzq); // 1011-ids
  numBytes += cSlice_init(&cSlice_6XGsKwJb, 1, -1);
  numBytes += cVar_init_f(&cVar_1v4KprZB, 0.0f);
  numBytes += cVar_init_f(&cVar_wJhjUNwT, 0.0f);
  numBytes += cSlice_init(&cSlice_NH1Gggi9, 1, 1);
  numBytes += cSlice_init(&cSlice_lu8pQhb7, 0, 1);
  numBytes += cPack_init(&cPack_OLN4o9vU, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_Ej2pp8DY, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_BRG8YCV8, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_HxsFN6OS, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_qBQzIi7S, 0.0f); // __lt
  numBytes += cIf_init(&cIf_ytWQRwNO, false);
  numBytes += cVar_init_f(&cVar_l6aAqxom, 0.0f);
  numBytes += cIf_init(&cIf_ypPqjst6, false);
  numBytes += cVar_init_f(&cVar_dS0n36x3, 0.0f);
  numBytes += cIf_init(&cIf_U3oXN1tQ, false);
  numBytes += cBinop_init(&cBinop_K23hPcNZ, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_zjGkNgke, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_WcQmuNxY, &hTable_GssIKZPv); // 1011-used
  numBytes += cSlice_init(&cSlice_HQBMd1kS, 1, -1);
  numBytes += cTabread_init(&cTabread_TsLNjqnf, &hTable_GssIKZPv); // 1011-used
  numBytes += cSlice_init(&cSlice_ds5AtnTq, 1, -1);
  numBytes += cVar_init_s(&cVar_YojZQDYW, "1011-used");
  numBytes += cBinop_init(&cBinop_o8nxB8nC, 0.0f); // __min
  numBytes += cIf_init(&cIf_VCHNZJiY, false);
  numBytes += cTabread_init(&cTabread_Vzmzp9JK, &hTable_GDWa1XQ3); // 1011-pitches
  numBytes += cSlice_init(&cSlice_OaSbr3aK, 1, -1);
  numBytes += cVar_init_s(&cVar_VStnTsTX, "1011-pitches");
  numBytes += cBinop_init(&cBinop_qXcqTOad, 0.0f); // __min
  numBytes += cIf_init(&cIf_Xf1se2Db, false);
  numBytes += cVar_init_f(&cVar_HtqHGvLP, 0.0f);
  numBytes += cIf_init(&cIf_KcIfSdX3, false);
  numBytes += cVar_init_f(&cVar_4umd0xWE, 0.0f);
  numBytes += cIf_init(&cIf_kVdKgDyL, false);
  numBytes += cBinop_init(&cBinop_S8cVnZ6W, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_98L1ElCl, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_H3ZsDSq5, &hTable_GssIKZPv); // 1011-used
  numBytes += cSlice_init(&cSlice_sx77rV83, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_PXj2JvfC, &hTable_MFv7IEzq); // 1011-ids
  numBytes += cSlice_init(&cSlice_eMXll9Al, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_nwSXxat4, &hTable_GDWa1XQ3); // 1011-pitches
  numBytes += cSlice_init(&cSlice_lcnByCqk, 1, -1);
  numBytes += cIf_init(&cIf_NddO1mto, false);
  numBytes += cVar_init_f(&cVar_iqx4WTXj, 0.0f);
  numBytes += cIf_init(&cIf_ePjFneKg, false);
  numBytes += cVar_init_f(&cVar_EOpuuhVI, 0.0f);
  numBytes += cIf_init(&cIf_azJ3IpEX, false);
  numBytes += cBinop_init(&cBinop_85yKNSU1, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_dxCtqdpW, 4.0f);
  numBytes += cVar_init_f(&cVar_5tJAOw1B, 0.0f);
  numBytes += cIf_init(&cIf_aGR4BfIC, false);
  numBytes += cVar_init_f(&cVar_WDUUCzpl, 0.0f);
  numBytes += cVar_init_f(&cVar_LrJRdCDh, 0.0f);
  numBytes += cVar_init_f(&cVar_aB63IU2h, 0.0f);
  numBytes += cIf_init(&cIf_0uLyjm07, false);
  numBytes += cIf_init(&cIf_4pZatWuY, false);
  numBytes += cPack_init(&cPack_uL0TR6OD, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_3NlfnqKi, 0.0f);
  numBytes += cSlice_init(&cSlice_y2g0xm3P, 1, 1);
  numBytes += cSlice_init(&cSlice_6nsyC4Dh, 0, 1);
  numBytes += cVar_init_f(&cVar_aredo9yh, 0.0f);
  numBytes += cIf_init(&cIf_MNrZ11df, false);
  numBytes += cVar_init_f(&cVar_ZCMqole4, 0.0f);
  numBytes += cVar_init_f(&cVar_ppbvUWKZ, 0.0f);
  numBytes += cTabread_init(&cTabread_JoAvpBwk, &hTable_GssIKZPv); // 1011-used
  numBytes += cSlice_init(&cSlice_u4xV6eaE, 1, -1);
  numBytes += cVar_init_s(&cVar_EmhsHA8c, "1011-used");
  numBytes += cBinop_init(&cBinop_vXmFf40I, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_3h6WhXfn, &hTable_MFv7IEzq); // 1011-ids
  numBytes += cSlice_init(&cSlice_Kx512YOR, 1, -1);
  numBytes += cVar_init_s(&cVar_tquBBBk2, "1011-ids");
  numBytes += cBinop_init(&cBinop_HtEHwo6M, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_3xGSlEZN, &hTable_GDWa1XQ3); // 1011-pitches
  numBytes += cSlice_init(&cSlice_oLiAtCPH, 1, -1);
  numBytes += cTabread_init(&cTabread_AZphACw2, &hTable_GDWa1XQ3); // 1011-pitches
  numBytes += cSlice_init(&cSlice_swHECMZQ, 1, -1);
  numBytes += cVar_init_s(&cVar_Ya1C8Puq, "1011-pitches");
  numBytes += cBinop_init(&cBinop_IobBNgms, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_BQmKrtjQ, &hTable_GDWa1XQ3); // 1011-pitches
  numBytes += cSlice_init(&cSlice_bUIAOAdL, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_5gcp5YHp, &hTable_GssIKZPv); // 1011-used
  numBytes += cSlice_init(&cSlice_RM19OxY2, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_y2vRLMIs, &hTable_MFv7IEzq); // 1011-ids
  numBytes += cSlice_init(&cSlice_Arj7vfFp, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_hikOkNyL, &hTable_MFv7IEzq); // 1011-ids
  numBytes += cSlice_init(&cSlice_jCAnmndA, 1, -1);
  numBytes += cVar_init_f(&cVar_cDECvFXR, 0.0f);
  numBytes += cTabwrite_init(&cTabwrite_OvWwoT6M, &hTable_GssIKZPv); // 1011-used
  numBytes += cSlice_init(&cSlice_5OucC5Xj, 1, -1);
  numBytes += cVar_init_f(&cVar_kEvnyOKj, 0.0f);
  numBytes += cSlice_init(&cSlice_BlLNoZ76, 1, 1);
  numBytes += cSlice_init(&cSlice_UGzYfsjm, 0, 1);
  numBytes += cVar_init_f(&cVar_Tlrnt22A, 0.0f);
  numBytes += cBinop_init(&cBinop_0qB7ZGdo, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_iOCyJ5qb, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_DJfFWGZU, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_3HYggn0n, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_6k0nQ9zn, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_BTWj6pzn, 65535.0f); // __unimod
  numBytes += hTable_init(&hTable_GDWa1XQ3, 4);
  numBytes += hTable_init(&hTable_GssIKZPv, 4);
  numBytes += hTable_init(&hTable_MFv7IEzq, 4);
  numBytes += cPack_init(&cPack_dHEG1i68, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_dR3Dvqp5, 1, -1);
  numBytes += cSlice_init(&cSlice_TVIMoPjA, 1, -1);
  numBytes += cSlice_init(&cSlice_saNTIlW6, 1, -1);
  numBytes += cSlice_init(&cSlice_AGQ0njo1, 1, -1);
  numBytes += cSlice_init(&cSlice_xen1cRyp, 1, 1);
  numBytes += cSlice_init(&cSlice_qhonfTcK, 0, 1);
  numBytes += cBinop_init(&cBinop_i9p8q7sH, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_ta2iqHlA, 22050.0f);
  numBytes += cBinop_init(&cBinop_yqED9YGo, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_c7biIJqK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_y9ooBJe6, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_0oYi1unn, 22050.0f);
  numBytes += cBinop_init(&cBinop_Cf9qoBGH, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_KMX3zdk1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_DRlU35hG, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_vbZ1h8NT, 1, 1);
  numBytes += cSlice_init(&cSlice_OWpeF5hr, 0, 1);
  numBytes += cBinop_init(&cBinop_BIyI3MO8, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_Pp0HvnTQ, 22050.0f);
  numBytes += cBinop_init(&cBinop_CYBaiXlh, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_xvK6e0tY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qgHHrE1t, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5IdiHe1E, 22050.0f);
  numBytes += cBinop_init(&cBinop_Zy3BtOQg, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_UkQUFIrl, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_f3YFv4aI, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_oiFuUeyP, 1, 1);
  numBytes += cSlice_init(&cSlice_kllGQR0C, 0, 1);
  numBytes += cBinop_init(&cBinop_LPnqYCQO, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_o6zYLr0f, 22050.0f);
  numBytes += cBinop_init(&cBinop_fcnGJg6Z, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_dRmrAqyK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NAaXX6zO, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_fnu1Rqy9, 22050.0f);
  numBytes += cBinop_init(&cBinop_xkrptTh0, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_BMfGRQ3t, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_INpzyiHX, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_9Q5Sv9S6, 1, 1);
  numBytes += cSlice_init(&cSlice_Xpl8S4ua, 0, 1);
  numBytes += cBinop_init(&cBinop_5TBYIPOk, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_072kmFLc, 22050.0f);
  numBytes += cBinop_init(&cBinop_x1ksKTEf, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_IH9pTizk, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9C8zdXo6, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Ba1eomVS, 22050.0f);
  numBytes += cBinop_init(&cBinop_Xrfkov59, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_ZDY0vl7D, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cxbla4d6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TAEegDLT, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_pdpoly::~Heavy_pdpoly() {
  cPack_free(&cPack_OLN4o9vU);
  cPack_free(&cPack_uL0TR6OD);
  hTable_free(&hTable_GDWa1XQ3);
  hTable_free(&hTable_GssIKZPv);
  hTable_free(&hTable_MFv7IEzq);
  cPack_free(&cPack_dHEG1i68);
}

HvTable *Heavy_pdpoly::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x7B847FB6: return &hTable_GDWa1XQ3; // 1011-pitches
    case 0xA0EFCB1D: return &hTable_GssIKZPv; // 1011-used
    case 0x73137BF4: return &hTable_MFv7IEzq; // 1011-ids
    default: return nullptr;
  }
}

void Heavy_pdpoly::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x7EA4AD17: { // 1011-currentVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YofLFB0u_sendMessage);
      break;
    }
    case 0x9B1DF8F3: { // 1011-indexOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_q9LPDzaF_sendMessage);
      break;
    }
    case 0xF7855D22: { // 1011-indexOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nM3qG6Zd_sendMessage);
      break;
    }
    case 0xEB1BA925: { // 1011-isFirstOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2Sd5P2ea_sendMessage);
      break;
    }
    case 0x7426D59: { // 1011-isFirstOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tFajeYh1_sendMessage);
      break;
    }
    case 0x199E738B: { // 1011-maxVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gJaGhg8W_sendMessage);
      break;
    }
    case 0x979E98C4: { // 1011-shouldSteal
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dVOTKSN1_sendMessage);
      break;
    }
    case 0xDB67A714: { // 1011-voiceId++
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BfF2cQtN_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LBoBrNTy_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wF8y98oy_sendMessage);
      break;
    }
    case 0xF89F9F3E: { // cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3MLwFsB5_sendMessage);
      break;
    }
    case 0xC2C62B6: { // vcut
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cAOo0Yv2_sendMessage);
      break;
    }
    case 0xB1642755: { // volume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wjSsmZCX_sendMessage);
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


void Heavy_pdpoly::cSlice_QOjO4xj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_NjsrhPJB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_qJk4Wdcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_JQNnkCAA, 0, m, &cIf_JQNnkCAA_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_9keZMPFL, 0, m, &cIf_9keZMPFL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_goGccCX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_NYOZtNqY, 0, m, &cIf_NYOZtNqY_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_yGsjnzDT, 0, m, &cIf_yGsjnzDT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_cZD5jLrO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_G9nCYZNl_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_WHuMf71b, 0, m, &cIf_WHuMf71b_sendMessage);
}

void Heavy_pdpoly::cUnop_aP1ZQLYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_GsovPalZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_u0jYGUVA, HV_BINOP_EQ, 1, m, &cBinop_u0jYGUVA_sendMessage);
}

void Heavy_pdpoly::cUnop_ldEecEvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_GsovPalZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_u0jYGUVA, HV_BINOP_EQ, 1, m, &cBinop_u0jYGUVA_sendMessage);
}

void Heavy_pdpoly::cIf_WHuMf71b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_ldEecEvn_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_aP1ZQLYE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_G9nCYZNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WHuMf71b, 1, m, &cIf_WHuMf71b_sendMessage);
}

void Heavy_pdpoly::cIf_9keZMPFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_Q3ywzOJv, 0, m, &cVar_Q3ywzOJv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_yGsjnzDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_K7sqBg7u_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_JQNnkCAA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_Q3ywzOJv, 0, m, &cVar_Q3ywzOJv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_NYOZtNqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_K7sqBg7u_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_NjsrhPJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u0jYGUVA, HV_BINOP_EQ, 0, m, &cBinop_u0jYGUVA_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_tgNTnWcZ_sendMessage);
}

void Heavy_pdpoly::cBinop_GsovPalZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YWUNbXPc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yPMjUpMx_sendMessage);
}

void Heavy_pdpoly::cBinop_u0jYGUVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S6Tqy96N_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nisnZC2M_sendMessage);
}

void Heavy_pdpoly::cCast_nisnZC2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NYOZtNqY, 1, m, &cIf_NYOZtNqY_sendMessage);
}

void Heavy_pdpoly::cCast_S6Tqy96N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9keZMPFL, 1, m, &cIf_9keZMPFL_sendMessage);
}

void Heavy_pdpoly::cCast_yPMjUpMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yGsjnzDT, 1, m, &cIf_yGsjnzDT_sendMessage);
}

void Heavy_pdpoly::cCast_YWUNbXPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JQNnkCAA, 1, m, &cIf_JQNnkCAA_sendMessage);
}

void Heavy_pdpoly::cBinop_tgNTnWcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cVar_6RDs48fS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_TO10Op6h_sendMessage);
}

void Heavy_pdpoly::cVar_s4vXQDHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BTWj6pzn, HV_BINOP_MOD_UNIPOLAR, 0, m, &cBinop_BTWj6pzn_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_K7sqBg7u_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Tub4RRby, 0, m, &cSlice_Tub4RRby_sendMessage);
      break;
    }
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_z1PYy6Fk, 0, m, &cSlice_z1PYy6Fk_sendMessage);
      break;
    }
    default: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_kWIMZmEE, 0, m, &cSlice_kWIMZmEE_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Oq8Lzc5k, 0, m, &cSlice_Oq8Lzc5k_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_Tub4RRby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gqOHWVJf_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6IPw0NoY_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gqOHWVJf_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6IPw0NoY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_z1PYy6Fk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZrNJjgre_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qO4Wc5Lt_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZrNJjgre_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qO4Wc5Lt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_kWIMZmEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_Q3ywzOJv, 0, m, &cVar_Q3ywzOJv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_Oq8Lzc5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_sr0A4Sdw, 0, m, &cIf_sr0A4Sdw_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_Bxgq9cfa, 0, m, &cIf_Bxgq9cfa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_Q3ywzOJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uL0TR6OD, 1, m, &cPack_uL0TR6OD_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_OLN4o9vU, 1, m, &cPack_OLN4o9vU_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_cIHhkFUk_sendMessage);
}

void Heavy_pdpoly::cIf_sr0A4Sdw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iPEbQOoT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JMwP5EZh_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bc35JKxn_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_uL0TR6OD, 0, m, &cPack_uL0TR6OD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_Bxgq9cfa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_OLN4o9vU, 0, m, &cPack_OLN4o9vU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_ClfUQ5iL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZRZ9546g_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nMmF47wG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_9zWWIijq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TJNuhFwM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FppV9jak_sendMessage);
}

void Heavy_pdpoly::cIf_ihVttPMk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xdSpCUKw_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7tPoDml7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_9TcrTMeM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ihVttPMk, 1, m, &cIf_ihVttPMk_sendMessage);
}

void Heavy_pdpoly::cVar_TZcPTXxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_gKPVcn1T_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_zqkIB5Ez, 0, m, &cIf_zqkIB5Ez_sendMessage);
}

void Heavy_pdpoly::cUnop_vinHYvir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_9TcrTMeM_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ihVttPMk, 0, m, &cIf_ihVttPMk_sendMessage);
}

void Heavy_pdpoly::cUnop_Eaju4uzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_9TcrTMeM_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ihVttPMk, 0, m, &cIf_ihVttPMk_sendMessage);
}

void Heavy_pdpoly::cIf_zqkIB5Ez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_Eaju4uzG_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vinHYvir_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_gKPVcn1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zqkIB5Ez, 1, m, &cIf_zqkIB5Ez_sendMessage);
}

void Heavy_pdpoly::cCast_TJNuhFwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oGZofClE, HV_BINOP_LESS_THAN, 0, m, &cBinop_oGZofClE_sendMessage);
}

void Heavy_pdpoly::cCast_FppV9jak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ClfUQ5iL, 0, m, &cIf_ClfUQ5iL_sendMessage);
}

void Heavy_pdpoly::cBinop_oGZofClE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ClfUQ5iL, 1, m, &cIf_ClfUQ5iL_sendMessage);
}

void Heavy_pdpoly::cCast_xdSpCUKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oGZofClE, HV_BINOP_LESS_THAN, 1, m, &cBinop_oGZofClE_sendMessage);
}

void Heavy_pdpoly::cCast_7tPoDml7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XPo2xDTn_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_MUyCTkZS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9zWWIijq, 0, m, &cVar_9zWWIijq_sendMessage);
}

void Heavy_pdpoly::cMsg_XPo2xDTn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_9zWWIijq, 0, m, &cVar_9zWWIijq_sendMessage);
}

void Heavy_pdpoly::cCast_nMmF47wG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_MUyCTkZS_sendMessage);
}

void Heavy_pdpoly::cCast_ZRZ9546g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vlbAmNLF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wH4nysib_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uqVW8Kya_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OcllA7n1_sendMessage);
}

void Heavy_pdpoly::cVar_C6VnRRJO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TZcPTXxg, 0, m, &cVar_TZcPTXxg_sendMessage);
}

void Heavy_pdpoly::cTabread_AEUlpSuv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HxsFN6OS, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_HxsFN6OS_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_wq2NBODm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_87vpm7W3, 0, m, &cSlice_87vpm7W3_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jSrhy8q7_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fqa0tbp0_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_87vpm7W3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_AEUlpSuv, 1, m, &cTabread_AEUlpSuv_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_AEUlpSuv, 1, m, &cTabread_AEUlpSuv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_16VqhRNH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sLTbcK3R_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_Ebm8HzlX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Et6SER5H_sendMessage);
}

void Heavy_pdpoly::cBinop_Wu6SIC4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6bg7A7qx, HV_BINOP_MIN, 0, m, &cBinop_6bg7A7qx_sendMessage);
}

void Heavy_pdpoly::cCast_jSrhy8q7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_16VqhRNH, 0, m, &cVar_16VqhRNH_sendMessage);
}

void Heavy_pdpoly::cCast_fqa0tbp0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Wu6SIC4x_sendMessage);
}

void Heavy_pdpoly::cBinop_6bg7A7qx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_AEUlpSuv, 0, m, &cTabread_AEUlpSuv_sendMessage);
}

void Heavy_pdpoly::cMsg_sLTbcK3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ebm8HzlX_sendMessage);
}

void Heavy_pdpoly::cBinop_Et6SER5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6bg7A7qx, HV_BINOP_MIN, 1, m, &cBinop_6bg7A7qx_sendMessage);
}

void Heavy_pdpoly::cTabread_FGb9foUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IwPx68DR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PMFNlByg_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_F1rAxUGH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Y2s53bDQ, 0, m, &cSlice_Y2s53bDQ_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oWKYuSSC_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gJVQUPZX_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_Y2s53bDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_FGb9foUy, 1, m, &cTabread_FGb9foUy_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_FGb9foUy, 1, m, &cTabread_FGb9foUy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_CDwDOcx3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NraJoYiB_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_Y7fl4K4c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_buTLUQSy_sendMessage);
}

void Heavy_pdpoly::cBinop_Er0XcHds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2L6G78XI, HV_BINOP_MIN, 0, m, &cBinop_2L6G78XI_sendMessage);
}

void Heavy_pdpoly::cCast_oWKYuSSC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CDwDOcx3, 0, m, &cVar_CDwDOcx3_sendMessage);
}

void Heavy_pdpoly::cCast_gJVQUPZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Er0XcHds_sendMessage);
}

void Heavy_pdpoly::cBinop_2L6G78XI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_FGb9foUy, 0, m, &cTabread_FGb9foUy_sendMessage);
}

void Heavy_pdpoly::cMsg_NraJoYiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Y7fl4K4c_sendMessage);
}

void Heavy_pdpoly::cBinop_buTLUQSy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2L6G78XI, HV_BINOP_MIN, 1, m, &cBinop_2L6G78XI_sendMessage);
}

void Heavy_pdpoly::cVar_L0M5j1nf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_CNl76jXS, 1, m, &cTabwrite_CNl76jXS_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_YOp2pK0x, 1, m, &cTabwrite_YOp2pK0x_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wJhjUNwT, 1, m, &cVar_wJhjUNwT_sendMessage);
}

void Heavy_pdpoly::cSlice_OneMkb08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_pdpoly::cSlice_a7ecUdnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OsSh5pwC_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bQoZIhC8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_MpFY0HZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ej2pp8DY, HV_BINOP_EQ, 0, m, &cBinop_Ej2pp8DY_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_8zgC8Zib_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5tD150Ri, 0, m, &cSlice_5tD150Ri_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pvqFXfht_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xpcsPtwA_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_5tD150Ri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_MpFY0HZc, 1, m, &cTabread_MpFY0HZc_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_MpFY0HZc, 1, m, &cTabread_MpFY0HZc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_r819D9Ec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SxF3Y2Xb_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_6JrFvEc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_YOs3r6ce_sendMessage);
}

void Heavy_pdpoly::cBinop_HRvpT6XI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3sjkcMXm, HV_BINOP_MIN, 0, m, &cBinop_3sjkcMXm_sendMessage);
}

void Heavy_pdpoly::cCast_pvqFXfht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_r819D9Ec, 0, m, &cVar_r819D9Ec_sendMessage);
}

void Heavy_pdpoly::cCast_xpcsPtwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_HRvpT6XI_sendMessage);
}

void Heavy_pdpoly::cBinop_3sjkcMXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_MpFY0HZc, 0, m, &cTabread_MpFY0HZc_sendMessage);
}

void Heavy_pdpoly::cMsg_SxF3Y2Xb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6JrFvEc1_sendMessage);
}

void Heavy_pdpoly::cBinop_YOs3r6ce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3sjkcMXm, HV_BINOP_MIN, 1, m, &cBinop_3sjkcMXm_sendMessage);
}

void Heavy_pdpoly::cVar_qck7iEtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qBQzIi7S, HV_BINOP_LESS_THAN, 1, m, &cBinop_qBQzIi7S_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_IhtIl9Uj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yRFWtNFz_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_yRFWtNFz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fGD4oeL1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Bq1S6Qay_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7qVPdBdt_sendMessage);
}

void Heavy_pdpoly::cVar_YqBOqqOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qBQzIi7S, HV_BINOP_LESS_THAN, 1, m, &cBinop_qBQzIi7S_sendMessage);
}

void Heavy_pdpoly::cIf_IVFveHER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VaUW7Jj2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M5RyICN2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Xmcydf1G_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_NH1Gggi9, 0, m, &cSlice_NH1Gggi9_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_lu8pQhb7, 0, m, &cSlice_lu8pQhb7_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mz03T41v_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_CNl76jXS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_H1EVMb7C_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Km5FcRM4, 0, m, &cSlice_Km5FcRM4_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_CNl76jXS, 0, m, &cTabwrite_CNl76jXS_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_Km5FcRM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_CNl76jXS, 2, m, &cTabwrite_CNl76jXS_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_CNl76jXS, 2, m, &cTabwrite_CNl76jXS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_YOp2pK0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_MbIRnyBu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6XGsKwJb, 0, m, &cSlice_6XGsKwJb_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_YOp2pK0x, 0, m, &cTabwrite_YOp2pK0x_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_6XGsKwJb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_YOp2pK0x, 2, m, &cTabwrite_YOp2pK0x_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_YOp2pK0x, 2, m, &cTabwrite_YOp2pK0x_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_1v4KprZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_MbIRnyBu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cVar_wJhjUNwT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_qAxC9aLk_sendMessage);
}

void Heavy_pdpoly::cSlice_NH1Gggi9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_pdpoly::cSlice_lu8pQhb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_dHEG1i68, 1, m, &cPack_dHEG1i68_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cPack_OLN4o9vU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q6hBEwRj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dceVUbZk_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OneMkb08, 0, m, &cSlice_OneMkb08_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_a7ecUdnz, 0, m, &cSlice_a7ecUdnz_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_IVFveHER, 0, m, &cIf_IVFveHER_sendMessage);
}

void Heavy_pdpoly::cCast_wH4nysib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_F1rAxUGH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_vlbAmNLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L0M5j1nf, 1, m, &cVar_L0M5j1nf_sendMessage);
}

void Heavy_pdpoly::cCast_OcllA7n1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8zgC8Zib_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_uqVW8Kya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_wq2NBODm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_EibhjqEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_IVFveHER, 1, m, &cIf_IVFveHER_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_L0M5j1nf, 0, m, &cVar_L0M5j1nf_sendMessage);
}

void Heavy_pdpoly::cMsg_AObMIFzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_IVFveHER, 1, m, &cIf_IVFveHER_sendMessage);
}

void Heavy_pdpoly::cCast_dceVUbZk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EibhjqEc_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_Q6hBEwRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qck7iEtX, 0, m, &cVar_qck7iEtX_sendMessage);
}

void Heavy_pdpoly::cCast_OsSh5pwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ej2pp8DY, HV_BINOP_EQ, 1, m, &cBinop_Ej2pp8DY_sendMessage);
}

void Heavy_pdpoly::cCast_bQoZIhC8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_C6VnRRJO, 0, m, &cVar_C6VnRRJO_sendMessage);
}

void Heavy_pdpoly::cBinop_Ej2pp8DY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BRG8YCV8, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_BRG8YCV8_sendMessage);
}

void Heavy_pdpoly::cBinop_BRG8YCV8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_IhtIl9Uj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_HxsFN6OS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BRG8YCV8, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_BRG8YCV8_sendMessage);
}

void Heavy_pdpoly::cBinop_qBQzIi7S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HxsFN6OS, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_HxsFN6OS_sendMessage);
}

void Heavy_pdpoly::cCast_Bq1S6Qay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AObMIFzh_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_fGD4oeL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YqBOqqOX, 0, m, &cVar_YqBOqqOX_sendMessage);
}

void Heavy_pdpoly::cCast_7qVPdBdt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L0M5j1nf, 0, m, &cVar_L0M5j1nf_sendMessage);
}

void Heavy_pdpoly::cCast_IwPx68DR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YqBOqqOX, 1, m, &cVar_YqBOqqOX_sendMessage);
}

void Heavy_pdpoly::cCast_PMFNlByg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qBQzIi7S, HV_BINOP_LESS_THAN, 0, m, &cBinop_qBQzIi7S_sendMessage);
}

void Heavy_pdpoly::cCast_aq9lygDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1v4KprZB, 0, m, &cVar_1v4KprZB_sendMessage);
}

void Heavy_pdpoly::cCast_HxBViqrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MIzbde4f_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_MIzbde4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BfF2cQtN_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_M5RyICN2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HxBViqrr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aq9lygDa_sendMessage);
}

void Heavy_pdpoly::cCast_VaUW7Jj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s9tKcFWZ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_s9tKcFWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_H1EVMb7C_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_Xmcydf1G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zPKWEofX_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_mz03T41v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wJhjUNwT, 0, m, &cVar_wJhjUNwT_sendMessage);
}

void Heavy_pdpoly::cMsg_zPKWEofX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_dHEG1i68, 2, m, &cPack_dHEG1i68_sendMessage);
}

void Heavy_pdpoly::cIf_ytWQRwNO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hJwkSExR_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7PcHsESR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_l6aAqxom_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7tS8K3tY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3uXO1uhQ_sendMessage);
}

void Heavy_pdpoly::cIf_ypPqjst6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u2Ca6TGb_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3V8CJeYv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_KSWjrRH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ypPqjst6, 1, m, &cIf_ypPqjst6_sendMessage);
}

void Heavy_pdpoly::cVar_dS0n36x3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_qGSdhQD9_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_U3oXN1tQ, 0, m, &cIf_U3oXN1tQ_sendMessage);
}

void Heavy_pdpoly::cUnop_ahGrdxT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_KSWjrRH2_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ypPqjst6, 0, m, &cIf_ypPqjst6_sendMessage);
}

void Heavy_pdpoly::cUnop_v934djZf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_KSWjrRH2_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ypPqjst6, 0, m, &cIf_ypPqjst6_sendMessage);
}

void Heavy_pdpoly::cIf_U3oXN1tQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_v934djZf_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ahGrdxT0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_qGSdhQD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_U3oXN1tQ, 1, m, &cIf_U3oXN1tQ_sendMessage);
}

void Heavy_pdpoly::cCast_7tS8K3tY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K23hPcNZ, HV_BINOP_LESS_THAN, 0, m, &cBinop_K23hPcNZ_sendMessage);
}

void Heavy_pdpoly::cCast_3uXO1uhQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ytWQRwNO, 0, m, &cIf_ytWQRwNO_sendMessage);
}

void Heavy_pdpoly::cBinop_K23hPcNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ytWQRwNO, 1, m, &cIf_ytWQRwNO_sendMessage);
}

void Heavy_pdpoly::cCast_u2Ca6TGb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K23hPcNZ, HV_BINOP_LESS_THAN, 1, m, &cBinop_K23hPcNZ_sendMessage);
}

void Heavy_pdpoly::cCast_3V8CJeYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pIETJm1n_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_yOZjnmdI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_l6aAqxom, 0, m, &cVar_l6aAqxom_sendMessage);
}

void Heavy_pdpoly::cMsg_pIETJm1n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_l6aAqxom, 0, m, &cVar_l6aAqxom_sendMessage);
}

void Heavy_pdpoly::cCast_hJwkSExR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mi1E0vZ5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iwCPIER8_sendMessage);
}

void Heavy_pdpoly::cCast_7PcHsESR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_yOZjnmdI_sendMessage);
}

void Heavy_pdpoly::cVar_zjGkNgke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dS0n36x3, 0, m, &cVar_dS0n36x3_sendMessage);
}

void Heavy_pdpoly::cTabwrite_WcQmuNxY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_hMMQ7zOz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_HQBMd1kS, 0, m, &cSlice_HQBMd1kS_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_WcQmuNxY, 0, m, &cTabwrite_WcQmuNxY_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_HQBMd1kS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_WcQmuNxY, 2, m, &cTabwrite_WcQmuNxY_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_WcQmuNxY, 2, m, &cTabwrite_WcQmuNxY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_TsLNjqnf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_4IYhsXGh_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_SF2Q34D1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ds5AtnTq, 0, m, &cSlice_ds5AtnTq_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GpBrtiu6_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YAOF6KfB_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_ds5AtnTq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_TsLNjqnf, 1, m, &cTabread_TsLNjqnf_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_TsLNjqnf, 1, m, &cTabread_TsLNjqnf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_YojZQDYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Vt96Ordz_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_8Tzx0kBQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_PstpBV8e_sendMessage);
}

void Heavy_pdpoly::cBinop_9y2hxKEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o8nxB8nC, HV_BINOP_MIN, 0, m, &cBinop_o8nxB8nC_sendMessage);
}

void Heavy_pdpoly::cCast_GpBrtiu6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YojZQDYW, 0, m, &cVar_YojZQDYW_sendMessage);
}

void Heavy_pdpoly::cCast_YAOF6KfB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_9y2hxKEd_sendMessage);
}

void Heavy_pdpoly::cBinop_o8nxB8nC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_TsLNjqnf, 0, m, &cTabread_TsLNjqnf_sendMessage);
}

void Heavy_pdpoly::cMsg_Vt96Ordz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8Tzx0kBQ_sendMessage);
}

void Heavy_pdpoly::cBinop_PstpBV8e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o8nxB8nC, HV_BINOP_MIN, 1, m, &cBinop_o8nxB8nC_sendMessage);
}

void Heavy_pdpoly::cIf_VCHNZJiY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NvIdo25L_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FIWdlHul_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cdFASV1S_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QusMS5sU_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5bzRCzve_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_Vzmzp9JK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dHEG1i68, 1, m, &cPack_dHEG1i68_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_pVHPijzR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_OaSbr3aK, 0, m, &cSlice_OaSbr3aK_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rS4PWr73_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BMwD9c3X_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_OaSbr3aK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_Vzmzp9JK, 1, m, &cTabread_Vzmzp9JK_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_Vzmzp9JK, 1, m, &cTabread_Vzmzp9JK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_VStnTsTX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kGHy5Zw7_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_zmWL28tg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Mbjons0D_sendMessage);
}

void Heavy_pdpoly::cBinop_cSdGQglc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qXcqTOad, HV_BINOP_MIN, 0, m, &cBinop_qXcqTOad_sendMessage);
}

void Heavy_pdpoly::cCast_rS4PWr73_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VStnTsTX, 0, m, &cVar_VStnTsTX_sendMessage);
}

void Heavy_pdpoly::cCast_BMwD9c3X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_cSdGQglc_sendMessage);
}

void Heavy_pdpoly::cBinop_qXcqTOad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_Vzmzp9JK, 0, m, &cTabread_Vzmzp9JK_sendMessage);
}

void Heavy_pdpoly::cMsg_kGHy5Zw7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zmWL28tg_sendMessage);
}

void Heavy_pdpoly::cBinop_Mbjons0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qXcqTOad, HV_BINOP_MIN, 1, m, &cBinop_qXcqTOad_sendMessage);
}

void Heavy_pdpoly::cCast_6IPw0NoY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zjGkNgke, 0, m, &cVar_zjGkNgke_sendMessage);
}

void Heavy_pdpoly::cCast_gqOHWVJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a0a5P79G_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_a0a5P79G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_6kICExQ6_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_6kICExQ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BfF2cQtN_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_4IYhsXGh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VCHNZJiY, 1, m, &cIf_VCHNZJiY_sendMessage);
}

void Heavy_pdpoly::cCast_iwCPIER8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VCHNZJiY, 0, m, &cIf_VCHNZJiY_sendMessage);
}

void Heavy_pdpoly::cCast_mi1E0vZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SF2Q34D1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_t8kJQ3sE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_dHEG1i68, 2, m, &cPack_dHEG1i68_sendMessage);
}

void Heavy_pdpoly::cCast_QusMS5sU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dQNVB2Mu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XvaLANeu_sendMessage);
}

void Heavy_pdpoly::cCast_NvIdo25L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t8kJQ3sE_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_5bzRCzve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DgevstcO_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_cdFASV1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_qAxC9aLk_sendMessage);
}

void Heavy_pdpoly::cCast_FIWdlHul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_pVHPijzR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_XvaLANeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tLuXrAW0_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_dQNVB2Mu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_WcQmuNxY, 1, m, &cTabwrite_WcQmuNxY_sendMessage);
}

void Heavy_pdpoly::cMsg_tLuXrAW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_hMMQ7zOz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSend_DgevstcO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BfF2cQtN_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_Xf1se2Db_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NLB2WEX1_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yhtjPOzi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_HtqHGvLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GgpRv6di_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Muph5OGh_sendMessage);
}

void Heavy_pdpoly::cIf_KcIfSdX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4fyFCLHO_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xoQblUdZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_zL5zGDNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KcIfSdX3, 1, m, &cIf_KcIfSdX3_sendMessage);
}

void Heavy_pdpoly::cVar_4umd0xWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_MOeSHfv0_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_kVdKgDyL, 0, m, &cIf_kVdKgDyL_sendMessage);
}

void Heavy_pdpoly::cUnop_r7cgST93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_zL5zGDNK_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_KcIfSdX3, 0, m, &cIf_KcIfSdX3_sendMessage);
}

void Heavy_pdpoly::cUnop_qcMYCG9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_zL5zGDNK_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_KcIfSdX3, 0, m, &cIf_KcIfSdX3_sendMessage);
}

void Heavy_pdpoly::cIf_kVdKgDyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_qcMYCG9a_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_r7cgST93_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_MOeSHfv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kVdKgDyL, 1, m, &cIf_kVdKgDyL_sendMessage);
}

void Heavy_pdpoly::cCast_GgpRv6di_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S8cVnZ6W, HV_BINOP_LESS_THAN, 0, m, &cBinop_S8cVnZ6W_sendMessage);
}

void Heavy_pdpoly::cCast_Muph5OGh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Xf1se2Db, 0, m, &cIf_Xf1se2Db_sendMessage);
}

void Heavy_pdpoly::cBinop_S8cVnZ6W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Xf1se2Db, 1, m, &cIf_Xf1se2Db_sendMessage);
}

void Heavy_pdpoly::cCast_4fyFCLHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S8cVnZ6W, HV_BINOP_LESS_THAN, 1, m, &cBinop_S8cVnZ6W_sendMessage);
}

void Heavy_pdpoly::cCast_xoQblUdZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mKP17W08_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_X1FnWBBo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HtqHGvLP, 0, m, &cVar_HtqHGvLP_sendMessage);
}

void Heavy_pdpoly::cMsg_mKP17W08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_HtqHGvLP, 0, m, &cVar_HtqHGvLP_sendMessage);
}

void Heavy_pdpoly::cCast_yhtjPOzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_X1FnWBBo_sendMessage);
}

void Heavy_pdpoly::cCast_NLB2WEX1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_nwSXxat4, 1, m, &cTabwrite_nwSXxat4_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_PXj2JvfC, 1, m, &cTabwrite_PXj2JvfC_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_H3ZsDSq5, 1, m, &cTabwrite_H3ZsDSq5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mfIThUXT_sendMessage);
}

void Heavy_pdpoly::cVar_98L1ElCl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4umd0xWE, 0, m, &cVar_4umd0xWE_sendMessage);
}

void Heavy_pdpoly::cTabwrite_H3ZsDSq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_0k3aHVh5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_sx77rV83, 0, m, &cSlice_sx77rV83_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_H3ZsDSq5, 0, m, &cTabwrite_H3ZsDSq5_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_sx77rV83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_H3ZsDSq5, 2, m, &cTabwrite_H3ZsDSq5_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_H3ZsDSq5, 2, m, &cTabwrite_H3ZsDSq5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_PXj2JvfC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_AQfygOzW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_eMXll9Al, 0, m, &cSlice_eMXll9Al_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_PXj2JvfC, 0, m, &cTabwrite_PXj2JvfC_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_eMXll9Al_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_PXj2JvfC, 2, m, &cTabwrite_PXj2JvfC_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_PXj2JvfC, 2, m, &cTabwrite_PXj2JvfC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_nwSXxat4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_xFq2viCg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lcnByCqk, 0, m, &cSlice_lcnByCqk_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_nwSXxat4, 0, m, &cTabwrite_nwSXxat4_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_lcnByCqk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_nwSXxat4, 2, m, &cTabwrite_nwSXxat4_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_nwSXxat4, 2, m, &cTabwrite_nwSXxat4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cMsg_s4RhZIu7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_xFq2viCg_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_AQfygOzW_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_0k3aHVh5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_ZrNJjgre_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HK8z8ikl_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_qO4Wc5Lt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_98L1ElCl, 0, m, &cVar_98L1ElCl_sendMessage);
}

void Heavy_pdpoly::cMsg_HK8z8ikl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_e9qWZDRM_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_e9qWZDRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BfF2cQtN_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_mfIThUXT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s4RhZIu7_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_NddO1mto_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tXeTX7lZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dEkIkGKi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_iqx4WTXj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_c9DeL7u9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_svTJ1svZ_sendMessage);
}

void Heavy_pdpoly::cIf_ePjFneKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_14VKr5Pn_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BzS1iLzd_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_dGtHxymu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ePjFneKg, 1, m, &cIf_ePjFneKg_sendMessage);
}

void Heavy_pdpoly::cVar_EOpuuhVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_opEJBZVm_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_azJ3IpEX, 0, m, &cIf_azJ3IpEX_sendMessage);
}

void Heavy_pdpoly::cUnop_j4oic2O0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_dGtHxymu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ePjFneKg, 0, m, &cIf_ePjFneKg_sendMessage);
}

void Heavy_pdpoly::cUnop_VfAKphow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_dGtHxymu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ePjFneKg, 0, m, &cIf_ePjFneKg_sendMessage);
}

void Heavy_pdpoly::cIf_azJ3IpEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_VfAKphow_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_j4oic2O0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_opEJBZVm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_azJ3IpEX, 1, m, &cIf_azJ3IpEX_sendMessage);
}

void Heavy_pdpoly::cCast_svTJ1svZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NddO1mto, 0, m, &cIf_NddO1mto_sendMessage);
}

void Heavy_pdpoly::cCast_c9DeL7u9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_85yKNSU1, HV_BINOP_LESS_THAN, 0, m, &cBinop_85yKNSU1_sendMessage);
}

void Heavy_pdpoly::cBinop_85yKNSU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NddO1mto, 1, m, &cIf_NddO1mto_sendMessage);
}

void Heavy_pdpoly::cCast_14VKr5Pn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_85yKNSU1, HV_BINOP_LESS_THAN, 1, m, &cBinop_85yKNSU1_sendMessage);
}

void Heavy_pdpoly::cCast_BzS1iLzd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_K068Y5n2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_UNQcl3Xt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iqx4WTXj, 0, m, &cVar_iqx4WTXj_sendMessage);
}

void Heavy_pdpoly::cMsg_K068Y5n2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_iqx4WTXj, 0, m, &cVar_iqx4WTXj_sendMessage);
}

void Heavy_pdpoly::cCast_dEkIkGKi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_UNQcl3Xt_sendMessage);
}

void Heavy_pdpoly::cCast_tXeTX7lZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_F8j1FjoR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zAUXOg0k_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BcfYDJ1y_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fKMrNi65_sendMessage);
}

void Heavy_pdpoly::cVar_dxCtqdpW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EOpuuhVI, 0, m, &cVar_EOpuuhVI_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_FBDDGVLr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UwME4U33_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_UwME4U33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dh18O4xR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iUcUl5W6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_x0bv3Sca_sendMessage);
}

void Heavy_pdpoly::cVar_5tJAOw1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_P8dzbXOG_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_aGR4BfIC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_oXgm9fCb_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_WDUUCzpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_H0NwnthZ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSwitchcase_oXgm9fCb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Du10argh_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_Du10argh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NccsRR1F_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G5JpuiPr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AOutMmrz_sendMessage);
}

void Heavy_pdpoly::cVar_LrJRdCDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iOCyJ5qb, HV_BINOP_LESS_THAN, 1, m, &cBinop_iOCyJ5qb_sendMessage);
}

void Heavy_pdpoly::cVar_aB63IU2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3HYggn0n, HV_BINOP_LESS_THAN, 1, m, &cBinop_3HYggn0n_sendMessage);
}

void Heavy_pdpoly::cIf_0uLyjm07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_y2g0xm3P, 0, m, &cSlice_y2g0xm3P_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_6nsyC4Dh, 0, m, &cSlice_6nsyC4Dh_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_p2Zg2zTl_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QYgPKrjb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mtZNPOqD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_4pZatWuY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_t2r6fr5L_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_BlLNoZ76, 0, m, &cSlice_BlLNoZ76_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_UGzYfsjm, 0, m, &cSlice_UGzYfsjm_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EARH4FPa_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mUooX6Rc_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5uUaCvqT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cPack_uL0TR6OD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4pZatWuY, 0, m, &cIf_4pZatWuY_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_0uLyjm07, 0, m, &cIf_0uLyjm07_sendMessage);
}

void Heavy_pdpoly::cVar_3NlfnqKi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_qAxC9aLk_sendMessage);
}

void Heavy_pdpoly::cSlice_y2g0xm3P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_dHEG1i68, 2, m, &cPack_dHEG1i68_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_6nsyC4Dh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_RbkDIbGD_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_dHEG1i68, 1, m, &cPack_dHEG1i68_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_aredo9yh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_qAxC9aLk_sendMessage);
}

void Heavy_pdpoly::cIf_MNrZ11df_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_4pZatWuY, 1, m, &cIf_4pZatWuY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_ZCMqole4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cjTBxlFr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cVar_ppbvUWKZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qB2Bee5z_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cTabread_JoAvpBwk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_N4m8d7i2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d7TGQ2TI_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_efN05WEf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_u4xV6eaE, 0, m, &cSlice_u4xV6eaE_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_f5PglhNp_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_i42OhF6u_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_u4xV6eaE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_JoAvpBwk, 1, m, &cTabread_JoAvpBwk_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_JoAvpBwk, 1, m, &cTabread_JoAvpBwk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_EmhsHA8c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mCExj9yV_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_15lcYRRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_l9rIK0cx_sendMessage);
}

void Heavy_pdpoly::cBinop_Dhc6huUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vXmFf40I, HV_BINOP_MIN, 0, m, &cBinop_vXmFf40I_sendMessage);
}

void Heavy_pdpoly::cCast_i42OhF6u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Dhc6huUU_sendMessage);
}

void Heavy_pdpoly::cCast_f5PglhNp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EmhsHA8c, 0, m, &cVar_EmhsHA8c_sendMessage);
}

void Heavy_pdpoly::cBinop_vXmFf40I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_JoAvpBwk, 0, m, &cTabread_JoAvpBwk_sendMessage);
}

void Heavy_pdpoly::cMsg_mCExj9yV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_15lcYRRS_sendMessage);
}

void Heavy_pdpoly::cBinop_l9rIK0cx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vXmFf40I, HV_BINOP_MIN, 1, m, &cBinop_vXmFf40I_sendMessage);
}

void Heavy_pdpoly::cTabread_3h6WhXfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3kEPd78u_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DO9YqE37_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aIlE37Q7_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_gdynETvN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Kx512YOR, 0, m, &cSlice_Kx512YOR_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tB6EbNWL_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BvMhUkrG_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_Kx512YOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_3h6WhXfn, 1, m, &cTabread_3h6WhXfn_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_3h6WhXfn, 1, m, &cTabread_3h6WhXfn_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_tquBBBk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PNQSE8Cq_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_yPWGG8M8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZwWsLPCM_sendMessage);
}

void Heavy_pdpoly::cBinop_gcoR0NOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HtEHwo6M, HV_BINOP_MIN, 0, m, &cBinop_HtEHwo6M_sendMessage);
}

void Heavy_pdpoly::cCast_BvMhUkrG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gcoR0NOo_sendMessage);
}

void Heavy_pdpoly::cCast_tB6EbNWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tquBBBk2, 0, m, &cVar_tquBBBk2_sendMessage);
}

void Heavy_pdpoly::cBinop_HtEHwo6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_3h6WhXfn, 0, m, &cTabread_3h6WhXfn_sendMessage);
}

void Heavy_pdpoly::cMsg_PNQSE8Cq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yPWGG8M8_sendMessage);
}

void Heavy_pdpoly::cBinop_ZwWsLPCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HtEHwo6M, HV_BINOP_MIN, 1, m, &cBinop_HtEHwo6M_sendMessage);
}

void Heavy_pdpoly::cTabwrite_3xGSlEZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_WtX8AgGm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_oLiAtCPH, 0, m, &cSlice_oLiAtCPH_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_3xGSlEZN, 0, m, &cTabwrite_3xGSlEZN_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_oLiAtCPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_3xGSlEZN, 2, m, &cTabwrite_3xGSlEZN_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_3xGSlEZN, 2, m, &cTabwrite_3xGSlEZN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_AZphACw2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dHEG1i68, 1, m, &cPack_dHEG1i68_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_cjTBxlFr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_swHECMZQ, 0, m, &cSlice_swHECMZQ_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M59usQNS_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gqdrD7dD_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_swHECMZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_AZphACw2, 1, m, &cTabread_AZphACw2_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_AZphACw2, 1, m, &cTabread_AZphACw2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_Ya1C8Puq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NBk3ncwW_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_oj48xqvm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_9nkJgYIc_sendMessage);
}

void Heavy_pdpoly::cBinop_4cp2pX5a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IobBNgms, HV_BINOP_MIN, 0, m, &cBinop_IobBNgms_sendMessage);
}

void Heavy_pdpoly::cCast_M59usQNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ya1C8Puq, 0, m, &cVar_Ya1C8Puq_sendMessage);
}

void Heavy_pdpoly::cCast_gqdrD7dD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_4cp2pX5a_sendMessage);
}

void Heavy_pdpoly::cBinop_IobBNgms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_AZphACw2, 0, m, &cTabread_AZphACw2_sendMessage);
}

void Heavy_pdpoly::cMsg_NBk3ncwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oj48xqvm_sendMessage);
}

void Heavy_pdpoly::cBinop_9nkJgYIc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IobBNgms, HV_BINOP_MIN, 1, m, &cBinop_IobBNgms_sendMessage);
}

void Heavy_pdpoly::cTabwrite_BQmKrtjQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_RbkDIbGD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_bUIAOAdL, 0, m, &cSlice_bUIAOAdL_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_BQmKrtjQ, 0, m, &cTabwrite_BQmKrtjQ_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_bUIAOAdL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_BQmKrtjQ, 2, m, &cTabwrite_BQmKrtjQ_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_BQmKrtjQ, 2, m, &cTabwrite_BQmKrtjQ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_5gcp5YHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_0JkJgNuo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_RM19OxY2, 0, m, &cSlice_RM19OxY2_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_5gcp5YHp, 0, m, &cTabwrite_5gcp5YHp_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_RM19OxY2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_5gcp5YHp, 2, m, &cTabwrite_5gcp5YHp_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_5gcp5YHp, 2, m, &cTabwrite_5gcp5YHp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_y2vRLMIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_qB2Bee5z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Arj7vfFp, 0, m, &cSlice_Arj7vfFp_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_y2vRLMIs, 0, m, &cTabwrite_y2vRLMIs_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_Arj7vfFp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_y2vRLMIs, 2, m, &cTabwrite_y2vRLMIs_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_y2vRLMIs, 2, m, &cTabwrite_y2vRLMIs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_hikOkNyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_G9dOKL4o_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jCAnmndA, 0, m, &cSlice_jCAnmndA_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_hikOkNyL, 0, m, &cTabwrite_hikOkNyL_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_jCAnmndA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_hikOkNyL, 2, m, &cTabwrite_hikOkNyL_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_hikOkNyL, 2, m, &cTabwrite_hikOkNyL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_cDECvFXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_G9dOKL4o_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cTabwrite_OvWwoT6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_3Es5pY9p_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5OucC5Xj, 0, m, &cSlice_5OucC5Xj_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_OvWwoT6M, 0, m, &cTabwrite_OvWwoT6M_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_5OucC5Xj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_OvWwoT6M, 2, m, &cTabwrite_OvWwoT6M_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_OvWwoT6M, 2, m, &cTabwrite_OvWwoT6M_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_kEvnyOKj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Wbmzi5u6_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vIvqBTQI_sendMessage);
}

void Heavy_pdpoly::cSlice_BlLNoZ76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_dHEG1i68, 2, m, &cPack_dHEG1i68_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_UGzYfsjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_WtX8AgGm_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_dHEG1i68, 1, m, &cPack_dHEG1i68_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_Tlrnt22A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6k0nQ9zn, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_6k0nQ9zn_sendMessage);
}

void Heavy_pdpoly::cBinop_0qB7ZGdo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_l2k6dOOm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rICmpPly_sendMessage);
}

void Heavy_pdpoly::cBinop_iOCyJ5qb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DJfFWGZU, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_DJfFWGZU_sendMessage);
}

void Heavy_pdpoly::cCast_F8j1FjoR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5tJAOw1B, 1, m, &cVar_5tJAOw1B_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WDUUCzpl, 1, m, &cVar_WDUUCzpl_sendMessage);
}

void Heavy_pdpoly::cCast_zAUXOg0k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_gdynETvN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_BcfYDJ1y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_efN05WEf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_fKMrNi65_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSend_P8dzbXOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_nM3qG6Zd_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_d7TGQ2TI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_CzFGU8uU_sendMessage);
}

void Heavy_pdpoly::cCast_N4m8d7i2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0qB7ZGdo, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_0qB7ZGdo_sendMessage);
}

void Heavy_pdpoly::cBinop_DJfFWGZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aGR4BfIC, 0, m, &cIf_aGR4BfIC_sendMessage);
}

void Heavy_pdpoly::cBinop_CzFGU8uU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DJfFWGZU, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_DJfFWGZU_sendMessage);
}

void Heavy_pdpoly::cCast_l2k6dOOm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_FBDDGVLr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_rICmpPly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Hww6A8mT_sendMessage);
}

void Heavy_pdpoly::cBinop_Hww6A8mT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_aGR4BfIC, 1, m, &cIf_aGR4BfIC_sendMessage);
}

void Heavy_pdpoly::cSend_H0NwnthZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_q9LPDzaF_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_VVY49j0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_nM3qG6Zd_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_0JbOhNaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_q9LPDzaF_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_bc35JKxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dxCtqdpW, 0, m, &cVar_dxCtqdpW_sendMessage);
}

void Heavy_pdpoly::cCast_JMwP5EZh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kEvnyOKj, 0, m, &cVar_kEvnyOKj_sendMessage);
}

void Heavy_pdpoly::cCast_iPEbQOoT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m926kzIm_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_3HYggn0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0qB7ZGdo, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_0qB7ZGdo_sendMessage);
}

void Heavy_pdpoly::cCast_aIlE37Q7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iOCyJ5qb, HV_BINOP_LESS_THAN, 0, m, &cBinop_iOCyJ5qb_sendMessage);
}

void Heavy_pdpoly::cCast_DO9YqE37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3HYggn0n, HV_BINOP_LESS_THAN, 0, m, &cBinop_3HYggn0n_sendMessage);
}

void Heavy_pdpoly::cCast_3kEPd78u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LrJRdCDh, 1, m, &cVar_LrJRdCDh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aB63IU2h, 1, m, &cVar_aB63IU2h_sendMessage);
}

void Heavy_pdpoly::cCast_vIvqBTQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LrJRdCDh, 0, m, &cVar_LrJRdCDh_sendMessage);
}

void Heavy_pdpoly::cCast_Wbmzi5u6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aB63IU2h, 0, m, &cVar_aB63IU2h_sendMessage);
}

void Heavy_pdpoly::cSend_6EUfWULL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2Sd5P2ea_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_NccsRR1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LrJRdCDh, 0, m, &cVar_LrJRdCDh_sendMessage);
}

void Heavy_pdpoly::cCast_AOutMmrz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WDUUCzpl, 0, m, &cVar_WDUUCzpl_sendMessage);
}

void Heavy_pdpoly::cCast_G5JpuiPr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EW4WsZv6_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_EW4WsZv6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_6EUfWULL_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_hndrWsYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_iYsIYajB_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_iYsIYajB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tFajeYh1_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_iUcUl5W6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hndrWsYc_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_dh18O4xR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aB63IU2h, 0, m, &cVar_aB63IU2h_sendMessage);
}

void Heavy_pdpoly::cCast_x0bv3Sca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5tJAOw1B, 0, m, &cVar_5tJAOw1B_sendMessage);
}

void Heavy_pdpoly::cMsg_m926kzIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_0JbOhNaq_sendMessage(_c, 0, m);
  cSend_VVY49j0I_sendMessage(_c, 0, m);
  cSend_HJ9HyGqQ_sendMessage(_c, 0, m);
  cSend_xDX4R8We_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_HJ9HyGqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tFajeYh1_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_xDX4R8We_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2Sd5P2ea_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_lPcECqbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0uLyjm07, 1, m, &cIf_0uLyjm07_sendMessage);
}

void Heavy_pdpoly::cCast_hxRbnIuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_4q5Yt5Jv_sendMessage);
}

void Heavy_pdpoly::cBinop_6k0nQ9zn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MNrZ11df, 0, m, &cIf_MNrZ11df_sendMessage);
}

void Heavy_pdpoly::cBinop_4q5Yt5Jv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Tlrnt22A, 0, m, &cVar_Tlrnt22A_sendMessage);
}

void Heavy_pdpoly::cMsg_0eca1ujB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_0JkJgNuo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_4dPAQY9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_3Es5pY9p_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_MX8X5V3O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_P47OpQ9d_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_PlIBNslD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aredo9yh, 0, m, &cVar_aredo9yh_sendMessage);
}

void Heavy_pdpoly::cCast_ncq3gzL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZCMqole4, 0, m, &cVar_ZCMqole4_sendMessage);
}

void Heavy_pdpoly::cMsg_P47OpQ9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_dHEG1i68, 2, m, &cPack_dHEG1i68_sendMessage);
}

void Heavy_pdpoly::cCast_mtZNPOqD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L1Gds0Ci_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZnoOuePH_sendMessage);
}

void Heavy_pdpoly::cCast_QYgPKrjb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0eca1ujB_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_p2Zg2zTl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3NlfnqKi, 0, m, &cVar_3NlfnqKi_sendMessage);
}

void Heavy_pdpoly::cCast_ZnoOuePH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ppbvUWKZ, 0, m, &cVar_ppbvUWKZ_sendMessage);
}

void Heavy_pdpoly::cCast_L1Gds0Ci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DsRRGQ32_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_DsRRGQ32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BfF2cQtN_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_W0ABm8jL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_FdeWayM9_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_v5jTRniR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cDECvFXR, 0, m, &cVar_cDECvFXR_sendMessage);
}

void Heavy_pdpoly::cSend_FdeWayM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_BfF2cQtN_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_t2r6fr5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MX8X5V3O_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ncq3gzL9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PlIBNslD_sendMessage);
}

void Heavy_pdpoly::cCast_5uUaCvqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W0ABm8jL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v5jTRniR_sendMessage);
}

void Heavy_pdpoly::cCast_mUooX6Rc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4dPAQY9Z_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_EARH4FPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aredo9yh, 0, m, &cVar_aredo9yh_sendMessage);
}

void Heavy_pdpoly::cCast_T1eJkZdm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Tlrnt22A, 0, m, &cVar_Tlrnt22A_sendMessage);
}

void Heavy_pdpoly::cCast_CESLzhnG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6k0nQ9zn, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_6k0nQ9zn_sendMessage);
}

void Heavy_pdpoly::cSend_kiqMm1zA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dVOTKSN1_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_jLVbmwsx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s4vXQDHN, 1, m, &cVar_s4vXQDHN_sendMessage);
}

void Heavy_pdpoly::cSend_Fae4MgLO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_YofLFB0u_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_qAxC9aLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dHEG1i68, 0, m, &cPack_dHEG1i68_sendMessage);
}

void Heavy_pdpoly::cBinop_BTWj6pzn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_jLVbmwsx_sendMessage);
  cSend_Fae4MgLO_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::hTable_GDWa1XQ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::hTable_GssIKZPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::hTable_MFv7IEzq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cCast_R0LWm6Sh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6RDs48fS, 0, m, &cVar_6RDs48fS_sendMessage);
}

void Heavy_pdpoly::cCast_RNYWzwhQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kWo8F6hJ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_AUu8pXRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gJaGhg8W_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_kWo8F6hJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 65535.0f);
  cSend_AUu8pXRc_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_cIHhkFUk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sr0A4Sdw, 1, m, &cIf_sr0A4Sdw_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Ajc109Po_sendMessage);
}

void Heavy_pdpoly::cBinop_Ajc109Po_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Bxgq9cfa, 1, m, &cIf_Bxgq9cfa_sendMessage);
}

void Heavy_pdpoly::cBinop_TO10Op6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_kiqMm1zA_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cPack_dHEG1i68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cwZt8xat_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSwitchcase_cwZt8xat_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_dR3Dvqp5, 0, m, &cSlice_dR3Dvqp5_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TVIMoPjA, 0, m, &cSlice_TVIMoPjA_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_saNTIlW6, 0, m, &cSlice_saNTIlW6_sendMessage);
      break;
    }
    case 0x40800000: { // "4.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_AGQ0njo1, 0, m, &cSlice_AGQ0njo1_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_dR3Dvqp5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_xen1cRyp, 0, m, &cSlice_xen1cRyp_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_qhonfTcK, 0, m, &cSlice_qhonfTcK_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_xen1cRyp, 0, m, &cSlice_xen1cRyp_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_qhonfTcK, 0, m, &cSlice_qhonfTcK_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_TVIMoPjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_vbZ1h8NT, 0, m, &cSlice_vbZ1h8NT_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_OWpeF5hr, 0, m, &cSlice_OWpeF5hr_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_vbZ1h8NT, 0, m, &cSlice_vbZ1h8NT_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_OWpeF5hr, 0, m, &cSlice_OWpeF5hr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_saNTIlW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_oiFuUeyP, 0, m, &cSlice_oiFuUeyP_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_kllGQR0C, 0, m, &cSlice_kllGQR0C_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_oiFuUeyP, 0, m, &cSlice_oiFuUeyP_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_kllGQR0C, 0, m, &cSlice_kllGQR0C_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_AGQ0njo1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_9Q5Sv9S6, 0, m, &cSlice_9Q5Sv9S6_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Xpl8S4ua, 0, m, &cSlice_Xpl8S4ua_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_9Q5Sv9S6, 0, m, &cSlice_9Q5Sv9S6_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Xpl8S4ua, 0, m, &cSlice_Xpl8S4ua_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_xen1cRyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_XLPqVAn6_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_qhonfTcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_9LPMcxdZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_vnWW9IB9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_nJXb0qiE, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_srsZvH0W_sendMessage);
}

void Heavy_pdpoly::cBinop_9LPMcxdZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_fCytNNeZ_sendMessage);
}

void Heavy_pdpoly::cBinop_fCytNNeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i9p8q7sH, HV_BINOP_POW, 1, m, &cBinop_i9p8q7sH_sendMessage);
  cMsg_EMZSlcu9_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_i9p8q7sH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_vnWW9IB9_sendMessage);
}

void Heavy_pdpoly::cMsg_EMZSlcu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_i9p8q7sH, HV_BINOP_POW, 0, m, &cBinop_i9p8q7sH_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_XLPqVAn6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WQsM5Qhj_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_G3s88LvB_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_WQsM5Qhj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bzpE8cGS_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_ta2iqHlA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yqED9YGo, HV_BINOP_MULTIPLY, 0, m, &cBinop_yqED9YGo_sendMessage);
}

void Heavy_pdpoly::cMsg_W6i8Oq90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Nw7IZ5cZ_sendMessage);
}

void Heavy_pdpoly::cSystem_Nw7IZ5cZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IzSX5kI1_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_yqED9YGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_gkNJ4asL_sendMessage);
}

void Heavy_pdpoly::cBinop_OWkJ930d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yqED9YGo, HV_BINOP_MULTIPLY, 1, m, &cBinop_yqED9YGo_sendMessage);
}

void Heavy_pdpoly::cMsg_IzSX5kI1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_OWkJ930d_sendMessage);
}

void Heavy_pdpoly::cBinop_gkNJ4asL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_1nRoLuTG_sendMessage);
}

void Heavy_pdpoly::cBinop_1nRoLuTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_2SeaurI1_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_y9ooBJe6, m);
}

void Heavy_pdpoly::cBinop_2SeaurI1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_c7biIJqK, m);
}

void Heavy_pdpoly::cVar_0oYi1unn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cf9qoBGH, HV_BINOP_MULTIPLY, 0, m, &cBinop_Cf9qoBGH_sendMessage);
}

void Heavy_pdpoly::cMsg_7QeNRwsj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VmGvf24M_sendMessage);
}

void Heavy_pdpoly::cSystem_VmGvf24M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_E5igyvFR_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_Cf9qoBGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2LWMmS8c_sendMessage);
}

void Heavy_pdpoly::cBinop_yWDZayy4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cf9qoBGH, HV_BINOP_MULTIPLY, 1, m, &cBinop_Cf9qoBGH_sendMessage);
}

void Heavy_pdpoly::cMsg_E5igyvFR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_yWDZayy4_sendMessage);
}

void Heavy_pdpoly::cBinop_2LWMmS8c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mWqcfgTj_sendMessage);
}

void Heavy_pdpoly::cBinop_mWqcfgTj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_9rq70sMw_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_DRlU35hG, m);
}

void Heavy_pdpoly::cBinop_9rq70sMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KMX3zdk1, m);
}

void Heavy_pdpoly::cMsg_bzpE8cGS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_03n31EqW, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_G3s88LvB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vphBubSp_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_vphBubSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_03n31EqW, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_srsZvH0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_DfTNZJm9, 0, m);
}

void Heavy_pdpoly::cSlice_vbZ1h8NT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_7OCjIbNh_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_OWpeF5hr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_OUcOvZ9f_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_r58afzuM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_5z6fZQ53, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_jBO2XU6Z_sendMessage);
}

void Heavy_pdpoly::cBinop_OUcOvZ9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_MkVNNBCz_sendMessage);
}

void Heavy_pdpoly::cBinop_MkVNNBCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BIyI3MO8, HV_BINOP_POW, 1, m, &cBinop_BIyI3MO8_sendMessage);
  cMsg_kmTXhCPh_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_BIyI3MO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_r58afzuM_sendMessage);
}

void Heavy_pdpoly::cMsg_kmTXhCPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BIyI3MO8, HV_BINOP_POW, 0, m, &cBinop_BIyI3MO8_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_7OCjIbNh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ToBedcIU_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_zfFAN1ae_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_ToBedcIU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TBSAh58D_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_Pp0HvnTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CYBaiXlh, HV_BINOP_MULTIPLY, 0, m, &cBinop_CYBaiXlh_sendMessage);
}

void Heavy_pdpoly::cMsg_ROpziBQX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kU2g9S5z_sendMessage);
}

void Heavy_pdpoly::cSystem_kU2g9S5z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PUJC7rCM_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_CYBaiXlh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_gtoLgQ6j_sendMessage);
}

void Heavy_pdpoly::cBinop_6ZhbVnLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CYBaiXlh, HV_BINOP_MULTIPLY, 1, m, &cBinop_CYBaiXlh_sendMessage);
}

void Heavy_pdpoly::cMsg_PUJC7rCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_6ZhbVnLH_sendMessage);
}

void Heavy_pdpoly::cBinop_gtoLgQ6j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Y6PtQlsy_sendMessage);
}

void Heavy_pdpoly::cBinop_Y6PtQlsy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_dAt7y3ph_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_qgHHrE1t, m);
}

void Heavy_pdpoly::cBinop_dAt7y3ph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xvK6e0tY, m);
}

void Heavy_pdpoly::cVar_5IdiHe1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Zy3BtOQg, HV_BINOP_MULTIPLY, 0, m, &cBinop_Zy3BtOQg_sendMessage);
}

void Heavy_pdpoly::cMsg_VT2b4Gsa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_T11WOnZT_sendMessage);
}

void Heavy_pdpoly::cSystem_T11WOnZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7LcRm1A6_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_Zy3BtOQg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_t3wo1zwN_sendMessage);
}

void Heavy_pdpoly::cBinop_EnnCsRSk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Zy3BtOQg, HV_BINOP_MULTIPLY, 1, m, &cBinop_Zy3BtOQg_sendMessage);
}

void Heavy_pdpoly::cMsg_7LcRm1A6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_EnnCsRSk_sendMessage);
}

void Heavy_pdpoly::cBinop_t3wo1zwN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_ARSNihuV_sendMessage);
}

void Heavy_pdpoly::cBinop_ARSNihuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nLhnF0rq_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_f3YFv4aI, m);
}

void Heavy_pdpoly::cBinop_nLhnF0rq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UkQUFIrl, m);
}

void Heavy_pdpoly::cMsg_TBSAh58D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_YvVlOupd, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_zfFAN1ae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LraHnVmI_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_LraHnVmI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_YvVlOupd, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_jBO2XU6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_RlcrU0PE, 0, m);
}

void Heavy_pdpoly::cSlice_oiFuUeyP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_FLRjqjA1_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_kllGQR0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_3daX9iXh_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_oPWcY36v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ekic19xi, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_oEBBDTOj_sendMessage);
}

void Heavy_pdpoly::cBinop_3daX9iXh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_mCLLZISw_sendMessage);
}

void Heavy_pdpoly::cBinop_mCLLZISw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LPnqYCQO, HV_BINOP_POW, 1, m, &cBinop_LPnqYCQO_sendMessage);
  cMsg_Lt8dlYkr_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_LPnqYCQO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_oPWcY36v_sendMessage);
}

void Heavy_pdpoly::cMsg_Lt8dlYkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LPnqYCQO, HV_BINOP_POW, 0, m, &cBinop_LPnqYCQO_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_FLRjqjA1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gj9wkIUT_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_QUUetWPQ_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_gj9wkIUT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b5jP8IYv_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_o6zYLr0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fcnGJg6Z, HV_BINOP_MULTIPLY, 0, m, &cBinop_fcnGJg6Z_sendMessage);
}

void Heavy_pdpoly::cMsg_OEpEzLp6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_D13CwXgJ_sendMessage);
}

void Heavy_pdpoly::cSystem_D13CwXgJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9bZDXE0O_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_fcnGJg6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_uT6d95bU_sendMessage);
}

void Heavy_pdpoly::cBinop_s9SjfMkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fcnGJg6Z, HV_BINOP_MULTIPLY, 1, m, &cBinop_fcnGJg6Z_sendMessage);
}

void Heavy_pdpoly::cMsg_9bZDXE0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_s9SjfMkD_sendMessage);
}

void Heavy_pdpoly::cBinop_uT6d95bU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_oee5f3GV_sendMessage);
}

void Heavy_pdpoly::cBinop_oee5f3GV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_cE4pjvwi_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NAaXX6zO, m);
}

void Heavy_pdpoly::cBinop_cE4pjvwi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dRmrAqyK, m);
}

void Heavy_pdpoly::cVar_fnu1Rqy9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xkrptTh0, HV_BINOP_MULTIPLY, 0, m, &cBinop_xkrptTh0_sendMessage);
}

void Heavy_pdpoly::cMsg_47h7y95M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cwzEvmZT_sendMessage);
}

void Heavy_pdpoly::cSystem_cwzEvmZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_luvzig2h_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_xkrptTh0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_K7XFS6pX_sendMessage);
}

void Heavy_pdpoly::cBinop_WEHu8ExS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xkrptTh0, HV_BINOP_MULTIPLY, 1, m, &cBinop_xkrptTh0_sendMessage);
}

void Heavy_pdpoly::cMsg_luvzig2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_WEHu8ExS_sendMessage);
}

void Heavy_pdpoly::cBinop_K7XFS6pX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_SOzhniZc_sendMessage);
}

void Heavy_pdpoly::cBinop_SOzhniZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_t4Fy7xac_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_INpzyiHX, m);
}

void Heavy_pdpoly::cBinop_t4Fy7xac_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BMfGRQ3t, m);
}

void Heavy_pdpoly::cMsg_b5jP8IYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_iTpxhYpN, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_QUUetWPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8nu4brr9_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_8nu4brr9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_iTpxhYpN, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_oEBBDTOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_awoCAqDD, 0, m);
}

void Heavy_pdpoly::cSlice_9Q5Sv9S6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_Hj3FocxG_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_Xpl8S4ua_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_mbGeWnjl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_jphvNKAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_DlMyAiOj, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_f13t36zZ_sendMessage);
}

void Heavy_pdpoly::cBinop_mbGeWnjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_qr0HggbW_sendMessage);
}

void Heavy_pdpoly::cBinop_qr0HggbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5TBYIPOk, HV_BINOP_POW, 1, m, &cBinop_5TBYIPOk_sendMessage);
  cMsg_sklB7N3v_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_5TBYIPOk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_jphvNKAE_sendMessage);
}

void Heavy_pdpoly::cMsg_sklB7N3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5TBYIPOk, HV_BINOP_POW, 0, m, &cBinop_5TBYIPOk_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_Hj3FocxG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cQqxiydS_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_QwundTXl_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_cQqxiydS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UYT9rWpK_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_072kmFLc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x1ksKTEf, HV_BINOP_MULTIPLY, 0, m, &cBinop_x1ksKTEf_sendMessage);
}

void Heavy_pdpoly::cMsg_FEHHT3su_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1tfCF8HS_sendMessage);
}

void Heavy_pdpoly::cSystem_1tfCF8HS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RuDKn1ok_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_x1ksKTEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_XoKgMQVD_sendMessage);
}

void Heavy_pdpoly::cBinop_zmIjmjFW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x1ksKTEf, HV_BINOP_MULTIPLY, 1, m, &cBinop_x1ksKTEf_sendMessage);
}

void Heavy_pdpoly::cMsg_RuDKn1ok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zmIjmjFW_sendMessage);
}

void Heavy_pdpoly::cBinop_XoKgMQVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_9q7EIYBu_sendMessage);
}

void Heavy_pdpoly::cBinop_9q7EIYBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_n5Gay05L_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9C8zdXo6, m);
}

void Heavy_pdpoly::cBinop_n5Gay05L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IH9pTizk, m);
}

void Heavy_pdpoly::cVar_Ba1eomVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xrfkov59, HV_BINOP_MULTIPLY, 0, m, &cBinop_Xrfkov59_sendMessage);
}

void Heavy_pdpoly::cMsg_YBoddUL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6XwgeijZ_sendMessage);
}

void Heavy_pdpoly::cSystem_6XwgeijZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XwyHitzO_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_Xrfkov59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_AebtNpwp_sendMessage);
}

void Heavy_pdpoly::cBinop_rYKiz4DP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xrfkov59, HV_BINOP_MULTIPLY, 1, m, &cBinop_Xrfkov59_sendMessage);
}

void Heavy_pdpoly::cMsg_XwyHitzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rYKiz4DP_sendMessage);
}

void Heavy_pdpoly::cBinop_AebtNpwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EY6ieRXR_sendMessage);
}

void Heavy_pdpoly::cBinop_EY6ieRXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_oFe4rX5R_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cxbla4d6, m);
}

void Heavy_pdpoly::cBinop_oFe4rX5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZDY0vl7D, m);
}

void Heavy_pdpoly::cMsg_UYT9rWpK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_eCjCXXhx, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_QwundTXl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c3vR0Ux6_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_c3vR0Ux6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_eCjCXXhx, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_f13t36zZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_iKkYsIWE, 0, m);
}

void Heavy_pdpoly::cSend_wMEbFgQt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_cAOo0Yv2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cReceive_LBoBrNTy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W6i8Oq90_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ta2iqHlA, 0, m, &cVar_ta2iqHlA_sendMessage);
  cMsg_7QeNRwsj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0oYi1unn, 0, m, &cVar_0oYi1unn_sendMessage);
  cMsg_ROpziBQX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Pp0HvnTQ, 0, m, &cVar_Pp0HvnTQ_sendMessage);
  cMsg_VT2b4Gsa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5IdiHe1E, 0, m, &cVar_5IdiHe1E_sendMessage);
  cMsg_OEpEzLp6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_o6zYLr0f, 0, m, &cVar_o6zYLr0f_sendMessage);
  cMsg_47h7y95M_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fnu1Rqy9, 0, m, &cVar_fnu1Rqy9_sendMessage);
  cMsg_FEHHT3su_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_072kmFLc, 0, m, &cVar_072kmFLc_sendMessage);
  cMsg_YBoddUL9_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Ba1eomVS, 0, m, &cVar_Ba1eomVS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cZD5jLrO, 0, m, &cVar_cZD5jLrO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RNYWzwhQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R0LWm6Sh_sendMessage);
}

void Heavy_pdpoly::cReceive_wF8y98oy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_QOjO4xj4, 0, m, &cSlice_QOjO4xj4_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_qJk4Wdcs, 0, m, &cSlice_qJk4Wdcs_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_goGccCX2, 0, m, &cSlice_goGccCX2_sendMessage);
}

void Heavy_pdpoly::cReceive_dVOTKSN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MNrZ11df, 1, m, &cIf_MNrZ11df_sendMessage);
}

void Heavy_pdpoly::cReceive_YofLFB0u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1v4KprZB, 1, m, &cVar_1v4KprZB_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ppbvUWKZ, 1, m, &cVar_ppbvUWKZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cDECvFXR, 1, m, &cVar_cDECvFXR_sendMessage);
}

void Heavy_pdpoly::cReceive_BfF2cQtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s4vXQDHN, 0, m, &cVar_s4vXQDHN_sendMessage);
}

void Heavy_pdpoly::cReceive_gJaGhg8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qck7iEtX, 1, m, &cVar_qck7iEtX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kEvnyOKj, 1, m, &cVar_kEvnyOKj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BTWj6pzn, HV_BINOP_MOD_UNIPOLAR, 1, m, &cBinop_BTWj6pzn_sendMessage);
}

void Heavy_pdpoly::cReceive_nM3qG6Zd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_3xGSlEZN, 1, m, &cTabwrite_3xGSlEZN_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_OvWwoT6M, 1, m, &cTabwrite_OvWwoT6M_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_hikOkNyL, 1, m, &cTabwrite_hikOkNyL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aredo9yh, 1, m, &cVar_aredo9yh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZCMqole4, 1, m, &cVar_ZCMqole4_sendMessage);
}

void Heavy_pdpoly::cReceive_q9LPDzaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3NlfnqKi, 1, m, &cVar_3NlfnqKi_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_y2vRLMIs, 1, m, &cTabwrite_y2vRLMIs_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_BQmKrtjQ, 1, m, &cTabwrite_BQmKrtjQ_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_5gcp5YHp, 1, m, &cTabwrite_5gcp5YHp_sendMessage);
}

void Heavy_pdpoly::cReceive_2Sd5P2ea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hxRbnIuu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lPcECqbp_sendMessage);
}

void Heavy_pdpoly::cReceive_tFajeYh1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CESLzhnG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T1eJkZdm_sendMessage);
}

void Heavy_pdpoly::cReceive_cAOo0Yv2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ta2iqHlA, 0, m, &cVar_ta2iqHlA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0oYi1unn, 0, m, &cVar_0oYi1unn_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Pp0HvnTQ, 0, m, &cVar_Pp0HvnTQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5IdiHe1E, 0, m, &cVar_5IdiHe1E_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_o6zYLr0f, 0, m, &cVar_o6zYLr0f_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fnu1Rqy9, 0, m, &cVar_fnu1Rqy9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_072kmFLc, 0, m, &cVar_072kmFLc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Ba1eomVS, 0, m, &cVar_Ba1eomVS_sendMessage);
}

void Heavy_pdpoly::cReceive_3MLwFsB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_wMEbFgQt_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cReceive_wjSsmZCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TAEegDLT, m);
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
    __hv_phasor_k_f(&sPhasor_nJXb0qiE, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_DfTNZJm9, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_y9ooBJe6, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_c7biIJqK, VOf(Bf2));
    __hv_rpole_f(&sRPole_SofnGBgU, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_DRlU35hG, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_KMX3zdk1, VOf(Bf2));
    __hv_rpole_f(&sRPole_goKP5JaM, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_03n31EqW, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_5z6fZQ53, VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_RlcrU0PE, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_qgHHrE1t, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_xvK6e0tY, VOf(Bf3));
    __hv_rpole_f(&sRPole_33ljBuDg, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_f3YFv4aI, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_UkQUFIrl, VOf(Bf3));
    __hv_rpole_f(&sRPole_G4gaqNLE, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_YvVlOupd, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_ekic19xi, VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_awoCAqDD, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_NAaXX6zO, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_dRmrAqyK, VOf(Bf2));
    __hv_rpole_f(&sRPole_sRUvQkKb, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_INpzyiHX, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_BMfGRQ3t, VOf(Bf2));
    __hv_rpole_f(&sRPole_e3iiWwN0, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_iTpxhYpN, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_DlMyAiOj, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_iKkYsIWE, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_9C8zdXo6, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_IH9pTizk, VOf(Bf1));
    __hv_rpole_f(&sRPole_aXqDhGbj, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_cxbla4d6, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_ZDY0vl7D, VOf(Bf1));
    __hv_rpole_f(&sRPole_aApveVw4, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_eCjCXXhx, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_TAEegDLT, VOf(Bf3));
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
