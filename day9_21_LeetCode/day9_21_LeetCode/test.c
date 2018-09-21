#include<stdio.h>
/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
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