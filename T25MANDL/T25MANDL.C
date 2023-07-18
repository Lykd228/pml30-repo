/* Usharova Milana, 10-5, group B, 04.02.2022 */
#include <glut.h>
#include "cmpl.h"

#define FRAME_W 800
#define FRAME_H 600

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
  double X0, Y0, X1, Y1;
  int xs, ys, n;
  CMPL Z;

  glClear(GL_COLOR_BUFFER_BIT);

  X0 = Y0 = -2, X1 = Y1 = 2;
  for (ys = 0; ys < FRAME_H; ys++)
    for (xs = 0; xs < FRAME_W; xs++)
    {
      Z = CmplSet(xs * (X1 - X0) / FRAME_W + X0,
                  ys * (Y1 - Y0) / FRAME_H + Y0);
      n = Mandelbrot(Z);
      PutPixel(xs, ys, n * 3, n * 30, n * 8);
    }
  
  glRasterPos2d(-1, 1);
  glPixelZoom(1, -1);
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
  glutInitWindowSize(FRAME_W, FRAME_H);
  glutCreateWindow("Mandelbrot");
  
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glClearColor(0, 0, 0, 1);

  glutMainLoop();
}
