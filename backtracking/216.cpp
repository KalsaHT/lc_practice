/*
 * @Author: httermin
 * @Date: 2019-11-18 16:18:37
 */

#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> candidates(a, a+9);
        vector<vector<int>> result;
        vector<int> tmp;
        getSum(candidates, result, 0, n, tmp, k);
        return result;
    }

    void getSum(vector<int>& candidates, vector<vector<int>>& result, int start, int target, vector<int>& tmp ,int k){
        if(target < 0) return;
        if(tmp.size() > k) return;
        if(tmp.size() == k && target == 0) result.push_back(tmp);
        for(int i=start; i<candidates.size(); i++){
            tmp.push_back(candidates[i]);
            getSum(candidates, result, i+1, target-candidates[i], tmp, k);
            tmp.pop_back();
        }
    }
};

int main(){
    int a[] = {2, 3, 5, 7};
    vector<int> candidates(a, a+3);

    int n=8;
    Solution ss;

    vector<vector<int>> result = ss.combinationSum3(3, 9);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<" "<<endl;
    }

    return 1;
}