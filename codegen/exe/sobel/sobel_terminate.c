/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sobel_terminate.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 25-Nov-2024 19:25:09
 */

/* Include Files */
#include "sobel_terminate.h"
#include "sobel.h"
#include "sobel_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void sobel_terminate(void)
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
  isInitialized_sobel = false;
}

/*
 * File trailer for sobel_terminate.c
 *
 * [EOF]
 */
