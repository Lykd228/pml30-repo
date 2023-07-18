/* Ekaterina Dalampira, 09-5, 28.04.2021 */
#include <stdio.h>
#include "fsqr.h"

void main( void )
{
  double A, B;
  int i, N = 100000;

  double (*Square[])( double A, double B, int N ) =
  {
    SquareRect, SquareMiddle, SquareTrap, SquareSimpson
  };
  char *FuncNames[] =
  {
    "Rectangle", "Middle", "Trapeze", "Simpson"
  };
  int SNum = sizeof(Square) / sizeof(Square[0]);

  printf("A:");
  scanf("%lf", &A);
  printf("B:");
  scanf("%lf", &B);
  
  for (i = 0; i < SNum; i++)
    printf("Square %s = %f\n", FuncNames[i], Square[i](A, B, N));

  getchar();
  getchar();

}
