/** Copyright (c) 2026 Charles Vestal. MIT License (LICENSE beside pdpoly.pd) */

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
  numBytes += sPhasor_k_init(&sPhasor_jV2cDyYP, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_4dRRUrVF, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_jbDdg7Nj);
  numBytes += sRPole_init(&sRPole_K1ABEsvr);
  numBytes += sLine_init(&sLine_3cPgyhkE);
  numBytes += sPhasor_k_init(&sPhasor_NnH0Ftp6, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_CzZFHSRT, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_Deu3Mykb);
  numBytes += sRPole_init(&sRPole_89Ssd6SU);
  numBytes += sLine_init(&sLine_UGZFJMTo);
  numBytes += sPhasor_k_init(&sPhasor_BC2hWuCu, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_Mxj5vG44, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_6C5joWU7);
  numBytes += sRPole_init(&sRPole_pl27kFyB);
  numBytes += sLine_init(&sLine_fyCXNMuh);
  numBytes += sPhasor_k_init(&sPhasor_pZ40fDSo, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_1HlcemhH, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_7cg01uF5);
  numBytes += sRPole_init(&sRPole_Ce0uuO8u);
  numBytes += sLine_init(&sLine_De1hOvE7);
  numBytes += cSlice_init(&cSlice_LgPMLc38, 2, 1);
  numBytes += cSlice_init(&cSlice_6d4hon6H, 1, 1);
  numBytes += cSlice_init(&cSlice_wWUqaFzD, 0, 1);
  numBytes += cVar_init_f(&cVar_Yl3HpL21, 0.0f);
  numBytes += cIf_init(&cIf_UyOUNzN2, false);
  numBytes += cIf_init(&cIf_2erLUHnR, false);
  numBytes += cIf_init(&cIf_KU3BehdE, false);
  numBytes += cIf_init(&cIf_5g9TLksS, false);
  numBytes += cIf_init(&cIf_EKSnxLgw, false);
  numBytes += cBinop_init(&cBinop_jpaJuwZu, 0.0f); // __eq
  numBytes += cVar_init_f(&cVar_fy5hAiJr, 1.0f);
  numBytes += cVar_init_f(&cVar_HTRxATFx, 0.0f);
  numBytes += cSlice_init(&cSlice_nkOP3AiU, 1, -1);
  numBytes += cSlice_init(&cSlice_bsnCpccR, 1, -1);
  numBytes += cSlice_init(&cSlice_isrPlfjN, 1, 1);
  numBytes += cSlice_init(&cSlice_HKG8ofng, 0, 1);
  numBytes += cVar_init_f(&cVar_k97X5Wxe, 0.0f);
  numBytes += cIf_init(&cIf_uJfCHij7, false);
  numBytes += cIf_init(&cIf_pq3fytoe, false);
  numBytes += cIf_init(&cIf_6wL4ZSez, false);
  numBytes += cVar_init_f(&cVar_FzCGzhSy, 0.0f);
  numBytes += cIf_init(&cIf_J7aAxecU, false);
  numBytes += cVar_init_f(&cVar_TW3cY6RK, 0.0f);
  numBytes += cIf_init(&cIf_CdRrj9E2, false);
  numBytes += cBinop_init(&cBinop_rv4r2UUK, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_5YS3HbyR, 4.0f);
  numBytes += cTabread_init(&cTabread_uD8bsAEx, &hTable_nqhVhaIy); // 1011-used
  numBytes += cSlice_init(&cSlice_jD9N4JW6, 1, -1);
  numBytes += cVar_init_s(&cVar_vY7XByet, "1011-used");
  numBytes += cBinop_init(&cBinop_CNWjz9pF, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_MJ8kK3DU, &hTable_RhMviSoN); // 1011-ids
  numBytes += cSlice_init(&cSlice_SzmJk01P, 1, -1);
  numBytes += cVar_init_s(&cVar_tGG169dh, "1011-ids");
  numBytes += cBinop_init(&cBinop_4HYoHA2f, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_P1RbjmJF, 0.0f);
  numBytes += cSlice_init(&cSlice_hd6eToBV, 1, 1);
  numBytes += cSlice_init(&cSlice_0rW28w98, 0, 1);
  numBytes += cTabread_init(&cTabread_DTqct87R, &hTable_sOb2BYmj); // 1011-pitches
  numBytes += cSlice_init(&cSlice_r8XpthtM, 1, -1);
  numBytes += cVar_init_s(&cVar_wMT77rsO, "1011-pitches");
  numBytes += cBinop_init(&cBinop_EVEZeiL7, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_AVb0enbj, 0.0f);
  numBytes += cVar_init_f(&cVar_fCgdAzzA, 0.0f);
  numBytes += cIf_init(&cIf_WhlaeSUA, false);
  numBytes += cTabwrite_init(&cTabwrite_7bpQzS0p, &hTable_nqhVhaIy); // 1011-used
  numBytes += cSlice_init(&cSlice_Or4CDb3F, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_bLTXHtVU, &hTable_RhMviSoN); // 1011-ids
  numBytes += cSlice_init(&cSlice_g9Rpcnwv, 1, -1);
  numBytes += cVar_init_f(&cVar_rlRg7Ewf, 0.0f);
  numBytes += cVar_init_f(&cVar_Rzql1D6T, 0.0f);
  numBytes += cSlice_init(&cSlice_6t4aPuYa, 1, 1);
  numBytes += cSlice_init(&cSlice_GBd9Z2zF, 0, 1);
  numBytes += cPack_init(&cPack_wgYC5svO, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_nXfUFBKx, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_IPz2c8gx, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_Sa45O2kp, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_42jKpJYb, 0.0f); // __lt
  numBytes += cIf_init(&cIf_VfglTXiL, false);
  numBytes += cVar_init_f(&cVar_KvQ4Fzya, 0.0f);
  numBytes += cIf_init(&cIf_V4h68Ggb, false);
  numBytes += cVar_init_f(&cVar_row8DAB4, 0.0f);
  numBytes += cIf_init(&cIf_Kns6SYwE, false);
  numBytes += cBinop_init(&cBinop_YWuo5DXQ, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_ToWXJRu0, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_77NiY5EF, &hTable_nqhVhaIy); // 1011-used
  numBytes += cSlice_init(&cSlice_Sv38SPGD, 1, -1);
  numBytes += cTabread_init(&cTabread_2LF9bUc8, &hTable_nqhVhaIy); // 1011-used
  numBytes += cSlice_init(&cSlice_s1jKmfW8, 1, -1);
  numBytes += cVar_init_s(&cVar_LuuM7h67, "1011-used");
  numBytes += cBinop_init(&cBinop_UGHeWlH6, 0.0f); // __min
  numBytes += cIf_init(&cIf_PcYHCyls, false);
  numBytes += cTabread_init(&cTabread_2AgvsBOX, &hTable_sOb2BYmj); // 1011-pitches
  numBytes += cSlice_init(&cSlice_hOZSn7fr, 1, -1);
  numBytes += cVar_init_s(&cVar_QZ9iEFyk, "1011-pitches");
  numBytes += cBinop_init(&cBinop_n6uJJvvB, 0.0f); // __min
  numBytes += cIf_init(&cIf_MAsQdjs8, false);
  numBytes += cVar_init_f(&cVar_YsA6Dodv, 0.0f);
  numBytes += cIf_init(&cIf_SKDfoO01, false);
  numBytes += cVar_init_f(&cVar_0KuQq8fK, 0.0f);
  numBytes += cIf_init(&cIf_wgHSSPWc, false);
  numBytes += cBinop_init(&cBinop_H7QVgaSs, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_HdNusQeV, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_vXLuqL2L, &hTable_nqhVhaIy); // 1011-used
  numBytes += cSlice_init(&cSlice_iA2q7qA0, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_tUZzbTpT, &hTable_RhMviSoN); // 1011-ids
  numBytes += cSlice_init(&cSlice_bEBijJde, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_QAPw1Np8, &hTable_sOb2BYmj); // 1011-pitches
  numBytes += cSlice_init(&cSlice_hNEmzIbu, 1, -1);
  numBytes += cIf_init(&cIf_0rzoSiTi, false);
  numBytes += cVar_init_f(&cVar_MQiXbJPW, 0.0f);
  numBytes += cIf_init(&cIf_1oEVWhUE, false);
  numBytes += cVar_init_f(&cVar_lOGtSZeI, 0.0f);
  numBytes += cIf_init(&cIf_zIAPwwmq, false);
  numBytes += cBinop_init(&cBinop_je6fjA7a, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_efsQgUhC, 4.0f);
  numBytes += cVar_init_f(&cVar_JGCCQAla, 0.0f);
  numBytes += cIf_init(&cIf_YHsYOo8K, false);
  numBytes += cVar_init_f(&cVar_21LKdHxo, 0.0f);
  numBytes += cVar_init_f(&cVar_mLuBC367, 0.0f);
  numBytes += cVar_init_f(&cVar_Qhd8DooS, 0.0f);
  numBytes += cIf_init(&cIf_CmbB9J8u, false);
  numBytes += cIf_init(&cIf_p4s6QG25, false);
  numBytes += cPack_init(&cPack_m0IbC46o, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_t9hxiyyF, 0.0f);
  numBytes += cSlice_init(&cSlice_Jj5Oah1t, 1, 1);
  numBytes += cSlice_init(&cSlice_YxRlSKIt, 0, 1);
  numBytes += cVar_init_f(&cVar_nyYdYuej, 0.0f);
  numBytes += cIf_init(&cIf_yqhwH2zn, false);
  numBytes += cVar_init_f(&cVar_y1WxshAL, 0.0f);
  numBytes += cVar_init_f(&cVar_WpOGftwj, 0.0f);
  numBytes += cTabread_init(&cTabread_a4DFHPg4, &hTable_nqhVhaIy); // 1011-used
  numBytes += cSlice_init(&cSlice_XzwmPsCc, 1, -1);
  numBytes += cVar_init_s(&cVar_QZSsxHWl, "1011-used");
  numBytes += cBinop_init(&cBinop_Hu78Pg8r, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_kLHkjQe0, &hTable_RhMviSoN); // 1011-ids
  numBytes += cSlice_init(&cSlice_ZMtrw3Ut, 1, -1);
  numBytes += cVar_init_s(&cVar_xx8L9MEM, "1011-ids");
  numBytes += cBinop_init(&cBinop_oysoCkSt, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_JeC2ILwJ, &hTable_sOb2BYmj); // 1011-pitches
  numBytes += cSlice_init(&cSlice_meFUd4ns, 1, -1);
  numBytes += cTabread_init(&cTabread_pvZwjjaL, &hTable_sOb2BYmj); // 1011-pitches
  numBytes += cSlice_init(&cSlice_0mZWWkoA, 1, -1);
  numBytes += cVar_init_s(&cVar_2JJSPgXK, "1011-pitches");
  numBytes += cBinop_init(&cBinop_Yyfete62, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_0KNrmZYO, &hTable_sOb2BYmj); // 1011-pitches
  numBytes += cSlice_init(&cSlice_k05M8rZY, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_U68ZtQCI, &hTable_nqhVhaIy); // 1011-used
  numBytes += cSlice_init(&cSlice_JWSEJKU9, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_Gll4eGKI, &hTable_RhMviSoN); // 1011-ids
  numBytes += cSlice_init(&cSlice_EmZJOq1Y, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_LszWQ7QZ, &hTable_RhMviSoN); // 1011-ids
  numBytes += cSlice_init(&cSlice_DXFeehZ3, 1, -1);
  numBytes += cVar_init_f(&cVar_9Zcwzybn, 0.0f);
  numBytes += cTabwrite_init(&cTabwrite_jnk5hZ9p, &hTable_nqhVhaIy); // 1011-used
  numBytes += cSlice_init(&cSlice_DrhonvgX, 1, -1);
  numBytes += cVar_init_f(&cVar_ORjgs46o, 0.0f);
  numBytes += cSlice_init(&cSlice_xACQ0mC2, 1, 1);
  numBytes += cSlice_init(&cSlice_3omKebEs, 0, 1);
  numBytes += cVar_init_f(&cVar_HGdcJwdj, 0.0f);
  numBytes += cBinop_init(&cBinop_FnRNka2z, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_OLpUC06p, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_I2mIw4Kd, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_uhLM6rkl, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_iyNfprqq, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_G7itATmX, 65535.0f); // __unimod
  numBytes += hTable_init(&hTable_sOb2BYmj, 4);
  numBytes += hTable_init(&hTable_nqhVhaIy, 4);
  numBytes += hTable_init(&hTable_RhMviSoN, 4);
  numBytes += cPack_init(&cPack_oeMqprdv, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_ooaPzFdZ, 1, -1);
  numBytes += cSlice_init(&cSlice_U9yjodK5, 1, -1);
  numBytes += cSlice_init(&cSlice_ZPMzCRDc, 1, -1);
  numBytes += cSlice_init(&cSlice_PWoU7Aqs, 1, -1);
  numBytes += cSlice_init(&cSlice_QiFPVoUS, 1, 1);
  numBytes += cSlice_init(&cSlice_ySBAmjnc, 0, 1);
  numBytes += cBinop_init(&cBinop_IT4T35pJ, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_2gtXAChe, 22050.0f);
  numBytes += cBinop_init(&cBinop_txFGC8A9, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_dGld7Ry0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_DEXGwPIf, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_bBamG7lg, 22050.0f);
  numBytes += cBinop_init(&cBinop_wYL69RAO, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_zQ9Wsdbw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TWLAsIA5, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_kav9ZjpO, 1, 1);
  numBytes += cSlice_init(&cSlice_M7XjvI8x, 0, 1);
  numBytes += cBinop_init(&cBinop_Gi2EUj9m, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_jQn6vsH7, 22050.0f);
  numBytes += cBinop_init(&cBinop_n4c9P2vb, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_YvcGEwE2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mtsk8ibJ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_hdZZODFX, 22050.0f);
  numBytes += cBinop_init(&cBinop_KXxNiyvZ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_V5bzevPA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2t16tEf7, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_CCiWHZfO, 1, 1);
  numBytes += cSlice_init(&cSlice_C7n0rTMp, 0, 1);
  numBytes += cBinop_init(&cBinop_WzxMwFBj, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_ZIhtxqx7, 22050.0f);
  numBytes += cBinop_init(&cBinop_MHiB7PA5, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_48ir5FZz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hlsZsb45, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_nENauZGp, 22050.0f);
  numBytes += cBinop_init(&cBinop_PO8xkMd5, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_UVZsfxRT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sinC2iP0, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_jwWKPi40, 1, 1);
  numBytes += cSlice_init(&cSlice_81v5NwxA, 0, 1);
  numBytes += cBinop_init(&cBinop_Lt4oGRad, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_cn1Y5NUb, 22050.0f);
  numBytes += cBinop_init(&cBinop_gFGXQsuZ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_cIH0PKGa, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0AJml8sU, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ee2Fqx0X, 22050.0f);
  numBytes += cBinop_init(&cBinop_QAbd5MXQ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_bVZfwv1L, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NBov8azo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nSqsBGld, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_pdpoly::~Heavy_pdpoly() {
  cPack_free(&cPack_wgYC5svO);
  cPack_free(&cPack_m0IbC46o);
  hTable_free(&hTable_sOb2BYmj);
  hTable_free(&hTable_nqhVhaIy);
  hTable_free(&hTable_RhMviSoN);
  cPack_free(&cPack_oeMqprdv);
}

HvTable *Heavy_pdpoly::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x7B847FB6: return &hTable_sOb2BYmj; // 1011-pitches
    case 0xA0EFCB1D: return &hTable_nqhVhaIy; // 1011-used
    case 0x73137BF4: return &hTable_RhMviSoN; // 1011-ids
    default: return nullptr;
  }
}

