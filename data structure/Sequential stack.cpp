//顺序栈
/*
	顺序栈的缺点：栈的大小不可变
	顺序栈的优化：共享栈，物理相邻，逻辑不相邻
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
//顺序栈的定义
typedef struct {
	char data[MAXSIZE];
	int top;
	//int top1;
}SqStack;
//顺序栈的初始化
void InitSqStack(SqStack &S){
	S.top=0;
}
//判断栈为空
bool StackEmpty(SqStack s){
	if(s.top==0)
		return true;
	else
		return false;
}
//插入元素x
bool Push(SqStack &S,char x){
	if(S.top==MAXSIZE)
		return false;
	S.data[S.top++]=x;
	return true;
}
//删除元素,并用x接受
bool Pop(SqStack &S,char &x){
	if(S.top==0)
		return false;
	x=S.data[--S.top];
	return true;
}
//读栈顶元素
bool GetTop(SqStack S,char &x){
	if(S.top==0)
		return false;
	x=S.data[--S.top];
	return true;
}
