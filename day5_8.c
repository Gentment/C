
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
//ʹ�ú���ʵ���������Ľ����� 
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
//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ���� 
//����9�����9*9�ھ������12�����12*12�ĳ˷��ھ��� 
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
//ʵ��һ�������ж�year�ǲ������ꡣ 
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
//		printf("%d�����ꡣ\n",num);
//	}else
//	{
//		printf("%d�������ꡣ\n",num);
//	}
//	return 0;
//}


//4. 
//����һ�����飬 
//ʵ�ֺ���init������ʼ�����顢 
//ʵ��empty����������顢 
//ʵ��reverse���������������Ԫ�ص����á� 
//Ҫ���Լ���ƺ����Ĳ���������ֵ�� 
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


//5.ʵ��һ���������ж�һ�����ǲ���������
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