#pragma once
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef enum
{
	EXIST,
	DELETE,
	EMPTY
}State;

typedef int KeyType;
typedef int (*HashFunc)(KeyType key,int capacity);  //定义函数指针，参数类型为KeyType

typedef struct HashElem
{
	KeyType key;
	State state;
}HashElem;

typedef struct HashTable
{
	HashElem *table;   
	int size;			//数据个数
	int capacity;					//容量
	HashFunc hashfunc; 	//哈希函数
}HashTable;				

//初始化/销毁
void HashInit(HashTable *pH,HashFunc hashfunc,int capacity)
{
	pH->table = (HashElem*)malloc(sizeof(HashElem)*capacity);
	assert(pH->table);

	pH->size = 0;
	pH->hashfunc = hashfunc;
	pH->capacity = capacity;
	for ( int i = 0; i < capacity; i++)
	{
		pH->table[i].state = EMPTY;
	}
}

void HashDestroy(HashTable *pH)
{
	free(pH->table);
}

//查找
int HashFind(HashTable *pH,KeyType  key)
{
	int index = pH->hashfunc(key,pH->capacity);
	while (pH->table[index].state != EMPTY)
	{
		if (pH->table[index].key == key)
		{
			return index;
		}
		index = (index + 1) % pH->capacity;
	}

	return -1;
}

int HashInsert(HashTable *pH, KeyType key);

int IsExpand(HashTable *pH)
{
	if (pH->size <=  pH->capacity * 0.8)
	{
		return 0;
	}
#if 0  // 数据搬移麻烦


	int newCapacity = pH->capacity * 2;
	HashElem *newTable = (HashElem *)malloc(sizeof(HashElem));
	assert(newTable);

	for (int i = 0; i < newCapacity; i++)
	{
		newTable[i].state = EMPTY;
	}

	free(pH->table);
	pH->table = newTable;
	pH->capacity = newCapacity;

#endif // 0
	
	HashTable newHT;
	HashInit(&newHT,pH->hashfunc, pH->capacity * 2);
	for (int i = 0; i < pH->capacity * 2; i++)
	{
		if (pH->table[i].state == EXIST)
		{
			HashInsert(&newHT, pH->table[i].key);
		}
	}

	free(pH->table);   //释放原来的table
	pH->table = newHT.table; //将新的table地址赋给
	pH->capacity = newHT.capacity;

	return 1;
}

int HashInsert(HashTable *pH,KeyType key)
{
	IsExpand(pH);

	int  index = pH->hashfunc(key, pH->capacity);

	while (1)
	{
		if (pH->table[index].key == key && pH->table[index].state == EXIST)
		{
			return -1;
		}

		if (pH->table[index].state != EXIST)
		{
			pH->table[index].key = key;
			pH->table[index].state = EXIST;
			pH->size++;
			return 1;
		}

		index = (index + 1) % pH->capacity;
	}
}

int HashRemove(HashTable *pH,KeyType key)
{
	int index = pH->hashfunc(key,pH->capacity);
	while (pH->table[index].state != EMPTY)
	{
		if (pH->table[index].key == key && pH->table[index].state == EXIST)
		{
			pH->table[index].state = DELETE;
			return 1;
		}
		index = (index + 1) % pH->capacity;
	}
	return -1;
}


void PrintKeyValue(HashTable *pH)
{
	printf("index --> value -->state\n");
	for (int i = 0; i < pH->size; i++)
	{
		int index = pH->hashfunc(pH->table[i].key,pH->capacity);
		printf("%d --> %d  -->%d\n",index,pH->table[index].key,pH->table[index].state);
	}
}

int mod(KeyType key, int capacity)
{
	return key % capacity;
}

void TestHash()
{
	
	HashTable ht;
	HashInit(&ht,mod,8);  // 插入的下标索引， 插入8个数，

	HashInsert(&ht,0);
	HashInsert(&ht,1);
	HashInsert(&ht,2);
	HashInsert(&ht,3);
	HashInsert(&ht,4);
	PrintKeyValue(&ht);

	//int ret = HashFind(&ht,5);
	//printf("%d\n", ret);


	//HashRemove(&ht, 5);
	//printf(HashRemove(&ht, 5)>0 ? "成功\n":"失败\n");
	HashDestroy(&ht);
}