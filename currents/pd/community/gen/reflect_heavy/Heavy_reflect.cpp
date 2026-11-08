/** Copyright (c) 2025 boochow Instruments (loguesdk_hvcc_examples, nts1mkii_hvcc_examples) / Copyright (c) 2026 boochow Instruments (drumlogue_hvcc_examples). MIT License (LICENSE beside reflect.pd) */

#include "Heavy_reflect.hpp"



#define Context(_c) static_cast<Heavy_reflect *>(_c)


/*
 * C Functions
 */









/*
 * Class Functions
 */

Heavy_reflect::Heavy_reflect(float sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sTabread_init(&sTabread_iIhwhOlw, &hTable_GoPyCGMw, true);
  numBytes += sTabwrite_init(&sTabwrite_BVXX5Jol, &hTable_GoPyCGMw);
  numBytes += sTabread_init(&sTabread_nUdDrSUF, &hTable_81YWEENA, true);
  numBytes += sTabwrite_init(&sTabwrite_ouZwnh1z, &hTable_81YWEENA);
  numBytes += cDelay_init(this, &cDelay_bGBTbUPp, 0.0f);
  numBytes += cDelay_init(this, &cDelay_rc3ZXUo4, 0.0f);
  numBytes += hTable_init(&hTable_GoPyCGMw, 256);
  numBytes += cTabhead_init(&cTabhead_1RpYWoRm, &hTable_GoPyCGMw);
  numBytes += cVar_init_s(&cVar_KD6A1FFF, "del-buf1");
  numBytes += cDelay_init(this, &cDelay_y0kb2CmR, 50.0f);
  numBytes += cDelay_init(this, &cDelay_CBvTdwIp, 0.0f);
  numBytes += cBinop_init(&cBinop_PYqkp6TO, 50.0f); // __mul
  numBytes += cBinop_init(&cBinop_4bQqfYHb, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Vfew2xUg, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_ZxCHosLr, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_BUj5hdZJ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_yiinUXVR, 0.0f);
  numBytes += hTable_init(&hTable_81YWEENA, 256);
  numBytes += cTabhead_init(&cTabhead_BwLW4f0c, &hTable_81YWEENA);
  numBytes += cVar_init_s(&cVar_C4RvwzNk, "del-buf2");
  numBytes += cDelay_init(this, &cDelay_bGAHlwIp, 50.0f);
  numBytes += cDelay_init(this, &cDelay_kD8cSJR8, 0.0f);
  numBytes += cBinop_init(&cBinop_CMsr0ljt, 50.0f); // __mul
  numBytes += cBinop_init(&cBinop_rrX30TeD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_kvAaKLvx, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_S1W1xEAk, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_2TW69Q0B, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0uj4OL39, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xepzYOK3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VCqfNY6P, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_reflect::~Heavy_reflect() {
  hTable_free(&hTable_GoPyCGMw);
  hTable_free(&hTable_81YWEENA);
}

HvTable *Heavy_reflect::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x7CE9FE80: return &hTable_GoPyCGMw; // del-buf1
    case 0x20DBBA68: return &hTable_81YWEENA; // del-buf2
    default: return nullptr;
  }
}

void Heavy_reflect::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_8KHxAtMF_sendMessage);
      break;
    }
    case 0xC21FE6A3: { // depth_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ItZ2gyFL_sendMessage);
      break;
    }
    case 0x2641F460: { // time_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_VheR5vxb_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_reflect::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "depth_f";
        info->hash = 0xC21FE6A3;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 1: {
        info->name = "time_f";
        info->hash = 0x2641F460;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
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


void Heavy_reflect::cMsg_6inTDP6r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7BvcLfxZ_sendMessage);
}

void Heavy_reflect::cSystem_7BvcLfxZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_V4IMVMR6_sendMessage);
}

void Heavy_reflect::cDelay_bGBTbUPp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bGBTbUPp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rc3ZXUo4, 0, m, &cDelay_rc3ZXUo4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bGBTbUPp, 0, m, &cDelay_bGBTbUPp_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_BVXX5Jol, 1, m, NULL);
}

