#pragma once

#include "Stack.h"
#include <string.h>

int Valid(char in[], char out[],int size)
{
	int ii = 0;
	int io = 0;
	Stack stack;
	StackInit(&stack);

	while (ii < size)
	{
		if (in[ii] == out[io])
		{
			ii++;
			io++;
		}
		else if (!StackEmpty(&stack) && StackTop(&stack) == out[io])
		{
			StackPop(&stack);
			io++;
		}
		else 
		{
			StackPush(&stack,in[ii]);
			ii++;
		}
	}

	while (!StackEmpty(&stack))
	{
		/*
		if (StackTop(&stack) != out[io])
		{
			return 0;
		}		
		StackPop(&stack);
		io++;
		*/

		if (StackTop(&stack) == out[io])
		{
			StackPop(&stack);
			io++;
		}	
		else
		return 0;
	}
	return 1;
}
void TestValid()
{
	char *in = "abcdefg";
	char *out1 = "decfbga";
	char *out2 = "fegdacb";
	char *out3 = "efdgbca";
	char *out4 = "cdbefag";
	//int ret;
	//ret = Valid(in,out1,7);
	//printf("%d",ret);
	printf("%s\n",Valid(in,out1,strlen(in)) ? "合法顺序":"非法顺序" );
	printf("%s\n",Valid(in,out2,strlen(in)) ? "合法顺序":"非法顺序" );
	printf("%s\n",Valid(in,out3,strlen(in)) ? "合法顺序":"非法顺序" );
	printf("%s\n",Valid(in,out4,strlen(in)) ? "合法顺序":"非法顺序" );
}