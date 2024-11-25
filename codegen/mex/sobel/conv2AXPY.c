/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * conv2AXPY.c
 *
 * Code generation for function 'conv2AXPY'
 *
 */

/* Include files */
#include "conv2AXPY.h"
#include "rt_nonfinite.h"
#include "sobel.h"
#include "sobel_emxutil.h"
#include "xaxpy.h"
#include <string.h>

/* Variable Definitions */
static emlrtRTEInfo e_emlrtRTEI = { 441,/* lineNo */
  5,                                   /* colNo */
  "conv2AXPY",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\private\\conv2AXPY.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 429,/* lineNo */
  14,                                  /* colNo */
  "conv2AXPY",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\private\\conv2AXPY.m"/* pName */
};

/* Function Definitions */
void b_conv2AXPYSameCMP(const emlrtStack *sp, const emxArray_real_T *a,
  emxArray_real_T *c)
{
  int32_T ma;
  int32_T na;
  int32_T jcut;
  int32_T ub_loop;
  int32_T j;
  int32_T imax;
  int32_T imin;
  int32_T ic0;
  boolean_T bijNotZero;
  int32_T bij;
  int32_T jbmax;
  int32_T jbmin;
  real_T cj_data[1024];
  int32_T jb;
  int32_T ib;
  static const int8_T b[9] = { 1, 2, 1, 0, 0, 0, -1, -2, -1 };

  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  jmp_buf b_emlrtJBEnviron;
  boolean_T emlrtHadParallelError = false;
  ma = a->size[0];
  na = a->size[1];
  if ((a->size[0] == 0) || (a->size[1] == 0)) {
    ub_loop = c->size[0] * c->size[1];
    c->size[0] = a->size[0];
    c->size[1] = a->size[1];
    emxEnsureCapacity_real_T(sp, c, ub_loop, &e_emlrtRTEI);
    ma = a->size[0] * a->size[1];
    for (ub_loop = 0; ub_loop < ma; ub_loop++) {
      c->data[ub_loop] = 0.0;
    }
  } else {
    jcut = a->size[1] - 1;
    ub_loop = c->size[0] * c->size[1];
    c->size[0] = a->size[0];
    c->size[1] = a->size[1];
    emxEnsureCapacity_real_T(sp, c, ub_loop, &f_emlrtRTEI);
    ub_loop = a->size[1] - 1;
    emlrtEnterParallelRegion(sp, omp_in_parallel());
    emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(imax,imin,ic0,bijNotZero,bij,jbmax,jbmin,cj_data,st,b_emlrtJBEnviron,jb,ib) \
 firstprivate(emlrtHadParallelError)

    {
      if (setjmp(b_emlrtJBEnviron) == 0) {
        st.prev = sp;
        st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
        st.site = NULL;
        emlrtSetJmpBuf(&st, &b_emlrtJBEnviron);
      } else {
        emlrtHadParallelError = true;
      }

#pragma omp for nowait

      for (j = 0; j <= ub_loop; j++) {
        if (emlrtHadParallelError)
          continue;
        if (setjmp(b_emlrtJBEnviron) == 0) {
          if (0 <= ma - 1) {
            memset(&cj_data[0], 0, ma * sizeof(real_T));
          }

          jbmin = (j + 1 <= 1);
          if (j + 1 < jcut) {
            jbmax = 2;
          } else {
            jbmax = na - j;
          }

          for (jb = jbmin; jb <= jbmax; jb++) {
            for (ib = 0; ib < 3; ib++) {
              bij = b[(3 * (2 - jb) - ib) + 2];
              bijNotZero = (bij != 0);
              if (bijNotZero) {
                if (ib < 1) {
                  ic0 = 2;
                  imin = ma - 1;
                } else {
                  ic0 = 1;
                  imin = (ma - ib) + 1;
                }

                imax = ((ic0 + ib) + ((jb + j) - 1) * ma) - 1;
                xaxpy(imin, bij, a, imax, cj_data, ic0);
              } else {
                if (ib < 1) {
                  imin = 2;
                  imax = ma;
                } else {
                  imin = 1;
                  imax = (ma - ib) + 1;
                }

                for (ic0 = imin; ic0 <= imax; ic0++) {
                  cj_data[ic0 - 1] += (real_T)bij * a->data[((ic0 + ib) +
                    a->size[0] * ((j + jb) - 1)) - 2];
                }
              }
            }
          }

          for (imin = 0; imin < ma; imin++) {
            c->data[imin + c->size[0] * j] = cj_data[imin];
          }
        } else {
          emlrtHadParallelError = true;
        }
      }
    }

    emlrtPopJmpBuf(sp, &emlrtJBStack);
    emlrtExitParallelRegion(sp, omp_in_parallel());
  }
}

