#include <iostream>
#include <string>
#include <sstream>
using namespace std;
template <typename T>
ostream &print(ostream &os,const T &t){
    return os<<t;
}
template<typename T,typename ...Args>
ostream &print(ostream &os,const T &t, const Args&...rest){
    os<<t<<" ,";
    return print(os,rest...);
}
template <typename T>
ostream &print(ostream &os,const T &t);
template <typename T>string debug_rep(const T &t){
    ostringstream ret;
    ret<<t;
    return ret.str();
}
//打印指针的值，后跟指针指向的对象
//注意：此函数不能用于char*;
template <typename T> string debug_rep(T* p){
    ostringstream ret;
    ret<<"pointer: "<<p;
    if(p)
        ret<<" "<<debug_rep(*p);
    else
        ret<<"null pointer";
    return ret.str();
}
template <typename...Args>
ostream& errorMsg(ostream &os,const Args&... rest){
    return print(os,debug_rep(rest)...);
}
int main(){
    int i=33;
    int *x=&i;
    string s="sdadasf";
    errorMsg(cerr,i,x,s,42); 
    cout<<endl;
    return 0;
}