// Match schedule

#include <stdio.h>
#include <conio.h>

int mat [150][150];

void tor_ply(int n)
	{
	 int i,j,x,set,totall_day,n2vom,up2vom;
	 if (n==2)
		{
		 mat[0][0]=2;
		 mat[1][0]=1;
		 return;
		}
	 else if (n==3)
		{
		 mat[0][0]=2;
		 mat[0][1]=3;
		 mat[0][2]=0;
		 mat[1][0]=1;
		 mat[1][1]=0;
		 mat[1][2]=3;
		 mat[2][0]=0;
		 mat[2][1]=1;
		 mat[2][2]=2;
		 return;
		}
	 else if (n==4)
		{
		 mat[0][0]=2;
		 mat[0][1]=3;
		 mat[0][2]=4;
		 mat[1][0]=1;
		 mat[1][1]=4;
		 mat[1][2]=3;
		 mat[2][0]=4;
		 mat[2][1]=1;
		 mat[2][2]=2;
		 mat[3][0]=3;
		 mat[3][1]=2;
		 mat[3][2]=1;
		 return;
		}
	 else if (n%2==1)
		{
		 totall_day=n;
		 n2vom=(n+1)/2;
		 up2vom=n2vom-1;
		 tor_ply(n2vom);
		}
	 else
		{
		 totall_day=n-1;
		 n2vom=n/2;
		 up2vom=n/2;
		 tor_ply(n2vom);
		}
/********     Combinations        **********/
	 set=n2vom+1;
	 for (i=0;i<up2vom;i++)
		for (j=0;j<n2vom;j++)
			 if (mat[i][j]==0)
				{
				 if (set<=n)
					mat[i][j]=set;
				 mat[i+n2vom][j]=set-n2vom;
				 set++;
				}
			 else if (mat[i][j]+n2vom<=n)
				mat[i+n2vom][j]=mat[i][j]+n2vom;
			 else
				mat[i+n2vom][j]=0;
/********       Shift       **********/
	 set=n2vom*2;
	 for (j=n2vom;j<totall_day;j++)
		{
		 if (j+2<=n)
			{
			 mat[0][j]=j+2;
			 mat[j+1][j]=1;
			}
		 else
			mat[0][j]=0;
		}
	 for (i=1;i<n2vom;i++)
		for (j=n2vom;j<totall_day;j++)
			{
			 x=mat[i-1][j]+1;
			 if (x==1)
				{
				 mat[i][j]=n2vom+1;
				 mat[n2vom][j]=i+1;
				}
			 else if (x>n)
				{
				 if (up2vom==n2vom)
					{
					 mat[i][j]=up2vom+1;
					 mat[up2vom][j]=i+1;
					}
				 else
					mat[i][j]=0;
				}
			 else
				{
				 mat[i][j]=x;
				 mat[x-1][j]=i+1;
				}
			}
	}

void main(void)
	{
	 int i,j,n,so;
	 mat [0][0]=0;
	 clrscr();
	 printf("Enter number of teams: ");
	 scanf("%d",&n);
	 if (n>1)
		tor_ply(n);
	 so=n;
	 if (n%2==0)
		so=n-1;
	 printf("\n      ");
	 for (i=0;i<so;i++)
		printf(" %2d",i+1);
	 printf("\n      \\");
	 for (i=0;i<n;i++)
		{
		 printf("\n %3d  ",i+1);
		 for (j=0;j<so;j++)
			printf(" %2d",mat[i][j]);
		}
	 getch();
	}
