#include <iostream>
#include <vector>
#include <memory>
template <typename T> class Blob{
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob ();
    Blob (std::initializer_list<T> il);
    Blob (std::vector<T> vt);
    template <typename IT>
    Blob (IT ia,IT ib);
    size_type size() const {return data->size();}
    bool empty() const{return data->empty();}
    void push_back(const T &t){data->push_back(std::move(t));}
    void pop_back();
    T& back();
    T& operator[](size_type i);
private:
    std::shared_ptr<std::vector<T>>data;
    void check(size_type i,const std::string &msg)const;
};
template <typename T>
Blob<T>::Blob(std::vector<T> vt):
data(std::make_shared<std::vector<T>>(vt)){}

template <typename T>
template<typename IT>
Blob<T>::Blob(IT ia,IT ib):
data(std::make_shared<std::vector<T>>(ia,ib)){}

template <typename T>
void Blob<T>::check(size_type i,const std::string &msg)const
{
    if(i>=data->size())
        throw std::out_of_range(msg);
}
template <typename T>
T& Blob<T>::back(){
    check(0,"back on empty Blob");
    return data->back();
} 
template <typename T>
T& Blob<T>::operator[] (size_type i)
{
    check(i,"subscript out of range");
    return (*data)[i];
}
template<typename T> 
void Blob<T>::pop_back(){
    check(0,"pop_back on empty Blob");
    data->pop_back();
}
template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
data(std::make_shared<std::vector<T>>(il)){}


int main(){
    Blob <int> ia;
    Blob <int> ia2={0,1,2,3,4};
    Blob <int> ia3(ia2);
    std::vector<int> v1({1,2,3,4,5,6});
    Blob <int> ia4(v1.begin(),v1.end());
    for(size_t i=0;i!=ia3.size();++i){
        ia3[i]=i*i;
        std::cout<<ia3[i]<<"  ";
    }
    return 0;
}
