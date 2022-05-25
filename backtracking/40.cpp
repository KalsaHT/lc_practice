/*
 * @Author: httermin
 * @Date: 2019-11-18 15:37:12
 */
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        vector<vector<int>> result;
        getSum(candidates, result, 0, target, tmp);
        return result;
    }

    void getSum(vector<int>& candidates, vector<vector<int>>& result, int start, int target, vector<int>& tmp){
        if(target < 0) return;
        if(target == 0) result.push_back(tmp);
        
        for(int i=start; i<candidates.size(); i++){
            if(i == start || candidates[i] != candidates[i-1]){
                tmp.push_back(candidates[i]);
                getSum(candidates, result, i+1, target-candidates[i], tmp);
                tmp.pop_back();
            }
        }
    }
};

int main(){
    int a[] = {2, 5, 2, 1, 2, 1, 5};
    vector<int> candidates(a, a+5);

    int n=5;
    Solution ss;

    vector<vector<int>> result = ss.combinationSum2(candidates, n);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<" "<<endl;
    }

    return 1;
}