void Heavy_pdpoly::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x7EA4AD17: { // 1011-currentVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lSPycKip_sendMessage);
      break;
    }
    case 0x9B1DF8F3: { // 1011-indexOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AnAGAMlI_sendMessage);
      break;
    }
    case 0xF7855D22: { // 1011-indexOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xx3nUNJm_sendMessage);
      break;
    }
    case 0xEB1BA925: { // 1011-isFirstOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2blUjMar_sendMessage);
      break;
    }
    case 0x7426D59: { // 1011-isFirstOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gDOtbvR0_sendMessage);
      break;
    }
    case 0x199E738B: { // 1011-maxVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Nx3o17bm_sendMessage);
      break;
    }
    case 0x979E98C4: { // 1011-shouldSteal
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QJNkIbFy_sendMessage);
      break;
    }
    case 0xDB67A714: { // 1011-voiceId++
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5wIX5vHs_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PwP3BAN0_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5JlAQXQo_sendMessage);
      break;
    }
    case 0xF89F9F3E: { // cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FiPksvmP_sendMessage);
      break;
    }
    case 0xC2C62B6: { // vcut
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2LzdBdmC_sendMessage);
      break;
    }
    case 0xB1642755: { // volume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OD3sQy6V_sendMessage);
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


void Heavy_pdpoly::cSlice_LgPMLc38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_HZUQhtqz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_6d4hon6H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_5g9TLksS, 0, m, &cIf_5g9TLksS_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_2erLUHnR, 0, m, &cIf_2erLUHnR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_wWUqaFzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_EKSnxLgw, 0, m, &cIf_EKSnxLgw_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_KU3BehdE, 0, m, &cIf_KU3BehdE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_Yl3HpL21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_9G2XwWgl_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_UyOUNzN2, 0, m, &cIf_UyOUNzN2_sendMessage);
}

void Heavy_pdpoly::cUnop_0GNFiE6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_3D1GwTnc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jpaJuwZu, HV_BINOP_EQ, 1, m, &cBinop_jpaJuwZu_sendMessage);
}

void Heavy_pdpoly::cUnop_EtEf6ouY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_3D1GwTnc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jpaJuwZu, HV_BINOP_EQ, 1, m, &cBinop_jpaJuwZu_sendMessage);
}

void Heavy_pdpoly::cIf_UyOUNzN2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_EtEf6ouY_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_0GNFiE6K_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_9G2XwWgl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UyOUNzN2, 1, m, &cIf_UyOUNzN2_sendMessage);
}

void Heavy_pdpoly::cIf_2erLUHnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_k97X5Wxe, 0, m, &cVar_k97X5Wxe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_KU3BehdE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_i5EJTYAV_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_5g9TLksS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_k97X5Wxe, 0, m, &cVar_k97X5Wxe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_EKSnxLgw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_i5EJTYAV_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_HZUQhtqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jpaJuwZu, HV_BINOP_EQ, 0, m, &cBinop_jpaJuwZu_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_WHVI1Sjv_sendMessage);
}

void Heavy_pdpoly::cBinop_3D1GwTnc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yFMg5wmL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_10kFVmdS_sendMessage);
}

void Heavy_pdpoly::cBinop_jpaJuwZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_etTSvupT_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JleeScbg_sendMessage);
}

void Heavy_pdpoly::cCast_JleeScbg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EKSnxLgw, 1, m, &cIf_EKSnxLgw_sendMessage);
}

void Heavy_pdpoly::cCast_etTSvupT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2erLUHnR, 1, m, &cIf_2erLUHnR_sendMessage);
}

void Heavy_pdpoly::cCast_yFMg5wmL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5g9TLksS, 1, m, &cIf_5g9TLksS_sendMessage);
}

void Heavy_pdpoly::cCast_10kFVmdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_KU3BehdE, 1, m, &cIf_KU3BehdE_sendMessage);
}

void Heavy_pdpoly::cBinop_WHVI1Sjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cVar_fy5hAiJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_C8ssn6lA_sendMessage);
}

void Heavy_pdpoly::cVar_HTRxATFx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G7itATmX, HV_BINOP_MOD_UNIPOLAR, 0, m, &cBinop_G7itATmX_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_i5EJTYAV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_nkOP3AiU, 0, m, &cSlice_nkOP3AiU_sendMessage);
      break;
    }
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_bsnCpccR, 0, m, &cSlice_bsnCpccR_sendMessage);
      break;
    }
    default: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_isrPlfjN, 0, m, &cSlice_isrPlfjN_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_HKG8ofng, 0, m, &cSlice_HKG8ofng_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_nkOP3AiU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FGtyP19l_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vth6P80y_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FGtyP19l_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vth6P80y_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_bsnCpccR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OYd55W1H_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9vmwPaZ0_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OYd55W1H_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9vmwPaZ0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_isrPlfjN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_k97X5Wxe, 0, m, &cVar_k97X5Wxe_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_HKG8ofng_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_uJfCHij7, 0, m, &cIf_uJfCHij7_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_pq3fytoe, 0, m, &cIf_pq3fytoe_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_k97X5Wxe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_m0IbC46o, 1, m, &cPack_m0IbC46o_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_wgYC5svO, 1, m, &cPack_wgYC5svO_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Dml6eVpZ_sendMessage);
}

void Heavy_pdpoly::cIf_uJfCHij7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ww9Rojla_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qAMhqCG9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zvAiXZMM_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_m0IbC46o, 0, m, &cPack_m0IbC46o_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_pq3fytoe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_wgYC5svO, 0, m, &cPack_wgYC5svO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_6wL4ZSez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uWM5ebV4_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6NpPw56e_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_FzCGzhSy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0vZUEMIb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UL1InFGS_sendMessage);
}

void Heavy_pdpoly::cIf_J7aAxecU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0As17IMm_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ulGImUbC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_HLdNs6q1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_J7aAxecU, 1, m, &cIf_J7aAxecU_sendMessage);
}

