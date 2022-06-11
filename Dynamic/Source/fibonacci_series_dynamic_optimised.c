// Fibonacci series
// Dynamic - optimised

#include <stdio.h>

int fib(int n)
	{
	 int temp0,temp1,f,i;
	 temp0=0;
	 temp1=1;
	 for (i=2;i<=n;i++)
		{
		 f=temp0+temp1;
		 temp0=temp1;
		 temp1=f;
		}
	 return f;
	}

void main(void)
	{
	 int n;
	 printf("\nEnter n:");
	 scanf("%d",&n);
	 printf("\nfib(%d)=%d",n,fib(n));
	}

