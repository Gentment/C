#include "SeqList.h"

void SeqListInit(SeqList *Seq)
{
	Seq->size = 0;
}

void SeqListInsert(SeqList *Seq,int pos,DataType data)
{
	int i = 0;
	assert(Seq != NULL);
	assert(pos <= Seq->size && pos>=0);
	if (Seq->size == MAX_SIZE)
	{
		printf("满了\n");
		return;
	}
	
	for (i=Seq->size; i>=pos; i--)
	{
		Seq->arr[i+1] = Seq->arr[i];
	}

	Seq->arr[pos] = data;
	Seq->size++;
}

void SeqListDelete(SeqList *Seq,DataType pos)
{
	int i = 0;
	assert(Seq != NULL);
	assert(pos <= Seq->size && pos>=0);
	if (Seq->size == 0)
	{
		printf("空的\n");
		return;
	}

	for (i=pos;i<Seq->size; i++)
	{
		Seq->arr[i] = Seq->arr[i+1];
	}
	Seq->size--;
}

int SeqListFind(SeqList *Seq,DataType data)
{
	int i = 0;
	assert(Seq != NULL);

	if (Seq->size == 0)
	{
		printf("空的\n");
		return 0;
	}

	for (i=0;i<Seq->size;i++)
	{
		if (Seq->arr[i] == data)
		{
			return i;
		}
	}
	return -1;
}


void SeqListModify(SeqList *Seq,DataType pos,DataType data)
{
	int i = 0;
	assert(Seq != NULL);
	assert(pos <= Seq->size && pos>=0);
	if (Seq->size == 0)
	{
		printf("空的\n");
		return;
	}
	Seq->arr[i] = data;
	/*for (i=0;i<Seq->size;i++)
	{
		if (i == pos)
		{
			Seq->arr[i] = data;
		}
	}*/

}

void print(SeqList *Seq)
{
	int i = 0;
	for (i=0;i<Seq->size;i++)
	{
		printf("%d ",Seq->arr[i]);
	}
	printf("\n");
}