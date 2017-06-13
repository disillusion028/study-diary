#include <stdio.h>
int uadd_ok(unsigned x,unsigned y){
    if(x+y<x)return -1;
    else return 1;
}
int tadd_ok(int x,int y){
    if(x>0&&y>0){
        if(x+y<=0)return -1;
    }
    if(x<0&&y<0){
        if(x+y>=0)return -1;
    }
    else return 1;
}