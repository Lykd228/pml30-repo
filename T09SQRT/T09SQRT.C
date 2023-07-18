#include <stdio.h>
#include <math.h>
#include "sqrt.h"

void main( void )
{
  double x;

  printf("X:");
  scanf("%lf", &x);
  printf("My    = %.15f\nExact = %.15f\n", MySqrt(x), sqrt(x));
  getchar();
  getchar();
}
