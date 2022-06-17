// Matrix multiplication

#include <math.h>
#include <stdio.h>

int a[100][100], b[100][100], c[100][100];

void mult(int p, int q, int s)
{
	int i, j, k;
	for (i = 0; i < p; i++)
		for (j = 0; j < q; j++)
		{
			c[i][j] = 0;
			for (k = 0; k < s; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
}

void main(void)
{
	int p, q, s1, s2, i, j;
	printf("\nInput dimension of matrix A (p*s) :");
	scanf("%d*%d", &p, &s1);
	printf("\nInput dimension of matrix B (s*q) :");
	scanf("%d*%d", &s2, &q);
	if (s1 != s2)
		printf("Invalid dimension !");
	else
	{
		for (i = 0; i < p; i++)
			for (j = 0; j < s1; j++)
			{
				printf("a[%d][%d] = ", i + 1, j + 1);
				scanf("%d", &a[i][j]);
			}
		for (i = 0; i < s1; i++)
			for (j = 0; j < q; j++)
			{
				printf("b[%d][%d] = ", i + 1, j + 1);
				scanf("%d", &b[i][j]);
			}
		mult(p, q, s1);
		for (i = 0; i < p; i++)
			for (j = 0; j < q; j++)
				printf("\nb[%d][%d] = %d", i + 1, j + 1, c[i][j]);
	}
}
