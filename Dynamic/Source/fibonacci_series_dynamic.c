// Fibonacci series
// Dynamic

#include <stdio.h>

int fib(int n)
{
	int f[300], i;
	f[0] = 0;
	f[1] = 1;
	for (i = 2; i <= n; i++)
		f[i] = f[i - 1] + f[i - 2];
	return f[i - 1];
}

void main(void)
{
	int n;
	printf("\nEnter n:");
	scanf("%d", &n);
	printf("\nfib(%d)=%d", n, fib(n));
}
