#ifndef __ARRAYLIST2_H__
#define __ARRAYLIST2_H__

#include "Point.h"

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef Point * LData;

typedef struct __Arraylist2 
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList2;

typedef ArrayList2 List;

void ListInit(List * plist);
void LInsert(List * plist, LData * pdata);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif // !__ARRAYLIST2_H__
