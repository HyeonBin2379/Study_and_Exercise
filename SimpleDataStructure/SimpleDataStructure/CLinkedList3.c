#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List * plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List * plist, LData data)	// 머리부터 노드 추가
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	(plist->numOfData)++;
}

void LInsert(List * plist, LData data)	// 꼬리부터 노드 추가
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;	// 리스트의 머리 부분 갱신
		plist->tail = newNode;
	}
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->tail == NULL)
		return FALSE;
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List * plist, LData * pdata)
{
	if (plist->tail == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur;
	LData rdata = plist->cur->data;

	if (rpos == plist->tail) {	// rpos는 삭제할 현재 노드
		if (plist->tail == plist->tail->next)
			plist->tail == NULL;
		else
			plist->tail = plist->before;
	}
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}
int LCount(List * plist)
{
	return plist->numOfData;
}