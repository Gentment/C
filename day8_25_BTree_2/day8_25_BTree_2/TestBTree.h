#pragma once

/*
�������ı����ǵݹ顢����������Ƿ�����ȫ������
*/
#include "BTree.h"	
#include "Stack.h"   //�ݹ������stack���
#include "Queue.h"  //���������queue���

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
			//�ж��������Ƿ������
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

//�ж�һ�����ǲ�����ȫ������
int IsCompleteBTree(BTreeNode *root)
{
	Queue queue;
	QueueInit(&queue);
	BTreeNode *pre;
	//����Ͳ������������pre ������NULL
	if (root == NULL)
	{
		//�������ȫ��������ʣ�µĽ��Ӧ��ȫ��NULL
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

	//����ʣ�����Ƿ���NULL
	//�ж�����Ϊ�� 
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

//�������
void LevelTraverse(BTreeNode *root)
{
	Queue queue;
	QueueInit(&queue);
	BTreeNode *pre;

	if (root == NULL)
	{
		return;
	}
	QueuePush(&queue,root); //��Ž���ַ�����ǽ��
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

//����
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

		//top���������Ѿ���������
		top = StackTop(&stack);
		if (top->RightChild == NULL || top->RightChild == last)
		{
			//�ж��������Ƿ������

			BTreeNode *t = top->LeftChild;
			top->LeftChild = top->RightChild;
			top->RightChild = t;

			//��¼����������Ľ��
			last = top;
		}
		else
		{
			cur = top->RightChild;
		}
	}

} 

//��ǰ���������������ؽ�������(ǰ����������1,2,3,4,5,6 ;������������4, 2, 5, 1, 6, 3)
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
//����
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

	IsCompleteBTree(root) == 1 ? printf("����ȫ������\n"): printf("����ȫ������\n");

	Mirror(root);
#endif // 0
	int preOrder[] = { 1,2,3,4,5,6,7 };
	int inOrder[] = { 2,1,4,6,7,5,3 };
	int size = sizeof(preOrder) / sizeof(int);
	BTreeNode * root = CreateTree(preOrder,inOrder,size);
	printf("123");
}