#ifndef  LIST_H
#define  LIST_H

class List
{
public:
	List(int size);
	~List();
	void ClearList();			//清空线性表
	bool ListEmpty();			//判断是否为空
	int ListLength();			//获取线性表的长度
	bool GetElem(int i,int *e);  //获取指定元素
	int LocateElem(int *e);		 //寻找第一个满足e的数据元素的位序
	bool PriorElem(int *currentElem,int *preElem); //获取指定元素的前驱
	bool NextElem(int *currentElem,int *nextElem); //获取指定元素的后继
	void  ListTraverse();			//遍历线性表
	bool ListInsert(int i,int *e);//在第i个位置插入元素
	bool ListDelete(int i,int *e);//在删除第i个位置的元素
private:
	int *m_pList;
	int m_iSize;
	int m_iLength;
};


#endif  //LIST_H