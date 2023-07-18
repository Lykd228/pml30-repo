#include "eqs.h"

/* binary operations */
double power(double A, double B) { return pow(A, B); }
double mult(double A, double B) { return A * B; }
double div(double A, double B) { return A / B; }
double sum(double A, double B) { return A + B; }
double diff(double A, double B) { return A - B; }
/* variables as a functions */
double xf(double A) { return A; };
double ef(double A) { return e; };
double Ef(double A) { return E; };
double pif(double A) { return pi; };

/* solve non-binary operations */
double SolveNonBinary( char *func, int *j, int flen, double X )
{
  int bracket = 1, sublen = 0, start;
  char operation[255], cc[2];
  double subres;

  cc[1] = '\0';
  /* operations themselves */
  double (*NonBinary[])(double) =
  {
    log10, log, sin, cos, tan, asin, acos, atan, exp, Factorial, sinh, cosh, tanh, xf, ef, Ef, pif
  };
  int nbfc = sizeof(NonBinary)/sizeof(NonBinary[0]);
  char *NonBinaryNames[] =
  {
    "log", "ln", "sin", "cos", "tan", "asin", "acos", "atan", "exp", "fact", "sinh", "cosh", "tanh", "x", "e", "E", "pi"
  };

  cc[0] = func[*j];
  while (cc[0] != '(' && FindString(bin, cc, bs) == -1 && *j < flen)
  {
    if (!(func[*j] > 96 && func[(*j)++] < 123))
      return nan;
    operation[sublen++] = cc[0];
    cc[0] = func[*j];
  }
  operation[sublen] = '\0';
  if (func[*j] == '(' && *j < flen)
  {
    start = (*j) + 1;
    sublen = SolveBrackets(func, j);
    subres = UniFunc(func + start, sublen, X);
  }
  else
  {
    subres = X;
    (*j)--;
  }
  if ((start = FindString(NonBinaryNames, operation, nbfc)) != -1) return NonBinary[start](subres);
  return nan;
}
                    
/* get value of function stored in "func" string in current X */
double UniFunc( char *func, int len, double X )
{
  /* variables */
  double sblock[128][128];
  int opers[128][128];
  int j, count = 0, level = 0, k, start, order;
  int A[] = {0, 1, 3}, B[] = {0, 2, 4}, os = sizeof(A)/sizeof(A[0]);
  char cc[2];

  cc[1] = '\0';
  /* operations */
  double (*operation[])(double, double) =
  {
    power, mult, div, sum, diff
  };

  /* read formula and split it into numbers and operations */
  for (j = 0; j < len; j++)
  {
    if (func[j] > 47 && func[j] < 58)
      /* number in string */
      sblock[level][count++] = GetNum(func, &j);
    else if (func[j] > 96 && func[j] < 123)
      /* non-binary function or constant */
      sblock[level][count++] = SolveNonBinary(func, &j, len, X);
    else if (func[j] == '(')
    {
      /* brackets changes order of operations */
      start = j + 1;
      k = SolveBrackets(func, &j);
      sblock[level][count++] = UniFunc(func + start, k, X);
    }
    else
    {
      cc[0] = func[j];
      if ((k = FindString(bin, cc, bs)) != -1)
          opers[level][count - 1] = k, start = 0;
      else 
        /* invalid symbol in formula, return NaN */
        return nan;
    }
  }
  /* now sblock[0] contains numbers
     and opers[0] contains operations 
     need to count they all */
   for (order = 0; order < os; order++)
     for (j = 0; j < count - 1; j++)
       if (opers[level][j] >= A[order] && opers[level][j] <= B[order])
       {
         sblock[level + 1][j] = operation[opers[level][j]](sblock[level][j], sblock[level][j + 1]);
         for (k = 0; k < j; k++)
         {
           sblock[level + 1][k] = sblock[level][k];
           opers[level + 1][k] = opers[level][k];
         }
         for (k = j + 1; k < count - 1; k++)
         {
           sblock[level + 1][k] = sblock[level][k + 1];
           opers[level + 1][k - 1] = opers[level][k];
         }
         count--;
         j--;
         level++;
       }
  return sblock[level][0];
}
