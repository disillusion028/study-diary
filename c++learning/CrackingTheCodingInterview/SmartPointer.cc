//implement of shared_ptr

#include <iostream>
using namespace std;
template<typename T>
class SmartPointer{
public:
    SmartPointer(T* pt){
        if(!pt){cout<<"parameter must not be null";}
        pointer=pt;
        refcount=new size_t(1);
    }
    SmartPointer(SmartPointer<T>& sptr){
        pointer=sptr.pointer;
        refcount=sptr.refcount;
        ++(*refcount);
    }
    SmartPointer<T> &operator=(SmartPointer<T> &sptr){
        if(this==&sptr)return *this;
        if(*refcount>0){
            rm();
        }
        pointer=sptr.pointer;
        refcount=sptr.refcount;
        ++(*refcount);
        return *this;
    }
    ~SmartPointer(){
        rm();
    }
    T getValue(){
        return *pointer;
    }
    void rm(){
        --(*refcount);
        if(*refcount==0){
            delete pointer;
            delete refcount;
            refcount=NULL;
            pointer=NULL;
            cout<<"deleted"<<endl;
        }
    }
private:
    T* pointer;
    size_t* refcount;

};
int main(){
    int *a=new int(5);
    int *b=new int(2);
    SmartPointer<int> Sp(a);
    SmartPointer<int> Sp2(Sp);
    SmartPointer<int> Sp3(b);
    Sp2=Sp;
    Sp=Sp3;
    cout<<Sp.getValue()<<endl;
    cout<<Sp2.getValue()<<endl;
}