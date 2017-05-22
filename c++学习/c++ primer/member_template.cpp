#include <iostream>
#include <memory>
//函数对象类，对给定指针执行 delete
using namespace std;
class DebugDelete{
public:
    DebugDelete(std::ostream &s=std::cerr):os(s){}
    template <typename T> 
    void operator() (T *p) const{
        os<<"deleting unique_ptr"<<std::endl;
        delete p;
    }
private:
    std::ostream &os;
};
int main(){
    double *p=new double;
    DebugDelete d;
    d(p);
    int* ip=new int;
    DebugDelete () (ip);
    unique_ptr<int,DebugDelete> p2(new int,DebugDelete());
    unique_ptr<string,DebugDelete> sp(new string,DebugDelete());

    return 0;
}