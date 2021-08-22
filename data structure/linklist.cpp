//������
/*
	1.����ʽ����ʵ�������Խṹ
	2.LNode*�ȼ���LinkList��LNodeǿ����㣬
	  LinkListǿ��������
	3.�����λ������ɾ����˼·��ͨ��˳������ҵ�Ҫ�����
	  ǰһ����㣬�����µĽ����в������޸Ľ��ָ�롣
	  ���ӣ�����Ҫɾ��5�Ž�㣬��4�Ž�㣬�����½ڵ�pָ��
	  5�Ž�㣬�ı�ǰ�����ָ�룬ͨ��free(p)���ͷſռ䡣
	
 */
/*
	
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	LNode * next;
}LNode,*LinkList;
//����ͷ���ĵ�����
bool InitListNo(LinkList &L){
	L = NULL;
	return true;
}
bool Empty(LinkList L)//�жϵ�����Ϊ��
{
	if(L == NULL)
		return  true;
	else
		return false;
}
//��ͷ���ĵ�����
bool InitList(LinkList &L){
  L = (LNode*)malloc(sizeof(LNode));
  if(L==NULL){
	return false;
  }
  L->next = NULL;
  return  true;
}

//��ͷ���Ĳ���(��λ��)
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

//����ͷ���Ĳ���(��λ��)
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

//��ָ�������к�����
bool  InsertNextList(LNode *p,int e){
	if(p==NULL)
		return false;
	LNode *s =(LNode*)malloc(sizeof(LNode));
	s->data= e;
	s->next = p->next;
	p->next = s;
	return true;
}

//��ָ��������ǰ�����
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

//������ɾ��ָ��λ����
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
//��ָ���Ľ��ɾ��
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
//��ָ����λ����в���
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
//��ָ����ֵ���в���
LNode* LocateElem(LinkList L,int e){
	LNode *p = L->next; 
	while(L!=NULL&&p->data != e){
		p=p->next;
	}
	return p;
}
//������ĳ���
int GetLength(LinkList L){
	int len = 0;
	LNode *p = L;
	while(p->next != NULL){
		p = p->next;
		len++;
	}
	return len;
}
//β�巨����������
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
//ͷ�巨����������
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