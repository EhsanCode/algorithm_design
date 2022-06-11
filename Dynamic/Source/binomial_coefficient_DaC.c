// Binomial coefficient nCk (DAC)
// divide and conquer DAC

#include <stdio.h>

int nCk(int n,int k)
	{
	 if (k==0 || k==n)
		return 1;
	 return (nCk(n-1,k-1)+nCk(n-1,k));
	}

void main(void)
	{
	 int n,k;
	 scanf("%d %d",&n,&k);
	 printf("%d\n",nCk(n,k));
	}