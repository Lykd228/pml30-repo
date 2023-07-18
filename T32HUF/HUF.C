#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huf.h"
#include "bitrw.h"

/* global variables and types */
static long Freq[256];

typedef struct tagTREE TREE;
struct tagTREE
{
  char Ch;
  long Freq;
  TREE *Left, *Right;
};

static TREE *Nodes[256];
int NumOfNodes;

typedef struct
{
  int Code[47], Len;
} CODE;
static CODE NewCodes[256], CurCode;

static void CountFreq( FILE *F )
{
  int i;

  memset(Freq, 0, sizeof(Freq));
  while ((i = fgetc(F)) != EOF)
    Freq[i]++;

  /* for (i = 0; i < 256; i++)
    if (Freq[i] > 0)
      printf("Sym %c (%d) cnt %ld\n", i < 32 ? '.' : i, i, Freq[i]); */
}

static void PlaceNode( char Ch, long Freq, TREE *L, TREE *R )
{
  int i;
  TREE *T = malloc(sizeof(TREE));

  if (T == NULL)
    return;
  T->Ch = Ch;
  T->Freq = Freq;
  T->Left = L;
  T->Right = R;

  i = NumOfNodes - 1;
  while (i >= 0 && T->Freq > Nodes[i]->Freq)
    Nodes[i + 1] = Nodes[i--];
  Nodes[i + 1] = T;
  NumOfNodes++;
}

static void BuildForest( void )
{
  int i;

  for (i = 0; i < 256; i++)
    if (Freq[i] > 0)
      PlaceNode(i, Freq[i], NULL, NULL);
}

static void CollapseForest( void )
{
  while (NumOfNodes > 1)
  {
    TREE
      *Last = Nodes[--NumOfNodes],
      *PreLast = Nodes[--NumOfNodes];
    PlaceNode(' ', Last->Freq + PreLast->Freq, PreLast, Last);
  }
}

static void BuildCodes( TREE *T )
{
  if (T->Left == NULL && T->Right == NULL)
  {
    NewCodes[(unsigned char)T->Ch] = CurCode;
    return;
  }

  /* left */
  CurCode.Code[CurCode.Len++] = 0;
  BuildCodes(T->Left);
  CurCode.Len--;

  /* right */
  CurCode.Code[CurCode.Len++] = 1;
  BuildCodes(T->Right);
  CurCode.Len--;
}

static char *PrintCode( CODE C )
{
  int i;
  char *res = malloc(C.Len + 1);

  if (res == NULL)
    return NULL;
  for (i = 0; i < C.Len; i++)
    res[i] = C.Code[i] == 0 ? '0' : '1';
  res[C.Len] = '\0';
  return res;
}

int Stat( char *FileName )
{
  int i, total = 0;
  FILE *F;

  if (FileName == NULL)
  {
    printf("File not specified\n");
    return 0;
  }

  if ((F = fopen(FileName, "rb")) == NULL)
  {
    printf("File %s not found\n", FileName);
    return 0;
  }

  /* compressing */
  CountFreq(F);
  NumOfNodes = 0;
  BuildForest();
  CollapseForest();
  CurCode.Len = 0;
  memset(NewCodes, 0, sizeof(NewCodes));
  BuildCodes(Nodes[0]);

  /* testing */
  for (i = 0; i < 256; i++)
    if (Freq[i] > 0)
    {
      total += NewCodes[i].Len * Freq[i];
      printf("Sym %c (%d) cnt %ld code %s\n", i < 32 ? '.' : i, i, Freq[i], PrintCode(NewCodes[i]));
    }
  printf("compress ratio %f\n", (double)Nodes[0]->Freq * 8 / total);

  fclose(F);
  return 1;
}

int Compress( char *Out, char *In )
{
  int i, ch;
  FILE *InF, *OutF;

  if (In == NULL || Out == NULL)
  {
    printf("File not specified\n");
    return 0;
  }

  if ((InF = fopen(In, "rb")) == NULL)
  {
    printf("Error on input file\n");
    return 0;
  }
  if ((OutF = fopen(Out, "wb")) == NULL)
  {
    printf("Error on output file\n");
    return 0;
  }

  CountFreq(InF);
  NumOfNodes = 0;
  BuildForest();
  CollapseForest();
  CurCode.Len = 0;
  memset(NewCodes, 0, sizeof(NewCodes));
  BuildCodes(Nodes[0]);

  rewind(InF);
  fwrite(Freq, 4, 256, OutF);
  WriteBitInit(OutF);
  while ((ch = fgetc(InF)) != EOF)
    for (i = 0; i < NewCodes[ch].Len; i++)
      WriteBit(NewCodes[ch].Code[i]);

  WriteBitClose();
  fclose(InF);
  fclose(OutF);
  return 1;
}

int Decompress( char *Out, char *In )
{
  int n;
  FILE *InF, *OutF;
  TREE *T;

  if (In == NULL || Out == NULL)
  {
    printf("File not specified\n");
    return 0;
  }

  if ((InF = fopen(In, "rb")) == NULL)
  {
    printf("Error on input file\n");
    return 0;
  }
  if ((OutF = fopen(Out, "wb")) == NULL)
  {
    printf("Error on output file\n");
    return 0;
  }

  fread(Freq, 4, 256, InF);
  NumOfNodes = 0;
  BuildForest();
  CollapseForest();
  n = Nodes[0]->Freq;
  T = Nodes[0];
  ReadBitInit(InF);
  while (n > 0)
    if (T->Left == NULL)
    {
      fputc(T->Ch, OutF);
      n--;
      T = Nodes[0];
    }
    else
      if (ReadBit())
        T = T->Right;
      else
        T = T->Left;

  fclose(InF);
  fclose(OutF);
  return 1;
}
