#include <stdio.h>
#include <math.h>
#include "seq.h"

int IsPrime( int x )
{
  int i, sqr_x = (int)sqrt((float)x);

  if (x == 1)
    return 0;
  for (i = 2; i <= sqr_x; i++)
    if (x % i == 0 && x != i)
      return 0;
  return 1;
}

int DigitSum( int x )
{
  int sum = 0;

  while (x != 0)
  {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int IsNumSymm( int x )
{
  int z = x, y = 0, d;

  while (z != 0)
  {
    d = z % 10;
    z /= 10;
    y = y * 10 + d;
  }
  if (x == y)
    return 1;
  return 0;
}

void Seq( void )
{
  int x, sum = 0, n = 0, n_even = 0, n_odd = 0, n_prime = 0, n_digit_sum_even = 0, n_symm = 0;

  printf("X (0 for finish):");
  scanf("%i", &x);
  while (x != 0)
  {
    sum += x;
    n++;
    if (x % 2 == 0)
      n_even++;
    else
      n_odd++;
    if (IsPrime(x))
      n_prime++;
    if (DigitSum(x) % 2 == 0)
      n_digit_sum_even++;
    if (IsNumSymm(x))
      n_symm++;
    printf("X (0 for finish):");
    scanf("%i", &x);
  }                      
  if (n == 0)
    printf("No numbers\n");
  else
    printf("Count: %i\nSum: %i\nAverage: %f\nEven: %i\nOdd: %i\nPrime: %i\nWith even digit sum: %i\nSymm: %i\n", n, sum, (float)sum / n, n_even, n_odd, n_prime, n_digit_sum_even, n_symm);
  getchar();
  getchar();
}
