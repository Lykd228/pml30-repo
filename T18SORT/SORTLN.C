#include <stdlib.h>
#include <string.h>
#include "sort.h"

static void MergeSortRec( float *mas, float *B, int size )
{
  int M, i, j, k;

  if (size < 2)
    return;
  M = size / 2;
  MergeSortRec(mas, B, M);
  MergeSortRec(mas + M, B, size - M);

  i = 0;
  j = M;
  for (k = 0; k < size; k++)
  {
    if (j >= size || i < M && mas[i] < mas[j])
      B[k] = mas[i++];
    else
      B[k] = mas[j++];
  }
  memcpy(mas, B, sizeof(float) * size);
}

void MergeSort( float *mas, int size )
{
  float *B;

  if (size < 2)
    return;
  B = malloc(sizeof(float) * size);
  MergeSortRec(mas, B, size);
  free(B);
}

void QuickSort( float *mas, int size )
{
  int b, e;
  float x;

  if (size < 2)
    return;

  x = mas[size / 2];
  b = 0;
  e = size - 1;
  while (b <= e)
  {
    while (mas[b] < x)
      b++;
    while (mas[e] > x)
      e--;
    if (b <= e)
    {
      if (b != e)
        Swap(&mas[b], &mas[e]);
      b++;
      e--;
    }
  }
  QuickSort(mas, e + 1);
  QuickSort(mas + b, size - b);
}

static void HeapCorrection( float *A, int N, int i )
{
  while (1)
  {
    int
      left = 2 * i + 1,
      right = 2 * i + 2,
      big = i;

    if (left < N && A[i] < A[left])
      big = left;
    if (right < N && A[big] < A[right])
      big = right;

    if (big == i)
      return;
    Swap(&A[i], &A[big]);
    i = big;
  }
}

void HeapSort( float *mas, int size )
{
  int i;

  for (i = size / 2 - 1; i >= 0; i--)
    HeapCorrection(mas, size, i);
  for (i = size - 1; i > 0; i--)
  {
    Swap(&mas[0], &mas[i]);
    HeapCorrection(mas, i, 0);
  }
}