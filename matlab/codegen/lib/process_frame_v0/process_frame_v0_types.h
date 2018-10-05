/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * process_frame_v0_types.h
 *
 * Code generation for function 'process_frame_v0'
 *
 */

#ifndef PROCESS_FRAME_V0_TYPES_H
#define PROCESS_FRAME_V0_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_dsp_BiquadFilter_0
#define struct_dsp_BiquadFilter_0

struct dsp_BiquadFilter_0
{
  int S0_isInitialized;
  double W0_FILT_STATES[6144];
  int W1_PreviousNumChannels;
  double P0_ICRTP;
  double P1_RTP1COEFF[9];
  double P2_RTP2COEFF[6];
  double P3_RTP3COEFF[4];
  boolean_T P4_RTP_COEFF3_BOOL[4];
};

#endif                                 /*struct_dsp_BiquadFilter_0*/

typedef struct {
  int isInitialized;
  dsp_BiquadFilter_0 cSFunObject;
} dspcodegen_BiquadFilter;

typedef struct {
  dspcodegen_BiquadFilter h_filter;
  boolean_T h_filter_not_empty;
} process_frame_v0PersistentData;

typedef struct {
  process_frame_v0PersistentData *pd;
} process_frame_v0StackData;

#endif

/* End of code generation (process_frame_v0_types.h) */
