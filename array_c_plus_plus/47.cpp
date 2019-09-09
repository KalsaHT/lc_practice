#include<vector>
#include<iostream>
#include<set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> set_result;
        if(nums.size() <= 1){
            result.push_back(nums);
            return result;
        } 
        vector<int> tmp;   
        dfs(set_result, nums, tmp);
        result.assign(set_result.begin(), set_result.end());
        return result;     

    }
    void dfs(set<vector<int>>& set_result, vector<int> num, vector<int> tmp){
        if(num.size() == 2){
            tmp.push_back(num[0]);
            tmp.push_back(num[1]);
            set_result.insert(tmp);

            tmp[tmp.size()-2] = num[1];
            tmp[tmp.size()-1] = num[0];
            set_result.insert(tmp);
            return;
        }else{
            for(int i=0; i<num.size(); i++){
                tmp.push_back(num[i]);
                vector<int> num2;
                for(int j=0; j<num.size();j++){
                    if(j!=i) num2.push_back(num[j]);
                }
                dfs(set_result, num2, tmp);
                tmp.erase(tmp.end()-1);
            }
        }
    }
};