/* Ekaterina Dalampira, 09-5, 28.04.2021 */
#include "fsqr.h"

double f( double X )
{
  return 3 * X * X;
}

double SquareRect( double A, double B, int N )
{
  int i;
  double sqr = 0, x = A, H = (B - A) / N;

  for (i = 0; i < N; i++)
  {
    sqr += H * f(x);
    x += H;
  }
  return sqr;
}

double SquareMiddle( double A, double B, int N )
{
  int i;
  double sqr = 0, x = A, H = (B - A) / N;

  for (i = 0; i < N; i++)
  {
    sqr += H * f(x + H / 2);
    x += H;
  }
  return sqr;
}

double SquareTrap( double A, double B, int N )
{
  int i;
  double sqr = 0, x = A, H = (B - A) / N;

  for (i = 0; i < N; i++)
  {
    sqr += H * (f(x) + f(x + H)) / 2;
    x += H;
  }
  return sqr;
}

double SubSimpson( double A, double B )
{
  return (B - A) / 6 * (f(A) + 4 * f((A + B) / 2) + f(B));
}

double SquareSimpson( double A, double B, int N )
{
  int i;
  double sqr = 0, x = A, H = (B - A) / N;

  for (i = 0; i < N; i++)
  {
    sqr += SubSimpson(x, x + H);
    x += H;
  }
  return sqr;
}
