#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
/*
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


typedef struct ListNode {
	int val;
	struct ListNode *next;
} ListNode;

static ListNode * CreateNode(int data)
{
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->val = data;
	newNode->next = NULL;

	return newNode;
}

void ListInsert(ListNode **list,int data)
{
	//if (*list == NULL)
	//{

	//}
	ListNode *newNode = CreateNode(data);

	newNode->next = *list;
	*list = newNode;
}

ListNode* addTwoNumbers(  ListNode *list1,const ListNode *list2)
{
	int num1 = 0;
	int num2 = 0;
	ListNode* l1 = list1;
	ListNode* l2 = list2;
	while (l1 != NULL)
	{
		num1 = num1*10+l1->val;
		l1 = l1->next;
	}

	printf("%d\n",num1); // 321
	
	while (l2 != NULL)
	{
		num2 = num2*10+l2->val;
		l2 = l2->next;
	}
	printf("%d\n", num2);  // 654


	int sum = num1 + num2;  // 975

	ListNode *newNode = NULL;

	while (sum>0)
	{
		ListInsert(&newNode, sum %10);
		sum = sum / 10;
	}
	/*int lg = 1;
	int temp = sum;
	while (temp > 10) {
		temp = temp / 10;
		lg *= 10;
	}
	while (sum > 0) {
		ListInsert(&newNode, sum/lg);
		sum = sum - (sum / lg)*lg;
		lg = lg / 10;
	}*/
	/*while (sum>9)
	{
		ListInsert(&newNode,sum);
		sum = sum % 10;
	}
	ListInsert(&newNode,sum);*/
	return newNode;
}

void Print(int sum)
{
	if (sum < 9)
	{	
		printf("%d ", sum);
	}
	else
	{
		Print(sum/10);	
		printf("%d ",sum%10);
	}
}

void Prints(int sum)
{
	int lg = 1;
	int temp = sum;
	while (temp > 10) {
		temp = temp / 10;
		lg *= 10;
	}
	while (sum > 0) {
		printf("%d ", sum / lg);
		sum = sum - (sum / lg)*lg;
		lg = lg / 10;
	}

}

int main()
{
	ListNode *list1 = NULL;
	ListNode *list2 = NULL;

	ListInsert(&list1,1);
	ListInsert(&list1,2);
	ListInsert(&list1,3);

	ListInsert(&list2,4);
	ListInsert(&list2,5);
	ListInsert(&list2,6);


//	Print(132);
//	Prints(412897351);
	ListNode * ret = addTwoNumbers(list1,list2);

}




/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
	 注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
*/

/*
int maxProfit(int* prices, int pricesSize) {
	int i = 0;
	int j = 0;
	int s = 0;
	int max = 0;
	for (i = 0; i < pricesSize; i++)
	{
		for (j =i+1; j < pricesSize; j++)		{
			s = prices[j] - prices[i];
			max = (s > max ? s : max);
		}
	}
	return max;
}

int main()
{
	int arr[] = { 7,1,5,3,6,4,9 };
	int ret = maxProfit(arr, 7);
	printf("%d\n", ret);
	return  0;
}
*/