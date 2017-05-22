// leetcode SubsetII
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> nums) {
        vector<vector<int> >ret;
        if(nums.empty())return ret;
        sort(nums.begin(),nums.end());
        vector<int>temp;
        dfs(ret,temp,0,nums);
        return ret;
    }
    void dfs(vector<vector<int> > &ret,vector<int>&temp,int start,vector<int>&nums){
        ret.push_back(temp);
        for(int i=0;i<temp.size();i++)cout<<temp[i]<<" ";
        cout<<endl;
        for(int i=start;i<nums.size();i++){
            if(i>start&&nums[i]==nums[i-1]){cout<<"m  "<<m++<<endl;continue;}
            temp.push_back(nums[i]);
            dfs(ret,temp,i+1,nums);
            temp.pop_back();
            if(temp.empty())cout<<"v empty"<<i<<endl;
        }
    }
    int m=0;   
};

int main(){
    Solution s;
    vector<vector<int> > myvec=s.subsetsWithDup( { 1,2,2,2 } );
    // for(int i=0;i<myvec.size();i++){
    //     for(int j=0;j<myvec[i].size();j++){
    //         cout<<myvec[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    return 0;
}