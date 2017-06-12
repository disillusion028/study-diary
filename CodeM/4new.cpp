#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
bool flag=false;
bool flag2=false;
void dfs(vector<int> &v1,vector<int>&v2,string x,int aim,int start,unordered_set<int>& visited1,unordered_set<int>&visited2,vector<string>&ret);
void solv(vector<int> &v1,vector<int> &v2,int n);
int main(){
    int n;
    cin>>n;
    vector<int>v1(n);
    vector<int>v2(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    for(int i=0;i<n;i++){
        cin>>v2[i];
    }
    solv(v1,v2,n);
    return 0;
}
void solv(vector<int> &v1,vector<int> &v2,int n){
    int aim=n-1;
    int start=0;
    string x;
    unordered_set<int> visited1;
    unordered_set<int> visited2;
    //visited1.insert(0);
    //visited2.insert(0);
    vector<string> ret;
    dfs(v1,v2,x,aim,start,visited1,visited2,ret);
    for(auto i:ret){
        cout<<"debug: "<<i<<endl;
    }
    if(ret.empty()){
        cout<<"No solution!"<<endl;
        return;
    }
    if(flag2==true){
        cout<<ret.front()<<endl;
        return;
    }
    if(flag==true){
        cout<<"Infinity!"<<endl;
        return;
    }
    else{
        cout<<ret.front()<<endl;
        return;
    }
}

void dfs(vector<int> &v1,vector<int>&v2,string x,int aim,int start,unordered_set<int>& visited1,unordered_set<int>& visited2,vector<string>& ret){
    if(start==aim){
        if(flag==false){
            flag2=true;
        }
        ret.push_back(x);
        return;
    }
    if(start<0||start>aim)return;
    if((start+v1[start]>=0)&&(start+v1[start]<=aim)){
        if(!(visited1.count(start))){
            visited1.insert(start);
            dfs(v1,v2,x+'a',aim,start+v1[start],visited1,visited2,ret);
            visited1.erase(start);
        }
        else {
            flag=true;
        }
    }
    if((start+v2[start]>=0)&&(start+v2[start]<=aim)){
        if(!(visited2.count(start))){
            visited2.insert(start);
            dfs(v1,v2,x+'b',aim,start+v2[start],visited1,visited2,ret);
            visited2.erase(start);
        }
    }
}