/*
 * @Author: httermin
 * @Date: 2019-11-19 14:41:07
 */

#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        vector<bool> isValid(nums.size(), true);
        vector<vector<int>> result;
        getPermute(result, tmp, isValid, nums);
        return result;
    }

    void getPermute(vector<vector<int>>& result, vector<int>& tmp, vector<bool> isValid, vector<int> nums){
        if(tmp.size() == nums.size()) result.push_back(tmp);
        
        for(int i=0; i<nums.size(); i++){
            
            if(isValid[i]){
                isValid[i] = false;
                tmp.push_back(nums[i]);
                getPermute(result, tmp, isValid, nums);
                isValid[i] = true;
                tmp.pop_back();

                while(i < nums.size() && nums[i] == nums[i+1]) i++;
            }
        }
    }
};

int main(){
    int a[] = {1, 1, 2};
    vector<int> candidates(a, a+3);

    int n=5;
    Solution ss;

    vector<vector<int>> result = ss.permuteUnique(candidates);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<" "<<endl;
    }

    return 1;
}