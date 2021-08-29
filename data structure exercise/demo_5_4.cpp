#include<bits/stdc++.h>
#include"data structure/BiTree.cpp"//树
#include"data structure/Sequential stack.cpp"//栈
#include"data structure/Staticqueue.cpp"//队列
//142 8
//递归
int DoubleNode(BiTree T){
    if(T==0)
        return 0;
    else if(T->lchild&&T->rchild){
        return DoubleNode(T->lchild)+DoubleNode(T->rchild)+1;
    else
        return DoubleNode(T->lchild)+DoubleNode(T->rchild);
    }
}
//非递归
int DoubleNode1(Bitree T){
    SqQueue Q;
    InitSqQueue(Q);
    int count;
    BiTNode *p;
    if(!=T)
        return 0;
    EnQueue(Q,T);
    while(!=IsEmpty(Q)){
        DeQueue(Q,p);
        if (p->lchild!=NULL&&p->rchild!=NULL)
        {
            count++;
        }
        if(p->lchild){
        EnQueue(Q,p->lchild);}
        if(p->rchild){ 
            EnQueue(Q,p->rchild);
        }
}
    return count;
}
//141 9题
void Swap(BiTree T){
    if(T){
        Swap(T->lchild);
        Swap(T->rchild);
        BiTNode *p;
        p = T->lchild;
        T->lchild=T->rchild;
        T->rchild=p;
    }
}
//141 10题
int i = 1;
int PreNode(BiTree b,int k){
    if(b==NULL)
        return '-1';
    if(i==k)
        return b->data;
    i++;
    int ch = PreNode(b->lchild,k);
    if(ch!='#'){
        return ch;
    }
    ch = PreNode(b->rchild,k);
    return ch;
}

