#include <stdio.h>

int IsBissextile( int Year )
{
  if (Year % 4 == 0 && (Year % 100 != 0 || Year % 400 == 0))
    return 1;
  return 0;
}

void main( void )
{
  int Year;

  printf("Year:");
  scanf("%i", &Year);
  if (IsBissextile(Year))
    printf("%i is bissextile\n", Year);
  else
    printf("%i is not bissextile\n", Year);
  getchar();
  getchar();
}