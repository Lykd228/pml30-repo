#include <stdlib.h>
#include <glut.h>

#define FRAME_W 192
#define FRAME_H 108

unsigned char Frame[FRAME_H][FRAME_W][3];

void Display( void )
{
  glClear(GL_COLOR_BUFFER_BIT);

  Frame[rand() % FRAME_H][rand() % FRAME_W][0] = rand() % 256;
  Frame[rand() % FRAME_H][rand() % FRAME_W][1] = rand() % 256;
  Frame[rand() % FRAME_H][rand() % FRAME_W][2] = rand() % 256;

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
  glutCreateWindow("09-2 forever!!!");
  
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glClearColor(0.30, 0.47, 0.8, 1);

  glutMainLoop();
}
