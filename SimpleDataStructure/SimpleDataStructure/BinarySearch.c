#include <stdio.h>

int BSearch(int arr[], int len, int target)
{
	int first = 0;
	int last = len-1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;
		if (arr[mid] == target) return mid;
		else if (arr[mid] > target) last = mid - 1;
		else first = mid + 1;
	}
	return -1;
}

int main(void)
{
	int arr[9] = { 1, 2, 3, 7, 9, 12, 21, 23 ,27 };
	int idx;
	
	idx= BSearch(arr, sizeof(arr) / sizeof(int), 3);
	if (idx > -1)
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d\n", idx);
	else
		printf("Å½»ö ½ÇÆĞ\n");

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx > -1)
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d\n", idx);
	else
		printf("Å½»ö ½ÇÆĞ\n");
	return 0;
}