#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int QDataType;

typedef struct QNode
{
	QDataType data;
	struct QNode *next;
} QNode;

typedef struct Queue
{
	QNode *front;
	QNode *rear;
}Queue;

void QueueInit(Queue *pQueue)
{
	pQueue->front = pQueue->rear = NULL;
}

void QueueDestroy(Queue *pQueue)
{
	QNode *cur,*next;
	for (cur = pQueue->front;cur != NULL;cur = next)
	{
		next = cur->next;
		free(cur);
	}
	pQueue->front = pQueue->rear = NULL;
}

static QNode * CreateNode(QDataType data)
{
	QNode * node =  (QNode *)malloc(sizeof(QNode));

	node->data = data;
	node->next = NULL;
	return node;
}

void QueuePush(Queue *pQueue,QDataType data)
{
	QNode *newNode = CreateNode(data);
	if (pQueue->front == NULL)
	{
		pQueue->front = pQueue->rear = newNode;
		return;
	}

	pQueue->rear->next = newNode;
	pQueue->rear = newNode;
}

void QueuePop(Queue *pQueue)
{
	Queue *del = pQueue->front;
	assert(pQueue);
	assert(pQueue->front != NULL);

	pQueue->front = pQueue->front->next;
	free(del);

	if (pQueue->front == NULL)
	{
		pQueue->rear = NULL;
	}
}


QDataType QueueFront(Queue *pQueue)
{
	assert(pQueue != NULL);
	assert(pQueue->front != NULL);
	return pQueue->front->data;
}

QDataType QueueEmpty(const Queue *pQueue)
{
	return pQueue->front == NULL;
}

QDataType QueueSize(const Queue *pQueue)
{
	int size = 0;
	QNode *cur;
	for (cur = pQueue->front;cur != NULL;cur = cur->next)
	{
		size++;
	}
	return size;
}

void PrintQueue(Queue *pQueue)
{
	QNode *cur = pQueue->front;
	while (cur != NULL)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}

	printf("\n");
}



void TestQueue()
{
	Queue queue;
	QueueInit(&queue);

	QueuePush(&queue,1);
	QueuePush(&queue,2);
	QueuePush(&queue,3);
	QueuePush(&queue,4);
	
	printf("%d",QueueFront(&queue));
	//printf("%d",QueueSize(&queue));
	//PrintQueue(&queue);
}