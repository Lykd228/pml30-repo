#include <stdio.h>
#include <conio.h>
#include "fur.h"

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
  char fn[MAX_STR];
  TREE *ExSys;

  SetDbgMemHooks();
  system("chcp 1251");
  LoadTree("M.Orlov.DB", &ExSys); /* ExSys = Init("свинья", NULL, NULL); */

  while (run)
  {
    printf("\n");
    printf("0. exit\n"
      "1. session\n"
      "2. draw tree\n"
      "3. save tree\n"
      "4. load tree\n");
    switch (_getch())
    {
    case '0':
      run = 0;
      break;
    case '1':
      Session(&ExSys);
      break;
    case '2':
      DrawTree(ExSys, 0);
      break;
    case '3':
      printf("Filename:");
      GetStr(fn, MAX_STR);
      if (SaveTree(fn, ExSys))
        printf("Ok\n");
      else
        printf("Fail\n");
      break;
    case '4':
      printf("Filename:");
      GetStr(fn, MAX_STR);
      if (LoadTree(fn, &ExSys))
        printf("Ok\n");
      else
        printf("Fail\n");
      break;
    default:
      printf("Incorrect choice\n");
    }
  }
  SaveTree("M.Orlov.DB", ExSys);
  ClearTree(&ExSys);
}
