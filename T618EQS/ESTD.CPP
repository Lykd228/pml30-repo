#include "eqs.h"

/* solve functions for equations with degree 1-4
   linear equation */
void SolveLinear( double *a, CUBIC *res )
{
  res[0] = -a[1]/a[0];
}

/* quadratic equation */
void SolveQuadratic( double *a, CUBIC *res )
{
  CUBIC D = a[1]*a[1]-4.0*a[0]*a[2];
  res[0] = (-a[1]-sqrt(D))/(2.0*a[0]);
  res[1] = (-a[1]+sqrt(D))/(2.0*a[0]);
}

/* cubic equation */
void SolveCubic( double *a, CUBIC *res )
{
  double p, q;
  CUBIC D, A[3], sqrq, pq3;
  int k;

  p = -a[1]*a[1]/(3*a[0]*a[0])+a[2]/a[0];
  q = (2*a[1]*a[1]*a[1])/(27*a[0]*a[0]*a[0])-a[1]*a[2]/(3*a[0]*a[0])+a[3]/a[0];
  D = -27*q*q-4*p*p*p;
  sqrq = sqrt(-D/108.0);
  pq3 = -q/2.0 + sqrq;
  A[0] = complex_pow(pq3, 1.0/3.0, 1);
  A[1] = A[0]*(-1.0/2.0 + i*sqrt(3.0)/2.0);
  A[2] = A[0]*(-1.0/2.0 - i*sqrt(3.0)/2.0);
  for (k = 0; k < 3; k++)
    res[k] = A[k] - p/(3.0*A[k]) - a[1]/(3.0*a[0]);
}

/* quartic equation */
void SolveQuartic( double *a, CUBIC *res )
{
  double suba[4], p, q, r;
  CUBIC z[3];

  p = (8*a[0]*a[2]-3*a[1]*a[1])/(8*a[0]*a[0]);
  q = (8*a[0]*a[0]*a[3]
      +a[1]*a[1]*a[1]
      -4*a[0]*a[1]*a[2])
      /(8*a[0]*a[0]*a[0]);
  r = (16*a[0]*a[1]*a[1]*a[2]
      -64*a[0]*a[0]*a[1]*a[3]
      -3*a[1]*a[1]*a[1]*a[1]
      +256*a[0]*a[0]*a[0]*a[4])
      /(256*a[0]*a[0]*a[0]*a[0]);
  suba[0] = 1.0;
  suba[1] = p/2;
  suba[2] = (p*p-4*r)/16;
  suba[3] = -q*q/64;
  SolveCubic(suba, z);
  if (q > 0)
  {
    res[0] = -sqrt(z[0])+sqrt(z[1])+sqrt(z[2]) - a[1]/(4*a[0]);
    res[1] = sqrt(z[0])-sqrt(z[1])+sqrt(z[2]) - a[1]/(4*a[0]);
    res[2] = sqrt(z[0])+sqrt(z[1])-sqrt(z[2]) - a[1]/(4*a[0]);
    res[3] = -sqrt(z[0])-sqrt(z[1])-sqrt(z[2]) - a[1]/(4*a[0]);
  }
  else
  {
    res[0] = -sqrt(z[0])-sqrt(z[1])+sqrt(z[2]) - a[1]/(4*a[0]);
    res[1] = sqrt(z[0])-sqrt(z[1])-sqrt(z[2]) - a[1]/(4*a[0]);
    res[2] = -sqrt(z[0])+sqrt(z[1])-sqrt(z[2]) - a[1]/(4*a[0]);
    res[3] = sqrt(z[0])+sqrt(z[1])+sqrt(z[2]) - a[1]/(4*a[0]);
  }
}

/* solve any equation via numerical Newton method */
double Newton( double B, double (*F)( double X ) )
{
  double A;

  do
  {
    A = B;
    B = A - F(A)/Derivative(A, F);
  } while (abs(A - B) > E);
  return B;
}