void conv2AXPYSameCMP(const emlrtStack *sp, const emxArray_real_T *a,
                      emxArray_real_T *c)
{
  int32_T ma;
  int32_T na;
  int32_T jcut;
  int32_T ub_loop;
  int32_T j;
  int32_T imax;
  int32_T imin;
  int32_T ic0;
  boolean_T bijNotZero;
  int32_T bij;
  int32_T jbmax;
  int32_T jbmin;
  real_T cj_data[1024];
  int32_T jb;
  int32_T ib;
  static const int8_T b[9] = { 1, 0, -1, 2, 0, -2, 1, 0, -1 };

  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  jmp_buf b_emlrtJBEnviron;
  boolean_T emlrtHadParallelError = false;
  ma = a->size[0];
  na = a->size[1];
  if ((a->size[0] == 0) || (a->size[1] == 0)) {
    ub_loop = c->size[0] * c->size[1];
    c->size[0] = a->size[0];
    c->size[1] = a->size[1];
    emxEnsureCapacity_real_T(sp, c, ub_loop, &e_emlrtRTEI);
    ma = a->size[0] * a->size[1];
    for (ub_loop = 0; ub_loop < ma; ub_loop++) {
      c->data[ub_loop] = 0.0;
    }
  } else {
    jcut = a->size[1] - 1;
    ub_loop = c->size[0] * c->size[1];
    c->size[0] = a->size[0];
    c->size[1] = a->size[1];
    emxEnsureCapacity_real_T(sp, c, ub_loop, &f_emlrtRTEI);
    ub_loop = a->size[1] - 1;
    emlrtEnterParallelRegion(sp, omp_in_parallel());
    emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(imax,imin,ic0,bijNotZero,bij,jbmax,jbmin,cj_data,st,b_emlrtJBEnviron,jb,ib) \
 firstprivate(emlrtHadParallelError)

    {
      if (setjmp(b_emlrtJBEnviron) == 0) {
        st.prev = sp;
        st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
        st.site = NULL;
        emlrtSetJmpBuf(&st, &b_emlrtJBEnviron);
      } else {
        emlrtHadParallelError = true;
      }

#pragma omp for nowait

      for (j = 0; j <= ub_loop; j++) {
        if (emlrtHadParallelError)
          continue;
        if (setjmp(b_emlrtJBEnviron) == 0) {
          if (0 <= ma - 1) {
            memset(&cj_data[0], 0, ma * sizeof(real_T));
          }

          jbmin = (j + 1 <= 1);
          if (j + 1 < jcut) {
            jbmax = 2;
          } else {
            jbmax = na - j;
          }

          for (jb = jbmin; jb <= jbmax; jb++) {
            for (ib = 0; ib < 3; ib++) {
              bij = b[(3 * (2 - jb) - ib) + 2];
              bijNotZero = (bij != 0);
              if (bijNotZero) {
                if (ib < 1) {
                  ic0 = 2;
                  imin = ma - 1;
                } else {
                  ic0 = 1;
                  imin = (ma - ib) + 1;
                }

                imax = ((ic0 + ib) + ((jb + j) - 1) * ma) - 1;
                xaxpy(imin, bij, a, imax, cj_data, ic0);
              } else {
                if (ib < 1) {
                  imin = 2;
                  imax = ma;
                } else {
                  imin = 1;
                  imax = (ma - ib) + 1;
                }

                for (ic0 = imin; ic0 <= imax; ic0++) {
                  cj_data[ic0 - 1] += (real_T)bij * a->data[((ic0 + ib) +
                    a->size[0] * ((j + jb) - 1)) - 2];
                }
              }
            }
          }

          for (imin = 0; imin < ma; imin++) {
            c->data[imin + c->size[0] * j] = cj_data[imin];
          }
        } else {
          emlrtHadParallelError = true;
        }
      }
    }

    emlrtPopJmpBuf(sp, &emlrtJBStack);
    emlrtExitParallelRegion(sp, omp_in_parallel());
  }
}

/* End of code generation (conv2AXPY.c) */
