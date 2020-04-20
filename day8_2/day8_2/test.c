#include <stdio.h>


void SelectSort(int arr[],int len)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for (i=0;i<len-1;i++)
	{
		for (j=i+1;j<len;j++)
		{
			if (arr[i]>arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

	}
}

void Print(int arr[],int len)
{
	int i = 0;
	for (i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}

}

//void InsertSort(int arr[],int n)
//{
//	int i =0;
//	int j = 0;
//	int tmp = 0;
//	for (i=1;i<n;i++)
//	{
//		if (arr[i]<arr[i-1])
//		{
//			tmp = arr[i];
//			for (j=i-1;arr[j]>tmp;j--)
//			{
//				arr[j+1] = arr[j];
//			}
//			arr[j+1] = tmp;
//		}
//	}
//}
void InsertSort(int arr[],int len)
{
	int i= 0;
	int j =0;
	int temp = 0;
	for (i=1;i<len;i++)
	{
		if (arr[i]<arr[i-1])
		{
			temp = arr[i];
			for (j=i-1;arr[j]>temp;j--)
			{
				arr[j+1] = arr[j];
			}
			arr[j+1] = temp;
		}
	}
}

int main()
{
	int arr[] ={2,8,6,9,4,5,3,1,0,7};
	//SelectSort(arr,10);
	InsertSort(arr,10);
	Print(arr,10);

}