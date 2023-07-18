/* Usharova Milana, 10-5, group B, 04.02.2022 */
#include <math.h>
#include "cmpl.h"

CMPL CmplSet( double a, double b )
{
  CMPL c;

  c.Re = a;
  c.Im = b;
  return c;
}

CMPL CmplAddCmpl( CMPL A, CMPL B )
{
  CMPL C;

  C.Re = A.Re + B.Re;
  C.Im = A.Im + B.Im;
  return C;
}

CMPL CmplMulCmpl( CMPL A, CMPL B )
{
  CMPL C;

  C.Re = A.Re * B.Re - A.Im * B.Im;
  C.Im = A.Re * B.Im + A.Im * B.Re;
  return C;
}

double CmplNorm( CMPL Z )
{
  return sqrt(Z.Re * Z.Re + Z.Im * Z.Im);
}

int Mandelbrot( CMPL Z )
{
  CMPL Z0 = Z;
  int n = 0;

  while (n < 255 && CmplNorm(Z) < 2)
    Z = CmplAddCmpl(CmplMulCmpl(Z, Z), Z0), n++;
  return n;
}
