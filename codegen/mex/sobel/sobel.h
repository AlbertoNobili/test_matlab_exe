/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sobel.h
 *
 * Code generation for function 'sobel'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "sobel_types.h"

/* Function Declarations */
void sobel(const emlrtStack *sp, const emxArray_real_T *originalImage, real_T
           threshold, emxArray_uint8_T *edgeImage);

/* End of code generation (sobel.h) */
