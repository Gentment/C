#include "List.h"


void ListInit(ListNode **Node)
{
	assert(Node != NULL);
	*Node = NULL;
}

void ListDestroy(ListNode **Node)
{
	*Node = NULL;
}

static ListNode * CreateNode(DataType data)
{
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}


//头插
void ListPushFront(ListNode **Node,DataType data)
{
	//assert(Node != NULL);

	ListNode *newNode = CreateNode(data);		 // *newNode 用来存储新结点的地址	
	newNode->next = *Node;						 // 把头结点的地址赋给新结点 

	*Node = newNode;							// 把新结点的地址赋给头结点 （ *Node用来存储下一个结点的地址）
	
}
//
//void ListPrint(ListNode *Node)
//{
//	assert(Node != NULL);
//	printf("123");
//	Node = NULL;
//	while (Node->next != NULL)
//	{
//		printf("%d ",Node->data);
//	}
//}

//尾插
void ListPushBack(ListNode **Node,DataType data)
{
	ListNode *newNode = CreateNode(data);

	ListNode *cur = *Node;								//把头结点地址赋给cur

	if (*Node == NULL)									//判断头结点是否为空，如果为空，将新的结点赋给头结点（如果是空链表）
	{
		*Node = newNode;
		return;
	}

	while (cur->next !=NULL)							//如果头结点不为空，则将判断头结点指向下一个结点以及后面的结点是否为空
	{													// 如果有空结点，则将赋给当前cur，
		cur = cur->next;
	}
	cur->next = newNode;								//将新的结点地址赋给当前的下一结点
}

void ListPopFront(ListNode **Node)
{
	//assert(Node != NULL);
	//assert(*Node != NULL);
	
	ListNode *del = *Node;								// 将头结点的地址del，然后指向下一个结点并赋给Node，然后释放del（头结点存储在del中）

	*Node = del->next;
	free(del);
}


void ListPopBack(ListNode **Node)
{
	/*ListNode *del = *Node ;
	while (del->next != NULL)
	{
		del = del->next;
	}
	*Node = del->next; 

	free(del);*/


	ListNode *del;
	ListNode *cur = *Node;

	while (cur->next->next != NULL)			// cur->next->next :头指针指向头结点，然后指向下一个结点
	{										// 判断并找到最后一个结点的地址，赋给del					
		cur = cur->next;
	}

	del = cur->next;
	cur->next = NULL;
	free(del);
}

//查找
ListNode* ListFind(ListNode *Node , DataType data)
{
	ListNode *cur;
	for (cur = Node;cur != NULL;cur=cur->next)
	{
		if (data == cur->data)
		{
			return cur;
		}
	}
	return NULL;
}

//在某结点前插入结点
void ListInsert(ListNode **Node,ListNode *pos,DataType data)
{
	ListNode *cur = *Node;
	ListNode *newNode;
	if (*Node == pos)
	{
		ListPopFront(Node);
		return;
	}
	
	
	while (cur->next != pos)
	{
		cur = cur->next;
	}

	newNode = CreateNode(data);
	newNode->next = cur->next;
	cur->next =newNode;

}

//删除指定结点
void ListDelete(ListNode **Node,ListNode *pos)
{
	ListNode *cur = *Node;
	if (*Node == pos)
	{
		ListPopFront(Node);
	}
	while (cur->next != pos)
	{
		cur = cur->next;
	}

	cur->next = pos->next;
	free(pos);
}

//单链表的打印
void  ListPrint(ListNode *Node)
{
	ListNode *cur = Node;
	if (Node == NULL)
	{
		return;
	}

	while (cur != NULL)
	{
		printf("%d--> ",cur->data);
		cur = cur->next;
	}	
}

// 1、从尾到头打印单链表 递归
void ListReversePrint(ListNode *Node)
{
	if (Node == NULL)
	{
		return;
	}

	ListReversePrint(Node->next);
	printf("%d-->",Node->data);
}

void ListReveresePrint2(ListNode *Node)
{
	ListNode *end = NULL;
	while (end != Node)
	{
		ListNode *cur = Node;
		while (cur->next != end)
		{
			cur = cur->next;
		}
		printf("%d-->",cur->data);
		end = cur;
	}
}

