#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//����������ĳ�Ա  ��ʵ���ǽ��
//link p;  p����һ�����
typedef struct Link {
	int data;			 //������
	struct Link *next;   //ָ����
}link;					 //link Ϊ����ṹ��ı���

//��ʼ������
link *initLink() {
	link *p = (link*)malloc(sizeof(link));  //����һ��ͷ���
	//��̬�����ڴ�
	link *temp = p;  //����һ��ָ��ָ��ͷ��㣬���ڱ�������
	//14���д�����һ��ͷ��� ����һ��ָ��  ��Ϊp��ָ����� tempҲ��ָ�����
	//��������
	int i = 0;
	for (i = 1; i < 5; i++) 
	{
		link *a = (link*)malloc(sizeof(link));   //����һ���µĽ��
												
		a->data = i;							//��������ĳ�Ա���и�ֵ	
		a->next = NULL;							//�������ָ��ָ��NULL ��ʾ������־
		temp->next = a;							//temp������������������
		temp = temp->next;
	}
	return p;
}

//����Ļ�������
//��������в���
link * insertElem(link *p, int elem, int add) {
	link *temp = p;								 //������ʱ���������������
	int i = 0;										 //���ҵ�Ҫ�����λ�õ���һ�����
	for (i = 1; i < add; i++) {
		if (temp == NULL) {
			printf("����λ����Ч\n"); 
			return p;							 //�����β�Ϊ���������׵�ַ ����׵�ַָ��Ϊ�� ˵����һ��������
												 //����һ��������� ��i���б�����ʱ��δ����add��λ�þ��Ѿ�������
		}
		temp = temp->next;						 //���б��� tempһ����������
	}
	//����������c
	//�����е����д洢��ʽ�������Խ��ķ�ʽ
	link *c = (link*)malloc(sizeof(link));   //
	c->data = elem;								 //������
												 //�������в�����
												//�����ǲ������һ������ ��ͨ���½ڵ����Ӻ������ Ȼ��ԭ���Ľ�������½ڵ�
	c->next = temp->next; 
	temp->next = c;
	return p;
}

link *delElem(link *p, int add) {
	link *temp = p;  //����һ����ʱ�����������
	//�ж�ɾ��λ���Ƿ���ȷ
	for (int i = 1; i < add; i++)
	{
		if (temp == NULL) {
			printf("ɾ��λ���쳣\n");
			return p;
		}
		temp = temp->next;
	}
	link *c = temp->next;   //���ﶨ�������ǳ�����
	//��ʱ��cָ��ɾȥ�Ľ��
	//Ҫɾ��ֱ�ӽ��串��
	temp->next = c->next;    //�����ok
	free(c);   //�ͷ��ڴ�
	return p;
}

int selectElem(link *p, int elem)
{
	link *temp = p;
	int i = 1;
	while (temp->next) {
		temp = temp->next;
		if (temp->data == elem)
			return i;
	}

	return -1;
}
//���и���
link *amendElem(link *p, int add, int newElem)
{
	link *temp = p;   //����һ����ʱ�����������
	for (int i = 1; i < add; i++)
	{
		if (temp == NULL) {
			printf("����λ����Ч\n");
			return p;
		}
		temp = temp->next;
	}
	//��ʱ��tempָ�����λ�õ�ǰһ����
	link *amend = temp->next;   //����һ����ʱ���ָ����ĵ�λ��
	amend->data = newElem;    //�������ݳɹ�

	return p;
}

//�������
void display(link *p) {
	link *temp = p;  //����һ����ʱ�����������
	//ֻҪtemp->next��ָ��NULL�����
	while (temp->next) {
		temp = temp->next;
		printf("%d ", temp->data);
	}
	printf("\n");
}


//���԰���
int main() {
	//��ʼ������
	printf("\n------��ʼ������----------\n");
	link *p = initLink();
	display(p);

	printf("�ڵ�4��λ�ò���Ԫ��5��\n");
	p = insertElem(p, 5, 4);
	display(p);

	printf("ɾ��Ԫ��3��\n");
	p = delElem(p, 3);
	display(p);

	printf("����Ԫ��2��λ��Ϊ��\n");
	int address = selectElem(p, 2);
	if (address == -1) 
		printf("û�и�Ԫ��\n");
	else printf("Ԫ��2��λ��Ϊ��%d\n", address);

	printf("���ĵ�3��λ�õ���Ϊ7��\n");
	p = amendElem(p, 3, 7);
	display(p);

	return 0;

}