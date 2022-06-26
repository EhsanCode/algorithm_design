// Binary search

#include <stdio.h>
#include <conio.h>

int binary_search(int f, int e, int num, int ary[])
{
	int p;
	if (f > e)
		return -1;

	p = (e + f) / 2;
	if (num == ary[p])
		return p;

	if (num < ary[p])
		return binary_search(f, p - 1, num, ary);

	return binary_search(p + 1, e, num, ary);
}

void main(void)
{
	int ary[100], n, x, i;
	char to_continue = 'y';
	printf("\nEnter the list length:");
	scanf("%d", &n);
	printf("Enter a sorted list of %d numbers:\n", n);
	for (i = 0; i < n; i++)
		scanf("%d", &ary[i]);

	do
	{
		printf("\nEnter number for search :");
		scanf("%d", &x);
		int idx = binary_search(0, n - 1, x, ary);
		if (idx == -1)
			printf("Not found!\n");
		else
			printf("Found at index %d\n", idx);
		printf("Continue (y or n)?");
		to_continue = getche();
	} while (to_continue == 'y' || to_continue == 'Y');
}
