/* ------------------------------------------------------------
name: "fm"
Code generated with Faust 2.83.1 (https://faust.grame.fr)
Compilation options: -lang c -fpga-mem-th 4 -ct 1 -cn rc_fm -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __rc_fm_H__
#define  __rc_fm_H__

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
#define FAUSTCLASS rc_fm
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
	float fRec0[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fRec2[2];
	FAUSTFLOAT fHslider4;
	float fRec1[2];
	FAUSTFLOAT fHslider5;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iRec3[2];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fRec4[2];
	float fConst4;
	FAUSTFLOAT fHslider8;
	int iRec5[2];
} rc_fm;

rc_fm* newrc_fm() { 
	rc_fm* dsp = (rc_fm*)calloc(1, sizeof(rc_fm));
	return dsp;
}

void deleterc_fm(rc_fm* dsp) { 
	free(dsp);
}

void metadatarc_fm(MetaGlue* m) { 
	m->declare(m->metaInterface, "compile_options", "-lang c -fpga-mem-th 4 -ct 1 -cn rc_fm -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
	m->declare(m->metaInterface, "envelopes.lib/adsr:author", "Yann Orlarey and Andrey Bundin");
	m->declare(m->metaInterface, "envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
	m->declare(m->metaInterface, "envelopes.lib/author", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "envelopes.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "envelopes.lib/name", "Faust Envelope Library");
	m->declare(m->metaInterface, "envelopes.lib/version", "1.3.0");
	m->declare(m->metaInterface, "filename", "fm.dsp");
	m->declare(m->metaInterface, "maths.lib/author", "GRAME");
	m->declare(m->metaInterface, "maths.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "maths.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "maths.lib/name", "Faust Math Library");
	m->declare(m->metaInterface, "maths.lib/version", "2.9.0");
	m->declare(m->metaInterface, "name", "fm");
	m->declare(m->metaInterface, "platform.lib/name", "Generic Platform Library");
	m->declare(m->metaInterface, "platform.lib/version", "1.3.0");
	m->declare(m->metaInterface, "voices", "6");
}

int getSampleRaterc_fm(rc_fm* RESTRICT dsp) {
	return dsp->fSampleRate;
}

int getNumInputsrc_fm(rc_fm* RESTRICT dsp) {
	return 0;
}
int getNumOutputsrc_fm(rc_fm* RESTRICT dsp) {
	return 2;
}

void classInitrc_fm(int sample_rate) {
}

void instanceResetUserInterfacerc_fm(rc_fm* dsp) {
	dsp->fHslider0 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider1 = (FAUSTFLOAT)(4.4e+02f);
	dsp->fHslider2 = (FAUSTFLOAT)(3.0f);
	dsp->fHslider3 = (FAUSTFLOAT)(2.0f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider5 = (FAUSTFLOAT)(0.2f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.4f);
	dsp->fHslider7 = (FAUSTFLOAT)(0.003f);
	dsp->fHslider8 = (FAUSTFLOAT)(0.6f);
}

void instanceClearrc_fm(rc_fm* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 2; l0 = l0 + 1) {
			dsp->fRec0[l0] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 2; l1 = l1 + 1) {
			dsp->fRec2[l1] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 2; l2 = l2 + 1) {
			dsp->fRec1[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->fVec0[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->iRec3[l4] = 0;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->fRec4[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->iRec5[l6] = 0;
		}
	}
}

void instanceConstantsrc_fm(rc_fm* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 1.0f / dsp->fConst0;
	dsp->fConst2 = fmaxf(1.0f, 0.001f * dsp->fConst0);
	dsp->fConst3 = 1.0f / dsp->fConst2;
	dsp->fConst4 = 0.2f / fmaxf(1.0f, 0.3f * dsp->fConst0);
}
	
void instanceInitrc_fm(rc_fm* dsp, int sample_rate) {
	instanceConstantsrc_fm(dsp, sample_rate);
	instanceResetUserInterfacerc_fm(dsp);
	instanceClearrc_fm(dsp);
}

void initrc_fm(rc_fm* dsp, int sample_rate) {
	classInitrc_fm(sample_rate);
	instanceInitrc_fm(dsp, sample_rate);
}

void buildUserInterfacerc_fm(rc_fm* dsp, UIGlue* ui_interface) {
	ui_interface->openVerticalBox(ui_interface->uiInterface, "fm");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "attack", &dsp->fHslider7, (FAUSTFLOAT)0.003f, (FAUSTFLOAT)0.001f, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.001f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "fall", &dsp->fHslider6, (FAUSTFLOAT)0.4f, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)4.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "feedback", &dsp->fHslider4, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "floor", &dsp->fHslider5, (FAUSTFLOAT)0.2f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "freq", &dsp->fHslider1, (FAUSTFLOAT)4.4e+02f, (FAUSTFLOAT)2e+01f, (FAUSTFLOAT)8e+03f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "gain", &dsp->fHslider0, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addButton(ui_interface->uiInterface, "gate", &dsp->fButton0);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "index", &dsp->fHslider2, (FAUSTFLOAT)3.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)12.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "ratio", &dsp->fHslider3, (FAUSTFLOAT)2.0f, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)8.0f, (FAUSTFLOAT)0.5f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "release", &dsp->fHslider8, (FAUSTFLOAT)0.6f, (FAUSTFLOAT)0.01f, (FAUSTFLOAT)6.0f, (FAUSTFLOAT)0.01f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computerc_fm(rc_fm* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	float fSlow0 = 0.35f * (float)(dsp->fHslider0);
	float fSlow1 = (float)(dsp->fHslider1);
	float fSlow2 = dsp->fConst1 * fSlow1;
	float fSlow3 = (float)(dsp->fHslider2);
	float fSlow4 = dsp->fConst1 * fSlow1 * (float)(dsp->fHslider3);
	float fSlow5 = 1.5f * (float)(dsp->fHslider4);
	float fSlow6 = (float)(dsp->fHslider5);
	float fSlow7 = 1.0f - fSlow6;
	float fSlow8 = (float)(dsp->fButton0);
	float fSlow9 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (float)(dsp->fHslider6));
	float fSlow10 = fmaxf(1.0f, dsp->fConst0 * (float)(dsp->fHslider7));
	float fSlow11 = 1.0f / fSlow10;
	float fSlow12 = 1.0f / fmaxf(1.0f, dsp->fConst0 * (float)(dsp->fHslider8));
	int iSlow13 = fSlow8 == 0.0f;
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->fRec0[0] = fSlow2 + (dsp->fRec0[1] - floorf(fSlow2 + dsp->fRec0[1]));
			dsp->fRec2[0] = fSlow4 + (dsp->fRec2[1] - floorf(fSlow4 + dsp->fRec2[1]));
			dsp->fRec1[0] = sinf(6.2831855f * dsp->fRec2[0] + fSlow5 * dsp->fRec1[1]);
			dsp->fVec0[0] = fSlow8;
			dsp->iRec3[0] = (dsp->iRec3[1] + (dsp->iRec3[1] > 0)) * (fSlow8 <= dsp->fVec0[1]) + (fSlow8 > dsp->fVec0[1]);
			float fTemp0 = (float)(dsp->iRec3[0]);
			dsp->fRec4[0] = fSlow8 + dsp->fRec4[1] * (float)(dsp->fVec0[1] >= fSlow8);
			dsp->iRec5[0] = iSlow13 * (dsp->iRec5[1] + 1);
			float fTemp1 = fSlow0 * sinf(6.2831855f * dsp->fRec0[0] + fSlow3 * dsp->fRec1[0] * (fSlow6 + fSlow7 * fmaxf(0.0f, fminf(dsp->fConst3 * fTemp0, fSlow9 * (dsp->fConst2 - fTemp0) + 1.0f)))) * fmaxf(0.0f, fminf(fSlow11 * dsp->fRec4[0], fmaxf(dsp->fConst4 * (fSlow10 - dsp->fRec4[0]) + 1.0f, 0.8f)) * (1.0f - fSlow12 * (float)(dsp->iRec5[0])));
			output0[i0] = (FAUSTFLOAT)(fTemp1);
			output1[i0] = (FAUSTFLOAT)(fTemp1);
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fVec0[1] = dsp->fVec0[0];
			dsp->iRec3[1] = dsp->iRec3[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->iRec5[1] = dsp->iRec5[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
