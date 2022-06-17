// Hamiltonian cycle

#include <conio.h>
#include <stdio.h>

int mat[100][100];
int path[100];
int check(int j, int node, int end)
{
   register int l;
   if (mat[path[j - 1]][node] == 0)
      return 0;
   if (j == end - 1 && mat[0][node] == 0)
      return 0;
   for (l = 0; l < j; l++)
      if (path[l] == node)
         return 0;
   return 1;
}

void display(int end)
{
   register int m;
   static int solution_number = 0;
   printf("\n *(%d)* \n", ++solution_number);
   for (m = 0; m < end; m++)
      printf("(V%d)->", path[m] + 1);
   printf("(V1)");
}

void hamiltonian_cycle(int n, int end)
{
   int i;
   if (n == end)
      display(end);
   else
      for (i = 0; i < end; i++)
         if (check(n, i, end) != 0)
         {
            path[n] = i;
            hamiltonian_cycle(n + 1, end);
            path[n] = -1;
         }
}

void main(void)
{
   int i, j, n;
   printf("\nEnter n=");
   scanf("%d", &n);
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
      {
         printf("a[%d][%d] = ", i + 1, j + 1);
         scanf("%d", &mat[i][j]);
      }
   path[0] = 0;
   hamiltonian_cycle(1, n);
}
