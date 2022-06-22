// Job Scheduling Problem with Deadlines

#include <stdio.h>
#include <conio.h>

int list[100][3], sort_job[100];

void merge(int fl1, int el1, int fl2, int el2)
{
	int list_h[100][3], i = 0, f = fl1;
	while (fl1 <= el1 && fl2 <= el2)
		if (list[fl1][1] > list[fl2][1])
		{
			list_h[i][0] = list[fl1][0];
			list_h[i][2] = list[fl1][2];
			list_h[i++][1] = list[fl1++][1];
		}
		else
		{
			list_h[i][0] = list[fl2][0];
			list_h[i][2] = list[fl2][2];
			list_h[i++][1] = list[fl2++][1];
		}

	while (fl1 <= el1)
	{
		list_h[i][0] = list[fl1][0];
		list_h[i][2] = list[fl1][2];
		list_h[i++][1] = list[fl1++][1];
	}

	while (fl2 <= el2)
	{
		list_h[i][0] = list[fl2][0];
		list_h[i][2] = list[fl2][2];
		list_h[i++][1] = list[fl2++][1];
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

void scheduling_with_deadlines(int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		j = list[i][2];
		if (j > n)
			j = n;

		for (; (sort_job[j] != -1 && j > 0); j--)
			;

		if (sort_job[j] == -1 && j >= 0)
			sort_job[j] = list[i][0];
	}
}

int scheduling(int n)
{
	int i, sum = 0;
	marge_sort(n);
	scheduling_with_deadlines(n);
	printf("\n\n Sort jobs : ");
	printf("\n job  deadline   profit");
	for (i = 0; i < n; i++)
		printf("\n #%d    %-9d  %d", list[i][0] + 1, list[i][2] + 1, list[i][1]);

	printf("\n\n Optimal set of jobs :\n  { ");
	for (i = 0; i < n; i++)
		if (sort_job[i] != -1)
		{
			sum += list[sort_job[i]][1];
			printf(" %d ", sort_job[i] + 1);
		}

	printf("}");
	return sum;
}

void main(void)
{
	int i, n;
	printf("\nEnter number of jobs:");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Deadline for job %d = ", i + 1);
		scanf("%d", &list[i][2]);
		list[i][2]--;
		printf("Profit of job %d = ", i + 1);
		scanf("%d", &list[i][1]);
		list[i][0] = i;
		sort_job[i] = -1;
	}

	printf("\n Waiting time = %d ", scheduling(n));
}