/* ------------------------------------------------------------
name: "pluck"
Code generated with Faust 2.83.1 (https://faust.grame.fr)
Compilation options: -lang c -fpga-mem-th 4 -ct 1 -cn rc_pluck -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __rc_pluck_H__
#define  __rc_pluck_H__

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
#define FAUSTCLASS rc_pluck
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
	FAUSTFLOAT fHslider2;
	int IOTA0;
	float fVec0[2];
	float fRec1[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	int iRec3[2];
	float fConst2;
	float fConst3;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	float fVec2[2];
	int iRec4[2];
	float fVec3[2];
	float fRec2[2];
	float fRec0[1024];
} rc_pluck;

rc_pluck* newrc_pluck() { 
	rc_pluck* dsp = (rc_pluck*)calloc(1, sizeof(rc_pluck));
	return dsp;
}

void deleterc_pluck(rc_pluck* dsp) { 
	free(dsp);
}

void metadatarc_pluck(MetaGlue* m) { 
	m->declare(m->metaInterface, "basics.lib/name", "Faust Basic Element Library");
	m->declare(m->metaInterface, "basics.lib/version", "1.22.0");
	m->declare(m->metaInterface, "compile_options", "-lang c -fpga-mem-th 4 -ct 1 -cn rc_pluck -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
	m->declare(m->metaInterface, "delays.lib/name", "Faust Delay Library");
	m->declare(m->metaInterface, "delays.lib/version", "1.2.0");
	m->declare(m->metaInterface, "envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
	m->declare(m->metaInterface, "envelopes.lib/author", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "envelopes.lib/name", "Faust Envelope Library");
	m->declare(m->metaInterface, "envelopes.lib/version", "1.3.0");
	m->declare(m->metaInterface, "filename", "pluck.dsp");
	m->declare(m->metaInterface, "filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
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
	m->declare(m->metaInterface, "name", "pluck");
	m->declare(m->metaInterface, "noises.lib/name", "Faust Noise Generator Library");
	m->declare(m->metaInterface, "noises.lib/version", "1.5.0");
	m->declare(m->metaInterface, "platform.lib/name", "Generic Platform Library");
	m->declare(m->metaInterface, "platform.lib/version", "1.3.0");
	m->declare(m->metaInterface, "voices", "6");
}

int getSampleRaterc_pluck(rc_pluck* RESTRICT dsp) {
	return dsp->fSampleRate;
}

int getNumInputsrc_pluck(rc_pluck* RESTRICT dsp) {
	return 0;
}
int getNumOutputsrc_pluck(rc_pluck* RESTRICT dsp) {
	return 2;
}

void classInitrc_pluck(int sample_rate) {
}

void instanceResetUserInterfacerc_pluck(rc_pluck* dsp) {
	dsp->fHslider0 = (FAUSTFLOAT)(0.996f);
	dsp->fHslider1 = (FAUSTFLOAT)(0.4f);
	dsp->fHslider2 = (FAUSTFLOAT)(2.2e+02f);
	dsp->fHslider3 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.7f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
}

void instanceClearrc_pluck(rc_pluck* dsp) {
	dsp->IOTA0 = 0;
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
			dsp->fRec1[l1] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 2; l2 = l2 + 1) {
			dsp->iRec3[l2] = 0;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->fVec1[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->fVec2[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->iRec4[l5] = 0;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->fVec3[l6] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 2; l7 = l7 + 1) {
			dsp->fRec2[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 1024; l8 = l8 + 1) {
			dsp->fRec0[l8] = 0.0f;
		}
	}
}

void instanceConstantsrc_pluck(rc_pluck* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 3.1415927f / dsp->fConst0;
	dsp->fConst2 = fmaxf(1.0f, 0.0005f * dsp->fConst0);
	dsp->fConst3 = 1.0f / dsp->fConst2;
}
	
void instanceInitrc_pluck(rc_pluck* dsp, int sample_rate) {
	instanceConstantsrc_pluck(dsp, sample_rate);
	instanceResetUserInterfacerc_pluck(dsp);
	instanceClearrc_pluck(dsp);
}

void initrc_pluck(rc_pluck* dsp, int sample_rate) {
	classInitrc_pluck(sample_rate);
	instanceInitrc_pluck(dsp, sample_rate);
}

void buildUserInterfacerc_pluck(rc_pluck* dsp, UIGlue* ui_interface) {
	ui_interface->openVerticalBox(ui_interface->uiInterface, "pluck");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "bright", &dsp->fHslider4, (FAUSTFLOAT)0.7f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "damp", &dsp->fHslider1, (FAUSTFLOAT)0.4f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "decay", &dsp->fHslider0, (FAUSTFLOAT)0.996f, (FAUSTFLOAT)0.9f, (FAUSTFLOAT)0.9995f, (FAUSTFLOAT)0.0001f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "freq", &dsp->fHslider2, (FAUSTFLOAT)2.2e+02f, (FAUSTFLOAT)56.0f, (FAUSTFLOAT)4e+03f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "gain", &dsp->fHslider3, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addButton(ui_interface->uiInterface, "gate", &dsp->fButton0);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computerc_pluck(rc_pluck* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	float fSlow0 = (float)(dsp->fHslider0);
	float fSlow1 = 1.0f / tanf(dsp->fConst1 * (9e+03f * (1.0f - (float)(dsp->fHslider1)) + 1e+03f));
	float fSlow2 = 1.0f / (fSlow1 + 1.0f);
	float fSlow3 = 1.0f - fSlow1;
	float fSlow4 = dsp->fConst0 / (float)(dsp->fHslider2);
	float fSlow5 = fSlow4 + -1.0f;
	float fSlow6 = floorf(fSlow5);
	float fSlow7 = fSlow6 + (2.0f - fSlow4);
	int iSlow8 = (int)(fSlow5);
	int iSlow9 = min_i(1001, max_i(0, iSlow8)) + 1;
	float fSlow10 = fSlow4 + (-1.0f - fSlow6);
	int iSlow11 = min_i(1001, max_i(0, iSlow8 + 1)) + 1;
	float fSlow12 = (float)(dsp->fHslider3);
	float fSlow13 = (float)(dsp->fHslider4);
	float fSlow14 = 1.0f / tanf(dsp->fConst1 * (9e+03f * fSlow13 + 6e+02f));
	float fSlow15 = 1.0f / (fSlow14 + 1.0f);
	float fSlow16 = (float)(dsp->fButton0);
	float fSlow17 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (0.01f * fSlow13 + 0.004f));
	float fSlow18 = 1.0f - fSlow14;
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = fSlow7 * dsp->fRec0[(dsp->IOTA0 - iSlow9) & 1023] + fSlow10 * dsp->fRec0[(dsp->IOTA0 - iSlow11) & 1023];
			dsp->fVec0[0] = fTemp0;
			dsp->fRec1[0] = -(fSlow2 * (fSlow3 * dsp->fRec1[1] - (fTemp0 + dsp->fVec0[1])));
			dsp->iRec3[0] = 1103515245 * dsp->iRec3[1] + 12345;
			dsp->fVec1[0] = fSlow16;
			float fTemp1 = fSlow16 - dsp->fVec1[1];
			float fTemp2 = fTemp1 * (float)(fTemp1 > 0.0f);
			dsp->fVec2[0] = fTemp2;
			dsp->iRec4[0] = (dsp->iRec4[1] + (dsp->iRec4[1] > 0)) * (fTemp2 <= dsp->fVec2[1]) + (fTemp2 > dsp->fVec2[1]);
			float fTemp3 = (float)(dsp->iRec4[0]);
			float fTemp4 = (float)(dsp->iRec3[0]) * fmaxf(0.0f, fminf(dsp->fConst3 * fTemp3, fSlow17 * (dsp->fConst2 - fTemp3) + 1.0f));
			dsp->fVec3[0] = fTemp4;
			dsp->fRec2[0] = fSlow15 * (4.656613e-10f * (fTemp4 + dsp->fVec3[1]) - fSlow18 * dsp->fRec2[1]);
			dsp->fRec0[dsp->IOTA0 & 1023] = fSlow0 * dsp->fRec1[0] + fSlow12 * dsp->fRec2[0];
			float fTemp5 = 0.6f * dsp->fRec0[dsp->IOTA0 & 1023];
			output0[i0] = (FAUSTFLOAT)(fTemp5);
			output1[i0] = (FAUSTFLOAT)(fTemp5);
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fVec0[1] = dsp->fVec0[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->iRec3[1] = dsp->iRec3[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->fVec2[1] = dsp->fVec2[0];
			dsp->iRec4[1] = dsp->iRec4[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->fRec2[1] = dsp->fRec2[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
