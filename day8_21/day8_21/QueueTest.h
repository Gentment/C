#pragma once

#include "Stack.h"
/*
*两个栈实现一个队列
*/


typedef struct Queues
{
	Stack stack1;
	Stack stack2;
}Queues;


void QueuesInit(Queues *pQs)
{
	StackInit(&(pQs->stack1));
	StackInit(&(pQs->stack2));
}

void QueuesPush(Queues *pQs,DataType data)
{
	StackPush(&(pQs->stack1),data);
}

void QueuesPop(Queues *pQs)
{
	if (StackEmpty(&(pQs->stack2)))
	{
		while (!StackEmpty(&(pQs->stack1)))
		{
			DataType data = StackTop(&(pQs->stack1));
			StackPush(&(pQs->stack2),data);
			StackPop(&(pQs->stack1));
		}
	}
	StackPop(&(pQs->stack2));
}

DataType QueuesFront(Queues *pQs)
{
	if (StackEmpty(&(pQs->stack2)))
	{
		while ( !StackEmpty(&(pQs->stack1)))
		{
			DataType data = StackTop(&(pQs->stack1));
			StackPush(&(pQs->stack2),data);
			StackPop(&(pQs->stack1));
		}
	}
	return StackTop(&(pQs->stack2));
}

void TestQueues()
{
	int i = 0;
	Queues queues;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	QueuesInit(&queues);
	for (i=0;i<9;i++)
	{
		QueuesPush(&queues,arr[i]);
		printf("%d ",QueuesFront(&queues));
		QueuesPop(&queues);
	}

}