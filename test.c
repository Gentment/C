#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("**************************\n");
	printf("******* 1��play  *********\n");
	printf("******* 2��exit  *********\n");
	printf("**************************\n");
}

void game()
{
	int sd = rand()%10;
	int input = 0;
	printf("%d\n",sd);
	while(1)
	{
		printf("�����롷");
		scanf("%d",&input);
		if (input>sd)
		{
			printf("��´���\n");
		}else if (input<sd)
		{
			printf("���С��\n");
		}else if (input == sd)
		{
			printf("��ϲ�㣬�¶���%d\n",sd);
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
		printf("��ѡ��");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("������ѡ��\n!");
			break;
		}

	} while (input);
	
	


	return 0;
}