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
