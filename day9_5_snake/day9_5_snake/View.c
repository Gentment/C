#include "View.h"
#include <stdio.h>
#include <Windows.h>

void ViewInit()
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	GetConsoleCursorInfo(hOutput, &ConsoleCursorInfo);
	ConsoleCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hOutput, &ConsoleCursorInfo);
}

void SetPos(int x,int y)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x,y };
	SetConsoleCursorPosition(hOutput,coord);
}

void DisplayWall(int width, int height)
{
	ViewInit();

	//�ϱ���
	SetPos(0,0);
	for (int i = 0; i < width + 2; i++)
	{
		printf("�}");
	}
	//�±���
	SetPos(0, height + 1);
	for (int i = 0; i < width + 2; i++)
	{
		printf("�}");
	}

	//�����
	for (int i = 0; i < height + 2; i++)
	{
		SetPos(0, i);
		printf("�}");
	}
	//�ұ���
	for (int i = 0; i < height + 2; i++)
	{
		SetPos(2*(width + 1), i);
		printf("�}");
	}

	/*SetPos(13*width,Height/2);
	printf("Score��%d",score);*/
}

static void TranslateSetPos(int x, int y)
{
	int X =2*( x+1);
	int Y = y+1;
	SetPos(X, Y);
}
void DisplaySnake(const Snake *pSnake)
{
	for (Node *node = pSnake->tail;node != NULL;node = node->next)
	{
		TranslateSetPos(node->pos.x, node->pos.y);
		printf("�}");
	}
}

void DisplaySnakeNode(const Position *pPos)
{
	TranslateSetPos(pPos->x, pPos->y);
	printf("�}");
}

void CleanSnakeNode(const Position *pPos)
{
	TranslateSetPos(pPos->x, pPos->y);
	printf(" ");
}

void DisplayFood(const Position *pFood)
{
	TranslateSetPos(pFood->x, pFood->y);
	printf("��");
}

void DisplayScore(int width,int height,int score)
{
	//�ϱ���
	SetPos(width, 0);
	for (int i = 0; i < (width + 2)/2; i++)
	{
		printf("�}");
	}
	//�±���
	SetPos(width, height + 1);
	for (int i = 0; i < (width + 2)/2; i++)
	{
		printf("�}");
	}
	//�ұ���
	for (int i = 0; i < height + 2; i++)
	{
		SetPos(2 * (width + 1)+1, i);
		printf("�}");
	}

	SetPos(width+20,Height/2);
	printf("Score��%d",score);
}