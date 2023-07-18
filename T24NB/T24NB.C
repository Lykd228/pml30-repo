#include "nb.h"

#define MAX 50

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
  int run = 1, DBSize = 0, i;
  static PUPIL DB[MAX], tmp;
  char fname[255];

  while (run)
  {
    printf("Database work:\n"
      "1. Read new pupil\n"
      "2. Delete pupil\n"
      "3. Print out all people\n"
      "4. Sort people\n"
      "5. Reverse people list\n"
      "6. Save list to file\n"
      "7. Load list from file\n"
      "0. Exit\n"
      "Enter your choice:\n");
    switch (_getch())
    {
    case '0':
      run = 0;
      break;
    case '1':
      if (DBSize < MAX)
        ReadPupil(&DB[DBSize++]);
      else
        printf("Not enough room\n");
      break;
    case '2':
      DeletePupil(DB, DBSize--);
      break;
    case '3':
      PrintOut(DB, DBSize);  
      break;
    case '4':
      printf("Sort by:\n"
             "a. by surname + name\n"
             "b. by name\n"
             "c. by age\n"
             "d. by birthday\n");
      SortAny(DB, DBSize, _getch());
      break;
    case '5':
      for (i = 0; i < DBSize / 2; i++)
        Swap(&DB[i], &DB[DBSize - i - 1]);
      break;
    case '6':
      printf("File name for save:");
      GetStr(fname, sizeof fname);
      if (SaveDB(fname, DB, DBSize))
        printf("Ok\n");
      else
        printf("Fail\n");
      break;
    case '7':
      printf("File name for load:");
      GetStr(fname, sizeof fname);
      DBSize = LoadDB(fname, DB, MAX);
      printf("Loaded %i records\n", DBSize);
      break;
    default:
      printf("Incorrect choice\n");
    }
  }
}
