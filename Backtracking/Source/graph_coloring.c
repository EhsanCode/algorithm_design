// Graph coloring

#include <conio.h>
#include <stdio.h>

#define MAX 25

int sel_color[MAX];
int mat[100][100];

int check(int j, int color)
{
  register int l;
  for (l = 0; l < j; l++)
    if (mat[l][j] == 1)
      if (sel_color[l] == color)
        return 0;
  return 1;
}

void display(int end)
{
  register int m;
  static int solution_number = 0;

  printf("\n *(%d)* \n", ++solution_number);
  for (m = 0; m < end; m++)
    printf(" nod%d color%d \n", m, sel_color[m]);
}

void m_coloring(int n, int color, int end)
{
  int i;
  if (n == end)
    display(end);
  else
    for (i = 0; i < color; i++)
      if (check(n, i) != 0)
      {
        sel_color[n] = i;
        m_coloring(n + 1, color, end);
        sel_color[n] = -1;
      }
}

void main(void)
{
  int i, j, n, color;
  printf("\nEnter n=");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
    {
      printf("a[%d][%d] = ", i + 1, j + 1);
      scanf("%d", &mat[i][j]);
    }
  printf("\nEnter MAX color :");
  scanf("%d", &color);
  m_coloring(0, color, n);
}
