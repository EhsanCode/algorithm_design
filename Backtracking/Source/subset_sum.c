// Subset sum

#include <stdio.h>
#include <conio.h>

int w[100], sum_m, w_total, w_sum_s = 0, w_m = 0, nodnum[100];

void display(int n)
{
	printf("\n { ");
	for (int i = 0; i <= n; i++)
		printf("w%d ", nodnum[i]);
	printf("}");
}

int check(int i)
{
	if (w_sum_s + w[i] == w_m)
		return 0;
	if ((w_sum_s + w[i] <= w_m) && (sum_m + w_sum_s >= w_m))
		return 1;
	return -1;
}

void find_sum(int i, int n, int t)
{
	if (i >= t)
		return;
	int p = check(i);
	sum_m -= w[i];
	if (p == 0)
	{
		nodnum[n] = i;
		display(n);
	}
	else if (p == 1)
	{
		w_sum_s += w[i];
		nodnum[n] = i;
		find_sum(i + 1, n + 1, t);
		w_sum_s -= w[i];
	}
	find_sum(i + 1, n, t);
	sum_m += w[i];
}

void main(void)
{
	int t;
	printf("\nEnter n:");
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("w%d = ", i);
		scanf("%d", &w[i]);
		w_total += w[i];
	}
	sum_m = w_total;
	printf("\nEnter W total:");
	scanf("%d", &w_m);
	find_sum(0, 0, t);
}
