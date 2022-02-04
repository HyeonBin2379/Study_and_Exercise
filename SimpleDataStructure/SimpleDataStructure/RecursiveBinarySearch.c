#include <stdio.h>

int BSearchRecur(int arr[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;
	mid = (first + last) / 2;
	if (target == arr[mid])
		return mid;
	else if (target < arr[mid])
		return BSearchRecur(arr, first, mid - 1, target);
	else
		return BSearchRecur(arr, mid + 1, last, target);
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int first = 0;
	int last = sizeof(arr) / sizeof(int) - 1;
	int idx;

	idx = BSearchRecur(arr, first, last, 7);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d\n", idx);

	idx = BSearchRecur(arr, first, last, 4);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d\n", idx);
	return 0;
}
