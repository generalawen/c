//�ڶ������Ա��ܽ�

/*
	�ܽ᣺1.˳��������
			1���߼��ṹ���������Խṹ
			2���洢�ṹ��˳���֧�������ȡ���洢�ܶȸ�
						 ��Ƭ�����ռ���䲻���㣬�ı�����
						 Ҳ������
						 ������ɢ��С�ռ���䷽�㣬�ı�����
						 ���������ȡ����ȡ�ܶȵ͡�
			3������������initlist(&L)[��ʼ����] destroylist(&L)[���ٲ���] 
				     listlnser(&L,i,e)[�������] ListDelete(&L,i,&e)[ɾ������]
				     locateelem(L,e)[��ֵ����] GetElem(L,i)[��λ����]
*/
//˳���̬�����ڴ�
#define MAXSIZE 100
#include<stdio.h>
typedef struct{
int *data;
int lenght;
};
//˳���̬�����ڴ�
typedef struct sqlist{
int data[MAXSIZE];
int lenght;
}SqList;

//������Ķ���
typedef struct{
	int data;
	Node *next;
}Node,*LinkList;
//˫����Ķ���
typedef struct DNode
{
	int data;
	Node *next;
	Node  *prior;
}DNode,*DLinkList;
int main(){
	printf("�ܽ�\n");
	return 0;
}