void Heavy_pdpoly::cVar_TW3cY6RK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_blbsFY9m_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_CdRrj9E2, 0, m, &cIf_CdRrj9E2_sendMessage);
}

void Heavy_pdpoly::cUnop_ygExzBzY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_HLdNs6q1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_J7aAxecU, 0, m, &cIf_J7aAxecU_sendMessage);
}

void Heavy_pdpoly::cUnop_b57zetbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_HLdNs6q1_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_J7aAxecU, 0, m, &cIf_J7aAxecU_sendMessage);
}

void Heavy_pdpoly::cIf_CdRrj9E2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_b57zetbp_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ygExzBzY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_blbsFY9m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CdRrj9E2, 1, m, &cIf_CdRrj9E2_sendMessage);
}

void Heavy_pdpoly::cCast_UL1InFGS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6wL4ZSez, 0, m, &cIf_6wL4ZSez_sendMessage);
}

void Heavy_pdpoly::cCast_0vZUEMIb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rv4r2UUK, HV_BINOP_LESS_THAN, 0, m, &cBinop_rv4r2UUK_sendMessage);
}

void Heavy_pdpoly::cBinop_rv4r2UUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6wL4ZSez, 1, m, &cIf_6wL4ZSez_sendMessage);
}

void Heavy_pdpoly::cCast_0As17IMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rv4r2UUK, HV_BINOP_LESS_THAN, 1, m, &cBinop_rv4r2UUK_sendMessage);
}

void Heavy_pdpoly::cCast_ulGImUbC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_imgox03r_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_woTtWQGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FzCGzhSy, 0, m, &cVar_FzCGzhSy_sendMessage);
}

void Heavy_pdpoly::cMsg_imgox03r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_FzCGzhSy, 0, m, &cVar_FzCGzhSy_sendMessage);
}

void Heavy_pdpoly::cCast_uWM5ebV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ApqFaJuz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xQYjvogs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fnAeSmyw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7hUMjIdg_sendMessage);
}

void Heavy_pdpoly::cCast_6NpPw56e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_woTtWQGv_sendMessage);
}

void Heavy_pdpoly::cVar_5YS3HbyR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TW3cY6RK, 0, m, &cVar_TW3cY6RK_sendMessage);
}

void Heavy_pdpoly::cTabread_uD8bsAEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sa45O2kp, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_Sa45O2kp_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_SWFWZ5TQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jD9N4JW6, 0, m, &cSlice_jD9N4JW6_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H8CoGtSN_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2B6btYuU_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_jD9N4JW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_uD8bsAEx, 1, m, &cTabread_uD8bsAEx_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_uD8bsAEx, 1, m, &cTabread_uD8bsAEx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_vY7XByet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gIUPLEk4_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_uaTxoQND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_cwI2Y1qX_sendMessage);
}

void Heavy_pdpoly::cBinop_jzLOyPXh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CNWjz9pF, HV_BINOP_MIN, 0, m, &cBinop_CNWjz9pF_sendMessage);
}

void Heavy_pdpoly::cCast_H8CoGtSN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vY7XByet, 0, m, &cVar_vY7XByet_sendMessage);
}

void Heavy_pdpoly::cCast_2B6btYuU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_jzLOyPXh_sendMessage);
}

void Heavy_pdpoly::cBinop_CNWjz9pF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_uD8bsAEx, 0, m, &cTabread_uD8bsAEx_sendMessage);
}

void Heavy_pdpoly::cMsg_gIUPLEk4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uaTxoQND_sendMessage);
}

void Heavy_pdpoly::cBinop_cwI2Y1qX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CNWjz9pF, HV_BINOP_MIN, 1, m, &cBinop_CNWjz9pF_sendMessage);
}

void Heavy_pdpoly::cTabread_MJ8kK3DU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0stxtk86_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FxJEYMfT_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_mDuEk8Gr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SzmJk01P, 0, m, &cSlice_SzmJk01P_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YtlaoOIs_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mYqW58xL_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_SzmJk01P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_MJ8kK3DU, 1, m, &cTabread_MJ8kK3DU_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_MJ8kK3DU, 1, m, &cTabread_MJ8kK3DU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_tGG169dh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2GSAtqBn_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_ZvyeN1eb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_O209Pu1L_sendMessage);
}

void Heavy_pdpoly::cBinop_2KlWEJX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4HYoHA2f, HV_BINOP_MIN, 0, m, &cBinop_4HYoHA2f_sendMessage);
}

void Heavy_pdpoly::cCast_mYqW58xL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_2KlWEJX9_sendMessage);
}

void Heavy_pdpoly::cCast_YtlaoOIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tGG169dh, 0, m, &cVar_tGG169dh_sendMessage);
}

void Heavy_pdpoly::cBinop_4HYoHA2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_MJ8kK3DU, 0, m, &cTabread_MJ8kK3DU_sendMessage);
}

void Heavy_pdpoly::cMsg_2GSAtqBn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZvyeN1eb_sendMessage);
}

void Heavy_pdpoly::cBinop_O209Pu1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4HYoHA2f, HV_BINOP_MIN, 1, m, &cBinop_4HYoHA2f_sendMessage);
}

void Heavy_pdpoly::cVar_P1RbjmJF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_7bpQzS0p, 1, m, &cTabwrite_7bpQzS0p_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_bLTXHtVU, 1, m, &cTabwrite_bLTXHtVU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Rzql1D6T, 1, m, &cVar_Rzql1D6T_sendMessage);
}

void Heavy_pdpoly::cSlice_hd6eToBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_pdpoly::cSlice_0rW28w98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nngMCRC3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g79vhKoP_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_DTqct87R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nXfUFBKx, HV_BINOP_EQ, 0, m, &cBinop_nXfUFBKx_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_EJ7PfAOr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_r8XpthtM, 0, m, &cSlice_r8XpthtM_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5kAWKwNc_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jlO5VhRc_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_r8XpthtM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_DTqct87R, 1, m, &cTabread_DTqct87R_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_DTqct87R, 1, m, &cTabread_DTqct87R_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_wMT77rsO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qhN8E1G0_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_CGupIpwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_K9Cx6Gj1_sendMessage);
}

void Heavy_pdpoly::cBinop_PHJd8B5x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EVEZeiL7, HV_BINOP_MIN, 0, m, &cBinop_EVEZeiL7_sendMessage);
}

void Heavy_pdpoly::cCast_jlO5VhRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_PHJd8B5x_sendMessage);
}

void Heavy_pdpoly::cCast_5kAWKwNc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wMT77rsO, 0, m, &cVar_wMT77rsO_sendMessage);
}

void Heavy_pdpoly::cBinop_EVEZeiL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_DTqct87R, 0, m, &cTabread_DTqct87R_sendMessage);
}

void Heavy_pdpoly::cMsg_qhN8E1G0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CGupIpwy_sendMessage);
}

void Heavy_pdpoly::cBinop_K9Cx6Gj1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EVEZeiL7, HV_BINOP_MIN, 1, m, &cBinop_EVEZeiL7_sendMessage);
}

void Heavy_pdpoly::cVar_AVb0enbj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_42jKpJYb, HV_BINOP_LESS_THAN, 1, m, &cBinop_42jKpJYb_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_nfAaz82w_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G7FKNJYZ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_G7FKNJYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lhMBszE8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UTGp7h19_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_17skL707_sendMessage);
}

void Heavy_pdpoly::cVar_fCgdAzzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_42jKpJYb, HV_BINOP_LESS_THAN, 1, m, &cBinop_42jKpJYb_sendMessage);
}

void Heavy_pdpoly::cIf_WhlaeSUA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xN0G9fHe_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_03l0JVof_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iD1DgPKS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_6t4aPuYa, 0, m, &cSlice_6t4aPuYa_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_GBd9Z2zF, 0, m, &cSlice_GBd9Z2zF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VfY7TDYG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_7bpQzS0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_Ec9QTKKd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Or4CDb3F, 0, m, &cSlice_Or4CDb3F_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_7bpQzS0p, 0, m, &cTabwrite_7bpQzS0p_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_Or4CDb3F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_7bpQzS0p, 2, m, &cTabwrite_7bpQzS0p_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_7bpQzS0p, 2, m, &cTabwrite_7bpQzS0p_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_bLTXHtVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_gtCzHjvm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_g9Rpcnwv, 0, m, &cSlice_g9Rpcnwv_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_bLTXHtVU, 0, m, &cTabwrite_bLTXHtVU_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_g9Rpcnwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_bLTXHtVU, 2, m, &cTabwrite_bLTXHtVU_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_bLTXHtVU, 2, m, &cTabwrite_bLTXHtVU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_rlRg7Ewf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_gtCzHjvm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cVar_Rzql1D6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TijI9t6B_sendMessage);
}

void Heavy_pdpoly::cSlice_6t4aPuYa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_pdpoly::cSlice_GBd9Z2zF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_oeMqprdv, 1, m, &cPack_oeMqprdv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cPack_wgYC5svO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6O5N0d8d_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7PZv9iBx_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_hd6eToBV, 0, m, &cSlice_hd6eToBV_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_0rW28w98, 0, m, &cSlice_0rW28w98_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_WhlaeSUA, 0, m, &cIf_WhlaeSUA_sendMessage);
}

void Heavy_pdpoly::cCast_ApqFaJuz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_P1RbjmJF, 1, m, &cVar_P1RbjmJF_sendMessage);
}

void Heavy_pdpoly::cCast_xQYjvogs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mDuEk8Gr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_fnAeSmyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SWFWZ5TQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_7hUMjIdg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_EJ7PfAOr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_n4mMygbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_WhlaeSUA, 1, m, &cIf_WhlaeSUA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_P1RbjmJF, 0, m, &cVar_P1RbjmJF_sendMessage);
}

void Heavy_pdpoly::cMsg_XIj0dFN5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_WhlaeSUA, 1, m, &cIf_WhlaeSUA_sendMessage);
}

void Heavy_pdpoly::cCast_7PZv9iBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n4mMygbV_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_6O5N0d8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AVb0enbj, 0, m, &cVar_AVb0enbj_sendMessage);
}

void Heavy_pdpoly::cCast_nngMCRC3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nXfUFBKx, HV_BINOP_EQ, 1, m, &cBinop_nXfUFBKx_sendMessage);
}

void Heavy_pdpoly::cCast_g79vhKoP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5YS3HbyR, 0, m, &cVar_5YS3HbyR_sendMessage);
}

void Heavy_pdpoly::cBinop_nXfUFBKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IPz2c8gx, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_IPz2c8gx_sendMessage);
}

void Heavy_pdpoly::cBinop_IPz2c8gx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_nfAaz82w_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_Sa45O2kp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IPz2c8gx, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_IPz2c8gx_sendMessage);
}

void Heavy_pdpoly::cBinop_42jKpJYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sa45O2kp, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_Sa45O2kp_sendMessage);
}

