
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define SetDbgMemHooks() \
  _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF | \
    _CRTDBG_ALLOC_MEM_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
#else
#define SetDbgMemHooks() ((void)0)
#endif
#include <stdlib.h>

#define MAX_STR 102

typedef unsigned char uchar;
typedef struct tagTREE TREE;
struct tagTREE
{
  char Text[MAX_STR];
  TREE *No, *Yes;
};

void GetStr( char *str, int max );
TREE *Init( char *Text, TREE *N, TREE *Y );
void Session( TREE **T );
int SaveTree( char *FileName, TREE *T );
int LoadTree( char *FileName, TREE **T );
void ClearTree( TREE **T );
void DrawTree( TREE *T, int Level );
