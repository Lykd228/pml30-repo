#include "glut.h"
#include "life.h"

#define FRAME_W 136
#define FRAME_H 76

unsigned char Frame[FRAME_H][FRAME_W][3];

void PutPixel( int x, int y, int r, int g, int b )
{
  if (x < 0 || x >= FRAME_W || y < 0 || y >= FRAME_H)
    return;
  Frame[y][x][0] = b;
  Frame[y][x][1] = g;
  Frame[y][x][2] = r;
}

void Display( void )
{
  glClear(GL_COLOR_BUFFER_BIT);

  Step();
  
  glRasterPos2d(-1, 1);
  glPixelZoom(10, -10);
  glDrawPixels(FRAME_W, FRAME_H, GL_BGR_EXT, GL_UNSIGNED_BYTE, Frame);

  glFinish();
  glutSwapBuffers();
  glutPostRedisplay();
}

void Keyboard( unsigned char Key, int X, int Y )
{
  if (Key == 27)
    exit(0);
}

void main( int argc, char *argv[] )
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(FRAME_W * 10, FRAME_H * 10);
  glutCreateWindow("Life");
  
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glClearColor(0, 0, 0, 1);
  
  Init();

  glutMainLoop();
}
