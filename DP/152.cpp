/*
 * @Author: httermin
 * @Date: 2019-10-16 20:21:59
 */

#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxV=nums[0], minV=nums[0], res=nums[0];
        for(int i=1; i<nums.size(); i++){
            int tmp = maxV;
            maxV = max(nums[i], max(nums[i]*maxV, nums[i]*minV));
            minV = min(nums[i], min(nums[i]*tmp, nums[i]*minV));
            res = max(maxV, res);
            // cout<<maxV<<" "<<minV<<endl;
        }
        return res;
    }
};

int main(){
    Solution ss;
    int a[] = {-4,-3,-2};
    vector<int> tmp(a, a+3);
    cout<<ss.maxProduct(tmp)<<endl;
    return 1;
}