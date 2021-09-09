#include<bits/stdc++.h>
#include"demo_821.cpp"
//307 4题
int Partition(int a[],int low,int high){
    int rand_Index = rand()%(high-low+1);
    Swap(a[rand_Index],a[low]);
    int pivot = a[low];
    int i=low;
    for (int j = low+1; j <= high; j++)
    {
        
        if(a[i]<pivot){
            Swap(a[++i],a[j]);
        }
        Swap(a[i],a[low]);
        return i;
    }  
}
//5题
int min_erem(int a[],int low,int high,int k){
    int pivot = a[low];
    int low_temp  = low;
    int high_temp=high;
    while(low<high){
        while(low<high&&a[high]>=pivot) --high;
        a[low]=a[high];
        while(low<high&&a[low]<=pivot) ++low;
        a[high] = a[low];
    }
    a[low] = pivot;
    if(low==k){
        return a[low];
    }
    else if(low>k){
        return min_erem(a,low_temp,low-1,k);
    }
    else{
        return min_erem(a,low+1,high_temp,k);
    }
}
/*
    6题:
    1)算法思想：根据题目可知要把集合n分为两个不相交的子集，快速排序的结果
        符合题目的要求，所以使用快速排序把集合根据中枢轴分为两个集合，
        所以根据枢轴的下标i分三种情况：
        ①当i=n/2时，分组完成；
        ②当i<n/2时，对后半部分继续进行分组；
        ③当i>n/2时，对前半部分继续进行分组。
        时间复杂度：O(n);时间复杂度为O(1)
*/
int setPartition(int a[],int n){
    int k=n/2;int flag = 1;
    int low=0, high=n;
    int low_temp  = low;
    int high_temp=high;
    int pivot = a[low];
    while(flag){
        while(low<high){
            while(low<high&&a[high]>=pivot) --high;
            if(low!=high) a[low]=a[high];
            while(low<high&&a[low]<=pivot) ++low;
            if(low!=high)  a[high]=a[low];
        }
            a[low] = pivot;
            if(low==k-1) flag = 0;
            else if(low<k-1){
                low_temp=++low;
                high=high_temp;
            }
            else{
                high_temp=--high;
                low=low_temp;
            }
    }
    int s1=0,s2=0;
    for (int i = 0 ; i < k; i++) s1+=a[i];
    for(int i=k;i<n;i++){s2+=a[i];}
    return s2-s1;
}