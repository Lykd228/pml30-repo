#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

template<typename Type>
  void Swap( Type *A, Type *B )
  {
    Type tmp = *A;
    *A = *B;
    *B = tmp;
  }

template<typename Type>
  void QuickSort( Type *mas, int size )
  {
    int b, e;
    Type x;

    if (size < 2)
      return;

    x = mas[size >> 1];
    b = 0;
    e = size - 1;
    while (b <= e)
    {
      while (mas[b] < x)
        b++;
      while (mas[e] > x)
        e--;
      if (b <= e)
      {
        if (b != e)
          Swap(&mas[b], &mas[e]);
        b++;
        e--;
      }     
    }
    QuickSort(mas, e + 1);
    QuickSort(mas + b, size - b);
  }

int main(void)
{
  string FileName;
  cout << "Input file name:";
  cin >> FileName;

  ifstream f(FileName);
  int N;
  f >> N;
  int *A = new int[N + 1];

  for (int i = 0; i < N; i++)
    f >> A[i];
  f.close();
  QuickSort(A, N);

  ofstream res(FileName);
  res << N << endl;
  for (int i = 0; i < N; i++)
    res << A[i] << endl;
  res.close();
  delete[] A;

  system("pause");
  return 0;
}
