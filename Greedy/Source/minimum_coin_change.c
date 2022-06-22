// the minimum number of coins

#include <conio.h>
#include <stdio.h>

#define NUM_COIN 9

void remaining_money(int n)
{
	int i, x;
	int coin[] = {250, 100, 50, 30, 20, 10, 5, 2, 1};
	for (i = 0; i < NUM_COIN && n != 0; i++)
	{
		x = coin[i];
		printf("\n %d of %d ", n / x, x);
		n %= x;
	}
}

void main(void)
{
	int n;
	printf("\n Enter the total money: ");
	scanf("%d", &n);
	remaining_money(n);
}
