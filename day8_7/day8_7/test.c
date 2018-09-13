
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef char DataType;
#define MaxSize 100
#include "LinkBiTree.h"


int main()
{
	int BiTree T,root;
	InitBitTree(&T);  
	printf("����������������������д�������������#����ʾ������:\n");
	CreateBitTree(&T);
	printf("���������������У�\n"); 
	printf("�ݹ飺\t");
	PreOrderTraverse(T);
	printf("\n");	
	printf("�ǵݹ飺\n");
	PreOrderTraverse2(T);
	printf("\n");
	printf("���������������У�\n");
	printf("�ݹ飺\t");	
	InOrderTraverse(T);
	printf("\n");
	printf("�ǵݹ飺");
	InOrderTraverse2(T);	
	printf("\n");
	printf("�������ĺ������У�\n");
	printf("�ݹ飺\t");
	PostOrderTraverse(T);
	printf("\n");
	printf("�ǵݹ飺\n");
	PostOrderTraverse2(T);
	printf("\n");
	printf("��������Ƕ�׵��ַ�����������:\n");
	createBitTree2(&root,"(a(b(c,d),e(f(,g),h(i))))");
	printf("���������������У�\n");
 	PreOrderTraverse(root);	
	printf("\n");
	DestroyBitTree(&T); 
	DestroyBitTree(&root); 
}

/*�������������ַ����еݹ鴴��������*/
void CreateBitTree(BiTree *T)
{
	DataType ch;
	scanf("%c",&ch);
	if(ch=='#')
		*T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BitNode));
		if(!(*T))
			exit(-1);
		(*T)->data=ch;
		CreateBitTree(&((*T)->lchild));
		CreateBitTree(&((*T)->rchild));
	 } 
 } 

/*����ݹ�*/
void PreOrderTraverse(BiTree *T)
{
	if(T!=null)
	{
		printf("%c",T->data);
		PreOrderTraverse(T->lchild);
		PerOrderTraverse(T->rchild);
	}
}
/*����ݹ�*/ 

void InOrderTraverse(BiTree *T)
{
	if(T!=null)
	{
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
}

/*����ݹ�*/ 
void PostOrderTraverse(BiTree *T)
{
	if(T!=null)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
	}
}

/*����ǵݹ�*/ 
void PreOrderTraverse2(BiTree *T)
{	
	BiTree stack[MaxSize];
	int top;
	BitNode *p;
	top=0;
	p=T;
	
	while(T !=NULL||top>0){
	
		while(T!=null)
		{
		printf("%c",p->data);
		stack[top++]=p;
		p=p->lchild;
		}
		if(top){
			p=stack[--top];
			p=p->rchild;
		}
}
}

/*����ǵݹ�*/

void InOrderTraverse2(BiTree *T)
{	
	BiTree stack[MaxSize];
	int top;
	BitNode *p;
	top=0;
	p=T;
	
	while(T !=NULL||top>0){
	
		while(T!=null)
		{

		stack[top++]=p;
		p=p->lchild;
		}
		if(top){
			p=stack[--top];
			printf("%c",p->data);	
			p=p->rchild;
		}
}
}

/*����ǵݹ�*/
void PostOrderTraverse2(BiTree *T)
{	
	BiTree stack[MaxSize];
	int top;
	BitNode *p *q;
	top=0;
	p=T;q=NULL
	
	while(p !=NULL||top>0){
	
		while(p!=null)
		{

		stack[top++]=p;
		p=p->lchild;
		}
		if(top>0){
			p=stack[top-1];
			if(p->rchild==NULL||p->rchild==q){
				
			printf("%c",p->data);
			q=p;
			p=NULL;
			top--;	
			}
			else
			p=p->rchild;
		}
	}
}

