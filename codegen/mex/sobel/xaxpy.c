/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xaxpy.c
 *
 * Code generation for function 'xaxpy'
 *
 */

/* Include files */
#include "xaxpy.h"
#include "blas.h"
#include "rt_nonfinite.h"
#include "sobel.h"

/* Function Definitions */
void xaxpy(int32_T n, real_T a, const emxArray_real_T *x, int32_T ix0, real_T
           y_data[], int32_T iy0)
{
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  if (n >= 1) {
    n_t = (ptrdiff_t)n;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    daxpy(&n_t, &a, &x->data[ix0 - 1], &incx_t, &y_data[iy0 - 1], &incy_t);
  }
}

/* End of code generation (xaxpy.c) */
