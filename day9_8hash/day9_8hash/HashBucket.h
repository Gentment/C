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
	//需要先释放哈希桶 链表
	for (int i = 0; i < pHB->capacity; i++)
	{
		ListDestory(pHB->array[i]);
	}
	//释放哈希桶
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

//和开放地址不同的是，此时的插入不需要考虑负载因子
//插入成功返回0，失败返回-1
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

	//头插
	newNode->next = first;
	pHB->array[index] = newNode;  //将新插入的结点地址改为原来在这个位置结点的地址
	pHB->size++;
	return 1;
}


//删除操作
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
			//删除
			if (pre == NULL)
			{
				//如果要删除的结点是第一个结点
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


	printf("%s\n", HashInsert(&hb, 11)==1 ? "插入成功":"插入失败");
	printf("%s\n", HashInsert(&hb, 13)==1 ? "插入成功":"插入失败");
	printf("%s\n", HashInsert(&hb, 12)==1 ? "插入成功":"插入失败");
	printf("%s\n", HashInsert(&hb, 22)==1 ? "插入成功":"插入失败");
	printf("%s\n", HashInsert(&hb, 23)==1 ? "插入成功":"插入失败");
	printf("%s\n", HashInsert(&hb, 16)==1 ? "插入成功":"插入失败");
	printf("%s\n", HashInsert(&hb, 19)==1 ? "插入成功":"插入失败");

	printf("%s\n", HashBucketRemove(&hb, 19) == 0 ? "删除成功" : "删除失败");

	HashBucketPrint(&hb);
}