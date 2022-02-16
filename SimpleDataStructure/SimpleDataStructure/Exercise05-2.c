#include <stdio.h>
#include "DBLinkedList2.h"

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	// 8���� ������ ����
	LInsert(&list, 1); 	LInsert(&list, 2);
	LInsert(&list, 3); 	LInsert(&list, 4);
	LInsert(&list, 5);	LInsert(&list, 6);
	LInsert(&list, 7);	LInsert(&list, 8);

	// ����� ������ ��ȸ
	printf("����� �����͸� ����մϴ�.\n");
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		// ���������� �̵��ϸ鼭 ������ ��ȸ
		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n\n");
	}


	if (LFirst(&list, &data)) {
		if (data % 2 == 0)
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	printf("����� �����͸� ����մϴ�.\n");
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		// ���������� �̵��ϸ鼭 ������ ��ȸ
		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n");
	}
	return 0;
}