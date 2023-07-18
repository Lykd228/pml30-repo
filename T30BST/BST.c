#include <stdio.h>
#include "bst.h"

int AccessTree( TREE **T, int Key )
{
  if (*T == NULL)
  {
    if ((*T = malloc(sizeof(TREE))) == NULL)
      return 0;
    (*T)->Key = Key;
    (*T)->Less = (*T)->More = NULL;
    return 1;
  }
  if ((*T)->Key == Key)
    return 1;
  if ((*T)->Key < Key)
    return AccessTree(&(*T)->More, Key);
  return AccessTree(&(*T)->Less, Key);
}

int AccessTree1( TREE **T, int Key )
{
  while (*T != NULL)
  {
    if ((*T)->Key == Key)
      return 1;
    if ((*T)->Key < Key)
      T = &(*T)->More;
    else
      T = &(*T)->Less;
  }
  if ((*T = malloc(sizeof(TREE))) == NULL)
    return 0;
  (*T)->Key = Key;
  (*T)->Less = (*T)->More = NULL;
  return 1;
}

void PutTree( TREE *T )
{
  if (T == NULL)
    printf("*");
  else
  {
    printf("%i(", T->Key);
    PutTree(T->Less);
    printf(",");
    PutTree(T->More);
    printf(")");
  }
}

void PutTree1( TREE *T )
{
  if (T == NULL)
    printf("*");
  else
  {
    PutTree1(T->Less);
    printf("%i", T->Key);
    PutTree1(T->More);
  }
}

void ClearTree( TREE **T )
{
  if (*T != NULL)
  {
    ClearTree(&(*T)->Less);
    ClearTree(&(*T)->More);
    free(*T);
    *T = NULL;
  }
}

void DrawTree( TREE *T, int Level )
{
  if (T == NULL)
    ; /* printf("%*c*\n", Level * 4, ' '); */
  else
  {
    DrawTree(T->More, Level + 1);
    printf("%*c%i\n", Level * 4, ' ', T->Key);
    DrawTree(T->Less, Level + 1);
  }
}

int DelTree( TREE **T, int Key )
{
  TREE **P, *tmp;

  /* search node for delete */
  if (*T == NULL)
    return 0;
  while (*T != NULL && (*T)->Key != Key)
  {
    if (Key > (*T)->Key)
      T = &(*T)->More;
    else
      T = &(*T)->Less;
  }
  if (*T == NULL)
    return 0;

  /* find biggest node in left subtree */
  P = &(*T)->Less;
  tmp = *T;
  if (*P == NULL)
    /* left is empty */
    *T = (*T)->More;
  else
  {
    while (*P != NULL)
      P = &(*P)->More;
    *P = (*T)->More;
    *T = (*T)->Less;
  }
  free(tmp);
  return 1;
}

int Linearize( TREE **T )
{
  TREE **P, *tmp;
  int n = 0;

  if (*T == NULL)
    return 0;
  while (*T != NULL)
  {
    /* cycle with left */
    while (*(P = &(*T)->Less) != NULL)
    {
      tmp = *P;
      /* find biggest in left and place T to More of him */
      while (*P != NULL)
        P = &(*P)->More;
      *P = *T;
      (*T)->Less = NULL;
      *T = tmp;
    }
    T = &(*T)->More;
    n++;
  }
  return n;
}

void BalanceTree( TREE **T, int N )
{
  TREE *P = *T, *tmp;
  int i;

  if (N < 3)
    return;

  for (i = 0; i < N / 2 - 1; i++)
    *T = (*T)->More;
  tmp = *T;
  *T = (*T)->More;
  tmp->More = NULL;

  (*T)->Less = P;
  BalanceTree(&(*T)->Less, N / 2);
  BalanceTree(&(*T)->More, N - N / 2 - 1);
}
