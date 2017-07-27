#include <iostream>
#include<cstdio>
#include <cstddef>
using namespace std;
class A{int m;};  
class B{int m;};  
class C:public A,public B{};
int main(){  
    C c;  
    printf("%p %p %p\r\n", &c,reinterpret_cast<B*>(&c),static_cast<B*>(&c));
    char x=255;
    unsigned short y=x;
    cout<<y<<endl;
    int * m=nullptr;
    nullptr_t o;
}