#include <iostream>
#include <vector>
using namespace std;
template<typename T>
void print(T& t){
    typename T::iterator begin=t.begin();
    typename T::iterator end=t.end();
    for(;begin!=end;begin++){
        cout<<*begin<<endl;
    }
}
int main(){
    vector<int> myvec({1,2,3,4,5,7,8,9,3,1});
    print(myvec);
    vector<string> mystrvec{"sdd","axw","hoho","hehe"};
    print(mystrvec);
    return 0;
}