#include <iostream>
#include <string.h>
#include <vector>
#include <list>
using namespace std;
vector<int>a;
template<typename Iter,typename T>
Iter Myfind(Iter first,const Iter last,const T &value){
    while(first!=last){
        if(*first==value){
            break;
        }
        else ++first;
    }
    return first;
}
class sales{
};
int main(){
    /*
    vector<int> myvec = {1,2,3,4,2,3,5,6,7,1};
    decltype(myvec.begin()) x=Myfind(myvec.begin(),myvec.end(),5);
    
    if(x!=myvec.end())cout<<*x<<endl;  
    */
    list<string> mylist={"haha","hoho","hehe","520"};
    cout<<*(Myfind(mylist.begin(),mylist.end(),"a"));
    return 0;
}
