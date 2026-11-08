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
  numBytes += sPhasor_k_init(&sPhasor_Wj5P76fV, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_idEzkmrR, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_JXSm576v);
  numBytes += sRPole_init(&sRPole_K8bnNaMb);
  numBytes += sLine_init(&sLine_M43wnOih);
  numBytes += sPhasor_k_init(&sPhasor_usjXZydD, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_IojInUMO, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_73sEIcOT);
  numBytes += sRPole_init(&sRPole_DVgg4fgb);
  numBytes += sLine_init(&sLine_L4QqhSIJ);
  numBytes += sPhasor_k_init(&sPhasor_3cnyDu3m, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_EI99XU1H, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_LKoJZv9R);
  numBytes += sRPole_init(&sRPole_svoFpBI9);
  numBytes += sLine_init(&sLine_poPOrEvR);
  numBytes += sPhasor_k_init(&sPhasor_aLE3vOG5, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_UnQcBchX, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_JPbUJ7Kq);
  numBytes += sRPole_init(&sRPole_zOu1kWC7);
  numBytes += sLine_init(&sLine_tTvv4cKl);
  numBytes += cSlice_init(&cSlice_7CZdLi3z, 2, 1);
  numBytes += cSlice_init(&cSlice_vhajNYeU, 1, 1);
  numBytes += cSlice_init(&cSlice_mkVSG4vR, 0, 1);
  numBytes += cVar_init_f(&cVar_TpLZWuWN, 0.0f);
  numBytes += cIf_init(&cIf_UGh9XWWU, false);
  numBytes += cIf_init(&cIf_zz43J9rJ, false);
  numBytes += cIf_init(&cIf_c5o1JfEL, false);
  numBytes += cIf_init(&cIf_EN0f6Qf8, false);
  numBytes += cIf_init(&cIf_RGmTNsCR, false);
  numBytes += cBinop_init(&cBinop_SovsIGsB, 0.0f); // __eq
  numBytes += cVar_init_f(&cVar_5gLbZ4VH, 1.0f);
  numBytes += cVar_init_f(&cVar_6AVLWKJ1, 0.0f);
  numBytes += cSlice_init(&cSlice_ShFMMLjb, 1, -1);
  numBytes += cSlice_init(&cSlice_a9YemX0s, 1, -1);
  numBytes += cSlice_init(&cSlice_C1l0hBfZ, 1, 1);
  numBytes += cSlice_init(&cSlice_wnJLo0iJ, 0, 1);
  numBytes += cVar_init_f(&cVar_6xYX6ilM, 0.0f);
  numBytes += cIf_init(&cIf_5VXvlq4z, false);
  numBytes += cIf_init(&cIf_8CHcna9u, false);
  numBytes += cIf_init(&cIf_XFQ3p6k5, false);
  numBytes += cVar_init_f(&cVar_REQPYjDX, 0.0f);
  numBytes += cIf_init(&cIf_UgVpTBis, false);
  numBytes += cVar_init_f(&cVar_fmahcE2n, 0.0f);
  numBytes += cIf_init(&cIf_78HICY3B, false);
  numBytes += cBinop_init(&cBinop_4JS9vY9r, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_0iEOGidy, 4.0f);
  numBytes += cTabread_init(&cTabread_aWKbAflz, &hTable_pXe9AovR); // 1011-used
  numBytes += cSlice_init(&cSlice_aCTpqzVZ, 1, -1);
  numBytes += cVar_init_s(&cVar_z8vDOVRj, "1011-used");
  numBytes += cBinop_init(&cBinop_dGQXGc93, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_nAyFhkbE, &hTable_ZsQlsR6V); // 1011-ids
  numBytes += cSlice_init(&cSlice_Ux3Gz4EB, 1, -1);
  numBytes += cVar_init_s(&cVar_gvpeh80y, "1011-ids");
  numBytes += cBinop_init(&cBinop_o0RsKSnA, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_PZu3QWOj, 0.0f);
  numBytes += cSlice_init(&cSlice_d5FhXFgI, 1, 1);
  numBytes += cSlice_init(&cSlice_nxmTjKdk, 0, 1);
  numBytes += cTabread_init(&cTabread_WZ8ylD5f, &hTable_MSBU8ehe); // 1011-pitches
  numBytes += cSlice_init(&cSlice_02OZn7s6, 1, -1);
  numBytes += cVar_init_s(&cVar_wAT1bhT2, "1011-pitches");
  numBytes += cBinop_init(&cBinop_hcgSmoMm, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_dAbOmiuS, 0.0f);
  numBytes += cVar_init_f(&cVar_zWkDB8YY, 0.0f);
  numBytes += cIf_init(&cIf_0cx8DZks, false);
  numBytes += cTabwrite_init(&cTabwrite_oSnDADn3, &hTable_pXe9AovR); // 1011-used
  numBytes += cSlice_init(&cSlice_1XPTk6pe, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_YF3w2MLm, &hTable_ZsQlsR6V); // 1011-ids
  numBytes += cSlice_init(&cSlice_iP6NXmNZ, 1, -1);
  numBytes += cVar_init_f(&cVar_qzyFhB9P, 0.0f);
  numBytes += cVar_init_f(&cVar_GAorKnX4, 0.0f);
  numBytes += cSlice_init(&cSlice_4Hhz7YRz, 1, 1);
  numBytes += cSlice_init(&cSlice_8WVIs7pm, 0, 1);
  numBytes += cPack_init(&cPack_9L9LzQDu, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_SmxSoF3g, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_ydzZArc4, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_A8veDUUJ, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_ioHGlAA7, 0.0f); // __lt
  numBytes += cIf_init(&cIf_6M40RSYv, false);
  numBytes += cVar_init_f(&cVar_skvXCdrP, 0.0f);
  numBytes += cIf_init(&cIf_fXzc9pby, false);
  numBytes += cVar_init_f(&cVar_yPBBcgPN, 0.0f);
  numBytes += cIf_init(&cIf_1lr0p5dk, false);
  numBytes += cBinop_init(&cBinop_u3lY0iH9, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_syyhG99p, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_F5LcY5Ee, &hTable_pXe9AovR); // 1011-used
  numBytes += cSlice_init(&cSlice_D39sYbna, 1, -1);
  numBytes += cTabread_init(&cTabread_A5WdklwJ, &hTable_pXe9AovR); // 1011-used
  numBytes += cSlice_init(&cSlice_fwL7wPDl, 1, -1);
  numBytes += cVar_init_s(&cVar_ENdjzPvY, "1011-used");
  numBytes += cBinop_init(&cBinop_JwNqc0yP, 0.0f); // __min
  numBytes += cIf_init(&cIf_L1T0xF9C, false);
  numBytes += cTabread_init(&cTabread_GtkzcUTu, &hTable_MSBU8ehe); // 1011-pitches
  numBytes += cSlice_init(&cSlice_YcqDOBz4, 1, -1);
  numBytes += cVar_init_s(&cVar_Pcj0UNwe, "1011-pitches");
  numBytes += cBinop_init(&cBinop_B4jBuJ7M, 0.0f); // __min
  numBytes += cIf_init(&cIf_gpA50uBR, false);
  numBytes += cVar_init_f(&cVar_df4N9NAX, 0.0f);
  numBytes += cIf_init(&cIf_Lg7nFwX2, false);
  numBytes += cVar_init_f(&cVar_RqNcdN73, 0.0f);
  numBytes += cIf_init(&cIf_EAuCcygz, false);
  numBytes += cBinop_init(&cBinop_QUs3u7ln, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_3i0IGMqX, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_1FxpFWFg, &hTable_pXe9AovR); // 1011-used
  numBytes += cSlice_init(&cSlice_UA6096g6, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_zf30tjzO, &hTable_ZsQlsR6V); // 1011-ids
  numBytes += cSlice_init(&cSlice_WaP5YVvL, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_y90545Sw, &hTable_MSBU8ehe); // 1011-pitches
  numBytes += cSlice_init(&cSlice_9IdfsYmk, 1, -1);
  numBytes += cIf_init(&cIf_LAk4pq92, false);
  numBytes += cVar_init_f(&cVar_NmzLTPfv, 0.0f);
  numBytes += cIf_init(&cIf_9mP1nkpW, false);
  numBytes += cVar_init_f(&cVar_3HC4d5sL, 0.0f);
  numBytes += cIf_init(&cIf_pSYp5bQK, false);
  numBytes += cBinop_init(&cBinop_anUELzZ7, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_2xSkMdNh, 4.0f);
  numBytes += cVar_init_f(&cVar_xdwcDSCX, 0.0f);
  numBytes += cIf_init(&cIf_f7RX8Ar1, false);
  numBytes += cVar_init_f(&cVar_HNQEv8dg, 0.0f);
  numBytes += cVar_init_f(&cVar_A2Pzvhzw, 0.0f);
  numBytes += cVar_init_f(&cVar_kLP251yp, 0.0f);
  numBytes += cIf_init(&cIf_NjEHh6AU, false);
  numBytes += cIf_init(&cIf_zur2p3Qt, false);
  numBytes += cPack_init(&cPack_1BRpMtdT, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_Ywi44Uvy, 0.0f);
  numBytes += cSlice_init(&cSlice_z2AqZiIu, 1, 1);
  numBytes += cSlice_init(&cSlice_7STl7G78, 0, 1);
  numBytes += cVar_init_f(&cVar_4nDMSKqo, 0.0f);
  numBytes += cIf_init(&cIf_dwATKqVK, false);
  numBytes += cVar_init_f(&cVar_oyDdxJnP, 0.0f);
  numBytes += cVar_init_f(&cVar_XyGzNCne, 0.0f);
  numBytes += cTabread_init(&cTabread_ZpaEUjvY, &hTable_pXe9AovR); // 1011-used
  numBytes += cSlice_init(&cSlice_5FqhzqOL, 1, -1);
  numBytes += cVar_init_s(&cVar_8KInnEqD, "1011-used");
  numBytes += cBinop_init(&cBinop_HWIDTVPh, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_ZG915VZe, &hTable_ZsQlsR6V); // 1011-ids
  numBytes += cSlice_init(&cSlice_EolPpEiq, 1, -1);
  numBytes += cVar_init_s(&cVar_baIEnrWJ, "1011-ids");
  numBytes += cBinop_init(&cBinop_EutqCYiW, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_oCWveMX9, &hTable_MSBU8ehe); // 1011-pitches
  numBytes += cSlice_init(&cSlice_22YlYBVm, 1, -1);
  numBytes += cTabread_init(&cTabread_LjOzAkZH, &hTable_MSBU8ehe); // 1011-pitches
  numBytes += cSlice_init(&cSlice_BsfGsx0E, 1, -1);
  numBytes += cVar_init_s(&cVar_FretsQzi, "1011-pitches");
  numBytes += cBinop_init(&cBinop_Um3h6DGJ, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_dIng54Xh, &hTable_MSBU8ehe); // 1011-pitches
  numBytes += cSlice_init(&cSlice_iaRUvFCf, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_5b0Ouubl, &hTable_pXe9AovR); // 1011-used
  numBytes += cSlice_init(&cSlice_5dznhrlp, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_wJqtQA1z, &hTable_ZsQlsR6V); // 1011-ids
  numBytes += cSlice_init(&cSlice_OGO44fnX, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_Zdl7o9yg, &hTable_ZsQlsR6V); // 1011-ids
  numBytes += cSlice_init(&cSlice_G4mzyaAZ, 1, -1);
  numBytes += cVar_init_f(&cVar_ErYhtuLf, 0.0f);
  numBytes += cTabwrite_init(&cTabwrite_pOBmMP0H, &hTable_pXe9AovR); // 1011-used
  numBytes += cSlice_init(&cSlice_DWrSN5GU, 1, -1);
  numBytes += cVar_init_f(&cVar_uK95EYv0, 0.0f);
  numBytes += cSlice_init(&cSlice_XXvuIvoO, 1, 1);
  numBytes += cSlice_init(&cSlice_Wzn1OLwX, 0, 1);
  numBytes += cVar_init_f(&cVar_jlq9e63J, 0.0f);
  numBytes += cBinop_init(&cBinop_mlETWTWB, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_QINOdvVC, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_p3ZvN2ES, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_RrW4eBWz, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_ByH516od, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_NC5AXQVg, 65535.0f); // __unimod
  numBytes += hTable_init(&hTable_MSBU8ehe, 4);
  numBytes += hTable_init(&hTable_pXe9AovR, 4);
  numBytes += hTable_init(&hTable_ZsQlsR6V, 4);
  numBytes += cPack_init(&cPack_8Uwl8Ktc, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_HAATdkMc, 1, -1);
  numBytes += cSlice_init(&cSlice_3v0tgLTX, 1, -1);
  numBytes += cSlice_init(&cSlice_GivCe5mp, 1, -1);
  numBytes += cSlice_init(&cSlice_Rd2I2I2m, 1, -1);
  numBytes += cSlice_init(&cSlice_nwanqaz6, 1, 1);
  numBytes += cSlice_init(&cSlice_GrwqtHc2, 0, 1);
  numBytes += cBinop_init(&cBinop_qJiiqiGD, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_VLPOQAyK, 22050.0f);
  numBytes += cBinop_init(&cBinop_pH8fO0Td, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Ceyaq3yV, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GaqkmNVZ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_3frtSIMd, 22050.0f);
  numBytes += cBinop_init(&cBinop_NDLMIjPR, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_NixyCauy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_szBkpq6X, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_8s7k4D47, 1, 1);
  numBytes += cSlice_init(&cSlice_monGASK1, 0, 1);
  numBytes += cBinop_init(&cBinop_98kPRk8f, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_hDQbXjFC, 22050.0f);
  numBytes += cBinop_init(&cBinop_5tVZOd74, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Wt5sAjWq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_QrTWWsH0, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_RvzrkK6U, 22050.0f);
  numBytes += cBinop_init(&cBinop_i1qsaVlT, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_p6LhJKv7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_IQKhtABl, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_85EvhwOT, 1, 1);
  numBytes += cSlice_init(&cSlice_vGFfZ3Xz, 0, 1);
  numBytes += cBinop_init(&cBinop_sRbg4dj7, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_v8XJVTvM, 22050.0f);
  numBytes += cBinop_init(&cBinop_LTo52LUD, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_kClAg4Eg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fAdMYihL, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Z2H8q1KL, 22050.0f);
  numBytes += cBinop_init(&cBinop_zVUhDAxS, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_4BULTExG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_K9JgPTgm, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_m5SNtuQf, 1, 1);
  numBytes += cSlice_init(&cSlice_lgQ89ov6, 0, 1);
  numBytes += cBinop_init(&cBinop_6xPlDnkQ, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_c07ZFn5S, 22050.0f);
  numBytes += cBinop_init(&cBinop_ZCWwsmuj, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_b9erWLPG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BdSY9Yqw, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_wwNxtIn5, 22050.0f);
  numBytes += cBinop_init(&cBinop_dsgFUUV1, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_4tHtdCCc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_7D6MKv1C, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_U0dh1fik, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_pdpoly::~Heavy_pdpoly() {
  cPack_free(&cPack_9L9LzQDu);
  cPack_free(&cPack_1BRpMtdT);
  hTable_free(&hTable_MSBU8ehe);
  hTable_free(&hTable_pXe9AovR);
  hTable_free(&hTable_ZsQlsR6V);
  cPack_free(&cPack_8Uwl8Ktc);
}

HvTable *Heavy_pdpoly::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x7B847FB6: return &hTable_MSBU8ehe; // 1011-pitches
    case 0xA0EFCB1D: return &hTable_pXe9AovR; // 1011-used
    case 0x73137BF4: return &hTable_ZsQlsR6V; // 1011-ids
    default: return nullptr;
  }
}

