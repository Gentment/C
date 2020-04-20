#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int KeyType;

typedef struct Node
{
	KeyType key;
	struct Node *next;
}Node;

typedef struct HashBucket
{
	KeyType size;
	KeyType capacity;
	Node ** array;
}HashBucket;

void HashBucketInit(HashBucket *pHB,int capacity)
{
	pHB->array = (Node **)malloc(sizeof(Node*)* capacity);
	pHB->capacity = capacity;
	pHB->size = 0;

	for (int i = 0; i < capacity; i++)
	{
		pHB->array[i] = NULL;
	}
}

void ListDestory(Node *first)
{
	Node *next = NULL;
	for (Node *cur = first; cur != NULL;cur = next)
	{
		cur = first->next;
		free(cur);
	}
}

void HashBucketDestory(HashBucket *pHB)
{
	//��Ҫ���ͷŹ�ϣͰ ����
	for (int i = 0; i < pHB->capacity; i++)
	{
		ListDestory(pHB->array[i]);
	}
	//�ͷŹ�ϣͰ
	free(pHB->array);
}
Node *HashFind(HashBucket* pHB,KeyType key)
{
	int index = key % pHB->capacity;
	Node *cur = pHB->array[index];

	while (cur != NULL)
	{
		if (cur->key == key)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

int HashInsert(HashBucket *pHB, int key);

void IsExtend(HashBucket *pHB) 
{
	if (pHB->size<pHB->capacity)
	{
		return;
	}
	HashBucket *newHB = NULL;
	HashBucketInit(newHB,pHB->capacity*2);
	for (int i = 0; i < pHB->capacity * 2; i++)
	{
		for (Node *cur = pHB->array[i]; cur != NULL;cur = cur->next)
		{
			HashInsert(newHB,cur->key);
		}
	}

	HashBucketDestory(pHB);
	pHB->array = newHB->array;
	pHB->capacity = newHB->capacity;
}

//�Ϳ��ŵ�ַ��ͬ���ǣ���ʱ�Ĳ��벻��Ҫ���Ǹ�������
//����ɹ�����0��ʧ�ܷ���-1
int HashInsert(HashBucket *pHB,int key)
{
	IsExtend(pHB);
	
	if (HashFind(pHB,key) != NULL)
	{
		return 0;
	}
	int index = key % pHB->capacity;

	Node *first = pHB->array[index];
	Node *newNode = (Node*)malloc(sizeof(Node));

	newNode->key = key;
	newNode->next = NULL;

	//ͷ��
	newNode->next = first;
	pHB->array[index] = newNode;  //���²���Ľ���ַ��Ϊԭ�������λ�ý��ĵ�ַ
	pHB->size++;
	return 1;
}


//ɾ������
int HashBucketRemove(HashBucket *pHB,KeyType key)
{
	if (HashFind(pHB, key) == NULL)
	{
		return 0;
	}
	Node *pre = NULL;
	int index = key % pHB->capacity;
	for (Node *cur = pHB->array[index];cur != NULL;cur = cur->next)
	{	
		if (cur->key == key)
		{
			//ɾ��
			if (pre == NULL)
			{
				//���Ҫɾ���Ľ���ǵ�һ�����
				pHB->array[index] = cur->next;
			}
			else
			{
				pre->next = cur->next;
			}
			free(cur);
			pHB->size--;
			return 0;
		}
		pre = cur;
	}
	return -1;
}

void HashBucketPrint(HashBucket *pHB)
{
	Node *pre = NULL;
	int index = 0;
	for (int i = 0;i<pHB->capacity;i++)
	{
		if (pHB->array[i] != NULL)
		{
			for (Node *cur = pHB->array[i]; cur != NULL;cur = pre)
			{
				printf("%d --> %p --> %d\t",cur->key%pHB->capacity,cur,cur->key);
				printf("\n");
				pre = cur->next;
			}
		}
	}
}

void HashBucketTest()
{
	HashBucket hb;
	HashBucketInit(&hb,11);


	printf("%s\n", HashInsert(&hb, 11)==1 ? "����ɹ�":"����ʧ��");
	printf("%s\n", HashInsert(&hb, 13)==1 ? "����ɹ�":"����ʧ��");
	printf("%s\n", HashInsert(&hb, 12)==1 ? "����ɹ�":"����ʧ��");
	printf("%s\n", HashInsert(&hb, 22)==1 ? "����ɹ�":"����ʧ��");
	printf("%s\n", HashInsert(&hb, 23)==1 ? "����ɹ�":"����ʧ��");
	printf("%s\n", HashInsert(&hb, 16)==1 ? "����ɹ�":"����ʧ��");
	printf("%s\n", HashInsert(&hb, 19)==1 ? "����ɹ�":"����ʧ��");

	printf("%s\n", HashBucketRemove(&hb, 19) == 0 ? "ɾ���ɹ�" : "ɾ��ʧ��");

	HashBucketPrint(&hb);
}