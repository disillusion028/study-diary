//Write a function in C called my2DAlloc which allocates a two-dimensional array.
#include <stdio.h>
#include <malloc.h>
int** my2DAlloc_1(int m,int n){
    int sz=m*n;
    int **ret=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        ret[i]=(int*)malloc(n*sizeof(int));
    }
    return ret;
}
void Dealloc_1(int ** ret,int m){
    for(int i=0;i<m;i++){
        free(ret[i]);
    }
    free(ret);
}
int** my2DAlloc(int m,int n){
    int h=m*sizeof(int*);
    int data=m*n*sizeof(int);
    int** ret=(int**)malloc((h+data)*sizeof(int*));

    int* buf=ret[m];
    for(int i=0;i<m;i++){
        ret[i]=buf+i*n;
    }
    return ret;
}