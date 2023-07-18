#include <stdio.h>
#include <math.h>
#include "sico.h"

void main( void )
{
  double pi = 3.14159265358979, x, y;

  printf("X:");
  scanf("%lf", &x);
  y = x * pi / 180;
  printf("MySin = %.15f\nExSin = %.15f\nMyCos = %.15f\nExCos = %.15f\n", MySin(y), sin(y), MyCos(y), cos(y));
  getchar();
  getchar();
}