void Heavy_pdpoly::cCast_UTGp7h19_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XIj0dFN5_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_lhMBszE8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fCgdAzzA, 0, m, &cVar_fCgdAzzA_sendMessage);
}

void Heavy_pdpoly::cCast_17skL707_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_P1RbjmJF, 0, m, &cVar_P1RbjmJF_sendMessage);
}

void Heavy_pdpoly::cCast_FxJEYMfT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_42jKpJYb, HV_BINOP_LESS_THAN, 0, m, &cBinop_42jKpJYb_sendMessage);
}

void Heavy_pdpoly::cCast_0stxtk86_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fCgdAzzA, 1, m, &cVar_fCgdAzzA_sendMessage);
}

void Heavy_pdpoly::cCast_73R6hR9E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rlRg7Ewf, 0, m, &cVar_rlRg7Ewf_sendMessage);
}

void Heavy_pdpoly::cCast_KkZFHJ6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_O5rvpvHp_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_O5rvpvHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5wIX5vHs_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_xN0G9fHe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pnfEyGvp_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_03l0JVof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KkZFHJ6a_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_73R6hR9E_sendMessage);
}

void Heavy_pdpoly::cMsg_pnfEyGvp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Ec9QTKKd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_VfY7TDYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Rzql1D6T, 0, m, &cVar_Rzql1D6T_sendMessage);
}

void Heavy_pdpoly::cCast_iD1DgPKS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GuyAwXHv_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_GuyAwXHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_oeMqprdv, 2, m, &cPack_oeMqprdv_sendMessage);
}

void Heavy_pdpoly::cIf_VfglTXiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lWio3cc1_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MGSVQdG1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_KvQ4Fzya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZH0uNlAi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0YuAUiwP_sendMessage);
}

void Heavy_pdpoly::cIf_V4h68Ggb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_I37wvsAn_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_f4xxBBj6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_OzVxJqr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_V4h68Ggb, 1, m, &cIf_V4h68Ggb_sendMessage);
}

void Heavy_pdpoly::cVar_row8DAB4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_NnpO2M4K_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Kns6SYwE, 0, m, &cIf_Kns6SYwE_sendMessage);
}

void Heavy_pdpoly::cUnop_2uKqrKRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_OzVxJqr5_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_V4h68Ggb, 0, m, &cIf_V4h68Ggb_sendMessage);
}

void Heavy_pdpoly::cUnop_OLtP9FI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_OzVxJqr5_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_V4h68Ggb, 0, m, &cIf_V4h68Ggb_sendMessage);
}

void Heavy_pdpoly::cIf_Kns6SYwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_OLtP9FI6_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2uKqrKRA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_NnpO2M4K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Kns6SYwE, 1, m, &cIf_Kns6SYwE_sendMessage);
}

void Heavy_pdpoly::cCast_0YuAUiwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VfglTXiL, 0, m, &cIf_VfglTXiL_sendMessage);
}

void Heavy_pdpoly::cCast_ZH0uNlAi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YWuo5DXQ, HV_BINOP_LESS_THAN, 0, m, &cBinop_YWuo5DXQ_sendMessage);
}

void Heavy_pdpoly::cBinop_YWuo5DXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VfglTXiL, 1, m, &cIf_VfglTXiL_sendMessage);
}

void Heavy_pdpoly::cCast_f4xxBBj6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jc6K7CQT_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_I37wvsAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YWuo5DXQ, HV_BINOP_LESS_THAN, 1, m, &cBinop_YWuo5DXQ_sendMessage);
}

void Heavy_pdpoly::cBinop_ZWEWYhjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KvQ4Fzya, 0, m, &cVar_KvQ4Fzya_sendMessage);
}

void Heavy_pdpoly::cMsg_jc6K7CQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_KvQ4Fzya, 0, m, &cVar_KvQ4Fzya_sendMessage);
}

void Heavy_pdpoly::cCast_MGSVQdG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ZWEWYhjZ_sendMessage);
}

void Heavy_pdpoly::cCast_lWio3cc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NNRjKZnL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S332QhHF_sendMessage);
}

void Heavy_pdpoly::cVar_ToWXJRu0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_row8DAB4, 0, m, &cVar_row8DAB4_sendMessage);
}

void Heavy_pdpoly::cTabwrite_77NiY5EF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_TlCNWz9a_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Sv38SPGD, 0, m, &cSlice_Sv38SPGD_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_77NiY5EF, 0, m, &cTabwrite_77NiY5EF_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_Sv38SPGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_77NiY5EF, 2, m, &cTabwrite_77NiY5EF_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_77NiY5EF, 2, m, &cTabwrite_77NiY5EF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_2LF9bUc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_thk086Y4_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_JHr1WOjO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_s1jKmfW8, 0, m, &cSlice_s1jKmfW8_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BZ2OsIJK_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Tan6lNsy_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_s1jKmfW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_2LF9bUc8, 1, m, &cTabread_2LF9bUc8_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_2LF9bUc8, 1, m, &cTabread_2LF9bUc8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_LuuM7h67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vFx7QXFm_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_fdgdWwq6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZVB8eX3M_sendMessage);
}

void Heavy_pdpoly::cBinop_NSSHHbPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UGHeWlH6, HV_BINOP_MIN, 0, m, &cBinop_UGHeWlH6_sendMessage);
}

void Heavy_pdpoly::cCast_BZ2OsIJK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LuuM7h67, 0, m, &cVar_LuuM7h67_sendMessage);
}

void Heavy_pdpoly::cCast_Tan6lNsy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_NSSHHbPD_sendMessage);
}

void Heavy_pdpoly::cBinop_UGHeWlH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_2LF9bUc8, 0, m, &cTabread_2LF9bUc8_sendMessage);
}

void Heavy_pdpoly::cMsg_vFx7QXFm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fdgdWwq6_sendMessage);
}

void Heavy_pdpoly::cBinop_ZVB8eX3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UGHeWlH6, HV_BINOP_MIN, 1, m, &cBinop_UGHeWlH6_sendMessage);
}

void Heavy_pdpoly::cIf_PcYHCyls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_it0IUAHh_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wVqPYMOa_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_twrkGOYU_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rmAVLYyF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R36yM3vY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_2AgvsBOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oeMqprdv, 1, m, &cPack_oeMqprdv_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_4Jo0kecf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hOZSn7fr, 0, m, &cSlice_hOZSn7fr_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XvvfvxYi_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_W06Z8LU1_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_hOZSn7fr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_2AgvsBOX, 1, m, &cTabread_2AgvsBOX_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_2AgvsBOX, 1, m, &cTabread_2AgvsBOX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_QZ9iEFyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ItGjyPuB_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_FbXNlv2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hfWLisKo_sendMessage);
}

void Heavy_pdpoly::cBinop_TEkFRRgS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n6uJJvvB, HV_BINOP_MIN, 0, m, &cBinop_n6uJJvvB_sendMessage);
}

void Heavy_pdpoly::cCast_W06Z8LU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_TEkFRRgS_sendMessage);
}

void Heavy_pdpoly::cCast_XvvfvxYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QZ9iEFyk, 0, m, &cVar_QZ9iEFyk_sendMessage);
}

void Heavy_pdpoly::cBinop_n6uJJvvB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_2AgvsBOX, 0, m, &cTabread_2AgvsBOX_sendMessage);
}

void Heavy_pdpoly::cMsg_ItGjyPuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FbXNlv2s_sendMessage);
}

void Heavy_pdpoly::cBinop_hfWLisKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n6uJJvvB, HV_BINOP_MIN, 1, m, &cBinop_n6uJJvvB_sendMessage);
}

void Heavy_pdpoly::cCast_vth6P80y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ToWXJRu0, 0, m, &cVar_ToWXJRu0_sendMessage);
}

void Heavy_pdpoly::cCast_FGtyP19l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LzjjbdyZ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_LzjjbdyZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_ky49RPzj_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_ky49RPzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5wIX5vHs_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_thk086Y4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PcYHCyls, 1, m, &cIf_PcYHCyls_sendMessage);
}

void Heavy_pdpoly::cCast_S332QhHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PcYHCyls, 0, m, &cIf_PcYHCyls_sendMessage);
}

void Heavy_pdpoly::cCast_NNRjKZnL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JHr1WOjO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_kzUHHsxD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_oeMqprdv, 2, m, &cPack_oeMqprdv_sendMessage);
}

void Heavy_pdpoly::cCast_twrkGOYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TijI9t6B_sendMessage);
}

void Heavy_pdpoly::cCast_R36yM3vY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IAfya4fw_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_wVqPYMOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4Jo0kecf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_rmAVLYyF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_c2E6w295_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2ggrIek1_sendMessage);
}

void Heavy_pdpoly::cCast_it0IUAHh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kzUHHsxD_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_2ggrIek1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_T2V4pDsk_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_c2E6w295_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_77NiY5EF, 1, m, &cTabwrite_77NiY5EF_sendMessage);
}

void Heavy_pdpoly::cMsg_T2V4pDsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_TlCNWz9a_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSend_IAfya4fw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5wIX5vHs_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_MAsQdjs8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7S4dZy0P_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_voD2owVE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_YsA6Dodv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Jx1HDXut_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yINHRByy_sendMessage);
}

void Heavy_pdpoly::cIf_SKDfoO01_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WMwqe2Ht_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_asCpJ3Od_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_grqTJ85g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SKDfoO01, 1, m, &cIf_SKDfoO01_sendMessage);
}

void Heavy_pdpoly::cVar_0KuQq8fK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_9eMIQqxO_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_wgHSSPWc, 0, m, &cIf_wgHSSPWc_sendMessage);
}

void Heavy_pdpoly::cUnop_z8tJZMM9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_grqTJ85g_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_SKDfoO01, 0, m, &cIf_SKDfoO01_sendMessage);
}

void Heavy_pdpoly::cUnop_ws5Zx1yv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_grqTJ85g_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_SKDfoO01, 0, m, &cIf_SKDfoO01_sendMessage);
}

void Heavy_pdpoly::cIf_wgHSSPWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_ws5Zx1yv_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_z8tJZMM9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_9eMIQqxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wgHSSPWc, 1, m, &cIf_wgHSSPWc_sendMessage);
}

void Heavy_pdpoly::cCast_Jx1HDXut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H7QVgaSs, HV_BINOP_LESS_THAN, 0, m, &cBinop_H7QVgaSs_sendMessage);
}

void Heavy_pdpoly::cCast_yINHRByy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MAsQdjs8, 0, m, &cIf_MAsQdjs8_sendMessage);
}

void Heavy_pdpoly::cBinop_H7QVgaSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_MAsQdjs8, 1, m, &cIf_MAsQdjs8_sendMessage);
}

void Heavy_pdpoly::cCast_asCpJ3Od_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zwAKECnt_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_WMwqe2Ht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H7QVgaSs, HV_BINOP_LESS_THAN, 1, m, &cBinop_H7QVgaSs_sendMessage);
}

