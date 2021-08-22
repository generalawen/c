/*
18页 14 ：
    基本设计思想：定义a,b,c;a从s1中取数，b从s2中取数，c从s3中取数；定义距离d=|a-b|+|b-c|+|c-a|;在通过储存单元d_min来记录
        最小的d;如果d_min>d;则d_min=d;比较a,b,c;最小的数去其属于数组的下一个单元，一直到最小值元素所在的数组遍历结束。
        输出d_min;
*/
#include <bits/stdc++.h>
int Abval(int i){
    if(i<0){
        return -i;
    }
    else{
        return i;
    }
}
bool abc_min(int a,int b,int c){
    if(a<b&&a<c){
        return true;
    }
    else{
        return false;
    }
}
int D_min(int A[],int B[],int C[],int a,int b,int c){
    int i,j,k;
    int d=0;
    i=j=k=0;
    int d_min=100;
    while(i<a&&j<b&&k<c){
        d=Abval(A[i]-B[j])+Abval(B[j]-C[k])+Abval(C[k]-A[i]);
        if(d_min>d){
            d_min=d;
        }
        if(abc_min(A[i],B[j],C[k])){
            i++;
        }
        else if(abc_min(B[j],C[k],A[i])){
                j++;
        }
        else{
            k++;
        }
    }
    return d_min;
}
int main(){
    int A[]={-1,0,9};
    int B[]={-25,-10,10,11};
    int C[]={2,9,17,30,41};
    int a=3,b=4,c=5;
    printf("%d\n",D_min(A,B,C,a,b,c));
    getchar();
    return 0;
    }