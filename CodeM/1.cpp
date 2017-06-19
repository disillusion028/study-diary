#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int solvediff(vector<int>&v1,vector<int>&v2,int start){
    int ret=0;
    int sz1=v1.size();
    int temp;
    for(int i=0;i<sz1;i++){
        temp=v1[i]-v2[start+i];
        temp=temp*temp;
        ret+=temp;
    }
    return ret;
}
int solution(vector<int>&v1,vector<int>&v2){
    int diff=INT_MAX;
    int x=v2.size()-v1.size();
    //cout<<x<<endl;
    for(int i=0;i<=x;i++){
        diff=min(diff,solvediff(v1,v2,i));
    }
    return diff;
}
int main(){
    vector<int> v1;
    vector<int> v2;
    int n,m,temp;
    cin>>n;
    while(n--){
        cin>>temp;
        v1.push_back(temp);
    }
    cin>>m;
    while(m--){
        cin>>temp;
        v2.push_back(temp);
    }
    cout<<solution(v1,v2)<<endl;
    return 0;
}
