#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_SIZE (100)

typedef int DataType;

typedef struct SeqList{
	DataType arr[MAX_SIZE];
	int size;
}SeqList;

void SeqListInit(SeqList *Seq);

void SeqListInsert(SeqList *Seq,DataType,DataType);

void SeqListDelete(SeqList *Seq,DataType);

int SeqListFind(SeqList *Seq,DataType);

void SeqListModify(SeqList *Seq,DataType,DataType);

void print(SeqList *Seq);