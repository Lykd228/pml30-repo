
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

typedef struct
{
  LIST
    *Head,
    *Tail;
} QUEUE;

typedef struct
{
  LIST
    *Top;
} STACK;

int Put( QUEUE *Q, int NewData );
int Get( QUEUE *Q, int *OldData );
int Push( STACK *S, int NewData );
int Pop( STACK *S, int *OldData );
void DisplayStack( STACK *S );
void DisplayQueue( QUEUE *Q );
void ClearStack( STACK *S );
void ClearQueue( QUEUE *Q );
