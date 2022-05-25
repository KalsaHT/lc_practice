/*
 * @Author: httermin
 * @Date: 2019-11-18 16:48:18
 */

#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    //backtracking
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        vector<bool> isValid(nums.size(), true);
        getPermute(nums, result, tmp, isValid);
        return result;
    }

    void getPermute(vector<int>& nums, vector<vector<int>>& result, vector<int>& tmp, vector<bool> isValid){
        if(tmp.size() == nums.size()) result.push_back(tmp);
        
        for(int i=0; i<nums.size(); i++){
            if(isValid[i]){
                isValid[i] = false;
                tmp.push_back(nums[i]);
                getPermute(nums, result, tmp, isValid);
                isValid[i] = true;
                tmp.pop_back();
            }
        }
        
    }
};

int main(){
    int a[] = {1, 2, 3};
    vector<int> candidates(a, a+3);

    int n=5;
    Solution ss;

    vector<vector<int>> result = ss.permute(candidates);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<" "<<endl;
    }

    return 1;
}