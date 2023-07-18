//#include <windows.h>
#include "glut.h"
//#include <iostream>
#include "anim.h"






int main(void)
{
    animation& MyAnim = animation::Get();

    MyAnim << new bez<3,10, 3>();
    MyAnim.Run();
   
    return 0;
}