void Heavy_pdpoly::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x7EA4AD17: { // 1011-currentVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ne3Wl82t_sendMessage);
      break;
    }
    case 0x9B1DF8F3: { // 1011-indexOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_JtpSDdTV_sendMessage);
      break;
    }
    case 0xF7855D22: { // 1011-indexOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gb0NX0pr_sendMessage);
      break;
    }
    case 0xEB1BA925: { // 1011-isFirstOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xP9N1Pfy_sendMessage);
      break;
    }
    case 0x7426D59: { // 1011-isFirstOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_XB8fCMhH_sendMessage);
      break;
    }
    case 0x199E738B: { // 1011-maxVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7SSvGYdC_sendMessage);
      break;
    }
    case 0x979E98C4: { // 1011-shouldSteal
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eeejjrCu_sendMessage);
      break;
    }
    case 0xDB67A714: { // 1011-voiceId++
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VweZyHLp_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EI4SZt1E_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wqW9bP97_sendMessage);
      break;
    }
    case 0xF89F9F3E: { // cutoff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PpWEy1He_sendMessage);
      break;
    }
    case 0xC2C62B6: { // vcut
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3NZPRswS_sendMessage);
      break;
    }
    case 0xB1642755: { // volume
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YVGLwQ7o_sendMessage);
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


void Heavy_pdpoly::cSlice_7CZdLi3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Rjic8hpq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_vhajNYeU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_EN0f6Qf8, 0, m, &cIf_EN0f6Qf8_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_zz43J9rJ, 0, m, &cIf_zz43J9rJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_mkVSG4vR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_RGmTNsCR, 0, m, &cIf_RGmTNsCR_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_c5o1JfEL, 0, m, &cIf_c5o1JfEL_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_TpLZWuWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_BuqTdPGh_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_UGh9XWWU, 0, m, &cIf_UGh9XWWU_sendMessage);
}

void Heavy_pdpoly::cUnop_wG1rVEeU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_ob5D72Le_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SovsIGsB, HV_BINOP_EQ, 1, m, &cBinop_SovsIGsB_sendMessage);
}

void Heavy_pdpoly::cUnop_r9rlvsnn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_ob5D72Le_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SovsIGsB, HV_BINOP_EQ, 1, m, &cBinop_SovsIGsB_sendMessage);
}

void Heavy_pdpoly::cIf_UGh9XWWU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_r9rlvsnn_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_wG1rVEeU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_BuqTdPGh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UGh9XWWU, 1, m, &cIf_UGh9XWWU_sendMessage);
}

void Heavy_pdpoly::cIf_zz43J9rJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_6xYX6ilM, 0, m, &cVar_6xYX6ilM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_c5o1JfEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_5M4aVU7j_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_EN0f6Qf8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_6xYX6ilM, 0, m, &cVar_6xYX6ilM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_RGmTNsCR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_5M4aVU7j_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_Rjic8hpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SovsIGsB, HV_BINOP_EQ, 0, m, &cBinop_SovsIGsB_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_IBRXYnnf_sendMessage);
}

void Heavy_pdpoly::cBinop_ob5D72Le_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_isyCKUnd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7UvgMSwv_sendMessage);
}

void Heavy_pdpoly::cBinop_SovsIGsB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hKuNpzlG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_W8EAKz6t_sendMessage);
}

void Heavy_pdpoly::cCast_hKuNpzlG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zz43J9rJ, 1, m, &cIf_zz43J9rJ_sendMessage);
}

void Heavy_pdpoly::cCast_W8EAKz6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RGmTNsCR, 1, m, &cIf_RGmTNsCR_sendMessage);
}

void Heavy_pdpoly::cCast_isyCKUnd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EN0f6Qf8, 1, m, &cIf_EN0f6Qf8_sendMessage);
}

void Heavy_pdpoly::cCast_7UvgMSwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_c5o1JfEL, 1, m, &cIf_c5o1JfEL_sendMessage);
}

void Heavy_pdpoly::cBinop_IBRXYnnf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cVar_5gLbZ4VH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_xC0RpBE7_sendMessage);
}

void Heavy_pdpoly::cVar_6AVLWKJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NC5AXQVg, HV_BINOP_MOD_UNIPOLAR, 0, m, &cBinop_NC5AXQVg_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_5M4aVU7j_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ShFMMLjb, 0, m, &cSlice_ShFMMLjb_sendMessage);
      break;
    }
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_a9YemX0s, 0, m, &cSlice_a9YemX0s_sendMessage);
      break;
    }
    default: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_C1l0hBfZ, 0, m, &cSlice_C1l0hBfZ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_wnJLo0iJ, 0, m, &cSlice_wnJLo0iJ_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_ShFMMLjb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xxHS0BQx_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VM4FFiFZ_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xxHS0BQx_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VM4FFiFZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_a9YemX0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fKniZqJL_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W49UzqyW_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fKniZqJL_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W49UzqyW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_C1l0hBfZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_6xYX6ilM, 0, m, &cVar_6xYX6ilM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_wnJLo0iJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_5VXvlq4z, 0, m, &cIf_5VXvlq4z_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_8CHcna9u, 0, m, &cIf_8CHcna9u_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_6xYX6ilM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1BRpMtdT, 1, m, &cPack_1BRpMtdT_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_9L9LzQDu, 1, m, &cPack_9L9LzQDu_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ulnf4P8k_sendMessage);
}

void Heavy_pdpoly::cIf_5VXvlq4z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_E2lz6zqG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jinB7z1J_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_18I4sLVl_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_1BRpMtdT, 0, m, &cPack_1BRpMtdT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_8CHcna9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_9L9LzQDu, 0, m, &cPack_9L9LzQDu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_XFQ3p6k5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xIVN9kHU_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_q7ue0dtG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_REQPYjDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1Uj9xkkv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_h8FWGeuU_sendMessage);
}

void Heavy_pdpoly::cIf_UgVpTBis_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_y5Sjn7eR_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wDjKDzBS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_Gb7q3atO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UgVpTBis, 1, m, &cIf_UgVpTBis_sendMessage);
}

void Heavy_pdpoly::cVar_fmahcE2n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_BhMKf1oP_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_78HICY3B, 0, m, &cIf_78HICY3B_sendMessage);
}

