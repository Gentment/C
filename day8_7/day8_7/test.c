
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
	printf("根据输入二叉树的先序序列创建二叉树（‘#’表示结束）:\n");
	CreateBitTree(&T);
	printf("二叉树的先序序列：\n"); 
	printf("递归：\t");
	PreOrderTraverse(T);
	printf("\n");	
	printf("非递归：\n");
	PreOrderTraverse2(T);
	printf("\n");
	printf("二叉树的中序序列：\n");
	printf("递归：\t");	
	InOrderTraverse(T);
	printf("\n");
	printf("非递归：");
	InOrderTraverse2(T);	
	printf("\n");
	printf("二叉树的后序序列：\n");
	printf("递归：\t");
	PostOrderTraverse(T);
	printf("\n");
	printf("非递归：\n");
	PostOrderTraverse2(T);
	printf("\n");
	printf("根据括号嵌套的字符建立二叉树:\n");
	createBitTree2(&root,"(a(b(c,d),e(f(,g),h(i))))");
	printf("二叉树的先序序列：\n");
 	PreOrderTraverse(root);	
	printf("\n");
	DestroyBitTree(&T); 
	DestroyBitTree(&root); 
}

/*按照先序输入字符序列递归创建二叉树*/
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

/*先序递归*/
void PreOrderTraverse(BiTree *T)
{
	if(T!=null)
	{
		printf("%c",T->data);
		PreOrderTraverse(T->lchild);
		PerOrderTraverse(T->rchild);
	}
}
/*中序递归*/ 

void InOrderTraverse(BiTree *T)
{
	if(T!=null)
	{
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
}

/*后序递归*/ 
void PostOrderTraverse(BiTree *T)
{
	if(T!=null)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
	}
}

/*先序非递归*/ 
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

/*中序非递归*/

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

/*后序非递归*/
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

