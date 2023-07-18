#include "anim.h"
#include "shape.h"
#include "vec.h"
#include "objects.h"
#include "bezye.h"
#include <iostream>

animation animation::Instance;

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  animation& anim = animation::Get();

  anim << new bezye(5, 5); 
  /* anim << new snowman(vec(7, 20, 0));
  anim << new tree(vec(2, 20, 0));
  anim << new tree(vec(11, 20, 3));
  anim << new tree(vec(11, 20, -4));
  anim << new pig(vec(5, 20, 0));

  for(int i = 0; i < 150; ++i)
    anim << new snowflake(); */
  anim.Run();
}
