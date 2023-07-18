#include <stdio.h>
#include <string.h>
#include "list2.h"

void DisplayList( LIST *L )
{
  if (L == NULL)
    printf("<Empty list>\n");
  else
  {
    LIST *save = L;

    while (L->Prev != NULL)
      L = L->Prev;
    while (L != NULL)
    {
      printf("%s%s", L->Str, L == save ? "(*)" : "");
      printf((L = L->Next) == NULL ? "\n" : ",");
    }
  }
}

int ShiftNext( LIST **L )
{
  if (*L == NULL || (*L)->Next == NULL)
    return 0;
  *L = (*L)->Next;
  return 1;
}

int ShiftPrev( LIST **L )
{
  if (*L == NULL || (*L)->Prev == NULL)
    return 0;
  *L = (*L)->Prev;
  return 1;
}

int AddToListFront( LIST **L, char *NewStr )
{
  LIST *next = NULL;

  while (*L != NULL)
  {
    next = *L;
    L = &(*L)->Prev;
  }
  if ((*L = malloc(sizeof(LIST))) == NULL)
    return 0;

  strncpy((*L)->Str, NewStr, MAX - 1);
  (*L)->Prev = NULL;
  (*L)->Next = next;
  return 1;
}

int AddToListBack( LIST **L, char *NewStr )
{
  LIST *prev = NULL;

  while (*L != NULL)
  {
    prev = *L;
    L = &(*L)->Next;
  }
  if ((*L = malloc(sizeof(LIST))) == NULL)
    return 0;

  strncpy((*L)->Str, NewStr, MAX - 1);
  (*L)->Prev = prev;
  (*L)->Next = NULL;
  return 1;
}

int DelFromListFront( LIST **L )
{
  LIST *next = NULL;

  if (*L == NULL)
    return 0;
  next = (*L)->Next;
  while ((*L)->Prev != NULL)
  {
    next = *L;
    L = &(*L)->Prev;
  }
  free(*L);
  *L = next;
  if (*L != NULL)
    (*L)->Prev = NULL;
  return 1;
}

int DelFromListBack( LIST **L )
{
  LIST *prev = NULL;

  if (*L == NULL)
    return 0;
  prev = (*L)->Prev;
  while ((*L)->Next != NULL)
  {
    prev = *L;
    L = &(*L)->Next;
  }
  free(*L);
  *L = prev;
  if (*L != NULL)
    (*L)->Next = NULL;
  return 1;
}

void ClearList( LIST **L )
{
  LIST *prev = NULL;

  if (*L == NULL)
    return;

  while ((*L)->Prev != NULL)
    *L = (*L)->Prev;

  while (*L != NULL)
  {
    prev = *L;
    *L = (*L)->Next;
    free(prev);
  }
}
