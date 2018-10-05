/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * _coder_process_frame_v0_api.h
 *
 * Code generation for function '_coder_process_frame_v0_api'
 *
 */

#ifndef _CODER_PROCESS_FRAME_V0_API_H
#define _CODER_PROCESS_FRAME_V0_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_process_frame_v0_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void process_frame_v0(int32_T frame_in[1024], boolean_T reset, int32_T
  frame_out[1024]);
extern void process_frame_v0_api(const mxArray * const prhs[5], const mxArray
  *plhs[1]);
extern void process_frame_v0_atexit(void);
extern void process_frame_v0_initialize(void);
extern void process_frame_v0_terminate(void);
extern void process_frame_v0_xil_terminate(void);

#endif

/* End of code generation (_coder_process_frame_v0_api.h) */
