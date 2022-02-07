#include <stdio.h>
#include "ArrayList3.h"

void ListInit(List * plist)
{
	plist->numOfData = 0;
	plist->curPosition = 0;
}
void LInsert(List * plist, LData data)
{
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->numOfData == 0) {
		puts("저장이 불가능합니다.");
		return FALSE;
	}
	if ((plist->curPosition) != 0)
		plist->curPosition = 0;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}
int LNext(List * plist, LData * pdata)
{
	if ((plist->curPosition) >= (plist->numOfData) - 1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}
LData LRemove(List * plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	int rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->curPosition)--;
	(plist->numOfData)--;
	return rdata;
}
int LCount(List * plist)
{
	return plist->numOfData;
}