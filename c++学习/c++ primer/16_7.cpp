#include <iostream>
using namespace std;

template <unsigned N,typename T>
constexpr int SZ(const T (&arr)[N]){
    return N;
}

//constexpr 变量必须在编译时进行初始化，所有constexpr 变量均为常量，必须使用常量表达式初始化； 
//constexpr函数是在使用需要它的代码时，可以在编译时计算其返回值的函数。当其参数为constexpr值并在编译时使用代码需要返回值时，它会生成编译时常量。
//使用非constexpr参数调用时，或编译时不需要其值时，它将与正则函数一样，在运行时生成一个值。
int main(){
    int a[10]={0,1,3,2,3,5,6,8,1,2};
    cout<<SZ(a)<<endl;  
    return 0;
}
