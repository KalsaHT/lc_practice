#include<vector>
#include<iostream>

using namespace std; 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2);
        result[0] = -1;
        result[1] = -1;

        int low=0, high=nums.size()-1, mid;
        
        while(high >= low){
            // cout<<mid<<endl;
            mid = low + (high - low) / 2;
            if(nums[mid] > target){
                high = mid - 1;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                // cout<<mid<<endl;
                int i=mid, j=mid;
                while(nums[i]==target && i>-1)i--;
                // cout<<i<<endl;
                i++;
                while(nums[j]==target && j<nums.size()) j++;
                j--;
                result[0] = i;
                result[1] = j;
                break;
            }
        }
        return result;
    }
};


int main(){
    int a[] = {5, 7, 7, 8, 8, 10};
    vector<int> v(a, a+6);
    
    Solution s;
    vector<int> result = s.searchRange(v, 8);
    cout<<result[0]<<" "<<result[1]<<endl;
    return -1;
}