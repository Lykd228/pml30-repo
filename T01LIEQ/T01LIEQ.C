#include <stdio.h>

void main( void )
{
  float a, b;

  printf("A:");
  scanf("%f", &a);
  printf("B:");
  scanf("%f", &b);
  if (a == 0)
    if (b == 0)
      printf("Solution is any number\n");
    else
      printf("No solutions\n");
  else
    printf("%f\n", -b / a);
  getchar();
  getchar();
}
