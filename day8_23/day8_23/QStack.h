#pragma once

#include "Queue.h"
#include <stdio.h>
/*
面试-3
利用两个队列实现一个栈

Push：往非空队列里插入（如果两个队列都是空，选第一个插入）

Pop：从非空队列中 move  size - 1 个元素到 空队列中，pop 剩下的一个

Top: 从非空队列中 move  size - 1 个元素到 空队列中，返回剩下的一个的值，
	 把剩下的一个也放入另一个队列中
*/

typedef struct QStack
{
	Queue queue1;
	Queue queue2;
}QStack;



void QStackInit(QStack *pQS)
{
	QueueInit(&(pQS->queue1));
	QueueInit(&(pQS->queue2));
}

void QStackDestory(QStack *pQS)
{
	QueueDestroy(&(pQS->queue1));
	QueueDestroy(&(pQS->queue2));
}

void QStackPush(QStack *pQS,QDataType data)
{
	Queue *pNotEmpty = &(pQS->queue2);

	if (QueueEmpty(pNotEmpty))		    // 如果队列二为空，则不为空的就假设为队列一，就将队列一中的插入队列二
	{
		pNotEmpty = &(pQS->queue1);		//如果队列二不为空，则直接将队列一中的插入队列二
	}
	QueuePush(pNotEmpty,data);
}

void QStackPop(QStack *pQS)
{
	Queue *pEmpty = &(pQS->queue1);
	Queue *pNotEmpty = &(pQS->queue2);
	if (QueueEmpty(pNotEmpty))		 //假设队列二是空，如果队列二空，则不空的就是队列一
	{
		pEmpty = &(pQS->queue2);
		pNotEmpty = &(pQS->queue1);
	}
	
	while (QueueSize(pNotEmpty) > 1)
	{
		QDataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty,data);
	}

	QueuePop(pNotEmpty);
}

QDataType QStackTop(QStack *pQS)
{
	QDataType data;
	QDataType r;
	Queue *pEmpty = &(pQS->queue1);
	Queue *pNotEmpty = &(pQS->queue2);
	if (QueueEmpty(pNotEmpty))		 //假设队列二是空，如果队列二空，则不空的就是队列一
	{
		pEmpty = &(pQS->queue2);
		pNotEmpty = &(pQS->queue1);
	}

	while (QueueSize(pNotEmpty) > 1)
	{
		data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty,data);
	}

	r = QueueFront(pNotEmpty);
	QueuePop(pNotEmpty);
	QueuePush(pEmpty,r);

	return r;
}


void TestQStack()
{	
	int i = 0;
	QStack qstack;
	QStackInit(&qstack);
	
	for (i=0;i<9;i++)
	{
		QStackPush(&qstack,i);
		
		printf("压入第%d ,压入 %d\n",i+1,QStackTop(&qstack));
		printf("Top = %d ",QStackTop(&qstack));
		//QStackPop(&qstack);
	}

	
}