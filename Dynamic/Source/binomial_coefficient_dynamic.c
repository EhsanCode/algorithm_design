// binomialcoefficient nCk
// Dynamic

#include <stdio.h>

int nCk(int n, int k)
{
	int b[150][150];
	for (int i = 0; i <= n; i++)
		for (int j = 0; (j <= i && j <= k); j++)
			if (j == 0 || j == i)
				b[i][j] = 1;
			else
				b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
	return b[n][k];
}

void main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", nCk(n, k));
}
