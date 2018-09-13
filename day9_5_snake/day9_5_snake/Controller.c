#include "Controller.h"
#include "View.h"
#include "Model.h"
#include <time.h>
#include <stdbool.h>
#include <Windows.h>

void SnakeInit(Snake *pSnake)
{
	pSnake->tail = NULL;
	for (int i = 0; i < Leg; i++)
	{
		Node *node = (Node*)malloc(sizeof(Node));
		node->pos.x = Leg + i;
		node->pos.y = 2;

		if (i == 0)
		{
			pSnake->head = node;
		}
		node->next = pSnake->tail;
		pSnake->tail = node;
	}
	pSnake->direction = RIGHT;
}
void WallInit(int width, int height)
{
	DisplayWall(width, height);
	DisplayScore(Width*1.5,Height,0);
}


void GameInit(Game *pGame)
{
	pGame->width = Width;
	pGame->height = Height;

	WallInit(pGame->width,pGame->height);
	SnakeInit(&pGame->snake);

	pGame->food = GenerateFood(pGame->width,pGame->height,pGame);
}


void ADDHead(Snake * pSnake, Position next)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->pos = next;
	node->next = NULL;
	pSnake->head->next = node;
	pSnake->head = node;

	DisplaySnakeNode(&next);
}


bool IsOverlap(Position pos,Snake *pSnake)
{
	Node *node;
	for (node = pSnake->tail;node != NULL;node = node->next)
	{
		if (node->pos.x == pos.x && node->pos.y == pos.y)
		{
			return true;
		}
	}
	return false;
}

bool IsEat(Position pos,Position next)
{
	return pos.x == next.x && pos.y == next.y;
}
//产生食物
Position GenerateFood(int width,int height,Snake *pSnake)
{
	Position pos;
	do
	{
		pos.x = rand() %width;
		pos.y = rand() %height;

	} while (IsOverlap(pos,pSnake));
	DisplayFood(&pos);

	return pos;
}

//获取下一个位置
Position GetnextPosition(const Snake *pSnake)
{
	Position next = pSnake->head->pos;

	switch (pSnake->direction)
	{
	case UP:
		next.y -= 1;
		break;
	case DOWN:
		next.y += 1;
		break;
	case LEFT:
		next.x -= 1;
		break;
	case RIGHT:
		next.x += 1;
		break;
	}
	return next;
}

void RemoveTail(Snake *pSnake)
{
	Node *tail = pSnake->tail;

	pSnake->tail = pSnake->tail->next;

	CleanSnakeNode(&tail->pos);

	free(tail);
}

bool KillByWall(const Snake *pSnake,int width,int height)
{
	int x = pSnake->head->pos.x;
	int y = pSnake->head->pos.y;
	if (x >= 0 && x< width && y >= 0 && y <height)
	{
		return false;
	}
	else
	{
		return true;
	}
}


bool KillBySelf(const Snake *pSnake)
{
	Node *node;
	for (node = pSnake->tail;node != pSnake->head;node = node->next) //node = pSnake->head,保证不吃自己的头
	{
		if (node->pos.x == pSnake->head->pos.x && node->pos.y == pSnake->head->pos.y)
		{
			return false;
		}
	}
	return false;
}

bool GameOver(const Snake *pSnake,int width,int height)
{
	if (KillByWall(pSnake,width,height))
	{
		printf("撞墙了\n");
		return true;
	}

	if (KillBySelf(pSnake))
	{
		printf("撞到自己了\n");
		return true;
	}
	return false;
}

void GameRun()
{
	Game game;
	GameInit(&game);
	DisplaySnake(&game.snake);
	int score = 0;
	while (1)
	{
		if (GetAsyncKeyState(VK_UP) && game.snake.direction != DOWN) {
			game.snake.direction = UP;
		}
		else if (GetAsyncKeyState(VK_DOWN) && game.snake.direction != UP) {
			game.snake.direction = DOWN;
		}
		else if(GetAsyncKeyState(VK_LEFT) && game.snake.direction != RIGHT) {
			game.snake.direction = LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && game.snake.direction != LEFT) {
			game.snake.direction = RIGHT;
		}
	
		Position nextPos = GetnextPosition(&game.snake);
			
		if (IsEat(game.food,nextPos))
		{
			  //得分
			score += 1 ;
			ADDHead(&game.snake,nextPos);
			//DisplayScore(Width+10,Height,score);
			DisplayScore(Width*1.5, Height, score);
			game.food = GenerateFood(game.width, game.height, &game.snake);
		}
		else   //向前移动的动作
		{
			RemoveTail(&game.snake);

			ADDHead(&game.snake,nextPos);
		}

		if (GameOver(&game.snake,game.width,game.height))
		{
			break;
		}

		
		Sleep(500);
	}
}

void DemoSetPos()
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;

	for (int i = 0; i < 6; i++)
	{
		coord.X = 2 * i;
		coord.Y = i;

		SetConsoleCursorPosition(hOutput,coord);

		printf("%02d",i);
	}
}