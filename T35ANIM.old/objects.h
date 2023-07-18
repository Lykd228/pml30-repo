#pragma once
#include "vec.h"
#include "shape.h"
#include "glut.h"
#include <iostream>
using namespace std;
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
		glTranslated(pos.x, pos.y, pos.z);
		glutSolidSphere(1, 15, 15);
		glPopMatrix();

		glPushMatrix();
		glTranslated(pos.x, pos.y + 1.4, pos.z);
		glutSolidSphere(0.65, 15, 15);
		glPopMatrix();

		glPushMatrix();
		glTranslated(pos.x, pos.y + 2.4, pos.z);
		glutSolidSphere(0.4, 15, 15);
		glPopMatrix();

		glPushMatrix();
		glColor3d(1, 0, 0);
		glTranslated(pos.x + 0.4, pos.y + 2.6, pos.z);
		//glRotated(90, pos.x, pos.y, pos.z);
		glRotated(90, pos.x * cos(time), pos.y, pos.z * cos(time));
		glutSolidCone(0.07, 0.2, 15, 15);
		glPopMatrix();

		glPushMatrix();
		glTranslated(pos.x + 0.2, pos.y + 2.65, pos.z + 0.18);
		glColor3d(0, 0, 0);
		glRotated(cos(time) * 180, pos.x * cos(time), pos.y, pos.z * cos(time));
		glutSolidSphere(0.05, 15, 15);
		glPopMatrix();

		glPushMatrix();
		glTranslated(pos.x + 0.2, pos.y + 2.65, pos.z - 0.18);
		glColor3d(0, 0, 0);
		glRotated(cos(time) * 180, pos.x * cos(time), pos.y, pos.z * cos(time));
		glutSolidSphere(0.05, 15, 15);
		glPopMatrix();
	}

	void Response(double Time)
	{
		pos.z = orig_pos.z;
		pos.y = orig_pos.y;
		pos.x = orig_pos.x;
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
		//glRotated(fabs(cos(time) * 90), pos.x, pos.y, pos.z);
		glTranslated(pos.x, pos.y, pos.z);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glColor3d(0, 1, 0.6);
		glRotated(cos(time) * 10, pos.x, pos.y, pos.z);
		glTranslated(pos.x, pos.y + 1, pos.z);
		glRotated(270, 1, 0, 0);
		glutSolidCone(2, 2, 50, 50);
		glPopMatrix();

		glPushMatrix();
		glColor3d(0, 1, 0.6);
		glRotated(cos(time) * 60, pos.x, pos.y, pos.z);
		glTranslated(pos.x, pos.y + 2.5, pos.z);
		glRotated(270, 1, 0, 0);
		glutSolidCone(1.5, 2, 50, 50);
		glPopMatrix();

	}

	void Response(double Time)
	{
		pos.z = orig_pos.z;
		pos.y = orig_pos.y;
		pos.x = orig_pos.x;
		
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
		glRotated(cos(time) * 45, pos.x, pos.y, pos.z);
		glTranslated(pos.x, pos.y, pos.z);
		glutSolidSphere(0.7, 15, 15);
		glPopMatrix();

		glPushMatrix();
		glColor3d(1, 0.75, 0.79);
	    glRotated(cos(time) * 45, pos.x, pos.y, pos.z);
		glTranslated(pos.x, pos.y, pos.z - 0.7);
		glutSolidSphere(0.7, 15, 15);
		glPopMatrix();

		glPushMatrix();
		glColor3d(1, 0.75, 0.79);
		glRotated(cos(time) * 45, pos.x, pos.y, pos.z);
		glTranslated(pos.x, pos.y + 0.65, pos.z + 0.2);
		glutSolidSphere(0.45, 15, 15);
		glPopMatrix();

		glPushMatrix();
		glColor3d(0, 0, 0);
		glRotated(cos(time) * 45, pos.x, pos.y, pos.z);
		glTranslated(pos.x + 0.7, pos.y + 0.05, pos.z + 0.1);
		glutSolidSphere(0.15, 15, 15);
		glPopMatrix();

		glPushMatrix();
		glColor3d(0, 0, 0);
		glRotated(cos(time) * 45, pos.x, pos.y, pos.z);
		glTranslated(pos.x + 0.7, pos.y + 0.05, pos.z - 0.8);
		glutSolidSphere(0.15, 15, 15);
		glPopMatrix();

		glPushMatrix();
		glColor3d(0, 0, 0);
		glRotated(cos(time) * 45, pos.x, pos.y, pos.z);
		glTranslated(pos.x - 0.7, pos.y + 0.05, pos.z + 0.1);
		glutSolidSphere(0.15, 15, 15);
		glPopMatrix();

		glPushMatrix();
		glColor3d(0, 0, 0);
		glRotated(cos(time) * 45, pos.x, pos.y, pos.z);
		glTranslated(pos.x - 0.7, pos.y + 0.05, pos.z - 0.8);
		glutSolidSphere(0.15, 15, 15);
		glPopMatrix();

		glPushMatrix();
		glColor3d(1, 0.75, 0.79);
		glRotated(cos(time) * 45, pos.x, pos.y, pos.z);
		glTranslated(pos.x, pos.y + 0.6, pos.z - 1);
		glutSolidSphere(0.15, 15, 15);
		glPopMatrix();
	}

	void Response(double Time)
	{
		pos.z = orig_pos.z + 5 * sin(2 * Time);
		pos.y = orig_pos.y;
		pos.x = orig_pos.x + 5 * cos(2 * Time);
		//glRotated(Time, 1, 1, 1);
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
		glTranslated(pos.x, pos.y, pos.z);
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
			pos.y = orig_pos.y - 3.5 * (Time - TimeFirstMelt * timesMelt);
		if (Time - havefckfallen >= 1 && flag)
		{
			Reset();
			pos.y = orig_pos.y;
			++timesMelt;
			if (TimeFirstMelt == 0)
				TimeFirstMelt = Time;
		}
		if (pos.y < 20)
		{
			flag = true;
			havefckfallen = Time;
			pos.y = 20;
		}

		pos.z = orig_pos.z;
		pos.x = orig_pos.x;
	}

};
