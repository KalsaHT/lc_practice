/*
 * @Author: httermin
 * @Date: 2019-09-18 10:53:19
 */

#include <vector>
#include<iostream>
#include <algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxV=nums[0], lastV = nums[0];
        for(int i=1; i<nums.size(); i++){
            lastV = max(lastV+nums[i], nums[i]);
            maxV = max(maxV, lastV);
        }
        return maxV;
    }
};

int main(){
    int A[] = {-1, -3, 1};
    vector<int> nums(A, A+3);
    Solution ss;
    int maxV = ss.maxSubArray(nums);
    cout<<maxV<<endl;
}