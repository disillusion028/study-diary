#include <iostream>
using namespace std;
class Base{
    public:
    virtual void f(){cout<<"Bf"<<endl;}
    virtual void g(){cout<<"Bg"<<endl;}
    virtual void h(){cout<<"Bh"<<endl;}
};
typedef void(*fun)(void);
int main(){
    Base b;
    fun pFun=NULL;
    cout<<"virtual table address: "<<(int*)(&b)<<endl;
    cout<<"virtual table first function address: "<<(int*)*(int*)(&b)<<endl;

    pFun=(fun)*((int*)*(int*)(&b));
    pFun();
    return 0;
}