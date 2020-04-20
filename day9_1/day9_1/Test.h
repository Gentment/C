#pragma once
#include "BTree.h"
#include "Queue.h"
#include "Stack.h"
#include <stdlib.h>

int GetLeveNodeSize(BTreeNode *root,int k)
{
	if (root == NULL)
	{
		return;
	}

	if (k == 1)
	{
		return 1;
	}
	
	DataType left = GetLeveNodeSize(root->LeftChild,k-1);
	
	DataType right = GetLeveNodeSize(root->RightChild,k-1);

	return left + right;
}

int IsCompleteBTree(BTreeNode *root)
{
	Queue queue;
	QueueInit(&queue);
	BTreeNode *cur = root;

	if (root == NULL)
	{
		return 1;
	}
	
	QueuePush(&queue,root);
	while (!QueueEmpty(&queue))
	{
		BTreeNode *top = QueueFront(&queue);
		if (top != NULL)
		{
		QueuePop(&root);
		QueuePush(&queue,cur->LeftChild);
		QueuePush(&queue,cur->RightChild);
		}
		else
		{
			return 0;
		}
	}

	while (!QueueEmpty(&queue))
	{
		BTreeNode *pre = QueueFront(&queue);
		QueuePop(&queue);
		if (pre != NULL)
		{
			return 0;
		}
	}
	return 1;
}

//1. 利用前序和中序构建二叉树; 
BTreeNode * CreateTree(int preOrder[], int inOrder[], int size)
{
	if (size <= 0)
	{
		return NULL;
	}
	int rootValue = preOrder[0];
	int rootIndex = -1;
	for (int i = 0; i < size; i++)
	{	
		if (inOrder[i] == rootValue)
		{
			rootIndex = i;
		}
	}
	assert(rootIndex != -1);

	BTreeNode *root = CreateNode(rootValue);
	root->LeftChild = CreateTree(preOrder + 1,inOrder,rootIndex);
	root->RightChild = CreateTree(preOrder + 1+rootIndex, inOrder+1+rootIndex, size-1-rootIndex);

	return root;
}


//2.递归方式，在二叉树中判断一个结点是否存在
BTreeNode *Find(BTreeNode *root,DataType data)
{
	if (root == NULL)
	{
		return	NULL;
	}
	if (root->data == data)
	{
		return root;
	}
	
	BTreeNode *result1 = Find(root->LeftChild, data);
	BTreeNode *result2 = Find(root->RightChild, data);

	return result1 == NULL ? result1 : result2;
}


//3. 层序遍历，遍历每个结点时，调用 HandleNode 函数 
void HandleNode(BTreeNode *node)
{
	printf("%d ", node->data);
}

void LevelTraverse(BTreeNode *root)
{
	if (root = NULL)
	{
		return;
	}

	Queue queue;
	QueueInit(&queue);
	BTreeNode *pre;

	QueuePush(&queue, root);
	while (!QueueEmpty(&queue))
	{
		pre = QueueFront(&queue);
		QueuePop(&queue);

		if (pre->LeftChild != NULL)
		{
			QueuePush(&queue, pre->LeftChild);
		}

		if (pre->RightChild != NULL)
		{
			QueuePush(&queue, pre->RightChild);
		}

		HandleNode(pre->data);
	}
}

//4. 非递归方式后序遍历二叉树，遍历每个结点时，调用 HandleNode 函数
void HandleNode(BTreeNode *node)
{
	printf("%d ", node->data);
}

void LastTraverse(BTreeNode *root)
{
	Stack stack;
	StackInit(&stack);

	BTreeNode *pre = root;
	BTreeNode *pass = NULL,*cur;

	while (pre != NULL || !QueueEmpty(&stack))
	{
		while (pre != NULL)
		{
			StackPush(&stack, pre->LeftChild);
			pre = pre->LeftChild;
		}

		pass = StackTop(&stack);
		if (pre->RightChild == NULL && pre->RightChild == pass )
		{
			StackPop(&stack);
			HandleNode(pre->data);

			pass = pre;
		}
		else
		{
			cur = pre->RightChild;
		}
	}
}


//5. 利用非递归方式实现搜索二叉树的结点删除 
//找到并删除返回 1，没找到返回 0
void RemoveLeftNULL(BTreeNode *parent, BTreeNode* cur, BTreeNode *root, DataType data)
{
	if (parent == NULL)
	{
		root = parent->RightChild;
	}
	else
	{
		if (data > cur->RightChild)
		{
			parent->LeftChild = cur->RightChild;
		}
		else
		{
			parent->RightChild = cur->RightChild;
		}
	}

	free(cur);
}

void RemoveRightNULL(BTreeNode *parent, BTreeNode* cur, BTreeNode *root, DataType data)
{
	if (parent == NULL)
	{
		root = parent->LeftChild;
	}
	else
	{
		if (data < cur->data)
		{
			parent->LeftChild = cur->LeftChild;
		}
		else
		{
			parent->RightChild = cur->LeftChild;
		}
	}
	free(cur);
}

void RemoveHasLeftAndRight(BTreeNode *cur)
{
	BTreeNode *del = cur->LeftChild;
	BTreeNode *delparent = NULL;

	while (del->RightChild != NULL)
	{
		delparent = del;
		del = del->RightChild;
	}

	cur->data = del->data;
	if (delparent == NULL)
	{
		cur->LeftChild = del->LeftChild;
	}
	else
	{
		delparent->RightChild = del->LeftChild;
	}

	free(del);

}
int Remove(BTreeNode *root, int data)
{
	BTreeNode *cur = root;
	BTreeNode *parent = NULL;

	while (cur != NULL)
	{
		if (data == cur->data)
		{
			if (cur->LeftChild == NULL)
			{
				RemoveLeftNULL(parent,cur,root,data);
			}
			else if(cur->RightChild == NULL)
			{
				RemoveRightNULL(parent,cur,root,data);
			}
			else
			{
				RemoveHasLeftAndRight(cur);
			}
		}

		parent = cur;
		if (data > cur->data)
		{
			cur = cur->RightChild;
		}
		else
		{
			cur = cur->LeftChild;
		}
	}
}