//2. 删除一个无头单链表的非尾结点（不能遍历链表）
void ListDelNotFirst(ListNode **Node ,ListNode *pos)
{
	ListNode *del;
	if (Node == NULL)
	{
		return;
	}
	//	pos 位置为第一个结点时，修改指针
	if (pos == *Node)
	{
		*Node = pos->next;
		free(pos);
	}
	// pos 位置不是第一个结点时也不是最后一个结点时
	pos->data = pos->next->data;   //先修改data的值
	del = pos->next;     //将pos->next作为要删除的结点
	pos->next = del->next;
	free(del);
}

//3.在无头单链表的一个结点前插入一个结点（不能遍历链表）

void ListInsertBefore(ListNode **Node ,ListNode *pos ,DataType data)
{
	ListNode *newNode;
	if (*Node == NULL && pos == NULL)
	{
		return;
	}
	//插入的结点是在第一个结点上
	if (pos == *Node)
	{
		ListNode *newNode = CreateNode(data);
		newNode->next = *Node;
		*Node = newNode;
		return;
	}
	//插入的结点不是第一个结点时
	newNode = CreateNode(pos->data);
	newNode->next = pos->next;  //后插
	pos->next = newNode;
	pos->data = data;
}

//4 .逆置/反转单链表
// 思路1：从第二个结点开始，将其删除，人挪活插在第一个结点处，直到链表结束
//void listReverse(ListNode **Node)
//{
//	if (Node == NULL)
//	{
//		return ;
//	}
//	if (*Node == NULL)
//	{
//		return;
//	}
//	//只有一个结点
//	if ((*Node)->next == NULL)
//	{
//		return ;
//	}
//	//至少两个结点
//	ListNode *cur = *Node;
//	while (cur->next != NULL)
//	{
//		ListNode *rm = cur->next;
//		cur->next = rm->next;
//		rm->next = *Node;
//		*Node = rm;
//	}
//}
//思路2：改变每个结点的指针指向从而逆置
//void listReverseRePoint(ListNode **Node)
//{
//	if (Node == NULL)
//	{
//		return;
//	}
//	if (*Node == NULL)
//	{
//		return;
//	}
//	if ((*Node)->next == NULL)
//	{
//		return;
//	}
//
//	ListNode *pre = *Node;
//	ListNode *cur = (*Node)->next;
//	pre->next = NULL;
//	
//	while (cur != NULL)
//	{
//		ListNode *temp = cur->next;
//		cur->next = pre;
//		pre =cur;
//		cur = temp;
//	}
//
//	*Node = pre;
//}


// 5.找出两个链表里相同数据
void ListIntersection(ListNode *list1,ListNode *list2)
{
	ListNode *head1 = list1;
	ListNode *head2 = list2;
	
	DataType data;

	if (head1 ==NULL && head2 == NULL)
	{
		return ;
	}

	while (head1 != NULL && head2 != NULL)
	{
		if (head1->data < head2->data)
		{
			head1 = head1->next;
		}
		 if (head1->data > head2->data)
		{
			head2 = head2->next;
		}
		
		if (head1->data == head2->data)
		{
			printf("%d ",head1->data);
			data = head1->data;

			while (head2 != NULL && data == head2->data  )
			{
				head2 = head2->next;
			}
			while (head1 != NULL && data == head1->data )
			{
				head1 = head1->next;
			}
		}
	}
}

void TestListInterstion()
{
	ListNode *list1 = NULL;
	ListNode *list2 = NULL;

	ListPushBack(&list1,1);
	ListPushBack(&list1,1);
	ListPushBack(&list1,3);	
	ListPushBack(&list1,4);

	ListPushBack(&list2,2);
	ListPushBack(&list2,2);
	ListPushBack(&list2,4);	
	ListPushBack(&list2,4);

	ListIntersection(list1,list2);
}


//6.单链表实现约瑟夫环
ListNode* ListJosephCircle(ListNode *list,DataType k)
{
	//第一步，变成环
	ListNode *tail = list;
	ListNode *cur = list;
	ListNode *pre = NULL;
	int i =0;
#if 0
	if (list == NULL)
	{
		return NULL;
	}
	
#endif
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = list;

	 
	//第二步，找到第k个数
	while ( cur->next != cur)
	{	
		#if 0
//1 2 3 4 5 6 7 8 
		while (--k)
		{
		
			pre = cur;  //记录剔除结点的前一个结点
			cur = cur->next;
		}
#endif
		for (i=1;i<k;i++)
		{
			pre = cur;  //记录剔除结点的前一个结点
			cur = cur->next;
		}
		
		pre->next =cur->next;
		printf("淘汰：%d\n",cur->data);
		free(cur);

		cur = pre->next;
	}	
	cur->next = NULL;
	return cur;
}


