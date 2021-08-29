
#include<bits/stdc++.h>
#include"data structure/BiTree.cpp"
#include"data structure/Sequential stack.cpp"

#include"data structure/Staticqueue.cpp"
/*
    141 3题(栈的储存元素没有更新，不匹配数据，需要运行得更改两个头文件，或者重写)
*/
void PostOrder(BiTree T){
    SqStack S;
    InitSqStack(S);
    BiTNode *p = T;
    BiTNode *r = NULL;
    while (p||!StackEmpty(S))
    {
        if(p){
            Push(S,p);
            p=p->lchild;
        }
        else{
            GetTop(S,p);
            if(p->rchild&&p->rchild!=r){
               p= p->rchild;
            }else{
                Pop(S,p);
                visit(p->data);
                r=p;
                p=NULL;
            }
        }
    }
    
}
/*
    141 4题
    思路:借助栈和队列，出栈输出结束。(如果用栈的指针就破坏了栈的性质)
    数据不匹配。
*/

void Ergodic(BiTree T){
    SqStack S;
    SqQueue Q;
    BiTNode p;
    InitSqStack(S);
    InitSqQueue(Q);
    if(T!=NULL){
        EnQueue(Q,T);
        while (!IsEmpty(Q))
        {
            DeQueue(Q,p);
            Push(S,p);
            if(T->lchild){
                EnQueue(Q,T->lchild);
            }
            if(T->rchild){
                EnQueue(Q,T->rchild);
            }
        }
        while (!StackEmpty(S))
        {
            Pop(S,p);
            visit(T->data);
        }    
    }
}



