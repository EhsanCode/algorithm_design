// Scheduling jobs

#include <stdio.h>
#include <conio.h>

int list[100][2];

void merge(int fl1, int el1, int fl2, int el2)
{
	int list_h[500][2], i = 0, f = fl1;
	while (fl1 <= el1 && fl2 <= el2)
		if (list[fl1][1] < list[fl2][1])
		{
			list_h[i][0] = list[fl1][0];
			list_h[i++][1] = list[fl1++][1];
		}
		else
		{
			list_h[i][0] = list[fl2][0];
			list_h[i++][1] = list[fl2++][1];
		}

	while (fl1 <= el1)
	{
		list_h[i][0] = list[fl1][0];
		list_h[i++][1] = list[fl1++][1];
	}

	while (fl2 <= el2)
	{
		list_h[i][0] = list[fl2][0];
		list_h[i++][1] = list[fl2++][1];
	}

	for (i = f; i <= el2; i++)
	{
		list[i][0] = list_h[i - f][0];
		list[i][1] = list_h[i - f][1];
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

int scheduling(int n)
{
	int i, sum = 0;
	marge_sort(n);
	printf("\n\n Sort the jobs : ");
	for (i = 0; i < n; i++)
	{
		sum += list[i][1] * (n - i);
		printf(" %d ", list[i][0] + 1);
	}

	return sum;
}

void main(void)
{
	int i, n;
	printf("\nEnter number of jobs: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Service time for job %d= ", i + 1);
		scanf("%d", &list[i][1]);
		list[i][0] = i;
	}

	printf("\n Waiting time = %d ", scheduling(n));
}
