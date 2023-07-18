#include "tobin.h"

void PrintBin( ulong x )
{
  int i = 63;

  while (((x >> i) & 1) == 0 && i > 0)
    i--;
  for (; i >= 0; i--)
    printf("%llu", ((x >> i) & 1));
  printf("\n");

  getchar();
  getchar();
}
