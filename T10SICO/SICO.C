#include <math.h>
#include "sico.h"

double MySin( double x )
{
  double sum = x, n = 0, an = x, e = 1e-14;

  while (fabs(an) > e)
  {
    an *= (-1) * x * x / ((2 * n + 2) * (2 * n + 3));
    sum += an;
    n++;
  }

  return sum;
}

double MyCos( double x )
{
  double sum = 1, n = 0, an = 1, e = 1e-14;

  while (fabs(an) > e)
  {
    an *= (-1) * x * x / ((2 * n + 1) * (2 * n + 2));
    sum += an;
    n++;
  }

  return sum;
}
