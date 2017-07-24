#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

// class MathObject{
// public:
//     virtual double Arith()=0 ;
//     virtual void Print()=0;
// };

// class Printable: public MathObject
// {
// public:

//     double Arith()override=0;
//     //double xx()override{return 1;}
//     void Print() final
//     {
//         //I want to avoid this function's overwrite
//         cout<<"Output is: "<<Arith()<<endl;
//     }
// };

// class Add2:public Printable{
// public:
//     Add2(double a,double b):x(a),y(b){}
//     double Arith()override{return x+y;}
// private:
//     double x,y;
// };

// class Mul3:public Printable{
// public:
//     Mul3(double a,double b,double c):x(a),y(b),z(c){}
//     double Arith(){return x*y*z;}
// private:
//     double x,y,z;
// };

// int main(){
//     Add2 ad2(1,4);
//     ad2.Print();
//     Mul3 ml3(2,3,5);
//     ml3.Print();
//     return 0;
// }


// 继承构造函数
// struct A{
//     A(int i){}
//     A(double d,int i){}
//     A(float f,int i,const char* c){}
// };
// struct B:A{
//     B(int i):A(i){}
//     B(double d,int i):A(d,i){}
//     B(float f,int i,const char* c):A(f,i,c){}
//     virtual void ExtraInterface(){}
// };
// struct C:A{
//     using A::A;
//     virtual void ExtraInterface(){}
// };
// struct Base{
//     void f(double i){cout<<"Base: "<<i<<endl;}
// };
// struct Derived:Base{
//     using Base::f;
//     void f(int i){cout<<"Derived: "<<i<<endl;}
// };
// int main(){
//     Base b;
//     b.f(4.5);
//     Derived d;
//     d.f(4.5);
//     C c(3);
//     return 0;
// }

// struct A{
//     A(int i){}
//     A(double d,int i){}
//     A(float f,int i,const char *c){}
// };
// struct B:A{
//     using A::A;
//     int d{0};
// };
// int main(){
//     B b(124);
//     cout<<b.d<<endl;
// }

// struct A{A(int){}
// A(){}};
// struct B:A{using A::A;};

// B b;
// int main(){return 0;}


// 委派构造函数
# if 0
class Info{
public:
    Info(){InitRest();}
    //Info(int i):type(i){InitRest();}// 可以运行，但是冗余了，不嫌累么？
    //Info(int i){this->Info();type=i;}//编译错误，不允许构造函数调用别的构造函数
    //Info(int i){new(this)Info();type=i;}//可以运行但是很危险
    Info(int i):Info(){type=i;}
    Info(char e):Info(){name=e;}

    //Info(char e){this->Info();name='a';}
//private:
    void InitRest(){}
    int type{1};
    char name{'a'};
};
#endif

#if 0
class Info{
public:
    Info():Info(1,'a'){}
    Info(int i):Info(i,'a'){}
    Info(char e):Info(1,e){}
//private:
    Info(int i,char e):type(i),name(e){/*else initial*/type++;}
    int type;
    char name;
};
#endif

#if 0
class TDConstructed{
    template<class T> TDConstructed(T first,T last):l(first,last){}
    list<int> l;
public:
    TDConstructed(vector<short> &v):TDConstructed(v.begin(),v.end()){}
    TDConstructed(deque<int> &d):TDConstructed(d.begin(),d.end()){}
};

int main(){
    Info x(12);
    cout<<x.type<<endl;
    return 0;
}
#endif
void RunCode(int &&m){cout<<"rvalue ref"<<endl;}
void RunCode(int &m){cout<<"lvalue ref"<<endl;}
void RunCode(const int &&m){cout<<"const rvalue ref"<<endl;}
void RunCode(const int &m){cout<<"const lvalue ref"<<endl;}

template <typename T>
void PerfectForward(T&& t){
    RunCode(forward<T>(t));
}
int main(){
    int a,b;
    const int c=1,d=0;
    PerfectForward(a);
    PerfectForward(move(b));
    PerfectForward(c);
    PerfectForward(move(d));
    return 0;
}