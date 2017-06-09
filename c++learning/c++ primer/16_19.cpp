//编写函数，接受一个容器的引用，打印容器中的元素，使用容器的size_type 和 size 成员来控制打印元素的循环
#include <iostream>
#include <vector>
using namespace std;
template <typename T>void print(T& t){
    typename T::size_type sz=t.size();
    for(typename T::size_type i=0;i<sz;i++){
        cout<<t[i]<<endl;
    }
}
int main(){
    vector<int> myvec={1,2,3,4,5,4,2,5};
    vector<string> mystrvec={"123","sd","24SD","0-0"};
    print(myvec);
    print(mystrvec);
    return 0;
}