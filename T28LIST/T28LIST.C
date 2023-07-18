#include <conio.h>
#include <stdio.h>
#include "list.h"

void main( void )
{
  int run = 1, x, pos;
  LIST *L = NULL;

  SetDbgMemHooks();

  while (run)
  {
    printf("\nList: ");
    DisplayList(L);
    printf("0. exit\n"
      "1. add to list front\n"
      "2. del from list front\n"
      "3. add to list back\n"
      "4. del from list back\n"
      "5. add to list arbitrary location\n"
      "6. del from list arbitrary location\n"
      "7. list clear\n"
      "Enter your choice:\n");
    switch (_getch())
    {
    case '0':
      run = 0;
      break;
    case '1':
      printf("X:");
      scanf("%i", &x);
      if (AddToListFront(&L, x))
        printf("Added: %i\n", x);
      else
        printf("Fail\n");
      break;
    case '2':
      if (DelFromListFront(&L, &x))
        printf("Deleted: %i\n", x);
      else
        printf("Nothing to delete\n");
      break;
    case '3':
      printf("X:");
      scanf("%i", &x);
      if (AddToListBack(&L, x))
        printf("Added: %i\n", x);
      else
        printf("Fail\n");
      break;
    case '4':
      if (DelFromListBack(&L, &x))
        printf("Deleted: %i\n", x);
      else
        printf("Nothing to delete\n");
      break;
    case '5':
      printf("X:");
      scanf("%i", &x);
      printf("Pos:");
      scanf("%i", &pos);
      if (AddToListArbit(&L, x, pos))
        printf("Added: %i\n", x);
      else
        printf("Fail\n");
      break;
    case '6':
      printf("Pos:");
      scanf("%i", &pos);
      if (DelFromListArbit(&L, &x, pos))
        printf("Deleted %i from position %i\n", x, pos);
      else
        printf("Nothing to delete\n");
      break;
    case '7':
      ClearList(&L);
      printf("List cleared\n");
      break;
    default:
      printf("Incorrect choice\n");
    }
  }
  ClearList(&L);
}