void Heavy_pdpoly::cUnop_GqVvB5I7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_Gb7q3atO_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_UgVpTBis, 0, m, &cIf_UgVpTBis_sendMessage);
}

void Heavy_pdpoly::cUnop_PqDOwqGg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_Gb7q3atO_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_UgVpTBis, 0, m, &cIf_UgVpTBis_sendMessage);
}

void Heavy_pdpoly::cIf_78HICY3B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_PqDOwqGg_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_GqVvB5I7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_BhMKf1oP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_78HICY3B, 1, m, &cIf_78HICY3B_sendMessage);
}

void Heavy_pdpoly::cCast_h8FWGeuU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XFQ3p6k5, 0, m, &cIf_XFQ3p6k5_sendMessage);
}

void Heavy_pdpoly::cCast_1Uj9xkkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4JS9vY9r, HV_BINOP_LESS_THAN, 0, m, &cBinop_4JS9vY9r_sendMessage);
}

void Heavy_pdpoly::cBinop_4JS9vY9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XFQ3p6k5, 1, m, &cIf_XFQ3p6k5_sendMessage);
}

void Heavy_pdpoly::cCast_wDjKDzBS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6FnAbCQ6_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_y5Sjn7eR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4JS9vY9r, HV_BINOP_LESS_THAN, 1, m, &cBinop_4JS9vY9r_sendMessage);
}

void Heavy_pdpoly::cBinop_QusPZqZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_REQPYjDX, 0, m, &cVar_REQPYjDX_sendMessage);
}

void Heavy_pdpoly::cMsg_6FnAbCQ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_REQPYjDX, 0, m, &cVar_REQPYjDX_sendMessage);
}

void Heavy_pdpoly::cCast_xIVN9kHU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9WuE8Y6F_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Amms9uN4_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3ayuCD4g_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CubPoJIR_sendMessage);
}

void Heavy_pdpoly::cCast_q7ue0dtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_QusPZqZK_sendMessage);
}

void Heavy_pdpoly::cVar_0iEOGidy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fmahcE2n, 0, m, &cVar_fmahcE2n_sendMessage);
}

void Heavy_pdpoly::cTabread_aWKbAflz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A8veDUUJ, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_A8veDUUJ_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_ZY5t5We2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_aCTpqzVZ, 0, m, &cSlice_aCTpqzVZ_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jpo4aZ9j_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iLn3kF3X_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_aCTpqzVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_aWKbAflz, 1, m, &cTabread_aWKbAflz_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_aWKbAflz, 1, m, &cTabread_aWKbAflz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_z8vDOVRj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p2eMhGr1_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_l4C2K9Lg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_p0DOQTp9_sendMessage);
}

void Heavy_pdpoly::cBinop_CIc97IoW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dGQXGc93, HV_BINOP_MIN, 0, m, &cBinop_dGQXGc93_sendMessage);
}

void Heavy_pdpoly::cCast_iLn3kF3X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CIc97IoW_sendMessage);
}

void Heavy_pdpoly::cCast_jpo4aZ9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_z8vDOVRj, 0, m, &cVar_z8vDOVRj_sendMessage);
}

void Heavy_pdpoly::cBinop_dGQXGc93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_aWKbAflz, 0, m, &cTabread_aWKbAflz_sendMessage);
}

void Heavy_pdpoly::cMsg_p2eMhGr1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_l4C2K9Lg_sendMessage);
}

void Heavy_pdpoly::cBinop_p0DOQTp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dGQXGc93, HV_BINOP_MIN, 1, m, &cBinop_dGQXGc93_sendMessage);
}

void Heavy_pdpoly::cTabread_nAyFhkbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VrQoXeWo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_y85a1Imr_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_d1NAz6Wd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ux3Gz4EB, 0, m, &cSlice_Ux3Gz4EB_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FVyS8N5h_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sYMGuKW4_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_Ux3Gz4EB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_nAyFhkbE, 1, m, &cTabread_nAyFhkbE_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_nAyFhkbE, 1, m, &cTabread_nAyFhkbE_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_gvpeh80y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CnmBdFlF_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_usWkYICy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_KnZzP86d_sendMessage);
}

void Heavy_pdpoly::cBinop_tDZahVn3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o0RsKSnA, HV_BINOP_MIN, 0, m, &cBinop_o0RsKSnA_sendMessage);
}

void Heavy_pdpoly::cCast_sYMGuKW4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_tDZahVn3_sendMessage);
}

void Heavy_pdpoly::cCast_FVyS8N5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gvpeh80y, 0, m, &cVar_gvpeh80y_sendMessage);
}

void Heavy_pdpoly::cBinop_o0RsKSnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_nAyFhkbE, 0, m, &cTabread_nAyFhkbE_sendMessage);
}

void Heavy_pdpoly::cMsg_CnmBdFlF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_usWkYICy_sendMessage);
}

void Heavy_pdpoly::cBinop_KnZzP86d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o0RsKSnA, HV_BINOP_MIN, 1, m, &cBinop_o0RsKSnA_sendMessage);
}

void Heavy_pdpoly::cVar_PZu3QWOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_oSnDADn3, 1, m, &cTabwrite_oSnDADn3_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_YF3w2MLm, 1, m, &cTabwrite_YF3w2MLm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GAorKnX4, 1, m, &cVar_GAorKnX4_sendMessage);
}

void Heavy_pdpoly::cSlice_d5FhXFgI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_pdpoly::cSlice_nxmTjKdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xWNlI3TX_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XHvETDsQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_WZ8ylD5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SmxSoF3g, HV_BINOP_EQ, 0, m, &cBinop_SmxSoF3g_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_BJU8zrUA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_02OZn7s6, 0, m, &cSlice_02OZn7s6_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7uARflPS_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cQTBcKe9_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_02OZn7s6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_WZ8ylD5f, 1, m, &cTabread_WZ8ylD5f_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_WZ8ylD5f, 1, m, &cTabread_WZ8ylD5f_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_wAT1bhT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GusNo2ss_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_R317EzEb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_k5jyZK3p_sendMessage);
}

void Heavy_pdpoly::cBinop_BaFWhSRX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hcgSmoMm, HV_BINOP_MIN, 0, m, &cBinop_hcgSmoMm_sendMessage);
}

void Heavy_pdpoly::cCast_cQTBcKe9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_BaFWhSRX_sendMessage);
}

void Heavy_pdpoly::cCast_7uARflPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wAT1bhT2, 0, m, &cVar_wAT1bhT2_sendMessage);
}

void Heavy_pdpoly::cBinop_hcgSmoMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_WZ8ylD5f, 0, m, &cTabread_WZ8ylD5f_sendMessage);
}

void Heavy_pdpoly::cMsg_GusNo2ss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_R317EzEb_sendMessage);
}

void Heavy_pdpoly::cBinop_k5jyZK3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hcgSmoMm, HV_BINOP_MIN, 1, m, &cBinop_hcgSmoMm_sendMessage);
}

void Heavy_pdpoly::cVar_dAbOmiuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ioHGlAA7, HV_BINOP_LESS_THAN, 1, m, &cBinop_ioHGlAA7_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_hUyeSXbZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pXfIMJQp_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_pXfIMJQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zdWST8FP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EXZUQNg3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QUJaZjIm_sendMessage);
}

void Heavy_pdpoly::cVar_zWkDB8YY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ioHGlAA7, HV_BINOP_LESS_THAN, 1, m, &cBinop_ioHGlAA7_sendMessage);
}

void Heavy_pdpoly::cIf_0cx8DZks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bcrxoKJD_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9oreXRSJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_96AQiXes_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_4Hhz7YRz, 0, m, &cSlice_4Hhz7YRz_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_8WVIs7pm, 0, m, &cSlice_8WVIs7pm_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oQt1ujl8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_oSnDADn3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_Rkf4magj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1XPTk6pe, 0, m, &cSlice_1XPTk6pe_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_oSnDADn3, 0, m, &cTabwrite_oSnDADn3_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_1XPTk6pe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_oSnDADn3, 2, m, &cTabwrite_oSnDADn3_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_oSnDADn3, 2, m, &cTabwrite_oSnDADn3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_YF3w2MLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_GIYeJnrb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iP6NXmNZ, 0, m, &cSlice_iP6NXmNZ_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_YF3w2MLm, 0, m, &cTabwrite_YF3w2MLm_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_iP6NXmNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_YF3w2MLm, 2, m, &cTabwrite_YF3w2MLm_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_YF3w2MLm, 2, m, &cTabwrite_YF3w2MLm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_qzyFhB9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GIYeJnrb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cVar_GAorKnX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_O3BaOaoP_sendMessage);
}

void Heavy_pdpoly::cSlice_4Hhz7YRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_pdpoly::cSlice_8WVIs7pm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_8Uwl8Ktc, 1, m, &cPack_8Uwl8Ktc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cPack_9L9LzQDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MKnIGF2a_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_e6ysXhDB_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_d5FhXFgI, 0, m, &cSlice_d5FhXFgI_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_nxmTjKdk, 0, m, &cSlice_nxmTjKdk_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_0cx8DZks, 0, m, &cIf_0cx8DZks_sendMessage);
}

void Heavy_pdpoly::cCast_3ayuCD4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZY5t5We2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_CubPoJIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BJU8zrUA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_Amms9uN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_d1NAz6Wd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_9WuE8Y6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PZu3QWOj, 1, m, &cVar_PZu3QWOj_sendMessage);
}

void Heavy_pdpoly::cMsg_fhAnldQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_0cx8DZks, 1, m, &cIf_0cx8DZks_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PZu3QWOj, 0, m, &cVar_PZu3QWOj_sendMessage);
}

void Heavy_pdpoly::cMsg_877nkWp2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_0cx8DZks, 1, m, &cIf_0cx8DZks_sendMessage);
}

void Heavy_pdpoly::cCast_MKnIGF2a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dAbOmiuS, 0, m, &cVar_dAbOmiuS_sendMessage);
}

void Heavy_pdpoly::cCast_e6ysXhDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fhAnldQM_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_xWNlI3TX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SmxSoF3g, HV_BINOP_EQ, 1, m, &cBinop_SmxSoF3g_sendMessage);
}

void Heavy_pdpoly::cCast_XHvETDsQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0iEOGidy, 0, m, &cVar_0iEOGidy_sendMessage);
}

void Heavy_pdpoly::cBinop_SmxSoF3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ydzZArc4, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_ydzZArc4_sendMessage);
}

void Heavy_pdpoly::cBinop_ydzZArc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_hUyeSXbZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_A8veDUUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ydzZArc4, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_ydzZArc4_sendMessage);
}

void Heavy_pdpoly::cBinop_ioHGlAA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A8veDUUJ, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_A8veDUUJ_sendMessage);
}

void Heavy_pdpoly::cCast_EXZUQNg3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_877nkWp2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_QUJaZjIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PZu3QWOj, 0, m, &cVar_PZu3QWOj_sendMessage);
}

void Heavy_pdpoly::cCast_zdWST8FP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zWkDB8YY, 0, m, &cVar_zWkDB8YY_sendMessage);
}

