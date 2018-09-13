#include <stdio.h>

//
//void test()
//{
//	static int num = 0;
//	num++;
//	printf("%d ",num);
//}
//
//int main()
//{
//	int i = 0;
//	for (i=0;i<10;i++)
//	{
//		test();
//	}
//	return 0;
//}

//#i/*nclude <stdio.h>
//
//void print(int arr[],int sz)
//{
//	int i = 0;
//	for (i=0;i<sz;i++)
//	{
//		printf("%d ",arr[i]);
//	}
//}
//void Move(int arr[],int j,int sz)
//{
//	int i = 0;
//	for (i=0;i<sz-j-1;i++)
//	{
//		arr[j] = arr[j+1];
//	}
//}
//
//void getSingle(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0;i<sz;i++)
//	{
//		for (j=1;j<sz-i-1;j++)
//		{
//			if (arr[i] = arr[j])
//			{
//				Move(arr,j,sz);
//			}
//		}
//		
//	}
//}
//int main()
//{
//	int arr[] = {1,1,2,3,3,4,4,5,5,6,6};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	print(arr,sz);
//
//	getSingle(arr,sz);
//	
//	printf("\n");
//	print(arr,sz);
//	return 0;
//}*/

#include <stdio.h>

void print(int arr[],int sz)
{
	int i = 0;
	for (i=0;i<sz;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void getSingle(int *arr,int sz)
{
	int i = 0;
	int j = 0;
	while (++j<sz)
	{
		if (arr[i] != arr[j])
		{
			arr[++i] = arr[j];
		}
	}
	for (j=0;j<=i;j++)
	{
		printf("%d ",arr[j]);
	}
}
int main()
{
	int arr[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,8,9,9};
	int sz = sizeof(arr)/sizeof(arr[0]);
	
	print(arr,sz);
	getSingle(arr,sz);
	
	return 0;
}