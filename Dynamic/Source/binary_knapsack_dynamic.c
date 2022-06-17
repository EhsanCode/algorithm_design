// Binary (0-1) knapsack
// Dynamic

#include <stdio.h>
#include <conio.h>

int p[100][100];

int max(int x, int y)
{
	if (x >= y)
		return x;
	return y;
}

int binary_knapsack(int n, int w_total, int w[], int cost[])
{
	int i, j;
	for (i = 0; i <= w_total; i++)
		p[0][i] = 0;
	for (i = w[0]; i <= w_total; i++)
		p[0][i] = cost[0];
	for (i = 1; i < n; i++)
		for (j = 0; j <= w_total; j++)
			if (w[i] <= j)
				p[i][j] = max(p[i - 1][j], cost[i] + p[i - 1][j - w[i]]);
			else
				p[i][j] = p[i - 1][j];
	return p[i - 1][j - 1];
}

void main(void)
{
	int n, w[100], w_total, cost[100];
	printf("\nEnter n:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Item%d\n     w=", i + 1);
		scanf("%d", &w[i]);
		printf(" Value=");
		scanf("%d", &cost[i]);
	}
	printf("\nEnter W:");
	scanf("%d", &w_total);
	printf("\nmax solution= %d", binary_knapsack(n, w_total, w, cost));
}
