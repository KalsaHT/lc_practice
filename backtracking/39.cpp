/*
 * @Author: httermin
 * @Date: 2019-11-01 16:36:42
 */

#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> result;
        getSum(candidates, result, 0, target, tmp);
        return result;
    }

    void getSum(vector<int>& candidates, vector<vector<int>>& result, int start, int target, vector<int>& tmp){
        if(target < 0) return;
        if(target == 0) result.push_back(tmp);
        
        for(int i=start; i<candidates.size(); i++){
            tmp.push_back(candidates[i]);
            getSum(candidates, result, i, target-candidates[i], tmp);
            tmp.pop_back();
        }
    }
};

int main(){
    int a[] = {2, 3, 5, 7};
    vector<int> candidates(a, a+3);

    int n=8;
    Solution ss;

    vector<vector<int>> result = ss.combinationSum(candidates, n);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<" "<<endl;
    }

    return 1;
}