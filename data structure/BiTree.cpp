//二叉树
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

//顺序存储(完全二叉树)
/*struct TreeNode{
int value;
bool isEmpty;
}*/
//链式存储
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
bool InputRootNode(BiTree &root,int x){
	if(root==NULL){
		root = (BiTree)malloc(sizeof(BiTNode));
		root->data=x;
		root->lchild=NULL;
		root->rchild=NULL;
		
	}else
		return false;
	return true;
}
bool InputNode(BiTree &root,int x){
	BiTNode *p=(BiTree)malloc(sizeof(BiTNode));
	p->data=x;
	p->lchild=NULL;
	p->rchild=NULL;
	if(root->lchild==NULL)
		root->lchild = p;
	else if(root->rchild==NULL)
		root->rchild = p;
	else
		return false;
	return true;
}
//访问结点
void visit(BiTree T){
	 printf("%d\n",T->data);
	 return;
}
//先序遍历
void Preorder(BiTree T){
	if(T!=NULL){
		visit(T);
		Preorder(T->lchild);
		Preorder(T->rchild);
	}		
	return;
}
//中序遍历
void Middleorder(BiTree T){
	if(T!=NULL){
		Middleorder(T->lchild);
		visit(T);
		Middleorder(T->rchild);
	}
}
//后序遍历
void Postorder(BiTree T){
	if(T!=NULL){
		Postorder(T->lchild);
		Postorder(T->rchild);
		visit(T);
	}
}
int main(){
	BiTree root = NULL;
	InputRootNode(root,2);
	BiTNode *p = root;
	InputNode(p,4);
	InputNode(p,3);
	return 0;
}