#include <stdio.h>
#include <math.h>

void Fill0( int *mas, int size )
{
  int i;

  for (i = 0; i < size; i++)
    mas[i] = 0;
}

void FillRand( int *mas, int size, int n )
{
  int i;

  for (i = 0; i < size; i++)
    mas[i] = rand() % (n + 1);
}

void FillIncr( int *mas, int size )
{
  int i;

  for (i = 0; i < size; i++)
    mas[i] = i + 1;
}

void FillDecr( int *mas, int size )
{
  int i;

  for (i = 0; i < size; i++)
    mas[i] = size - i;
}

void OutMas( int *mas, int size )
{
  int i;

  for (i = 0; i < size; i++)
    printf("%i%c", mas[i], (i == size - 1) ? '\n' : ',');
}

void GetMinMax( int *mas, int size, int *mi, int *ma )
{
  int i;

  for (i = 0; i < size; i++)
  {
    if (mas[i] > *ma)
      *ma = mas[i];
  }
  *mi = *ma;
  for (i = 0; i < size; i++)
  {
    if (mas[i] < *mi)
      *mi = mas[i];
  }
}

double GetAverage( int *mas, int size )
{
  int i, sum = 0;

  for (i = 0; i < size; i++)
    sum += mas[i];
  return (double)sum / size;
}

void FillWithStep( int *mas, int size, int a, int b )
{
  int i;

  for (i = 0; i < size; i++)
  {
    mas[i] = a;
    a += b;
  }
}

void Reverse( int *mas, int size )
{
  int i, tmp;

  for (i = 0; i < size / 2; i++)
  {
    tmp = mas[i];
    mas[i] = mas[size - i - 1];
    mas[size - i - 1] = tmp;
  }
}

int GetDigitSum( int n )
{
  int sum = 0;

  while (n > 0)
  {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

void GetMaxDigitSum( int *mas, int size )
{
  int i, max, max_sum = 0;

  for (i = 0; i < size; i++)
  {
    if(GetDigitSum(mas[i]) >= max_sum)
    {
      max = mas[i];
      max_sum = GetDigitSum(mas[i]);
    }
  }
  printf("Number with maximal digits sum is %i\n", max);
}

int IsPrime( int x )
{
  int i = 2, last = (int)sqrt(x), flag = 1;

  while (i <= last && flag)
    flag = x % i++ != 0;
  return flag;
}

void PrintOutPrime( int *mas, int size )
{
  int i;

  for (i = 0; i < size; i++)
  {
    if (IsPrime(mas[i]))
      printf("%i ", mas[i]);
  }
  printf("\n");
}

int CountLenOfNumber( int x )
{
  int len = 0;

  do
  {
    x /= 10;
    len++;
  } while (x > 0);
  return len;
}

int GetDigit( int x, int digit )
{
  int i, ret;

  for (i = 0; i < digit; i++)
  {
    ret = x % 10;
    x /= 10;
  }
  return ret;
}

int IsSimmetrical( int x )
{
  int i, len = CountLenOfNumber(x), flag = 1;

  for (i = 1; i <= len && flag; i++)
  {
    if (GetDigit(x, i) != GetDigit(x, len - i + 1))
      flag = 0;
  }
  return flag;
}

int CountSimmetrical( int *mas, int size )
{
  int i, sum = 0;

  for (i = 0; i < size; i++)
  {
    if (IsSimmetrical(mas[i]))
      sum++;
  }
  return sum;
}
