#ifndef __CLINKEDLIST_H__
#define __CLINKEDLIST_H__

#define TRUE 1
#define FALSE 0
typedef int LData;

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

typedef struct _CLL
{
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
} CList;

typedef CList List;

void ListInit(List * plist);
void LInsertFront(List * plist, LData data);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif // !__CLINKEDLIST_H__
