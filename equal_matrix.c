// 4. WAP to find weather two matrix are equal or not.
#include <stdio.h>
int main()
{
	int i, j, m, n, m1, n1, a[10][10], b[10][10], flag = 1;
	printf("Enter the size of matrix A :\n");
	scanf("%d %d", &m, &n);
	printf("Enter the size of matrix B:\n");
	scanf("%d %d", &m1, &n1);
	printf("Enter the First matrix elements:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	printf("Enter the Second matrix elements:\n");
	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < n1; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}
	if (m == n && m1 == n1)
	{
		printf("Matrix can be operated.\n");
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n1; j++)
			{
				if (a[i][j] != b[i][j])
				{
					flag = 0;
					break;
				}
			}
		}
	}
	else
		printf("cant be compared.\n");
	if (flag == 1)

		printf("Matrix is  equal.\n");
	else
		printf("But, Matrix is not equal.\n");
}
