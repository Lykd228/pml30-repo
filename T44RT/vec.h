#ifndef __vec_h_
#define __vec_h_

#include <cmath>
#include <cassert>

typedef double dbl;
typedef unsigned char uchar;

template<typename type>
class vec
{
private:
	type X, Y, Z;
public:
	vec(void)
	{}
	vec(type A, type B, type C) : X(A), Y(B), Z(C)
	{}
	explicit vec(type A) : X(A), Y(A), Z(A)
	{}
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
		return vec(X * V.X, Y * V.Y, Z * V.Z);
	}
	vec& operator*=(const vec& V)
	{
		X *= V.X;
		Y *= V.Y;
		Z *= V.Z;
		return *this;
	}
	vec operator*(type N) const
	{
		return vec(X * N, Y * N, Z * N);
	}
	vec& operator*=(type N)
	{
		X *= N;
		Y *= N;
		Z *= N;
		return *this;
	}
	type operator&(const vec& V) const
	{
		return X * V.X + Y * V.Y + Z * V.Z;
	}
	vec operator%(const vec& V) const
	{
		return vec(Y * V.Z - Z * V.Y, Z * V.X - X * V.Z, X * V.Y - Y * V.X);
	}
	type& operator[](int I) const
	{
		assert(I >= 0 && I <= 2);
		return *(&X + I);
	}
	const type operator[](int I) const
	{
		assert(I >= 0 && I <= 2);
		return *(&X + I);
	}
	static type R0(void)
	{
		return rand() / reinterpret_cast<type>(RAND_MAX);
	}
	static type R1(void)
	{
		return 2 * rand() / reinterpret_cast<type>(RAND_MAX) - 1;
	}
	static vec Rnd0(void)
	{
		return vec(R0(), R0(), R0());
	}
	static vec Rnd1(void)
	{
		return vec(R1(), R1(), R1());
	}
	type Len(void) const
	{
		return sqrt(reinterpret_cast<dbl>(X * X + Y * Y + Z * Z));
	}
	type operator!(void) const
	{
		return this->Len();
	}
	vec Normalize(void) const
	{
		if (type L = this->Len(); L != 0 && L != 1)
			return vec(X / L, Y / L, Z / L);
		return *this;
	}
};

#endif // __vec_h_
