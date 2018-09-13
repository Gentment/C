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

	//先找到要插入的位置
	while (cur != NULL)
	{
		//先判断是否已存在该元素
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

	//创建结点
	BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	node->key = key;
	node->left = node->right = NULL;

	//插入元素
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

//递归插入写法
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

//查找递归写法
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

//查找非递归写法
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

//删除
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

	//删除del结点
	if (delParent == NULL)
	{
		//左孩子中最大的就是cur的左孩子
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

	//先找到要插入的位置
	while (cur != NULL)
	{
		//先判断是否已存在该元素
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

		parent = cur;		//parent记录找到节点的根节点，通过下面的判定，cur为当前要删除的节点
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
	r = BSTreeInsert(&root, 5); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 3); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 7); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 1); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 4); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 6); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 8); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 0); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 2); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 9); printf("插入%s\n", r ? "成功" : "失败");
	r = BSTreeInsert2(&root, 10); printf("插入%s\n", r ? "成功" : "失败");


	PreOrder(root); printf("\n");
	InOrder(root); printf("\n");

	r = BSTreeFind(root, 3); printf("查找3 %s\n", r ? "成功" : "失败");
	r = BSTreeFind2(root, 3); printf("查找3 %s\n", r ? "成功" : "失败");
	printf("删除3 %s\n", BSTreeRemove(&root, 1) ? "成功" : "失败");
}