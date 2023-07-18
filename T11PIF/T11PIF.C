#include <stdio.h>
#include "pif.h"

void main( void )
{
  int n;

  printf("N:");
  scanf("%i", &n);
  PrintPif(n);
  getchar();
  getchar();
}
