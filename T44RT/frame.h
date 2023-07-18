#ifndef __frame_h_
#define __frame_h_

#include <glut.h>
#include "ray.h"
#include "camera.h"

typedef uchar pixel[3];

class frame
{
private:
	int Ws, Hs;
	pixel* Image;
public:
	frame(void) : Image(nullptr)
	{}
	frame(int W, int H) : Image(nullptr)
	{
		this->SetSize(W, H);
	}
	void SetSize(int W, int H)
	{
		if (Image != nullptr)
			delete[] Image;
		Image = new pixel[Ws * Hs];
	}
	void Draw(void)
	{
		glDrawPixels(Ws, Hs, GL_BGR_EXT, GL_UNSIGNED_BYTE, Image);
	}
	void PutPixel(int x, int y, int r, int g, int b)
	{
		if (x < 0 || x >= Ws || y < 0 || y >= Hs)
			return;
		Image[y * Ws + x][0] = b;
		Image[y * Ws + x][1] = g;
		Image[y * Ws + x][2] = r;
	}
};

#endif // __frame_h_
