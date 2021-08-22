//��ջ

#include<stdio.h>
#include<stdlib.h>
//��ջ�Ķ���
typedef struct LinkNode{
	char  data;
	struct LinkNode *next;
}*LiStack;
//��ջ�ĳ�ʼ��(��ͷ���)
void InitLiStack(LiStack &L){
	L = NULL;
	
}
//��ջ
bool push(LiStack &L,char x){
	LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
	if(p==NULL)
		return false;
	p->data = x;
	p->next=L;
	L = p;
	return true;
}
//��ջ
bool pop(LiStack &L,char &x){
	if(L==NULL)
		return false;
     LinkNode *p = L;
	 x = p->data;
	 L = p->next;
	 free(p);
	return true;
}
int main(){
  LiStack L;
  InitLiStack(L);
  char x = 12;
  push(L,x);
  push(L,26);
  pop(L,x);

  return 0;
}

