#include <stdio.h>
#include "DBLinkedList2.h"

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	// 8개의 데이터 저장
	LInsert(&list, 1); 	LInsert(&list, 2);
	LInsert(&list, 3); 	LInsert(&list, 4);
	LInsert(&list, 5);	LInsert(&list, 6);
	LInsert(&list, 7);	LInsert(&list, 8);

	// 저장된 데이터 조회
	printf("저장된 데이터를 출력합니다.\n");
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		// 오른쪽으로 이동하면서 데이터 조회
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

	printf("저장된 데이터를 출력합니다.\n");
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		// 오른쪽으로 이동하면서 데이터 조회
		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n");
	}
	return 0;
}