void Heavy_pdpoly::cBinop_v4JeS4Am_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YsA6Dodv, 0, m, &cVar_YsA6Dodv_sendMessage);
}

void Heavy_pdpoly::cMsg_zwAKECnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_YsA6Dodv, 0, m, &cVar_YsA6Dodv_sendMessage);
}

void Heavy_pdpoly::cCast_voD2owVE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_v4JeS4Am_sendMessage);
}

void Heavy_pdpoly::cCast_7S4dZy0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_QAPw1Np8, 1, m, &cTabwrite_QAPw1Np8_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_tUZzbTpT, 1, m, &cTabwrite_tUZzbTpT_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_vXLuqL2L, 1, m, &cTabwrite_vXLuqL2L_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b1Gt2weu_sendMessage);
}

void Heavy_pdpoly::cVar_HdNusQeV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0KuQq8fK, 0, m, &cVar_0KuQq8fK_sendMessage);
}

void Heavy_pdpoly::cTabwrite_vXLuqL2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_kb8qFiuv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iA2q7qA0, 0, m, &cSlice_iA2q7qA0_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_vXLuqL2L, 0, m, &cTabwrite_vXLuqL2L_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_iA2q7qA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_vXLuqL2L, 2, m, &cTabwrite_vXLuqL2L_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_vXLuqL2L, 2, m, &cTabwrite_vXLuqL2L_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_tUZzbTpT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_HIoVq99X_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_bEBijJde, 0, m, &cSlice_bEBijJde_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_tUZzbTpT, 0, m, &cTabwrite_tUZzbTpT_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_bEBijJde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_tUZzbTpT, 2, m, &cTabwrite_tUZzbTpT_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_tUZzbTpT, 2, m, &cTabwrite_tUZzbTpT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_QAPw1Np8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_kt6tHckF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hNEmzIbu, 0, m, &cSlice_hNEmzIbu_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_QAPw1Np8, 0, m, &cTabwrite_QAPw1Np8_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_hNEmzIbu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_QAPw1Np8, 2, m, &cTabwrite_QAPw1Np8_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_QAPw1Np8, 2, m, &cTabwrite_QAPw1Np8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cMsg_b7rqY9v4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_kt6tHckF_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_HIoVq99X_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_kb8qFiuv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_9vmwPaZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HdNusQeV, 0, m, &cVar_HdNusQeV_sendMessage);
}

void Heavy_pdpoly::cCast_OYd55W1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d9T1DLwj_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_d9T1DLwj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_17ErLSQM_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_17ErLSQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5wIX5vHs_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_b1Gt2weu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b7rqY9v4_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_0rzoSiTi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_M65FW9vd_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OTOvbrrZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_MQiXbJPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ykJpIlLA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uAdYCzAa_sendMessage);
}

void Heavy_pdpoly::cIf_1oEVWhUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VSYjfAhg_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_f9I8ofzc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_fuhVKSKs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1oEVWhUE, 1, m, &cIf_1oEVWhUE_sendMessage);
}

void Heavy_pdpoly::cVar_lOGtSZeI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_uQGvqwwy_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_zIAPwwmq, 0, m, &cIf_zIAPwwmq_sendMessage);
}

void Heavy_pdpoly::cUnop_H3IB6IWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_fuhVKSKs_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_1oEVWhUE, 0, m, &cIf_1oEVWhUE_sendMessage);
}

void Heavy_pdpoly::cUnop_ZzCsgZFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_fuhVKSKs_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_1oEVWhUE, 0, m, &cIf_1oEVWhUE_sendMessage);
}

void Heavy_pdpoly::cIf_zIAPwwmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_ZzCsgZFv_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_H3IB6IWc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_uQGvqwwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zIAPwwmq, 1, m, &cIf_zIAPwwmq_sendMessage);
}

void Heavy_pdpoly::cCast_uAdYCzAa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0rzoSiTi, 0, m, &cIf_0rzoSiTi_sendMessage);
}

void Heavy_pdpoly::cCast_ykJpIlLA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_je6fjA7a, HV_BINOP_LESS_THAN, 0, m, &cBinop_je6fjA7a_sendMessage);
}

void Heavy_pdpoly::cBinop_je6fjA7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0rzoSiTi, 1, m, &cIf_0rzoSiTi_sendMessage);
}

void Heavy_pdpoly::cCast_f9I8ofzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5NbKnfSL_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_VSYjfAhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_je6fjA7a, HV_BINOP_LESS_THAN, 1, m, &cBinop_je6fjA7a_sendMessage);
}

void Heavy_pdpoly::cBinop_fRgeIzWg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MQiXbJPW, 0, m, &cVar_MQiXbJPW_sendMessage);
}

void Heavy_pdpoly::cMsg_5NbKnfSL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_MQiXbJPW, 0, m, &cVar_MQiXbJPW_sendMessage);
}

void Heavy_pdpoly::cCast_OTOvbrrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_fRgeIzWg_sendMessage);
}

void Heavy_pdpoly::cCast_M65FW9vd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lxHAqJvG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_42ZRGeA3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9FG8sF45_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bMmE5UHi_sendMessage);
}

void Heavy_pdpoly::cVar_efsQgUhC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lOGtSZeI, 0, m, &cVar_lOGtSZeI_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_38AjFplL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CBSjdjzG_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_CBSjdjzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yVvMhbIb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mzDIF5jC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lLMUCXS4_sendMessage);
}

void Heavy_pdpoly::cVar_JGCCQAla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_llNti9gA_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_YHsYOo8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_3anm38Fx_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_21LKdHxo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_WX0qtaVW_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSwitchcase_3anm38Fx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S5xlG5mz_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_S5xlG5mz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cgRWoffF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0H2EbpaL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LEZPJJMB_sendMessage);
}

void Heavy_pdpoly::cVar_mLuBC367_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OLpUC06p, HV_BINOP_LESS_THAN, 1, m, &cBinop_OLpUC06p_sendMessage);
}

void Heavy_pdpoly::cVar_Qhd8DooS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uhLM6rkl, HV_BINOP_LESS_THAN, 1, m, &cBinop_uhLM6rkl_sendMessage);
}

void Heavy_pdpoly::cIf_CmbB9J8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Jj5Oah1t, 0, m, &cSlice_Jj5Oah1t_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_YxRlSKIt, 0, m, &cSlice_YxRlSKIt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ytUCvxSp_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dfqS883v_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zgFY2c82_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_p4s6QG25_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ppnEVSvx_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_xACQ0mC2, 0, m, &cSlice_xACQ0mC2_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_3omKebEs, 0, m, &cSlice_3omKebEs_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XThWee9w_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fdPOYlL0_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_idg2LE5H_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cPack_m0IbC46o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_p4s6QG25, 0, m, &cIf_p4s6QG25_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_CmbB9J8u, 0, m, &cIf_CmbB9J8u_sendMessage);
}

void Heavy_pdpoly::cVar_t9hxiyyF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TijI9t6B_sendMessage);
}

void Heavy_pdpoly::cSlice_Jj5Oah1t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_oeMqprdv, 2, m, &cPack_oeMqprdv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_YxRlSKIt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_OnGrXtfh_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_oeMqprdv, 1, m, &cPack_oeMqprdv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_nyYdYuej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TijI9t6B_sendMessage);
}

void Heavy_pdpoly::cIf_yqhwH2zn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_p4s6QG25, 1, m, &cIf_p4s6QG25_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_y1WxshAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_2LsJLB7i_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cVar_WpOGftwj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_PDRCJDpV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cTabread_a4DFHPg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vLMz8bps_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2tAmmSMm_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_GbCqazGq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XzwmPsCc, 0, m, &cSlice_XzwmPsCc_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KLny29gm_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7H4W2TrJ_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_XzwmPsCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_a4DFHPg4, 1, m, &cTabread_a4DFHPg4_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_a4DFHPg4, 1, m, &cTabread_a4DFHPg4_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_QZSsxHWl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bQ1AB0hA_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_mwWCN46a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Cvy1CAdk_sendMessage);
}

void Heavy_pdpoly::cBinop_NyKcZMcy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hu78Pg8r, HV_BINOP_MIN, 0, m, &cBinop_Hu78Pg8r_sendMessage);
}

void Heavy_pdpoly::cCast_KLny29gm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QZSsxHWl, 0, m, &cVar_QZSsxHWl_sendMessage);
}

void Heavy_pdpoly::cCast_7H4W2TrJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_NyKcZMcy_sendMessage);
}

void Heavy_pdpoly::cBinop_Hu78Pg8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_a4DFHPg4, 0, m, &cTabread_a4DFHPg4_sendMessage);
}

void Heavy_pdpoly::cMsg_bQ1AB0hA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mwWCN46a_sendMessage);
}

void Heavy_pdpoly::cBinop_Cvy1CAdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Hu78Pg8r, HV_BINOP_MIN, 1, m, &cBinop_Hu78Pg8r_sendMessage);
}

void Heavy_pdpoly::cTabread_kLHkjQe0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ej9rToFt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_n2MNfbc0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HH5bVK1C_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_8ofIUcNi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZMtrw3Ut, 0, m, &cSlice_ZMtrw3Ut_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DOoLrLMi_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nIExv0GW_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_ZMtrw3Ut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_kLHkjQe0, 1, m, &cTabread_kLHkjQe0_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_kLHkjQe0, 1, m, &cTabread_kLHkjQe0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_xx8L9MEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GplDl0Sg_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_tlbBgxEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_5M6wjhja_sendMessage);
}

void Heavy_pdpoly::cBinop_8QFiKaE0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oysoCkSt, HV_BINOP_MIN, 0, m, &cBinop_oysoCkSt_sendMessage);
}

void Heavy_pdpoly::cCast_nIExv0GW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8QFiKaE0_sendMessage);
}

void Heavy_pdpoly::cCast_DOoLrLMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xx8L9MEM, 0, m, &cVar_xx8L9MEM_sendMessage);
}

void Heavy_pdpoly::cBinop_oysoCkSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_kLHkjQe0, 0, m, &cTabread_kLHkjQe0_sendMessage);
}

void Heavy_pdpoly::cMsg_GplDl0Sg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tlbBgxEO_sendMessage);
}

void Heavy_pdpoly::cBinop_5M6wjhja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oysoCkSt, HV_BINOP_MIN, 1, m, &cBinop_oysoCkSt_sendMessage);
}

