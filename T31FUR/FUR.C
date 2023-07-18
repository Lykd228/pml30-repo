#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "fur.h"

TREE *Init( char *Text, TREE *N, TREE *Y )
{
  TREE *T = malloc(sizeof(TREE));

  if (T == NULL)
    return NULL;
  strncpy(T->Text, Text, MAX_STR - 1);
  T->No = N;
  T->Yes = Y;
  return T;
}

void Session( TREE **T )
{
  int key;

  if (*T == NULL)
    return;
  while (1)
  {
    printf("%s?", (*T)->Text);
    key = _getch();
    printf(key == 'Y' || key == 'y' || key == (uchar)'Д' || key == (uchar)'д' ? " Yes\n" : " No\n");
    if ((*T)->Yes != NULL)
      T = (key == 'Y' || key == 'y' || key == (uchar)'Д' || key == (uchar)'д' ? &(*T)->Yes : &(*T)->No);
    else
    {
      if (key == 'N' || key == 'n' || key == (uchar)'Н' || key == (uchar)'н')
      {
        char Qst[MAX_STR], Ans[MAX_STR];

        printf("тогда введите новое определение: ");
        GetStr(Qst, MAX_STR);
        printf("введите правильный ответ для определения: ");
        GetStr(Ans, MAX_STR);
        *T = Init(Qst, *T, Init(Ans, NULL, NULL));
      }
      return;
    }
  }
}

void SaveTreeRec( FILE *F, TREE *T )
{
  if (T == NULL)
    return;
  fwrite(T, sizeof(TREE), 1, F);
  SaveTreeRec(F, T->No);
  SaveTreeRec(F, T->Yes);
}

int SaveTree( char *FileName, TREE *T )
{
  FILE *F = fopen(FileName, "wb");

  if (F == NULL)
    return 0;

  SaveTreeRec(F, T);

  fclose(F);
  return 1;
}

void LoadTreeRec( FILE *F, TREE **T )
{
  TREE tr;

  if (fread(&tr, sizeof(TREE), 1, F) != 1)
    return;
  *T = Init(tr.Text, NULL, NULL);

  if (tr.No != NULL)
    LoadTreeRec(F, &(*T)->No);
  if (tr.Yes != NULL)
    LoadTreeRec(F, &(*T)->Yes);
}

int LoadTree( char *FileName, TREE **T )
{
  FILE *F = fopen(FileName, "rb");

  if (F == NULL)
    return 0;

  LoadTreeRec(F, T);

  fclose(F);
  return 1;
}

void ClearTree( TREE **T )
{
  if (*T == NULL)
    return;
  ClearTree(&(*T)->No);
  ClearTree(&(*T)->Yes);
  free(*T);
  *T = NULL;
}

void DrawTree( TREE *T, int Level )
{
  if (T == NULL)
    ;
  else
  {
    DrawTree(T->Yes, Level + 2);
    printf("%*c%s\n", Level * 8, ' ', T->Text);
    DrawTree(T->No, Level + 2);
  }
}
