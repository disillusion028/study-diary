#include <iostream>
using namespace std;
class b1{
    protected:
    virtual void f(){
        cout<<"b1::f"<<endl;
    }
    virtual void g(){
        cout<<"b1::g"<<endl;
    }
    virtual void h(){
        cout<<"b1::h"<<endl;
    }
};
class b2{
    virtual void f(){
        cout<<"b2::f"<<endl;
    }
    virtual void g(){
        cout<<"b2::g"<<endl;
    }
    virtual void h(){
        cout<<"b2::h"<<endl;
    }
};
class b3{
    virtual void f(){
        cout<<"b3::f"<<endl;
    }
    virtual void g(){
        cout<<"b3::g"<<endl;
    }
    virtual void h(){
        cout<<"b3::h"<<endl;
    }
};
class d:public b1,public b2,public b3{
    public:
    void f1(){
        b1::f();
    }
};
int main(){
    d myd;
    myd.f1();
    return 0;
}