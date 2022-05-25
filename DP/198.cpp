/*
 * @Author: httermin
 * @Date: 2019-09-18 15:05:32
 */
#include <vector>
#include<iostream>
#include <algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int prepre = nums[0];
        int pre = max(nums[0], nums[1]);

        int result = max(prepre, pre);
        for(int i=2; i< nums.size(); i++){
            result = max(pre, prepre + nums[i]);
            prepre = pre;
            pre = result;
        }
        return result;
    }
};

int main(){
    int A[] = {2, 7, 9, 11, 1};
    vector<int> nums(A, A+2);
    Solution ss;
    cout<<ss.rob(nums)<<endl;
}