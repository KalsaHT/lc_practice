/*
 * @Author: httermin
 * @Date: 2019-10-16 18:01:45
 */

#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        
        if(n<2) return 1;
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
            // cout<<dp[i]<<endl;
        }
        return dp[n];
    }
};

int main(){
    int n=3;
    Solution ss;
    cout<<ss.numTrees(n)<<endl;
}