#include "Vec.hpp"
#include <ctime>
int main(){
    // Vec<std::string> myvec={"sd","pf"};
    // std::string mystr="hahaha";
    // myvec.emplace_back(mystr);
    // myvec.push_back("abcd");
    // myvec.push_back("asdf");
    // myvec.push_back("ss");
    // myvec.emplace_back(10,'c');
    // std::cout<<myvec.size()<<std::endl;
    // std::cout<<myvec.capacity()<<std::endl;
    // std::cout<<myvec<<std::endl;
    // myvec.reserve(1);
    // std::cout<<myvec.capacity()<<std::endl;
    // Vec<myclass> myvec2;
    // myvec2.push_back(myclass());
    // std::cout<<myvec2.size()<<std::endl;
    std::clock_t b_start=std::clock();
    Vec<int> v;
    for(int i=0;i<10000000;i++){
        v.push_back(i);
    }
    
    std::clock_t b_end=std::clock();
    std::cout<<(b_end-b_start)<<"us"<<std::endl;
    std::cout<<v.size()<<std::endl;
    return 0;
}
