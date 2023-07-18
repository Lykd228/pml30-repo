#include <stdio.h>
#include "pif.h"

int GetLen( int n )
{
  if (n >= 100000000)
    return 9;
  if (n >= 10000000)
    return 8;
  if (n >= 1000000)
    return 7;
  if (n >= 100000)
    return 6;
  if (n >= 10000)
    return 5;
  if (n >= 1000)
    return 4;
  if (n >= 100)
    return 3;
  if (n >= 10)
    return 2;
  return 1;
}

void PrintPif( int n )
{
  int a, b, i, sq = n * n, spaces_pre, spaces_post;

  for (a = 1; a <= n; a++)
  {
    for (b = 1; b <= n; b++)
    {
      spaces_pre = GetLen(n) - GetLen(a);
      spaces_post = GetLen(sq) - GetLen(a * (b + 1)) + 1;

      if (b == 1)
        for (i = 0; i < spaces_pre; i++)
          printf(" ");

      printf("%i", a * b);
      for (i = 0; i < spaces_post; i++)
        printf(" ");
    }
    printf("\n");
  }
}
