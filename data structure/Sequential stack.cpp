//˳��ջ
/*
	˳��ջ��ȱ�㣺ջ�Ĵ�С���ɱ�
	˳��ջ���Ż�������ջ���������ڣ��߼�������
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
//˳��ջ�Ķ���
typedef struct {
	int data[MAXSIZE];
	int top;
	//int top1;
}SqStack;
//˳��ջ�ĳ�ʼ��
void InitSqStack(SqStack &S){
	S.top=0;
}
//�ж�ջΪ��
bool StackEmpty(SqStack s){
	if(s.top==0)
		return true;
	else
		return false;
}
//����Ԫ��x
bool Push(SqStack &S,int x){
	if(S.top==MAXSIZE)
		return false;
	S.data[S.top++]=x;
	return true;
}
//ɾ��Ԫ��,����x����
bool Pop(SqStack &S,int &x){
	if(S.top==0)
		return false;
	x=S.data[--S.top];
	return true;
}
//��ջ��Ԫ��
bool GetTop(SqStack S,int &x){
	if(S.top==0)
		return false;
	x=S.data[--S.top];
	return true;
}
