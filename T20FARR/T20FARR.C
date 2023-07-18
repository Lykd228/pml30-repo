#include <stdio.h>
#include <stdlib.h>

int Count( void )
{
  int x, cnt = 0;
  FILE *F;

  F = fopen("IN.TXT", "r");
  if (F == NULL)
    return 0;
  while (fscanf(F, "%i", &x) == 1)
    cnt++;
  fclose(F);
  return cnt;
}

void ReadMas( int *A, int N )
{
  int i;
  FILE *F;

  F = fopen("IN.TXT", "r");
  if (F == NULL)
    return;
  for (i = 0; i < N; i++)
    fscanf(F, "%i", &A[i]);
  fclose(F);
}

void WriteMas( int *A, int N )
{
  int i;
  FILE *F;

  F = fopen("RES.TXT", "w");
  if (F == NULL)
    return;
  for (i = N - 1; i >= 0; i--)
    fprintf(F, "%i ", A[i]);
  fclose(F);
}

void Correction( int *A, int N )
{
  int i;

  for (i = 0; i < N; i++)
    if (A[i] % 2 == 0)
      A[i] = 0;
}

void main( void )
{
  int *a, n = Count();

  a = malloc(n * sizeof(int));
  if (a == NULL)
    return;
  ReadMas(a, n);
  Correction(a, n);
  WriteMas(a, n);
}