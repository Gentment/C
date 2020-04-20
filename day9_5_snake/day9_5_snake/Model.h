#pragma once

#include <stdlib.h>
#define Width 28 //墙宽度
#define Height 27 // 墙高度
#define Leg 3  //snake初始化长度

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



