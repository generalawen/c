#include<bits/stdc++.h>
//211 4 题
#define M 100
#define N 100
void Convert(ALGaph &G,int arcs[M][N]){
    for (int  i = 0; i < n; i++)
    {
        p =(G->v[i]).firstarc;
        while (p!=NULL)
        {
            arcs[i][p->data] = 1;
            p=p->nextarc;
        } 
    }
}

























