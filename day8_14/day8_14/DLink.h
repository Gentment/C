#pragma once

#include <stdlib.h>
#include <stdio.h>


typedef int DataType;

typedef struct DLink 
{
	DataType data;
	struct DLink *next;
	struct DLink *pre;
}DLink;


void DLinkInit(DLink **head)
{
	DLink *node;
	assert(head != NULL);
	node = (DLink *)malloc(sizeof(DLink));
	node->next = node;
	node->pre = node;
	*head = node;
}

//保留头结点
void DLinkClear(DLink *head)
{
	DLink *cur = head->next;
	DLink *next;

	while (cur != NULL)
	{
		next = cur->next;
		free(cur);
	}
	head->next = head;
	head->pre = head;
}

void DLinkDestory(DLink **head)
{
	DLinkClear(*head);
	free(*head);
	*head = NULL;
}

//插入结点
void DLinkInsert(DLink *head,DLink *pos,DataType data)
{
	DLink *node;
	node = (DLink *)malloc(sizeof(DLink));

	node->data = data;

	node->pre = pos->pre;
	pos->pre->next = node;

	node->next = pos;
	pos->pre = node;

}

//头插
void DLinkPushFront(DLink *head,DataType data)
{
	DLinkInsert(head,head->next,data);
}

//尾插
void DLinkPushBack(DLink *head, DataType data)
{
	DLinkInsert(head,head,data);
}

//删除
void DLinkDelete(DLink *head,DLink *pos)
{
	DLink *del = head;
	assert(pos != head);
	pos->pre->next = pos->next;
	pos->next->pre = pos->pre;

	free(pos);
}

//头删
void DLinkPopFront(DLink *head)
{	
	DLinkDelete(head,head->next);
}
//尾删
void DLinkPopBack(DLink *head)
{
	DLinkDelete(head,head->pre);
}

void DLinkPrint(DLink *head)
{
	DLink *node = head;

	node = node->next;
	//while (node->next != head)
	//{
	//	//printf("[(%p)-->%d -->(%p)] ",node->pre != NULL ? node->pre:0,node->data,node->next);
	//	printf("[(%p)-->%d -->(%p)] ",node,node->data,node->next);

	//	node = node->next;
	//}

	do 
	{
		//printf("[(%p)--->(%p)-->%d -->(%p)] ",node,node->pre,node->data,node->next);//包含头结点
		printf("[(%p)-->%d -->(%p)]\n",node,node->data,node->next);
		node = node->next;
	} while (node->next != head);
	printf("[(%p)-->%d -->(%p)] ",node,node->data,node->next->next); //打印最后一个结点
	printf("\n");
}

void TestDLinkInsert()
{
	DLink *link;
	DLinkInit(&link);	

	DLinkPushBack(link,1);
	DLinkPushBack(link,2);
	DLinkPushBack(link,3);
	DLinkPushBack(link,4);
	DLinkPushBack(link,5);

	//printf("1234\n");
	DLinkPrint(link);

	DLinkPopBack(link);
	
	printf("尾删后：\n");
	DLinkPrint(link);
}