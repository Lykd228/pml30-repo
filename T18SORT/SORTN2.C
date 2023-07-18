#include "sort.h"

void BubbleSort( float *mas, int size )
{
  int i, k;

  for (k = 0; k < size - 1; k++)
    for (i = 0; i < size - 1 - k; i++)
      if (mas[i] > mas[i + 1])
        Swap(&mas[i], &mas[i + 1]);
}

void BubbleSortAdv( float *mas, int size )
{
  int i, changed, last = size - 2;

  do
  {
    changed = 0;
    for (i = 0; i <= last; i++)
      if (mas[i] > mas[i + 1])
        Swap(&mas[i], &mas[i + 1]), changed = i;
    last = changed - 1;
  } while (last >= 0);
}

void InsertionSort( float *mas, int size )
{
  int i, j;
  float x;

  for (i = 1; i < size; i++)
  {
    x = mas[i];
    j = i - 1;
    while (j >= 0 && x < mas[j])
      mas[j + 1] = mas[j], j--;
    mas[j + 1] = x;
  }
}

void SelectionSort( float *mas, int size )
{
  int i, j, min;

  for (j = 0; j < size - 1; j++)
  {
    for (i = j + 1, min = j; i < size; i++)
      if (mas[i] < mas[min])
        min = i;
    Swap(&mas[j], &mas[min]);
  }
}
