
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
void merge(int* nums1, int m, int* nums2, int n)
{
	int cur1 = 0;
	int cur2 = 0;
	int index = 0;
	int *tmp = (int*)malloc(sizeof(int)*(m+n));
	assert(tmp);
	memset(tmp,0, m + n);
	while (cur1 < m && cur2 < n)
	{		
		if (nums1[cur1] < nums2[cur2])
		{
			tmp[index] = nums1[cur1];
			index++;
			cur1++;
		}
		else if(nums1[cur1] > nums2[cur2])
		{
			tmp[index] = nums2[cur2];
			index++;
			cur2++;
		}
		else if (nums1[cur1] == nums2[cur2])
		{
			tmp[index] = nums1[cur1];
			index++;
			tmp[index] = nums2[cur2];
			index++;
			cur1++;
			cur2++;
		}
	}

	while (cur1 < m)
	{
		tmp[index++] = nums1[cur1++];
	}
	while (cur2 < n)
	{
		tmp[index++] = nums2[cur2++];
	}

	for (int i = 0; i < m+n; i++)
	{
		nums1[i] = tmp[i];
	}

//	memcpy(nums1,tmp, (m+n));
	free(tmp);
}

void Merge(int *nums1,int m,int *nums2,int n)
{
	int count = m + n - 1;
	--m, --n;
	while (n>=0 && m>=0)
	{
		nums1[count--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
	}

	while (m >= 0)
	{
		nums1[count--] = nums1[m--];
	}
}

int main()
{
//	int nums1[] = { 1,2,3,4 };
//	int nums2[] = { 5,6,7,8 };
	int nums1[] = { 1,3,5,7 };
	int nums2[] = { 2,4,6,8 };
	int s1 = sizeof(nums1) / sizeof(nums1[0]);
	int s2 = sizeof(nums2) / sizeof(nums2[0]);

	Merge(nums1,s1,nums2,s2);
	
	for (int i = 0; i < s1+s2 ; i++)
	{
		printf("%d ", nums1[i]);
	}
	return 0;
}

