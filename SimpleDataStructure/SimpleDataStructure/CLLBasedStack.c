#include "CLinkedList3.h"
#include "CLLBasedStack.h"

void StackInit(Stack * pstack)
{
	pstack->list = (List *)malloc(sizeof(List));
	ListInit(pstack->list);
}
int SIsEmpty(Stack * pstack)
{
	if (LCount(pstack->list) == 0)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	LInsertFront(pstack->list, data);
}
Data SPop(Stack * pstack)
{
	Data data;
	LFirst(pstack->list, &data);
	LRemove(pstack->list);
	return data;
}
Data SPeek(Stack * pstack, Data * pdata)
{
	Data data;
	LFirst(pstack->list, &data);
	return data;
}
