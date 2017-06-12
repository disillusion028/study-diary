#include <iostream>
#include <vector>
using namespace std;
// class A{
//     public:
//     A(int a):x(a){

//     }
//     int x;
//     A foo(int a){
//         return A(a+1);
//     }
// };
vector<int>& bar(vector<int>&x){
    x=vector<int>({3,4});
    return x;
    //return std::move(vec);
}
int main(){
    // A a(3);
    // A b=a.foo(4);
    // cout<<a.foo(5).x<<endl;
    vector<int> vec={1,2};
    cout<<bar(vec)[0]<<endl;
}