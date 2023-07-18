#ifndef __camera_h_
#define __camera_h_

#include "vec.h"

template<typename type>
class camera
{
public:
	vec<type> Loc, R, U, D;
	int Ws, Hs;
	type Wp, Hp, ProjDist, Size;

	camera(void)
	{}
	camera(int Ws, int Hs)
	{
		this->Resize(Ws, Hs);
	}
	camera& Set(const vec<type>& NewLoc, const vec<type>& At, const vec<type>& U1)
	{
		D = (At - Loc).Normalize();
		R = (D % U1).Normalize();
		U = R % D;
	}
	camera& Resize(int NewWs, int NewHs)
	{
		Ws = NewWs, Hs = NewHs;
		SetProj(ProjDist, Size);
		return *this;
	}
	camera& SetProj(type NewProjDist, type NewSize)
	{
		ProjDist = NewProjDist, Size = NewSize;
		Wp = Size, Hp = Size;
		if (Ws > Hs)
			Wp *= reinterpret_cast<type>(Ws) / Hs;
		else
			Hp *= reinterpret_cast<type>(Hs) / Ws;
		return *this;
	}
	ray<type> FrameRay(type Xs, type Ys) const
	{
		vec<type> A = D * ProjDist, B = R * (Xs * Wp / Ws - Wp / 2), C = U * (Ys * Hp / Hs - Hp / 2);
		vec<type> Dir = A + B + C;
		vec<type> Org = Loc + Dir;
		return ray(Org, Dir);
	}
};

#endif // __camera_h_
