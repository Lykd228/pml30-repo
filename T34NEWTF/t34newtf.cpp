#include <ctime>
#include <cstdlib>
#include <glut.h>
#include "compl.h"

struct frame
{
  static const int Ws = 400, Hs = 400;
  unsigned char Image[Hs][Ws][3];
  double X0, Y0, X1, Y1;

  frame( void ) : X0(-2), Y0(-2), X1(2), Y1(2)
  {
  }

  void Julia( const cmpl &C )
  {
    for (int y = 0; y < Hs; y++)
      for (int x = 0; x < Ws; x++)
      {
        int n = cmpl(x * (X1 - X0) / Ws + X0, y * (Y1 - Y0) / Hs + Y0).Julia(C);
        PutPixel(x, y, n * 20, n * 7, n * 15);
      }
  }

  void Newton( const cmpl &C )
  {
    for (int y = 0; y < Hs; y++)
      for (int x = 0; x < Ws; x++)
      {
        int n = cmpl(x * (X1 - X0) / Ws + X0, y * (Y1 - Y0) / Hs + Y0).Newton(C);
        PutPixel(x, y, n * 23, n * 45, n * 37);
      }
  }

  void Draw( void )
  {
    glDrawPixels(Ws, Hs, GL_BGR_EXT, GL_UNSIGNED_BYTE, Image);
  }

  void PutPixel( int x, int y, int r, int g, int b )
  {
    if (x < 0 || x >= Ws || y < 0 || y >= Hs)
      return;
    Image[y][x][0] = b;
    Image[y][x][1] = g;
    Image[y][x][2] = r;
  }
};

struct anim
{
  static double SyncTime;
  static frame View;

  anim( const char *Title = "30 forever!!!" )
  {
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(400, 400);
    glutCreateWindow(Title);
    glutDisplayFunc(Display);
    glutKeyboardFunc(Keyboard);
  }

  static void Display( void )
  {
    SyncTime = clock() / CLOCKS_PER_SEC;
    glClear(GL_COLOR_BUFFER_BIT);
    View.Newton(tan(SyncTime));
    View.Draw();
    glFinish();
    glutSwapBuffers();
    glutPostRedisplay();
  }

  static void Keyboard( unsigned char Key, int X, int Y )
  {
    if (Key == 27)
      exit(0);
  }

  void Run( void )
  {
    glutMainLoop();
  }
};

double anim::SyncTime;
frame anim::View;

int main( void )
{
  anim("Fractals eeee!").Run();
  return 0;
}
