#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <glut.h>

void Display( void )
{
  int i;
  double t = 3 * clock() / (double)CLOCKS_PER_SEC;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  
  gluLookAt(-15, 10, 15, 0, 0, 0, 0.3, 1, 0);

  for (i = 0; i < 3; i++)
  {
    glPushMatrix();
    glRotated(120 * i + 20 * t, 0, 1, 0);
    glTranslated(6, 0, 0);
    glColor3d(fmod(0.26 * (i + 1), 1.0), fmod(0.4 * (i + 1), 1.0), fmod(0.55 * (i + 1), 1.0));
    switch (i)
    {
    case 0:
      glPushMatrix();
      glRotated(40 * t, fmod(0.26 * (i + 1), 1.0), fmod(0.4 * (i + 1), 1.0), fmod(0.55 * (i + 1), 1.0));
      glutSolidCube(1);
      glPopMatrix();

      glRotated(40 * t, 0, 1, 0);

      glPushMatrix();
      glTranslated(2.5, 0, 0);
      glRotated(40 * t, fmod(0.2 * (i + 1), 1.0), fmod(0.5 * (i + 1), 1.0), fmod(0.1 * (i + 1), 1.0));
      glColor3d(fmod(0.2 * (i + 1), 1.0), fmod(0.5 * (i + 1), 1.0), fmod(0.1 * (i + 1), 1.0));
      glutSolidCone(0.5, 3, 20, 20);
      glPopMatrix();

      glPushMatrix();
      glTranslated(-2.5, 0, 0);
      glRotated(40 * t, fmod(0.4 * (i + 1), 1.0), fmod(0.1 * (i + 1), 1.0), fmod(0.8 * (i + 1), 1.0));
      glColor3d(fmod(0.5 * (i + 1), 1.0), fmod(0.1 * (i + 1), 1.0), fmod(0.8 * (i + 1), 1.0));
      glutSolidSphere(0.8, 20, 20);
      glPopMatrix();
      break;
    case 1:
      glPushMatrix();
      glRotated(40 * t, fmod(0.26 * (i + 1), 1.0), fmod(0.4 * (i + 1), 1.0), fmod(0.55 * (i + 1), 1.0));
      glutSolidTeapot(1);
      glPopMatrix();

      glRotated(40 * t, 0, 1, 0);

      glPushMatrix();
      glTranslated(2.5, 0, 0);
      glRotated(40 * t, fmod(0.2 * (i + 1), 1.0), fmod(0.5 * (i + 1), 1.0), fmod(0.1 * (i + 1), 1.0));
      glColor3d(fmod(0.2 * (i + 1), 1.0), fmod(0.5 * (i + 1), 1.0), fmod(0.1 * (i + 1), 1.0));
      glScaled(0.5, 0.5, 0.5);
      glutSolidDodecahedron();
      glPopMatrix();

      glPushMatrix();
      glTranslated(-2.5, 0, 0);
      glRotated(40 * t, fmod(0.4 * (i + 1), 1.0), fmod(0.1 * (i + 1), 1.0), fmod(0.8 * (i + 1), 1.0));
      glColor3d(fmod(0.5 * (i + 1), 1.0), fmod(0.1 * (i + 1), 1.0), fmod(0.8 * (i + 1), 1.0));
      glutSolidOctahedron();
      glPopMatrix();
      break;
    case 2:
      glPushMatrix(); /* torus */
      glRotated(40 * t, fmod(0.26 * (i + 1), 1.0), fmod(0.4 * (i + 1), 1.0), fmod(0.55 * (i + 1), 1.0));
      glutSolidTorus(0.3, 1.3, 20, 20);

      glTranslated(1.5, 0, 0);
      glRotated(40 * t, 0, 1, 0);
      glTranslated(-1.5, 0, 0);

      glPushMatrix(); /* icosahedron */
      glScaled(0.4, 0.4, 0.4);
      glRotated(40 * t, fmod(0.2 * (i + 1), 1.0), fmod(0.5 * (i + 1), 1.0), fmod(0.1 * (i + 1), 1.0));
      glColor3d(fmod(0.2 * (i + 1), 1.0), fmod(0.5 * (i + 1), 1.0), fmod(0.1 * (i + 1), 1.0));
      glutSolidIcosahedron();
      glPopMatrix(); /* end of icosahedron */

      glRotated(40 * t, 0, 1, 0);

      glPushMatrix(); /* tetrahedron */
      glTranslated(-1, 0, 0);
      glRotated(40 * t, fmod(0.4 * (i + 1), 1.0), fmod(0.1 * (i + 1), 1.0), fmod(0.8 * (i + 1), 1.0));
      glColor3d(fmod(0.5 * (i + 1), 1.0), fmod(0.1 * (i + 1), 1.0), fmod(0.8 * (i + 1), 1.0));
      glScaled(0.4, 0.4, 0.4);
      glutSolidTetrahedron();
      glPopMatrix(); /* tetrahedron */
      glPopMatrix(); /* end of torus */

      glRotated(40 * t, 0, 1, 0);

      glPushMatrix();
      glTranslated(3, 0, 0);
      glRotated(-80 * t, fmod(0.4 * (i + 1), 1.0), fmod(0.1 * (i + 1), 1.0), fmod(0.8 * (i + 1), 1.0));
      glColor3d(fmod(0.9 * (i + 1), 1.0), fmod(0.9 * (i + 1), 1.0), fmod(0.3 * (i + 1), 1.0));
      glutSolidSphere(0.6, 20, 20);
      glPopMatrix();
      break;
    }
    glPopMatrix();
  }

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}

void Keyboard( unsigned char Key, int X, int Y )
{
  if (Key == 27)
    exit(0);
}

void Reshape( int W, int H )
{
  double size = 0.1, rx = size, ry = size;

  glViewport(0, 0, W, H);
  if (W > H)
    rx *= (double)W / H;
  else
    ry *= (double)H / W;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-rx / 2, rx / 2, -ry / 2, ry / 2, size, 500);
  glMatrixMode(GL_MODELVIEW);
}

void main( int argc, char *argv[] )
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(800, 600);
  glutCreateWindow("T37F3D");
  
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
  glutReshapeFunc(Reshape);

  glClearColor(0.3, 0.47, 0.8, 1);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_NORMALIZE);

  glutMainLoop();
}
