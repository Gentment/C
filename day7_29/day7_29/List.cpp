//#include "List.h"
//#include <iostream>
//using namespace std;
//
//List::List()
//{
//	m_pList = new Node;
//	m_pList->data = 0;
//	m_pList->next = NULL;
//	m_iLength = 0;
//}
//
//bool List::ListEmpty()
//{
//	if (m_iLength == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//
//int List::ListLength()
//{
//	return m_iLength;
//}
//
//void List::ClearList()
//{
//	Node *currentNode = m_pList->next;
//	while (currentNode != NULL)
//	{
//		Node * temp = currentNode->next;
//		delete currentNode;
//		currentNode = temp;
//	}
//	m_pList->next = NULL;
//}
//
//bool List::ListInsertHead(Node *pNode)
//{
//	Node *temp = m_pList->next;
//	Node *newNode = new Node;
//	if (newNode == NULL)
//	{
//		return false;
//	}
//	newNode->data = pNode->data;
//	m_pList->next = newNode;
//	newNode->next = temp;
//
//	return true;
//}
//
//bool List::ListInsertTail(Node *pNode)
//{
//	Node *currentNode = m_pList;
//	while(currentNode->next != NULL)
//	{
//		currentNode = currentNode->next;
//
//	}
//	Node *newNode = new Node;
//	if (newNode == NULL)
//	{
//		return false;
//	}
//	newNode->data = pNode->data;
//	newNode->next = NULL;
//	currentNode->next = newNode;
//	m_iLength++;
//
//	return true;
//}
//
//
//
//bool List::ListInsert(int i,Node *pNode)
//{
//	if (i<0||i>m_iLength)
//	{
//		return false;
//	}
//	Node *currentNode = m_pList;
//	
//	for (int k=0;k<i;k++)
//	{
//		currentNode = currentNode->next;
//	}
//	
//	Node *newNode = new Node;
//	if (newNode == NULL)
//	{
//		return false;
//	}
//	newNode->data = pNode->data;
//	newNode->next = currentNode->next;
//	currentNode->next = newNode;
//	
//	return true;
//}
