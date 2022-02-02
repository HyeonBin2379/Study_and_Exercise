#include <stdio.h>

int LSearch(int arr[], int len, int target)
{
	for (int i = 0; i < len; i++) {
		if (arr[i] == target)	//	����Ž�� ���� ����: Ÿ���� ã���� �ش� �ε��� ��ȣ ����
			return i;
	}
	return -1;
}


int main(void)
{
	int arr[7] = { 3, 5, 2, 4, 9 };
	int len = sizeof(arr) / sizeof(int);
	int idx;

	idx = LSearch(arr, len, 4);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d\n", idx);

	idx = LSearch(arr, len, 7);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d\n", idx);

	return 0;
}