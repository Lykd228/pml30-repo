#include "eqs.h"
#include "glut.h"

/* global variables for cycle */
double *a, img, A, B;
CUBIC *X, Z;
int j, k, max_pow;

void (*Solve[])(double *, CUBIC *) =
{
  SolveLinear, SolveQuadratic, SolveCubic, SolveQuartic
};

void Display( void )
{
  glClear(GL_COLOR_BUFFER_BIT);

  glRasterPos2d(-1, 1);
  glPixelZoom(1, -1);

  /* draw axes */
  for (j = 0; j < FRAME_W; j++)
    PutPixel(j, FRAME_H / 2, 255, 255, 255);
  for (j = 0; j < FRAME_H; j++)
    PutPixel(FRAME_W / 2, j, 255, 255, 255);

  glDrawPixels(FRAME_W, FRAME_H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();

  /* dialog cycle */
  printf("\n1. Solve polynominal equation\n"
           "2. Solve defined integral [A; B] of F(x)\n"
           "3. Solve gamma-function from complex arg\n"
           "4. Solve root N's degree from complex arg\n"
           "5. Find derivative of F(x) in current X\n"
           "6. Input function F(x)\n"
           "0. Exit\n");
  switch(_getch())
  {
  case '1':
    printf("We will solve equation of the form A1*x^n + A2*x^(n-1) + ... + An*x + An+1 = 0\n"
           "n:");           
    scanf("%i", &max_pow);
    if (max_pow < 1)
    {
      printf("Incorrect equation, stupid motherfucker!\n");
      break;
    }
    a = (double *)malloc(sizeof(double)*(max_pow+1));
    X = (CUBIC *)malloc(sizeof(CUBIC)*(max_pow+1));
    for (j = 0; j <= max_pow; j++)
    {
      printf("A%i:", j + 1);
      scanf("%lf", &a[j]);
    }
    if (max_pow < 5)
      Solve[max_pow - 1](a, X);
    else
      SolveFull(max_pow, a, X);
    for (j = 0; j < max_pow; j++)
    {
      img = imag(X[j]);
      if (fabs(img) < E)
        printf("X%i = %f\n", j + 1, real(X[j]));
      else
        printf("X%i = %f %c %fi\n", j + 1, real(X[j]), (img < 0) ? '-' : '+', fabs(img));
    }
    break;
  case '2':
    printf("A:");
    scanf("%lf", &A);
    printf("B:");
    scanf("%lf", &B);
    printf("Integral of F(x) from %f to %f = %f\n", A, B, Integral(A, B, F));
    break;
  case '3':
    printf("Real part of complex number:");
    scanf("%lf", &A);
    printf("Imaginary part of complex number:");
    scanf("%lf", &B);
    Z = Gamma(A + B * i);
    printf("Gamma of (%f, %f) = (%f, %f)\n", A, B, real(Z), imag(Z));
    break;
  case '4':
    printf("Power:");
    scanf("%i", &max_pow);
    printf("Real part:");
    scanf("%lf", &A);
    printf("Imaginary part:");
    scanf("%lf", &B);
    Z = A + i*B;
    for (j = 0; j < max_pow; j++)
      printf("X%i = (%f, %f)\n", j, real(complex_pow(Z, 1.0/max_pow, j)), imag(complex_pow(Z, 1.0/max_pow, j)));
    break;
  case '5':
    printf("X:");
    scanf("%lf", &A);
    printf("F(%f) = %f, F'(%f) = %f\n", A, F(A), A, Derivative(A, F));
    break;
  case '6':
    free(func);
    func = (char *)malloc(255);
    printf("Input function without spaces:");
    scanf("%s", func);
    funclen = strlen(func);
    /* allow omit multiple symbol */
    for (j = 0; j < funclen - 1; j++)
      if (func[j] > 47 && func[j] < 58 && func[j + 1] > 96 && func[j + 1] < 123 ||
          func[j] > 47 && func[j] < 58 && func[j + 1] == '(' ||
          func[j] == 'x' && func[j + 1] == '(') {
        func[funclen + 1] = '\0';
        for (k = funclen - 1; k > j; k--)
          func[k + 1] = func[k];
        func[j + 1] = '*';
        funclen++;
      }
    break;
  case '0':
    exit(0);
    break;
  default:
    printf("Incorrect choice\n");
  }
}
