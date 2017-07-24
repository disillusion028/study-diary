#include <iostream>
class OnlyStack{
private:
    void *operator new(size_t t){};
    void operator delete(void *ptr){}; 
public:
    OnlyStack(){};
    ~OnlyStack(){};
};
#if 1
class OnlyHeap{
protected:
    ~OnlyHeap(){};
public:
    OnlyHeap(){};
    void Destory(){delete this;}
};
#endif
#if 0
class OnlyHeap{
protected:
    ~OnlyHeap(){}
    OnlyHeap(){}
public:
    static OnlyHeap* Create(){
        return new OnlyHeap();
    }
    void Destory(){
        delete this;
    }
};
#endif
int main(){
    //OnlyHeap* a=OnlyHeap::Create();
    OnlyHeap *a=new OnlyHeap();
    a->Destory();
    OnlyStack b;
    //OnlyStack *c=new OnlyStack();
    return 0;
}