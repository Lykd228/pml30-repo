#include <stdio.h>
#include "qust.h"

/* add to queue */
int Put( QUEUE *Q, int NewData )
{
  LIST *NewElement = malloc(sizeof(LIST));

  if (NewElement == NULL)
    return 0;
  NewElement->Data = NewData;
  NewElement->Next = NULL;
  if (Q->Head == NULL)
    Q->Head = Q->Tail = NewElement;
  else
    Q->Tail->Next = NewElement, Q->Tail = NewElement;
  return 1;
}

/* remove from queue */
int Get( QUEUE *Q, int *OldData )
{
  LIST *OldElement = Q->Head;
      
  if (OldElement == NULL)
    return 0;
  Q->Head = Q->Head->Next;

  if (OldData != NULL)
    *OldData = OldElement->Data;
  free(OldElement);
  return 1;
}

/* add to stack */
int Push( STACK *S, int NewData )
{
  LIST *NewElement = malloc(sizeof(LIST));

  if (NewElement == NULL)
    return 0;
  NewElement->Data = NewData;
  NewElement->Next = S->Top;
  S->Top = NewElement;
  return 1;
}

/* remove from stack */
int Pop( STACK *S, int *OldData )
{
  LIST *OldElement = S->Top;
      
  if (OldElement == NULL)
    return 0;
  S->Top = S->Top->Next;

  if (OldData != NULL)
    *OldData = OldElement->Data;
  free(OldElement);
  return 1;
}

void DisplayList( LIST *L )
{
  if (L == NULL)
    printf("<Empty>\n");
  else
    while (L != NULL)
    {
      printf("%i", L->Data);
      printf((L = L->Next) == NULL ? "\n" : ",");
    }
}

void ClearList( LIST **L )
{
  LIST *OldElement = *L;

  while (OldElement != NULL)
  {
    *L = (*L)->Next;
    free(OldElement);
    OldElement = *L;
  }
}

void DisplayStack( STACK *S )
{
  DisplayList(S->Top);
}

void DisplayQueue( QUEUE *Q )
{
  DisplayList(Q->Head);
}

void ClearStack( STACK *S )
{
  ClearList(&S->Top);
}

void ClearQueue( QUEUE *Q )
{
  ClearList(&Q->Head);
}
