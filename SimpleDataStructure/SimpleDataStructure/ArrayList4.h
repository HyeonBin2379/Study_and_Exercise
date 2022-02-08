#ifndef __ARRAYLIST4_H__
#define __ARRAYLIST4_H__

#define TRUE 1
#define FALSE 0

typedef int LData;
#define LIST_LEN 100

typedef struct __arrayList4
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList4;

typedef ArrayList4 List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int(*comp)(LData d1, LData d2));

#endif // !__ARRAYLIST4_H__

