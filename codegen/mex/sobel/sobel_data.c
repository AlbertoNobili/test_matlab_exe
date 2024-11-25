/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sobel_data.c
 *
 * Code generation for function 'sobel_data'
 *
 */

/* Include files */
#include "sobel_data.h"
#include "rt_nonfinite.h"
#include "sobel.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131483U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "sobel",                             /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo h_emlrtRSI = { 477,        /* lineNo */
  "conv2AXPYSameCMP",                  /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\private\\conv2AXPY.m"/* pathName */
};

emlrtRSInfo i_emlrtRSI = { 61,         /* lineNo */
  "xaxpy",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xaxpy.m"/* pathName */
};

emlrtRSInfo j_emlrtRSI = { 60,         /* lineNo */
  "xaxpy",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xaxpy.m"/* pathName */
};

/* End of code generation (sobel_data.c) */
