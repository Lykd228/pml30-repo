/* Orlov Maxim, 11-5, 04.02.2023 */
#include "vec.h"
#include "shape.h"
#include <glut.h>
#include <iostream>

using namespace std;
class cube : public shape
{
  vec pos;
  double a;
public:
  cube(double a = 0) : a(a)
  {}

  void Draw(void)
  {
    glPushMatrix();
    glColor3d(0.8, 0.85, 0.95);
    glutSolidCube(a);
    glPopMatrix();
  }
};

class sphere : public shape
{
  vec pos;
  double R;

public:
  sphere(vec pos = vec::rnd0(), double R = vec::frnd0()) : pos(pos), R(R)
  {}
  void Draw(void)
  {
    glPushMatrix();
    glColor3d(1, 1, 1);
    glTranslated(pos.X, pos.Y, pos.Z);
    glutSolidSphere(R, 10, 10);
    glPopMatrix();
  }
};

class snowman : public shape
{
  vec pos, orig_pos;
  double time;
public:
  snowman(vec pos = vec::rnd0()) : orig_pos(pos)
  {}
  void Draw(void)
  {
    glPushMatrix();
    glColor3d(1, 1, 1);
    glTranslated(pos.X, pos.Y, pos.Z);
    glutSolidSphere(1, 15, 15);
    glPopMatrix();

    glPushMatrix();
    glTranslated(pos.X, pos.Y + 1.4, pos.Z);
    glutSolidSphere(0.65, 15, 15);
    glPopMatrix();

    glPushMatrix();
    glTranslated(pos.X, pos.Y + 2.4, pos.Z);
    glutSolidSphere(0.4, 15, 15);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1, 0, 0);
    glTranslated(pos.X + 0.4, pos.Y + 2.6, pos.Z);

    glRotated(90, pos.X * cos(time), pos.Y, pos.Z * cos(time));
    glutSolidCone(0.07, 0.2, 15, 15);
    glPopMatrix();

    glPushMatrix();
    glTranslated(pos.X + 0.2, pos.Y + 2.65, pos.Z + 0.18);
    glColor3d(0, 0, 0);
    glRotated(cos(time) * 180, pos.X * cos(time), pos.Y, pos.Z * cos(time));
    glutSolidSphere(0.05, 15, 15);
    glPopMatrix();

    glPushMatrix();
    glTranslated(pos.X + 0.2, pos.Y + 2.65, pos.Z - 0.18);
    glColor3d(0, 0, 0);
    glRotated(cos(time) * 180, pos.X * cos(time), pos.Y, pos.Z * cos(time));
    glutSolidSphere(0.05, 15, 15);
    glPopMatrix();
  }

  void Response(double Time)
  {
    pos.Z = orig_pos.Z;
    pos.Y = orig_pos.Y;
    pos.X = orig_pos.X;
    time = Time;
  }
};

class tree : public shape
{
  vec pos, orig_pos;
  double time;
public:
  tree(vec pos = vec::rnd0()) : orig_pos(pos)
  {}
  void Draw(void)
  {
    glPushMatrix();
    glColor3d(1, 0.8, 0);
    glTranslated(pos.X, pos.Y, pos.Z);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0, 1, 0.6);
    glRotated(cos(time) * 10, pos.X, pos.Y, pos.Z);
    glTranslated(pos.X, pos.Y + 1, pos.Z);
    glRotated(270, 1, 0, 0);
    glutSolidCone(2, 2, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0, 1, 0.6);
    glRotated(cos(time) * 60, pos.X, pos.Y, pos.Z);
    glTranslated(pos.X, pos.Y + 2.5, pos.Z);
    glRotated(270, 1, 0, 0);
    glutSolidCone(1.5, 2, 50, 50);
    glPopMatrix();
  }

  void Response(double Time)
  {
    pos.Z = orig_pos.Z;
    pos.Y = orig_pos.Y;
    pos.X = orig_pos.X;
    
    time = Time;
  }
};

