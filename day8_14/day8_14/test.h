#pragma once

//#include "List.h"
//
//ListNode * Reverse(ListNode *list)
//{
//	ListNode *cur = list;
//	ListNode *rm ;
//
//	if (list == NULL)
//	{
//		return ;
//	}
//	if (list->next == NULL)
//	{
//		return;
//	}
//	while (cur->next != NULL)
//	{
//		rm = cur->next;
//		cur->next = rm->next;
//		rm->data = list;
//		*list = rm;
//	}
//}
//
//#include "Link.h"
//
//Link_C * ListCopy(Link_C *link)
//{
//	//���ƽ��
//	Link_C *cur  = link;
//	Link_C *newLink;
//	while (cur->next != NULL)
//	{
//		newLink = linkCreateNode(link->data);
//		cur->next = newLink;
//		newLink->next = cur->next->next;
//		cur = cur->next;
//	}
//
//	//����random
//
//	cur = link;
//	while (cur != NULL)
//	{
//		cur->next->random = cur->random->next;
//
//	}
//	cur = cur->next->next;
//	//���
//	cur = link;
//	newLink = cur->next;
//
//}