
/*#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define SetDbgMemHooks() \
  _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF | \
    _CRTDBG_ALLOC_MEM_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
#else*/
#define SetDbgMemHooks() ((void)0)
/*#endif */
#include <stdlib.h>

typedef struct tagTREE TREE;
struct tagTREE
{
  int Key;
  TREE *Less, *More;
};

int AccessTree( TREE **T, int Key );
int AccessTree1( TREE **T, int Key );
void PutTree( TREE *T );
void PutTree1( TREE *T );
void DrawTree( TREE *T, int Level );
void ClearTree( TREE **T );
int DelTree( TREE **T, int Key );
int Linearize( TREE **T );
void BalanceTree( TREE **T, int N );
