#include<stdio.h>  
#include"firstpage.h"  
#include"secondpage.h"  

int main()  
{  
	int Choice;  
	while (1) {  
		Choice = StartPage();  
		switch (Choice) {  
		case 0:system("cls"); return 0;  
		case 1:StartGame();  
		case 2:system("cls"); continue;  
		}  
	}  
	return 0;  
}  