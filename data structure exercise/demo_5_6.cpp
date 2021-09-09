#include<bits/stdc++.h>
#include"data structure/BiTree.cpp"//树
//142 13
#define MAXSIZE 100
typedef struct{
BiTree b;
int tag;
}stack;
stack s[MAXSIZE],s1[MAXSIZE];
BiTree ancestor(BiTree root,BiTree *p,BiTNode *q){
    int top=0;
    int top1=0;
    BiTree bt=root;
    while (bt||top>0){
        while (bt)
        {
            s[++top].b = bt;
            s[top].tag=0;
            bt=bt->lchild;
        }
    while (top!=0&&s[top].tag==1)
    {
        if(s[top].b==p){
            for(int i=1;i<=top;i++)
                s1[i] = s[i];
            top1 = top;
        }
        if(s[top].b==q){
            for(int i=top;i>0;i--){
                for(int j = top1;j>0;j--){
                    if(s1[j].b==s[i].b)
                        return s[i].b;
                }
            }
        }
        top--;
    }
    if(top!=0){
        s[top].tag=1;
        bt = s[top].b->rchild;
    }
    }
    return NULL;
}

