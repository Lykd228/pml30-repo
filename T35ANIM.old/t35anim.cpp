#include "anim.h"
#include "shape.h"
#include "sphere.h"
#include "vec.h"
#include "background.h"
#include "objects.h"
#include <iostream>

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	animation& anim = animation::Get();

	anim << new cube(30); 
	//anim << new sphere(vec(5, 20, 0), 0.7);
	anim << new snowman(vec(7, 20, 0));
	std::cout << "here" << std::endl;
	anim << new tree(vec(2, 20, 0));
	anim << new tree(vec(11, 20, 3));
	anim << new tree(vec(11, 20, -4));
	anim << new pig(vec(5, 20, 0));

	for(int i = 0; i < 150; ++i)
		anim << new snowflake();
	//anim << new sphere(vec(-1, 4, -5), 2);

	anim.Run();

	return 0;
}