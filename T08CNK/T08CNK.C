#include <stdio.h>

int fact( int n )
{
  int i, prod;

  for (i = 1, prod = 1; i <= n; i++)
    prod *= i;
  return prod;
}

int cnk( int n, int i )
{
  int n_fact = fact(n), n_i_fact = fact(n - i), i_fact = fact(i);

  return n_fact / (i_fact * n_i_fact);
}

void PascalTriangle( int a )
{
  int n, i, j;

  for (n = 0; n <= a; n++)
  {
    for (j = 1; j <= a - n; j++)
      printf(" ");
    for (i = 0; i <= n; i++)
      printf("%i ", cnk(n, i));
    for (j = 1; j < a - n; j++)
      printf(" ");
    printf("\n");
  }
}

void main( void )
{
  int n, i;

  printf("N:");
  scanf("%i", &n);
  printf("I:");
  scanf("%i", &i);
  printf("C(%i, %i) = %i\n", i, n, cnk(n, i));
  PascalTriangle(n);
  getchar();
  getchar();
}