void Heavy_reflect::cDelay_rc3ZXUo4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rc3ZXUo4, m);
  cMsg_ZQMsZH3Q_sendMessage(_c, 0, m);
}

void Heavy_reflect::cSwitchcase_aXvnbcaP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_uGz3a4ZD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_reflect::cBinop_anQ2dngO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jj8uCfu9_sendMessage(_c, 0, m);
}

void Heavy_reflect::hTable_GoPyCGMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Gl37TJAV_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bGBTbUPp, 2, m, &cDelay_bGBTbUPp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F5W4hNXT_sendMessage);
}

void Heavy_reflect::cMsg_jj8uCfu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_GoPyCGMw, 0, m, &hTable_GoPyCGMw_sendMessage);
}

void Heavy_reflect::cBinop_V4IMVMR6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_anQ2dngO_sendMessage);
}

void Heavy_reflect::cMsg_ZQMsZH3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_GoPyCGMw, 0, m, &hTable_GoPyCGMw_sendMessage);
}

void Heavy_reflect::cCast_F5W4hNXT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bGBTbUPp, 0, m, &cDelay_bGBTbUPp_sendMessage);
}

void Heavy_reflect::cMsg_Gl37TJAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_rc3ZXUo4, 2, m, &cDelay_rc3ZXUo4_sendMessage);
}

void Heavy_reflect::cMsg_uGz3a4ZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_BVXX5Jol, 1, m, NULL);
}

void Heavy_reflect::cTabhead_1RpYWoRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4bQqfYHb, HV_BINOP_SUBTRACT, 0, m, &cBinop_4bQqfYHb_sendMessage);
}

void Heavy_reflect::cMsg_ds2QZXdg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iQFi2hLu_sendMessage);
}

void Heavy_reflect::cSystem_iQFi2hLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BtFggTWx_sendMessage);
}

void Heavy_reflect::cVar_KD6A1FFF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xILb0C0U_sendMessage(_c, 0, m);
}

void Heavy_reflect::cDelay_y0kb2CmR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_y0kb2CmR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CBvTdwIp, 0, m, &cDelay_CBvTdwIp_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_iIhwhOlw, 0, m, &sTabread_iIhwhOlw_sendMessage);
}

void Heavy_reflect::cDelay_CBvTdwIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CBvTdwIp, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_iIhwhOlw, 0, m, &sTabread_iIhwhOlw_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CBvTdwIp, 0, m, &cDelay_CBvTdwIp_sendMessage);
}

void Heavy_reflect::sTabread_iIhwhOlw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ZxCHosLr, HV_BINOP_SUBTRACT, 0, m, &cBinop_ZxCHosLr_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_reflect::cBinop_PYqkp6TO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vfew2xUg, HV_BINOP_MAX, 0, m, &cBinop_Vfew2xUg_sendMessage);
}

void Heavy_reflect::cBinop_BtFggTWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PYqkp6TO, HV_BINOP_MULTIPLY, 0, m, &cBinop_PYqkp6TO_sendMessage);
}

void Heavy_reflect::cBinop_4bQqfYHb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xjvsTbVV_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_iIhwhOlw, 0, m, &sTabread_iIhwhOlw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TLg2bQaC_sendMessage);
}

void Heavy_reflect::cSystem_vVf0z6Fk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZxCHosLr, HV_BINOP_SUBTRACT, 1, m, &cBinop_ZxCHosLr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CBvTdwIp, 2, m, &cDelay_CBvTdwIp_sendMessage);
}

void Heavy_reflect::cMsg_xILb0C0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vVf0z6Fk_sendMessage);
}

void Heavy_reflect::cMsg_xjvsTbVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_y0kb2CmR, 0, m, &cDelay_y0kb2CmR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CBvTdwIp, 0, m, &cDelay_CBvTdwIp_sendMessage);
}

void Heavy_reflect::cMsg_QMJxto7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vfew2xUg, HV_BINOP_MAX, 1, m, &cBinop_Vfew2xUg_sendMessage);
}

void Heavy_reflect::cBinop_Vfew2xUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4bQqfYHb, HV_BINOP_SUBTRACT, 1, m, &cBinop_4bQqfYHb_sendMessage);
}

