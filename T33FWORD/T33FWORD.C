#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagTREE TREE;
struct tagTREE
{
  char Str[101];
  TREE *Less, *More;
};

int AccessTree( TREE **T, char *Str )
{
  int cmp;

  if (*T == NULL)
  {
    if ((*T = malloc(sizeof(TREE))) == NULL)
      return 0;
    strncpy((*T)->Str, Str, 100);
    (*T)->Less = (*T)->More = NULL;
    return 1;
  }

  cmp = strcmp((*T)->Str, Str);
  if (cmp == 0)
    return 1;
  if (cmp > 0)
    return AccessTree(&(*T)->Less, Str);
  return AccessTree(&(*T)->More, Str);
}

void PrintTree( TREE *T, FILE *F )
{
  if (T != NULL)
  {
    PrintTree(T->Less, F);
    fprintf(F, "%s ", T->Str);
    PrintTree(T->More, F);
  }
}

void main( void )
{
  TREE *Root = NULL;
  char Str[101];
  FILE *In, *Out;
  
  In = fopen("IN.TXT", "r");
  Out = fopen("RES.TXT", "w");
  if (In == NULL || Out == NULL)
  {
    printf("File error\n");
    return;
  }

  while (fscanf(In, "%100s", Str) == 1)
    AccessTree(&Root, Str);
  PrintTree(Root, Out);
  fclose(In);
  fclose(Out);
}
