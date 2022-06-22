// Dijkastra’s Shortest Path Algorithm

#include <stdio.h>
#include <conio.h>

#define LIMITLESS 1000
int a[100][100];

void dijkstra(int n)
{
	int vnear, i, w, k, v, min, c[100], d[100], p[100];
	for (i = 0; i < n; i++)
	{
		d[i] = a[0][i];
		p[i] = 0;
	}

	// greedy loop
	for (k = 1; k < n; k++)
	{
		min = LIMITLESS;
		printf("\n D%d= {", k);
		for (i = 1; i < n; i++)
			printf(" %d ", d[i]);

		printf("}");
		for (i = 1; i < n; i++)
			if (c[i] != -1)
				if (d[i] < min)
				{
					min = d[i];
					v = i;
				}

		for (w = 1; w < n; w++)
			if (c[i] != -1)
				if (d[w] > d[v] + a[v][w])
				{
					d[w] = d[v] + a[v][w];
					p[w] = v;
				}
		c[v] = -1;
	}
	printf("\n D%d= {", k);
	for (i = 1; i < n; i++)
		printf(" %d ", d[i]);

	printf("}");
	printf("\n\n p= {");
	for (i = 0; i < n; i++)
		printf(" %d ", p[i] + 1);

	printf("}\n");
	for (i = 0; i < n; i++)
	{
		printf("\n %d to %d :", 1, i + 1);
		if (d[i] >= LIMITLESS)
			printf(" Not find path.");
		else
		{
			printf(" %d<-", i + 1);
			v = i;
			while (p[v] != 0)
			{
				printf("%d<-", p[v] + 1);
				v = p[v];
			}
			printf("1 & W=%d", d[i]);
		}
	}
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

	dijkstra(n);
}
