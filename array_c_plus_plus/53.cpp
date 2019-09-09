#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = nums[0];
        for(int i=0; i<nums.size(); i++){
            sum1 += nums[i];
            sum2 = sum1>sum2 ? sum1:sum2;
            sum1 = sum1>0 ? sum1:0;
        }
        return sum2;
    }
};


int main(){
    int A[] = {-1};
    vector<int> nums(A, A+1);
    Solution s;
    cout<<s.maxSubArray(nums);
    return -1;

}
