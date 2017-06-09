#include <iostream>
#include <sstream>
#include <string>
#include <utility>
using namespace std;
/*
template <typename T>
typename remove_reference<T>::type&& move(T&& t){
    return static_cast<typename remove_reference<T>::type&&>(t);
}
template <typename F,typename T1,typename T2>
void flip(F f,T1 &&t1,T2 &&t2){
    f(std::forward<T2>(t2),std::forward<T1>(t1));
}
*/
//模板函数的重载
//debug_rep
//该函数可以用来生成一个对象对应的string表示，该对象可以是任意具备输出运算符的类型
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

int main(){
    string s("hi");
    cout<<debug_rep(s)<<endl;
    cout<<debug_rep(&s)<<endl;
    return 0;
}