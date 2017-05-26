#include <iostream>
using namespace std;
template <typename T> void f(T t){
    cout<<1<<endl;
    cout<<t<<endl;
    cout<<&t<<endl;
}
template <typename T> void f(const T* t){
    cout<<2<<endl;
    cout<<t<<endl;
    cout<<&t<<endl;
}
template <typename T> void g(T t){
    cout<<3<<endl;
    cout<<t<<endl;
    cout<<&t<<endl;
}
template <typename T> void g(T* t){
    cout<<4<<endl;
    cout<<t<<endl;
    cout<<&t<<endl;
}
template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);
int main(){
    int i=42,*p=&i;
    const int ci=0,*p2=&ci;
    g(42);g(p);g(ci);g(p2);
    //f(42);
    f(p);// T 比 const T * 更加特例化？
    //f(ci);
    //f(p2);
    return 0;
}