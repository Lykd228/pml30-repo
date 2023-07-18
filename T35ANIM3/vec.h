
//#include <windows.h>
//#include "glut.h"
#include <iostream>
//#include <ctime>
//#include <cmath>

class vec
{
public:
    double x, y, z;
    vec(double x = 0, double y = 0, double z = 0)
        : x(x)
        , y(y)
        , z(z)
    {}
    static float frnd(double min = 0, double max = 1)
    {
        return min + (max - min) * rand() / RAND_MAX;
    }
    static vec rnd(double min = 0, double max = 1)
    {
        return vec(frnd(min, max), frnd(min, max), frnd(min, max));
    }
    vec operator * (double R) const
    {
        return vec(x * R, y * R, z * R);
    }
    vec operator + (const vec &v) const
    {
        return vec(x + v.x, y + v.y, z + v.z);
    }
};
