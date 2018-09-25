#pragma once  
#include<iostream>  
#include<windows.h>  
using namespace std;  

void menu() {  
	cout << "***************Menu*******************" << endl;  
	cout << "*                                    *" << endl;  
	cout << "*           开始游戏请按 1           *" << endl;  
	cout << "*           退出游戏请按 0           *" << endl;  
	cout << "*                                    *" << endl;  
	cout << "***************Menu*******************" << endl;  
}  

int StartPage() {  
	menu();  
	int ok;  
	cin >> ok;  
	switch (ok) {  
		case 1:return 1;  
		case 0:return 0;  
		default:system("cls");  
			cout << "please input 1 or 0" << endl;  
			Sleep(1000),system("cls");  
			return 2;  
	}  
}  