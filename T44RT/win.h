#ifndef __win_h_
#define __win_h_

#include <time.h>
#include "scene.h"

class anim
{
private:
    static double SyncTime;
    static frame View;
    static camera<dbl> C;
    static scene S;

    anim(const char* Title = "Ray tracing wtf")
    {
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
        glutInitWindowPosition(0, 0);
        glutInitWindowSize(400, 400);
        glutCreateWindow(Title);
        glutDisplayFunc(Display);
        glutReshapeFunc(Reshape);
        glutKeyboardFunc(Keyboard);

        View.SetSize(100, 100);
        C.Resize(100, 100);
        C.SetProj(0.5, 0.5);
        C.Set(vec<dbl>(0), vec<dbl>(0), vec<dbl>(0, 1, 0));
    }
    static void Display(void)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        View.Draw();
        glFinish();
        glutSwapBuffers();
        glutPostRedisplay();
    }
    static void Reshape(int W, int H)
    {
        View.SetSize(W, H);
        C.Resize(W, H);
    }
    static void Keyboard(unsigned char Key, int X, int Y)
    {
        switch (Key)
        {
        case 27:
            exit(0);
            break;
        case 'R':
            S.Render(C, View);
            break;
        }
    }
    static anim animation;
public:
    void Run(void)
    {
        glutMainLoop();
    }
    static anim& Get(void)
    {
        return animation;
    }
};

#endif // __win_h_
