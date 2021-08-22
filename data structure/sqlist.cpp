//顺序表
/*
1)加入typedef使可以定义Sqlist list;不然的话系统会报错
2)顺序表的特点：
			随机访问
			储存密度高
			拓展容量不方便
			插入，删除数据元素不方便
*/
#include<stdio.h>
#include<stdlib.h>
#define num 10
//静态分配
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
//动态分配
typedef struct{
	int *data;
	int MaxData;
	int leght;
}SqList;
void InitList(SqList& list )//顺序表初始化
{
	list.data = (int*)malloc(num*sizeof(int));
	list.leght = 0;
	list.MaxData =  num; 
}
void IncreaceList(SqList& list,int len)//增加动态数组的长度
{
	int *p = list.data;
	list.data = (int*)malloc((list.MaxData + len)*sizeof(int));
	for(int i=0;i<list.leght;i++){
		list.data[i] = p[i];
	}
	list.MaxData = len + list.MaxData;
	free(p);
}
int InsertList(SqList &L,int i,int e)//插入数据在序i处插入e || 1序列不合法,2顺序表无内存,0 成功
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
bool DeleteList(SqList &L,int i,int &e)//删除序列i的元素,并把删除的元素值赋给e
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