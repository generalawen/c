//���е�˳��洢
/*
	���У�ֻ���ڶ�β���룬�ڶ�ͷɾ�����Ƚ��ȳ�
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
//���еĶ���
typedef struct {
	char data[MAXSIZE];
	int front,rear;
	int size;
}SqQueue;
//���еĳ�ʼ��
void InitSqQueue(SqQueue &L){
	L.front = L.rear = 0;
	L.size = 0;
}
//����Ԫ��
bool EnQueue(SqQueue &L,char x){
	if(L.size==MAXSIZE)
		return false;
	L.data[L.rear]=x;
	L.rear= (L.rear+1)%MAXSIZE;
	L.size++;
	return true;
}
//ɾ��Ԫ��
bool DeQueue(SqQueue &L,char &x){
	if(L.size==0)
		return false;
	x = L.data[L.front];
	L.data[L.front] = 0;
	L.front= (L.front+1)%MAXSIZE;
	L.size--;
	return true;
}
//�鿴��ͷ����βԪ��
bool SeekQueue(SqQueue L,char &x,char &y){
	if(L.size==0)
		return false;
	x = L.data[L.front];
	y = L.data[L.rear];
	return true;
}
int main(){
	SqQueue L;
	InitSqQueue(L);
	EnQueue(L,45);
	EnQueue(L,46);
	EnQueue(L,47);
	char a;
	DeQueue(L, a);
	char x,y;
	SeekQueue(L,x,y);
	return 0;
}