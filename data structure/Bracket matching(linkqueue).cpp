//ջ������ƥ��
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
//���������ж�
bool BracketCheck(char str[],int length){
	LiStack S;
	InitLiStack(S);
	for(int i=0;i<length;i++){
		if(str[i]=='('||str[i]=='['||str[i]=='{'){
			push(S,str[i]);
		}
		else{
			if(S==NULL)
				return false;
			char topElem;
			pop(S,topElem);
			if(str[i]==')'&&topElem!='(')
				return false;
			if(str[i]==']'&&topElem!='[')
				return false;
			if(str[i]=='}'&&topElem!='{')
				return false;
		}
	}
	if(S!=NULL)
		return false;
	return true;
}

int main(){
	char s[]={'(','[' ,'{','}','}',')'};
	int length = sizeof(s);
bool a  =	BracketCheck(s,length);
	return 0;
}