void Heavy_pdpoly::cCast_y85a1Imr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ioHGlAA7, HV_BINOP_LESS_THAN, 0, m, &cBinop_ioHGlAA7_sendMessage);
}

void Heavy_pdpoly::cCast_VrQoXeWo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zWkDB8YY, 1, m, &cVar_zWkDB8YY_sendMessage);
}

void Heavy_pdpoly::cCast_NmtVyQWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qzyFhB9P, 0, m, &cVar_qzyFhB9P_sendMessage);
}

void Heavy_pdpoly::cCast_LjPEG4Ce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cXkjk3Ae_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_cXkjk3Ae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VweZyHLp_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_9oreXRSJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LjPEG4Ce_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NmtVyQWZ_sendMessage);
}

void Heavy_pdpoly::cCast_bcrxoKJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aFHKiriv_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_aFHKiriv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Rkf4magj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_96AQiXes_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aodBFsfr_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_oQt1ujl8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GAorKnX4, 0, m, &cVar_GAorKnX4_sendMessage);
}

void Heavy_pdpoly::cMsg_aodBFsfr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_8Uwl8Ktc, 2, m, &cPack_8Uwl8Ktc_sendMessage);
}

void Heavy_pdpoly::cIf_6M40RSYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SkGHMBBa_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hqKVCEzi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_skvXCdrP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pVBSuwwU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3fzCFWZY_sendMessage);
}

void Heavy_pdpoly::cIf_fXzc9pby_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_thMzSLCC_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fJAXMK44_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_ATGPijzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_fXzc9pby, 1, m, &cIf_fXzc9pby_sendMessage);
}

void Heavy_pdpoly::cVar_yPBBcgPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_JAhde729_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_1lr0p5dk, 0, m, &cIf_1lr0p5dk_sendMessage);
}

void Heavy_pdpoly::cUnop_vqmLWjYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_ATGPijzm_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_fXzc9pby, 0, m, &cIf_fXzc9pby_sendMessage);
}

void Heavy_pdpoly::cUnop_VQDiLsuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_ATGPijzm_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_fXzc9pby, 0, m, &cIf_fXzc9pby_sendMessage);
}

void Heavy_pdpoly::cIf_1lr0p5dk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_VQDiLsuL_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vqmLWjYv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_JAhde729_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_1lr0p5dk, 1, m, &cIf_1lr0p5dk_sendMessage);
}

void Heavy_pdpoly::cCast_3fzCFWZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6M40RSYv, 0, m, &cIf_6M40RSYv_sendMessage);
}

void Heavy_pdpoly::cCast_pVBSuwwU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u3lY0iH9, HV_BINOP_LESS_THAN, 0, m, &cBinop_u3lY0iH9_sendMessage);
}

void Heavy_pdpoly::cBinop_u3lY0iH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6M40RSYv, 1, m, &cIf_6M40RSYv_sendMessage);
}

void Heavy_pdpoly::cCast_thMzSLCC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u3lY0iH9, HV_BINOP_LESS_THAN, 1, m, &cBinop_u3lY0iH9_sendMessage);
}

void Heavy_pdpoly::cCast_fJAXMK44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8LNQxISL_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_1gwQu5fA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_skvXCdrP, 0, m, &cVar_skvXCdrP_sendMessage);
}

void Heavy_pdpoly::cMsg_8LNQxISL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_skvXCdrP, 0, m, &cVar_skvXCdrP_sendMessage);
}

void Heavy_pdpoly::cCast_SkGHMBBa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kaeVaBmY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EBrl5Qht_sendMessage);
}

void Heavy_pdpoly::cCast_hqKVCEzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_1gwQu5fA_sendMessage);
}

void Heavy_pdpoly::cVar_syyhG99p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yPBBcgPN, 0, m, &cVar_yPBBcgPN_sendMessage);
}

void Heavy_pdpoly::cTabwrite_F5LcY5Ee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_lS6mo4Qn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_D39sYbna, 0, m, &cSlice_D39sYbna_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_F5LcY5Ee, 0, m, &cTabwrite_F5LcY5Ee_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_D39sYbna_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_F5LcY5Ee, 2, m, &cTabwrite_F5LcY5Ee_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_F5LcY5Ee, 2, m, &cTabwrite_F5LcY5Ee_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_A5WdklwJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_jC2hm7G2_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_BtDnjUSt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fwL7wPDl, 0, m, &cSlice_fwL7wPDl_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fueCAyD9_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_A8QJ2TxO_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_fwL7wPDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_A5WdklwJ, 1, m, &cTabread_A5WdklwJ_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_A5WdklwJ, 1, m, &cTabread_A5WdklwJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_ENdjzPvY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q0hqrzLb_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_WpErSV4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_PRqYkcRq_sendMessage);
}

void Heavy_pdpoly::cBinop_nObVVVMx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JwNqc0yP, HV_BINOP_MIN, 0, m, &cBinop_JwNqc0yP_sendMessage);
}

void Heavy_pdpoly::cCast_A8QJ2TxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_nObVVVMx_sendMessage);
}

void Heavy_pdpoly::cCast_fueCAyD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ENdjzPvY, 0, m, &cVar_ENdjzPvY_sendMessage);
}

void Heavy_pdpoly::cBinop_JwNqc0yP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_A5WdklwJ, 0, m, &cTabread_A5WdklwJ_sendMessage);
}

void Heavy_pdpoly::cMsg_Q0hqrzLb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WpErSV4q_sendMessage);
}

void Heavy_pdpoly::cBinop_PRqYkcRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JwNqc0yP, HV_BINOP_MIN, 1, m, &cBinop_JwNqc0yP_sendMessage);
}

void Heavy_pdpoly::cIf_L1T0xF9C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QzxSgUz5_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5KIX96oS_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ymWjhyup_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_peaom0g6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KkK9ZD2f_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_GtkzcUTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_8Uwl8Ktc, 1, m, &cPack_8Uwl8Ktc_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_jL38rtE8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YcqDOBz4, 0, m, &cSlice_YcqDOBz4_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cbTJYNJ8_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GwBRISjJ_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_YcqDOBz4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_GtkzcUTu, 1, m, &cTabread_GtkzcUTu_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_GtkzcUTu, 1, m, &cTabread_GtkzcUTu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_Pcj0UNwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KrztGAlg_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_gYbHpHXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_1wmY3aBj_sendMessage);
}

void Heavy_pdpoly::cBinop_MMvUFnn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B4jBuJ7M, HV_BINOP_MIN, 0, m, &cBinop_B4jBuJ7M_sendMessage);
}

void Heavy_pdpoly::cCast_GwBRISjJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MMvUFnn9_sendMessage);
}

void Heavy_pdpoly::cCast_cbTJYNJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Pcj0UNwe, 0, m, &cVar_Pcj0UNwe_sendMessage);
}

void Heavy_pdpoly::cBinop_B4jBuJ7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_GtkzcUTu, 0, m, &cTabread_GtkzcUTu_sendMessage);
}

void Heavy_pdpoly::cMsg_KrztGAlg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gYbHpHXm_sendMessage);
}

void Heavy_pdpoly::cBinop_1wmY3aBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B4jBuJ7M, HV_BINOP_MIN, 1, m, &cBinop_B4jBuJ7M_sendMessage);
}

void Heavy_pdpoly::cCast_VM4FFiFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_syyhG99p, 0, m, &cVar_syyhG99p_sendMessage);
}

void Heavy_pdpoly::cCast_xxHS0BQx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wDkxjrgY_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_wDkxjrgY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_sgUdZs0j_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_sgUdZs0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VweZyHLp_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_jC2hm7G2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_L1T0xF9C, 1, m, &cIf_L1T0xF9C_sendMessage);
}

void Heavy_pdpoly::cCast_kaeVaBmY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BtDnjUSt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_EBrl5Qht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_L1T0xF9C, 0, m, &cIf_L1T0xF9C_sendMessage);
}

void Heavy_pdpoly::cMsg_RLNTjpAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_8Uwl8Ktc, 2, m, &cPack_8Uwl8Ktc_sendMessage);
}

void Heavy_pdpoly::cCast_ymWjhyup_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_O3BaOaoP_sendMessage);
}

void Heavy_pdpoly::cCast_KkK9ZD2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_hrsFcNkP_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_peaom0g6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KHkA88oq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CcEfYm3g_sendMessage);
}

void Heavy_pdpoly::cCast_QzxSgUz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RLNTjpAd_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_5KIX96oS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jL38rtE8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_KHkA88oq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_F5LcY5Ee, 1, m, &cTabwrite_F5LcY5Ee_sendMessage);
}

void Heavy_pdpoly::cCast_CcEfYm3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7hZPAQUQ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_7hZPAQUQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_lS6mo4Qn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSend_hrsFcNkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VweZyHLp_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_gpA50uBR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4v4UYk45_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fxFglpFN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_df4N9NAX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JaCFew8Z_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IGSv5v7x_sendMessage);
}

void Heavy_pdpoly::cIf_Lg7nFwX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_z5EEF0ML_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JcQv71Lv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_CtsWkWRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Lg7nFwX2, 1, m, &cIf_Lg7nFwX2_sendMessage);
}

void Heavy_pdpoly::cVar_RqNcdN73_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_3Q1PxkVh_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_EAuCcygz, 0, m, &cIf_EAuCcygz_sendMessage);
}

void Heavy_pdpoly::cUnop_3cxeuUSG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_CtsWkWRF_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Lg7nFwX2, 0, m, &cIf_Lg7nFwX2_sendMessage);
}

void Heavy_pdpoly::cUnop_kmGFbFQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_CtsWkWRF_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Lg7nFwX2, 0, m, &cIf_Lg7nFwX2_sendMessage);
}

void Heavy_pdpoly::cIf_EAuCcygz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_kmGFbFQK_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_3cxeuUSG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_3Q1PxkVh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EAuCcygz, 1, m, &cIf_EAuCcygz_sendMessage);
}

void Heavy_pdpoly::cCast_JaCFew8Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QUs3u7ln, HV_BINOP_LESS_THAN, 0, m, &cBinop_QUs3u7ln_sendMessage);
}

void Heavy_pdpoly::cCast_IGSv5v7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gpA50uBR, 0, m, &cIf_gpA50uBR_sendMessage);
}

void Heavy_pdpoly::cBinop_QUs3u7ln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gpA50uBR, 1, m, &cIf_gpA50uBR_sendMessage);
}

void Heavy_pdpoly::cCast_z5EEF0ML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QUs3u7ln, HV_BINOP_LESS_THAN, 1, m, &cBinop_QUs3u7ln_sendMessage);
}

void Heavy_pdpoly::cCast_JcQv71Lv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qnPbkCl9_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_Yrghx699_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_df4N9NAX, 0, m, &cVar_df4N9NAX_sendMessage);
}

void Heavy_pdpoly::cMsg_qnPbkCl9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_df4N9NAX, 0, m, &cVar_df4N9NAX_sendMessage);
}

