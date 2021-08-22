//第二章线性表总结

/*
	总结：1.顺序表和链表
			1）逻辑结构：都是线性结构
			2）存储结构：顺序表支持随机存取，存储密度高
						 大片连续空间分配不方便，改变容量
						 也不方便
						 链表离散的小空间分配方便，改变容易
						 不可随机存取，存取密度低。
			3）基本操作：initlist(&L)[初始化表] destroylist(&L)[销毁操作] 
				     listlnser(&L,i,e)[插入操作] ListDelete(&L,i,&e)[删除操作]
				     locateelem(L,e)[按值查找] GetElem(L,i)[按位查找]
*/
//顺序表动态分配内存
#define MAXSIZE 100
#include<stdio.h>
typedef struct{
int *data;
int lenght;
};
//顺序表静态分配内存
typedef struct sqlist{
int data[MAXSIZE];
int lenght;
}SqList;

//单链表的定义
typedef struct{
	int data;
	Node *next;
}Node,*LinkList;
//双链表的定义
typedef struct DNode
{
	int data;
	Node *next;
	Node  *prior;
}DNode,*DLinkList;
int main(){
	printf("总结\n");
	return 0;
}