#include "myheap.h"
int mytest(){
    std::vector<int> vint={2,7,5,6,1,3,4};
    {
        Myheap h1(vint);
        std::cout<<h1<<std::endl;
    }
    {
        Myheap h1(vint);
        h1.BuildMaxHeap();
        std::cout<<h1<<std::endl;    
    }
    {
        HeapSort(vint);
    }
    return 0;
}
int main(){
    mytest();
    return 0;
}