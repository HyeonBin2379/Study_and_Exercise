#include <stdio.h>

void HanoiTowerMove(int num, int from, int by, int to)
{
	int count = 0;
	if (num == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		HanoiTowerMove(num - 1, from, to, by);
		printf("%d %d\n", from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int main(void)
{
	int num;
	scanf("%d", &num);
	printf("%d \n", (1 << num) - 1);
	HanoiTowerMove(num, 1, 2, 3);
	return 0;
}