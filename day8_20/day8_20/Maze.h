#pragma once

#include <assert.h>
#include <string.h>
#include <stdio.h>

#define MAX_SIZE (100)
#define ROWS  (6)
#define COLS  (6)
typedef struct{
	int x;
	int y;
}Postion;

typedef Postion StackDataType;

typedef struct Stack
{
	StackDataType arr[MAX_SIZE];
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

void StackPush(Stack *stack,StackDataType data)
{
	assert(stack->top <MAX_SIZE);
	stack->arr[stack->top++] = data;
}


void StackPop(Stack *stack)
{
	assert(stack->top > 0);
	stack->top--;
}

StackDataType StackTop(const Stack *stack)
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

void StackCopy(Stack *min,Stack *path)
{
	memcpy(min->arr,path->arr,sizeof(StackDataType)*path->top);
	min->top = path->top;
}


//int gMaze[ROWS][COLS] = 
//{
//	{ 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 1, 1, 0 },
//	{ 0, 0, 1, 0, 1, 1 },
//	{ 0, 0, 1, 0, 0, 0 }
//};

//int gMaze[ROWS][COLS] = {
//	{ 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 1, 1, 1, 1 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 0, 0, 0 },
//	{ 0, 0, 1, 1, 1, 1 },
//	{ 0, 0, 1, 0, 0, 0 }
//};

int gMaze[ROWS][COLS] = {
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 }
};

//入口点
Postion gEntry = {5,2};

//判断是否走到出口，最后一列都是出口
int IsExit(Postion pos)
{
	if (pos.y == COLS-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int CanPass(Postion pos)
{
	if (pos.x >= ROWS)
	{
		return 0;
	}
	if (pos.y >= COLS)
	{
		return 0;
	}

	return gMaze[pos.x][pos.y] == 1;
}


void RunMaze()
{
	Stack stack;
	Postion at;
	Postion next;
	StackInit(&stack);
	
	at.x = gEntry.x;
	at.y = gEntry.y;

	while (1)
	{
		gMaze[at.x][at.y] = 2;

		StackPush(&stack,at);

		if (IsExit(at))
		{
			printf("(x,y)=(%d,%d)",at.x,at.y);
			return;
		}

		next.x = at.x;
		next.y = at.y-1;
		if (CanPass(next))
		{
			at.x = next.x;
			at.y = next.y;
			continue;
		}

		next.x = at.x-1;
		next.y = at.y;
		if (CanPass(next))
		{
			at.x = next.x;
			at.y = next.y;
			continue;
		}

		next.x = at.x;
		next.y = at.y+1;
		if (CanPass(next))
		{
			at.x = next.x;
			at.y = next.y;
			continue;
		}

		next.x = at.x+1;
		next.y = at.y;
		if (CanPass(next))
		{
			at.x = next.x;
			at.y = next.y;
			continue;
		}

		StackPop(&stack);
		if (StackEmpty(&stack))
		{
			printf("没有出口\n");
			return;
		}

		at = StackTop(&stack);
		StackPop(&stack);

	}
}


Stack path;
Stack min;

void PrintPath(Stack *stack)
{
	Postion at;
	int i = 0;
	for (i=0;i<stack->top;i++)
	{
		at = stack->arr[i];
		printf("[x,y]=[%d,%d]\n",at.x,at.y);
	}

}


void PrintMaze()
{
	int i , j;
	for (i=0;i<ROWS;i++)
	{
		for (j=0;j<COLS;j++)
		{
			if (gMaze[i][j] == 0)
			{
				printf("█");
			}
			else if (gMaze[i][j] == 1)
			{
				printf("  ");
			}
			else if (gMaze[i][j] == 2)
			{
				printf("* ");
			}
		}
		printf("\n");
	}
	printf("\n");
}


//递归写法
void RunMazeRec(Postion at)
{
	Postion next;
	StackPush(&path,at);

	//一进来标记走过了
	gMaze[at.x][at.y] = 2;
	//PrintMaze();

	if (IsExit(at))
	{
		if (StackEmpty(&min) || stackSize(&path) < StackEmpty(&min))
		{
			StackCopy(&min,&path);
		}
		
		PrintPath(&path);
		printf("===================\n");

		//重新设置为1
		gMaze[at.x][at.y] = 1;

		StackPop(&path);
		return; //会发生回溯
	}

	next.x = at.x;
	next.y = at.y-1;
	if (CanPass(next))
	{
		RunMazeRec(next);
	//	PrintMaze();
	}

	next.x = at.x-1;
	next.y = at.y;
	if (CanPass(next))
	{
		RunMazeRec(next);
	//	PrintMaze();
	}

	next.x = at.x;
	next.y = at.y+1;
	if (CanPass(next))
	{
		RunMazeRec(next);
		//PrintMaze();
	}

	next.x = at.x+1;
	next.y = at.y;
	if (CanPass(next))
	{
		RunMazeRec(next);
		//PrintMaze();
	}

	//重置为1
	//PrintMaze();
	gMaze[at.x][at.y] = 1;
	StackPop(&path);
	return;
}


void TestRunMaze()
{
//	RunMaze();
	StackInit(&path);
	StackInit(&min);
	RunMazeRec(gEntry);
	PrintMaze();
	printf("最短路径长度是 %d \n",stackSize(&min));
}