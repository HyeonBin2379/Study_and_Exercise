#ifndef __ARRAYBASEDSTACK_H__
#define __ARRAYBASEDSTACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _stack
{
	Data array[STACK_LEN];
	int topIndex;
} ArrayBasedStack;

typedef ArrayBasedStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack *pstack);

#endif // !__ARRAYBASESTACK_H__
