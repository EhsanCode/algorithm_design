// Fractional knapsack

#include <stdio.h>
#include <conio.h>

float list[100][3];

void merge(int fl1, int el1, int fl2, int el2)
{
	float list_h[500][3];
	int i = 0, f = fl1;
	while (fl1 <= el1 && fl2 <= el2)
		if (list[fl1][1] > list[fl2][1])
		{
			list_h[i][0] = list[fl1][0];
			list_h[i][1] = list[fl1][1];
			list_h[i++][2] = list[fl1++][2];
		}
		else
		{
			list_h[i][0] = list[fl2][0];
			list_h[i][1] = list[fl2][1];
			list_h[i++][2] = list[fl2++][2];
		}

	while (fl1 <= el1)
	{
		list_h[i][0] = list[fl1][0];
		list_h[i][1] = list[fl1][1];
		list_h[i++][2] = list[fl1++][2];
	}

	while (fl2 <= el2)
	{
		list_h[i][0] = list[fl2][0];
		list_h[i][1] = list[fl2][1];
		list_h[i++][2] = list[fl2++][2];
	}

	for (i = f; i <= el2; i++)
	{
		list[i][0] = list_h[i - f][0];
		list[i][1] = list_h[i - f][1];
		list[i][2] = list_h[i - f][2];
	}
}

void marge_sort(int n)
{
	int p, i;
	for (p = 2; p < n * 2; p *= 2)
	{
		for (i = 0; i + p < n; i += p)
			merge(i, (i + p / 2) - 1, i + p / 2, i + p - 1);

		if (i + p >= n && n - i > p / 2)
			merge(i, (i + p / 2) - 1, i + p / 2, n - 1);

		p /= 2;
		if (i + p >= n)
			merge(i, (i + p / 2) - 1, i + p / 2, n - 1);

		p *= 2;
	}
}

float scheduling(int n, float w)
{
	int i;
	float sum_w = 0, sum_cost = 0, w_temp;
	marge_sort(n);
	printf("\n");
	for (i = 0; i < n && sum_w + list[i][2] <= w; i++)
	{
		sum_w += list[i][2];
		sum_cost += list[i][1] * list[i][2];
		printf("\n k%1.0f : %f Kg ", list[i][0] + 1, list[i][2]);
	}

	if (sum_w != w && i < n)
	{
		if (w - sum_w >= list[i][2])
			w_temp = list[i][2];
		else
			w_temp = w - sum_w;

		sum_w += w_temp;
		sum_cost += list[i][1] * w_temp;
		printf("\n k%1.0f : %f Kg ", list[i][0] + 1, w_temp);
	}

	return sum_cost;
}

void main(void)
{
	int i, n;
	float w;
	printf("\nEnter number of items: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("k%d :", i + 1);
		printf("\n    w=");
		scanf("%f", &list[i][2]);
		printf(" Cost=");
		scanf("%f", &list[i][1]);
		list[i][1] /= list[i][2];
		list[i][0] = i;
	}

	printf("\nW total=");
	scanf("%f", &w);
	printf("\n Max cost = %f $", scheduling(n, w));
}