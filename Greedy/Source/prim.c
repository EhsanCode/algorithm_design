// Prim’s Minimum Spanning Tree

#include <stdio.h>

int a[100][100];

int prim(int n)
{
	int sum = 0, near, i, j, min, nearest[100], distance[100];
	for (i = 0; i < n; i++)
	{
		nearest[i] = 0;
		distance[i] = a[0][i];
	}

	// greedy loop
	for (j = 0; j < n - 1; j++)
	{
		min = 1000;
		for (i = 1; i < n; i++)
			if (distance[i] < min && distance[i] > -1)
			{
				min = distance[i];
				near = i;
			}

		printf("\nV%d -(%d)-> V%d ", nearest[near] + 1, distance[near], near + 1);
		sum += distance[near];
		for (i = 1; i < n; i++)
			if (a[near][i] < distance[i])
			{
				distance[i] = a[near][i];
				nearest[i] = near;
			}

		distance[near] = -1;
	}

	return sum;
}

void main(void)
{
	int i, j, n;
	printf("\nEnter number of nodes: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			printf("a[%d][%d] = ", i + 1, j + 1);
			scanf("%d", &a[i][j]);
		}

	printf("\n   w=%d", prim(n));
}
