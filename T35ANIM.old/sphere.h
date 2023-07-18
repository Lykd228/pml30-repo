#pragma once
#include "vec.h"
#include "shape.h"

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
		glTranslated(pos.x, pos.y, pos.z);
		glutSolidSphere(R, 10, 10);
		glPopMatrix();
	}
};