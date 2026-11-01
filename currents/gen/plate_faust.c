/* ------------------------------------------------------------
name: "plate"
Code generated with Faust 2.83.1 (https://faust.grame.fr)
Compilation options: -lang c -fpga-mem-th 4 -ct 1 -cn rc_plate -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __rc_plate_H__
#define  __rc_plate_H__

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
#define FAUSTCLASS rc_plate
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif
static inline int max_i(int a, int b) { return (a > b) ? a : b; }
static inline int min_i(int a, int b) { return (a < b) ? a : b; }

typedef struct {
	FAUSTFLOAT fHslider0;
	int IOTA0;
	float fVec0[256];
	float fRec6[2];
	float fVec1[128];
	float fRec4[2];
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider2;
	float fConst2;
	FAUSTFLOAT fHslider3;
	float fConst3;
	float fRec9[2];
	float fVec2[2];
	float fRec8[2];
	float fVec3[2];
	float fRec10[2];
	float fVec4[2];
	float fRec11[2];
	float fVec5[2];
	float fRec12[2];
	float fRec0[2048];
	float fRec1[2048];
	float fRec2[2048];
	float fRec3[2048];
} rc_plate;

rc_plate* newrc_plate() { 
	rc_plate* dsp = (rc_plate*)calloc(1, sizeof(rc_plate));
	return dsp;
}

void deleterc_plate(rc_plate* dsp) { 
	free(dsp);
}

void metadatarc_plate(MetaGlue* m) { 
	m->declare(m->metaInterface, "basics.lib/name", "Faust Basic Element Library");
	m->declare(m->metaInterface, "basics.lib/version", "1.22.0");
	m->declare(m->metaInterface, "compile_options", "-lang c -fpga-mem-th 4 -ct 1 -cn rc_plate -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
	m->declare(m->metaInterface, "delays.lib/name", "Faust Delay Library");
	m->declare(m->metaInterface, "delays.lib/version", "1.2.0");
	m->declare(m->metaInterface, "filename", "plate.dsp");
	m->declare(m->metaInterface, "filters.lib/allpass_comb:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/allpass_comb:license", "MIT-style STK-4.3 license");
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
	m->declare(m->metaInterface, "name", "plate");
	m->declare(m->metaInterface, "platform.lib/name", "Generic Platform Library");
	m->declare(m->metaInterface, "platform.lib/version", "1.3.0");
	m->declare(m->metaInterface, "routes.lib/hadamard:author", "Remy Muller, revised by Romain Michon");
	m->declare(m->metaInterface, "routes.lib/name", "Faust Signal Routing Library");
	m->declare(m->metaInterface, "routes.lib/version", "1.2.0");
	m->declare(m->metaInterface, "signals.lib/name", "Faust Signal Routing Library");
	m->declare(m->metaInterface, "signals.lib/version", "1.6.0");
}

int getSampleRaterc_plate(rc_plate* RESTRICT dsp) {
	return dsp->fSampleRate;
}

int getNumInputsrc_plate(rc_plate* RESTRICT dsp) {
	return 2;
}
int getNumOutputsrc_plate(rc_plate* RESTRICT dsp) {
	return 2;
}

void classInitrc_plate(int sample_rate) {
}

void instanceResetUserInterfacerc_plate(rc_plate* dsp) {
	dsp->fHslider0 = (FAUSTFLOAT)(0.3f);
	dsp->fHslider1 = (FAUSTFLOAT)(0.8f);
	dsp->fHslider2 = (FAUSTFLOAT)(0.4f);
	dsp->fHslider3 = (FAUSTFLOAT)(0.8f);
}

void instanceClearrc_plate(rc_plate* dsp) {
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 256; l0 = l0 + 1) {
			dsp->fVec0[l0] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 2; l1 = l1 + 1) {
			dsp->fRec6[l1] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 128; l2 = l2 + 1) {
			dsp->fVec1[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->fRec4[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->fRec9[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->fVec2[l5] = 0.0f;
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
		for (l7 = 0; l7 < 2; l7 = l7 + 1) {
			dsp->fVec3[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->fRec10[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1) {
			dsp->fVec4[l9] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1) {
			dsp->fRec11[l10] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->fVec5[l11] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 2; l12 = l12 + 1) {
			dsp->fRec12[l12] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 2048; l13 = l13 + 1) {
			dsp->fRec0[l13] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 2048; l14 = l14 + 1) {
			dsp->fRec1[l14] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 2048; l15 = l15 + 1) {
			dsp->fRec2[l15] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; l16 < 2048; l16 = l16 + 1) {
			dsp->fRec3[l16] = 0.0f;
		}
	}
}

void instanceConstantsrc_plate(rc_plate* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 3.1415927f / dsp->fConst0;
	dsp->fConst2 = 44.1f / dsp->fConst0;
	dsp->fConst3 = 1.0f - dsp->fConst2;
}
	
void instanceInitrc_plate(rc_plate* dsp, int sample_rate) {
	instanceConstantsrc_plate(dsp, sample_rate);
	instanceResetUserInterfacerc_plate(dsp);
	instanceClearrc_plate(dsp);
}

void initrc_plate(rc_plate* dsp, int sample_rate) {
	classInitrc_plate(sample_rate);
	instanceInitrc_plate(dsp, sample_rate);
}

void buildUserInterfacerc_plate(rc_plate* dsp, UIGlue* ui_interface) {
	ui_interface->openVerticalBox(ui_interface->uiInterface, "plate");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "damp", &dsp->fHslider2, (FAUSTFLOAT)0.4f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "decay", &dsp->fHslider1, (FAUSTFLOAT)0.8f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)0.97f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "mix", &dsp->fHslider0, (FAUSTFLOAT)0.3f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "size", &dsp->fHslider3, (FAUSTFLOAT)0.8f, (FAUSTFLOAT)0.2f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.01f);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computerc_plate(rc_plate* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* input0 = inputs[0];
	FAUSTFLOAT* input1 = inputs[1];
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	float fSlow0 = (float)(dsp->fHslider0);
	float fSlow1 = 0.5f * (float)(dsp->fHslider1);
	float fSlow2 = 1.0f / tanf(dsp->fConst1 * (1.4e+04f * (1.0f - (float)(dsp->fHslider2)) + 1.5e+03f));
	float fSlow3 = 1.0f / (fSlow2 + 1.0f);
	float fSlow4 = 1.0f - fSlow2;
	float fSlow5 = dsp->fConst2 * (float)(dsp->fHslider3);
	float fSlow6 = 1.0f - fSlow0;
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = (float)(input0[i0]);
			float fTemp1 = (float)(input1[i0]);
			float fTemp2 = 0.5f * (fTemp0 + fTemp1) - 0.6f * dsp->fRec6[1];
			dsp->fVec0[dsp->IOTA0 & 255] = fTemp2;
			dsp->fRec6[0] = dsp->fVec0[(dsp->IOTA0 - 141) & 255];
			float fRec7 = 0.6f * fTemp2;
			float fTemp3 = fRec7 + dsp->fRec6[1] - 0.6f * dsp->fRec4[1];
			dsp->fVec1[dsp->IOTA0 & 127] = fTemp3;
			dsp->fRec4[0] = dsp->fVec1[(dsp->IOTA0 - 106) & 127];
			float fRec5 = 0.6f * fTemp3;
			dsp->fRec9[0] = fSlow5 + dsp->fConst3 * dsp->fRec9[1];
			float fTemp4 = 1381.0f * dsp->fRec9[0];
			int iTemp5 = (int)(fTemp4);
			float fTemp6 = floorf(fTemp4);
			float fTemp7 = dsp->fRec0[(dsp->IOTA0 - (min_i(2001, max_i(0, iTemp5)) + 1)) & 2047] * (fTemp6 + (1.0f - fTemp4)) + (fTemp4 - fTemp6) * dsp->fRec0[(dsp->IOTA0 - (min_i(2001, max_i(0, iTemp5 + 1)) + 1)) & 2047];
			dsp->fVec2[0] = fTemp7;
			dsp->fRec8[0] = -(fSlow3 * (fSlow4 * dsp->fRec8[1] - (fTemp7 + dsp->fVec2[1])));
			float fTemp8 = 1931.0f * dsp->fRec9[0];
			int iTemp9 = (int)(fTemp8);
			float fTemp10 = floorf(fTemp8);
			float fTemp11 = dsp->fRec2[(dsp->IOTA0 - (min_i(2001, max_i(0, iTemp9)) + 1)) & 2047] * (fTemp10 + (1.0f - fTemp8)) + (fTemp8 - fTemp10) * dsp->fRec2[(dsp->IOTA0 - (min_i(2001, max_i(0, iTemp9 + 1)) + 1)) & 2047];
			dsp->fVec3[0] = fTemp11;
			dsp->fRec10[0] = -(fSlow3 * (fSlow4 * dsp->fRec10[1] - (fTemp11 + dsp->fVec3[1])));
			float fTemp12 = dsp->fRec8[0] + dsp->fRec10[0];
			float fTemp13 = 1637.0f * dsp->fRec9[0];
			int iTemp14 = (int)(fTemp13);
			float fTemp15 = floorf(fTemp13);
			float fTemp16 = dsp->fRec1[(dsp->IOTA0 - (min_i(2001, max_i(0, iTemp14)) + 1)) & 2047] * (fTemp15 + (1.0f - fTemp13)) + (fTemp13 - fTemp15) * dsp->fRec1[(dsp->IOTA0 - (min_i(2001, max_i(0, iTemp14 + 1)) + 1)) & 2047];
			dsp->fVec4[0] = fTemp16;
			dsp->fRec11[0] = -(fSlow3 * (fSlow4 * dsp->fRec11[1] - (fTemp16 + dsp->fVec4[1])));
			float fTemp17 = 1063.0f * dsp->fRec9[0];
			int iTemp18 = (int)(fTemp17);
			float fTemp19 = floorf(fTemp17);
			float fTemp20 = dsp->fRec3[(dsp->IOTA0 - (min_i(2001, max_i(0, iTemp18)) + 1)) & 2047] * (fTemp19 + (1.0f - fTemp17)) + (fTemp17 - fTemp19) * dsp->fRec3[(dsp->IOTA0 - (min_i(2001, max_i(0, iTemp18 + 1)) + 1)) & 2047];
			dsp->fVec5[0] = fTemp20;
			dsp->fRec12[0] = -(fSlow3 * (fSlow4 * dsp->fRec12[1] - (fTemp20 + dsp->fVec5[1])));
			float fTemp21 = dsp->fRec11[0] + dsp->fRec12[0];
			dsp->fRec0[dsp->IOTA0 & 2047] = dsp->fRec4[1] + fRec5 + fSlow1 * (fTemp12 + fTemp21);
			float fTemp22 = fRec5 + dsp->fRec4[1];
			dsp->fRec1[dsp->IOTA0 & 2047] = fTemp22 + fSlow1 * (fTemp12 - fTemp21);
			float fTemp23 = dsp->fRec8[0] - dsp->fRec10[0];
			float fTemp24 = dsp->fRec11[0] - dsp->fRec12[0];
			dsp->fRec2[dsp->IOTA0 & 2047] = fTemp22 + fSlow1 * (fTemp23 + fTemp24);
			dsp->fRec3[dsp->IOTA0 & 2047] = fTemp22 + fSlow1 * (fTemp23 - fTemp24);
			output0[i0] = (FAUSTFLOAT)(fSlow0 * (dsp->fRec0[dsp->IOTA0 & 2047] + dsp->fRec2[dsp->IOTA0 & 2047]) + fSlow6 * fTemp0);
			output1[i0] = (FAUSTFLOAT)(fSlow0 * (dsp->fRec1[dsp->IOTA0 & 2047] + dsp->fRec3[dsp->IOTA0 & 2047]) + fSlow6 * fTemp1);
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fRec9[1] = dsp->fRec9[0];
			dsp->fVec2[1] = dsp->fVec2[0];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fVec4[1] = dsp->fVec4[0];
			dsp->fRec11[1] = dsp->fRec11[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec12[1] = dsp->fRec12[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
