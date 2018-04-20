#include<stdio.h>
int main()
{
	int i, j, k;
	printf("\n");
	for (i = 1; i <= 10; i++)
	{
		for (j = 1; j <= 10; j++)
		{
			k = i*j;
			printf("%d*%d=%-5d\t", i, j, k);
		}
		printf("\n");
	}
	system("pause");
}
