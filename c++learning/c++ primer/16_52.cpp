#include <iostream>
using namespace std;
//variadic template
template <typename T,typename...Args>
void foo(const T &t,const Args&...rest){
    cout<<sizeof...(Args)<<endl;
    cout<<sizeof...(rest)<<endl;
}

int main(){
    int i=0;double d=3.14;string s="how now brown cow";
    foo(i,s,42,d);
    foo(s,42,"hi");
    foo(d,s);
    foo("fu*k");
    return 0;
}