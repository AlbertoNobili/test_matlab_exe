/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sobel.c
 *
 * Code generation for function 'sobel'
 *
 */

/* Include files */
#include "sobel.h"
#include "conv2AXPY.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sobel_emxutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 12,    /* lineNo */
  "sobel",                             /* fcnName */
  "C:\\Users\\alber\\Desktop\\test_matlab_exe\\sobel.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 13,  /* lineNo */
  "sobel",                             /* fcnName */
  "C:\\Users\\alber\\Desktop\\test_matlab_exe\\sobel.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 14,  /* lineNo */
  "sobel",                             /* fcnName */
  "C:\\Users\\alber\\Desktop\\test_matlab_exe\\sobel.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 57,  /* lineNo */
  "conv2",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\conv2.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 74,  /* lineNo */
  "conv2NonSeparable",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\conv2.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 94,  /* lineNo */
  "conv2",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\conv2.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 27,  /* lineNo */
  "conv2AXPY",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\private\\conv2AXPY.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 13,  /* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  14,                                  /* lineNo */
  10,                                  /* colNo */
  "sobel",                             /* fName */
  "C:\\Users\\alber\\Desktop\\test_matlab_exe\\sobel.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 15,/* lineNo */
  1,                                   /* colNo */
  "sobel",                             /* fName */
  "C:\\Users\\alber\\Desktop\\test_matlab_exe\\sobel.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 12,/* lineNo */
  1,                                   /* colNo */
  "sobel",                             /* fName */
  "C:\\Users\\alber\\Desktop\\test_matlab_exe\\sobel.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "sobel",                             /* fName */
  "C:\\Users\\alber\\Desktop\\test_matlab_exe\\sobel.m"/* pName */
};

/* Function Definitions */
void sobel(const emlrtStack *sp, const emxArray_real_T *originalImage, real_T
           threshold, emxArray_uint8_T *edgeImage)
{
  emxArray_real_T *H;
  emxArray_real_T *V;
  int32_T nx;
  int32_T i;
  boolean_T p;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &H, 2, &c_emlrtRTEI, true);
  emxInit_real_T(sp, &V, 2, &d_emlrtRTEI, true);

  /*  edgeImage = sobel(originalImage, threshold) */
  /*  Sobel edge detection. Given a normalized image (with double values) */
  /*  return an image where the edges are detected w.r.t. threshold value. */
  st.site = &emlrtRSI;
  b_st.site = &d_emlrtRSI;
  c_st.site = &e_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  e_st.site = &g_emlrtRSI;
  conv2AXPYSameCMP(&e_st, originalImage, H);
  st.site = &b_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  c_st.site = &e_emlrtRSI;
  d_st.site = &f_emlrtRSI;
  e_st.site = &g_emlrtRSI;
  b_conv2AXPYSameCMP(&e_st, originalImage, V);
  nx = H->size[0] * H->size[1];
  for (i = 0; i < nx; i++) {
    H->data[i] *= H->data[i];
  }

  nx = V->size[0] * V->size[1];
  for (i = 0; i < nx; i++) {
    V->data[i] *= V->data[i];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])H->size, *(int32_T (*)[2])V->size,
    &emlrtECI, sp);
  st.site = &c_emlrtRSI;
  nx = H->size[0] * H->size[1];
  for (i = 0; i < nx; i++) {
    H->data[i] += V->data[i];
  }

  emxFree_real_T(&V);
  p = false;
  i = H->size[0] * H->size[1];
  for (k = 0; k < i; k++) {
    if (p || (H->data[k] < 0.0)) {
      p = true;
    }
  }

  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  nx = H->size[0] * H->size[1];
  for (k = 0; k < nx; k++) {
    H->data[k] = muDoubleScalarSqrt(H->data[k]);
  }

  i = edgeImage->size[0] * edgeImage->size[1];
  edgeImage->size[0] = H->size[0];
  edgeImage->size[1] = H->size[1];
  emxEnsureCapacity_uint8_T(sp, edgeImage, i, &b_emlrtRTEI);
  nx = H->size[0] * H->size[1];
  for (i = 0; i < nx; i++) {
    edgeImage->data[i] = (uint8_T)((H->data[i] > threshold) * 255U);
  }

  emxFree_real_T(&H);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sobel.c) */
