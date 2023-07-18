#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define SetDbgMemHooks() \
  _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF | \
    _CRTDBG_ALLOC_MEM_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
#else
#define SetDbgMemHooks() ((VOID)0)
#endif
#include <stdlib.h>

typedef struct tagLIST LIST;
struct tagLIST
{
  int Data;
  LIST *Next;
};

void DisplayList( LIST *L );
int AddToListFront( LIST **L, int NewData );
int AddToListBack( LIST **L, int NewData );
int DelFromListFront( LIST **L, int *OldData );
int DelFromListBack( LIST **L, int *OldData );
void ClearList( LIST **L );
int DelFromListArbit( LIST **L, int *OldData, int Pos );
int AddToListArbit( LIST **L, int NewData, int Pos );