void Heavy_pdpoly::cTabwrite_JeC2ILwJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_moqSZJnq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_meFUd4ns, 0, m, &cSlice_meFUd4ns_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_JeC2ILwJ, 0, m, &cTabwrite_JeC2ILwJ_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_meFUd4ns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_JeC2ILwJ, 2, m, &cTabwrite_JeC2ILwJ_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_JeC2ILwJ, 2, m, &cTabwrite_JeC2ILwJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_pvZwjjaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oeMqprdv, 1, m, &cPack_oeMqprdv_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_2LsJLB7i_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0mZWWkoA, 0, m, &cSlice_0mZWWkoA_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5viRfwRN_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bdOkDEWz_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_0mZWWkoA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_pvZwjjaL, 1, m, &cTabread_pvZwjjaL_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_pvZwjjaL, 1, m, &cTabread_pvZwjjaL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_2JJSPgXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q5wqO3Cu_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_pWzr76os_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_sbCMdVkj_sendMessage);
}

void Heavy_pdpoly::cBinop_l8YvZx0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yyfete62, HV_BINOP_MIN, 0, m, &cBinop_Yyfete62_sendMessage);
}

void Heavy_pdpoly::cCast_bdOkDEWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_l8YvZx0M_sendMessage);
}

void Heavy_pdpoly::cCast_5viRfwRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2JJSPgXK, 0, m, &cVar_2JJSPgXK_sendMessage);
}

void Heavy_pdpoly::cBinop_Yyfete62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_pvZwjjaL, 0, m, &cTabread_pvZwjjaL_sendMessage);
}

void Heavy_pdpoly::cMsg_Q5wqO3Cu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pWzr76os_sendMessage);
}

void Heavy_pdpoly::cBinop_sbCMdVkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Yyfete62, HV_BINOP_MIN, 1, m, &cBinop_Yyfete62_sendMessage);
}

void Heavy_pdpoly::cTabwrite_0KNrmZYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_OnGrXtfh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_k05M8rZY, 0, m, &cSlice_k05M8rZY_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_0KNrmZYO, 0, m, &cTabwrite_0KNrmZYO_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_k05M8rZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_0KNrmZYO, 2, m, &cTabwrite_0KNrmZYO_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_0KNrmZYO, 2, m, &cTabwrite_0KNrmZYO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_U68ZtQCI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_HmnxP4pd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JWSEJKU9, 0, m, &cSlice_JWSEJKU9_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_U68ZtQCI, 0, m, &cTabwrite_U68ZtQCI_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_JWSEJKU9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_U68ZtQCI, 2, m, &cTabwrite_U68ZtQCI_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_U68ZtQCI, 2, m, &cTabwrite_U68ZtQCI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_Gll4eGKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_PDRCJDpV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_EmZJOq1Y, 0, m, &cSlice_EmZJOq1Y_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Gll4eGKI, 0, m, &cTabwrite_Gll4eGKI_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_EmZJOq1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Gll4eGKI, 2, m, &cTabwrite_Gll4eGKI_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Gll4eGKI, 2, m, &cTabwrite_Gll4eGKI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_LszWQ7QZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_9GPKkNka_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_DXFeehZ3, 0, m, &cSlice_DXFeehZ3_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_LszWQ7QZ, 0, m, &cTabwrite_LszWQ7QZ_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_DXFeehZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_LszWQ7QZ, 2, m, &cTabwrite_LszWQ7QZ_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_LszWQ7QZ, 2, m, &cTabwrite_LszWQ7QZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_9Zcwzybn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9GPKkNka_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cTabwrite_jnk5hZ9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_SD0MwiiI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_DrhonvgX, 0, m, &cSlice_DrhonvgX_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jnk5hZ9p, 0, m, &cTabwrite_jnk5hZ9p_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_DrhonvgX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jnk5hZ9p, 2, m, &cTabwrite_jnk5hZ9p_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jnk5hZ9p, 2, m, &cTabwrite_jnk5hZ9p_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_ORjgs46o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9MsC8sUB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3dkSTMQi_sendMessage);
}

void Heavy_pdpoly::cSlice_xACQ0mC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_oeMqprdv, 2, m, &cPack_oeMqprdv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_3omKebEs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_moqSZJnq_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_oeMqprdv, 1, m, &cPack_oeMqprdv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_HGdcJwdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iyNfprqq, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_iyNfprqq_sendMessage);
}

void Heavy_pdpoly::cBinop_FnRNka2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RiAuaVmD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ffykz1zP_sendMessage);
}

void Heavy_pdpoly::cBinop_OLpUC06p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I2mIw4Kd, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_I2mIw4Kd_sendMessage);
}

void Heavy_pdpoly::cCast_9FG8sF45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GbCqazGq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_lxHAqJvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JGCCQAla, 1, m, &cVar_JGCCQAla_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_21LKdHxo, 1, m, &cVar_21LKdHxo_sendMessage);
}

void Heavy_pdpoly::cCast_42ZRGeA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_8ofIUcNi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_bMmE5UHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSend_llNti9gA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xx3nUNJm_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_vLMz8bps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FnRNka2z, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_FnRNka2z_sendMessage);
}

void Heavy_pdpoly::cCast_2tAmmSMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_lwOoQ32F_sendMessage);
}

void Heavy_pdpoly::cBinop_I2mIw4Kd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YHsYOo8K, 0, m, &cIf_YHsYOo8K_sendMessage);
}

void Heavy_pdpoly::cBinop_lwOoQ32F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I2mIw4Kd, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_I2mIw4Kd_sendMessage);
}

void Heavy_pdpoly::cCast_RiAuaVmD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_38AjFplL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_ffykz1zP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_qARGjqMC_sendMessage);
}

void Heavy_pdpoly::cBinop_qARGjqMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YHsYOo8K, 1, m, &cIf_YHsYOo8K_sendMessage);
}

void Heavy_pdpoly::cSend_WX0qtaVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AnAGAMlI_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_nfXBLAb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xx3nUNJm_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_z3ERL1Rw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_AnAGAMlI_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_ww9Rojla_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ugxYQW8s_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_qAMhqCG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ORjgs46o, 0, m, &cVar_ORjgs46o_sendMessage);
}

void Heavy_pdpoly::cCast_zvAiXZMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_efsQgUhC, 0, m, &cVar_efsQgUhC_sendMessage);
}

void Heavy_pdpoly::cBinop_uhLM6rkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FnRNka2z, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_FnRNka2z_sendMessage);
}

void Heavy_pdpoly::cCast_HH5bVK1C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OLpUC06p, HV_BINOP_LESS_THAN, 0, m, &cBinop_OLpUC06p_sendMessage);
}

void Heavy_pdpoly::cCast_Ej9rToFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mLuBC367, 1, m, &cVar_mLuBC367_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Qhd8DooS, 1, m, &cVar_Qhd8DooS_sendMessage);
}

void Heavy_pdpoly::cCast_n2MNfbc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uhLM6rkl, HV_BINOP_LESS_THAN, 0, m, &cBinop_uhLM6rkl_sendMessage);
}

void Heavy_pdpoly::cCast_9MsC8sUB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Qhd8DooS, 0, m, &cVar_Qhd8DooS_sendMessage);
}

void Heavy_pdpoly::cCast_3dkSTMQi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mLuBC367, 0, m, &cVar_mLuBC367_sendMessage);
}

void Heavy_pdpoly::cSend_v6zsPm6p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2blUjMar_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_cgRWoffF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mLuBC367, 0, m, &cVar_mLuBC367_sendMessage);
}

void Heavy_pdpoly::cCast_LEZPJJMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_21LKdHxo, 0, m, &cVar_21LKdHxo_sendMessage);
}

void Heavy_pdpoly::cCast_0H2EbpaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hEKmyxr0_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_hEKmyxr0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_v6zsPm6p_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_6A0RPwnD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_JxzfWnKb_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_JxzfWnKb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gDOtbvR0_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_mzDIF5jC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6A0RPwnD_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_yVvMhbIb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Qhd8DooS, 0, m, &cVar_Qhd8DooS_sendMessage);
}

void Heavy_pdpoly::cCast_lLMUCXS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JGCCQAla, 0, m, &cVar_JGCCQAla_sendMessage);
}

void Heavy_pdpoly::cMsg_ugxYQW8s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_z3ERL1Rw_sendMessage(_c, 0, m);
  cSend_nfXBLAb7_sendMessage(_c, 0, m);
  cSend_2tSYSCAX_sendMessage(_c, 0, m);
  cSend_9JH8QwjA_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_2tSYSCAX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gDOtbvR0_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_9JH8QwjA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2blUjMar_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_d7JCwiFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_CmbB9J8u, 1, m, &cIf_CmbB9J8u_sendMessage);
}

void Heavy_pdpoly::cCast_froDbiX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_AmsIMyml_sendMessage);
}

void Heavy_pdpoly::cBinop_iyNfprqq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yqhwH2zn, 0, m, &cIf_yqhwH2zn_sendMessage);
}

void Heavy_pdpoly::cBinop_AmsIMyml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HGdcJwdj, 0, m, &cVar_HGdcJwdj_sendMessage);
}

void Heavy_pdpoly::cMsg_J98g7Mq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_HmnxP4pd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_UM3lUuIl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_SD0MwiiI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_DFYPqJzj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nyYdYuej, 0, m, &cVar_nyYdYuej_sendMessage);
}

void Heavy_pdpoly::cCast_NrVJQnRS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y1WxshAL, 0, m, &cVar_y1WxshAL_sendMessage);
}

void Heavy_pdpoly::cCast_q3vRjElp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jasC95Zg_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_jasC95Zg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_oeMqprdv, 2, m, &cPack_oeMqprdv_sendMessage);
}

void Heavy_pdpoly::cCast_dfqS883v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J98g7Mq0_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_ytUCvxSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t9hxiyyF, 0, m, &cVar_t9hxiyyF_sendMessage);
}

void Heavy_pdpoly::cCast_zgFY2c82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xOzpVsiq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YBV6ozuF_sendMessage);
}

void Heavy_pdpoly::cCast_YBV6ozuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WpOGftwj, 0, m, &cVar_WpOGftwj_sendMessage);
}

void Heavy_pdpoly::cCast_xOzpVsiq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tITs9BJx_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_tITs9BJx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5wIX5vHs_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_07cdAk31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9Zcwzybn, 0, m, &cVar_9Zcwzybn_sendMessage);
}

void Heavy_pdpoly::cCast_8ycEIlaj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RasK5k8m_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_RasK5k8m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_5wIX5vHs_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_fdPOYlL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UM3lUuIl_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_idg2LE5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8ycEIlaj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_07cdAk31_sendMessage);
}

void Heavy_pdpoly::cCast_XThWee9w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nyYdYuej, 0, m, &cVar_nyYdYuej_sendMessage);
}

void Heavy_pdpoly::cCast_ppnEVSvx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q3vRjElp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NrVJQnRS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DFYPqJzj_sendMessage);
}

void Heavy_pdpoly::cCast_9dZxTYfW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HGdcJwdj, 0, m, &cVar_HGdcJwdj_sendMessage);
}

void Heavy_pdpoly::cCast_WIIgdLk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iyNfprqq, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_iyNfprqq_sendMessage);
}

void Heavy_pdpoly::cSend_DZwIMfKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_QJNkIbFy_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_dD76FbSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HTRxATFx, 1, m, &cVar_HTRxATFx_sendMessage);
}

