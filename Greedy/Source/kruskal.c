// Kruskal’s Minimum Spanning Tree

#include <stdio.h>

int a[100][100];

int kruskal(int n)
{
	int t = -1, sum = 0, min_i, min_j = 1, min, i, j, e[100][3], m[100];
	while (min_j)
	{
		min_i = 0;
		min_j = 0;
		min = 1000;
		for (i = 0; i < n - 1; i++)
			for (j = i + 1; j < n; j++)
				if (min > a[i][j] && a[i][j] != -1)
				{
					min_i = i;
					min_j = j;
					min = a[i][j];
				}
		e[++t][0] = min_i;
		e[t][1] = min_j;
		e[t][2] = a[min_i][min_j];
		m[t] = t;
		a[min_i][min_j] = -1;
	}

	printf("\nSort:");
	for (i = 0; i < t; i++)
		printf("\n  W{V%d,V%d}= %d", e[i][0] + 1, e[i][1] + 1, e[i][2]);

	// greedy loop
	for (i = 0; i < t; i++)
		if (m[e[i][0]] != m[e[i][1]])
		{
			printf("\n%d -(%d)-> %d", e[i][0] + 1, e[i][2], e[i][1] + 1);
			sum += e[i][2];
			int q = m[e[i][1]];
			for (j = 0; j < t; j++)
				if (m[j] == q)
					m[j] = m[e[i][0]];
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

	printf("\n   w=%d", kruskal(n));
}
