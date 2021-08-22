//��
/*	
	1.���壺���ַ���������0�����߶���ַ����ɵ���������
	2.�������Ա�1�����Ķ����޶�Ϊ�ַ���
				  2�����Ĳ������������Ӵ���	
	3.���ĵ�һ��λ�ò������ݣ�
*/
#include<stdio.h>
#define MAXSIZE 255
typedef struct{ //���ľ�̬˳��洢
	char ch[MAXSIZE];
	int length;
}SString;

typedef struct{ //���Ķ�̬˳��洢
	char *ch;
	int length;
}HString;
typedef struct StringNode{//������ʽ�洢
	char ch[4];
	struct StringNode* next;
}StringNode,*String;
//���Ӵ�����sub���ش�s�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
bool SubString(SString &Sub,SString S,int pos,int len){
//�Ӵ�Խ��
	if(pos+len>S.length)
		return false;
	for(int i=pos;i<pos+len;i++){
		Sub.ch[i-pos+1] = S.ch[i];
	}
	Sub.length=len;
	return true;
}
//�Ƚ������ַ����Ĵ�С
int StrCompare(SString S,SString T){
	for(int i=1;i<S.length&&i<T.length;i++){
		if(S.ch[i]!=T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.length-T.length;
}
//��λ�������ҳ�������Tֵ��ͬ���Ӵ���������λ��
int Index(SString S,SString T){
	int i=1;
	int n=S.length;
	int m=T.length;
	SString sub;
	while(i<=n-m+1){
		for(int j=i;j<=i+m;j++)
			sub.ch[j-i+1]=S.ch[j];
		if(StrCompare(sub,T)!=0)
			i++;
		else 
			return i;
	}
	/*
	while(i<=n-m+1){//ʹ��ǰ��ĺ���
		SubString(sub,S,i,m);
		if(StrCompare(sub,T)!=0)
			i++;
		else 
			return i;
	  }
	*/
	return 0;
}
//����ģʽƥ���㷨
int  Simple(SString S,SString T){
	int i=1,k=1,j=1;
	while(i<=S.length&&j<=T.length){
		if(S.ch[i]==T.ch[i]){
			++i;
			++j;
		}else{
			k++;
			i=k;
			j=1;
		}
	}
	if(j>T.length)
		return k;
	else 
		return 0;

}
//kmp�㷨������ģʽ�㷨���Ż��� 
int index_Kmp(SString S,SString T,int next[]){
	int j=1,i=1;
	while(i<S.length&&j<T.length){
	if(j==0||S.ch[i]==T.ch[j])
	{
		i++;
		j++;
	}else
		j=next[j];	
	}
	if(j>T.length)
		return i-T.length;
	else
		return 0;
}
//��ģʽ��T������
void get_next(SString T,int next[]){
	int i,j;
	next[1]=0;
	while(i<T.length){
		i=1;
		j=0;
		if(T.ch[i]=T.ch[j]||j==0){
		++j;
		++i;
		next[i]=j;
		}else
			j=next[j];
	}
}
int main(){

return 0;
}