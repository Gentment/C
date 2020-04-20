#pragma once
#include<stdlib.h>
#include<stdio.h>

typedef int DataType;

typedef struct BSTreeNode
{
	DataType key;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
}BSTreeNode;


int BSTreeInsert(BSTreeNode **root,DataType key)
{
	BSTreeNode *cur = *root;
	BSTreeNode *parent = NULL;

	//���ҵ�Ҫ�����λ��
	while (cur != NULL)
	{
		//���ж��Ƿ��Ѵ��ڸ�Ԫ��
		if (key == cur->key)
		{
			return 0;
		}
		
		parent = cur;
		if (key>cur->key)
		{
			cur = cur->right;
		}
		else
		{
			cur = cur->left;
		}
	}

	//�������
	BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	node->key = key;
	node->left = node->right = NULL;

	//����Ԫ��
	if (parent == NULL)
	{
		*root = node;
		return 1;
	}

	if (key<parent->key)
	{
		parent->left = node;
	}
	else
	{
		parent->right = node;
	}
	return 1;
}

//�ݹ����д��
int BSTreeInsert2(BSTreeNode **root, DataType key)
{
	if (*root == NULL)
	{
		BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
		node->key = key;
		node->left = node->right = NULL;
		*root = node;
		return 1;
	}

	if ((*root)->key == key)
	{
		return 0;
	}
	if (key >(*root)->key)
	{
		return BSTreeInsert2(&(*root)->right,key);
	}
	else
	{
		return BSTreeInsert2(&(*root)->right, key);
	}
}

//���ҵݹ�д��
int BSTreeFind(const BSTreeNode *root, DataType key)
{
	if (root == NULL)
	{
		return 0;
	}

	if (key == root->key)
	{
		return 1;
	}else	if (root->key < key)
	{
		BSTreeFind(root->right,key);
	}
	else
	{
		BSTreeFind(root->left, key);
	}

	return 0;
}

//���ҷǵݹ�д��
int BSTreeFind2(const BSTreeNode *root,DataType key)
{
	BSTreeNode *cur = (BSTreeNode *)root;
	while (cur != NULL)
	{
		if (cur->key == key)
		{
			return 1;
		}
		else if (cur->key > key)
		{
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}
	return 0;

}

//ɾ��
void RemoveLeftNULL(BSTreeNode *parent,BSTreeNode *cur, BSTreeNode **root,DataType key)
{
	if (parent == NULL)
	{
		*root = cur->right;
	}
	else
	{
		if (key < parent->key)
		{
			parent->left = cur->right;
		}
		else
		{
			parent->right = cur->right;
		}
	}
	free(cur);
}

void RemoveRightNULL(BSTreeNode *parent, BSTreeNode *cur, BSTreeNode **root, DataType key)
{
	if (parent == NULL)
	{
		*root = cur->left;
	}
	else
	{
		if (key < parent->key)
		{
			parent->left = cur->left;
		}
		else
		{
			parent->right = cur->left;
		}
	}
	free(cur);
}

static void RemoveHasLeftAndRight(BSTreeNode *cur)
{
	BSTreeNode *del = cur->left;
	BSTreeNode *delParent = NULL;
	while (del->right != NULL)
	{
		delParent = del;
		del = del->right;
	}
	cur->key = del->key;

	//ɾ��del���
	if (delParent == NULL)
	{
		//���������ľ���cur������
		cur->left = del->left;
	}
	else
	{
		delParent->right = del->left;
	}
	free(del);
}
int BSTreeRemove(BSTreeNode **root,DataType key)
{
	BSTreeNode *cur = *root;
	BSTreeNode *parent = NULL;

	//���ҵ�Ҫ�����λ��
	while (cur != NULL)
	{
		//���ж��Ƿ��Ѵ��ڸ�Ԫ��
		if (key == cur->key)
		{
			if (cur->left == NULL)
			{
				RemoveLeftNULL(parent,cur,root,key);
			}
			else if (cur->right == NULL)
			{
				RemoveRightNULL(parent,cur,root,key);
			}
			else
			{
				RemoveHasLeftAndRight(cur);
			}
		}

		parent = cur;		//parent��¼�ҵ��ڵ�ĸ��ڵ㣬ͨ��������ж���curΪ��ǰҪɾ���Ľڵ�
		if (key > cur->key)
		{
			cur = cur->right;
		}
		else
		{
			cur = cur->left;
		}
	}
	return 1;

}
void PreOrder(BSTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ",root->key);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BSTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->left);
	printf("%d ", root->key);
	InOrder(root->right);
}
void BSTreeTest()
{
	int r;
	BSTreeNode *root = NULL;
	r = BSTreeInsert(&root, 5); printf("����%s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 3); printf("����%s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 7); printf("����%s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 1); printf("����%s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 4); printf("����%s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 6); printf("����%s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 8); printf("����%s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 0); printf("����%s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 2); printf("����%s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 9); printf("����%s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert2(&root, 10); printf("����%s\n", r ? "�ɹ�" : "ʧ��");


	PreOrder(root); printf("\n");
	InOrder(root); printf("\n");

	r = BSTreeFind(root, 3); printf("����3 %s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeFind2(root, 3); printf("����3 %s\n", r ? "�ɹ�" : "ʧ��");
	printf("ɾ��3 %s\n", BSTreeRemove(&root, 1) ? "�ɹ�" : "ʧ��");
}