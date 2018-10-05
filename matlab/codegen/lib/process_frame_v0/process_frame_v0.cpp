/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * process_frame_v0.cpp
 *
 * Code generation for function 'process_frame_v0'
 *
 */

/* Include files */
#include "process_frame_v0.h"

/* Function Declarations */
static dspcodegen_BiquadFilter *BiquadFilter_BiquadFilter
  (dspcodegen_BiquadFilter *obj);
static void SystemCore_reset(dspcodegen_BiquadFilter *obj);
static void SystemCore_step(dspcodegen_BiquadFilter *obj, const double
  varargin_1[1024], double varargout_1[1024]);
static void b_BiquadFilter_BiquadFilter(dspcodegen_BiquadFilter **obj);
static void process_frame_v0_init(process_frame_v0StackData *SD);

/* Function Definitions */
static dspcodegen_BiquadFilter *BiquadFilter_BiquadFilter
  (dspcodegen_BiquadFilter *obj)
{
  dspcodegen_BiquadFilter *b_obj;
  b_obj = obj;
  b_BiquadFilter_BiquadFilter(&b_obj);
  return b_obj;
}

static void SystemCore_reset(dspcodegen_BiquadFilter *obj)
{
  int i1;
  if (obj->isInitialized == 1) {
    /* System object Initialization function: dsp.BiquadFilter */
    for (i1 = 0; i1 < 6144; i1++) {
      obj->cSFunObject.W0_FILT_STATES[i1] = obj->cSFunObject.P0_ICRTP;
    }
  }
}

static void SystemCore_step(dspcodegen_BiquadFilter *obj, const double
  varargin_1[1024], double varargout_1[1024])
{
  dsp_BiquadFilter_0 *b_obj;
  int ioIdx;
  int k;
  int memOffset;
  double stageIn;
  double numAccum;
  double stageOut;
  if (obj->isInitialized != 1) {
    obj->isInitialized = 1;

    /* System object Initialization function: dsp.BiquadFilter */
    for (ioIdx = 0; ioIdx < 6144; ioIdx++) {
      obj->cSFunObject.W0_FILT_STATES[ioIdx] = obj->cSFunObject.P0_ICRTP;
    }
  }

  b_obj = &obj->cSFunObject;

  /* System object Outputs function: dsp.BiquadFilter */
  ioIdx = 0;
  for (k = 0; k < 1024; k++) {
    memOffset = 6 * k;
    stageIn = b_obj->P3_RTP3COEFF[0U] * varargin_1[ioIdx];
    numAccum = b_obj->W0_FILT_STATES[memOffset];
    numAccum += b_obj->P1_RTP1COEFF[0] * stageIn;
    stageOut = numAccum;
    numAccum = b_obj->W0_FILT_STATES[memOffset + 1];
    numAccum += b_obj->P1_RTP1COEFF[1] * stageIn;
    numAccum -= b_obj->P2_RTP2COEFF[0] * stageOut;
    b_obj->W0_FILT_STATES[memOffset] = numAccum;
    numAccum = b_obj->P1_RTP1COEFF[2] * stageIn;
    numAccum -= b_obj->P2_RTP2COEFF[1] * stageOut;
    b_obj->W0_FILT_STATES[memOffset + 1] = numAccum;
    stageIn = b_obj->P3_RTP3COEFF[1U] * stageOut;
    numAccum = b_obj->W0_FILT_STATES[memOffset + 2];
    numAccum += b_obj->P1_RTP1COEFF[3] * stageIn;
    stageOut = numAccum;
    numAccum = b_obj->W0_FILT_STATES[memOffset + 3];
    numAccum += b_obj->P1_RTP1COEFF[4] * stageIn;
    numAccum -= b_obj->P2_RTP2COEFF[2] * stageOut;
    b_obj->W0_FILT_STATES[memOffset + 2] = numAccum;
    numAccum = b_obj->P1_RTP1COEFF[5] * stageIn;
    numAccum -= b_obj->P2_RTP2COEFF[3] * stageOut;
    b_obj->W0_FILT_STATES[memOffset + 3] = numAccum;
    stageIn = b_obj->P3_RTP3COEFF[2U] * stageOut;
    numAccum = b_obj->W0_FILT_STATES[memOffset + 4];
    numAccum += b_obj->P1_RTP1COEFF[6] * stageIn;
    stageOut = numAccum;
    numAccum = b_obj->W0_FILT_STATES[memOffset + 5];
    numAccum += b_obj->P1_RTP1COEFF[7] * stageIn;
    numAccum -= b_obj->P2_RTP2COEFF[4] * stageOut;
    b_obj->W0_FILT_STATES[memOffset + 4] = numAccum;
    numAccum = b_obj->P1_RTP1COEFF[8] * stageIn;
    numAccum -= b_obj->P2_RTP2COEFF[5] * stageOut;
    b_obj->W0_FILT_STATES[memOffset + 5] = numAccum;
    varargout_1[ioIdx] = stageOut;
    ioIdx++;
  }
}