void Heavy_pdpoly::cCast_4v4UYk45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_y90545Sw, 1, m, &cTabwrite_y90545Sw_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_zf30tjzO, 1, m, &cTabwrite_zf30tjzO_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_1FxpFWFg, 1, m, &cTabwrite_1FxpFWFg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FEymuxkb_sendMessage);
}

void Heavy_pdpoly::cCast_fxFglpFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Yrghx699_sendMessage);
}

void Heavy_pdpoly::cVar_3i0IGMqX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RqNcdN73, 0, m, &cVar_RqNcdN73_sendMessage);
}

void Heavy_pdpoly::cTabwrite_1FxpFWFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_EjqlkXPP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UA6096g6, 0, m, &cSlice_UA6096g6_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_1FxpFWFg, 0, m, &cTabwrite_1FxpFWFg_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_UA6096g6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_1FxpFWFg, 2, m, &cTabwrite_1FxpFWFg_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_1FxpFWFg, 2, m, &cTabwrite_1FxpFWFg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_zf30tjzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_Qpc96D6O_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_WaP5YVvL, 0, m, &cSlice_WaP5YVvL_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_zf30tjzO, 0, m, &cTabwrite_zf30tjzO_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_WaP5YVvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_zf30tjzO, 2, m, &cTabwrite_zf30tjzO_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_zf30tjzO, 2, m, &cTabwrite_zf30tjzO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_y90545Sw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_PuEKqV3T_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9IdfsYmk, 0, m, &cSlice_9IdfsYmk_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_y90545Sw, 0, m, &cTabwrite_y90545Sw_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_9IdfsYmk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_y90545Sw, 2, m, &cTabwrite_y90545Sw_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_y90545Sw, 2, m, &cTabwrite_y90545Sw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cMsg_vr65uoch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_PuEKqV3T_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Qpc96D6O_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_EjqlkXPP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_W49UzqyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3i0IGMqX, 0, m, &cVar_3i0IGMqX_sendMessage);
}

void Heavy_pdpoly::cCast_fKniZqJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XigPcztc_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_XigPcztc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_hxmDur3E_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_hxmDur3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VweZyHLp_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_FEymuxkb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vr65uoch_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_LAk4pq92_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8k2QcH6V_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gjrUpda6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_NmzLTPfv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_D2gYhhtA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4fal6jcK_sendMessage);
}

void Heavy_pdpoly::cIf_9mP1nkpW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UPYpgovX_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PNVENifc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_2og99mVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9mP1nkpW, 1, m, &cIf_9mP1nkpW_sendMessage);
}

void Heavy_pdpoly::cVar_3HC4d5sL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_4WuGiq2y_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_pSYp5bQK, 0, m, &cIf_pSYp5bQK_sendMessage);
}

void Heavy_pdpoly::cUnop_QuOk0Ged_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_2og99mVr_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_9mP1nkpW, 0, m, &cIf_9mP1nkpW_sendMessage);
}

void Heavy_pdpoly::cUnop_J03nDlOK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_2og99mVr_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_9mP1nkpW, 0, m, &cIf_9mP1nkpW_sendMessage);
}

void Heavy_pdpoly::cIf_pSYp5bQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_J03nDlOK_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_QuOk0Ged_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_4WuGiq2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_pSYp5bQK, 1, m, &cIf_pSYp5bQK_sendMessage);
}

void Heavy_pdpoly::cCast_4fal6jcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_LAk4pq92, 0, m, &cIf_LAk4pq92_sendMessage);
}

void Heavy_pdpoly::cCast_D2gYhhtA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_anUELzZ7, HV_BINOP_LESS_THAN, 0, m, &cBinop_anUELzZ7_sendMessage);
}

void Heavy_pdpoly::cBinop_anUELzZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_LAk4pq92, 1, m, &cIf_LAk4pq92_sendMessage);
}

void Heavy_pdpoly::cCast_UPYpgovX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_anUELzZ7, HV_BINOP_LESS_THAN, 1, m, &cBinop_anUELzZ7_sendMessage);
}

void Heavy_pdpoly::cCast_PNVENifc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_c5xGqqHf_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_TkIj5cQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NmzLTPfv, 0, m, &cVar_NmzLTPfv_sendMessage);
}

void Heavy_pdpoly::cMsg_c5xGqqHf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_NmzLTPfv, 0, m, &cVar_NmzLTPfv_sendMessage);
}

void Heavy_pdpoly::cCast_8k2QcH6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_phhuoJ86_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aeFRqdNq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Y50uVzzJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2gvbfXuS_sendMessage);
}

void Heavy_pdpoly::cCast_gjrUpda6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TkIj5cQQ_sendMessage);
}

void Heavy_pdpoly::cVar_2xSkMdNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3HC4d5sL, 0, m, &cVar_3HC4d5sL_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_vAI2sRRC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B6UU3cHy_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_B6UU3cHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xROeMUsh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fRshXMTM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WtHsrOID_sendMessage);
}

void Heavy_pdpoly::cVar_xdwcDSCX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_twp5HHKI_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cIf_f7RX8Ar1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_0UYOnAZv_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_HNQEv8dg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_qBjrN9Ib_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSwitchcase_0UYOnAZv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5ji7L8bj_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cCast_5ji7L8bj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6jgVw00q_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XSJOs239_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Afld1YxA_sendMessage);
}

void Heavy_pdpoly::cVar_A2Pzvhzw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QINOdvVC, HV_BINOP_LESS_THAN, 1, m, &cBinop_QINOdvVC_sendMessage);
}

void Heavy_pdpoly::cVar_kLP251yp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RrW4eBWz, HV_BINOP_LESS_THAN, 1, m, &cBinop_RrW4eBWz_sendMessage);
}

void Heavy_pdpoly::cIf_NjEHh6AU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_z2AqZiIu, 0, m, &cSlice_z2AqZiIu_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_7STl7G78, 0, m, &cSlice_7STl7G78_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pmjFaJIm_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8IJTfAEP_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1mWjVmwO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cIf_zur2p3Qt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NcyQeTrf_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_XXvuIvoO, 0, m, &cSlice_XXvuIvoO_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_Wzn1OLwX, 0, m, &cSlice_Wzn1OLwX_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9gZraFE9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_drdiETEG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XXJQztSD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cPack_1BRpMtdT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zur2p3Qt, 0, m, &cIf_zur2p3Qt_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NjEHh6AU, 0, m, &cIf_NjEHh6AU_sendMessage);
}

void Heavy_pdpoly::cVar_Ywi44Uvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_O3BaOaoP_sendMessage);
}

void Heavy_pdpoly::cSlice_z2AqZiIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_8Uwl8Ktc, 2, m, &cPack_8Uwl8Ktc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_7STl7G78_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_jpvAzKkj_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_8Uwl8Ktc, 1, m, &cPack_8Uwl8Ktc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_4nDMSKqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_O3BaOaoP_sendMessage);
}

void Heavy_pdpoly::cIf_dwATKqVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_zur2p3Qt, 1, m, &cIf_zur2p3Qt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_oyDdxJnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ADAu0TY8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cVar_XyGzNCne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WGTNGpdG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cTabread_ZpaEUjvY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3gzVEJNr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_K2TqPR3H_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_5dW4Y9Vl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5FqhzqOL, 0, m, &cSlice_5FqhzqOL_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0KYFDtsp_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rkAw3uQD_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_5FqhzqOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_ZpaEUjvY, 1, m, &cTabread_ZpaEUjvY_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_ZpaEUjvY, 1, m, &cTabread_ZpaEUjvY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_8KInnEqD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wPrsFQxG_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_6mBsgQPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_BuzRfJNU_sendMessage);
}

void Heavy_pdpoly::cBinop_mfsqj9ZL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HWIDTVPh, HV_BINOP_MIN, 0, m, &cBinop_HWIDTVPh_sendMessage);
}

void Heavy_pdpoly::cCast_rkAw3uQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mfsqj9ZL_sendMessage);
}

void Heavy_pdpoly::cCast_0KYFDtsp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8KInnEqD, 0, m, &cVar_8KInnEqD_sendMessage);
}

void Heavy_pdpoly::cBinop_HWIDTVPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_ZpaEUjvY, 0, m, &cTabread_ZpaEUjvY_sendMessage);
}

void Heavy_pdpoly::cMsg_wPrsFQxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6mBsgQPV_sendMessage);
}

void Heavy_pdpoly::cBinop_BuzRfJNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HWIDTVPh, HV_BINOP_MIN, 1, m, &cBinop_HWIDTVPh_sendMessage);
}

void Heavy_pdpoly::cTabread_ZG915VZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TLnLtawE_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J4NsJCYB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Bhu13UDM_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_KPcGGKDg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_EolPpEiq, 0, m, &cSlice_EolPpEiq_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BwWs0V4L_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ll5HROSy_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_EolPpEiq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_ZG915VZe, 1, m, &cTabread_ZG915VZe_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_ZG915VZe, 1, m, &cTabread_ZG915VZe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_baIEnrWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3Tltaw0v_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_u1A8v369_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_lwfEIWGb_sendMessage);
}

void Heavy_pdpoly::cBinop_IrulnwT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EutqCYiW, HV_BINOP_MIN, 0, m, &cBinop_EutqCYiW_sendMessage);
}

void Heavy_pdpoly::cCast_ll5HROSy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_IrulnwT0_sendMessage);
}

void Heavy_pdpoly::cCast_BwWs0V4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_baIEnrWJ, 0, m, &cVar_baIEnrWJ_sendMessage);
}

void Heavy_pdpoly::cBinop_EutqCYiW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_ZG915VZe, 0, m, &cTabread_ZG915VZe_sendMessage);
}

void Heavy_pdpoly::cMsg_3Tltaw0v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_u1A8v369_sendMessage);
}

void Heavy_pdpoly::cBinop_lwfEIWGb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EutqCYiW, HV_BINOP_MIN, 1, m, &cBinop_EutqCYiW_sendMessage);
}

void Heavy_pdpoly::cTabwrite_oCWveMX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_6JokRLaH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_22YlYBVm, 0, m, &cSlice_22YlYBVm_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_oCWveMX9, 0, m, &cTabwrite_oCWveMX9_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_22YlYBVm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_oCWveMX9, 2, m, &cTabwrite_oCWveMX9_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_oCWveMX9, 2, m, &cTabwrite_oCWveMX9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabread_LjOzAkZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_8Uwl8Ktc, 1, m, &cPack_8Uwl8Ktc_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_ADAu0TY8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BsfGsx0E, 0, m, &cSlice_BsfGsx0E_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SKaW5d76_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PKQesbxd_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_BsfGsx0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_LjOzAkZH, 1, m, &cTabread_LjOzAkZH_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_LjOzAkZH, 1, m, &cTabread_LjOzAkZH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_FretsQzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ua5CeEJb_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSystem_aoD92YYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mlmA7DLT_sendMessage);
}

void Heavy_pdpoly::cBinop_jCHtrVbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Um3h6DGJ, HV_BINOP_MIN, 0, m, &cBinop_Um3h6DGJ_sendMessage);
}

