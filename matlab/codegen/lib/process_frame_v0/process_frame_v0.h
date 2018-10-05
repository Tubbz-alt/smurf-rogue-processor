/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * process_frame_v0.h
 *
 * Code generation for function 'process_frame_v0'
 *
 */

#ifndef PROCESS_FRAME_V0_H
#define PROCESS_FRAME_V0_H

/* Include files */
#include <cmath>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "process_frame_v0_types.h"

/* Function Declarations */
extern void process_frame_v0(process_frame_v0StackData *SD, const int frame_in
  [1024], boolean_T reset, int frame_out[1024]);
extern void process_frame_v0_initialize(process_frame_v0StackData *SD);
extern void process_frame_v0_terminate();

#endif

/* End of code generation (process_frame_v0.h) */
