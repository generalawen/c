//循环链表
/*
	1.判断循环链表是否为末结点通过p->next==L;
	2.判断头结点为p==L;
	3.对循环链表的插入或删除结点不需要判断该节点的p->next是否为空；

*/
#include<stdio.h>
#include<stdlib.h>

//循环单链表
typedef struct LNode{
int data;
struct LNode *next;
}LNode,*LinkList;
//带头结点的初始化链表
bool InitLinlList(LinkList &L){
	L=(LinkList)malloc(sizeof(LNode));
	if(L==NULL)
		return false;
	L->next=L;
	return  true;
}
//判断单链表是否为空
bool EmptyList(LinkList L){
	if(L->next==L)
		return true;
	else
		return false;
}
//判断结点是否为末尾结点(如果判断是否为头结点，比较p==L)
bool LastLNode(LinkList L,LNode *p){

	if(p->next==L)
		return true;
	else
		return false;

}
//循环双链表大体与单链表相同，只是多处理一个结构体成员prior;

