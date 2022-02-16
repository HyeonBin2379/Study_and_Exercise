#ifndef __CLINKEDLIST2_H__
#define __CLINKEDLIST2_H__

#include "Employee.h"
#define TRUE 1
#define FALSE 0

typedef Employee * LData;
typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _CLL
{
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
} CLinkedList;

typedef CLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);
void LInsertFront(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif // !__CLINKEDLIST2_H__
