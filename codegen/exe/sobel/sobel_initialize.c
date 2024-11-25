/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sobel_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 25-Nov-2024 19:25:09
 */

/* Include Files */
#include "sobel_initialize.h"
#include "sobel.h"
#include "sobel_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void sobel_initialize(void)
{
  omp_init_nest_lock(&emlrtNestLockGlobal);
  isInitialized_sobel = true;
}

/*
 * File trailer for sobel_initialize.c
 *
 * [EOF]
 */