void Heavy_pdpoly::cCast_SKaW5d76_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FretsQzi, 0, m, &cVar_FretsQzi_sendMessage);
}

void Heavy_pdpoly::cCast_PKQesbxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_jCHtrVbm_sendMessage);
}

void Heavy_pdpoly::cBinop_Um3h6DGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_LjOzAkZH, 0, m, &cTabread_LjOzAkZH_sendMessage);
}

void Heavy_pdpoly::cMsg_ua5CeEJb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aoD92YYy_sendMessage);
}

void Heavy_pdpoly::cBinop_mlmA7DLT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Um3h6DGJ, HV_BINOP_MIN, 1, m, &cBinop_Um3h6DGJ_sendMessage);
}

void Heavy_pdpoly::cTabwrite_dIng54Xh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_jpvAzKkj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iaRUvFCf, 0, m, &cSlice_iaRUvFCf_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_dIng54Xh, 0, m, &cTabwrite_dIng54Xh_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_iaRUvFCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_dIng54Xh, 2, m, &cTabwrite_dIng54Xh_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_dIng54Xh, 2, m, &cTabwrite_dIng54Xh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_5b0Ouubl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_GIbKm36j_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5dznhrlp, 0, m, &cSlice_5dznhrlp_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_5b0Ouubl, 0, m, &cTabwrite_5b0Ouubl_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_5dznhrlp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_5b0Ouubl, 2, m, &cTabwrite_5b0Ouubl_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_5b0Ouubl, 2, m, &cTabwrite_5b0Ouubl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_wJqtQA1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_WGTNGpdG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_OGO44fnX, 0, m, &cSlice_OGO44fnX_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_wJqtQA1z, 0, m, &cTabwrite_wJqtQA1z_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_OGO44fnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_wJqtQA1z, 2, m, &cTabwrite_wJqtQA1z_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_wJqtQA1z, 2, m, &cTabwrite_wJqtQA1z_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cTabwrite_Zdl7o9yg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_bFSUsHX6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_G4mzyaAZ, 0, m, &cSlice_G4mzyaAZ_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Zdl7o9yg, 0, m, &cTabwrite_Zdl7o9yg_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_G4mzyaAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Zdl7o9yg, 2, m, &cTabwrite_Zdl7o9yg_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Zdl7o9yg, 2, m, &cTabwrite_Zdl7o9yg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_ErYhtuLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bFSUsHX6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cTabwrite_pOBmMP0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cSwitchcase_lIn7CZkj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_DWrSN5GU, 0, m, &cSlice_DWrSN5GU_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pOBmMP0H, 0, m, &cTabwrite_pOBmMP0H_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_DWrSN5GU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pOBmMP0H, 2, m, &cTabwrite_pOBmMP0H_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pOBmMP0H, 2, m, &cTabwrite_pOBmMP0H_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_uK95EYv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0nkH5VOJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mmkj6bH8_sendMessage);
}

void Heavy_pdpoly::cSlice_XXvuIvoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_8Uwl8Ktc, 2, m, &cPack_8Uwl8Ktc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_Wzn1OLwX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_6JokRLaH_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_8Uwl8Ktc, 1, m, &cPack_8Uwl8Ktc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cVar_jlq9e63J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ByH516od, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_ByH516od_sendMessage);
}

void Heavy_pdpoly::cBinop_mlETWTWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SNFXyd9R_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nLsRofPK_sendMessage);
}

void Heavy_pdpoly::cBinop_QINOdvVC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p3ZvN2ES, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_p3ZvN2ES_sendMessage);
}

void Heavy_pdpoly::cCast_phhuoJ86_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xdwcDSCX, 1, m, &cVar_xdwcDSCX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HNQEv8dg, 1, m, &cVar_HNQEv8dg_sendMessage);
}

void Heavy_pdpoly::cCast_Y50uVzzJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5dW4Y9Vl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_2gvbfXuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cCast_aeFRqdNq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KPcGGKDg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSend_twp5HHKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gb0NX0pr_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_3gzVEJNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mlETWTWB, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_mlETWTWB_sendMessage);
}

void Heavy_pdpoly::cCast_K2TqPR3H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Y7vEGuQ4_sendMessage);
}

void Heavy_pdpoly::cBinop_p3ZvN2ES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_f7RX8Ar1, 0, m, &cIf_f7RX8Ar1_sendMessage);
}

void Heavy_pdpoly::cBinop_Y7vEGuQ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p3ZvN2ES, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_p3ZvN2ES_sendMessage);
}

void Heavy_pdpoly::cCast_nLsRofPK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_DbPVQ0Mb_sendMessage);
}

void Heavy_pdpoly::cCast_SNFXyd9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vAI2sRRC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_DbPVQ0Mb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_f7RX8Ar1, 1, m, &cIf_f7RX8Ar1_sendMessage);
}

void Heavy_pdpoly::cSend_qBjrN9Ib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JtpSDdTV_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_cetlulw2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_gb0NX0pr_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_J0btnJsx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_JtpSDdTV_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_18I4sLVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2xSkMdNh, 0, m, &cVar_2xSkMdNh_sendMessage);
}

void Heavy_pdpoly::cCast_E2lz6zqG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FI07LRJc_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_jinB7z1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uK95EYv0, 0, m, &cVar_uK95EYv0_sendMessage);
}

void Heavy_pdpoly::cBinop_RrW4eBWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mlETWTWB, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_mlETWTWB_sendMessage);
}

void Heavy_pdpoly::cCast_J4NsJCYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RrW4eBWz, HV_BINOP_LESS_THAN, 0, m, &cBinop_RrW4eBWz_sendMessage);
}

void Heavy_pdpoly::cCast_TLnLtawE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A2Pzvhzw, 1, m, &cVar_A2Pzvhzw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kLP251yp, 1, m, &cVar_kLP251yp_sendMessage);
}

void Heavy_pdpoly::cCast_Bhu13UDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QINOdvVC, HV_BINOP_LESS_THAN, 0, m, &cBinop_QINOdvVC_sendMessage);
}

void Heavy_pdpoly::cCast_mmkj6bH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A2Pzvhzw, 0, m, &cVar_A2Pzvhzw_sendMessage);
}

void Heavy_pdpoly::cCast_0nkH5VOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kLP251yp, 0, m, &cVar_kLP251yp_sendMessage);
}

void Heavy_pdpoly::cSend_mh9ESRMO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xP9N1Pfy_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_Afld1YxA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HNQEv8dg, 0, m, &cVar_HNQEv8dg_sendMessage);
}

void Heavy_pdpoly::cCast_XSJOs239_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HW9SqiVv_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_6jgVw00q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A2Pzvhzw, 0, m, &cVar_A2Pzvhzw_sendMessage);
}

void Heavy_pdpoly::cMsg_HW9SqiVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_mh9ESRMO_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_xkXmalmA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_wgL89MSU_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_wgL89MSU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_XB8fCMhH_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_xROeMUsh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kLP251yp, 0, m, &cVar_kLP251yp_sendMessage);
}

void Heavy_pdpoly::cCast_WtHsrOID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xdwcDSCX, 0, m, &cVar_xdwcDSCX_sendMessage);
}

void Heavy_pdpoly::cCast_fRshXMTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xkXmalmA_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_FI07LRJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_J0btnJsx_sendMessage(_c, 0, m);
  cSend_cetlulw2_sendMessage(_c, 0, m);
  cSend_ROqWga10_sendMessage(_c, 0, m);
  cSend_teZaXVjd_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_ROqWga10_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_XB8fCMhH_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_teZaXVjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xP9N1Pfy_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_aB9TtdXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NjEHh6AU, 1, m, &cIf_NjEHh6AU_sendMessage);
}

void Heavy_pdpoly::cCast_nPA1aGA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_4lyC42mf_sendMessage);
}

void Heavy_pdpoly::cBinop_ByH516od_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dwATKqVK, 0, m, &cIf_dwATKqVK_sendMessage);
}

void Heavy_pdpoly::cBinop_4lyC42mf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jlq9e63J, 0, m, &cVar_jlq9e63J_sendMessage);
}

void Heavy_pdpoly::cMsg_qCQd8hkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_GIbKm36j_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cMsg_SeIEp9hx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_lIn7CZkj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cCast_rC77Gnai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_csRT7KzV_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_T5JOHwWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4nDMSKqo, 0, m, &cVar_4nDMSKqo_sendMessage);
}

void Heavy_pdpoly::cCast_vhUIayUT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oyDdxJnP, 0, m, &cVar_oyDdxJnP_sendMessage);
}

void Heavy_pdpoly::cMsg_csRT7KzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_8Uwl8Ktc, 2, m, &cPack_8Uwl8Ktc_sendMessage);
}

void Heavy_pdpoly::cCast_1mWjVmwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cZ9NdIhz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qd5dtLzz_sendMessage);
}

void Heavy_pdpoly::cCast_8IJTfAEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qCQd8hkE_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_pmjFaJIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ywi44Uvy, 0, m, &cVar_Ywi44Uvy_sendMessage);
}

void Heavy_pdpoly::cCast_cZ9NdIhz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_NPky3jok_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_Qd5dtLzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XyGzNCne, 0, m, &cVar_XyGzNCne_sendMessage);
}

void Heavy_pdpoly::cSend_NPky3jok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VweZyHLp_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_LAeAwDOf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_sMjIIBUn_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_LK41B7Au_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ErYhtuLf, 0, m, &cVar_ErYhtuLf_sendMessage);
}

void Heavy_pdpoly::cSend_sMjIIBUn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_VweZyHLp_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_NcyQeTrf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rC77Gnai_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vhUIayUT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T5JOHwWv_sendMessage);
}

void Heavy_pdpoly::cCast_XXJQztSD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LAeAwDOf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LK41B7Au_sendMessage);
}

void Heavy_pdpoly::cCast_drdiETEG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SeIEp9hx_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cCast_9gZraFE9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4nDMSKqo, 0, m, &cVar_4nDMSKqo_sendMessage);
}

void Heavy_pdpoly::cCast_P4TfiCI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jlq9e63J, 0, m, &cVar_jlq9e63J_sendMessage);
}

void Heavy_pdpoly::cCast_DDWV6KHD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ByH516od, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_ByH516od_sendMessage);
}

void Heavy_pdpoly::cSend_bKxO8cOh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_eeejjrCu_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_UKo3LOii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6AVLWKJ1, 1, m, &cVar_6AVLWKJ1_sendMessage);
}

void Heavy_pdpoly::cSend_TZqwXAt7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Ne3Wl82t_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_O3BaOaoP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_8Uwl8Ktc, 0, m, &cPack_8Uwl8Ktc_sendMessage);
}

void Heavy_pdpoly::cBinop_NC5AXQVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_UKo3LOii_sendMessage);
  cSend_TZqwXAt7_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::hTable_MSBU8ehe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::hTable_pXe9AovR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::hTable_ZsQlsR6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_pdpoly::cCast_3WZ5pCJJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5gLbZ4VH, 0, m, &cVar_5gLbZ4VH_sendMessage);
}

