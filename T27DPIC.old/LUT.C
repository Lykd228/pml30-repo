#include <math.h>
#include "pic.h"

int Clamp( int X, int A, int B )
{
  if (X < A)
    return A;
  if (X > B)
    return B;
  return X;
}

void LUTApply( PIC *PicDest, PIC *PicSrc, byte *LUT )
{
  int x, y, c;

  for (y = 0; y < PicDest->H; y++)
    for (x = 0; x < PicDest->W; x++)
      for (c = 0; c < 3; c++)
        PicSet(PicDest, x, y, c, LUT[PicGet(PicSrc, x, y, c)]);
}

void LUTSetCopy( byte *LUT )
{
  int i;

  for (i = 0; i < 255; i++)
    LUT[i] = i;
}

void LUTSetNegative( byte *LUT )
{
  int i;

  for (i = 0; i < 256; i++)
    LUT[i] = 255 - i;
}

void LUTSetBrightness( byte *LUT, int Di )
{
  int i;

  for (i = 0; i < 256; i++)
    LUT[i] = Clamp(i + Di, 0, 255);
}

void LUTSetContrast( byte *LUT, int A, int B )
{
  int i;

  for (i = 0; i < 256; i++)
    LUT[i] = Clamp(255 * (i - A) / (B - A), 0, 255);
}

void LUTSetGamma( byte *LUT, double Gamma )
{
  int i;

  for (i = 0; i < 256; i++)
    LUT[i] = (byte)(255 * pow(i / 255.0, 1.0 / Gamma));
}

void LUTSetAutoContrast( byte *LUT, PIC *P )
{
  int min = P->Pixels[0][0], max = P->Pixels[0][0], offset, c;

  for (offset = 0; offset < P->H * P->W; offset++)
  {
    for (c = 0; c < 3; c++)
    {
      if (P->Pixels[offset][c] < min)
        min = P->Pixels[offset][c];
      else if (P->Pixels[offset][c] > max)
        max = P->Pixels[offset][c];
    }
  }
  LUTSetContrast(LUT, min, max);
}

void LUTSetPoster( byte *LUT, int Levels )
{
  double single = 256.0 / Levels, color = 255.0 / (Levels - 1);
  int i, j;

  for (i = 0; i < Levels; i++)
  {
    for (j = i * single; j < (i + 1) * single; j++)
      LUT[j] = Clamp((byte)(color * i), 0, 255);
  }
}
