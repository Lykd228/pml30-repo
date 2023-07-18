#pragma once 
#include "vec.h"

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