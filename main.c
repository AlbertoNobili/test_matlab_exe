/*
 * File: main.c
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include <stdio.h>
#include "main.h"
#include "sobel.h"
#include "sobel_emxAPI.h"
#include "sobel_terminate.h"
#include "sobel_types.h"

/* Function Declarations */
static emxArray_real_T *argInit_d1024xd1024_real_T(FILE *fd);
static void saveImage(emxArray_uint8_T *edgeImage);
static double argInit_real_T(void);
static void main_sobel(FILE *fd, double threshold);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_d1024xd1024_real_T(FILE *fd)
{
  emxArray_real_T *result;
  double *result_data;
  int idx0 = 484;
  int idx1 = 648;
  /* Set the size of the array.
  Change this size to the value that the application requires. */
  double element;
  result = emxCreate_real_T(484, 648);
  result_data = result->data;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
  Change this value to the value that the application requires. */
      fread(&element, 1, sizeof(element), fd);
      result_data[idx0 + result->size[0] * idx1] = element;
    }
  }
  return result;
}

static void saveImage(emxArray_uint8_T *edgeImage)
{
  int idx0;
  int idx1;
  uint8_T element;
 
  FILE *fd = fopen("edge.bin", "wb");
 if (fd == NULL) {
   exit(-1);
 }
  /* Loop over the array to save each element. */
  for (idx0 = 0; idx0 < edgeImage->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < edgeImage->size[1U]; idx1++) {
      element = edgeImage->data[idx0 + edgeImage->size[0] * idx1];
      fwrite(&element, 1, sizeof(element), fd);
    }
  }
  fclose(fd);
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_sobel(FILE *fd, double threshold)
{
  emxArray_real_T *originalImage;
  emxArray_uint8_T *edgeImage;
  emxInitArray_uint8_T(&edgeImage, 2);
  /* Initialize function 'sobel' input arguments. */
  /* Initialize function input argument 'originalImage'. */
  originalImage = argInit_d1024xd1024_real_T(fd);
  /* Call the entry-point 'sobel'. */
  sobel(originalImage, threshold, edgeImage);
  saveImage(edgeImage);
    
  emxDestroyArray_uint8_T(edgeImage);
  emxDestroyArray_real_T(originalImage);
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  const char *filename;
  double threshold;
  FILE *fd;
  if (argc != 3) {
      printf("Expected 2 arguments: filename and threshold\n");
      exit(-1);
  }
  filename = argv[1];
  threshold = atof(argv[2]);
  
  fd = fopen(filename, "rb");
  if (fd == NULL) {
   exit(-1);
  }

  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_sobel(fd, threshold);
    fclose(fd);
  /* Terminate the application.
You do not need to do this more than one time. */
  sobel_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */