/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sobel.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 25-Nov-2024 19:14:18
 */

#ifndef SOBEL_H
#define SOBEL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "sobel_types.h"

/* Function Declarations */
extern void sobel(const emxArray_real_T *originalImage, double threshold,
                  emxArray_uint8_T *edgeImage);

#endif

/*
 * File trailer for sobel.h
 *
 * [EOF]
 */
