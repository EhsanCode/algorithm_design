// Multiplication of Large Integers

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

char sum_char(char a, char b, int *cary)
{
	int c;
	c = a + b - 2 * '0' + (*cary);
	*cary = c / 10;
	return (c % 10 + '0');
}

char *add(char a[], char b[])
{
	int a_len, b_len, i;
	char c[51];
	int cary = 0;
	a_len = strlen(a) - 1;
	b_len = strlen(b) - 1;
	i = max(a_len, b_len);
	c[i + 2] = NULL;
	for (; a_len >= 0 && b_len >= 0; i--)
		c[i + 1] = sum_char(a[a_len--], b[b_len--], &cary);
	if (a_len >= 0)
		for (; a_len >= 0; i--)
			c[i + 1] = sum_char(a[a_len--], '0', &cary);
	else if (b_len >= 0)
		for (; b_len >= 0; i--)
			c[i + 1] = sum_char('0', b[b_len--], &cary);
	if (cary == 0)
		return c + 1;
	c[0] = cary + '0';
	return c;
}

void divide_rem(char *s, char *p, char *q, int m)
{
	if (m <= 0)
	{
		p[0] = NULL;
		q[0] = NULL;
		return;
	}
	if (m >= strlen(s))
	{
		strcpy(p, s);
		q[0] = NULL;
		return;
	}
	memcpy(p, s, m); // memcpy copies mbytes bytes from the "a" string to the "p" string.
	p[m] = NULL;
	strcpy(q, s + m);
}

char *smal_mult(char a[], char b[])
{
	char c[50];
	return itoa(atoi(a) * atoi(b), c, 10);
}

char *mult(char a[], char b[])
{
	char exp[50], d[100], c[100], x[50], y[50], w[50], z[50];
	int m, n;
	if (a == NULL || b == NULL)
		return 0;
	n = max(strlen(a), strlen(b));
	if (n <= 1)
		return smal_mult(a, b);
	m = n / 2;
	divide_rem(a, x, y, m);
	divide_rem(b, w, z, m);
	strcpy(d, mult(x, z));
	strcpy(d, add(d, mult(w, y)));
	memset(exp, '0', m);
	exp[m] = NULL;
	strcat(d, exp);
	strcpy(c, mult(x, w));
	memset(exp, '0', 2 * m);
	exp[2 * m] = NULL;
	strcat(c, exp);
	strcpy(c, add(c, d));
	strcpy(c, add(c, mult(y, z)));
	return c;
}

void main(void)
{
	char a[50], b[50];
	puts("\nEnter A:");
	gets(a);
	puts("Enter B:");
	gets(b);
	printf("\nA*B=%s", mult(a, b));
}