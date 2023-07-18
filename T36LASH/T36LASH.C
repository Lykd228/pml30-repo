#include <math.h>
#include <time.h>
#include <glut.h>

#define N 5
#define SPEED 2
#define WIDTH 800
#define HEIGHT 700

double F( int n, int c, double t )
{
  t = fmod(t, n);
  if (t < c - 1)
    return 0.0;
  if (c - 1 <= t && t < c)
    return t - c + 1;
  if (c <= t && t < n - c)
    return 1.0;
  if (n - c <= t && t < n - c + 1)
    return n - c + 1 - t;
  return 0.0;
}

void Display( void )
{
  int i;
  double t = SPEED * clock() / (double)CLOCKS_PER_SEC;

  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  glTranslated(0, -0.27, 0);
  glColor3d(0.3, 0.4, 0.5);
  glRectd(-0.2, 0, 0.2, -0.7);

  for (i = 1; i < N; i++)
  {
    glScaled(0.7, 0.7, 0.7);
    glColor3d(fmod(i - 0.1, 0.7), fmod(i - 0.2, 0.7), fmod(i - 0.3, 0.7));
    glRotated(180 * F(2*(N-1), i, t) - (i == 1 ? 0 : 180), 0, 0, 1);
    glRectd(-0.2, 0, 0.2, -0.7);
    glTranslated(0, -0.7, 0);
  }

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}

void main( int argc, char *argv[] )
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutCreateWindow("10-2");
  
  glutDisplayFunc(Display);

  glClearColor(0.3, 0.47, 0.8, 1);

  glutMainLoop();
}
