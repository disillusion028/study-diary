//16.16将Vec重写为模板
#include <iostream>
#include <utility>//pair move
#include <string>
#include <memory>
#include <algorithm> //for_each
template <typename T> class Vec{
public:
    Vec():
        elements(nullptr),first_free(nullptr),cap(nullptr){ }
    Vec(const std::initializer_list<T>& il);
    Vec(const Vec&);
    Vec &operator=(const Vec&);
    ~Vec();
    void push_back(const T&);
    size_t size() const {return first_free-elements;}
    size_t capacity() const {return cap-elements;}
    T *begin() const {return elements;}
    T *end() const {return first_free;}
    void reserve(const int n);
    template <typename TT> 
    friend std::ostream &operator<<(std::ostream &os,const Vec<TT> &s);//友元的模板和该类的模板类型不一样

private:
    static std::allocator<T> alloc;
    void chk_n_alloc(){
        if(size()==capacity())
            reallocate();
    }
    std::pair<T*,T*> alloc_n_copy(const T*,const T*);
    void free();
    void reallocate();
    T *elements;
    T *first_free;
    T *cap;
};
template <typename T> 
std::ostream &operator<<(std::ostream&os,const Vec<T> &s){
    for(auto i=s.begin();i!=s.end()-1;i++){
        os<<*i<<std::endl;
    }
    os<<*(s.end()-1);
    return os;
}
template <typename T> 
void Vec<T>::push_back(const T&s){
    chk_n_alloc();
    alloc.construct(first_free++,s);
}
template <typename T> 
std::pair<T*,T*>
Vec<T>::alloc_n_copy(const T *b,const T *e){
    auto data=alloc.allocate(e-b);
    return {data,std::uninitialized_copy(b,e,data)};
}
template <typename T> 
void Vec<T>::reserve(const int n){
    if(n<this->size())return;
    auto newcapacity = n;
    auto newdata=alloc.allocate(newcapacity);
    auto dest=newdata;
    auto elem=elements;
    for(size_t i=0;i!=size();++i){
        alloc.construct(dest++,std::move(*elem++));
    }
    free();
    elements=newdata;
    first_free=dest;
    cap=elements+newcapacity;
}
template <typename T> 
void Vec<T>::free(){
    if(elements){
        std::cout<<typeid(elements).name()<<std::endl;
        // for(auto p=first_free;p!=elements;){
        //     alloc.destroy(--p);
        // }
        std::for_each(elements,first_free,[&](T& p){p.~T();});
	//for_each中对p的调用已经解构了，所以用 T&
        alloc.deallocate(elements,cap-elements);
    }
}
template <typename T> 
Vec<T>::Vec(const Vec<T> &s){
    auto newdata=alloc_n_copy(s.begin(),s.end());
    elements=newdata.first;
    first_free=cap=newdata.second;
}
template <typename T> 
Vec<T>::Vec(const std::initializer_list<T> &il){
    auto newdata=alloc_n_copy(il.begin(),il.end());
    elements=newdata.first;
    first_free=cap=newdata.second;
}
template <typename T> 
Vec<T>::~Vec(){free();}

template <typename T> 
Vec<T>& Vec<T>::operator=(const Vec<T> &rhs){
    auto data=alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}
template <typename T>
void Vec<T>::reallocate(){
    auto newcapacity = size()?2*size():1;
    auto newdata=alloc.allocate(newcapacity);
    auto dest=newdata;
    auto elem=elements;
    for(size_t i=0;i!=size();++i){
        alloc.construct(dest++,std::move(*elem++));
    }
    free();
    elements=newdata;
    first_free=dest;
    cap=elements+newcapacity;
}
//static 成员需要在.cpp中声明！
template <typename T>
std::allocator<T> Vec<T>::alloc;
class myclass{
public:
    myclass(){
        std::cout<<"alloc"<<std::endl;
    }
    ~myclass(){
        std::cout<<"free"<<std::endl;
    }
};
int main(){
    // Vec<std::string> myvec={"sd","pf"};
    // myvec.push_back("abcd");
    // myvec.push_back("asdf");
    // myvec.push_back("ss");
    // std::cout<<myvec.size()<<std::endl;
    // std::cout<<myvec.capacity()<<std::endl;
    // std::cout<<myvec<<std::endl;
    // myvec.reserve(1);
    // std::cout<<myvec.capacity()<<std::endl;
    Vec<myclass> myvec2;
    myvec2.push_back(myclass());
    std::cout<<myvec2.size()<<std::endl;
    return 0;
}
