/*
    265 6题，折半查找递归
*/
#include<bits/stdc++.h>
typedef struct 
{
    int *data;
    int  lenght;
}SStable;
int Search(SStable st,int key,int low,int high){
    if(low>high)
        return 0 ;
    int mid = (low+high)/2;
    if(key>st.data[mid])
        Search(st,key,mid+1,high);
    else if(key<st.data[mid])
        Search(st,key,low,mid-1);
    else
        return mid;

}
