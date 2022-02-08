#include <stdio.h>
#include "ArrayList4.h"

void ListInit(List * plist)
{
	plist->numOfData = 0;
	plist->curPosition = -1;
}
void LInsert(List * plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
		return;
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->numOfData == 0) {
		puts("저장된 데이터가 없습니다.\n");
		return FALSE;
	}
	else {
		plist->curPosition = 0;
		*pdata = plist->arr[plist->curPosition];
	}
	return TRUE;

}
int LNext(List * plist, LData * pdata)
{
	if ((plist->curPosition) >= (plist->numOfData)-1) {
		return FALSE;
	}
	else {
		plist->curPosition++;
		*pdata = plist->arr[plist->curPosition];
	}
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

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{

}