void Heavy_pdpoly::cCast_FGI6RDQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ICIWMthe_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cSend_kSh3kiRn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7SSvGYdC_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_ICIWMthe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 65535.0f);
  cSend_kSh3kiRn_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_ulnf4P8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5VXvlq4z, 1, m, &cIf_5VXvlq4z_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_0YiP8jax_sendMessage);
}

void Heavy_pdpoly::cBinop_0YiP8jax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_8CHcna9u, 1, m, &cIf_8CHcna9u_sendMessage);
}

void Heavy_pdpoly::cBinop_xC0RpBE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_bKxO8cOh_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cPack_8Uwl8Ktc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BCD1L7AE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_pdpoly::cSwitchcase_BCD1L7AE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_HAATdkMc, 0, m, &cSlice_HAATdkMc_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3v0tgLTX, 0, m, &cSlice_3v0tgLTX_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GivCe5mp, 0, m, &cSlice_GivCe5mp_sendMessage);
      break;
    }
    case 0x40800000: { // "4.0f"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Rd2I2I2m, 0, m, &cSlice_Rd2I2I2m_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_pdpoly::cSlice_HAATdkMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_nwanqaz6, 0, m, &cSlice_nwanqaz6_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_GrwqtHc2, 0, m, &cSlice_GrwqtHc2_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_nwanqaz6, 0, m, &cSlice_nwanqaz6_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_GrwqtHc2, 0, m, &cSlice_GrwqtHc2_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_3v0tgLTX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_8s7k4D47, 0, m, &cSlice_8s7k4D47_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_monGASK1, 0, m, &cSlice_monGASK1_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_8s7k4D47, 0, m, &cSlice_8s7k4D47_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_monGASK1, 0, m, &cSlice_monGASK1_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_GivCe5mp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_85EvhwOT, 0, m, &cSlice_85EvhwOT_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_vGFfZ3Xz, 0, m, &cSlice_vGFfZ3Xz_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_85EvhwOT, 0, m, &cSlice_85EvhwOT_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_vGFfZ3Xz, 0, m, &cSlice_vGFfZ3Xz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_Rd2I2I2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_m5SNtuQf, 0, m, &cSlice_m5SNtuQf_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_lgQ89ov6, 0, m, &cSlice_lgQ89ov6_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_m5SNtuQf, 0, m, &cSlice_m5SNtuQf_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_lgQ89ov6, 0, m, &cSlice_lgQ89ov6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_nwanqaz6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_hhyXVpeG_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_GrwqtHc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_1C3B1DoJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_TA1kaiyf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Wj5P76fV, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_fMR8XJkI_sendMessage);
}

void Heavy_pdpoly::cBinop_1C3B1DoJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_ImAgXaUh_sendMessage);
}

void Heavy_pdpoly::cBinop_ImAgXaUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qJiiqiGD, HV_BINOP_POW, 1, m, &cBinop_qJiiqiGD_sendMessage);
  cMsg_NaOmdFAc_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_qJiiqiGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_TA1kaiyf_sendMessage);
}

void Heavy_pdpoly::cMsg_NaOmdFAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qJiiqiGD, HV_BINOP_POW, 0, m, &cBinop_qJiiqiGD_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_hhyXVpeG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mdRp8heo_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_drSr50eJ_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_mdRp8heo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IaKrUoyt_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_VLPOQAyK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pH8fO0Td, HV_BINOP_MULTIPLY, 0, m, &cBinop_pH8fO0Td_sendMessage);
}

void Heavy_pdpoly::cMsg_kAu1KmHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BsyB5RQx_sendMessage);
}

void Heavy_pdpoly::cSystem_BsyB5RQx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gnv3e8p1_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_pH8fO0Td_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_TQaZSix2_sendMessage);
}

void Heavy_pdpoly::cBinop_UjfIiWe9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pH8fO0Td, HV_BINOP_MULTIPLY, 1, m, &cBinop_pH8fO0Td_sendMessage);
}

void Heavy_pdpoly::cMsg_gnv3e8p1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_UjfIiWe9_sendMessage);
}

void Heavy_pdpoly::cBinop_TQaZSix2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5f1YaAVm_sendMessage);
}

void Heavy_pdpoly::cBinop_5f1YaAVm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_foYwyr6n_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GaqkmNVZ, m);
}

void Heavy_pdpoly::cBinop_foYwyr6n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ceyaq3yV, m);
}

void Heavy_pdpoly::cVar_3frtSIMd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NDLMIjPR, HV_BINOP_MULTIPLY, 0, m, &cBinop_NDLMIjPR_sendMessage);
}

void Heavy_pdpoly::cMsg_4qisC7vr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ktOkcUMu_sendMessage);
}

void Heavy_pdpoly::cSystem_ktOkcUMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TzObo5ST_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_NDLMIjPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_DkUxC7MK_sendMessage);
}

void Heavy_pdpoly::cBinop_lFVi6YTc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NDLMIjPR, HV_BINOP_MULTIPLY, 1, m, &cBinop_NDLMIjPR_sendMessage);
}

void Heavy_pdpoly::cMsg_TzObo5ST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_lFVi6YTc_sendMessage);
}

void Heavy_pdpoly::cBinop_DkUxC7MK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_xp1Kn9v0_sendMessage);
}

void Heavy_pdpoly::cBinop_xp1Kn9v0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_qSilGuC3_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_szBkpq6X, m);
}

void Heavy_pdpoly::cBinop_qSilGuC3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NixyCauy, m);
}

void Heavy_pdpoly::cMsg_IaKrUoyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_M43wnOih, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_drSr50eJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lqhNFOd4_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_lqhNFOd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_M43wnOih, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_fMR8XJkI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_idEzkmrR, 0, m);
}

void Heavy_pdpoly::cSlice_8s7k4D47_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_FZIBfr8T_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_monGASK1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_e5YDn1YI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_Wh5pN6oU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_usjXZydD, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_s6ZEJuuF_sendMessage);
}

void Heavy_pdpoly::cBinop_e5YDn1YI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_NRDvJoWd_sendMessage);
}

void Heavy_pdpoly::cBinop_NRDvJoWd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_98kPRk8f, HV_BINOP_POW, 1, m, &cBinop_98kPRk8f_sendMessage);
  cMsg_AN7e35HK_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_98kPRk8f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Wh5pN6oU_sendMessage);
}

void Heavy_pdpoly::cMsg_AN7e35HK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_98kPRk8f, HV_BINOP_POW, 0, m, &cBinop_98kPRk8f_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_FZIBfr8T_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HobYNpMO_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_HQQJ5sZq_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_HobYNpMO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nooahwaF_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_hDQbXjFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5tVZOd74, HV_BINOP_MULTIPLY, 0, m, &cBinop_5tVZOd74_sendMessage);
}

void Heavy_pdpoly::cMsg_VyQOJfxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vNdXlfMm_sendMessage);
}

void Heavy_pdpoly::cSystem_vNdXlfMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hqWZY6Ig_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_5tVZOd74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_cOwtFdSs_sendMessage);
}

void Heavy_pdpoly::cBinop_G2nw5Ly9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5tVZOd74, HV_BINOP_MULTIPLY, 1, m, &cBinop_5tVZOd74_sendMessage);
}

void Heavy_pdpoly::cMsg_hqWZY6Ig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_G2nw5Ly9_sendMessage);
}

void Heavy_pdpoly::cBinop_cOwtFdSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_UcsjECnq_sendMessage);
}

void Heavy_pdpoly::cBinop_UcsjECnq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_xqqBasGI_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_QrTWWsH0, m);
}

void Heavy_pdpoly::cBinop_xqqBasGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Wt5sAjWq, m);
}

void Heavy_pdpoly::cVar_RvzrkK6U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i1qsaVlT, HV_BINOP_MULTIPLY, 0, m, &cBinop_i1qsaVlT_sendMessage);
}

void Heavy_pdpoly::cMsg_jSkn8v3C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_O2Dmkf9T_sendMessage);
}

void Heavy_pdpoly::cSystem_O2Dmkf9T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nqKOVn8w_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_i1qsaVlT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_XmwYucq7_sendMessage);
}

void Heavy_pdpoly::cBinop_65QTjTvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i1qsaVlT, HV_BINOP_MULTIPLY, 1, m, &cBinop_i1qsaVlT_sendMessage);
}

void Heavy_pdpoly::cMsg_nqKOVn8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_65QTjTvT_sendMessage);
}

void Heavy_pdpoly::cBinop_XmwYucq7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DtuQgZuL_sendMessage);
}

void Heavy_pdpoly::cBinop_DtuQgZuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_LcK1YcpE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_IQKhtABl, m);
}

void Heavy_pdpoly::cBinop_LcK1YcpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_p6LhJKv7, m);
}

void Heavy_pdpoly::cMsg_nooahwaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_L4QqhSIJ, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_HQQJ5sZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wxCLb18E_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_wxCLb18E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_L4QqhSIJ, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_s6ZEJuuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_IojInUMO, 0, m);
}

void Heavy_pdpoly::cSlice_85EvhwOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_zobd4AS0_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_vGFfZ3Xz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_2TZwCnPn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_ZVgXAboD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_3cnyDu3m, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_REP1xyQt_sendMessage);
}

void Heavy_pdpoly::cBinop_2TZwCnPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_rQqW0BVK_sendMessage);
}

void Heavy_pdpoly::cBinop_rQqW0BVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sRbg4dj7, HV_BINOP_POW, 1, m, &cBinop_sRbg4dj7_sendMessage);
  cMsg_tyrJvCQ2_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_sRbg4dj7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_ZVgXAboD_sendMessage);
}

void Heavy_pdpoly::cMsg_tyrJvCQ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sRbg4dj7, HV_BINOP_POW, 0, m, &cBinop_sRbg4dj7_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_zobd4AS0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h5CtKBJh_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_bjIXfPQQ_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_h5CtKBJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ponT2AYr_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_v8XJVTvM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LTo52LUD, HV_BINOP_MULTIPLY, 0, m, &cBinop_LTo52LUD_sendMessage);
}

void Heavy_pdpoly::cMsg_dF5ywCED_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XEWRbwyO_sendMessage);
}

void Heavy_pdpoly::cSystem_XEWRbwyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iPqAKItZ_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_LTo52LUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_LVYzTA10_sendMessage);
}

void Heavy_pdpoly::cBinop_XeVRgaXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LTo52LUD, HV_BINOP_MULTIPLY, 1, m, &cBinop_LTo52LUD_sendMessage);
}

void Heavy_pdpoly::cMsg_iPqAKItZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_XeVRgaXe_sendMessage);
}

void Heavy_pdpoly::cBinop_LVYzTA10_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GAMtr4ld_sendMessage);
}

void Heavy_pdpoly::cBinop_GAMtr4ld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ya1k6SBY_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fAdMYihL, m);
}

void Heavy_pdpoly::cBinop_ya1k6SBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kClAg4Eg, m);
}

