#include <string>
#include <cstring>
#include <iostream>
using namespace std;
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int sz=nums.size();
//         k %= sz;
//         reverse(nums, 0, sz-1);
//         reverse(nums, 0, k-1);
//         reverse(nums, k, sz-1);
//     }
//     void reverse(vector<int>& nums, int start, int end) {
//         while (start < end) {
//             swap(nums[start], nums[end]);
//             start ++;
//             end --;
//         }
//     }
// };
int main(){
    // vector<int> vec={1,2,3,4,5,6,7};
    // Solution s;
    // s.rotate(vec,4);
    string str("abc");
    const char *a=str.c_str();
    char *b=const_cast<char*>(a);
    //printf("%ld",strlen(b));
    //printf("%c\n",b[3]);
    //b[3]='?';
    for(int i=3;i<25;i++){
        b[i]='Q';
    }
    cout<<b<<hex<<endl;
    
    return 0;
}