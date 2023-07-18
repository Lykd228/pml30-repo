#include <stdio.h>
#include "wday.h"

int GetWeekDay( int D, int M, int Y )
{
  if (M > 2)
    M++;
  else
  {
    M += 13;
    Y--;
  }
  return (36525 * Y / 100 + 306 * M / 10 + D - 621050) % 7;
}

void PrintWeekDay( int WD )
{
  if (WD == 0)
    printf("Monday\n");
  else if (WD == 1)
    printf("Tuesday\n");
  else if (WD == 2)
    printf("Wednesday\n");
  else if (WD == 3)
    printf("Thursday\n");
  else if (WD == 4)
    printf("Friday\n");
  else if (WD == 5)
    printf("Saturday\n");
  else
    printf("Sunday\n");
}
