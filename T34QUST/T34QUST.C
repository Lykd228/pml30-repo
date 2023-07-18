#include <conio.h>
#include <stdio.h>
#include "qust.h"

void main( void )
{
  int run = 1, x;
  STACK S = {NULL};
  QUEUE Q = {NULL};

  SetDbgMemHooks();

  while (run)
  {
    printf("Stack: ");
    DisplayStack(&S);
    printf("Queue: ");
    DisplayQueue(&Q);
    printf("0. exit\n"
      "1. put\n"
      "2. get\n"
      "3. push\n"
      "4. pop\n"
      "Enter your choice:\n");
    switch (_getch())
    {
    case '0':
      run = 0;
      break;
    case '1':
      printf("X:");
      scanf("%i", &x);
      if (Put(&Q, x))
        printf("Put: %i\n", x);
      else
        printf("Fail\n");
      break;
    case '2':
      if (Get(&Q, &x))
        printf("Got: %i\n", x);
      else
        printf("Nothing to got\n");
      break;
    case '3':
      printf("X:");
      scanf("%i", &x);
      if (Push(&S, x))
        printf("Pushed: %i\n", x);
      else
        printf("Fail\n");
      break;
    case '4':
      if (Pop(&S, &x))
        printf("Popped: %i\n", x);
      else
        printf("Nothing to pop\n");
      break;
    default:
      printf("Incorrect choice\n");
    }
  }
  ClearStack(&S);
  ClearQueue(&Q);
}
