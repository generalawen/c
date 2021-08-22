#include"stdio.h"
#define Maxsize 100
typedef struct{
int data[Maxsize];
int length;
}SqList;
bool Min_data(SqList &L,int &value){
    if(L.length==0)
        {
            printf("顺序表为空");
            return false;
        }
        value=L.data[0];
        int a=0;
    for(int i=0;i<L.length;i++){
            if(value>L.data[i]){
                value=L.data[i];
                a=i;
            }
    }
    L.data[a]=L.data[L.length-1];
    L.length-=1;
    return true;
}

/*
//Min)data测试
int main(){
    SqList L;
    for(int a=0;a<100;a++){
        L.data[100-a]=a;
    }
    L.length=5;
    int value=0;
    Min_data(L,value);
    printf("%d",value);
    getchar();
    return 0;
}
*/