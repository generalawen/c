//307 2题
#include <bits/stdc++.h>
void Swap(int &a,int &b){
    int c=0;
    c=a;
    a=b;
    b=c;
}
void BubbleSort(int a[],int n){
    int low = 0,high = n-1;
    bool flag = true;
    while(low<high&&flag){
        flag = false;
        for(int i=0;i<high;i++){
            if(a[i]>a[i+1]){
                Swap(a[i],a[i+1]);
                flag = true;
            }
        }
        high--;
        for(int i=high;i>low;i--){
            if(a[i]<a[i-1]){
                Swap(a[i],a[i-1]);
                flag=true;
            }
        }
        low++;
    }
}
/*int main(){
    int a[]={5,6,4,9,2,1,0,7,9};
    int n=9;
    BubbleSort(a,n);
    for(int i=0;i<n;i++){
            printf("%d",a[i]);
    }
    return 0;
}
*/