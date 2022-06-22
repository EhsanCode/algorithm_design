// Scheduling jobs on two machines

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

void scheduling(int n)
{
	int i, j = 0, m1, m2, sum1 = 0, sum2 = 0;
	marge_sort(n);
	printf("\n\n    Number of jobs: ");
	printf("\n  Automaton 1 | Automaton 2");
	printf("\n -------------+-------------");
	m1 = n / 2;
	m2 = m1;
	if (n % 2 == 1)
		m1++;

	for (i = 0; i < n - 1; i += 2, j++)
	{
		sum1 += list[i][1] * (m1 - j);
		sum2 += list[i + 1][1] * (m2 - j);
		printf("\n\t %4d | %d ", list[i][0] + 1, list[i + 1][0] + 1);
	}

	if (n % 2 != 0)
	{
		sum1 += list[i][1] * (m1 - j);
		printf("\n\t %4d |", list[i][0] + 1);
	}

	printf("\n Waiting time Automaton 1 = %d ", sum1);
	printf("\n Waiting time Automaton 2 = %d ", sum2);
	printf("\n Sum waiting time = %d ", sum1 + sum2);
}

void main(void)
{
	int i, n;
	printf("\nEnter number of jobs: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Service time for job %d = ", i + 1);
		scanf("%d", &list[i][1]);
		list[i][0] = i;
	}

	scheduling(n);
}
