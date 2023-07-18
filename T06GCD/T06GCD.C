#include <stdio.h>

int GCD( int a, int b )
{
  int c = a % b;
  
  while (c != 0)
  {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

int LCM( int a, int b )
{
  return a * b / GCD(a, b);
}

void main( void )
{
  int a, b;

  printf("A:");
  scanf("%i", &a);
  printf("B:");
  scanf("%i", &b);
  printf("GCD(%i, %i) = %i\n", a, b, GCD(a, b));
  printf("LCM(%i, %i) = %i\n", a, b, LCM(a, b));
  getchar();
  getchar();
}