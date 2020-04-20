#include<stdio.h>
/*
����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 ���ҳ��������������Ҳ��ظ�����Ԫ�顣
*/



/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) 
{
	if (numsSize < 3)
	{
		return NULL;
	}
	int index = 0;
	int i = 0, j = 0;
	for (i = 0; i < numsSize -2; i++)
	{
		int first = nums[j];
		for (j = 0; j < numsSize-i-2; j++)
		{
			int second = nums[j+1];
			int third = nums[j + 2];
			int sum = first + second + third;
			if (sum == 0)
			{
				returnSize[index++] = first;
				returnSize[index++] = second;
				returnSize[index++] = third;
			}
			
		}

	}
	return *returnSize;
}



int main()
{
	int arr[] = { 1,0,2,3,4,-1,-5,-3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int *retArr;
	threeSum(arr,size,retArr);

	//for (int i = 0; i < retArr; i++)
	//{

	//}
}