#include <windows.h>
#include "glut.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include "vec.h"

//using namespace std;

#define MAX_SHAPE 1000
class shape
{
public:
    virtual void Draw(void)
    {}
    virtual void Response(double time)
    {}
};

class scene
{
	shape* shapes[MAX_SHAPE];
	int Amount;

public:
	scene(void) : Amount(0) {}
	scene& operator << (shape* p)
	{
		if (Amount == MAX_SHAPE - 1)
		{
			delete p;
			return *this;
		}
		shapes[Amount++] = p;
		return *this;
	}

	void Draw(void)
	{
		for (int i = 0; i < Amount; i++)
			shapes[i]->Draw();
	}

	void Response(double Time)
	{
		for (int i = 0; i < Amount; i++)
			shapes[i]->Response(Time);
	}
};

template <int M = 10, int S = 2, int N = 2, int size = 1>
class bez_pl : public shape
{
    double B1[M][N + 1];
    double B2[M][S + 1];
    vec P[S + 1][N + 1];
    vec C[S + 1][M];
    vec C2[M][M];
    vec Color;
    double dp;
    //vec dp[N + 1];

public:
    bez_pl(void) : Color(vec::rnd(0, 1))
    {
        for (int i = 0; i < S + 1; ++i)
            for (int j = 0; j < N + 1; ++j)
            {
                P[i][j].y = 0;
                P[i][j].z = i * 2;
                P[i][j].x = j * 2;
                dp = 0.1;
                //dp[i] = vec::rnd(0, 0.1);
            }
        check_b_1();
        check_b_2();
        Eval1();
        Eval2();
    }

    int fact(int n)
    {
        int sum = 1;
        for (int i = 2; i <= n; i++)
            sum *= i;
        return sum;
    }
    double c_in_k(int n, int k)
    {
        return fact(n) / (fact(k) * fact(n - k));
    }

    void check_b_1(void)
    {
        int j = 0;
        for (int i = 0; i < M; i++)
        {
            double t = i * 1. / M;
            for (j = 0; j < N + 1; j++)
            {
                B1[i][j] = c_in_k(N, j) * pow(t, j) * pow(1 - t, N - j);
            }
        }
    }
    void check_b_2(void)
    {
        int j = 0;
        for (int i = 0; i < M; i++)
        {
            double t = i * 1. / M;
            for (j = 0; j < S + 1; j++)
            {
                B2[i][j] = c_in_k(S, j) * pow(t, j) * pow(1 - t, S - j);
            }
        }
    }

    void Eval1(void)
    {
        for (int t = 0; t < S + 1; ++t)
            for (int i = 0; i < M; ++i)
            {
                C[t][i] = 0;
                for (int j = 0; j < N + 1; ++j)
                    C[t][i] = C[t][i] + P[t][j] * B1[i][j];
            }
    }

    void Eval2(void)
    {
        for (int t = 0; t < M; ++t)
            for (int i = 0; i < M; ++i)
            {
                C2[t][i] = 0;
                for (int j = 0; j < S + 1; ++j)
                    C2[t][i] = C2[t][i] + C[j][t] * B2[i][j];
            }
    }



    void Draw(void)
    {
        glPushMatrix();
        glColor3d(Color.y, Color.z, Color.x);
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < M; ++j)
            {
                glPushMatrix();
                glTranslated(C2[i][j].x, C2[i][j].y, C2[i][j].z);
                glutSolidSphere(0.1, 20, 20);
                glPopMatrix();
            }
        /*
        glColor3d(1, 1, 1);
        for (int i = 0; i < S + 1; ++i)
            for (int j = 0; j < N + 1; ++j)
            {
                glPushMatrix();
                glTranslated(P[i][j].x, P[i][j].y, P[i][j].z);
                glutSolidSphere(0.2, 20, 20);
                glPopMatrix();
            }
            */
        glPopMatrix();
    }
  
    void Response(double time)
    {
        double old_time = time;
        for (int i = 0; i < S + 1; i++)
            for (int j = 0; j < N + 1; j++)
            {
                P[i][j].y += dp;
                if (abs(P[i][0].y) > 2)
                    dp *= -1;
            }
        Eval1();
        Eval2();
    }
};
template <int M = 3, int N = 2, int size = 15>
class bez: public shape
{
    double B[M][N + 1];
    vec P[N + 1];
    vec C[M];
    vec Color;
    vec dp[N + 1];

public:
    bez(void): Color(vec::rnd(0, 1))
    {
        for (int i = 0; i < N + 1; ++i)
        {
            P[i] = vec::rnd(-size, size);
            dp[i] = vec::rnd(0, 0.1);
         }
        check_b();
        Eval();
    }

