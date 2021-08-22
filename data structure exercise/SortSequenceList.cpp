//331 题2
/*
    算法设计思想：把数组a看做前m个元素已经拍好的序列，把
    后n个依次从后开始插入数组。
    时间复杂度：O(mn),空间复杂度：O(1)
*/
#include<bits/stdc++.h>
void SortSqlist(int a[],int m,int n){
    int j,i;
    for( i=m+1;i<m+n;i++){
        a[0]=a[i];
        for( j=i-1;a[j]>a[0];j--){
            a[j+1]=a[j];
        }
        a[j+1]=a[0];
    }

}
//331 题三
/*
    算法设计思想：对每个元素，统计数组中关键码比他小
    的元素个数，记为cnt，并把该元素放到下标为cnt的位置上。
    时间复杂度：O(n^2) 空间复杂度：O(n)
*/
void CountArr(int a[],int b[],int n){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]>a[j])
                cnt++;
        }
        b[cnt]=a[i];
    }
}

