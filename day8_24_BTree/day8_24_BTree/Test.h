#pragma ocne

/*
¿ÎÌÃÁ·Ï°»Ø¹Ë
*/
#include "BTree.h"

#define MAX(a,b) ((a)>(b)?(a):(b))
int GetHight(BTreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}

	return MAX(GetHight(root->LeftChild ),GetHight(root->RightChild ));

}


BTreeNode *Find(BTreeNode *root,DataType data)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == data)
	{
		return root;
	}
	
	return Find(root->LeftChild, data) == NULL ? Find(root->LeftChild,data) : Find(root->RightChild,data);

}