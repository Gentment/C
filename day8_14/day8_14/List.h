#pragma once

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


typedef int DataType;

typedef struct ListNode
{
	DataType data;
	struct ListNode *next;
} ListNode;


void ListInit(ListNode **Node);

void ListDestroy(ListNode **Node);

void ListPushFront(ListNode **Node,DataType data);

void ListPushBack(ListNode **Node,DataType data);

void ListPopFront(ListNode **Node);

void LIstPopBack(ListNode **Node);

ListNode* ListFind(ListNode *Node , DataType data);

void ListInsert(ListNode **Node,ListNode *pos,DataType data);

void ListDelete(ListNode **Node,ListNode *pos);

// 删除一个无头单链表的非尾结点（不能遍历链表）
void ListDelNotFirst(ListNode **Node ,ListNode *pos);

//递归写法
void ListReversePrint(ListNode *Node);

void ListReveresePrint2(ListNode *Node);

void ListPrint(ListNode *Node);

void ListIntersection(ListNode *list1,ListNode *list2);
void TestListInterstion();

ListNode* ListJosephCircle(ListNode *list,DataType k);
void TestListJosephCircle();

ListNode *ListMerge(ListNode *list1,ListNode *list2);
void TestMerge();

void ListFindMidNode(ListNode *list);
void TestFindMid();

void ListFindTailK(ListNode *list,DataType k);
void TestFindTailK();

void ListDelTailK(ListNode *list, DataType k);
void TestDelTailK();