void TestListJosephCircle()
{
	ListNode *list1 = NULL;
	ListNode *re;
	ListPushBack(&list1,1);
	ListPushBack(&list1,2);
	ListPushBack(&list1,3);	
	ListPushBack(&list1,4);
	ListPushBack(&list1,5);
	ListPushBack(&list1,6);
	
	ListPrint(list1);
	printf("\n");
	re = ListJosephCircle(list1,3);
	printf("%d\n",re->data);
}

//7.合并两个有序的链表，合并后依然有序
ListNode *ListMerge(ListNode *list1,ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;
	ListNode *result = NULL;	//结果链表
	ListNode *tail = NULL;		 //结果链表中的最后一个结点，方便尾插
	ListNode *next = NULL;		//保存遍历过程中的下一个结点
	ListNode *node;

	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data <= cur2->data)
		{
			node = cur1;
		}
		else
		{
			node =cur2;
		}

		next = node->next;
		if (result != NULL)
		{
			tail->next = node;
		}
		else
		{
			result = node;
		}
		node->next = NULL;

		tail = node;
	
		
		if (node == cur1)
		{
			cur1 = next;
		}
		else
		{
			cur2 = next;
		}
	}
	//一个链表空了
	if (cur1 == NULL)
	{
		tail->next =cur2;
	}
	if (cur2 == NULL)
	{
		tail->next =cur1;
	}

	return result;
}

void TestMerge()
{
	ListNode *list1 = NULL;
	ListNode *list2 = NULL;

	ListNode *result = NULL;

	ListPushBack(&list1,1);
	ListPushBack(&list1,2);
	ListPushBack(&list1,3);	
	ListPushBack(&list1,4);

	ListPushBack(&list2,1);
	ListPushBack(&list2,2);
	ListPushBack(&list2,3);	
	ListPushBack(&list2,4);

	result = ListMerge(list1,list2);
	ListPrint(result);
}

//8.查找单链表的中间结点，要求只能遍历一次链表
void ListFindMidNode(ListNode *list)
{	
	ListNode *fast = list;
	ListNode *slow = list;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next;
		if (fast == NULL)
		{
			break;
		}
		fast = fast->next;
		if (fast == NULL)
		{
			break;
		}
		slow = slow->next;
	}

	printf("%d\n",slow->data);
}

void TestFindMid()
{
	ListNode *list = NULL;

	ListPushBack(&list,1);
	ListPushBack(&list,2);
	ListPushBack(&list,3);	
	ListPushBack(&list,4);
	ListPushBack(&list,5);	
	ListPushBack(&list,6);

	ListFindMidNode(list);
}

//9.查找单链表中的倒数第K个结点，要求只能遍历一次链表

void ListFindTailK(ListNode *list,DataType k)
{
	ListNode *fast = list;
	ListNode *slow = list;

	while (k--)
	{
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}

	printf("%d\n",slow->data);
}

void TestFindTailK()
{
	ListNode *list = NULL;

	ListPushBack(&list,1);
	ListPushBack(&list,2);
	ListPushBack(&list,3);	
	ListPushBack(&list,4);
	ListPushBack(&list,5);	
	ListPushBack(&list,6);
	
	ListFindTailK(list,3);

}

//10.删除单链表中的倒数第K个结点

void ListDelTailK(ListNode *list, DataType k)
{
	ListNode *fast = list;
	ListNode *slow = list;
	ListNode *pre = NULL;
	
	while (k--)
	{
		fast = fast->next;
	}

	while (fast != NULL)
	{
		pre = slow;
		fast = fast->next;
		slow = slow->next;
	}
	pre->next = slow->next;

	free(slow);

}

void TestDelTailK()
{
	ListNode *list = NULL;

	ListPushBack(&list,1);
	ListPushBack(&list,2);
	ListPushBack(&list,3);	
	ListPushBack(&list,4);
	ListPushBack(&list,5);	
	ListPushBack(&list,6);
	
	ListPrint(list);
	printf("\n删除倒数第%d个结点\n",3);
	ListDelTailK(list,3);

	 ListDelNotFirst(list,list);


	ListPrint(list);
}

void TestListDelNotFirst()
{
	ListNode *list = NULL;

	ListPushBack(&list,1);
	ListPushBack(&list,2);
	ListPushBack(&list,3);	
	ListPushBack(&list,4);
	ListPushBack(&list,5);	
	ListPushBack(&list,6);

	ListPrint(list);

	ListDelNotFirst(list,list);

	ListPrint(list);
}