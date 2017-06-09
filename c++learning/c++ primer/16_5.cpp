#include <iostream>
using namespace std;

template <unsigned N,typename T>
void print(const T (&arr)[N]){
    for(auto elem:arr){
        cout<<elem<<endl;
    }
}
int main(){
    int a[10]={0,1,3,2,3,5,6,8,1,2};
    print(a);
    
    return 0;
}
