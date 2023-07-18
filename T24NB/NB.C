#include "nb.h"

void Swap( PUPIL *A, PUPIL *B )
{
  PUPIL tmp = *A;

  *A = *B;
  *B = tmp;
}

void ReadPupil( PUPIL *P )
{
  printf("Surname:");
  GetStr(P->Surname, sizeof P->Surname);
  printf("Name:");
  GetStr(P->Name, sizeof P->Name);
  printf("Birth day:");
  scanf("%i", &(P->Birthday.D));
  GetStr(NULL, 0);
  printf("Birth month:");
  scanf("%i", &(P->Birthday.M));
  GetStr(NULL, 0);
  printf("Birth year:");
  scanf("%i", &(P->Birthday.Y));
  GetStr(NULL, 0);
  printf("Sex (M/F):");
  scanf("%c", &(P->Sex));
  GetStr(NULL, 0);
  printf("Form:");
  scanf("%i", &(P->Form));
  GetStr(NULL, 0);
  printf("Form digit:");
  scanf("%c", &(P->FormDigit));
  GetStr(NULL, 0);
  printf("Phone:");
  GetStr(P->Phone, sizeof P->Phone);
}

void DeletePupil( PUPIL *DB, int DBSize )
{
  int n, i;

  printf("Number of pupil for delete:");
  scanf("%i", &n);
  for (i = n - 1; i < DBSize - 1; i++)
    DB[i] = DB[i + 1];
  GetStr(NULL, 0);
}


void PrintOut( PUPIL *DB, int DBSize )
{
  int i;

  printf("\n");
  for (i = 0; i < DBSize; i++)
    printf("%i) %s %s (%i.%i.%i), %c, %i-%c, %s\n", i + 1, DB[i].Name, DB[i].Surname, DB[i].Birthday.D, DB[i].Birthday.M, DB[i].Birthday.Y, DB[i].Sex, DB[i].Form, DB[i].FormDigit, DB[i].Phone);
  printf("\n");
}

int SaveDB( char *FileName, PUPIL *Base, int N )
{
  FILE *F;

  F = fopen(FileName, "wb");
  if (F == NULL)
    return 0;
  fwrite(Base, sizeof(PUPIL), N, F);
  fclose(F);
  return 1;
}

int LoadDB( char *FileName, PUPIL *Base, int MaxSize )
{
  int N;
  FILE *F;

  F = fopen(FileName, "rb");
  if (F == NULL)
    return 0;
  N = fread(Base, sizeof(PUPIL), MaxSize, F);
  fclose(F);
  return N;
}

int IsSurnameNameLess( PUPIL A, PUPIL B )
{
  int n;

  if ((n = strcmp(A.Surname, B.Surname)) == 0)
    return strcmp(A.Name, B.Name) < 0;
  return n < 0;
}

int IsNameLess( PUPIL A, PUPIL B )
{
  return strcmp(A.Name, B.Name) < 0;
}

int IsDateLess( PUPIL A, PUPIL B )
{
  if (A.Birthday.Y == B.Birthday.Y)
    if (A.Birthday.M == B.Birthday.M)
      return A.Birthday.D < B.Birthday.D;
    else
      return A.Birthday.M < B.Birthday.M;
  return A.Birthday.Y < B.Birthday.Y;
}

int IsBirthdayLess( PUPIL A, PUPIL B )
{
  if (A.Birthday.M == B.Birthday.M)
    return A.Birthday.D < B.Birthday.D;
  return A.Birthday.M < B.Birthday.M;
}

void SortAny( PUPIL *DB, int DBSize, char c )
{
  int i, j, min;
  int (*IsLess[])( PUPIL A, PUPIL B ) =
  {
    IsSurnameNameLess, IsNameLess, IsDateLess, IsBirthdayLess
  };

  for (j = 0; j < DBSize - 1; j++)
  {
    for (i = j + 1, min = j; i < DBSize; i++)
      if (IsLess[(int)(c - 'a')](DB[i], DB[min]))
        min = i;
    Swap(&DB[j], &DB[min]);
  }
}
