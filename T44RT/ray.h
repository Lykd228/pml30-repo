#ifndef __ray_h_
#define __ray_h_

#include "vec.h"

template<typename type>
class ray
{
public:
	vec<type> Org, Dir;

	ray(void)
	{}
	ray(const vec& NewOrg, const ves& NewDir) : Org(NewOrg), Dir(NewDir)
	{}
	vec<type> operator()(type T) const
	{
		return Org + Dir * T;
	}
};

#endif // __ray_h_
