#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
void dfs(vector<int> &v1,vector<int> &v2,string X,int aim,int start,unordered_set<int>&,unordered_set<int>&);
bool isinfi=true;
vector<string> ret;
//vector<string> ret2;
string Cp;
bool haha=false;
void solv(vector<int> &v1,vector<int> &v2,int n){
    int aim=n-1;
    int start=0;
    string X;
    unordered_set<int> visited1;
    unordered_set<int> visited2;

    visited1.insert(0);
    visited2.insert(0);
    dfs(v1,v2,X,aim,start,visited1,visited2);
}
void dfs(vector<int> &v1,vector<int> &v2,string X,int aim,int start,unordered_set<int>& visited1,unordered_set<int>&visited2){
    if(start==aim){
        ret.push_back(X);
        return;
    }
    if(start>=v1.size()||start<0)return;
   // cout<<"debug: "<<start<<endl;
    if(start+v1[start]<v1.size()&&start+v1[start]>=0){
        if(!visited1.count(start+v1[start])){
            visited1.insert(start+v1[start]);
            dfs(v1,v2,X+'a',aim,start+v1[start],visited1,visited2);
            visited1.erase(start+v1[start]);
        }
        else {
            isinfi=true;
        }
    }
    if(start+v2[start]<v2.size()&&start+v2[start]>=0){
        if(!visited2.count(start+v2[start])){
            visited2.insert(start+v2[start]);
            dfs(v1,v2,X+'b',aim,start+v2[start],visited1,visited2);
            visited2.erase(start+v2[start]);
        }
        else{
            isinfi=true;
        }
    }
}
void dfs2(vector<int> &v1,vector<int> &v2,string X,int aim,int start,unordered_set<int>& visited1,unordered_set<int>&visited2){
    if(start==aim){
        if(haha)Cp=X;
        haha=false;
        return;
    }
    if(start>=v1.size()||start<0)return;
   // cout<<"debug: "<<start<<endl;
    if(start+v1[start]<v1.size()&&start+v1[start]>=0){
        if(!visited1.count(start+v1[start])){
            visited1.insert(start+v1[start]);
            dfs(v1,v2,X+'a',aim,start+v1[start],visited1,visited2);
            visited1.erase(start+v1[start]);
        }
        else {
            if(haha)Cp=X;
            haha=false;
            return;
        }
    }
    if(start+v2[start]<v2.size()&&start+v2[start]>=0){
        if(!visited2.count(start+v2[start])){
            visited2.insert(start+v2[start]);
            dfs(v1,v2,X+'b',aim,start+v2[start],visited1,visited2);
            visited2.erase(start+v2[start]);
        }
        else {
            if(haha)Cp=X;
            haha=false;
            return;
        }
    }
}
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
    if(ret.empty()){
        cout<<"No solution!"<<endl;
        return 0;
    }
    if(isinfi){
        string f1=ret.front();
        string cy;
        unordered_set<int> tp1;
        unordered_set<int> tp2;
        dfs2(v1,v2,cy,v1.size()-1,0,tp1,tp2);

        if(Cp.empty()){
            if(v1[0]==0){
                cout<<"Infinity!"<<endl;
                return 0;
            }
        }
        else{

            bool flag=false;
            for(int i=0;i<Cp.size();i++){
                if(Cp[i]!=f1[i]){flag=true;break;}
            }
            if(flag==false){
                cout<<"Infinity!"<<endl;
                return 0;
            }
        }
        cout<<f1<<endl;
    }
    else{
        cout<<ret.front()<<endl;
    }
    return 0;
}