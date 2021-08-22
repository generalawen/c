//静态链表

/*静态链表本质上就是储存结构体的数组，只是把结
构体的next当做下一个数组的下标，序列5是经过next
的第五个，而不是数组下标
a[0]=	25,2   
a[1]=	28,5
a[2]=	26,4
a[3]=	0,-1
a[4]=	27,1
a[5]=	29,3

*/

/*
	
	  判断静态链表是否已满通过判断-2的数量是否为MAXSIZE.
	默认把L[0]作为头结点或者第一个元素。
	
	  插入删除操作根据next数据进行顺序遍历找到第i-1的数据
	修改下标同时操作元素进行初始化操作。
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
//静态链表定义
typedef struct {
	int data;
	int next;
}SLinkList[MAXSIZE],component;
//静态链表初始化
void InitSLinkList(SLinkList L){
 
 for(int i = 0;i<MAXSIZE;i++){
	L[i].next=-2;
 }
}

int main(){
	SLinkList L;
	InitSLinkList(L);
	return 0;
}