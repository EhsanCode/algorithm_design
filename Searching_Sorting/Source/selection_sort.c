// Selection sort

#include <stdio.h>
#include <conio.h>

void xchange(int list[], int x, int y)
{
	int temp;
	temp = list[x];
	list[x] = list[y];
	list[y] = temp;
}

void selection_sort(int list[], int n)
{
	int min, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;

		xchange(list, i, min);
	}
}

void read_list(int list[], int n)
{
	int i;
	printf("Enter numbers:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &list[i]);
}

void print_results(int list[], int n)
{
	int i;
	printf("\nSorted list:\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
}

void main(void)
{
	int list[100], n;
	printf("\nEnter the list length:");
	scanf("%d", &n);
	read_list(list, n);
	selection_sort(list, n);
	print_results(list, n);
	getch();
}
