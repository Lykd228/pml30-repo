#ifndef __scene_h_
#define __scene_h_

#include "frame.h"

class shape
{
	shape(void)
	{}
	virtual dbl Intersect(const ray<dbl>& R) const
	{}
	virtual vec<dbl> GetNormal(const vec<dbl>& P) const
	{}
};

class scene
{
private:
	scene(void)
	{}
public:
	void Render(camera<dbl>& Cam, frame& Frm)
	{}
};

#endif // __scene_h_
