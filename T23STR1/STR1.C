#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "str1.h"

char *Load( char *fn )
{
  char *s;
  FILE *F;
  int len = 0, i;

  if ((F = fopen(fn, "r")) == NULL)
    return NULL;
  while(fgetc(F) != EOF)
    len++;
  s = malloc(len + 1);
  rewind(F);
  for (i = 0; i < len; i++)
    s[i] = fgetc(F);
  s[len] = 0;
  return s;
}

int CountDigits( char *str )
{
  int i, len, count = 0;

  len = strlen(str);
  for (i = 0; i < len; i++)
    if (str[i] >= '0' && str[i] <= '9')
      count++;
  return count;
}

int CountAlpha( char *str )
{
  int i, count = 0, len;

  len = strlen(str);
  for (i = 0; i < len; i++)
    if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
      count++;
  return count;
}

int CountLines( char *str )
{
  int i, count = 0, len;

  len = strlen(str);
  for (i = 0; i < len; i++)
    if (str[i] == '\n')
      count++;
  return count;
}

void CountAllLetters( char *str, int *letter )
{
  int i, len;

  for (i = 0; i < 26; i++)
    letter[i] = 0;

  len = strlen(str);
  for (i = 0; i < len; i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
      letter[str[i] - 'a']++;
    if (str[i] >= 'A' && str[i] <= 'Z')
      letter[str[i] - 'A']++;
  }
}

void GetStrStatistic( char *str, int *digit, int *alpha, int *lines, int *letter )
{
  *digit = CountDigits(str);
  *alpha = CountAlpha(str);
  *lines = CountLines(str);
  CountAllLetters(str, letter);
}

int IsSymmetrical( char *str, int e )
{
  int b = 0;

  while (b < e)
    if (str[b++] != str[e--])
      return 0;
  return 1;
}

int IsPalindrom( char *str )
{
  int b = 0, e = strlen(str) - 1;

  while (b < e)
  {
    while(isspace((unsigned char)str[b]))
      b++;
    while(isspace((unsigned char)str[e]))
      e--;
    if (str[b++] != str[e--])
      return 0;
  }
  return 1;
}

void WordCount( char *str, int *words, int *symwords )
{
  int i = 0, begin, end;

  while (str[i] != 0)
  {
    /* find begin and end of each word and handle them as needed */
    while(isspace((unsigned char)str[i]))
      i++;
    if (str[i] != 0)
    {
      begin = i;
      while (str[i] != 0 && !isspace((unsigned char)str[i]))
        i++;
      end = i - 1;
    }
    (*words)++;
    *symwords += IsSymmetrical(str + begin, end - begin);;
  }
}
