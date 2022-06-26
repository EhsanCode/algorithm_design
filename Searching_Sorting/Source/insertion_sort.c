// Insertion sort

#include <conio.h>
#include <stdio.h>

void insertion_sort(int list[], int n)
{
	int t, i, j;
	for (i = 1; i < n; i++)
	{
		t = list[i];
		for (j = i - 1; j >= 0 && t > list[j]; j--)
			list[j + 1] = list[j];
		list[j + 1] = t;
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
	insertion_sort(list, n);
	print_results(list, n);
	getch();
}
