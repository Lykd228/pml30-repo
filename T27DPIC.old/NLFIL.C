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

void DispIntCount( PIC *P, int X0, int Y0, int C, int R, double *res )
{
  int x, y;
  double disp, s1 = 0, s2 = 0;

  for (x = X0; x < X0 + R; x++)
  {  
    for (y = Y0; y < Y0 + R; y++)
    {
      s1 += PicGet(P, x, y, C);
      s2 += PicGet(P, x, y, C) * PicGet(P, x, y, C);
    }
  }
  s1 /= R * R;
  s2 /= R * R;
  disp = s2 - s1 * s1;
  if (disp < res[1])
  {
    res[0] = s1;
    res[1] = disp;
  }
}

void PicFilterKuwahara( PIC *PDest, PIC *PSrc, int R )
{
  int x, y, c;
  double res[2];

  res[1] = 255 * R * R;
  for (x = 0; x < PSrc->W; x++)
    for (y = 0; y < PSrc->H; y++)
      for (c = 0; c < 3; c++)
      {
        res[1] = 255 * R * R;
        DispIntCount(PSrc, x - R, y + 1, c, R, res);
        DispIntCount(PSrc, x - R, y - R, c, R, res);
        DispIntCount(PSrc, x + 1, y + 1, c, R, res);
        DispIntCount(PSrc, x + 1, y - R, c, R, res);
        PicSet(PDest, x, y, c, res[0]);
      }
}
