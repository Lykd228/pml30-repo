#include "win.h"

anim anim::animation;
int main(void)
{
	anim &animation = anim::Get();
	animation.Run();
	return 0;
}
