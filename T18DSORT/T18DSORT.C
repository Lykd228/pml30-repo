#include <stdio.h>
#include <time.h>

#define MAX 100000000

typedef unsigned long long ull;

int GetSum( int *A, int N )
{
  int i, cnt = 0;

  for (i = 0; i < N; i++)
    cnt += A[i];
  return cnt;
}

void Swap( ull *A, ull *B )
{
  ull tmp = *A;

  *A = *B;
  *B = tmp;
}

void QuickSort( ull *A, int N )
{
  int b, e;
  ull x;

  if (N < 2)
    return;

  x = A[N / 2];
  b = 0;
  e = N - 1;
  while (b <= e)
  {
    while (A[b] < x)
      b++;
    while (A[e] > x)
      e--;
    if (b <= e)
    {
      if (b != e)
        Swap(&A[b], &A[e]);
      b++;
      e--;
    }
  }
  QuickSort(A, e + 1);
  QuickSort(A + b, N - b);
}

void DigitSort( ull *A, int N )
{
  int i, Count[256], Offset[256], digit_count;
  ull *b, *tmp;

  b = malloc(N * sizeof(ull));
  for (digit_count = 0; digit_count < 8; digit_count++)
  {
    for (i = 0; i < 256; i++)
      Count[i] = 0;
    for (i = 0; i < N; i++)
      Count[((unsigned char *)&A[i])[digit_count]]++;
    for (i = 0; i < 256; i++)
      Offset[i] = GetSum(Count, i);
    for (i = 0; i < N; i++)  
      b[Offset[((unsigned char *)&A[i])[digit_count]]++] = A[i];
    tmp = A;
    A = b;
    b = tmp;
  }
  free(b);
}

int CheckSort( ull *mas, int size )
{
  int i;

  for (i = 1; i < size; i++)
    if (mas[i] < mas[i - 1])
      return 0;
  return 1;
}

void main( void )
{
  static ull A[MAX];
  int i, si;
  long t;

  void (*Sort[])( ull *A, int N ) =
  {
    QuickSort, DigitSort
  };

  srand(31608);
  for (si = 0; si < sizeof(Sort) / sizeof(Sort[0]); si++)
  {
    for (i = 0; i < MAX; i++)
      A[i] = rand();

    t = clock();
    Sort[si](A, MAX);
    t = clock() - t;
    if (CheckSort(A, MAX))
      printf("%10.5f", t / (double)CLOCKS_PER_SEC);
    else
      printf("   FAIL   ");
  }
  printf("\n");
  getchar();
}