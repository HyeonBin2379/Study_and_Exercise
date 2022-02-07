#ifndef __ARRAYLIST3_H__
#define __ARRAYLIST3_H__

#include "NameCard.h"
#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef NameCard * LData;

typedef struct _arraylist3
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList3;

typedef ArrayList3 List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif // !__ARRAYlIST3_H__
