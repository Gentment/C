#pragma once

#include "Model.h"

void GameRun();
void GameInit(Game *pGame);
void SnakeInit(Snake *pSnake);
void WallInit(int width,int height);

Position GenerateFood(int width, int height, Snake *pSnake);
void DemoSetPos();