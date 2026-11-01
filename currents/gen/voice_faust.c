/* ------------------------------------------------------------
name: "voice"
Code generated with Faust 2.83.1 (https://faust.grame.fr)
Compilation options: -lang c -fpga-mem-th 4 -ct 1 -cn rc_voice -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __rc_voice_H__
#define  __rc_voice_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 


#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

static float rc_voice_faustpower2_f(float value) {
	return value * value;
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS rc_voice
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif
static inline int max_i(int a, int b) { return (a > b) ? a : b; }
static inline int min_i(int a, int b) { return (a < b) ? a : b; }

typedef struct {
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	float fRec0[2];
	float fConst1;
	FAUSTFLOAT fHslider2;
	int iRec1[2];
	float fConst2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec3[2];
	float fRec5[2];
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider5;
	float fConst5;
	float fRec7[2];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fRec8[2];
	float fRec2[3];
} rc_voice;

rc_voice* newrc_voice() { 
	rc_voice* dsp = (rc_voice*)calloc(1, sizeof(rc_voice));
	return dsp;
}

void deleterc_voice(rc_voice* dsp) { 
	free(dsp);
}

void metadatarc_voice(MetaGlue* m) { 
	m->declare(m->metaInterface, "compile_options", "-lang c -fpga-mem-th 4 -ct 1 -cn rc_voice -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
	m->declare(m->metaInterface, "envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
	m->declare(m->metaInterface, "envelopes.lib/author", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "envelopes.lib/name", "Faust Envelope Library");
	m->declare(m->metaInterface, "envelopes.lib/version", "1.3.0");
	m->declare(m->metaInterface, "filename", "voice.dsp");
	m->declare(m->metaInterface, "filters.lib/fir:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/fir:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/iir:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/iir:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/name", "Faust Filters Library");
	m->declare(m->metaInterface, "filters.lib/resonlp:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/resonlp:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/resonlp:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/tf2:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/tf2:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/tf2s:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/tf2s:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/version", "1.7.1");
	m->declare(m->metaInterface, "maths.lib/author", "GRAME");
	m->declare(m->metaInterface, "maths.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "maths.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "maths.lib/name", "Faust Math Library");
	m->declare(m->metaInterface, "maths.lib/version", "2.9.0");
	m->declare(m->metaInterface, "name", "voice");
	m->declare(m->metaInterface, "oscillators.lib/name", "Faust Oscillator Library");
	m->declare(m->metaInterface, "oscillators.lib/saw2ptr:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "oscillators.lib/saw2ptr:license", "STK-4.3");
	m->declare(m->metaInterface, "oscillators.lib/version", "1.6.0");
	m->declare(m->metaInterface, "platform.lib/name", "Generic Platform Library");
	m->declare(m->metaInterface, "platform.lib/version", "1.3.0");
	m->declare(m->metaInterface, "signals.lib/name", "Faust Signal Routing Library");
	m->declare(m->metaInterface, "signals.lib/version", "1.6.0");
	m->declare(m->metaInterface, "voices", "6");
}

int getSampleRaterc_voice(rc_voice* RESTRICT dsp) {
	return dsp->fSampleRate;
}

int getNumInputsrc_voice(rc_voice* RESTRICT dsp) {
	return 0;
}
int getNumOutputsrc_voice(rc_voice* RESTRICT dsp) {
	return 2;
}

void classInitrc_voice(int sample_rate) {
}

void instanceResetUserInterfacerc_voice(rc_voice* dsp) {
	dsp->fHslider0 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider1 = (FAUSTFLOAT)(0.005f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider2 = (FAUSTFLOAT)(0.35f);
	dsp->fHslider3 = (FAUSTFLOAT)(4.4e+02f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.12f);
	dsp->fHslider5 = (FAUSTFLOAT)(2.4e+03f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.6f);
	dsp->fHslider7 = (FAUSTFLOAT)(1.5f);
}

void instanceClearrc_voice(rc_voice* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 2; l0 = l0 + 1) {
			dsp->fVec0[l0] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 2; l1 = l1 + 1) {
			dsp->fRec0[l1] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 2; l2 = l2 + 1) {
			dsp->iRec1[l2] = 0;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->fRec3[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->fRec5[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->fRec7[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->fRec8[l6] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 3; l7 = l7 + 1) {
			dsp->fRec2[l7] = 0.0f;
		}
	}
}

void instanceConstantsrc_voice(rc_voice* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 0.3f / fmaxf(1.0f, 0.25f * dsp->fConst0);
	dsp->fConst2 = 1.0f / dsp->fConst0;
	dsp->fConst3 = 3.1415927f / dsp->fConst0;
	dsp->fConst4 = 44.1f / dsp->fConst0;
	dsp->fConst5 = 1.0f - dsp->fConst4;
}
	
void instanceInitrc_voice(rc_voice* dsp, int sample_rate) {
	instanceConstantsrc_voice(dsp, sample_rate);
	instanceResetUserInterfacerc_voice(dsp);
	instanceClearrc_voice(dsp);
}

void initrc_voice(rc_voice* dsp, int sample_rate) {
	classInitrc_voice(sample_rate);
	instanceInitrc_voice(dsp, sample_rate);
}

void buildUserInterfacerc_voice(rc_voice* dsp, UIGlue* ui_interface) {
	ui_interface->openVerticalBox(ui_interface->uiInterface, "voice");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider1, (FAUSTFLOAT)0.005f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.001f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "cutoff", &dsp->fHslider5, (FAUSTFLOAT)2.4e+03f, (FAUSTFLOAT)6e+01f, (FAUSTFLOAT)1.2e+04f, (FAUSTFLOAT)1.0f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "detune", &dsp->fHslider4, (FAUSTFLOAT)0.12f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "envamt", &dsp->fHslider6, (FAUSTFLOAT)0.6f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "freq", &dsp->fHslider3, (FAUSTFLOAT)4.4e+02f, (FAUSTFLOAT)2e+01f, (FAUSTFLOAT)8e+03f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "gain", &dsp->fHslider0, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addButton(ui_interface->uiInterface, "gate", &dsp->fButton0);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider2, (FAUSTFLOAT)0.35f, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)4.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "res", &dsp->fHslider7, (FAUSTFLOAT)1.5f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)8.0f, (FAUSTFLOAT)0.01f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computerc_voice(rc_voice* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	float fSlow0 = 0.4f * (float)(dsp->fHslider0);
	float fSlow1 = fmaxf(1.0f, dsp->fConst0 * (float)(dsp->fHslider1));
	float fSlow2 = 1.0f / fSlow1;
	float fSlow3 = (float)(dsp->fButton0);
	float fSlow4 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (float)(dsp->fHslider2));
	int iSlow5 = fSlow3 == 0.0f;
	float fSlow6 = (float)(dsp->fHslider3);
	float fSlow7 = 0.01f * (float)(dsp->fHslider4);
	float fSlow8 = fmaxf(1.1920929e-07f, fabsf(fSlow6 * (fSlow7 + 1.0f)));
	float fSlow9 = dsp->fConst2 * fSlow8;
	float fSlow10 = 1.0f - dsp->fConst0 / fSlow8;
	float fSlow11 = fmaxf(1.1920929e-07f, fabsf(fSlow6 * (1.0f - fSlow7)));
	float fSlow12 = dsp->fConst2 * fSlow11;
	float fSlow13 = 1.0f - dsp->fConst0 / fSlow11;
	float fSlow14 = dsp->fConst4 * (float)(dsp->fHslider5);
	float fSlow15 = 3.0f * (float)(dsp->fHslider6);
	float fSlow16 = dsp->fConst4 * (float)(dsp->fHslider7);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->fVec0[0] = fSlow3;
			dsp->fRec0[0] = fSlow3 + dsp->fRec0[1] * (float)(dsp->fVec0[1] >= fSlow3);
			dsp->iRec1[0] = iSlow5 * (dsp->iRec1[1] + 1);
			float fTemp0 = fmaxf(0.0f, fminf(fSlow2 * dsp->fRec0[0], fmaxf(dsp->fConst1 * (fSlow1 - dsp->fRec0[0]) + 1.0f, 0.7f)) * (1.0f - fSlow4 * (float)(dsp->iRec1[0])));
			float fTemp1 = fSlow9 + dsp->fRec3[1] + -1.0f;
			int iTemp2 = fTemp1 < 0.0f;
			float fTemp3 = fSlow9 + dsp->fRec3[1];
			dsp->fRec3[0] = ((iTemp2) ? fTemp3 : fTemp1);
			float fRec4 = ((iTemp2) ? fTemp3 : fSlow9 + dsp->fRec3[1] + fSlow10 * fTemp1);
			float fTemp4 = fSlow12 + dsp->fRec5[1] + -1.0f;
			int iTemp5 = fTemp4 < 0.0f;
			float fTemp6 = fSlow12 + dsp->fRec5[1];
			dsp->fRec5[0] = ((iTemp5) ? fTemp6 : fTemp4);
			float fRec6 = ((iTemp5) ? fTemp6 : fSlow12 + dsp->fRec5[1] + fSlow13 * fTemp4);
			dsp->fRec7[0] = fSlow14 + dsp->fConst5 * dsp->fRec7[1];
			float fTemp7 = tanf(dsp->fConst3 * fminf(1.6e+04f, dsp->fRec7[0] * (fSlow15 * fTemp0 + 1.0f)));
			float fTemp8 = 1.0f / fTemp7;
			dsp->fRec8[0] = fSlow16 + dsp->fConst5 * dsp->fRec8[1];
			float fTemp9 = 1.0f / dsp->fRec8[0];
			float fTemp10 = (fTemp9 + fTemp8) / fTemp7 + 1.0f;
			dsp->fRec2[0] = -(1.0f - (fRec4 + fRec6) + (dsp->fRec2[2] * ((fTemp8 - fTemp9) / fTemp7 + 1.0f) + 2.0f * dsp->fRec2[1] * (1.0f - 1.0f / rc_voice_faustpower2_f(fTemp7))) / fTemp10);
			float fTemp11 = fSlow0 * (fTemp0 * (dsp->fRec2[2] + dsp->fRec2[0] + 2.0f * dsp->fRec2[1]) / fTemp10);
			output0[i0] = (FAUSTFLOAT)(fTemp11);
			output1[i0] = (FAUSTFLOAT)(fTemp11);
			dsp->fVec0[1] = dsp->fVec0[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->iRec1[1] = dsp->iRec1[0];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->fRec2[2] = dsp->fRec2[1];
			dsp->fRec2[1] = dsp->fRec2[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