static void b_BiquadFilter_BiquadFilter(dspcodegen_BiquadFilter **obj)
{
  int i;
  static const signed char iv1[9] = { 1, 2, 1, 1, 2, 1, 1, 2, 1 };

  static const double dv0[6] = { -1.9103797356621315, 0.92963038890235361,
    -1.8006450571175834, 0.81878992798079742, -1.742845764790887,
    0.76040819954815841 };

  static const double dv1[4] = { 0.004812663310055503, 0.0045362177158035106,
    0.0043906086893177624, 0.0 };

  static const boolean_T bv0[4] = { true, true, true, false };

  (*obj)->isInitialized = 0;

  /* System object Constructor function: dsp.BiquadFilter */
  (*obj)->cSFunObject.P0_ICRTP = 0.0;
  for (i = 0; i < 9; i++) {
    (*obj)->cSFunObject.P1_RTP1COEFF[i] = iv1[i];
  }

  for (i = 0; i < 6; i++) {
    (*obj)->cSFunObject.P2_RTP2COEFF[i] = dv0[i];
  }

  for (i = 0; i < 4; i++) {
    (*obj)->cSFunObject.P3_RTP3COEFF[i] = dv1[i];
  }

  for (i = 0; i < 4; i++) {
    (*obj)->cSFunObject.P4_RTP_COEFF3_BOOL[i] = bv0[i];
  }
}

static void process_frame_v0_init(process_frame_v0StackData *SD)
{
  SD->pd->h_filter_not_empty = false;
}

void process_frame_v0(process_frame_v0StackData *SD, const int frame_in[1024],
                      boolean_T reset, int frame_out[1024])
{
  int i0;
  double b_frame_in[1024];
  double varargin_1[1024];
  double u;
  double v;
  if (!SD->pd->h_filter_not_empty) {
    BiquadFilter_BiquadFilter(&SD->pd->h_filter);
    SD->pd->h_filter_not_empty = true;
  }

  if (reset) {
    SystemCore_reset(&SD->pd->h_filter);
    memcpy(&frame_out[0], &frame_in[0], sizeof(int) << 10);
  } else {
    /*  convert to floating */
    /*  step filter, output quantized */
    for (i0 = 0; i0 < 1024; i0++) {
      b_frame_in[i0] = (double)frame_in[i0] * 3.7252902984619141E-9;
    }

    SystemCore_step(&SD->pd->h_filter, b_frame_in, varargin_1);
    for (i0 = 0; i0 < 1024; i0++) {
      u = varargin_1[i0] * 2.68435456E+8;
      v = std::abs(u);
      if (v < 4.503599627370496E+15) {
        if (v >= 0.5) {
          u = std::floor(u + 0.5);
        } else {
          u = 0.0;
        }
      }

      u = std::fmod(u, 4.294967296E+9);
      if (u < 0.0) {
        frame_out[i0] = -(int)(unsigned int)-u;
      } else {
        frame_out[i0] = (int)(unsigned int)u;
      }
    }
  }
}

void process_frame_v0_initialize(process_frame_v0StackData *SD)
{
  process_frame_v0_init(SD);
}

void process_frame_v0_terminate()
{
  /* (no terminate code required) */
}

/* End of code generation (process_frame_v0.cpp) */
