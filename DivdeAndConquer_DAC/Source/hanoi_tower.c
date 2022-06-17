// Hanoi Tower

#include <conio.h>
#include <stdio.h>

void towers(int n, char f, char t, char a)
{
	if (n == 1)
		printf("move disk 1 from %c to %c \n", f, t);
	else
	{
		towers(n - 1, f, a, t);
		printf("move disk %d from %c to %c \n", n, f, t);
		towers(n - 1, a, t, f);
	}
}

void main(void)
{
	char f, t, a;
	int n;
	printf("\n Enter number of disks:");
	scanf("%d", &n);
	towers(n, 'E', 'F', 'H');
}
