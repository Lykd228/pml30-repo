#include <iostream>
#include <cstdlib>
#include <cmath>

typedef unsigned char uchar;
int NumWidth( int X )
{
    return (int)log10((double)X);
}

void PrintEdge( int singleNumLen, int numLen, int B, int A, int c0, int c1, int c2 )
{
    std::cout << (uchar)c0;
    for (int i = 0; i < singleNumLen ; i++)
        std::cout << (uchar)196;
    std::cout << (uchar)c1;
    for (int i = 0; i < numLen * (B - A + 1) + 1; i++)
        std::cout << (uchar)196;
    std::cout << (uchar)c2 << std::endl;
}

void PrintVert( int W )
{
    std::cout.width(W);
    std::cout << (uchar)179;
}

int main( void )
{
  int A, B;
  std::cout << "A:";
  std::cin >> A;
  std::cout << "B:";
  std::cin >> B;
  int numLen = 2 * NumWidth(B) + 3;
  int singleNumLen = NumWidth(B - A) + 3;

  PrintEdge(singleNumLen, numLen, B, A, 218, 194, 191);

  PrintVert(1);
  std::cout.width(singleNumLen - 1);
  std::cout << " ";
  PrintVert(2);

  for (int i = A; i <= B; i++)
  {
    std::cout.width(numLen);
    std::cout << i;
  }
  PrintVert(2);
  std::cout << std::endl;

  PrintEdge(singleNumLen, numLen, B, A, 195, 197, 180);

  for (int i = A; i <= B; i++)
  {
    PrintVert(1);
    std::cout.width(singleNumLen - 1);
    std::cout << i;
    PrintVert(2);

    for (int j = A; j <= B; j++)
    {
      std::cout.width(numLen);
      std::cout << i * j;
    }
    PrintVert(2);
    std::cout << std::endl;
  }

  PrintEdge(singleNumLen, numLen, B, A, 192, 193, 217);
  system("pause");
  return 0;
}
