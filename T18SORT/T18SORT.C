#include <stdio.h>
#include <time.h>
#include "sort.h"

#define MAX 2000000

void main( void )
{
  static float mas[MAX];
  long t;
  int si, fi;

  void (*Fill[])( float *mas, int size ) =
  {
    FillRand, FillIncr, FillDecr, FillEq, FillMostly
  };
  void (*Sort[])( float *mas, int size ) =
  {
    MergeSort, QuickSort, HeapSort
  };

  for (si = 0; si < sizeof(Sort) / sizeof(Sort[0]); si++)
  {
    printf("Sort #%i\n", si + 1);
    for (fi = 0; fi < sizeof(Fill) / sizeof(Fill[0]); fi++)
    {
      Fill[fi](mas, MAX);
      t = clock();
      Sort[si](mas, MAX);
      t = clock() - t;
      if (CheckSort(mas, MAX))
        printf("%10.5f", t / (double)CLOCKS_PER_SEC);
      else
        printf("   FAIL   ");
    }
    printf("\n");
  }
  getchar();
}
