// Binomial coefficient nCk 
// Dynamic

#include <stdio.h>

int nCk(int n,int k)
	{
	 int j,pl,p=0,b[400]; /* Max = k+n+1 */
	 for (int i=0;i<=n;i++)
		{
		 pl=p;
		 if (i%2)
			p=i+p;
		 else
			p=0;
		 for (j=0;(j<=i && j<=k);j++)
			 if (j==0 || j==i)
				 b[j+p]=1;
			 else
				 b[j+p]=b[j+pl-1]+b[j+pl];
		 j--;
		}
	 return b[j+p];
	}

void main(void)
	{
	 int n,k;
	 scanf("%d %d",&n,&k);
	 printf("%d\n",nCk(n,k));
	}