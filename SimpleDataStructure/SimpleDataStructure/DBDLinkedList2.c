#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList2.h"

void ListInit(List * plist)
{
	plist->head = (Node *)malloc(sizeof(Node));
	plist->tail = (Node *)malloc(sizeof(Node));

	// head와 tail의 더미노드 초기화
	plist->head->prev = NULL;			// 더미노드의 끝 초기화
	plist->tail->next = NULL;

	plist->head->next = plist->tail;	// 더미노드가 서로 가리키게 하기
	plist->tail->prev = plist->head;
	
	plist->numOfData = 0;
}
void LInsert(List * plist, Data data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	// 새 노드와 새 노드의 왼쪽에 있는 노드가 서로를 가리킴
	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;
	// 새 노드와 새 노드의 오른쪽에 있는 노드가 서로를 가리킴
	newNode->next = plist->tail;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if (plist->head->next == plist->tail) {
		return FALSE;
	}
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List * plist, Data * pdata) 
{
	if (plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist) 
{
	Node * rpos = plist->cur;
	Data remv = plist->cur->data;

	// 삭제할 노드 전후의 노드에 대한 포인터 변수 재조정
	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	// 현재 노드를 이전 노드로 변경
	plist->cur = plist->cur->prev;
	free(rpos);

	// 데이터의 개수 감소 및 삭제한 값 반환
	(plist->numOfData)--;
	return remv;
}
int LCount(List * plist) 
{
	return plist->numOfData;
}