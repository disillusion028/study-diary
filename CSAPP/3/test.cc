#include <tuple>
#include <vector>
using namespace std;
void twiddle1(long *xp,long *yp){
    *xp+=*yp;
    *xp+=*yp;
}
void twiddle2(long *xp,long *yp){
    *xp+=2* *yp;
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        //first compute latest start time
        int n=courses.size();
        // for(auto i:courses){
        //     i[1]=i[1]-i[0];
        // }
        vector<vector<tuple<int,int,set<int>>>> dp(n,vector<tuple<int,int,set<int>>>(n,{0,0,{}}));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0)dp[i][j]={courses[i][1],courses[i][0]+courses[i][1],{j}};
                else{
                    if(get<0>(dp[i-1][j])>courses[j][1]-courses[j][0]){
                        continue;
                    }
                    if(get<2>(dp[i-1][j]).count(j))continue;
                    if(get<1>(dp[i-1][j])==courses[j][1]-courses[j][0]){
                        get<1>(dp[i][j])=courses[j][1]-courses[j][0];
                        get<0>(dp[i][j])=get<0>(dp[i-1][j])+courses[i][1];
                        get<2>(dp[i][j]).insert(j);
                    }
                    if(get<1>(dp[i-1][j])<courses[j][1]-courses[j][0]){
                        continue;
                    }
                }
            }
        }
        
        
        
        
        
        return 0;
    }
};