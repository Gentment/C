#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Heap{
	int array[MAX_SIZE];
	int size;
}Heap;


void HeapInit(Heap *pH,int arr[],int size)
{
	for (int i = 0; i < pH->size; i++)
	{
		pH->array[i] = arr[i];
	}
	pH->size = size;
}

void HeaoAdjustDown(Heap *pH,int root)
{
	int parent = root;

	while (1)
	{
		//�����Ӵ���ʱ
		int left = parent * 2 + 1;
		//�ж������Ƿ�Խ��
		if (left >= pH->size)
		{
			return;
		}

		//��һ�����Һ���ʱ
		int MaxChild = left;
		if (parent*2+2<pH->size && pH->array[parent*2+2]>MaxChild)
		{
			MaxChild = parent * 2 + 2;
		}

		if (pH->array[parent]>pH->array[MaxChild])
		{
			return;
		}

		int temp = pH->array[parent];
		pH->array[parent] = pH->array[MaxChild];
		pH->array[MaxChild] = temp;

		parent = MaxChild;
	}
}

void Swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void ArrayAdjustDown(int array[],int size,int root)
{
	int parent = root;
	while (1)
	{
		int left = parent * 2 + 1;
		if (left>=size)
		{
			return;
		}
		int MaxChild = left;
		if (parent*2+2 <size && array[parent*2+2] > array[MaxChild])
		{
			MaxChild = parent * 2 + 2;
		}

		if (array[parent] > array[MaxChild])
		{
			return;
		}

		Swap(array + parent,array+MaxChild);

		parent = MaxChild;
	}
}
void  HeapAdjustUp(Heap *pH,int child)
{
	int parent;
	while (child > 0)
	{
		parent = (child > 0);
		if (pH->array[parent] >= pH->array[child])
		{
			return;
		}
		
		int temp = pH->array[parent];
		pH->array[parent] = pH->array[child];
		pH->array[child] = temp;

		child = parent;
	}
}
void HeapMake(Heap *pH)
{
	for (int i = (pH->size-2)/2; i > 0; i--)
	{
		HeaoAdjustDown(pH,i);
	}
}

//����
void HeapPush(Heap *pH,int data)
{
	assert(pH->size < MAX_SIZE);
	pH->array[pH->size++] = data;
	HeapAdjustUp(pH, pH->size - 1);
}
//ɾ��
void HeapPop(Heap *pH)
{
	pH->array[0] = pH->array[pH->size - 1];
	pH->size--;

	HeapAdjustUp(pH, 0);
}

void HeapTop(Heap *pH)
{
	return pH->array[0];
}

void HeapSort(int array[],int size)
{
	//�������
	for ( int i = (size-2)/2; i > 0;  i--)
	{
		ArrayAdjustDown(array,size,i);
	}
	//��ʼ����
	for (int j = 0; j < size; j++)
	{
		int s = size - 1 - j;
		Swap(array, array + s);
		ArrayAdjustDown(array, size - 1 - j, 0);
	}
}
//100�ڸ������ҳ���С��ǰK��������������top K���⣩
int *TopK(int array[],int size,int k)
{
	int *heapArray = (int *)malloc(k * sizeof(int));
	assert(heapArray);
	
	//��ǰK����
	for (int i = 0; i < k; i++)
	{
		heapArray[i] = array[i];
	}
	//������(���)
	for ( int j = (k-2)/2; j >= 0; j--)
	{
		ArrayAdjustDown(heapArray,k,j);
	}

	//����K����������Ԫ�رȽ�
	for (int i = k; i < size; i++)
	{
		if (array[i] >= heapArray[0])
		{
			continue;
		}

		heapArray[0] = array[i];     //�滻������СԪ��
		ArrayAdjustDown(heapArray,k,0);
	}
	return heapArray;
}
void TestHeap()
{
#if 0
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	int size = sizeof(array) / sizeof(int);

	Heap heap;
	HeapInit(&heap, array, size);
	HeapMake(&heap);

	printf("�������\n");
#endif // 0

	int array[] = { 1,4,9,4,5,2,7,8,5,3,6,6,2,3 };
	int sz = sizeof(array) / sizeof(array[0]);

	int *ret = TopK(array, sz, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ",ret[i]);
	}
}