//单链表
/*
	1.用链式储存实现了线性结构
	2.LNode*等价于LinkList，LNode强调结点，
	  LinkList强调单链表
	3.链表的位序插入和删除的思路：通过顺序遍历找到要处理的
	  前一个结点，命名新的结点进行操作并修改结点指针。
	  例子：假如要删除5号结点，找4号结点，命名新节点p指向
	  5号结点，改变前后结点的指针，通过free(p)来释放空间。
	
 */
/*
	
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	LNode * next;
}LNode,*LinkList;
//不带头结点的单链表
bool InitListNo(LinkList &L){
	L = NULL;
	return true;
}
bool Empty(LinkList L)//判断单链表为空
{
	if(L == NULL)
		return  true;
	else
		return false;
}
//带头结点的单链表
bool InitList(LinkList &L){
  L = (LNode*)malloc(sizeof(LNode));
  if(L==NULL){
	return false;
  }
  L->next = NULL;
  return  true;
}

//带头结点的插入(按位序)
bool InsertList(LinkList &L,int i,int e){
	if(i<1){
		return false;
	}
	LNode *p;
	int j = 0;;
	p = L;
	while(p!=NULL&&j<i-1){
		p = p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next=s;
	return true;
}

//不带头结点的插入(按位序)
bool InsertListNo(LinkList &L,int i,int e){
	if(i<1){
		return false;
	}
	if(i == 1){
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data = e;
		s->next= L->next;
		L = s ;
		return true;
	}
	LNode *p;
	int j = 1;;
	p = L;
	while(p!=NULL&&j<i-1){
		p = p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next=s;
	return true;
}

//按指定结点进行后插操作
bool  InsertNextList(LNode *p,int e){
	if(p==NULL)
		return false;
	LNode *s =(LNode*)malloc(sizeof(LNode));
	s->data= e;
	s->next = p->next;
	p->next = s;
	return true;
}

//按指定结点进行前插操作
bool InsertFrontList(LNode *p,int e){
	if(p==NULL)
		return false;
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->data = p->data;
	p->data = e;
	s->next= p->next;
	p->next = s;
	return true;
}

//按链表删除指定位序结点
bool DeleteLNode(LinkList &L,int i,int &e){
	if(i<1)
		return false;
	int j = 0;
	LNode *p;
	p = L;
	while(p!=NULL&&j<i-1){
		p = p->next;
		j++;
	}
	LNode *q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true;

}
//按指定的结点删除
bool DeleteLNode(LNode *p){
	if(p==NULL){
		return false;
	}
	LNode *q = p->next;
	p->data=p->next->data;
	p->next = q->next;
	free(q);
	return true;
}
//按指定的位序进行查找
LNode * GetElem(LinkList L,int i){
	if(i<1)
		return NULL;
	int j = 0;
	LNode *p;
	p = L ;
	while(L!=NULL&&j<i){
	    p= p->next;
		j++;
	}
	return p;
}
//按指定的值进行查找
LNode* LocateElem(LinkList L,int e){
	LNode *p = L->next; 
	while(L!=NULL&&p->data != e){
		p=p->next;
	}
	return p;
}
//求单链表的长度
int GetLength(LinkList L){
	int len = 0;
	LNode *p = L;
	while(p->next != NULL){
		p = p->next;
		len++;
	}
	return len;
}
//尾插法创建单链表
LinkList CreateListFinal(LinkList &L){
	int x;
	L =(LinkList)malloc(sizeof(LNode));
	LNode *s,*r = L;
	scanf("%d",&x);
	while(x!=9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next=s;
		r= s;
		scanf("%d",&x);
	}
	r->next = NULL;
	return L;
}
//头插法创建单链表
LinkList CreateListFirst(LinkList &L){
	LNode * s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d",&x);
	while(x!=9999){
		s =(LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d",&x);
	}
	return L;
}
int main(){
	LinkList L;
	InitList(L);


	return 0;
}