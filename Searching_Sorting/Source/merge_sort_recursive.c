// Merge sort

#include <conio.h>
#include <stdio.h>

void merge(int fl1, int el1, int fl2, int el2, int list[])
{
	int list_h[500], i = 0, f = fl1;
	while (fl1 <= el1 && fl2 <= el2)
		if (list[fl1] < list[fl2])
			list_h[i++] = list[fl1++];
		else
			list_h[i++] = list[fl2++];

	while (fl1 <= el1)
		list_h[i++] = list[fl1++];

	while (fl2 <= el2)
		list_h[i++] = list[fl2++];

	for (i = f; i <= el2; i++)
		list[i] = list_h[i - f];
}

void merge_sort(int f, int e, int list[])
{
	int p, i;
	if (f >= e)
		return;

	merge_sort(f, (e + f) / 2, list);
	merge_sort((e + f) / 2 + 1, e, list);
	merge(f, (e + f) / 2, (e + f) / 2 + 1, e, list);
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
	merge_sort(0, n - 1, list);
	print_results(list, n);
	getch();
}
