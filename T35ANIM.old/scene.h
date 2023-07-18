#include "shape.h"

class scene
{
	shape* shapes[MAX_SHAPE];
	int Amount;

public:
	scene(void) : Amount(0) {}
	scene& operator << (shape* p)
	{
		if (Amount == MAX_SHAPE - 1)
		{
			delete p;
			return *this;
		}
		shapes[Amount++] = p;
		return *this;
	}

	void Draw(void)
	{
		for (int i = 0; i < Amount; ++i)
			shapes[i]->Draw();
	}

	void Response(double Time)
	{
		for (int i = 0; i < Amount; ++i)
			shapes[i]->Response(Time);
	}
};