#include <iostream>
#include<typeinfo>
#include <stdlib.h>
#include <functional>
using namespace std;
int main(){
   // int x=300*400*500*600;
 //   cout<<x<<endl;
    cout<<(1+1e20)-1e20<<endl;
    int64_t a=1e15;
    cout<<a<<endl;
    cout<<typeid(1e20).name()<<endl;
    cout<<3.14+(1e20-1e20)<<endl;
}