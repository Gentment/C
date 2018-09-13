#ifndef  __LinkBiTree__H__
#define  __LinkBiTree__H__


typedef struct BiTree {
	int data;
	struct BiTree *T,*root;
}BiTree;

void InitBitTree(&T);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);               
void PreOrderTraverse2(BiTree T);
void InOrderTraverse2(BiTree T);
void PostOrderTraverse2(BiTree T);
void CreateBitTree2(BiTree *T,char str[]);


#endif  //__LinkBiTree__H__