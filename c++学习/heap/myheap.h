#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T> class Myheap;
template<typename TT>
std::ostream& operator<<(std::ostream& os,const Myheap<TT> &s);
template <typename T>//TODO::可选参数 放一个比较函数进去
class Myheap{
public:
    template<typename TT>
    friend std::ostream& operator<<(std::ostream& os,const Myheap<TT> &s);    
    Myheap(const std::initializer_list<T> &il){
        heapvec=std::vector<T>(il);
    }
    Myheap(const std::vector<T> &s){
        this->heapvec=s;
    }
    std::vector<T> operator()(Myheap &s){
        return this->heapvec;
    }

private:
    std::vector<T> heapvec;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Myheap<T> &s){
    // for(auto i:s()){
    //     os<<i<<"  ";
    // }
    for(auto i=s.heapvec.begin();i!=s.heapvec.end();i++){
        os<<*i<<"  ";
    }
    return os;
}