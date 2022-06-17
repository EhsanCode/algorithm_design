// Binary (0-1) Knapsack
// Divide And Conquer DAC

#include <stdio.h>
#include <conio.h>

int cost[100], w[100];

int max(int x, int y)
{
	if (x >= y)
		return x;
	return y;
}

int binary_knapsack(int i, int j)
{
	if (i == 0)
		if (j >= w[0])
			return cost[0];
		else
			return 0;
	if (w[i] <= j)
		return max(p(i - 1, j), cost[i] + p(i - 1, j - w[i]));
	return p(i - 1, j);
}

void main(void)
{
	int n, w_total;
	printf("\nEnter n:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Item%d\n    w=", i + 1);
		scanf("%d", &w[i]);
		printf(" Cost=");
		scanf("%d", &cost[i]);
	}
	printf("\nEnter W:");
	scanf("%d", &w_total);
	printf("\nmax solution= %d", binary_knapsack(n - 1, w_total));
}
