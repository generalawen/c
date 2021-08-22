/*
17页12题：
    算法设计思想：对数组进行两次遍历，第一次遍历选出可能的主元素，第二次遍历判断其是否为主元素。具体的步骤如下
        1）定义主一维数组A，储存单元 a,b，第一次遍历，把第一个元素储存在a中，此时记录b为1，寻找下一个元素，如果
        该元素与a相等，那么b++,如果不相等，b--;依次遍历，当遇到b=0时，将此时遍历的元素放入a中，b=1;一直到数组结束
        2）第二编遍历，当数组的元素与a中的相同，b++;直到数组结束，如果b>size(A)/2,则输出主元素a，否则输出-1；
*/
#include <bits/stdc++.h>
int MajorNum(int A[],int size){
    int a=A[0];
    int b=1;
    for(int i=1;i<size;i++){
        if(a==A[i]){
            b++;
        }
        else{
            if(b>0){
                b--;
            }else{
                a=A[i];
                b=1;
            }
        }
        
    }
    b=0;
    for(int i=0;i<size;i++){
        if(a==A[i]){
            b++;
        }
    }
    if(b<(size/2)){
        return -1;
    }
    return a;
}
int main(){
   int A[]={0,5,5,3,5,7,5,5};
    int B[]={0,1,2,3,4,5,3,7};
    int size=8;
    printf("%d\n",MajorNum(A,size));
    printf("%d\n",MajorNum(B,size));
    getchar();
}