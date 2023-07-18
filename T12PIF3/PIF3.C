#include <stdio.h>
#include <math.h>
#include "pif3.h"

void PrintPif3( int n )
{
  int a, b, c;
  float c_float;

  for (a = 1; a <= n; a++)
    for (b = a; b <= n; b++)
    {
      c_float = sqrt((float)a * a + b * b);
      c = (int)c_float;
      if (c == c_float && c <= n)
        printf("(%i, %i, %i)\n", a, b, c);
    }
}
