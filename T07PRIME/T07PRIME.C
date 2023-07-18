#include <stdio.h>
#include <math.h>

int IsPrime( int x )
{
  int i = 2, last = (int)sqrt(x), flag = 1;

  while (i <= last && flag)
    flag = x % i++ != 0;
  return flag;
}

void AllPrimes( int x )
{
  int i = 2, n = 0;
  
  while (i <= x)
  {
    if (IsPrime(i))
    {
      printf("%i\n", i);
      n++;
    }
    i++;
  }
  printf("Total %i primes\n", n);
}

void main( void )
{
  int x;
  
  printf("X:");
  scanf("%i", &x);
  if (IsPrime(x))
    printf("%i is prime\n", x);
  else
    printf("%i is not prime\n", x);
  AllPrimes(x);
  getchar();
  getchar();
}
