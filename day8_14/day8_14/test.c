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


	/*printf("����\n");
	ListPrint(Node);
	printf("\n-----------------------\n");
	printf("����1�����\n");
	ListReversePrint(Node);
	printf("\n-----------------------\n");
	printf("����2�����\n");
	ListReveresePrint2(Node);
	printf("\n-----------------------\n");*/

	//����λ�ò���
	/*re = ListFind(Node,2);
	ListInsert(&Node,re,7);
	printf("����������\n");
	ListPrint(Node);*/

	//ɾ���ող��������
	/*re = ListFind(Node,7);
	ListDelete(&Node,re);
	printf("\n-----------------------\n");
	printf("ɾ���������\n");
	ListPrint(Node);*/
	
	//ɾ��������ͷ������ķ�δ���
	//ListDelNotFirst(&Node,re);
	//printf("\n-----------------------\n");
	//printf("ɾ���������\n");
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