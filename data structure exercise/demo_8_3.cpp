/*
    307 3题
*/
#include<bits/stdc++.h>
#include"demo_821.cpp"
void Move(int a[],int len){
    int i=0,j=len-1;
    while(i<j){
        while(i<j&&a[i]%2!=0) i++;
        while (i<j&&a[j]%2==0) j--;
        if(i<j){
            Swap(a[i],a[j]);
            i++;j++;
        }
        
    }
}
int main(){
    int a[]={1,2,3,4,5,6,7,8,9};
    Move(a,9);
    for (int i = 0; i < 9; i++)
    {
        /* code */
        printf("%d",a[i]);
    }
    return 0;
}