#include <stdio.h>
#include <assert.h>

////����ð����������
//void BubbleSort1(int* arr,int value)
//{
//	int i = 0;
//	int j = 0;
//	for (i=0;i<value;i++)
//	{
//      int flag = 0;   //����flag�����ж��Ƿ�ԭ�����ǰ���˳�����е� 
//		for (j=value-1;j>=i;j--)
//		{
//			if (arr[j]<arr[j-1])
//			{
//				int tmp = arr[j-1];
//				arr[j-1] = arr[j];
//				arr[j] = tmp;
//				flag = 1;
//			}
//
//		}
//		if(flag == 0)
//			break;
//	}
//	
//}

////ָ��ʵ�ֵ���ð������(����)
//void BubbleSort2(int *arr,int sz)
//{
//	int *start = arr;
//	int *end = arr+sz-1;
//	int *cur = NULL;
//	assert(arr!=NULL);
//	while (start<end)
//	{
//		cur = start;
//		while (cur<end)
//		{
//			if (*cur<*cur+1)
//			{
//				int tmp = *cur;
//				*cur = *cur+1;
//				*(cur+1) = tmp;
//			}
//			cur++;
//		}
//		end--;
//	}
//
//}

//˫��ð������
//void BubbleSort3(int *arr , int sz)
//{
//	int left = 1;
//	int right = sz-1;
//	int i = 0;
//	int t = 0;
//	
//	while (left<right)
//	{
//		for (i=right;i>=left;i--)
//		{
//			if (arr[i]<arr[i-1])
//			{
//				int tmp = arr[i];
//				arr[i] = arr[i-1];
//				arr[i-1] = tmp;
//				t = i;
//			}
//
//		}
//		left = 1+t;
//		for (i=left;i<right+1;i++)
//		{
//			if (arr[i]<arr[i-1])
//			{
//				int tmp = arr[i];
//				arr[i] = arr[i-1];
//				arr[i-1] = tmp;
//				t = i;
//			}
//		}
//		right = i-1;
//	}
//}

//
//void Swap( int *num_a, int *num_b )  
//{  
//	int temp = *num_b;  
//	*num_b = *num_a;  
//	*num_a = temp;  
//}
//
//void BubbleSort3(int array[], int n)  
//{  
//	int low, high, flag, i;  
//	low = 0;  
//	high = n - 1;  
//	while(low < high)  
//	{  
//		flag=0;  
//		for(i=low; i<high; i++)  //����ð��  
//		{  
//			if(array[i] > array[i+1]) //�ҵ�ʣ��������  
//			{  
//				Swap(&array[i], &array[i+1]);  
//				flag = 1;    //��־�� �����ݽ���  
//			}  
//		}  
//		if( !flag )  
//			break;  
//		high--;  
//		for( i=high; i>low; i-- ) //����ð��  
//		{  
//			if(array[i] < array[i-1])   //�ҵ�ʣ������С��  
//				Swap(&array[i], &array[i-1]);  
//		}  
//		low++;  
//	}  
//}  
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9};
//	int i = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	
//	printf("������������\n");
//	BubbleSort1(arr,sz);
//	for (i=0;i<sz;i++)
//	{
//		printf("%d  ",arr[i]);
//	}
//	printf("\n");
//
//	printf("����������\n");
//	BubbleSort2(arr,sz);
//	for (i=0;i<sz;i++)
//	{
//		printf("%d  ",arr[i]);
//	}
//	printf("\n");
//
//	printf("˫����������\n");
//	BubbleSort3(arr,sz);
//	for (i=0;i<sz;i++)
//	{
//		printf("%d  ",arr[i]);
//	}
//		printf("\n");
//	return 0;
//}