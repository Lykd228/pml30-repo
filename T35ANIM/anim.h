#include <glut.h>
#include <time.h>
#include "shape.h"
#include "scene.h"
#include "windows.h"

class animation
{
private:
  static animation Instance;
  double SyncTime;
  scene Scene;

  animation(void)
  {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Bebra");

    glutDisplayFunc(Display);
    glutKeyboardFunc(Keyboard);
    glutReshapeFunc(Reshape);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
  }

  static void Display(void)
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1, 0.1, 0.1, 1);

    Instance.Scene.Draw();
    Idle();

    glFinish();
    glutSwapBuffers();
    glutPostRedisplay();
  }

  static void Keyboard(unsigned char Key, int X, int Y)
  {
    if (Key == 27)
      exit(0);
  }

  static void Reshape(int W, int H)
  {
    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, (double)W / H, 1, 800);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(150, 90, 150, 0, 0, 0, 0, 1, 0);
  }

public:
  static animation& Get(void)
  {
    return Instance;
  }

  void Run()
  {
    glutMainLoop();
  }

  static void Idle(void)
  {
    Instance.SyncTime = 1. * clock() / CLOCKS_PER_SEC;
    Instance.Scene.Response(Instance.SyncTime);
  }

  animation& operator << (shape* p)
  {
    Scene << p;
    return *this;
  }
};
