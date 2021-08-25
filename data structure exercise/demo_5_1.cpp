/*
    127 5 
*/
#include<bits/stdc++.h>
typedef struct{
    int data[20];
    int lenght;
}SqTree;
int Father_node(SqTree T,int i,int j){
    if(T.data[i]!="#"&&T.data[j]!="#"){
        while(i!=j){
            if(i>j)
                i=i/2;
            if(j>i)
                j=j/2;
        }
        return T.data[i];
    }
}