#include <stdlib.h>
#include <string.h>
#include "life.h"

#define LIFE_W 136
#define LIFE_H 76

static int F1[LIFE_H][LIFE_W], F2[LIFE_H][LIFE_W];

int GetCell( int (*F)[LIFE_W], int x, int y )
{
  x = (x + LIFE_W) % LIFE_W;
  y = (y + LIFE_H) % LIFE_H;
  return F[y][x];
}

void SetCell( int (*F)[LIFE_W], int x, int y, int val )
{
  x = (x + LIFE_W) % LIFE_W;
  y = (y + LIFE_H) % LIFE_H;
  F[y][x] = val;
}

int GetNeighbours( int (*F)[LIFE_W], int x, int y )
{
  return GetCell(F, x - 1, y - 1) + GetCell(F, x, y - 1) + GetCell(F, x + 1, y - 1) + GetCell(F, x - 1, y) + GetCell(F, x + 1, y) + GetCell(F, x - 1, y + 1) + GetCell(F, x, y + 1) + GetCell(F, x + 1, y + 1);
}

void DrawField( int (*F)[LIFE_W] )
{
  int x, y;

  for (y = 0; y < LIFE_H; y++)
    for (x = 0; x < LIFE_W; x++)
      if (GetCell(F, x, y))
        PutPixel(x, y, 255, 255, 255);
      else
        PutPixel(x, y, 0, 0, 0);
}

void NewGeneration( int (*F1)[LIFE_W], int (*F2)[LIFE_W] )
{
  int x, y, n, new_val;

  for (y = 0; y < LIFE_H; y++)
    for (x = 0; x < LIFE_W; x++)
    {
      n = GetNeighbours(F1, x, y);
      if (GetCell(F1, x, y))
      {
        if (n < 2 || n > 3)
          new_val = 0;
        else
          new_val = 1;
      }
      else
      {
        if (n == 3)
          new_val = 1;
        else
          new_val = 0;
      }
      SetCell(F2, x, y, new_val);
    }
}

void Step( void )
{
  DrawField(F1);
  NewGeneration(F1, F2);
  memcpy(F1, F2, sizeof(F2));
}

void Init( void )
{
  int x, y;

  for (y = 0; y < LIFE_H; y++)
    for (x = 0; x < LIFE_W; x++)
      F1[y][x] = rand() % 2;
}