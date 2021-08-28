#include<bits/stdc++.h>
#include"data structure/BiTree.cpp"
#include"data structure/Staticqueue.cpp"
//141 5题
int Btdepth(BiTree T){
    if(T==NULL){
        return 0;
    }
    int front=-1,rear=-1;
    int last=0,level = 0;
    BiTree Q[MaxSize];
    Q[++rear] = T;
    BiTree p;
    while (front<rear)
    {  p = Q[++front];
        if(p->lchild)
            Q[++rear]=p->lchild;
        if(p->rchild)
            Q[++rear]=p->rchild;
        if(front==last){
            level++;
            last=rear;
        }
    }
    return level;
}
//141  6题
Bitree PreInCreat(int a[],int b[],int l1,int h1,int l2,int h2){
   BiTree root = (BiTNode*)malloc(sizeof(BiTNode));
    root->data=a[l1];
    int i;
    for (i = l2; b[i]!=root->data; i++);
    int llen=i-l2;
    int rlen=h2-i;
    if(llen){
        root->lchild=PreInCreat(a,b,l1+1,l1+llen,l2,l2+llen-1);}
        else{
            root->lchild=NULL;
        }
    if(rlen){
        root->rchild=PreInCreat(a,b,h1-rlen+1,h1,h2-rlen+1,h2);
    }
    else{
        root->rchild=NULL;
    }
    return root;

}
//141 7题
bool GoodTree(BiTree T){
    SqQueue Q;
    InitSqQueue(Q);
    BiTNode *p;
    if(!=T)
        return true;
    EnQueue(Q,T);
    while(!=IsEmpty(Q)){
        DeQueue(Q,p);
        if(p){
            EnQueue(Q,p->lchild);
            EnQueue(Q,p->rchild);
        }
        else{
            while(!IsEmpty(Q)){
                DeQueue(Q,p);
                if(p)
                    return false;
            }
        }
    }
    return true;
}
