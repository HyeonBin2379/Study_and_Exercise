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

	printf("리스트 준비중...\n");
	ListInit(&list);

	printf("리스트 데이터 삽입...\n");
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
	printf("리스트 데이터 삽입 완료!\n");

	printf("지정한 리스트 데이터 조회\n");
	pemp = WhoIsNightDuty(&list, "Terry", 3);
	ShowEmployeeInfo(pemp);

	pemp = WhoIsNightDuty(&list, "Sunny", 15);
	ShowEmployeeInfo(pemp);

	printf("리스트 조회 종료, 리스트 해제\n");
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