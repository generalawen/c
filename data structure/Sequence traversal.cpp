//�������Ĳ������
#include<stdio.h>
#include<stdlib.h>
//��������㣨��ʽ�洢��
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//������ʽ�洢
typedef struct LinkNode{
	BiTNode *data;
	struct LinkNode *next;
}LinkNode;
typedef struct {
	LinkNode *front,*rear;
}LinkQueue;
bool InitQueue(LinkQueue &q){

}
bool EnQueue(LinkQueue &q,BiTree T){

}
bool DeQueue(LinkQueue &q,BiTree T){

}
bool IsEmpty(LinkQueue q){

}
void visit(BiTree p){
	
}
//�������
void LevelOrder(BiTree T){
	LinkQueue Q;
	InitQueue(Q);  //��ʼ����������
	BiTree p;
	EnQueue(Q,T); //���ڵ����
	while(!IsEmpty(Q)){
		DeQueue(Q,p);//��ͷ������
		visit(p);
		if(p->lchild!=NULL){
			EnQueue(Q,p->lchild);
		}
		if(p->rchild!=NULL){
			EnQueue(Q,p->rchild);
		}
	}
}
