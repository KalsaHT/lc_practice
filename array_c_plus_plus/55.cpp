#include<vector>
#include<iostream>

using namespace std; 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool result=false;
        if(nums.size() == 1) return true;
        m(nums, nums.size()-2, nums.size()-1, result);
        return result;
    }

    void m(vector<int>& nums, int start, int end, bool& result){
        if(start < 0) return;
        if(nums[0] >= end - start && start == 0){
            result = true;
            return;
        }else if(nums[start] >= end - start){
            m(nums, start-1, start, result);
            return;
        }else{
            m(nums, start-1, end, result);
        }
    }
};

int main(){
    int a[] = {2, 3, 1, 1, 4};
    vector<int> nums(a, a+1);
    
    Solution s;
    bool result = s.canJump(nums);
    cout<<result<<endl;
    return -1;
}