class pig : public shape
{
  vec pos, orig_pos;
  double time;
public:
  pig(vec pos = vec::rnd0()) : orig_pos(pos)
  {}

  void Draw(void)
  {
    glPushMatrix();
    glColor3d(1, 0.75, 0.79);
    glRotated(cos(time) * 45, pos.X, pos.Y, pos.Z);
    glTranslated(pos.X, pos.Y, pos.Z);
    glutSolidSphere(0.7, 15, 15);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1, 0.75, 0.79);
    glRotated(cos(time) * 45, pos.X, pos.Y, pos.Z);
    glTranslated(pos.X, pos.Y, pos.Z - 0.7);
    glutSolidSphere(0.7, 15, 15);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1, 0.75, 0.79);
    glRotated(cos(time) * 45, pos.X, pos.Y, pos.Z);
    glTranslated(pos.X, pos.Y + 0.65, pos.Z + 0.2);
    glutSolidSphere(0.45, 15, 15);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0, 0, 0);
    glRotated(cos(time) * 45, pos.X, pos.Y, pos.Z);
    glTranslated(pos.X + 0.7, pos.Y + 0.05, pos.Z + 0.1);
    glutSolidSphere(0.15, 15, 15);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0, 0, 0);
    glRotated(cos(time) * 45, pos.X, pos.Y, pos.Z);
    glTranslated(pos.X + 0.7, pos.Y + 0.05, pos.Z - 0.8);
    glutSolidSphere(0.15, 15, 15);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0, 0, 0);
    glRotated(cos(time) * 45, pos.X, pos.Y, pos.Z);
    glTranslated(pos.X - 0.7, pos.Y + 0.05, pos.Z + 0.1);
    glutSolidSphere(0.15, 15, 15);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0, 0, 0);
    glRotated(cos(time) * 45, pos.X, pos.Y, pos.Z);
    glTranslated(pos.X - 0.7, pos.Y + 0.05, pos.Z - 0.8);
    glutSolidSphere(0.15, 15, 15);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1, 0.75, 0.79);
    glRotated(cos(time) * 45, pos.X, pos.Y, pos.Z);
    glTranslated(pos.X, pos.Y + 0.6, pos.Z - 1);
    glutSolidSphere(0.15, 15, 15);
    glPopMatrix();
  }

  void Response(double Time)
  {
    pos.Z = orig_pos.Z + 5 * sin(2 * Time);
    pos.Y = orig_pos.Y;
    pos.X = orig_pos.X + 5 * cos(2 * Time);
    time = Time;
  }
};

class snowflake : public shape
{
  vec pos, orig_pos;
  int havefckfallen;
  int timesMelt;
  int TimeFirstMelt;
  double radius;
  bool flag;
public:
  snowflake(void) : orig_pos(pos)
  {
    Reset();
    timesMelt = 0;
    TimeFirstMelt = 0;
    radius = 0.2;
  }
  void Draw(void)
  {
    glPushMatrix();
    glColor3d(1, 1, 1);
    glTranslated(pos.X, pos.Y, pos.Z);
    glutSolidSphere(radius, 15, 15);
    glPopMatrix();
  }
  void Reset()
  {
    radius = 0.8 / (rand() % 5 + 1);
    orig_pos = vec(rand() % 50 - 20, rand() % 30 + 29, rand() % 50 - 10);
    flag = false;
  }
  void Response(double Time)
  {
    if (!flag)
      pos.Y = orig_pos.Y - 3.5 * (Time - TimeFirstMelt * timesMelt);
    if (Time - havefckfallen >= 1 && flag)
    {
      Reset();
      pos.Y = orig_pos.Y;
      ++timesMelt;
      if (TimeFirstMelt == 0)
        TimeFirstMelt = Time;
    }
    if (pos.Y < 20)
    {
      flag = true;
      havefckfallen = Time;
      pos.Y = 20;
    }

    pos.Z = orig_pos.Z;
    pos.X = orig_pos.X;
  }
};
