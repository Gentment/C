#pragma once
#include <assert.h>
#include "BTree.h"
/*
常见二叉树的操作
*/

//计算所有结点个数
//方法一
int count;
int GetNodeNum(BTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	GetNodeNum(root->LeftChild);
	GetNodeNum(root->RightChild);
	count++;
	return count;
}

//方法二
int GetNodeNum2(BTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = GetNodeNum2(root->LeftChild);
	int right = GetNodeNum2(root->RightChild);

	return left + right + 1;
}

//查找结点
BTreeNode * FindNode(BTreeNode *root,DataType data)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == data)
	{
		return root;
	}

	BTreeNode *result1 = FindNode(root->LeftChild,data);
	BTreeNode *result2 = FindNode(root->LeftChild, data);

	return result1 == NULL ? result1 : result2;
}

//叶子结点个数
int GetLeafNum(BTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		if (root->LeftChild == NULL && root->RightChild == NULL)
		{
			return 1;
		}
		else
			return GetLeafNum(root->LeftChild) + GetLeafNum(root->RightChild);
	}
}

//第K层有多少个结点
int GetLevelKNum(BTreeNode *root,DataType k)
{
	assert(k>=1);

	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	DataType left = GetLevelKNum(root->LeftChild, k-1);
	DataType right = GetLevelKNum(root->RightChild, k-1);

	return left + right;
}


//高度/深度
#define MAX(a,b) ((a)>(b)?(a):(b))
int GetHight(BTreeNode *root)
{
	if (root ==NULL)
	{
		return 0;
	}

	return MAX(GetHight(root->LeftChild) ,GetHight(root->RightChild)) + 1;
}

//测试
void TestBTree()
{

	int arr[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int pUsedSize;

	BTreeNode *root = CreateBTree(arr, size, &pUsedSize);

	PreOrderTraverse(root);
	printf("\n");
	InOrderTraverse(root);
	printf("\n");
	LastOrderTraverse(root);
	printf("\n");

	printf("结点个数：%d\n",GetNodeNum(root));
	printf("结点个数：%d\n", GetNodeNum2(root));

	printf("查找的结点地址：%p\n",FindNode(root, 3));

	printf("叶子结点个数：%d \n",GetLeafNum(root));

	printf("第3层的结点个数：%d \n",GetLevelKNum(root, 3));

	printf("树的高度：%d\n", GetHight(root));
}

