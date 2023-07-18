/* Usharova Milana, 10-5, group B, 04.02.2022 */

typedef struct
{
  double Re, Im;
} CMPL;

CMPL CmplSet( double a, double b );
CMPL CmplAddCmpl( CMPL A, CMPL B );
CMPL CmplMulCmpl( CMPL A, CMPL B );
double CmplNorm( CMPL Z );
int Mandelbrot( CMPL Z );
