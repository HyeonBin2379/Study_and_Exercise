#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList2.h"

Employee * WhoIsNightDuty(List * plist, char * name, int day);
void ShowEmployeeInfo(Employee * emp);

int main(void)
{
	int i;
	Employee * pemp;
	List list;

	printf("����Ʈ �غ���...\n");
	ListInit(&list);

	printf("����Ʈ ������ ����...\n");
	pemp = (Employee *)malloc(sizeof(Employee));
	pemp->empNum = 1111;
	strcpy(pemp->name, "Terry");
	LInsert(&list, pemp);

	pemp = (Employee *)malloc(sizeof(Employee));
	pemp->empNum = 2222;
	strcpy(pemp->name, "Jerry");
	LInsert(&list, pemp);

	pemp = (Employee *)malloc(sizeof(Employee));
	pemp->empNum = 3333;
	strcpy(pemp->name, "Harry");
	LInsert(&list, pemp);

	pemp = (Employee *)malloc(sizeof(Employee));
	pemp->empNum = 4444;
	strcpy(pemp->name, "Sunny");
	LInsert(&list, pemp);
	printf("����Ʈ ������ ���� �Ϸ�!\n");

	printf("������ ����Ʈ ������ ��ȸ\n");
	pemp = WhoIsNightDuty(&list, "Terry", 3);
	ShowEmployeeInfo(pemp);

	pemp = WhoIsNightDuty(&list, "Sunny", 15);
	ShowEmployeeInfo(pemp);

	printf("����Ʈ ��ȸ ����, ����Ʈ ����\n");
	if (LFirst(&list, &pemp)) {
		free(pemp);

		for (i = 0; i < LCount(&list)-1; i++)
		{
			if (LNext(&list, &pemp))
				free(pemp);
		}
	}
	return 0;
}

Employee * WhoIsNightDuty(List * plist, char * name, int day)
{
	int i;
	Employee * ret;
	int num = LCount(plist);

	LFirst(plist, &ret);
	if (strcmp(ret->name, name) != 0)
	{
		for (i = 0; i < num-1; i++) {
			LNext(plist, &ret);
			if (strcmp(ret->name, name) == 0)
				break;
		}
		if (i >= num - 1)
			return NULL;
	}

	for (i = 0; i < day; i++)
		LNext(plist, &ret);
	return ret;
}
void ShowEmployeeInfo(Employee * emp)
{
	printf("Employee's Name: %s \n", emp->name);
	printf("Employee's Number: %d \n", emp->empNum);
}