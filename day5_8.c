
#include <stdio.h>
//#include <Windows.h>
//int fun()
//{
//	static int count = 1;
//	return ++count;
//}
//int main()
//{
//
//	int answer;
//	answer = fun() - fun()*fun();
//	printf("%d\n",answer);
//	return 0;
//}
//
//int main()
//{
//	int MessageBoxIndirect(){
//		CONST LPMSGBOXPARAMS lpMsgBoxParams ;
//	 message box parameters);
//	}
//	MessageBox(0,"haha","First",1);
//	
//	return 0;
//}

//2. 
//使用函数实现两个数的交换。 
//void swap(int *pa,int *pb)
//{
//int tem = 0;
//tem =*pa;
//*pa=*pb;
//*pb=tem;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("input two number>>");
//	scanf("%d%d",&a,&b);
//	printf("before change :%d %d\n",a,b);
//	swap(&a,&b);
//	printf("after change :%d %d\n",a,b);
//
//	return 0;
//}



////
//1. 
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定， 
//输入9，输出9*9口诀表，输出12，输出12*12的乘法口诀表。 
//void test(int x,int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i=1;i<=x;i++)
//	{
//		for (j=1;j<=y;j++)
//		{
//			printf("%d*%d=%-6d",i,j,i*j);
//		}
//		printf("\n");
//	}
//
//}
//
//int main()
//{
//
//	int a = 0;
//	int b = 0;
//	printf("input row and col>>>");
//	scanf("%d%d",&a,&b);
//	test(a,b);
//}

//
//3. 
//实现一个函数判断year是不是润年。 
//int test(int a)
//{
//	if((a%4 == 0 && a%400 != 0)||a%400==0)
//	{
//		return 1;
//	}else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int num = 0;
//	int ret = 0;
//	printf("input a year>>");
//	scanf("%d",&num);
//	ret = test(num);
//	if(ret)
//	{
//		printf("%d是闰年。\n",num);
//	}else
//	{
//		printf("%d不是闰年。\n",num);
//	}
//	return 0;
//}


//4. 
//创建一个数组， 
//实现函数init（）初始化数组、 
//实现empty（）清空数组、 
//实现reverse（）函数完成数组元素的逆置。 
//要求：自己设计函数的参数，返回值。 
//void init(int arr[], int size)
//{
//	int i = 0;
//	for(i=0;i<size;i++)
//	{
//		arr[i] = i;
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//}
//
//empty(int arr[], int size)
//{
//	int i = 0;
//	for(i=0;i<size;i++)
//	{
//		arr[i] = 0;
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//}
//
//reverse(int arr[],int size)
//{
//	int left = 0;
//	int right = size-1;
//	int i = 0;
//	for (i=0;i<size;i++)
//	{
//		
//		while(left<right)
//		{
//			int tem=arr[left];
//			arr[left] = arr[right];
//			arr[right] = tem;
//			left++;
//			right--;
//
//		}
//		printf("%d ",arr[i]);
//
//	}
//	printf("\n");
//}
//int main()
//{
//
//	int arr[10] ={0};
//	int size = sizeof(arr)/sizeof(arr[0]);
//	printf("init>>\n");
//	init(arr,size);
//	
//	printf("reverse>>\n");
//	reverse(arr,size);
//
//	printf("empty>>\n");
//	empty(arr,size);
//
//	return 0;
//}


//5.实现一个函数，判断一个数是不是素数。
//#include <math.h>
//int prime(int num)
//{
//	int i = 0;
//	for (i=2;i<sqrt(num);i++)
//	{
//		if (num%i==0)
//		{
//			return 0;
//		}
//	return 1;
//	}
//}
//int main()
//{
//	int number = 0;
//	int ret = 0;
//	printf("input a number>>>");
//	scanf("%d",&number);
//	ret = prime(number);
//	if (ret)
//	{
//		printf("Is a prime\n");
//	}else{
//		printf("Is not a prime\n");
//	}
//	return 0;
//}