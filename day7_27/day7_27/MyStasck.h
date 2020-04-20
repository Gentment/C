#ifndef MYSTACK_H
#define MYSTACK_H

class MyStack
{
public:
	MyStack(int size);  //分配内存出赎回栈空间，设定栈容量，栈顶
	~MyStack();			//同收栈空间内存
	bool stackEmpty();	//..
	bool stackFull();
	void clearStack();
	int stackLength();
	bool push(char elem);
	bool pop(char &elem);
	void stackTraverse(bool isFromButtom);
private:
	char *m_pBuffer;  //栈空间指针
	int m_iSize;	  //栈容量
	int m_iTop;		  //栈顶，栈中元素个数
};
#endif //MYSTACK_H