void Heavy_pdpoly::cSend_7SrY6HtY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lSPycKip_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_TijI9t6B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_oeMqprdv, 0, m, &cPack_oeMqprdv_sendMessage);
}

void Heavy_pdpoly::cBinop_G7itATmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_dD76FbSA_sendMessage);
  cSend_7SrY6HtY_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::hTable_sOb2BYmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::hTable_nqhVhaIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::hTable_RhMviSoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cCast_aEu6DlQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4s9UpjsB_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_KAt3YIia_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fy5hAiJr, 0, m, &cVar_fy5hAiJr_sendMessage);
}

void Heavy_pdpoly::cSend_11P9OixE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Nx3o17bm_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_4s9UpjsB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 65535.0f);
  cSend_11P9OixE_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_Dml6eVpZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uJfCHij7, 1, m, &cIf_uJfCHij7_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_c0mEyoBu_sendMessage);
}

void Heavy_pdpoly::cBinop_c0mEyoBu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_pq3fytoe, 1, m, &cIf_pq3fytoe_sendMessage);
}

void Heavy_pdpoly::cBinop_C8ssn6lA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_DZwIMfKc_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cPack_oeMqprdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TSsbTCdN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSwitchcase_TSsbTCdN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ooaPzFdZ, 0, m, &cSlice_ooaPzFdZ_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_U9yjodK5, 0, m, &cSlice_U9yjodK5_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZPMzCRDc, 0, m, &cSlice_ZPMzCRDc_sendMessage);
      break;
    }
    case 0x40800000: { // "4.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PWoU7Aqs, 0, m, &cSlice_PWoU7Aqs_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_ooaPzFdZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_QiFPVoUS, 0, m, &cSlice_QiFPVoUS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ySBAmjnc, 0, m, &cSlice_ySBAmjnc_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_QiFPVoUS, 0, m, &cSlice_QiFPVoUS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ySBAmjnc, 0, m, &cSlice_ySBAmjnc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_U9yjodK5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_kav9ZjpO, 0, m, &cSlice_kav9ZjpO_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_M7XjvI8x, 0, m, &cSlice_M7XjvI8x_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_kav9ZjpO, 0, m, &cSlice_kav9ZjpO_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_M7XjvI8x, 0, m, &cSlice_M7XjvI8x_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_ZPMzCRDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_CCiWHZfO, 0, m, &cSlice_CCiWHZfO_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_C7n0rTMp, 0, m, &cSlice_C7n0rTMp_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_CCiWHZfO, 0, m, &cSlice_CCiWHZfO_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_C7n0rTMp, 0, m, &cSlice_C7n0rTMp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_PWoU7Aqs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_jwWKPi40, 0, m, &cSlice_jwWKPi40_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_81v5NwxA, 0, m, &cSlice_81v5NwxA_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_jwWKPi40, 0, m, &cSlice_jwWKPi40_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_81v5NwxA, 0, m, &cSlice_81v5NwxA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_QiFPVoUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_s24FQCwO_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_ySBAmjnc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_DwFUc1Mg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_O95AbhMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_jV2cDyYP, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_FG1NHaxs_sendMessage);
}

void Heavy_pdpoly::cBinop_DwFUc1Mg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_z1MNDfFo_sendMessage);
}

void Heavy_pdpoly::cBinop_z1MNDfFo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IT4T35pJ, HV_BINOP_POW, 1, m, &cBinop_IT4T35pJ_sendMessage);
  cMsg_SWjsGD0z_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_IT4T35pJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_O95AbhMf_sendMessage);
}

void Heavy_pdpoly::cMsg_SWjsGD0z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IT4T35pJ, HV_BINOP_POW, 0, m, &cBinop_IT4T35pJ_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_s24FQCwO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xkFZoraw_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_yuwpvtl4_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_xkFZoraw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_P38Y0NdR_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_2gtXAChe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_txFGC8A9, HV_BINOP_MULTIPLY, 0, m, &cBinop_txFGC8A9_sendMessage);
}

void Heavy_pdpoly::cMsg_sxwe3tKM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6vTERPwY_sendMessage);
}

void Heavy_pdpoly::cSystem_6vTERPwY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ynlm0bWi_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_txFGC8A9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_AfpAfFu3_sendMessage);
}

void Heavy_pdpoly::cBinop_VYSOgX6e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_txFGC8A9, HV_BINOP_MULTIPLY, 1, m, &cBinop_txFGC8A9_sendMessage);
}

void Heavy_pdpoly::cMsg_Ynlm0bWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_VYSOgX6e_sendMessage);
}

void Heavy_pdpoly::cBinop_AfpAfFu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_XNWeYg9r_sendMessage);
}

void Heavy_pdpoly::cBinop_XNWeYg9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8Ug4k7ie_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_DEXGwPIf, m);
}

void Heavy_pdpoly::cBinop_8Ug4k7ie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dGld7Ry0, m);
}

void Heavy_pdpoly::cVar_bBamG7lg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wYL69RAO, HV_BINOP_MULTIPLY, 0, m, &cBinop_wYL69RAO_sendMessage);
}

void Heavy_pdpoly::cMsg_0aGwUIGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8ePujGNU_sendMessage);
}

void Heavy_pdpoly::cSystem_8ePujGNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HZUf0sED_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_wYL69RAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_5h94bAXg_sendMessage);
}

void Heavy_pdpoly::cBinop_VwcZFGP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wYL69RAO, HV_BINOP_MULTIPLY, 1, m, &cBinop_wYL69RAO_sendMessage);
}

void Heavy_pdpoly::cMsg_HZUf0sED_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_VwcZFGP5_sendMessage);
}

void Heavy_pdpoly::cBinop_5h94bAXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_jx7NmRcj_sendMessage);
}

void Heavy_pdpoly::cBinop_jx7NmRcj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mHXMlQ7P_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TWLAsIA5, m);
}

void Heavy_pdpoly::cBinop_mHXMlQ7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zQ9Wsdbw, m);
}

void Heavy_pdpoly::cMsg_P38Y0NdR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_3cPgyhkE, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_yuwpvtl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UvzxQZai_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_UvzxQZai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_3cPgyhkE, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_FG1NHaxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_4dRRUrVF, 0, m);
}

void Heavy_pdpoly::cSlice_kav9ZjpO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_NrgHHwIR_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_M7XjvI8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_540fsBK9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_LSZlEuh6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_NnH0Ftp6, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_OlGeY48H_sendMessage);
}

void Heavy_pdpoly::cBinop_540fsBK9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_JqzCUxYj_sendMessage);
}

void Heavy_pdpoly::cBinop_JqzCUxYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gi2EUj9m, HV_BINOP_POW, 1, m, &cBinop_Gi2EUj9m_sendMessage);
  cMsg_OsUIxwwf_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_Gi2EUj9m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_LSZlEuh6_sendMessage);
}

void Heavy_pdpoly::cMsg_OsUIxwwf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gi2EUj9m, HV_BINOP_POW, 0, m, &cBinop_Gi2EUj9m_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_NrgHHwIR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yoeQ7F47_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_hseDALxQ_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_yoeQ7F47_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aKClssqb_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_jQn6vsH7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n4c9P2vb, HV_BINOP_MULTIPLY, 0, m, &cBinop_n4c9P2vb_sendMessage);
}

void Heavy_pdpoly::cMsg_dX3tGjXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_t6JeqWPC_sendMessage);
}

void Heavy_pdpoly::cSystem_t6JeqWPC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eDSgvEyR_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_n4c9P2vb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_pBAyFLN6_sendMessage);
}

void Heavy_pdpoly::cBinop_tOn0o20A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n4c9P2vb, HV_BINOP_MULTIPLY, 1, m, &cBinop_n4c9P2vb_sendMessage);
}

void Heavy_pdpoly::cMsg_eDSgvEyR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_tOn0o20A_sendMessage);
}

void Heavy_pdpoly::cBinop_pBAyFLN6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QdSG6Nbx_sendMessage);
}

void Heavy_pdpoly::cBinop_QdSG6Nbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_i9xJyAbK_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mtsk8ibJ, m);
}

void Heavy_pdpoly::cBinop_i9xJyAbK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YvcGEwE2, m);
}

void Heavy_pdpoly::cVar_hdZZODFX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KXxNiyvZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_KXxNiyvZ_sendMessage);
}

void Heavy_pdpoly::cMsg_k1Ctvq5m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9fmcs3f5_sendMessage);
}

void Heavy_pdpoly::cSystem_9fmcs3f5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t9fSF8mj_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_KXxNiyvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_GXZ13MvD_sendMessage);
}

void Heavy_pdpoly::cBinop_zNtkkBmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KXxNiyvZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_KXxNiyvZ_sendMessage);
}

void Heavy_pdpoly::cMsg_t9fSF8mj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zNtkkBmG_sendMessage);
}

void Heavy_pdpoly::cBinop_GXZ13MvD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6VsIfWbU_sendMessage);
}

void Heavy_pdpoly::cBinop_6VsIfWbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ImNEl0oy_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_2t16tEf7, m);
}

void Heavy_pdpoly::cBinop_ImNEl0oy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_V5bzevPA, m);
}

void Heavy_pdpoly::cMsg_aKClssqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_UGZFJMTo, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_hseDALxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2Ta9dF4e_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_2Ta9dF4e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_UGZFJMTo, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_OlGeY48H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_CzZFHSRT, 0, m);
}

void Heavy_pdpoly::cSlice_CCiWHZfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_QckQWR43_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_C7n0rTMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_aYQkXwnE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_BYZhXZZv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_BC2hWuCu, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_H5L8tZSn_sendMessage);
}

void Heavy_pdpoly::cBinop_aYQkXwnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_uFHwStoW_sendMessage);
}

void Heavy_pdpoly::cBinop_uFHwStoW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WzxMwFBj, HV_BINOP_POW, 1, m, &cBinop_WzxMwFBj_sendMessage);
  cMsg_kSLITPan_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_WzxMwFBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_BYZhXZZv_sendMessage);
}

void Heavy_pdpoly::cMsg_kSLITPan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WzxMwFBj, HV_BINOP_POW, 0, m, &cBinop_WzxMwFBj_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_QckQWR43_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i8qivwtz_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_LbZvM2am_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_i8qivwtz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2nQy3U3R_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_ZIhtxqx7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MHiB7PA5, HV_BINOP_MULTIPLY, 0, m, &cBinop_MHiB7PA5_sendMessage);
}

void Heavy_pdpoly::cMsg_sUuH0xLc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_plPTwjf7_sendMessage);
}

void Heavy_pdpoly::cSystem_plPTwjf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9Bbfwv6F_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_MHiB7PA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LKltJQxm_sendMessage);
}

void Heavy_pdpoly::cBinop_DkdnYzXC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MHiB7PA5, HV_BINOP_MULTIPLY, 1, m, &cBinop_MHiB7PA5_sendMessage);
}

