#pragma once

#include "Model.h"


void ViewInit();
void DisplayWall(int width, int height);

void DisplaySnake(const Snake *pSnake);

void DisplaySnakeNode(const Position *pPos);
void CleanSnakeNode(const Position *pPos);
void DisplayFood(const Position *pFood);
void DisplayScore(int width, int height,int score);
