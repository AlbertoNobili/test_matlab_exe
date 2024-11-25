/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sobel.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 25-Nov-2024 19:14:18
 */

/* Include Files */
#include "sobel.h"
#include "conv2AXPY.h"
#include "sobel_data.h"
#include "sobel_emxutil.h"
#include "sobel_initialize.h"
#include <math.h>

/* Function Definitions */

/*
 * edgeImage = sobel(originalImage, threshold)
 *  Sobel edge detection. Given a normalized image (with double values)
 *  return an image where the edges are detected w.r.t. threshold value.
 * Arguments    : const emxArray_real_T *originalImage
 *                double threshold
 *                emxArray_uint8_T *edgeImage
 * Return Type  : void
 */
void sobel(const emxArray_real_T *originalImage, double threshold,
           emxArray_uint8_T *edgeImage)
{
  emxArray_real_T *H;
  emxArray_real_T *V;
  int nx;
  int k;
  if (isInitialized_sobel == false) {
    sobel_initialize();
  }

  emxInit_real_T(&H, 2);
  emxInit_real_T(&V, 2);
  conv2AXPYSameCMP(originalImage, H);
  b_conv2AXPYSameCMP(originalImage, V);
  nx = H->size[0] * H->size[1];
  for (k = 0; k < nx; k++) {
    H->data[k] = H->data[k] * H->data[k] + V->data[k] * V->data[k];
  }

  emxFree_real_T(&V);
  nx = H->size[0] * H->size[1];
  for (k = 0; k < nx; k++) {
    H->data[k] = sqrt(H->data[k]);
  }

  k = edgeImage->size[0] * edgeImage->size[1];
  edgeImage->size[0] = H->size[0];
  edgeImage->size[1] = H->size[1];
  emxEnsureCapacity_uint8_T(edgeImage, k);
  nx = H->size[0] * H->size[1];
  for (k = 0; k < nx; k++) {
    edgeImage->data[k] = (unsigned char)((H->data[k] > threshold) * 255U);
  }

  emxFree_real_T(&H);
}

/*
 * File trailer for sobel.c
 *
 * [EOF]
 */
