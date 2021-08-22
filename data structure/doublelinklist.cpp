//˫����(����ͷ���)
/*
	˫����ı���ͨ��whileѭ�����в�����ֻ��
	˳�������
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct DNode{
	int data;
	struct DNode *prior, *next;
}DNode,*DLinkList;
//˫����ĳ�ʼ��
bool InitDLinkList(DLinkList &L){
	L=(DNode*)malloc(sizeof(DNode));
	if(L==NULL)
		return false;
	L->prior=NULL;
	L->next=NULL;
	return true;
}
//˫�������Ԫ����P�������s
bool InsertNextDNode(DNode *p,DNode *s){
	if(p==NULL||s==NULL)
		return false;
	s->next = p->next;
	if(p->next!=NULL)
		p->next->prior=s;
	s->prior = p;
	p->next = s;
	return true;
}
//˫������ָ��λ�ò����½��
bool InsertDNode(DLinkList &L,int i,int e){
	if(i<1)
		return false;
	DNode *p;
	int j = 0;
	p = L;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL)
		return false;
	DNode *q = (DNode*)malloc(sizeof(DNode));
	q->data=e;
	q->next=p->next;
	if(p->next!=NULL)
		p->next->prior=q;
	q->prior=p;
	p->next=q;
	return true;

}
//˫����ɾ��p����Ľ��
bool DeleteNextDNode(DNode *p){
	if(p==NULL)
		return false;
	DNode *q = p->next;
	if(q==NULL)
		return false;
	if(q->next!=NULL)
		q->next->prior = p;
	p->next=q->next;
	free(q);
	return true;
}
//ɾ��˫����
void DeleteLinkList(DLinkList &L){
	while(L->next!=NULL){
		DeleteNextDNode(L);
	}
	free(L);
	L = NULL;
}
void main(){
	DLinkList L;
	InitDLinkList(L);
	return;
}