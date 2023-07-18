/* Orlov Maxim, 11-5, 04.02.2023 */
#include "vec.h"
#include "shape.h"
#include <glut.h>
#include <iostream>

class bezye : public shape
{
  int M, split;
  double time, *C;
  vec **P;

public:
  bezye(int size, int parts) : M(size), split(parts)
  {
    C = reinterpret_cast<dbl *>(malloc((M+1)*sizeof(dbl)));
    C[0] = 1;
    for (int i = 1; i <= M; i++)
      C[i] = C[i - 1] * (M - i + 1) / i;
    P = createSquareMass(M+1);
  }

  vec** createSquareMass(int A)
  {
    vec **pointer = reinterpret_cast<vec **>(malloc((A)*sizeof(vec *)));
    for (int i = 0; i < A; i++)
      pointer[i] = reinterpret_cast<vec *>(malloc((A)*sizeof(vec)));
    return pointer;
  }

  void Draw(void)
  {
    // create base points
    srand(228);
    for (int j = 0; j <= M; j++)
      for (int i = 0; i <= M; i++)
        P[j][i] = vec(13. * j, 20 * sin(time + 3 * vec::frnd0()), 13. * i);

    // create all points
    double PS = split*M;
    vec **G = createSquareMass(PS + 1);
    for (int u = 0; u <= PS; u++)
      for (int v = 0; v <= PS; v++)
      {
        vec current(0);
        for (int j = 0; j <= M; j++)
          for (int i = 0; i <= M; i++)
            current += P[j][i] * C[i] * C[j] *
                       pow(1. - u/PS, double(M-i)) * pow(u/PS, double(i)) *
                       pow(1. - v/PS, double(M-j)) * pow(v/PS, double(j));
        G[v][u] = current;
      }

    // try to draw all points
    glColor3d(1, 1, 0);
    for (int j = 0; j <= PS; j++)
      for (int i = 0; i <= PS; i++)
      {
        glPushMatrix();
        G[j][i].Translate();
        glutSolidSphere(1, 10, 10);
        glPopMatrix();
      }
  }

  void Response(double Time)
  {
    time = Time;
  }
};
