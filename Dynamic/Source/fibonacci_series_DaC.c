// Fibonacci series
// Divide And Conquer DAC

#include <stdio.h>

int fib(int n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 0;
	return (fib(n - 1) + fib(n - 2));
}

void main(void)
{
	int n;
	printf("\nEnter n:");
	scanf("%d", &n);
	printf("\nfib(%d)=%d", n, fib(n));
}