void Heavy_pdpoly::cMsg_9Bbfwv6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_DkdnYzXC_sendMessage);
}

void Heavy_pdpoly::cBinop_LKltJQxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Q4jwKrtI_sendMessage);
}

void Heavy_pdpoly::cBinop_Q4jwKrtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_cBjQ0RZZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hlsZsb45, m);
}

void Heavy_pdpoly::cBinop_cBjQ0RZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_48ir5FZz, m);
}

void Heavy_pdpoly::cVar_nENauZGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PO8xkMd5, HV_BINOP_MULTIPLY, 0, m, &cBinop_PO8xkMd5_sendMessage);
}

void Heavy_pdpoly::cMsg_qKdmEe4p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uFWfdHCp_sendMessage);
}

void Heavy_pdpoly::cSystem_uFWfdHCp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FDDXg0U3_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_PO8xkMd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_alVQRiqv_sendMessage);
}

void Heavy_pdpoly::cBinop_X7qOSk5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PO8xkMd5, HV_BINOP_MULTIPLY, 1, m, &cBinop_PO8xkMd5_sendMessage);
}

void Heavy_pdpoly::cMsg_FDDXg0U3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_X7qOSk5X_sendMessage);
}

void Heavy_pdpoly::cBinop_alVQRiqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kv5sv4rT_sendMessage);
}

void Heavy_pdpoly::cBinop_kv5sv4rT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_y7I9fMAD_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_sinC2iP0, m);
}

void Heavy_pdpoly::cBinop_y7I9fMAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UVZsfxRT, m);
}

void Heavy_pdpoly::cMsg_2nQy3U3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fyCXNMuh, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_LbZvM2am_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2I8ZdS8Y_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_2I8ZdS8Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fyCXNMuh, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_H5L8tZSn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Mxj5vG44, 0, m);
}

void Heavy_pdpoly::cSlice_jwWKPi40_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_zfVkhgcK_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_81v5NwxA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_C6GAoHSt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_wFPI2TOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_pZ40fDSo, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_gbix61Yf_sendMessage);
}

void Heavy_pdpoly::cBinop_C6GAoHSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_AUcs2yhI_sendMessage);
}

void Heavy_pdpoly::cBinop_AUcs2yhI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lt4oGRad, HV_BINOP_POW, 1, m, &cBinop_Lt4oGRad_sendMessage);
  cMsg_htDaibtD_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_Lt4oGRad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_wFPI2TOd_sendMessage);
}

void Heavy_pdpoly::cMsg_htDaibtD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lt4oGRad, HV_BINOP_POW, 0, m, &cBinop_Lt4oGRad_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_zfVkhgcK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8I1f8tfM_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_Fu3Xgj3u_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_8I1f8tfM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9PbRssqX_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_cn1Y5NUb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gFGXQsuZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_gFGXQsuZ_sendMessage);
}

void Heavy_pdpoly::cMsg_3qZYuim6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DIfmUDdM_sendMessage);
}

void Heavy_pdpoly::cSystem_DIfmUDdM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5leMl4m5_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_gFGXQsuZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_V9P3rYWr_sendMessage);
}

void Heavy_pdpoly::cBinop_Rv2xhdoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gFGXQsuZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_gFGXQsuZ_sendMessage);
}

void Heavy_pdpoly::cMsg_5leMl4m5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Rv2xhdoQ_sendMessage);
}

void Heavy_pdpoly::cBinop_V9P3rYWr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_q9czFXam_sendMessage);
}

void Heavy_pdpoly::cBinop_q9czFXam_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_I7zQ2lal_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0AJml8sU, m);
}

void Heavy_pdpoly::cBinop_I7zQ2lal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cIH0PKGa, m);
}

void Heavy_pdpoly::cVar_ee2Fqx0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QAbd5MXQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_QAbd5MXQ_sendMessage);
}

void Heavy_pdpoly::cMsg_P3hmaV3K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_36VZBZNw_sendMessage);
}

void Heavy_pdpoly::cSystem_36VZBZNw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_g43CpFf7_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_QAbd5MXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_rSS7tHpI_sendMessage);
}

void Heavy_pdpoly::cBinop_e1dtGRzs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QAbd5MXQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_QAbd5MXQ_sendMessage);
}

void Heavy_pdpoly::cMsg_g43CpFf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_e1dtGRzs_sendMessage);
}

void Heavy_pdpoly::cBinop_rSS7tHpI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_BWDHAQZB_sendMessage);
}

void Heavy_pdpoly::cBinop_BWDHAQZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_oaOJD8yH_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NBov8azo, m);
}

void Heavy_pdpoly::cBinop_oaOJD8yH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bVZfwv1L, m);
}

void Heavy_pdpoly::cMsg_9PbRssqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_De1hOvE7, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_Fu3Xgj3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BKtDOLYX_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_BKtDOLYX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_De1hOvE7, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_gbix61Yf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_1HlcemhH, 0, m);
}

void Heavy_pdpoly::cSend_o7WqGFN8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2LzdBdmC_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cReceive_PwP3BAN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sxwe3tKM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2gtXAChe, 0, m, &cVar_2gtXAChe_sendMessage);
  cMsg_0aGwUIGr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bBamG7lg, 0, m, &cVar_bBamG7lg_sendMessage);
  cMsg_dX3tGjXg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jQn6vsH7, 0, m, &cVar_jQn6vsH7_sendMessage);
  cMsg_k1Ctvq5m_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hdZZODFX, 0, m, &cVar_hdZZODFX_sendMessage);
  cMsg_sUuH0xLc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZIhtxqx7, 0, m, &cVar_ZIhtxqx7_sendMessage);
  cMsg_qKdmEe4p_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nENauZGp, 0, m, &cVar_nENauZGp_sendMessage);
  cMsg_3qZYuim6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cn1Y5NUb, 0, m, &cVar_cn1Y5NUb_sendMessage);
  cMsg_P3hmaV3K_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ee2Fqx0X, 0, m, &cVar_ee2Fqx0X_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Yl3HpL21, 0, m, &cVar_Yl3HpL21_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aEu6DlQ1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KAt3YIia_sendMessage);
}

void Heavy_pdpoly::cReceive_5JlAQXQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_LgPMLc38, 0, m, &cSlice_LgPMLc38_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_6d4hon6H, 0, m, &cSlice_6d4hon6H_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_wWUqaFzD, 0, m, &cSlice_wWUqaFzD_sendMessage);
}

void Heavy_pdpoly::cReceive_QJNkIbFy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yqhwH2zn, 1, m, &cIf_yqhwH2zn_sendMessage);
}

void Heavy_pdpoly::cReceive_lSPycKip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rlRg7Ewf, 1, m, &cVar_rlRg7Ewf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WpOGftwj, 1, m, &cVar_WpOGftwj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9Zcwzybn, 1, m, &cVar_9Zcwzybn_sendMessage);
}

void Heavy_pdpoly::cReceive_5wIX5vHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HTRxATFx, 0, m, &cVar_HTRxATFx_sendMessage);
}

void Heavy_pdpoly::cReceive_Nx3o17bm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AVb0enbj, 1, m, &cVar_AVb0enbj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ORjgs46o, 1, m, &cVar_ORjgs46o_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_G7itATmX, HV_BINOP_MOD_UNIPOLAR, 1, m, &cBinop_G7itATmX_sendMessage);
}

void Heavy_pdpoly::cReceive_xx3nUNJm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_JeC2ILwJ, 1, m, &cTabwrite_JeC2ILwJ_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_jnk5hZ9p, 1, m, &cTabwrite_jnk5hZ9p_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_LszWQ7QZ, 1, m, &cTabwrite_LszWQ7QZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nyYdYuej, 1, m, &cVar_nyYdYuej_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_y1WxshAL, 1, m, &cVar_y1WxshAL_sendMessage);
}

void Heavy_pdpoly::cReceive_AnAGAMlI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t9hxiyyF, 1, m, &cVar_t9hxiyyF_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Gll4eGKI, 1, m, &cTabwrite_Gll4eGKI_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_0KNrmZYO, 1, m, &cTabwrite_0KNrmZYO_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_U68ZtQCI, 1, m, &cTabwrite_U68ZtQCI_sendMessage);
}

void Heavy_pdpoly::cReceive_2blUjMar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_froDbiX0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d7JCwiFw_sendMessage);
}

void Heavy_pdpoly::cReceive_gDOtbvR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WIIgdLk9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9dZxTYfW_sendMessage);
}

void Heavy_pdpoly::cReceive_2LzdBdmC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2gtXAChe, 0, m, &cVar_2gtXAChe_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bBamG7lg, 0, m, &cVar_bBamG7lg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jQn6vsH7, 0, m, &cVar_jQn6vsH7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hdZZODFX, 0, m, &cVar_hdZZODFX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZIhtxqx7, 0, m, &cVar_ZIhtxqx7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nENauZGp, 0, m, &cVar_nENauZGp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cn1Y5NUb, 0, m, &cVar_cn1Y5NUb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ee2Fqx0X, 0, m, &cVar_ee2Fqx0X_sendMessage);
}

void Heavy_pdpoly::cReceive_FiPksvmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_o7WqGFN8_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cReceive_OD3sQy6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nSqsBGld, m);
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
    __hv_phasor_k_f(&sPhasor_jV2cDyYP, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_4dRRUrVF, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_DEXGwPIf, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_dGld7Ry0, VOf(Bf2));
    __hv_rpole_f(&sRPole_jbDdg7Nj, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_TWLAsIA5, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_zQ9Wsdbw, VOf(Bf2));
    __hv_rpole_f(&sRPole_K1ABEsvr, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_3cPgyhkE, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_NnH0Ftp6, VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_CzZFHSRT, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_mtsk8ibJ, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_YvcGEwE2, VOf(Bf3));
    __hv_rpole_f(&sRPole_Deu3Mykb, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_2t16tEf7, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_V5bzevPA, VOf(Bf3));
    __hv_rpole_f(&sRPole_89Ssd6SU, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_UGZFJMTo, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_BC2hWuCu, VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_Mxj5vG44, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_hlsZsb45, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_48ir5FZz, VOf(Bf2));
    __hv_rpole_f(&sRPole_6C5joWU7, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_sinC2iP0, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_UVZsfxRT, VOf(Bf2));
    __hv_rpole_f(&sRPole_pl27kFyB, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_fyCXNMuh, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_pZ40fDSo, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_1HlcemhH, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_0AJml8sU, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_cIH0PKGa, VOf(Bf1));
    __hv_rpole_f(&sRPole_7cg01uF5, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_NBov8azo, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_bVZfwv1L, VOf(Bf1));
    __hv_rpole_f(&sRPole_Ce0uuO8u, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_De1hOvE7, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_nSqsBGld, VOf(Bf3));
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
