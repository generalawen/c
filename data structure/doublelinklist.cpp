//双链表(都带头结点)
/*
	双链表的遍历通过while循环进行操作，只能
	顺序遍历。
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct DNode{
	int data;
	struct DNode *prior, *next;
}DNode,*DLinkList;
//双链表的初始化
bool InitDLinkList(DLinkList &L){
	L=(DNode*)malloc(sizeof(DNode));
	if(L==NULL)
		return false;
	L->prior=NULL;
	L->next=NULL;
	return true;
}
//双链表插入元素在P结点后插入s
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
//双链表在指定位置插入新结点
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
//双链表删除p结点后的结点
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
//删除双链表
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