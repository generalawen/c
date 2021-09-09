//142 14
#include<bits/stdc++.h>
#include"data structure/BiTree.cpp"
#define Maxsize 100;

typedef struct 
{
    BiTNode *q;
    int level;
}Array;

typedef struct 
{
  Array a[Maxsize];
  int front,rear;
}s;
int WidthBi(Bitree b){
    BiTree p;
    int max,k;
    s s;
    s.front=-1;
    s.rear=0;
    s.a->p[s.rear]=b;
    s.a->level=1;
    while (s.front<s.rear)
    {
        s.front++;
        p=s.a[s.front]->q;
        k=s.a[s.front].level;
        if (p->lchild)
        {
           s.rear++;
           s.a[s.rear]->q = p->lchild;
           s.a[s.rear].level=k+1;
        }
        if (p->rchild)
        {
            s.rear++;
            s.a[s.rear]->q = p->rchild;
            s.a[s.rear].level=k+1;
        }  
    }
    int i=0;
    while (i<s.rear)
    {
        int n=0;
        while (i<=s.rear&&s.a[i].level==k)
        {
              n++;i++;
        }
        k = s.a[i].level;
      if(max<n)
        max=n;
    }
    return max;
}

