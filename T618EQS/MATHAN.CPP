#include "eqs.h"

/* intergal via Simpson method */
double SubSimpson( double A, double B, double (*f)( double X ) )
{
  return (B - A) / 6 * (f(A) + 4 * f((A + B) / 2) + f(B));
}

double Integral( double A, double B, double (*f)( double X ) )
{
  int j;
  double sqr = 0, N = 1000, x = A, H = (B - A) / N;

  for (j = 0; j < N; j++)
  {
    sqr += SubSimpson(x, x + H, f);
    x += H;
  }
  return sqr;
}

/* derivative of function in current point */
double Derivative( double X, double (*f)( double X ) )
{
  return (f(X + E) - f(X))/E;
}

/* gamma function of complex argument */
CUBIC Gamma( CUBIC Z )
{
  CUBIC x1 = 1.0 / Z, x2 = x1;
  int n = 1;

  do
  {
    x1 = x2;
    x2 = x1 * pow(n + 1.0, Z) / (pow((double)n, Z - 1.0) * (Z + (double)n));
    n++;
  } while (abs(x1 - x2) > E);
  return x2;
}

/* factorial */
double Factorial( double X )
{
  return real(Gamma(X + 1.0));
}
