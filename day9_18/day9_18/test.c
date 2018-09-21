// day9_18.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize <= 0)
	{
		return 0;
	}

	int i = 0;
	for (int j = 0; j < numsSize; j++)
	{
		if (nums[i] != nums[j])
		{
			i++;
			nums[i] = nums[j];
		}
	}
	return i + 1;
}


int removeDuplicates2(int* nums, int size) {
	if (size <= 2) {
		return size;
	}

	int i = 0;
	int j = 1;
	int count = 1;
	while (j<size)
	{
		//当nums[i]== nums[j]，count == 0时，此时这个数是第一次和后面的一个数相等
		if (nums[i] == nums[j] && count == 0) {
			++j;
		}
		else
		{	//此时判断是否与后面的数还能相等，相等时就 --count，
			//否则不相等count还是1，说明这个数只出现两次
			if (nums[i] == nums[j]) {
				--count;
			}
			else
			{
				count = 1;
			}
			//此时我们让第二次出现的这个数后移动一位，并放在这个数后面
			nums[++i] = nums[j++];
		}
	}


	return i+1;
}

int removeDuplicates3(int* nums, int numsSize)
{
	if (numsSize <= 0)
	{
		return 0;
	}

	int i = 0;
	for (int j = 0; j < numsSize; j++)
	{
		if (nums[i] != nums[j])
		{
			i++;
			nums[i] = nums[j];
		}
		if (nums[i] == nums[j])
		{
			return i;
		}
	}
	return i + 1;
}
#if 0


int main()
{

	//int arr[] = { 1,1,2,2,3,4,5,6 };
	int arr[] = { 81155225, 81142020, 81109030, 80397860, 78359913, 75504370,
		80574053, 80406066, 80405490, 81169130, 80727024, 81026634,
		80806225, 80778206, 80726673, 80719697, 80637176, 80574556,
		80469773, 80396884, 80379815, 80296843, 80293638, 80258924,
		80258924, 80230385, 80209019, 80114583, 79983059, 81195320,
		81206742, 81266253, 81013616, 81274374, 81336019, 81582947,
		81974025, 81984795, 82011296, 82055863, 82086180, 82155831,
		82263045, 81530522, 82534227, 82707041, 82718724, 82720799,
		82760317, 82760338, 82706472, 82659507 };

	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = removeDuplicates3(arr, size);
	printf("%d \n", ret);
}

#endif // 0


















