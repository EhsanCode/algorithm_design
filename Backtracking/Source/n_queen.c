// N-Queen

#include <conio.h>
#include <stdio.h>

#define MAX 25

int i[MAX];
int sum[MAX], diff[MAX], andis_i[MAX];
char chessboard[MAX][MAX];

void set(int j)
{
	sum[j] = i[j] + j;
	diff[j] = i[j] - j;
	andis_i[j] = i[j];
}

void empty(int j, int end)
{
	if (i[j] == 0)
		chessboard[end - 1][j] = '#';
	else
		chessboard[(i[j] - 1)][j] = '#';
}

int check(int j, int end)
{
	register int l;
	empty(j, end);
	for (l = 0; l < j; l++)
		if ((sum[l] == i[j] + j) || (diff[l] == i[j] - j) || (andis_i[l] == i[j]))
			return (0);
	chessboard[i[j]][j] = 'Q';
	set(j);
	return (1);
}

void display(int end)
{
	register int m, n;
	static int solution_number = 0;
	printf("\n\n%d :", ++solution_number);
	for (m = 0; m < end; m++)
	{
		printf("\n");
		for (n = 0; n < end; n++)
			printf(" %c", chessboard[m][n]);
	}
}

void backtracking(int n, int end)
{
	if (n == end)
		display(end);
	else
		for (i[n] = 0; i[n] < end; i[n]++)
			if (check(n, end) != 0)
				backtracking(n + 1, end);
}

void init(int end)
{
	register int m, n;
	for (m = 0; m < end; m++)
		for (n = 0; n < end; n++)
			chessboard[m][n] = '#';
}

void n_queens(int n)
{
	init(n);
	backtracking(0, n);
}

void main(void)
{
	int n;
	printf("\nn = ");
	scanf("%d", &n);
	n_queens(n);
}
