#pragma once
#include <cstdlib>

class vec
{
public:
	double x, y, z;
	vec(double v = 0): x(v), y(v), z(v)
	{}
	vec(double x, double y, double z) : x(x), y(y), z(z)
	{}

	static double frnd0(void)
	{
		return (1. * rand() / RAND_MAX);
	}

	static vec rnd0(void)
	{
		return vec(frnd0(), frnd0(), frnd0());
	}
};