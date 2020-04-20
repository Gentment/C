#pragma once
#include "Stack.h"
#include <stdio.h>

typedef struct
{
	Stack MinStack;
	Stack NormalStack;
}StackMin;

void MinStackInit(StackMin *pMs)
{
	StackInit(&(pMs->MinStack));
	StackInit(&(pMs->NormalStack));
}

void MinStackPush(StackMin * pMs,DataType data)
{
	StackPush(&(pMs->NormalStack),data);
	if (StackEmpty(&(pMs->MinStack)))
	{
		StackPush(&(pMs->MinStack),data);
		return ;
	}

	if (data < StackTop(&(pMs->MinStack)))
	{
		StackPush(&(pMs->MinStack),data);
	}

#if 0
	
	Stack *pMin = &(pMs->MinStack);

	DataType min = 0;

	StackPush(&(pMs->NormalStack),data);

	if (StackEmpty(pMin))
	{
		StackPush(pMin,data);
		return;
	}
	
	min = StackTop(pMin);
	if (data < min)
	{
		StackPush(pMin,data);
	}
	else
	{
		StackPush(pMin,min);
	}
#endif

}

void MinStackPop(StackMin * pMs)
{
	if (StackTop(&(pMs->MinStack)) == StackTop(&(pMs->NormalStack)))
	{
		StackPop(&(pMs->MinStack));
	}
	StackPop(&(pMs->NormalStack));

#if 0
	StackPop(&(pMs->MinStack));
	StackPop(&(pMs->NormalStack));
#endif
}

DataType MinStackTop(StackMin *pMs)
{
	return StackTop(&(pMs->NormalStack));
}
DataType MinStackMin(StackMin *pMs)
{
	return StackTop(&(pMs->MinStack));
}

void TestMinStack()
{
	StackMin stack;
	int i = 0;
	int num[] = {5,4,6,3,2,8,9,7,1};
	MinStackInit(&stack);

#if 1

	for (i=0;i<9;i++)
	{
		MinStackPush(&stack,num[i]);
		printf("Top = %d , Min = %d \n",MinStackTop(&stack),MinStackMin(&stack));
	}
#endif

}