#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    template <typename T>
    vector<T> subsetSum(vector<T> &nums,T target){
        vector<T>dp(target+1);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                dp[j]=dp[j]+dp[j-nums[i]];
            }
            for(auto i:dp){
                cout<<i<<"  ";
            }
            cout<<endl;
        }
        return dp;
    }
};
int main(){
    Solution a;
    vector<int> nums={6,5,4,3,2,1,1,1};
    int target=7;
    vector<int> ret=a.subsetSum(nums,target);
    return 0;
}