#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{
  int Y, M, D;
} DATE;

typedef struct
{
  char Surname[30], Name[27];
  DATE Birthday;
  char Phone[20];
  int Form;
  char FormDigit;
  char Sex;
} PUPIL;

void Swap( PUPIL *A, PUPIL *B );
void GetStr( char *str, int max );
void ReadPupil( PUPIL *P );
void DeletePupil( PUPIL *DB, int DBSize );
void PrintOut( PUPIL *DB, int DBSize );
int SaveDB( char *FileName, PUPIL *Base, int N );
int LoadDB( char *FileName, PUPIL *Base, int MaxSize );
void SortAny( PUPIL *DB, int DBSize, char c );
