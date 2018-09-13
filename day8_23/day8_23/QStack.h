#pragma once

#include "Queue.h"
#include <stdio.h>
/*
����-3
������������ʵ��һ��ջ

Push�����ǿն�������루����������ж��ǿգ�ѡ��һ�����룩

Pop���ӷǿն����� move  size - 1 ��Ԫ�ص� �ն����У�pop ʣ�µ�һ��

Top: �ӷǿն����� move  size - 1 ��Ԫ�ص� �ն����У�����ʣ�µ�һ����ֵ��
	 ��ʣ�µ�һ��Ҳ������һ��������
*/

typedef struct QStack
{
	Queue queue1;
	Queue queue2;
}QStack;



void QStackInit(QStack *pQS)
{
	QueueInit(&(pQS->queue1));
	QueueInit(&(pQS->queue2));
}

void QStackDestory(QStack *pQS)
{
	QueueDestroy(&(pQS->queue1));
	QueueDestroy(&(pQS->queue2));
}

void QStackPush(QStack *pQS,QDataType data)
{
	Queue *pNotEmpty = &(pQS->queue2);

	if (QueueEmpty(pNotEmpty))		    // ������ж�Ϊ�գ���Ϊ�յľͼ���Ϊ����һ���ͽ�����һ�еĲ�����ж�
	{
		pNotEmpty = &(pQS->queue1);		//������ж���Ϊ�գ���ֱ�ӽ�����һ�еĲ�����ж�
	}
	QueuePush(pNotEmpty,data);
}

void QStackPop(QStack *pQS)
{
	Queue *pEmpty = &(pQS->queue1);
	Queue *pNotEmpty = &(pQS->queue2);
	if (QueueEmpty(pNotEmpty))		 //������ж��ǿգ�������ж��գ��򲻿յľ��Ƕ���һ
	{
		pEmpty = &(pQS->queue2);
		pNotEmpty = &(pQS->queue1);
	}
	
	while (QueueSize(pNotEmpty) > 1)
	{
		QDataType data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty,data);
	}

	QueuePop(pNotEmpty);
}

QDataType QStackTop(QStack *pQS)
{
	QDataType data;
	QDataType r;
	Queue *pEmpty = &(pQS->queue1);
	Queue *pNotEmpty = &(pQS->queue2);
	if (QueueEmpty(pNotEmpty))		 //������ж��ǿգ�������ж��գ��򲻿յľ��Ƕ���һ
	{
		pEmpty = &(pQS->queue2);
		pNotEmpty = &(pQS->queue1);
	}

	while (QueueSize(pNotEmpty) > 1)
	{
		data = QueueFront(pNotEmpty);
		QueuePop(pNotEmpty);
		QueuePush(pEmpty,data);
	}

	r = QueueFront(pNotEmpty);
	QueuePop(pNotEmpty);
	QueuePush(pEmpty,r);

	return r;
}


void TestQStack()
{	
	int i = 0;
	QStack qstack;
	QStackInit(&qstack);
	
	for (i=0;i<9;i++)
	{
		QStackPush(&qstack,i);
		
		printf("ѹ���%d ,ѹ�� %d\n",i+1,QStackTop(&qstack));
		printf("Top = %d ",QStackTop(&qstack));
		//QStackPop(&qstack);
	}

	
}