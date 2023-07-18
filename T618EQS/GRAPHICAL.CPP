#include "glut.h"

#define FRAME_W 1360
#define FRAME_H 760

void Display( void );

unsigned char Frame[FRAME_H][FRAME_W][3];

void PutPixel( int x, int y, int r, int g, int b )
{
  if (x < 0 || x >= FRAME_W || y < 0 || y >= FRAME_H)
    return;
  Frame[y][x][0] = b;
  Frame[y][x][1] = g;
  Frame[y][x][2] = r;
}

void Keyboard( unsigned char Key, int X, int Y )
{
  if (Key == 27)
    exit(0);
}

void Mouse( int Button, int State, int MouseX, int MouseY )
{
  int TSK_MButtons = 0;
  
  if (Button == GLUT_LEFT_BUTTON)
  {
    if (State == GLUT_DOWN)
      TSK_MButtons = 1;
    else
      TSK_MButtons = 0;
  }

  if (TSK_MButtons)
    exit(12); /* do something */
}

void main( int argc, char *argv[] )
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(FRAME_W, FRAME_H);
  glutCreateWindow("T618");
  
  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);
  glutMouseFunc(Mouse);

  glClearColor(0, 0, 0, 1);

  glutMainLoop();
}
