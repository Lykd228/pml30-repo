#include <stdio.h>
#include "wday.h"

void main( void )
{
  int d, m, y;

  printf("Day:");
  scanf("%i", &d);
  printf("Month:");
  scanf("%i", &m);
  printf("Year:");
  scanf("%i", &y);
  PrintWeekDay(GetWeekDay(d, m, y));
  getchar();
  getchar();
}
