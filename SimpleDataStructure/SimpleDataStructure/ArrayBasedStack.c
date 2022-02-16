#include <stdio.h>
#include <stdlib.h>
#include "ArrayBasedStack.h"

void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;
}
int SIsEmpty(Stack * pstack) 
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)	// �ε��� ���� �� ������ ����
{
	pstack->topIndex += 1;
	pstack->array[pstack->topIndex] = data;
}
Data SPop(Stack * pstack)	// �ε����� �ӽ� ����, �ε��� ���� �� ������ ��ȯ
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	// top�� �����ϸ鼭 ������ top�� �ش��ϴ� �ε��� �����ʹ� ��ȿȭ
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->array[rIdx];
}
Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	// ���� ���� �ε����� ������ ��ȯ
	return pstack->array[pstack->topIndex];
}