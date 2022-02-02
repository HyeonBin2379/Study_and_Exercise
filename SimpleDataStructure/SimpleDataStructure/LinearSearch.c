#include <stdio.h>

int LSearch(int arr[], int len, int target)
{
	for (int i = 0; i < len; i++) {
		if (arr[i] == target)	//	¼øÂ÷Å½»ö ¼öÇà ÁöÁ¡: Å¸°ÙÀ» Ã£À¸¸é ÇØ´ç ÀÎµ¦½º ¹øÈ£ ¸®ÅÏ
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
		printf("Å½»ö ½ÇÆĞ\n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d\n", idx);

	idx = LSearch(arr, len, 7);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ\n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d\n", idx);

	return 0;
}