void Heavy_reflect::cCast_TLg2bQaC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_y0kb2CmR, 0, m, &cDelay_y0kb2CmR_sendMessage);
}

void Heavy_reflect::cBinop_vCZH4WZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_y0kb2CmR, 2, m, &cDelay_y0kb2CmR_sendMessage);
}

void Heavy_reflect::cBinop_ZxCHosLr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vCZH4WZH_sendMessage);
}

void Heavy_reflect::cCast_XXSDaSp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KD6A1FFF, 0, m, &cVar_KD6A1FFF_sendMessage);
  cMsg_ds2QZXdg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_1RpYWoRm, 0, m, &cTabhead_1RpYWoRm_sendMessage);
}

void Heavy_reflect::cMsg_xc6X4DUm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Fm3Ke5TU_sendMessage);
}

void Heavy_reflect::cSystem_Fm3Ke5TU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nRZzhYON_sendMessage);
}

void Heavy_reflect::cDelay_BUj5hdZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BUj5hdZJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yiinUXVR, 0, m, &cDelay_yiinUXVR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BUj5hdZJ, 0, m, &cDelay_BUj5hdZJ_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ouZwnh1z, 1, m, NULL);
}

void Heavy_reflect::cDelay_yiinUXVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yiinUXVR, m);
  cMsg_YBIRVlbm_sendMessage(_c, 0, m);
}

void Heavy_reflect::cSwitchcase_zhi6xTCS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_xWlC7v6h_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_reflect::cBinop_uXOq1JBB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ix9GHDBU_sendMessage(_c, 0, m);
}

void Heavy_reflect::hTable_81YWEENA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Yd5g0ytZ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BUj5hdZJ, 2, m, &cDelay_BUj5hdZJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dzxv3ToL_sendMessage);
}

void Heavy_reflect::cMsg_Ix9GHDBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_81YWEENA, 0, m, &hTable_81YWEENA_sendMessage);
}

void Heavy_reflect::cBinop_nRZzhYON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_uXOq1JBB_sendMessage);
}

void Heavy_reflect::cMsg_YBIRVlbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_81YWEENA, 0, m, &hTable_81YWEENA_sendMessage);
}

void Heavy_reflect::cCast_Dzxv3ToL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BUj5hdZJ, 0, m, &cDelay_BUj5hdZJ_sendMessage);
}

void Heavy_reflect::cMsg_Yd5g0ytZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_yiinUXVR, 2, m, &cDelay_yiinUXVR_sendMessage);
}

void Heavy_reflect::cMsg_xWlC7v6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_ouZwnh1z, 1, m, NULL);
}

void Heavy_reflect::cTabhead_BwLW4f0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rrX30TeD, HV_BINOP_SUBTRACT, 0, m, &cBinop_rrX30TeD_sendMessage);
}

void Heavy_reflect::cMsg_DgPF6KVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3OcUTGrl_sendMessage);
}

void Heavy_reflect::cSystem_3OcUTGrl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ksLAdPMm_sendMessage);
}

void Heavy_reflect::cVar_C4RvwzNk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4jDk8imT_sendMessage(_c, 0, m);
}

void Heavy_reflect::cDelay_bGAHlwIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bGAHlwIp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kD8cSJR8, 0, m, &cDelay_kD8cSJR8_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nUdDrSUF, 0, m, &sTabread_nUdDrSUF_sendMessage);
}

void Heavy_reflect::cDelay_kD8cSJR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kD8cSJR8, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nUdDrSUF, 0, m, &sTabread_nUdDrSUF_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kD8cSJR8, 0, m, &cDelay_kD8cSJR8_sendMessage);
}

void Heavy_reflect::sTabread_nUdDrSUF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_S1W1xEAk, HV_BINOP_SUBTRACT, 0, m, &cBinop_S1W1xEAk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_reflect::cBinop_CMsr0ljt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kvAaKLvx, HV_BINOP_MAX, 0, m, &cBinop_kvAaKLvx_sendMessage);
}

void Heavy_reflect::cBinop_ksLAdPMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CMsr0ljt, HV_BINOP_MULTIPLY, 0, m, &cBinop_CMsr0ljt_sendMessage);
}

