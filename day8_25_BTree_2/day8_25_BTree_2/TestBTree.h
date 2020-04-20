#pragma once

/*
二叉树的遍历非递归、层序遍历、是否是完全二叉树
*/
#include "BTree.h"	
#include "Stack.h"   //递归遍历用stack完成
#include "Queue.h"  //层序遍历用queue完成

void preOrderTraverse(BTreeNode *root)
{
	BTreeNode *cur = root;
	BTreeNode *top = NULL;
	Stack stack;
	StackInit(&stack);
	while (cur != NULL || !StackEmpty(&stack))
	{
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			printf("%d ", cur->data);
			cur = cur->LeftChild;
		}

		top = StackTop(&stack);
		StackPop(&stack);
		cur = top->RightChild;
	}
}

void inOrderTraverse(BTreeNode *root)
{
	BTreeNode *cur = root;
	BTreeNode *top;
	Stack stack;
	StackInit(&stack);
	while (cur != NULL || !StackEmpty(&stack))
	{
		while (cur!=NULL)
		{
			StackPush(&stack, cur);
			cur = cur->LeftChild;
		}

		top = StackTop(&stack);
		printf("%d ",top->data);
		StackPop(&stack);
		cur = top->RightChild;
	}
}

void lastOrderTraverse(BTreeNode *root)
{
	BTreeNode *cur = root;
	BTreeNode *top,*last = NULL;
	Stack stack;
	StackInit(&stack);
	while (cur != NULL || !StackEmpty(&stack))
	{
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->LeftChild;
		}

		top = StackTop(&stack);
		if (top->RightChild == NULL || top->RightChild == last)
		{
			//判断右子树是否遍历过
			StackPop(&stack);
			printf("%d ", top->data);
			last = top;
		}
		else
		{
			cur = top->RightChild;
		}
	}
}

//判断一棵树是不是完全二叉树
int IsCompleteBTree(BTreeNode *root)
{
	Queue queue;
	QueueInit(&queue);
	BTreeNode *pre;
	//这里和层序遍历的区别：pre 可能是NULL
	if (root == NULL)
	{
		//如果是完全二叉树，剩下的结点应该全是NULL
		return 1;
	}

	QueuePush(&queue, root);
	while (!QueueEmpty(&queue))
	{
		pre = QueueFront(&queue);
		QueuePop(&queue);
		if (pre == NULL)
		{
			break;
		}
		QueuePush(&queue, pre->LeftChild);
		QueuePush(&queue, pre->RightChild);
	}

	//队列剩余结点是否都是NULL
	//判定队列为空 
	while (!QueueEmpty(&queue))
	{
		pre = QueueFront(&queue);
		QueuePop(&queue);
		if (pre != NULL)
		{
			return 0;
		}
	}
	return 1;
}

//层序遍历
void LevelTraverse(BTreeNode *root)
{
	Queue queue;
	QueueInit(&queue);
	BTreeNode *pre;

	if (root == NULL)
	{
		return;
	}
	QueuePush(&queue,root); //存放结点地址，不是结点
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

		printf("%d ", pre->data);
	}
}

//求镜像
void Mirror(BTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	Mirror(root->LeftChild);
	Mirror(root->RightChild);

	BTreeNode *t = root->LeftChild;
	root->LeftChild = root->RightChild;
	root->RightChild = t;
}


void Mirror2(BTreeNode *root)
{
	BTreeNode *cur = root;
	BTreeNode *top, *last = NULL;
	Stack stack;
	StackInit(&stack);
	while (cur != NULL || !StackEmpty(&stack))
	{
		while (cur != NULL)
		{
			StackPush(&stack, cur);
			cur = cur->LeftChild;
		}

		//top的左子树已经遍历过了
		top = StackTop(&stack);
		if (top->RightChild == NULL || top->RightChild == last)
		{
			//判断右子树是否遍历过

			BTreeNode *t = top->LeftChild;
			top->LeftChild = top->RightChild;
			top->RightChild = t;

			//记录这个被遍历的结点
			last = top;
		}
		else
		{
			cur = top->RightChild;
		}
	}

} 

//有前序遍历和中序遍历重建二叉树(前序遍历结果：1,2,3,4,5,6 ;中序遍历结果：4, 2, 5, 1, 6, 3)
BTreeNode* CreateTree(int preOrder[],int inOrder[],int size)
{
	if (size <= 0)
	{
		return NULL;
	}

	int rootValue = preOrder[0];

	int rootIndexInOrder = -1;
	for (int i = 0; i < size; i++)
	{
		if (inOrder[i] == rootValue)
		{
			rootIndexInOrder = i;
		}
	}

	assert(rootIndexInOrder != -1);

	BTreeNode *root = CreateNode(rootValue);
	root->LeftChild = CreateTree(preOrder+1,inOrder,rootIndexInOrder);
	root->RightChild = CreateTree(preOrder + 1 + rootIndexInOrder, 
		inOrder + 1 + rootIndexInOrder, size - 1 - rootIndexInOrder);

	return root;
}
//测试
void TestBTree()
{
#if 0

	int arr[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int pUsedSize;

	BTreeNode *root = CreateBTree(arr, size, &pUsedSize);

	preOrderTraverse(root);
	printf("\n");
	inOrderTraverse(root);
	printf("\n");
	lastOrderTraverse(root);
	printf("\n");

	LevelTraverse(root);
	printf("\n");

	IsCompleteBTree(root) == 1 ? printf("是完全二叉树\n"): printf("是完全二叉树\n");

	Mirror(root);
#endif // 0
	int preOrder[] = { 1,2,3,4,5,6,7 };
	int inOrder[] = { 2,1,4,6,7,5,3 };
	int size = sizeof(preOrder) / sizeof(int);
	BTreeNode * root = CreateTree(preOrder,inOrder,size);
	printf("123");
}