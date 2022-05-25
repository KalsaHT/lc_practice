/*
 * @Author: httermin
 * @Date: 2019-09-18 21:13:09
 */

#include <vector>
#include<iostream>
#include <algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() < 2) return 0;
        
        int pre = cost[1], prepre = cost[0];

        int result = 0;
        // cout<<pre<<" "<<prepre<<" "<<result<<endl;
        for(int i=2; i<cost.size(); i++){
            // cout<<pre<<" "<<prepre<<" "<<result<<endl;

            result = cost[i] + min(pre, prepre);
            // cout<<pre<<" "<<prepre<<" "<<result<<endl;
            prepre = pre;
            pre = result;
        }

        return min(pre, prepre);
    }
};

int main(){
    int A[] = {0, 1, 1, 0};
    vector<int> nums(A, A+4);
    Solution ss;
    int maxV = ss.minCostClimbingStairs(nums);
    cout<<maxV<<endl;
}