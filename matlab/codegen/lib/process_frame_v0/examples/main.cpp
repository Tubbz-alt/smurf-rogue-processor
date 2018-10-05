/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, educational organizations only. Not for
 * government, commercial, or other organizational use.
 *
 * main.cpp
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include files */
#include "process_frame_v0.h"
#include "main.h"

/* Variable Definitions */
static process_frame_v0StackData process_frame_v0StackDataGlobal;
static process_frame_v0PersistentData c_process_frame_v0PersistentDat;

/* Function Declarations */
static void argInit_1x1024_sfix32_En28(int result[1024]);
static boolean_T argInit_boolean_T();
static int argInit_sfix32_En28();
static void main_process_frame_v0();

/* Function Definitions */
static void argInit_1x1024_sfix32_En28(int result[1024])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 1024; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_sfix32_En28();
  }
}

static boolean_T argInit_boolean_T()
{
  return false;
}

static int argInit_sfix32_En28()
{
  return 0;
}

static void main_process_frame_v0()
{
  int iv0[1024];
  int frame_out[1024];

  /* Initialize function 'process_frame_v0' input arguments. */
  /* Initialize function input argument 'frame_in'. */
  /* Call the entry-point 'process_frame_v0'. */
  argInit_1x1024_sfix32_En28(iv0);
  process_frame_v0(&process_frame_v0StackDataGlobal, iv0, argInit_boolean_T(),
                   frame_out);
}

int main(int, const char * const [])
{
  /* Initialize reentrant memory structures */
  process_frame_v0StackDataGlobal.pd = &c_process_frame_v0PersistentDat;

  /* Initialize the application.
     You do not need to do this more than one time. */
  process_frame_v0_initialize(&process_frame_v0StackDataGlobal);

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_process_frame_v0();

  /* Terminate the application.
     You do not need to do this more than one time. */
  process_frame_v0_terminate();
  return 0;
}

/* End of code generation (main.cpp) */
