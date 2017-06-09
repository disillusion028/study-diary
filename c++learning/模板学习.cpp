#include <utility>
#include <iostream>
using namespace std;
template <typename F,typename T1,typename T2>
void flip1(F f,T1 t1,T2 t2){
    f(t2,t1);
}
template <typename F, typename &&T1,typename &&T2>
void flip2(F f,T1 t1,T2 t2){
    f(t2,t1);
}
void f(int v1,int &v2){
    cout<<v1<<" "<<++v2<<endl;
}
int main(){
    int i1=0;
    f(42,i1);
    int i2=0;
    flip1(f,i2,42);
    cout<<i1<<"   "<<i2<<endl;
    int i3=0;
    flip2(f,i3,42);
    cout<<i3<<endl;
    return 0;
}