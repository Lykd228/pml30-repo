#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "huf.h"

#define MAX 255

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

int main( int argc, char *argv[] )
{
  int ret = 1;
  char Out[MAX], In[MAX];

  system("chcp 1251");
  if (argc == 1)
  {
    int run = 1;

    while (run)
    {
      printf("Huffman (de)compress:\n"
        "1. stat file\n"
        "2. compress file\n"
        "3. decompress file\n"
        "0. exit\n"
        "Enter your choice:\n");
      switch (_getch())
      {
      case '0':
        run = 0;
        break;
      case '1':
        printf("Input file:");
        GetStr(In, MAX);
        if (Stat(In))
          printf("Success\n");
        break;
      case '2':
        printf("Input file:");
        GetStr(In, MAX);
        printf("Output file:");
        GetStr(Out, MAX);
        if (Compress(Out, In))
          printf("Success\n");
        break;
      case '3':
        printf("Input file:");
        GetStr(In, MAX);
        printf("Output file:");
        GetStr(Out, MAX);
        if (Decompress(Out, In))
          printf("Success\n");
        break;
      default:
        printf("Incorrect choice\n");
      }
    }
  }
  else
  {
    switch (argv[1][0])
    {
    case 'c':
      if (Compress(argv[3], argv[2]))
        ret = 0;
      break;
    case 'd':
      if (Decompress(argv[3], argv[2]))
        ret = 0;
      break;
    case 's':
      if (Stat(argv[2]))
        ret = 0;
      break;
    default:
      printf("Incorrect choice\n");
    }
  }
  return 0;
}
