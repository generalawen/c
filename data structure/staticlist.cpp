//��̬����

/*��̬�������Ͼ��Ǵ���ṹ������飬ֻ�ǰѽ�
�����next������һ��������±꣬����5�Ǿ���next
�ĵ�����������������±�
a[0]=	25,2   
a[1]=	28,5
a[2]=	26,4
a[3]=	0,-1
a[4]=	27,1
a[5]=	29,3

*/

/*
	
	  �жϾ�̬�����Ƿ�����ͨ���ж�-2�������Ƿ�ΪMAXSIZE.
	Ĭ�ϰ�L[0]��Ϊͷ�����ߵ�һ��Ԫ�ء�
	
	  ����ɾ����������next���ݽ���˳������ҵ���i-1������
	�޸��±�ͬʱ����Ԫ�ؽ��г�ʼ��������
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
//��̬������
typedef struct {
	int data;
	int next;
}SLinkList[MAXSIZE],component;
//��̬�����ʼ��
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