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

void SPush(Stack * pstack, Data data)	// 인덱스 증가 후 데이터 저장
{
	pstack->topIndex += 1;
	pstack->array[pstack->topIndex] = data;
}
Data SPop(Stack * pstack)	// 인덱스값 임시 저장, 인덱스 감소 후 데이터 반환
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	// top이 감소하면서 이전의 top에 해당하는 인덱스 데이터는 무효화
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

	// 삭제 없이 인덱스의 데이터 반환
	return pstack->array[pstack->topIndex];
}