#include "myheap.h"
int mytest(){
    std::vector<int> vint={2,7,5,6,1,9,4};
    Myheap<int> h1(vint);
    //Myheap<int> h2({2,3,4,2,4,76,3,4,1});
    //vector<int> temp=h1();
    std::cout<<h1<<std::endl;
    //cout<<h2<<endl;

    //for(auto i:temp){
    //    cout<<i<<" ";
    //}
    return 0;
}
int main(){
    mytest();
    return 0;
}