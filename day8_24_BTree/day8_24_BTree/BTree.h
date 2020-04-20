#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef int DataType;

typedef struct BTreeNode
{
	DataType data;
	struct BTreeNode *LeftChild;
	struct BTreeNode *RightChild;
} BTreeNode;

void BTreeInit(BTreeNode *root)
{
	root->data = 0;
	root = NULL;
}

BTreeNode * CreateNode(DataType data)
{
	BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
	node->data = data;
	node->LeftChild = node->RightChild = NULL;

	return node;
}

BTreeNode * CreateBTree( int arr[],int size,int *pUsedSize)
{
	if (size <= 0)
	{
		*pUsedSize = 0;
		return NULL;
	}
	int leftUse, rightUse;
	int data = arr[0];
	if (data == -1)
	{
		*pUsedSize = 1;
		return NULL;
	}

	BTreeNode *root = CreateNode(data);

	root->LeftChild = CreateBTree(arr + 1,size - 1,&leftUse);
	root->RightChild = CreateBTree(arr + 1+leftUse, size - leftUse - 1,&rightUse);

	*pUsedSize = leftUse + rightUse + 1;

	return root;
}
/*
#if 0
//先序遍历
void PreOrderTraverse(BTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%d ",root->data);
	PreOrderTraverse(root->LeftChild);
	PreOrderTraverse(root->RightChild);
}

//中序遍历
void InOrderTraverse(BTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	InOrderTraverse(root->LeftChild);
	printf("%d ", root->data);
	InOrderTraverse(root->RightChild);
}

//后序遍历
void  LastOrderTraverse(BTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	LastOrderTraverse(root->LeftChild);
	LastOrderTraverse(root->RightChild);
	printf("%d ", root->data);
}


#endif
*/