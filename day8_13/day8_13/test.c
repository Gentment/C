#include <stdio.h>
#include "SeqList.h"


int main()
{
	int i = 0;
	SeqList Seq;
	SeqListInit(&Seq);
	SeqListInsert(&Seq,0,2);
	SeqListInsert(&Seq,1,3);
	SeqListInsert(&Seq,2,4);
	SeqListInsert(&Seq,3,5);

	print(&Seq);

	SeqListInsert(&Seq,0,1);
	
	print(&Seq);

	SeqListDelete(&Seq,3);
	print(&Seq);
	
	printf("%d\n ",SeqListFind(&Seq,3));
	

	SeqListModify(&Seq,0,10);
	print(&Seq);
	return 0;
}