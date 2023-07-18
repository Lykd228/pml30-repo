#include "eqs.h"

/* solve any degree equation via limits */
void SolveFull( int N, double *a, CUBIC *res )
{
  int j, k, cycle;
  CUBIC x1, x2, subsum(0, 0);

  double first = a[0];

  for (j = 0; j < N; j++)
    a[j] = -1.0 * a[j + 1] / first;

  /* foolproof protection */
  if (a[N - 1] == 0)
    a[N - 1] = E;

  for (k = 0; k < N; k++)
  {
    cycle = 0;
    x2 = complex_pow(a[N - 1], 1.0/N, k);
    do
    {
      if (cycle > 1000)
      {
        x2 = 666.0 + 666.0*i; // signal about something wrong
        break;
      }
      x1 = x2;
      for (j = 0; j < N; j++)
        subsum += a[N - j - 1] * complex_pow(x1, (double)j, k);
      x2 = complex_pow(subsum, 1.0/N, k);
      subsum = 0;
      cycle++;
    } while (abs(x1 - x2) > E);
    res[k] = x2;
  }
}
