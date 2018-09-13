#pragma once

#include <stdlib.h>
#define Width 28 //ǽ���
#define Height 27 // ǽ�߶�
#define Leg 3  //snake��ʼ������

typedef enum Direction
{
	UP, DOWN, LEFT, RIGHT
}Direction;

typedef struct PoPositionstion
{
	int x;
	int y;
}Position;

typedef struct Node
{
	Position pos;
	struct Node *next;
}Node;

typedef struct Snake
{
	Node *head;
	Node *tail;
	Direction direction;
} Snake;

typedef struct Game
{
	Snake snake;
	Position food;
	int width;
	int height;
}Game;



