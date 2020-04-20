#include "List.h"
#include "Link.h"
#include "DLink.h"

int main()
{
	/*ListNode *Node;
	ListNode *re;
	ListInit(&Node);

	ListPushFront(&Node,1);
	ListPushFront(&Node,2);
	ListPushFront(&Node,3);
	ListPushFront(&Node,4);
	ListPushFront(&Node,5);
	ListPushFront(&Node,6);*/

	//ListPushBack(&Node,7);
	//ListPushBack(&Node,8);
	
	/*ListPopFront(&Node);*/
	
	//ListPopBack(&Node);


	/*printf("链表：\n");
	ListPrint(Node);
	printf("\n-----------------------\n");
	printf("逆置1结果：\n");
	ListReversePrint(Node);
	printf("\n-----------------------\n");
	printf("逆置2结果：\n");
	ListReveresePrint2(Node);
	printf("\n-----------------------\n");*/

	//任意位置插入
	/*re = ListFind(Node,2);
	ListInsert(&Node,re,7);
	printf("插入后的链表：\n");
	ListPrint(Node);*/

	//删除刚刚插入的数据
	/*re = ListFind(Node,7);
	ListDelete(&Node,re);
	printf("\n-----------------------\n");
	printf("删除后的链表：\n");
	ListPrint(Node);*/
	
	//删除不是无头单链表的非未结点
	//ListDelNotFirst(&Node,re);
	//printf("\n-----------------------\n");
	//printf("删除后的链表：\n");
	//ListPrint(Node);

	//printf("\n-----------------------\n");
	//printf("\n-----------------------\n");


	//TestListInterstion();
	//TestListJosephCircle();
	//TestMerge();
	//TestFindMid();
	//TestFindTailK();
	//TestDelTailK();

	TestCopy();
	//TestDLinkInsert();
//	TestListDelNotFirst();
	return 0;
}