#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
void dfs(vector<int> &v1,vector<int> &v2,string X,int aim,int start);
bool isinfi=false;
bool isinfi2=false;
vector<string> ret;
unordered_set<int> visited1;
unordered_set<int> visited2;
void solv(vector<int> &v1,vector<int> &v2,int n){
    int aim=n-1;
    int start=0;
    string X;
    dfs(v1,v2,X,aim,start);
}
void dfs(vector<int> &v1,vector<int> &v2,string X,int aim,int start){
    if(start==aim){
        if(isinfi==false){isinfi2=true;}
        ret.push_back(X);
        return;
    }
    if(start>=v1.size()||start<0)return;
    if(!visited1.count(start)){
        visited1.insert(start);
        if(start+v1[start]<v1.size()&&start+v1[start]>=0){
                dfs(v1,v2,X+'a',aim,start+v1[start]);
        }
        visited1.erase(start);
    }
    else{
        isinfi=true;
    }
    if(!visited2.count(start)){ 
        visited2.insert(start);
        if(start+v2[start]<v2.size()&&start+v2[start]>=0){
                dfs(v1,v2,X+'b',aim,start+v2[start]);
        }
        visited2.erase(start);
    }

}
// vector<vector<int>> BuildGraph(vector<int> &v1,vector<int> &v2)
int main(){
    int n;
    cin>>n;
    vector<int> v1(n);
    vector<int> v2(n);
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        v1[i]=temp;
    }
    for(int i=0;i<n;i++){
        cin>>temp;
        v2[i]=temp;
    }
    solv(v1,v2,n);
//   cout<< isinfi<<"  "<<isinfi2<<endl;
    for(auto i:ret){
        cout<<i<<endl;
    }
    if(isinfi2==true){
        cout<<ret.front()<<endl;
        return 0;
    }
    if(isinfi2==false&&isinfi==true){
        cout<<"Infinity!"<<endl;
        return 0;
    }
    if(ret.empty()){
        cout<<"No solution!"<<endl;
        return 0;
    }
    else{
        cout<<ret.front()<<endl;
    }
    return 0;
}