#include "eqs.h"

/* define constants */
CUBIC i(0.0, 1.0);
const double e = 2.718281828459045;
const double pi = 3.141592653589793;
const double E = 1e-7;
char *func = NULL;
char *bin[] = {"^\0", "*\0", "/\0", "+\0", "-\0"};
int funclen = 0, bs = sizeof(bin)/sizeof(bin[0]);
const double nan = std::numeric_limits<double>::quiet_NaN();

/* UniFunc */
double F( double X )
{
  if (func == NULL)
      return nan;
  return UniFunc(func, funclen, X);
}

/* get argument of complex number */
double argument( CUBIC A )
{
  double x = real(A), y = imag(A);
  double res = atan(y/x);

  if (x < 0)
  {
    if (y >= 0)
      res += pi;
    else
      res -= pi;
  }
  else if (x == 0)
  {
    if (y > 0)
      res = pi/2;
    else if (y < 0)
      res = -pi/2;
    else
      res = 0;
  }
  return res;
}

/* complex multi-value power */
CUBIC complex_pow( CUBIC A, CUBIC B, int k )
{
  double arg, mod;
  CUBIC pr, res;

  arg = argument(A);
  mod = abs(A);
  pr = B*(log(mod)+i*(arg+2*pi*k));
  res = exp(pr);

  return res;
}

/* extract float number from function string */
double GetNum( char *func, int *j )
{
  double res = 0, appow = 0;
  int afterpoint = 0, k = *j;

  do
  {
    if (func[k] == '.')
    {
      afterpoint = 1;
      appow--;
      k++;
      continue;
    }
    if (!afterpoint)
      res = res * 10 + func[k] - 48;
    else
      res += (func[k] - 48) * pow(10.0, appow--);
    k++;
  } while ((func[k] >= 48 && func[k] <= 57) || func[k] == '.');
  *j = k - 1;

  return res;
}

/* get length of function in brackets */
int SolveBrackets( char *func, int *j )
{
  int k = 0, start = (*j) + 1, bracket = 1;
  do
  {
    (*j)++;
    if (func[*j] == '(')
      bracket++;
    else if (func[*j] == ')')
      bracket--;
    if (bracket)
      k++;
  } while (bracket);
  return k;
}

/* find position of string in massive */
int FindString( char **strings, char *key, int count )
{
  int k;

  for (k = 0; k < count; k++)
    if (!strcmp(key, strings[k])) return k;
  return -1;
}
