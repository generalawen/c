//˳���
/*
1)����typedefʹ���Զ���Sqlist list;��Ȼ�Ļ�ϵͳ�ᱨ��
2)˳�����ص㣺
			�������
			�����ܶȸ�
			��չ����������
			���룬ɾ������Ԫ�ز�����
*/
#include<stdio.h>
#include<stdlib.h>
#define num 10
//��̬����
 /* typedef struct {
	char data[num];
	int SqListlight;
}SqList;
void InitList(SqList& list){
	for(int i=0;i<num;i++){
		list.data[i] = 0;
	}
		list.SqListlight = 0;
		return;
} 
*/
//��̬����
typedef struct{
	int *data;
	int MaxData;
	int leght;
}SqList;
void InitList(SqList& list )//˳����ʼ��
{
	list.data = (int*)malloc(num*sizeof(int));
	list.leght = 0;
	list.MaxData =  num; 
}
void IncreaceList(SqList& list,int len)//���Ӷ�̬����ĳ���
{
	int *p = list.data;
	list.data = (int*)malloc((list.MaxData + len)*sizeof(int));
	for(int i=0;i<list.leght;i++){
		list.data[i] = p[i];
	}
	list.MaxData = len + list.MaxData;
	free(p);
}
int InsertList(SqList &L,int i,int e)//������������i������e || 1���в��Ϸ�,2˳������ڴ�,0 �ɹ�
{
	if(i<1||i>L.leght+1){
		return  1;
	}
	if(L.leght>=L.MaxData){
	return 2;
	}
	for(int j=L.leght;j>=i;j-- ){		
		L.data[j] = L.data[j-1];
	}
	L.data[i-1]= e;
	L.leght++;
	return 0;
}
bool DeleteList(SqList &L,int i,int &e)//ɾ������i��Ԫ��,����ɾ����Ԫ��ֵ����e
{
	if(i<1||i>L.leght+1){
		return  false;
	}
	e = L.data[i-1];
	for(int j = i;j<L.leght;j++){
		L.data[j-1] = L.data[j];
	}
	L.leght--;
	return true;
}
int main(){

	 SqList l;
	InitList(l);
	IncreaceList(l,10);
	return 0;
}