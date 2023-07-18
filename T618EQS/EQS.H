
/* enable I/O and complex mathematics */
#include <stdio.h>
#include <complex>
#include <math.h>
#include <limits>
#include <conio.h>
#include <string.h>

#define FRAME_W 1360
#define FRAME_H 760

extern unsigned char Frame[FRAME_H][FRAME_W][3];

/* use standart namespace */
using namespace std;

/* define complex type with double accuracy */
typedef complex<double> CUBIC;

/* constants */
extern CUBIC i;
extern const double e, pi, E, nan;
extern char *func, *bin[];
extern int funclen, bs;

/* all functions of project */
double argument( CUBIC A );
CUBIC complex_pow( CUBIC A, CUBIC B, int k );
double UniFunc( char *func, int len, double X );
double F( double X );
void SolveLinear( double *a, CUBIC *res );
void SolveQuadratic( double *a, CUBIC *res );
void SolveCubic( double *a, CUBIC *res );
void SolveQuartic( double *a, CUBIC *res );
double Integral( double A, double B, double (*f)( double X ) );
CUBIC Gamma( CUBIC Z );
double Factorial( double X );
void SolveDepressed( int N, double p, double q, CUBIC *res );
void SolveFull( int N, double *a, CUBIC *res );
double Derivative( double X, double (*f)( double X ) );
double Newton( double B, double (*F)( double X ) );
int SolveBrackets( char *func, int *j );
double GetNum( char *func, int *j );
int FindString( char **strings, char *key, int count );
void Display( void );
void PutPixel( int x, int y, int r, int g, int b );
