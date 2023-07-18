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

void Swap( int *A, int *B )
{
  float tmp = *A;

  *A = *B;
  *B = tmp;
}

void HeapCorrection( int *A, int N, int i )
{
  while (1)
  {
    int
      left = 2 * i + 1,
      right = 2 * i + 2,
      big = i;

    if (left < N && A[i] < A[left])
      big = left;
    if (right < N && A[big] < A[right])
      big = right;

    if (big == i)
      return;
    Swap(&A[i], &A[big]);
    i = big;
  }
}

void Sort( int *mas, int size )
{
  int i;

  for (i = size / 2 - 1; i >= 0; i--)
    HeapCorrection(mas, size, i);
  for (i = size - 1; i > 0; i--)
  {
    Swap(&mas[0], &mas[i]);
    HeapCorrection(mas, i, 0);
  }
  for (i = 0; i < size / 2; i++)
    Swap(&mas[i], &mas[size - i - 1]);
}

void WriteMas( int *A, int N )
{
  int i;
  FILE *F;

  F = fopen("RES.TXT", "w");
  if (F == NULL)
    return;
  for (i = 0; i < N; i++)
    fprintf(F, "%i ", A[i]);
  fclose(F);
}

void GetRandFile( int N )
{
  int i;
  FILE *F;

  F = fopen("IN.TXT", "w");
  if (F == NULL)
    return;
  for (i = 0; i < N; i++)
    fprintf(F, "%i ", rand() % N);
  fclose(F);
}

void main( void )
{
  int *a, n = Count();

  a = malloc(n * sizeof(int));
  if (a == NULL)
    return;
  ReadMas(a, n);
  Sort(a, n);
  WriteMas(a, n);
}
