#include <time.h>
#include "wmill.h"

int *TexNames, angle = 10, speed = 2;

void Display( void )
{
  double t = clock() / (double)CLOCKS_PER_SEC;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  
  gluLookAt(25, 27, 30, 0, 0, 0, 0, 1, 0);

  DrawWindMill(angle, t * speed);

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}

void Keyboard( unsigned char Key, int X, int Y )
{
  switch (Key)
  {
  case 27:
    exit(0);
    break;
  case '+':
    speed += (speed < 20 ? 1 : 0);
    break;
  case '-':
    speed -= (speed > 1 ? 1 : 0);
    break;
  }
}

void Arrows( int Key, int X, int Y )
{
  switch (Key)
  {
  case GLUT_KEY_LEFT:
    angle -= 10;
    break;
  case GLUT_KEY_RIGHT:
    angle += 10;
    break;
  }
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
  int i;
  char *pics[] =
  {
    "X:\\PICS\\BRICK.G24",
    "X:\\PICS\\LOGO30.G24",
    "X:\\PICS\\M.G24",
    "X:\\PICS\\GRASS.G24",
    "X:\\PICS\\SKYTST.G24",
    "X:\\PICS\\S1.G24"
  };

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(800, 600);
  glutCreateWindow("M.Orlov WMILL");
  
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
  glutSpecialFunc(Arrows);
  glutReshapeFunc(Reshape);

  glClearColor(0.3, 0.47, 0.8, 1);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_NORMALIZE);

  if ((TexNames = malloc(6*sizeof(int))) == NULL)
    return;
  glEnable(GL_TEXTURE_2D);
  glGenTextures(6, TexNames);
  for (i = 0; i < 6; i++)
  {
    glBindTexture(GL_TEXTURE_2D, TexNames[i]);
    LoadTex(pics[i]);
  }
  glDisable(GL_TEXTURE_2D);

  glutMainLoop();
}
