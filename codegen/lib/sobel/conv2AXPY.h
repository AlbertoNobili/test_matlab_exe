/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: conv2AXPY.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 25-Nov-2024 19:14:18
 */

#ifndef CONV2AXPY_H
#define CONV2AXPY_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "sobel_types.h"

/* Function Declarations */
extern void b_conv2AXPYSameCMP(const emxArray_real_T *a, emxArray_real_T *c);
extern void conv2AXPYSameCMP(const emxArray_real_T *a, emxArray_real_T *c);

#endif

/*
 * File trailer for conv2AXPY.h
 *
 * [EOF]
 */
