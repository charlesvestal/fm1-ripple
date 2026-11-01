/* ------------------------------------------------------------
name: "delay"
Code generated with Faust 2.83.1 (https://faust.grame.fr)
Compilation options: -lang c -fpga-mem-th 4 -ct 1 -cn rc_delay -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __rc_delay_H__
#define  __rc_delay_H__

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


#ifndef FAUSTCLASS 
#define FAUSTCLASS rc_delay
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
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fConst2;
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	float fConst3;
	FAUSTFLOAT fHslider3;
	int IOTA0;
	float fVec0[2];
	float fRec2[2];
	float fRec1[16384];
	float fConst4;
} rc_delay;

rc_delay* newrc_delay() { 
	rc_delay* dsp = (rc_delay*)calloc(1, sizeof(rc_delay));
	return dsp;
}

void deleterc_delay(rc_delay* dsp) { 
	free(dsp);
}

void metadatarc_delay(MetaGlue* m) { 
	m->declare(m->metaInterface, "compile_options", "-lang c -fpga-mem-th 4 -ct 1 -cn rc_delay -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
	m->declare(m->metaInterface, "delays.lib/name", "Faust Delay Library");
	m->declare(m->metaInterface, "delays.lib/version", "1.2.0");
	m->declare(m->metaInterface, "filename", "delay.dsp");
	m->declare(m->metaInterface, "filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/lowpass:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/lowpass:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/name", "Faust Filters Library");
	m->declare(m->metaInterface, "filters.lib/tf1:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/tf1:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/tf1s:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/tf1s:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/version", "1.7.1");
	m->declare(m->metaInterface, "maths.lib/author", "GRAME");
	m->declare(m->metaInterface, "maths.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "maths.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "maths.lib/name", "Faust Math Library");
	m->declare(m->metaInterface, "maths.lib/version", "2.9.0");
	m->declare(m->metaInterface, "name", "delay");
	m->declare(m->metaInterface, "platform.lib/name", "Generic Platform Library");
	m->declare(m->metaInterface, "platform.lib/version", "1.3.0");
	m->declare(m->metaInterface, "signals.lib/name", "Faust Signal Routing Library");
	m->declare(m->metaInterface, "signals.lib/version", "1.6.0");
}

int getSampleRaterc_delay(rc_delay* RESTRICT dsp) {
	return dsp->fSampleRate;
}

int getNumInputsrc_delay(rc_delay* RESTRICT dsp) {
	return 2;
}
int getNumOutputsrc_delay(rc_delay* RESTRICT dsp) {
	return 2;
}

void classInitrc_delay(int sample_rate) {
}

void instanceResetUserInterfacerc_delay(rc_delay* dsp) {
	dsp->fHslider0 = (FAUSTFLOAT)(0.3f);
	dsp->fHslider1 = (FAUSTFLOAT)(0.28f);
	dsp->fHslider2 = (FAUSTFLOAT)(0.45f);
	dsp->fHslider3 = (FAUSTFLOAT)(3.5e+03f);
}

void instanceClearrc_delay(rc_delay* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 2; l0 = l0 + 1) {
			dsp->fRec0[l0] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 2; l1 = l1 + 1) {
			dsp->fVec0[l1] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 2; l2 = l2 + 1) {
			dsp->fRec2[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 16384; l3 = l3 + 1) {
			dsp->fRec1[l3] = 0.0f;
		}
	}
}

void instanceConstantsrc_delay(rc_delay* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 44.1f / dsp->fConst0;
	dsp->fConst2 = 1.0f - dsp->fConst1;
	dsp->fConst3 = 3.1415927f / dsp->fConst0;
	dsp->fConst4 = 0.75f * dsp->fConst0;
}
	
void instanceInitrc_delay(rc_delay* dsp, int sample_rate) {
	instanceConstantsrc_delay(dsp, sample_rate);
	instanceResetUserInterfacerc_delay(dsp);
	instanceClearrc_delay(dsp);
}

void initrc_delay(rc_delay* dsp, int sample_rate) {
	classInitrc_delay(sample_rate);
	instanceInitrc_delay(dsp, sample_rate);
}

void buildUserInterfacerc_delay(rc_delay* dsp, UIGlue* ui_interface) {
	ui_interface->openVerticalBox(ui_interface->uiInterface, "delay");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "feedback", &dsp->fHslider2, (FAUSTFLOAT)0.45f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.92f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "mix", &dsp->fHslider0, (FAUSTFLOAT)0.3f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "time", &dsp->fHslider1, (FAUSTFLOAT)0.28f, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)0.36f, (FAUSTFLOAT)0.001f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "tone", &dsp->fHslider3, (FAUSTFLOAT)3.5e+03f, (FAUSTFLOAT)3e+02f, (FAUSTFLOAT)1.2e+04f, (FAUSTFLOAT)1.0f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computerc_delay(rc_delay* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* input0 = inputs[0];
	FAUSTFLOAT* input1 = inputs[1];
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	float fSlow0 = (float)(dsp->fHslider0);
	float fSlow1 = 1.0f - fSlow0;
	float fSlow2 = dsp->fConst1 * (float)(dsp->fHslider1);
	float fSlow3 = (float)(dsp->fHslider2);
	float fSlow4 = 1.0f / tanf(dsp->fConst3 * (float)(dsp->fHslider3));
	float fSlow5 = 1.0f / (fSlow4 + 1.0f);
	float fSlow6 = 1.0f - fSlow4;
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = (float)(input0[i0]);
			dsp->fRec0[0] = fSlow2 + dsp->fConst2 * dsp->fRec0[1];
			float fTemp1 = dsp->fConst0 * dsp->fRec0[0];
			float fTemp2 = floorf(fTemp1);
			float fTemp3 = fTemp2 + (1.0f - fTemp1);
			int iTemp4 = (int)(fTemp1);
			int iTemp5 = min_i(16001, max_i(0, iTemp4));
			float fTemp6 = fTemp1 - fTemp2;
			int iTemp7 = min_i(16001, max_i(0, iTemp4 + 1));
			float fTemp8 = dsp->fRec1[(dsp->IOTA0 - (iTemp5 + 1)) & 16383] * fTemp3 + fTemp6 * dsp->fRec1[(dsp->IOTA0 - (iTemp7 + 1)) & 16383];
			dsp->fVec0[0] = fTemp8;
			dsp->fRec2[0] = -(fSlow5 * (fSlow6 * dsp->fRec2[1] - (fTemp8 + dsp->fVec0[1])));
			float fTemp9 = (float)(input1[i0]);
			dsp->fRec1[dsp->IOTA0 & 16383] = fSlow3 * dsp->fRec2[0] + 0.5f * (fTemp0 + fTemp9);
			output0[i0] = (FAUSTFLOAT)(fSlow1 * fTemp0 + fSlow0 * (fTemp3 * dsp->fRec1[(dsp->IOTA0 - iTemp5) & 16383] + fTemp6 * dsp->fRec1[(dsp->IOTA0 - iTemp7) & 16383]));
			float fTemp10 = dsp->fConst4 * dsp->fRec0[0];
			int iTemp11 = (int)(fTemp10);
			float fTemp12 = floorf(fTemp10);
			output1[i0] = (FAUSTFLOAT)(fSlow1 * fTemp9 + fSlow0 * (dsp->fRec1[(dsp->IOTA0 - min_i(16001, max_i(0, iTemp11))) & 16383] * (fTemp12 + (1.0f - fTemp10)) + (fTemp10 - fTemp12) * dsp->fRec1[(dsp->IOTA0 - min_i(16001, max_i(0, iTemp11 + 1))) & 16383]));
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fVec0[1] = dsp->fVec0[0];
			dsp->fRec2[1] = dsp->fRec2[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
