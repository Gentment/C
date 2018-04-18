#include<stdio.h>
#include<math.h>

int fun(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int  n;
	//printf("请输入一个数:\n");
	// scanf("%d",&n);
	for (n = 100; n<200; n++){
		if (fun(n))
			printf("%d\t", n);
		//	 printf(","); 	
	}
	// printf("该数是素数:\n");
	// else
	// printf("该数不是是素数:\n");
	system("pause");
}
