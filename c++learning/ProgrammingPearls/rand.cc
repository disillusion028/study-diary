#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
using namespace std;
inline int randi(int i){
    return rand()%(i+1);
}
int getRand(int n,int m){
    for(int i=0;i<n;i++){
        if(rand()%(n-i)<m){
            cout<<i<<endl;
            m--;
        }
    }
    return 0;
}//当n很大时计算速度比较慢
int getRand2(int n,int m)
{
    vector<int> res(m,0);
    for(int i=0;i<m;i++){
        res[i]=i;
    }
    int temp;
    for(int i=m;i<n;i++){
        temp=randi(i);
        if(temp<m){
            swap(res[temp],i);
        }
    }
    for(auto &&i:res){
        cout<<i<<endl;
    }
    return 0;
}
int main(){
    int n,m;
    n=INT_MAX,m=10;
    srand(time(NULL));
    getRand(n,m);
    return 0;
}
