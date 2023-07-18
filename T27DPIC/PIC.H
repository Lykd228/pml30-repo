#include <stdio.h>
#include <stdlib.h>

#define FRAME_W 1920
#define FRAME_H 1080

typedef unsigned char byte;
typedef byte RGB[3];

typedef struct
{
  int W, H;
  RGB *Pixels;
} PIC;

typedef struct
{
  char *Name;
  int A[3][3], Frac, Bias;
} FILTER;

extern FILTER Filters[];
extern int NumOfFilters;

void PutPixel( int x, int y, int r, int g, int b );
void PicDraw( PIC *P, int X0, int Y0 );
int PicGet( PIC *P, int X, int Y, int C );
int PicCreate( PIC *P, int NewW, int NewH );
int PicLoad( PIC *P, char *FileName );
void PicFree( PIC *P );
int PicSave( PIC *P, char *FileName );
int PicSet( PIC *P, int X, int Y, int C, byte Value );
int Clamp( int X, int A, int B );
void LUTApply( PIC *PicDest, PIC *PicSrc, byte *LUT );
void LUTSetCopy( byte *LUT );
void LUTSetNegative( byte *LUT );
void LUTSetBrightness( byte *LUT, int Di );
void LUTSetContrast( byte *LUT, int A, int B );
void LUTSetGamma( byte *LUT, double Gamma );
void LUTSetAutoContrast( byte *LUT, PIC *P );
void LUTSetPoster( byte *LUT, int Levels );
void AutoDraw( PIC *P );
void PicFilter( PIC *PDest, PIC *PSrc, FILTER *F );
void PicFilterRoberts( PIC *PDest, PIC *PSrc, double Alpha );
void PicFilterSobel( PIC *PDest, PIC *PSrc, double Alpha );
void PicFilterMedian( PIC *PDest, PIC *PSrc, int N );
void kuwahara( PIC *result, PIC *source, int r );
