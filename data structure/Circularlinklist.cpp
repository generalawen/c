//ѭ������
/*
	1.�ж�ѭ�������Ƿ�Ϊĩ���ͨ��p->next==L;
	2.�ж�ͷ���Ϊp==L;
	3.��ѭ������Ĳ����ɾ����㲻��Ҫ�жϸýڵ��p->next�Ƿ�Ϊ�գ�

*/
#include<stdio.h>
#include<stdlib.h>

//ѭ��������
typedef struct LNode{
int data;
struct LNode *next;
}LNode,*LinkList;
//��ͷ���ĳ�ʼ������
bool InitLinlList(LinkList &L){
	L=(LinkList)malloc(sizeof(LNode));
	if(L==NULL)
		return false;
	L->next=L;
	return  true;
}
//�жϵ������Ƿ�Ϊ��
bool EmptyList(LinkList L){
	if(L->next==L)
		return true;
	else
		return false;
}
//�жϽ���Ƿ�Ϊĩβ���(����ж��Ƿ�Ϊͷ��㣬�Ƚ�p==L)
bool LastLNode(LinkList L,LNode *p){

	if(p->next==L)
		return true;
	else
		return false;

}
//ѭ��˫��������뵥������ͬ��ֻ�Ƕദ��һ���ṹ���Աprior;

