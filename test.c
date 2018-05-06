#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("**************************\n");
	printf("******* 1、play  *********\n");
	printf("******* 2、exit  *********\n");
	printf("**************************\n");
}

void game()
{
	int sd = rand()%10;
	int input = 0;
	printf("%d\n",sd);
	while(1)
	{
		printf("请输入》");
		scanf("%d",&input);
		if (input>sd)
		{
			printf("你猜大了\n");
		}else if (input<sd)
		{
			printf("你猜小了\n");
		}else if (input == sd)
		{
			printf("恭喜你，猜对了%d\n",sd);
			break;
		}

	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("请选择》");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏！\n");
			break;
		default:
			printf("请重新选择\n!");
			break;
		}

	} while (input);
	
	


	return 0;
}