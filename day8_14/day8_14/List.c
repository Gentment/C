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


//ͷ��
void ListPushFront(ListNode **Node,DataType data)
{
	//assert(Node != NULL);

	ListNode *newNode = CreateNode(data);		 // *newNode �����洢�½��ĵ�ַ	
	newNode->next = *Node;						 // ��ͷ���ĵ�ַ�����½�� 

	*Node = newNode;							// ���½��ĵ�ַ����ͷ��� �� *Node�����洢��һ�����ĵ�ַ��
	
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

//β��
void ListPushBack(ListNode **Node,DataType data)
{
	ListNode *newNode = CreateNode(data);

	ListNode *cur = *Node;								//��ͷ����ַ����cur

	if (*Node == NULL)									//�ж�ͷ����Ƿ�Ϊ�գ����Ϊ�գ����µĽ�㸳��ͷ��㣨����ǿ�����
	{
		*Node = newNode;
		return;
	}

	while (cur->next !=NULL)							//���ͷ��㲻Ϊ�գ����ж�ͷ���ָ����һ������Լ�����Ľ���Ƿ�Ϊ��
	{													// ����пս�㣬�򽫸�����ǰcur��
		cur = cur->next;
	}
	cur->next = newNode;								//���µĽ���ַ������ǰ����һ���
}

void ListPopFront(ListNode **Node)
{
	//assert(Node != NULL);
	//assert(*Node != NULL);
	
	ListNode *del = *Node;								// ��ͷ���ĵ�ַdel��Ȼ��ָ����һ����㲢����Node��Ȼ���ͷ�del��ͷ���洢��del�У�

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

	while (cur->next->next != NULL)			// cur->next->next :ͷָ��ָ��ͷ��㣬Ȼ��ָ����һ�����
	{										// �жϲ��ҵ����һ�����ĵ�ַ������del					
		cur = cur->next;
	}

	del = cur->next;
	cur->next = NULL;
	free(del);
}

//����
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

//��ĳ���ǰ������
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

//ɾ��ָ�����
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

//������Ĵ�ӡ
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

// 1����β��ͷ��ӡ������ �ݹ�
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

//2. ɾ��һ����ͷ������ķ�β��㣨���ܱ�������
void ListDelNotFirst(ListNode **Node ,ListNode *pos)
{
	ListNode *del;
	if (Node == NULL)
	{
		return;
	}
	//	pos λ��Ϊ��һ�����ʱ���޸�ָ��
	if (pos == *Node)
	{
		*Node = pos->next;
		free(pos);
	}
	// pos λ�ò��ǵ�һ�����ʱҲ�������һ�����ʱ
	pos->data = pos->next->data;   //���޸�data��ֵ
	del = pos->next;     //��pos->next��ΪҪɾ���Ľ��
	pos->next = del->next;
	free(del);
}

//3.����ͷ�������һ�����ǰ����һ����㣨���ܱ�������

void ListInsertBefore(ListNode **Node ,ListNode *pos ,DataType data)
{
	ListNode *newNode;
	if (*Node == NULL && pos == NULL)
	{
		return;
	}
	//����Ľ�����ڵ�һ�������
	if (pos == *Node)
	{
		ListNode *newNode = CreateNode(data);
		newNode->next = *Node;
		*Node = newNode;
		return;
	}
	//����Ľ�㲻�ǵ�һ�����ʱ
	newNode = CreateNode(pos->data);
	newNode->next = pos->next;  //���
	pos->next = newNode;
	pos->data = data;
}

//4 .����/��ת������
// ˼·1���ӵڶ�����㿪ʼ������ɾ������Ų����ڵ�һ����㴦��ֱ���������
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
//	//ֻ��һ�����
//	if ((*Node)->next == NULL)
//	{
//		return ;
//	}
//	//�����������
//	ListNode *cur = *Node;
//	while (cur->next != NULL)
//	{
//		ListNode *rm = cur->next;
//		cur->next = rm->next;
//		rm->next = *Node;
//		*Node = rm;
//	}
//}
//˼·2���ı�ÿ������ָ��ָ��Ӷ�����
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


// 5.�ҳ�������������ͬ����
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


//6.������ʵ��Լɪ��
ListNode* ListJosephCircle(ListNode *list,DataType k)
{
	//��һ������ɻ�
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

	 
	//�ڶ������ҵ���k����
	while ( cur->next != cur)
	{	
		#if 0
//1 2 3 4 5 6 7 8 
		while (--k)
		{
		
			pre = cur;  //��¼�޳�����ǰһ�����
			cur = cur->next;
		}
#endif
		for (i=1;i<k;i++)
		{
			pre = cur;  //��¼�޳�����ǰһ�����
			cur = cur->next;
		}
		
		pre->next =cur->next;
		printf("��̭��%d\n",cur->data);
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

//7.�ϲ���������������ϲ�����Ȼ����
ListNode *ListMerge(ListNode *list1,ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;
	ListNode *result = NULL;	//�������
	ListNode *tail = NULL;		 //��������е����һ����㣬����β��
	ListNode *next = NULL;		//������������е���һ�����
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
	//һ���������
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

//8.���ҵ�������м��㣬Ҫ��ֻ�ܱ���һ������
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

//9.���ҵ������еĵ�����K����㣬Ҫ��ֻ�ܱ���һ������

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

//10.ɾ���������еĵ�����K�����

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
	printf("\nɾ��������%d�����\n",3);
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