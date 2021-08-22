//串
/*	
	1.定义：即字符串，是由0个或者多个字符构成的有限序列
	2.串和线性表：1）串的对象限定为字符集
				  2）串的操作对象大多是子串。	
	3.串的第一个位置不存数据；
*/
#include<stdio.h>
#define MAXSIZE 255
typedef struct{ //串的静态顺序存储
	char ch[MAXSIZE];
	int length;
}SString;

typedef struct{ //串的动态顺序存储
	char *ch;
	int length;
}HString;
typedef struct StringNode{//串的链式存储
	char ch[4];
	struct StringNode* next;
}StringNode,*String;
//求子串，用sub返回串s的第pos个字符起长度为len的子串
bool SubString(SString &Sub,SString S,int pos,int len){
//子串越界
	if(pos+len>S.length)
		return false;
	for(int i=pos;i<pos+len;i++){
		Sub.ch[i-pos+1] = S.ch[i];
	}
	Sub.length=len;
	return true;
}
//比较两个字符串的大小
int StrCompare(SString S,SString T){
	for(int i=1;i<S.length&&i<T.length;i++){
		if(S.ch[i]!=T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.length-T.length;
}
//定位操作，找出串中与T值相同的子串，并返回位置
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
	while(i<=n-m+1){//使用前面的函数
		SubString(sub,S,i,m);
		if(StrCompare(sub,T)!=0)
			i++;
		else 
			return i;
	  }
	*/
	return 0;
}
//朴素模式匹配算法
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
//kmp算法（朴素模式算法的优化） 
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
//求模式串T的数组
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