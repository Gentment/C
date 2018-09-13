#include <iostream>
#include <stdlib.h>
#include "MyStasck.h"
using namespace std;


int main()
{
	MyStack *pStack = new MyStack(5);

	pStack->push('a');
	pStack->push('b');
	pStack->push('c');
	pStack->push('d');
	pStack->push('e');

	pStack->stackTraverse(true); //1
	cout<<endl;
	cout<<"栈的元素个数："<<pStack->stackLength()<<endl;
	char elem = 0;
	pStack->pop(elem);
	cout<<endl;
	cout<<"pop元素："<<elem<<endl;	//2
	
	pStack->stackTraverse(true); //3
	cout<<endl;
	cout<<"栈的元素个数："<<pStack->stackLength()<<endl; //4
	//pStack->clearStack();
	if (pStack->stackEmpty())
	{
	   cout<<"栈为空"<<endl; //5
	}
	if (pStack->stackFull())
	{
	   cout<<"栈为满"<<endl;
	}

	delete pStack;
	pStack = NULL;


}