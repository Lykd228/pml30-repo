#include <stdio.h>
#include "list.h"

void DisplayList( LIST *L )
{
  if (L == NULL)
    printf("<Empty list>\n");
  else
    while (L != NULL)
    {
      printf("%i", L->Data);
      printf((L = L->Next) == NULL ? "\n" : ",");
    }
}

int AddToListFront( LIST **L, int NewData )
{
  LIST *NewElement;

  if ((NewElement = malloc(sizeof(LIST))) == NULL)
    return 0;
  NewElement->Data = NewData;
  NewElement->Next = *L;

  *L = NewElement;
  return 1;
}

int AddToListBack( LIST **L, int NewData )
{
  LIST *NewElement;

  if ((NewElement = malloc(sizeof(LIST))) == NULL)
    return 0;
  NewElement->Data = NewData;
  NewElement->Next = NULL;
                    
  while (*L != NULL)
    L = &(*L)->Next;
  *L = NewElement;
  return 1;
}

int DelFromListFront( LIST **L, int *OldData )
{
  LIST *OldElement = *L;
      
  if (OldElement == NULL)
    return 0;
  *L = (*L)->Next;

  if (OldData != NULL)
    *OldData = OldElement->Data;
  free(OldElement);
  return 1;
}

int DelFromListBack( LIST **L, int *OldData )
{
  if ((*L) == NULL)
    return 0;
  while ((*L)->Next != NULL)
    L = &(*L)->Next;
  
  if (OldData != NULL)
    *OldData = (*L)->Data;
  free(*L);
  *L = NULL;
  return 1;
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

int DelFromListArbit( LIST **L, int *OldData, int Pos )
{
  LIST *OldElement;
  
  if ((*L) == NULL)
    return 0;
  while (Pos-- > 0 && (*L)->Next != NULL)
    L = &(*L)->Next;
  OldElement = *L;
  *L = (*L)->Next;
  
  if (OldData != NULL)
    *OldData = OldElement->Data;
  free(OldElement);
  return 1;
}

int AddToListArbit( LIST **L, int NewData, int Pos )
{
  LIST *NewElement;

  if ((NewElement = malloc(sizeof(LIST))) == NULL)
    return 0;
  NewElement->Data = NewData;

  while (Pos-- > 0 && *L != NULL)
    L = &(*L)->Next;
  NewElement->Next = *L;
  *L = NewElement;
  return 1;
}
