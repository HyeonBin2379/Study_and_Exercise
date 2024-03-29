#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	List list;
	int data, i;
	int sum = 0;

	ListInit(&list);
	for (i = 1; i < 10; i++) {
		LInsert(&list, i);
	}

	printf("리스트에 저장된 정수들의 개수: %d \n", LCount(&list));
	if (LFirst(&list, &data)) {
		sum += data;
		while (LNext(&list, &data))
			sum += data;
	}
	printf("SUM: %d \n\n", sum);

	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0) {
			LRemove(&list);
		}
		
		while (LNext(&list, &data)) {
			if (data % 2 == 0 || data % 3 == 0) {
				LRemove(&list);
			}
		}
	}

	printf("리스트에 저장된 정수들의 개수: %d \n", LCount(&list));
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("%\n\n");
	return 0;
}