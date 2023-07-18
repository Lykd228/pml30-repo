#include <stdio.h>
#include <math.h>

float Square( float a, float b, float c )
{
  float p;

  if (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a)
  {
    p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
  }
  return 0;
}

void main( void )
{
  float a, b, c, s;
  
  printf("A:");
  scanf("%f", &a);
  printf("B:");
  scanf("%f", &b);
  printf("C:");
  scanf("%f", &c);
  s = Square(a, b, c);
  
  if (s == 0)
    printf("not a triangle\n");
  else
    printf("s = %f\n", s);

  getchar();
  getchar();
}