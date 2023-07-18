#include <stdio.h>
#include <conio.h>
#include "list2.h"

void GetStr( char *str, int max )
{
  char ch;
  int i = 0;

  while ((ch = getchar()) != '\n')
    if (str != NULL && i < max - 1)
      str[i++] = ch;
  if (str != NULL && i < max)
    str[i] = 0;
}

void main( void )
{
  int run = 1;
  LIST *L = NULL;
  char s[MAX];

  SetDbgMemHooks();

  while (run)
  {
    printf("\n");
    DisplayList(L);
    printf("0. exit\n"
      "1. add to begin\n"
      "2. del from begin\n"
      "3. add to end\n"
      "4. del from end\n"
      "7. shift prev\n"
      "8. shift next\n"
      "9. clear list\n"
      "Enter your choice:\n");
    switch (_getch())
    {
    case '0':
      run = 0;
      break;
    case '1':
      printf("New string:");
      GetStr(s, sizeof(s));
      if (AddToListFront(&L, s))
        printf("Ok\n");
      else
        printf("Fail\n");
      break;
    case '2':
      if (DelFromListFront(&L))
        printf("Deleted\n");
      else
        printf("Nothing to delete\n");
      break;
    case '3':
      printf("New string:");
      GetStr(s, sizeof(s));
      if (AddToListBack(&L, s))
        printf("Ok\n");
      else
        printf("Fail\n");
      break;
    case '4':
      if (DelFromListBack(&L))
        printf("Deleted\n");
      else
        printf("Nothing to delete\n");
      break;
    case '7':
      ShiftPrev(&L);
      break;
    case '8':
      ShiftNext(&L);
      break;
    case '9':
      ClearList(&L);
      printf("List cleared\n");
      break;
    default:
      printf("Incorrect choice\n");
    }
  }
  ClearList(&L);
}