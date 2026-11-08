/** the author of logue-wavefolder.pd */

#ifndef _HEAVY_CONTEXT_LOGUE_WAVEFOLDER_HPP_
#define _HEAVY_CONTEXT_LOGUE_WAVEFOLDER_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalPhasor.h"
#include "HvSignalVar.h"
#include "HvSignalLine.h"
#include "HvMath.h"

class Heavy_logue_wavefolder : public HeavyContext {

 public:
  Heavy_logue_wavefolder(float sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_logue_wavefolder();

  const char *getName() override { return "logue_wavefolder"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 1; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        ALT_F = 0x6C87328F, // alt_f
        PITCH = 0x8B2148DD, // pitch
        SCALE_F = 0x4C5B5D06, // scale_f
        SHAPE_F = 0xCE9531B0, // shape_f
        SLFO = 0x32F5C118, // slfo
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;


  /*
  * Code for expr~ implementation
  * Write out the generic header code
  */

  // per class code

  // per object code


  // static sendMessage functions
  static void cMsg_Z8ErjHnt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MhWktToE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qlgHHV90_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WNTkrTB2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_W1tkqv6Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_TjUVQciC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ovyMMhYL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_vp5vb5BT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_6xpn4S0b_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_6myptfwv;
  SignalLine sLine_kEughDpV;
  SignalLine sLine_WnT5HiOq;
  SignalLine sLine_hKeXzF7i;
  SignalLine sLine_Uhj43Got;
};

#endif // _HEAVY_CONTEXT_LOGUE_WAVEFOLDER_HPP_
