#include <stdio.h>
#include <string.h>
#include "str1.h"

#define MAX 100

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
  char *str, fn[MAX];
  int digit = 0, alpha = 0, lines = 0, i, letter[26], words = 0, symwords = 0;

  printf("Input file name\n");
  GetStr(fn, MAX);
  str = Load(fn);
  if (str == NULL)
  {
    printf("File not found\n");
    return;                           
  }

  GetStrStatistic(str, &digit, &alpha, &lines, letter);
  WordCount(str, &words, &symwords);
  printf("Length: %i\n", strlen(str));
  printf("Numbers: %i\n", digit);
  printf("Letters: %i\n", alpha);
  printf("Lines: %i\n", lines);
  for (i = 0; i < 26; i++)
    printf("%c: %i\n", 'a' + i, letter[i]);

  printf("String is%s symmetrical\n", IsSymmetrical(str, strlen(str) - 1) ? "" : "n't");
  printf("String is%s palindrom\n", IsPalindrom(str) ? "" : "n't");
  printf("Words count: %i\n", words);
  printf("Symmetrical words: %i\n", symwords);
  getchar();
}