void Heavy_reflect::cBinop_rrX30TeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TVerGwfQ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_nUdDrSUF, 0, m, &sTabread_nUdDrSUF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1NkxY1y7_sendMessage);
}

void Heavy_reflect::cSystem_gJk5IYRH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S1W1xEAk, HV_BINOP_SUBTRACT, 1, m, &cBinop_S1W1xEAk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kD8cSJR8, 2, m, &cDelay_kD8cSJR8_sendMessage);
}

void Heavy_reflect::cMsg_4jDk8imT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gJk5IYRH_sendMessage);
}

void Heavy_reflect::cMsg_TVerGwfQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bGAHlwIp, 0, m, &cDelay_bGAHlwIp_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kD8cSJR8, 0, m, &cDelay_kD8cSJR8_sendMessage);
}

void Heavy_reflect::cMsg_60hnsJkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_kvAaKLvx, HV_BINOP_MAX, 1, m, &cBinop_kvAaKLvx_sendMessage);
}

void Heavy_reflect::cBinop_kvAaKLvx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rrX30TeD, HV_BINOP_SUBTRACT, 1, m, &cBinop_rrX30TeD_sendMessage);
}

void Heavy_reflect::cCast_1NkxY1y7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bGAHlwIp, 0, m, &cDelay_bGAHlwIp_sendMessage);
}

void Heavy_reflect::cBinop_KnPkPE9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bGAHlwIp, 2, m, &cDelay_bGAHlwIp_sendMessage);
}

void Heavy_reflect::cBinop_S1W1xEAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_KnPkPE9p_sendMessage);
}

void Heavy_reflect::cCast_fgdVZ1rb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_C4RvwzNk, 0, m, &cVar_C4RvwzNk_sendMessage);
  cMsg_DgPF6KVT_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_BwLW4f0c, 0, m, &cTabhead_BwLW4f0c_sendMessage);
}

void Heavy_reflect::cBinop_EXE6cdyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VCqfNY6P, m);
}

void Heavy_reflect::cBinop_Y7bl7gvc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.5f, 0, m, &cBinop_EXE6cdyG_sendMessage);
}

void Heavy_reflect::cBinop_FiKtyZq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2TW69Q0B, m);
}

void Heavy_reflect::cBinop_WN67NWKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0uj4OL39, m);
}

void Heavy_reflect::cBinop_jxtZtuA8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xepzYOK3, m);
}

void Heavy_reflect::cReceive_ItZ2gyFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Y7bl7gvc_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.2f, 0, m, &cBinop_jxtZtuA8_sendMessage);
}

void Heavy_reflect::cReceive_VheR5vxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.871402f, 0, m, &cBinop_FiKtyZq8_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.882762f, 0, m, &cBinop_WN67NWKQ_sendMessage);
}

void Heavy_reflect::cReceive_8KHxAtMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6inTDP6r_sendMessage(_c, 0, m);
  cMsg_xc6X4DUm_sendMessage(_c, 0, m);
  cMsg_QMJxto7D_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KD6A1FFF, 0, m, &cVar_KD6A1FFF_sendMessage);
  cMsg_ds2QZXdg_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_1RpYWoRm, 0, m, &cTabhead_1RpYWoRm_sendMessage);
  cMsg_60hnsJkx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_C4RvwzNk, 0, m, &cVar_C4RvwzNk_sendMessage);
  cMsg_DgPF6KVT_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_BwLW4f0c, 0, m, &cTabhead_BwLW4f0c_sendMessage);
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

int Heavy_reflect::process(float **inputBuffers, float **outputBuffers, int n) {
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
    __hv_tabread_f(&sTabread_iIhwhOlw, VOf(Bf0));
    __hv_varread_f(&sVarf_2TW69Q0B, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(I0), VIf(I1), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_BVXX5Jol, VIf(Bf2));
    __hv_tabread_f(&sTabread_nUdDrSUF, VOf(Bf2));
    __hv_varread_f(&sVarf_0uj4OL39, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_ouZwnh1z, VIf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_xepzYOK3, VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_VCqfNY6P, VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_reflect::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_reflect::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
