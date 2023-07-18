#include <math.h>
#include "sqrt.h"

double MySqrt( double x )
{
  double e = 1e-12, a = x, a0;

  do
  {
    a0 = a;
    a = 0.5 * (a0 + x / a0);
  } while (fabs(a0 - a) > e);

  return a;
}
