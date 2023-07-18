/* Orlov Maxim, 11-5, 04.02.2023 */
#ifndef __vec_h_
#define __vec_h_

#include <glut.h>
#include <cmath>
#include <cassert>

typedef double dbl;
typedef unsigned char uchar;

class vec
{
public:
  dbl X, Y, Z;

  vec(void)
  {}
  vec(dbl A, dbl B, dbl C) : X(A), Y(B), Z(C)
  {}
  explicit vec(dbl A) : X(A), Y(A), Z(A)
  {}

  static double frnd0(void)
  {
    return (1. * rand() / RAND_MAX);
  }
  static vec rnd0(void)
  {
    return vec(frnd0(), frnd0(), frnd0());
  }

  double x(void) {return X;}
  double y(void) {return Y;}
  double z(void) {return Z;}

  void Translate(void)
  {
    glTranslated(X, Y, Z);
  }

  vec operator+(const vec& V) const
  {
    return vec(X + V.X, Y + V.Y, Z + V.Z);
  }
  vec& operator+=(const vec& V)
  {
    X += V.X;
    Y += V.Y;
    Z += V.Z;
    return *this;
  }

  vec operator-(void) const
  {
    return vec(-X, -Y, -Z);
  }
  vec operator-(const vec& V) const
  {
    return *this + -V;
  }
  vec& operator-=(const vec& V)
  {
    return *this += -V;
  }

  vec operator*(const vec& V) const
  {
    return vec(Y * V.Z - Z * V.Y, Z * V.X - X * V.Z, X * V.Y - Y * V.X);
  }
  vec operator*(dbl N) const
  {
    return vec(X * N, Y * N, Z * N);
  }
  vec& operator*=(dbl N)
  {
    X *= N;
    Y *= N;
    Z *= N;
    return *this;
  }
  dbl operator&(const vec& V) const
  {
    return X * V.X + Y * V.Y + Z * V.Z;
  }

  dbl Len(void) const
  {
    return sqrt(X * X + Y * Y + Z * Z);
  }
  dbl operator!(void) const
  {
    return this->Len();
  }
  vec Normalize(void) const
  {
    dbl L = this->Len();
    if (L != 0 && L != 1)
      return vec(X / L, Y / L, Z / L);
    return *this;
  }
};

#endif // __vec_h_
