#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef int DataType;

typedef struct Link_C{
	int data;
	struct Link_C *next;
    struct Link_C *random;	
}Link_C;

static Link_C * linkCreateNode(DataType data)
{
	Link_C *node = (Link_C *)malloc(sizeof(Link_C));
	node->data = data;
	node->next = NULL;
	node->random = NULL;

	return node;
}

Link_C * LinkCopy(Link_C *head)
{
	//第一步，复制结点
	Link_C *cur = head;
	Link_C *newNode;
	Link_C *newLink;
	Link_C *pre;
	while (cur != NULL)
	{
		newNode = linkCreateNode(cur->data);
		newNode->next = cur->next;
		cur->next = newNode;

		cur = cur->next->next;
	}

	//第二步，复制random

	cur = head;
	while (cur != NULL)
	{	
		if (cur->random != NULL)
		{
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;
	}
	
	
	//第三步，新旧链表拆开
	cur = head;
	newLink = cur->next;
	while ( cur != NULL)
	{	
		pre = cur->next;

		cur->next = pre->next;
		if (cur->next != NULL)
		{
			pre->next = cur->next->next;
		}
		else
		{
			pre->next = NULL;
		}

		cur = cur->next;
		
	}

	return newLink;
}
void Print(Link_C *head)
{
	Link_C *node = head;
	while (node != NULL)
	{
		printf("[%d  random(%p)->%d ] \n",
			node->data,
			node->random,
			node->random ? node->random->data:0);

		node = node->next;
	}

	printf("\n");

}
void TestCopy()
{
	Link_C *n1 = linkCreateNode(1);
	Link_C *n2 = linkCreateNode(2);
	Link_C *n3 = linkCreateNode(3);
	Link_C *n4 = linkCreateNode(4);
	Link_C *n5 = linkCreateNode(5);
	Link_C *n6 = linkCreateNode(6);

	Link_C *result;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	
	n1->random = n3;
	n2->random = n6;
	n3->random = n3;
	n4->random = n4;
	n5->random = n2;

	Print(n1);

	printf("\n----------------\n");
	result = LinkCopy(n1);
	Print(result);
}