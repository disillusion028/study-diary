//定义一个函数模板，统计一个给定值在一个vector中出现的次数。
//编写特例化版本来处理 vector<const char*>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
template<typename T> 
int counts(vector<T> &vec,const T& t){
    int ret=0;
    for(T& i:vec){
        if(i==t)ret++;
    }
    return ret;
}
template<>
int counts(vector<const char*>&vec,const char * const & s)//当模板参数为引用时不能进行数组和指针的转换！
{
    int ret=0; 
    for(auto &i:vec){
        if(strcmp(s,i)==0)ret++;
    }
    return ret;
}
int main(){
    int x=2;
    vector<int> vint={1,1,1,1,2,2,2,3,3,4};
    vector<string> vstring={"haha","haha","hoho","heihei"};
    vector<double> vdouble={1.2,1.2,5.5,5.5,5.5,6.6,7.7,9.1};
    vector<const char*>vcstr={"haha","haha","haha","hoho","heihei"};
    cout<<counts(vint,1)<<endl;
    cout<<counts(vint,x)<<endl;
    cout<<counts(vstring,string("hoho"))<<endl;
    cout<<counts(vdouble,5.5)<<endl;
    const char* str="haha";
    cout<<counts(vcstr,str)<<endl;
    return 0;
}