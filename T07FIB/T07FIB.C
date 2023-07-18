#include <stdio.h>

void EachTwoFib( int x )
{
  int a, b, c;
  
  if (x <= 0)
    printf("0\n");
  else
  {
    a = 0;
    b = 1;
    while (b <= x)
    {
      printf("%i ", b);
      c = a + b;
      a = b;
      b = c;
      c = a + b;
      a = b;
      b = c;
    }
    printf("\n");
  }
}

void main( void )
{
  int x;
  
  printf("X:");
  scanf("%i", &x);
  EachTwoFib(x);
  getchar();
  getchar();
}