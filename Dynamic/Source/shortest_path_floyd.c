// Shortest path 
// Floyd

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int n,d[100][100],p[100][100];

void floyd(void)
	{
	 int k,i,j;
	 for (k=0;k<n;k++)
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (d[i][k]+d[k][j]<d[i][j])
					{
					 p[i][j]=k+1;
					 d[i][j]=d[i][k]+d[k][j];
					}
	}

void path(int i,int j)
	{
	 while (p[i-1][j-1]!=0)
			{
			 printf(" %d <<",p[i-1][j-1]);
			 j=p[i-1][j-1];
			}
	 printf(" %d",i);
	}

void main(void)
	{
	 int k,i,j;
	 printf("\nEntert n=");
	 scanf("%d",&n);
	 for (i=0;i<n;i++)
		 for (j=0;j<n;j++)
			{
			 printf("\W[%d][%d] = ",i,j);
			 scanf("%d",&d[i][j]);
			 p[i][j]=0;
			}
	 floyd();
	 printf("\nmat d=\n");
	 for (i=0;i<n;i++)
		 {
		  printf("\n ");
		  for (j=0;j<n;j++)
			 printf("%4d",d[i][j]);
		 }
	 printf("\n\nmat p=\n");
	 for (i=0;i<n;i++)
		 {
		  printf("\n ");
		  for (j=0;j<n;j++)
			 printf("%4d",p[i][j]);
		 }
	 char ans='y';
	 while (ans=='y')
	       {
		printf("\nEnter source node : ");
		scanf("%d",&i);
		printf("\nEnter destination node :");
		scanf("%d",&j);
		printf("\n %d <<",j);
		path(i,j);
		printf("\n\n Continue? (y/n)");
		ans=getche();
	       }
	}
