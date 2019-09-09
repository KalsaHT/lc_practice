#include<vector>
#include<iostream>
#include<algorithm>
#include "math.h"

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        int diff;
        int len = nums.size();
        int result=0;
        for(int i=0; i<len-2; i++){
            for(int j=i+1, k=len-1; j<k;){
                diff = target - nums[j] - nums[k] - nums[i];
                if(abs(diff) < min_diff){
                    cout<<abs(diff)<<endl;
                    min_diff = abs(diff);
                    result = nums[i] + nums[j] + nums[k];
                } 
                if(diff == 0){
                    return target;
                }else if(j<k && diff>0){
                    j++;
                }else if(j<k && diff<0){
                    k--;
                }
                if(abs(diff) < min_diff){
                    cout<<abs(diff)<<endl;
                    min_diff = abs(diff);
                    result = nums[i] + nums[j] + nums[k];
                } 
            }
        }
        return result;
    }
};

int main(){
    int a[] = {0,1,2};
    vector<int> v(a, a+3);
    Solution s;
    int result = s.threeSumClosest(v, 4);
    cout<<result<<endl;
    return -1;
}