    int fact(int n)
    {
        int sum = 1;
        for (int i = 2; i <= n; i++)
             sum *= i;
        return sum;
    }
    double c_in_k(int n, int k)
    {
        return fact(n) / (fact(k) * fact(n - k));
    }

    void check_b(void)
    {
        int j = 0;
        for (int i = 0; i < M; i++)
        {
            double t = i * 1. / M;
            for (j = 0; j < N + 1; j++)
            {
                B[i][j] = c_in_k(N, j) * pow(t, j) * pow(1 - t, N - j);
            }
        }
    }

    void Eval(void)
    {
        for (int i = 0; i < M; i++)
        {
            C[i] = 0;
            for (int j = 0; j < N + 1; j++)
                C[i] = C[i] + P[j] * B[i][j];
        }
    }

    

    void Draw(void)
    {
        glPushMatrix();
        glColor3d(Color.x, Color.y, Color.z);
        for (int i = 0; i < M; i++)
        {
            glPushMatrix();
            glTranslated(C[i].x, C[i].y, C[i].z);
            glutSolidSphere(0.4, 20, 20);
            glPopMatrix();
        }
        /*
        glColor3d(1, 1, 1);
        for (int i = 0; i < N + 1; ++i)
        {
            glPushMatrix();
            glTranslated(P[i].x, P[i].y, P[i].z);
            glutSolidSphere(0.5, 20, 20);
            glPopMatrix();
        }
        */
        //glPopMatrix();
    }
    
    void Response(double time)
    {
        for (int i = 0; i < N + 1; i++)
        {
            P[i] = P[i] + dp[i];
            if (abs(P[i].x) > size)
                dp[i].x *= -1;
            if (abs(P[i].y) > size)
                dp[i].y *= -1;
            if (abs(P[i].z) > size)
                dp[i].z *= -1;
        }
        Eval();
    }
    
};


class animation
{
	animation(void) : Synctime(0)
	{
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowPosition(0, 0);
        glutInitWindowSize(500, 500);

        glutCreateWindow("");

        glutDisplayFunc(Display);
        glutKeyboardFunc(Keyboard);
        glutReshapeFunc(Reshape);
        glutIdleFunc(Idle);

        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_DEPTH_TEST);
	}

    static void Keyboard(BYTE Key, INT X, INT Y)
    {
        if (Key == 27)
            exit(0);
    }
    static void Idle(void)
    {
        Instance.Synctime = (double)clock() / CLOCKS_PER_SEC;
	Instance.Scene.Response(Instance.Synctime);
    }
    static void Reshape(int width, int height)
    {
        glViewport(0, 0, width, height);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(90, (double)width / height, 1, 800);
        glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
		gluLookAt(
			14, 30, 0,
			0, 0, 0,
			0, 1, 0
		);
    }

    static void Display(void)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        Instance.Scene.Draw();
        //Instance.Scene.Response(Instance.Synctime);
        glFinish();
        glutSwapBuffers();
        glutPostRedisplay();
    }
    

    static animation Instance;
    double Synctime;
    //double x = 5, y = 5, z = 0;
    scene Scene;

public: 
    animation& operator << (shape* p)
    {
        Scene << p;
        return *this;
    }
    static animation& Get(void)
    {
        return Instance;
    }
    void Run(void)
    {
        glutMainLoop();
    }
};
