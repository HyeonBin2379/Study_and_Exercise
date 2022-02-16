#ifndef __LISTBASEDSTACK_H__
#define __LISTBASEDSTACK_H__

#include "CLinkedList3.h"

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct __CLLStack
{
	List * list;
} CLLStack;

typedef CLLStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif // !__LISTBASEDSTACK_H__
