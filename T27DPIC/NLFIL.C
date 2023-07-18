#include <math.h>
#include "pic.h"

void Swap( byte *A, byte *B )
{
  byte tmp = *A;

  *A = *B;
  *B = tmp;
}

void QuickSort( byte *A, int N )
{
  int b, e;
  byte x;

  if (N < 2)
    return;

  x = A[N / 2];
  b = 0;
  e = N - 1;
  while (b <= e)
  {
    while (A[b] < x)
      b++;
    while (A[e] > x)
      e--;
    if (b <= e)
    {
      if (b != e)
        Swap(&A[b], &A[e]);
      b++;
      e--;
    }
  }
  QuickSort(A, e + 1);
  QuickSort(A + b, N - b);
}

void PicFilterRoberts( PIC *PDest, PIC *PSrc, double Alpha )
{
  int x, y, c;
  double res;

  for (x = 0; x < PSrc->W; x++)
    for (y = 0; y < PSrc->H; y++)
      for (c = 0; c < 3; c++)
      {
        res = abs(PicGet(PSrc, x, y, c) - PicGet(PSrc, x + 1, y + 1, c)) + abs(PicGet(PSrc, x + 1, y, c) - PicGet(PSrc, x, y + 1, c));
        PicSet(PDest, x, y, c, Clamp(res * Alpha, 0, 255));
      }
}

void PicFilterSobel( PIC *PDest, PIC *PSrc, double Alpha )
{
  int x, y, c;
  double f, g;

  for (x = 0; x < PSrc->W; x++)
    for (y = 0; y < PSrc->H; y++)
      for (c = 0; c < 3; c++)
      {
        f = (PicGet(PSrc, x - 1, y + 1, c) +
             2 * PicGet(PSrc, x, y + 1, c) +
             PicGet(PSrc, x + 1, y + 1, c)) -
             (PicGet(PSrc, x - 1, y - 1, c) +
             2 * PicGet(PSrc, x, y - 1, c) +
             PicGet(PSrc, x + 1, y - 1, c));
        g = (PicGet(PSrc, x - 1, y + 1, c) +
             2 * PicGet(PSrc, x - 1, y, c) +
             PicGet(PSrc, x - 1, y - 1, c)) -
             (PicGet(PSrc, x + 1, y + 1, c) +
             2 * PicGet(PSrc, x + 1, y, c) +
             PicGet(PSrc, x + 1, y - 1, c));
        PicSet(PDest, x, y, c, Clamp(sqrt(f * f + g * g) * Alpha, 0, 255));
      }
}

void PicFilterMedian( PIC *PDest, PIC *PSrc, int N )
{
  int x, y, c, k, i, j;
  byte *A;

  if ((A = malloc(N * N)) == NULL)
    return;

  for (x = 0; x < PSrc->W; x++)
    for (y = 0; y < PSrc->H; y++)
      for (c = 0; c < 3; c++)
      {
        k = 0;
        for (i = 0; i < N; i++)
          for (j = 0; j < N; j++)
            A[k++] = PicGet(PSrc, x - N / 2 + j, y - N / 2 + i, c);
        QuickSort(A, N * N);
        PicSet(PDest, x, y, c, A[N * N / 2]);
      }
  free(A);
}

double dispersion(PIC *pic, int x0, int y0, int c, int a)
{
  int x, y, s1, s2;
  double n = a * a;

  s1 = s2 = 0;
  for (y = y0; y < y0 + a; y++) {
    for (x = x0; x < x0 + a; x++) {
      int col = PicGet(pic, x, y, c);
      s1 += col, s2 += col * col;
    }
  }
  return s2 / n - (s1 / n) * (s1 / n);
}

double yarkost(PIC *pic, int x0, int y0, int c, int a)
{
  int x, y, res = 0;
  for (y = y0; y < y0 + a; y++)
    for (x = x0; x < x0 + a; x++)
      res += PicGet(pic, x, y, c);
  return (double)res / (a * a);
}

void kuwahara( PIC *result, PIC *source, int r )
{
  int x, y, c;
  double dp[2], pd, pc;

  for (x = 0; x < source->W; x++)
    for (y = 0; y < source->H; y++)
      for (c = 0; c < 3; c++)
      {
        pd = 1000000000;
        dp[0] = dispersion(source, x - r, y + 1, c, r);
        dp[1] = yarkost(source, x - r, y + 1, c, r);
        if (dp[0] < pd)
          pd = dp[0], pc = dp[1];
        dp[0] = dispersion(source, x - r, y + r, c, r);
        dp[1] = yarkost(source, x - r, y + r, c, r);
        if (dp[0] < pd)
          pd = dp[0], pc = dp[1];
        dp[0] = dispersion(source, x + 1, y + 1, c, r);
        dp[1] = yarkost(source, x + 1, y + 1, c, r);
        if (dp[0] < pd)
          pd = dp[0], pc = dp[1];
        dp[0] = dispersion(source, x + 1, y - r, c, r);
        dp[1] = yarkost(source, x + 1, y - r, c, r);
        if (dp[0] < pd)
          pd = dp[0], pc = dp[1];
        PicSet(result, x, y, c, pc);
      }
}
