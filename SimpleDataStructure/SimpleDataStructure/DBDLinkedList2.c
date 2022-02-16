#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList2.h"

void ListInit(List * plist)
{
	plist->head = (Node *)malloc(sizeof(Node));
	plist->tail = (Node *)malloc(sizeof(Node));

	// head�� tail�� ���̳�� �ʱ�ȭ
	plist->head->prev = NULL;			// ���̳���� �� �ʱ�ȭ
	plist->tail->next = NULL;

	plist->head->next = plist->tail;	// ���̳�尡 ���� ����Ű�� �ϱ�
	plist->tail->prev = plist->head;
	
	plist->numOfData = 0;
}
void LInsert(List * plist, Data data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	// �� ���� �� ����� ���ʿ� �ִ� ��尡 ���θ� ����Ŵ
	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;
	// �� ���� �� ����� �����ʿ� �ִ� ��尡 ���θ� ����Ŵ
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

	// ������ ��� ������ ��忡 ���� ������ ���� ������
	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	// ���� ��带 ���� ���� ����
	plist->cur = plist->cur->prev;
	free(rpos);

	// �������� ���� ���� �� ������ �� ��ȯ
	(plist->numOfData)--;
	return remv;
}
int LCount(List * plist) 
{
	return plist->numOfData;
}