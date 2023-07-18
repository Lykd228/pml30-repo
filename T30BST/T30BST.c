#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "bst.h"

void main( void )
{
  int run = 1, n;
  TREE *Root = NULL;

  SetDbgMemHooks();

  for (n = 1; n <= 15; n++)
    AccessTree(&Root, n);
  while (run)
  {
    printf("\n");
    PutTree(Root);
    printf("\n");
    PutTree1(Root);
    printf("\n");
    printf("0. exit\n"
      "1. access tree\n"
      "2. access tree (no recursion)\n"
      "3. draw tree\n"
      "4. clear tree\n"
      "5. delete from tree\n"
      "6. linearize tree\n"
      "7. balance tree\n"
      "8. gremlin test\n");
    switch (_getch())
    {
    case '0':
      run = 0;
      break;
    case '1':
      printf("Key:");
      scanf("%i", &n);
      if (AccessTree(&Root, n))
        printf("Added: %i\n");
      else
        printf("Not enough memory\n");
      break;
    case '2':
      printf("Key:");
      scanf("%i", &n);
      if (AccessTree1(&Root, n))
        printf("Added: %i\n");
      else
        printf("Not enough memory\n");
      break;
    case '3':
      printf("\n");
      DrawTree(Root, 0);
      break;
    case '4':
      ClearTree(&Root);
      printf("Tree cleared\n");
      break;
    case '5':
      printf("Key:");
      scanf("%i", &n);
      if (DelTree(&Root, n))
        printf("Deleted: %i\n", n);
      else
        printf("Nothing to delete\n");
      break;
    case '6':
      printf("Linearized tree of %i nodes\n", Linearize(&Root));
      break;
    case '7':
      BalanceTree(&Root, Linearize(&Root));
      printf("Tree balanced\n");
      break;
    case '8':
      for (n = 0; n < 100; n++)
        AccessTree1(&Root, rand());
      for (n = 0; n < 50; n++)
        DelTree(&Root, rand());
      BalanceTree(&Root, Linearize(&Root));
      break;
    default:
      printf("Incorrect choice\n");
    }
  }
  ClearTree(&Root);
}