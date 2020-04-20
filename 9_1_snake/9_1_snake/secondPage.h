#pragma once  

#include<time.h>  
#include<stdio.h>  
#include<conio.h>  
#include<iostream>  
#include<windows.h>  
using namespace std;

int direct, cnt = 0;
int eaten = 0, ch;
#define height 20  
#define width 50  
#define up      72  
#define down    80  
#define left    75  
#define right   77  
#define maxn 1050  

struct Food {
	int x, y;
}food;
struct Snake {
	int x[maxn], y[maxn];
	int len, speed;
}snake;

void StartGameIntroduce() {
	system("cls");
	cout << "************Option************" << endl;
	cout << "*                            *" << endl;
	cout << "*                            *" << endl;
	cout << "*        使用上下左右键      *" << endl;
	cout << "*         控制小蛇移动       *" << endl;
	cout << "*                            *" << endl;
	cout << "*                            *" << endl;
	cout << "************Option************" << endl;
	Sleep(1000);
	system("cls");
}

void gotoxy(int x, int y) {
	HANDLE hout;
	COORD cor;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cor.X = x, cor.Y = y;
	SetConsoleCursorPosition(hout, cor);
}

void init() {
	/*****************游戏框架***********************/
	for (int i = 0; i < width; i++) {
		gotoxy(i, 0), printf("&");
		gotoxy(i, height - 1), printf("&");

	}
	for (int i = 0; i < height; i++) {
		gotoxy(0, i), printf("&");
		gotoxy(width - 1, i), printf("&");
	}


	/*****************游戏食物***********************/
	food.x = rand() % (width - 2) + 1;
	food.y = rand() % (height - 2) + 1;
	gotoxy(food.x, food.y);
	printf("o");


	/*****************游戏小蛇***********************/
	ch = direct = up;
	snake.x[0] = rand() % (width - 8) + 8;
	snake.y[0] = rand() % (height - 8) + 8;
	snake.x[1] = snake.x[0];
	snake.y[1] = snake.y[0] + 1;
	snake.x[2] = snake.x[1];
	snake.y[2] = snake.y[1] + 1;
	snake.len = 3;
	snake.speed = 200;
	for (int i = 0; i < snake.len; i++) {
		gotoxy(snake.x[i], snake.y[i]);
		if (i == 0) printf("@");
		else printf("#");
	}
}

void update_food() {
	if (snake.x[0] == food.x&&snake.y[0] == food.y) {
		food.x = rand() % (width - 2) + 1;
		food.y = rand() % (height - 2) + 1;
		gotoxy(food.x, food.y);
		printf("o");
		snake.len++;
		eaten = 1;
		cnt++;
	}
}

void update_speed() {
	if (eaten) snake.speed = snake.speed - snake.len * 2;
}

void update_snake() {
	int flag = 0;
	if (_kbhit()) ch = _getch(), flag = 1;
	if (!eaten) {
		gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]);
		printf(" ");
	}
	for (int i = snake.len - 1; i > 0; i--) {
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1];
	}


	if (!(ch == up || ch == down || ch == left || ch == right || ch == direct)) flag = 0;
	if (flag && (ch + direct == 152)) flag = 0;
	if (flag == 0) ch = direct;
	else         direct = ch;

	switch (ch) {
	case up:snake.y[0]--; break;
	case down:snake.y[0]++; break;
	case left:snake.x[0]--; break;
	case right:snake.x[0]++; break;
	}

	gotoxy(snake.x[0], snake.y[0]); printf("@");
	gotoxy(snake.x[1], snake.y[1]); printf("#");
	eaten = 0;
}

int is_alive() {
	if (snake.x[0] == 0 || snake.x[0] == width || snake.y[0] == 0 || snake.y[0] == height) return 0;
	for (int i = 1; i < snake.len; i++)
		if (snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i])
			return 0;
	return 1;
}

void StartGame() {
	StartGameIntroduce();   //游戏开始的介绍页面  
	srand((int)time(NULL));
	init();                 //游戏开始前的准备工作  
	while (1)
	{
		update_food();
		update_speed();
		update_snake();
		Sleep(snake.speed);
		if (!is_alive()) {
			system("cls");
			cout << "******************************" << endl;
			cout << "*                            *" << endl;
			cout << "*                            *" << endl;
			cout << "*          game  over        *" << endl;
			printf("*           %4d分           *\n", cnt);
			cout << "*                            *" << endl;
			cout << "******************************" << endl;
			Sleep(3000);
			system("cls");
			break;
		}
	}
}
