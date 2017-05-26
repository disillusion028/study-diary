#include <iostream>
#include <vector>
using namespace std;
template <typename T>
ostream &print(ostream &os,const T &t){
    return os<<t;
}
template<typename T,typename ...Args>
ostream &print(ostream &os,const T &t, const Args&...rest){
    os<<t<<" ,";
    return print(os,rest...);
}
template <typename T>
ostream &print(ostream &os,const T &t);
int main(){
    int i=33;
    vector<int> a{1,2};
    string s="sdadasf";
    print(cout,i,s,42);
    return 0;
}