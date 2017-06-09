#include <iostream>
using namespace std;
class A{
    public:
    A(int a):x(a){

    }
    int x;
    A foo(int a){
        return A(a+1);
    }
};
int main(){
    A a(3);
    A b=a.foo(4);
    cout<<a.foo(5).x<<endl;
}