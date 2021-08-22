//链式队列
#include<stdio.h>
#include<stdlib.h>
//链式表定义
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;
typedef struct LinkQueue{
 LinkNode *front,*rear;
}LinkQueue;
/*
//带头结点
//初始化队列
void InitQueue(LinkQueue &Q){
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
}
//入队
void EnQueue(LinkQueue &Q,int x){
	LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data=x;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}
//出队
bool DeQueue(LinkQueue &Q,int &x){
	if(Q.front==Q.rear)
		return false;
	LinkNode *p=Q.front->next;
	x = p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	free(p);
	return true;
}
*/
//不带头结点
void InitQueue(LinkQueue &Q){
	Q.front=NULL;
	Q.rear=NULL;
}
//入队
void EnQueue(LinkQueue &Q,int x){
	LinkNode *p=(LinkNode*)malloc(sizeof(LinkNode));
	p->data=x;
	p->next=NULL;
	if(Q.front==NULL){
		Q.front=p;
		Q.rear=p;
	}else{
		Q.rear->next=p;
		Q.rear=p;
	}
}
//出队
bool DeQueue(LinkQueue &Q,int &x){
	if(Q.front==NULL)
		return false;
	LinkNode *p=Q.front;
	x=p->data;
	Q.front=p->next;
	if(Q.rear==p){
		Q.front=NULL;
		Q.rear=NULL;
	}
	free(p);
	return true;
}
//入口
int mian(){
	LinkQueue Q;
	return 0;
}
