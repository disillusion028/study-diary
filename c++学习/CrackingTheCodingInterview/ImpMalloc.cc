#include <iostream>
#include <malloc.h>
using namespace std;
void* aligned_malloc(int sz,int spc){
    void* p1;
    void* p2;
    int offset=
}
int main(){
    void* vp=aligned_malloc(1000,128);
    cout<<vp<<endl;
    return 0;
}