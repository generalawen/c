//二叉树的层序遍历
#include<stdio.h>
#include<stdlib.h>
//二叉树结点（链式存储）
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//队列链式存储
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
//层序遍历
void LevelOrder(BiTree T){
	LinkQueue Q;
	InitQueue(Q);  //初始化辅助队列
	BiTree p;
	EnQueue(Q,T); //根节点入队
	while(!IsEmpty(Q)){
		DeQueue(Q,p);//对头结点出队
		visit(p);
		if(p->lchild!=NULL){
			EnQueue(Q,p->lchild);
		}
		if(p->rchild!=NULL){
			EnQueue(Q,p->rchild);
		}
	}
}
