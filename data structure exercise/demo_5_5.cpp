#include<bits/stdc++.h>
#include"data structure/BiTree.cpp"//树
#include"data structure/Staticqueue.cpp"
//141 11题
void DeleteNode(BiTree &b){
    if(b){
        DeleteNode(b->lchild);
        DeleteNode(b->rchild);
        free(b);
    }
}
void Sreach(BiTree b,int k){
    BiTree Q[];
    BiTNode *p;
    if(b){
        if(b->data==x){
            DeleteNode(b);
            exit(0);
        }
        InitSqQueue(Q);
        EnQueue(Q,b);
        while(!=IsEmpty(Q)){
            DeQueue(Q,p);
            if(p->lchild)
                if(p->lchild->data==k){
                    DeleteNode(p->lchild);
                    p->lchild=NULL;
                }
                else{
                    EnQueue(Q,p->lchild);
                }
            if(p->rchild){
                if(p->rchild->data==k){
                    DeleteNode(p->rchild);
                    p->rchild=NULL;
                }
                else{
                    EnQueue(p->rchild);
                }
            }

        }
    }

}

//141 12题
typedef struct{
    BiTree t;
    int tag;
}stack;
void SearchX(BiTree b,int x){
    stack s[MAXSIZE];
    int top = 0;
    while(b||top>0){
        while(b||b->data!=x){
            s[++p]=b;
            s[top].tag=0;
            b = b->lchild;
        }
        if(b->data==x){
            printf("所有结点的所有祖先节点值为：");
            for(i=1;i<top;i++)
                printf("%d",s[i].t->data);
            exit(1);
        }
        while (top!=0&&s[top].top==1)
            top--;
        if(top!=0){
            s[top].tag=1;
            b=s[top].t->rchild;
        }
    }
}