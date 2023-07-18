#include "pic.h"

void PicDraw( PIC *P, int X0, int Y0 )
{
  int x, y, offset = 0;

  for (y = 0; y < P->H; y++)
    for (x = 0; x < P->W; x++, offset++)
      PutPixel(x + X0, y + Y0,
        P->Pixels[offset][2],
        P->Pixels[offset][1],
        P->Pixels[offset][0]);
}

void AutoDraw( PIC *P )
{
  static int X = 0, Y = 0;

  PicDraw(P, X, Y);
  X += P->W;

  if (X > FRAME_W - P->W)
  {
    X = 0;
    Y += P->H;
    if (Y > FRAME_H - P->H)
      Y = 0;
  }
}

int PicGet( PIC *P, int X, int Y, int C )
{
  X = (X + P->W) % P->W;
  Y = (Y + P->H) % P->H;
  return P->Pixels[Y * P->W + X][C];
}

int PicCreate( PIC *P, int NewW, int NewH )
{
  P->Pixels = malloc(NewW * NewH * sizeof(RGB));
  if (P->Pixels == NULL)
    return 0;
  P->W = NewW;
  P->H = NewH;
  return 1;
}

int PicLoad( PIC *P, char *FileName )
{
  int W = 0, H = 0;
  FILE *F;

  if ((F = fopen(FileName, "rb")) == NULL)
    return 0;
  fread(&W, 2, 1, F);
  fread(&H, 2, 1, F);
  if (!PicCreate(P, W, H))
  {
    fclose(F);
    return 0;
  }
  fread(P->Pixels, 3, W * H, F);
  fclose(F);
  return 1;
}

void PicFree( PIC *P )
{
  if (P->Pixels != NULL)
    free(P->Pixels);
  P->W = P->H = 0;
  P->Pixels = NULL;
}

int PicSave( PIC *P, char *FileName )
{
  FILE *F;

  if ((F = fopen(FileName, "wb")) == NULL)
    return 0;
  fwrite(&P->W, 2, 1, F);
  fwrite(&P->H, 2, 1, F);
  fwrite(P->Pixels, 3, P->W * P->H, F);
  fclose(F);
  return 1;
}

int PicSet( PIC *P, int X, int Y, int C, byte Value )
{
  if (X < 0 || Y < 0 || X >= P->W || Y >= P->H)
    return 0;
  P->Pixels[Y * P->W + X][C] = Value;
  return 1;
}