void Heavy_pdpoly::cVar_Z2H8q1KL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zVUhDAxS, HV_BINOP_MULTIPLY, 0, m, &cBinop_zVUhDAxS_sendMessage);
}

void Heavy_pdpoly::cMsg_RUWBFmeO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_28YfCFk2_sendMessage);
}

void Heavy_pdpoly::cSystem_28YfCFk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZeRxuFLB_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_zVUhDAxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_6kuz8YER_sendMessage);
}

void Heavy_pdpoly::cBinop_CN55Fdeq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zVUhDAxS, HV_BINOP_MULTIPLY, 1, m, &cBinop_zVUhDAxS_sendMessage);
}

void Heavy_pdpoly::cMsg_ZeRxuFLB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_CN55Fdeq_sendMessage);
}

void Heavy_pdpoly::cBinop_6kuz8YER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_frqomwzY_sendMessage);
}

void Heavy_pdpoly::cBinop_frqomwzY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_rXf6CcWF_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_K9JgPTgm, m);
}

void Heavy_pdpoly::cBinop_rXf6CcWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4BULTExG, m);
}

void Heavy_pdpoly::cMsg_ponT2AYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_poPOrEvR, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_bjIXfPQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZQWG4X5i_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_ZQWG4X5i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_poPOrEvR, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_REP1xyQt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_EI99XU1H, 0, m);
}

void Heavy_pdpoly::cSlice_m5SNtuQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_pBqWrUMd_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cSlice_lgQ89ov6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ptaRx0Qb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_pdpoly::cBinop_NnYsT1Ra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_aLE3vOG5, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.006f, 0, m, &cBinop_MBNqpEAa_sendMessage);
}

void Heavy_pdpoly::cBinop_ptaRx0Qb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_bk7AlZDN_sendMessage);
}

void Heavy_pdpoly::cBinop_bk7AlZDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6xPlDnkQ, HV_BINOP_POW, 1, m, &cBinop_6xPlDnkQ_sendMessage);
  cMsg_lB95uxsq_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_6xPlDnkQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_NnYsT1Ra_sendMessage);
}

void Heavy_pdpoly::cMsg_lB95uxsq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6xPlDnkQ, HV_BINOP_POW, 0, m, &cBinop_6xPlDnkQ_sendMessage);
}

void Heavy_pdpoly::cSwitchcase_pBqWrUMd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0f"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Xe1XEdlE_sendMessage);
      break;
    }
    default: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_Z0GcAoYt_sendMessage);
      break;
    }
  }
}

void Heavy_pdpoly::cCast_Xe1XEdlE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G82Lc75z_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cVar_c07ZFn5S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZCWwsmuj, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZCWwsmuj_sendMessage);
}

void Heavy_pdpoly::cMsg_IFRYHDwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_y4iUoMdk_sendMessage);
}

void Heavy_pdpoly::cSystem_y4iUoMdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uFeu62K1_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_ZCWwsmuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ggMRGM52_sendMessage);
}

void Heavy_pdpoly::cBinop_jfMtiEyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZCWwsmuj, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZCWwsmuj_sendMessage);
}

void Heavy_pdpoly::cMsg_uFeu62K1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_jfMtiEyS_sendMessage);
}

void Heavy_pdpoly::cBinop_ggMRGM52_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_qh7S8B7q_sendMessage);
}

void Heavy_pdpoly::cBinop_qh7S8B7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_XSPIl9uK_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BdSY9Yqw, m);
}

void Heavy_pdpoly::cBinop_XSPIl9uK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_b9erWLPG, m);
}

void Heavy_pdpoly::cVar_wwNxtIn5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dsgFUUV1, HV_BINOP_MULTIPLY, 0, m, &cBinop_dsgFUUV1_sendMessage);
}

void Heavy_pdpoly::cMsg_KV6JJ6iB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vVkWWut4_sendMessage);
}

void Heavy_pdpoly::cSystem_vVkWWut4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ueEV2Oc4_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cBinop_dsgFUUV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_YxHHpbve_sendMessage);
}

void Heavy_pdpoly::cBinop_NRir55v5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dsgFUUV1, HV_BINOP_MULTIPLY, 1, m, &cBinop_dsgFUUV1_sendMessage);
}

void Heavy_pdpoly::cMsg_ueEV2Oc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_NRir55v5_sendMessage);
}

void Heavy_pdpoly::cBinop_YxHHpbve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_zBu0q9j3_sendMessage);
}

void Heavy_pdpoly::cBinop_zBu0q9j3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_OYUp4QSb_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7D6MKv1C, m);
}

void Heavy_pdpoly::cBinop_OYUp4QSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4tHtdCCc, m);
}

void Heavy_pdpoly::cMsg_G82Lc75z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 400.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_tTvv4cKl, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_Z0GcAoYt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_F8PeFDmf_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cMsg_F8PeFDmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_tTvv4cKl, 0, m, NULL);
}

void Heavy_pdpoly::cBinop_MBNqpEAa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_UnQcBchX, 0, m);
}

void Heavy_pdpoly::cSend_Jn5BjehS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3NZPRswS_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cReceive_EI4SZt1E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kAu1KmHO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VLPOQAyK, 0, m, &cVar_VLPOQAyK_sendMessage);
  cMsg_4qisC7vr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3frtSIMd, 0, m, &cVar_3frtSIMd_sendMessage);
  cMsg_VyQOJfxL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hDQbXjFC, 0, m, &cVar_hDQbXjFC_sendMessage);
  cMsg_jSkn8v3C_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RvzrkK6U, 0, m, &cVar_RvzrkK6U_sendMessage);
  cMsg_dF5ywCED_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_v8XJVTvM, 0, m, &cVar_v8XJVTvM_sendMessage);
  cMsg_RUWBFmeO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Z2H8q1KL, 0, m, &cVar_Z2H8q1KL_sendMessage);
  cMsg_IFRYHDwv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_c07ZFn5S, 0, m, &cVar_c07ZFn5S_sendMessage);
  cMsg_KV6JJ6iB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wwNxtIn5, 0, m, &cVar_wwNxtIn5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TpLZWuWN, 0, m, &cVar_TpLZWuWN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FGI6RDQ1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3WZ5pCJJ_sendMessage);
}

void Heavy_pdpoly::cReceive_wqW9bP97_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_7CZdLi3z, 0, m, &cSlice_7CZdLi3z_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_vhajNYeU, 0, m, &cSlice_vhajNYeU_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_mkVSG4vR, 0, m, &cSlice_mkVSG4vR_sendMessage);
}

void Heavy_pdpoly::cReceive_eeejjrCu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dwATKqVK, 1, m, &cIf_dwATKqVK_sendMessage);
}

void Heavy_pdpoly::cReceive_Ne3Wl82t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qzyFhB9P, 1, m, &cVar_qzyFhB9P_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XyGzNCne, 1, m, &cVar_XyGzNCne_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ErYhtuLf, 1, m, &cVar_ErYhtuLf_sendMessage);
}

void Heavy_pdpoly::cReceive_VweZyHLp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6AVLWKJ1, 0, m, &cVar_6AVLWKJ1_sendMessage);
}

void Heavy_pdpoly::cReceive_7SSvGYdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dAbOmiuS, 1, m, &cVar_dAbOmiuS_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uK95EYv0, 1, m, &cVar_uK95EYv0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NC5AXQVg, HV_BINOP_MOD_UNIPOLAR, 1, m, &cBinop_NC5AXQVg_sendMessage);
}

void Heavy_pdpoly::cReceive_gb0NX0pr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_oCWveMX9, 1, m, &cTabwrite_oCWveMX9_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_pOBmMP0H, 1, m, &cTabwrite_pOBmMP0H_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Zdl7o9yg, 1, m, &cTabwrite_Zdl7o9yg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4nDMSKqo, 1, m, &cVar_4nDMSKqo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_oyDdxJnP, 1, m, &cVar_oyDdxJnP_sendMessage);
}

void Heavy_pdpoly::cReceive_JtpSDdTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ywi44Uvy, 1, m, &cVar_Ywi44Uvy_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_wJqtQA1z, 1, m, &cTabwrite_wJqtQA1z_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_dIng54Xh, 1, m, &cTabwrite_dIng54Xh_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_5b0Ouubl, 1, m, &cTabwrite_5b0Ouubl_sendMessage);
}

void Heavy_pdpoly::cReceive_xP9N1Pfy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nPA1aGA9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aB9TtdXY_sendMessage);
}

void Heavy_pdpoly::cReceive_XB8fCMhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DDWV6KHD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P4TfiCI6_sendMessage);
}

void Heavy_pdpoly::cReceive_3NZPRswS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VLPOQAyK, 0, m, &cVar_VLPOQAyK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3frtSIMd, 0, m, &cVar_3frtSIMd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hDQbXjFC, 0, m, &cVar_hDQbXjFC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RvzrkK6U, 0, m, &cVar_RvzrkK6U_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_v8XJVTvM, 0, m, &cVar_v8XJVTvM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Z2H8q1KL, 0, m, &cVar_Z2H8q1KL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_c07ZFn5S, 0, m, &cVar_c07ZFn5S_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wwNxtIn5, 0, m, &cVar_wwNxtIn5_sendMessage);
}

void Heavy_pdpoly::cReceive_PpWEy1He_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Jn5BjehS_sendMessage(_c, 0, m);
}

void Heavy_pdpoly::cReceive_YVGLwQ7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_U0dh1fik, m);
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
    __hv_phasor_k_f(&sPhasor_Wj5P76fV, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_idEzkmrR, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_GaqkmNVZ, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_Ceyaq3yV, VOf(Bf2));
    __hv_rpole_f(&sRPole_JXSm576v, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_szBkpq6X, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_NixyCauy, VOf(Bf2));
    __hv_rpole_f(&sRPole_K8bnNaMb, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_M43wnOih, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_usjXZydD, VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_IojInUMO, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_QrTWWsH0, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_Wt5sAjWq, VOf(Bf3));
    __hv_rpole_f(&sRPole_73sEIcOT, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_IQKhtABl, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_p6LhJKv7, VOf(Bf3));
    __hv_rpole_f(&sRPole_DVgg4fgb, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_L4QqhSIJ, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_3cnyDu3m, VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_EI99XU1H, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_fAdMYihL, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_kClAg4Eg, VOf(Bf2));
    __hv_rpole_f(&sRPole_LKoJZv9R, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_K9JgPTgm, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_4BULTExG, VOf(Bf2));
    __hv_rpole_f(&sRPole_svoFpBI9, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_poPOrEvR, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_aLE3vOG5, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_UnQcBchX, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_BdSY9Yqw, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_b9erWLPG, VOf(Bf1));
    __hv_rpole_f(&sRPole_JPbUJ7Kq, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_7D6MKv1C, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_4tHtdCCc, VOf(Bf1));
    __hv_rpole_f(&sRPole_zOu1kWC7, VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_tTvv4cKl, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_U0dh1fik, VOf(Bf3));
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
