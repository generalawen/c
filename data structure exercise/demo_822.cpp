#include<bits/stdc++.h>
/*代码运行时因为没有给leght赋值出现了Segmentation Fault错误
之前定义的指针data，因为没有动态赋值而出现
cannot convert '<brace-enclosed initializer list>' to 'int*' in assignmentgc
*/
typedef struct {
	int data[16];
	int leght;
}SqList;
int Binary_Search(SqList L,int key){
    int low=0,high = L.leght-1,mid;
    int count=0;
    while(low<=high){
        mid=(low+high)/2;
        if(L.data[mid]==key){
            count++;
            return count;
        }
        else if(L.data[mid]>key){
            count++;high=mid-1;
        }
        else{
            count++;low = mid+1;
        }
    }
    return count;
}
int main(){
    SqList L;
    L.leght=16;
    for(int i=0;i<16;i++){
        L.data[i]=i;
    }
    int count= Binary_Search(L,19);
    printf("%d",count);
    return 0;
}