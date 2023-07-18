#include <stdio.h>
#include <stdlib.h>

void FillRand( float *mas, int size )
{
  int i;

  srand(12);
  for (i = 0; i < size; i++)
    mas[i] = (rand() - RAND_MAX / 2) / 30.0;
}

void FillIncr( float *mas, int size )
{
  int i;

  srand(12);
  for (mas[0] = -30.47, i = 1; i < size; i++)
    mas[i] = mas[i - 1] + rand() % 10 / 8.0 + 0.1;
}

void FillDecr( float *mas, int size )
{
  int i;

  srand(12);
  for (mas[size - 1] = -30.47, i = size - 2; i >= 0; i--)
    mas[i] = mas[i + 1] + rand() % 10 / 8.0 + 0.1;
}

void FillEq( float *mas, int size )
{
  int i;

  srand(12);
  for (mas[0] = -30.47, i = 1; i < size; i++)
    mas[i] = mas[0];
}

void Swap( float *A, float *B )
{
  float tmp = *A;

  *A = *B;
  *B = tmp;
}

void FillMostly( float *mas, int size )
{
  int i;

  FillIncr(mas, size);
  for (i = 0; i < size / 20; i++)
    Swap(&mas[rand() % size], &mas[rand() % size]);
}

void OutMas( float *mas, int size )
{
  int i;

  for (i = 0; i < size; i++)
    printf("%f%c", mas[i], (i == size - 1) ? '\n' : ',');
}

int CheckSort( float *mas, int size )
{
  int i;

  for (i = 1; i < size; i++)
    if (mas[i] < mas[i - 1])
      return 0;
  return 1;
}
