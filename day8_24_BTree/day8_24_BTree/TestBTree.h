#pragma once
#include <assert.h>
#include "BTree.h"
/*
�����������Ĳ���
*/

//�������н�����
//����һ
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

//������
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

//���ҽ��
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

//Ҷ�ӽ�����
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

//��K���ж��ٸ����
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


//�߶�/���
#define MAX(a,b) ((a)>(b)?(a):(b))
int GetHight(BTreeNode *root)
{
	if (root ==NULL)
	{
		return 0;
	}

	return MAX(GetHight(root->LeftChild) ,GetHight(root->RightChild)) + 1;
}

//����
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

	printf("��������%d\n",GetNodeNum(root));
	printf("��������%d\n", GetNodeNum2(root));

	printf("���ҵĽ���ַ��%p\n",FindNode(root, 3));

	printf("Ҷ�ӽ�������%d \n",GetLeafNum(root));

	printf("��3��Ľ�������%d \n",GetLevelKNum(root, 3));

	printf("���ĸ߶ȣ�%d\n", GetHight(root));
}

