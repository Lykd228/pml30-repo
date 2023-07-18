#pragma once
#define MAX_SHAPE 10000
class shape
{
public:
	virtual void Draw(void)
	{}
	virtual void Response(double time)
	{}
};