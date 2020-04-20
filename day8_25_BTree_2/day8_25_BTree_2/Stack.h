#pragma once

#include <stdio.h>
#include <assert.h>

//typedef int DataType;
struct BTreeNode;
typedef struct BTreeNode * SDataType;

#define MAX_SIZE (100)

typedef struct Stack{
	
	SDataType arr[MAX_SIZE];
	int top;
}Stack;

void StackInit(Stack *stack)
{
	stack->top = 0;
}

void StackDestory(Stack *stack)
{
	stack->top = 0;
}

void StackPush(Stack *stack, SDataType data)
{
	assert(stack->top <MAX_SIZE);
	stack->arr[stack->top++] = data;
}


void StackPop(Stack *stack)
{
	assert(stack->top > 0);
	stack->top--;
}

SDataType StackTop(const Stack *stack)
{
	assert(stack->top > 0);
	return stack->arr[stack->top-1];
}

int stackSize(Stack *stack)
{
	return stack->top;
}

int StackFull(Stack *stack)
{
	return stack->top >= MAX_SIZE;
}

int StackEmpty(Stack *stack)
{
	return stack->top <= 0;
}
