#include <stdio.h>
#include <math.h>

void SolveQuadratic( float a, float b, float c )
{
  float d, p, q;

  if (a == 0)
    if (b == 0)
      if (c == 0)
        printf("Solution is any number\n");
      else
        printf("No solutions\n");
    else
      printf("x = %f\n", -c / b);
  else
  {
    d = b * b - 4 * a * c;
    if (d >= 0)
    {
      p = -b / (2 * a);
      q = sqrt(d) / (2 * a);
      printf("x1 = %f\n", p + q);
      printf("x2 = %f\n", p - q);
    }
    else
      printf("No real solutions\n");
  }
}

void main( void )
{
  float a, b, c;
  
  printf("A:");
  scanf("%f", &a);
  printf("B:");
  scanf("%f", &b);
  printf("C:");
  scanf("%f", &c);
  SolveQuadratic(a, b, c);
  getchar();
  getchar();
}