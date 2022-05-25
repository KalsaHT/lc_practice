/*
 * @Author: httermin
 * @Date: 2019-09-18 14:45:53
 */

#include <vector>
#include<iostream>
#include <algorithm>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int maxV=0, minB;
        minB = prices[0]>prices[1]?prices[1]:prices[0];
        maxV = max(0, prices[1] - prices[0]);
        // cout<<maxV<<" "<<minB<<endl;

        for(int i=2; i<prices.size(); i++){
            maxV = max(maxV, prices[i] - minB);
            minB = min(minB, prices[i]);
            // cout<<maxV<<" "<<minB<<" "<<i<<endl;
        }
        return maxV;
    }
};

int main(){
    int A[] = {7, 3, 5, 1, 6, 4};
    vector<int> nums(A, A+6);
    Solution ss;
    cout<<ss.maxProfit(nums)<<endl;
}