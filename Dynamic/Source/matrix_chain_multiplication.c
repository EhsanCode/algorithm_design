// Matrix chain multiplication 

#include <stdio.h>
#include <conio.h>

int m[100][100];
int p[100][100];

int minimult(int n,int d[])
	{
	 int min,m_h,j,k;
	 for (int i=0;i<n;i++)
		m[i][i]=0;
	 for (int diagonal=0;diagonal<n;diagonal++)
		for (i=0;i<n-diagonal;i++)
			{
			 j=i+diagonal;
			 k=i;
			 if (k<j)
				{
				 m_h=m[i][k]+m[k+1][j]+d[i]*d[k+1]*d[j+1];
				 min=m_h;
				 m[i][j]=m_h;
				 p[i][j]=k;
				}
			 for (k=i+1;k<j;k++)
				{
				 m_h=m[i][k]+m[k+1][j]+d[i]*d[k+1]*d[j+1];
				 if (min>m_h)
					{
					 min=m_h;
					 m[i][j]=m_h;
					 p[i][j]=k;
					}
				}
			 gotoxy(j+5*j+1,i+2);
			 printf(" %d ",m[i][j]);
			}
	 return m[0][n-1];
	}

void order(int i,int j)
	{
	 if (i==j)
		printf("A%d",i+1);
	 else
		{
		 printf("(");
		 order(i,p[i][j]);
		 order(p[i][j]+1,j);
		 printf(")");
		}
	}

void main(void)
	{
	 int n,d[100];
	 printf("\nEnter n:");
	 scanf("%d",&n);
	 for (int i=0;i<=n;i++)
		{
		 printf("d%d=",i);
		 scanf("%d",&d[i]);
		}
	 clrscr();
	 int m=minimult(n,d);
	 gotoxy(2,n+2);
	 printf("\nminimult= %d\n\n\t\t",m);
	 order(0,n-1);
	}
